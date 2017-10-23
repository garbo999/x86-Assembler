#ifndef AUTHZ_H
#define AUTHZ_H

/* authorization framework API definitions */

#IFNDEF WINDOWS_H
	#include windows.h
#ENDIF
#IFNDEF ADTGEN_H
	#include adtgen.h
#ENDIF

#define AUTHZ_SKIP_TOKEN_GROUPS  0x2

#define AUTHZ_GENERATE_SUCCESS_AUDIT  0x1
#define AUTHZ_GENERATE_FAILURE_AUDIT  0x2

#define AUTHZ_ACCESS_CHECK_NO_DEEP_COPY_SD  0x00000001

#define AUTHZ_RM_FLAG_NO_AUDIT  0x1

#define AUTHZ_VALID_RM_INIT_FLAGS  AUTHZ_RM_FLAG_NO_AUDIT

#define AUTHZ_NO_SUCCESS_AUDIT  0x00000001
#define AUTHZ_NO_FAILURE_AUDIT  0x00000002
#define AUTHZ_NO_ALLOC_STRINGS  0x00000004

#define AUTHZ_VALID_OBJECT_ACCESS_AUDIT_FLAGS  (AUTHZ_NO_SUCCESS_AUDIT|AUTHZ_NO_FAILURE_AUDIT|AUTHZ_NO_ALLOC_STRINGS)

AUTHZ_ACCESS_REQUEST STRUCT
	DesiredAccess DD
	PrincipalSelfSid PTR
	ObjectTypeList PTR
	ObjectTypeListLength DD
	OptionalArguments PTR
ENDS

AUTHZ_ACCESS_REPLY STRUCT
	ResultListLength DD
	GrantedAccessMask PTR
	SaclEvaluationResults PTR
	Error PTR
ENDS

AuthzContextInfoUserSid = 1
AuthzContextInfoGroupsSids = 2
AuthzContextInfoRestrictedSids = 3
AuthzContextInfoPrivileges = 4 
AuthzContextInfoExpirationTime = 5
AuthzContextInfoServerContext = 6
AuthzContextInfoIdentifier = 7
AuthzContextInfoSource = 8
AuthzContextInfoAll = 9

AuthzAuditEventInfoFlags = 1
AuthzAuditEventInfoOperationType = 2
AuthzAuditEventInfoObjectType = 3
AuthzAuditEventInfoObjectName = 4
AuthzAuditEventInfoAdditionalInfo = 5

#endif /* _AUTHZ_H */
