#include <stdio.h>
#include <d3d9.h>
#include "d3d9hooks.h"

IDirect3DDevice9* Dark_FindDirect3DDevice9Ptr()
{
    // FIXME: this is hardcoding T2v127 offsets, and then
    // not checking them at all! It really should do some
    // sanity checking...
    DWORD addrRenderer = 0x005d9d88UL + (DWORD)GetModuleHandle(0);
    DWORD ofsDevice = 15;
    IDirect3DDevice9** pDevice = (IDirect3DDevice9**)(*((DWORD**)addrRenderer) + ofsDevice);
    IDirect3DDevice9* device = (pDevice ? *pDevice : NULL);
    return device;
}

/** We only support hooking one device at any time (so I don't ever have to malloc).
   
    g_HookedDevice: The hooked device; NULL if no device is hooked.
    g_pOrig: Pointer to the original vtable; NULL if no device is hooked.
    g_Hooks: Replacement vtable with pointers to hooked and/or original functions.
*/
static IDirect3DDevice9* g_HookedDevice = NULL;
static Direct3DDevice9_Vtable const * g_pOrig = NULL;
static Direct3DDevice9_Vtable g_Hooks = {};

HRESULT HookDirect3DDevice9(IDirect3DDevice9* device, Direct3DDevice9_Vtable const * pHooks, Direct3DDevice9_Vtable const ** ppOrig)
{
// Hook the given device with the functions in pHooks, and return a pointer to the original vtable
// in ppOrig for hooks to call through to the original functions.

// For any functions you do not want to hook, put NULL in the corresponding entry in pHooks; the
// hooked device will use the original function pointer for that entry.

// If pHooks is NULL then the device will still be hooked, but will only have original functions;
// you can use SetHookedDirect3DDevice9Fn() to then hook and unhook functions individually.

// The pHooks pointer is not retained, so may safely point to a stack variable.

// ppOrig must not be NULL, and all your hooks should use it to call any functions on this device;
// you should not call This->Whatever(...) directly; instead call ppOrig->Whatever(This, ...).

// On success, HookDirect3DDevice9() will return S_OK.

// Only one device may be hooked at any given time; if you try to hook a second device before
// unhooking the first, HookDirect3DDevice9() will return E_FAIL.

// No guarantees whatsoever are made concerning thread safety.

    if (! device) return E_INVALIDARG;
    if (! ppOrig) return E_INVALIDARG;
    if (g_HookedDevice) return E_FAIL;

    g_HookedDevice = device;
    g_Hooks = *pHooks;
    g_pOrig = *ppOrig = *(Direct3DDevice9_Vtable const **)device;
    printf("device: %p\n", device);
    printf("g_pOrig: %p\n", g_pOrig);
    void** hookPtrs = (void**)&g_Hooks;
    void** origPtrs = (void**)g_pOrig;
    for (int i=0; i<Direct3DDevice9_FnIndex_Count; ++i) {
        if (! hookPtrs[i]) {
            hookPtrs[i] = origPtrs[i];
            printf("%d: %p\n", i, hookPtrs[i]);
        } else {
            printf("%d: %p (HOOKED)\n", i, hookPtrs[i]);
        }
    }
    //*(Direct3DDevice9_Vtable const **)device = &g_Hooks;

    return S_OK;
}

HRESULT UnhookDirect3DDevice9(IDirect3DDevice9* device)
{
    if (! device) return E_INVALIDARG;
    if (device != g_HookedDevice) return E_FAIL;

    //*(Direct3DDevice9_Vtable const **)device = g_pOrig;
    g_HookedDevice = NULL;
    g_pOrig = NULL;
    g_Hooks = {};

    return S_OK;
}

BOOL IsHookedDirect3DDevice9(IDirect3DDevice9* device)
{
    return (device == g_HookedDevice);
}

HRESULT SetHookedDirect3DDevice9Fn(IDirect3DDevice9* device, Direct3DDevice9_FnIndex index, void *fn)
{
    if (! device) return E_INVALIDARG;
    if (! (index >= 0 && index < Direct3DDevice9_FnIndex_Count)) return E_INVALIDARG;
    if (device != g_HookedDevice) return E_FAIL;

    void** hookPtrs = (void**)&g_Hooks;
    void** origPtrs = (void**)g_pOrig;
    if (! fn) fn = origPtrs[index];

    hookPtrs[index] = fn;

    return S_OK;
}