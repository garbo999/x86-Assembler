#ifndef ACCCTRL_H
#define ACCCTRL_H

#IFNDEF WTYPES_H
	#include wtypes.h
#ENDIF

#IFDEF LINKFILES
	#dynamiclinkfile Advapi32.dll
#ENDIF

#define NO_INHERITANCE  0x0
#define SUB_OBJECTS_ONLY_INHERIT  0x1
#define SUB_CONTAINERS_ONLY_INHERIT  0x2
#define SUB_CONTAINERS_AND_OBJECTS_INHERIT  0x3
#define INHERIT_NO_PROPAGATE  0x4
#define INHERIT_ONLY  0x8
#define INHERITED_ACCESS_ENTRY  0x10

#define INHERITED_PARENT  0x10000000
#define INHERITED_GRANDPARENT  0x20000000

#define ACCCTRL_DEFAULT_PROVIDERA  A"Windows NT Access Provider"
#define ACCCTRL_DEFAULT_PROVIDERW  L"Windows NT Access Provider"

#define TRUSTEE_ACCESS_ALLOWED  0x00000001
#define TRUSTEE_ACCESS_READ  0x00000002
#define TRUSTEE_ACCESS_WRITE  0x00000004
#define TRUSTEE_ACCESS_EXPLICIT  0x00000001
#define TRUSTEE_ACCESS_READ_WRITE  TRUSTEE_ACCESS_READ|TRUSTEE_ACCESS_WRITE
#define TRUSTEE_ACCESS_ALL  0xFFFFFFFF

#define ACTRL_RESERVED  0x00000000
#define ACTRL_PERM_1  0x00000001
#define ACTRL_PERM_2  0x00000002
#define ACTRL_PERM_3  0x00000004
#define ACTRL_PERM_4  0x00000008
#define ACTRL_PERM_5  0x00000010
#define ACTRL_PERM_6  0x00000020
#define ACTRL_PERM_7  0x00000040
#define ACTRL_PERM_8  0x00000080
#define ACTRL_PERM_9  0x00000100
#define ACTRL_PERM_10  0x00000200
#define ACTRL_PERM_11  0x00000400
#define ACTRL_PERM_12  0x00000800
#define ACTRL_PERM_13  0x00001000
#define ACTRL_PERM_14  0x00002000
#define ACTRL_PERM_15  0x00004000
#define ACTRL_PERM_16  0x00008000
#define ACTRL_PERM_17  0x00010000
#define ACTRL_PERM_18  0x00020000
#define ACTRL_PERM_19  0x00040000
#define ACTRL_PERM_20  0x00080000

#define ACTRL_ACCESS_ALLOWED  0x00000001
#define ACTRL_ACCESS_DENIED  0x00000002
#define ACTRL_AUDIT_SUCCESS  0x00000004
#define ACTRL_AUDIT_FAILURE  0x00000008

#define ACTRL_ACCESS_PROTECTED  0x00000001

#define ACTRL_SYSTEM_ACCESS  0x04000000
#define ACTRL_DELETE  0x08000000
#define ACTRL_READ_CONTROL  0x10000000
#define ACTRL_CHANGE_ACCESS  0x20000000
#define ACTRL_CHANGE_OWNER  0x40000000
#define ACTRL_SYNCHRONIZE  0x80000000
#define ACTRL_STD_RIGHTS_ALL  0xf8000000
#define ACTRL_STD_RIGHT_REQUIRED  ACTRL_STD_RIGHTS_ALL & !(ACTRL_SYNCHRONIZE)

#IFNDEF _DS_CONTROL_BITS_DEFINED_
	#define _DS_CONTROL_BITS_DEFINED_
	#define ACTRL_DS_OPEN  ACTRL_RESERVED
	#define ACTRL_DS_CREATE_CHILD  ACTRL_PERM_1
	#define ACTRL_DS_DELETE_CHILD  ACTRL_PERM_2
	#define ACTRL_DS_LIST  ACTRL_PERM_3
	#define ACTRL_DS_SELF  ACTRL_PERM_4
	#define ACTRL_DS_READ_PROP  ACTRL_PERM_5
	#define ACTRL_DS_WRITE_PROP  ACTRL_PERM_6
	#define ACTRL_DS_DELETE_TREE  ACTRL_PERM_7
	#define ACTRL_DS_LIST_OBJECT  ACTRL_PERM_8
	#define ACTRL_DS_CONTROL_ACCESS  ACTRL_PERM_9
#ENDIF

