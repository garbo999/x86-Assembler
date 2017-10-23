#ifndef CERTVIEW_H
#define CERTVIEW_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF
#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#IFNDEF COM_NO_WINDOWS_H
	#IFNDEF WINDOWS_H
		#include "windows.h"
	#ENDIF
	#IFNDEF OLE2_H
		#include "ole2.h"
	#ENDIF
#ENDIF /*COM_NO_WINDOWS_H */

#IFNDEF WTYPES_H
	#include "wtypes.h"
#ENDIF

#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF

#define CV_OUT_BASE64HEADER  (0)
#define CV_OUT_BASE64  (0x1)
#define CV_OUT_BINARY  (0x2)
#define CV_OUT_BASE64REQUESTHEADER  (0x3)
#define CV_OUT_HEX  (0x4)
#define CV_OUT_HEXASCII (0x5)
#define CV_OUT_BASE64X509CRLHEADER  (0x9)
#define CV_OUT_HEXADDR  (0xa)
#define CV_OUT_HEXASCIIADDR  (0xb)
#define CV_OUT_ENCODEMASK  (0xff)
#define CVR_SEEK_NONE  (0)
#define CVR_SEEK_EQ  (0x1)
#define CVR_SEEK_LT  (0x2)
#define CVR_SEEK_LE  (0x4)
#define CVR_SEEK_GE  (0x8)
#define CVR_SEEK_GT  (0x10)
#define CVR_SEEK_MASK  (0xff)
#define CVR_SEEK_NODELTA  (0x1000)
#define CVR_SORT_NONE  (0)
#define CVR_SORT_ASCEND (0x1)
#define CVR_SORT_DESCEND  (0x2)
#define CV_COLUMN_QUEUE_DEFAULT (-1)
#define CV_COLUMN_LOG_DEFAULT  (-2)
#define CV_COLUMN_LOG_FAILED_DEFAULT  (-3)

#define GUID_IID_IEnumCERTVIEWCOLUMN <9c735be2,0x57a5,0x11d1,<0x9b,0xdb,0x00,0xc0,0x4f,0xb6,0x83,0xfa>>
IEnumCERTVIEWCOLUMN STRUCT
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
	Next PTR
	GetName PTR
	GetDisplayName PTR
	GetType PTR
	IsIndexed PTR
	GetMaxLength PTR
	GetValue PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#define GUID_IID_IEnumCERTVIEWATTRIBUTE <0xe77db656,0x7653,0x11d1,<0x9b,0xde,0x00,0xc0,0x4f,0xb6,0x83,0xfa>>
IEnumCERTVIEWATTRIBUTE STRUCT
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
	Next PTR
	GetName PTR
	GetValue PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#define GUID_IID_IEnumCERTVIEWEXTENSION <0xe7dd1466,0x7653,0x11d1,<0x9b,0xde,0x00,0xc0,0x4f,0xb6,0x83,0xfa>>
IEnumCERTVIEWEXTENSION STRUCT
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
	Next PTR
	GetName PTR
	GetFlags PTR
	GetValue PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#define GUID_IID_IEnumCERTVIEWROW <0xd1157f4c,0x5af2,0x11d1,<0x9b,0xdc,0x00,0xc0,0x4f,0xb6,0x83,0xfa>>
IEnumCERTVIEWROW STRUCT
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
	Next PTR
	EnumCertViewColumn PTR
	EnumCertViewAttribute PTR
	EnumCertViewExtension PTR
	Skip PTR
	Reset PTR
	Clone PTR
	GetMaxIndex PTR
ENDS

#define GUID_IID_ICertView <0xc3fac344,0x1e84,0x11d1,<0x9b,0xd6,0x00,0xc0,0x4f,0xb6,0x83,0xfa>>
ICertView STRUCT
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
	OpenConnection PTR
	EnumCertViewColumn PTR
	GetColumnCount PTR
	GetColumnIndex PTR
	SetResultColumnCount PTR
	SetResultColumn PTR
	SetRestriction PTR
	OpenView PTR
ENDS

#endif
