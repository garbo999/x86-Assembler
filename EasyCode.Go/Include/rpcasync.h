#ifndef RPCASYNC_H
#define RPCASYNC_H

/* Windows Async RPC runtime API definitions */
#define RPC_C_NOTIFY_ON_SEND_COMPLETE  0x1
#define RPC_C_INFINITE_TIMEOUT  INFINITE

RpcNotificationTypeNone = 0
RpcNotificationTypeEvent = 1
RpcNotificationTypeApc = 2
RpcNotificationTypeIoc = 3
RpcNotificationTypeHwnd = 4
RpcNotificationTypeCallback = 5

RpcCallComplete = 0
RpcSendComplete = 1
RpcReceiveComplete = 2

eeptAnsiString = 1
eeptUnicodeString = 2
eeptLongVal = 3
eeptShortVal = 4
eeptPointerVal = 5
eeptNone = 6
eeptBinary = 7

rctInvalid = 0
rctNormal = 1
rctTraining = 2
rctGuaranteed = 3

rcclInvalid = 0
rcclLocal = 1
rcclRemote = 2
rcclClientUnknownLocality = 3

RpcNotificationCallNone = 0
RpcNotificationClientDisconnect = 1
RpcNotificationCallCancel = 2      // internal for Windows

#define EEInfoPreviousRecordsMissing     1
#define EEInfoNextRecordsMissing         2
#define EEInfoUseFileTime                4
#define EEInfoGCCOM                     11
#define EEInfoGCFRS                     12

#define MaxNumberOfEEInfoParams    4
#define RPC_EEINFO_VERSION         1

BinaryParam STRUCT
	Buffer PTR
	Size DD
ENDS

RPC_EE_INFO_PARAM STRUCT
	ParameterType DD
	UNION
		AnsiString PTR
		UnicodeString PTR
		LVal DD
		SVal DW
		PVal DQ
		BVal BinaryParam
	ENDUNION
ENDS

RPC_EXTENDED_ERROR_INFO STRUCT
	Version DD
	ComputerName PTR
	ProcessID DD
	UNION
	#IFNDEF KRPCENV
		SystemTime SYSTEMTIME
		FileTime FILETIME
	#else
		KernelTime LARGE_INTEGER
	#endif
	ENDUNION
	GeneratingComponent DD
	Status DD
	DetectionLocation DW
	Flags DW
	NumberOfParameters DD
	Parameters RPC_EE_INFO_PARAM MaxNumberOfEEInfoParams DUP
ENDS

RPC_ERROR_ENUM_HANDLE STRUCT
	Signature DD
	CurrentPos PTR
	Head PTR
ENDS

#IFDEF VISTA
	rlafInvalid = 0
	rlafIPv4 = 1
	rlafIPv6 = 2
	
	RPC_CALL_LOCAL_ADDRESS_V1 STRUCT
		Version DD
		Buffer PTR
		BufferSize DD
		AddressFormat DD
	ENDS
	
	#define RPC_CALL_ATTRIBUTES_VERSION                         (2)
	
	#define RPC_QUERY_SERVER_PRINCIPAL_NAME                     (0x02)
	#define RPC_QUERY_CLIENT_PRINCIPAL_NAME                     (0x04)
	#define RPC_QUERY_CALL_LOCAL_ADDRESS                        (0x08)
	#define RPC_QUERY_CLIENT_PID                                (0x10)
	#define RPC_QUERY_IS_CLIENT_LOCAL                           (0x20)
	#define RPC_QUERY_NO_AUTH_REQUIRED                          (0x40)
#endif

#IFDEF WINXP
	#define RPC_CALL_ATTRIBUTES_VERSION                         (1)
	#define RPC_QUERY_SERVER_PRINCIPAL_NAME                     (2)
	#define RPC_QUERY_CLIENT_PRINCIPAL_NAME                     (4)
#ENDIF

RPC_ASYNC_STATE STRUCT
	Size DD
	Signature DD
	Lock DD
	Flags DD
	StubInfo PTR
	UserInfo PTR
	RuntimeInfo PTR
	Event DD
	NotificationType DD
	UNION
		APC STRUCT
			NotificationRoutine PTR
			hThread HANDLE
		ENDS
		IOC STRUCT
			hIOPort HANDLE
			dwNumberOfBytesTransferred DD
			dwCompletionKey DWORD_PTR
			lpOverlapped PTR
		ENDS
		HWND STRUCT
			hWnd HANDLE
			Msg DD
		ENDS
		#IFNDEF KRPCENV
			hEvent HANDLE
		#ELSE
			Event PTR
		#ENDIF
	ENDUNION
	Reserved LONG_PTR 4 DUP
ends

RPC_CALL_ATTRIBUTES_V1_A STRUCT
	Version DD
	Flags DD
	ServerPrincipalNameBufferLength DD
	ServerPrincipalName PTR
	ClientPrincipalNameBufferLength DD
	ClientPrincipalName PTR
	AuthenticationLevel DD
	AuthenticationService DD
	NullSession DD
ENDS

#DEFINE RPC_CALL_ATTRIBUTES_V1_W RPC_CALL_ATTRIBUTES_V1_A

RPC_CALL_ATTRIBUTES_V2_A STRUCT
	Version DD
	Flags DD
	ServerPrincipalNameBufferLength DD
	ServerPrincipalName PTR
	ClientPrincipalNameBufferLength DD
	ClientPrincipalName PTR
	AuthenticationLevel DD
	AuthenticationService DD
	NullSession DD
	KernelModeCaller DD
	ProtocolSequence DD
	IsClientLocal DD
	ClientPID HANDLE
	CallStatus DD
	CallType DD
	CallLocalAddress PTR
	OpNum DW
	InterfaceUuid GUID
ENDS

#DEFINE RPC_CALL_ATTRIBUTES_V2_W RPC_CALL_ATTRIBUTES_V2_A

#IFDEF UNICODE
	#define RPC_CALL_ATTRIBUTES_V1 RPC_CALL_ATTRIBUTES_V1_W
	#ifdef VISTA
		#define RPC_CALL_ATTRIBUTES_V2 RPC_CALL_ATTRIBUTES_V2_W
	#endif
	#define RpcServerInqCallAttributes RpcServerInqCallAttributesW
#else
	#define RPC_CALL_ATTRIBUTES_V1 RPC_CALL_ATTRIBUTES_V1_A
	#ifdef VISTA
		#define RPC_CALL_ATTRIBUTES_V2 RPC_CALL_ATTRIBUTES_V2_A
	#endif // (NTDDI_VERSION >= NTDDI_VISTA)
	#define RpcServerInqCallAttributes RpcServerInqCallAttributesA
#endif // !UNICODE

#endif /* _RPCASYNC_H */
