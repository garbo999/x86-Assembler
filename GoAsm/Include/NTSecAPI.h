/*++ BUILD Version: 0000 Increment this if a change has global effects

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

ntsecapi.h

Abstract:

This module defines the Local Security Authority APIs.

--*/

#ifndef NTSECAPI_H
#define NTSECAPI_H

#IFDEF LINKFILES
	#dynamiclinkfile Secur32.dll
	#dynamiclinkfile Advapi32.dll
#ENDIF

#IFNDEF LSALOOKUP_H
	#include "lsalookup.h"
#ENDIF

#DEFINE GUID_Audit_System_SecurityStateChange <0x0cce9210,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_System_SecuritySubsystemExtension <0x0cce9211,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_System_Integrity <0x0cce9212,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_System_IPSecDriverEvents <0x0cce9213,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_System_Others <0x0cce9214,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_Logon_Logon <0x0cce9215,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_Logon_Logoff <0x0cce9216,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_Logon_AccountLockout <0x0cce9217,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_Logon_IPSecMainMode <0x0cce9218,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_Logon_IPSecQuickMode <0x0cce9219,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_Logon_IPSecUserMode <0x0cce921a,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_Logon_SpecialLogon <0x0cce921b,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_Logon_Others <0x0cce921c,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_ObjectAccess_FileSystem <0x0cce921d,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_ObjectAccess_Registry <0x0cce921e,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_ObjectAccess_Kernel <0x0cce921f,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_ObjectAccess_Sam <0x0cce9220,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_ObjectAccess_CertificationServices <0x0cce9221,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_ObjectAccess_ApplicationGenerated <0x0cce9222,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_ObjectAccess_Handle <0x0cce9223,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_ObjectAccess_Share <0x0cce9224,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_ObjectAccess_FirewallPacketDrops <0x0cce9225,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_ObjectAccess_FirewallConnection <0x0cce9226,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_ObjectAccess_Other <0x0cce9227,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_PrivilegeUse_Sensitive <0x0cce9228,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_PrivilegeUse_NonSensitive <0x0cce9229,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_PrivilegeUse_Others <0x0cce922a,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_DetailedTracking_ProcessCreation <0x0cce922b,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_DetailedTracking_ProcessTermination <0x0cce922c,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_DetailedTracking_DpapiActivity <0x0cce922d,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_DetailedTracking_RpcCall <0x0cce922e,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_PolicyChange_AuditPolicy <0x0cce922f,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_PolicyChange_AuthenticationPolicy <0x0cce9230,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_PolicyChange_AuthorizationPolicy <0x0cce9231,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_PolicyChange_MpsscvRulePolicy <0x0cce9232,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_PolicyChange_WfpIPSecPolicy <0x0cce9233,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_PolicyChange_Others <0x0cce9234,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_AccountManagement_UserAccount <0x0cce9235,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_AccountManagement_ComputerAccount <0x0cce9236,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_AccountManagement_SecurityGroup <0x0cce9237,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_AccountManagement_DistributionGroup <0x0cce9238,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_AccountManagement_ApplicationGroup <0x0cce9239,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_AccountManagement_Others <0x0cce923a,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_DSAccess_DSAccess <0x0cce923b,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_DsAccess_AdAuditChanges <0x0cce923c,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_Ds_Replication <0x0cce923d,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_Ds_DetailedReplication <0x0cce923e,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_AccountLogon_CredentialValidation <0x0cce923f,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_AccountLogon_Kerberos <0x0cce9240,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_AccountLogon_Others <0x0cce9241,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_AccountLogon_KerbCredentialValidation <0x0cce9242,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_Logon_NPS <0x0cce9243,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_ObjectAccess_DetailedFileShare <0x0cce9244,0x69ae, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_System <0x69979848,0x797a, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_Logon <0x69979849,0x797a, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_ObjectAccess <0x6997984a,0x797a, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_PrivilegeUse <0x6997984b,0x797a, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_DetailedTracking <0x6997984c,0x797a, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_PolicyChange <0x6997984d,0x797a, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_AccountManagement <0x6997984e,0x797a, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_DirectoryServiceAccess <0x6997984f,0x797a, 0x11d9, <0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>
#DEFINE GUID_Audit_AccountLogon <0x69979850,0x797a, 0x11d9, 0xbe, 0xd3, 0x50, 0x50, 0x54, 0x50, 0x30, 0x30>>

#define LSA_MODE_PASSWORD_PROTECTED 0x00000001
#define LSA_MODE_INDIVIDUAL_ACCOUNTS 0x00000002
#define LSA_MODE_MANDATORY_ACCESS 0x00000004
#define LSA_MODE_LOG_FULL 0x00000008

UndefinedLogonType = 0
Interactive = 2
Network = 3
Batch = 4
Service = 5
Proxy = 6
Unlock = 7
NetworkCleartext = 8
NewCredentials = 9

#if WINVER >= NTDDI_WINXP
	RemoteInteractive = 10
	CachedInteractive = 11
#endif

#if WINVER >= NTDDI_WS03
	CachedRemoteInteractive = 12
	CachedUnlock = 13
#endif

// enum SE_ADT_PARAMETER_TYPE
#IFNDEF SeAdtParmTypeNone
SeAdtParmTypeNone = 0
SeAdtParmTypeString = 1
SeAdtParmTypeFileSpec = 2
SeAdtParmTypeUlong = 3
SeAdtParmTypeSid = 4
SeAdtParmTypeLogonId = 5
SeAdtParmTypeNoLogonId = 6
SeAdtParmTypeAccessMask = 7
SeAdtParmTypePrivs = 8
SeAdtParmTypeObjectTypes = 9
SeAdtParmTypeHexUlong = 10
SeAdtParmTypePtr = 11
SeAdtParmTypeTime = 12
SeAdtParmTypeGuid = 13
SeAdtParmTypeLuid = 14
SeAdtParmTypeHexInt64 = 15
SeAdtParmTypeStringList = 16
SeAdtParmTypeSidList = 17
SeAdtParmTypeDuration = 18
SeAdtParmTypeUserAccountControl = 19
SeAdtParmTypeNoUac = 20
SeAdtParmTypeMessage = 21
SeAdtParmTypeDateTime = 22
SeAdtParmTypeSockAddr = 23
SeAdtParmTypeSD = 24
SeAdtParmTypeLogonHours = 25
SeAdtParmTypeLogonIdNoSid = 26
SeAdtParmTypeUlongNoConv = 27
SeAdtParmTypeSockAddrNoPort = 28
SeAdtParmTypeAccessReason = 29


#IF WINVER >= NTDDI_WINXP
	SeAdtParmTypeTime = 12
	SeAdtParmTypeGuid = 13
#ENDIF

#IF WINVER >= NTDDI_WS03
	SeAdtParmTypeLuid = 14
	SeAdtParmTypeHexInt64 = 15
	SeAdtParmTypeStringList = 16
	SeAdtParmTypeSidList = 17
	SeAdtParmTypeDuration = 18
	SeAdtParmTypeUserAccountControl = 19
	SeAdtParmTypeNoUac = 20
	SeAdtParmTypeMessage = 21
	SeAdtParmTypeDateTime = 22
	SeAdtParmTypeSockAddr = 23
#ENDIF


#IF WINVER >= NTDDI_WS08
	SeAdtParmTypeSD = 24
	SeAdtParmTypeLogonHours = 25
	SeAdtParmTypeLogonIdNoSid = 26
	SeAdtParmTypeUlongNoConv = 27
	SeAdtParmTypeSockAddrNoPort = 28
	SeAdtParmTypeAccessReason = 29
#ENDIF

#DEFINE SE_ADT_OBJECT_ONLY 0x1

SE_ADT_OBJECT_TYPE STRUCT
	ObjectType GUID
	Flags SHORT
	Level SHORT
	AccessMask ACCESS_MASK
ENDS

SE_ADT_PARAMETER_ARRAY_ENTRY STRUCT
	Type DD
	Length LONG
	Data ULONG_PTR 2 DUP
	Address PTR
ENDS

SE_ADT_ACCESS_REASON STRUCT
	AccessMask ACCESS_MASK
	AccessReasons LONG 32 DUP
	ObjectTypeIndex LONG
	AccessGranted LONG
	SecurityDescriptor PTR
ENDS
//
// Structure that will be passed between the Reference Monitor and LSA
// to transmit auditing information.
//
#define SE_MAX_AUDIT_PARAMETERS 32
#define SE_MAX_GENERIC_AUDIT_PARAMETERS 28

SE_ADT_PARAMETER_ARRAY STRUCT
	CategoryId LONG
	AuditId LONG
	ParameterCount LONG
	Length LONG
	FlatSubCategoryId LONG
	Type LONG
	Flags LONG
	#IFNDEF WIN64
	Parameters DB 16*32 DUP ; SE_ADT_PARAMETER_ARRAY_ENTRY
	#ELSE
	Parameters DB 24*32 DUP ; SE_ADT_PARAMETER_ARRAY_ENTRY
	#ENDIF
