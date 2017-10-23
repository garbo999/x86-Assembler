#ifndef MSIMCNTL_H
#define MSIMCNTL_H

/* header files for imported files */
#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF

#IFNDEF OCIDL_H
	#include "ocidl.h"
#ENDIF

#IFNDEF SIMPDATA_H
	#include "simpdata.h"
#ENDIF

#define DMSIMCONTACTVIEWEVENTS_OnReady              0xD0
#define DMSIMCONTACTVIEWEVENTS_OnLogon              0xD1
#define DMSIMCONTACTVIEWEVENTS_OnLogoff             0xD2
#define DMSIMCONTACTVIEWEVENTS_OnLaunchMessageUI    0xD3
#define DMSIMCONTACTVIEWEVENTS_OnMenuRequest        0xD6
#define DMSIMCONTACTVIEWEVENTS_OnMenuSelect         0xD7
#define DMSIMCONTACTVIEWEVENTS_OnAddResult          0xD8
#define DMSIMCONTACTVIEWEVENTS_OnRemoveResult       0xD9
#define DMSIMCONTACTVIEWEVENTS_OnSelect             0xDA
#define DMSIMCONTACTVIEWEVENTS_OnShutdown           0xDB
#define DMSIMCONTACTVIEWEVENTS_OnEMailContact       0xDC
#define DMSIMCONTACTVIEWEVENTS_OnAddContactUI       0xDD
#define DMSIMCONTACTVIEWEVENTS_OnLocalStateChange   0xDE
#define DMSIMCONTACTVIEWEVENTS_OnExtentsChange      0xDF
#define DMSIMMESSAGEVIEWEVENTS_OnReady              0xD0
#define DMSIMMESSAGEVIEWEVENTS_OnLogon              0xD1
#define DMSIMMESSAGEVIEWEVENTS_OnLogoff             0xD2
#define DMSIMMESSAGEVIEWEVENTS_OnLaunchMessageUI    0xD3
#define DMSIMMESSAGEVIEWEVENTS_OnNewMessage         0xD6
#define DMSIMMESSAGEVIEWEVENTS_OnAddResult          0xD7
#define DMSIMMESSAGEVIEWEVENTS_OnRemoveResult       0xD8
#define DMSIMMESSAGEVIEWEVENTS_OnNewSession         0xD9
#define DMSIMMESSAGEVIEWEVENTS_OnSessionEnd         0xDA
#define DMSIMMESSAGEVIEWEVENTS_OnShutdown           0xDB
#define DMSIMMESSAGEVIEWEVENTS_OnLocalStateChange   0xDC
#define DMSIMCONTACTLISTEVENTS_OnReady              0xD0
#define DMSIMCONTACTLISTEVENTS_OnLogon              0xD1
#define DMSIMCONTACTLISTEVENTS_OnLogoff             0xD2
#define DMSIMCONTACTLISTEVENTS_OnAddResult          0xD3
#define DMSIMCONTACTLISTEVENTS_OnRemoveResult       0xD4
#define DMSIMCONTACTLISTEVENTS_OnShutdown           0xD5
#define DMSIMCONTACTLISTEVENTS_OnChangeContact      0xD6
#define DMSIMCONTACTLISTEVENTS_OnLocalStateChange   0xD7

MSIM_PROVIDER_FIRST	= 0
MSIM_PROVIDER_ANY	= 0
MSIM_PROVIDER_EXCHANGE_HOST	= 1
MSIM_PROVIDER_LAST	= 1
MSIM_PROVIDER_NONE	= 0xffff

MSIM_MSG_UI_SESSION	= 0
MSIM_MSG_UI_NETMEETING	= 1

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#DEFINE GUID_IID__IUseIMBase <0x9D921DA0,0xDFE1,0x45AE,<0x9E,0xB6,0xE5,0x0A,0x27,0x70,0xA5,0x7E>>

_IUseIMBase STRUCT
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
	SetService PTR
	get_Service PTR
	put_Service PTR
	get_HasService PTR
	get_AutoLogon PTR
	put_AutoLogon PTR
	get_LoggedOn PTR
	Logon PTR
	Logoff PTR
	GetLocalState PTR
	SetLocalState PTR
ENDS

#DEFINE GUID_IID_IMSIMContactView <0x415ADE21,0xA15F,0x4C06,<0x8F,0x5D,0xDD,0x5E,0x0A,0x9E,0xA2,0x30>>

