#IFNDEF FILTEREG_H
#DEFINE FILTEREG_H

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
#endif /*COM_NO_WINDOWS_H*/

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#IFNDEF OAIDL_H
	#include "oaidl.h"
#ENDIF
#IFNDEF OCIDL_H
	#include "ocidl.h"
#ENDIF
#IFNDEF FILTER_H
	#include "filter.h"
#ENDIF

// CLSID_FilterRegistration is defined in SearchAPI.h

FILTERED_DATA_SOURCES STRUCT
	pwcsExtension PTR
	pwcsMime PTR
	pClsid PTR
	pwcsOverride PTR
ENDS

#DEFINE GUID_IID_ILoadFilter <0xc7310722,0xac80,0x11d1,<0x8d,0xf3,0x00,0xc0,0x4f,0xb6,0xef,0x4f>>

ILoadFilter STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	LoadIFilter PTR
	LoadIFilterFromStorage PTR
	LoadIFilterFromStream PTR
ENDS

#endif



