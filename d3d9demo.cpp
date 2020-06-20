/******************************************************************************
 *    Demo.cc
 *
 *    This file is part of Object Script Module
 *    Copyright (C) 2004 Tom N Harris <telliamed@whoopdedo.cjb.net>
 *
 *    Permission is hereby granted, free of charge, to any person obtaining
 *    a copy of this software and associated documentation files (the 
 *    "Software"), to deal in the Software without restriction, including 
 *    without limitation the rights to use, copy, modify, merge, publish, 
 *    distribute, sublicense, and/or sell copies of the Software, and to 
 *    permit persons to whom the Software is furnished to do so.
 *    
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 *    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
 *    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-
 *    INFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS 
 *    BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN 
 *    AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR 
 *    IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
 *    THE SOFTWARE.
 *
 *****************************************************************************/
#include "Script.h"
#include "ScriptModule.h"

#include <lg/scrservices.h>

#include <cstring>
#include <new>
#include <exception>
#include <string>
#include <strings.h>
#include <stdio.h>
#include <windows.h>

#include <d3d9.h>
#include "d3d9hooks.h"

using namespace std;

/*** Direct3D9 hooks ***/

const Direct3DDevice9_Vtable *g_pOrig = NULL;

DIRECT3DDEVICE9_PRESENT_FN(Hooked_Present) {
    printf("Present\n");
    return g_pOrig->Present(This, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

DIRECT3DDEVICE9_BEGINSCENE_FN(Hooked_BeginScene) {
    printf("BeginScene\n");
    return g_pOrig->BeginScene(This);
}

DIRECT3DDEVICE9_ENDSCENE_FN(Hooked_EndScene) {
    printf("EndScene\n");
    return g_pOrig->EndScene(This);
}

IUNKNOWN_QUERYINTERFACE_FN(Hooked_QueryInterface) {
    printf("QueryInterface(%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X)\n",
        riid.Data1, (int)riid.Data2, (int)riid.Data3,
        (int)riid.Data4[0], (int)riid.Data4[1], (int)riid.Data4[2], (int)riid.Data4[3],
        (int)riid.Data4[4], (int)riid.Data4[5], (int)riid.Data4[6], (int)riid.Data4[7]);
    void *pvObj = NULL;
    HRESULT result = g_pOrig->QueryInterface(This, riid, &pvObj);
    *ppvObj = pvObj;
    printf("  returned %ld, -> %p\n", result, pvObj);
    return result;
}

#define ACTIVATE_HOOKS_AT 0 // 0: DLL attach, 1: OnSim, 2: OnDarkGameModeChange

void ActivateHooks(bool activate)
{
    printf("%s\n", activate ? "ACTIVATING HOOKS" : "DEACTIVATING HOOKS");

    IDirect3DDevice9* device = Dark_FindDirect3DDevice9Ptr();
    printf("d3d9demo: device is %p\n", device);
    if (activate) {
        Direct3DDevice9_Vtable hooks = {};
        hooks.QueryInterface = Hooked_QueryInterface;
        hooks.Present = Hooked_Present;
        hooks.BeginScene = Hooked_BeginScene;
        hooks.EndScene = Hooked_EndScene;
        HRESULT result = HookDirect3DDevice9(device, &hooks, &g_pOrig);
        printf("d3d9demo: HookDirect3DDevice9 returned %ld\n", result);
    } else {
        HRESULT result = UnhookDirect3DDevice9(device);
        printf("d3d9demo: UnhookDirect3DDevice9 returned %ld\n", result);
        g_pOrig = NULL;
    }
}

/*** Script class declarations (this will usually be in a header file) ***/

class cScr_Echo : public cScript
{
public:
    virtual ~cScr_Echo() { }
    cScr_Echo(const char* pszName, int iHostObjId)
        : cScript(pszName,iHostObjId)
    { }

    STDMETHOD_(long,ReceiveMessage)(sScrMsg*,sMultiParm*,eScrTraceAction);

public:
    static IScript* __cdecl ScriptFactory(const char* pszName, int iHostObjId);
};

/*** Script implementations ***/

long cScr_Echo::ReceiveMessage(sScrMsg* pMsg, sMultiParm* pReply, eScrTraceAction eTrace)
{
    long iRet = cScript::ReceiveMessage(pMsg, pReply, eTrace);

    try
    {
        string sOutput = pMsg->message;
        sOutput += "(";
        sOutput += static_cast<const char*>(pMsg->data);
        sOutput += ",";
        sOutput += static_cast<const char*>(pMsg->data2);
        sOutput += ",";
        sOutput += static_cast<const char*>(pMsg->data2);
        sOutput += ")";

        printf("%s\n", sOutput.c_str());

        int iTime = -1001;
        IPropertySrv* pProps = static_cast<IPropertySrv*>(g_pScriptManager->GetService(IID_IPropertyScriptService));
        if (pProps)
        {
            if (pProps->Possessed(m_iObjId, "ScriptTiming"))
            {
                cMultiParm mpTiming;
                pProps->Get(mpTiming, m_iObjId, "ScriptTiming", NULL);
                if (static_cast<int>(mpTiming) > 0)
                {
                    iTime = mpTiming;
                }
            }
            pProps->Release();
        }

        IDarkUISrv* pUI = static_cast<IDarkUISrv*>(g_pScriptManager->GetService(IID_IDarkUIScriptService));
        if (pUI)
        {
            pUI->TextMessage(sOutput.c_str(), 0, iTime);
            pUI->Release();
        }

    // OKAY! So. The _direct_ way of finding the device pointer doesn't work at BeginScript or Sim,
    // it's still null then. It does work after the first DarkGameModeChange, however. Hmm....
    if (strcasecmp(pMsg->message, "BeginScript") == 0) {
        printf("==== BeginScript: ====\n");
        printf("device: %p (indirect)\n", Dark_FindDirect3DDevice9Ptr());
        printf("device: %p (direct)\n", Dark_FindDirect3DDevice9Ptr_Direct());
    } else if (strcasecmp(pMsg->message, "Sim") == 0) {
        bool fStarting = ((sSimMsg*)pMsg)->fStarting;
        printf("==== Sim (fStarting=%s): ====\n", fStarting ? "true" : "false");
        printf("device: %p (indirect)\n", Dark_FindDirect3DDevice9Ptr());
        printf("device: %p (direct)\n", Dark_FindDirect3DDevice9Ptr_Direct());
#if ACTIVATE_HOOKS_AT == 1
        ActivateHooks(fStarting);
#endif
    } else if (strcasecmp(pMsg->message, "DarkGameModeChange") == 0) {
        bool fSuspending = ((sDarkGameModeScrMsg*)pMsg)->fSuspending;
        bool fResuming = ((sDarkGameModeScrMsg*)pMsg)->fResuming;
        printf("==== DarkGameModeChange (fSuspending=%s,fResuming=%s): ====\n",
            fSuspending ? "true" : "false",
            fResuming ? "true" : "false");
        printf("device: %p (indirect)\n", Dark_FindDirect3DDevice9Ptr());
        printf("device: %p (direct)\n", Dark_FindDirect3DDevice9Ptr_Direct());
#if ACTIVATE_HOOKS_AT == 2
        /// PROBLEM: on _start_, both resuming and suspending are false.
        /// AND: on _end_, both... yep, you guess it!
        // if (fResuming) {
        //     ActivateHooks(true);
        // } else if (fSuspending) {
        //     ActivateHooks(false);
        // }
        printf("I don't know if we're coming or going tbh\n");
#endif
    }

    }
    catch (exception& err)
    {
        // Don't pass exceptions out of the module.
        if (g_pfnMPrintf)
            g_pfnMPrintf("Error! %s\n", err.what());
    }

    return iRet;
}

/*** Script Factories ***/

IScript* cScr_Echo::ScriptFactory(const char* pszName, int iHostObjId)
{
    if (stricmp(pszName,"Echo") != 0)
        return NULL;

    // Use a static string, so I don't have to make a copy.
    cScr_Echo* pscrRet = new(nothrow) cScr_Echo("Echo", iHostObjId);
    return static_cast<IScript*>(pscrRet);
}

const sScrClassDesc cScriptModule::sm_ScriptsArray[] = {
    { "echo", "Echo", "CustomScript", cScr_Echo::ScriptFactory },
};
const unsigned int cScriptModule::sm_ScriptsArraySize = sizeof(sm_ScriptsArray)/sizeof(sm_ScriptsArray[0]);

/*** Entry point ***/

#define USE_CONSOLE 1

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
    switch (reason) {
    case DLL_PROCESS_ATTACH: {
#if USE_CONSOLE
        // Allocate a console for handy viewing.
        AllocConsole();
        freopen("CONOUT$", "w", stdout);

        // FIXME: for my convenience, let's put the console in
        //        a handy location.
        HWND hwnd = GetConsoleWindow();
        RECT rect;
        GetWindowRect(hwnd, &rect);
        int left = 1930;
        int top = 480;
        int width = (int)(rect.right - rect.left);
        int height = (int)(rect.bottom - rect.top);
        MoveWindow(hwnd, left, top, width, height, TRUE);
#endif //USE_CONSOLE

        printf("d3d9demo: DLL_PROCESS_ATTACH\n");
        printf("d3d9demo: EXE Base address: 0x%08x\n", (unsigned int)GetModuleHandle(NULL));
        printf("d3d9demo: DLL base address: 0x%08x\n", (unsigned int)hModule);
        printf("device: %p (indirect)\n", Dark_FindDirect3DDevice9Ptr());
        printf("device: %p (direct)\n", Dark_FindDirect3DDevice9Ptr_Direct());
        printf("\n");
#if ACTIVATE_HOOKS_AT == 0
        ActivateHooks(true);
#endif
    } break;
    case DLL_PROCESS_DETACH: {
#if ACTIVATE_HOOKS_AT == 0
        ActivateHooks(false);
#endif

#if USE_CONSOLE
        FreeConsole();
#endif //USE_CONSOLE
    } break;
    }
    return true;
}
