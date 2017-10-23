/*==========================================================================;
 *
 *  Copyright (C) Microsoft Corporation.  All Rights Reserved.
 *
 *  File:   d3d9.h
 *  Content:    Direct3D include file
 *
 ****************************************************************************/

#ifndef D3D9_H
#define D3D9_H

#ifndef DIRECT3D_VERSION
	#define DIRECT3D_VERSION         0x0900
#endif  //DIRECT3D_VERSION

#IFDEF LINKFILES
	#dynamiclinkfile d3d9.dll
#ENDIF

/* This identifier is passed to Direct3DCreate9 in order to ensure that an
 * application was built against the correct header files. This number is
 * incremented whenever a header (or other) change would require applications
 * to be rebuilt. If the version doesn't match, Direct3DCreate9 will fail.
 * (The number itself has no meaning.)
 */

#ifdef D3D_DEBUG_INFO
	#define D3D_SDK_VERSION   (32 | 0x80000000)
	#define D3D9b_SDK_VERSION (31 | 0x80000000)
#else
	#define D3D_SDK_VERSION   32
	#define D3D9b_SDK_VERSION 31
#endif

#IFNDEF WINDOWS_H
	#include "windows.h"
#ENDIF

#DEFINE GUID_IID_IDirect3D9 <0x81bdcbca, 0x64d4, 0x426d, <0xae, 0x8d, 0xad, 0x1, 0x47, 0xf4, 0x27, 0x5c>>
#DEFINE GUID_IID_IDirect3DDevice9 <0xd0223b96, 0xbf7a, 0x43fd, <0x92, 0xbd, 0xa4, 0x3b, 0xd, 0x82, 0xb9, 0xeb>>
#DEFINE GUID_IID_IDirect3DResource9 <0x5eec05d, 0x8f7d, 0x4362, <0xb9, 0x99, 0xd1, 0xba, 0xf3, 0x57, 0xc7, 0x4>>
#DEFINE GUID_IID_IDirect3DBaseTexture <0x580ca87e, 0x1d3c, 0x4d54, <0x99, 0x1d, 0xb7, 0xd3, 0xe3, 0xc2, 0x98, 0xce>>
#DEFINE GUID_IID_IDirect3DTexture9 <0x85c31227, 0x3de5, 0x4f00, <0x9b, 0x3a, 0xf1, 0x1a, 0xc3, 0x8c, 0x18, 0xb5>>
#DEFINE GUID_IID_IDirect3DCubeTexture9 <0xfff32f81, 0xd953, 0x473a, <0x92, 0x23, 0x93, 0xd6, 0x52, 0xab, 0xa9, 0x3f>>
#DEFINE GUID_IID_IDirect3DVolumeTexture9 <0x2518526c, 0xe789, 0x4111, <0xa7, 0xb9, 0x47, 0xef, 0x32, 0x8d, 0x13, 0xe6>>
#DEFINE GUID_IID_IDirect3DVertexBuffer9 <0xb64bb1b5, 0xfd70, 0x4df6, <0xbf, 0x91, 0x19, 0xd0, 0xa1, 0x24, 0x55, 0xe3>>
#DEFINE GUID_IID_IDirect3DIndexBuffer9 <0x7c9dd65e, 0xd3f7, 0x4529, <0xac, 0xee, 0x78, 0x58, 0x30, 0xac, 0xde, 0x35>>
#DEFINE GUID_IID_IDirect3DSurface9 <0xcfbaf3a, 0x9ff6, 0x429a, <0x99, 0xb3, 0xa2, 0x79, 0x6a, 0xf8, 0xb8, 0x9b>>
#DEFINE GUID_IID_IDirect3DVolume9 <0x24f416e6, 0x1f67, 0x4aa7, <0xb8, 0x8e, 0xd3, 0x3f, 0x6f, 0x31, 0x28, 0xa1>>
#DEFINE GUID_IID_IDirect3DSwapChain9 <0x794950f2, 0xadfc, 0x458a, <0x90, 0x5e, 0x10, 0xa1, 0xb, 0xb, 0x50, 0x3b>>
#DEFINE GUID_IID_IDirect3DVertexDeclaration9 <0xdd13c59c, 0x36fa, 0x4098, <0xa8, 0xfb, 0xc7, 0xed, 0x39, 0xdc, 0x85, 0x46>>
#DEFINE GUID_IID_IDirect3DVertexShader9 <0xefc5557e, 0x6265, 0x4613, <0x8a, 0x94, 0x43, 0x85, 0x78, 0x89, 0xeb, 0x36>>
#DEFINE GUID_IID_IDirect3DPixelShader9 <0x6d3bdbdc, 0x5b02, 0x4415, <0xb8, 0x52, 0xce, 0x5e, 0x8b, 0xcc, 0xb2, 0x89>>
#DEFINE GUID_IID_IDirect3DStateBlock9 <0xb07c4fe5, 0x310d, 0x4ba8, <0xa2, 0x3c, 0x4f, 0xf, 0x20, 0x6f, 0x21, 0x8b>>
#DEFINE GUID_IID_IDirect3DQuery9 <0xd9771460, 0xa695, 0x4f26, <0xbb, 0xd3, 0x27, 0xb8, 0x40, 0xb5, 0x41, 0xcc>>
#DEFINE GUID_IID_HelperName <0xe4a36723, 0xfdfe, 0x4b22, <0xb1, 0x46, 0x3c, 0x4, 0xc0, 0x7f, 0x4c, 0xc8>>
#DEFINE GUID_IID_IDirect3D9Ex <0x02177241, 0x69FC, 0x400C, <0x8F, 0xF1, 0x93, 0xA4, 0x4D, 0xF6, 0x86, 0x1D>>
#DEFINE GUID_IID_IDirect3DDevice9Ex <0xb18b10ce, 0x2649, 0x405a, <0x87, 0xf, 0x95, 0xf7, 0x77, 0xd4, 0x31, 0x3a>>
#DEFINE GUID_IID_IDirect3DSwapChain9Ex <0x91886caf, 0x1c3d, 0x4d2e, <0xa0, 0xab, 0x3e, 0x4c, 0x7d, 0x8d, 0x33, 0x3>>
#DEFINE GUID_IID_IDirect3D9ExOverlayExtension <0x187aeb13, 0xaaf5, 0x4c59, <0x87, 0x6d, 0xe0, 0x59, 0x8, 0x8c, 0xd, 0xf8>>
#DEFINE GUID_IID_IDirect3DDevice9Video <0x26dc4561, 0xa1ee, 0x4ae7, <0x96, 0xda, 0x11, 0x8a, 0x36, 0xc0, 0xec, 0x95>>
#DEFINE GUID_IID_IDirect3DAuthenticatedChannel9 <0xff24beee, 0xda21, 0x4beb, <0x98, 0xb5, 0xd2, 0xf8, 0x99, 0xf9, 0x8a, 0xf9>>
#DEFINE GUID_IID_IDirect3DCryptoSession9 <0xfa0ab799, 0x7a9c, 0x48ca, <0x8c, 0x5b, 0x23, 0x7e, 0x71, 0xa5, 0x44, 0x34>>

