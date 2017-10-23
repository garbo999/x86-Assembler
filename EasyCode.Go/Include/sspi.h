#ifndef SSPI_H
#define SSPI_H

/*
Switches

*** The following 2 switches are mutually exlusive, one must be defined
SECURITY_WIN32
SECURITY_KERNEL
*/

#IFNDEF SECURITY_WIN32
	#IFNDEF SECURITY_KERNEL
		#define SECURITY_WIN32
	#ENDIF
#ENDIF

#IFDEF LINKFILES
	#dynamiclinkfile Secur32.dll
#ENDIF

/* Security Support Provider Interface (SSPI) definitions */

#ifdef SECURITY_WIN32
	#define ISSP_LEVEL  32
	#define ISSP_MODE  1
#endif

#ifdef SECURITY_KERNEL
	#define ISSP_LEVEL  32
	#ifdef ISSP_MODE
		#undef ISSP_MODE
	#endif
	#define ISSP_MODE  0
#endif /* SECURITY_KERNEL */

TimeStamp = FILETIME

SecHandle STRUCT
	dwLower DD
	dwUpper DD
ENDS

SECURITY_INTEGER STRUCT
	LowPart DD
	HighPart DD
ENDS

SECURITY_STRING STRUCT
	Length DW
	MaximumLength DW
	Buffer PTR
ENDS

SecPkgInfoW STRUCT
	fCapabilities DD
	wVersion DW
	wRPCID DW
	cbMaxToken DD
	Name PTR
	Comment PTR
ENDS

SecPkgInfoA STRUCT
	fCapabilities DD
	wVersion DW
	wRPCID DW
	cbMaxToken DD
	Name PTR
	Comment PTR
ENDS

#define SECPKG_FLAG_INTEGRITY  0x00000001
#define SECPKG_FLAG_PRIVACY  0x00000002
#define SECPKG_FLAG_TOKEN_ONLY  0x00000004
#define SECPKG_FLAG_DATAGRAM  0x00000008
#define SECPKG_FLAG_CONNECTION  0x00000010
#define SECPKG_FLAG_MULTI_REQUIRED  0x00000020
#define SECPKG_FLAG_CLIENT_ONLY  0x00000040
#define SECPKG_FLAG_EXTENDED_ERROR  0x00000080
#define SECPKG_FLAG_IMPERSONATION  0x00000100
#define SECPKG_FLAG_ACCEPT_WIN32_NAME  0x00000200
#define SECPKG_FLAG_STREAM  0x00000400
#define SECPKG_FLAG_NEGOTIABLE  0x00000800
#define SECPKG_FLAG_GSS_COMPATIBLE  0x00001000
#define SECPKG_FLAG_LOGON  0x00002000
#define SECPKG_FLAG_ASCII_BUFFERS  0x00004000
#define SECPKG_FLAG_FRAGMENT  0x00008000
#define SECPKG_FLAG_MUTUAL_AUTH  0x00010000
#define SECPKG_FLAG_DELEGATION  0x00020000

#define SECPKG_ID_NONE  0xFFFF

SecBuffer STRUCT
	cbBuffer DD
	BufferType DD
	pvBuffer PTR
ENDS

SecBufferDesc STRUCT
	ulVersion DD
	cBuffers DD
	pBuffers PTR
ENDS

#define SECBUFFER_VERSION  0

#define SECBUFFER_EMPTY  0
#define SECBUFFER_DATA  1
#define SECBUFFER_TOKEN  2
#define SECBUFFER_PKG_PARAMS  3
#define SECBUFFER_MISSING  4
#define SECBUFFER_EXTRA  5
#define SECBUFFER_STREAM_TRAILER  6
#define SECBUFFER_STREAM_HEADER  7
#define SECBUFFER_NEGOTIATION_INFO  8
#define SECBUFFER_PADDING  9
#define SECBUFFER_STREAM  10
#define SECBUFFER_MECHLIST  11
#define SECBUFFER_MECHLIST_SIGNATURE 12

#define SECBUFFER_ATTRMASK  0xF0000000
#define SECBUFFER_READONLY  0x80000000
#define SECBUFFER_RESERVED  0x40000000

SEC_NEGOTIATION_INFO STRUCT
	Size DD
	NameLength DD
	Name PTR
	Reserved DD
ENDS

