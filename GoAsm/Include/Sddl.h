/*++

Copyright (c) 1997-1998  Microsoft Corporation

Module Name:

 sddl.w

Abstract:

 This module defines the support and conversions routines necessary for SDDL.

Revision History:

--*/

#ifndef SDDL_H
#define SDDL_H

#IFDEF LINKFILES
	#dynamiclinkfile Advapi32.dll
#ENDIF

//
// SDDL Version information
//
#define SDDL_REVISION_1 1
#define SDDL_REVISION SDDL_REVISION_1

//
// SDDL Component tags
//
#define SDDL_OWNER  "O" // Owner tag
#define SDDL_GROUP  "G" // Group tag
#define SDDL_DACL "D" // DACL tag
#define SDDL_SACL "S" // SACL tag

//
// SDDL Security descriptor controls
//
#define SDDL_PROTECTED  "P" // DACL or SACL Protected
#define SDDL_AUTO_INHERIT_REQ "AR"  // Auto inherit request
#define SDDL_AUTO_INHERITED "AI"  // DACL/SACL are auto inherited
#define SDDL_NULL_ACL "NO_ACCESS_CONTROL" // Null ACL

//
// SDDL Ace types
//
#define SDDL_ACCESS_ALLOWED "A" // Access allowed
#define SDDL_ACCESS_DENIED  "D" // Access denied
#define SDDL_OBJECT_ACCESS_ALLOWED  "OA"  // Object access allowed
#define SDDL_OBJECT_ACCESS_DENIED "OD"  // Object access denied
#define SDDL_AUDIT  "AU"  // Audit
#define SDDL_ALARM  "AL"  // Alarm
#define SDDL_OBJECT_AUDIT "OU"  // Object audit
#define SDDL_OBJECT_ALARM "OL"  // Object alarm
#define SDDL_MANDATORY_LABEL "ML"  // Integrity label
#define SDDL_CALLBACK_ACCESS_ALLOWED "XA" // callback Access allowed
#define SDDL_CALLBACK_ACCESS_DENIED  "XD" // callback Access denied

//
// SDDL Ace flags
//
#define SDDL_CONTAINER_INHERIT  "CI" //  Container inherit
#define SDDL_OBJECT_INHERIT "OI" //  Object inherit
#define SDDL_NO_PROPAGATE "NP" //  Inherit no propagate
#define SDDL_INHERIT_ONLY "IO" //  Inherit only
#define SDDL_INHERITED  "ID" //  Inherited
#define SDDL_AUDIT_SUCCESS  "SA" //  Audit success
#define SDDL_AUDIT_FAILURE  "FA" //  Audit failure


//
// SDDL Rights
//
#define SDDL_READ_PROPERTY  "RP"
#define SDDL_WRITE_PROPERTY "WP"
#define SDDL_CREATE_CHILD "CC"
#define SDDL_DELETE_CHILD "DC"
#define SDDL_LIST_CHILDREN  "LC"
#define SDDL_SELF_WRITE "SW"
#define SDDL_LIST_OBJECT "LO"
#define SDDL_DELETE_TREE "DT"
#define SDDL_CONTROL_ACCESS "CR"
#define SDDL_READ_CONTROL "RC"
#define SDDL_WRITE_DAC  "WD"
#define SDDL_WRITE_OWNER "WO"
#define SDDL_STANDARD_DELETE "SD"
#define SDDL_GENERIC_ALL "GA"
#define SDDL_GENERIC_READ "GR"
#define SDDL_GENERIC_WRITE  "GW"
#define SDDL_GENERIC_EXECUTE "GX"
#define SDDL_FILE_ALL "FA"
#define SDDL_FILE_READ  "FR"
#define SDDL_FILE_WRITE "FW"
#define SDDL_FILE_EXECUTE "FX"
#define SDDL_KEY_ALL "KA"
#define SDDL_KEY_READ "KR"
#define SDDL_KEY_WRITE  "KW"
#define SDDL_KEY_EXECUTE "KX"
#define SDDL_NO_WRITE_UP "NW"
#define SDDL_NO_READ_UP "NR"
#define SDDL_NO_EXECUTE_UP  "NX"


//
// SDDL User alias max size
//  - currently, upto two supported eg. "DA"
//  - modify this if more WCHARs need to be there in future e.g. "DAX"
//

#define SDDL_ALIAS_SIZE 2

