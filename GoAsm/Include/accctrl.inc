;=============================================================;
;          accctrl.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF ACCCTRL_INC
#Define ACCCTRL_INC

#IFNDEF WTYPES_INC
	#include <wtypes.inc>
#ENDIF

#Define AccFree LocalFree

;TRUSTEE_TYPE enumeration
TRUSTEE_IS_UNKNOWN							Equ 0
TRUSTEE_IS_USER								Equ 1
TRUSTEE_IS_GROUP							Equ 2
TRUSTEE_IS_DOMAIN							Equ 3
TRUSTEE_IS_ALIAS							Equ 4
TRUSTEE_IS_WELL_KNOWN_GROUP					Equ 5
TRUSTEE_IS_DELETED							Equ 6
TRUSTEE_IS_INVALID							Equ 7

;TRUSTEE_FORM enumeration
TRUSTEE_IS_SID								Equ 0
TRUSTEE_IS_NAME								Equ 1
TRUSTEE_BAD_FORM							Equ 2

;MULTIPLE_TRUSTEE_OPERATION enumeration
NO_MULTIPLE_TRUSTEE							Equ 0
TRUSTEE_IS_IMPERSONATE						Equ 1

;ACCESS_MODE enumeration
NOT_USED_ACCESS								Equ 0
GRANT_ACCESS								Equ 1
SET_ACCESS									Equ 2
DENY_ACCESS									Equ 3
REVOKE_ACCESS								Equ 4
SET_AUDIT_SUCCESS							Equ 5
SET_AUDIT_FAILURE							Equ 6

#Define NO_INHERITANCE 						00H
#Define SUB_OBJECTS_ONLY_INHERIT            01H
#Define SUB_CONTAINERS_ONLY_INHERIT         02H
#Define SUB_CONTAINERS_AND_OBJECTS_INHERIT  03H
#Define INHERIT_NO_PROPAGATE                04H
#Define INHERIT_ONLY                        08H

#Define INHERITED_ACCESS_ENTRY              010H

#Define INHERITED_PARENT                    010000000H
#Define INHERITED_GRANDPARENT               020000000H

;SE_OBJECT_TYPE enumeration
SE_UNKNOWN_OBJECT_TYPE						Equ 0
SE_FILE_OBJECT								Equ 1
SE_SERVICE									Equ 2
SE_PRINTER									Equ 3
SE_REGISTRY_KEY								Equ 4
SE_LMSHARE									Equ 5
SE_KERNEL_OBJECT							Equ 6
SE_WINDOW_OBJECT							Equ 7
SE_DS_OBJECT								Equ 8
SE_DS_OBJECT_ALL							Equ 9
SE_PROVIDER_DEFINED_OBJECT					Equ 10

#Define ACCCTRL_DEFAULT_PROVIDERA			"Windows NT Access Provider"
#Define ACCCTRL_DEFAULT_PROVIDERW			L"Windows NT Access Provider"

#Define TRUSTEE_ACCESS_ALLOWED				000000001H
#Define TRUSTEE_ACCESS_READ					000000002H
#Define TRUSTEE_ACCESS_WRITE				000000004H

#Define TRUSTEE_ACCESS_EXPLICIT				000000001H
#Define TRUSTEE_ACCESS_READ_WRITE			(TRUSTEE_ACCESS_READ | TRUSTEE_ACCESS_WRITE)

#Define TRUSTEE_ACCESS_ALL					0FFFFFFFFH