#IFNDEF D3D9TYPES_H
	#include "d3d9types.h"
#ENDIF
#IFNDEF D3D9CAPS_H
	#include "d3d9caps.h"
#ENDIF

IDirect3D9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	RegisterSoftwareDevice PTR
	GetAdapterCount PTR
	GetAdapterIdentifier PTR
	GetAdapterModeCount PTR
	EnumAdapterModes PTR
	GetAdapterDisplayMode PTR
	CheckDeviceType PTR
	CheckDeviceFormat PTR
	CheckDeviceMultiSampleType PTR
	CheckDepthStencilMatch PTR
	CheckDeviceFormatConversion PTR
	GetDeviceCaps PTR
	GetAdapterMonitor PTR
	CreateDevice PTR
ENDS

IDirect3DDevice9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	TestCooperativeLevel PTR
	GetAvailableTextureMem PTR
	EvictManagedResources PTR
	GetDirect3D PTR
	GetDeviceCaps PTR
	GetDisplayMode PTR
	GetCreationParameters PTR
	SetCursorProperties PTR
	SetCursorPosition PTR
	ShowCursor PTR
	CreateAdditionalSwapChain PTR
	GetSwapChain PTR
	GetNumberOfSwapChains PTR
	Reset PTR
	Present PTR
	GetBackBuffer PTR
	GetRasterStatus PTR
	SetDialogBoxMode PTR
	SetGammaRamp PTR
	GetGammaRamp PTR
	CreateTexture PTR
	CreateVolumeTexture PTR
	CreateCubeTexture PTR
	CreateVertexBuffer PTR
	CreateIndexBuffer PTR
	CreateRenderTarget PTR
	CreateDepthStencilSurface PTR
	UpdateSurface PTR
	UpdateTexture PTR
	GetRenderTargetData PTR
	GetFrontBufferData PTR
	StretchRect PTR
	ColorFill PTR
	CreateOffscreenPlainSurface PTR
	SetRenderTarget PTR
	GetRenderTarget PTR
	SetDepthStencilSurface PTR
	GetDepthStencilSurface PTR
	BeginScene PTR
	EndScene PTR
	Clear PTR
	SetTransform PTR
	GetTransform PTR
	MultiplyTransform PTR
	SetViewport PTR
	GetViewport PTR
	SetMaterial PTR
	GetMaterial PTR
	SetLight PTR
	GetLight PTR
	LightEnable PTR
	GetLightEnable PTR
	SetClipPlane PTR
	GetClipPlane PTR
	SetRenderState PTR
	GetRenderState PTR
	CreateStateBlock PTR
	BeginStateBlock PTR
	EndStateBlock PTR
	SetClipStatus PTR
	GetClipStatus PTR
	GetTexture PTR
	SetTexture PTR
	GetTextureStageState PTR
	SetTextureStageState PTR
	GetSamplerState PTR
	SetSamplerState PTR
	ValidateDevice PTR
	SetPaletteEntries PTR
	GetPaletteEntries PTR
	SetCurrentTexturePalette PTR
	GetCurrentTexturePalette PTR
	SetScissorRect PTR
	GetScissorRect PTR
	SetSoftwareVertexProcessing PTR
	GetSoftwareVertexProcessing PTR
	SetNPatchMode PTR
	GetNPatchMode PTR
	DrawPrimitive PTR
	DrawIndexedPrimitive PTR
	DrawPrimitiveUP PTR
	DrawIndexedPrimitiveUP PTR
	ProcessVertices PTR
	CreateVertexDeclaration PTR
	SetVertexDeclaration PTR
	GetVertexDeclaration PTR
	SetFVF PTR
	GetFVF PTR
	CreateVertexShader PTR
	SetVertexShader PTR
	GetVertexShader PTR
	SetVertexShaderConstantF PTR
	GetVertexShaderConstantF PTR
	SetVertexShaderConstantI PTR
	GetVertexShaderConstantI PTR
	SetVertexShaderConstantB PTR
	GetVertexShaderConstantB PTR
	SetStreamSource PTR
	GetStreamSource PTR
	SetStreamSourceFreq PTR
	GetStreamSourceFreq PTR
	SetIndices PTR
	GetIndices PTR
	CreatePixelShader PTR
	SetPixelShader PTR
	GetPixelShader PTR
	SetPixelShaderConstantF PTR
	GetPixelShaderConstantF PTR
	SetPixelShaderConstantI PTR
	GetPixelShaderConstantI PTR
	SetPixelShaderConstantB PTR
	GetPixelShaderConstantB PTR
	DrawRectPatch PTR
	DrawTriPatch PTR
	DeletePatch PTR
	CreateQuery PTR
	#ifdef D3D_DEBUG_INFO
		CreationParameters D3DDEVICE_CREATION_PARAMETERS
		PresentParameters D3DPRESENT_PARAMETERS
		DisplayMode D3DDISPLAYMODE
		Caps D3DCAPS9
		AvailableTextureMem DD
		SwapChains DD
		Textures DD
		VertexBuffers DD
		IndexBuffers DD
		VertexShaders DD
		PixelShaders DD
		Viewport D3DVIEWPORT9
		ProjectionMatrix D3DMATRIX
		ViewMatrix D3DMATRIX
		WorldMatrix D3DMATRIX
		TextureMatrices D3DMATRIX 8 DUP
		FVF DD
		VertexSize DD
		VertexShaderVersion DD
		PixelShaderVersion DD
		SoftwareVertexProcessing BOOL
		Material D3DMATERIAL9
		Lights D3DLIGHT9 16 DUP
		LightsEnabled BOOL 16 DUP
		GammaRamp D3DGAMMARAMP
		ScissorRect RECT
		DialogBoxMode BOOL
	#endif
