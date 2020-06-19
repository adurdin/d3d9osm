#pragma once

#ifndef DIRECT3D_VERSION
#error "You must #include <d3d9.h> before \"d3dhooks.h\""
#else

#define IUNKNOWN_QUERYINTERFACE_FN(NAME) HRESULT __stdcall (NAME)(IUnknown* This, REFIID riid, void** ppvObj)
#define IUNKNOWN_ADDREF_FN(NAME) ULONG __stdcall (NAME)(IUnknown* This)
#define IUNKNOWN_RELEASE_FN(NAME) ULONG __stdcall (NAME)(IUnknown* This)
#define DIRECT3DDEVICE9_TESTCOOPERATIVELEVEL_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This)
#define DIRECT3DDEVICE9_GETAVAILABLETEXTUREMEM_FN(NAME) UINT __stdcall (NAME)(IDirect3DDevice9* This)
#define DIRECT3DDEVICE9_EVICTMANAGEDRESOURCES_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This)
#define DIRECT3DDEVICE9_GETDIRECT3D_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3D9** ppD3D9)
#define DIRECT3DDEVICE9_GETDEVICECAPS_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DCAPS9* pCaps)
#define DIRECT3DDEVICE9_GETDISPLAYMODE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT iSwapChain,D3DDISPLAYMODE* pMode)
#define DIRECT3DDEVICE9_GETCREATIONPARAMETERS_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DDEVICE_CREATION_PARAMETERS *pParameters)
#define DIRECT3DDEVICE9_SETCURSORPROPERTIES_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT XHotSpot,UINT YHotSpot,IDirect3DSurface9* pCursorBitmap)
#define DIRECT3DDEVICE9_SETCURSORPOSITION_FN(NAME) void __stdcall (NAME)(IDirect3DDevice9* This, int X,int Y,DWORD Flags)
#define DIRECT3DDEVICE9_SHOWCURSOR_FN(NAME) BOOL __stdcall (NAME)(IDirect3DDevice9* This, BOOL bShow)
#define DIRECT3DDEVICE9_CREATEADDITIONALSWAPCHAIN_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DSwapChain9** pSwapChain)
#define DIRECT3DDEVICE9_GETSWAPCHAIN_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT iSwapChain,IDirect3DSwapChain9** pSwapChain)
#define DIRECT3DDEVICE9_GETNUMBEROFSWAPCHAINS_FN(NAME) UINT __stdcall (NAME)(IDirect3DDevice9* This)
#define DIRECT3DDEVICE9_RESET_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DPRESENT_PARAMETERS* pPresentationParameters)
#define DIRECT3DDEVICE9_PRESENT_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, CONST RECT* pSourceRect,CONST RECT* pDestRect,HWND hDestWindowOverride,CONST RGNDATA* pDirtyRegion)
#define DIRECT3DDEVICE9_GETBACKBUFFER_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT iSwapChain,UINT iBackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface9** ppBackBuffer)
#define DIRECT3DDEVICE9_GETRASTERSTATUS_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT iSwapChain,D3DRASTER_STATUS* pRasterStatus)
#define DIRECT3DDEVICE9_SETDIALOGBOXMODE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, BOOL bEnableDialogs)
#define DIRECT3DDEVICE9_SETGAMMARAMP_FN(NAME) void __stdcall (NAME)(IDirect3DDevice9* This, UINT iSwapChain,DWORD Flags,CONST D3DGAMMARAMP* pRamp)
#define DIRECT3DDEVICE9_GETGAMMARAMP_FN(NAME) void __stdcall (NAME)(IDirect3DDevice9* This, UINT iSwapChain,D3DGAMMARAMP* pRamp)
#define DIRECT3DDEVICE9_CREATETEXTURE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT Width,UINT Height,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DTexture9** ppTexture,HANDLE* pSharedHandle)
#define DIRECT3DDEVICE9_CREATEVOLUMETEXTURE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT Width,UINT Height,UINT Depth,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DVolumeTexture9** ppVolumeTexture,HANDLE* pSharedHandle)
#define DIRECT3DDEVICE9_CREATECUBETEXTURE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT EdgeLength,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DCubeTexture9** ppCubeTexture,HANDLE* pSharedHandle)
#define DIRECT3DDEVICE9_CREATEVERTEXBUFFER_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IDirect3DVertexBuffer9** ppVertexBuffer,HANDLE* pSharedHandle)
#define DIRECT3DDEVICE9_CREATEINDEXBUFFER_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT Length,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DIndexBuffer9** ppIndexBuffer,HANDLE* pSharedHandle)
#define DIRECT3DDEVICE9_CREATERENDERTARGET_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Lockable,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle)
#define DIRECT3DDEVICE9_CREATEDEPTHSTENCILSURFACE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Discard,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle)
#define DIRECT3DDEVICE9_UPDATESURFACE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestinationSurface,CONST POINT* pDestPoint)
#define DIRECT3DDEVICE9_UPDATETEXTURE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DBaseTexture9* pSourceTexture,IDirect3DBaseTexture9* pDestinationTexture)
#define DIRECT3DDEVICE9_GETRENDERTARGETDATA_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DSurface9* pRenderTarget,IDirect3DSurface9* pDestSurface)
#define DIRECT3DDEVICE9_GETFRONTBUFFERDATA_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT iSwapChain,IDirect3DSurface9* pDestSurface)
#define DIRECT3DDEVICE9_STRETCHRECT_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DSurface9* pSourceSurface,CONST RECT* pSourceRect,IDirect3DSurface9* pDestSurface,CONST RECT* pDestRect,D3DTEXTUREFILTERTYPE Filter)
#define DIRECT3DDEVICE9_COLORFILL_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DSurface9* pSurface,CONST RECT* pRect,D3DCOLOR color)
#define DIRECT3DDEVICE9_CREATEOFFSCREENPLAINSURFACE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT Width,UINT Height,D3DFORMAT Format,D3DPOOL Pool,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle)
#define DIRECT3DDEVICE9_SETRENDERTARGET_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD RenderTargetIndex,IDirect3DSurface9* pRenderTarget)
#define DIRECT3DDEVICE9_GETRENDERTARGET_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD RenderTargetIndex,IDirect3DSurface9** ppRenderTarget)
#define DIRECT3DDEVICE9_SETDEPTHSTENCILSURFACE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DSurface9* pNewZStencil)
#define DIRECT3DDEVICE9_GETDEPTHSTENCILSURFACE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DSurface9** ppZStencilSurface)
#define DIRECT3DDEVICE9_BEGINSCENE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This)
#define DIRECT3DDEVICE9_ENDSCENE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This)
#define DIRECT3DDEVICE9_CLEAR_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD Count,CONST D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil)
#define DIRECT3DDEVICE9_SETTRANSFORM_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DTRANSFORMSTATETYPE State,CONST D3DMATRIX* pMatrix)
#define DIRECT3DDEVICE9_GETTRANSFORM_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DTRANSFORMSTATETYPE State,D3DMATRIX* pMatrix)
#define DIRECT3DDEVICE9_MULTIPLYTRANSFORM_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DTRANSFORMSTATETYPE,CONST D3DMATRIX*)
#define DIRECT3DDEVICE9_SETVIEWPORT_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, CONST D3DVIEWPORT9* pViewport)
#define DIRECT3DDEVICE9_GETVIEWPORT_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DVIEWPORT9* pViewport)
#define DIRECT3DDEVICE9_SETMATERIAL_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, CONST D3DMATERIAL9* pMaterial)
#define DIRECT3DDEVICE9_GETMATERIAL_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DMATERIAL9* pMaterial)
#define DIRECT3DDEVICE9_SETLIGHT_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD Index,CONST D3DLIGHT9*)
#define DIRECT3DDEVICE9_GETLIGHT_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD Index,D3DLIGHT9*)
#define DIRECT3DDEVICE9_LIGHTENABLE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD Index,BOOL Enable)
#define DIRECT3DDEVICE9_GETLIGHTENABLE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD Index,BOOL* pEnable)
#define DIRECT3DDEVICE9_SETCLIPPLANE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD Index,CONST float* pPlane)
#define DIRECT3DDEVICE9_GETCLIPPLANE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD Index,float* pPlane)
#define DIRECT3DDEVICE9_SETRENDERSTATE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DRENDERSTATETYPE State,DWORD Value)
#define DIRECT3DDEVICE9_GETRENDERSTATE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DRENDERSTATETYPE State,DWORD* pValue)
#define DIRECT3DDEVICE9_CREATESTATEBLOCK_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DSTATEBLOCKTYPE Type,IDirect3DStateBlock9** ppSB)
#define DIRECT3DDEVICE9_BEGINSTATEBLOCK_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This)
#define DIRECT3DDEVICE9_ENDSTATEBLOCK_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DStateBlock9** ppSB)
#define DIRECT3DDEVICE9_SETCLIPSTATUS_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, CONST D3DCLIPSTATUS9* pClipStatus)
#define DIRECT3DDEVICE9_GETCLIPSTATUS_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DCLIPSTATUS9* pClipStatus)
#define DIRECT3DDEVICE9_GETTEXTURE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD Stage,IDirect3DBaseTexture9** ppTexture)
#define DIRECT3DDEVICE9_SETTEXTURE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD Stage,IDirect3DBaseTexture9* pTexture)
#define DIRECT3DDEVICE9_GETTEXTURESTAGESTATE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD* pValue)
#define DIRECT3DDEVICE9_SETTEXTURESTAGESTATE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD Value)
#define DIRECT3DDEVICE9_GETSAMPLERSTATE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD* pValue)
#define DIRECT3DDEVICE9_SETSAMPLERSTATE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD Value)
#define DIRECT3DDEVICE9_VALIDATEDEVICE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD* pNumPasses)
#define DIRECT3DDEVICE9_SETPALETTEENTRIES_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT PaletteNumber,CONST PALETTEENTRY* pEntries)
#define DIRECT3DDEVICE9_GETPALETTEENTRIES_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT PaletteNumber,PALETTEENTRY* pEntries)
#define DIRECT3DDEVICE9_SETCURRENTTEXTUREPALETTE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT PaletteNumber)
#define DIRECT3DDEVICE9_GETCURRENTTEXTUREPALETTE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT *PaletteNumber)
#define DIRECT3DDEVICE9_SETSCISSORRECT_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, CONST RECT* pRect)
#define DIRECT3DDEVICE9_GETSCISSORRECT_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, RECT* pRect)
#define DIRECT3DDEVICE9_SETSOFTWAREVERTEXPROCESSING_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, BOOL bSoftware)
#define DIRECT3DDEVICE9_GETSOFTWAREVERTEXPROCESSING_FN(NAME) BOOL __stdcall (NAME)(IDirect3DDevice9* This)
#define DIRECT3DDEVICE9_SETNPATCHMODE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, float nSegments)
#define DIRECT3DDEVICE9_GETNPATCHMODE_FN(NAME) float __stdcall (NAME)(IDirect3DDevice9* This)
#define DIRECT3DDEVICE9_DRAWPRIMITIVE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount)
#define DIRECT3DDEVICE9_DRAWINDEXEDPRIMITIVE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DPRIMITIVETYPE,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount)
#define DIRECT3DDEVICE9_DRAWPRIMITIVEUP_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
#define DIRECT3DDEVICE9_DRAWINDEXEDPRIMITIVEUP_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,CONST void* pIndexData,D3DFORMAT IndexDataFormat,CONST void* pVertexStreamZeroData,UINT VertexStreamZeroStride)
#define DIRECT3DDEVICE9_PROCESSVERTICES_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,IDirect3DVertexBuffer9* pDestBuffer,IDirect3DVertexDeclaration9* pVertexDecl,DWORD Flags)
#define DIRECT3DDEVICE9_CREATEVERTEXDECLARATION_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, CONST D3DVERTEXELEMENT9* pVertexElements,IDirect3DVertexDeclaration9** ppDecl)
#define DIRECT3DDEVICE9_SETVERTEXDECLARATION_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DVertexDeclaration9* pDecl)
#define DIRECT3DDEVICE9_GETVERTEXDECLARATION_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DVertexDeclaration9** ppDecl)
#define DIRECT3DDEVICE9_SETFVF_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD FVF)
#define DIRECT3DDEVICE9_GETFVF_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, DWORD* pFVF)
#define DIRECT3DDEVICE9_CREATEVERTEXSHADER_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, CONST DWORD* pFunction,IDirect3DVertexShader9** ppShader)
#define DIRECT3DDEVICE9_SETVERTEXSHADER_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DVertexShader9* pShader)
#define DIRECT3DDEVICE9_GETVERTEXSHADER_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DVertexShader9** ppShader)
#define DIRECT3DDEVICE9_SETVERTEXSHADERCONSTANTF_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount)
#define DIRECT3DDEVICE9_GETVERTEXSHADERCONSTANTF_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StartRegister,float* pConstantData,UINT Vector4fCount)
#define DIRECT3DDEVICE9_SETVERTEXSHADERCONSTANTI_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount)
#define DIRECT3DDEVICE9_GETVERTEXSHADERCONSTANTI_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StartRegister,int* pConstantData,UINT Vector4iCount)
#define DIRECT3DDEVICE9_SETVERTEXSHADERCONSTANTB_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount)
#define DIRECT3DDEVICE9_GETVERTEXSHADERCONSTANTB_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StartRegister,BOOL* pConstantData,UINT BoolCount)
#define DIRECT3DDEVICE9_SETSTREAMSOURCE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride)
#define DIRECT3DDEVICE9_GETSTREAMSOURCE_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StreamNumber,IDirect3DVertexBuffer9** ppStreamData,UINT* pOffsetInBytes,UINT* pStride)
#define DIRECT3DDEVICE9_SETSTREAMSOURCEFREQ_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StreamNumber,UINT Setting)
#define DIRECT3DDEVICE9_GETSTREAMSOURCEFREQ_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StreamNumber,UINT* pSetting)
#define DIRECT3DDEVICE9_SETINDICES_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DIndexBuffer9* pIndexData)
#define DIRECT3DDEVICE9_GETINDICES_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DIndexBuffer9** ppIndexData)
#define DIRECT3DDEVICE9_CREATEPIXELSHADER_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, CONST DWORD* pFunction,IDirect3DPixelShader9** ppShader)
#define DIRECT3DDEVICE9_SETPIXELSHADER_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DPixelShader9* pShader)
#define DIRECT3DDEVICE9_GETPIXELSHADER_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, IDirect3DPixelShader9** ppShader)
#define DIRECT3DDEVICE9_SETPIXELSHADERCONSTANTF_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StartRegister,CONST float* pConstantData,UINT Vector4fCount)
#define DIRECT3DDEVICE9_GETPIXELSHADERCONSTANTF_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StartRegister,float* pConstantData,UINT Vector4fCount)
#define DIRECT3DDEVICE9_SETPIXELSHADERCONSTANTI_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StartRegister,CONST int* pConstantData,UINT Vector4iCount)
#define DIRECT3DDEVICE9_GETPIXELSHADERCONSTANTI_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StartRegister,int* pConstantData,UINT Vector4iCount)
#define DIRECT3DDEVICE9_SETPIXELSHADERCONSTANTB_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StartRegister,CONST BOOL* pConstantData,UINT  BoolCount)
#define DIRECT3DDEVICE9_GETPIXELSHADERCONSTANTB_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT StartRegister,BOOL* pConstantData,UINT BoolCount)
#define DIRECT3DDEVICE9_DRAWRECTPATCH_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT Handle,CONST float* pNumSegs,CONST D3DRECTPATCH_INFO* pRectPatchInfo)
#define DIRECT3DDEVICE9_DRAWTRIPATCH_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT Handle,CONST float* pNumSegs,CONST D3DTRIPATCH_INFO* pTriPatchInfo)
#define DIRECT3DDEVICE9_DELETEPATCH_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, UINT Handle)
#define DIRECT3DDEVICE9_CREATEQUERY_FN(NAME) HRESULT __stdcall (NAME)(IDirect3DDevice9* This, D3DQUERYTYPE Type,IDirect3DQuery9** ppQuery)

