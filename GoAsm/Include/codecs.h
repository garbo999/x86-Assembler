#ifndef CODECS_H
#define CODECS_H

/* CODEC definitions */

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define IC_E_CAPS_INSTANTIATION_FAILURE  0x83010001
#define IC_E_CAPS_INITIALIZATION_FAILURE  0x83010002
#define IC_E_NO_FORMATS  0x83010003
#define IC_E_NO_SUCH_FORMAT  0x83010005
#define IC_E_INTERNAL_ERROR  0x83010006

IInstallAudioCodecs STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddACMFormat PTR
	RemoveACMFormat PTR
	ReorderFormats PTR
	EnumFormats PTR
	FreeBuffer PTR
ENDS

IInstallVideoCodecs STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddVCMFormat PTR
	RemoveVCMFormat PTR
	ReorderFormats PTR
	EnumFormats PTR
	FreeBuffer PTR
ENDS

IInstallCodecs STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddACMFormat PTR
	RemoveACMFormat PTR
	ReorderFormats PTR
	EnumFormats PTR
	FreeBuffer PTR
ENDS

#define GUID_CLSID_InstallCodecs <0x8ed14cc0,0x7a1f,0x11d0,<0x92,0xf6,0x0,0xa0,0xc9,0x22,0xe6,0xb2>>
#define GUID_IID_IInstallCodecs <0x8ed14cc1,0x7a1f,0x11d0,<0x92,0xf6,0x0,0xa0,0xc9,0x22,0xe6,0xb2>>
#define GUID_IID_IInstallAudioCodecs <0x8ed14cc2,0x7a1f,<0x11d0,0x92,0xf6,0x0,0xa0,0xc9,0x22,0xe6,0xb2>>
#define GUID_IID_IInstallVideoCodecs <0x8ed14cc3,0x7a1f,<0x11d0,0x92,0xf6,0x0,0xa0,0xc9,0x22,0xe6,0xb2>>

#endif