ENDS

IDirect3DStateBlock9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDevice PTR
	Capture PTR
	Apply PTR
    #ifdef D3D_DEBUG_INFO
		CreationCallStack PTR
    #endif
ENDS

IDirect3DSwapChain9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Present PTR
	GetFrontBufferData PTR
	GetBackBuffer PTR
	GetRasterStatus PTR
	GetDisplayMode PTR
	GetDevice PTR
	GetPresentParameters PTR
	#ifdef D3D_DEBUG_INFO
		PresentParameters D3DPRESENT_PARAMETERS
		DisplayMode D3DDISPLAYMODE
		CreationCallStack PTR
	#endif
ENDS

IDirect3DResource9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDevice PTR
	SetPrivateData PTR
	GetPrivateData PTR
	FreePrivateData PTR
	SetPriority PTR
	GetPriority PTR
	PreLoad PTR
	GetType PTR
ENDS

IDirect3DVertexDeclaration9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDevice PTR
	GetDeclaration PTR
	#ifdef D3D_DEBUG_INFO
		CreationCallStack PTR
	#endif
ENDS

IDirect3DVertexShader9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDevice PTR
	GetFunction PTR
	#ifdef D3D_DEBUG_INFO
		Version DD
		CreationCallStack PTR
	#endif
ENDS

IDirect3DPixelShader9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDevice PTR
	GetFunction PTR
	#ifdef D3D_DEBUG_INFO
		Version DD
		CreationCallStack PTR
	#endif
