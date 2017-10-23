#IFNDEF VSHELP80_H
#DEFINE VSHELP80_H

#define GUID_IID_IVSHelp <0x4A791148,0x19E4,0x11D3,<0xB8,0x6B,0x00,0xC0,0x4F,0x79,0xF8,0x02>>
#define GUID_IID_IVSHelp80 <0x78413D2D,0x0492,0x4A9B,<0xAB,0x25,0x73,0x06,0x33,0x67,0x99,0x77>>
#define GUID_IID_IVsHelpFavorites <0xD1333514,0x2B6B,0x4479,<0x81,0x35,0xA3,0x9E,0x28,0x6E,0x14,0x6D>>
#define GUID_IID_IVsHelpOwner <0xB9B0983A,0x364C,0x4866,<0x87,0x3F,0xD5,0xED,0x19,0x01,0x38,0xFB>>
#define GUID_IID_IVsHelpTopicShowEvents <0xD1AAC64A,0x6A25,0x4274,<0xB2,0xC6,0xBC,0x3B,0x84,0x0B,0x6E,0x54>>
#define GUID_IID_IVsHelpEvents <0x507E4490,0x5A8C,0x11d3,<0xB8,0x97,0x00,0xC0,0x4F,0x79,0xF8,0x02>>

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

IVsHelpOwner STRUCT
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
	BringHelpToTop PTR
	get_AutomationObject PTR
ENDS

IVsHelpTopicShowEvents STRUCT
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
	OnBeforeTopicShow PTR
	OnTopicShowComplete PTR
ENDS

IVsHelpEvents STRUCT
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
	OnFilterChanged PTR
	OnCollectionChanged PTR
ENDS

HELP STRUCT
	Contents PTR
	Index PTR
	Search PTR
	IndexResults PTR
	SearchResults PTR
	DisplayTopicFromId PTR
	DisplayTopicFromURL PTR
	DisplayTopicFromURLEx PTR
	DisplayTopicFromKeyword PTR
	DisplayTopicFromF1Keyword PTR
	DisplayTopicFrom_OLD_Help PTR
	SyncContents PTR
	CanSyncContents PTR
	GetNextTopic PTR
	GetPrevTopic PTR
	FilterUI PTR
	CanShowFilterUI PTR
	Close PTR
	SyncIndex PTR
	SetCollection PTR
	GetCollection PTR
	GetFilter PTR
	SetFilter PTR
	FilterQuery PTR
	GetHelpOwner PTR
	SetHelpOwner PTR
	HxSession PTR
	Help PTR
	GetObject PTR
ENDS

HELP2 STRUCT
	SearchEx PTR
	HowDoI PTR
	Favorites PTR
	AskAQuestion PTR
	DisplayTopicFromURLEx2 PTR
	InitializeSettingsToken PTR
ENDS

IVSHelp STRUCT
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
	Contents PTR
	Index PTR
	Search PTR
	IndexResults PTR
	SearchResults PTR
	DisplayTopicFromId PTR
	DisplayTopicFromURL PTR
	DisplayTopicFromURLEx PTR
	DisplayTopicFromKeyword PTR
	DisplayTopicFromF1Keyword PTR
	DisplayTopicFrom_OLD_Help PTR
	SyncContents PTR
	CanSyncContents PTR
	GetNextTopic PTR
	GetPrevTopic PTR
	FilterUI PTR
	CanShowFilterUI PTR
	Close PTR
	SyncIndex PTR
	SetCollection PTR
	GetCollection PTR
	GetFilter PTR
	SetFilter PTR
	FilterQuery PTR
	GetHelpOwner PTR
	SetHelpOwner PTR
	HxSession PTR
	Help PTR
	GetObject PTR
ENDS

IVSHelp80 STRUCT
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
	Help HELP
	Help2 HELP2
ENDS

IVsHelpFavorites STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ShowFavorites PTR
	AddFavoriteTopic PTR
ENDS

#define vsAskQuestionFlagsAskNew 0x00000001 
#define vsAskQuestionFlagsCheckStatus 0x00000002 
#define vsAskQuestionFlagsSendFeedback 0x00000004 

#define vsSearchFlagsNone 0x00000000
#define vsSearchFlagsExecuteSearch 0x00000001
#define vsSearchFlagsAddToExistingQueryString 0x00000002
#define vsSearchFlagsFilterTransformSpecified 0x00000004

#define vsHelpDisplayUrlFlagsNone 0
#define vsHelpDisplayUrlFlagsHighlightTerm 1
#define vsHelpDisplayUrlFlagsOpenNewWindow 2
#define vsHelpDisplayUrlFlagsGuidLocal 16
#define vsHelpDisplayUrlFlagsGuidOnline 32
#define vsHelpDisplayUrlFlagsGuidLocale 64
#define vsHelpDisplayUrlFlagsGuidFailover 128
#define vsHelpDisplayUrlFlagsNamedUrl 256
#define vsHelpDisplayUrlFlagsNoHistory 512
#define vsHelpDisplayUrlFlagsNoHistoryThisPage 1024

#define HUFTID_Default 0
#define HUFTID_Local 1
#define HUFTID_Online 2
#define HUFTID_Locale 4

#define vsHelpSearchFilterTransformsHelp L"Help"
#define vsHelpSearchFilterTransformsControls L"Controls"
#define vsHelpSearchFilterTransformsSamples L"Samples"
#define vsHelpSearchFilterTransformsSnippets L"Snippets"
#define vsHelpSearchFilterTransformsStarterKits L"StarterKits"
#define vsHelpSearchFilterTransformsAddins L"Addins"
#define vsHelpSearchFilterTransformsUnfiltered L"Unfiltered"

#define DExploreWndClass "wndclass_desked_gsk"
#define VSHELP_VI_PROGID "DExplore.AppObj"

#ENDIF