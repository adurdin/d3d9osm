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

IDirect3DDevice9* Dark_FindDirect3DDevice9Ptr_Direct()
{
    // FIXME: this is hardcoding T2v127 offsets, and then
    // not checking them at all! It really should do some
    // sanity checking...
    DWORD addrDevice = 0x005d915cUL + (DWORD)GetModuleHandle(0);
    IDirect3DDevice9** pDevice = (IDirect3DDevice9**)addrDevice;
    IDirect3DDevice9* device = (pDevice ? *pDevice : NULL);
    return device;
}

/** We only support hooking one device at any time (so I don't ever have to malloc).
   
    g_HookedDevice: The hooked device; NULL if no device is hooked.
    g_Orig: Copy of original vtable with pointers to original functions.
*/
static IDirect3DDevice9* g_HookedDevice = NULL;
static Direct3DDevice9_Vtable g_Orig = {};

HRESULT HookDirect3DDevice9(IDirect3DDevice9* device, Direct3DDevice9_Vtable const * pHooks, Direct3DDevice9_Vtable const ** ppOrig)
{
    if (! device) return E_INVALIDARG;
    if (! ppOrig) return E_INVALIDARG;
    if (g_HookedDevice) return E_FAIL;

    printf("Hooking device: %p\n", device);

    g_HookedDevice = device;
    Direct3DDevice9_Vtable const *vtable = *(Direct3DDevice9_Vtable const **)device;
    g_Orig = *vtable;
    *ppOrig = &g_Orig;
    DWORD* hookPtrs = (DWORD*)pHooks;
    DWORD* origPtrs = (DWORD*)&g_Orig;
    DWORD* vtablePtrs = (DWORD*)vtable;
    for (int i=0; i<Direct3DDevice9_FnIndex_Count; ++i) {
        if (hookPtrs[i]) {
            vtablePtrs[i] = hookPtrs[i];
            printf("%d: %p (HOOKED)\n", i, (void*)hookPtrs[i]);
        } else {
            printf("%d: %p\n", i, (void*)origPtrs[i]);
        }
    }

    return S_OK;
}

HRESULT UnhookDirect3DDevice9(IDirect3DDevice9* device)
{
    if (! device) return E_INVALIDARG;
    if (device != g_HookedDevice) return E_FAIL;

    printf("Unhooking device: %p\n", device);

    Direct3DDevice9_Vtable const *vtable = *(Direct3DDevice9_Vtable const **)device;
    DWORD* origPtrs = (DWORD*)&g_Orig;
    DWORD* vtablePtrs = (DWORD*)vtable;
    for (int i=0; i<Direct3DDevice9_FnIndex_Count; ++i) {
        vtablePtrs[i] = origPtrs[i];
        printf("%d: %p\n", i, (void*)origPtrs[i]);
    }

    g_HookedDevice = NULL;
    g_Orig = {};

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

    Direct3DDevice9_Vtable const *vtable = *(Direct3DDevice9_Vtable const **)device;
    DWORD* origPtrs = (DWORD*)&g_Orig;
    DWORD* vtablePtrs = (DWORD*)vtable;
    if (fn) {
        vtablePtrs[index] = (DWORD)fn;
        printf("%d: %p (HOOKED)\n", index, fn);
    } else {
        vtablePtrs[index] = origPtrs[index];
        printf("%d: %p\n", index, (void*)origPtrs[index]);
    }

    return S_OK;
}