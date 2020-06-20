#include <stdio.h>
#include <d3d9.h>
#include "d3d9hooks.h"

#include <stdarg.h>

static FILE* logfile(void)
{
    static FILE* f = NULL;
    if (! f) {
        f = fopen("d3d9hooks.log", "w");
    }
    return f;
}

static void log(const char *fmt, ...)
{
    va_list args1, args2;
    va_start(args1, fmt);
    va_copy(args2, args1);
    vfprintf(stdout, fmt, args1);
    vfprintf(logfile(), fmt, args2);
    va_end(args2);
    va_end(args1);
    fflush(stdout);
    fflush(logfile());
}

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
static Direct3DDevice9_Vtable g_Hooks = {};

HRESULT HookDirect3DDevice9(IDirect3DDevice9* device, Direct3DDevice9_Vtable const * pHooks, Direct3DDevice9_Vtable const ** ppOrig)
{
    if (! device) return E_INVALIDARG;
    if (! ppOrig) return E_INVALIDARG;
    if (g_HookedDevice) return E_FAIL;

    log("Hooking device: %p\n", device);

    g_HookedDevice = device;
    Direct3DDevice9_Vtable const *vtable = *(Direct3DDevice9_Vtable const **)device;
    g_Orig = *vtable;
    g_Hooks = *pHooks;
    *ppOrig = &g_Orig;
    DWORD* origPtrs = (DWORD*)&g_Orig;
    DWORD* hookPtrs = (DWORD*)&g_Hooks;
    DWORD* vtablePtrs = (DWORD*)vtable;
    for (int i=0; i<Direct3DDevice9_FnIndex_Count; ++i) {
        if (hookPtrs[i]) {
            vtablePtrs[i] = hookPtrs[i];
            log("%3d:#%p%c", i, (void*)hookPtrs[i], (i%4==3?'\n':'\t'));
        } else {
            log("%3d: %p%c", i, (void*)origPtrs[i], (i%4==3?'\n':'\t'));
        }
    }
    log("\n");

    return S_OK;
}

HRESULT UnhookDirect3DDevice9(IDirect3DDevice9* device)
{
    if (! device) return E_INVALIDARG;
    if (device != g_HookedDevice) return E_FAIL;

    log("Unhooking device: %p\n", device);

    Direct3DDevice9_Vtable const *vtable = *(Direct3DDevice9_Vtable const **)device;
    DWORD* origPtrs = (DWORD*)&g_Orig;
    DWORD* vtablePtrs = (DWORD*)vtable;
    for (int i=0; i<Direct3DDevice9_FnIndex_Count; ++i) {
        vtablePtrs[i] = origPtrs[i];
        log("%3d: %p%c", i, (void*)origPtrs[i], (i%4==3?'\n':'\t'));
    }
    log("\n");

    g_HookedDevice = NULL;
    g_Orig = {};
    g_Hooks = {};

    return S_OK;
}

HRESULT RehookDirect3DDevice9_Begin() {
    if (! g_HookedDevice) return E_FAIL;

    IDirect3DDevice9* device = g_HookedDevice;
    log("Rehook, unhooking device: %p\n", device);
    Direct3DDevice9_Vtable const *vtable = *(Direct3DDevice9_Vtable const **)device;
    DWORD* origPtrs = (DWORD*)&g_Orig;
    DWORD* vtablePtrs = (DWORD*)vtable;
    for (int i=0; i<Direct3DDevice9_FnIndex_Count; ++i) {
        vtablePtrs[i] = origPtrs[i];
    }

    return S_OK;
}
HRESULT RehookDirect3DDevice9_End() {
    if (! g_HookedDevice) return E_FAIL;

    IDirect3DDevice9* device = g_HookedDevice;
    log("Rehook, hooking device: %p\n", device);
    Direct3DDevice9_Vtable const *vtable = *(Direct3DDevice9_Vtable const **)device;
    DWORD* hookPtrs = (DWORD*)&g_Hooks;
    DWORD* vtablePtrs = (DWORD*)vtable;
    for (int i=0; i<Direct3DDevice9_FnIndex_Count; ++i) {
        if (hookPtrs[i]) {
            vtablePtrs[i] = hookPtrs[i];
        }
    }

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
    DWORD* hookPtrs = (DWORD*)&g_Hooks;
    DWORD* vtablePtrs = (DWORD*)vtable;
    if (fn) {
        hookPtrs[index] = (DWORD)fn;
        vtablePtrs[index] = (DWORD)fn;
        log("%3d:#%p\n", index, fn);
    } else {
        hookPtrs[index] = 0;
        vtablePtrs[index] = origPtrs[index];
        log("%3d: %p\n", index, (void*)origPtrs[index]);
    }

    return S_OK;
}