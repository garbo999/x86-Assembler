#ifndef RPCDCE_H
#define RPCDCE_H

/* Windows DCE RPC runtime API definitions */

RPC_BINDING_VECTOR STRUCT
	Count DD
	BindingH HANDLE
ENDS

#IFDEF LINKFILES
	#dynamiclinkfile Rpcrt4.dll
#ENDIF

#ifndef IFID_DEFINED
	#define IFID_DEFINED
	RPC_IF_ID STRUCT
		Uuid GUID <>
		VersMajor DW
		VersMinor DW
	ENDS
#endif

#define RPC_C_BINDING_INFINITE_TIMEOUT  10
#define RPC_C_BINDING_MIN_TIMEOUT  0
#define RPC_C_BINDING_DEFAULT_TIMEOUT  5
#define RPC_C_BINDING_MAX_TIMEOUT  9

#define RPC_C_CANCEL_INFINITE_TIMEOUT  -1

#define RPC_C_LISTEN_MAX_CALLS_DEFAULT  1234
#define RPC_C_PROTSEQ_MAX_REQS_DEFAULT  10

#define RPC_C_BIND_TO_ALL_NICS  1
#define RPC_C_USE_INTERNET_PORT  0x1
#define RPC_C_USE_INTRANET_PORT  0x2
#define RPC_C_DONT_FAIL  0x4

#define RPC_C_MQ_TEMPORARY  0x0000
#define RPC_C_MQ_PERMANENT  0x0001
#define RPC_C_MQ_CLEAR_ON_OPEN  0x0002
#define RPC_C_MQ_USE_EXISTING_SECURITY  0x0004
#define RPC_C_MQ_AUTHN_LEVEL_NONE  0x0000
#define RPC_C_MQ_AUTHN_LEVEL_PKT_INTEGRITY  0x0008
#define RPC_C_MQ_AUTHN_LEVEL_PKT_PRIVACY  0x0010

#define RPC_C_OPT_MQ_DELIVERY  1
#define RPC_C_OPT_MQ_PRIORITY  2
#define RPC_C_OPT_MQ_JOURNAL  3
#define RPC_C_OPT_MQ_ACKNOWLEDGE  4
#define RPC_C_OPT_MQ_AUTHN_SERVICE  5
#define RPC_C_OPT_MQ_AUTHN_LEVEL  6
#define RPC_C_OPT_MQ_TIME_TO_REACH_QUEUE  7
#define RPC_C_OPT_MQ_TIME_TO_BE_RECEIVED  8
#define RPC_C_OPT_BINDING_NONCAUSAL  9
#define RPC_C_OPT_SECURITY_CALLBACK  10
#define RPC_C_OPT_UNIQUE_BINDING  11
#define RPC_C_OPT_MAX_OPTIONS  12

#define RPC_C_MQ_EXPRESS  0
#define RPC_C_MQ_RECOVERABLE  1

#define RPC_C_MQ_JOURNAL_NONE  0
#define RPC_C_MQ_JOURNAL_DEADLETTER  1
#define RPC_C_MQ_JOURNAL_ALWAYS  2

#define RPC_C_FULL_CERT_CHAIN  0x0001

#define RPC_C_AUTHN_LEVEL_DEFAULT  0
#define RPC_C_AUTHN_LEVEL_NONE  1
#define RPC_C_AUTHN_LEVEL_CONNECT  2
#define RPC_C_AUTHN_LEVEL_CALL  3
#define RPC_C_AUTHN_LEVEL_PKT  4
#define RPC_C_AUTHN_LEVEL_PKT_INTEGRITY  5
#define RPC_C_AUTHN_LEVEL_PKT_PRIVACY  6

#define RPC_C_IMP_LEVEL_DEFAULT  0
#define RPC_C_IMP_LEVEL_ANONYMOUS  1
#define RPC_C_IMP_LEVEL_IDENTIFY  2
#define RPC_C_IMP_LEVEL_IMPERSONATE  3
#define RPC_C_IMP_LEVEL_DELEGATE  4

#define RPC_C_QOS_IDENTITY_STATIC  0
#define RPC_C_QOS_IDENTITY_DYNAMIC  1

#define RPC_C_QOS_CAPABILITIES_DEFAULT  0
#define RPC_C_QOS_CAPABILITIES_MUTUAL_AUTH  1
#define RPC_C_QOS_CAPABILITIES_MAKE_FULLSIC  2
#define RPC_C_QOS_CAPABILITIES_ANY_AUTHORITY  4

