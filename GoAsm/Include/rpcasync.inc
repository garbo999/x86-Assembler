;=============================================================;
;         rpcasync.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF RPCASYNC_INC
#Define RPCASYNC_INC

;RPC_NOTIFICATION_TYPES enumeration
#Define RpcNotificationTypeNone             0
#Define RpcNotificationTypeEvent            1
#Define RpcNotificationTypeApc              2
#Define RpcNotificationTypeIoc              3
#Define RpcNotificationTypeHwnd             4
#Define RpcNotificationTypeCallback         5

;RPC_ASYNC_EVENT enumeration
#Define RpcCallComplete                     0
#Define RpcSendComplete                     1
#Define RpcReceiveComplete                  2

_APC Struct
	NotificationRoutine DD
	hThread DD
EndS

_IOC Struct
	hIOPort DD
	dwNumberOfBytesTransferred DD
	dwCompletionKey DD
	lpOverlapped DD
EndS

_HWND Struct
	hWnd DD
	Msg DD
EndS

RPC_ASYNC_STATE Struct
	Size DD
	Signature DD
	Lock DD
	Flags DD
	StubInfo DD
	UserInfo DD
	RuntimeInfo DD
	Event DD
	NotificationType DD
	Union
		apc _APC <>
		ioc _IOC <>
		hWnd _HWND <>
		hEvent DD
		NotificationRoutine DD
	EndUnion
	Reserved DD 4 Dup ?
EndS

#Define RPC_ASYNC_VERSION_1_0               SizeOf(RPC_ASYNC_STATE)

#Define RPC_C_NOTIFY_ON_SEND_COMPLETE       01H
#Define RPC_C_INFINITE_TIMEOUT              INFINITE

#ENDIF ;RPCASYNC_INC
