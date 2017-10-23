#IFNDEF FUSION_H
#DEFINE FUSION_H

#IFDEF LINKFILES
	#dynamiclinkfile fusion.dll
#ENDIF

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

/* header files for imported files */
#IFNDEF OBJIDL_H
	#include "objidl.h"
#ENDIF

ASM_CACHE_ZAP	= 0x1
ASM_CACHE_GAC	= 0x2
ASM_CACHE_DOWNLOAD	= 0x4
ASM_CACHE_ROOT	= 0x8

peNone	= 0
peMSIL	= 0x1
peI386	= 0x2
peIA64	= 0x3
peAMD64	= 0x4
peInvalid	= 0xffffffff

/* interface IAssemblyCache */
/* [unique][uuid][object][local] */ 

// {8cedc215-ac4b-488b-93c0-a50a49cb2fb8}
#DEFINE GUID_FUSION_REFCOUNT_UNINSTALL_SUBKEY_GUID <0x8cedc215, 0xac4b, 0x488b, <0x93, 0xc0, 0xa5, 0x0a, 0x49, 0xcb, 0x2f, 0xb8>>

// {b02f9d65-fb77-4f7a-afa5-b391309f11c9}
#DEFINE GUID_FUSION_REFCOUNT_FILEPATH_GUID <0xb02f9d65, 0xfb77, 0x4f7a, <0xaf, 0xa5, 0xb3, 0x91, 0x30, 0x9f, 0x11, 0xc9>>

// {2ec93463-b0c3-45e1-8364-327e96aea856}
#DEFINE GUID_FUSION_REFCOUNT_OPAQUE_STRING_GUID <0x2ec93463, 0xb0c3, 0x45e1, <0x83, 0x64, 0x32, 0x7e, 0x96, 0xae, 0xa8, 0x56>>

 // {25df0fc1-7f97-4070-add7-4b13bbfd7cb8} // this GUID cannot be used for installing into GAC.
#DEFINE GUID_FUSION_REFCOUNT_MSI_GUID  <0x25df0fc1, 0x7f97, 0x4070, <0xad, 0xd7, 0x4b, 0x13, 0xbb, 0xfd, 0x7c, 0xb8>>
 // {d16d444c-56d8-11d5-882d-0080c847b195}
#DEFINE GUID_FUSION_REFCOUNT_OSINSTALL_GUID <0xd16d444c, 0x56d8, 0x11d5, <0x88, 0x2d, 0x00, 0x80, 0xc8, 0x47, 0xb1, 0x95>>

FUSION_INSTALL_REFERENCE STRUCT
	cbSize DD
	dwFlags DD
	guidScheme GUID
	szIdentifier PTR
	szNonCannonicalData PTR
ENDS

ASSEMBLY_INFO STRUCT
	cbAssemblyInfo LONG
	dwAssemblyFlags DD
	uliAssemblySizeInKB LARGE_INTEGER
	pszCurrentAssemblyPathBuf PTR
	cchBuf LONG
ENDS

#define IASSEMBLYCACHE_INSTALL_FLAG_REFRESH       0x00000001
#define IASSEMBLYCACHE_INSTALL_FLAG_FORCE_REFRESH 0x00000002
#define IASSEMBLYCACHE_UNINSTALL_DISPOSITION_UNINSTALLED 1
#define IASSEMBLYCACHE_UNINSTALL_DISPOSITION_STILL_IN_USE 2
#define IASSEMBLYCACHE_UNINSTALL_DISPOSITION_ALREADY_UNINSTALLED 3
#define IASSEMBLYCACHE_UNINSTALL_DISPOSITION_DELETE_PENDING 4
#define IASSEMBLYCACHE_UNINSTALL_DISPOSITION_HAS_INSTALL_REFERENCES 5
#define IASSEMBLYCACHE_UNINSTALL_DISPOSITION_REFERENCE_NOT_FOUND 6
#define QUERYASMINFO_FLAG_VALIDATE        0x00000001
#define QUERYASMINFO_FLAG_GETSIZE         0x00000002
#define ASSEMBLYINFO_FLAG_INSTALLED       0x00000001
#define ASSEMBLYINFO_FLAG_PAYLOADRESIDENT 0x00000002

