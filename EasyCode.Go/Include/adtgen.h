#ifndef ADTGEN_H
#define ADTGEN_H

#DEFINE ADTGEN_H_REQVER 100

/* Generic audits generating definitions */

/*
Switches used
None
*/

#define AUDIT_TYPE_LEGACY  1
#define AUDIT_TYPE_WMI  2

APT_None = 1
APT_String = 2
APT_Ulong = 3
APT_Pointer = 4
APT_Sid = 5
APT_LogonId = 6
APT_ObjectTypeList = 7

#define AP_ParamTypeBits  8
#define AP_ParamTypeMask  0x000000ff

#define AP_FormatHex  256
#define AP_AccessMask  512
#define AP_Filespec  256
#define AP_PrimaryLogonId  256
#define AP_ClientLogonId  512

#define APF_AuditFailure  0x00000000
#define APF_AuditSuccess  0x00000001

#define APF_ValidFlags  (APF_AuditSuccess)

AUDIT_OBJECT_TYPE STRUCT
	ObjectType GUID
	Flags DW
	Level DW
	AccessMask DD
ENDS

AUDIT_OBJECT_TYPES STRUCT
	Count DW
	Flags DW
    pObjectTypes PTR
ENDS

AUDIT_PARAM STRUCT
	Type AUDIT_PARAM_TYPE
	Length DD
	Flags DD
    UNION
		Data0 DD
		String DD
		u DD
		psid PTR
		LogonId_LowPart DD
		pObjectTypes PTR
    ENDUNION
    UNION
		Data1 DD
		LogonId_HighPart DD
    ENDUNION
ENDS

AUDIT_PARAMS STRUCT
	Length DD
	Flags DD
	Count DW
	Parameters DD
ENDS

AUTHZ_AUDIT_EVENT_TYPE_LEGACY STRUCT
	CategoryId DW
	AuditId DW
	ParameterCount DW
ENDS

AUTHZ_AUDIT_EVENT_TYPE_OLD STRUCT
	Version DD
	dwFlags DD
	RefCount DD
	hAudit HANDLE
	LinkId LUID
	Legacy UNION
		CategoryId DW
		AuditId DW
		ParameterCount DW
	ENDUNION
ENDS

#endif

