
#ifndef CONTROL_H
#define CONTROL_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF

#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

/*
typedef double REFTIME;

typedef LONG_PTR OAEVENT;

typedef LONG_PTR OAHWND;

typedef long OAFilterState;
*/

#DEFINE GUID_LIBID_QuartzTypeLib <0x56a868b0,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

#DEFINE GUID_IID_IAMCollection <0x56a868b9,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IAMCollection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Count PTR
	Item PTR
ENDS

#DEFINE GUID_IID_IMediaControl <0x56a868b1,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IMediaControl STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Run PTR
	Pause PTR
	Stop PTR
	GetState PTR
	RenderFile PTR
	AddSourceFilter PTR
	get_FilterCollection PTR
	get_RegFilterCollection PTR
	StopWhenReady PTR
ENDS

#DEFINE GUID_IID_IMediaEvent <0x56a868b6,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IMediaEvent STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	GetEventHandle PTR
	GetEvent PTR
	WaitForCompletion PTR
	CancelDefaultHandling PTR
	RestoreDefaultHandling PTR
	FreeEventParams PTR
ENDS

#DEFINE GUID_IID_IMediaEventEx <0x56a868c0,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IMediaEventEx STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	GetEventHandle PTR
	GetEvent PTR
	WaitForCompletion PTR
	CancelDefaultHandling PTR
	RestoreDefaultHandling PTR
	FreeEventParams PTR
	SetNotifyWindow PTR
	SetNotifyFlags PTR
	GetNotifyFlags PTR
ENDS

#DEFINE GUID_IID_IMediaPosition <0x56a868b2,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IMediaPosition STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Duration PTR
	put_CurrentPosition PTR
	get_CurrentPosition PTR
	get_StopTime PTR
	put_StopTime PTR
	get_PrerollTime PTR
	put_PrerollTime PTR
	put_Rate PTR
	get_Rate PTR
	CanSeekForward PTR
	CanSeekBackward PTR
ENDS

#DEFINE GUID_IID_IBasicAudio <0x56a868b3,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IBasicAudio STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	put_Volume PTR
	get_Volume PTR
	put_Balance PTR
	get_Balance PTR
ENDS

#DEFINE GUID_IID_IVideoWindow <0x56a868b4,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IVideoWindow STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	put_Caption PTR
	get_Caption PTR
	put_WindowStyle PTR
	get_WindowStyle PTR
	put_WindowStyleEx PTR
	get_WindowStyleEx PTR
	put_AutoShow PTR
	get_AutoShow PTR
	put_WindowState PTR
	get_WindowState PTR
	put_BackgroundPalette PTR
	get_BackgroundPalette PTR
	put_Visible PTR
	get_Visible PTR
	put_Left PTR
	get_Left PTR
	put_Width PTR
	get_Width PTR
	put_Top PTR
	get_Top PTR
	put_Height PTR
	get_Height PTR
	put_Owner PTR
	get_Owner PTR
	put_MessageDrain PTR
	get_MessageDrain PTR
	get_BorderColor PTR
	put_BorderColor PTR
	get_FullScreenMode PTR
	put_FullScreenMode PTR
	SetWindowForeground PTR
	NotifyOwnerMessage PTR
	SetWindowPosition PTR
	GetWindowPosition PTR
	GetMinIdealImageSize PTR
	GetMaxIdealImageSize PTR
	GetRestorePosition PTR
	HideCursor PTR
	IsCursorHidden PTR
ENDS


#DEFINE GUID_IID_IBasicVideo <0x56a868b5,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IBasicVideo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_AvgTimePerFrame PTR
	get_BitRate PTR
	get_BitErrorRate PTR
	get_VideoWidth PTR
	get_VideoHeight PTR
	put_SourceLeft PTR
	get_SourceLeft PTR
	put_SourceWidth PTR
	get_SourceWidth PTR
	put_SourceTop PTR
	get_SourceTop PTR
	put_SourceHeight PTR
	get_SourceHeight PTR
	put_DestinationLeft PTR
	get_DestinationLeft PTR
	put_DestinationWidth PTR
	get_DestinationWidth PTR
	put_DestinationTop PTR
	get_DestinationTop PTR
	put_DestinationHeight PTR
	get_DestinationHeight PTR
	SetSourcePosition PTR
	GetSourcePosition PTR
	SetDefaultSourcePosition PTR
	SetDestinationPosition PTR
	GetDestinationPosition PTR
	SetDefaultDestinationPosition PTR
	GetVideoSize PTR
	GetVideoPaletteEntries PTR
	GetCurrentImage PTR
	IsUsingDefaultSource PTR
	IsUsingDefaultDestination PTR
