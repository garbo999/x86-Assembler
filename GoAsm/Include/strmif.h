#ifndef STRMIF_H
#define STRMIF_H

/*
NOTE:

The VMRGUID structure has the following change:

The member VMRGUID.GUID has been changed to VMRGUID.guid to resolve a conflict with the GUID structure
*/

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF

#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#ifndef COM_NO_WINDOWS_H
	#IFNDEF WINDOWS_H
		#include "windows.h"
	#ENDIF
	#IFNDEF OLE2_H
		#include "ole2.h"
	#ENDIF
#endif

/* header files for imported files */
#IFNDEF UNKNWN_H
	#include "unknwn.h"
#ENDIF

#IFNDEF OBJIDL_H
	#include "objidl.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF

#IFNDEF OCIDL_H
	#include "ocidl.h"
#ENDIF

#IFNDEF DDRAW_H
	#include "ddraw.h"
#ENDIF

#define CDEF_CLASS_DEFAULT      0x0001
#define CDEF_BYPASS_CLASS_MANAGER   0x0002
#define CDEF_MERIT_ABOVE_DO_NOT_USE  0x0008
#define CDEF_DEVMON_CMGR_DEVICE  0x0010
#define CDEF_DEVMON_DMO  0x0020
#define CDEF_DEVMON_PNP_DEVICE  0x0040
#define CDEF_DEVMON_FILTER  0x0080
#define CDEF_DEVMON_SELECTIVE_MASK  0x00f0

#DEFINE GUID_IID_ICreateDevEnum <0x29840822,0x5B84,0x11D0,<0xBD,0x3B,0x00,0xA0,0xC9,0x11,0xCE,0x86>>

ICreateDevEnum STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateClassEnumerator PTR
ENDS

#define CHARS_IN_GUID     39
AM_MEDIA_TYPE STRUCT
	majortype GUID
	subtype GUID
	bFixedSizeSamples BOOL
	bTemporalCompression BOOL
	lSampleSize LONG
	formattype GUID
	pUnk PTR
	cbFormat LONG
	pbFormat PTR
ENDS

PINDIR_INPUT	= 0
PINDIR_OUTPUT	= 1 

#define MAX_PIN_NAME     128
#define MAX_FILTER_NAME  128

/*
typedef LONGLONG REFERENCE_TIME;

typedef double REFTIME;

typedef DWORD_PTR HSEMAPHORE;

typedef DWORD_PTR HEVENT;
*/

ALLOCATOR_PROPERTIES STRUCT
	cBuffers LONG
	cbBuffer LONG
	cbAlign LONG
	cbPrefix LONG
ENDS

PIN_INFO STRUCT
	pFilter PTR
	dir ENUM
	achName WCHAR 128 DUP
ENDS

#DEFINE GUID_IID_IPin <0x56a86891,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IPin STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Connect PTR
	ReceiveConnection PTR
	Disconnect PTR
	ConnectedTo PTR
	ConnectionMediaType PTR
	QueryPinInfo PTR
	QueryDirection PTR
	QueryId PTR
	QueryAccept PTR
	EnumMediaTypes PTR
	QueryInternalConnections PTR
	EndOfStream PTR
	BeginFlush PTR
	EndFlush PTR
	NewSegment PTR
ENDS

#DEFINE GUID_IID_IEnumPins <0x56a86892,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IEnumPins STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#DEFINE GUID_IID_IEnumMediaTypes <0x89c31040,0x846b,0x11ce,<0x97,0xd3,0x00,0xaa,0x00,0x55,0x59,0x5a>>

IEnumMediaTypes STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#DEFINE GUID_IID_IFilterGraph <0x56a8689f,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IFilterGraph STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddFilter PTR
	RemoveFilter PTR
	EnumFilters PTR
	FindFilterByName PTR
	ConnectDirect PTR
	Reconnect PTR
	Disconnect PTR
	SetDefaultSyncSource PTR
ENDS

#DEFINE GUID_IID_IEnumFilters <0x56a86893,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IEnumFilters STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

// FilterState
	State_Stopped	= 0
	State_Paused	= 1
	State_Running	= 2 

#DEFINE GUID_IID_IMediaFilter <0x56a86899,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IMediaFilter STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	Stop PTR
	Pause PTR
	Run PTR
	GetState PTR
	SetSyncSource PTR
	GetSyncSource PTR
ENDS

FILTER_INFO STRUCT
	achName WCHAR 128 DUP
	pGraph PTR
ENDS

#DEFINE GUID_IID_IBaseFilter <0x56a86895,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IBaseFilter STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	Stop PTR
	Pause PTR
	Run PTR
	GetState PTR
	SetSyncSource PTR
	GetSyncSource PTR
	GetSyncSource PTR
	EnumPins PTR
	FindPin PTR
	QueryFilterInfo PTR
	JoinFilterGraph PTR
	QueryVendorInfo PTR
ENDS

#DEFINE GUID_IID_IReferenceClock <0x56a86897,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IReferenceClock STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetTime PTR
	AdviseTime PTR
	AdvisePeriodic PTR
	Unadvise PTR
ENDS

#DEFINE GUID_IID_IReferenceClockTimerControl <0xebec459c,0x2eca,0x4d42,<0xa8,0xaf,0x30,0xdf,0x55,0x76,0x14,0xb8>>

IReferenceClockTimerControl STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetDefaultTimerResolution PTR
	GetDefaultTimerResolution PTR
ENDS

#DEFINE GUID_IID_IReferenceClock2 <0x36b73885,0xc2c8,0x11cf,<0x8b,0x46,0x00,0x80,0x5f,0x6c,0xef,0x60>>

IReferenceClock2 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetTime PTR
	AdviseTime PTR
	AdvisePeriodic PTR
	Unadvise PTR
ENDS

#DEFINE GUID_IID_IMediaSample <0x56a8689a,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IMediaSample STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPointer PTR
	GetSize PTR
	GetTime PTR
	SetTime PTR
	IsSyncPoint PTR
	SetSyncPoint PTR
	IsPreroll PTR
	SetPreroll PTR
	GetActualDataLength PTR
	SetActualDataLength PTR
	GetMediaType PTR
	SetMediaType PTR
	IsDiscontinuity PTR
	SetDiscontinuity PTR
	GetMediaTime PTR
	SetMediaTime PTR
ENDS

// AM_SAMPLE_PROPERTY_FLAGS
	AM_SAMPLE_SPLICEPOINT	= 0x1
	AM_SAMPLE_PREROLL	= 0x2
	AM_SAMPLE_DATADISCONTINUITY	= 0x4
	AM_SAMPLE_TYPECHANGED	= 0x8
	AM_SAMPLE_TIMEVALID	= 0x10
	AM_SAMPLE_TIMEDISCONTINUITY	= 0x40
	AM_SAMPLE_FLUSH_ON_PAUSE	= 0x80
	AM_SAMPLE_STOPVALID	= 0x100
	AM_SAMPLE_ENDOFSTREAM	= 0x200
	AM_STREAM_MEDIA	= 0
	AM_STREAM_CONTROL	= 1

AM_SAMPLE2_PROPERTIES STRUCT
	cbData DD
	dwTypeSpecificFlags DD
	dwSampleFlags DD
	lActual LONG
	tStart LONGLONG
	tStop LONGLONG
	dwStreamId DD
	pMediaType PTR
	pbBuffer PTR
	cbBuffer LONG
ENDS

#DEFINE GUID_IID_IMediaSample2 <0x36b73884,0xc2c8,0x11cf,<0x8b,0x46,0x00,0x80,0x5f,0x6c,0xef,0x60>>

IMediaSample2 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPointer PTR
	GetSize PTR
	GetTime PTR
	SetTime PTR
	IsSyncPoint PTR
	SetSyncPoint PTR
	IsPreroll PTR
	SetPreroll PTR
	GetActualDataLength PTR
	SetActualDataLength PTR
	GetMediaType PTR
	SetMediaType PTR
	IsDiscontinuity PTR
	SetDiscontinuity PTR
	GetMediaTime PTR
	SetMediaTime PTR
	GetProperties PTR
	SetProperties PTR
ENDS

#DEFINE GUID_IID_IMediaSample2Config <0x68961E68,0x832B,0x41ea,<0xBC,0x91,0x63,0x59,0x3F,0x3E,0x70,0xE3>>

IMediaSample2Config STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetSurface PTR
ENDS

#define AM_GBF_PREVFRAMESKIPPED 1
#define AM_GBF_NOTASYNCPOINT 2
#define AM_GBF_NOWAIT 4
#define AM_GBF_NODDSURFACELOCK 8

#DEFINE GUID_IID_IMemAllocator <0x56a8689c,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IMemAllocator STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetProperties PTR
	GetProperties PTR
	Commit PTR
	Decommit PTR
	GetBuffer PTR
	ReleaseBuffer PTR
ENDS

#DEFINE GUID_IID_IMemAllocatorCallbackTemp <0x379a0cf0,0xc1de,0x11d2,<0xab,0xf5,0x00,0xa0,0xc9,0x05,0xf3,0x75>>

IMemAllocatorCallbackTemp STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetProperties PTR
	GetProperties PTR
	Commit PTR
	Decommit PTR
	GetBuffer PTR
	ReleaseBuffer PTR
	SetNotify PTR
	GetFreeCount PTR
ENDS

#DEFINE GUID_IID_IMemAllocatorNotifyCallbackTemp <0x92980b30,0xc1de,0x11d2,<0xab,0xf5,0x00,0xa0,0xc9,0x05,0xf3,0x75>>

IMemAllocatorNotifyCallbackTemp STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	NotifyRelease PTR
ENDS

#DEFINE GUID_IID_IMemInputPin <0x56a8689d,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IMemInputPin STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetAllocator PTR
	NotifyAllocator PTR
	GetAllocatorRequirements PTR
	Receive PTR
	ReceiveMultiple PTR
	ReceiveCanBlock PTR
ENDS

#DEFINE GUID_IID_IAMovieSetup <0xa3d8cec0,0x7e5a,0x11cf,<0xbb,0xc5,0x00,0x80,0x5f,0x6c,0xef,0x20>>

IAMovieSetup STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Register PTR
	Unregister PTR
ENDS

// AM_SEEKING_SeekingFlags
	AM_SEEKING_NoPositioning	= 0
	AM_SEEKING_AbsolutePositioning	= 0x1
	AM_SEEKING_RelativePositioning	= 0x2
	AM_SEEKING_IncrementalPositioning	= 0x3
	AM_SEEKING_PositioningBitsMask	= 0x3
	AM_SEEKING_SeekToKeyFrame	= 0x4
	AM_SEEKING_ReturnTime	= 0x8
	AM_SEEKING_Segment	= 0x10
	AM_SEEKING_NoFlush	= 0x20

// AM_SEEKING_SeekingCapabilities
	AM_SEEKING_CanSeekAbsolute	= 0x1
	AM_SEEKING_CanSeekForwards	= 0x2
	AM_SEEKING_CanSeekBackwards	= 0x4
	AM_SEEKING_CanGetCurrentPos	= 0x8
	AM_SEEKING_CanGetStopPos	= 0x10
	AM_SEEKING_CanGetDuration	= 0x20
	AM_SEEKING_CanPlayBackwards	= 0x40
	AM_SEEKING_CanDoSegments	= 0x80
	AM_SEEKING_Source	= 0x100

#DEFINE GUID_IID_IMediaSeeking <0x36b73880,0xc2c8,0x11cf,<0x8b,0x46,0x00,0x80,0x5f,0x6c,0xef,0x60>>

IMediaSeeking STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCapabilities PTR
	CheckCapabilities PTR
	IsFormatSupported PTR
	QueryPreferredFormat PTR
	GetTimeFormat PTR
	IsUsingTimeFormat PTR
	SetTimeFormat PTR
	GetDuration PTR
	GetStopPosition PTR
	GetCurrentPosition PTR
	ConvertTimeFormat PTR
	SetPositions PTR
	GetPositions PTR
	GetAvailable PTR
	SetRate PTR
	GetRate PTR
	GetPreroll PTR
ENDS

// AM_MEDIAEVENT_FLAGS
	AM_MEDIAEVENT_NONOTIFY = 0x01

REGFILTER STRUCT
	Clsid CLSID
	Name PTR
ENDS

#DEFINE GUID_IID_IEnumRegFilters <0x56a868a4,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IEnumRegFilters STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

// MIDL_IFilterMapper_0001
    MERIT_PREFERRED	= 0x800000
	MERIT_NORMAL	= 0x600000
	MERIT_UNLIKELY	= 0x400000
	MERIT_DO_NOT_USE	= 0x200000
	MERIT_SW_COMPRESSOR	= 0x100000
	MERIT_HW_COMPRESSOR	= 0x100050

#DEFINE GUID_IID_IFilterMapper <0x56a868a3,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IFilterMapper STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	RegisterFilter PTR
	RegisterFilterInstance PTR
	RegisterPin PTR
	RegisterPinType PTR
	UnregisterFilter PTR
	UnregisterFilterInstance PTR
	UnregisterPin PTR
	EnumMatchingFilters PTR
ENDS

REGPINTYPES STRUCT
	clsMajorType PTR
	clsMinorType PTR
ENDS