typedef IUNKNOWN_QUERYINTERFACE_FN((*IUnknown_QueryInterface_FnPtr));
typedef IUNKNOWN_ADDREF_FN((*IUnknown_AddRef_FnPtr));
typedef IUNKNOWN_RELEASE_FN((*IUnknown_Release_FnPtr));
typedef DIRECT3DDEVICE9_TESTCOOPERATIVELEVEL_FN((*Direct3DDevice9_TestCooperativeLevel_FnPtr));
typedef DIRECT3DDEVICE9_GETAVAILABLETEXTUREMEM_FN((*Direct3DDevice9_GetAvailableTextureMem_FnPtr));
typedef DIRECT3DDEVICE9_EVICTMANAGEDRESOURCES_FN((*Direct3DDevice9_EvictManagedResources_FnPtr));
typedef DIRECT3DDEVICE9_GETDIRECT3D_FN((*Direct3DDevice9_GetDirect3D_FnPtr));
typedef DIRECT3DDEVICE9_GETDEVICECAPS_FN((*Direct3DDevice9_GetDeviceCaps_FnPtr));
typedef DIRECT3DDEVICE9_GETDISPLAYMODE_FN((*Direct3DDevice9_GetDisplayMode_FnPtr));
typedef DIRECT3DDEVICE9_GETCREATIONPARAMETERS_FN((*Direct3DDevice9_GetCreationParameters_FnPtr));
typedef DIRECT3DDEVICE9_SETCURSORPROPERTIES_FN((*Direct3DDevice9_SetCursorProperties_FnPtr));
typedef DIRECT3DDEVICE9_SETCURSORPOSITION_FN((*Direct3DDevice9_SetCursorPosition_FnPtr));
typedef DIRECT3DDEVICE9_SHOWCURSOR_FN((*Direct3DDevice9_ShowCursor_FnPtr));
typedef DIRECT3DDEVICE9_CREATEADDITIONALSWAPCHAIN_FN((*Direct3DDevice9_CreateAdditionalSwapChain_FnPtr));
typedef DIRECT3DDEVICE9_GETSWAPCHAIN_FN((*Direct3DDevice9_GetSwapChain_FnPtr));
typedef DIRECT3DDEVICE9_GETNUMBEROFSWAPCHAINS_FN((*Direct3DDevice9_GetNumberOfSwapChains_FnPtr));
typedef DIRECT3DDEVICE9_RESET_FN((*Direct3DDevice9_Reset_FnPtr));
typedef DIRECT3DDEVICE9_PRESENT_FN((*Direct3DDevice9_Present_FnPtr));
typedef DIRECT3DDEVICE9_GETBACKBUFFER_FN((*Direct3DDevice9_GetBackBuffer_FnPtr));
typedef DIRECT3DDEVICE9_GETRASTERSTATUS_FN((*Direct3DDevice9_GetRasterStatus_FnPtr));
typedef DIRECT3DDEVICE9_SETDIALOGBOXMODE_FN((*Direct3DDevice9_SetDialogBoxMode_FnPtr));
typedef DIRECT3DDEVICE9_SETGAMMARAMP_FN((*Direct3DDevice9_SetGammaRamp_FnPtr));
typedef DIRECT3DDEVICE9_GETGAMMARAMP_FN((*Direct3DDevice9_GetGammaRamp_FnPtr));
typedef DIRECT3DDEVICE9_CREATETEXTURE_FN((*Direct3DDevice9_CreateTexture_FnPtr));
typedef DIRECT3DDEVICE9_CREATEVOLUMETEXTURE_FN((*Direct3DDevice9_CreateVolumeTexture_FnPtr));
typedef DIRECT3DDEVICE9_CREATECUBETEXTURE_FN((*Direct3DDevice9_CreateCubeTexture_FnPtr));
typedef DIRECT3DDEVICE9_CREATEVERTEXBUFFER_FN((*Direct3DDevice9_CreateVertexBuffer_FnPtr));
typedef DIRECT3DDEVICE9_CREATEINDEXBUFFER_FN((*Direct3DDevice9_CreateIndexBuffer_FnPtr));
typedef DIRECT3DDEVICE9_CREATERENDERTARGET_FN((*Direct3DDevice9_CreateRenderTarget_FnPtr));
typedef DIRECT3DDEVICE9_CREATEDEPTHSTENCILSURFACE_FN((*Direct3DDevice9_CreateDepthStencilSurface_FnPtr));
typedef DIRECT3DDEVICE9_UPDATESURFACE_FN((*Direct3DDevice9_UpdateSurface_FnPtr));
typedef DIRECT3DDEVICE9_UPDATETEXTURE_FN((*Direct3DDevice9_UpdateTexture_FnPtr));
typedef DIRECT3DDEVICE9_GETRENDERTARGETDATA_FN((*Direct3DDevice9_GetRenderTargetData_FnPtr));
typedef DIRECT3DDEVICE9_GETFRONTBUFFERDATA_FN((*Direct3DDevice9_GetFrontBufferData_FnPtr));
typedef DIRECT3DDEVICE9_STRETCHRECT_FN((*Direct3DDevice9_StretchRect_FnPtr));
typedef DIRECT3DDEVICE9_COLORFILL_FN((*Direct3DDevice9_ColorFill_FnPtr));
typedef DIRECT3DDEVICE9_CREATEOFFSCREENPLAINSURFACE_FN((*Direct3DDevice9_CreateOffscreenPlainSurface_FnPtr));
typedef DIRECT3DDEVICE9_SETRENDERTARGET_FN((*Direct3DDevice9_SetRenderTarget_FnPtr));
typedef DIRECT3DDEVICE9_GETRENDERTARGET_FN((*Direct3DDevice9_GetRenderTarget_FnPtr));
typedef DIRECT3DDEVICE9_SETDEPTHSTENCILSURFACE_FN((*Direct3DDevice9_SetDepthStencilSurface_FnPtr));
typedef DIRECT3DDEVICE9_GETDEPTHSTENCILSURFACE_FN((*Direct3DDevice9_GetDepthStencilSurface_FnPtr));
typedef DIRECT3DDEVICE9_BEGINSCENE_FN((*Direct3DDevice9_BeginScene_FnPtr));
typedef DIRECT3DDEVICE9_ENDSCENE_FN((*Direct3DDevice9_EndScene_FnPtr));
typedef DIRECT3DDEVICE9_CLEAR_FN((*Direct3DDevice9_Clear_FnPtr));
typedef DIRECT3DDEVICE9_SETTRANSFORM_FN((*Direct3DDevice9_SetTransform_FnPtr));
typedef DIRECT3DDEVICE9_GETTRANSFORM_FN((*Direct3DDevice9_GetTransform_FnPtr));
typedef DIRECT3DDEVICE9_MULTIPLYTRANSFORM_FN((*Direct3DDevice9_MultiplyTransform_FnPtr));
typedef DIRECT3DDEVICE9_SETVIEWPORT_FN((*Direct3DDevice9_SetViewport_FnPtr));
typedef DIRECT3DDEVICE9_GETVIEWPORT_FN((*Direct3DDevice9_GetViewport_FnPtr));
typedef DIRECT3DDEVICE9_SETMATERIAL_FN((*Direct3DDevice9_SetMaterial_FnPtr));
typedef DIRECT3DDEVICE9_GETMATERIAL_FN((*Direct3DDevice9_GetMaterial_FnPtr));
typedef DIRECT3DDEVICE9_SETLIGHT_FN((*Direct3DDevice9_SetLight_FnPtr));
typedef DIRECT3DDEVICE9_GETLIGHT_FN((*Direct3DDevice9_GetLight_FnPtr));
typedef DIRECT3DDEVICE9_LIGHTENABLE_FN((*Direct3DDevice9_LightEnable_FnPtr));
typedef DIRECT3DDEVICE9_GETLIGHTENABLE_FN((*Direct3DDevice9_GetLightEnable_FnPtr));
typedef DIRECT3DDEVICE9_SETCLIPPLANE_FN((*Direct3DDevice9_SetClipPlane_FnPtr));
typedef DIRECT3DDEVICE9_GETCLIPPLANE_FN((*Direct3DDevice9_GetClipPlane_FnPtr));
typedef DIRECT3DDEVICE9_SETRENDERSTATE_FN((*Direct3DDevice9_SetRenderState_FnPtr));
typedef DIRECT3DDEVICE9_GETRENDERSTATE_FN((*Direct3DDevice9_GetRenderState_FnPtr));
typedef DIRECT3DDEVICE9_CREATESTATEBLOCK_FN((*Direct3DDevice9_CreateStateBlock_FnPtr));
typedef DIRECT3DDEVICE9_BEGINSTATEBLOCK_FN((*Direct3DDevice9_BeginStateBlock_FnPtr));
typedef DIRECT3DDEVICE9_ENDSTATEBLOCK_FN((*Direct3DDevice9_EndStateBlock_FnPtr));
typedef DIRECT3DDEVICE9_SETCLIPSTATUS_FN((*Direct3DDevice9_SetClipStatus_FnPtr));
typedef DIRECT3DDEVICE9_GETCLIPSTATUS_FN((*Direct3DDevice9_GetClipStatus_FnPtr));
typedef DIRECT3DDEVICE9_GETTEXTURE_FN((*Direct3DDevice9_GetTexture_FnPtr));
typedef DIRECT3DDEVICE9_SETTEXTURE_FN((*Direct3DDevice9_SetTexture_FnPtr));
typedef DIRECT3DDEVICE9_GETTEXTURESTAGESTATE_FN((*Direct3DDevice9_GetTextureStageState_FnPtr));
typedef DIRECT3DDEVICE9_SETTEXTURESTAGESTATE_FN((*Direct3DDevice9_SetTextureStageState_FnPtr));
typedef DIRECT3DDEVICE9_GETSAMPLERSTATE_FN((*Direct3DDevice9_GetSamplerState_FnPtr));
typedef DIRECT3DDEVICE9_SETSAMPLERSTATE_FN((*Direct3DDevice9_SetSamplerState_FnPtr));
typedef DIRECT3DDEVICE9_VALIDATEDEVICE_FN((*Direct3DDevice9_ValidateDevice_FnPtr));
typedef DIRECT3DDEVICE9_SETPALETTEENTRIES_FN((*Direct3DDevice9_SetPaletteEntries_FnPtr));
typedef DIRECT3DDEVICE9_GETPALETTEENTRIES_FN((*Direct3DDevice9_GetPaletteEntries_FnPtr));
typedef DIRECT3DDEVICE9_SETCURRENTTEXTUREPALETTE_FN((*Direct3DDevice9_SetCurrentTexturePalette_FnPtr));
typedef DIRECT3DDEVICE9_GETCURRENTTEXTUREPALETTE_FN((*Direct3DDevice9_GetCurrentTexturePalette_FnPtr));
typedef DIRECT3DDEVICE9_SETSCISSORRECT_FN((*Direct3DDevice9_SetScissorRect_FnPtr));
typedef DIRECT3DDEVICE9_GETSCISSORRECT_FN((*Direct3DDevice9_GetScissorRect_FnPtr));
typedef DIRECT3DDEVICE9_SETSOFTWAREVERTEXPROCESSING_FN((*Direct3DDevice9_SetSoftwareVertexProcessing_FnPtr));
typedef DIRECT3DDEVICE9_GETSOFTWAREVERTEXPROCESSING_FN((*Direct3DDevice9_GetSoftwareVertexProcessing_FnPtr));
typedef DIRECT3DDEVICE9_SETNPATCHMODE_FN((*Direct3DDevice9_SetNPatchMode_FnPtr));
typedef DIRECT3DDEVICE9_GETNPATCHMODE_FN((*Direct3DDevice9_GetNPatchMode_FnPtr));
typedef DIRECT3DDEVICE9_DRAWPRIMITIVE_FN((*Direct3DDevice9_DrawPrimitive_FnPtr));
typedef DIRECT3DDEVICE9_DRAWINDEXEDPRIMITIVE_FN((*Direct3DDevice9_DrawIndexedPrimitive_FnPtr));
typedef DIRECT3DDEVICE9_DRAWPRIMITIVEUP_FN((*Direct3DDevice9_DrawPrimitiveUP_FnPtr));
typedef DIRECT3DDEVICE9_DRAWINDEXEDPRIMITIVEUP_FN((*Direct3DDevice9_DrawIndexedPrimitiveUP_FnPtr));
typedef DIRECT3DDEVICE9_PROCESSVERTICES_FN((*Direct3DDevice9_ProcessVertices_FnPtr));
typedef DIRECT3DDEVICE9_CREATEVERTEXDECLARATION_FN((*Direct3DDevice9_CreateVertexDeclaration_FnPtr));
typedef DIRECT3DDEVICE9_SETVERTEXDECLARATION_FN((*Direct3DDevice9_SetVertexDeclaration_FnPtr));
typedef DIRECT3DDEVICE9_GETVERTEXDECLARATION_FN((*Direct3DDevice9_GetVertexDeclaration_FnPtr));
typedef DIRECT3DDEVICE9_SETFVF_FN((*Direct3DDevice9_SetFVF_FnPtr));
typedef DIRECT3DDEVICE9_GETFVF_FN((*Direct3DDevice9_GetFVF_FnPtr));
typedef DIRECT3DDEVICE9_CREATEVERTEXSHADER_FN((*Direct3DDevice9_CreateVertexShader_FnPtr));
typedef DIRECT3DDEVICE9_SETVERTEXSHADER_FN((*Direct3DDevice9_SetVertexShader_FnPtr));
typedef DIRECT3DDEVICE9_GETVERTEXSHADER_FN((*Direct3DDevice9_GetVertexShader_FnPtr));
typedef DIRECT3DDEVICE9_SETVERTEXSHADERCONSTANTF_FN((*Direct3DDevice9_SetVertexShaderConstantF_FnPtr));
typedef DIRECT3DDEVICE9_GETVERTEXSHADERCONSTANTF_FN((*Direct3DDevice9_GetVertexShaderConstantF_FnPtr));
typedef DIRECT3DDEVICE9_SETVERTEXSHADERCONSTANTI_FN((*Direct3DDevice9_SetVertexShaderConstantI_FnPtr));
typedef DIRECT3DDEVICE9_GETVERTEXSHADERCONSTANTI_FN((*Direct3DDevice9_GetVertexShaderConstantI_FnPtr));
typedef DIRECT3DDEVICE9_SETVERTEXSHADERCONSTANTB_FN((*Direct3DDevice9_SetVertexShaderConstantB_FnPtr));
typedef DIRECT3DDEVICE9_GETVERTEXSHADERCONSTANTB_FN((*Direct3DDevice9_GetVertexShaderConstantB_FnPtr));
typedef DIRECT3DDEVICE9_SETSTREAMSOURCE_FN((*Direct3DDevice9_SetStreamSource_FnPtr));
typedef DIRECT3DDEVICE9_GETSTREAMSOURCE_FN((*Direct3DDevice9_GetStreamSource_FnPtr));
typedef DIRECT3DDEVICE9_SETSTREAMSOURCEFREQ_FN((*Direct3DDevice9_SetStreamSourceFreq_FnPtr));
typedef DIRECT3DDEVICE9_GETSTREAMSOURCEFREQ_FN((*Direct3DDevice9_GetStreamSourceFreq_FnPtr));
typedef DIRECT3DDEVICE9_SETINDICES_FN((*Direct3DDevice9_SetIndices_FnPtr));
typedef DIRECT3DDEVICE9_GETINDICES_FN((*Direct3DDevice9_GetIndices_FnPtr));
typedef DIRECT3DDEVICE9_CREATEPIXELSHADER_FN((*Direct3DDevice9_CreatePixelShader_FnPtr));
typedef DIRECT3DDEVICE9_SETPIXELSHADER_FN((*Direct3DDevice9_SetPixelShader_FnPtr));
typedef DIRECT3DDEVICE9_GETPIXELSHADER_FN((*Direct3DDevice9_GetPixelShader_FnPtr));
typedef DIRECT3DDEVICE9_SETPIXELSHADERCONSTANTF_FN((*Direct3DDevice9_SetPixelShaderConstantF_FnPtr));
typedef DIRECT3DDEVICE9_GETPIXELSHADERCONSTANTF_FN((*Direct3DDevice9_GetPixelShaderConstantF_FnPtr));
typedef DIRECT3DDEVICE9_SETPIXELSHADERCONSTANTI_FN((*Direct3DDevice9_SetPixelShaderConstantI_FnPtr));
typedef DIRECT3DDEVICE9_GETPIXELSHADERCONSTANTI_FN((*Direct3DDevice9_GetPixelShaderConstantI_FnPtr));
typedef DIRECT3DDEVICE9_SETPIXELSHADERCONSTANTB_FN((*Direct3DDevice9_SetPixelShaderConstantB_FnPtr));
typedef DIRECT3DDEVICE9_GETPIXELSHADERCONSTANTB_FN((*Direct3DDevice9_GetPixelShaderConstantB_FnPtr));
typedef DIRECT3DDEVICE9_DRAWRECTPATCH_FN((*Direct3DDevice9_DrawRectPatch_FnPtr));
typedef DIRECT3DDEVICE9_DRAWTRIPATCH_FN((*Direct3DDevice9_DrawTriPatch_FnPtr));
typedef DIRECT3DDEVICE9_DELETEPATCH_FN((*Direct3DDevice9_DeletePatch_FnPtr));
typedef DIRECT3DDEVICE9_CREATEQUERY_FN((*Direct3DDevice9_CreateQuery_FnPtr));