#define SECURITY_NATIVE_DREP  0x00000010
#define SECURITY_NETWORK_DREP  0x00000000

#define SECPKG_CRED_INBOUND  0x00000001
#define SECPKG_CRED_OUTBOUND  0x00000002
#define SECPKG_CRED_BOTH  0x00000003
#define SECPKG_CRED_DEFAULT  0x00000004
#define SECPKG_CRED_RESERVED  0xF0000000

#define ISC_REQ_DELEGATE  0x00000001
#define ISC_REQ_MUTUAL_AUTH  0x00000002
#define ISC_REQ_REPLAY_DETECT  0x00000004
#define ISC_REQ_SEQUENCE_DETECT  0x00000008
#define ISC_REQ_CONFIDENTIALITY  0x00000010
#define ISC_REQ_USE_SESSION_KEY  0x00000020
#define ISC_REQ_PROMPT_FOR_CREDS  0x00000040
#define ISC_REQ_USE_SUPPLIED_CREDS  0x00000080
#define ISC_REQ_ALLOCATE_MEMORY  0x00000100
#define ISC_REQ_USE_DCE_STYLE  0x00000200
#define ISC_REQ_DATAGRAM  0x00000400
#define ISC_REQ_CONNECTION  0x00000800
#define ISC_REQ_CALL_LEVEL  0x00001000
#define ISC_REQ_FRAGMENT_SUPPLIED  0x00002000
#define ISC_REQ_EXTENDED_ERROR  0x00004000
#define ISC_REQ_STREAM  0x00008000
#define ISC_REQ_INTEGRITY  0x00010000
#define ISC_REQ_IDENTIFY  0x00020000
#define ISC_REQ_NULL_SESSION  0x00040000
#define ISC_REQ_MANUAL_CRED_VALIDATION  0x00080000
#define ISC_REQ_RESERVED1  0x00100000
#define ISC_REQ_FRAGMENT_TO_FIT  0x00200000

#define ISC_RET_DELEGATE  0x00000001
#define ISC_RET_MUTUAL_AUTH  0x00000002
#define ISC_RET_REPLAY_DETECT  0x00000004
#define ISC_RET_SEQUENCE_DETECT  0x00000008
#define ISC_RET_CONFIDENTIALITY  0x00000010
#define ISC_RET_USE_SESSION_KEY  0x00000020
#define ISC_RET_USED_COLLECTED_CREDS  0x00000040
#define ISC_RET_USED_SUPPLIED_CREDS  0x00000080
#define ISC_RET_ALLOCATED_MEMORY  0x00000100
#define ISC_RET_USED_DCE_STYLE  0x00000200
#define ISC_RET_DATAGRAM  0x00000400
#define ISC_RET_CONNECTION  0x00000800
#define ISC_RET_INTERMEDIATE_RETURN  0x00001000
#define ISC_RET_CALL_LEVEL  0x00002000
#define ISC_RET_EXTENDED_ERROR  0x00004000
#define ISC_RET_STREAM  0x00008000
#define ISC_RET_INTEGRITY  0x00010000
#define ISC_RET_IDENTIFY  0x00020000
#define ISC_RET_NULL_SESSION  0x00040000
#define ISC_RET_MANUAL_CRED_VALIDATION  0x00080000
#define ISC_RET_RESERVED1  0x00100000
#define ISC_RET_FRAGMENT_ONLY  0x00200000

#define ASC_REQ_DELEGATE  0x00000001
#define ASC_REQ_MUTUAL_AUTH  0x00000002
#define ASC_REQ_REPLAY_DETECT  0x00000004
#define ASC_REQ_SEQUENCE_DETECT  0x00000008
#define ASC_REQ_CONFIDENTIALITY  0x00000010
#define ASC_REQ_USE_SESSION_KEY  0x00000020
#define ASC_REQ_ALLOCATE_MEMORY  0x00000100
#define ASC_REQ_USE_DCE_STYLE  0x00000200
#define ASC_REQ_DATAGRAM  0x00000400
#define ASC_REQ_CONNECTION  0x00000800
#define ASC_REQ_CALL_LEVEL  0x00001000
#define ASC_REQ_EXTENDED_ERROR  0x00008000
#define ASC_REQ_STREAM  0x00010000
#define ASC_REQ_INTEGRITY  0x00020000
#define ASC_REQ_LICENSING  0x00040000
#define ASC_REQ_IDENTIFY  0x00080000
#define ASC_REQ_ALLOW_NULL_SESSION  0x00100000
#define ASC_REQ_ALLOW_NON_USER_LOGONS  0x00200000
#define ASC_REQ_ALLOW_CONTEXT_REPLAY  0x00400000
#define ASC_REQ_FRAGMENT_TO_FIT  0x00800000
#define ASC_REQ_FRAGMENT_SUPPLIED  0x00002000