REGFILTERPINS STRUCT
	strName PTR
	bRendered BOOL
	bOutput BOOL
	bZero BOOL
	bMany BOOL
	clsConnectsToFilter PTR
	strConnectsToPin PTR
	nMediaTypes LONG
	lpMediaType PTR
ENDS

REGPINMEDIUM STRUCT
	clsMedium CLSID
	dw1 DD
	dw2 DD
ENDS

// MIDL___MIDL_itf_strmif_0000_0022_0001
	REG_PINFLAG_B_ZERO	= 0x1
	REG_PINFLAG_B_RENDERER	= 0x2
	REG_PINFLAG_B_MANY	= 0x4
	REG_PINFLAG_B_OUTPUT	= 0x8

REGFILTERPINS2 STRUCT
	dwFlags DD
	cInstances LONG
	nMediaTypes LONG
	lpMediaType PTR
	nMediums LONG
	lpMedium PTR
	clsPinCategory PTR
ENDS

REGFILTER2 STRUCT
	dwVersion DD
	dwMerit DD
	UNION
		struct
			cPins LONG
			rgPins PTR
		ends
		struct
			cPins2 LONG
			rgPins2 PTR
		ends
	ENDUNION
ENDS

#DEFINE GUID_IID_IFilterMapper2 <0xb79bb0b0,0x33c1,0x11d1,<0xab,0xe1,0x00,0xa0,0xc9,0x05,0xf3,0x75>>

IFilterMapper2 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateCategory PTR
	UnregisterFilter PTR
	RegisterFilter PTR
	EnumMatchingFilters PTR
ENDS

#DEFINE GUID_IID_IFilterMapper3 <0xb79bb0b1,0x33c1,0x11d1,<0xab,0xe1,0x00,0xa0,0xc9,0x05,0xf3,0x75>>

IFilterMapper3 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateCategory PTR
	UnregisterFilter PTR
	RegisterFilter PTR
	EnumMatchingFilters PTR
	GetICreateDevEnum PTR
ENDS

// QualityMessageType
	Famine	= 0
	Flood	= 1

Quality STRUCT
	Type ENUM
	Proportion LONG
	Late LONGLONG // REFERENCE_TIME
	TimeStamp  LONGLONG // REFERENCE_TIME
ENDS

#DEFINE GUID_IID_IQualityControl <0x56a868a5,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IQualityControl STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Notify PTR
	SetSink PTR
ENDS

// MIDL___MIDL_itf_strmif_0000_0025_0001
	CK_NOCOLORKEY	= 0
	CK_INDEX	= 0x1
	CK_RGB	= 0x2

COLORKEY STRUCT
	KeyType DD
	PaletteIndex DD
	LowColorValue COLORREF
	HighColorValue COLORREF
ENDS

// MIDL___MIDL_itf_strmif_0000_0025_0002
	ADVISE_NONE	= 0
	ADVISE_CLIPPING	= 0x1
	ADVISE_PALETTE	= 0x2
	ADVISE_COLORKEY	= 0x4
	ADVISE_POSITION	= 0x8
	ADVISE_DISPLAY_CHANGE	= 0x10

#define	ADVISE_ALL	(ADVISE_CLIPPING | ADVISE_PALETTE  | ADVISE_COLORKEY  | ADVISE_POSITION)

#define	ADVISE_ALL2	(ADVISE_ALL | ADVISE_DISPLAY_CHANGE)

#ifndef WINGDI_H
	RGNDATAHEADER STRUCT
		dwSize DD
		iType DD
		nCount DD
		nRgnSize DD
		rcBound RECT
	ENDS

	RGNDATA STRUCT
		rdh RGNDATAHEADER
		Buffer CHAR
	ENDS
#endif

#DEFINE GUID_IID_IOverlayNotify <0x56a868a0,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IOverlayNotify STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnPaletteChange PTR
	OnClipChange PTR
	OnColorKeyChange PTR
	OnPositionChange PTR
ENDS

#DEFINE GUID_IID_IOverlayNotify2 <0x680EFA10,0xD535,0x11D1,<0x87,0xC8,0x00,0xA0,0xC9,0x22,0x31,0x96>>

IOverlayNotify2 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnPaletteChange PTR
	OnClipChange PTR
	OnColorKeyChange PTR
	OnPositionChange PTR
	OnDisplayChange PTR
ENDS

#DEFINE GUID_IID_IOverlay <0x56a868a1,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IOverlay STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPalette PTR
	SetPalette PTR
	GetDefaultColorKey PTR
	GetColorKey PTR
	SetColorKey PTR
	GetWindowHandle PTR
	GetClipList PTR
	GetVideoPosition PTR
	Advise PTR
	Unadvise PTR
ENDS

#DEFINE GUID_IID_IMediaEventSink <0x56a868a2,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IMediaEventSink STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Notify PTR
ENDS

#DEFINE GUID_IID_IFileSourceFilter <0x56a868a6,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IFileSourceFilter STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Load PTR
	GetCurFile PTR
ENDS

#DEFINE GUID_IID_IFileSinkFilter <0xa2104830,0x7c70,0x11cf,<0x8b,0xce,0x00,0xaa,0x00,0xa3,0xf1,0xa6>>

IFileSinkFilter STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetFileName PTR
	GetCurFile PTR
ENDS

#DEFINE GUID_IID_IFileSinkFilter2 <0x00855B90,0xCE1B,0x11d0,<0xBD,0x4F,0x00,0xA0,0xC9,0x11,0xCE,0x86>>

IFileSinkFilter2 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetFileName PTR
	GetCurFile PTR
	SetMode PTR
	GetMode PTR
ENDS

// AM_FILESINK_FLAGS
	AM_FILE_OVERWRITE	= 0x1

#DEFINE GUID_IID_IGraphBuilder <0x56a868a9,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IGraphBuilder STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddFilter PTR
	RemoveFilter PTR
	EnumFilters PTR
	FindFilterByName PTR
	ConnectDirect PTR
	Reconnect PTR
	Disconnect PTR
	SetDefaultSyncSource PTR
	Connect PTR
	Render PTR
	RenderFile PTR
	AddSourceFilter PTR
	SetLogFile PTR
	Abort PTR
	ShouldOperationContinue PTR
ENDS

#DEFINE GUID_IID_ICaptureGraphBuilder <0xbf87b6e0,0x8c27,0x11d0,<0xb3,0xf0,0x00,0xaa,0x00,0x37,0x61,0xc5>>

ICaptureGraphBuilder STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetFiltergraph PTR
	GetFiltergraph PTR
	SetOutputFileName PTR
	FindInterface PTR
	RenderStream PTR
	ControlStream PTR
	AllocCapFile PTR
	CopyCaptureFile PTR
ENDS

#DEFINE GUID_IID_IAMCopyCaptureFileProgress <0x670d1d20,0xa068,0x11d0,<0xb3,0xf0,0x00,0xaa,0x00,0x37,0x61,0xc5>>

IAMCopyCaptureFileProgress STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Progress PTR
ENDS

#DEFINE GUID_IID_ICaptureGraphBuilder2 <0x93E5A4E0,0x2D50,0x11d2,<0xAB,0xFA,0x00,0xA0,0xC9,0xC6,0xE3,0x8D>>

ICaptureGraphBuilder2 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetFiltergraph PTR
	GetFiltergraph PTR
	SetOutputFileName PTR
	FindInterface PTR
	RenderStream PTR
	ControlStream PTR
	AllocCapFile PTR
	CopyCaptureFile PTR
	FindPin PTR
ENDS

// AM_RENSDEREXFLAGS
	AM_RENDEREX_RENDERTOEXISTINGRENDERERS	= 0x1

#DEFINE GUID_IID_IFilterGraph2 <0x36b73882,0xc2c8,0x11cf,<0x8b,0x46,0x00,0x80,0x5f,0x6c,0xef,0x60>>

IFilterGraph2 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddFilter PTR
	RemoveFilter PTR
	EnumFilters PTR
	FindFilterByName PTR
	ConnectDirect PTR
	Reconnect PTR
	Disconnect PTR
	SetDefaultSyncSource PTR
	Connect PTR
	Render PTR
	RenderFile PTR
	AddSourceFilter PTR
	SetLogFile PTR
	Abort PTR
	ShouldOperationContinue PTR
	AddSourceFilterForMoniker PTR
	ReconnectEx PTR
	RenderEx PTR
ENDS

#DEFINE GUID_IID_IFilterGraph3 <0xaaf38154,0xb80b,0x422f,<0x91,0xe6,0xb6,0x64,0x67,0x50,0x9a,0x07>>

IFilterGraph3 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddFilter PTR
	RemoveFilter PTR
	EnumFilters PTR
	FindFilterByName PTR
	ConnectDirect PTR
	Reconnect PTR
	Disconnect PTR
	SetDefaultSyncSource PTR
	Connect PTR
	Render PTR
	RenderFile PTR
	AddSourceFilter PTR
	SetLogFile PTR
	Abort PTR
	ShouldOperationContinue PTR
	AddSourceFilterForMoniker PTR
	ReconnectEx PTR
	RenderEx PTR
	SetSyncSourceEx PTR
ENDS

#DEFINE GUID_IID_IStreamBuilder <0x56a868bf,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IStreamBuilder STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Render PTR
	Backout PTR
ENDS

#DEFINE GUID_IID_IAsyncReader <0x56a868aa,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IAsyncReader STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	RequestAllocator PTR
	Request PTR
	WaitForNext PTR
	SyncReadAligned PTR
	SyncRead PTR
	Length PTR
	BeginFlush PTR
	EndFlush PTR
ENDS

#DEFINE GUID_IID_IGraphVersion <0x56a868ab,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IGraphVersion STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryVersion PTR
ENDS

#DEFINE GUID_IID_IResourceConsumer <0x56a868ad,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IResourceConsumer STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	AcquireResource PTR
	ReleaseResource PTR
ENDS

#DEFINE GUID_IID_IResourceManager <0x56a868ac,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IResourceManager STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Register PTR
	RegisterGroup PTR
	RequestResource PTR
	NotifyAcquire PTR
	NotifyRelease PTR
	CancelRequest PTR
	SetFocus PTR
	ReleaseFocus PTR
ENDS

#DEFINE GUID_IID_IDistributorNotify <0x56a868af,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IDistributorNotify STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Stop PTR
	Pause PTR
	Run PTR
	SetSyncSource PTR
	NotifyGraphChange PTR
ENDS

// AM_STREAM_INFO_FLAGS
	AM_STREAM_INFO_START_DEFINED	= 0x1
	AM_STREAM_INFO_STOP_DEFINED	= 0x2
	AM_STREAM_INFO_DISCARDING	= 0x4
	AM_STREAM_INFO_STOP_SEND_EXTRA	= 0x10

AM_STREAM_INFO STRUCT
	tStart LONGLONG
	tStop LONGLONG
	dwStartCookie DD
	dwStopCookie DD
	dwFlags DD
ENDS

#DEFINE GUID_IID_IAMStreamControl <0x36b73881,0xc2c8,0x11cf,<0x8b,0x46,0x00,0x80,0x5f,0x6c,0xef,0x60>>

IAMStreamControl STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	StartAt PTR
	StopAt PTR
	GetInfo PTR
ENDS

#DEFINE GUID_IID_ISeekingPassThru <0x36b73883,0xc2c8,0x11cf,<0x8b,0x46,0x00,0x80,0x5f,0x6c,0xef,0x60>>

ISeekingPassThru STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Init PTR
ENDS

VIDEO_STREAM_CONFIG_CAPS STRUCT
	guid GUID
	VideoStandard LONG
	InputSize SIZE
	MinCroppingSize SIZE
	MaxCroppingSize SIZE
	CropGranularityX LONG
	CropGranularityY LONG
	CropAlignX LONG
	CropAlignY LONG
	MinOutputSize SIZE
	MaxOutputSize SIZE
	OutputGranularityX LONG
	OutputGranularityY LONG
	StretchTapsX LONG
	StretchTapsY LONG
	ShrinkTapsX LONG
	ShrinkTapsY LONG
	MinFrameInterval LONGLONG
	MaxFrameInterval LONGLONG
	MinBitsPerSecond LONG
	MaxBitsPerSecond LONG
ENDS

AUDIO_STREAM_CONFIG_CAPS STRUCT
	guid GUID
	MinimumChannels LONG
	MaximumChannels LONG
	ChannelsGranularity LONG
	MinimumBitsPerSample LONG
	MaximumBitsPerSample LONG
	BitsPerSampleGranularity LONG
	MinimumSampleFrequency LONG
	MaximumSampleFrequency LONG
	SampleFrequencyGranularity LONG
ENDS


#DEFINE GUID_IID_IAMStreamConfig <0xC6E13340,0x30AC,0x11d0,<0xA1,0x8C,0x00,0xA0,0xC9,0x11,0x89,0x56>>

IAMStreamConfig STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetFormat PTR
	GetFormat PTR
	GetNumberOfCapabilities PTR
	GetStreamCaps PTR
ENDS

// InterleavingMode
	INTERLEAVE_NONE	= 0
	INTERLEAVE_CAPTURE	= 1
	INTERLEAVE_FULL	= 2
	INTERLEAVE_NONE_BUFFERED = 3

#DEFINE GUID_IID_IConfigInterleaving <0xBEE3D220,0x157B,0x11d0,<0xBD,0x23,0x00,0xA0,0xC9,0x11,0xCE,0x86>>