#define ACTRL_FILE_READ  ACTRL_PERM_1
#define ACTRL_FILE_WRITE  ACTRL_PERM_2
#define ACTRL_FILE_APPEND  ACTRL_PERM_3
#define ACTRL_FILE_READ_PROP  ACTRL_PERM_4
#define ACTRL_FILE_WRITE_PROP  ACTRL_PERM_5
#define ACTRL_FILE_EXECUTE  ACTRL_PERM_6
#define ACTRL_FILE_READ_ATTRIB  ACTRL_PERM_8
#define ACTRL_FILE_WRITE_ATTRIB  ACTRL_PERM_9
#define ACTRL_FILE_CREATE_PIPE  ACTRL_PERM_10
#define ACTRL_DIR_LIST  ACTRL_PERM_1
#define ACTRL_DIR_CREATE_OBJECT  ACTRL_PERM_2
#define ACTRL_DIR_CREATE_CHILD  ACTRL_PERM_3
#define ACTRL_DIR_DELETE_CHILD  ACTRL_PERM_7
#define ACTRL_DIR_TRAVERSE  ACTRL_PERM_6
#define ACTRL_KERNEL_TERMINATE  ACTRL_PERM_1
#define ACTRL_KERNEL_THREAD  ACTRL_PERM_2
#define ACTRL_KERNEL_VM  ACTRL_PERM_3
#define ACTRL_KERNEL_VM_READ  ACTRL_PERM_4
#define ACTRL_KERNEL_VM_WRITE  ACTRL_PERM_5
#define ACTRL_KERNEL_DUP_HANDLE  ACTRL_PERM_6
#define ACTRL_KERNEL_PROCESS  ACTRL_PERM_7
#define ACTRL_KERNEL_SET_INFO  ACTRL_PERM_8
#define ACTRL_KERNEL_GET_INFO  ACTRL_PERM_9
#define ACTRL_KERNEL_CONTROL  ACTRL_PERM_10
#define ACTRL_KERNEL_ALERT  ACTRL_PERM_11
#define ACTRL_KERNEL_GET_CONTEXT  ACTRL_PERM_12
#define ACTRL_KERNEL_SET_CONTEXT  ACTRL_PERM_13
#define ACTRL_KERNEL_TOKEN  ACTRL_PERM_14
#define ACTRL_KERNEL_IMPERSONATE  ACTRL_PERM_15
#define ACTRL_KERNEL_DIMPERSONATE  ACTRL_PERM_16
#define ACTRL_PRINT_SADMIN  ACTRL_PERM_1
#define ACTRL_PRINT_SLIST  ACTRL_PERM_2
#define ACTRL_PRINT_PADMIN  ACTRL_PERM_3
#define ACTRL_PRINT_PUSE  ACTRL_PERM_4
#define ACTRL_PRINT_JADMIN  ACTRL_PERM_5
#define ACTRL_SVC_GET_INFO  ACTRL_PERM_1
#define ACTRL_SVC_SET_INFO  ACTRL_PERM_2
#define ACTRL_SVC_STATUS  ACTRL_PERM_3
#define ACTRL_SVC_LIST  ACTRL_PERM_4
#define ACTRL_SVC_START  ACTRL_PERM_5
#define ACTRL_SVC_STOP  ACTRL_PERM_6
#define ACTRL_SVC_PAUSE  ACTRL_PERM_7
#define ACTRL_SVC_INTERROGATE  ACTRL_PERM_8
#define ACTRL_SVC_UCONTROL  ACTRL_PERM_9
#define ACTRL_REG_QUERY  ACTRL_PERM_1
#define ACTRL_REG_SET  ACTRL_PERM_2
#define ACTRL_REG_CREATE_CHILD  ACTRL_PERM_3
#define ACTRL_REG_LIST  ACTRL_PERM_4
#define ACTRL_REG_NOTIFY  ACTRL_PERM_5
#define ACTRL_REG_LINK  ACTRL_PERM_6
#define ACTRL_WIN_CLIPBRD  ACTRL_PERM_1
#define ACTRL_WIN_GLOBAL_ATOMS  ACTRL_PERM_2
#define ACTRL_WIN_CREATE  ACTRL_PERM_3
#define ACTRL_WIN_LIST_DESK  ACTRL_PERM_4
#define ACTRL_WIN_LIST  ACTRL_PERM_5
#define ACTRL_WIN_READ_ATTRIBS  ACTRL_PERM_6
#define ACTRL_WIN_WRITE_ATTRIBS  ACTRL_PERM_7
#define ACTRL_WIN_SCREEN  ACTRL_PERM_8
#define ACTRL_WIN_EXIT  ACTRL_PERM_9

#define ACTRL_ACCESS_NO_OPTIONS  0x00000000
#define ACTRL_ACCESS_SUPPORTS_OBJECT_ENTRIES  0x00000001