ENDS

IDirect3DBaseTexture9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDevice PTR
	SetPrivateData PTR
	GetPrivateData PTR
	FreePrivateData PTR
	SetPriority PTR
	GetPriority PTR
	PreLoad PTR
	GetType PTR
	SetLOD PTR
	GetLOD PTR
	GetLevelCount PTR
	SetAutoGenFilterType PTR
	GetAutoGenFilterType PTR
	GenerateMipSubLevels PTR
ENDS

IDirect3DTexture9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDevice PTR
	SetPrivateData PTR
	GetPrivateData PTR
	FreePrivateData PTR
	SetPriority PTR
	GetPriority PTR
	PreLoad PTR
	GetType PTR
	SetLOD PTR
	GetLOD PTR
	GetLevelCount PTR
	SetAutoGenFilterType PTR
	GetAutoGenFilterType PTR
	GenerateMipSubLevels PTR
	GetLevelDesc PTR
	GetSurfaceLevel PTR
	LockRect PTR
	UnlockRect PTR
	AddDirtyRect PTR
	#ifdef D3D_DEBUG_INFO
		Name PTR
		Width DD
		Height DD
		Levels DD
		Usage DD
		Format ENUM // D3DFORMAT
		Pool ENUM // D3DPOOL
		Priority DD
		LOD DD
		FilterType ENUM // D3DTEXTUREFILTERTYPE
		LockCount DD
		CreationCallStack PTR
	#endif
ENDS

IDirect3DVolumeTexture9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDevice PTR
	SetPrivateData PTR
	GetPrivateData PTR
	FreePrivateData PTR
	SetPriority PTR
	GetPriority PTR
	PreLoad PTR
	GetType PTR
	SetLOD PTR
	GetLOD PTR
	GetLevelCount PTR
	SetAutoGenFilterType PTR
	GetAutoGenFilterType PTR
	GenerateMipSubLevels PTR
	GetLevelDesc PTR
	GetVolumeLevel PTR
	LockBox PTR
	UnlockBox PTR
	AddDirtyBox PTR
	#ifdef D3D_DEBUG_INFO
		Name PTR
		Width DD
		Height DD
		Levels DD
		Usage DD
		Format ENUM // D3DFORMAT
		Pool ENUM // D3DPOOL
		Priority DD
		LOD DD
		FilterType ENUM // D3DTEXTUREFILTERTYPE
		LockCount DD
		CreationCallStack PTR
	#endif