#Define ACTRL_RESERVED						000000000H
#Define ACTRL_PERM_1						000000001H
#Define ACTRL_PERM_2						000000002H
#Define ACTRL_PERM_3						000000004H
#Define ACTRL_PERM_4						000000008H
#Define ACTRL_PERM_5						000000010H
#Define ACTRL_PERM_6						000000020H
#Define ACTRL_PERM_7						000000040H
#Define ACTRL_PERM_8						000000080H
#Define ACTRL_PERM_9						000000100H
#Define ACTRL_PERM_10						000000200H
#Define ACTRL_PERM_11						000000400H
#Define ACTRL_PERM_12						000000800H
#Define ACTRL_PERM_13						000001000H
#Define ACTRL_PERM_14						000002000H
#Define ACTRL_PERM_15						000004000H
#Define ACTRL_PERM_16						000008000H
#Define ACTRL_PERM_17						000010000H
#Define ACTRL_PERM_18						000020000H
#Define ACTRL_PERM_19						000040000H
#Define ACTRL_PERM_20						000080000H

#Define ACTRL_ACCESS_ALLOWED				000000001H
#Define ACTRL_ACCESS_DENIED					000000002H
#Define ACTRL_AUDIT_SUCCESS					000000004H
#Define ACTRL_AUDIT_FAILURE					000000008H

#Define ACTRL_ACCESS_PROTECTED				000000001H

#Define ACTRL_SYSTEM_ACCESS					004000000H
#Define ACTRL_DELETE						008000000H
#Define ACTRL_READ_CONTROL					010000000H
#Define ACTRL_CHANGE_ACCESS					020000000H
#Define ACTRL_CHANGE_OWNER					040000000H
#Define ACTRL_SYNCHRONIZE					080000000H
#Define ACTRL_STD_RIGHTS_ALL				0F8000000H