struct Direct3DDevice9_Vtable {
    IUnknown_QueryInterface_FnPtr QueryInterface;
    IUnknown_AddRef_FnPtr AddRef;
    IUnknown_Release_FnPtr Release;
    Direct3DDevice9_TestCooperativeLevel_FnPtr TestCooperativeLevel;
    Direct3DDevice9_GetAvailableTextureMem_FnPtr GetAvailableTextureMem;
    Direct3DDevice9_EvictManagedResources_FnPtr EvictManagedResources;
    Direct3DDevice9_GetDirect3D_FnPtr GetDirect3D;
    Direct3DDevice9_GetDeviceCaps_FnPtr GetDeviceCaps;
    Direct3DDevice9_GetDisplayMode_FnPtr GetDisplayMode;
    Direct3DDevice9_GetCreationParameters_FnPtr GetCreationParameters;
    Direct3DDevice9_SetCursorProperties_FnPtr SetCursorProperties;
    Direct3DDevice9_SetCursorPosition_FnPtr SetCursorPosition;
    Direct3DDevice9_ShowCursor_FnPtr ShowCursor;
    Direct3DDevice9_CreateAdditionalSwapChain_FnPtr CreateAdditionalSwapChain;
    Direct3DDevice9_GetSwapChain_FnPtr GetSwapChain;
    Direct3DDevice9_GetNumberOfSwapChains_FnPtr GetNumberOfSwapChains;
    Direct3DDevice9_Reset_FnPtr Reset;
    Direct3DDevice9_Present_FnPtr Present;
    Direct3DDevice9_GetBackBuffer_FnPtr GetBackBuffer;
    Direct3DDevice9_GetRasterStatus_FnPtr GetRasterStatus;
    Direct3DDevice9_SetDialogBoxMode_FnPtr SetDialogBoxMode;
    Direct3DDevice9_SetGammaRamp_FnPtr SetGammaRamp;
    Direct3DDevice9_GetGammaRamp_FnPtr GetGammaRamp;
    Direct3DDevice9_CreateTexture_FnPtr CreateTexture;
    Direct3DDevice9_CreateVolumeTexture_FnPtr CreateVolumeTexture;
    Direct3DDevice9_CreateCubeTexture_FnPtr CreateCubeTexture;
    Direct3DDevice9_CreateVertexBuffer_FnPtr CreateVertexBuffer;
    Direct3DDevice9_CreateIndexBuffer_FnPtr CreateIndexBuffer;
    Direct3DDevice9_CreateRenderTarget_FnPtr CreateRenderTarget;
    Direct3DDevice9_CreateDepthStencilSurface_FnPtr CreateDepthStencilSurface;
    Direct3DDevice9_UpdateSurface_FnPtr UpdateSurface;
    Direct3DDevice9_UpdateTexture_FnPtr UpdateTexture;
    Direct3DDevice9_GetRenderTargetData_FnPtr GetRenderTargetData;
    Direct3DDevice9_GetFrontBufferData_FnPtr GetFrontBufferData;
    Direct3DDevice9_StretchRect_FnPtr StretchRect;
    Direct3DDevice9_ColorFill_FnPtr ColorFill;
    Direct3DDevice9_CreateOffscreenPlainSurface_FnPtr CreateOffscreenPlainSurface;
    Direct3DDevice9_SetRenderTarget_FnPtr SetRenderTarget;
    Direct3DDevice9_GetRenderTarget_FnPtr GetRenderTarget;
    Direct3DDevice9_SetDepthStencilSurface_FnPtr SetDepthStencilSurface;
    Direct3DDevice9_GetDepthStencilSurface_FnPtr GetDepthStencilSurface;
    Direct3DDevice9_BeginScene_FnPtr BeginScene;
    Direct3DDevice9_EndScene_FnPtr EndScene;
    Direct3DDevice9_Clear_FnPtr Clear;
    Direct3DDevice9_SetTransform_FnPtr SetTransform;
    Direct3DDevice9_GetTransform_FnPtr GetTransform;
    Direct3DDevice9_MultiplyTransform_FnPtr MultiplyTransform;
    Direct3DDevice9_SetViewport_FnPtr SetViewport;
    Direct3DDevice9_GetViewport_FnPtr GetViewport;
    Direct3DDevice9_SetMaterial_FnPtr SetMaterial;
    Direct3DDevice9_GetMaterial_FnPtr GetMaterial;
    Direct3DDevice9_SetLight_FnPtr SetLight;
    Direct3DDevice9_GetLight_FnPtr GetLight;
    Direct3DDevice9_LightEnable_FnPtr LightEnable;
    Direct3DDevice9_GetLightEnable_FnPtr GetLightEnable;
    Direct3DDevice9_SetClipPlane_FnPtr SetClipPlane;
    Direct3DDevice9_GetClipPlane_FnPtr GetClipPlane;
    Direct3DDevice9_SetRenderState_FnPtr SetRenderState;
    Direct3DDevice9_GetRenderState_FnPtr GetRenderState;
    Direct3DDevice9_CreateStateBlock_FnPtr CreateStateBlock;
    Direct3DDevice9_BeginStateBlock_FnPtr BeginStateBlock;
    Direct3DDevice9_EndStateBlock_FnPtr EndStateBlock;
    Direct3DDevice9_SetClipStatus_FnPtr SetClipStatus;
    Direct3DDevice9_GetClipStatus_FnPtr GetClipStatus;
    Direct3DDevice9_GetTexture_FnPtr GetTexture;
    Direct3DDevice9_SetTexture_FnPtr SetTexture;
    Direct3DDevice9_GetTextureStageState_FnPtr GetTextureStageState;
    Direct3DDevice9_SetTextureStageState_FnPtr SetTextureStageState;
    Direct3DDevice9_GetSamplerState_FnPtr GetSamplerState;
    Direct3DDevice9_SetSamplerState_FnPtr SetSamplerState;
    Direct3DDevice9_ValidateDevice_FnPtr ValidateDevice;
    Direct3DDevice9_SetPaletteEntries_FnPtr SetPaletteEntries;
    Direct3DDevice9_GetPaletteEntries_FnPtr GetPaletteEntries;
    Direct3DDevice9_SetCurrentTexturePalette_FnPtr SetCurrentTexturePalette;
    Direct3DDevice9_GetCurrentTexturePalette_FnPtr GetCurrentTexturePalette;
    Direct3DDevice9_SetScissorRect_FnPtr SetScissorRect;
    Direct3DDevice9_GetScissorRect_FnPtr GetScissorRect;
    Direct3DDevice9_SetSoftwareVertexProcessing_FnPtr SetSoftwareVertexProcessing;
    Direct3DDevice9_GetSoftwareVertexProcessing_FnPtr GetSoftwareVertexProcessing;
    Direct3DDevice9_SetNPatchMode_FnPtr SetNPatchMode;
    Direct3DDevice9_GetNPatchMode_FnPtr GetNPatchMode;
    Direct3DDevice9_DrawPrimitive_FnPtr DrawPrimitive;
    Direct3DDevice9_DrawIndexedPrimitive_FnPtr DrawIndexedPrimitive;
    Direct3DDevice9_DrawPrimitiveUP_FnPtr DrawPrimitiveUP;
    Direct3DDevice9_DrawIndexedPrimitiveUP_FnPtr DrawIndexedPrimitiveUP;
    Direct3DDevice9_ProcessVertices_FnPtr ProcessVertices;
    Direct3DDevice9_CreateVertexDeclaration_FnPtr CreateVertexDeclaration;
    Direct3DDevice9_SetVertexDeclaration_FnPtr SetVertexDeclaration;
    Direct3DDevice9_GetVertexDeclaration_FnPtr GetVertexDeclaration;
    Direct3DDevice9_SetFVF_FnPtr SetFVF;
    Direct3DDevice9_GetFVF_FnPtr GetFVF;
    Direct3DDevice9_CreateVertexShader_FnPtr CreateVertexShader;
    Direct3DDevice9_SetVertexShader_FnPtr SetVertexShader;
    Direct3DDevice9_GetVertexShader_FnPtr GetVertexShader;
    Direct3DDevice9_SetVertexShaderConstantF_FnPtr SetVertexShaderConstantF;
    Direct3DDevice9_GetVertexShaderConstantF_FnPtr GetVertexShaderConstantF;
    Direct3DDevice9_SetVertexShaderConstantI_FnPtr SetVertexShaderConstantI;
    Direct3DDevice9_GetVertexShaderConstantI_FnPtr GetVertexShaderConstantI;
    Direct3DDevice9_SetVertexShaderConstantB_FnPtr SetVertexShaderConstantB;
    Direct3DDevice9_GetVertexShaderConstantB_FnPtr GetVertexShaderConstantB;
    Direct3DDevice9_SetStreamSource_FnPtr SetStreamSource;
    Direct3DDevice9_GetStreamSource_FnPtr GetStreamSource;
    Direct3DDevice9_SetStreamSourceFreq_FnPtr SetStreamSourceFreq;
    Direct3DDevice9_GetStreamSourceFreq_FnPtr GetStreamSourceFreq;
    Direct3DDevice9_SetIndices_FnPtr SetIndices;
    Direct3DDevice9_GetIndices_FnPtr GetIndices;
    Direct3DDevice9_CreatePixelShader_FnPtr CreatePixelShader;
    Direct3DDevice9_SetPixelShader_FnPtr SetPixelShader;
    Direct3DDevice9_GetPixelShader_FnPtr GetPixelShader;
    Direct3DDevice9_SetPixelShaderConstantF_FnPtr SetPixelShaderConstantF;
    Direct3DDevice9_GetPixelShaderConstantF_FnPtr GetPixelShaderConstantF;
    Direct3DDevice9_SetPixelShaderConstantI_FnPtr SetPixelShaderConstantI;
    Direct3DDevice9_GetPixelShaderConstantI_FnPtr GetPixelShaderConstantI;
    Direct3DDevice9_SetPixelShaderConstantB_FnPtr SetPixelShaderConstantB;
    Direct3DDevice9_GetPixelShaderConstantB_FnPtr GetPixelShaderConstantB;
    Direct3DDevice9_DrawRectPatch_FnPtr DrawRectPatch;
    Direct3DDevice9_DrawTriPatch_FnPtr DrawTriPatch;
    Direct3DDevice9_DeletePatch_FnPtr DeletePatch;
    Direct3DDevice9_CreateQuery_FnPtr CreateQuery;
};

