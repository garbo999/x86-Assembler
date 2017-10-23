
#IFNDEF WPCAPI_H
#DEFINE WPCAPI_H

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

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF
#IFNDEF OCIDL_H
	#include "ocidl.h"
#ENDIF

#DEFINE GUID_IID_IWPCProviderState <0x50B6A267,0xC4BD,0x450b,<0xAD,0xB5,0x75,0x90,0x73,0x83,0x7C,0x9E>>

IWPCProviderState STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Enable PTR
	Disable PTR
ENDS

WPCFLAG_APPLICATION	= 0x1
WPCFLAG_OVERRIDE = 0x2

#DEFINE GUID_IID_IWPCProviderConfig <0xBEF54196,0x2D02,0x4a26,<0xB6,0xE5,0xD6,0x5A,0xF2,0x95,0xD0,0xF1>>

IWPCProviderConfig STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetUserSummary PTR
	Configure PTR
	RequestOverride PTR
ENDS

WPCFLAG_NO_RESTRICTION	= 0
WPCFLAG_LOGGING_REQUIRED	= 0x1
WPCFLAG_WEB_FILTERED	= 0x2
WPCFLAG_HOURS_RESTRICTED	= 0x4
WPCFLAG_GAMES_BLOCKED	= 0x8
WPCFLAG_APPS_RESTRICTED	= 0x10

#DEFINE GUID_IID_IWPCSettings <0x8FDF6CA1,0x0189,0x47e4,<0xB6,0x70,0x1A,0x8A,0x46,0x36,0xE3,0x40>>

IWPCSettings STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	IsLoggingRequired PTR
	GetLastSettingsChangeTime PTR
	GetRestrictions PTR
ENDS

#DEFINE GUID_IID_IWPCGamesSettings <0x95E87780,0xE158,0x489e,<0xB4,0x52,0xBB,0xB8,0x50,0x79,0x07,0x15>>

IWPCGamesSettings STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	IsLoggingRequired PTR
	GetLastSettingsChangeTime PTR
	GetRestrictions PTR
	IsBlocked PTR
ENDS

WPCFLAG_WEB_SETTING_NOTBLOCKED = 0
WPCFLAG_WEB_SETTING_DOWNLOADSBLOCKED = 0x1

#DEFINE GUID_IID_IWPCWebSettings <0xFFCCBDB8,0x0992,0x4c30,<0xB0,0xF1,0x1C,0xBB,0x09,0xC2,0x40,0xAA>>

IWPCWebSettings STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	IsLoggingRequired PTR
	GetLastSettingsChangeTime PTR
	GetRestrictions PTR
	GetSettings PTR
	RequestURLOverride PTR
ENDS

WPCFLAG_WPC_VISIBLE	= 0,
WPCFLAG_WPC_HIDDEN	= 0x1

#DEFINE GUID_IID_IWindowsParentalControlsCore <0x4FF40A0F,0x3F3B,0x4d7c,<0xA4,0x1B,0x4F,0x39,0xD7,0xB4,0x4D,0x05>>

IWindowsParentalControlsCore STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetVisibility PTR
	GetUserSettings PTR
	GetWebSettings PTR
	GetWebFilterInfo PTR
ENDS

#DEFINE GUID_IID_IWindowsParentalControls <0x28B4D88B,0xE072,0x49e6,<0x80,0x4D,0x26,0xED,0xBE,0x21,0xA7,0xB9>>

IWindowsParentalControls STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetVisibility PTR
	GetUserSettings PTR
	GetWebSettings PTR
	GetWebFilterInfo PTR
	GetGamesSettings PTR
ENDS

#DEFINE GUID_IID_IWPCProviderSupport <0x41EBA572,0x23ED,0x4779,<0xBE,0xC1,0x8D,0xF9,0x62,0x06,0xC4,0x4C>>

IWPCProviderSupport STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCurrent PTR
ENDS

#DEFINE GUID_CLSID_WpcSettingsProvider <0x355DFFAA,0x3B9F,0x435c,<0xB4,0x28,0x5D,0x44,0x29,0x0B,0xC5,0xF2>>
#DEFINE GUID_CLSID_WpcProviderSupport <0xBB18C7A0,0x2186,0x4be0,<0x97,0xD8,0x04,0x84,0x7B,0x62,0x8E,0x02>>
#DEFINE GUID_CLSID_WindowsParentalControls <0xE77CC89B,0x7401,0x4c04,<0x8C,0xED,0x14,0x9D,0xB3,0x5A,0xDD,0x04>>

#endif