#Define ACTRL_DS_OPEN						ACTRL_RESERVED
#Define ACTRL_DS_CREATE_CHILD				ACTRL_PERM_1
#Define ACTRL_DS_DELETE_CHILD				ACTRL_PERM_2
#Define ACTRL_DS_LIST						ACTRL_PERM_3
#Define ACTRL_DS_SELF						ACTRL_PERM_4
#Define ACTRL_DS_READ_PROP					ACTRL_PERM_5
#Define ACTRL_DS_WRITE_PROP					ACTRL_PERM_6
#Define ACTRL_FILE_READ						ACTRL_PERM_1
#Define ACTRL_FILE_WRITE					ACTRL_PERM_2
#Define ACTRL_FILE_APPEND					ACTRL_PERM_3
#Define ACTRL_FILE_READ_PROP				ACTRL_PERM_4
#Define ACTRL_FILE_WRITE_PROP				ACTRL_PERM_5
#Define ACTRL_FILE_EXECUTE					ACTRL_PERM_6
#Define ACTRL_FILE_READ_ATTRIB				ACTRL_PERM_7
#Define ACTRL_FILE_WRITE_ATTRIB				ACTRL_PERM_8
#Define ACTRL_DIR_LIST						ACTRL_PERM_1
#Define ACTRL_DIR_CREATE_OBJECT				ACTRL_PERM_2
#Define ACTRL_DIR_CREATE_CHILD				ACTRL_PERM_3
#Define ACTRL_DIR_DELETE_CHILD				ACTRL_PERM_4
#Define ACTRL_DIR_TRAVERSE					ACTRL_PERM_6
#Define ACTRL_KERNEL_TERMINATE				ACTRL_PERM_1
#Define ACTRL_KERNEL_THREAD					ACTRL_PERM_2
#Define ACTRL_KERNEL_VM						ACTRL_PERM_3
#Define ACTRL_KERNEL_VM_READ				ACTRL_PERM_4
#Define ACTRL_KERNEL_VM_WRITE				ACTRL_PERM_5
#Define ACTRL_KERNEL_DUP_HANDLE				ACTRL_PERM_6
#Define ACTRL_KERNEL_PROCESS				ACTRL_PERM_7
#Define ACTRL_KERNEL_SET_INFO				ACTRL_PERM_8
#Define ACTRL_KERNEL_GET_INFO				ACTRL_PERM_9
#Define ACTRL_KERNEL_CONTROL				ACTRL_PERM_10
#Define ACTRL_KERNEL_ALERT					ACTRL_PERM_11
#Define ACTRL_KERNEL_GET_CONTEXT			ACTRL_PERM_12
#Define ACTRL_KERNEL_SET_CONTEXT			ACTRL_PERM_13
#Define ACTRL_KERNEL_TOKEN					ACTRL_PERM_14
#Define ACTRL_KERNEL_IMPERSONATE			ACTRL_PERM_15
#Define ACTRL_KERNEL_DIMPERSONATE			ACTRL_PERM_16
#Define ACTRL_PRINT_SADMIN					ACTRL_PERM_1
#Define ACTRL_PRINT_SLIST					ACTRL_PERM_2
#Define ACTRL_PRINT_PADMIN					ACTRL_PERM_3
#Define ACTRL_PRINT_PUSE					ACTRL_PERM_4
#Define ACTRL_PRINT_JADMIN					ACTRL_PERM_5
#Define ACTRL_SVC_GET_INFO					ACTRL_PERM_1
#Define ACTRL_SVC_SET_INFO					ACTRL_PERM_2
#Define ACTRL_SVC_STATUS					ACTRL_PERM_3
#Define ACTRL_SVC_LIST						ACTRL_PERM_4
#Define ACTRL_SVC_START						ACTRL_PERM_5
#Define ACTRL_SVC_STOP						ACTRL_PERM_6
#Define ACTRL_SVC_PAUSE						ACTRL_PERM_7
#Define ACTRL_SVC_INTERROGATE				ACTRL_PERM_8
#Define ACTRL_SVC_UCONTROL					ACTRL_PERM_9
#Define ACTRL_REG_QUERY						ACTRL_PERM_1
#Define ACTRL_REG_SET						ACTRL_PERM_2
#Define ACTRL_REG_CREATE_CHILD				ACTRL_PERM_3
#Define ACTRL_REG_LIST						ACTRL_PERM_4
#Define ACTRL_REG_NOTIFY					ACTRL_PERM_5
#Define ACTRL_REG_LINK						ACTRL_PERM_6
#Define ACTRL_WIN_CLIPBRD					ACTRL_PERM_1
#Define ACTRL_WIN_GLOBAL_ATOMS				ACTRL_PERM_2
#Define ACTRL_WIN_CREATE					ACTRL_PERM_3
#Define ACTRL_WIN_LIST_DESK					ACTRL_PERM_4
#Define ACTRL_WIN_LIST						ACTRL_PERM_5
#Define ACTRL_WIN_READ_ATTRIBS				ACTRL_PERM_6
#Define ACTRL_WIN_WRITE_ATTRIBS				ACTRL_PERM_7
#Define ACTRL_WIN_SCREEN					ACTRL_PERM_8
#Define ACTRL_WIN_EXIT						ACTRL_PERM_9

#Define ACTRL_ACCESS_NO_OPTIONS					000000000H
#Define ACTRL_ACCESS_SUPPORTS_OBJECT_ENTRIES	000000001H


;Structures
TRUSTEE_A Struct
    pMultipleTrustee DD
    MultipleTrusteeOperation DD
    TrusteeForm DD
    TrusteeType DD
    ptstrName DD
EndS

TRUSTEE_W Struct
    pMultipleTrustee DD
    MultipleTrusteeOperation DD
    TrusteeForm DD
    TrusteeType DD
    ptstrName DD
EndS

EXPLICIT_ACCESS_A Struct
	grfAccessPermissions DD
	grfAccessMode DD
	grfInheritance DD
    Trustee TRUSTEE_A <>
EndS

EXPLICIT_ACCESS_W Struct
	grfAccessPermissions DD
	grfAccessMode DD
	grfInheritance DD
    Trustee TRUSTEE_W <>
EndS

ACTRL_ACCESS_ENTRYA Struct
	Trustee TRUSTEE_A <>
	fAccessFlags DD
	Access DD
	ProvSpecificAccess DD
	Inheritance DD
	lpInheritProperty DD
EndS