#define ASC_RET_DELEGATE  0x00000001
#define ASC_RET_MUTUAL_AUTH  0x00000002
#define ASC_RET_REPLAY_DETECT  0x00000004
#define ASC_RET_SEQUENCE_DETECT  0x00000008
#define ASC_RET_CONFIDENTIALITY  0x00000010
#define ASC_RET_USE_SESSION_KEY  0x00000020
#define ASC_RET_ALLOCATED_MEMORY  0x00000100
#define ASC_RET_USED_DCE_STYLE  0x00000200
#define ASC_RET_DATAGRAM  0x00000400
#define ASC_RET_CONNECTION  0x00000800
#define ASC_RET_CALL_LEVEL  0x00002000
#define ASC_RET_THIRD_LEG_FAILED  0x00004000
#define ASC_RET_EXTENDED_ERROR  0x00008000
#define ASC_RET_STREAM  0x00010000
#define ASC_RET_INTEGRITY  0x00020000
#define ASC_RET_LICENSING  0x00040000
#define ASC_RET_IDENTIFY  0x00080000
#define ASC_RET_NULL_SESSION  0x00100000
#define ASC_RET_ALLOW_NON_USER_LOGONS  0x00200000
#define ASC_RET_ALLOW_CONTEXT_REPLAY  0x00400000
#define ASC_RET_FRAGMENT_ONLY  0x00800000

#define SECPKG_CRED_ATTR_NAMES  1

SecPkgCredentials_NamesW STRUCT
	sUserName PTR
ENDS

SecPkgCredentials_NamesA STRUCT
	sUserName PTR
ENDS

#define SECPKG_ATTR_SIZES  0
#define SECPKG_ATTR_NAMES  1
#define SECPKG_ATTR_LIFESPAN  2
#define SECPKG_ATTR_DCE_INFO  3
#define SECPKG_ATTR_STREAM_SIZES  4
#define SECPKG_ATTR_KEY_INFO  5
#define SECPKG_ATTR_AUTHORITY  6
#define SECPKG_ATTR_PROTO_INFO  7
#define SECPKG_ATTR_PASSWORD_EXPIRY 8
#define SECPKG_ATTR_SESSION_KEY  9
#define SECPKG_ATTR_PACKAGE_INFO  10
#define SECPKG_ATTR_USER_FLAGS  11
#define SECPKG_ATTR_NEGOTIATION_INFO 12
#define SECPKG_ATTR_NATIVE_NAMES  13
#define SECPKG_ATTR_FLAGS  14

SecPkgContext_Sizes STRUCT
	cbMaxToken DD
	cbMaxSignature DD
	cbBlockSize DD
	cbSecurityTrailer DD
ENDS

SecPkgContext_StreamSizes STRUCT
	cbHeader DD
	cbTrailer DD
	cbMaximumMessage DD
	cBuffers DD
	cbBlockSize DD
ENDS

SecPkgContext_NamesW STRUCT
	sUserName PTR
ENDS

SecPkgContext_NamesA STRUCT
	sUserName PTR
ENDS

SecPkgContext_Lifespan STRUCT
	tsStart TimeStamp
	tsExpiry TimeStamp
ENDS

SecPkgContext_DceInfo STRUCT
	AuthzSvc DD
	pPac PTR
ENDS

SecPkgContext_KeyInfoA STRUCT
	sSignatureAlgorithmName PTR
	sEncryptAlgorithmName PTR
	KeySize DD
	SignatureAlgorithm DD
	EncryptAlgorithm DD
ENDS

SecPkgContext_KeyInfoW STRUCT
	sSignatureAlgorithmName PTR
	sEncryptAlgorithmName PTR
	KeySize DD
	SignatureAlgorithm DD
	EncryptAlgorithm DD
ENDS