IConfigInterleaving STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	put_Mode PTR
	get_Mode PTR
	put_Interleaving PTR
	get_Interleaving PTR
ENDS

#DEFINE GUID_IID_IConfigAviMux <0x5ACD6AA0,0xF482,0x11ce,<0x8B,0x67,0x00,0xAA,0x00,0xA3,0xF1,0xA6>>

IConfigAviMux STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetMasterStream PTR
	GetMasterStream PTR
	SetOutputCompatibilityIndex PTR
	GetOutputCompatibilityIndex PTR
ENDS

// CompressionCaps
	CompressionCaps_CanQuality	= 0x1
	CompressionCaps_CanCrunch	= 0x2
	CompressionCaps_CanKeyFrame	= 0x4
	CompressionCaps_CanBFrame	= 0x8
	CompressionCaps_CanWindow	= 0x10

#DEFINE GUID_IID_IAMVideoCompression <0xC6E13343,0x30AC,0x11d0,<0xA1,0x8C,0x00,0xA0,0xC9,0x11,0x89,0x56>>

IAMVideoCompression STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	put_KeyFrameRate PTR
	get_KeyFrameRate PTR
	put_PFramesPerKeyFrame PTR
	get_PFramesPerKeyFrame PTR
	put_Quality PTR
	get_Quality PTR
	put_WindowSize PTR
	get_WindowSize PTR
	GetInfo PTR
	OverrideKeyFrame PTR
	OverrideFrameSize PTR
ENDS

// VfwCaptureDialogs
	VfwCaptureDialog_Source	= 0x1
	VfwCaptureDialog_Format	= 0x2
	VfwCaptureDialog_Display	= 0x4

// VfwCompressDialogs
	VfwCompressDialog_Config	= 0x1
	VfwCompressDialog_About	= 0x2
	VfwCompressDialog_QueryConfig	= 0x4
	VfwCompressDialog_QueryAbout	= 0x8

#DEFINE GUID_IID_IAMVfwCaptureDialogs <0xD8D715A0,0x6E5E,0x11D0,<0xb3,0xf0,0x00,0xaa,0x00,0x37,0x61,0xc5>>

IAMVfwCaptureDialogs STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	HasDialog PTR
	ShowDialog PTR
	SendDriverMessage PTR
ENDS

#DEFINE GUID_IID_IAMVfwCompressDialogs <0xD8D715A3,0x6E5E,0x11D0,<0xb3,0xf0,0x00,0xaa,0x00,0x37,0x61,0xc5>>

IAMVfwCompressDialogs STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	ShowDialog PTR
	GetState PTR
	SetState PTR
	SendDriverMessage PTR
ENDS

#DEFINE GUID_IID_IAMDroppedFrames <0xC6E13344,0x30AC,0x11d0,<0xA1,0x8C,0x00,0xA0,0xC9,0x11,0x89,0x56>>

IAMDroppedFrames STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetNumDropped PTR
	GetNumNotDropped PTR
	GetDroppedInfo PTR
	GetAverageFrameSize PTR
ENDS

#define AMF_AUTOMATICGAIN -1.0

#DEFINE GUID_IID_IAMAudioInputMixer <0x54C39221,0x8380,0x11d0,<0xb3,0xf0,0x00,0xaa,0x00,0x37,0x61,0xc5>>

IAMAudioInputMixer STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	put_Enable PTR
	get_Enable PTR
	put_Mono PTR
	get_Mono PTR
	put_MixLevel PTR
	get_MixLevel PTR
	put_Pan PTR
	get_Pan PTR
	put_Loudness PTR
	get_Loudness PTR
	put_Treble PTR
	get_Treble PTR
	get_TrebleRange PTR
	put_Bass PTR
	get_Bass PTR
	get_BassRange PTR
ENDS

#DEFINE GUID_IID_IAMBufferNegotiation <0x56ED71A0,0xAF5F,0x11D0,<0xb3,0xf0,0x00,0xaa,0x00,0x37,0x61,0xc5>>

IAMBufferNegotiation STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SuggestAllocatorProperties PTR
	GetAllocatorProperties PTR
ENDS

// AnalogVideoStandard
	AnalogVideo_None	= 0
	AnalogVideo_NTSC_M	= 0x1
	AnalogVideo_NTSC_M_J	= 0x2
	AnalogVideo_NTSC_433	= 0x4
	AnalogVideo_PAL_B	= 0x10
	AnalogVideo_PAL_D	= 0x20
	AnalogVideo_PAL_G	= 0x40
	AnalogVideo_PAL_H	= 0x80
	AnalogVideo_PAL_I	= 0x100
	AnalogVideo_PAL_M	= 0x200
	AnalogVideo_PAL_N	= 0x400
	AnalogVideo_PAL_60	= 0x800
	AnalogVideo_SECAM_B	= 0x1000
	AnalogVideo_SECAM_D	= 0x2000
	AnalogVideo_SECAM_G	= 0x4000
	AnalogVideo_SECAM_H	= 0x8000
	AnalogVideo_SECAM_K	= 0x10000
	AnalogVideo_SECAM_K1	= 0x20000
	AnalogVideo_SECAM_L	= 0x40000
	AnalogVideo_SECAM_L1	= 0x80000
	AnalogVideo_PAL_N_COMBO	= 0x100000
	AnalogVideoMask_MCE_NTSC	= (AnalogVideo_NTSC_M | AnalogVideo_NTSC_M_J  | AnalogVideo_NTSC_433 | AnalogVideo_PAL_M | AnalogVideo_PAL_N | AnalogVideo_PAL_60 | AnalogVideo_PAL_N_COMBO )
	AnalogVideoMask_MCE_PAL	= (AnalogVideo_PAL_B | AnalogVideo_PAL_D | AnalogVideo_PAL_G | AnalogVideo_PAL_H | AnalogVideo_PAL_I )
	AnalogVideoMask_MCE_SECAM	= (AnalogVideo_SECAM_B | AnalogVideo_SECAM_D | AnalogVideo_SECAM_G | AnalogVideo_SECAM_H | AnalogVideo_SECAM_K | AnalogVideo_SECAM_K1 | AnalogVideo_SECAM_L | AnalogVideo_SECAM_L1 ) 

// TunerInputType
	TunerInputCable	= 0
	TunerInputAntenna	= 1

#define AnalogVideo_NTSC_Mask  0x00000007
#define AnalogVideo_PAL_Mask   0x00100FF0
#define AnalogVideo_SECAM_Mask 0x000FF000

// VideoCopyProtectionType
	VideoCopyProtectionMacrovisionBasic	= 0
	VideoCopyProtectionMacrovisionCBI	= 1

// PhysicalConnectorType
	PhysConn_Video_Tuner	= 1
	PhysConn_Video_Composite	= 2
	PhysConn_Video_SVideo	= 3
	PhysConn_Video_RGB	= 4
	PhysConn_Video_YRYBY	= 5
	PhysConn_Video_SerialDigital	= 6
	PhysConn_Video_ParallelDigital	= 7
	PhysConn_Video_SCSI	= 8
	PhysConn_Video_AUX	= 9
	PhysConn_Video_1394	= 10
	PhysConn_Video_USB	= 11
	PhysConn_Video_VideoDecoder	= 12
	PhysConn_Video_VideoEncoder	= 13
	PhysConn_Video_SCART	= 14
	PhysConn_Video_Black	= 15
	PhysConn_Audio_Tuner	= 4096
	PhysConn_Audio_Line	= 4097
	PhysConn_Audio_Mic	= 4098
	PhysConn_Audio_AESDigital	= 4099
	PhysConn_Audio_SPDIFDigital	= 4100
	PhysConn_Audio_SCSI	= 4101
	PhysConn_Audio_AUX	= 4102
	PhysConn_Audio_1394	= 4103
	PhysConn_Audio_USB	= 4104
	PhysConn_Audio_AudioDecoder	= 4105

#DEFINE GUID_IID_IAMAnalogVideoDecoder <0xC6E13350,0x30AC,0x11d0,<0xA1,0x8C,0x00,0xA0,0xC9,0x11,0x89,0x56>>

IAMAnalogVideoDecoder STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_AvailableTVFormats PTR
	put_TVFormat PTR
	get_TVFormat PTR
	get_HorizontalLocked PTR
	put_VCRHorizontalLocking PTR
	get_VCRHorizontalLocking PTR
	get_NumberOfLines PTR
	put_OutputEnable PTR
	get_OutputEnable PTR
ENDS

// VideoProcAmpProperty
	VideoProcAmp_Brightness	= 0
	VideoProcAmp_Contrast	= 1
	VideoProcAmp_Hue	= 2
	VideoProcAmp_Saturation	= 3
	VideoProcAmp_Sharpness	= 4
	VideoProcAmp_Gamma	= 5
	VideoProcAmp_ColorEnable	= 6
	VideoProcAmp_WhiteBalance	= 7
	VideoProcAmp_BacklightCompensation	= 8
	VideoProcAmp_Gain	= 9

// VideoProcAmpFlags
	VideoProcAmp_Flags_Auto	= 0x1
	VideoProcAmp_Flags_Manual	= 0x2

#DEFINE GUID_IID_IAMVideoProcAmp <0xC6E13360,0x30AC,0x11d0,<0xA1,0x8C,0x00,0xA0,0xC9,0x11,0x89,0x56>>

IAMVideoProcAmp STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetRange PTR
	Set PTR
	Get PTR
ENDS

// CameraControlProperty
	CameraControl_Pan	= 0
	CameraControl_Tilt	= 1
	CameraControl_Roll	= 2
	CameraControl_Zoom	= 3
	CameraControl_Exposure	= 4
	CameraControl_Iris	= 5
	CameraControl_Focus	= 6

// CameraControlFlags
	CameraControl_Flags_Auto	= 0x1
	CameraControl_Flags_Manual	= 0x2

#DEFINE GUID_IID_IAMCameraControl <0xC6E13370,0x30AC,0x11d0,<0xA1,0x8C,0x00,0xA0,0xC9,0x11,0x89,0x56>>

IAMCameraControl STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetRange PTR
	Set PTR
	Get PTR
ENDS

// VideoControlFlags
	VideoControlFlag_FlipHorizontal	= 0x1
	VideoControlFlag_FlipVertical	= 0x2
	VideoControlFlag_ExternalTriggerEnable	= 0x4
	VideoControlFlag_Trigger	= 0x8

#DEFINE GUID_IID_IAMVideoControl <0x6a2e0670,0x28e4,0x11d0,<0xA1,0x8C,0x00,0xA0,0xC9,0x11,0x89,0x56>>

IAMVideoControl STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCaps PTR
	SetMode PTR
	GetMode PTR
	GetCurrentActualFrameRate PTR
	GetMaxAvailableFrameRate PTR
	GetFrameRateList PTR
ENDS

#DEFINE GUID_IID_IAMCrossbar <0xC6E13380,0x30AC,0x11d0,<0xA1,0x8C,0x00,0xA0,0xC9,0x11,0x89,0x56>>

IAMCrossbar STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_PinCounts PTR
	CanRoute PTR
	Route PTR
	get_IsRoutedTo PTR
	get_CrossbarPinInfo PTR
ENDS

// AMTunerSubChannel
	AMTUNER_SUBCHAN_NO_TUNE	= -2
	AMTUNER_SUBCHAN_DEFAULT	= -1

// AMTunerSignalStrength
	AMTUNER_HASNOSIGNALSTRENGTH	= -1
	AMTUNER_NOSIGNAL	= 0
	AMTUNER_SIGNALPRESENT	= 1

// AMTunerModeType
	AMTUNER_MODE_DEFAULT	= 0
	AMTUNER_MODE_TV	= 0x1
	AMTUNER_MODE_FM_RADIO	= 0x2
	AMTUNER_MODE_AM_RADIO	= 0x4
	AMTUNER_MODE_DSS	= 0x8

// AMTunerEventType
	AMTUNER_EVENT_CHANGED	= 0x1

#DEFINE GUID_IID_IAMTuner <0x211A8761,0x03AC,0x11d1,<0x8D,0x13,0x00,0xAA,0x00,0xBD,0x83,0x39>>

IAMTuner STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	put_Channel PTR
	get_Channel PTR
	ChannelMinMax PTR
	put_CountryCode PTR
	get_CountryCode PTR
	put_TuningSpace PTR
	get_TuningSpace PTR
	Logon PTR
	Logout PTR
	SignalPresent PTR
	put_Mode PTR
	get_Mode PTR
	GetAvailableModes PTR
	RegisterNotificationCallBack PTR
	UnRegisterNotificationCallBack PTR
ENDS

#DEFINE GUID_IID_IAMTunerNotification <0x211A8760,0x03AC,0x11d1,<0x8D,0x13,0x00,0xAA,0x00,0xBD,0x83,0x39>>

IAMTunerNotification STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnEvent PTR
ENDS

#DEFINE GUID_IID_IAMTVTuner <0x211A8766,0x03AC,0x11d1,<0x8D,0x13,0x00,0xAA,0x00,0xBD,0x83,0x39>>

