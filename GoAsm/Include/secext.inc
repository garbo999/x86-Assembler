;=============================================================;
;          secext.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF SECEXT_INC
#Define SECEXT_INC

#IFNDEF SECURITY_STRING
	SECURITY_STRING Struct
		Length DW
		MaximumLength DW
		Buffer DD
	EndS
#ENDIF

SecurityUserData Struct
	UserName SECURITY_STRING <>
	LogonDomainName SECURITY_STRING <>
	LogonServer SECURITY_STRING <>
	pSid DD
EndS

#Define UNDERSTANDS_LONG_NAMES              1
#Define NO_LONG_NAMES                       2

#Define SECURITY_CONTROL_NAME                       L"SPMgr"
#define SECURITY_CONTROL_REFRESH                    100
#define SECURITY_CONTROL_UPDATE_MACHINE_JP_PROPS    101
#define SECURITY_CONTROL_RELOAD_LOCAL_POLICY        102

#IF STRINGS UNICODE
	#Define AddSecurityPackage AddSecurityPackageW
	#Define DeleteSecurityPackage DeleteSecurityPackageW
	#Define GetUserNameEx GetUserNameExW
	#Define GetComputerObjectName GetComputerObjectNameW
	#Define TranslateName TranslateNameW
#ELSE
	#Define AddSecurityPackage  AddSecurityPackageA
	#Define DeleteSecurityPackage DeleteSecurityPackageA
	#Define GetUserNameEx GetUserNameExA
	#Define GetComputerObjectName GetComputerObjectNameA
	#Define TranslateName TranslateNameA
#ENDIF

#ENDIF ;SECEXT_INC