#define RPC_C_PROTECT_LEVEL_DEFAULT  (RPC_C_AUTHN_LEVEL_DEFAULT)
#define RPC_C_PROTECT_LEVEL_NONE  (RPC_C_AUTHN_LEVEL_NONE)
#define RPC_C_PROTECT_LEVEL_CONNECT  (RPC_C_AUTHN_LEVEL_CONNECT)
#define RPC_C_PROTECT_LEVEL_CALL  (RPC_C_AUTHN_LEVEL_CALL)
#define RPC_C_PROTECT_LEVEL_PKT  (RPC_C_AUTHN_LEVEL_PKT)
#define RPC_C_PROTECT_LEVEL_PKT_INTEGRITY  (RPC_C_AUTHN_LEVEL_PKT_INTEGRITY)
#define RPC_C_PROTECT_LEVEL_PKT_PRIVACY  (RPC_C_AUTHN_LEVEL_PKT_PRIVACY)

#define RPC_C_AUTHN_NONE  0
#define RPC_C_AUTHN_DCE_PRIVATE  1
#define RPC_C_AUTHN_DCE_PUBLIC  2
#define RPC_C_AUTHN_DEC_PUBLIC  4
#define RPC_C_AUTHN_GSS_NEGOTIATE  9
#define RPC_C_AUTHN_WINNT  10
#define RPC_C_AUTHN_GSS_SCHANNEL  14
#define RPC_C_AUTHN_GSS_KERBEROS  16
#define RPC_C_AUTHN_DPA  17
#define RPC_C_AUTHN_MSN  18
#define RPC_C_AUTHN_MQ  100
#define RPC_C_AUTHN_DEFAULT  0xFFFFFFFF

;#define RPC_C_NO_CREDENTIALS  ((RPC_AUTH_IDENTITY_HANDLE)~0UL)

#define RPC_C_SECURITY_QOS_VERSION  1

#define RPC_C_STATS_CALLS_IN  0
#define RPC_C_STATS_CALLS_OUT  1
#define RPC_C_STATS_PKTS_IN  2
#define RPC_C_STATS_PKTS_OUT  3

#define RPC_MGR_EPV void

#define SEC_WINNT_AUTH_IDENTITY_ANSI  0x1
#define SEC_WINNT_AUTH_IDENTITY_UNICODE  0x2

#define RPC_C_AUTHZ_NONE  0
#define RPC_C_AUTHZ_NAME  1
#define RPC_C_AUTHZ_DCE  2
#define RPC_C_AUTHZ_DEFAULT  0xFFFFFFFF

#define DCE_C_ERROR_STRING_LEN  256

#define RPC_C_EP_ALL_ELTS  0
#define RPC_C_EP_MATCH_BY_IF  1
#define RPC_C_EP_MATCH_BY_OBJ  2
#define RPC_C_EP_MATCH_BY_BOTH  3

#define RPC_C_VERS_ALL  1
#define RPC_C_VERS_COMPATIBLE  2
#define RPC_C_VERS_EXACT  3
#define RPC_C_VERS_MAJOR_ONLY  4
#define RPC_C_VERS_UPTO  5

#define RPC_C_MGMT_INQ_IF_IDS  0
#define RPC_C_MGMT_INQ_PRINC_NAME  1
#define RPC_C_MGMT_INQ_STATS  2
#define RPC_C_MGMT_IS_SERVER_LISTEN  3
#define RPC_C_MGMT_STOP_SERVER_LISTEN  4

#define RPC_C_PARM_MAX_PACKET_LENGTH  1
#define RPC_C_PARM_BUFFER_LENGTH  2

#define RPC_IF_AUTOLISTEN  0x0001
#define RPC_IF_OLE  0x0002
#define RPC_IF_ALLOW_UNKNOWN_AUTHORITY  0x0004
#define RPC_IF_ALLOW_SECURE_ONLY  0x0008

RPC_PROTSEQ_VECTORA STRUCT
	Count DD
	Protseq DB
ENDS

RPC_PROTSEQ_VECTORW STRUCT
	Count DD
	Protseq DB
ENDS

RPC_POLICY STRUCT
	Length DD
	EndpointFlags DD
	NICFlags DD
ENDS

RPC_STATS_VECTOR STRUCT
	Count DD
	Stats DD
ENDS

RPC_IF_ID_VECTOR STRUCT
	Count DD
	IfId PTR
ENDS

RPC_SECURITY_QOS STRUCT
	Version DD
	Capabilities DD
	IdentityTracking DD
	ImpersonationType DD
ENDS

SEC_WINNT_AUTH_IDENTITY_W STRUCT
	User PTR
	UserLength DD
	Domain PTR
	DomainLength DD
	Password PTR
	PasswordLength DD
	Flags DD
ENDS

SEC_WINNT_AUTH_IDENTITY_A STRUCT
	User PTR
	UserLength DD
	Domain PTR
	DomainLength DD
	Password PTR
	PasswordLength DD
	Flags DD
ENDS

RPC_CLIENT_INFORMATION1 STRUCT
	UserName DD
	ComputerName PTR
	Privilege DD
	AuthFlags DD
ENDS

