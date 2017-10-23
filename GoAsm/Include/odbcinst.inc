;=============================================================;
;         odbcinst.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF ODBCINST_INC
#Define ODBCINST_INC

#Define ODBC_ADD_DSN                        1
#Define ODBC_CONFIG_DSN                     2
#Define ODBC_REMOVE_DSN                     3

#Define ODBC_ADD_SYS_DSN                    4
#Define ODBC_CONFIG_SYS_DSN	                5
#Define ODBC_REMOVE_SYS_DSN	                6
#Define ODBC_REMOVE_DEFAULT_DSN             7

#Define ODBC_INSTALL_INQUIRY	            1
#Define ODBC_INSTALL_COMPLETE	            2

#Define ODBC_INSTALL_DRIVER	                1
#Define ODBC_REMOVE_DRIVER		            2
#Define ODBC_CONFIG_DRIVER		            3
#Define ODBC_CONFIG_DRIVER_MAX              100

#Define ODBC_BOTH_DSN		                0
#Define ODBC_USER_DSN		                1
#Define ODBC_SYSTEM_DSN		                2

#Define ODBC_ERROR_GENERAL_ERR              1
#Define ODBC_ERROR_INVALID_BUFF_LEN         2
#Define ODBC_ERROR_INVALID_HWND             3
#Define ODBC_ERROR_INVALID_STR              4
#Define ODBC_ERROR_INVALID_REQUEST_TYPE     5
#Define ODBC_ERROR_COMPONENT_NOT_FOUND      6
#Define ODBC_ERROR_INVALID_NAME             7
#Define ODBC_ERROR_INVALID_KEYWORD_VALUE    8
#Define ODBC_ERROR_INVALID_DSN              9
#Define ODBC_ERROR_INVALID_INF              10
#Define ODBC_ERROR_REQUEST_FAILED           11
#Define ODBC_ERROR_INVALID_PATH             12
#Define ODBC_ERROR_LOAD_LIB_FAILED          13
#Define ODBC_ERROR_INVALID_PARAM_SEQUENCE   14
#Define ODBC_ERROR_INVALID_LOG_FILE         15
#Define ODBC_ERROR_USER_CANCELED            16
#Define ODBC_ERROR_USAGE_UPDATE_FAILED      17
#Define ODBC_ERROR_CREATE_DSN_FAILED        18
#Define ODBC_ERROR_WRITING_SYSINFO_FAILED   19
#Define ODBC_ERROR_REMOVE_DSN_FAILED        20
#Define ODBC_ERROR_OUT_OF_MEM               21
#Define ODBC_ERROR_OUTPUT_STRING_TRUNCATED  22

#IF STRINGS UNICODE
	#Define SQLInstallODBC SQLInstallODBCW
	#Define SQLCreateDataSource SQLCreateDataSourceW
	#Define SQLGetTranslator SQLGetTranslatorW
	#Define SQLInstallDriver SQLInstallDriverW
	#Define SQLInstallDriverManager SQLInstallDriverManagerW
	#Define SQLGetInstalledDrivers SQLGetInstalledDriversW
	#Define SQLGetAvailableDrivers SQLGetAvailableDriversW
	#Define SQLConfigDataSource SQLConfigDataSourceW
	#Define SQLWriteDSNToIni SQLWriteDSNToIniW
	#Define SQLRemoveDSNFromIni SQLRemoveDSNFromIniW
	#Define SQLValidDSN SQLValidDSNW
	#Define SQLWritePrivateProfileString SQLWritePrivateProfileStringW
	#Define SQLGetPrivateProfileString SQLGetPrivateProfileStringW
	#Define SQLInstallTranslator SQLInstallTranslatorW
	#Define SQLRemoveTranslator SQLRemoveTranslatorW
	#Define SQLRemoveDriver SQLRemoveDriverW
	#Define SQLConfigDriver SQLConfigDriverW
	#Define SQLInstallerError SQLInstallerErrorW
	#Define SQLPostInstallerError SQLPostInstallerErrorW
	#Define SQLReadFileDSN SQLReadFileDSNW
	#Define SQLWriteFileDSN SQLWriteFileDSNW
	#Define SQLInstallDriverEx SQLInstallDriverExW
	#Define SQLInstallTranslatorEx SQLInstallTranslatorExW
#ENDIF

#ENDIF ;ODBCINST_INC
