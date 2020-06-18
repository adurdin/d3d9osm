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

//#include "d3d9hooks.h"

using namespace std;


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

/*** Direct3D9 hooks ***/

// Direct3DDevice9_FnPtrs *g_pOrig = NULL;
//
// DIRECT3DDEVICE9_PRESENT_FN(Hooked_Present) {
//     printf("Present\n");
//     g_pOrig->Present(thisDevice, pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
// }

/*** Entry point ***/

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
    switch (reason) {
    case DLL_PROCESS_ATTACH: {
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

        // Now that we (hopefully) have somewhere for output to go,
        // we can print some useful messages.
        printf("d3d9demo: DLL_PROCESS_ATTACH\n");
        printf("d3d9demo: EXE Base address: 0x%08x\n", (unsigned int)GetModuleHandle(NULL));
        printf("d3d9demo: DLL base address: 0x%08x\n", (unsigned int)hModule);

        // Direct3DDevice9_FnPtrs hooks = {};
        // hooks.Present = Hooked_Present;
        // HRESULT result = InstallD3D9Hooks(&hooks, &g_pOrig);
        // printf("d3d9demo: InstallD3D9Hooks: %d\n", result);
    } break;
    case DLL_PROCESS_DETACH: {
        // HRESULT result = UninstallD3D9Hooks();
        // printf("d3d9demo: UninstallD3D9Hooks: %d\n", result);
        // g_pOrig = {};

        FreeConsole();
    } break;
    }
    return true;
}
