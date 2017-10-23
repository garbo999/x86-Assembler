#ifndef EXDISP_H
#define EXDISP_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF

#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

CSC_UPDATECOMMANDS = 0xffffffff
CSC_NAVIGATEFORWARD = 0x1
CSC_NAVIGATEBACK = 0x2

SWC_EXPLORER = 0
SWC_BROWSER = 0x1
SWC_3RDPARTY = 0x2
SWC_CALLBACK = 0x4

SWFO_NEEDDISPATCH = 0x1
SWFO_INCLUDEPENDING = 0x2
SWFO_COOKIEPASSED = 0x4

navOpenInNewWindow = 0x1
navNoHistory = 0x2
navNoReadFromCache = 0x4
navNoWriteToCache = 0x8
navAllowAutosearch = 0x10
navBrowserBar = 0x20

REFRESH_NORMAL = 0
REFRESH_IFEXPIRED = 1
REFRESH_COMPLETELY = 3

#define GUID_IID_IWebBrowser <0xEAB22AC1,0x30C1,0x11CF,<0xA7,0xEB,0x00,0x00,0xC0,0x5B,0xAE,0x0B>>
IWebBrowser STRUCT
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
	GoBack PTR
	GoForward PTR
	GoHome PTR
	GoSearch PTR
	Navigate PTR
	Refresh PTR
	Refresh2 PTR
	Stop PTR
	get_Application PTR
	get_Parent PTR
	get_Container PTR
	get_Document PTR
	get_TopLevelContainer PTR
	get_Type PTR
	get_Left PTR
	put_Left PTR
	get_Top PTR
	put_Top PTR
	get_Width PTR
	put_Width PTR
	get_Height PTR
	put_Height PTR
	get_LocationName PTR
	get_LocationURL PTR
	get_Busy PTR
ENDS

#define GUID_IID_DWebBrowserEvents <0xEAB22AC2,0x30C1,0x11CF,<0xA7,0xEB,0x00,0x00,0xC0,0x5B,0xAE,0x0B>>
DWebBrowserEvents STRUCT
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
ENDS

#define GUID_IID_IWebBrowserApp <0x0002DF05,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IWebBrowserApp STRUCT
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
	GoBack PTR
	GoForward PTR
	GoHome PTR
	GoSearch PTR
	Navigate PTR
	Refresh PTR
	Refresh2 PTR
	Stop PTR
	get_Application PTR
	get_Parent PTR
	get_Container PTR
	get_Document PTR
	get_TopLevelContainer PTR
	get_Type PTR
	get_Left PTR
	put_Left PTR
	get_Top PTR
	put_Top PTR
	get_Width PTR
	put_Width PTR
	get_Height PTR
	put_Height PTR
	get_LocationName PTR
	get_LocationURL PTR
	get_Busy PTR
	Quit PTR
	ClientToWindow PTR
	PutProperty PTR
	GetProperty PTR
	get_Name PTR
	get_HWND PTR
	get_FullName PTR
	get_Path PTR
	get_Visible PTR
	put_Visible PTR
	get_StatusBar PTR
	put_StatusBar PTR
	get_StatusText PTR
	put_StatusText PTR
	get_ToolBar PTR
	put_ToolBar PTR
	get_MenuBar PTR
	put_MenuBar PTR
	get_FullScreen PTR
	put_FullScreen PTR
ENDS

