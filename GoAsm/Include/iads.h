#ifndef IADS_H
#define IADS_H

/* Active Directory Service Interface definitions */

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF

#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

ADSTYPE_INVALID = 0
ADSTYPE_DN_STRING = 1
ADSTYPE_CASE_EXACT_STRING = 2
ADSTYPE_CASE_IGNORE_STRING = 3
ADSTYPE_PRINTABLE_STRING = 4
ADSTYPE_NUMERIC_STRING = 5
ADSTYPE_BOOLEAN = 6
ADSTYPE_INTEGER = 7
ADSTYPE_OCTET_STRING = 8
ADSTYPE_UTC_TIME = 9
ADSTYPE_LARGE_INTEGER = 10
ADSTYPE_PROV_SPECIFIC = 11
ADSTYPE_OBJECT_CLASS = 12
ADSTYPE_CASEIGNORE_LIST = 13
ADSTYPE_OCTET_LIST = 14
ADSTYPE_PATH = 15
ADSTYPE_POSTALADDRESS = 16
ADSTYPE_TIMESTAMP = 17
ADSTYPE_BACKLINK = 18
ADSTYPE_TYPEDNAME = 19
ADSTYPE_HOLD = 20
ADSTYPE_NETADDRESS = 21
ADSTYPE_REPLICAPOINTER = 22
ADSTYPE_FAXNUMBER = 23
ADSTYPE_EMAIL = 24
ADSTYPE_NT_SECURITY_DESCRIPTOR = 25
ADSTYPE_UNKNOWN = 26
ADSTYPE_DN_WITH_BINARY = 27
ADSTYPE_DN_WITH_STRING = 28

ADS_OCTET_STRING STRUCT
	dwLength DD
	lpValue PTR
ENDS

ADS_NT_SECURITY_DESCRIPTOR STRUCT
	dwLength DD
	lpValue PTR
ENDS

ADS_PROV_SPECIFIC STRUCT
	dwLength DD
	lpValue PTR
ENDS

ADS_CASEIGNORE_LIST STRUCT
	Next DD
	String PTR
ENDS

ADS_OCTET_LIST STRUCT
	Next PTR
	Length DD
	Data PTR
ENDS

ADS_PATH STRUCT
	Type DD
	VolumeName PTR
	Path PTR
ENDS

ADS_POSTALADDRESS STRUCT
	PostalAddress PTR 6 DUP (?)
ENDS

ADS_TIMESTAMP STRUCT
	WholeSeconds DD
	EventID DD
ENDS

ADS_BACKLINK STRUCT
	RemoteID DD
	ObjectName PTR
ENDS

ADS_TYPEDNAME STRUCT
	ObjectName PTR
	Level DD
	Interval DD
ENDS

ADS_HOLD STRUCT
	ObjectName PTR
	Amount DD
ENDS

ADS_NETADDRESS STRUCT
	AddressType DD
	AddressLength DD
	Address PTR
ENDS

ADS_REPLICAPOINTER STRUCT
	ServerName PTR
	ReplicaType DD
	ReplicaNumber DD
	Count DD
	ReplicaAddressHints PTR
ENDS

ADS_FAXNUMBER STRUCT
	TelephoneNumber PTR
	NumberOfBits DD
	Parameters PTR
ENDS

ADS_EMAIL STRUCT
	Address PTR
	Type DD
ENDS

ADS_DN_WITH_BINARY STRUCT
	dwLength DD
	lpBinaryValue PTR
	pszDNString PTR
ENDS

ADS_DN_WITH_STRING STRUCT
	pszStringValue PTR
	pszDNString PTR
ENDS

ADSVALUE STRUCT
	dwType DD
	UNION
		DNString ADS_DN_STRING
		CaseExactString PTR
		CaseIgnoreString PTR
		PrintableString PTR
		NumericString PTR
		Boolean BOOLEAN
		Integer DD
		OctetString ADS_OCTET_STRING
		UTCTime SYSTEMTIME
		LargeInteger LARGE_INTEGER
		ClassName PTR
		ProviderSpecific ADS_PROV_SPECIFIC
		pCaseIgnoreList PTR
		pOctetList PTR
		pPath PTR
		pPostalAddress PTR
		Timestamp ADS_TIMESTAMP
		BackLink ADS_BACKLINK
		pTypedName PTR
		Hold ADS_HOLD
		pNetAddress PTR
		pReplicaPointer PTR
		pFaxNumber PTR
		Email ADS_EMAIL
		SecurityDescriptor ADS_NT_SECURITY_DESCRIPTOR
		pDNWithBinary PTR
		pDNWithString PTR
	ENDUNION
ENDS

ADS_ATTR_INFO STRUCT
	pszAttrName PTR
	dwControlCode DD
	dwADsType DD
	pADsValues PTR
	dwNumValues DD
ENDS

ADS_SECURE_AUTHENTICATION = 0x1
ADS_USE_ENCRYPTION = 0x2
ADS_USE_SSL = 0x2
ADS_READONLY_SERVER = 0x4
ADS_PROMPT_CREDENTIALS = 0x8
ADS_NO_AUTHENTICATION = 0x10
ADS_FAST_BIND = 0x20
ADS_USE_SIGNING = 0x40
ADS_USE_SEALING = 0x80
ADS_USE_DELEGATION = 0x100
ADS_SERVER_BIND = 0x200
ADS_AUTH_RESERVED = 0x80000000

#define ADS_ATTR_CLEAR  1
#define ADS_ATTR_UPDATE 2
#define ADS_ATTR_APPEND 3
#define ADS_ATTR_DELETE 4

ADS_OBJECT_INFO STRUCT
	pszRDN PTR
	pszObjectDN PTR
	pszParentDN PTR
	pszSchemaDN PTR
	pszClassName PTR
ENDS

ADS_STATUS_S_OK = 0
ADS_STATUS_INVALID_SEARCHPREF = ADS_STATUS_S_OK+1
ADS_STATUS_INVALID_SEARCHPREFVALUE = ADS_STATUS_INVALID_SEARCHPREF+1

ADS_DEREF_NEVER = 0
ADS_DEREF_SEARCHING = 1
ADS_DEREF_FINDING = 2
ADS_DEREF_ALWAYS = 3

ADS_SCOPE_BASE = 0
ADS_SCOPE_ONELEVEL = 1
ADS_SCOPE_SUBTREE = 2

