;=============================================================;
;          winreg.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINREG_INC
#Define WINREG_INC

#Define HKEY_CLASSES_ROOT           	080000000H
#Define HKEY_CURRENT_USER           	080000001H
#Define HKEY_LOCAL_MACHINE          	080000002H
#Define HKEY_USERS                  	080000003H
#Define HKEY_PERFORMANCE_DATA       	080000004H
#Define HKEY_CURRENT_CONFIG         	080000005H
#Define HKEY_DYN_DATA               	080000006H

#Define WIN31_CLASS                 	NULL

val_context Struct
	valuelen DD
	value_context DD
	val_buff_ptr DD
EndS

PVALUEA Struct
	pv_valuename DD
	pv_valuelen DD
	pv_value_context DD
	pv_type DD
EndS

PVALUEW Struct
	pv_valuename DD
	pv_valuelen DD
	pv_value_context DD
	pv_type DD
EndS

REG_PROVIDER Struct
	pi_R0_1val DD
	pi_R0_allvals DD
	pi_R3_1val DD
	pi_R3_allvals DD
	pi_flags DD
	pi_key_context DD
EndS

VALENTA Struct
	ve_valuename DD
	ve_valuelen DD
	ve_valueptr DD
	ve_type DD
EndS

VALENTW Struct
	ve_valuename DD
	ve_valuelen DD
	ve_valueptr DD
	ve_type DD
EndS


#IF STRINGS UNICODE
	#Define PVALUE PVALUEW
	#Define VALENT VALENTW
	#Define RegConnectRegistry RegConnectRegistryW
	#Define RegCreateKey RegCreateKeyW
	#Define RegCreateKeyEx RegCreateKeyExW
	#Define RegDeleteKey RegDeleteKeyW
	#Define RegDeleteValue RegDeleteValueW
	#Define RegEnumKey RegEnumKeyW
	#Define RegEnumKeyEx RegEnumKeyExW
	#Define RegEnumValue RegEnumValueW
	#Define RegLoadKey RegLoadKeyW
	#Define RegOpenKey RegOpenKeyW
	#Define RegOpenKeyEx RegOpenKeyExW
	#Define RegQueryInfoKey RegQueryInfoKeyW
	#Define RegQueryValue RegQueryValueW
	#Define RegQueryMultipleValues RegQueryMultipleValuesW
	#Define RegQueryValueEx RegQueryValueExW
	#Define RegReplaceKey RegReplaceKeyW
	#Define RegRestoreKey RegRestoreKeyW
	#Define RegSaveKey RegSaveKeyW
	#Define RegSetValue RegSetValueW
	#Define RegSetValueEx RegSetValueExW
	#Define RegUnLoadKey RegUnLoadKeyW
	#Define InitiateSystemShutdown InitiateSystemShutdownW
	#Define AbortSystemShutdown AbortSystemShutdownW
#ELSE
	#Define PVALUE PVALUEA
	#Define VALENT VALENTA
	#Define RegConnectRegistry RegConnectRegistryA
	#Define RegCreateKey RegCreateKeyA
	#Define RegCreateKeyEx RegCreateKeyExA
	#Define RegDeleteKey RegDeleteKeyA
	#Define RegDeleteValue RegDeleteValueA
	#Define RegEnumKey RegEnumKeyA
	#Define RegEnumKeyEx RegEnumKeyExA
	#Define RegEnumValue RegEnumValueA
	#Define RegLoadKey RegLoadKeyA
	#Define RegOpenKey RegOpenKeyA
	#Define RegOpenKeyEx RegOpenKeyExA
	#Define RegQueryInfoKey RegQueryInfoKeyA
	#Define RegQueryValue RegQueryValueA
	#Define RegQueryMultipleValues RegQueryMultipleValuesA
	#Define RegQueryValueEx RegQueryValueExA
	#Define RegReplaceKey RegReplaceKeyA
	#Define RegRestoreKey RegRestoreKeyA
	#Define RegSaveKey RegSaveKeyA
	#Define RegSetValue RegSetValueA
	#Define RegSetValueEx RegSetValueExA
	#Define RegUnLoadKey RegUnLoadKeyA
	#Define InitiateSystemShutdown InitiateSystemShutdownA
	#Define AbortSystemShutdown AbortSystemShutdownA
#ENDIF

#ENDIF ;WINREG_INC
