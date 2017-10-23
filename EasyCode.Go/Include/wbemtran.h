#ifndef WBEMTRAN_H
#define WBEMTRAN_H

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

#ifndef OBJIDL_H
	#include "objidl.h"
#endif

#ifndef OLEIDL_H
	#include "oleidl.h"
#endif

#ifndef OAIDL_H
	#include "oaidl.h"
#endif

#ifndef WBEMCLI_H
	#include "wbemcli.h"
#endif

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

WBEM_FLAG_INPROC_LOGIN = 0
WBEM_FLAG_LOCAL_LOGIN = 1
WBEM_FLAG_REMOTE_LOGIN = 2
WBEM_AUTHENTICATION_METHOD_MASK = 0xf
WBEM_FLAG_USE_MULTIPLE_CHALLENGES = 0x10

#define GUID_IID_IWbemTransport <0x553fe584,0x2156,0x11d0,<0xb6,0xae,0x00,0xaa,0x00,0x32,0x40,0xc7>>
IWbemTransport STRUCT
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

#define GUID_IID_IWbemLevel1Login <0xF309AD18,0xD86A,0x11d0,<0xA0,0x75,0x00,0xC0,0x4F,0xB6,0x88,0x20>>
IWbemLevel1Login STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	EstablishPosition PTR
	RequestChallenge PTR
	WBEMLogin PTR
	NTLMLogin PTR
ENDS

#define GUID_IID_IWbemConnectorLogin <0xd8ec9cb1,0xb135,0x4f10,<0x8b,0x1b,0xc7,0x18,0x8b,0xb0,0xd1,0x86>>
IWbemConnectorLogin STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ConnectorLogin PTR
ENDS

#define GUID_IID_IWbemAddressResolution <0xF7CE2E12,0x8C90,0x11d1,<0x9E,0x7B,0x00,0xC0,0x4F,0xC3,0x24,0xA8>>
IWbemAddressResolution STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Resolve PTR
ENDS

#define GUID_CLSID_WbemLevel1Login <0x8BC3F05E,0xD86B,0x11d0,<0xA0,0x75,0x00,0xC0,0x4F,0xB6,0x88,0x20>>
#define GUID_CLSID_WbemLocalAddrRes <0xA1044801,0x8F7E,0x11d1,<0x9E,0x7C,0x00,0xC0,0x4F,0xC3,0x24,0xA8>>
#define GUID_CLSID_WbemUninitializedClassObject <0x7a0227f6,0x7108,0x11d1,<0xad,0x90,0x00,0xc0,0x4f,0xd8,0xfd,0xff>>

#define GUID_IID_IWbemClientTransport <0xF7CE2E11,0x8C90,0x11d1,<0x9E,0x7B,0x00,0xC0,0x4F,0xC3,0x24,0xA8>>
IWbemClientTransport STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ConnectServer PTR
ENDS

#define GUID_IID_IWbemClientConnectionTransport <0xa889c72a,0xfcc1,0x4a9e,<0xaf,0x61,0xed,0x07,0x13,0x33,0xfb,0x5b>>
IWbemClientConnectionTransport STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Open PTR
	OpenAsync PTR
	Cancel PTR
ENDS

#define GUID_CLSID_WbemDCOMTransport <0xF7CE2E13,0x8C90,0x11d1,<0x9E,0x7B,0x00,0xC0,0x4F,0xC3,0x24,0xA8>>

#define GUID_IID_IWbemConstructClassObject <0x9ef76194,0x70d5,0x11d1,<0xad,0x90,0x00,0xc0,0x4f,0xd8,0xfd,0xff>>
IWbemConstructClassObject STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetInheritanceChain PTR
	SetPropertyOrigin PTR
	SetMethodOrigin PTR
	SetServerNamespace PTR
ENDS

#endif /* WBEMTRAN_H */
