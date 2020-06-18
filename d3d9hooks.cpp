#include <d3d9.h>
#include "d3d9hooks.h"

#define DIRECT3DDEVICE9_FN_START 3
#define DIRECT3DDEVICE9_FN_COUNT 116

Direct3DDevice9_FnPtrs g_pOrig = {};
Direct3DDevice9_FnPtrs g_pHooks = {};
DWORD *g_vtable = NULL;

static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return 0;
}

static DWORD* get_Direct3DDevice9_vtable()
{
    DWORD* vtable = NULL;
    HINSTANCE hInstance = (HINSTANCE)GetModuleHandle(0);

    IDirect3D9* direct3D = Direct3DCreate9(D3D_SDK_VERSION);
    if (direct3D) {
        const char *wndClassName = "D3D9HOOKS";
        WNDCLASSEXA wndClass = {
            sizeof(WNDCLASSEXA), CS_HREDRAW|CS_VREDRAW, WindowProc, 0, 0,
            hInstance, NULL, NULL, NULL, NULL, wndClassName, NULL,
        };
        if (RegisterClassExA(&wndClass)) {
            HWND hWnd = CreateWindowExA(WS_EX_NOACTIVATE, wndClassName, "d3d9hooks",
                WS_DISABLED, 0, 0, 100, 100, NULL, NULL, hInstance, NULL);
            if (hWnd) {
                D3DPRESENT_PARAMETERS presentParams = {
                    0, 0, D3DFMT_UNKNOWN, 1, D3DMULTISAMPLE_NONE, 0, D3DSWAPEFFECT_COPY,
                    hWnd, TRUE, FALSE, D3DFMT_UNKNOWN, 0, 0, D3DPRESENT_INTERVAL_DEFAULT,
                };
                IDirect3DDevice9* device = NULL;
                HRESULT result = direct3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                    D3DCREATE_SOFTWARE_VERTEXPROCESSING, &presentParams, &device);
                if (result == D3D_OK) {
                    vtable = *(DWORD **)device;
                    device->Release();
                }
                DestroyWindow(hWnd);
            }
            UnregisterClassA(wndClassName, hInstance);
        }
        direct3D->Release();
    }
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

    g_pOrig = orig;
    g_pHooks = *pHooks;
    g_vtable = vtable;
    *ppOrig = &g_pOrig;

    return S_OK;
}

HRESULT UninstallD3D9Hooks()
{
    if (! g_vtable) return E_ABORT;

    DWORD* vtable = g_vtable;
    if (! vtable) return E_UNEXPECTED;

    DWORD* origAddr = (DWORD*)&g_pOrig;
    DWORD* hookAddr = (DWORD*)&g_pHooks;
    for (int i=0; i<DIRECT3DDEVICE9_FN_COUNT; ++i) {
        if (hookAddr[i]) {
            vtable[i+DIRECT3DDEVICE9_FN_START] = origAddr[i];
        }
    }

    g_pOrig = {};
    g_pHooks = {};
    g_vtable = NULL;

    return S_OK;
}