IAMTVTuner STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	put_Channel PTR
	get_Channel PTR
	ChannelMinMax PTR
	put_CountryCode PTR
	get_CountryCode PTR
	put_TuningSpace PTR
	get_TuningSpace PTR
	Logon PTR
	Logout PTR
	SignalPresent PTR
	put_Mode PTR
	get_Mode PTR
	GetAvailableModes PTR
	RegisterNotificationCallBack PTR
	UnRegisterNotificationCallBack PTR
	get_AvailableTVFormats PTR
	get_TVFormat PTR
	AutoTune PTR
	StoreAutoTune PTR
	get_NumInputConnections PTR
	put_InputType PTR
	get_InputType PTR
	put_ConnectInput PTR
	get_ConnectInput PTR
	get_VideoFrequency PTR
	get_AudioFrequency PTR
ENDS

#DEFINE GUID_IID_IBPCSatelliteTuner <0x211A8765,0x03AC,0x11d1,<0x8D,0x13,0x00,0xAA,0x00,0xBD,0x83,0x39>>

IBPCSatelliteTuner STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	put_Channel PTR
	get_Channel PTR
	ChannelMinMax PTR
	put_CountryCode PTR
	get_CountryCode PTR
	put_TuningSpace PTR
	get_TuningSpace PTR
	Logon PTR
	Logout PTR
	SignalPresent PTR
	put_Mode PTR
	get_Mode PTR
	GetAvailableModes PTR
	RegisterNotificationCallBack PTR
	UnRegisterNotificationCallBack PTR
	get_DefaultSubChannelTypes PTR
	put_DefaultSubChannelTypes PTR
	IsTapingPermitted PTR
ENDS

// TVAudioMode
	AMTVAUDIO_MODE_MONO	= 0x1
	AMTVAUDIO_MODE_STEREO	= 0x2
	AMTVAUDIO_MODE_LANG_A	= 0x10
	AMTVAUDIO_MODE_LANG_B	= 0x20
	AMTVAUDIO_MODE_LANG_C	= 0x40
	AMTVAUDIO_PRESET_STEREO	= 0x200
	AMTVAUDIO_PRESET_LANG_A	= 0x1000
	AMTVAUDIO_PRESET_LANG_B	= 0x2000
	AMTVAUDIO_PRESET_LANG_C	= 0x4000

// AMTVAudioEventType
	AMTVAUDIO_EVENT_CHANGED	= 0x1

#DEFINE GUID_IID_IAMTVAudio <0x83EC1C30,0x23D1,0x11d1,<0x99,0xE6,0x00,0xA0,0xC9,0x56,0x02,0x66>>

IAMTVAudio STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetHardwareSupportedTVAudioModes PTR
	GetAvailableTVAudioModes PTR
	get_TVAudioMode PTR
	put_TVAudioMode PTR
	RegisterNotificationCallBack PTR
	UnRegisterNotificationCallBack PTR
ENDS

#DEFINE GUID_IID_IAMTVAudioNotification <0x83EC1C33,0x23D1,0x11d1,<0x99,0xE6,0x00,0xA0,0xC9,0x56,0x02,0x66>>>

IAMTVAudioNotification STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnEvent PTR
ENDS

#DEFINE GUID_IID_IAMAnalogVideoEncoder <0xC6E133B0,0x30AC,0x11d0,<0xA1,0x8C,0x00,0xA0,0xC9,0x11,0x89,0x56>>

IAMAnalogVideoEncoder STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_AvailableTVFormats PTR
	put_TVFormat PTR
	get_TVFormat PTR
	put_CopyProtection PTR
	get_CopyProtection PTR
	put_CCEnable PTR
	get_CCEnable PTR
ENDS

// AMPROPERTY_PIN
	AMPROPERTY_PIN_CATEGORY	= 0
	AMPROPERTY_PIN_MEDIUM	= 1

#define KSPROPERTY_SUPPORT_GET  1
#define KSPROPERTY_SUPPORT_SET  2

#DEFINE GUID_IID_IKsPropertySet <0x31EFAC30,0x515C,0x11d0,<0xA9,0xAA,0x00,0xAA,0x00,0x61,0xBE,0x93>>

IKsPropertySet STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Set PTR
	Get PTR
	QuerySupported PTR
ENDS

#DEFINE GUID_IID_IMediaPropertyBag <0x6025A880,0xC0D5,0x11d0,<0xBD,0x4E,0x00,0xA0,0xC9,0x11,0xCE,0x86>>

IMediaPropertyBag STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Read PTR
	Write PTR
	EnumProperty PTR
ENDS

#DEFINE GUID_IID_IPersistMediaPropertyBag <0x5738E040,0xB67F,0x11d0,<0xBD,0x4D,0x00,0xA0,0xC9,0x11,0xCE,0x86>>

IPersistMediaPropertyBag STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetClassID PTR
	InitNew PTR
	Load PTR
	Save PTR
ENDS

#DEFINE GUID_IID_IAMPhysicalPinInfo <0xF938C991,0x3029,0x11cf,<0x8C,0x44,0x00,0xAA,0x00,0x6B,0x68,0x14>>

IAMPhysicalPinInfo STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPhysicalType PTR
ENDS

#DEFINE GUID_IID_IAMExtDevice <0xB5730A90,0x1A2C,0x11cf,<0x8C,0x23,0x00,0xAA,0x00,0x6B,0x68,0x14>>

IAMExtDevice STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCapability PTR
	get_ExternalDeviceID PTR
	get_ExternalDeviceVersion PTR
	put_DevicePower PTR
	get_DevicePower PTR
	Calibrate PTR
	put_DevicePort PTR
	get_DevicePort PTR
ENDS

#DEFINE GUID_IID_IAMExtTransport <0xA03CD5F0,0x3045,0x11cf,<0x8C,0x44,0x00,0xAA,0x00,0x6B,0x68,0x14>>

IAMExtTransport STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCapability PTR
	put_MediaState PTR
	get_MediaState PTR
	put_LocalControl PTR
	get_LocalControl PTR
	GetStatus PTR
	GetTransportBasicParameters PTR
	SetTransportBasicParameters PTR
	GetTransportVideoParameters PTR
	SetTransportVideoParameters PTR
	GetTransportAudioParameters PTR
	SetTransportAudioParameters PTR
	put_Mode PTR
	get_Mode PTR
	put_Rate PTR
	get_Rate PTR
	GetChase PTR
	SetChase PTR
	GetBump PTR
	SetBump PTR
	get_AntiClogControl PTR
	put_AntiClogControl PTR
	GetEditPropertySet PTR
	SetEditPropertySet PTR
	GetEditProperty PTR
	SetEditProperty PTR
	get_EditStart PTR
	put_EditStart PTR
ENDS

TIMECODE STRUCT
	wFrameRate DW
	wFrameFract DW
	dwFrames DD
	qw DWORDLONG
ENDS

TIMECODE_SAMPLE STRUCT
	qwTick LONGLONG
	timecode TIMECODE
	dwUser DD
	dwFlags DD
ENDS

#DEFINE GUID_IID_IAMTimecodeReader <0x9B496CE1,0x811B,0x11cf,<0x8C,0x77,0x00,0xAA,0x00,0x6B,0x68,0x14>>

IAMTimecodeReader STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetTCRMode PTR
	SetTCRMode PTR
	put_VITCLine PTR
	get_VITCLine PTR
	GetTimecode PTR
ENDS

#DEFINE GUID_IID_IAMTimecodeGenerator <0x9B496CE0,0x811B,0x11cf,<0x8C,0x77,0x00,0xAA,0x00,0x6B,0x68,0x14>>

IAMTimecodeGenerator STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetTCGMode PTR
	SetTCGMode PTR
	put_VITCLine PTR
	get_VITCLine PTR
	SetTimecode PTR
	GetTimecode PTR
ENDS

#DEFINE GUID_IID_IAMTimecodeDisplay <0x9B496CE2,0x811B,0x11cf,<0x8C,0x77,0x00,0xAA,0x00,0x6B,0x68,0x14>>

IAMTimecodeDisplay STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetTCDisplayEnable PTR
	SetTCDisplayEnable PTR
	GetTCDisplay PTR
	SetTCDisplay PTR
ENDS

#DEFINE GUID_IID_IAMDevMemoryAllocator <0xc6545bf0,0xe76b,0x11d0,<0xbd,0x52,0x00,0xa0,0xc9,0x11,0xce,0x86>>

IAMDevMemoryAllocator STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetInfo PTR
	CheckMemory PTR
	Alloc PTR
	Free PTR
	GetDevMemoryObject PTR
ENDS

#DEFINE GUID_IID_IAMDevMemoryControl <0xc6545bf1,0xe76b,0x11d0,<0xbd,0x52,0x00,0xa0,0xc9,0x11,0xce,0x86>>

IAMDevMemoryControl STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryWriteSync PTR
	WriteSync PTR
	GetDevId PTR
ENDS

// AMSTREAMSELECTINFOFLAGS
	AMSTREAMSELECTINFO_ENABLED	= 0x1
	AMSTREAMSELECTINFO_EXCLUSIVE	= 0x2

// AMSTREAMSELECTENABLEFLAGS
	AMSTREAMSELECTENABLE_ENABLE	= 0x1
	AMSTREAMSELECTENABLE_ENABLEALL	= 0x2

#DEFINE GUID_IID_IAMStreamSelect <0xc1960960,0x17f5,0x11d1,<0xab,0xe1,0x00,0xa0,0xc9,0x05,0xf3,0x75>>

IAMStreamSelect STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Count PTR
	Info PTR
	Enable PTR
ENDS

// AMRESCTL_RESERVEFLAGS
	AMRESCTL_RESERVEFLAGS_RESERVE	= 0
	AMRESCTL_RESERVEFLAGS_UNRESERVE	= 0x1

#DEFINE GUID_IID_IAMResourceControl <0x8389d2d0,0x77d7,0x11d1,<0xab,0xe6,0x00,0xa0,0xc9,0x05,0xf3,0x75>>

IAMResourceControl STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Reserve PTR
ENDS

#DEFINE GUID_IID_IAMClockAdjust <0x4d5466b0,0xa49c,0x11d1,<0xab,0xe8,0x00,0xa0,0xc9,0x05,0xf3,0x75>>

IAMClockAdjust STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetClockDelta PTR
ENDS

// AM_FILTER_MISC_FLAGS
	AM_FILTER_MISC_FLAGS_IS_RENDERER	= 0x1
	AM_FILTER_MISC_FLAGS_IS_SOURCE	= 0x2

#DEFINE GUID_IID_IAMFilterMiscFlags <0x2dd74950,0xa890,0x11d1,<0xab,0xe8,0x00,0xa0,0xc9,0x05,0xf3,0x75>>

IAMFilterMiscFlags STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetMiscFlags PTR
ENDS

#DEFINE GUID_IID_IDrawVideoImage <0x48efb120,0xab49,0x11d2,<0xae,0xd2,0x00,0xa0,0xc9,0x95,0xe8,0xd5>>

IDrawVideoImage STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	DrawVideoImageBegin PTR
	DrawVideoImageEnd PTR
	DrawVideoImageDraw PTR
ENDS

#DEFINE GUID_IID_IDecimateVideoImage <0x2e5ea3e0,0xe924,0x11d2,<0xb6,0xda,0x00,0xa0,0xc9,0x95,0xe8,0xdf>>

IDecimateVideoImage STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetDecimationImageSize PTR
	ResetDecimationImageSize PTR
ENDS

// DECIMATION_USAGE
	DECIMATION_LEGACY	= 0
	DECIMATION_USE_DECODER_ONLY	= 1
	DECIMATION_USE_VIDEOPORT_ONLY	= 2
	DECIMATION_USE_OVERLAY_ONLY	= 3
	DECIMATION_DEFAULT	= 4

#DEFINE GUID_IID_IAMVideoDecimationProperties <0x60d32930,0x13da,0x11d3,<0x9e,0xc6,0xc4,0xfc,0xae,0xf5,0xc7,0xbe>>

IAMVideoDecimationProperties STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryDecimationUsage PTR
	SetDecimationUsage PTR
ENDS

#DEFINE GUID_IID_IVideoFrameStep <0xe46a9787,0x2b71,0x444d,<0xa4,0xb5,0x1f,0xab,0x7b,0x70,0x8d,0x6a>>

IVideoFrameStep STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Step PTR
	CanStep PTR
	CancelStep PTR
ENDS

// AM_PUSHSOURCE_FLAGS
	AM_PUSHSOURCECAPS_INTERNAL_RM	= 0x1
	AM_PUSHSOURCECAPS_NOT_LIVE	= 0x2
	AM_PUSHSOURCECAPS_PRIVATE_CLOCK	= 0x4
	AM_PUSHSOURCEREQS_USE_STREAM_CLOCK	= 0x10000
	AM_PUSHSOURCEREQS_USE_CLOCK_CHAIN	= 0x20000

#DEFINE GUID_IID_IAMLatency <0x62EA93BA,0xEC62,0x11d2,<0xB7,0x70,0x00,0xC0,0x4F,0xB6,0xBD,0x3D>>

IAMLatency STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLatency PTR
ENDS

#DEFINE GUID_IID_IAMPushSource <0xF185FE76,0xE64E,0x11d2,<0xB7,0x6E,0x00,0xC0,0x4F,0xB6,0xBD,0x3D>>

IAMPushSource STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLatency PTR
	GetPushSourceFlags PTR
	SetPushSourceFlags PTR
	SetStreamOffset PTR
	GetStreamOffset PTR
	GetMaxStreamOffset PTR
	SetMaxStreamOffset PTR
