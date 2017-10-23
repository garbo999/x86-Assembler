#ifndef ACLUI_H
#define ACLUI_H

/* Windows ACLUI.DLL definitions */

#IFDEF LINKFILES
	#dynamiclinkfile ACLUI.dll
#ENDIF

#IFNDEF ACCCTRL_H
	#include "accctrl.h"
#ENDIF

#IFNDEF OBJBASE_H
	#include "objbase.h"
#ENDIF

#IFNDEF COMMCTRL_H
	#include "commctrl.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define SI_EDIT_PERMS  0x00000000
#define SI_EDIT_OWNER  0x00000001
#define SI_EDIT_AUDITS  0x00000002
#define SI_CONTAINER  0x00000004
#define SI_READONLY  0x00000008
#define SI_ADVANCED  0x00000010
#define SI_RESET  0x00000020
#define SI_OWNER_READONLY  0x00000040
#define SI_EDIT_PROPERTIES  0x00000080
#define SI_OWNER_RECURSE  0x00000100
#define SI_NO_ACL_PROTECT  0x00000200
#define SI_NO_TREE_APPLY  0x00000400
#define SI_PAGE_TITLE  0x00000800
#define SI_SERVER_IS_DC  0x00001000
#define SI_RESET_DACL_TREE  0x00004000
#define SI_RESET_SACL_TREE  0x00008000
#define SI_OBJECT_GUID  0x00010000

#define SI_EDIT_EFFECTIVE           0x00020000
#define SI_RESET_DACL               0x00040000
#define SI_RESET_SACL               0x00080000
#define SI_RESET_OWNER              0x00100000
#define SI_NO_ADDITIONAL_PERMISSION 0x00200000
#if WINVER >= NTDDI_VISTA
	#define SI_VIEW_ONLY                0x00400000
	#define SI_PERMS_ELEVATION_REQUIRED 0x01000000
	#define SI_AUDITS_ELEVATION_REQUIRED 0x02000000
	#define SI_OWNER_ELEVATION_REQUIRED 0x04000000
#endif // (WINVER >= NTDDI_VISTA
#define SI_MAY_WRITE                0x10000000 //not sure if user can write permission

#define SI_EDIT_ALL  (SI_EDIT_PERMS|SI_EDIT_OWNER|SI_EDIT_AUDITS)

#define SI_ACCESS_SPECIFIC  0x00010000
#define SI_ACCESS_GENERAL  0x00020000
#define SI_ACCESS_CONTAINER  0x00040000
#define SI_ACCESS_PROPERTY  0x00080000

#define PSPCB_SI_INITDIALOG  (WM_USER+1)

SI_OBJECT_INFO STRUCT
	dwFlags DD
	hInstance HANDLE
	pszServerName PTR
	pszObjectName PTR
	pszPageTitle PTR
	guidObjectType GUID <>
ENDS

SI_ACCESS STRUCT
	pguid PTR
	mask DD
	pszName PTR
	dwFlags DD
ENDS

SI_INHERIT_TYPE STRUCT
	pguid PTR
	dwFlags DD
	pszName PTR
ENDS

SI_PAGE_PERM = 0
SI_PAGE_ADVPERM = 1
SI_PAGE_AUDIT  = 2
SI_PAGE_OWNER  = 3
#if WINVER >= NTDDI_VISTA
	SI_PAGE_TAKEOWNERSHIP = 4
#endif

ISecurityInformation STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetObjectInformation PTR
	GetSecurity PTR
	SetSecurity PTR
	GetAccessRights PTR
	MapGeneric PTR
	GetInheritTypes PTR
	PropertySheetPageCallback PTR
ENDS

ISecurityInformation2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	IsDaclCanonical PTR
	LookupSids PTR
ENDS

SID_INFO STRUCT
	pSid PTR
	pwzCommonName PTR
	pwzClass PTR
	pwzUPN PTR
ENDS

SID_INFO_LIST STRUCT
	cItems DD
	aSidInfo SID_INFO
ENDS

IEffectivePermission STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetEffectivePermission PTR
ENDS

ISecurityObjectTypeInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetInheritSource PTR
ENDS

ISecurityInformation3 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetFullResourceName PTR
	OpenElevatedEditor PTR
ENDS

#Define GUID_IID_ISecurityInformation <0x965fc360,0x16ff,0x11d0,<0x91,0xcb,0x0,0xaa,0x0,0xbb,0xb7,0x23>>
#Define GUID_IID_ISecurityInformation2 <0xc3ccfdb4,0x6f88,0x11d2,<0xa3,0xce,0x0,0xc0,0x4f,0xb1,0x78,0x2a>>
#Define GUID_IID_IEffectivePermission <0x3853DC76,0x9F35,0x407c,<0x88,0xA1,0xD1,0x93,0x44,0x36,0x5F,0xBC>>
#Define GUID_IID_ISecurityObjectTypeInfo <0xFC3066EB,0x79EF,0x444b,<0x91,0x11,0xD1,0x8A,0x75,0xEB,0xF2,0xFA>>
#Define GUID_IID_ISecurityInformation3 <0xe2cdc9cc,0x31bd,0x4f8f,<0x8c,0x8b,0xb6,0x41,0xaf,0x51,0x6a,0x1a>>

#endif
