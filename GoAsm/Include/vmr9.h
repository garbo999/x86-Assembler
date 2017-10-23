#ifndef VMR9_H
#define VMR9_H

#ifndef WINDOWS_H
	#include "windows.h"
#endif

#IFNDEF AM_MEDIA_TYPE
AM_MEDIA_TYPE STRUCT
	dw1 DD
	dw2 DD
ENDS
#endif

// enum VMR9PresentationFlags
VMR9Sample_SyncPoint	= 0x1
VMR9Sample_Preroll	= 0x2
VMR9Sample_Discontinuity	= 0x4
VMR9Sample_TimeValid	= 0x8
VMR9Sample_SrcDstRectsValid	= 0x10

VMR9PresentationInfo struct
	dwFlags DD
	lpSurf PTR
	rtStart LONGLONG ; REFERENCE_TIME
	rtEnd LONGLONG ; REFERENCE_TIME
	szAspectRatio SIZE
	rcSrc RECT
	rcDst RECT
	dwReserved1 DD
	dwReserved2 DD
ENDS

#define GUID_IID_IVMRImagePresenter9 <0x69188c61,0x12a3,0x40f0,<0x8f,0xfc,0x34,0x2e,0x7b,0x43,0x3f,0xd7>>

IVMRImagePresenter9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	StartPresenting PTR
	StopPresenting PTR
	PresentImage PTR
ENDS

// enum VMR9SurfaceAllocationFlags
VMR9AllocFlag_3DRenderTarget	= 0x1
VMR9AllocFlag_DXVATarget	= 0x2
VMR9AllocFlag_TextureSurface	= 0x4
VMR9AllocFlag_OffscreenSurface	= 0x8
VMR9AllocFlag_RGBDynamicSwitch	= 0x10
VMR9AllocFlag_UsageReserved	= 0xe0
VMR9AllocFlag_UsageMask	= 0xff

VMR9AllocationInfo STRUCT
	dwFlags DD
	dwWidth DD
	dwHeight DD
	Format DD // D3DFORMAT
	Pool DD // D3DPOOL
	MinBuffers DD
	szAspectRatio SIZE
	szNativeSize SIZE
ENDS

#define GUID_IID_IVMRSurfaceAllocator9 <0x8d5148ea,0x3f5d,0x46cf,<0x9d,0xf1,0xd1,0xb8,0x96,0xee,0xdb,0x1f>>

IVMRSurfaceAllocator9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	InitializeDevice PTR
	TerminateDevice PTR
	GetSurface PTR 
	AdviseNotify PTR
ENDS

#DEFINE GUID_IID_IVMRSurfaceAllocatorEx9 <0x6de9a68a,0xa928,0x4522,<0xbf,0x57,0x65,0x5a,0xe3,0x86,0x64,0x56>>

IVMRSurfaceAllocatorEx9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	InitializeDevice PTR
	TerminateDevice PTR
	GetSurface PTR 
	AdviseNotify PTR
	GetSurfaceEx PTR
ENDS

#DEFINE GUID_IID_IVMRSurfaceAllocatorNotify9 <0xdca3f5df,0xbb3a,0x4d03,<0xbd,0x81,0x84,0x61,0x4b,0xfb,0xfa,0x0c>>

IVMRSurfaceAllocatorNotify9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	AdviseSurfaceAllocator PTR
	SetD3DDevice PTR
	ChangeD3DDevice PTR
	AllocateSurfaceHelper PTR
	NotifyEvent PTR
ENDS

// enum VMR9AspectRatioMode
VMR9ARMode_None	= 0
VMR9ARMode_LetterBox	= 1

#DEFINE GUID_IID_IVMRWindowlessControl9 <0x8f537d09,0xf85e,0x4414,<0xb2,0x3b,0x50,0x2e,0x54,0xc7,0x99,0x27>>

IVMRWindowlessControl9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetNativeVideoSize PTR
	GetMinIdealVideoSize PTR
	GetMaxIdealVideoSize PTR
	SetVideoPosition PTR
	GetVideoPosition PTR
	GetAspectRatioMode PTR
	SetAspectRatioMode PTR
	SetVideoClippingWindow PTR
	RepaintVideo PTR
	DisplayModeChanged PTR
	GetCurrentImage PTR
	SetBorderColor PTR
	GetBorderColor PTR
ENDS