SecPkgContext_AuthorityA STRUCT
	sAuthorityName PTR
ENDS

SecPkgContext_AuthorityW STRUCT
	sAuthorityName PTR
ENDS

SecPkgContext_ProtoInfoA STRUCT
	sProtocolName PTR
	majorVersion DD
	minorVersion DD
ENDS

SecPkgContext_ProtoInfoW STRUCT
	sProtocolName PTR
	majorVersion DD
	minorVersion DD
ENDS

SecPkgContext_PasswordExpiry STRUCT
	tsPasswordExpires TimeStamp
ENDS

SecPkgContext_SessionKey STRUCT
	SessionKeyLength DD
	SessionKey PTR
ENDS

SecPkgContext_PackageInfoW STRUCT
	PackageInfo PTR
ENDS

SecPkgContext_PackageInfoA STRUCT
	PackageInfo PTR
ENDS

SecPkgContext_UserFlags STRUCT
	UserFlags DD
ENDS

SecPkgContext_Flags STRUCT
	Flags DD
ENDS

SecPkgContext_NegotiationInfoA STRUCT
	PackageInfo PTR
	NegotiationState DD
ENDS

SecPkgContext_NegotiationInfoW STRUCT
	PackageInfo PTR
	NegotiationState DD
ENDS

#define SECPKG_NEGOTIATION_COMPLETE  0
#define SECPKG_NEGOTIATION_OPTIMISTIC  1
#define SECPKG_NEGOTIATION_IN_PROGRESS  2
#define SECPKG_NEGOTIATION_DIRECT  3

SecPkgContext_NativeNamesW STRUCT
	sClientName PTR
	sServerName PTR
ENDS

SecPkgContext_NativeNamesA STRUCT
	sClientName PTR
	sServerName PTR
ENDS

#define SECPKG_CONTEXT_EXPORT_RESET_NEW  0x00000001
#define SECPKG_CONTEXT_EXPORT_DELETE_OLD  0x00000002

SecFull = 0
SecService = 1
SecTree = 2
SecDirectory = 3
SecObject = 4

#define SECURITY_ENTRYPOINT_ANSIW L"InitSecurityInterfaceW"
#define SECURITY_ENTRYPOINT_ANSIA A"InitSecurityInterfaceA"
#define SECURITY_ENTRYPOINTW W"InitSecurityInterfaceW"
#define SECURITY_ENTRYPOINTA A"InitSecurityInterfaceA"
#define SECURITY_ENTRYPOINT16 "INITSECURITYINTERFACEA"

#define FreeCredentialHandle FreeCredentialsHandle

SECURITY_FUNCTION_TABLE_W STRUCT
	dwVersion DD
	EnumerateSecurityPackagesW DD
	QueryCredentialsAttributesW DD
	AcquireCredentialsHandleW DD
	FreeCredentialsHandle DD
	Reserved2 DD
	InitializeSecurityContextW DD
	AcceptSecurityContext DD
	CompleteAuthToken DD
	DeleteSecurityContext DD
	ApplyControlToken DD
	QueryContextAttributesW DD
	ImpersonateSecurityContext DD
	RevertSecurityContext DD
	MakeSignature DD
	VerifySignature DD
	FreeContextBuffer DD
	QuerySecurityPackageInfoW DD
	Reserved3 DD
	Reserved4 DD
	ExportSecurityContext DD
	ImportSecurityContextW DD
	AddCredentialsW DD
	Reserved8 DD
	QuerySecurityContextToken DD
	EncryptMessage DD
	DecryptMessage DD
ENDS

SECURITY_FUNCTION_TABLE_A STRUCT
	dwVersion DD
	EnumerateSecurityPackagesA DD
	QueryCredentialsAttributesA DD
	AcquireCredentialsHandleA DD
	FreeCredentialsHandle DD
	Reserved2 DD
	InitializeSecurityContextA DD
	AcceptSecurityContext DD
	CompleteAuthToken DD
	DeleteSecurityContext DD
	ApplyControlToken DD
	QueryContextAttributesA DD
	ImpersonateSecurityContext DD
	RevertSecurityContext DD
	MakeSignature DD
	VerifySignature DD
	FreeContextBuffer DD
	QuerySecurityPackageInfoA DD
	Reserved3 DD
	Reserved4 DD
	ExportSecurityContext DD
	ImportSecurityContextA DD
	AddCredentialsA DD
	Reserved8 DD
	QuerySecurityContextToken DD
	EncryptMessage DD
	DecryptMessage DD