ADSIPROP_ASYNCHRONOUS = 0
ADSIPROP_DEREF_ALIASES = 0x1
ADSIPROP_SIZE_LIMIT = 0x2
ADSIPROP_TIME_LIMIT = 0x3
ADSIPROP_ATTRIBTYPES_ONLY = 0x4
ADSIPROP_SEARCH_SCOPE = 0x5
ADSIPROP_TIMEOUT = 0x6
ADSIPROP_PAGESIZE = 0x7
ADSIPROP_PAGED_TIME_LIMIT = 0x8
ADSIPROP_CHASE_REFERRALS = 0x9
ADSIPROP_SORT_ON = 0xa
ADSIPROP_CACHE_RESULTS = 0xb
ADSIPROP_ADSIFLAG = 0xc

ADSI_DIALECT_LDAP = 0
ADSI_DIALECT_SQL = 0x1

ADS_CHASE_REFERRALS_NEVER = 0
ADS_CHASE_REFERRALS_SUBORDINATE = 0x20
ADS_CHASE_REFERRALS_EXTERNAL = 0x40
ADS_CHASE_REFERRALS_ALWAYS = ADS_CHASE_REFERRALS_SUBORDINATE|ADS_CHASE_REFERRALS_EXTERNAL

ADS_SEARCHPREF_ASYNCHRONOUS = 0
ADS_SEARCHPREF_DEREF_ALIASES = 1
ADS_SEARCHPREF_SIZE_LIMIT = 2
ADS_SEARCHPREF_TIME_LIMIT = 3
ADS_SEARCHPREF_ATTRIBTYPES_ONLY = 4
ADS_SEARCHPREF_SEARCH_SCOPE = 5
ADS_SEARCHPREF_TIMEOUT = 6
ADS_SEARCHPREF_PAGESIZE = 7
ADS_SEARCHPREF_PAGED_TIME_LIMIT = 8
ADS_SEARCHPREF_CHASE_REFERRALS = 9
ADS_SEARCHPREF_SORT_ON = 10
ADS_SEARCHPREF_CACHE_RESULTS = 11
ADS_SEARCHPREF_DIRSYNC = 12
ADS_SEARCHPREF_TOMBSTONE = 13
ADS_SEARCHPREF_VLV = 14
ADS_SEARCHPREF_ATTRIBUTE_QUERY = 15
ADS_SEARCHPREF_SECURITY_MASK = 16

ADS_SEARCHPREF_INFO STRUCT
	dwSearchPref DD
	vValue DD
	dwStatus DD
ENDS

#define ADS_DIRSYNC_COOKIE  L"fc8cb04d-311d-406c-8cb9-1ae8b843b418"
#define ADS_VLV_RESPONSE  L"fc8cb04d-311d-406c-8cb9-1ae8b843b419"

ADS_SEARCH_COLUMN STRUCT
	pszAttrName PTR
	dwADsType DD
	pADsValues PTR
	dwNumValues DD
	hReserved HANDLE
ENDS

ADS_ATTR_DEF STRUCT
	pszAttrName PTR
	dwADsType DD
	dwMinRange DD
	dwMaxRange DD
	fMultiValued DD
ENDS

ADS_CLASS_DEF STRUCT
	pszClassName PTR
	dwMandatoryAttrs DD
	ppszMandatoryAttrs PTR
	optionalAttrs DD
	ppszOptionalAttrs PTR
	dwNamingAttrs DD
	ppszNamingAttrs PTR
	dwSuperClasses DD
	ppszSuperClasses PTR
	fIsContainer DD
ENDS

ADS_SORTKEY STRUCT
	pszAttrType PTR
	pszReserved PTR
	fReverseorder DB
ENDS

ADS_VLV STRUCT
	dwBeforeCount DD
	dwAfterCount DD
	dwOffset DD
	dwContentCount DD
	pszTarget PTR
	dwContextIDLength DD
	lpContextID PTR
ENDS

#define ADS_EXT_MINEXTDISPID  1
#define ADS_EXT_MAXEXTDISPID  16777215
#define ADS_EXT_INITCREDENTIALS  1
#define ADS_EXT_INITIALIZE_COMPLETE  2

ADS_PROPERTY_CLEAR = 1
ADS_PROPERTY_UPDATE = 2
ADS_PROPERTY_APPEND = 3
ADS_PROPERTY_DELETE = 4

ADS_SYSTEMFLAG_DISALLOW_DELETE = 0x80000000
ADS_SYSTEMFLAG_CONFIG_ALLOW_RENAME = 0x40000000
ADS_SYSTEMFLAG_CONFIG_ALLOW_MOVE = 0x20000000
ADS_SYSTEMFLAG_CONFIG_ALLOW_LIMITED_MOVE = 0x10000000
ADS_SYSTEMFLAG_DOMAIN_DISALLOW_RENAME = 0x8000000
ADS_SYSTEMFLAG_DOMAIN_DISALLOW_MOVE = 0x4000000
ADS_SYSTEMFLAG_CR_NTDS_NC = 0x1
ADS_SYSTEMFLAG_CR_NTDS_DOMAIN = 0x2
ADS_SYSTEMFLAG_ATTR_NOT_REPLICATED = 0x1
ADS_SYSTEMFLAG_ATTR_IS_CONSTRUCTED = 0x4

ADS_GROUP_TYPE_GLOBAL_GROUP = 0x2
ADS_GROUP_TYPE_DOMAIN_LOCAL_GROUP = 0x4
ADS_GROUP_TYPE_LOCAL_GROUP = 0x4
ADS_GROUP_TYPE_UNIVERSAL_GROUP = 0x8
ADS_GROUP_TYPE_SECURITY_ENABLED = 0x80000000

ADS_UF_SCRIPT = 0x1
ADS_UF_ACCOUNTDISABLE = 0x2
ADS_UF_HOMEDIR_REQUIRED = 0x8
ADS_UF_LOCKOUT = 0x10
ADS_UF_PASSWD_NOTREQD = 0x20
ADS_UF_PASSWD_CANT_CHANGE = 0x40
ADS_UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED = 0x80
ADS_UF_TEMP_DUPLICATE_ACCOUNT = 0x100
ADS_UF_NORMAL_ACCOUNT = 0x200
ADS_UF_INTERDOMAIN_TRUST_ACCOUNT = 0x800
ADS_UF_WORKSTATION_TRUST_ACCOUNT = 0x1000
ADS_UF_SERVER_TRUST_ACCOUNT = 0x2000
ADS_UF_DONT_EXPIRE_PASSWD = 0x10000
ADS_UF_MNS_LOGON_ACCOUNT = 0x20000
ADS_UF_SMARTCARD_REQUIRED = 0x40000
ADS_UF_TRUSTED_FOR_DELEGATION = 0x80000
ADS_UF_NOT_DELEGATED = 0x100000
ADS_UF_USE_DES_KEY_ONLY = 0x200000
ADS_UF_DONT_REQUIRE_PREAUTH = 0x400000
ADS_UF_PASSWORD_EXPIRED = 0x800000
ADS_UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION = 0x1000000