ENDS

#define SE_ADT_PARAMETERS_SELF_RELATIVE 0x00000001
#define SE_ADT_PARAMETERS_SEND_TO_LSA 0x00000002
#define SE_ADT_PARAMETER_EXTENSIBLE_AUDIT 0x00000004
#define SE_ADT_PARAMETER_GENERIC_AUDIT 0x00000008
#define SE_ADT_PARAMETER_WRITE_SYNCHRONOUS 0x00000010

#ENDIF

AuditCategorySystem = 0
AuditCategoryLogon = 1
AuditCategoryObjectAccess = 2
AuditCategoryPrivilegeUse = 3
AuditCategoryDetailedTracking = 4
AuditCategoryPolicyChange = 5
AuditCategoryAccountManagement = 6
AuditCategoryDirectoryServiceAccess = 7
AuditCategoryAccountLogon = 8

#define POLICY_AUDIT_EVENT_UNCHANGED 0x00000000
#define POLICY_AUDIT_EVENT_SUCCESS 0x00000001
#define POLICY_AUDIT_EVENT_FAILURE 0x00000002
#define POLICY_AUDIT_EVENT_NONE 0x00000004
#define POLICY_AUDIT_EVENT_MASK 0x00000007

#define LSA_SUCCESS 0

#define POLICY_VIEW_LOCAL_INFORMATION 0x00000001
#define POLICY_VIEW_AUDIT_INFORMATION 0x00000002
#define POLICY_GET_PRIVATE_INFORMATION 0x00000004
#define POLICY_TRUST_ADMIN 0x00000008
#define POLICY_CREATE_ACCOUNT 0x00000010
#define POLICY_CREATE_SECRET 0x00000020
#define POLICY_CREATE_PRIVILEGE 0x00000040
#define POLICY_SET_DEFAULT_QUOTA_LIMITS 0x00000080
#define POLICY_SET_AUDIT_REQUIREMENTS 0x00000100
#define POLICY_AUDIT_LOG_ADMIN 0x00000200
#define POLICY_SERVER_ADMIN 0x00000400
#define POLICY_LOOKUP_NAMES 0x00000800
#define POLICY_NOTIFICATION 0x00001000

#define POLICY_ALL_ACCESS	(STANDARD_RIGHTS_REQUIRED |\
							POLICY_VIEW_LOCAL_INFORMATION|\
							POLICY_VIEW_AUDIT_INFORMATION|\
							POLICY_GET_PRIVATE_INFORMATION |\
							POLICY_TRUST_ADMIN |\
							POLICY_CREATE_ACCOUNT|\
							POLICY_CREATE_SECRET |\
							POLICY_CREATE_PRIVILEGE|\
							POLICY_SET_DEFAULT_QUOTA_LIMITS|\
							POLICY_SET_AUDIT_REQUIREMENTS|\
							POLICY_AUDIT_LOG_ADMIN |\
							POLICY_SERVER_ADMIN|\
							POLICY_LOOKUP_NAMES)


#define POLICY_READ (STANDARD_RIGHTS_READ |\
					POLICY_VIEW_AUDIT_INFORMATION|\
					POLICY_GET_PRIVATE_INFORMATION)

#define POLICY_WRITE	(STANDARD_RIGHTS_WRITE|\
						POLICY_TRUST_ADMIN |\
						POLICY_CREATE_ACCOUNT|\
						POLICY_CREATE_SECRET |\
						POLICY_CREATE_PRIVILEGE|\
						POLICY_SET_DEFAULT_QUOTA_LIMITS|\
						POLICY_SET_AUDIT_REQUIREMENTS|\
						POLICY_AUDIT_LOG_ADMIN |\
						POLICY_SERVER_ADMIN)

#define POLICY_EXECUTE	(STANDARD_RIGHTS_EXECUTE|\
						POLICY_VIEW_LOCAL_INFORMATION|\
						POLICY_LOOKUP_NAMES)

LSA_TRANSLATED_SID STRUCT
	Use DD
	RelativeId LONG
	DomainIndex LONG
ENDS

PolicyServerRoleBackup = 2
PolicyServerRolePrimary = 3

PolicyServerEnabled = 2
PolicyServerDisabled = 3

PolicyAuditLogInformation = 1
PolicyAuditEventsInformation = 2
PolicyPrimaryDomainInformation = 3
PolicyPdAccountInformation = 4
PolicyAccountDomainInformation = 5
PolicyLsaServerRoleInformation = 6
PolicyReplicaSourceInformation = 7
PolicyDefaultQuotaInformation = 8
PolicyModificationInformation = 9
PolicyAuditFullSetInformation = 10
PolicyAuditFullQueryInformation = 11
PolicyDnsDomainInformation = 12
PolicyDnsDomainInformationInt = 13
PolicyLocalAccountDomainInformation = 14
PolicyLastEntry = 15

POLICY_AUDIT_LOG_INFO STRUCT
	AuditLogPercentFull LONG
	MaximumLogSize LONG
	AuditRetentionPeriod LARGE_INTEGER
	AuditLogFullShutdownInProgress BOOLEAN
	TimeToShutdown LARGE_INTEGER
	NextAuditRecordId LONG
ENDS

POLICY_AUDIT_EVENTS_INFO STRUCT
	AuditingMode BOOLEAN
	EventAuditingOptions PTR
	MaximumAuditEventCount LONG
ENDS

POLICY_AUDIT_SUBCATEGORIES_INFO STRUCT
	MaximumSubCategoryCount LONG
	EventAuditingOptions PTR
ENDS

POLICY_AUDIT_CATEGORIES_INFO STRUCT
	MaximumCategoryCount LONG
	SubCategoriesInfo PTR
ENDS

#define PER_USER_POLICY_UNCHANGED 0x00
#define PER_USER_AUDIT_SUCCESS_INCLUDE 0x01
#define PER_USER_AUDIT_SUCCESS_EXCLUDE 0x02
#define PER_USER_AUDIT_FAILURE_INCLUDE 0x04
#define PER_USER_AUDIT_FAILURE_EXCLUDE 0x08
#define PER_USER_AUDIT_NONE 0x10

#define VALID_PER_USER_AUDIT_POLICY_FLAG	(PER_USER_AUDIT_SUCCESS_INCLUDE | \
											PER_USER_AUDIT_SUCCESS_EXCLUDE | \
											PER_USER_AUDIT_FAILURE_INCLUDE | \
											PER_USER_AUDIT_FAILURE_EXCLUDE | \
											PER_USER_AUDIT_NONE)

POLICY_PRIMARY_DOMAIN_INFO STRUCT
	Name LSA_UNICODE_STRING
	Sid PTR
ENDS

POLICY_PD_ACCOUNT_INFO STRUCT
	Name LSA_UNICODE_STRING
ENDS

POLICY_LSA_SERVER_ROLE_INFO STRUCT
	LsaServerRole DD
ENDS

POLICY_REPLICA_SOURCE_INFO STRUCT
	ReplicaSource LSA_UNICODE_STRING
	ReplicaAccountName LSA_UNICODE_STRING
ENDS

POLICY_DEFAULT_QUOTA_INFO STRUCT
	QuotaLimits QUOTA_LIMITS
ENDS

POLICY_MODIFICATION_INFO STRUCT
	ModifiedId LARGE_INTEGER
	DatabaseCreationTime LARGE_INTEGER
ENDS

POLICY_AUDIT_FULL_SET_INFO STRUCT
	ShutDownOnFull BOOLEAN
ENDS

POLICY_AUDIT_FULL_QUERY_INFO STRUCT
	ShutDownOnFull BOOLEAN
	LogIsFull BOOLEAN
ENDS

PolicyDomainQualityOfServiceInformation = 1
PolicyDomainEfsInformation = 2
PolicyDomainKerberosTicketInformation = 3

#define POLICY_QOS_SCHANNEL_REQUIRED 0x00000001
#define POLICY_QOS_OUTBOUND_INTEGRITY 0x00000002
#define POLICY_QOS_OUTBOUND_CONFIDENTIALITY 0x00000004
#define POLICY_QOS_INBOUND_INTEGRITY 0x00000008
#define POLICY_QOS_INBOUND_CONFIDENTIALITY 0x00000010
#define POLICY_QOS_ALLOW_LOCAL_ROOT_CERT_STORE 0x00000020
#define POLICY_QOS_RAS_SERVER_ALLOWED 0x00000040
#define POLICY_QOS_DHCP_SERVER_ALLOWED 0x00000080

#if WINVER = NTDDI_WIN2K
	POLICY_DOMAIN_QUALITY_OF_SERVICE_INFO STRUCT
		QualityOfService LONG
	ENDS
#endif

POLICY_DOMAIN_EFS_INFO STRUCT
	InfoLength LONG
	EfsBlob PTR
ENDS

