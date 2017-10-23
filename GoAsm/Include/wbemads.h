#ifndef WBEMADS_H
#define WBEMADS_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF

#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#IFDEF LINKFILES
	#dynamiclinkfile Wbemads.dll
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

#define GUID_IID_IWMIExtension <0xadc1f06e,0x5c7e,0x11d2,<0x8b,0x74,0x00,0x10,0x4b,0x2a,0xfb,0x41>>
IWMIExtension STRUCT
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
	get_WMIObjectPath PTR
	GetWMIObject PTR
	GetWMIServices PTR
ENDS

#define GUID_CLSID_WMIExtension <0xf0975afe,0x5c7f,0x11d2,<0x8b,0x74,0x00,0x10,0x4b,0x2a,0xfb,0x41>>

#endif /* _WBEMADS_H */
