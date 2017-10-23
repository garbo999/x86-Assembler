;=============================================================;
;          rpcdce.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF RPCDCE_INC
#Define RPCDCE_INC

#IFNDEF GUID_DEFINED
	#Define GUID_DEFINED
	GUID Struct
	    Data1 DD
	    Data2 DW
	    Data3 DW
	    Data4 DB 8 Dup ?
	EndS
#ENDIF

RPC_BINDING_VECTOR Struct
	Count DD
	BindingH DD
EndS

UUID_VECTOR Struct
  Count DD
  Uuid DD
EndS

#IFNDEF IFID_DEFINED
	#Define IFID_DEFINED
	RPC_IF_ID Struct
		Uuid GUID <>
		VersMajor DW
		VersMinor DW
	EndS
#ENDIF

#Define RPC_C_BINDING_INFINITE_TIMEOUT      10
#Define RPC_C_BINDING_MIN_TIMEOUT           0
#Define RPC_C_BINDING_DEFAULT_TIMEOUT       5
#Define RPC_C_BINDING_MAX_TIMEOUT           9

#Define RPC_C_CANCEL_INFINITE_TIMEOUT       (-1)

#Define RPC_C_LISTEN_MAX_CALLS_DEFAULT      1234
#Define RPC_C_PROTSEQ_MAX_REQS_DEFAULT      10

#Define RPC_C_BIND_TO_ALL_NICS              1
#Define RPC_C_USE_INTERNET_PORT             1
#Define RPC_C_USE_INTRANET_PORT             2

#Define RPC_C_MQ_TEMPORARY                  00000H
#Define RPC_C_MQ_PERMANENT                  00001H
#Define RPC_C_MQ_CLEAR_ON_OPEN              00002H
#Define RPC_C_MQ_USE_EXISTING_SECURITY      00004H
#Define RPC_C_MQ_AUTHN_LEVEL_NONE           00000H
#Define RPC_C_MQ_AUTHN_LEVEL_PKT_INTEGRITY  00008H
#Define RPC_C_MQ_AUTHN_LEVEL_PKT_PRIVACY    00010H

#Define RPC_C_OPT_MQ_DELIVERY               1
#Define RPC_C_OPT_MQ_PRIORITY               2
#Define RPC_C_OPT_MQ_JOURNAL                3
#Define RPC_C_OPT_MQ_ACKNOWLEDGE            4
#Define RPC_C_OPT_MQ_AUTHN_SERVICE          5
#Define RPC_C_OPT_MQ_AUTHN_LEVEL            6
#Define RPC_C_OPT_MQ_TIME_TO_REACH_QUEUE    7
#Define RPC_C_OPT_MQ_TIME_TO_BE_RECEIVED    8
#Define RPC_C_OPT_BINDING_NONCAUSAL         9
#Define RPC_C_OPT_MAX_OPTIONS               10

#Define RPC_C_MQ_RECOVERABLE                1

#Define RPC_C_MQ_JOURNAL_NONE               0
#Define RPC_C_MQ_JOURNAL_DEADLETTER         1
#Define RPC_C_MQ_JOURNAL_ALWAYS             2

RPC_PROTSEQ_VECTORA Struct
	Count DD
	Protseq DD
EndS

RPC_PROTSEQ_VECTORW Struct
	Count DD
	Protseq DD
EndS

RPC_POLICY Struct
    unsigned int Length DD
    unsigned long EndpointFlags DD
    unsigned long NICFlags DD
EndS

RPC_STATS_VECTOR Struct
	Count DD
	Stats DD
EndS

#Define RPC_C_STATS_CALLS_IN                0
#Define RPC_C_STATS_CALLS_OUT               1
#Define RPC_C_STATS_PKTS_IN                 2
#Define RPC_C_STATS_PKTS_OUT                3

RPC_IF_ID_VECTOR Struct
	Count DD
	IfId DD
EndS

#Define RPC_C_AUTHN_LEVEL_DEFAULT           0
#Define RPC_C_AUTHN_LEVEL_NONE              1
#Define RPC_C_AUTHN_LEVEL_CONNECT           2
#Define RPC_C_AUTHN_LEVEL_CALL              3
#Define RPC_C_AUTHN_LEVEL_PKT               4
#Define RPC_C_AUTHN_LEVEL_PKT_INTEGRITY     5
#Define RPC_C_AUTHN_LEVEL_PKT_PRIVACY       6

#Define RPC_C_IMP_LEVEL_ANONYMOUS           1
#Define RPC_C_IMP_LEVEL_IDENTIFY            2
#Define RPC_C_IMP_LEVEL_IMPERSONATE         3
#Define RPC_C_IMP_LEVEL_DELEGATE            4

