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
static int g_RefCnt;

static GUID g_IID_IDirect3DDevice9 = { 0xd0223b96UL, 0xbf7a, 0x43fd, 0x92, 0xbd, 0xa4, 0x3b, 0xd, 0x82, 0xb9, 0xeb };

IUNKNOWN_QUERYINTERFACE_FN(Hooked_QueryInterface)
{
    log("QueryInterface(%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X)\n",
        riid.Data1, (int)riid.Data2, (int)riid.Data3,
        (int)riid.Data4[0], (int)riid.Data4[1], (int)riid.Data4[2], (int)riid.Data4[3],
        (int)riid.Data4[4], (int)riid.Data4[5], (int)riid.Data4[6], (int)riid.Data4[7]);

    // When querying for IID_IDirect3DDevice9, the returned interface gets
    // its vtable rewritten. For all I know, the entire thing could even get
    // deallocated and reallocated. So we unhook, then rehook if the pointer
    // is the same (which is not guaranteed).
    bool shouldRehook = (IsEqualGUID(riid, g_IID_IDirect3DDevice9));
    Direct3DDevice9_Vtable hooks = g_Hooks;
    if (shouldRehook) {
        log("Unhooking for QueryInterface...\n");
        UnhookDirect3DDevice9((IDirect3DDevice9*)This);
    }
    void *pvObj = NULL;
    HRESULT result = g_Orig.QueryInterface(This, riid, &pvObj);
    *ppvObj = pvObj;
    log("  returned %ld, -> %p\n", result, pvObj);
    if (shouldRehook) {
        if (pvObj == This) {
            const Direct3DDevice9_Vtable* pOrig;
            HookDirect3DDevice9((IDirect3DDevice9*)This, &hooks, &pOrig);
            log("Rehooked.\n");
        } else {
            log("Warning: cannot rehook.\n");
        }
    }
    return result;
}

IUNKNOWN_ADDREF_FN(Hooked_AddRef)
{
    log("AddRef()\n");
    ++g_RefCnt;
    return g_Orig.AddRef(This);
}

IUNKNOWN_RELEASE_FN(Hooked_Release)
{
    log("Release()\n");
    --g_RefCnt;
    if (g_RefCnt == 0) {
        log("Warning: Unhooking due to Release(), will not rehook.\n");
        UnhookDirect3DDevice9((IDirect3DDevice9*)This);
    }
    return g_Orig.Release(This);
}


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
    g_RefCnt = 1;
    *ppOrig = &g_Orig;
    g_Hooks.QueryInterface = Hooked_QueryInterface;
    g_Hooks.AddRef = Hooked_AddRef;
    g_Hooks.Release = Hooked_Release;
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
    g_RefCnt = 0;

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