#if WINVER >= NTDDI_VISTA
	#define TREE_SEC_INFO_SET                   0x00000001
	#define TREE_SEC_INFO_RESET                 0x00000002
	#define TREE_SEC_INFO_RESET_KEEP_EXPLICIT   0x00000003
#endif

// enum PROG_INVOKE_SETTING
ProgressInvokeNever = 1        // Never invoke the progress function
ProgressInvokeEveryObject = 2  // Invoke for each object
ProgressInvokeOnError = 3      // Invoke only for each error case
ProgressCancelOperation = 4    // Stop propagation and return
ProgressRetryOperation = 5     // Retry operation on subtree
#if WINVER >= NTDDI_VISTA
    ProgressInvokePrePostError = 6 // Invoke Pre, Post, Error
#endif

FN_OBJECT_MGR_FUNCTIONS STRUCT
	Placeholder DD
ENDS

INHERITED_FROMA STRUCT
	GenerationGap LONG
	AncestorName PTR
ENDS

INHERITED_FROMW STRUCT
	GenerationGap LONG
	AncestorName PTR
ENDS

// enum SE_OBJECT_TYPE
SE_UNKNOWN_OBJECT_TYPE = 0
SE_FILE_OBJECT = 1
SE_SERVICE = 2
SE_PRINTER = 3
SE_REGISTRY_KEY = 4
SE_LMSHARE = 5
SE_KERNEL_OBJECT = 6
SE_WINDOW_OBJECT = 7
SE_DS_OBJECT = 8
SE_DS_OBJECT_ALL = 9
SE_PROVIDER_DEFINED_OBJECT = 10
SE_WMIGUID_OBJECT = 11
SE_REGISTRY_WOW64_32KEY = 12

// enum TRUSTEE_TYPE
TRUSTEE_IS_UNKNOWN = 0
TRUSTEE_IS_USER = 1
TRUSTEE_IS_GROUP = 2
TRUSTEE_IS_DOMAIN = 3
TRUSTEE_IS_ALIAS = 4
TRUSTEE_IS_WELL_KNOWN_GROUP = 5
TRUSTEE_IS_DELETED = 6
TRUSTEE_IS_INVALID = 7
TRUSTEE_IS_COMPUTER = 8

// enum TRUSTEE_FORM
TRUSTEE_IS_SID = 0
TRUSTEE_IS_NAME = 1
TRUSTEE_BAD_FORM = 2
TRUSTEE_IS_OBJECTS_AND_SID = 3
TRUSTEE_IS_OBJECTS_AND_NAME = 4

// enum MULTIPLE_TRUSTEE_OPERATION
NO_MULTIPLE_TRUSTEE = 0
TRUSTEE_IS_IMPERSONATE = 1

OBJECTS_AND_SID STRUCT
	ObjectsPresent DD
	ObjectTypeGuid GUID
	InheritedObjectTypeGuid GUID
	pSid PTR
ENDS

OBJECTS_AND_NAME_A STRUCT
	ObjectsPresent DD
	ObjectType ENUM
	ObjectTypeName PTR
	InheritedObjectTypeName PTR
	ptstrName PTR
ENDS

OBJECTS_AND_NAME_W STRUCT
	ObjectsPresent DD
	ObjectType ENUM
	ObjectTypeName PTR
	InheritedObjectTypeName PTR
	ptstrName PTR
ENDS

TRUSTEE_A STRUCT
	pMultipleTrustee PTR
	MultipleTrusteeOperation ENUM
	TrusteeForm DD
	TrusteeType DD
	ptstrName PTR
ENDS

TRUSTEE_W STRUCT
	pMultipleTrustee PTR
	MultipleTrusteeOperation ENUM
	TrusteeForm DD
	TrusteeType DD
	ptstrName PTR
ENDS

EXPLICIT_ACCESS_A STRUCT
	grfAccessPermissions DD
	grfAccessMode DD
	grfInheritance DD
	Trustee TRUSTEE_A
ENDS

EXPLICIT_ACCESS_W STRUCT
	grfAccessPermissions DD
	grfAccessMode DD
	grfInheritance DD
	Trustee TRUSTEE_W
ENDS

// enum ACCESS_MODE
NOT_USED_ACCESS = 0
GRANT_ACCESS = 1
SET_ACCESS = 2
DENY_ACCESS = 3
REVOKE_ACCESS = 4
SET_AUDIT_SUCCESS = 5
SET_AUDIT_FAILURE = 6

EXPLICIT_ACCESSA STRUCT
	grfAccessPermissions DD
	grfAccessMode DD
	grfInheritance DD
	Trustee TRUSTEE_A
ENDS

EXPLICIT_ACCESSW STRUCT
	grfAccessPermissions DD
	grfAccessMode DD
	grfInheritance DD
	Trustee TRUSTEE_W
