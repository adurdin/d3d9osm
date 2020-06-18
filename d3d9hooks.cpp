#include <stdio.h>
#include <d3d9.h>
#include "d3d9hooks.h"

#define DIRECT3DDEVICE9_FN_START 3
#define DIRECT3DDEVICE9_FN_COUNT 116

static Direct3DDevice9_FnPtrs g_Orig = {};
static Direct3DDevice9_FnPtrs g_Hooks = {};
static DWORD *g_vtable = NULL;

DWORD* get_Direct3DDevice9_vtable()
{
    printf("get_Direct3DDevice9_vtable... ");
    DWORD* vtable = NULL;
    HINSTANCE hInstance = GetModuleHandle(0);
    IDirect3D9* direct3D = Direct3DCreate9(D3D_SDK_VERSION);
    if (direct3D) {
        const char *wndClassName = "D3D9HOOKS";
        WNDCLASSEXA wndClass = {
            sizeof(WNDCLASSEXA), CS_HREDRAW|CS_VREDRAW, DefWindowProc, 0, 0,
            hInstance, NULL, NULL, NULL, NULL, wndClassName, NULL,
        };
        if (RegisterClassExA(&wndClass)) {
            HWND hWnd = CreateWindowExA(0, wndClassName, "d3d9hooks",
                WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 640, 480, NULL, NULL, hInstance, NULL);
            if (hWnd) {
                D3DPRESENT_PARAMETERS presentParams = {
                    0, 0, D3DFMT_UNKNOWN, 1, D3DMULTISAMPLE_NONE, 0, D3DSWAPEFFECT_COPY,
                    NULL, TRUE, FALSE, D3DFMT_UNKNOWN, 0, 0, D3DPRESENT_INTERVAL_DEFAULT,
                };
                IDirect3DDevice9* device = NULL;
                HRESULT result = direct3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                    D3DCREATE_SOFTWARE_VERTEXPROCESSING, &presentParams, &device);
                if (result == D3D_OK) {
                    vtable = *(DWORD **)device;
                    printf("vtable is at %08x", (unsigned int)vtable);
                    device->Release();
                } else {
                    printf("CreateDevice failed (%lu).", result & 0xFFFFUL);
                }
                DestroyWindow(hWnd);
            }
            UnregisterClassA(wndClassName, hInstance);
        }
        direct3D->Release();
    } else {
        printf("Direct3DCreate9 failed.");
    }
    printf("\n");
    return vtable;
}

HRESULT InstallD3D9Hooks(const Direct3DDevice9_FnPtrs* pHooks, const Direct3DDevice9_FnPtrs** ppOrig)
{
    if (! pHooks || ! ppOrig) return E_INVALIDARG;
    if (g_vtable) return E_ABORT;

    DWORD* vtable = get_Direct3DDevice9_vtable();
    if (! vtable) return E_UNEXPECTED;

    Direct3DDevice9_FnPtrs orig = {};
    DWORD* origAddr = (DWORD*)&orig;
    for (int i=0; i<DIRECT3DDEVICE9_FN_COUNT; ++i) {
        origAddr[i] = vtable[i+DIRECT3DDEVICE9_FN_START];
    }
    DWORD* hookAddr = (DWORD*)pHooks;
    for (int i=0; i<DIRECT3DDEVICE9_FN_COUNT; ++i) {
        DWORD addr = hookAddr[i];
        if (addr) {
            vtable[i+DIRECT3DDEVICE9_FN_START] = addr;
        }
    }

    g_Orig = orig;
    g_Hooks = *pHooks;
    g_vtable = vtable;
    *ppOrig = &g_Orig;

    return S_OK;
}

HRESULT UninstallD3D9Hooks()
{
    if (! g_vtable) return E_ABORT;

    DWORD* vtable = g_vtable;
    if (! vtable) return E_UNEXPECTED;

    DWORD* origAddr = (DWORD*)&g_Orig;
    DWORD* hookAddr = (DWORD*)&g_Hooks;
    for (int i=0; i<DIRECT3DDEVICE9_FN_COUNT; ++i) {
        if (hookAddr[i]) {
            vtable[i+DIRECT3DDEVICE9_FN_START] = origAddr[i];
        }
    }

    g_Orig = {};
    g_Hooks = {};
    g_vtable = NULL;

    return S_OK;
}
