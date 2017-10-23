#IFNDEF SHIMGDATA_H
#DEFINE SHIMGDATA_H

#IFNDEF RPC_H
	#include rpc.h ; Windows RPC definitions
#ENDIF

#IFNDEF RPCNDR_H
	#include rpcndr.h
#ENDIF

#ifndef COM_NO_WINDOWS_H
	#IFNDEF WINDOWS_H
		#include windows.h
	#ENDIF
	#IFNDEF OLE2_H
		#include ole2.h
	#ENDIF
#endif

/* header files for imported files */
#IFNDEF OLEIDL_H
	#include "oleidl.h"
#ENDIF

#IFNDEF PROPIDL_H
	#include "propidl.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF


#define  SHIMGKEY_QUALITY    L"Compression"
#define  SHIMGKEY_RAWFORMAT  L"RawDataFormat"

#define  SHIMGDEC_DEFAULT            0x00000000
#define  SHIMGDEC_THUMBNAIL          0x00000001
#define  SHIMGDEC_LOADFULL           0x00000002
#define  E_NOTVALIDFORANIMATEDIMAGE  (SEVERITY_ERROR<<31|FACILITY_ITF<<16|1)

#DEFINE GUID_IID_IShellImageDataFactory <0x9be8ed5c,0xedab,0x4d75,<0x90,0xf3,0xbd,0x5b,0xdb,0xb2,0x1c,0x82>>

IShellImageDataFactory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION	
	CreateIShellImageData PTR
	CreateImageFromFile PTR
	CreateImageFromStream PTR
	GetDataFormatFromPath PTR
ENDS

#DEFINE GUID_IID_IShellImageData <0xbfdeec12,0x8040,0x4403,<0xa5,0xea,0x9e,0x07,0xda,0xfc,0xf5,0x30>>

IShellImageData STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION	
	Decode PTR
	Draw PTR
	NextFrame PTR
	NextPage PTR
	PrevPage PTR
	IsTransparent PTR
	IsAnimated PTR
	IsVector PTR
	IsMultipage PTR
	IsEditable PTR
	IsPrintable PTR
	IsDecoded PTR
	GetCurrentPage PTR
	GetPageCount PTR
	SelectPage PTR
	GetSize PTR
	GetRawDataFormat PTR
	GetPixelFormat PTR
	GetDelay PTR
	GetProperties PTR
	Rotate PTR
	Scale PTR
	DiscardEdit PTR
	SetEncoderParams PTR
	DisplayName PTR
	GetResolution PTR
	GetEncoderParams PTR
	RegisterAbort PTR
	CloneFrame PTR
	ReplaceFrame PTR
ENDS

#DEFINE GUID_IID_IShellImageDataAbort <0x53fb8e58,0x50c0,0x4003,<0xb4,0xaa,0x0c,0x8d,0xf2,0x8e,0x7f,0x3a>>

IShellImageDataAbort STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION	
	QueryAbort PTR
ENDS

#DEFINE GUID_CLSID_ShellImageDataFactory <0x66e4e4fb,0xf385,0x4dd0,<0x8d,0x74,0xa2,0xef,0xd1,0xbc,0x61,0x78>>
#DEFINE GUID_CLSID_ShellImageData GUID_CLSID_ShellImageDataFactory

#endif


