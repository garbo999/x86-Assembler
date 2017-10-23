#IFNDEF WIN9X

#ifndef WINWLX_H
#define WINWLX_H

/* Windows WinLogon eXtensions: */
/* Graphical Identification aNd Authentication (GINA) DLL definitions */

#define WLX_VERSION_1_0  0X00010000
#define WLX_VERSION_1_1  0X00010001
#define WLX_VERSION_1_2  0X00010002
#define WLX_VERSION_1_3  0X00010003
#define WLX_CURRENT_VERSION  WLX_VERSION_1_3

#define WLX_SAS_TYPE_TIMEOUT  0
#define WLX_SAS_TYPE_CTRL_ALT_DEL  1
#define WLX_SAS_TYPE_SCRNSVR_TIMEOUT  2
#define WLX_SAS_TYPE_SCRNSVR_ACTIVITY  3
#define WLX_SAS_TYPE_USER_LOGOFF  4
#define WLX_SAS_TYPE_SC_INSERT  5
#define WLX_SAS_TYPE_SC_REMOVE  6
#define WLX_SAS_TYPE_MAX_MSFT_VALUE  127

#define WLX_LOGON_OPT_NO_PROFILE  0x00000001

#define WLX_PROFILE_TYPE_V1_0  1
#define WLX_PROFILE_TYPE_V2_0  2

#define WLX_SAS_ACTION_LOGON  1
#define WLX_SAS_ACTION_NONE  2
#define WLX_SAS_ACTION_LOCK_WKSTA  3
#define WLX_SAS_ACTION_LOGOFF  4
#define WLX_SAS_ACTION_SHUTDOWN  5
#define WLX_SAS_ACTION_PWD_CHANGED  6
#define WLX_SAS_ACTION_TASKLIST  7
#define WLX_SAS_ACTION_UNLOCK_WKSTA  8
#define WLX_SAS_ACTION_FORCE_LOGOFF  9
#define WLX_SAS_ACTION_SHUTDOWN_POWER_OFF  10
#define WLX_SAS_ACTION_SHUTDOWN_REBOOT  11
#define WLX_SAS_ACTION_SHUTDOWN_SLEEP  12
#define WLX_SAS_ACTION_SHUTDOWN_SLEEP2  13
#define WLX_SAS_ACTION_SHUTDOWN_HIBERNATE  14
#define WLX_SAS_ACTION_RECONNECTED  15
#define WLX_SAS_ACTION_DELAYED_FORCE_LOGOFF 16

#define WLX_WM_SAS  (WM_USER+601)

#define WLX_DLG_SAS  101
#define WLX_DLG_INPUT_TIMEOUT  102
#define WLX_DLG_SCREEN_SAVER_TIMEOUT  103
#define WLX_DLG_USER_LOGOFF  104

#define WLX_DIRECTORY_LENGTH  256

#define WLX_CREDENTIAL_TYPE_V1_0  1

#define STATUSMSG_OPTION_NOANIMATION  0x00000001
#define STATUSMSG_OPTION_SETFOREGROUND  0x00000002

#define WLX_DESKTOP_NAME  0x00000001
#define WLX_DESKTOP_HANDLE  0x00000002

#define WLX_CREATE_INSTANCE_ONLY  0x00000001
#define WLX_CREATE_USER  0x00000002

#define WLX_OPTION_USE_CTRL_ALT_DEL  0x00000001
#define WLX_OPTION_CONTEXT_POINTER  0x00000002
#define WLX_OPTION_USE_SMART_CARD  0x00000003
#define WLX_OPTION_FORCE_LOGOFF_TIME  0x00000004
#define WLX_OPTION_IGNORE_AUTO_LOGON  0x00000008

#define WLX_OPTION_SMART_CARD_PRESENT  0x00010001
#define WLX_OPTION_SMART_CARD_INFO  0x00010002
#define WLX_OPTION_DISPATCH_TABLE_SIZE  0x00010003

WLX_SC_NOTIFICATION_INFO STRUCT
	pszCard PTR
	pszReader PTR
	pszContainer PTR
	pszCryptoProvider PTR
ENDS

WLX_PROFILE_V1_0 STRUCT
	dwType DD
	pszProfile PTR
ENDS

WLX_PROFILE_V2_0 STRUCT
	dwType DD
	pszProfile PTR
	pszPolicy PTR
	pszNetworkDefaultUserProfile PTR
	pszServerName PTR
	pszEnvironment PTR
ENDS