#define POLICY_KERBEROS_VALIDATE_CLIENT 0x00000080

POLICY_DOMAIN_KERBEROS_TICKET_INFO STRUCT
	AuthenticationOptions LONG
	MaxServiceTicketAge LARGE_INTEGER
	MaxTicketAge LARGE_INTEGER
	MaxRenewAge LARGE_INTEGER
	MaxClockSkew LARGE_INTEGER
	Reserved LARGE_INTEGER
ENDS

PolicyNotifyAuditEventsInformation = 1
PolicyNotifyAccountDomainInformation = 2
PolicyNotifyServerRoleInformation = 3
PolicyNotifyDnsDomainInformation = 4
PolicyNotifyDomainEfsInformation = 5
PolicyNotifyDomainKerberosTicketInformation = 6
PolicyNotifyMachineAccountPasswordInformation = 7
PolicyNotifyGlobalSaclInformation = 8
PolicyNotifyMax = 9

TrustedDomainNameInformation = 1
TrustedControllersInformation = 2
TrustedPosixOffsetInformation = 3
TrustedPasswordInformation = 4
TrustedDomainInformationBasic = 5
TrustedDomainInformationEx = 6
TrustedDomainAuthInformation = 7
TrustedDomainFullInformation = 8
TrustedDomainAuthInformationInternal = 9
TrustedDomainFullInformationInternal = 10
TrustedDomainInformationEx2Internal = 11
TrustedDomainFullInformation2Internal = 12
TrustedDomainSupportedEncryptionTypes = 13

TRUSTED_DOMAIN_NAME_INFO STRUCT
	Name LSA_UNICODE_STRING
ENDS

TRUSTED_CONTROLLERS_INFO STRUCT
	Entries LONG
	Names PTR
ENDS

TRUSTED_POSIX_OFFSET_INFO STRUCT
	Offset LONG
ENDS

TRUSTED_PASSWORD_INFO STRUCT
	Password LSA_UNICODE_STRING
	OldPassword LSA_UNICODE_STRING
ENDS

#define TRUST_DIRECTION_DISABLED 0x00000000
#define TRUST_DIRECTION_INBOUND 0x00000001
#define TRUST_DIRECTION_OUTBOUND 0x00000002
#define TRUST_DIRECTION_BIDIRECTIONAL (TRUST_DIRECTION_INBOUND | TRUST_DIRECTION_OUTBOUND)

#define TRUST_TYPE_DOWNLEVEL 0x00000001
#define TRUST_TYPE_UPLEVEL 0x00000002
#define TRUST_TYPE_MIT 0x00000003

#if WINVER < NTDDI_WS03
	#define TRUST_TYPE_DCE 0x00000004
#endif

#define TRUST_ATTRIBUTE_NON_TRANSITIVE 0x00000001
#define TRUST_ATTRIBUTE_UPLEVEL_ONLY 0x00000002
#if WINVER = NTDDI_WIN2K
	#define TRUST_ATTRIBUTE_TREE_PARENT 0x00400000
	#define TRUST_ATTRIBUTE_TREE_ROOT 0x00800000
	#define TRUST_ATTRIBUTES_VALID 0xFF02FFFF
#endif

#if WINVER < NTDDI_WINXP
	#define TRUST_ATTRIBUTE_FILTER_SIDS 0x00000004
#else
	#define TRUST_ATTRIBUTE_QUARANTINED_DOMAIN 0x00000004
#endif

#if WINVER >= NTDDI_WINXP
	#define TRUST_ATTRIBUTE_FOREST_TRANSITIVE 0x00000008
	#define TRUST_ATTRIBUTES_VALID 0xFF03FFFF
#ENDIF
#if WINVER >= NTDDI_WINXPSP2
	#define TRUST_ATTRIBUTE_CROSS_ORGANIZATION 0x00000010
	#define TRUST_ATTRIBUTE_WITHIN_FOREST 0x00000020
	#define TRUST_ATTRIBUTE_TREAT_AS_EXTERNAL 0x00000040
#ENDIF
#if WINVER >= NTDDI_VISTA
	#define TRUST_ATTRIBUTE_TRUST_USES_RC4_ENCRYPTION 0x00000080
	#define TRUST_ATTRIBUTE_TRUST_USES_AES_KEYS 0x00000100
#endif
#define TRUST_ATTRIBUTES_USER 0xFF000000

TRUSTED_DOMAIN_INFORMATION_EX STRUCT
	Name LSA_UNICODE_STRING
	FlatName LSA_UNICODE_STRING
	Sid PTR
	TrustDirection LONG
	TrustType LONG
	TrustAttributes LONG
ENDS

TRUSTED_DOMAIN_INFORMATION_EX2 STRUCT
	Name LSA_UNICODE_STRING
	FlatName LSA_UNICODE_STRING
	Sid PTR
	TrustDirection LONG
	TrustType LONG
	TrustAttributes LONG
	ForestTrustLength LONG
	ForestTrustInfo PTR
ENDS

#define TRUST_AUTH_TYPE_NONE 0 // Ignore this entry
#define TRUST_AUTH_TYPE_NT4OWF 1 // NT4 OWF password
#define TRUST_AUTH_TYPE_CLEAR 2 // Cleartext password
#define TRUST_AUTH_TYPE_VERSION 3 // Cleartext password version number

LSA_AUTH_INFORMATION STRUCT
	LastUpdateTime LARGE_INTEGER
	AuthType LONG
	AuthInfoLength LONG
	AuthInfo PTR
ENDS

TRUSTED_DOMAIN_AUTH_INFORMATION STRUCT
	IncomingAuthInfos LONG
	IncomingAuthenticationInformation PTR
	IncomingPreviousAuthenticationInformation PTR
	OutgoingAuthInfos LONG
	OutgoingAuthenticationInformation PTR
	OutgoingPreviousAuthenticationInformation PTR
ENDS

TRUSTED_DOMAIN_FULL_INFORMATION STRUCT
	Information TRUSTED_DOMAIN_INFORMATION_EX
	PosixOffset TRUSTED_POSIX_OFFSET_INFO
	AuthInformation TRUSTED_DOMAIN_AUTH_INFORMATION
ENDS

TRUSTED_DOMAIN_FULL_INFORMATION2 STRUCT
	Information TRUSTED_DOMAIN_INFORMATION_EX2
	PosixOffset TRUSTED_POSIX_OFFSET_INFO
	AuthInformation TRUSTED_DOMAIN_AUTH_INFORMATION
ENDS

TRUSTED_DOMAIN_SUPPORTED_ENCRYPTION_TYPES STRUCT
	SupportedEncryptionTypes LONG
ENDS

ForestTrustTopLevelName = 0
ForestTrustTopLevelNameEx = 1
ForestTrustDomainInfo = 2
ForestTrustRecordTypeLast = 2

#if WINVER < NTDDI_WINXPSP2
	#define LSA_FOREST_TRUST_RECORD_TYPE_UNRECOGNIZED 0x80000000
#endif

#define LSA_FTRECORD_DISABLED_REASONS 0x0000FFFF

#define LSA_TLN_DISABLED_NEW 0x00000001
#define LSA_TLN_DISABLED_ADMIN 0x00000002
#define LSA_TLN_DISABLED_CONFLICT 0x00000004

#define LSA_SID_DISABLED_ADMIN 0x00000001
#define LSA_SID_DISABLED_CONFLICT 0x00000002
#define LSA_NB_DISABLED_ADMIN 0x00000004
#define LSA_NB_DISABLED_CONFLICT 0x00000008

LSA_FOREST_TRUST_DOMAIN_INFO STRUCT
	Sid PTR
	DnsName LSA_UNICODE_STRING
	NetbiosName LSA_UNICODE_STRING
ENDS

#if WINVER >= NTDDI_WINXPSP2
	#define MAX_FOREST_TRUST_BINARY_DATA_SIZE 131072
#endif

LSA_FOREST_TRUST_BINARY_DATA STRUCT
	Length LONG
	Buffer PTR
ENDS

LSA_FOREST_TRUST_RECORD STRUCT
	Flags LONG
	ForestTrustType LSA_FOREST_TRUST_RECORD_TYPE
	Time LARGE_INTEGER
	ForestTrustData UNION
		TopLevelName LSA_UNICODE_STRING
		DomainInfo LSA_FOREST_TRUST_DOMAIN_INFO
		Data LSA_FOREST_TRUST_BINARY_DATA
	ENDUNION
ENDS

#if WINVER >= NTDDI_WINXPSP2
	#define MAX_RECORDS_IN_FOREST_TRUST_INFO 4000
#endif

LSA_FOREST_TRUST_INFORMATION STRUCT
	RecordCount LONG
	Entries PTR
ENDS

CollisionTdo = 0
CollisionXref = 1
CollisionOther = 2

LSA_FOREST_TRUST_COLLISION_RECORD STRUCT
	Index LONG
	Type ENUM
	Flags LONG
	Name LSA_UNICODE_STRING