#IFDEF UNICODE
	#define SEC_WINNT_AUTH_IDENTITY SEC_WINNT_AUTH_IDENTITY_W
	#define RPC_PROTSEQ_VECTOR RPC_PROTSEQ_VECTORW
	#define RpcBindingFromStringBinding RpcBindingFromStringBindingW
	#define RpcBindingToStringBinding RpcBindingToStringBindingW
	#define RpcStringBindingCompose RpcStringBindingComposeW
	#define RpcStringBindingParse RpcStringBindingParseW
	#define RpcStringFree RpcStringFreeW
	#define RpcNetworkIsProtseqValid RpcNetworkIsProtseqValidW
	#define RpcNetworkInqProtseqs RpcNetworkInqProtseqsW
	#define RpcProtseqVectorFree RpcProtseqVectorFreeW
	#define RpcServerUseProtseq RpcServerUseProtseqW
	#define RpcServerUseProtseqEx RpcServerUseProtseqExW
	#define RpcServerUseProtseqEp RpcServerUseProtseqEpW
	#define RpcServerUseProtseqEpEx RpcServerUseProtseqEpExW
	#define RpcServerUseProtseqIf RpcServerUseProtseqIfW
	#define RpcServerUseProtseqIfEx RpcServerUseProtseqIfExW
	#define RpcMgmtInqServerPrincName RpcMgmtInqServerPrincNameW
	#define RpcServerInqDefaultPrincName RpcServerInqDefaultPrincNameW
	#define RpcNsBindingInqEntryName RpcNsBindingInqEntryNameW
	#define RpcBindingInqAuthClient RpcBindingInqAuthClientW
	#define RpcBindingInqAuthClientEx RpcBindingInqAuthClientExW
	#define RpcBindingInqAuthInfo RpcBindingInqAuthInfoW
	#define RpcBindingSetAuthInfo RpcBindingSetAuthInfoW
	#define RpcServerRegisterAuthInfo RpcServerRegisterAuthInfoW
	#define RpcBindingInqAuthInfoEx RpcBindingInqAuthInfoExW
	#define RpcBindingSetAuthInfoEx RpcBindingSetAuthInfoExW
	#define UuidFromString UuidFromStringW
	#define UuidToString UuidToStringW
	#define RpcEpRegisterNoReplace RpcEpRegisterNoReplaceW
	#define RpcEpRegister RpcEpRegisterW
	#define DceErrorInqText DceErrorInqTextW
	#define RpcMgmtEpEltInqNext RpcMgmtEpEltInqNextW
#else
	#define SEC_WINNT_AUTH_IDENTITY SEC_WINNT_AUTH_IDENTITY_A
	#define RPC_PROTSEQ_VECTOR RPC_PROTSEQ_VECTORA
	#define RpcBindingFromStringBinding RpcBindingFromStringBindingA
	#define RpcBindingToStringBinding RpcBindingToStringBindingA
	#define RpcStringBindingCompose RpcStringBindingComposeA
	#define RpcStringBindingParse RpcStringBindingParseA
	#define RpcStringFree RpcStringFreeA
	#define RpcNetworkIsProtseqValid RpcNetworkIsProtseqValidA
	#define RpcNetworkInqProtseqs RpcNetworkInqProtseqsA
	#define RpcProtseqVectorFree RpcProtseqVectorFreeA
	#define RpcServerUseProtseq RpcServerUseProtseqA
	#define RpcServerUseProtseqEx RpcServerUseProtseqExA
	#define RpcServerUseProtseqEp RpcServerUseProtseqEpA
	#define RpcServerUseProtseqEpEx RpcServerUseProtseqEpExA
	#define RpcServerUseProtseqIf RpcServerUseProtseqIfA
	#define RpcServerUseProtseqIfEx RpcServerUseProtseqIfExA
	#define RpcMgmtInqServerPrincName RpcMgmtInqServerPrincNameA
	#define RpcServerInqDefaultPrincName RpcServerInqDefaultPrincNameA
	#define RpcNsBindingInqEntryName RpcNsBindingInqEntryNameA
	#define RpcBindingInqAuthClient RpcBindingInqAuthClientA
	#define RpcBindingInqAuthClientEx RpcBindingInqAuthClientExA
	#define RpcBindingInqAuthInfo RpcBindingInqAuthInfoA
	#define RpcBindingSetAuthInfo RpcBindingSetAuthInfoA
	#define RpcServerRegisterAuthInfo RpcServerRegisterAuthInfoA
	#define RpcBindingInqAuthInfoEx RpcBindingInqAuthInfoExA
	#define RpcBindingSetAuthInfoEx RpcBindingSetAuthInfoExA
	#define UuidFromString UuidFromStringA
	#define UuidToString UuidToStringA
	#define RpcEpRegisterNoReplace RpcEpRegisterNoReplaceA
	#define RpcEpRegister RpcEpRegisterA
	#define DceErrorInqText DceErrorInqTextA
	#define RpcMgmtEpEltInqNext RpcMgmtEpEltInqNextA
#endif /* UNICODE */

#endif /* _RPCDCE_H */