// enum VMR9MixerPrefs
MixerPref9_NoDecimation	= 0x1
MixerPref9_DecimateOutput	= 0x2
MixerPref9_ARAdjustXorY	= 0x4
MixerPref9_NonSquareMixing	= 0x8
MixerPref9_DecimateMask	= 0xf
MixerPref9_BiLinearFiltering	= 0x10
MixerPref9_PointFiltering	= 0x20
MixerPref9_AnisotropicFiltering	= 0x40
MixerPref9_PyramidalQuadFiltering	= 0x80
MixerPref9_GaussianQuadFiltering	= 0x100
MixerPref9_FilteringReserved	= 0xe00
MixerPref9_FilteringMask	= 0xff0
MixerPref9_RenderTargetRGB	= 0x1000
MixerPref9_RenderTargetYUV	= 0x2000
MixerPref9_RenderTargetReserved	= 0xfc000
MixerPref9_RenderTargetMask	= 0xff000
MixerPref9_DynamicSwitchToBOB	= 0x100000
MixerPref9_DynamicDecimateBy2	= 0x200000
MixerPref9_DynamicReserved	= 0xc00000
MixerPref9_DynamicMask	= 0xf00000

VMR9NormalizedRect STRUCT
	left FLOAT
	top FLOAT
	right FLOAT
	bottom FLOAT
ENDS

// enum VMR9ProcAmpControlFlags
ProcAmpControl9_Brightness	= 0x1
ProcAmpControl9_Contrast	= 0x2
ProcAmpControl9_Hue	= 0x4
ProcAmpControl9_Saturation	= 0x8
ProcAmpControl9_Mask	= 0xf

VMR9ProcAmpControl STRUCT
	dwSize DD
	dwFlags DD
	Brightness FLOAT
	Contrast FLOAT
	Hue FLOAT
	Saturation FLOAT
ENDS

VMR9ProcAmpControlRange STRUCT
	dwSize DD
	dwProperty ENUM // VMR9ProcAmpControlFlags
	MinValue FLOAT
	MaxValue FLOAT
	DefaultValue FLOAT
	StepSize FLOAT
ENDS

#DEFINE GUID_IID_IVMRMixerControl9 <0x1a777eaa,0x47c8,0x4930,<0xb2,0xc9,0x8f,0xee,0x1c,0x1b,0x0f,0x3b>>

IVMRMixerControl9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetAlpha PTR
	GetAlpha PTR
	SetZOrder PTR
	GetZOrder PTR
	SetOutputRect PTR
	GetOutputRect PTR
	SetBackgroundClr PTR
	GetBackgroundClr PTR
	SetMixingPrefs PTR
	GetMixingPrefs PTR
	SetProcAmpControl PTR
	GetProcAmpControl PTR
	GetProcAmpControlRange PTR
ENDS


VMR9AlphaBitmap STRUCT
	dwFlags DD
	hdc HANDLE
	pDDS PTR
	rSrc RECT
	rDest VMR9NormalizedRect
	fAlpha FLOAT
	clrSrcKey COLORREF
	dwFilterMode DD
ENDS

// enum VMR9AlphaBitmapFlags
VMR9AlphaBitmap_Disable	= 0x1
VMR9AlphaBitmap_hDC	= 0x2
VMR9AlphaBitmap_EntireDDS	= 0x4
VMR9AlphaBitmap_SrcColorKey	= 0x8
VMR9AlphaBitmap_SrcRect	= 0x10
VMR9AlphaBitmap_FilterMode	= 0x20

#DEFINE GUID_IID_IVMRMixerBitmap9 <0xced175e5,0x1935,0x4820,<0x81,0xbd,0xff,0x6a,0xd0,0x0c,0x91,0x08>>

IVMRMixerBitmap9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetAlphaBitmap PTR
	UpdateAlphaBitmapParameters PTR
	GetAlphaBitmapParameters PTR
ENDS

#DEFINE GUID_IID_IVMRSurface9 <0xdfc581a1,0x6e1f,0x4c3a,<0x8d,0x0a,0x5e,0x97,0x92,0xea,0x2a,0xfc>>

IVMRSurface9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	IsSurfaceLocked PTR
	LockSurface PTR
	UnlockSurface PTR
	GetSurface PTR
ENDS

// enum VMR9RenderPrefs
RenderPrefs9_DoNotRenderBorder	= 0x1
RenderPrefs9_Mask	= 0x1

#DEFINE GUID_IID_IVMRImagePresenterConfig9 <0x45c15cab,0x6e22,0x420a,<0x80,0x43,0xae,0x1f,0x0a,0xc0,0x2c,0x7d>>

IVMRImagePresenterConfig9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetRenderingPrefs PTR
	GetRenderingPrefs PTR
ENDS

#DEFINE GUID_IID_IVMRVideoStreamControl9 <0xd0cfe38b,0x93e7,0x4772,<0x89,0x57,0x04,0x00,0xc4,0x9a,0x44,0x85>>

IVMRVideoStreamControl9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetStreamActiveState PTR
	GetStreamActiveState PTR
ENDS

// enum VMR9Mode
VMR9Mode_Windowed	= 0x1
VMR9Mode_Windowless	= 0x2
VMR9Mode_Renderless	= 0x4
VMR9Mode_Mask	= 0x7