ACTRL_ACCESS_ENTRYW Struct
    Trustee TRUSTEE_W <>
	fAccessFlags DD
	Access DD
	ProvSpecificAccess DD
	Inheritance DD
	lpInheritProperty DD
EndS

ACTRL_ACCESS_ENTRY_LISTA Struct
	cEntries DD
	pAccessList DD
EndS

ACTRL_ACCESS_ENTRY_LISTW Struct
	cEntries DD
	pAccessList DD
EndS

ACTRL_PROPERTY_ENTRYA Struct
	lpProperty DD
	pAccessEntryList DD
	fListFlags DD
EndS

ACTRL_PROPERTY_ENTRYW Struct
	lpProperty DD
	pAccessEntryList DD
	fListFlags DD
EndS

ACTRL_ACCESSA Struct
	cEntries DD
	pPropertyAccessList DD
EndS

ACTRL_ACCESSW Struct
	cEntries DD
	pPropertyAccessList DD
EndS

TRUSTEE_ACCESSA Struct
	lpProperty DD
	Access DD
	fAccessFlags DD
	fReturnedAccess DD
EndS

TRUSTEE_ACCESSW Struct
	lpProperty DD
	Access DD
	fAccessFlags DD
	fReturnedAccess DD
EndS

ACTRL_OVERLAPPED Struct
	Reserved1 DD
	Reserved2 DD
	hEvent DD
EndS

ACTRL_ACCESS_INFOA Struct
	fAccessPermission DD
	lpAccessPermissionName DD
EndS

ACTRL_ACCESS_INFOW Struct
	fAccessPermission DD
	lpAccessPermissionName DD
EndS

ACTRL_CONTROL_INFOA Struct
	lpControlId DD
	lpControlName DD
EndS

ACTRL_CONTROL_INFOW Struct
	lpControlId DD
	lpControlName DD
EndS


#IF STRINGS UNICODE
	#Define ACCCTRL_DEFAULT_PROVIDER ACCCTRL_DEFAULT_PROVIDERW
	#Define TRUSTEE TRUSTEE_W
	#Define EXPLICIT_ACCESS EXPLICIT_ACCESS_W
	#Define ACTRL_ACCESS_ENTRY ACTRL_ACCESS_ENTRYW
	#Define ACTRL_ACCESS_ENTRY_LIST ACTRL_ACCESS_ENTRY_LISTW
	#Define ACTRL_PROPERTY_ENTRY ACTRL_PROPERTY_ENTRYW
	#Define ACTRL_ACCESS ACTRL_ACCESSW
	#Define ACTRL_AUDIT ACTRL_AUDITW
	#Define TRUSTEE_ACCESS TRUSTEE_ACCESSW
	#Define ACTRL_ACCESS_INFO ACTRL_ACCESS_INFOW
	#Define ACTRL_CONTROL_INFO ACTRL_CONTROL_INFOW
#ELSE
	#Define ACCCTRL_DEFAULT_PROVIDER ACCCTRL_DEFAULT_PROVIDERA
	#Define TRUSTEE TRUSTEE_A
	#Define EXPLICIT_ACCESS EXPLICIT_ACCESS_A
	#Define ACTRL_ACCESS_ENTRY ACTRL_ACCESS_ENTRYA
	#Define ACTRL_ACCESS_ENTRY_LIST ACTRL_ACCESS_ENTRY_LISTA
	#Define ACTRL_PROPERTY_ENTRY ACTRL_PROPERTY_ENTRYA
	#Define ACTRL_ACCESS ACTRL_ACCESSA
	#Define ACTRL_AUDIT ACTRL_AUDITA
	#Define TRUSTEE_ACCESS TRUSTEE_ACCESSA
	#Define ACTRL_ACCESS_INFO ACTRL_ACCESS_INFOA
	#Define ACTRL_CONTROL_INFO ACTRL_CONTROL_INFOA
#ENDIF

#ENDIF ;ACCCTRL_INC