#define GUID_IID_IWebBrowser2 <0xD30C1661,0xCDAF,0x11d0,<0x8A,0x3E,0x00,0xC0,0x4F,0xC9,0xE2,0x6E>>
IWebBrowser2 STRUCT
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
	GoBack PTR
	GoForward PTR
	GoHome PTR
	GoSearch PTR
	Navigate PTR
	Refresh PTR
	Refresh2 PTR
	Stop PTR
	get_Application PTR
	get_Parent PTR
	get_Container PTR
	get_Document PTR
	get_TopLevelContainer PTR
	get_Type PTR
	get_Left PTR
	put_Left PTR
	get_Top PTR
	put_Top PTR
	get_Width PTR
	put_Width PTR
	get_Height PTR
	put_Height PTR
	get_LocationName PTR
	get_LocationURL PTR
	get_Busy PTR
	Quit PTR
	ClientToWindow PTR
	PutProperty PTR
	GetProperty PTR
	get_Name PTR
	get_HWND PTR
	get_FullName PTR
	get_Path PTR
	get_Visible PTR
	put_Visible PTR
	get_StatusBar PTR
	put_StatusBar PTR
	get_StatusText PTR
	put_StatusText PTR
	get_ToolBar PTR
	put_ToolBar PTR
	get_MenuBar PTR
	put_MenuBar PTR
	get_FullScreen PTR
	put_FullScreen PTR
	Navigate2 PTR
	QueryStatusWB PTR
	ExecWB PTR
	ShowBrowserBar PTR
	get_ReadyState PTR
	get_Offline PTR
	put_Offline PTR
	get_Silent PTR
	put_Silent PTR
	get_RegisterAsBrowser PTR
	put_RegisterAsBrowser PTR
	get_RegisterAsDropTarget PTR
	put_RegisterAsDropTarget PTR
	get_TheaterMode PTR
	put_TheaterMode PTR
	get_AddressBar PTR
	put_AddressBar PTR
	get_Resizable PTR
	put_Resizable PTR
ENDS

// Class GUIDs for IWebBrowser2::ShowBrowserBar
#define GUID_CLSID_Search <0x30D02401,0x6A81,0x11D0,<0x82,0x74,0x00,0xC0,0x4F,0xD5,0xAE,0x38>>
#define GUID_CLSID_Favorites <0xEFA24E61,0xB078,0x11D0,<0x89,0xE4,0x00,0xC0,0x4F,0xC9,0xE2,0x6E>>
#define GUID_CLSID_History <0xEFA24E62,0xB078,0x11D0,<0x89,0xE4,0x00,0xC0,0x4F,0xC9,0xE2,0x6E>>
#define GUID_CLSID_Channels <0xEFA24E63,0xB078,0x11D0,<0x89,0xE4,0x00,0xC0,0x4F,0xC9,0xE2,0x6E>>

#define GUID_IID_DWebBrowserEvents2 <0x34A715A0,0x6587,0x11D0,<0x92,0x4A,0x00,0x20,0xAF,0xC7,0xAC,0x4D>>
DWebBrowserEvents2 STRUCT
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
ENDS

#define GUID_IID_DShellWindowsEvents <0xfe4106e0,0x399a,0x11d0,<0xa4,0x8c,0x00,0xa0,0xc9,0x0a,0x8f,0x39>>
DShellWindowsEvents STRUCT
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
ENDS

#define GUID_IID_IShellWindows <0x85CB6900,0x4D95,0x11CF,<0x96,0x0C,0x00,0x80,0xC7,0xF4,0xEE,0x85>>
IShellWindows STRUCT
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
	_NewEnum PTR
	Register PTR
	RegisterPending PTR
	Revoke PTR
	OnNavigate PTR
	OnActivated PTR
	FindWindow PTR
	OnCreated PTR
	ProcessAttachDetach PTR
ENDS

#define GUID_IID_IShellUIHelper <0x729FE2F8,0x1EA8,0x11d1,<0x8F,0x85,0x00,0xC0,0x4F,0xC2,0xFB,0xE1>>
IShellUIHelper STRUCT
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
	ResetFirstBootMode PTR
	ResetSafeMode PTR
	RefreshOfflineDesktop PTR
	AddFavorite PTR
	AddChannel PTR
	AddDesktopComponent PTR
	IsSubscribed PTR
	NavigateAndFind PTR
	ImportExportFavorites PTR
	AutoCompleteSaveForm PTR
	AutoScan PTR
	AutoCompleteAttach PTR
	ShowBrowserUI PTR
ENDS

#define GUID_IID_ShellFavoritesNameSpaceEvents <0x55136806,0xB2DE,0x11D1,<0xB9,0xF2,0x00,0xA0,0xC9,0x8B,0xC5,0x47>>
_ShellFavoritesNameSpaceEvents STRUCT
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
ENDS

