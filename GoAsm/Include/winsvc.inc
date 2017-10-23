;=============================================================;
;          winsvc.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINSVC_INC
#Define WINSVC_INC

#Define SERVICES_ACTIVE_DATABASEW		L"ServicesActive"
#Define SERVICES_FAILED_DATABASEW		L"ServicesFailed"

#Define SERVICES_ACTIVE_DATABASEA		"ServicesActive"
#Define SERVICES_FAILED_DATABASEA		"ServicesFailed"

#Define SC_GROUP_IDENTIFIERW			L'+'
#Define SC_GROUP_IDENTIFIERA			'+'

#Define SERVICE_NO_CHANGE               0FFFFFFFFH

#Define SERVICE_ACTIVE                  000000001H
#Define SERVICE_INACTIVE                000000002H
#Define SERVICE_STATE_ALL               (SERVICE_ACTIVE | SERVICE_INACTIVE)

#Define SERVICE_CONTROL_STOP            000000001H
#Define SERVICE_CONTROL_PAUSE           000000002H
#Define SERVICE_CONTROL_CONTINUE        000000003H
#Define SERVICE_CONTROL_INTERROGATE     000000004H
#Define SERVICE_CONTROL_SHUTDOWN        000000005H
#Define SERVICE_CONTROL_PARAMCHANGE     000000006H
#Define SERVICE_CONTROL_NETBINDADD      000000007H
#Define SERVICE_CONTROL_NETBINDREMOVE   000000008H
#Define SERVICE_CONTROL_NETBINDENABLE   000000009H
#Define SERVICE_CONTROL_NETBINDDISABLE  00000000AH

#Define SERVICE_STOPPED                 000000001H
#Define SERVICE_START_PENDING           000000002H
#Define SERVICE_STOP_PENDING            000000003H
#Define SERVICE_RUNNING                 000000004H
#Define SERVICE_CONTINUE_PENDING        000000005H
#Define SERVICE_PAUSE_PENDING           000000006H
#Define SERVICE_PAUSED                  000000007H

#Define SERVICE_ACCEPT_STOP             000000001H
#Define SERVICE_ACCEPT_PAUSE_CONTINUE   000000002H
#Define SERVICE_ACCEPT_SHUTDOWN         000000004H
#Define SERVICE_ACCEPT_PARAMCHANGE      000000008H
#Define SERVICE_ACCEPT_NETBINDCHANGE    000000010H

#Define SC_MANAGER_CONNECT              00001H
#Define SC_MANAGER_CREATE_SERVICE       00002H
#Define SC_MANAGER_ENUMERATE_SERVICE    00004H
#Define SC_MANAGER_LOCK                 00008H
#Define SC_MANAGER_QUERY_LOCK_STATUS    00010H
#Define SC_MANAGER_MODIFY_BOOT_CONFIG   00020H

#Define SC_MANAGER_ALL_ACCESS           (STANDARD_RIGHTS_REQUIRED | SC_MANAGER_CONNECT | SC_MANAGER_CREATE_SERVICE | SC_MANAGER_ENUMERATE_SERVICE | SC_MANAGER_LOCK | SC_MANAGER_QUERY_LOCK_STATUS | SC_MANAGER_MODIFY_BOOT_CONFIG)

#Define SERVICE_QUERY_CONFIG            00001H
#Define SERVICE_CHANGE_CONFIG           00002H
#Define SERVICE_QUERY_STATUS            00004H
#Define SERVICE_ENUMERATE_DEPENDENTS    00008H
#Define SERVICE_START                   00010H
#Define SERVICE_STOP                    00020H
#Define SERVICE_PAUSE_CONTINUE          00040H
#Define SERVICE_INTERROGATE             00080H
#Define SERVICE_USER_DEFINED_CONTROL    00100H

#Define SERVICE_ALL_ACCESS              (STANDARD_RIGHTS_REQUIRED | SERVICE_QUERY_CONFIG | SERVICE_CHANGE_CONFIG | SERVICE_QUERY_STATUS | SERVICE_ENUMERATE_DEPENDENTS | SERVICE_START | SERVICE_STOP | SERVICE_PAUSE_CONTINUE | SERVICE_INTERROGATE | SERVICE_USER_DEFINED_CONTROL)

#Define SERVICE_CONFIG_DESCRIPTION      1
#Define SERVICE_CONFIG_FAILURE_ACTIONS  2

;SC_ACTION_TYPE enumeration
SC_ACTION_NONE							Equ 0
SC_ACTION_RESTART						Equ 1
SC_ACTION_REBOOT						Equ 2
SC_ACTION_RUN_COMMAND					Equ 3


SERVICE_DESCRIPTIONA Struct
	lpDescription DD
EndS

SERVICE_DESCRIPTIONW Struct
	lpDescription DD
EndS

SC_ACTION Struct
	Type DD
	Delay DD
EndS

SERVICE_FAILURE_ACTIONSA Struct
	dwResetPeriod DD
	lpRebootMsg DD
	lpCommand DD
	cActions DD
	lpsaActions DD
EndS

SERVICE_FAILURE_ACTIONSW Struct
	dwResetPeriod DD
	lpRebootMsg DD
	lpCommand DD
	cActions DD
	lpsaActions DD
EndS

