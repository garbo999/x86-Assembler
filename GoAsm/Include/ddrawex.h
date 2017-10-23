#ifndef DDRAWEX_H
#define DDRAWEX_H

/* DirectDrawEx definitions */

#IFNDEF DDRAW_H
	#include ddraw.h
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#DEFINE GUID_CLSID_DirectDrawFactory <0x4fd2a832,0x86c8,0x11d0,<0x8f,0xca,0x0,0xc0,0x4f,0xd9,0x18,0x9d>>
#DEFINE GUID_IID_IDirectDrawFactory <0x4fd2a833,0x86c8,0x11d0,<0x8f,0xca,0x0,0xc0,0x4f,0xd9,0x18,0x9d>>

#define DDSCAPS_DATAEXCHANGE  (DDSCAPS_SYSTEMMEMORY|DDSCAPS_VIDEOMEMORY)

#define DDERR_LOADFAILED  (1<<31) + (0x876<<16) + 901
#define DDERR_BADVERSIONINFO  (1<<31) + (0x876<<16) + 902
#define DDERR_BADPROCADDRESS  (1<<31) + (0x876<<16) + 903
#define DDERR_LEGACYUSAGE  (1<<31) + (0x876<<16) + 904

#define DDSD_LPSURFACE  0x00000800

#DEFINE GUID_IID_IDirectDrawSurface3 <0xDA044E00,0x69B2,0x11D0,<0xA1,0xD5,0x00,0xAA,0x00,0xB8,0xDF,0xBB>>
IDirectDrawSurface3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddAttachedSurface PTR
	AddOverlayDirtyRect PTR
	Blt PTR
	BltBatch PTR
	BltFast PTR
	DeleteAttachedSurface PTR
	EnumAttachedSurfaces PTR
	EnumOverlayZOrders PTR
	Flip PTR
	GetAttachedSurface PTR
	GetBltStatus PTR
	GetCaps PTR
	GetClipper PTR
	GetColorKey PTR
	GetDC PTR
	GetFlipStatus PTR
	GetOverlayPosition PTR
	GetPalette PTR
	GetPixelFormat PTR
	GetSurfaceDesc PTR
	Initialize PTR
	IsLost PTR
	Lock PTR
	ReleaseDC PTR
	Restore PTR
	SetClipper PTR
	SetColorKey PTR
	SetOverlayPosition PTR
	SetPalette PTR
	Unlock PTR
	UpdateOverlay PTR
	UpdateOverlayDisplay PTR
	UpdateOverlayZOrder PTR
	GetDDInterface PTR
	PageLock PTR
	PageUnlock PTR
	SetSurfaceDesc PTR
ENDS

IDirectDrawFactory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateDirectDraw PTR
	DirectDrawEnumerate PTR
ENDS

#DEFINE GUID_IID_IDirectDraw3 <0x618f8ad4,0x8b7a,0x11d0,<0x8f,0xcc,0x0,0xc0,0x4f,0xd9,0x18,0x9d>>
IDirectDraw3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Compact PTR
	CreateClipper PTR
	CreatePalette PTR
	CreateSurface PTR
	DuplicateSurface PTR
	EnumDisplayModes PTR
	EnumSurfaces PTR
	FlipToGDISurface PTR
	GetCaps PTR
	GetDisplayMode PTR
	GetFourCCCodes PTR
	GetGDISurface PTR
	GetMonitorFrequency PTR
	GetScanLine PTR
	GetVerticalBlankStatus PTR
	Initialize PTR
	RestoreDisplayMode PTR
	SetCooperativeLevel PTR
	SetDisplayMode PTR
	WaitForVerticalBlank PTR
	GetAvailableVidMem PTR
	GetSurfaceFromDC PTR
ENDS

#endif /* _DDRAWEX_H */