ENDS

#DEFINE GUID_IID_IAMDeviceRemoval <0xf90a6130,0xb658,0x11d2,<0xae,0x49,0x00,0x00,0xf8,0x75,0x4b,0x99>>

IAMDeviceRemoval STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	DeviceInfo PTR
	Reassociate PTR
	Disassociate PTR
ENDS

DVINFO STRUCT
	dwDVAAuxSrc DD
	dwDVAAuxCtl DD
	dwDVAAuxSrc1 DD
	dwDVAAuxCtl1 DD
	dwDVVAuxSrc DD
	dwDVVAuxCtl DD
	dwDVReserved DD 2 DUP
ENDS

// DVENCODERRESOLUTION
	DVENCODERRESOLUTION_720x480	= 2012
	DVENCODERRESOLUTION_360x240	= 2013
	DVENCODERRESOLUTION_180x120	= 2014
	DVENCODERRESOLUTION_88x60	= 2015

// DVENCODERVIDEOFORMAT
	DVENCODERVIDEOFORMAT_NTSC	= 2000
	DVENCODERVIDEOFORMAT_PAL	= 2001

// DVENCODERFORMAT
	DVENCODERFORMAT_DVSD	= 2007
	DVENCODERFORMAT_DVHD	= 2008
	DVENCODERFORMAT_DVSL	= 2009

#DEFINE GUID_IID_IDVEnc <0xd18e17a0,0xaacb,0x11d0,<0xaf,0xb0,0x00,0xaa,0x00,0xb6,0x7a,0x42>>

IDVEnc STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_IFormatResolution PTR
	put_IFormatResolution PTR
ENDS

// DVDECODERRESOLUTION
	DVDECODERRESOLUTION_720x480	= 1000
	DVDECODERRESOLUTION_360x240	= 1001
	DVDECODERRESOLUTION_180x120	= 1002
	DVDECODERRESOLUTION_88x60	= 1003

// DVRESOLUTION
	DVRESOLUTION_FULL	= 1000
	DVRESOLUTION_HALF	= 1001
	DVRESOLUTION_QUARTER	= 1002
	DVRESOLUTION_DC	= 1003

#DEFINE GUID_IID_IIPDVDec <0xb8e8bd60,0x0bfe,0x11d0,<0xaf,0x91,0x00,0xaa,0x00,0xb6,0x7a,0x42>>

IIPDVDec STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_IPDisplay PTR
	put_IPDisplay PTR
ENDS

#DEFINE GUID_IID_IDVRGB219 <0x58473A19,0x2BC8,0x4663,<0x80,0x12,0x25,0xF8,0x1B,0xAB,0xDD,0xD1>>

IDVRGB219 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetRGB219 PTR
ENDS

#DEFINE GUID_IID_IDVSplitter <0x92a3a302,0xda7c,0x4a1f,<0xba,0x7e,0x18,0x02,0xbb,0x5d,0x2d,0x02>>

IDVSplitter STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	DiscardAlternateVideoFrames PTR
ENDS

// AM_AUDIO_RENDERER_STAT_PARAM
	AM_AUDREND_STAT_PARAM_BREAK_COUNT = 1
	AM_AUDREND_STAT_PARAM_SLAVE_MODE = 2
	AM_AUDREND_STAT_PARAM_SILENCE_DUR = 3
	AM_AUDREND_STAT_PARAM_LAST_BUFFER_DUR = 4
	AM_AUDREND_STAT_PARAM_DISCONTINUITIES = 5
	AM_AUDREND_STAT_PARAM_SLAVE_RATE = 6
	AM_AUDREND_STAT_PARAM_SLAVE_DROPWRITE_DUR = 7
	AM_AUDREND_STAT_PARAM_SLAVE_HIGHLOWERROR = 8
	AM_AUDREND_STAT_PARAM_SLAVE_LASTHIGHLOWERROR = 9
	AM_AUDREND_STAT_PARAM_SLAVE_ACCUMERROR = 10
	AM_AUDREND_STAT_PARAM_BUFFERFULLNESS = 11
	AM_AUDREND_STAT_PARAM_JITTER = 12

#DEFINE GUID_IID_IAMAudioRendererStats <0x22320CB2,0xD41A,0x11d2,<0xBF,0x7C,0xD7,0xCB,0x9D,0xF0,0xBF,0x93>>

IAMAudioRendererStats STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetStatParam PTR
ENDS

// AM_INTF_SEARCH_FLAGS
	AM_INTF_SEARCH_INPUT_PIN	= 0x1
	AM_INTF_SEARCH_OUTPUT_PIN	= 0x2
	AM_INTF_SEARCH_FILTER	= 0x4

#DEFINE GUID_IID_IAMGraphStreams <0x632105FA,0x072E,0x11d3,<0x8A,0xF9,0x00,0xC0,0x4F,0xB6,0xBD,0x3D>>

IAMGraphStreams STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	FindUpstreamInterface PTR
	SyncUsingStreamOffset PTR
	SetMaxGraphLatency PTR
ENDS

// AMOVERLAYFX
	AMOVERFX_NOFX	= 0
	AMOVERFX_MIRRORLEFTRIGHT	= 0x2
	AMOVERFX_MIRRORUPDOWN	= 0x4
	AMOVERFX_DEINTERLACE	= 0x8

#DEFINE GUID_IID_IAMOverlayFX <0x62fae250,0x7e65,0x4460,<0xbf,0xc9,0x63,0x98,0xb3,0x22,0x07,0x3c>>

IAMOverlayFX STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryOverlayFXCaps PTR
	SetOverlayFX PTR
	GetOverlayFX PTR
ENDS

#DEFINE GUID_IID_IAMOpenProgress <0x8E1C39A1,0xDE53,0x11cf,<0xA,0xA63,0x00,0x80,0xC7,0x44,0x52,0x8D>>

IAMOpenProgress STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryProgress PTR
	AbortOperation PTR
ENDS

#DEFINE GUID_IID_IMpeg2Demultiplexer <0x436eee9c,0x264f,0x4242,<0x90,0xe1,0x4e,0x33,0x0c,0x10,0x75,0x12>>

IMpeg2Demultiplexer STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateOutputPin PTR
	SetOutputPinMediaType PTR
	DeleteOutputPin PTR
ENDS

#define MPEG2_PROGRAM_STREAM_MAP                 0x00000000
#define MPEG2_PROGRAM_ELEMENTARY_STREAM          0x00000001
#define MPEG2_PROGRAM_DIRECTORY_PES_PACKET       0x00000002
#define MPEG2_PROGRAM_PACK_HEADER                0x00000003
#define MPEG2_PROGRAM_PES_STREAM                 0x00000004
#define MPEG2_PROGRAM_SYSTEM_HEADER              0x00000005
#define SUBSTREAM_FILTER_VAL_NONE                0x10000000

STREAM_ID_MAP STRUCT
	stream_id LONG
	dwMediaSampleContent DD
	ulSubstreamFilterValue LONG
	iDataOffset LONG
ENDS

#DEFINE GUID_IID_IEnumStreamIdMap <0x945C1566,0x6202,0x46fc,<0x96,0xC7,0xD8,0x7F,0x28,0x9C,0x65,0x34>>

IEnumStreamIdMap STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#DEFINE GUID_IID_IMPEG2StreamIdMap <0xD0E04C47,0x25B8,0x4369,<0x92,0x5A,0x36,0x2A,0x01,0xD9,0x54,0x44>>

IMPEG2StreamIdMap STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	MapStreamId PTR
	UnmapStreamId PTR
	EnumStreamIdMap PTR
ENDS

#DEFINE GUID_IID_IRegisterServiceProvider <0x7B3A2F01,0x0751,0x48DD,<0xB5,0x56,0x00,0x47,0x85,0x17,0x1C,0x54>>

IRegisterServiceProvider STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	RegisterService PTR
ENDS

#DEFINE GUID_IID_IAMClockSlave <0x9FD52741,0x176D,0x4b36,<0x8F,0x51,0xCA,0x8F,0x93,0x32,0x23,0xBE>>

IAMClockSlave STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetErrorTolerance PTR
	GetErrorTolerance PTR
ENDS

#DEFINE GUID_IID_IAMGraphBuilderCallback <0x4995f511,0x9ddb,0x4f12,<0xbd,0x3b,0xf0,0x46,0x11,0x80,0x7b,0x79>>

IAMGraphBuilderCallback STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SelectedFilter PTR
	CreatedFilter PTR
ENDS

/*
// Note: Because this interface was not defined as a proper interface it is
//       supported under C++ only. Methods aren't stdcall.
#DEFINE GUID_IID_IAMFilterGraphCallback <0x56a868fd,0x0ad4,0x11ce,<0xb0,0xa3,0x0,0x20,0xaf,0x0b,0xa7,0x70>>

IAMFilterGraphCallback STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	UnableToRender PTR
ENDS
*/

CodecAPIEventData STRUCT
	guid GUID
	dataLength DD
	reserved DD 3 DUP
ENDS

#DEFINE GUID_IID_ICodecAPI <0x901db4c7,0x31ce,0x41a2,<0x85,0xdc,0x8f,0xa0,0xbf,0x41,0xb8,0xda>>

ICodecAPI STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	IsSupported PTR
	IsModifiable PTR
	GetParameterRange PTR
	GetParameterValues PTR
	GetDefaultValue PTR
	GetValue PTR
	SetValue PTR
	RegisterForEvent PTR
	UnregisterForEvent PTR
	SetAllDefaults PTR
	SetValueWithNotify PTR
	SetAllDefaultsWithNotify PTR
	GetAllSettings PTR
	SetAllSettings PTR
	SetAllSettingsWithNotify PTR
ENDS

#DEFINE GUID_IID_IGetCapabilitiesKey <0xa8809222,0x07bb,0x48ea,<0x95,0x1c,0x33,0x15,0x81,0x00,0x62,0x5b>>

IGetCapabilitiesKey STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCapabilitiesKey PTR
ENDS

#DEFINE GUID_IID_IEncoderAPI <0x70423839,0x6ACC,0x4b23,<0xB0,0x79,0x21,0xDB,0xF0,0x81,0x56,0xA5>>

IEncoderAPI STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	IsSupported PTR
	IsAvailable PTR
	GetParameterRange PTR
	GetParameterValues PTR
	GetDefaultValue PTR
	GetValue PTR
	SetValue PTR
ENDS

#DEFINE GUID_IID_IVideoEncoder <0x02997C3B,0x8E1B,0x460e,<0x92,0x70,0x54,0x5E,0x0D,0xE9,0x56,0x3E>>

IVideoEncoder STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	IsSupported PTR
	IsAvailable PTR
	GetParameterRange PTR
	GetParameterValues PTR
	GetDefaultValue PTR
	GetValue PTR
	SetValue PTR
ENDS

// VIDEOENCODER_BITRATE_MODE
	ConstantBitRate	= 0
	VariableBitRateAverage	= 1
	VariableBitRatePeak	= 2

#define AM_GETDECODERCAP_QUERY_VMR_SUPPORT   0x00000001
#define VMR_NOTSUPPORTED 0x00000000
#define VMR_SUPPORTED 0x00000001
#define AM_QUERY_DECODER_VMR_SUPPORT         0x00000001
#define AM_QUERY_DECODER_DXVA_1_SUPPORT      0x00000002
#define AM_QUERY_DECODER_DVD_SUPPORT         0x00000003
#define AM_QUERY_DECODER_ATSC_SD_SUPPORT     0x00000004
#define AM_QUERY_DECODER_ATSC_HD_SUPPORT     0x00000005
#define AM_GETDECODERCAP_QUERY_VMR9_SUPPORT  0x00000006
#define AM_GETDECODERCAP_QUERY_EVR_SUPPORT   0x00000007
#define DECODER_CAP_NOTSUPPORTED 0x00000000
#define DECODER_CAP_SUPPORTED 0x00000001

#DEFINE GUID_IID_IAMDecoderCaps <0xc0dff467,0xd499,0x4986,<0x97,0x2b,0xe1,0xd9,0x09,0x0f,0xa9,0x41>>

IAMDecoderCaps STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDecoderCaps PTR
ENDS

AMCOPPSignature STRUCT
	Signature DB 256 DUP
ENDS

AMCOPPCommand STRUCT
	macKDI GUID
	guidCommandID GUID
	dwSequence DD
	cbSizeData DD
	CommandData DB 4056 DUP
ENDS

AMCOPPStatusInput STRUCT
	rApp GUID
	guidStatusRequestID GUID
	dwSequence DD
	cbSizeData DD
	StatusData DB 4056 DUP
ENDS

AMCOPPStatusOutput STRUCT
	macKDI GUID
	cbSizeData DD
	COPPStatus DB 4076 DUP
ENDS

#DEFINE GUID_IID_IAMCertifiedOutputProtection <0x6feded3e,0x0ff1,0x4901,<0xa2,0xf1,0x43,0xf7,0x01,0x2c,0x85,0x15>>

IAMCertifiedOutputProtection STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	KeyExchange PTR
	SessionSequenceStart PTR
	ProtectionCommand PTR
	ProtectionStatus PTR
ENDS

#DEFINE GUID_IID_IAMAsyncReaderTimestampScaling <0xcf7b26fc,0x9a00,0x485b,<0x81,0x47,0x3e,0x78,0x9d,0x5e,0x8f,0x67>>