ENDS

#DEFINE GUID_IID_IBasicVideo2 <0x329bb360,0xf6ea,0x11d1,<0x90,0x38,0x00,0xa0,0xc9,0x69,0x72,0x98>>

IBasicVideo2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_AvgTimePerFrame PTR
	get_BitRate PTR
	get_BitErrorRate PTR
	get_VideoWidth PTR
	get_VideoHeight PTR
	put_SourceLeft PTR
	get_SourceLeft PTR
	put_SourceWidth PTR
	get_SourceWidth PTR
	put_SourceTop PTR
	get_SourceTop PTR
	put_SourceHeight PTR
	get_SourceHeight PTR
	put_DestinationLeft PTR
	get_DestinationLeft PTR
	put_DestinationWidth PTR
	get_DestinationWidth PTR
	put_DestinationTop PTR
	get_DestinationTop PTR
	put_DestinationHeight PTR
	get_DestinationHeight PTR
	SetSourcePosition PTR
	GetSourcePosition PTR
	SetDefaultSourcePosition PTR
	SetDestinationPosition PTR
	GetDestinationPosition PTR
	SetDefaultDestinationPosition PTR
	GetVideoSize PTR
	GetVideoPaletteEntries PTR
	GetCurrentImage PTR
	IsUsingDefaultSource PTR
	IsUsingDefaultDestination PTR
	GetPreferredAspectRatio PTR
ENDS

#DEFINE GUID_IID_IDeferredCommand <0x56a868b8,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IDeferredCommand STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Cancel PTR
	Confidence PTR
	Postpone PTR
	GetHResult PTR
ENDS

#DEFINE GUID_IID_IQueueCommand <0x56a868b7,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IQueueCommand STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	InvokeAtStreamTime PTR
	InvokeAtPresentationTime PTR
ENDS

#DEFINE GUID_CLSID_FilgraphManager <0xe436ebb3,0x524f,0x11ce,<0x9f,0x53,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

#DEFINE GUID_IID_IFilterInfo <0x56a868ba,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IFilterInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	FindPin PTR
	get_Name PTR
	get_VendorInfo PTR
	get_Filter PTR
	get_Pins PTR
	get_IsFileSource PTR
	get_Filename PTR
	put_Filename PTR
ENDS

#DEFINE GUID_IID_IRegFilterInfo <0x56a868bb,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IRegFilterInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	Filter PTR
ENDS

#DEFINE GUID_IID_IMediaTypeInfo <0x56a868bc,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IMediaTypeInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Type PTR
	get_Subtype PTR
ENDS

#DEFINE GUID_IID_IPinInfo <0x56a868bd,0x0ad4,0x11ce,<0xb0,0x3a,0x00,0x20,0xaf,0x0b,0xa7,0x70>>

IPinInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Pin PTR
	get_ConnectedTo PTR
	get_ConnectionMediaType PTR
	get_FilterInfo PTR
	get_Name PTR
	get_Direction PTR
	get_PinID PTR
	get_MediaTypes PTR
	Connect PTR
	ConnectDirect PTR
	ConnectWithType PTR
	Disconnect PTR
	Render PTR
ENDS

#DEFINE GUID_IID_IAMStats <0xbc9bcf80,0xdcd2,0x11d2,<0xab,0xf6,0x00,0xa0,0xc9,0x05,0xf3,0x75>>

IAMStats STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Reset PTR
	GetValueByIndex PTR
	GetValueByName PTR
	GetIndex PTR
	AddValue PTR
ENDS

#endif