ENDS

#IFDEF UNICODE
	#define AcquireCredentialsHandle AcquireCredentialsHandleW
	#define SECURITY_ENTRYPOINT SECURITY_ENTRYPOINTW
	#define SECURITY_ENTRYPOINT_ANSI SECURITY_ENTRYPOINT_ANSIW
	#define AddCredentials  AddCredentialsW
	#define SspiLogonUser SspiLogonUserW
	#define InitializeSecurityContext InitializeSecurityContextW
	#define QueryContextAttributes QueryContextAttributesW
	#define QueryCredentialsAttributes QueryCredentialsAttributesW
	#define EnumerateSecurityPackages EnumerateSecurityPackagesW
	#define QuerySecurityPackageInfo QuerySecurityPackageInfoW
	#define SaslInitializeSecurityContext  SaslInitializeSecurityContextW
	#define SaslIdentifyPackage SaslIdentifyPackageW
	#define SaslGetProfilePackage  SaslGetProfilePackageW
	#define SaslEnumerateProfiles  SaslEnumerateProfilesW
	#define InitSecurityInterface InitSecurityInterfaceW
	#define INIT_SECURITY_INTERFACE INIT_SECURITY_INTERFACE_W
	#define SecurityFunctionTable SecurityFunctionTableW
	#define ImportSecurityContext ImportSecurityContextW
	#define SecPkgInfo SecPkgInfoW
	#define SecPkgCredentials_Names SecPkgCredentials_NamesW
	#define SecPkgContext_Names SecPkgContext_NamesW
	#define SecPkgContext_KeyInfo  SecPkgContext_KeyInfoW
	#define SecPkgContext_Authority SecPkgContext_AuthorityW
	#define SecPkgContext_ProtoInfo  SecPkgContext_ProtoInfoW
	#define SecPkgContext_PackageInfo  SecPkgContext_PackageInfoW
	#define SecPkgContext_NegotiationInfo  SecPkgContext_NegotiationInfoW
	#define SecPkgContext_NativeNames SecPkgContext_NativeNamesW
#else
	#define AcquireCredentialsHandle AcquireCredentialsHandleA
	#define SECURITY_ENTRYPOINT SECURITY_ENTRYPOINTA
	#define SECURITY_ENTRYPOINT_ANSI SECURITY_ENTRYPOINT_ANSIA
	#define AddCredentials  AddCredentialsA
	#define SspiLogonUser SspiLogonUserA
	#define InitializeSecurityContext InitializeSecurityContextA
	#define QueryContextAttributes QueryContextAttributesA
	#define QueryCredentialsAttributes QueryCredentialsAttributesA
	#define EnumerateSecurityPackages EnumerateSecurityPackagesA
	#define QuerySecurityPackageInfo QuerySecurityPackageInfoA
	#define SaslInitializeSecurityContext  SaslInitializeSecurityContextA
	#define SaslIdentifyPackage SaslIdentifyPackageA
	#define SaslGetProfilePackage  SaslGetProfilePackageA
	#define SaslEnumerateProfiles  SaslEnumerateProfilesA
	#define InitSecurityInterface InitSecurityInterfaceA
	#define INIT_SECURITY_INTERFACE INIT_SECURITY_INTERFACE_A
	#define SecurityFunctionTable SecurityFunctionTableA
	#define ImportSecurityContext ImportSecurityContextA
	#define SecPkgInfo SecPkgInfoA
	#define SecPkgCredentials_Names SecPkgCredentials_NamesA
	#define SecPkgContext_Names SecPkgContext_NamesA
	#define SecPkgContext_KeyInfo  SecPkgContext_KeyInfoA
	#define SecPkgContext_Authority SecPkgContext_AuthorityA
	#define SecPkgContext_ProtoInfo  SecPkgContext_ProtoInfoA
	#define SecPkgContext_PackageInfo  SecPkgContext_PackageInfoA
	#define SecPkgContext_NegotiationInfo  SecPkgContext_NegotiationInfoA
	#define SecPkgContext_NativeNames SecPkgContext_NativeNamesA
#endif

#endif /* _SSPI_H */