WLX_MPR_NOTIFY_INFO STRUCT
	pszUserName PTR
	pszDomain PTR
	pszPassword PTR
	pszOldPassword PTR
ENDS

WLX_TERMINAL_SERVICES_DATA STRUCT
	ProfilePath DW WLX_DIRECTORY_LENGTH+1 DUP (?)
	HomeDir DW WLX_DIRECTORY_LENGTH+1 DUP (?)
	HomeDirDrive DW 4 DUP (?)
ENDS

WLX_CLIENT_CREDENTIALS_INFO_V1_0 STRUCT
	dwType DD
	pszUserName PTR
	pszDomain PTR
	pszPassword PTR
	fPromptForPassword DD
ENDS

WLX_DESKTOP STRUCT
	Size DD
	Flags DD
	hDesktop HANDLE
	pszDesktopName PTR
ENDS

WLX_DISPATCH_VERSION_1_0 STRUCT
	WlxUseCtrlAltDel PTR
	WlxSetContextPointer PTR
	WlxSasNotify PTR
	WlxSetTimeout PTR
	WlxAssignShellProtection PTR
	WlxMessageBox PTR
	WlxDialogBox PTR
	WlxDialogBoxParam PTR
	WlxDialogBoxIndirect PTR
	WlxDialogBoxIndirectParam PTR
	WlxSwitchDesktopToUser PTR
	WlxSwitchDesktopToWinlogon PTR
	WlxChangePasswordNotify PTR
ENDS

WLX_DISPATCH_VERSION_1_1 STRUCT
	WlxUseCtrlAltDel PTR
	WlxSetContextPointer PTR
	WlxSasNotify PTR
	WlxSetTimeout PTR
	WlxAssignShellProtection PTR
	WlxMessageBox PTR
	WlxDialogBox PTR
	WlxDialogBoxParam PTR
	WlxDialogBoxIndirect PTR
	WlxDialogBoxIndirectParam PTR
	WlxSwitchDesktopToUser PTR
	WlxSwitchDesktopToWinlogon PTR
	WlxChangePasswordNotify PTR
	WlxGetSourceDesktop PTR
	WlxSetReturnDesktop PTR
	WlxCreateUserDesktop PTR
	WlxChangePasswordNotifyEx PTR
ENDS

WLX_DISPATCH_VERSION_1_2 STRUCT
	WlxUseCtrlAltDel PTR
	WlxSetContextPointer PTR
	WlxSasNotify PTR
	WlxSetTimeout PTR
	WlxAssignShellProtection PTR
	WlxMessageBox PTR
	WlxDialogBox PTR
	WlxDialogBoxParam PTR
	WlxDialogBoxIndirect PTR
	WlxDialogBoxIndirectParam PTR
	WlxSwitchDesktopToUser PTR
	WlxSwitchDesktopToWinlogon PTR
	WlxChangePasswordNotify PTR
	WlxGetSourceDesktop PTR
	WlxSetReturnDesktop PTR
	WlxCreateUserDesktop PTR
	WlxChangePasswordNotifyEx PTR
	WlxCloseUserDesktop PTR
ENDS

WLX_DISPATCH_VERSION_1_3 STRUCT
	WlxUseCtrlAltDel PTR
	WlxSetContextPointer PTR
	WlxSasNotify PTR
	WlxSetTimeout PTR
	WlxAssignShellProtection PTR
	WlxMessageBox PTR
	WlxDialogBox PTR
	WlxDialogBoxParam PTR
	WlxDialogBoxIndirect PTR
	WlxDialogBoxIndirectParam PTR
	WlxSwitchDesktopToUser PTR
	WlxSwitchDesktopToWinlogon PTR
	WlxChangePasswordNotify PTR
	WlxGetSourceDesktop PTR
	WlxSetReturnDesktop PTR
	WlxCreateUserDesktop PTR
	WlxChangePasswordNotifyEx PTR
	WlxCloseUserDesktop PTR
	WlxSetOption PTR
	WlxGetOption PTR
	WlxWin31Migrate PTR
	WlxQueryClientCredentials PTR
	WlxQueryInetConnectorCredentials PTR
	WlxDisconnect PTR
	WlxQueryTerminalServicesData PTR
ENDS

WLX_NOTIFICATION_INFO STRUCT
	Size DD
	Flags DD
	UserName PTR
	Domain PTR
	WindowStation PTR
	hToken HANDLE
	hDesktop HANDLE
	pStatusCallback PTR
ENDS

#endif /* WINWLX_H */
#ENDIF /* WIN9X */