ADS_RIGHT_DELETE = 0x10000
ADS_RIGHT_READ_CONTROL = 0x20000
ADS_RIGHT_WRITE_DAC = 0x40000
ADS_RIGHT_WRITE_OWNER = 0x80000
ADS_RIGHT_SYNCHRONIZE = 0x100000
ADS_RIGHT_ACCESS_SYSTEM_SECURITY = 0x1000000
ADS_RIGHT_GENERIC_READ = 0x80000000
ADS_RIGHT_GENERIC_WRITE = 0x40000000
ADS_RIGHT_GENERIC_EXECUTE = 0x20000000
ADS_RIGHT_GENERIC_ALL = 0x10000000
ADS_RIGHT_DS_CREATE_CHILD = 0x1
ADS_RIGHT_DS_DELETE_CHILD = 0x2
ADS_RIGHT_ACTRL_DS_LIST = 0x4
ADS_RIGHT_DS_SELF = 0x8
ADS_RIGHT_DS_READ_PROP = 0x10
ADS_RIGHT_DS_WRITE_PROP = 0x20
ADS_RIGHT_DS_DELETE_TREE = 0x40
ADS_RIGHT_DS_LIST_OBJECT = 0x80
ADS_RIGHT_DS_CONTROL_ACCESS = 0x100

ADS_ACETYPE_ACCESS_ALLOWED = 0
ADS_ACETYPE_ACCESS_DENIED = 0x1
ADS_ACETYPE_SYSTEM_AUDIT = 0x2
ADS_ACETYPE_ACCESS_ALLOWED_OBJECT = 0x5
ADS_ACETYPE_ACCESS_DENIED_OBJECT = 0x6
ADS_ACETYPE_SYSTEM_AUDIT_OBJECT = 0x7
ADS_ACETYPE_SYSTEM_ALARM_OBJECT = 0x8
ADS_ACETYPE_ACCESS_ALLOWED_CALLBACK = 0x9
ADS_ACETYPE_ACCESS_DENIED_CALLBACK = 0xa
ADS_ACETYPE_ACCESS_ALLOWED_CALLBACK_OBJECT = 0xb
ADS_ACETYPE_ACCESS_DENIED_CALLBACK_OBJECT = 0xc
ADS_ACETYPE_SYSTEM_AUDIT_CALLBACK = 0xd
ADS_ACETYPE_SYSTEM_ALARM_CALLBACK = 0xe
ADS_ACETYPE_SYSTEM_AUDIT_CALLBACK_OBJECT = 0xf
ADS_ACETYPE_SYSTEM_ALARM_CALLBACK_OBJECT = 0x10

ADS_ACEFLAG_INHERIT_ACE = 0x2
ADS_ACEFLAG_NO_PROPAGATE_INHERIT_ACE = 0x4
ADS_ACEFLAG_INHERIT_ONLY_ACE = 0x8
ADS_ACEFLAG_INHERITED_ACE = 0x10
ADS_ACEFLAG_VALID_INHERIT_FLAGS = 0x1f
ADS_ACEFLAG_SUCCESSFUL_ACCESS = 0x40
ADS_ACEFLAG_FAILED_ACCESS = 0x80

ADS_FLAG_OBJECT_TYPE_PRESENT = 0x1
ADS_FLAG_INHERITED_OBJECT_TYPE_PRESENT = 0x2

ADS_SD_CONTROL_SE_OWNER_DEFAULTED = 0x1
ADS_SD_CONTROL_SE_GROUP_DEFAULTED = 0x2
ADS_SD_CONTROL_SE_DACL_PRESENT = 0x4
ADS_SD_CONTROL_SE_DACL_DEFAULTED = 0x8
ADS_SD_CONTROL_SE_SACL_PRESENT = 0x10
ADS_SD_CONTROL_SE_SACL_DEFAULTED = 0x20
ADS_SD_CONTROL_SE_DACL_AUTO_INHERIT_REQ = 0x100
ADS_SD_CONTROL_SE_SACL_AUTO_INHERIT_REQ = 0x200
ADS_SD_CONTROL_SE_DACL_AUTO_INHERITED = 0x400
ADS_SD_CONTROL_SE_SACL_AUTO_INHERITED = 0x800
ADS_SD_CONTROL_SE_DACL_PROTECTED = 0x1000
ADS_SD_CONTROL_SE_SACL_PROTECTED = 0x2000
ADS_SD_CONTROL_SE_SELF_RELATIVE = 0x8000

ADS_SD_REVISION_DS = 4

ADS_NAME_TYPE_1779 = 1
ADS_NAME_TYPE_CANONICAL = 2
ADS_NAME_TYPE_NT4 = 3
ADS_NAME_TYPE_DISPLAY = 4
ADS_NAME_TYPE_DOMAIN_SIMPLE = 5
ADS_NAME_TYPE_ENTERPRISE_SIMPLE = 6
ADS_NAME_TYPE_GUID = 7
ADS_NAME_TYPE_UNKNOWN = 8
ADS_NAME_TYPE_USER_PRINCIPAL_NAME = 9
ADS_NAME_TYPE_CANONICAL_EX = 10
ADS_NAME_TYPE_SERVICE_PRINCIPAL_NAME = 11
ADS_NAME_TYPE_SID_OR_SID_HISTORY_NAME = 12

ADS_NAME_INITTYPE_DOMAIN = 1
ADS_NAME_INITTYPE_SERVER = 2
ADS_NAME_INITTYPE_GC = 3

ADS_OPTION_SERVERNAME = 0
ADS_OPTION_REFERRALS = 1
ADS_OPTION_PAGE_SIZE = 2
ADS_OPTION_SECURITY_MASK = 3
ADS_OPTION_MUTUAL_AUTH_STATUS = 4

ADS_SECURITY_INFO_OWNER = 0x1
ADS_SECURITY_INFO_GROUP = 0x2
ADS_SECURITY_INFO_DACL = 0x4
ADS_SECURITY_INFO_SACL = 0x8

ADS_SETTYPE_FULL = 1
ADS_SETTYPE_PROVIDER = 2
ADS_SETTYPE_SERVER = 3
ADS_SETTYPE_DN = 4