ENDS

LSA_FOREST_TRUST_COLLISION_INFORMATION STRUCT
	RecordCount LONG
	Entries PTR
ENDS

LSA_ENUMERATION_INFORMATION STRUCT
	Sid PTR
ENDS

#if WINVER >= NTDDI_VISTA

LSA_LAST_INTER_LOGON_INFO STRUCT
	LastSuccessfulLogon LARGE_INTEGER
	LastFailedLogon LARGE_INTEGER
	FailedAttemptCountSinceLastSuccessfulLogon LONG
ENDS

#endif

#if WINVER >= NTDDI_WINXP
SECURITY_LOGON_SESSION_DATA STRUCT
	Size LONG
	LogonId LUID
	UserName LSA_UNICODE_STRING
	LogonDomain LSA_UNICODE_STRING
	AuthenticationPackage LSA_UNICODE_STRING
	LogonType LONG
	Session LONG
	Sid PTR
	LogonTime LARGE_INTEGER
	LogonServer LSA_UNICODE_STRING
	DnsDomainName LSA_UNICODE_STRING
	Upn LSA_UNICODE_STRING
	#if WINVER >= NTDDI_VISTA
		UserFlags LONG
		LastLogonInfo LSA_LAST_INTER_LOGON_INFO
		LogonScript LSA_UNICODE_STRING
		ProfilePath LSA_UNICODE_STRING
		HomeDirectory LSA_UNICODE_STRING
		HomeDirectoryDrive LSA_UNICODE_STRING
		LogoffTime LARGE_INTEGER
		KickOffTime LARGE_INTEGER
		PasswordLastSet LARGE_INTEGER
		PasswordCanChange LARGE_INTEGER
		PasswordMustChange LARGE_INTEGER
	#endif
ENDS
#endif

#define SE_INTERACTIVE_LOGON_NAME "SeInteractiveLogonRight"
#define SE_NETWORK_LOGON_NAME "SeNetworkLogonRight"
#define SE_BATCH_LOGON_NAME "SeBatchLogonRight"
#define SE_SERVICE_LOGON_NAME "SeServiceLogonRight"
#define SE_DENY_INTERACTIVE_LOGON_NAME"SeDenyInteractiveLogonRight"
#define SE_DENY_NETWORK_LOGON_NAME"SeDenyNetworkLogonRight"
#define SE_DENY_BATCH_LOGON_NAME"SeDenyBatchLogonRight"
#define SE_DENY_SERVICE_LOGON_NAME"SeDenyServiceLogonRight"
#if WINVER >= NTDDI_WINXP
	#define SE_REMOTE_INTERACTIVE_LOGON_NAME"SeRemoteInteractiveLogonRight"
	#define SE_DENY_REMOTE_INTERACTIVE_LOGON_NAME "SeDenyRemoteInteractiveLogonRight"
#endif

NegEnumPackagePrefixes = 0
NegGetCallerName = 1
NegCallPackageMax = 2

#define NEGOTIATE_MAX_PREFIX32

NEGOTIATE_PACKAGE_PREFIX STRUCT
	PackageId ULONG_PTR
	PackageDataA PTR
	PackageDataW PTR
	PrefixLen ULONG_PTR
	Prefix CHAR NEGOTIATE_MAX_PREFIX DUP
ENDS

NEGOTIATE_PACKAGE_PREFIXES STRUCT
	MessageType LONG
	PrefixCount LONG
	Offset LONG
	#if WINVER >= NTDDI_WINXPSP2
		Pad LONG
	#endif
ENDS

NEGOTIATE_CALLER_NAME_REQUEST STRUCT
	MessageType LONG
	LogonId LUID
ENDS

NEGOTIATE_CALLER_NAME_RESPONSE STRUCT
	MessageType LONG
	CallerName PTR
ENDS

DOMAIN_PASSWORD_INFORMATION STRUCT
	MinPasswordLength SHORT
	PasswordHistoryLength SHORT
	PasswordProperties LONG
	MaxPasswordAge LARGE_INTEGER
	MinPasswordAge LARGE_INTEGER
ENDS

#if WINVER >= NTDDI_WINXP
#define DOMAIN_PASSWORD_COMPLEX 0x00000001
#define DOMAIN_PASSWORD_NO_ANON_CHANGE 0x00000002
#define DOMAIN_PASSWORD_NO_CLEAR_CHANGE 0x00000004
#define DOMAIN_LOCKOUT_ADMINS 0x00000008
#define DOMAIN_PASSWORD_STORE_CLEARTEXT 0x00000010
#define DOMAIN_REFUSE_PASSWORD_CHANGE 0x00000020
#if WINVER >= NTDDI_WINXPSP2
	#define DOMAIN_NO_LM_OWF_CHANGE 0x00000040
#endif
#endif

#define SAM_PASSWORD_CHANGE_NOTIFY_ROUTINE"PasswordChangeNotify"
#define SAM_INIT_NOTIFICATION_ROUTINE"InitializeChangeNotify"
#define SAM_PASSWORD_FILTER_ROUTINE"PasswordFilter"

#define MSV1_0_PACKAGE_NAME "MICROSOFT_AUTHENTICATION_PACKAGE_V1_0"
#define MSV1_0_PACKAGE_NAMEWL"MICROSOFT_AUTHENTICATION_PACKAGE_V1_0"
#define MSV1_0_SUBAUTHENTICATION_KEY "SYSTEM\\CurrentControlSet\\Control\\Lsa\\MSV1_0"
#define MSV1_0_SUBAUTHENTICATION_VALUE "Auth"

MsV1_0InteractiveLogon = 2
MsV1_0Lm20Logon = 3
MsV1_0NetworkLogon = 4
MsV1_0SubAuthLogon = 5
MsV1_0WorkstationUnlockLogon = 7
MsV1_0S4ULogon = 12
MsV1_0VirtualLogon = 82

MsV1_0InteractiveProfile = 2
MsV1_0Lm20LogonProfile = 3
MsV1_0SmartCardProfile = 4

MSV1_0_INTERACTIVE_LOGON STRUCT
	MessageType ENUM
	LogonDomainName UNICODE_STRING
	UserName UNICODE_STRING
	Password UNICODE_STRING
ENDS

MSV1_0_INTERACTIVE_PROFILE STRUCT
	MessageType ENUM
	LogonCount SHORT
	BadPasswordCount SHORT
	LogonTime LARGE_INTEGER
	LogoffTime LARGE_INTEGER
	KickOffTime LARGE_INTEGER
	PasswordLastSet LARGE_INTEGER
	PasswordCanChange LARGE_INTEGER
	PasswordMustChange LARGE_INTEGER
	LogonScript UNICODE_STRING
	HomeDirectory UNICODE_STRING
	FullName UNICODE_STRING
	ProfilePath UNICODE_STRING
	HomeDirectoryDrive UNICODE_STRING
	LogonServer UNICODE_STRING
	UserFlags LONG
ENDS

#define MSV1_0_CHALLENGE_LENGTH 8
#define MSV1_0_USER_SESSION_KEY_LENGTH 16
#define MSV1_0_LANMAN_SESSION_KEY_LENGTH 8

#define MSV1_0_CLEARTEXT_PASSWORD_ALLOWED 0x02
#define MSV1_0_UPDATE_LOGON_STATISTICS 0x04
#define MSV1_0_RETURN_USER_PARAMETERS 0x08
#define MSV1_0_DONT_TRY_GUEST_ACCOUNT 0x10
#define MSV1_0_ALLOW_SERVER_TRUST_ACCOUNT 0x20
#define MSV1_0_RETURN_PASSWORD_EXPIRY 0x40
#define MSV1_0_USE_CLIENT_CHALLENGE 0x80
#define MSV1_0_TRY_GUEST_ACCOUNT_ONLY 0x100
#define MSV1_0_RETURN_PROFILE_PATH 0x200
#define MSV1_0_TRY_SPECIFIED_DOMAIN_ONLY 0x400
#define MSV1_0_ALLOW_WORKSTATION_TRUST_ACCOUNT 0x800

#define MSV1_0_DISABLE_PERSONAL_FALLBACK 0x00001000
#define MSV1_0_ALLOW_FORCE_GUEST 0x00002000

#if WINVER >= NTDDI_WINXPSP2
	#define MSV1_0_CLEARTEXT_PASSWORD_SUPPLIED 0x00004000
	#define MSV1_0_USE_DOMAIN_FOR_ROUTING_ONLY 0x00008000
#endif
#define MSV1_0_SUBAUTHENTICATION_DLL_EX0x00100000
#define MSV1_0_ALLOW_MSVCHAPV2 0x00010000

#if WINVER >= NTDDI_VISTA
	#define MSV1_0_S4U2SELF0x00020000
	#define MSV1_0_CHECK_LOGONHOURS_FOR_S4U 0x00040000
#endif

