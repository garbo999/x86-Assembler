#ifndef D3D8_H
#define D3D8_H

/* Direct3D include file */

#ifndef DIRECT3D_VERSION
	#define DIRECT3D_VERSION  0x0800
#endif

#if DIRECT3D_VERSION >= 0x0800

#define D3D_SDK_VERSION  120

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#ifdef COM_NO_WINDOWS_H
	#IFNDEF OBJBASE_H
		#include objbase.h
	#ENDIF
	#IFNDEF WINDOWS_H
		#include windows.h
	#ENDIF
#endif

#define D3DSPD_IUNKNOWN  0x00000001

#define D3DCURRENT_DISPLAY_MODE  0x00EFFFFF

#define D3DCREATE_FPU_PRESERVE  0x00000002
#define D3DCREATE_MULTITHREADED  0x00000004
#define D3DCREATE_PUREDEVICE  0x00000010
#define D3DCREATE_SOFTWARE_VERTEXPROCESSING  0x00000020
#define D3DCREATE_HARDWARE_VERTEXPROCESSING  0x00000040
#define D3DCREATE_MIXED_VERTEXPROCESSING  0x00000080

#define D3DADAPTER_DEFAULT  0

#define D3DENUM_NO_WHQL_LEVEL  0x00000002

#define D3DPRESENT_BACK_BUFFERS_MAX  3

#define D3DSGR_NO_CALIBRATION  0x00000000
#define D3DSGR_CALIBRATE  0x00000001

#define D3DCURSOR_IMMEDIATE_UPDATE  0x00000001

#define _FACD3D  0x876

#define D3D_OK  S_OK

#define D3DERR_WRONGTEXTUREFORMAT  (1<<31)|(0x876<<16)|(2072)
#define D3DERR_UNSUPPORTEDCOLOROPERATION  (1<<31)|(0x876<<16)|(2073)
#define D3DERR_UNSUPPORTEDCOLORARG  (1<<31)|(0x876<<16)|(2074)
#define D3DERR_UNSUPPORTEDALPHAOPERATION  (1<<31)|(0x876<<16)|(2075)
#define D3DERR_UNSUPPORTEDALPHAARG  (1<<31)|(0x876<<16)|(2076)
#define D3DERR_TOOMANYOPERATIONS  (1<<31)|(0x876<<16)|(2077)
#define D3DERR_CONFLICTINGTEXTUREFILTER  (1<<31)|(0x876<<16)|(2078)
#define D3DERR_UNSUPPORTEDFACTORVALUE  (1<<31)|(0x876<<16)|(2079)
#define D3DERR_CONFLICTINGRENDERSTATE  (1<<31)|(0x876<<16)|(2081)
#define D3DERR_UNSUPPORTEDTEXTUREFILTER  (1<<31)|(0x876<<16)|(2082)
#define D3DERR_CONFLICTINGTEXTUREPALETTE  (1<<31)|(0x876<<16)|(2086)
#define D3DERR_DRIVERINTERNALERROR  (1<<31)|(0x876<<16)|(2087)
#define D3DERR_NOTFOUND  (1<<31)|(0x876<<16)|(2150)
#define D3DERR_MOREDATA  (1<<31)|(0x876<<16)|(2151)
#define D3DERR_DEVICELOST  (1<<31)|(0x876<<16)|(2152)
#define D3DERR_DEVICENOTRESET  (1<<31)|(0x876<<16)|(2153)
#define D3DERR_NOTAVAILABLE  (1<<31)|(0x876<<16)|(2154)
#define D3DERR_OUTOFVIDEOMEMORY  (1<<31)|(0x876<<16)|(380)
#define D3DERR_INVALIDDEVICE  (1<<31)|(0x876<<16)|(2155)
#define D3DERR_INVALIDCALL  (1<<31)|(0x876<<16)|(2156)
#define D3DERR_DRIVERINVALIDCALL  (1<<31)|(0x876<<16)|(2157)

#DEFINE GUID_IID_IDirect3D8 <0x1dd9e8da,0x1c77,0x4d40,<0xb0,0xcf,0x98,0xfe,0xfd,0xff,0x95,0x12>>
#DEFINE GUID_IID_IDirect3DDevice8 <0x7385e5df,0x8fe8,0x41d5,<0x86,0xb6,0xd7,0xb4,0x85,0x47,0xb6,0xcf>>
#DEFINE GUID_IID_IDirect3DResource8 <0x1b36bb7b,0x9b7,0x410a,<0xb4,0x45,0x7d,0x14,0x30,0xd7,0xb3,0x3f>>
#DEFINE GUID_IID_IDirect3DBaseTexture8 <0xb4211cfa,0x51b9,0x4a9f,<0xab,0x78,0xdb,0x99,0xb2,0xbb,0x67,0x8e>>
#DEFINE GUID_IID_IDirect3DTexture8 <0xe4cdd575,0x2866,0x4f01,<0xb1,0x2e,0x7e,0xec,0xe1,0xec,0x93,0x58>>
#DEFINE GUID_IID_IDirect3DCubeTexture8 <0x3ee5b968,0x2aca,0x4c34,<0x8b,0xb5,0x7e,0x0c,0x3d,0x19,0xb7,0x50>>
#DEFINE GUID_IID_IDirect3DVolumeTexture8 <0x4b8aaafa,0x140f,0x42ba,<0x91,0x31,0x59,0x7e,0xaf,0xaa,0x2e,0xad>>
#DEFINE GUID_IID_IDirect3DVertexBuffer8 <0x8aeeeac7,0x05f9,0x44d4,<0xb5,0x91,0x00,0x0b,0x0d,0xf1,0xcb,0x95>>
#DEFINE GUID_IID_IDirect3DIndexBuffer8 <0x0e689c9a,0x053d,0x44a0,<0x9d,0x92,0xdb,0x0e,0x3d,0x75,0x0f,0x86>>
#DEFINE GUID_IID_IDirect3DSurface8 <0xb96eebca,0xb326,0x4ea5,<0x88,0x2f,0x2f,0xf5,0xba,0xe0,0x21,0xdd>>
#DEFINE GUID_IID_IDirect3DVolume8 <0xbd7349f5,0x14f1,0x42e4,<0x9c,0x79,0x97,0x23,0x80,0xdb,0x40,0xc0>>
#DEFINE GUID_IID_IDirect3DSwapChain8 <0x928c088b,0x76b9,0x4c6b,<0xa5,0x36,0xa5,0x90,0x85,0x38,0x76,0xcd>>