ADS_FORMAT_WINDOWS = 1
ADS_FORMAT_WINDOWS_NO_SERVER = 2
ADS_FORMAT_WINDOWS_DN = 3
ADS_FORMAT_WINDOWS_PARENT = 4
ADS_FORMAT_X500 = 5
ADS_FORMAT_X500_NO_SERVER = 6
ADS_FORMAT_X500_DN = 7
ADS_FORMAT_X500_PARENT = 8
ADS_FORMAT_SERVER = 9
ADS_FORMAT_PROVIDER = 10
ADS_FORMAT_LEAF = 11

ADS_DISPLAY_FULL = 1
ADS_DISPLAY_VALUE_ONLY = 2

ADS_ESCAPEDMODE_DEFAULT = 1
ADS_ESCAPEDMODE_ON = 2
ADS_ESCAPEDMODE_OFF = 3
ADS_ESCAPEDMODE_OFF_EX = 4

ADS_PATH_FILE = 1
ADS_PATH_FILESHARE = 2
ADS_PATH_REGISTRY = 3

ADS_SD_FORMAT_IID = 1
ADS_SD_FORMAT_RAW = 2
ADS_SD_FORMAT_HEXSTRING = 3

#define GUID_IID_IADs <0xfd8256d0,0xfd15,0x11ce,<0xab,0xc4,0x02,0x60,0x8c,0x9e,0x75,0x53>>
IADs STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
ENDS

#define GUID_IID_IADsContainer <0x001677d0,0xfd16,0x11ce,<0xab,0xc4,0x02,0x60,0x8c,0x9e,0x75,0x53>>
IADsContainer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Count PTR
	get__NewEnum PTR
	get_Filter PTR
	put_Filter PTR
	get_Hints PTR
	put_Hints PTR
	GetObject PTR
	Create PTR
	Delete PTR
	CopyHere PTR
	MoveHere PTR
ENDS

#define GUID_IID_IADsCollection <0x72b945e0,0x253b,0x11cf,<0xa9,0x88,0x00,0xaa,0x00,0x6b,0xc1,0x49>>
IADsCollection STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get__NewEnum PTR
	Add PTR
	Remove PTR
	GetObject PTR
ENDS

#define GUID_IID_IADsMembers <0x451a0030,0x72ec,0x11cf,<0xb0,0x3b,0x00,0xaa,0x00,0x6e,0x09,0x75>>
IADsMembers STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Count PTR
	get__NewEnum PTR
	get_Filter PTR
	put_Filter PTR
ENDS

#define GUID_IID_IADsPropertyList <0xc6f602b6,0x8f69,0x11d0,<0x85,0x28,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IADsPropertyList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_PropertyCount PTR
	Next PTR
	Skip PTR
	Reset PTR
	Item PTR
	GetPropertyItem PTR
	PutPropertyItem PTR
	ResetPropertyItem PTR
	PurgePropertyList PTR
ENDS

#define GUID_IID_IADsPropertyEntry <0x05792c8e,0x941f,0x11d0,<0x85,0x29,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IADsPropertyEntry STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Clear PTR
	get_Name PTR
	put_Name PTR
	get_ADsType PTR
	put_ADsType PTR
	get_ControlCode PTR
	put_ControlCode PTR
	get_Values PTR
	put_Values PTR
ENDS

#define GUID_IID_IADsPropertyValue <0x79fa9ad0,0xa97c,0x11d0,<0x85,0x34,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IADsPropertyValue STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Clear PTR
	get_ADsType PTR
	put_ADsType PTR
	get_DNString PTR
	put_DNString PTR
	get_CaseExactString PTR
	put_CaseExactString PTR
	get_CaseIgnoreString PTR
	put_CaseIgnoreString PTR
	get_PrintableString PTR
	put_PrintableString PTR
	get_NumericString PTR
	put_NumericString PTR
	get_Boolean PTR
	put_Boolean PTR
	get_Integer PTR
	put_Integer PTR
	get_OctetString PTR
	put_OctetString PTR
	get_SecurityDescriptor PTR
	put_SecurityDescriptor PTR
	get_LargeInteger PTR
	put_LargeInteger PTR
	get_UTCTime PTR
	put_UTCTime PTR
ENDS

#define GUID_IID_IADsPropertyValue2 <0x306e831c,0x5bc7,0x11d1,<0xa3,0xb8,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsPropertyValue2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	GetObjectProperty PTR
	PutObjectProperty PTR
ENDS

#define GUID_IID_IPrivateDispatch <0x86ab4bbe,0x65f6,0x11d1,<0x8c,0x13,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IPrivateDispatch STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
ENDS

#define GUID_IID_IPrivateUnknown <0x89126bab,0x6ead,0x11d1,<0x8c,0x18,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IPrivateUnknown STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ADSIInitializeObject PTR
	ADSIReleaseObject PTR
ENDS

#define GUID_IID_IADsExtension <0x3d35553c,0xd2b0,0x11d1,<0xb1,0x7b,0x00,0x00,0xf8,0x75,0x93,0xa0>>
IADsExtension STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Operate PTR
	PrivateGetIDsOfNames PTR
	PrivateInvoke PTR
ENDS

#define GUID_IID_IADsDeleteOps <0xb2bd0902,0x8878,0x11d1,<0x8c,0x21,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IADsDeleteOps STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	DeleteObject PTR
ENDS

#define GUID_IID_IADsNamespaces <0x28b96ba0,0xb330,0x11cf,<0xa9,0xad,0x00,0xaa,0x00,0x6b,0xc1,0x49>>
IADsNamespaces STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_DefaultContainer PTR
	put_DefaultContainer PTR
ENDS

#define GUID_IID_IADsClass <0xc8f93dd0,0x4ae0,0x11cf,<0x9e,0x73,0x00,0xaa,0x00,0x4a,0x56,0x91>>
IADsClass STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_PrimaryInterface PTR
	get_CLSID PTR
	put_CLSID PTR
	get_OID PTR
	put_OID PTR
	get_Abstract PTR
	put_Abstract PTR
	get_Auxiliary PTR
	put_Auxiliary PTR
	get_MandatoryProperties PTR
	put_MandatoryProperties PTR
	get_OptionalProperties PTR
	put_OptionalProperties PTR
	get_NamingProperties PTR
	put_NamingProperties PTR
	get_DerivedFrom PTR
	put_DerivedFrom PTR
	get_AuxDerivedFrom PTR
	put_AuxDerivedFrom PTR
	get_PossibleSuperiors PTR
	put_PossibleSuperiors PTR
	get_Containment PTR
	put_Containment PTR
	get_Container PTR
	put_Container PTR
	get_HelpFileName PTR
	put_HelpFileName PTR
	get_HelpFileContext PTR
	put_HelpFileContext PTR
	Qualifiers PTR