#define MSV1_0_SUBAUTHENTICATION_DLL 0xFF000000
#define MSV1_0_SUBAUTHENTICATION_DLL_SHIFT 24
#define MSV1_0_MNS_LOGON 0x01000000

#define MSV1_0_SUBAUTHENTICATION_DLL_RAS 2
#define MSV1_0_SUBAUTHENTICATION_DLL_IIS 132

MSV1_0_LM20_LOGON STRUCT
	MessageType ENUM
	LogonDomainName UNICODE_STRING
	UserName UNICODE_STRING
	Workstation UNICODE_STRING
	ChallengeToClient CHAR MSV1_0_CHALLENGE_LENGTH DUP
	CaseSensitiveChallengeResponse STRING
	CaseInsensitiveChallengeResponse STRING
	ParameterControl LONG
ENDS

MSV1_0_SUBAUTH_LOGON STRUCT
	MessageType ENUM
	LogonDomainName UNICODE_STRING
	UserName UNICODE_STRING
	Workstation UNICODE_STRING
	ChallengeToClient CHAR MSV1_0_CHALLENGE_LENGTH DUP
	AuthenticationInfo1 STRING
	AuthenticationInfo2 STRING
	ParameterControl LONG
	SubAuthPackageId LONG
ENDS

#if WINVER >= NTDDI_VISTA

#define MSV1_0_S4U_LOGON_FLAG_CHECK_LOGONHOURS 0x2

MSV1_0_S4U_LOGON STRUCT
	MessageType ENUM
	Flags LONG
	UserPrincipalName UNICODE_STRING
	DomainName UNICODE_STRING
ENDS

#endif 

#define LOGON_GUEST 0x01
#define LOGON_NOENCRYPTION 0x02
#define LOGON_CACHED_ACCOUNT 0x04
#define LOGON_USED_LM_PASSWORD 0x08
#define LOGON_EXTRA_SIDS 0x20
#define LOGON_SUBAUTH_SESSION_KEY 0x40
#define LOGON_SERVER_TRUST_ACCOUNT 0x80
#define LOGON_NTLMV2_ENABLED 0x100 // says DC understands NTLMv2
#define LOGON_RESOURCE_GROUPS 0x200
#define LOGON_PROFILE_PATH_RETURNED 0x400
// Defined in Windows Server 2008 and above
#define LOGON_NT_V2 0x800 // NT response was used for validation
#define LOGON_LM_V2 0x1000// LM response was used for validation
#define LOGON_NTLM_V2 0x2000// LM response was used to authenticate but NT response was used to derive the session key

#if WINVER >= NTDDI_VISTA
	#define LOGON_OPTIMIZED 0x4000// this is an optimized logon
	#define LOGON_WINLOGON 0x8000// the logon session was created for winlogon
	#define LOGON_PKINIT 0x10000// Kerberos PKINIT extension was used to authenticate the user
	#define LOGON_NO_OPTIMIZED 0x20000// optimized logon has been disabled for this account
#endif

#define MSV1_0_SUBAUTHENTICATION_FLAGS 0xFF000000

// Values returned by the MSV1_0_MNS_LOGON SubAuthentication DLL
#define LOGON_GRACE_LOGON 0x01000000

MSV1_0_LM20_LOGON_PROFILE STRUCT
	MessageType ENUM
	KickOffTime LARGE_INTEGER
	LogoffTime LARGE_INTEGER
	UserFlags LONG
	UserSessionKey CHAR MSV1_0_USER_SESSION_KEY_LENGTH DUP
	LogonDomainName UNICODE_STRING
	LanmanSessionKey CHAR MSV1_0_LANMAN_SESSION_KEY_LENGTH DUP
	LogonServer UNICODE_STRING
	UserParameters UNICODE_STRING
ENDS

#define MSV1_0_OWF_PASSWORD_LENGTH 16
#define MSV1_0_CRED_LM_PRESENT 0x1
#define MSV1_0_CRED_NT_PRESENT 0x2
#define MSV1_0_CRED_VERSION 0

MSV1_0_SUPPLEMENTAL_CREDENTIAL STRUCT
	Version LONG
	Flags LONG
	LmPassword CHAR MSV1_0_OWF_PASSWORD_LENGTH DUP
	NtPassword CHAR MSV1_0_OWF_PASSWORD_LENGTH DUP
ENDS

#define MSV1_0_NTLM3_RESPONSE_LENGTH 16
#define MSV1_0_NTLM3_OWF_LENGTH 16

#if WINVER == NTDDI_WIN2K
	#define MSV1_0_MAX_NTLM3_LIFE 1800 // 30 minutes (in seconds)
#else
	#define MSV1_0_MAX_NTLM3_LIFE 129600 // 36 hours (in seconds)
#endif

#define MSV1_0_MAX_AVL_SIZE 64000

#if WINVER >= NTDDI_WINXP
	#define MSV1_0_AV_FLAG_FORCE_GUEST 0x00000001
#endif

#if WINVER >= NTDDI_VISTA
#define MSV1_0_AV_FLAG_MIC_HANDSHAKE_MESSAGES 0x00000002 // the client supports
#endif

MSV1_0_NTLM3_RESPONSE STRUCT
	Response CHAR MSV1_0_NTLM3_RESPONSE_LENGTH DUP
	RespType CHAR
	HiRespType CHAR
	Flags SHORT
	MsgWord LONG
	TimeStamp LONGLONG
	ChallengeFromClient CHAR MSV1_0_CHALLENGE_LENGTH DUP
	AvPairsOff LONG
	Buffer CHAR
ENDS

MsvAvEOL = 0
MsvAvNbComputerName = 1
MsvAvNbDomainName = 2
MsvAvDnsComputerName = 3
MsvAvDnsDomainName = 4
#if WINVER >= NTDDI_WINXP
	MsvAvDnsTreeName = 5
	MsvAvFlags = 6
#ENDIF
#if WINVER >= NTDDI_VISTA
	MsvAvTimestamp = 7
	MsvAvRestrictions = 8
	MsvAvTargetName = 9
	MsvAvChannelBindings = 10
#endif

MSV1_0_AV_PAIR STRUCT
	AvId SHORT
	AvLen SHORT
ENDS

MsV1_0Lm20ChallengeRequest = 0
MsV1_0Lm20GetChallengeResponse = 1
MsV1_0EnumerateUsers = 2
MsV1_0GetUserInfo = 3
MsV1_0ReLogonUsers = 4
MsV1_0ChangePassword = 5
MsV1_0ChangeCachedPassword = 6
MsV1_0GenericPassthrough = 7
MsV1_0CacheLogon = 8
MsV1_0SubAuth = 9
MsV1_0DeriveCredential = 10
MsV1_0CacheLookup = 11
#if WINVER >= NTDDI_WINXP
	MsV1_0SetProcessOption = 12
#endif
#if WINVER >= NTDDI_VISTA
	MsV1_0ConfigLocalAliases = 13
	MsV1_0ClearCachedCredentials = 14
#endif

MSV1_0_CHANGEPASSWORD_REQUEST STRUCT
	MessageType ENUM
	DomainName UNICODE_STRING
	AccountName UNICODE_STRING
	OldPassword UNICODE_STRING
	NewPassword UNICODE_STRING
	Impersonating BOOLEAN
ENDS

MSV1_0_CHANGEPASSWORD_RESPONSE STRUCT
	MessageType ENUM
	PasswordInfoValid BOOLEAN
	DomainPasswordInfo DOMAIN_PASSWORD_INFORMATION
ENDS


#if WINVER >= NTDDI_WINXPSP2
	MSV1_0_PASSTHROUGH_REQUEST STRUCT
		MessageType ENUM
		DomainName UNICODE_STRING
		PackageName UNICODE_STRING
		DataLength LONG
		LogonData PTR
		Pad LONG
	ENDS

	MSV1_0_PASSTHROUGH_RESPONSE STRUCT
		MessageType ENUM
		Pad LONG
		DataLength LONG
		ValidationData PTR
	ENDS
#endif

MSV1_0_SUBAUTH_REQUEST STRUCT
	MessageType ENUM
	SubAuthPackageId LONG
	SubAuthInfoLength LONG
	SubAuthSubmitBuffer PTR
ENDS

MSV1_0_SUBAUTH_RESPONSE STRUCT
	MessageType ENUM
	SubAuthInfoLength LONG
	SubAuthReturnBuffer PTR
ENDS

#IF ADVAPIVER >= WIN32_ADVAPI_510
	#define RtlGenRandom SystemFunction036
	#define RtlEncryptMemory SystemFunction040
	#define RtlDecryptMemory SystemFunction041
#endif

#define RTL_ENCRYPT_MEMORY_SIZE 8
#define RTL_ENCRYPT_OPTION_CROSS_PROCESS 0x01
#define RTL_ENCRYPT_OPTION_SAME_LOGON 0x02

#define KERBEROS_VERSION5
#define KERBEROS_REVISION 6