#DEFINE GUID_IID_IVMRFilterConfig9 <0x5a804648,0x4f66,0x4867,<0x9c,0x43,0x4f,0x5c,0x82,0x2c,0xf1,0xb8>>

IVMRFilterConfig9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetImageCompositor PTR
	SetNumberOfStreams PTR
	GetNumberOfStreams PTR
	SetRenderingPrefs PTR
	GetRenderingPrefs PTR
	SetRenderingMode PTR
	GetRenderingMode PTR
ENDS

#DEFINE GUID_IID_IVMRAspectRatioControl9 <0x00d96c29,0xbbde,0x4efc,<0x99,0x01,0xbb,0x50,0x36,0x39,0x21,0x46>>

IVMRAspectRatioControl9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetAspectRatioMode PTR
	SetAspectRatioMode PTR
ENDS
 
VMR9MonitorInfo STRUCT
	uDevID DD
	rcMonitor RECT
	hMon HANDLE
	dwFlags DD
	szDevice WCHAR 32 DUP
	szDescription WCHAR 512  DUP
	liDriverVersion LARGE_INTEGER
	dwVendorId DD
	dwDeviceId DD
	dwSubSysId DD
	dwRevision DD
ENDS

#DEFINE GUID_IID_IVMRMonitorConfig9 <0x46c2e457,0x8ba0,0x4eef,<0xb8,0x0b,0x06,0x80,0xf0,0x97,0x87,0x49>>

IVMRMonitorConfig9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetMonitor PTR
	GetMonitor PTR
	SetDefaultMonitor PTR
	GetDefaultMonitor PTR
	GetAvailableMonitors PTR
ENDS

// enum VMR9DeinterlacePrefs
DeinterlacePref9_NextBest	= 0x1
DeinterlacePref9_BOB	= 0x2
DeinterlacePref9_Weave	= 0x4
DeinterlacePref9_Mask	= 0x7

// enum VMR9DeinterlaceTech
DeinterlaceTech9_Unknown	= 0
DeinterlaceTech9_BOBLineReplicate	= 0x1
DeinterlaceTech9_BOBVerticalStretch	= 0x2
DeinterlaceTech9_MedianFiltering	= 0x4
DeinterlaceTech9_EdgeFiltering	= 0x10
DeinterlaceTech9_FieldAdaptive	= 0x20
DeinterlaceTech9_PixelAdaptive	= 0x40
DeinterlaceTech9_MotionVectorSteered	= 0x80

VMR9Frequency STRUCT
	dwNumerator DD
	dwDenominator DD
ENDS

// enum VMR9_SampleFormat
VMR9_SampleReserved	= 1
VMR9_SampleProgressiveFrame	= 2
VMR9_SampleFieldInterleavedEvenFirst	= 3
VMR9_SampleFieldInterleavedOddFirst	= 4
VMR9_SampleFieldSingleEven	= 5
VMR9_SampleFieldSingleOdd	= 6

VMR9VideoDesc STRUCT
	dwSize DD
	dwSampleWidth DD
	dwSampleHeight DD
	SampleFormat ENUM // VMR9_SampleFormat
	dwFourCC DD
	InputSampleFreq VMR9Frequency
	OutputFrameFreq VMR9Frequency
ENDS

VMR9DeinterlaceCaps STRUCT
	dwSize DD
	dwNumPreviousOutputFrames DD
	dwNumForwardRefSamples DD
	dwNumBackwardRefSamples DD
	DeinterlaceTechnology ENUM // VMR9DeinterlaceTech
ENDS

#DEFINE GUID_IID_IVMRDeinterlaceControl9 <0xa215fb8d,0x13c2,0x4f7f,<0x99,0x3c,0x00,0x3d,0x62,0x71,0xa4,0x59>>

IVMRDeinterlaceControl9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetNumberOfDeinterlaceModes PTR
	GetDeinterlaceModeCaps PTR
	GetDeinterlaceMode PTR
	SetDeinterlaceMode PTR
	GetDeinterlacePrefs PTR
	SetDeinterlacePrefs PTR
	GetActualDeinterlaceMode PTR
ENDS

VMR9VideoStreamInfo STRUCT
	pddsVideoSurface PTR
	dwWidth DD
	dwHeight DD
	dwStrmID DD
	fAlpha FLOAT
	rNormal VMR9NormalizedRect
	rtStart LONGLONG // REFERENCE_TIME
	rtEnd  LONGLONG // REFERENCE_TIME
	SampleFormat ENUM // VMR9_SampleFormat
ENDS

#DEFINE GUID_IID_IVMRImageCompositor9 <0x4a5c89eb,0xdf51,0x4654,<0xac,0x2a,0xe4,0x8e,0x02,0xbb,0xab,0xf6>>

IVMRImageCompositor9 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	InitCompositionDevice PTR
	TermCompositionDevice PTR
	SetStreamMediaType PTR
	CompositeImage PTR
ENDS

#endif



