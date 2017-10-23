#ifndef WINREG_H
#define WINREG_H

#DEFINE WINREG_H_REQVER 100

/* Windows Registry API definitions */


/*
Switches used
None
*/

#IFDEF LINKFILES
	#dynamiclinkfile Advapi32.dll
#ENDIF

#define HKEY_CLASSES_ROOT 0x80000000
#define HKEY_CURRENT_USER 0x80000001
#define HKEY_LOCAL_MACHINE 0x80000002
#define HKEY_USERS 0x80000003
#define HKEY_PERFORMANCE_DATA 0x80000004
#define HKEY_CURRENT_CONFIG 0x80000005
#define HKEY_DYN_DATA 0x80000006

#IFNDEF WINNT_H
	#define REG_OPTION_NON_VOLATILE  0x00000000
	#define REG_OPTION_VOLATILE  0x00000001
	#define REG_OPTION_CREATE_LINK  0x00000002
	#define REG_OPTION_BACKUP_RESTORE  0x00000004
	#define REG_OPTION_OPEN_LINK  0x00000008
	#define REG_CREATED_NEW_KEY  0x00000001
	#define REG_OPENED_EXISTING_KEY  0x00000002
	
	#define REG_NONE  0
	#define REG_SZ  1
	#define REG_EXPAND_SZ  2
	#define REG_BINARY  3
	#define REG_DWORD  4
	#define REG_DWORD_LITTLE_ENDIAN  4
	#define REG_DWORD_BIG_ENDIAN  5
	#define REG_LINK  6
	#define REG_MULTI_SZ  7
	#define REG_RESOURCE_LIST  8
	#define REG_FULL_RESOURCE_DESCRIPTOR  9
	#define REG_RESOURCE_REQUIREMENTS_LIST  10
	#define REG_QWORD  11
	#define REG_QWORD_LITTLE_ENDIAN  11
	
	#define REG_NOTIFY_CHANGE_NAME  0x00000001
	#define REG_NOTIFY_CHANGE_ATTRIBUTES  0x00000002
	#define REG_NOTIFY_CHANGE_LAST_SET  0x00000004
	#define REG_NOTIFY_CHANGE_SECURITY  0x00000008
#ENDIF

#define REASON_SWINSTALL  0
#define REASON_HWINSTALL  1
#define REASON_SERVICEHANG  2
#define REASON_UNSTABLE  3
#define REASON_SWHWRECONF  4
#define REASON_OTHER  5
#define REASON_UNKNOWN  255
#define REASON_PLANNED_FLAG  0x80000000

#ifndef PROVIDER_STRUCTS_DEFINED
	#define PROVIDER_STRUCTS_DEFINED
	
	#define PROVIDER_KEEPS_VALUE_LENGTH  0x1
	
	VALCONTEXT STRUCT
		valuelen DD
		value_context PTR
		val_buff_ptr PTR
	ENDS

	#DEFINE val_context VALCONTEXT

	PVALUEA STRUCT
		pv_valuename PTR
		pv_valuelen DD
		pv_value_context PTR
		pv_type DD
	ENDS

	#DEFINE pvalueA PVALUEA

	PVALUEW STRUCT
		pv_valuename PTR
		pv_valuelen DD
		pv_value_context PTR
		pv_type DD
	ENDS

	#DEFINE pvalueW PVALUEW

	REG_PROVIDER STRUCT
		pi_R0_1val PTR
		pi_R0_allvals PTR
		pi_R3_1val PTR
		pi_R3_allvals PTR
		pi_flags DD
		pi_key_context PTR
	ENDS

	#DEFINE provider_info REG_PROVIDER

	VALENTA STRUCT
		ve_valuename PTR
		ve_valuelen DD
		ve_valueptr DD
		ve_type DD
	ENDS

	#DEFINE value_entA VALENTA

	VALENTW STRUCT
		ve_valuename PTR
		ve_valuelen DD
		ve_valueptr DWORD_PTR
		ve_type DD
	ENDS

	#DEFINE value_entW VALENTW

#endif /* _PROVIDER_STRUCTS_DEFINED */

#IFDEF UNICODE
	#define AbortSystemShutdown AbortSystemShutdownW
	#define InitiateSystemShutdown InitiateSystemShutdownW
	#define InitiateSystemShutdownEx InitiateSystemShutdownExW
	#define RegConnectRegistry RegConnectRegistryW
	#define RegCreateKey RegCreateKeyW
	#define RegCreateKeyEx RegCreateKeyExW
	#define RegDeleteKey RegDeleteKeyW
	#define RegDeleteValue RegDeleteValueW
	#define RegEnumKey RegEnumKeyW
	#define RegEnumKeyEx RegEnumKeyExW
	#define RegEnumValue RegEnumValueW
	#define RegLoadKey RegLoadKeyW
	#define RegOpenKey RegOpenKeyW
	#define RegOpenKeyEx RegOpenKeyExW
	#define RegQueryInfoKey RegQueryInfoKeyW
	#define RegQueryMultipleValues RegQueryMultipleValuesW
	#define RegQueryValue RegQueryValueW
	#define RegQueryValueEx RegQueryValueExW
	#define RegReplaceKey RegReplaceKeyW
	#define RegRestoreKey RegRestoreKeyW
	#define RegSaveKey RegSaveKeyW
	#define RegSetValue RegSetValueW
	#define RegSetValueEx RegSetValueExW
	#define RegUnLoadKey RegUnLoadKeyW
#else
	#define AbortSystemShutdown AbortSystemShutdownA
	#define InitiateSystemShutdown InitiateSystemShutdownA
	#define InitiateSystemShutdownEx InitiateSystemShutdownExA
	#define RegConnectRegistry RegConnectRegistryA
	#define RegCreateKey RegCreateKeyA
	#define RegCreateKeyEx RegCreateKeyExA
	#define RegDeleteKey RegDeleteKeyA
	#define RegDeleteValue RegDeleteValueA
	#define RegEnumKey RegEnumKeyA
	#define RegEnumKeyEx RegEnumKeyExA
	#define RegEnumValue RegEnumValueA
	#define RegLoadKey RegLoadKeyA
	#define RegOpenKey RegOpenKeyA
	#define RegOpenKeyEx RegOpenKeyExA
	#define RegQueryInfoKey RegQueryInfoKeyA
	#define RegQueryMultipleValues RegQueryMultipleValuesA
	#define RegQueryValue RegQueryValueA
	#define RegQueryValueEx RegQueryValueExA
	#define RegReplaceKey RegReplaceKeyA
	#define RegRestoreKey RegRestoreKeyA
	#define RegSaveKey RegSaveKeyA
	#define RegSetValue RegSetValueA
	#define RegSetValueEx RegSetValueExA
	#define RegUnLoadKey RegUnLoadKeyA
#endif /* UNICODE */

#endif /* WINREG_H */