#define KERB_ETYPE_NULL 0
#define KERB_ETYPE_DES_CBC_CRC 1
#define KERB_ETYPE_DES_CBC_MD4 2
#define KERB_ETYPE_DES_CBC_MD5 3
#define KERB_ETYPE_AES128_CTS_HMAC_SHA1_96 17
#define KERB_ETYPE_AES256_CTS_HMAC_SHA1_96 18

#define KERB_ETYPE_RC4_MD4 -128// FFFFFF80
#define KERB_ETYPE_RC4_PLAIN2 -129
#define KERB_ETYPE_RC4_LM -130
#define KERB_ETYPE_RC4_SHA -131
#define KERB_ETYPE_DES_PLAIN -132
#define KERB_ETYPE_RC4_HMAC_OLD -133// FFFFFF7B
#define KERB_ETYPE_RC4_PLAIN_OLD -134
#define KERB_ETYPE_RC4_HMAC_OLD_EXP -135
#define KERB_ETYPE_RC4_PLAIN_OLD_EXP -136
#define KERB_ETYPE_RC4_PLAIN -140
#define KERB_ETYPE_RC4_PLAIN_EXP -141

#define KERB_ETYPE_AES128_CTS_HMAC_SHA1_96_PLAIN -148
#define KERB_ETYPE_AES256_CTS_HMAC_SHA1_96_PLAIN -149

#define KERB_ETYPE_DSA_SHA1_CMS 9
#define KERB_ETYPE_RSA_MD5_CMS10
#define KERB_ETYPE_RSA_SHA1_CMS 11
#define KERB_ETYPE_RC2_CBC_ENV 12
#define KERB_ETYPE_RSA_ENV 13
#define KERB_ETYPE_RSA_ES_OEAP_ENV 14
#define KERB_ETYPE_DES_EDE3_CBC_ENV 15

#define KERB_ETYPE_DSA_SIGN 8
#define KERB_ETYPE_RSA_PRIV 9
#define KERB_ETYPE_RSA_PUB 10
#define KERB_ETYPE_RSA_PUB_MD5 11
#define KERB_ETYPE_RSA_PUB_SHA1 12
#define KERB_ETYPE_PKCS7_PUB 13

#if WINVER >= NTDDI_WINXPSP2
	#define KERB_ETYPE_DES3_CBC_MD5 5
	#define KERB_ETYPE_DES3_CBC_SHA1 7
	#define KERB_ETYPE_DES3_CBC_SHA1_KD 16
#endif

#define KERB_ETYPE_DES_CBC_MD5_NT 20
#define KERB_ETYPE_RC4_HMAC_NT 23
#define KERB_ETYPE_RC4_HMAC_NT_EXP 24

#define KERB_CHECKSUM_NONE 0
#define KERB_CHECKSUM_CRC32 1
#define KERB_CHECKSUM_MD4 2
#define KERB_CHECKSUM_KRB_DES_MAC 4
#if WINVER >= NTDDI_WINXP
	#define KERB_CHECKSUM_KRB_DES_MAC_K 5
#endif
#define KERB_CHECKSUM_MD5 7
#define KERB_CHECKSUM_MD5_DES 8

#define KERB_CHECKSUM_SHA1_NEW 14 // defined in RFC3961
#define KERB_CHECKSUM_HMAC_SHA1_96_AES128 15
#define KERB_CHECKSUM_HMAC_SHA1_96_AES256 16

#define KERB_CHECKSUM_LM -130
#define KERB_CHECKSUM_SHA1 -131
#define KERB_CHECKSUM_REAL_CRC32 -132
#define KERB_CHECKSUM_DES_MAC -133
#define KERB_CHECKSUM_DES_MAC_MD5 -134
#define KERB_CHECKSUM_MD25 -135
#define KERB_CHECKSUM_RC4_MD5 -136
#define KERB_CHECKSUM_MD5_HMAC -137// used by netlogon
#define KERB_CHECKSUM_HMAC_MD5 -138// used by Kerberos

#define KERB_CHECKSUM_HMAC_SHA1_96_AES128_Ki -150
#define KERB_CHECKSUM_HMAC_SHA1_96_AES256_Ki -151

#define AUTH_REQ_ALLOW_FORWARDABLE 0x00000001
#define AUTH_REQ_ALLOW_PROXIABLE 0x00000002
#define AUTH_REQ_ALLOW_POSTDATE 0x00000004
#define AUTH_REQ_ALLOW_RENEWABLE 0x00000008
#define AUTH_REQ_ALLOW_NOADDRESS 0x00000010
#define AUTH_REQ_ALLOW_ENC_TKT_IN_SKEY 0x00000020
#define AUTH_REQ_ALLOW_VALIDATE 0x00000040
#define AUTH_REQ_VALIDATE_CLIENT 0x00000080
#define AUTH_REQ_OK_AS_DELEGATE 0x00000100
#define AUTH_REQ_PREAUTH_REQUIRED 0x00000200
#define AUTH_REQ_TRANSITIVE_TRUST 0x00000400

#if WINVER >= NTDDI_WINXPSP2
	#define AUTH_REQ_ALLOW_S4U_DELEGATE 0x00000800
#endif

#define AUTH_REQ_PER_USER_FLAGS (AUTH_REQ_ALLOW_FORWARDABLE | AUTH_REQ_ALLOW_PROXIABLE | AUTH_REQ_ALLOW_POSTDATE | AUTH_REQ_ALLOW_RENEWABLE | AUTH_REQ_ALLOW_VALIDATE )

#define KERB_TICKET_FLAGS_reserved 0x80000000
#define KERB_TICKET_FLAGS_forwardable 0x40000000
#define KERB_TICKET_FLAGS_forwarded 0x20000000
#define KERB_TICKET_FLAGS_proxiable 0x10000000
#define KERB_TICKET_FLAGS_proxy 0x08000000
#define KERB_TICKET_FLAGS_may_postdate 0x04000000
#define KERB_TICKET_FLAGS_postdated 0x02000000
#define KERB_TICKET_FLAGS_invalid 0x01000000
#define KERB_TICKET_FLAGS_renewable 0x00800000
#define KERB_TICKET_FLAGS_initial 0x00400000
#define KERB_TICKET_FLAGS_pre_authent 0x00200000
#define KERB_TICKET_FLAGS_hw_authent 0x00100000
#define KERB_TICKET_FLAGS_ok_as_delegate 0x00040000
#define KERB_TICKET_FLAGS_name_canonicalize 0x00010000
#if WINVER >= NTDDI_WINXP
	#define KERB_TICKET_FLAGS_cname_in_pa_data 0x00040000
#endif
#define KERB_TICKET_FLAGS_reserved1 0x00000001

#if WINVER >= NTDDI_WINXP
	#define KRB_NT_UNKNOWN 0 // Name type not known
	#define KRB_NT_PRINCIPAL 1 // Just the name of the principal as in DCE, or for users
	#define KRB_NT_PRINCIPAL_AND_ID -131 // Name of the principal and its SID.
	#define KRB_NT_SRV_INST 2 // Service and other unique instance (krbtgt)
	#define KRB_NT_SRV_INST_AND_ID -132 // SPN and SID
	#define KRB_NT_SRV_HST 3 // Service with host name as instance (telnet, rcommands)
	#define KRB_NT_SRV_XHST 4 // Service with host as remaining components
	#define KRB_NT_UID 5 // Unique ID
	#define KRB_NT_ENTERPRISE_PRINCIPAL 10 // UPN **ONLY**
	#define KRB_NT_ENT_PRINCIPAL_AND_ID -130 // UPN and SID
	#define KRB_NT_MS_PRINCIPAL -128 // NT4 style name
	#define KRB_NT_MS_PRINCIPAL_AND_ID -129 // nt4 style name with sid
	#define KRB_NT_MS_BRANCH_ID -133 // Branch ID
#endif

#if WINVER >= NTDDI_VISTA
#define KRB_NT_X500_PRINCIPAL 6 // Encoded X.500 Distingished name [RFC 2253]
#endif

#ifndef MICROSOFT_KERBEROS_NAME_A
	#define MICROSOFT_KERBEROS_NAME_A "Kerberos"
	#define MICROSOFT_KERBEROS_NAME_W L"Kerberos"
	#ifdef WINVER <= NTDDI_WIN9XALL
		#define MICROSOFT_KERBEROS_NAME MICROSOFT_KERBEROS_NAME_A
	#else
		#define MICROSOFT_KERBEROS_NAME MICROSOFT_KERBEROS_NAME_W
	#endif
#endif

#define KERB_WRAP_NO_ENCRYPT 0x80000001

KerbInteractiveLogon = 2
KerbSmartCardLogon = 6
KerbWorkstationUnlockLogon = 7
KerbSmartCardUnlockLogon = 8
KerbProxyLogon = 9
KerbTicketLogon = 10
KerbTicketUnlockLogon = 11
KerbS4ULogon = 12
#if WINVER >= NTDDI_VISTA
	KerbCertificateLogon = 13
	KerbCertificateS4ULogon = 14
	KerbCertificateUnlockLogon = 15