ENDS

#define GUID_IID_IADsProperty <0xc8f93dd3,0x4ae0,0x11cf,<0x9e,0x73,0x00,0xaa,0x00,0x4a,0x56,0x91>>
IADsProperty STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_OID PTR
	put_OID PTR
	get_Syntax PTR
	put_Syntax PTR
	get_MaxRange PTR
	put_MaxRange PTR
	get_MinRange PTR
	put_MinRange PTR
	get_MultiValued PTR
	put_MultiValued PTR
	Qualifiers PTR
ENDS

#define GUID_IID_IADsSyntax <0xc8f93dd2,0x4ae0,0x11cf,<0x9e,0x73,0x00,0xaa,0x00,0x4a,0x56,0x91>>
IADsSyntax STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_OleAutoDataType PTR
	put_OleAutoDataType PTR
ENDS

#define GUID_IID_IADsLocality <0xa05e03a2,0xeffe,0x11cf,<0x8a,0xbc,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IADsLocality STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_Description PTR
	put_Description PTR
	get_LocalityName PTR
	put_LocalityName PTR
	get_PostalAddress PTR
	put_PostalAddress PTR
	get_SeeAlso PTR
	put_SeeAlso PTR
ENDS

#define GUID_IID_IADsO <0xa1cd2dc6,0xeffe,0x11cf,<0x8a,0xbc,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IADsO STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_Description PTR
	put_Description PTR
	get_LocalityName PTR
	put_LocalityName PTR
	get_PostalAddress PTR
	put_PostalAddress PTR
	get_TelephoneNumber PTR
	put_TelephoneNumber PTR
	get_FaxNumber PTR
	put_FaxNumber PTR
	get_SeeAlso PTR
	put_SeeAlso PTR
ENDS

#define GUID_IID_IADsOU <0xa2f733b8,0xeffe,0x11cf,<0x8a,0xbc,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IADsOU STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_Description PTR
	put_Description PTR
	get_LocalityName PTR
	put_LocalityName PTR
	get_PostalAddress PTR
	put_PostalAddress PTR
	get_TelephoneNumber PTR
	put_TelephoneNumber PTR
	get_FaxNumber PTR
	put_FaxNumber PTR
	get_SeeAlso PTR
	put_SeeAlso PTR
	get_BusinessCategory PTR
	put_BusinessCategory PTR
ENDS

#define GUID_IID_IADsDomain <0x00e4c220,0xfd16,0x11ce,<0xab,0xc4,0x02,0x60,0x8c,0x9e,0x75,0x53>>
IADsDomain STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_IsWorkgroup PTR
	get_MinPasswordLength PTR
	put_MinPasswordLength PTR
	get_MinPasswordAge PTR
	put_MinPasswordAge PTR
	get_MaxPasswordAge PTR
	put_MaxPasswordAge PTR
	get_MaxBadPasswordsAllowed PTR
	put_MaxBadPasswordsAllowed PTR
	get_PasswordHistoryLength PTR
	put_PasswordHistoryLength PTR
	get_PasswordAttributes PTR
	put_PasswordAttributes PTR
	get_AutoUnlockInterval PTR
	put_AutoUnlockInterval PTR
	get_LockoutObservationInterval PTR
	put_LockoutObservationInterval PTR
ENDS

#define GUID_IID_IADsComputer <0xefe3cc70,0x1d9f,0x11cf,<0xb1,0xf3,0x02,0x60,0x8c,0x9e,0x75,0x53>>
IADsComputer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_ComputerID PTR
	get_Site PTR
	get_Description PTR
	put_Description PTR
	get_Location PTR
	put_Location PTR
	get_PrimaryUser PTR
	put_PrimaryUser PTR
	get_Owner PTR
	put_Owner PTR
	get_Division PTR
	put_Division PTR
	get_Department PTR
	put_Department PTR
	get_Role PTR
	put_Role PTR
	get_OperatingSystem PTR
	put_OperatingSystem PTR
	get_OperatingSystemVersion PTR
	put_OperatingSystemVersion PTR
	get_Model PTR
	put_Model PTR
	get_Processor PTR
	put_Processor PTR
	get_ProcessorCount PTR
	put_ProcessorCount PTR
	get_MemorySize PTR
	put_MemorySize PTR
	get_StorageCapacity PTR
	put_StorageCapacity PTR
	get_NetAddresses PTR
	put_NetAddresses PTR
ENDS

#define GUID_IID_IADsComputerOperations <0xef497680,0x1d9f,0x11cf,<0xb1,0xf3,0x02,0x60,0x8c,0x9e,0x75,0x53>>
IADsComputerOperations STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	Status PTR
	Shutdown PTR
ENDS

#define GUID_IID_IADsGroup <0x27636b00,0x410f,0x11cf,<0xb1,0xff,0x02,0x60,0x8c,0x9e,0x75,0x53>>
IADsGroup STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_Description PTR
	put_Description PTR
	Members PTR
	IsMember PTR
	Add PTR
	Remove PTR
ENDS