#define GUID_IID_IShellFavoritesNameSpace <0x55136804,0xB2DE,0x11D1,<0xB9,0xF2,0x00,0xA0,0xC9,0x8B,0xC5,0x47>>
IShellFavoritesNameSpace STRUCT
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
	MoveSelectionUp PTR
	MoveSelectionDown PTR
	ResetSort PTR
	NewFolder PTR
	Synchronize PTR
	Import PTR
	Export PTR
	InvokeContextMenuCommand PTR
	MoveSelectionTo PTR
	get_FOfflinePackInstalled PTR
	CreateSubscriptionForSelection PTR
	DeleteSubscriptionForSelection PTR
	SetRoot PTR
ENDS

#define GUID_IID_IScriptErrorList <0xF3470F24,0x15FD,0x11d2,<0xBB,0x2E,0x00,0x80,0x5F,0xF7,0xEF,0xCA>>
IScriptErrorList STRUCT
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
	advanceError PTR
	retreatError PTR
	canAdvanceError PTR
	canRetreatError PTR
	getErrorLine PTR
	getErrorChar PTR
	getErrorCode PTR
	getErrorMsg PTR
	getErrorUrl PTR
	getAlwaysShowLockState PTR
	getDetailsPaneOpen PTR
	setDetailsPaneOpen PTR
	getPerErrorDisplay PTR
	setPerErrorDisplay PTR
ENDS

#define GUID_IID_ISearch <0xba9239a4,0x3dd5,0x11d2,<0xbf,0x8b,0x00,0xc0,0x4f,0xb9,0x36,0x61>>
ISearch STRUCT
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
	get_Title PTR
	get_Id PTR
	get_Url PTR
ENDS

#define GUID_IID_ISearches <0x47c922a2,0x3dd5,0x11d2,<0xbf,0x8b,0x00,0xc0,0x4f,0xb9,0x36,0x61>>
ISearches STRUCT
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
	get_Default PTR
	Item PTR
	_NewEnum PTR
ENDS

#define GUID_IID_ISearchAssistantOC <0x72423E8F,0x8011,0x11d2,<0xBE,0x79,0x00,0xA0,0xC9,0xA8,0x3D,0xA1>>
ISearchAssistantOC STRUCT
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
	AddNextMenuItem PTR
	SetDefaultSearchUrl PTR
	NavigateToDefaultSearch PTR
	IsRestricted PTR
	get_ShellFeaturesEnabled PTR
	get_SearchAssistantDefault PTR
	get_Searches PTR
	get_InWebFolder PTR
	PutProperty PTR
	GetProperty PTR
	put_EventHandled PTR
	ResetNextMenu PTR
	FindOnWeb PTR
	FindFilesOrFolders PTR
	FindComputer PTR
	FindPrinter PTR
	FindPeople PTR
	GetSearchAssistantURL PTR
	NotifySearchSettingsChanged PTR
	put_ASProvider PTR
	get_ASProvider PTR
	put_ASSetting PTR
	get_ASSetting PTR
	NETDetectNextNavigate PTR
	PutFindText PTR
	get_Version PTR
	EncodeString PTR
ENDS

#define GUID_IID_ISearchAssistantOC2 <0x72423E8F,0x8011,0x11d2,<0xBE,0x79,0x00,0xA0,0xC9,0xA8,0x3D,0xA2>>
ISearchAssistantOC2 STRUCT
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
	AddNextMenuItem PTR
	SetDefaultSearchUrl PTR
	NavigateToDefaultSearch PTR
	IsRestricted PTR
	get_ShellFeaturesEnabled PTR
	get_SearchAssistantDefault PTR
	get_Searches PTR
	get_InWebFolder PTR
	PutProperty PTR
	GetProperty PTR
	put_EventHandled PTR
	ResetNextMenu PTR
	FindOnWeb PTR
	FindFilesOrFolders PTR
	FindComputer PTR
	FindPrinter PTR
	FindPeople PTR
	GetSearchAssistantURL PTR
	NotifySearchSettingsChanged PTR
	put_ASProvider PTR
	get_ASProvider PTR
	put_ASSetting PTR
	get_ASSetting PTR
	NETDetectNextNavigate PTR
	PutFindText PTR
	get_Version PTR
	EncodeString PTR
	get_ShowFindPrinter PTR
ENDS

#define GUID_IID_SearchAssistantEvents <0x1611FDDA-445B,0x11d2,<0x85,0xDE,0x00,0xC0,0x4F,0xA3,0x5C,0x89>>
_SearchAssistantEvents STRUCT
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
ENDS

#endif
