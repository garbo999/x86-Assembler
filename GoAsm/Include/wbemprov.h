
#ifndef WBEMPROV_H
#define WBEMPROV_H

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
#endif /*COM_NO_WINDOWS_H */

#IFNDEF OBJIDL_H
	#include "objidl.h"
#ENDIF

#IFNDEF OLEIDL_H
	#include "oleidl.h"
#ENDIF

#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF

#IFNDEF WBEMCLI_H
	#include "wbemcli.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

WBEM_REQUIREMENTS_START_POSTFILTER = 0
WBEM_REQUIREMENTS_STOP_POSTFILTER = 1
WBEM_REQUIREMENTS_RECHECK_SUBSCRIPTIONS = 2

#define GUID_IID_IWbemPropertyProvider <0xCE61E841,0x65BC,0x11d0,<0xB6,0xBD,0x00,0xAA,0x00,0x32,0x40,0xC7>>
IWbemPropertyProvider STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetProperty PTR
	PutProperty PTR
ENDS

#define GUID_IID_IWbemUnboundObjectSink <0xe246107b,0xb06e,0x11d0,<0xad,0x61,0x00,0xc0,0x4f,0xd8,0xfd,0xff>>
IWbemUnboundObjectSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	IndicateToConsumer PTR
ENDS

#define GUID_IID_IWbemEventProvider <0xe245105b,0xb06e,0x11d0,<0xad,0x61,0x00,0xc0,0x4f,0xd8,0xfd,0xff>>
IWbemEventProvider STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ProvideEvents PTR
ENDS

#define GUID_IID_IWbemEventProviderQuerySink <0x580acaf8,0xfa1c,0x11d0,<0xad,0x72,0x00,0xc0,0x4f,0xd8,0xfd,0xff>>
IWbemEventProviderQuerySink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	NewQuery PTR
	CancelQuery PTR
ENDS

#define GUID_IID_IWbemEventConsumerProvider <0xe246107a,0xb06e,0x11d0,<0xad,0x61,0x00,0xc0,0x4f,0xd8,0xfd,0xff>>
IWbemEventConsumerProvider STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	FindConsumer PTR
ENDS

#define GUID_IID_IWbemProviderInitSink <0x1be41571,0x91dd,0x11d1,<0xae,0xb2,0x00,0xc0,0x4f,0xb6,0x88,0x20>>
IWbemProviderInitSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetStatus PTR
ENDS

#define GUID_IID_IWbemProviderInit <0x1be41572,0x91dd,0x11d1,<0xae,0xb2,0x00,0xc0,0x4f,0xb6,0x88,0x20>>
IWbemProviderInit STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Initialize PTR
ENDS

#define GUID_IID_IWbemHiPerfProvider <0x49353c93,0x516b,0x11d1,<0xae,0xa6,0x00,0xc0,0x4f,0xb6,0x88,0x20>>
IWbemHiPerfProvider STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	QueryInstances PTR
	CreateRefresher PTR
	CreateRefreshableObject PTR
	StopRefreshing PTR
	CreateRefreshableEnum PTR
	GetObjects PTR
ENDS

#define GUID_CLSID_WbemAdministrativeLocator <0xcb8555cc,0x9128,0x11d1,<0xad,0x9b,0x00,0xc0,0x4f,0xd8,0xfd,0xff>>
#define GUID_CLSID_WbemAuthenticatedLocator <0xcd184336,0x9128,0x11d1,<0xad,0x9b,0x00,0xc0,0x4f,0xd8,0xfd,0xff>>
#define GUID_CLSID_WbemUnauthenticatedLocator <0x443E7B79,0xDE31,0x11d2,<0xB3,0x40,0x00,0x10,0x4B,0xCC,0x4B,0x4A>>

#define GUID_IID_IWbemEventProviderSecurity <0x631f7d96,0xd993,0x11d2,<0xb3,0x39,0x00,0x10,0x5a,0x1f,0x4a,0xaf>>
IWbemEventProviderSecurity STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AccessCheck PTR
ENDS

#define GUID_IID_IWbemProviderIdentity <0x631f7d97,0xd993,0x11d2,<0xb3,0x39,0x00,0x10,0x5a,0x1f,0x4a,0xaf>>
IWbemProviderIdentity STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetRegistrationObject PTR
ENDS

WBEM_S_INITIALIZED = 0
WBEM_S_LIMITED_SERVICE = 0x43001
WBEM_S_INDIRECTLY_UPDATED = WBEM_S_LIMITED_SERVICE+1
WBEM_E_RETRY_LATER = 0x80043001
WBEM_E_RESOURCE_CONTENTION = WBEM_E_RETRY_LATER+1
WBEM_FLAG_OWNER_UPDATE = 0x10000

#endif /* _WBEMPROV_H */