#define GUID_IID_IADsUser <0x3e37e320,0x17e2,0x11cf,<0xab,0xc4,0x02,0x60,0x8c,0x9e,0x75,0x53>>
IADsUser STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_BadLoginAddress PTR
	get_BadLoginCount PTR
	get_LastLogin PTR
	get_LastLogoff PTR
	get_LastFailedLogin PTR
	get_PasswordLastChanged PTR
	get_Description PTR
	put_Description PTR
	get_Division PTR
	put_Division PTR
	get_Department PTR
	put_Department PTR
	get_EmployeeID PTR
	put_EmployeeID PTR
	get_FullName PTR
	put_FullName PTR
	get_FirstName PTR
	put_FirstName PTR
	get_LastName PTR
	put_LastName PTR
	get_OtherName PTR
	put_OtherName PTR
	get_NamePrefix PTR
	put_NamePrefix PTR
	get_NameSuffix PTR
	put_NameSuffix PTR
	get_Title PTR
	put_Title PTR
	get_Manager PTR
	put_Manager PTR
	get_TelephoneHome PTR
	put_TelephoneHome PTR
	get_TelephoneMobile PTR
	put_TelephoneMobile PTR
	get_TelephoneNumber PTR
	put_TelephoneNumber PTR
	get_TelephonePager PTR
	put_TelephonePager PTR
	get_FaxNumber PTR
	put_FaxNumber PTR
	get_OfficeLocations PTR
	put_OfficeLocations PTR
	get_PostalAddresses PTR
	put_PostalAddresses PTR
	get_PostalCodes PTR
	put_PostalCodes PTR
	get_SeeAlso PTR
	put_SeeAlso PTR
	get_AccountDisabled PTR
	put_AccountDisabled PTR
	get_AccountExpirationDate PTR
	put_AccountExpirationDate PTR
	get_GraceLoginsAllowed PTR
	put_GraceLoginsAllowed PTR
	get_GraceLoginsRemaining PTR
	put_GraceLoginsRemaining PTR
	get_IsAccountLocked PTR
	put_IsAccountLocked PTR
	get_LoginHours PTR
	put_LoginHours PTR
	get_LoginWorkstations PTR
	put_LoginWorkstations PTR
	get_MaxLogins PTR
	put_MaxLogins PTR
	get_MaxStorage PTR
	put_MaxStorage PTR
	get_PasswordExpirationDate PTR
	put_PasswordExpirationDate PTR
	get_PasswordMinimumLength PTR
	put_PasswordMinimumLength PTR
	get_PasswordRequired PTR
	put_PasswordRequired PTR
	get_RequireUniquePassword PTR
	put_RequireUniquePassword PTR
	get_EmailAddress PTR
	put_EmailAddress PTR
	get_HomeDirectory PTR
	put_HomeDirectory PTR
	get_Languages PTR
	put_Languages PTR
	get_Profile PTR
	put_Profile PTR
	get_LoginScript PTR
	put_LoginScript PTR
	get_Picture PTR
	put_Picture PTR
	get_HomePage PTR
	put_HomePage PTR
	Groups PTR
	SetPassword PTR
	ChangePassword PTR
ENDS

#define GUID_IID_IADsPrintQueue <0xb15160d0,0x1226,0x11cf,<0xa9,0x85,0x00,0xaa,0x00,0x6b,0xc1,0x49>>
IADsPrintQueue STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_PrinterPath PTR
	put_PrinterPath PTR
	get_Model PTR
	put_Model PTR
	get_Datatype PTR
	put_Datatype PTR
	get_PrintProcessor PTR
	put_PrintProcessor PTR
	get_Description PTR
	put_Description PTR
	get_Location PTR
	put_Location PTR
	get_StartTime PTR
	put_StartTime PTR
	get_UntilTime PTR
	put_UntilTime PTR
	get_DefaultJobPriority PTR
	put_DefaultJobPriority PTR
	get_Priority PTR
	put_Priority PTR
	get_BannerPage PTR
	put_BannerPage PTR
	get_PrintDevices PTR
	put_PrintDevices PTR
	get_NetAddresses PTR
	put_NetAddresses PTR
ENDS

#define GUID_IID_IADsPrintQueueOperations <0x124be5c0,0x156e,0x11cf,<0xa9,0x86,0x00,0xaa,0x00,0x6b,0xc1,0x49>>
IADsPrintQueueOperations STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_Status PTR
	PrintJobs PTR
	Pause PTR
	Resume PTR
	Purge PTR
ENDS

#define GUID_IID_IADsPrintJob <0x32fb6780,0x1ed0,0x11cf,<0xa9,0x88,0x00,0xaa,0x00,0x6b,0xc1,0x49>>
IADsPrintJob STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_HostPrintQueue PTR
	get_User PTR
	get_UserPath PTR
	get_TimeSubmitted PTR
	get_TotalPages PTR
	get_Size PTR
	get_Description PTR
	put_Description PTR
	get_Priority PTR
	put_Priority PTR
	get_StartTime PTR
	put_StartTime PTR
	get_UntilTime PTR
	put_UntilTime PTR
	get_Notify PTR
	put_Notify PTR
	get_NotifyPath PTR
	put_NotifyPath PTR
ENDS

#define GUID_IID_IADsPrintJobOperations <0x9a52db30,0x1ecf,0x11cf,<0xa9,0x88,0x00,0xaa,0x00,0x6b,0xc1,0x49>>
IADsPrintJobOperations STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_Status PTR
	get_TimeElapsed PTR
	get_PagesPrinted PTR
	get_Position PTR
	put_Position PTR
	Pause PTR
	Resume PTR
ENDS

#define GUID_IID_IADsService <0x68af66e0,0x31ca,0x11cf,<0xa9,0x8a,0x00,0xaa,0x00,0x6b,0xc1,0x49>>
IADsService STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_HostComputer PTR
	put_HostComputer PTR
	get_DisplayName PTR
	put_DisplayName PTR
	get_Version PTR
	put_Version PTR
	get_ServiceType PTR
	put_ServiceType PTR
	get_StartType PTR
	put_StartType PTR
	get_Path PTR
	put_Path PTR
	get_StartupParameters PTR
	put_StartupParameters PTR
	get_ErrorControl PTR
	put_ErrorControl PTR
	get_LoadOrderGroup PTR
	put_LoadOrderGroup PTR
	get_ServiceAccountName PTR
	put_ServiceAccountName PTR
	get_ServiceAccountPath PTR
	put_ServiceAccountPath PTR
	get_Dependencies PTR
	put_Dependencies PTR
ENDS

#define GUID_IID_IADsServiceOperations <0x5d7b33f0,0x31ca,0x11cf,<0xa9,0x8a,0x00,0xaa,0x00,0x6b,0xc1,0x49>>
IADsServiceOperations STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_Status PTR
	Start PTR
	Stop PTR
	Pause PTR
	Continue PTR
	SetPassword PTR
ENDS

#define GUID_IID_IADsFileService <0xa89d1900,0x31ca,0x11cf,<0xa9,0x8a,0x00,0xaa,0x00,0x6b,0xc1,0x49>>
IADsFileService STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_HostComputer PTR
	put_HostComputer PTR
	get_DisplayName PTR
	put_DisplayName PTR
	get_Version PTR
	put_Version PTR
	get_ServiceType PTR
	put_ServiceType PTR
	get_StartType PTR
	put_StartType PTR
	get_Path PTR
	put_Path PTR
	get_StartupParameters PTR
	put_StartupParameters PTR
	get_ErrorControl PTR
	put_ErrorControl PTR
	get_LoadOrderGroup PTR
	put_LoadOrderGroup PTR
	get_ServiceAccountName PTR
	put_ServiceAccountName PTR
	get_ServiceAccountPath PTR
	put_ServiceAccountPath PTR
	get_Dependencies PTR
	put_Dependencies PTR
	get_Description PTR
	put_Description PTR
	get_MaxUserCount PTR
	put_MaxUserCount PTR
ENDS

