#ifndef CERTIF_H
#define CERTIF_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF

#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

/*
Switches
COM_NO_WINDOWS_H
*/

#ifndef COM_NO_WINDOWS_H
	#IFNDEF WINDOWS_H
		#include "windows.h"
	#ENDIF
	#IFNDEF OLE2_H
		#include "ole2.h"
	#ENDIF
#endif /*COM_NO_WINDOWS_H */

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#IFNDEF WTYPES_H
	#include "wtypes.h"
#ENDIF
#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF

#define ENUMEXT_OBJECTID 1

#define GUID_IID_ICertServerPolicy <0xaa000922,0xffbe,0x11cf,<0x88,0x00,0x00,0xa0,0xc9,0x03,0xb8,0x3c>>
ICertServerPolicy STRUCT
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
	SetContext PTR
	GetRequestProperty PTR
	GetRequestAttribute PTR
	GetCertificateProperty PTR
	SetCertificateProperty PTR
	GetCertificateExtension PTR
	GetCertificateExtensionFlags PTR
	SetCertificateExtension PTR
	EnumerateExtensionsSetup PTR
	EnumerateExtensions PTR
	EnumerateExtensionsClose PTR
	EnumerateAttributesSetup PTR
	EnumerateAttributes PTR
	EnumerateAttributesClose PTR
ENDS

#define GUID_IID_ICertServerExit <0x4ba9eb90,0x732c,0x11d0,<0x88,0x16,0x00,0xa0,0xc9,0x03,0xb8,0x3c>>
ICertServerExit STRUCT
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
	SetContext PTR
	GetRequestProperty PTR
	GetRequestAttribute PTR
	GetCertificateProperty PTR
	GetCertificateExtension PTR
	GetCertificateExtensionFlags PTR
	EnumerateExtensionsSetup PTR
	EnumerateExtensions PTR
	EnumerateExtensionsClose PTR
	EnumerateAttributesSetup PTR
	EnumerateAttributes PTR
	EnumerateAttributesClose PTR
ENDS

#endif /* CERTIF_H */
