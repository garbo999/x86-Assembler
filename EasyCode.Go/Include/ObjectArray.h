#ifndef OBJECTARRAY_H
#define OBJECTARRAY_H

#ifndef RPC_H
	#include "rpc.h"
#endif
#ifndef RPCNDR_H
	#include "rpcndr.h"
#endif

#ifndef COM_NO_WINDOWS_H
	#ifndef WINDOWS_H
		#include "windows.h"
	#endif
	#ifndef OLE2_H
		#include "ole2.h"
	#endif
#endif /*COM_NO_WINDOWS_H*/

/* header files for imported files */
#ifndef OAIDL_H
	#include "oaidl.h"
#endif
#ifndef OCIDL_H
	#include "ocidl.h"
#endif

#define GUID_IID_IObjectArray <0x92CA9DCD, 0x5622, 0x4bba, <0xA8, 0x05, 0x5E, 0x9F, 0x54, 0x1B, 0xD8, 0xC9>>

IObjectArray STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCount PTR
	GetAt PTR
ENDS

#define GUID_IID_IObjectCollection <0x5632b1a4, 0xe38a, 0x400a, <0x92, 0x8a, 0xd4, 0xcd, 0x63, 0x23, 0x02, 0x95>>

IObjectCollection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCount PTR
	GetAt PTR
	AddObject PTR
	AddFromArray PTR
	RemoveObjectAt PTR
	Clear PTR
ENDS

#endif