ENDS

IDirect3DCubeTexture9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDevice PTR
	SetPrivateData PTR
	GetPrivateData PTR
	FreePrivateData PTR
	SetPriority PTR
	GetPriority PTR
	PreLoad PTR
	GetType PTR
	SetLOD PTR
	GetLOD PTR
	GetLevelCount PTR
	SetAutoGenFilterType PTR
	GetAutoGenFilterType PTR
	GenerateMipSubLevels PTR
	GetLevelDesc PTR
	GetCubeMapSurface PTR
	LockRect PTR
	UnlockRect PTR
	AddDirtyRect PTR
	#ifdef D3D_DEBUG_INFO
		Name PTR
		Width DD
		Height DD
		Levels DD
		Usage DD
		Format ENUM // D3DFORMAT
		Pool ENUM // D3DPOOL
		Priority DD
		LOD DD
		FilterType ENUM // D3DTEXTUREFILTERTYPE
		LockCount DD
		CreationCallStack PTR
	#endif
ENDS

IDirect3DVertexBuffer9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDevice PTR
	SetPrivateData PTR
	GetPrivateData PTR
	FreePrivateData PTR
	SetPriority PTR
	GetPriority PTR
	PreLoad PTR
	GetType PTR
	Lock PTR
	Unlock PTR
	GetDesc PTR
	#ifdef D3D_DEBUG_INFO
		Name PTR
		Length DD
		Usage DD
		FVF DD
		Pool ENUM // D3DPOOL
		Priority DD
		LockCount DD
		CreationCallStack PTR
	#endif
ENDS

IDirect3DIndexBuffer9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDevice PTR
	SetPrivateData PTR
	GetPrivateData PTR
	FreePrivateData PTR
	SetPriority PTR
	GetPriority PTR
	PreLoad PTR
	GetType PTR
	Lock PTR
	Unlock PTR
	GetDesc PTR
	#ifdef D3D_DEBUG_INFO
		Name PTR
		Length DD
		Usage DD
		Format ENUM // D3DFORMAT
		Pool ENUM // D3DPOOL
		Priority DD
		LockCount DD
		CreationCallStack PTR
	#endif
ENDS

IDirect3DSurface9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDevice PTR
	SetPrivateData PTR
	GetPrivateData PTR
	FreePrivateData PTR
	SetPriority PTR
	GetPriority PTR
	PreLoad PTR
	GetType PTR
	GetContainer PTR
	GetDesc PTR
	LockRect PTR
	UnlockRect PTR
	GetDC PTR
	ReleaseDC PTR
	#ifdef D3D_DEBUG_INFO
		Name PTR
		Width DD
		Height DD
		Usage DD
		Format ENUM  // D3DFORMAT
		Pool ENUM // D3DPOOL
		MultiSampleType ENUM // D3DMULTISAMPLE_TYPE
		MultiSampleQuality DD
		Priority DD
		LockCount DD
		DCCount DD
		CreationCallStack PTR
	#endif
ENDS

IDirect3DVolume9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDevice PTR
	SetPrivateData PTR
	GetPrivateData PTR
	FreePrivateData PTR
	GetContainer PTR
	GetDesc PTR
	LockBox PTR
	UnlockBox PTR
	#ifdef D3D_DEBUG_INFO
		Name PTR
		Width DD
		Height DD
		Depth DD
		Usage DD
		Format ENUM // D3DFORMAT
		Pool ENUM // D3DPOOL
		LockCount DD
		CreationCallStack PTR
	#endif
ENDS

IDirect3DQuery9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDevice PTR
	GetType PTR
	GetDataSize PTR
	Issue PTR
	GetData PTR
	#ifdef D3D_DEBUG_INFO
		Type ENUM // D3DQUERYTYPE
		DataSize DD
		CreationCallStack PTR
	#endif
ENDS