IAMAsyncReaderTimestampScaling STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetTimestampMode PTR
	SetTimestampMode PTR
ENDS

#DEFINE GUID_IID_IAMPluginControl <0x0e26a181,0xf40c,0x4635,<0x87,0x86,0x97,0x62,0x84,0xb5,0x29,0x81>>

IAMPluginControl STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPreferredClsid PTR
	GetPreferredClsidByIndex PTR
	SetPreferredClsid PTR
	IsDisabled PTR
	GetDisabledByIndex PTR
	SetDisabled PTR
	IsLegacyDisabled PTR
ENDS

// DVD_DOMAIN
	DVD_DOMAIN_FirstPlay = 1
	DVD_DOMAIN_VideoManagerMenu = 2
	DVD_DOMAIN_VideoTitleSetMenu = 3
	DVD_DOMAIN_Title = 4
	DVD_DOMAIN_Stop = 5

// DVD_MENU_ID
	DVD_MENU_Title	= 2
	DVD_MENU_Root	= 3
	DVD_MENU_Subpicture	= 4
	DVD_MENU_Audio	= 5
	DVD_MENU_Angle	= 6
	DVD_MENU_Chapter	= 7

// DVD_DISC_SIDE
	DVD_SIDE_A	= 1
	DVD_SIDE_B	= 2

// DVD_PREFERRED_DISPLAY_MODE
	DISPLAY_CONTENT_DEFAULT	= 0
	DISPLAY_16x9	= 1
	DISPLAY_4x3_PANSCAN_PREFERRED	= 2
	DISPLAY_4x3_LETTERBOX_PREFERRED	= 3

DVD_ATR STRUCT
	ulCAT LONG
	pbATRI DB 768 DUP
ENDS

// DVD_FRAMERATE
	DVD_FPS_25	= 1
	DVD_FPS_30NonDrop	= 3

DVD_TIMECODE STRUCT
	Hours1 LONG
	Hours10 LONG
	Minutes1 LONG
	Minutes10 LONG
	Seconds1 LONG
	Seconds10 LONG
	Frames1 LONG
	Frames10 LONG
	FrameRateCode LONG
ENDS

// DVD_NavCmdType
	DVD_NavCmdType_Pre	= 1
	DVD_NavCmdType_Post	= 2
	DVD_NavCmdType_Cell	= 3
	DVD_NavCmdType_Button	= 4

// DVD_TIMECODE_FLAGS
	DVD_TC_FLAG_25fps	= 0x1
	DVD_TC_FLAG_30fps	= 0x2
	DVD_TC_FLAG_DropFrame	= 0x4
	DVD_TC_FLAG_Interpolated	= 0x8

DVD_HMSF_TIMECODE STRUCT
	bHours DB
	bMinutes DB
	bSeconds DB
	bFrames DB
ENDS

DVD_PLAYBACK_LOCATION2 STRUCT
	TitleNum LONG
	ChapterNum LONG
	TimeCode DVD_HMSF_TIMECODE
	TimeCodeFlags LONG
ENDS

DVD_PLAYBACK_LOCATION STRUCT
	TitleNum LONG
	ChapterNum LONG
	TimeCode LONG
ENDS

// MIDL___MIDL_itf_strmif_0000_0111_0001
	UOP_FLAG_Play_Title_Or_AtTime	= 0x1
	UOP_FLAG_Play_Chapter	= 0x2
	UOP_FLAG_Play_Title	= 0x4
	UOP_FLAG_Stop	= 0x8
	UOP_FLAG_ReturnFromSubMenu	= 0x10
	UOP_FLAG_Play_Chapter_Or_AtTime	= 0x20
	UOP_FLAG_PlayPrev_Or_Replay_Chapter	= 0x40
	UOP_FLAG_PlayNext_Chapter	= 0x80
	UOP_FLAG_Play_Forwards	= 0x100
	UOP_FLAG_Play_Backwards	= 0x200
	UOP_FLAG_ShowMenu_Title	= 0x400
	UOP_FLAG_ShowMenu_Root	= 0x800
	UOP_FLAG_ShowMenu_SubPic	= 0x1000
	UOP_FLAG_ShowMenu_Audio	= 0x2000
	UOP_FLAG_ShowMenu_Angle	= 0x4000
	UOP_FLAG_ShowMenu_Chapter	= 0x8000
	UOP_FLAG_Resume	= 0x10000
	UOP_FLAG_Select_Or_Activate_Button	= 0x20000
	UOP_FLAG_Still_Off	= 0x40000
	UOP_FLAG_Pause_On	= 0x80000
	UOP_FLAG_Select_Audio_Stream	= 0x100000
	UOP_FLAG_Select_SubPic_Stream	= 0x200000
	UOP_FLAG_Select_Angle	= 0x400000,
	UOP_FLAG_Select_Karaoke_Audio_Presentation_Mode	= 0x800000
	UOP_FLAG_Select_Video_Mode_Preference	= 0x1000000

// MIDL___MIDL_itf_strmif_0000_0111_0002
	DVD_CMD_FLAG_None	= 0
	DVD_CMD_FLAG_Flush	= 0x1
	DVD_CMD_FLAG_SendEvents	= 0x2
	DVD_CMD_FLAG_Block	= 0x4
	DVD_CMD_FLAG_StartWhenRendered	= 0x8
	DVD_CMD_FLAG_EndAfterRendered	= 0x10

// MIDL___MIDL_itf_strmif_0000_0111_0003
	DVD_ResetOnStop	= 1
	DVD_NotifyParentalLevelChange	= 2
	DVD_HMSF_TimeCodeEvents	= 3
	DVD_AudioDuringFFwdRew	= 4
	DVD_EnableNonblockingAPIs	= 5
	DVD_CacheSizeInMB	= 6
	DVD_EnablePortableBookmarks	= 7
	DVD_EnableExtendedCopyProtectErrors	= 8
	DVD_NotifyPositionChange	= 9
	DVD_IncreaseOutputControl	= 10
	DVD_EnableStreaming	= 11
	DVD_EnableESOutput	= 12
	DVD_EnableTitleLength	= 13
	DVD_DisableStillThrottle	= 14
	DVD_EnableLoggingEvents	= 15
	DVD_MaxReadBurstInKB	= 16
	DVD_ReadBurstPeriodInMS	= 17

// MIDL___MIDL_itf_strmif_0000_0111_0004
	DVD_Relative_Upper	= 1
	DVD_Relative_Lower	= 2
	DVD_Relative_Left	= 3
	DVD_Relative_Right	= 4

// DVD_PARENTAL_LEVEL
	DVD_PARENTAL_LEVEL_8	= 0x8000
	DVD_PARENTAL_LEVEL_7	= 0x4000
	DVD_PARENTAL_LEVEL_6	= 0x2000
	DVD_PARENTAL_LEVEL_5	= 0x1000
	DVD_PARENTAL_LEVEL_4	= 0x800
	DVD_PARENTAL_LEVEL_3	= 0x400
	DVD_PARENTAL_LEVEL_2	= 0x200
	DVD_PARENTAL_LEVEL_1	= 0x100

// DVD_AUDIO_LANG_EXT
	DVD_AUD_EXT_NotSpecified	= 0
	DVD_AUD_EXT_Captions	= 1
	DVD_AUD_EXT_VisuallyImpaired	= 2
	DVD_AUD_EXT_DirectorComments1	= 3
	DVD_AUD_EXT_DirectorComments2	= 4

// DVD_SUBPICTURE_LANG_EXT
	DVD_SP_EXT_NotSpecified	= 0
	DVD_SP_EXT_Caption_Normal	= 1
	DVD_SP_EXT_Caption_Big	= 2
	DVD_SP_EXT_Caption_Children	= 3
	DVD_SP_EXT_CC_Normal	= 5
	DVD_SP_EXT_CC_Big	= 6
	DVD_SP_EXT_CC_Children	= 7
	DVD_SP_EXT_Forced	= 9
	DVD_SP_EXT_DirectorComments_Normal	= 13
	DVD_SP_EXT_DirectorComments_Big	= 14
	DVD_SP_EXT_DirectorComments_Children	= 15

// DVD_AUDIO_APPMODE
	DVD_AudioMode_None	= 0
	DVD_AudioMode_Karaoke	= 1
	DVD_AudioMode_Surround	= 2
	DVD_AudioMode_Other	= 3

// DVD_AUDIO_FORMAT
	DVD_AudioFormat_AC3	= 0
	DVD_AudioFormat_MPEG1	= 1
	DVD_AudioFormat_MPEG1_DRC	= 2
	DVD_AudioFormat_MPEG2	= 3
	DVD_AudioFormat_MPEG2_DRC	= 4
	DVD_AudioFormat_LPCM	= 5
	DVD_AudioFormat_DTS	= 6
	DVD_AudioFormat_SDDS	= 7
	DVD_AudioFormat_Other	= 8

// DVD_KARAOKE_DOWNMIX
	DVD_Mix_0to0	= 0x1
	DVD_Mix_1to0	= 0x2
	DVD_Mix_2to0	= 0x4
	DVD_Mix_3to0	= 0x8
	DVD_Mix_4to0	= 0x10
	DVD_Mix_Lto0	= 0x20
	DVD_Mix_Rto0	= 0x40
	DVD_Mix_0to1	= 0x100
	DVD_Mix_1to1	= 0x200
	DVD_Mix_2to1	= 0x400
	DVD_Mix_3to1	= 0x800
	DVD_Mix_4to1	= 0x1000
	DVD_Mix_Lto1	= 0x2000
	DVD_Mix_Rto1	= 0x4000

DVD_AudioAttributes STRUCT
	AppMode ENUM
	AppModeData DB
	AudioFormat ENUM
	Language LCID
	LanguageExtension ENUM
	fHasMultichannelInfo BOOL
	dwFrequency DD
	bQuantization DB
	bNumberOfChannels DB
	dwReserved DD 2 DUP
ENDS

DVD_MUA_MixingInfo STRUCT
	fMixTo0 BOOL
	fMixTo1 BOOL
	fMix0InPhase BOOL
	fMix1InPhase BOOL
	dwSpeakerPosition DD
ENDS

DVD_MUA_Coeff STRUCT
	log2_alpha DOUBLE
	log2_beta DOUBLE
ENDS

DVD_MultichannelAudioAttributes STRUCT
	Info DB 20*8 DUP ; DVD_MUA_MixingInfo
	Coeff DB 16*8 DUP ; DVD_MUA_Coeff
ENDS

// DVD_KARAOKE_CONTENTS
	DVD_Karaoke_GuideVocal1	= 0x1
	DVD_Karaoke_GuideVocal2	= 0x2
	DVD_Karaoke_GuideMelody1	= 0x4
	DVD_Karaoke_GuideMelody2	= 0x8
	DVD_Karaoke_GuideMelodyA	= 0x10
	DVD_Karaoke_GuideMelodyB	= 0x20
	DVD_Karaoke_SoundEffectA	= 0x40
	DVD_Karaoke_SoundEffectB	= 0x80

// DVD_KARAOKE_ASSIGNMENT
	DVD_Assignment_reserved0	= 0
	DVD_Assignment_reserved1	= 1
	DVD_Assignment_LR	= 2
	DVD_Assignment_LRM	= 3
	DVD_Assignment_LR1	= 4
	DVD_Assignment_LRM1	= 5
	DVD_Assignment_LR12	= 6
	DVD_Assignment_LRM12	= 7

DVD_KaraokeAttributes STRUCT
	bVersion DB
	fMasterOfCeremoniesInGuideVocal1 BOOL
	fDuet BOOL
	ChannelAssignment ENUM
	wChannelContents DW 8 DUP
ENDS

// DVD_VIDEO_COMPRESSION
	DVD_VideoCompression_Other	= 0
	DVD_VideoCompression_MPEG1	= 1
	DVD_VideoCompression_MPEG2	= 2

DVD_VideoAttributes STRUCT
	fPanscanPermitted BOOL
	fLetterboxPermitted BOOL
	ulAspectX LONG
	ulAspectY LONG
	ulFrameRate LONG
	ulFrameHeight LONG
	Compression ENUM
	fLine21Field1InGOP BOOL
	fLine21Field2InGOP BOOL
	ulSourceResolutionX LONG
	ulSourceResolutionY LONG
	fIsSourceLetterboxed BOOL
	fIsFilmMode BOOL
ENDS

// DVD_SUBPICTURE_TYPE
	DVD_SPType_NotSpecified	= 0
	DVD_SPType_Language	= 1
	DVD_SPType_Other	= 2

// DVD_SUBPICTURE_CODING
	DVD_SPCoding_RunLength	= 0
	DVD_SPCoding_Extended	= 1
	DVD_SPCoding_Other	= 2

DVD_SubpictureAttributes STRUCT
	Type ENUM
	CodingMode ENUM
	Language LCID
	LanguageExtension ENUM
ENDS

// DVD_TITLE_APPMODE
	DVD_AppMode_Not_Specified = 0
	DVD_AppMode_Karaoke	= 1
	DVD_AppMode_Other	= 3

