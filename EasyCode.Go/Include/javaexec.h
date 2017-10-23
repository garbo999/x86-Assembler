#ifndef JAVAEXEC_H
#define JAVAEXEC_H

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

JAVAPROPERTY STRUCT
	pszKey PTR
	pszValue PTR
ENDS

// The JAVACLASSRESOURCE header must have tis signature
#define JAVACLASSRESOURCESIGNATURE  0x43524E44

JAVACLASSRESOURCE STRUCT
	dwSignature DD 0x43524E44
	dwNumClasses DD
	dwFormatVersion DD
	dwFlags DD
ENDS

JAVACLASSRESOURCEINFO STRUCT
	hModule HANDLE
	dwResourceID DD
ENDS

// IJavaExecute2::SetClassSource Type Flags

#define CLASS_SOURCE_TYPE_MODULERESOURCES  0x00000001
#define CLASS_SOURCE_TYPE_ISTORAGE         0x00000002

// Data structure to be passed to IJavaExecute2::SetClassSource
// when using the CLASS_SOURCE_TYPE_MODULERESOURCES source type.

JAVACLASSRESOURCEINFO STRUCT
	hModule HANDLE
	dwResourceID DD
ENDS

IEnumJAVAPROPERTY STRUCT
	#IFNDEF NO_BASEINTERFACE_FUNCS
		UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	#ENDIF
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

JAVAEXECUTEINFO STRUCT
	cbSize DD
	dwFlags DD
	pszClassName PTR
	rgszArgs PTR
	cArgs DD
	pszClassPath PTR
	pszNamespace PTR
ENDS

#define JEIF_VERIFYCLASSES              0x00000002
#define JEIF_ACTIVEXDEBUG               0x00000004
#define JEIF_NATIVECODEINMODULE         0x00000008
#define JEIF_NAMESPACE_SPECIFIED        0x00000010
#define JEIF_INSTALLSTANDARDSECURITY    0x00000020

#ifdef AD2_STUFF
	#define JEIF_APPLETVIEWER 0x00000040
	#define JEIF_ALL_FLAGS 0x0000007E
#else
	#define JEIF_ALL_FLAGS 0x0000003E
#endif

IJavaExecute STRUCT
	#IFNDEF NO_BASEINTERFACE_FUNCS
		UNION
			struct
				QueryInterface		PTR
				AddRef				PTR
				Release				PTR
			ends
			IUnknown Unknown
		ENDUNION
	#ENDIF
	GetDefaultClassPath PTR
	Execute PTR
ENDS

IJavaExecute2 STRUCT
	#IFNDEF NO_BASEINTERFACE_FUNCS
		UNION
			struct
				QueryInterface		PTR
				AddRef				PTR
				Release				PTR
			ends
			IUnknown Unknown
		ENDUNION
	#ENDIF
	GetDefaultClassPath PTR
	Execute PTR
	SetSystemProperties PTR
	SetClassSource PTR
ENDS

// {3EFB1800-C2A1-11cf-960C-0080C7C2BA87}
#DEFINE GUID_CLSID_JavaExecute <0x3efb1800, 0xc2a1, 0x11cf, <0x96, 0xc, 0x0, 0x80, 0xc7, 0xc2, 0xba, 0x87>>
// {3EFB1803-C2A1-11cf-960C-0080C7C2BA87}
#DEFINE GUID_IID_IJavaExecute <0x3efb1803, 0xc2a1, 0x11cf, <0x96, 0xc, 0x0, 0x80, 0xc7, 0xc2, 0xba, 0x87>>
// {D7658820-01DD-11d0-9746-00AA00342BD8}
#DEFINE GUID_IID_IJavaExecute2 <0xd7658820, 0x1dd, 0x11d0, <0x97, 0x46, 0x0, 0xaa, 0x0, 0x34, 0x2b, 0xd8>>
// {56E7DF80-F527-11cf-B728-FC8703C10000}
#DEFINE GUID_IID_IEnumJAVAPROPERTY <0x56e7df80, 0xf527, 0x11cf, <0xb7, 0x28, 0xfc, 0x87, 0x3, 0xc1, 0x0, 0x0>>

#endif