#define D3DSPD_IUNKNOWN                         0x00000001
#define D3DCREATE_FPU_PRESERVE                  0x00000002
#define D3DCREATE_MULTITHREADED                 0x00000004
#define D3DCREATE_PUREDEVICE                    0x00000010
#define D3DCREATE_SOFTWARE_VERTEXPROCESSING     0x00000020
#define D3DCREATE_HARDWARE_VERTEXPROCESSING     0x00000040
#define D3DCREATE_MIXED_VERTEXPROCESSING        0x00000080
#define D3DCREATE_DISABLE_DRIVER_MANAGEMENT     0x00000100
#define D3DCREATE_ADAPTERGROUP_DEVICE           0x00000200
#define D3DCREATE_DISABLE_DRIVER_MANAGEMENT_EX  0x00000400
#define D3DCREATE_NOWINDOWCHANGES				0x00000800
#define D3DCREATE_DISABLE_PSGP_THREADING        0x00002000
#define D3DCREATE_ENABLE_PRESENTSTATS           0x00004000
#define D3DCREATE_DISABLE_PRINTSCREEN           0x00008000
#define D3DCREATE_SCREENSAVER                   0x10000000
#define D3DADAPTER_DEFAULT                      0
#define D3DENUM_WHQL_LEVEL                      0x00000002
#define D3DENUM_NO_DRIVERVERSION                0x00000004
#define D3DPRESENT_BACK_BUFFERS_MAX             3
#define D3DPRESENT_BACK_BUFFERS_MAX_EX          30
#define D3DSGR_NO_CALIBRATION                  0x00000000
#define D3DSGR_CALIBRATE                       0x00000001
#define D3DCURSOR_IMMEDIATE_UPDATE             0x00000001
#define D3DPRESENT_DONOTWAIT                   0x00000001
#define D3DPRESENT_LINEAR_CONTENT              0x00000002
#define D3DPRESENT_DONOTFLIP                   0x00000004
#define D3DPRESENT_FLIPRESTART                 0x00000008
#define D3DPRESENT_VIDEO_RESTRICT_TO_MONITOR   0x00000010
#define D3DPRESENT_UPDATEOVERLAYONLY           0x00000020
#define D3DPRESENT_HIDEOVERLAY                 0x00000040
#define D3DPRESENT_UPDATECOLORKEY              0x00000080
#define D3DPRESENT_FORCEIMMEDIATE              0x00000100

#define FACD3D  0x876
#define MAKE_D3DHRESULT(%code) macro
	(1<<31 | 0x876<<16 | %code)
ENDM

/*
 * Direct3D Errors
 */
#define D3D_OK                              S_OK

#define D3DERR_WRONGTEXTUREFORMAT               MAKE_D3DHRESULT(2072)
#define D3DERR_UNSUPPORTEDCOLOROPERATION        MAKE_D3DHRESULT(2073)
#define D3DERR_UNSUPPORTEDCOLORARG              MAKE_D3DHRESULT(2074)
#define D3DERR_UNSUPPORTEDALPHAOPERATION        MAKE_D3DHRESULT(2075)
#define D3DERR_UNSUPPORTEDALPHAARG              MAKE_D3DHRESULT(2076)
#define D3DERR_TOOMANYOPERATIONS                MAKE_D3DHRESULT(2077)
#define D3DERR_CONFLICTINGTEXTUREFILTER         MAKE_D3DHRESULT(2078)
#define D3DERR_UNSUPPORTEDFACTORVALUE           MAKE_D3DHRESULT(2079)
#define D3DERR_CONFLICTINGRENDERSTATE           MAKE_D3DHRESULT(2081)
#define D3DERR_UNSUPPORTEDTEXTUREFILTER         MAKE_D3DHRESULT(2082)
#define D3DERR_CONFLICTINGTEXTUREPALETTE        MAKE_D3DHRESULT(2086)
#define D3DERR_DRIVERINTERNALERROR              MAKE_D3DHRESULT(2087)