#DEFINE GUID_IID_IAssemblyCache <0xe707dcde,0xd1cd,0x11d2,<0xba,0xb9,0x00,0xc0,0x4f,0x8e,0xce,0xae>>

IAssemblyCache STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UninstallAssembly PTR
	QueryAssemblyInfo PTR
	CreateAssemblyCacheItem PTR
	CreateAssemblyScavenger PTR
	InstallAssembly PTR
ENDS

#define STREAM_FORMAT_COMPLIB_MODULE    0
#define STREAM_FORMAT_COMPLIB_MANIFEST  1
#define STREAM_FORMAT_WIN32_MODULE      2
#define STREAM_FORMAT_WIN32_MANIFEST    4
#define IASSEMBLYCACHEITEM_COMMIT_FLAG_REFRESH       0x00000001
#define IASSEMBLYCACHEITEM_COMMIT_FLAG_FORCE_REFRESH 0x00000002
#define IASSEMBLYCACHEITEM_COMMIT_DISPOSITION_INSTALLED 1
#define IASSEMBLYCACHEITEM_COMMIT_DISPOSITION_REFRESHED 2
#define IASSEMBLYCACHEITEM_COMMIT_DISPOSITION_ALREADY_INSTALLED 3

#DEFINE GUID_IID_IAssemblyCacheItem <0x9e3aaeb4,0xd1cd,0x11d2,<0xba,0xb9,0x00,0xc0,0x4f,0x8e,0xce,0xae>>

IAssemblyCacheItem STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateStream PTR
	Commit PTR
	AbortItem PTR
ENDS

CANOF_PARSE_DISPLAY_NAME	= 0x1
CANOF_SET_DEFAULT_VALUES	= 0x2
CANOF_VERIFY_FRIEND_ASSEMBLYNAME	= 0x4
CANOF_PARSE_FRIEND_DISPLAY_NAME	= CANOF_PARSE_DISPLAY_NAME | CANOF_VERIFY_FRIEND_ASSEMBLYNAME


ASM_NAME_PUBLIC_KEY	= 0
ASM_NAME_PUBLIC_KEY_TOKEN	= 1
ASM_NAME_HASH_VALUE	= 2
ASM_NAME_NAME	= 3
ASM_NAME_MAJOR_VERSION	= 4
ASM_NAME_MINOR_VERSION	= 5
ASM_NAME_BUILD_NUMBER	= 6
ASM_NAME_REVISION_NUMBER	= 7
ASM_NAME_CULTURE	= 8
ASM_NAME_PROCESSOR_ID_ARRAY	= 9
ASM_NAME_OSINFO_ARRAY	= 10
ASM_NAME_HASH_ALGID	= 11
ASM_NAME_ALIAS	= 12
ASM_NAME_CODEBASE_URL	= 13
ASM_NAME_CODEBASE_LASTMOD	= 14
ASM_NAME_NULL_PUBLIC_KEY	= 15
ASM_NAME_NULL_PUBLIC_KEY_TOKEN	= 16
ASM_NAME_CUSTOM	= 17
ASM_NAME_NULL_CUSTOM	= 18
ASM_NAME_MVID	= 19
ASM_NAME_FILE_MAJOR_VERSION	= 20
ASM_NAME_FILE_MINOR_VERSION	= 21
ASM_NAME_FILE_BUILD_NUMBER	= 22
ASM_NAME_FILE_REVISION_NUMBER	= 23
ASM_NAME_RETARGET	= 24
ASM_NAME_SIGNATURE_BLOB	= 25
ASM_NAME_CONFIG_MASK	= 26
ASM_NAME_ARCHITECTURE	= 27
ASM_NAME_MAX_PARAMS	= 28