//
// SDDL User aliases
//
#define SDDL_DOMAIN_ADMINISTRATORS  "DA"  // Domain admins
#define SDDL_DOMAIN_GUESTS  "DG"  // Domain guests
#define SDDL_DOMAIN_USERS "DU"  // Domain users
#define SDDL_ENTERPRISE_DOMAIN_CONTROLLERS  "ED"  // Enterprise domain controllers
#define SDDL_DOMAIN_DOMAIN_CONTROLLERS  "DD"  // Domain domain controllers
#define SDDL_DOMAIN_COMPUTERS "DC"  // Domain computers
#define SDDL_BUILTIN_ADMINISTRATORS "BA"  // Builtin (local ) administrators
#define SDDL_BUILTIN_GUESTS "BG"  // Builtin (local ) guests
#define SDDL_BUILTIN_USERS  "BU"  // Builtin (local ) users
#define SDDL_LOCAL_ADMIN "LA"  // Local administrator account
#define SDDL_LOCAL_GUEST "LG"  // Local group account
#define SDDL_ACCOUNT_OPERATORS  "AO"  // Account operators
#define SDDL_BACKUP_OPERATORS "BO"  // Backup operators
#define SDDL_PRINTER_OPERATORS  "PO"  // Printer operators
#define SDDL_SERVER_OPERATORS "SO"  // Server operators
#define SDDL_AUTHENTICATED_USERS "AU"  // Authenticated users
#define SDDL_PERSONAL_SELF  "PS"  // Personal self
#define SDDL_CREATOR_OWNER  "CO"  // Creator owner
#define SDDL_CREATOR_GROUP  "CG"  // Creator group
#define SDDL_LOCAL_SYSTEM "SY"  // Local system
#define SDDL_POWER_USERS "PU"  // Power users
#define SDDL_EVERYONE "WD"  // Everyone ( World )
#define SDDL_REPLICATOR "RE"  // Replicator
#define SDDL_INTERACTIVE "IU"  // Interactive logon user
#define SDDL_NETWORK "NU"  // Nework logon user
#define SDDL_SERVICE "SU"  // Service logon user
#define SDDL_RESTRICTED_CODE "RC"  // Restricted code
#define SDDL_WRITE_RESTRICTED_CODE  "WR"  // Write Restricted code
#define SDDL_ANONYMOUS  "AN"  // Anonymous Logon
#define SDDL_SCHEMA_ADMINISTRATORS  "SA"  // Schema Administrators
#define SDDL_CERT_SERV_ADMINISTRATORS "CA"  // Certificate Server Administrators
#define SDDL_RAS_SERVERS "RS"  // RAS servers group
#define SDDL_ENTERPRISE_ADMINS  "EA"  // Enterprise administrators
#define SDDL_GROUP_POLICY_ADMINS "PA"  // Group Policy administrators
#define SDDL_ALIAS_PREW2KCOMPACC "RU"  // alias to allow previous windows 2000
#define SDDL_LOCAL_SERVICE  "LS"  // Local service account (for services)
#define SDDL_NETWORK_SERVICE "NS"  // Network service account (for services)
#define SDDL_REMOTE_DESKTOP "RD"  // Remote desktop users (for terminal server)
#define SDDL_NETWORK_CONFIGURATION_OPS  "NO"  // Network configuration operators ( to manage configuration of networking features)
#define SDDL_PERFMON_USERS  "MU"  // Performance Monitor Users
#define SDDL_PERFLOG_USERS  "LU"  // Performance Log Users
#define SDDL_IIS_USERS  "IS"  // Anonymous Internet Users
#define SDDL_CRYPTO_OPERATORS "CY"  // Crypto Operators
#define SDDL_OWNER_RIGHTS "OW"  // Owner Rights SID
#define SDDL_EVENT_LOG_READERS  "ER"  // Event log readers
#define SDDL_ENTERPRISE_RO_DCs  "RO"  // Enterprise Read-only domain controllers
#define SDDL_CERTSVC_DCOM_ACCESS "CD"  // Users who can connect to certification authorities using DCOM
//
// Integrity Labels
//
#define SDDL_ML_LOW "LW"  // Low mandatory level
#define SDDL_ML_MEDIUM  "ME"  // Medium mandatory level
#define SDDL_ML_MEDIUM_PLUS "MP"  // Medium Plus mandatory level
#define SDDL_ML_HIGH "HI"  // High mandatory level
#define SDDL_ML_SYSTEM  "SI"  // System mandatory level

//
// SDDL Seperators - character version
//
#define SDDL_SEPERATORC ';'
#define SDDL_DELIMINATORC ':'
#define SDDL_ACE_BEGINC '('
#define SDDL_ACE_ENDC ')'
#define SDDL_SPACEC  ' '
#define SDDL_ACE_COND_BEGINC '('
#define SDDL_ACE_COND_ENDC ')'
#define SDDL_ACE_COND_STRING_BEGINC '"'
#define SDDL_ACE_COND_STRING_ENDC '"'
#define SDDL_ACE_COND_COMPOSITEVALUE_BEGINC '{'
#define SDDL_ACE_COND_COMPOSITEVALUE_ENDC '}'
#define SDDL_ACE_COND_COMPOSITEVALUE_SEPERATORC ','
#define SDDL_ACE_COND_BLOB_PREFIXC  '#'
#define SDDL_ACE_COND_SID_BEGINC '('
#define SDDL_ACE_COND_SID_ENDC ')'

//
// SDDL Seperators - string version
//
#define SDDL_SEPERATOR ";"
#define SDDL_DELIMINATOR ":"
#define SDDL_ACE_BEGIN "("
#define SDDL_ACE_END ")"
#define SDDL_ACE_COND_BEGIN "("
#define SDDL_ACE_COND_END ")"
#define SDDL_SPACE  " "
#define SDDL_ACE_COND_BLOB_PREFIX  "#"
#define SDDL_ACE_COND_SID_PREFIX  "SID"

#ifdef UNICODE
#define ConvertSidToStringSid  ConvertSidToStringSidW
#define ConvertStringSidToSid  ConvertStringSidToSidW
#define ConvertStringSecurityDescriptorToSecurityDescriptor  ConvertStringSecurityDescriptorToSecurityDescriptorW
#define ConvertSecurityDescriptorToStringSecurityDescriptor  ConvertSecurityDescriptorToStringSecurityDescriptorW
#else
#define ConvertSidToStringSid  ConvertSidToStringSidA
#define ConvertStringSidToSid  ConvertStringSidToSidA
#define ConvertSecurityDescriptorToStringSecurityDescriptor  ConvertSecurityDescriptorToStringSecurityDescriptorA
#define ConvertStringSecurityDescriptorToSecurityDescriptor  ConvertStringSecurityDescriptorToSecurityDescriptorA
#endif // !UNICODE

#endif  // endif __SDDL_H__