IMSIMContactView STRUCT
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
	SetService PTR
	get_Service PTR
	put_Service PTR
	get_HasService PTR
	get_AutoLogon PTR
	put_AutoLogon PTR
	get_LoggedOn PTR
	Logon PTR
	Logoff PTR
	GetLocalState PTR
	SetLocalState PTR
	Add PTR
	Remove PTR
	get_List PTR
	put_List PTR
	AddMenuItem PTR
	get_SelectedMenuOptions PTR
	IMSelected PTR
	EMailSelected PTR
	InviteSelected PTR
	BlockSelected PTR
	UnblockSelected PTR
	get_ExtentWidth PTR
	get_ExtentHeight PTR
	get_HotTracking PTR
	put_HotTracking PTR
	get_AllowCollapse PTR
	put_AllowCollapse PTR
	get_ShowSelectAlways PTR
	put_ShowSelectAlways PTR
	get_OnlineRootLabel PTR
	put_OnlineRootLabel PTR
	get_OfflineRootLabel PTR
	put_OfflineRootLabel PTR
	get_Window PTR
	get_ShowLogonButton PTR
	put_ShowLogonButton PTR
	get_OnlineCollapsed PTR
	put_OnlineCollapsed PTR
	get_OfflineCollapsed PTR
	put_OfflineCollapsed PTR
	get_Group PTR
	put_Group PTR
	get_FilterOffline PTR
	put_FilterOffline PTR
	get_ShowIcons PTR
	put_ShowIcons PTR
	get_AcceptMessages PTR
	put_AcceptMessages PTR
ENDS

#DEFINE GUID_IID_DMSIMContactViewEvents <0x5D39E512,0x1068,0x4F85,<0x81,0x73,0x35,0x7C,0xA1,0x89,0x2E,0xE2>>

DMSIMContactViewEvents STRUCT
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

#DEFINE GUID_IID_IMSIMMessageView <0x053A4F4E,0xB931,0x4602,<0x8C,0x73,0xAB,0xD3,0x04,0x05,0x58,0xF2>>

IMSIMMessageView STRUCT
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
	SetService PTR
	get_Service PTR
	put_Service PTR
	get_HasService PTR
	get_AutoLogon PTR
	put_AutoLogon PTR
	get_LoggedOn PTR
	Logon PTR
	Logoff PTR
	GetLocalState PTR
	SetLocalState PTR
	get_Window PTR
	put_Appearance PTR
	get_Appearance PTR
	get_ShowParticipants PTR
	put_ShowParticipants PTR
	get_ShowMembers PTR
	put_ShowMembers PTR
	get_ShowAvailable PTR
	put_ShowAvailable PTR
	get_AvailableList PTR
	put_AvailableList PTR
	get_ShowMessageHistory PTR
	put_ShowMessageHistory PTR
	get_ShowEdit PTR
	put_ShowEdit PTR
	get_HideStatus PTR
	put_HideStatus PTR
	get_MessageHistory PTR
	get_StatusText PTR
	put_StatusText PTR
	get_MessageText PTR
	put_MessageText PTR
	Invite PTR
	EndSession PTR
	AddToAvailable PTR
	RemoveFromAvailable PTR
	InviteNetMeeting PTR
	NetMeetingInvite PTR
	get_SourceURL PTR
	put_SourceURL PTR
	get_InSession PTR
ENDS

#DEFINE GUID_IID_DMSIMMessageViewEvents <0xEFFE4FAB,0xE75C,0x46EC,<0xAB,0x15,0x58,0x2C,0xD4,0x69,0xEB,0x08>>

DMSIMMessageViewEvents STRUCT
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

#DEFINE GUID_IID_IIMSafeContact <0xC7B1AD00,0x4099,0x4E41,<0xA5,0x66,0x4C,0x49,0xDD,0x3F,0xA1,0x9E>>

IIMSafeContact STRUCT
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
	get_LogonName PTR
	get_FriendlyName PTR
	get_EmailAddress PTR
	get_State PTR
	_SetBaseContact PTR
	LaunchInstantMessage PTR
	LaunchEmail PTR
	LaunchNetMeeting PTR
ENDS

#DEFINE GUID_IID_IMSIMContactList <0x31AE52BA,0xBCED,0x4D92,<0x95,0x82,0x8C,0x45,0x60,0xD6,0xC2,0x58>>

IMSIMContactList STRUCT
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
	SetService PTR
	get_Service PTR
	put_Service PTR
	get_HasService PTR
	get_AutoLogon PTR
	put_AutoLogon PTR
	get_LoggedOn PTR
	Logon PTR
	Logoff PTR
	GetLocalState PTR
	SetLocalState PTR
	get_List PTR
	put_List PTR
	Add PTR
	Remove PTR
	get_SelectedMenuOptions PTR
	InstantMessage PTR
	EMail PTR
	Invite PTR
	Block PTR
	Unblock PTR
	get_Count PTR
	get_Item PTR
	get__NewEnum PTR
	get_LocalState PTR
	put_LocalState PTR
	get_LocalLogonName PTR
ENDS

#DEFINE GUID_IID_DIMContactListEvents <0x8D99BC3C,0x1F60,0x4f2e,<0x9D,0x8B,0x58,0x81,0x60,0x4A,0x2E,0x51>>

DIMContactListEvents STRUCT
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

#DEFINE GUID_CLSID_MSIMContactList <0x0711F6B0,0xB4FA,0x4DDB,<0x89,0x3E,0xCC,0x19,0x7A,0x8F,0x9D,0xC7>>
#DEFINE GUID_CLSID_IMSafeContact <0xEFF88E1B,0x4A46,0x4B09,<0x9D,0x2A,0x81,0x91,0xC4,0x2A,0x16,0x61>>

#endif