enum Direct3DDevice9_FnIndex
{
    Direct3DDevice9_QueryInterface_FnIndex = 0,
    Direct3DDevice9_AddRef_FnIndex = 1,
    Direct3DDevice9_Release_FnIndex = 2,
    Direct3DDevice9_TestCooperativeLevel_FnIndex = 3,
    Direct3DDevice9_GetAvailableTextureMem_FnIndex = 4,
    Direct3DDevice9_EvictManagedResources_FnIndex = 5,
    Direct3DDevice9_GetDirect3D_FnIndex = 6,
    Direct3DDevice9_GetDeviceCaps_FnIndex = 7,
    Direct3DDevice9_GetDisplayMode_FnIndex = 8,
    Direct3DDevice9_GetCreationParameters_FnIndex = 9,
    Direct3DDevice9_SetCursorProperties_FnIndex = 1,
    Direct3DDevice9_SetCursorPosition_FnIndex = 11,
    Direct3DDevice9_ShowCursor_FnIndex = 12,
    Direct3DDevice9_CreateAdditionalSwapChain_FnIndex = 13,
    Direct3DDevice9_GetSwapChain_FnIndex = 14,
    Direct3DDevice9_GetNumberOfSwapChains_FnIndex = 15,
    Direct3DDevice9_Reset_FnIndex = 16,
    Direct3DDevice9_Present_FnIndex = 17,
    Direct3DDevice9_GetBackBuffer_FnIndex = 18,
    Direct3DDevice9_GetRasterStatus_FnIndex = 19,
    Direct3DDevice9_SetDialogBoxMode_FnIndex = 2,
    Direct3DDevice9_SetGammaRamp_FnIndex = 21,
    Direct3DDevice9_GetGammaRamp_FnIndex = 22,
    Direct3DDevice9_CreateTexture_FnIndex = 23,
    Direct3DDevice9_CreateVolumeTexture_FnIndex = 24,
    Direct3DDevice9_CreateCubeTexture_FnIndex = 25,
    Direct3DDevice9_CreateVertexBuffer_FnIndex = 26,
    Direct3DDevice9_CreateIndexBuffer_FnIndex = 27,
    Direct3DDevice9_CreateRenderTarget_FnIndex = 28,
    Direct3DDevice9_CreateDepthStencilSurface_FnIndex = 29,
    Direct3DDevice9_UpdateSurface_FnIndex = 3,
    Direct3DDevice9_UpdateTexture_FnIndex = 31,
    Direct3DDevice9_GetRenderTargetData_FnIndex = 32,
    Direct3DDevice9_GetFrontBufferData_FnIndex = 33,
    Direct3DDevice9_StretchRect_FnIndex = 34,
    Direct3DDevice9_ColorFill_FnIndex = 35,
    Direct3DDevice9_CreateOffscreenPlainSurface_FnIndex = 36,
    Direct3DDevice9_SetRenderTarget_FnIndex = 37,
    Direct3DDevice9_GetRenderTarget_FnIndex = 38,
    Direct3DDevice9_SetDepthStencilSurface_FnIndex = 39,
    Direct3DDevice9_GetDepthStencilSurface_FnIndex = 4,
    Direct3DDevice9_BeginScene_FnIndex = 41,
    Direct3DDevice9_EndScene_FnIndex = 42,
    Direct3DDevice9_Clear_FnIndex = 43,
    Direct3DDevice9_SetTransform_FnIndex = 44,
    Direct3DDevice9_GetTransform_FnIndex = 45,
    Direct3DDevice9_MultiplyTransform_FnIndex = 46,
    Direct3DDevice9_SetViewport_FnIndex = 47,
    Direct3DDevice9_GetViewport_FnIndex = 48,
    Direct3DDevice9_SetMaterial_FnIndex = 49,
    Direct3DDevice9_GetMaterial_FnIndex = 5,
    Direct3DDevice9_SetLight_FnIndex = 51,
    Direct3DDevice9_GetLight_FnIndex = 52,
    Direct3DDevice9_LightEnable_FnIndex = 53,
    Direct3DDevice9_GetLightEnable_FnIndex = 54,
    Direct3DDevice9_SetClipPlane_FnIndex = 55,
    Direct3DDevice9_GetClipPlane_FnIndex = 56,
    Direct3DDevice9_SetRenderState_FnIndex = 57,
    Direct3DDevice9_GetRenderState_FnIndex = 58,
    Direct3DDevice9_CreateStateBlock_FnIndex = 59,
    Direct3DDevice9_BeginStateBlock_FnIndex = 6,
    Direct3DDevice9_EndStateBlock_FnIndex = 61,
    Direct3DDevice9_SetClipStatus_FnIndex = 62,
    Direct3DDevice9_GetClipStatus_FnIndex = 63,
    Direct3DDevice9_GetTexture_FnIndex = 64,
    Direct3DDevice9_SetTexture_FnIndex = 65,
    Direct3DDevice9_GetTextureStageState_FnIndex = 66,
    Direct3DDevice9_SetTextureStageState_FnIndex = 67,
    Direct3DDevice9_GetSamplerState_FnIndex = 68,
    Direct3DDevice9_SetSamplerState_FnIndex = 69,
    Direct3DDevice9_ValidateDevice_FnIndex = 7,
    Direct3DDevice9_SetPaletteEntries_FnIndex = 71,
    Direct3DDevice9_GetPaletteEntries_FnIndex = 72,
    Direct3DDevice9_SetCurrentTexturePalette_FnIndex = 73,
    Direct3DDevice9_GetCurrentTexturePalette_FnIndex = 74,
    Direct3DDevice9_SetScissorRect_FnIndex = 75,
    Direct3DDevice9_GetScissorRect_FnIndex = 76,
    Direct3DDevice9_SetSoftwareVertexProcessing_FnIndex = 77,
    Direct3DDevice9_GetSoftwareVertexProcessing_FnIndex = 78,
    Direct3DDevice9_SetNPatchMode_FnIndex = 79,
    Direct3DDevice9_GetNPatchMode_FnIndex = 8,
    Direct3DDevice9_DrawPrimitive_FnIndex = 81,
    Direct3DDevice9_DrawIndexedPrimitive_FnIndex = 82,
    Direct3DDevice9_DrawPrimitiveUP_FnIndex = 83,
    Direct3DDevice9_DrawIndexedPrimitiveUP_FnIndex = 84,
    Direct3DDevice9_ProcessVertices_FnIndex = 85,
    Direct3DDevice9_CreateVertexDeclaration_FnIndex = 86,
    Direct3DDevice9_SetVertexDeclaration_FnIndex = 87,
    Direct3DDevice9_GetVertexDeclaration_FnIndex = 88,
    Direct3DDevice9_SetFVF_FnIndex = 89,
    Direct3DDevice9_GetFVF_FnIndex = 9,
    Direct3DDevice9_CreateVertexShader_FnIndex = 91,
    Direct3DDevice9_SetVertexShader_FnIndex = 92,
    Direct3DDevice9_GetVertexShader_FnIndex = 93,
    Direct3DDevice9_SetVertexShaderConstantF_FnIndex = 94,
    Direct3DDevice9_GetVertexShaderConstantF_FnIndex = 95,
    Direct3DDevice9_SetVertexShaderConstantI_FnIndex = 96,
    Direct3DDevice9_GetVertexShaderConstantI_FnIndex = 97,
    Direct3DDevice9_SetVertexShaderConstantB_FnIndex = 98,
    Direct3DDevice9_GetVertexShaderConstantB_FnIndex = 99,
    Direct3DDevice9_SetStreamSource_FnIndex = 1,
    Direct3DDevice9_GetStreamSource_FnIndex = 11,
    Direct3DDevice9_SetStreamSourceFreq_FnIndex = 12,
    Direct3DDevice9_GetStreamSourceFreq_FnIndex = 13,
    Direct3DDevice9_SetIndices_FnIndex = 14,
    Direct3DDevice9_GetIndices_FnIndex = 15,
    Direct3DDevice9_CreatePixelShader_FnIndex = 16,
    Direct3DDevice9_SetPixelShader_FnIndex = 17,
    Direct3DDevice9_GetPixelShader_FnIndex = 18,
    Direct3DDevice9_SetPixelShaderConstantF_FnIndex = 19,
    Direct3DDevice9_GetPixelShaderConstantF_FnIndex = 11,
    Direct3DDevice9_SetPixelShaderConstantI_FnIndex = 111,
    Direct3DDevice9_GetPixelShaderConstantI_FnIndex = 112,
    Direct3DDevice9_SetPixelShaderConstantB_FnIndex = 113,
    Direct3DDevice9_GetPixelShaderConstantB_FnIndex = 114,
    Direct3DDevice9_DrawRectPatch_FnIndex = 115,
    Direct3DDevice9_DrawTriPatch_FnIndex = 116,
    Direct3DDevice9_DeletePatch_FnIndex = 117,
    Direct3DDevice9_CreateQuery_FnIndex = 118,