SERVICE_STATUS Struct
	dwServiceType DD
	dwCurrentState DD
	dwControlsAccepted DD
	dwWin32ExitCode DD
	dwServiceSpecificExitCode DD
	dwCheckPoint DD
	dwWaitHint DD
EndS

ENUM_SERVICE_STATUSA Struct
	lpServiceName DD
	lpDisplayName DD
	ServiceStatus SERVICE_STATUS <>
EndS

ENUM_SERVICE_STATUSW Struct
	lpServiceName DD
	lpDisplayName DD
	ServiceStatus SERVICE_STATUS <>
EndS

QUERY_SERVICE_LOCK_STATUSA Struct
	fIsLocked DD
	lpLockOwner DD
	dwLockDuration DD
EndS

QUERY_SERVICE_LOCK_STATUSW Struct
	fIsLocked DD
	lpLockOwner DD
	dwLockDuration DD
EndS

QUERY_SERVICE_CONFIGA Struct
	dwServiceType DD
	dwStartType DD
	dwErrorControl DD
	lpBinaryPathName DD
	lpLoadOrderGroup DD
	dwTagId DD
	lpDependencies DD
	lpServiceStartName DD
	lpDisplayName DD
EndS

QUERY_SERVICE_CONFIGW Struct
	dwServiceType DD
	dwStartType DD
	dwErrorControl DD
	lpBinaryPathName DD
	lpLoadOrderGroup DD
	dwTagId DD
	lpDependencies DD
	lpServiceStartName DD
	lpDisplayName DD
EndS

SERVICE_TABLE_ENTRYA Struct
	lpServiceName DD
	lpServiceProc DD
EndS

SERVICE_TABLE_ENTRYW Struct
	lpServiceName DD
	lpServiceProc DD
EndS


#IF STRINGS UNICODE
	#Define SERVICES_ACTIVE_DATABASE SERVICES_ACTIVE_DATABASEW
	#Define SERVICES_FAILED_DATABASE SERVICES_FAILED_DATABASEW
	#Define SC_GROUP_IDENTIFIER SC_GROUP_IDENTIFIERW
	#Define SERVICE_DESCRIPTION SERVICE_DESCRIPTIONW
	#Define SERVICE_FAILURE_ACTIONS SERVICE_FAILURE_ACTIONSW
	#Define ENUM_SERVICE_STATUS ENUM_SERVICE_STATUSW
	#Define QUERY_SERVICE_LOCK_STATUS QUERY_SERVICE_LOCK_STATUSW
	#Define QUERY_SERVICE_CONFIG QUERY_SERVICE_CONFIGW
	#Define SERVICE_TABLE_ENTRY SERVICE_TABLE_ENTRYW
	#Define ChangeServiceConfig ChangeServiceConfigW
	#Define ChangeServiceConfig2 ChangeServiceConfig2W
	#Define CreateService CreateServiceW
	#Define EnumDependentServices EnumDependentServicesW
	#Define EnumServicesStatus EnumServicesStatusW
	#Define GetServiceKeyName GetServiceKeyNameW
	#Define GetServiceDisplayName GetServiceDisplayNameW
	#Define OpenSCManager OpenSCManagerW
	#Define OpenService OpenServiceW
	#Define QueryServiceConfig QueryServiceConfigW
	#Define QueryServiceConfig2 QueryServiceConfig2W
	#Define QueryServiceLockStatus QueryServiceLockStatusW
	#Define RegisterServiceCtrlHandler RegisterServiceCtrlHandlerW
	#Define StartServiceCtrlDispatcher StartServiceCtrlDispatcherW
	#Define StartService StartServiceW
#ELSE
	#Define SERVICES_ACTIVE_DATABASE SERVICES_ACTIVE_DATABASEA
	#Define SERVICES_FAILED_DATABASE SERVICES_FAILED_DATABASEA
	#Define SC_GROUP_IDENTIFIER SC_GROUP_IDENTIFIERA
	#Define SERVICE_DESCRIPTION SERVICE_DESCRIPTIONA
	#Define SERVICE_FAILURE_ACTIONS SERVICE_FAILURE_ACTIONSA
	#Define ENUM_SERVICE_STATUS ENUM_SERVICE_STATUSA
	#Define QUERY_SERVICE_LOCK_STATUS QUERY_SERVICE_LOCK_STATUSA
	#Define QUERY_SERVICE_CONFIG QUERY_SERVICE_CONFIGA
	#Define SERVICE_TABLE_ENTRY SERVICE_TABLE_ENTRYA
	#Define ChangeServiceConfig ChangeServiceConfigA
	#Define ChangeServiceConfig2 ChangeServiceConfig2A
	#Define CreateService CreateServiceA
	#Define EnumDependentServices EnumDependentServicesA
	#Define EnumServicesStatus EnumServicesStatusA
	#Define GetServiceKeyName GetServiceKeyNameA
	#Define GetServiceDisplayName GetServiceDisplayNameA
	#Define OpenSCManager OpenSCManagerA
	#Define OpenService OpenServiceA
	#Define QueryServiceConfig QueryServiceConfigA
	#Define QueryServiceConfig2 QueryServiceConfig2A
	#Define QueryServiceLockStatus QueryServiceLockStatusA
	#Define RegisterServiceCtrlHandler RegisterServiceCtrlHandlerA
	#Define StartServiceCtrlDispatcher StartServiceCtrlDispatcherA
	#Define StartService StartServiceA
#ENDIF

#ENDIF ;WINSVC_INC