#IFNDEF D3DD8TYPES_H
	#include "d3d8types.h"
#ENDIF
#IFNDEF D3D8CAPS
	#include "d3d8caps.h"
#ENDIF

IDirect3D STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
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
	GetDeviceCaps PTR
	GetAdapterMonitor PTR
	CreateDevice PTR
ENDS

IDirect3DDevice8 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	TestCooperativeLevel PTR
	GetAvailableTextureMem PTR
	ResourceManagerDiscardBytes PTR
	GetDirect3D PTR
	GetDeviceCaps PTR
	GetDisplayMode PTR
	GetCreationParameters PTR
	SetCursorProperties PTR
	SetCursorPosition PTR
	ShowCursor PTR
	CreateAdditionalSwapChain PTR
	Reset PTR
	Present PTR
	GetBackBuffer PTR
	GetRasterStatus PTR
	SetGammaRamp PTR
	GetGammaRamp PTR
	CreateTexture PTR
	CreateVolumeTexture PTR
	CreateCubeTexture PTR
	CreateVertexBuffer PTR
	CreateIndexBuffer PTR
	CreateRenderTarget PTR
	CreateDepthStencilSurface PTR
	CreateImageSurface PTR
	CopyRects PTR
	UpdateTexture PTR
	GetFrontBuffer PTR
	SetRenderTarget PTR
	GetRenderTarget PTR
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
	BeginStateBlock PTR
	EndStateBlock PTR
	ApplyStateBlock PTR
	CaptureStateBlock PTR
	DeleteStateBlock PTR
	CreateStateBlock PTR
	SetClipStatus PTR
	GetClipStatus PTR
	GetTexture PTR
	SetTexture PTR
	GetTextureStageState PTR
	SetTextureStageState PTR
	ValidateDevice PTR
	GetInfo PTR
	SetPaletteEntries PTR
	GetPaletteEntries PTR
	SetCurrentTexturePalette PTR
	GetCurrentTexturePalette PTR
	DrawPrimitive PTR
	DrawIndexedPrimitive PTR
	DrawPrimitiveUP PTR
	DrawIndexedPrimitiveUP PTR
	ProcessVertices PTR
	CreateVertexShader PTR
	SetVertexShader PTR
	GetVertexShader PTR
	DeleteVertexShader PTR
	SetVertexShaderConstant PTR
	GetVertexShaderConstant PTR
	GetVertexShaderDeclaration PTR
	GetVertexShaderFunction PTR
	SetStreamSource PTR
	GetStreamSource PTR
	SetIndices PTR
	GetIndices PTR
	CreatePixelShader PTR
	SetPixelShader PTR
	GetPixelShader PTR
	DeletePixelShader PTR
	SetPixelShaderConstant PTR
	GetPixelShaderConstant PTR
	GetPixelShaderFunction PTR
	DrawRectPatch PTR
	DrawTriPatch PTR
	DeletePatch PTR
ENDS

IDirect3DSwapChain8 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Present PTR
	GetBackBuffer PTR
ENDS

IDirect3DResource8 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
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

IDirect3DBaseTexture8 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
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
ENDS

IDirect3DTexture8 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
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
	GetLevelDesc PTR
	GetSurfaceLevel PTR
	LockRect PTR
	UnlockRect PTR
	AddDirtyRect PTR
ENDS

IDirect3DVolumeTexture8 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
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
	GetLevelDesc PTR
	GetVolumeLevel PTR
	LockBox PTR
	UnlockBox PTR
	AddDirtyBox PTR
ENDS

IDirect3DCubeTexture8 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
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
	GetLevelDesc PTR
	GetCubeMapSurface PTR
	LockRect PTR
	UnlockRect PTR
	AddDirtyRect PTR
ENDS

IDirect3DVertexBuffer8 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
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
ENDS

IDirect3DIndexBuffer8 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
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
ENDS

IDirect3DSurface8 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDevice PTR
	SetPrivateData PTR
	GetPrivateData PTR
	FreePrivateData PTR
	GetContainer PTR
	GetDesc PTR
	LockRect PTR
	UnlockRect PTR
ENDS

IDirect3DVolume8 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
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
ENDS

#endif // DIRECT3D_VERSION >= 0x0800)

#endif // D3D8_H