#define GUID_IID_IADsFileServiceOperations <0xa02ded10,0x31ca,0x11cf,<0xa9,0x8a,0x00,0xaa,0x00,0x6b,0xc1,0x49>>
IADsFileServiceOperations STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_Status PTR
	Start PTR
	Stop PTR
	Pause PTR
	Continue PTR
	SetPassword PTR
	Sessions PTR
	Resources PTR
ENDS

#define GUID_IID_IADsFileShare <0xeb6dcaf0,0x4b83,0x11cf,<0xa9,0x95,0x00,0xaa,0x00,0x6b,0xc1,0x49>>
IADsFileShare STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_CurrentUserCount PTR
	get_Description PTR
	put_Description PTR
	get_HostComputer PTR
	put_HostComputer PTR
	get_Path PTR
	put_Path PTR
	get_MaxUserCount PTR
	put_MaxUserCount PTR
ENDS

#define GUID_IID_IADsSession <0x398b7da0,0x4aab,0x11cf,<0xae,0x2c,0x00,0xaa,0x00,0x6e,0xbf,0xb9>>
IADsSession STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_User PTR
	get_UserPath PTR
	get_Computer PTR
	get_ComputerPath PTR
	get_ConnectTime PTR
	get_IdleTime PTR
ENDS

#define GUID_IID_IIADsResource <0x34a05b20,0x4aab,0x11cf,<0xae,0x2c,0x00,0xaa,0x00,0x6e,0xbf,0xb9>>
IIADsResource STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Name PTR
	get_Class PTR
	get_GUID PTR
	get_ADsPath PTR
	get_Parent PTR
	get_Schema PTR
	GetInfo PTR
	SetInfo PTR
	Get PTR
	Put PTR
	GetEx PTR
	PutEx PTR
	GetInfoEx PTR
	get_User PTR
	get_UserPath PTR
	get_Path PTR
	get_LockCount PTR
ENDS

#define GUID_IID_IADsOpenDSObject <0xddf2891e,0x0f9c,0x11d0,<0x8a,0xd4,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IADsOpenDSObject STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	OpenDSObject PTR
ENDS

#define GUID_IID_IDirectoryObject <0xe798de2c,0x22e4,0x11d0,<0x84,0xfe,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IDirectoryObject STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetObjectInformation PTR
	GetObjectAttributes PTR
	SetObjectAttributes PTR
	CreateDSObject PTR
	DeleteDSObject PTR
ENDS

#define GUID_IID_IDirectorySearch <0x109ba8ec,0x92f0,0x11d0,<0xa7,0x90,0x00,0xc0,0x4f,0xd8,0xd5,0xa8>>
IDirectorySearch STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetSearchPreference PTR
	ExecuteSearch PTR
	AbandonSearch PTR
	GetFirstRow PTR
	GetNextRow PTR
	GetPreviousRow PTR
	GetNextColumnName PTR
	GetColumn PTR
	FreeColumn PTR
	CloseSearchHandle PTR
ENDS

#define GUID_IID_IDirectorySchemaMgmt <0x75db3b9c,0xa4d8,0x11d0,<0xa7,0x9c,0x00,0xc0,0x4f,0xd8,0xd5,0xa8>>
IDirectorySchemaMgmt STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	EnumAttributes PTR
	CreateAttributeDefinition PTR
	WriteAttributeDefinition PTR
	DeleteAttributeDefinition PTR
	EnumClasses PTR
	WriteClassDefinition PTR
	CreateClassDefinition PTR
	DeleteClassDefinition PTR
ENDS

#define GUID_IID_IADsAggregatee <0x1346ce8c,0x9039,0x11d0,<0x85,0x28,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IADsAggregatee STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ConnectAsAggregatee PTR
	DisconnectAsAggregatee PTR
	RelinquishInterface PTR
	RestoreInterface PTR
ENDS

#define GUID_IID_IADsAggregator <0x52db5fb0,0x941f,0x11d0,<0x85,0x29,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IADsAggregator STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ConnectAsAggregator PTR
	DisconnectAsAggregator PTR
ENDS

#define GUID_IID_IADsAccessControlEntry <0xb4f3a14c,0x9bdd,0x11d0,<0x85,0x2c,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IADsAccessControlEntry STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_AccessMask PTR
	put_AccessMask PTR
	get_AceType PTR
	put_AceType PTR
	get_AceFlags PTR
	put_AceFlags PTR
	get_Flags PTR
	put_Flags PTR
	get_ObjectType PTR
	put_ObjectType PTR
	get_InheritedObjectType PTR
	put_InheritedObjectType PTR
	get_Trustee PTR
	put_Trustee PTR
ENDS

#define GUID_IID_IIADsAccessControlList <0xb7ee91cc,0x9bdd,0x11d0,<0x85,0x2c,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IADsAccessControlList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_AclRevision PTR
	put_AclRevision PTR
	get_AceCount PTR
	put_AceCount PTR
	AddAce PTR
	RemoveAce PTR
	CopyAccessList PTR
	get__NewEnum PTR
ENDS

#define GUID_IID_IADsSecurityDescriptor <0xb8c787ca,0x9bdd,0x11d0,<0x85,0x2c,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IADsSecurityDescriptor STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Revision PTR
	put_Revision PTR
	get_Control PTR
	put_Control PTR
	get_Owner PTR
	put_Owner PTR
	get_OwnerDefaulted PTR
	put_OwnerDefaulted PTR
	get_Group PTR
	put_Group PTR
	get_GroupDefaulted PTR
	put_GroupDefaulted PTR
	get_DiscretionaryAcl PTR
	put_DiscretionaryAcl PTR
	get_DaclDefaulted PTR
	put_DaclDefaulted PTR
	get_SystemAcl PTR
	put_SystemAcl PTR
	get_SaclDefaulted PTR
	put_SaclDefaulted PTR
	CopySecurityDescriptor PTR
ENDS

#define GUID_IID_IADsLargeInteger <0x9068270b,0x0939,0x11d1,<0x8b,0xe1,0x00,0xc0,0x4f,0xd8,0xd5,0x03>>
IADsLargeInteger STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_HighPart PTR
	put_HighPart PTR
	get_LowPart PTR
	put_LowPart PTR
ENDS

#define GUID_IID_IADsNameTranslate <0xb1b272a3,0x3625,0x11d1,<0xa3,0xa4,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsNameTranslate STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	put_ChaseReferral PTR
	Init PTR
	InitEx PTR
	Set PTR
	Get PTR
	SetEx PTR
	GetEx PTR
ENDS

