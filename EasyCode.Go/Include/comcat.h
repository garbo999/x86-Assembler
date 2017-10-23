#ifndef COMCAT_H
#define COMCAT_H

#ifndef RPC_H
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

#define GUID_IID_IEnumGUID <0002E000,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IEnumGUID STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

CATEGORYINFO STRUCT
	catid GUID
	lcid LCID
	szDescription DW 128 DUP
ENDS

#define GUID_IID_IEnumCATEGORYINFO <0002E011,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IEnumCATEGORYINFO STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

#define GUID_IID_ICatRegister <0002E012,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
ICatRegister STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	RegisterCategories PTR
	UnRegisterCategories PTR
	RegisterClassImplCategories PTR
	UnRegisterClassImplCategories PTR
	RegisterClassReqCategories PTR
	UnRegisterClassReqCategories PTR
ENDS

#define GUID_IID_ICatInformation <0002E013,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
ICatInformation STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	EnumCategories PTR
	GetCategoryDesc PTR
	EnumClassesOfCategories PTR
	IsClassOfCategories PTR
	EnumImplCategoriesOfClass PTR
	EnumReqCategoriesOfClass PTR
ENDS

#endif