#Define RPC_C_QOS_IDENTITY_STATIC           0
#Define RPC_C_QOS_IDENTITY_DYNAMIC          1

#Define RPC_C_QOS_CAPABILITIES_DEFAULT      0
#Define RPC_C_QOS_CAPABILITIES_MUTUAL_AUTH  1

#Define RPC_C_PROTECT_LEVEL_DEFAULT         (RPC_C_AUTHN_LEVEL_DEFAULT)
#Define RPC_C_PROTECT_LEVEL_NONE            (RPC_C_AUTHN_LEVEL_NONE)
#Define RPC_C_PROTECT_LEVEL_CONNECT         (RPC_C_AUTHN_LEVEL_CONNECT)
#Define RPC_C_PROTECT_LEVEL_CALL            (RPC_C_AUTHN_LEVEL_CALL)
#Define RPC_C_PROTECT_LEVEL_PKT             (RPC_C_AUTHN_LEVEL_PKT)
#Define RPC_C_PROTECT_LEVEL_PKT_INTEGRITY   (RPC_C_AUTHN_LEVEL_PKT_INTEGRITY)
#Define RPC_C_PROTECT_LEVEL_PKT_PRIVACY     (RPC_C_AUTHN_LEVEL_PKT_PRIVACY)

#Define RPC_C_AUTHN_NONE                    0
#Define RPC_C_AUTHN_DCE_PRIVATE             1
#Define RPC_C_AUTHN_DCE_PUBLIC              2
#Define RPC_C_AUTHN_DEC_PUBLIC              4
#Define RPC_C_AUTHN_WINNT                  10
#Define RPC_C_AUTHN_DPA                    16
#Define RPC_C_AUTHN_MSN                    17
#Define RPC_C_AUTHN_GSS_KERBEROS           18
#Define RPC_C_AUTHN_MQ                     100
#Define RPC_C_AUTHN_DEFAULT                0FFFFFFFFH

#Define RPC_C_SECURITY_QOS_VERSION         1

RPC_SECURITY_QOS Struct
	Version DD
	Capabilities DD
	IdentityTracking DD
	ImpersonationType DD
EndS

#Define SEC_WINNT_AUTH_IDENTITY_ANSI        01H
#Define SEC_WINNT_AUTH_IDENTITY_UNICODE     02H

SEC_WINNT_AUTH_IDENTITY_W Struct
	User DD
	UserLength DD
	Domain DD
	DomainLength DD
	Password DD
	PasswordLength DD
	Flags DD
EndS

SEC_WINNT_AUTH_IDENTITY_A Struct
	User DD
	UserLength DD
	Domain DD
	DomainLength DD
	Password DD
	PasswordLength DD
	Flags DD
EndS

#Define RPC_C_AUTHZ_NONE                    0
#Define RPC_C_AUTHZ_NAME                    1
#Define RPC_C_AUTHZ_DCE                     2

RPC_CLIENT_INFORMATION1 Struct
	UserName DD
	ComputerName DD
	Privilege DW
	AuthFlags DD
EndS

#Define DCE_C_ERROR_STRING_LEN              256

#Define RPC_C_EP_ALL_ELTS                   0
#Define RPC_C_EP_MATCH_BY_IF                1
#Define RPC_C_EP_MATCH_BY_OBJ               2
#Define RPC_C_EP_MATCH_BY_BOTH              3

#Define RPC_C_VERS_ALL                      1
#Define RPC_C_VERS_COMPATIBLE               2
#Define RPC_C_VERS_EXACT                    3
#Define RPC_C_VERS_MAJOR_ONLY               4
#Define RPC_C_VERS_UPTO                     5

#Define RPC_C_MGMT_INQ_IF_IDS               0
#Define RPC_C_MGMT_INQ_PRINC_NAME           1
#Define RPC_C_MGMT_INQ_STATS                2
#Define RPC_C_MGMT_IS_SERVER_LISTEN         3
#Define RPC_C_MGMT_STOP_SERVER_LISTEN       4

#Define RPC_C_PARM_MAX_PACKET_LENGTH        1
#Define RPC_C_PARM_BUFFER_LENGTH            2

#Define RPC_IF_AUTOLISTEN                   00001H
#Define RPC_IF_OLE                          00002H