#define D3DERR_NOTFOUND                         MAKE_D3DHRESULT(2150)
#define D3DERR_MOREDATA                         MAKE_D3DHRESULT(2151)
#define D3DERR_DEVICELOST                       MAKE_D3DHRESULT(2152)
#define D3DERR_DEVICENOTRESET                   MAKE_D3DHRESULT(2153)
#define D3DERR_NOTAVAILABLE                     MAKE_D3DHRESULT(2154)
#define D3DERR_OUTOFVIDEOMEMORY                 MAKE_D3DHRESULT(380)
#define D3DERR_INVALIDDEVICE                    MAKE_D3DHRESULT(2155)
#define D3DERR_INVALIDCALL                      MAKE_D3DHRESULT(2156)
#define D3DERR_DRIVERINVALIDCALL                MAKE_D3DHRESULT(2157)
#define D3DERR_WASSTILLDRAWING                  MAKE_D3DHRESULT(540)
#define D3DOK_NOAUTOGEN                         MAKE_D3DHRESULT(2159)

#define D3DERR_DEVICEREMOVED                    MAKE_D3DHRESULT(2160)
#define S_NOT_RESIDENT                          MAKE_D3DHRESULT(2165)
#define S_RESIDENT_IN_SHARED_MEMORY             MAKE_D3DHRESULT(2166)
#define S_PRESENT_MODE_CHANGED                  MAKE_D3DHRESULT(2167)
#define S_PRESENT_OCCLUDED                      MAKE_D3DHRESULT(2168)
#define D3DERR_DEVICEHUNG                       MAKE_D3DHRESULT(2164)
#define D3DERR_UNSUPPORTEDOVERLAY               MAKE_D3DHRESULT(2171)
#define D3DERR_UNSUPPORTEDOVERLAYFORMAT         MAKE_D3DHRESULT(2172)
#define D3DERR_CANNOTPROTECTCONTENT             MAKE_D3DHRESULT(2173)
#define D3DERR_UNSUPPORTEDCRYPTO                MAKE_D3DHRESULT(2174)
#define D3DERR_PRESENT_STATISTICS_DISJOINT      MAKE_D3DHRESULT(2180)

;*******************
; D3D9Ex interfaces
;*******************

IDirect3D9Ex STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	RegisterSoftwareDevice PTR
	GetAdapterCount PTR
	GetAdapterIdentifier PTR
	GetAdapterModeCount PTR
	EnumAdapterModes PTR
	GetAdapterDisplayMode PTR
	CheckDeviceType PTR
	CheckDeviceFormat PTR
	CheckDeviceMultiSampleType PTR
	CheckDepthStencilMatch PTR
	CheckDeviceFormatConversion PTR
	GetDeviceCaps PTR
	GetAdapterMonitor PTR
	CreateDevice PTR
	GetAdapterModeCountEx PTR
	EnumAdapterModesEx PTR
	GetAdapterDisplayModeEx PTR
	CreateDeviceEx PTR
	GetAdapterLUID PTR
ENDS