#define GUID_IID_IADsCaseIgnoreList <0x7b66b533,0x4680,0x11d1,<0xa3,0xb4,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsCaseIgnoreList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_CaseIgnoreList PTR
	put_CaseIgnoreList PTR
ENDS

#define GUID_IID_IADsFaxNumber <0xa910dea9,0x4680,0x11d1,<0xa3,0xb4,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsFaxNumber STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_TelephoneNumber PTR
	put_TelephoneNumber PTR
	get_Parameters PTR
	put_Parameters PTR
ENDS

#define GUID_IID_IADsNetAddress <0xb21a50a9,0x4080,0x11d1,<0xa3,0xac,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsNetAddress STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_AddressType PTR
	put_AddressType PTR
	get_Address PTR
	put_Address PTR
ENDS

#define GUID_IID_IADsOctetList <0x7b28b80f,0x4680,0x11d1,<0xa3,0xb4,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsOctetList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_OctetList PTR
	put_OctetList PTR
ENDS

#define GUID_IID_IADsEmail <0x97af011a,0x478e,0x11d1,<0xa3,0xb4,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsEmail STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Type PTR
	put_Type PTR
	get_Address PTR
	put_Address PTR
ENDS

#define GUID_IID_IADsPath <0xb287fcd5,0x4080,0x11d1,<0xa3,0xac,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsPath STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Type PTR
	put_Type PTR
	get_VolumeName PTR
	put_VolumeName PTR
	get_Path PTR
	put_Path PTR
ENDS

#define GUID_IID_IADsReplicaPointer <0xf60fb803,0x4080,0x11d1,<0xa3,0xac,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsReplicaPointer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_ServerName PTR
	put_ServerName PTR
	get_ReplicaType PTR
	put_ReplicaType PTR
	get_ReplicaNumber PTR
	put_ReplicaNumber PTR
	get_Count PTR
	put_Count PTR
	get_ReplicaAddressHints PTR
	put_ReplicaAddressHints PTR
ENDS

#define GUID_IID_IADsAcl <0x8452d3ab,0x0869,0x11d1,<0xa3,0x77,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsAcl STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_ProtectedAttrName PTR
	put_ProtectedAttrName PTR
	get_SubjectName PTR
	put_SubjectName PTR
	get_Privileges PTR
	put_Privileges PTR
	CopyAcl PTR
ENDS

#define GUID_IID_IADsTimestamp <0xb2f5a901,0x4080,0x11d1,<0xa3,0xac,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsTimestamp STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_WholeSeconds PTR
	put_WholeSeconds PTR
	get_EventID PTR
	put_EventID PTR
ENDS

#define GUID_IID_IADsPostalAddress <0x7adecf29,0x4680,0x11d1,<0xa3,0xb4,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsPostalAddress STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_PostalAddress PTR
	put_PostalAddress PTR
ENDS

#define GUID_IID_IADsBackLink <0xfd1302bd,0x4080,0x11d1,<0xa3,0xac,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsBackLink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_RemoteID PTR
	put_RemoteID PTR
	get_ObjectName PTR
	put_ObjectName PTR
ENDS

#define GUID_IID_IADsTypedName <0xb371a349,0x4080,0x11d1,<0xa3,0xac,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsTypedName STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_ObjectName PTR
	put_ObjectName PTR
	get_Level PTR
	put_Level PTR
	get_Interval PTR
	put_Interval PTR
ENDS

#define GUID_IID_IADsHold <0xb3eb3b37,0x4080,0x11d1,<0xa3,0xac,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsHold STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_ObjectName PTR
	put_ObjectName PTR
	get_Amount PTR
	put_Amount PTR
ENDS

#define GUID_IID_IADsObjectOptions <0x46f14fda,0x232b,0x11d1,<0xa8,0x08,0x00,0xc0,0x4f,0xd8,0xd5,0xa8>>
IADsObjectOptions STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	GetOption PTR
	SetOption PTR
ENDS

#define GUID_IID_IADsPathname <0xd592aed4,0xf420,0x11d0,<0xa3,0x6e,0x00,0xc0,0x4f,0xb9,0x50,0xdc>>
IADsPathname STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	Set PTR
	SetDisplayType PTR
	Retrieve PTR
	GetNumElements PTR
	GetElement PTR
	AddLeafElement PTR
	RemoveLeafElement PTR
	CopyPath PTR
	GetEscapedElement PTR
	get_EscapedMode PTR
	put_EscapedMode PTR
ENDS

#define GUID_IID_IADsADSystemInfo <0x5BB11929,0xAFD1,0x11d2,<0x9C,0xB9,0x00,0x00,0xF8,0x7A,0x36,0x9E>>
IADsADSystemInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_UserName PTR
	get_ComputerName PTR
	get_SiteName PTR
	get_DomainShortName PTR
	get_DomainDNSName PTR
	get_ForestDNSName PTR
	get_PDCRoleOwner PTR
	get_SchemaRoleOwner PTR
	get_IsNativeMode PTR
	GetAnyDCName PTR
	GetDCSiteName PTR
	RefreshSchemaCache PTR
	GetTrees PTR
ENDS

#define GUID_IID_IADsWinNTSystemInfo <0x6C6D65DC,0xAFD1,0x11d2,<0x9C,0xB9,0x00,0x00,0xF8,0x7A,0x36,0x9E>>
IADsWinNTSystemInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_UserName PTR
	get_ComputerName PTR
	get_DomainName PTR
	get_PDC PTR
ENDS

#define GUID_IID_IADsDNWithBinary <0x7e99c0a2,0xf935,0x11d2,<0xba,0x96,0x00,0xc0,0x4f,0xb6,0xd0,0xd1>>
IADsDNWithBinary STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_BinaryValue PTR
	put_BinaryValue PTR
	get_DNString PTR
	put_DNString PTR
ENDS

#define GUID_IID_IADsDNWithString <0x370df02e,0xf934,0x11d2,<0xba,0x96,0x00,0xc0,0x4f,0xb6,0xd0,0xd1>>
IADsDNWithString STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_StringValue PTR
	put_StringValue PTR
	get_DNString PTR
	put_DNString PTR
ENDS

#define GUID_IID_IADsSecurityUtility <0xa63251b2,0x5f21,0x474b,<0xab,0x52,0x4a,0x8e,0xfa,0xd1,0x08,0x95>>
IADsSecurityUtility STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	GetSecurityDescriptor PTR
	SetSecurityDescriptor PTR
	ConvertSecurityDescriptor PTR
	get_SecurityMask PTR
	put_SecurityMask PTR
ENDS

#endif