#IF STRINGS UNICODE
	#Define RPC_PROTSEQ_VECTOR RPC_PROTSEQ_VECTORW
	#Define RpcBindingFromStringBinding RpcBindingFromStringBindingW
	#Define RpcBindingToStringBinding RpcBindingToStringBindingW
	#Define RpcStringBindingCompose RpcStringBindingComposeW
	#Define RpcStringBindingParse RpcStringBindingParseW
	#Define RpcStringFree RpcStringFreeW
	#Define RpcNetworkIsProtseqValid RpcNetworkIsProtseqValidW
	#Define RpcNetworkInqProtseqs RpcNetworkInqProtseqsW
	#Define RpcProtseqVectorFree RpcProtseqVectorFreeW
	#Define RpcServerUseProtseq RpcServerUseProtseqW
	#Define RpcServerUseProtseqEx RpcServerUseProtseqExW
	#Define RpcServerUseProtseqEp RpcServerUseProtseqEpW
	#Define RpcServerUseProtseqEpEx RpcServerUseProtseqEpExW
	#Define RpcServerUseProtseqIf RpcServerUseProtseqIfW
	#Define RpcServerUseProtseqIfEx RpcServerUseProtseqIfExW
	#Define RpcMgmtInqServerPrincName RpcMgmtInqServerPrincNameW
	#Define RpcServerInqDefaultPrincName RpcServerInqDefaultPrincNameW
	#Define RpcNsBindingInqEntryName RpcNsBindingInqEntryNameW
	#Define SEC_WINNT_AUTH_IDENTITY SEC_WINNT_AUTH_IDENTITY_W
	#Define RpcBindingInqAuthClient RpcBindingInqAuthClientW
	#Define RpcBindingInqAuthInfo RpcBindingInqAuthInfoW
	#Define RpcBindingSetAuthInfo RpcBindingSetAuthInfoW
	#Define RpcServerRegisterAuthInfo RpcServerRegisterAuthInfoW
	#Define RpcBindingInqAuthInfoEx RpcBindingInqAuthInfoExW
	#Define RpcBindingSetAuthInfoEx RpcBindingSetAuthInfoExW
	#Define UuidFromString UuidFromStringW
	#Define UuidToString UuidToStringW
	#Define RpcEpRegisterNoReplace RpcEpRegisterNoReplaceW
	#Define RpcEpRegister RpcEpRegisterW
	#Define DceErrorInqText DceErrorInqTextW
	#Define RpcMgmtEpEltInqNext RpcMgmtEpEltInqNextW
#ELSE
	#Define RPC_PROTSEQ_VECTOR RPC_PROTSEQ_VECTORA
	#Define RpcBindingFromStringBinding RpcBindingFromStringBindingA
	#Define RpcBindingToStringBinding RpcBindingToStringBindingA
	#Define RpcStringBindingCompose RpcStringBindingComposeA
	#Define RpcStringBindingParse RpcStringBindingParseA
	#Define RpcStringFree RpcStringFreeA
	#Define RpcNetworkIsProtseqValid RpcNetworkIsProtseqValidA
	#Define RpcNetworkInqProtseqs RpcNetworkInqProtseqsA
	#Define RpcProtseqVectorFree RpcProtseqVectorFreeA
	#Define RpcServerUseProtseq RpcServerUseProtseqA
	#Define RpcServerUseProtseqEx RpcServerUseProtseqExA
	#Define RpcServerUseProtseqEp RpcServerUseProtseqEpA
	#Define RpcServerUseProtseqEpEx RpcServerUseProtseqEpExA
	#Define RpcServerUseProtseqIf RpcServerUseProtseqIfA
	#Define RpcServerUseProtseqIfEx RpcServerUseProtseqIfExA
	#Define RpcMgmtInqServerPrincName RpcMgmtInqServerPrincNameA
	#Define RpcServerInqDefaultPrincName RpcServerInqDefaultPrincNameA
	#Define RpcNsBindingInqEntryName RpcNsBindingInqEntryNameA
	#Define SEC_WINNT_AUTH_IDENTITY SEC_WINNT_AUTH_IDENTITY_A
	#Define RpcBindingInqAuthClient RpcBindingInqAuthClientA
	#Define RpcBindingInqAuthInfo RpcBindingInqAuthInfoA
	#Define RpcBindingSetAuthInfo RpcBindingSetAuthInfoA
	#Define RpcServerRegisterAuthInfo RpcServerRegisterAuthInfoA
	#Define RpcBindingInqAuthInfoEx RpcBindingInqAuthInfoExA
	#Define RpcBindingSetAuthInfoEx RpcBindingSetAuthInfoExA
	#Define UuidFromString UuidFromStringA
	#Define UuidToString UuidToStringA
	#Define RpcEpRegisterNoReplace RpcEpRegisterNoReplaceA
	#Define RpcEpRegister RpcEpRegisterA
	#Define DceErrorInqText DceErrorInqTextA
	#Define RpcMgmtEpEltInqNext RpcMgmtEpEltInqNextA
#ENDIF

#ENDIF ;RPCDCE_INC