ENDS

ACTRL_ACCESS_ENTRYA STRUCT
	Trustee TRUSTEE_A
	fAccessFlags DD
	Access DD
	ProvSpecificAccess DD
	Inheritance DD
	lpInheritProperty PTR
ENDS

ACTRL_ACCESS_ENTRYW STRUCT
    Trustee TRUSTEE_W
	fAccessFlags DD
	Access DD
	ProvSpecificAccess DD
	Inheritance DD
	lpInheritProperty PTR
ENDS

ACTRL_ACCESS_ENTRY_LISTA STRUCT
	cEntries DD
	pAccessList PTR
ENDS

ACTRL_ACCESS_ENTRY_LISTW STRUCT
	cEntries DD
	pAccessList PTR
ENDS

ACTRL_PROPERTY_ENTRYA STRUCT
	lpProperty PTR
	pAccessEntryList PTR
	fListFlags DD
ENDS

ACTRL_PROPERTY_ENTRYW STRUCT
	lpProperty PTR
	pAccessEntryList PTR
	fListFlags DD
ENDS

ACTRL_ALISTA STRUCT
	cEntries DD
	pPropertyAccessList PTR
ENDS

ACTRL_ALISTW STRUCT
	cEntries DD
	pPropertyAccessList PTR
ENDS

TRUSTEE_ACCESSA STRUCT
	lpProperty PTR
	Access DD
	fAccessFlags DD
	fReturnedAccess DD
ENDS

TRUSTEE_ACCESSW STRUCT
	lpProperty PTR
	Access DD
	fAccessFlags DD
	fReturnedAccess DD
ENDS

ACTRL_OVERLAPPED STRUCT
    UNION
		Provider PTR
		Reserved1 DD
    ENDUNION
	Reserved2 DD
	hEvent HANDLE
ENDS

ACTRL_ACCESS_INFOA STRUCT
	fAccessPermission DD
	lpAccessPermissionName PTR
ENDS

ACTRL_ACCESS_INFOW STRUCT
	fAccessPermission DD
	lpAccessPermissionName PTR
ENDS

ACTRL_CONTROL_INFOA STRUCT
	lpControlId PTR
	lpControlName PTR
ENDS

ACTRL_CONTROL_INFOW STRUCT
	lpControlId PTR
	lpControlName PTR
ENDS

ACTRL_AUDITA STRUCT
	cEntries DD
	pPropertyAccessList PTR
ENDS

ACTRL_AUDITA STRUCT
	cEntries DD
	pPropertyAccessList PTR
ENDS

#ifdef UNICODE
	#define OBJECTS_AND_NAME OBJECTS_AND_NAME_W
	#define TRUSTEE TRUSTEE_W
	#define EXPLICIT_ACCESS EXPLICIT_ACCESSW
	#define ACTRL_ACCESS_ENTRY ACTRL_ACCESS_ENTRYW
	#define ACTRL_ACCESS_ENTRY_LIST ACTRL_ACCESS_ENTRY_LISTW
	#define ACTRL_PROPERTY_ENTRY ACTRL_PROPERTY_ENTRYW
	#define ACTRL_ACCESS ACTRL_ACCESSW
	#define ACTRL_AUDIT ACTRL_AUDITW
	#define TRUSTEE_ACCESS TRUSTEE_ACCESSW
	#define ACTRL_ACCESS_INFO ACTRL_ACCESS_INFOW
	#define ACTRL_CONTROL_INFO ACTRL_CONTROL_INFOW
	#define ACCCTRL_DEFAULT_PROVIDER ACCCTRL_DEFAULT_PROVIDERW
#ELSE
	#define OBJECTS_AND_NAME OBJECTS_AND_NAME_A
	#define TRUSTEE TRUSTEE_A
	#define EXPLICIT_ACCESS EXPLICIT_ACCESSA
	#define ACTRL_ACCESS_ENTRY ACTRL_ACCESS_ENTRYA
	#define ACTRL_ACCESS_ENTRY_LIST ACTRL_ACCESS_ENTRY_LISTA
	#define ACTRL_PROPERTY_ENTRY ACTRL_PROPERTY_ENTRYA
	#define ACTRL_ACCESS ACTRL_ACCESSA
	#define ACTRL_AUDIT ACTRL_AUDITA
	#define TRUSTEE_ACCESS TRUSTEE_ACCESSA
	#define ACTRL_ACCESS_INFO ACTRL_ACCESS_INFOA
	#define ACTRL_CONTROL_INFO ACTRL_CONTROL_INFOA
	#define ACCCTRL_DEFAULT_PROVIDER ACCCTRL_DEFAULT_PROVIDERA
#ENDIF

#ENDIF // ACCCTRL_H