    Direct3DDevice9_FnIndex_Count,
};

/** HookDirect3DDevice9(device, pHooks, ppOrig):

    Hook the given device with the functions in pHooks, and return a pointer to the original vtable
    in ppOrig for hooks to call through to the original functions.

    For any functions you do not want to hook, put NULL in the corresponding entry in pHooks; the
    hooked device will use the original function pointer for that entry.

    If pHooks is NULL then the device will still be hooked, but will only have original functions;
    you can use SetHookedDirect3DDevice9Fn() to then hook and unhook functions individually.

    The pHooks pointer is not retained, so may safely point to a stack variable.

    ppOrig must not be NULL, and all your hooks should use it to call any functions on this device;
    you should not call This->Whatever(...) directly; instead call ppOrig->Whatever(This, ...).

    On success, HookDirect3DDevice9() will return S_OK.

    Only one device may be hooked at any given time; if you try to hook a second device before
    unhooking the first, HookDirect3DDevice9() will return E_FAIL.

    No guarantees whatsoever are made concerning thread safety.
*/
extern HRESULT HookDirect3DDevice9(IDirect3DDevice9* device, Direct3DDevice9_Vtable const * pHooks, Direct3DDevice9_Vtable const ** ppOrig);

/** UnhookDirect3DDevice9(device):

    Unhook the given device; all its functions will be restored to their originals.

    On success, UnhookDirect3DDevice9() will return S_OK.

    If the device is not already hooked, UnhookDirect3DDevice9() will return E_FAIL.

    No guarantees whatsoever are made concerning thread safety.
*/
extern HRESULT UnhookDirect3DDevice9(IDirect3DDevice9* device);

/** IsHookedDirect3DDevice9(device):

    Indicate if the given device is currently hooked or not.
*/
extern BOOL IsHookedDirect3DDevice9(IDirect3DDevice9* device);

/** SetHookedDirect3DDevice9Fn(device, index, fn):

    Replace the function at the given index of the hooked device's vtable with fn.

    You must ensure you pass the right type of function for the index.

    If fn is NULL, this will restore the original function - from IDirect3DDevice9,
    that is, not the previous hook (if any).

    On success, SetHookedDirect3DDevice9Fn() will return S_OK.

    If the device is not already hooked, SetHookedDirect3DDevice9Fn() will return E_FAIL.

    No guarantees whatsoever are made concerning thread safety.
*/
extern HRESULT SetHookedDirect3DDevice9Fn(IDirect3DDevice9* device, Direct3DDevice9_FnIndex index, void *fn);

/** Dark_FindDirect3DDevice9Ptr():

    Return the Direct3D9 device used by the game.

    If the game could not be recognised, or the device could not be found, then
    Dark_FindDirect3DDevice9Ptr will return NULL.
*/
extern IDirect3DDevice9* Dark_FindDirect3DDevice9Ptr();

#endif