#endif

KERB_INTERACTIVE_LOGON STRUCT
	MessageType ENUM
	LogonDomainName UNICODE_STRING
	UserName UNICODE_STRING
	Password UNICODE_STRING
ENDS

KERB_INTERACTIVE_UNLOCK_LOGON STRUCT
	Logon KERB_INTERACTIVE_LOGON
	LogonId LUID
ENDS

KERB_SMART_CARD_LOGON STRUCT
	MessageType ENUM
	Pin UNICODE_STRING
	CspDataLength LONG
	CspData PTR
ENDS

KERB_SMART_CARD_UNLOCK_LOGON STRUCT
	Logon KERB_SMART_CARD_LOGON
	LogonId LUID
ENDS

#if WINVER >= NTDDI_VISTA

#define KERB_CERTIFICATE_LOGON_FLAG_CHECK_DUPLICATES 0x1

KERB_CERTIFICATE_LOGON STRUCT
	MessageType ENUM
	DomainName UNICODE_STRING
	UserName UNICODE_STRING
	Pin UNICODE_STRING
	Flags LONG
	CspDataLength LONG
	CspData PTR
ENDS

KERB_CERTIFICATE_UNLOCK_LOGON STRUCT
	Logon KERB_CERTIFICATE_LOGON
	LogonId LUID
ENDS

#define KERB_CERTIFICATE_S4U_LOGON_FLAG_CHECK_DUPLICATES 0x1
#define KERB_CERTIFICATE_S4U_LOGON_FLAG_CHECK_LOGONHOURS 0x2
#define KERB_CERTIFICATE_S4U_LOGON_FLAG_FAIL_IF_NT_AUTH_POLICY_REQUIRED 0x4

KERB_CERTIFICATE_S4U_LOGON STRUCT
	MessageType ENUM
	Flags LONG
	UserPrincipalName UNICODE_STRING
	DomainName UNICODE_STRING
	CertificateLength LONG
	Certificate PTR
ENDS

#endif 

KERB_TICKET_LOGON STRUCT
	MessageType ENUM
	Flags LONG
	ServiceTicketLength LONG
	TicketGrantingTicketLength LONG
	ServiceTicket PTR
	TicketGrantingTicket PTR
ENDS

#define KERB_LOGON_FLAG_ALLOW_EXPIRED_TICKET 0x1

KERB_TICKET_UNLOCK_LOGON STRUCT
	Logon KERB_TICKET_LOGON
	LogonId LUID
ENDS

#if WINVER >= NTDDI_VISTA
	#define KERB_S4U_LOGON_FLAG_CHECK_LOGONHOURS 0x2
#endif

KERB_S4U_LOGON STRUCT
	MessageType ENUM
	Flags LONG
	ClientUpn UNICODE_STRING
	ClientRealm UNICODE_STRING
ENDS

KerbInteractiveProfile = 2
KerbSmartCardProfile = 4
KerbTicketProfile = 6

KERB_INTERACTIVE_PROFILE STRUCT
	MessageType ENUM
	LogonCount SHORT
	BadPasswordCount SHORT
	LogonTime LARGE_INTEGER
	LogoffTime LARGE_INTEGER
	KickOffTime LARGE_INTEGER
	PasswordLastSet LARGE_INTEGER
	PasswordCanChange LARGE_INTEGER
	PasswordMustChange LARGE_INTEGER
	LogonScript UNICODE_STRING
	HomeDirectory UNICODE_STRING
	FullName UNICODE_STRING
	ProfilePath UNICODE_STRING
	HomeDirectoryDrive UNICODE_STRING
	LogonServer UNICODE_STRING
	UserFlags LONG
ENDS

KERB_SMART_CARD_PROFILE STRUCT
	Profile KERB_INTERACTIVE_PROFILE
	CertificateSize LONG
	CertificateData PTR
ENDS

KERB_CRYPTO_KEY STRUCT
	KeyType LONG
	Length LONG
	Value PTR
ENDS

KERB_CRYPTO_KEY32 STRUCT
	KeyType LONG
	Length LONG
	Offset LONG
ENDS

KERB_TICKET_PROFILE STRUCT
	Profile KERB_INTERACTIVE_PROFILE
	SessionKey KERB_CRYPTO_KEY
ENDS

KerbDebugRequestMessage = 0
KerbQueryTicketCacheMessage = 1
KerbChangeMachinePasswordMessage = 2
KerbVerifyPacMessage = 3
KerbRetrieveTicketMessage = 4
KerbUpdateAddressesMessage = 5
KerbPurgeTicketCacheMessage = 6
KerbChangePasswordMessage = 7
KerbRetrieveEncodedTicketMessage = 8
KerbDecryptDataMessage = 9
KerbAddBindingCacheEntryMessage = 10
KerbSetPasswordMessage = 11
KerbSetPasswordExMessage = 12
#if WINVER == NTDDI_WIN2K
	KerbAddExtraCredentialsMessage = 17
#endif
#if WINVER >= NTDDI_WINXP
	KerbVerifyCredentialsMessage = 18
	KerbQueryTicketCacheExMessage = 19
	KerbPurgeTicketCacheExMessage = 20
#endif
#if WINVER >= NTDDI_WINXPSP2
	KerbRefreshSmartcardCredentialsMessage = 21
	KerbAddExtraCredentialsMessage = 22
	KerbQuerySupplementalCredentialsMessage = 23
#endif
#if WINVER >= NTDDI_VISTA
	KerbTransferCredentialsMessage = 24
	KerbQueryTicketCacheEx2Message = 25
	KerbSubmitTicketMessage = 26
	KerbAddExtraCredentialsExMessage = 27
#endif

KERB_QUERY_TKT_CACHE_REQUEST STRUCT
	MessageType ENUM
	LogonId LUID
ENDS


KERB_TICKET_CACHE_INFO STRUCT
	ServerName UNICODE_STRING
	RealmName UNICODE_STRING
	StartTime LARGE_INTEGER
	EndTime LARGE_INTEGER
	RenewTime LARGE_INTEGER
	EncryptionType LONG
	TicketFlags LONG
ENDS


#if WINVER >= NTDDI_WINXP
KERB_TICKET_CACHE_INFO_EX STRUCT
	ClientName UNICODE_STRING
	ClientRealm UNICODE_STRING
	ServerName UNICODE_STRING
	ServerRealm UNICODE_STRING
	StartTime LARGE_INTEGER
	EndTime LARGE_INTEGER
	RenewTime LARGE_INTEGER
	EncryptionType LONG
	TicketFlags LONG
ENDS
#endif

KERB_TICKET_CACHE_INFO_EX2 STRUCT
	ClientName UNICODE_STRING
	ClientRealm UNICODE_STRING
	ServerName UNICODE_STRING
	ServerRealm UNICODE_STRING
	StartTime LARGE_INTEGER
	EndTime LARGE_INTEGER
	RenewTime LARGE_INTEGER
	EncryptionType LONG
	TicketFlags LONG
	SessionKeyType LONG
	BranchId LONG
ENDS

KERB_QUERY_TKT_CACHE_RESPONSE STRUCT
	MessageType ENUM
	CountOfTickets LONG
	Tickets KERB_TICKET_CACHE_INFO
ENDS

#if WINVER >= NTDDI_WINXPSP2
KERB_QUERY_TKT_CACHE_EX_RESPONSE STRUCT
	MessageType ENUM
	CountOfTickets LONG
	Tickets KERB_TICKET_CACHE_INFO_EX
ENDS
#endif

KERB_QUERY_TKT_CACHE_EX2_RESPONSE STRUCT
	MessageType ENUM
	CountOfTickets LONG
	Tickets KERB_TICKET_CACHE_INFO_EX2
ENDS

#ifndef SecHandle
SecHandle STRUCT
	dwLower ULONG_PTR
	dwUpper ULONG_PTR
ENDS
#endif

#if WINVER >= NTDDI_WINXP
	#define KERB_USE_DEFAULT_TICKET_FLAGS 0x0
	#define KERB_RETRIEVE_TICKET_DEFAULT 0x0
#endif
#define KERB_RETRIEVE_TICKET_DONT_USE_CACHE 0x1
#define KERB_RETRIEVE_TICKET_USE_CACHE_ONLY 0x2
#define KERB_RETRIEVE_TICKET_USE_CREDHANDLE 0x4
#if WINVER >= NTDDI_WINXP
#define KERB_RETRIEVE_TICKET_AS_KERB_CRED 0x8
#define KERB_RETRIEVE_TICKET_WITH_SEC_CRED 0x10
#endif
#if WINVER >= NTDDI_VISTA
#define KERB_RETRIEVE_TICKET_CACHE_TICKET 0x20
#endif

#if WINVER >= NTDDI_WIN7
#define KERB_RETRIEVE_TICKET_MAX_LIFETIME 0x40
#endif