DVD_TitleMainAttributes STRUCT
	UNION
		AppMode ENUM
		TitleLength DVD_HMSF_TIMECODE
	ENDUNION
	VideoAttributes DVD_VideoAttributes
	ulNumberOfAudioStreams LONG
	AudioAttributes DVD_AudioAttributes 8 DUP
	MultichannelAudioAttributes DVD_MultichannelAudioAttributes 8 DUP
	ulNumberOfSubpictureStreams LONG
	SubpictureAttributes DVD_SubpictureAttributes 32 DUP
ENDS

DVD_MenuAttributes STRUCT
	fCompatibleRegion BOOL 8 DUP
	VideoAttributes DVD_VideoAttributes
	fAudioPresent BOOL
	AudioAttributes DVD_AudioAttributes
	fSubpicturePresent BOOL
	SubpictureAttributes DVD_SubpictureAttributes
ENDS

#DEFINE GUID_IID_IDvdControl <0xA70EFE61,0xE2A3,0x11d0,<0xA9,0xBE,0x00,0xAA,0x00,0x61,0xBE,0x93>>

IDvdControl STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	TitlePlay PTR
	ChapterPlay PTR
	TimePlay PTR
	StopForResume PTR
	GoUp PTR
	TimeSearch PTR
	ChapterSearch PTR
	PrevPGSearch PTR
	TopPGSearch PTR
	NextPGSearch PTR
	ForwardScan PTR
	BackwardScan PTR
	MenuCall PTR
	Resume PTR
	UpperButtonSelect PTR
	LowerButtonSelect PTR
	LeftButtonSelect PTR
	RightButtonSelect PTR
	ButtonActivate PTR
	ButtonSelectAndActivate PTR
	StillOff PTR
	PauseOn PTR
	PauseOff PTR
	MenuLanguageSelect PTR
	AudioStreamChange PTR
	SubpictureStreamChange PTR
	AngleChange PTR
	ParentalLevelSelect PTR
	ParentalCountrySelect PTR
	KaraokeAudioPresentationModeChange PTR
	VideoModePreferrence PTR
	SetRoot PTR
	MouseActivate PTR
	MouseSelect PTR
	ChapterPlayAutoStop PTR
ENDS

#DEFINE GUID_IID_IDvdInfo <0xA70EFE60,0xE2A3,0x11d0,<0xA9,0xBE,0x00,0xAA,0x00,0x61,0xBE,0x93>>

IDvdInfo STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCurrentDomain PTR
	GetCurrentLocation PTR
	GetTotalTitleTime PTR
	GetCurrentButton PTR
	GetCurrentAngle PTR
	GetCurrentAudio PTR
	GetCurrentSubpicture PTR
	GetCurrentUOPS PTR
	GetAllSPRMs PTR
	GetAllGPRMs PTR
	GetAudioLanguage PTR
	GetSubpictureLanguage PTR
	GetTitleAttributes PTR
	GetVMGAttributes PTR
	GetCurrentVideoAttributes PTR
	GetCurrentAudioAttributes PTR
	GetCurrentSubpictureAttributes PTR
	GetCurrentVolumeInfo PTR
	GetDVDTextInfo PTR
	GetPlayerParentalLevel PTR
	GetNumberOfChapters PTR
	GetTitleParentalLevels PTR
	GetRoot PTR
ENDS

#DEFINE GUID_IID_IDvdCmd <0x5a4a97e4,0x94ee,0x4a55,<0x97,0x51,0x74,0xb5,0x64,0x3a,0xa2,0x7d>>

IDvdCmd STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	WaitForStart PTR
	WaitForEnd PTR
ENDS

#DEFINE GUID_IID_IDvdState <0x86303d6d,0x1c4a,0x4087,<0xab,0x42,0xf7,0x11,0x16,0x70,0x48,0xef>>

IDvdState STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetDiscID PTR
	GetParentalLevel PTR
ENDS

#DEFINE GUID_IID_IDvdControl2 <0x33BC7430,0xEEC0,0x11D2,<0x82,0x01,0x00,0xA0,0xC9,0xD7,0x48,0x42>>

IDvdControl2 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	PlayTitle PTR
	PlayChapterInTitle PTR
	PlayAtTimeInTitle PTR
	Stop PTR
	ReturnFromSubmenu PTR
	PlayAtTime PTR
	PlayChapter PTR
	PlayPrevChapter PTR
	ReplayChapter PTR
	PlayNextChapter PTR
	PlayForwards PTR
	PlayBackwards PTR
	ShowMenu PTR
	Resume PTR
	SelectRelativeButton PTR
	ActivateButton PTR
	SelectButton PTR
	SelectAndActivateButton PTR
	StillOff PTR
	Pause PTR
	SelectAudioStream PTR
	SelectSubpictureStream PTR
	SetSubpictureState PTR
	SelectAngle PTR
	SelectParentalLevel PTR
	SelectParentalCountry PTR
	SelectKaraokeAudioPresentationMode PTR
	SelectVideoModePreference PTR
	SetDVDDirectory PTR
	ActivateAtPosition PTR
	SelectAtPosition PTR
	PlayChaptersAutoStop PTR
	AcceptParentalLevelChange PTR
	SetOption PTR
	SetState PTR
	PlayPeriodInTitleAutoStop PTR
	SetGPRM PTR
	SelectDefaultMenuLanguage PTR
	SelectDefaultAudioLanguage PTR
	SelectDefaultSubpictureLanguage PTR
ENDS

// DVD_TextStringType
	DVD_Struct_Volume	= 0x1
	DVD_Struct_Title	= 0x2
	DVD_Struct_ParentalID	= 0x3
	DVD_Struct_PartOfTitle	= 0x4
	DVD_Struct_Cell	= 0x5
	DVD_Stream_Audio	= 0x10
	DVD_Stream_Subpicture	= 0x11
	DVD_Stream_Angle	= 0x12
	DVD_Channel_Audio	= 0x20
	DVD_General_Name	= 0x30
	DVD_General_Comments	= 0x31
	DVD_Title_Series	= 0x38
	DVD_Title_Movie	= 0x39
	DVD_Title_Video	= 0x3a
	DVD_Title_Album	= 0x3b
	DVD_Title_Song	= 0x3c
	DVD_Title_Other	= 0x3f
	DVD_Title_Sub_Series	= 0x40
	DVD_Title_Sub_Movie	= 0x41
	DVD_Title_Sub_Video	= 0x42
	DVD_Title_Sub_Album	= 0x43
	DVD_Title_Sub_Song	= 0x44
	DVD_Title_Sub_Other	= 0x47
	DVD_Title_Orig_Series	= 0x48
	DVD_Title_Orig_Movie	= 0x49
	DVD_Title_Orig_Video	= 0x4a
	DVD_Title_Orig_Album	= 0x4b
	DVD_Title_Orig_Song	= 0x4c
	DVD_Title_Orig_Other	= 0x4f
	DVD_Other_Scene	= 0x50
	DVD_Other_Cut	= 0x51
	DVD_Other_Take	= 0x52

// DVD_TextCharSet
	DVD_CharSet_Unicode	= 0
	DVD_CharSet_ISO646	= 1
	DVD_CharSet_JIS_Roman_Kanji	= 2
	DVD_CharSet_ISO8859_1	= 3
	DVD_CharSet_ShiftJIS_Kanji_Roman_Katakana	= 4

#define DVD_TITLE_MENU				0x000
#define DVD_STREAM_DATA_CURRENT     0x800
#define DVD_STREAM_DATA_VMGM        0x400
#define DVD_STREAM_DATA_VTSM        0x401
#define DVD_DEFAULT_AUDIO_STREAM	0x0f

DVD_DECODER_CAPS STRUCT
	dwSize DD
	dwAudioCaps DD
	dFwdMaxRateVideo DOUBLE
	dFwdMaxRateAudio DOUBLE
	dFwdMaxRateSP DOUBLE
	dBwdMaxRateVideo DOUBLE
	dBwdMaxRateAudio DOUBLE
	dBwdMaxRateSP DOUBLE
	dwRes1 DD
	dwRes2 DD
	dwRes3 DD
	dwRes4 DD
ENDS

#define DVD_AUDIO_CAPS_AC3		0x00000001
#define DVD_AUDIO_CAPS_MPEG2	0x00000002
#define DVD_AUDIO_CAPS_LPCM		0x00000004
#define DVD_AUDIO_CAPS_DTS		0x00000008
#define DVD_AUDIO_CAPS_SDDS		0x00000010

#DEFINE GUID_IID_IDvdInfo2 <0x34151510,0xEEC0,0x11D2,<0x82,0x01,0x00,0xA0,0xC9,0xD7,0x48,0x42>>

IDvdInfo2 STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCurrentDomain PTR
	GetCurrentLocation PTR
	GetTotalTitleTime PTR
	GetCurrentButton PTR
	GetCurrentAngle PTR
	GetCurrentAudio PTR
	GetCurrentSubpicture PTR
	GetCurrentUOPS PTR
	GetAllSPRMs PTR
	GetAllGPRMs PTR
	GetAudioLanguage PTR
	GetSubpictureLanguage PTR
	GetTitleAttributes PTR
	GetVMGAttributes PTR
	GetCurrentVideoAttributes PTR
	GetAudioAttributes PTR
	GetKaraokeAttributes PTR
	GetSubpictureAttributes PTR
	GetDVDVolumeInfo PTR
	GetDVDTextNumberOfLanguages PTR
	GetDVDTextLanguageInfo PTR
	GetDVDTextStringAsNative PTR
	GetDVDTextStringAsUnicode PTR
	GetPlayerParentalLevel PTR
	GetNumberOfChapters PTR
	GetTitleParentalLevels PTR
	GetDVDDirectory PTR
	IsAudioStreamEnabled PTR
	GetDiscID PTR
	GetState PTR
	GetMenuLanguages PTR
	GetButtonAtPosition PTR
	GetCmdFromEvent PTR
	GetDefaultMenuLanguage PTR
	GetDefaultAudioLanguage PTR
	GetDefaultSubpictureLanguage PTR
	GetDecoderCaps PTR
	GetButtonRect PTR
	IsSubpictureStreamEnabled PTR
ENDS

// AM_DVD_GRAPH_FLAGS
	AM_DVD_HWDEC_PREFER	= 0x1
	AM_DVD_HWDEC_ONLY	= 0x2
	AM_DVD_SWDEC_PREFER	= 0x4
	AM_DVD_SWDEC_ONLY	= 0x8
	AM_DVD_NOVPE	= 0x100
	AM_DVD_DO_NOT_CLEAR	= 0x200
	AM_DVD_VMR9_ONLY	= 0x800
	AM_DVD_EVR_ONLY	= 0x1000
	AM_DVD_EVR_QOS	= 0x2000
	AM_DVD_ADAPT_GRAPH	= 0x4000
	AM_DVD_MASK	= 0xffff

// AM_DVD_STREAM_FLAGS
	AM_DVD_STREAM_VIDEO	= 0x1
	AM_DVD_STREAM_AUDIO	= 0x2
	AM_DVD_STREAM_SUBPIC	= 0x4

AM_DVD_RENDERSTATUS STRUCT
	hrVPEStatus HANDLE
	bDvdVolInvalid BOOL
	bDvdVolUnknown BOOL
	bNoLine21In BOOL
	bNoLine21Out BOOL
	iNumStreams LONG
	iNumStreamsFailed LONG
	dwFailedStreamsFlag DD
ENDS

#DEFINE GUID_IID_IDvdGraphBuilder <0xFCC152B6,0xF372,0x11d0,<0x8E,0x00,0x00,0xC0,0x4F,0xD7,0xC0,0x8B>>

IDvdGraphBuilder STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetFiltergraph PTR
	GetDvdInterface PTR
	RenderDvdVideoVolume PTR
ENDS

#DEFINE GUID_IID_IDDrawExclModeVideo <0x153ACC21,0xD83B,0x11d1,<0x82,0xBF,0x00,0xA0,0xC9,0x69,0x6C,0x8F>>

IDDrawExclModeVideo STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetDDrawObject PTR
	GetDDrawObject PTR
	SetDDrawSurface PTR
	GetDDrawSurface PTR
	SetDrawParameters PTR
	GetNativeVideoProps PTR
	SetCallbackInterface PTR
ENDS

// AM_OVERLAY_NOTIFY_FLAGS
	AM_OVERLAY_NOTIFY_VISIBLE_CHANGE	= 0x1
	AM_OVERLAY_NOTIFY_SOURCE_CHANGE	= 0x2
	AM_OVERLAY_NOTIFY_DEST_CHANGE	= 0x4

#DEFINE GUID_IID_IDDrawExclModeVideoCallback <0x913c24a0,0x20ab,0x11d2,<0x90,0x38,0x00,0xa0,0xc9,0x69,0x72,0x98>>

IDDrawExclModeVideoCallback STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnUpdateOverlay PTR
	OnUpdateColorKey PTR
	OnUpdateSize PTR
ENDS

#DEFINE GUID_IID_IPinConnection <0x4a9a62d3,0x27d4,0x403d,<0x91,0xe9,0x89,0xf5,0x40,0xe5,0x55,0x34>>

IPinConnection STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	DynamicQueryAccept PTR
	NotifyEndOfStream PTR
	IsEndPin PTR
	DynamicDisconnect PTR
ENDS

#DEFINE GUID_IID_IPinFlowControl <0xc56e9858,0xdbf3,0x4f6b,<0x81,0x19,0x38,0x4a,0xf2,0x06,0x0d,0xeb>>

IPinFlowControl STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Block PTR
ENDS