ASM_DISPLAYF_VERSION	= 0x1
ASM_DISPLAYF_CULTURE	= 0x2
ASM_DISPLAYF_PUBLIC_KEY_TOKEN	= 0x4
ASM_DISPLAYF_PUBLIC_KEY	= 0x8
ASM_DISPLAYF_CUSTOM	= 0x10
ASM_DISPLAYF_PROCESSORARCHITECTURE	= 0x20
ASM_DISPLAYF_LANGUAGEID	= 0x40
ASM_DISPLAYF_RETARGET	= 0x80
ASM_DISPLAYF_CONFIG_MASK	= 0x100
ASM_DISPLAYF_MVID	= 0x200
ASM_DISPLAYF_FULL	= ASM_DISPLAYF_VERSION | ASM_DISPLAYF_CULTURE | ASM_DISPLAYF_PUBLIC_KEY_TOKEN | ASM_DISPLAYF_RETARGET | ASM_DISPLAYF_PROCESSORARCHITECTURE

ASM_CMPF_NAME	= 0x1
ASM_CMPF_MAJOR_VERSION	= 0x2
ASM_CMPF_MINOR_VERSION	= 0x4
ASM_CMPF_BUILD_NUMBER	= 0x8
ASM_CMPF_REVISION_NUMBER	= 0x10
ASM_CMPF_VERSION	= ASM_CMPF_MAJOR_VERSION | ASM_CMPF_MINOR_VERSION | ASM_CMPF_BUILD_NUMBER | ASM_CMPF_REVISION_NUMBER,
ASM_CMPF_PUBLIC_KEY_TOKEN	= 0x20
ASM_CMPF_CULTURE	= 0x40
ASM_CMPF_CUSTOM	= 0x80
ASM_CMPF_DEFAULT	= 0x100
ASM_CMPF_RETARGET	= 0x200
ASM_CMPF_ARCHITECTURE	= 0x400
ASM_CMPF_CONFIG_MASK	= 0x800
ASM_CMPF_MVID	= 0x1000
ASM_CMPF_SIGNATURE	= 0x2000
ASM_CMPF_IL_ALL	= ASM_CMPF_NAME | ASM_CMPF_VERSION | ASM_CMPF_PUBLIC_KEY_TOKEN | ASM_CMPF_CULTURE,
ASM_CMPF_IL_NO_VERSION	= ASM_CMPF_NAME | ASM_CMPF_PUBLIC_KEY_TOKEN | ASM_CMPF_CULTURE


#DEFINE GUID_IID_IAssemblyName <0xCD193BC0,0xB4BC,0x11d2,<0x98,0x33,0x00,0xC0,0x4F,0xC3,0x1D,0x2E>>

IAssemblyName STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetProperty PTR
	GetProperty PTR
	Finalize PTR
	GetDisplayName PTR
	Reserved PTR
	GetName PTR
	GetVersion PTR
	IsEqual PTR
	Clone PTR
ENDS

#DEFINE GUID_IID_IAssemblyEnum <0x21b8916c,0xf28e,0x11d2,<0xa4,0x73,0x00,0xc0,0x4f,0x8e,0xf4,0x48>>

IAssemblyEnum STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetNextAssembly PTR
	Reset PTR
	Clone PTR
ENDS

#DEFINE GUID_IID_IInstallReferenceItem <0x582dac66,0xe678,0x449f,<0xab,0xa6,0x6f,0xaa,0xec,0x8a,0x93,0x94>>

IInstallReferenceItem STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetReference PTR
ENDS

#DEFINE GUID_IID_IInstallReferenceEnum <0x56b1a988,0x7c0c,0x4aa2,<0x86,0x39,0xc3,0xeb,0x5a,0x90,0x22,0x6f>>

IInstallReferenceEnum STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetNextInstallReferenceItem PTR
ENDS

ACR_Unknown	= 0
ACR_EquivalentFullMatch	= 1
ACR_EquivalentWeakNamed	= 2
ACR_EquivalentFXUnified	= 3
ACR_EquivalentUnified	= 4
ACR_NonEquivalentVersion	= 5
ACR_NonEquivalent	= 6
ACR_EquivalentPartialMatch	= 7
ACR_EquivalentPartialWeakNamed	= 8
ACR_EquivalentPartialUnified	= 9
ACR_EquivalentPartialFXUnified	= 10
ACR_NonEquivalentPartialVersion	= 11

#endif