#if WINVER >= NTDDI_WINXP

#define KERB_ETYPE_DEFAULT 0x0 // don't specify etype in tkt req.

KERB_AUTH_DATA STRUCT
	Type LONG
	Length LONG
	Data PTR
ENDS

KERB_NET_ADDRESS STRUCT
	Family LONG
	Length LONG
	Address PTR
ENDS

KERB_NET_ADDRESSES STRUCT
	Number LONG
	Addresses KERB_NET_ADDRESS
ENDS

#endif

KERB_EXTERNAL_NAME STRUCT
	NameType SHORT
	NameCount SHORT
	Names UNICODE_STRING
ENDS

KERB_EXTERNAL_TICKET STRUCT
	ServiceName PTR
	TargetName PTR
	ClientName PTR
	DomainName UNICODE_STRING
	TargetDomainName UNICODE_STRING
	AltTargetDomainName UNICODE_STRING
	SessionKey KERB_CRYPTO_KEY
	TicketFlags LONG
	Flags LONG
	KeyExpirationTime LARGE_INTEGER
	StartTime LARGE_INTEGER
	EndTime LARGE_INTEGER
	RenewUntil LARGE_INTEGER
	TimeSkew LARGE_INTEGER
	EncodedTicketSize LONG
	EncodedTicket PTR
ENDS

KERB_RETRIEVE_TKT_REQUEST STRUCT
	MessageType ENUM
	LogonId LUID
	TargetName UNICODE_STRING
	TicketFlags LONG
	CacheOptions LONG
	EncryptionType LONG
	CredentialsHandle SecHandle
ENDS

KERB_RETRIEVE_TKT_RESPONSE STRUCT
	Ticket KERB_EXTERNAL_TICKET
ENDS

//
// Used to purge entries from the ticket cache
//

KERB_PURGE_TKT_CACHE_REQUEST STRUCT
	MessageType ENUM
	LogonId LUID
	ServerName UNICODE_STRING
	RealmName UNICODE_STRING
ENDS

#if WINVER >= NTDDI_WINXP

#define KERB_PURGE_ALL_TICKETS 1

KERB_PURGE_TKT_CACHE_EX_REQUEST STRUCT
	MessageType ENUM
	LogonId LUID
	Flags LONG
	TicketTemplate KERB_TICKET_CACHE_INFO_EX
ENDS

#endif

KERB_SUBMIT_TKT_REQUEST STRUCT
	MessageType ENUM
	LogonId LUID
	Flags LONG
	Key KERB_CRYPTO_KEY32
	KerbCredSize LONG
	KerbCredOffset LONG
ENDS

KERB_CHANGEPASSWORD_REQUEST STRUCT
	MessageType ENUM
	DomainName UNICODE_STRING
	AccountName UNICODE_STRING
	OldPassword UNICODE_STRING
	NewPassword UNICODE_STRING
	Impersonating BOOLEAN
ENDS

KERB_SETPASSWORD_REQUEST STRUCT
	MessageType ENUM
	LogonId LUID
	CredentialsHandle SecHandle
	Flags LONG
	DomainName UNICODE_STRING
	AccountName UNICODE_STRING
	Password UNICODE_STRING
ENDS

KERB_SETPASSWORD_EX_REQUEST STRUCT
	MessageType ENUM
	LogonId LUID
	CredentialsHandle SecHandle
	Flags LONG
	AccountRealm UNICODE_STRING
	AccountName UNICODE_STRING
	Password UNICODE_STRING
	ClientRealm UNICODE_STRING
	ClientName UNICODE_STRING
	Impersonating BOOLEAN
	KdcAddress UNICODE_STRING
	KdcAddressType LONG
ENDS

#define DS_UNKNOWN_ADDRESS_TYPE 0 // anything *but* IP
#define KERB_SETPASS_USE_LOGONID 1
#define KERB_SETPASS_USE_CREDHANDLE 2

KERB_DECRYPT_REQUEST STRUCT
	MessageType ENUM
	LogonId LUID
	Flags LONG
	CryptoType LONG
	KeyUsage LONG
	Key KERB_CRYPTO_KEY
	EncryptedDataSize LONG
	InitialVectorSize LONG
	InitialVector PTR
	EncryptedData PTR
ENDS

#define KERB_DECRYPT_FLAG_DEFAULT_KEY 0x00000001

KERB_DECRYPT_RESPONSESTRUCT
	DecryptedData CHAR
ENDS

KERB_ADD_BINDING_CACHE_ENTRY_REQUEST STRUCT
	MessageType ENUM
	RealmName UNICODE_STRING
	KdcAddress UNICODE_STRING
	AddressType LONG
ENDS

#if WINVER >= NTDDI_WINXPSP2

KERB_REFRESH_SCCRED_REQUEST STRUCT
	MessageType ENUM
	CredentialBlob UNICODE_STRING
	LogonId LUID
	Flags LONG
ENDS

#define KERB_REFRESH_SCCRED_RELEASE 0x0
#define KERB_REFRESH_SCCRED_GETTGT 0x1
#endif

#if WINVER >= NTDDI_WINXP
KERB_ADD_CREDENTIALS_REQUEST STRUCT
	MessageType ENUM
	UserName UNICODE_STRING
	DomainName UNICODE_STRING
	Password UNICODE_STRING
	LogonId LUID
	Flags LONG
ENDS
#define KERB_REQUEST_ADD_CREDENTIAL 1
#define KERB_REQUEST_REPLACE_CREDENTIAL 2
#define KERB_REQUEST_REMOVE_CREDENTIAL 4
#endif

#if WINVER >= NTDDI_VISTA
KERB_ADD_CREDENTIALS_REQUEST_EX STRUCT
	Credentials KERB_ADD_CREDENTIALS_REQUEST
	PrincipalNameCount LONG
	PrincipalNames UNICODE_STRING
ENDS
#endif

KERB_TRANSFER_CRED_REQUEST STRUCT
	MessageType ENUM
	OriginLogonId LUID
	DestinationLogonId LUID
	Flags LONG
ENDS

#define KERB_TRANSFER_CRED_WITH_TICKETS 0x1

POLICY_AUDIT_SID_ARRAY STRUCT
	UsersCount LONG
	UserSidArray PTR
ENDS

AUDIT_POLICY_INFORMATION STRUCT
	AuditSubCategoryGuid GUID
	AuditingInformation LONG
	AuditCategoryGuid GUID
ENDS

#define AUDIT_SET_SYSTEM_POLICY 0x0001
#define AUDIT_QUERY_SYSTEM_POLICY 0x0002
#define AUDIT_SET_USER_POLICY 0x0004
#define AUDIT_QUERY_USER_POLICY 0x0008
#define AUDIT_ENUMERATE_USERS 0x0010
#define AUDIT_SET_MISC_POLICY 0x0020
#define AUDIT_QUERY_MISC_POLICY 0x0040

#define AUDIT_GENERIC_ALL 0x7F
#define AUDIT_GENERIC_READ (STANDARD_RIGHTS_READ | 0x0541)
#define AUDIT_GENERIC_WRITE (STANDARD_RIGHTS_WRITE | 0x0241)
#define AUDIT_GENERIC_EXECUTE STANDARD_RIGHTS_EXECUTE

#ifdef UNICODE
	#define AuditLookupCategoryNameAuditLookupCategoryNameW
	#define AuditLookupSubCategoryNameAuditLookupSubCategoryNameW
	#define AuditSetGlobalSacl AuditSetGlobalSaclW
	#define AuditQueryGlobalSacl AuditQueryGlobalSaclW
#else
	#define AuditLookupCategoryNameAuditLookupCategoryNameA
	#define AuditLookupSubCategoryNameAuditLookupSubCategoryNameA
	#define AuditSetGlobalSacl AuditSetGlobalSaclA
	#define AuditQueryGlobalSacl AuditQueryGlobalSaclA
#endif

#if WINVER >= NTDDI_WIN7
	#define PKU2U_PACKAGE_NAME_A "pku2u"
	#define PKU2U_PACKAGE_NAME L"pku2u"
	#define PKU2U_PACKAGE_NAME_W L"pku2u"
	
	PKU2U_CERT_BLOB STRUCT
		CertOffset LONG 
		CertLength SHORT
	ENDS
	
	#define PKU2U_CREDUI_CONTEXT_VERSION 0x4154414454524543 // "CERTDATA"
	
	PKU2U_CREDUI_CONTEXT STRUCT
		Version DWORD64
		cbHeaderLength SHORT
		cbStructureLength LONG
		CertArrayCount SHORT
		CertArrayOffset LONG
	ENDS
	
	Pku2uCertificateS4ULogon = 14
	
	PKU2U_CERTIFICATE_S4U_LOGON STRUCT
		MessageType ENUM
		Flags LONG
		UserPrincipalName UNICODE_STRING
		DomainName UNICODE_STRING
		CertificateLength LONG
		Certificate PTR
	ENDS
#endif

#endif