// AM_PIN_FLOW_CONTROL_BLOCK_FLAGS
	AM_PIN_FLOW_CONTROL_BLOCK	= 0x1

// AM_GRAPH_CONFIG_RECONNECT_FLAGS
	AM_GRAPH_CONFIG_RECONNECT_DIRECTCONNECT	= 0x1
	AM_GRAPH_CONFIG_RECONNECT_CACHE_REMOVED_FILTERS	= 0x2
	AM_GRAPH_CONFIG_RECONNECT_USE_ONLY_CACHED_FILTERS	= 0x4

// REM_FILTER_FLAGS
	REMFILTERF_LEAVECONNECTED	= 0x1

// AM_FILTER_FLAGS
	AM_FILTER_FLAGS_REMOVABLE	= 0x1

#DEFINE GUID_IID_IGraphConfig <0x03A1EB8E,0x32BF,0x4245,<0x85,0x02,0x11,0x4D,0x08,0xA9,0xCB,0x88>>

IGraphConfig STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Reconnect PTR
	Reconfigure PTR
	AddFilterToCache PTR
	EnumCacheFilter PTR
	RemoveFilterFromCache PTR
	GetStartTime PTR
	PushThroughData PTR
	SetFilterFlags PTR
	GetFilterFlags PTR
	RemoveFilterEx PTR
ENDS

#DEFINE GUID_IID_IGraphConfigCallback <0xade0fd60,0xd19d,0x11d2,<0xab,0xf6,0x00,0xa0,0xc9,0x05,0xf3,0x75>>

IGraphConfigCallback STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	Reconfigure PTR
ENDS

#DEFINE GUID_IID_IFilterChain <0xDCFBDCF6,0x0DC2,0x45f5,<0x9A,0xB2,0x7C,0x33,0x0E,0xA0,0x9C,0x29>>

IFilterChain STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	StartChain PTR
	PauseChain PTR
	StopChain PTR
	RemoveChain PTR
ENDS

DDCOLORKEY STRUCT
	dw1 DD
	dw2 DD
ENDS

// VMRPresentationFlags
	VMRSample_SyncPoint	= 0x1
	VMRSample_Preroll	= 0x2
	VMRSample_Discontinuity	= 0x4
	VMRSample_TimeValid	= 0x8
	VMRSample_SrcDstRectsValid	= 0x10

VMRPRESENTATIONINFO STRUCT
	dwFlags DD
	lpSurf PTR
	rtStart LONGLONG
	rtEnd LONGLONG
	szAspectRatio SIZE
	rcSrc RECT
	rcDst RECT
	dwTypeSpecificFlags DD
	dwInterlaceFlags DD
ENDS

#DEFINE GUID_IID_IVMRImagePresenter <0xCE704FE7,0xE71E,0x41fb,<0xBA,0xA2,0xC4,0x40,0x3E,0x11,0x82,0xF5>>

IVMRImagePresenter STRUCT
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

// VMRSurfaceAllocationFlags
	AMAP_PIXELFORMAT_VALID	= 0x1
	AMAP_3D_TARGET	= 0x2
	AMAP_ALLOW_SYSMEM	= 0x4
	AMAP_FORCE_SYSMEM	= 0x8
	AMAP_DIRECTED_FLIP	= 0x10
	AMAP_DXVA_TARGET	= 0x20

VMRALLOCATIONINFO STRUCT
	dwFlags DD
	lpHdr PTR
	lpPixFmt PTR
	szAspectRatio SIZE
	dwMinBuffers DD
	dwMaxBuffers DD
	dwInterlaceFlags DD
	szNativeSize SIZE
ENDS

#DEFINE GUID_IID_IVMRSurfaceAllocator <0x31ce832e,0x4484,0x458b,<0x8c,0xca,0xf4,0xd7,0xe3,0xdb,0x0b,0x52>>

IVMRSurfaceAllocator STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	AllocateSurface PTR
	FreeSurface PTR
	PrepareSurface PTR
	AdviseNotify PTR
ENDS

#DEFINE GUID_IID_IVMRSurfaceAllocatorNotify <0xaada05a8,0x5a4e,0x4729,<0xaf,0x0b,0xce,0xa2,0x7a,0xed,0x51,0xe2>>

IVMRSurfaceAllocatorNotify STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	AdviseSurfaceAllocator PTR
	SetDDrawDevice PTR
	ChangeDDrawDevice PTR
	RestoreDDrawSurfaces PTR
	NotifyEvent PTR
	SetBorderColor PTR
ENDS

// VMR_ASPECT_RATIO_MODE
	VMR_ARMODE_NONE	= 0
	VMR_ARMODE_LETTER_BOX	= 1

#DEFINE GUID_IID_IVMRWindowlessControl <0x0eb1088c,0x4dcd,0x46f0,<0x87,0x8f,0x39,0xda,0xe8,0x6a,0x51,0xb7>>

IVMRWindowlessControl STRUCT
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
	SetColorKey PTR
	GetColorKey PTR
ENDS

// VMRMixerPrefs
	MixerPref_NoDecimation	= 0x1
	MixerPref_DecimateOutput	= 0x2
	MixerPref_ARAdjustXorY	= 0x4
	MixerPref_DecimationReserved	= 0x8
	MixerPref_DecimateMask	= 0xf
	MixerPref_BiLinearFiltering	= 0x10
	MixerPref_PointFiltering	= 0x20
	MixerPref_FilteringMask	= 0xf0
	MixerPref_RenderTargetRGB	= 0x100
	MixerPref_RenderTargetYUV	= 0x1000
	MixerPref_RenderTargetYUV420	= 0x200
	MixerPref_RenderTargetYUV422	= 0x400
	MixerPref_RenderTargetYUV444	= 0x800
	MixerPref_RenderTargetReserved	= 0xe000
	MixerPref_RenderTargetMask	= 0xff00
	MixerPref_DynamicSwitchToBOB	= 0x10000
	MixerPref_DynamicDecimateBy2	= 0x20000
	MixerPref_DynamicReserved	= 0xc0000
	MixerPref_DynamicMask	= 0xf0000

NORMALIZEDRECT STRUCT
	left FLOAT
	top FLOAT
	right FLOAT
	bottom FLOAT
ENDS

#DEFINE GUID_IID_IVMRMixerControl <0x1c1a17b0,0xbed0,0x415d,<0x97,0x4b,0xdc,0x66,0x96,0x13,0x15,0x99>>

IVMRMixerControl STRUCT
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
ENDS

VMRGUID STRUCT
	pGUID PTR
    guid GUID
ENDS

VMRMONITORINFO STRUCT
	guid VMRGUID
	rcMonitor RECT
	hMon HANDLE
	dwFlags DD
	szDevice WCHAR 32 DUP
	szDescription WCHAR 256 DUP
	liDriverVersion LARGE_INTEGER
	dwVendorId DD
	dwDeviceId DD
	dwSubSysId DD
	dwRevision DD
ENDS

#DEFINE GUID_IID_IVMRMonitorConfig <0x9cf0b1b6,0xfbaa,0x4b7f,<0x88,0xcf,0xcf,0x1f,0x13,0x0a,0x0d,0xce>>

IVMRMonitorConfig STRUCT
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

// VMRRenderPrefs
	RenderPrefs_RestrictToInitialMonitor	= 0
	RenderPrefs_ForceOffscreen	= 0x1
	RenderPrefs_ForceOverlays	= 0x2
	RenderPrefs_AllowOverlays	= 0
	RenderPrefs_AllowOffscreen	= 0
	RenderPrefs_DoNotRenderColorKeyAndBorder	= 0x8
	RenderPrefs_Reserved	= 0x10
	RenderPrefs_PreferAGPMemWhenMixing	= 0x20
	RenderPrefs_Mask	= 0x3f

// VMRMode
	VMRMode_Windowed	= 0x1
	VMRMode_Windowless	= 0x2
	VMRMode_Renderless	= 0x4
	VMRMode_Mask	= 0x7


// MIDL_itf_strmif_0000_0131_0001
	MAX_NUMBER_OF_STREAMS	= 16

#DEFINE GUID_IID_IVMRFilterConfig <0x9e5530c5,0x7034,0x48b4,<0xbb,0x46,0x0b,0x8a,0x6e,0xfc,0x8e,0x36>>

IVMRFilterConfig STRUCT
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

#DEFINE GUID_IID_IVMRAspectRatioControl <0xede80b5c,0xbad6,0x4623,<0xb5,0x37,0x65,0x58,0x6c,0x9f,0x8d,0xfd>>

IVMRAspectRatioControl STRUCT
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

// VMRDeinterlacePrefs
	DeinterlacePref_NextBest	= 0x1
	DeinterlacePref_BOB	= 0x2
	DeinterlacePref_Weave	= 0x4
	DeinterlacePref_Mask	= 0x7

// VMRDeinterlaceTech
	DeinterlaceTech_Unknown	= 0
	DeinterlaceTech_BOBLineReplicate	= 0x1
	DeinterlaceTech_BOBVerticalStretch	= 0x2
	DeinterlaceTech_MedianFiltering	= 0x4
	DeinterlaceTech_EdgeFiltering	= 0x10
	DeinterlaceTech_FieldAdaptive	= 0x20
	DeinterlaceTech_PixelAdaptive	= 0x40
	DeinterlaceTech_MotionVectorSteered	= 0x80

VMRFrequency STRUCT
	dwNumerator DD
	dwDenominator DD
ENDS

VMRVideoDesc STRUCT
	dwSize DD
	dwSampleWidth DD
	dwSampleHeight DD
	SingleFieldPerSample BOOL
	dwFourCC DD
	InputSampleFreq VMRFrequency
	OutputFrameFreq VMRFrequency
ENDS

VMRDeinterlaceCaps STRUCT
	dwSize DD
	dwNumPreviousOutputFrames DD
	dwNumForwardRefSamples DD
	dwNumBackwardRefSamples DD
	DeinterlaceTechnology ENUM
ENDS

#DEFINE GUID_IID_IVMRDeinterlaceControl <0xbb057577,0x0db8,0x4e6a,<0x87,0xa7,0x1a,0x8c,0x9a,0x50,0x5a,0x0f>>

IVMRDeinterlaceControl STRUCT
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

VMRALPHABITMAP STRUCT
	dwFlags DD
	hdc HANDLE
	pDDS PTR
	rSrc RECT
	rDest NORMALIZEDRECT
	fAlpha FLOAT
	clrSrcKey COLORREF
ENDS

#define VMRBITMAP_DISABLE            0x00000001
#define VMRBITMAP_HDC                0x00000002
#define VMRBITMAP_ENTIREDDS          0x00000004
#define VMRBITMAP_SRCCOLORKEY        0x00000008
#define VMRBITMAP_SRCRECT            0x00000010

#DEFINE GUID_IID_IVMRMixerBitmap <0x1E673275,0x0257,0x40aa,<0xAF,0x20,0x7C,0x60,0x8D,0x4A,0x04,0x28>>

IVMRMixerBitmap STRUCT
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

VMRVIDEOSTREAMINFO STRUCT
	pddsVideoSurface PTR
	dwWidth DD
	dwHeight DD
	dwStrmID DD
	fAlpha FLOAT
	ddClrKey DDCOLORKEY
	rNormal NORMALIZEDRECT
ENDS

#DEFINE GUID_IID_IVMRImageCompositor <0x7a4fb5af,0x479f,0x4074,<0xbb,0x40,0xce,0x67,0x22,0xe4,0x3c,0x82>>

IVMRImageCompositor STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	InitCompositionTarget PTR
	TermCompositionTarget PTR
	SetStreamMediaType PTR
	CompositeImage PTR
ENDS

#DEFINE GUID_IID_IVMRVideoStreamControl <0x058d1f11,0x2a54,0x4bef,<0xbd,0x54,0xdf,0x70,0x66,0x26,0xb7,0x27>>

IVMRVideoStreamControl STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetColorKey PTR
	GetColorKey PTR
	SetStreamActiveState PTR
	GetStreamActiveState PTR
ENDS

#DEFINE GUID_IID_IVMRSurface <0xa9849bbe,0x9ec8,0x4263,<0xb7,0x64,0x62,0x73,0x0f,0x0d,0x15,0xd0>>

IVMRSurface STRUCT
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

#DEFINE GUID_IID_IVMRImagePresenterConfig <0x9f3a1c85,0x8555,0x49ba,<0x93,0x5f,0xbe,0x5b,0x5b,0x29,0xd1,0x78>>

IVMRImagePresenterConfig STRUCT
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

#DEFINE GUID_IID_IVMRImagePresenterExclModeConfig <0xe6f7ce40,0x4673,0x44f1,<0x8f,0x77,0x54,0x99,0xd6,0x8c,0xb4,0xea>>

IVMRImagePresenterExclModeConfig STRUCT
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
	SetXlcModeDDObjAndPrimarySurface PTR
	GetXlcModeDDObjAndPrimarySurface PTR
ENDS

#DEFINE GUID_IID_IVPManager <0xaac18c18,0xe186,0x46d2,<0x82,0x5d,0xa1,0xf8,0xdc,0x8e,0x39,0x5a>>

IVPManager STRUCT
	UNION
		struct
			QueryInterface PTR
			AddRef PTR
			Release PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetVideoPortIndex PTR
	GetVideoPortIndex PTR
ENDS

#endif