IDirect3DDevice9Ex STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	TestCooperativeLevel PTR
	GetAvailableTextureMem PTR
	EvictManagedResources PTR
	GetDirect3D PTR
	GetDeviceCaps PTR
	GetDisplayMode PTR
	GetCreationParameters PTR
	SetCursorProperties PTR
	SetCursorPosition PTR
	ShowCursor PTR
	CreateAdditionalSwapChain PTR
	GetSwapChain PTR
	GetNumberOfSwapChains PTR
	Reset PTR
	Present PTR
	GetBackBuffer PTR
	GetRasterStatus PTR
	SetDialogBoxMode PTR
	SetGammaRamp PTR
	GetGammaRamp PTR
	CreateTexture PTR
	CreateVolumeTexture PTR
	CreateCubeTexture PTR
	CreateVertexBuffer PTR
	CreateIndexBuffer PTR
	CreateRenderTarget PTR
	CreateDepthStencilSurface PTR
	UpdateSurface PTR
	UpdateTexture PTR
	GetRenderTargetData PTR
	GetFrontBufferData PTR
	StretchRect PTR
	ColorFill PTR
	CreateOffscreenPlainSurface PTR
	SetRenderTarget PTR
	GetRenderTarget PTR
	SetDepthStencilSurface PTR
	GetDepthStencilSurface PTR
	BeginScene PTR
	EndScene PTR
	Clear PTR
	SetTransform PTR
	GetTransform PTR
	MultiplyTransform PTR
	SetViewport PTR
	GetViewport PTR
	SetMaterial PTR
	GetMaterial PTR
	SetLight PTR
	GetLight PTR
	LightEnable PTR
	GetLightEnable PTR
	SetClipPlane PTR
	GetClipPlane PTR
	SetRenderState PTR
	GetRenderState PTR
	CreateStateBlock PTR
	BeginStateBlock PTR
	EndStateBlock PTR
	SetClipStatus PTR
	GetClipStatus PTR
	GetTexture PTR
	SetTexture PTR
	GetTextureStageState PTR
	SetTextureStageState PTR
	GetSamplerState PTR
	SetSamplerState PTR
	ValidateDevice PTR
	SetPaletteEntries PTR
	GetPaletteEntries PTR
	SetCurrentTexturePalette PTR
	GetCurrentTexturePalette PTR
	SetScissorRect PTR
	GetScissorRect PTR
	SetSoftwareVertexProcessing PTR
	GetSoftwareVertexProcessing PTR
	SetNPatchMode PTR
	GetNPatchMode PTR
	DrawPrimitive PTR
	DrawIndexedPrimitive PTR
	DrawPrimitiveUP PTR
	DrawIndexedPrimitiveUP PTR
	ProcessVertices PTR
	CreateVertexDeclaration PTR
	SetVertexDeclaration PTR
	GetVertexDeclaration PTR
	SetFVF PTR
	GetFVF PTR
	CreateVertexShader PTR
	SetVertexShader PTR
	GetVertexShader PTR
	SetVertexShaderConstantF PTR
	GetVertexShaderConstantF PTR
	SetVertexShaderConstantI PTR
	GetVertexShaderConstantI PTR
	SetVertexShaderConstantB PTR
	GetVertexShaderConstantB PTR
	SetStreamSource PTR
	GetStreamSource PTR
	SetStreamSourceFreq PTR
	GetStreamSourceFreq PTR
	SetIndices PTR
	GetIndices PTR
	CreatePixelShader PTR
	SetPixelShader PTR
	GetPixelShader PTR
	SetPixelShaderConstantF PTR
	GetPixelShaderConstantF PTR
	SetPixelShaderConstantI PTR
	GetPixelShaderConstantI PTR
	SetPixelShaderConstantB PTR
	GetPixelShaderConstantB PTR
	DrawRectPatch PTR
	DrawTriPatch PTR
	DeletePatch PTR
	CreateQuery PTR
	SetConvolutionMonoKernel PTR
	ComposeRects PTR
	PresentEx PTR
	GetGPUThreadPriority PTR
	SetGPUThreadPriority PTR
	WaitForVBlank PTR
	CheckResourceResidency PTR
	SetMaximumFrameLatency PTR
	GetMaximumFrameLatency PTR
	CheckDeviceState PTR
	CreateRenderTargetEx PTR
	CreateOffscreenPlainSurfaceEx PTR
	CreateDepthStencilSurfaceEx PTR
	ResetEx PTR
	GetDisplayModeEx PTR
ENDS

IDirect3DSwapChain9Ex STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Present PTR
	GetFrontBufferData PTR
	GetBackBuffer PTR
	GetRasterStatus PTR
	GetDisplayMode PTR
	GetDevice PTR
	GetPresentParameters PTR
	GetLastPresentCount PTR
	GetPresentStats PTR
	GetDisplayModeEx PTR
ENDS

IDirect3D9ExOverlayExtension STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	CheckDeviceOverlayType PTR
ENDS

IDirect3DDevice9Video STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetContentProtectionCaps PTR
	CreateAuthenticatedChannel PTR
	CreateCryptoSession PTR
ENDS

IDirect3DAuthenticatedChannel9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCertificateSize PTR
	GetCertificate PTR
	NegotiateKeyExchange PTR
	Query PTR
	Configure PTR
ENDS

IDirect3DCryptoSession9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCertificateSize PTR
	GetCertificate PTR
	NegotiateKeyExchange PTR
	EncryptionBlt PTR
	DecryptionBlt PTR
	GetSurfacePitch PTR
	StartSessionKeyRefresh PTR
	FinishSessionKeyRefresh PTR
	GetEncryptionBltKey PTR
ENDS

#endif /* D3D9_H */


