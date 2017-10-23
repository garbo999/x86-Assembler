#IFNDEF BASECOM_H
#DEFINE BASECOM_H

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

#IFNDEF Unknown
	Unknown STRUCT
	   QueryInterface		PTR
	   AddRef				PTR
	   Release				PTR
	ENDS
#ENDIF

#IFNDEF Dispatch
	Dispatch STRUCT
		GetTypeInfoCount PTR
		GetTypeInfo PTR
		GetIDsOfNames PTR
		Invoke PTR
	ENDS
#ENDIF

#IFNDEF STANDARD_DISPATCH
	STANDARD_DISPATCH STRUCT
	;	UNION
	;		struct
	;			QueryInterface		PTR
	;			AddRef				PTR
	;			Release				PTR
	;		ends
			IUnknown Unknown
	;	ENDUNION
	;	UNION
	;		struct
	;			GetTypeInfoCount PTR
	;			GetTypeInfo PTR
	;			GetIDsOfNames PTR
	;			Invoke PTR
	;		ends
			IDispatch Dispatch
	;	ENDUNION
	ENDS
#ENDIF

#IFNDEF GUID_IID_IClassFactory
	#define GUID_IID_IClassFactory <0x00000001,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
#ENDIF

#IFNDEF IClassFactory
	IClassFactory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
		CreateInstance PTR
		LockServer PTR
	ENDS
#ENDIF

#IFNDEF GUID_IID_IDispatch
	#define GUID_IID_IDispatch <0x00020400,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
#ENDIF

#IFNDEF IDISPATCH_DEFINED
	#IFNDEF IDispatch
		IDispatch STRUCT
			struct
				QueryInterface		PTR
				AddRef				PTR
				Release				PTR
			ends
			struct
				GetTypeInfoCount PTR
				GetTypeInfo PTR
				GetIDsOfNames PTR
				Invoke PTR
			ends
		ENDS
	#ENDIF
#ENDIF

#IFNDEF GUID_IID_IUnknown
	#define GUID_IID_IUnknown <0x00000000,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
#ENDIF

#IFNDEF IUNKNOWN_DEFINED
	#IFNDEF IUnknown
		IUnknown STRUCT
		   QueryInterface		PTR
		   AddRef				PTR
		   Release				PTR
		ENDS
	#ENDIF
#ENDIF

#IFNDEF GUID_IID_AsyncIUnknown
	#define GUID_IID_AsyncIUnknown <0x000e0000,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
#ENDIF

AsyncIUnknown STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Begin_QueryInterface PTR
	Finish_QueryInterface PTR
	Begin_AddRef PTR
	Finish_AddRef PTR
	Begin_Release PTR
	Finish_Release PTR
ENDS

#ENDIF