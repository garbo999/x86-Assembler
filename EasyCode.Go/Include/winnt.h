#ifndef WINNT_H
#define WINNT_H

#DEFINE WINNT_H_REQVER 100

/*
Switches used
X64 = For use only with 64 bit CPU
UNICODE = Use UNICODE versions
*/

/* Windows NT definitions */

#define ANYSIZE_ARRAY  1

#IF X64
	#define MAX_NATURAL_ALIGNMENT 8
#ELSE
	#define MAX_NATURAL_ALIGNMENT 4
#ENDIF

#IF IA64
	#define MAX_NATURAL_ALIGNMENT 8
#ELSE
	#define MAX_NATURAL_ALIGNMENT 4
#ENDIF

#define APPLICATION_ERROR_MASK  0x20000000
#define ERROR_SEVERITY_SUCCESS  0x00000000
#define ERROR_SEVERITY_INFORMATIONAL 0x40000000
#define ERROR_SEVERITY_WARNING  0x80000000
#define ERROR_SEVERITY_ERROR  0xC0000000

#define UCSCHAR_INVALID_CHARACTER (0xffffffff)
#define MIN_UCSCHAR (0)
#define MAX_UCSCHAR (0x0010FFFF)

#IFNDEF GUID
	GUID STRUCT
		Data1	dd
		Data2	dw
		Data3	dw
		Data4	db 8 DUP
	ENDS
#ENDIF

FLOAT128 STRUCT
	LowPart DQ
	HighPart DQ
ENDS

#define MAXLONGLONG  0x7FFFFFFFFFFFFFFF

LARGE_INTEGER STRUCT
	LowPart DD
	HighPart DD
ENDS

LUID STRUCT
	LowPart DD
	HighPart DD
ENDS

#DEFINE GUID_MAX_POWER_SAVINGS <0xA1841308, 0x3541, 0x4FAB, <0xBC, 0x81, 0xF7, 0x15, 0x56, 0xF2, 0x0B, 0x4A>>
#DEFINE GUID_MIN_POWER_SAVINGS <0x8C5E7FDA, 0xE8BF, 0x4A96, <0x9A, 0x85, 0xA6, 0xE2, 0x3A, 0x8C, 0x63, 0x5C>>
#DEFINE GUID_TYPICAL_POWER_SAVINGS <0x381B4222, 0xF694, 0x41F0, <0x96, 0x85, 0xFF, 0x5B, 0xB2, 0x60, 0xDF, 0x2E>>
#DEFINE GUID_NO_SUBGROUP_GUID <0xFEA3413E, 0x7E05, 0x4911, <0x9A, 0x71, 0x70, 0x03, 0x31, 0xF1, 0xC2, 0x94>>
#DEFINE GUID_ALL_POWERSCHEMES_GUID <0x68A1E95E, 0x13EA, 0x41E1, <0x80, 0x11, 0x0C, 0x49, 0x6C, 0xA4, 0x90, 0xB0>>
#DEFINE GUID_POWERSCHEME_PERSONALITY <0x245D8541, 0x3943, 0x4422, <0xB0, 0x25, 0x13, 0xA7, 0x84, 0xF6, 0x79, 0xB7>>
#DEFINE GUID_ACTIVE_POWERSCHEME <0x31F9F286, 0x5084, 0x42FE, <0xB7, 0x20, 0x2B, 0x02, 0x64, 0x99, 0x37, 0x63>>
#DEFINE GUID_VIDEO_SUBGROUP <0x7516B95F, 0xF776, 0x4464, <0x8C, 0x53, 0x06, 0x16, 0x7F, 0x40, 0xCC, 0x99>>
#DEFINE GUID_VIDEO_POWERDOWN_TIMEOUT <0x3C0BC021, 0xC8A8, 0x4E07, <0xA9, 0x73, 0x6B, 0x14, 0xCB, 0xCB, 0x2B, 0x7E>>
#DEFINE GUID_VIDEO_ADAPTIVE_POWERDOWN <0x90959D22, 0xD6A1, 0x49B9, <0xAF, 0x93, 0xBC, 0xE8, 0x85, 0xAD, 0x33, 0x5B>>
#DEFINE GUID_MONITOR_POWER_ON <0x02731015, 0x4510, 0x4526, <0x99, 0xE6, 0xE5, 0xA1, 0x7E, 0xBD, 0x1A, 0xEA>>
#DEFINE GUID_DISK_SUBGROUP <0x0012EE47, 0x9041, 0x4B5D, <0x9B, 0x77, 0x53, 0x5F, 0xBA, 0x8B, 0x14, 0x42>>
#DEFINE GUID_DISK_POWERDOWN_TIMEOUT <0x6738E2C4, 0xE8A5, 0x4A42, <0xB1, 0x6A, 0xE0, 0x40, 0xE7, 0x69, 0x75, 0x6E>>
#DEFINE GUID_DISK_BURST_IGNORE_THRESHOLD <0x80e3c60e, 0xbb94, 0x4ad8, <0xbb, 0xe0, 0x0d, 0x31, 0x95, 0xef, 0xc6, 0x63>>
#DEFINE GUID_DISK_ADAPTIVE_POWERDOWN <0x396A32E1, 0x499A, 0x40B2, <0x91, 0x24, 0xA9, 0x6A, 0xFE, 0x70, 0x76, 0x67>>
#DEFINE GUID_SLEEP_SUBGROUP <0x238C9FA8, 0x0AAD, 0x41ED, <0x83, 0xF4, 0x97, 0xBE, 0x24, 0x2C, 0x8F, 0x20>>
#DEFINE GUID_SLEEP_IDLE_THRESHOLD <0x81cd32e0, 0x7833, 0x44f3, <0x87, 0x37, 0x70, 0x81, 0xf3, 0x8d, 0x1f, 0x70>>
#DEFINE GUID_STANDBY_TIMEOUT <0x29F6C1DB, 0x86DA, 0x48C5, <0x9F, 0xDB, 0xF2, 0xB6, 0x7B, 0x1F, 0x44, 0xDA>>
#DEFINE GUID_UNATTEND_SLEEP_TIMEOUT <0x7bc4a2f9, 0xd8fc, 0x4469, <0xb0, 0x7b, 0x33, 0xeb, 0x78, 0x5a, 0xac, 0xa0>>
#DEFINE GUID_HIBERNATE_TIMEOUT <0x9D7815A6, 0x7EE4, 0x497E, <0x88, 0x88, 0x51, 0x5A, 0x05, 0xF0, 0x23, 0x64>>
#DEFINE GUID_HIBERNATE_FASTS4_POLICY <0x94AC6D29, 0x73CE, 0x41A6, <0x80, 0x9F, 0x63, 0x63, 0xBA, 0x21, 0xB4, 0x7E>>
#DEFINE GUID_CRITICAL_POWER_TRANSITION <0xB7A27025, 0xE569, 0x46c2, <0xA5, 0x04, 0x2B, 0x96, 0xCA, 0xD2, 0x25, 0xA1>>
#DEFINE GUID_SYSTEM_AWAYMODE <0x98A7F580, 0x01F7, 0x48AA, <0x9C, 0x0F, 0x44, 0x35, 0x2C, 0x29, 0xE5, 0xC0>>
#DEFINE GUID_ALLOW_AWAYMODE <0x25dfa149, 0x5dd1, 0x4736, <0xb5, 0xab, 0xe8, 0xa3, 0x7b, 0x5b, 0x81, 0x87>>
#DEFINE GUID_ALLOW_STANDBY_STATES <0xabfc2519, 0x3608, 0x4c2a, <0x94, 0xea, 0x17, 0x1b, 0x0e, 0xd5, 0x46, 0xab>>
#DEFINE GUID_ALLOW_RTC_WAKE <0xBD3B718A, 0x0680, 0x4D9D, <0x8A, 0xB2, 0xE1, 0xD2, 0xB4, 0xAC, 0x80, 0x6D>>
#DEFINE GUID_SYSTEM_BUTTON_SUBGROUP <0x4F971E89, 0xEEBD, 0x4455, <0xA8, 0xDE, 0x9E, 0x59, 0x04, 0x0E, 0x73, 0x47>>
#DEFINE GUID_POWERBUTTON_ACTION <0x7648EFA3, 0xDD9C, 0x4E3E, <0xB5, 0x66, 0x50, 0xF9, 0x29, 0x38, 0x62, 0x80>>
#DEFINE GUID_POWERBUTTON_ACTION_FLAGS <0x857E7FAC, 0x034B, 0x4704, <0xAB, 0xB1, 0xBC, 0xA5, 0x4A, 0xA3, 0x14, 0x78>>
#DEFINE GUID_SLEEPBUTTON_ACTION <0x96996BC0, 0xAD50, 0x47EC, <0x92, 0x3B, 0x6F, 0x41, 0x87, 0x4D, 0xD9, 0xEB>>
#DEFINE GUID_SLEEPBUTTON_ACTION_FLAGS <0x2A160AB1, 0xB69D, 0x4743, <0xB7, 0x18, 0xBF, 0x14, 0x41, 0xD5, 0xE4, 0x93>>
#DEFINE GUID_USERINTERFACEBUTTON_ACTION <0xA7066653, 0x8D6C, 0x40A8, <0x91, 0x0E, 0xA1, 0xF5, 0x4B, 0x84, 0xC7, 0xE5>>
#DEFINE GUID_LIDCLOSE_ACTION <0x5CA83367, 0x6E45, 0x459F, <0xA2, 0x7B, 0x47, 0x6B, 0x1D, 0x01, 0xC9, 0x36>>
#DEFINE GUID_LIDCLOSE_ACTION_FLAGS <0x97E969AC, 0x0D6C, 0x4D08, <0x92, 0x7C, 0xD7, 0xBD, 0x7A, 0xD7, 0x85, 0x7B>>
#DEFINE GUID_LIDOPEN_POWERSTATE <0x99FF10E7, 0x23B1, 0x4C07, <0xA9, 0xD1, 0x5C, 0x32, 0x06, 0xD7, 0x41, 0xB4>>
#DEFINE GUID_BATTERY_SUBGROUP <0xE73A048D, 0xBF27, 0x4F12, <0x97, 0x31, 0x8B, 0x20, 0x76, 0xE8, 0x89, 0x1F>>
#DEFINE GUID_BATTERY_DISCHARGE_ACTION_0 <0x637EA02F, 0xBBCB, 0x4015, <0x8E, 0x2C, 0xA1, 0xC7, 0xB9, 0xC0, 0xB5, 0x46>>
#DEFINE GUID_BATTERY_DISCHARGE_LEVEL_0 <0x9A66D8D7, 0x4FF7, 0x4EF9, <0xB5, 0xA2, 0x5A, 0x32, 0x6C, 0xA2, 0xA4, 0x69>>
#DEFINE GUID_BATTERY_DISCHARGE_FLAGS_0 <0x5dbb7c9f, 0x38e9, 0x40d2, <0x97, 0x49, 0x4f, 0x8a, 0x0e, 0x9f, 0x64, 0x0f>>
#DEFINE GUID_BATTERY_DISCHARGE_ACTION_1 <0xD8742DCB, 0x3E6A, 0x4B3C, <0xB3, 0xFE, 0x37, 0x46, 0x23, 0xCD, 0xCF, 0x06>>
#DEFINE GUID_BATTERY_DISCHARGE_LEVEL_1 <0x8183BA9A, 0xE910, 0x48DA, <0x87, 0x69, 0x14, 0xAE, 0x6D, 0xC1, 0x17, 0x0A>>
#DEFINE GUID_BATTERY_DISCHARGE_FLAGS_1 <0xbcded951, 0x187b, 0x4d05, <0xbc, 0xcc, 0xf7, 0xe5, 0x19, 0x60, 0xc2, 0x58>>
#DEFINE GUID_BATTERY_DISCHARGE_ACTION_2 <0x421CBA38, 0x1A8E, 0x4881, <0xAC, 0x89, 0xE3, 0x3A, 0x8B, 0x04, 0xEC, 0xE4>>
#DEFINE GUID_BATTERY_DISCHARGE_LEVEL_2 <0x07A07CA2, 0xADAF, 0x40D7, <0xB0, 0x77, 0x53, 0x3A, 0xAD, 0xED, 0x1B, 0xFA>>
#DEFINE GUID_BATTERY_DISCHARGE_FLAGS_2 <0x7fd2f0c4, 0xfeb7, 0x4da3, <0x81, 0x17, 0xe3, 0xfb, 0xed, 0xc4, 0x65, 0x82>>
#DEFINE GUID_BATTERY_DISCHARGE_ACTION_3 <0x80472613, 0x9780, 0x455E, <0xB3, 0x08, 0x72, 0xD3, 0x00, 0x3C, 0xF2, 0xF8>>
#DEFINE GUID_BATTERY_DISCHARGE_LEVEL_3 <0x58AFD5A6, 0xC2DD, 0x47D2, <0x9F, 0xBF, 0xEF, 0x70, 0xCC, 0x5C, 0x59, 0x65>>
#DEFINE GUID_BATTERY_DISCHARGE_FLAGS_3 <0x73613ccf, 0xdbfa, 0x4279, <0x83, 0x56, 0x49, 0x35, 0xf6, 0xbf, 0x62, 0xf3>>
#DEFINE GUID_PROCESSOR_SETTINGS_SUBGROUP <0x54533251, 0x82BE, 0x4824, <0x96, 0xC1, 0x47, 0xB6, 0x0B, 0x74, 0x0D, 0x00>>
#DEFINE GUID_PROCESSOR_THROTTLE_POLICY <0x57027304, 0x4AF6, 0x4104, <0x92, 0x60, 0xE3, 0xD9, 0x52, 0x48, 0xFC, 0x36>>
#DEFINE GUID_PROCESSOR_THROTTLE_MAXIMUM <0xBC5038F7, 0x23E0, 0x4960, <0x96, 0xDA, 0x33, 0xAB, 0xAF, 0x59, 0x35, 0xEC>>
#DEFINE GUID_PROCESSOR_THROTTLE_MINIMUM <0x893DEE8E, 0x2BEF, 0x41E0, <0x89, 0xC6, 0xB5, 0x5D, 0x09, 0x29, 0x96, 0x4C>>
#DEFINE GUID_PROCESSOR_ALLOW_THROTTLING <0x3b04d4fd, 0x1cc7, 0x4f23, <0xab, 0x1c, 0xd1, 0x33, 0x78, 0x19, 0xc4, 0xbb>>
#DEFINE GUID_PROCESSOR_IDLESTATE_POLICY <0x68f262a7, 0xf621, 0x4069, <0xb9, 0xa5, 0x48, 0x74, 0x16, 0x9b, 0xe2, 0x3c>>
#DEFINE GUID_PROCESSOR_PERFSTATE_POLICY <0xBBDC3814, 0x18E9, 0x4463, <0x8A, 0x55, 0xD1, 0x97, 0x32, 0x7C, 0x45, 0xC0>>
#DEFINE GUID_SYSTEM_COOLING_POLICY <0x94D3A615, 0xA899, 0x4AC5, <0xAE, 0x2B, 0xE4, 0xD8, 0xF6, 0x34, 0x36, 0x7F>>
#DEFINE GUID_LOCK_CONSOLE_ON_WAKE <0x0E796BDB, 0x100D, 0x47D6, <0xA2, 0xD5, 0xF7, 0xD2, 0xDA, 0xA5, 0x1F, 0x51>>
#DEFINE GUID_DEVICE_IDLE_POLICY <0x4faab71a, 0x92e5, 0x4726, <0xb5, 0x31, 0x22, 0x45, 0x59, 0x67, 0x2d, 0x19>>
#DEFINE GUID_PPM_PERFSTATE_CHANGE_GUID <0xa5b32ddd, 0x7f39, 0x4abc, <0xb8, 0x92, 0x90, 0xe, 0x43, 0xb5, 0x9e, 0xbb>>
#DEFINE GUID_PPM_PERFSTATE_DOMAIN_CHANGE_GUID <0x995e6b7f, 0xd653, 0x497a, <0xb9, 0x78, 0x36, 0xa3, 0xc, 0x29, 0xbf, 0x1>>
#DEFINE GUID_PPM_IDLESTATE_CHANGE_GUID <0x4838fe4f, 0xf71c, 0x4e51, <0x9e, 0xcc, 0x84, 0x30, 0xa7, 0xac, 0x4c, 0x6c>>
#DEFINE GUID_PPM_PERFSTATES_DATA_GUID <0x5708cc20, 0x7d40, 0x4bf4, <0xb4, 0xaa, 0x2b, 0x01, 0x33, 0x8d, 0x01, 0x26>>
#DEFINE GUID_PPM_IDLESTATES_DATA_GUID <0xba138e10, 0xe250, 0x4ad7, <0x86, 0x16, 0xcf, 0x1a, 0x7a, 0xd4, 0x10, 0xe7>>
#DEFINE GUID_PPM_IDLE_ACCOUNTING_GUID <0xe2a26f78, 0xae07, 0x4ee0, <0xa3, 0x0f, 0xce, 0x54, 0xf5, 0x5a, 0x94, 0xcd>>
#DEFINE GUID_PPM_THERMALCONSTRAINT_GUID <0xa852c2c8, 0x1a4c, 0x423b, <0x8c, 0x2c, 0xf3, 0x0d, 0x82, 0x93, 0x1a, 0x88>>
#DEFINE GUID_PPM_PERFMON_PERFSTATE_GUID <0x7fd18652, 0xcfe, 0x40d2, <0xb0, 0xa1, 0xb, 0x6, 0x6a, 0x87, 0x75, 0x9e>>
#DEFINE GUID_PPM_THERMAL_POLICY_CHANGE_GUID <0x48f377b8, 0x6880, 0x4c7b, <0x8b, 0xdc, 0x38, 0x1, 0x76, 0xc6, 0x65, 0x4d>>

#define ANSI_NULL 0
#define UNICODE_NULL 0

#define MINCHAR  0x80
#define MAXCHAR  0x7F
#define MINSHORT  0x8000
#define MAXSHORT  0x7FFF
#define MINLONG  0x80000000
#define MAXLONG  0x7FFFFFFF
#define MAXBYTE  0xFF
#define MAXWORD  0xFFFF
#define MAXDWORD  0xFFFFFFFF

#define NLS_VALID_LOCALE_MASK  0x000FFFFF

#define VER_SERVER_NT                       0x80000000
#define VER_WORKSTATION_NT                  0x40000000
#define VER_SUITE_SMALLBUSINESS             0x00000001
#define VER_SUITE_ENTERPRISE                0x00000002
#define VER_SUITE_BACKOFFICE                0x00000004
#define VER_SUITE_COMMUNICATIONS            0x00000008
#define VER_SUITE_TERMINAL                  0x00000010
#define VER_SUITE_SMALLBUSINESS_RESTRICTED  0x00000020
#define VER_SUITE_EMBEDDEDNT                0x00000040
#define VER_SUITE_DATACENTER                0x00000080
#define VER_SUITE_SINGLEUSERTS              0x00000100
#define VER_SUITE_PERSONAL                  0x00000200
#define VER_SUITE_BLADE                     0x00000400
#define VER_SUITE_EMBEDDED_RESTRICTED       0x00000800
#define VER_SUITE_SECURITY_APPLIANCE        0x00001000
#define VER_SUITE_STORAGE_SERVER            0x00002000
#define VER_SUITE_COMPUTE_SERVER            0x00004000
#define VER_SUITE_WH_SERVER                 0x00008000

ActivationContextBasicInformation                       = 1
ActivationContextDetailedInformation                    = 2
AssemblyDetailedInformationInActivationContext          = 3
FileInformationInAssemblyOfAssemblyInActivationContext  = 4
RunlevelInformationInActivationContext                  = 5
MaxActivationContextInfoClass = 6
//
// compatibility with old names
//
AssemblyDetailedInformationInActivationContxt           = 3
FileInformationInAssemblyOfAssemblyInActivationContxt   = 4

//
// Product types
// This list grows with each OS release.
//
// There is no ordering of values to ensure callers
// do an equality test i.e. greater-than and less-than
// comparisons are not useful.
//
// NOTE: Values in this list should never be deleted.
//       When a product-type 'X' gets dropped from a
//       OS release onwards, the value of 'X' continues
//       to be used in the mapping table of GetProductInfo.
//

#define PRODUCT_UNDEFINED                           0x00000000

#define PRODUCT_ULTIMATE                            0x00000001
#define PRODUCT_HOME_BASIC                          0x00000002
#define PRODUCT_HOME_PREMIUM                        0x00000003
#define PRODUCT_ENTERPRISE                          0x00000004
#define PRODUCT_HOME_BASIC_N                        0x00000005
#define PRODUCT_BUSINESS                            0x00000006
#define PRODUCT_STANDARD_SERVER                     0x00000007
#define PRODUCT_DATACENTER_SERVER                   0x00000008
#define PRODUCT_SMALLBUSINESS_SERVER                0x00000009
#define PRODUCT_ENTERPRISE_SERVER                   0x0000000A
#define PRODUCT_STARTER                             0x0000000B
#define PRODUCT_DATACENTER_SERVER_CORE              0x0000000C
#define PRODUCT_STANDARD_SERVER_CORE                0x0000000D
#define PRODUCT_ENTERPRISE_SERVER_CORE              0x0000000E
#define PRODUCT_ENTERPRISE_SERVER_IA64              0x0000000F
#define PRODUCT_BUSINESS_N                          0x00000010
#define PRODUCT_WEB_SERVER                          0x00000011
#define PRODUCT_CLUSTER_SERVER                      0x00000012
#define PRODUCT_HOME_SERVER                         0x00000013
#define PRODUCT_STORAGE_EXPRESS_SERVER              0x00000014
#define PRODUCT_STORAGE_STANDARD_SERVER             0x00000015
#define PRODUCT_STORAGE_WORKGROUP_SERVER            0x00000016
#define PRODUCT_STORAGE_ENTERPRISE_SERVER           0x00000017
#define PRODUCT_SERVER_FOR_SMALLBUSINESS            0x00000018
#define PRODUCT_SMALLBUSINESS_SERVER_PREMIUM        0x00000019
#define PRODUCT_HOME_PREMIUM_N                      0x0000001A
#define PRODUCT_ENTERPRISE_N                        0x0000001B
#define PRODUCT_ULTIMATE_N                          0x0000001C
#define PRODUCT_WEB_SERVER_CORE                     0x0000001D
#define PRODUCT_MEDIUMBUSINESS_SERVER_MANAGEMENT    0x0000001E
#define PRODUCT_MEDIUMBUSINESS_SERVER_SECURITY      0x0000001F
#define PRODUCT_MEDIUMBUSINESS_SERVER_MESSAGING     0x00000020
#define PRODUCT_SMALLBUSINESS_SERVER_PRIME          0x00000021
#define PRODUCT_HOME_PREMIUM_SERVER                 0x00000022
#define PRODUCT_SERVER_FOR_SMALLBUSINESS_V          0x00000023
#define PRODUCT_STANDARD_SERVER_V                   0x00000024
#define PRODUCT_DATACENTER_SERVER_V                 0x00000025
#define PRODUCT_ENTERPRISE_SERVER_V                 0x00000026
#define PRODUCT_DATACENTER_SERVER_CORE_V            0x00000027
#define PRODUCT_STANDARD_SERVER_CORE_V              0x00000028
#define PRODUCT_ENTERPRISE_SERVER_CORE_V            0x00000029
#define PRODUCT_HYPERV                              0x0000002A
#define PRODUCT_UNLICENSED                          0xABCDABCD

#Define LOCALE_USER_DEFAULT 0400h

#IFNDEF WINNLS_H
	#Define LOCALE_SYSTEM_DEFAULT 2048
	#Define LOCALE_NOUSEROVERRIDE 80000000h
	#Define LOCALE_ILANGUAGE 1h
	#Define LOCALE_SLANGUAGE 2h
	#Define LOCALE_SENGLANGUAGE 1001h
	#Define LOCALE_SABBREVLANGNAME 3h
	#Define LOCALE_SNATIVELANGNAME 4h
	#Define LOCALE_ICOUNTRY 5h
	#Define LOCALE_SCOUNTRY 6h
	#Define LOCALE_SENGCOUNTRY 1002h
	#Define LOCALE_SABBREVCTRYNAME 7h
	#Define LOCALE_SNATIVECTRYNAME 8h
	#Define LOCALE_IDEFAULTLANGUAGE 9h
	#Define LOCALE_IDEFAULTCOUNTRY 0Ah
	#Define LOCALE_IDEFAULTCODEPAGE 0Bh
	#Define LOCALE_SLIST 0Ch
	#Define LOCALE_IMEASURE 0Dh
	#Define LOCALE_SDECIMAL 0Eh
	#Define LOCALE_STHOUSAND 0Fh
	#Define LOCALE_SGROUPING 10h
	#Define LOCALE_IDIGITS 11h
	#Define LOCALE_ILZERO 12h
	#Define LOCALE_SNATIVEDIGITS 13h
	#Define LOCALE_SCURRENCY 14h
	#Define LOCALE_SINTLSYMBOL 15h
	#Define LOCALE_SMONDECIMALSEP 16h
	#Define LOCALE_SMONTHOUSANDSEP 17h
	#Define LOCALE_SMONGROUPING 18h
	#Define LOCALE_ICURRDIGITS 19h
	#Define LOCALE_IINTLCURRDIGITS 1Ah
	#Define LOCALE_ICURRENCY 1Bh
	#Define LOCALE_INEGCURR 1Ch
	#Define LOCALE_SDATE 1Dh
	#Define LOCALE_STIME 1Eh
	#Define LOCALE_SSHORTDATE 1Fh
	#Define LOCALE_SLONGDATE 20h
	#Define LOCALE_STIMEFORMAT 1003h
	#Define LOCALE_IDATE 21h
	#Define LOCALE_ILDATE 22h
	#Define LOCALE_ITIME 23h
	#Define LOCALE_ICENTURY 24h
	#Define LOCALE_ITLZERO 25h
	#Define LOCALE_IDAYLZERO 26h
	#Define LOCALE_IMONLZERO 27h
	#Define LOCALE_S1159 28h
	#Define LOCALE_S2359 29h
	#Define LOCALE_SDAYNAME1 2Ah
	#Define LOCALE_SDAYNAME2 2Bh
	#Define LOCALE_SDAYNAME3 2Ch
	#Define LOCALE_SDAYNAME4 2Dh
	#Define LOCALE_SDAYNAME5 2Eh
	#Define LOCALE_SDAYNAME6 2Fh
	#Define LOCALE_SDAYNAME7 30h
	#Define LOCALE_SABBREVDAYNAME1 31h
	#Define LOCALE_SABBREVDAYNAME2 32h
	#Define LOCALE_SABBREVDAYNAME3 33h
	#Define LOCALE_SABBREVDAYNAME4 34h
	#Define LOCALE_SABBREVDAYNAME5 35h
	#Define LOCALE_SABBREVDAYNAME6 36h
	#Define LOCALE_SABBREVDAYNAME7 37h
	#Define LOCALE_SMONTHNAME1 38h
	#Define LOCALE_SMONTHNAME2 39h
	#Define LOCALE_SMONTHNAME3 3Ah
	#Define LOCALE_SMONTHNAME4 3Bh
	#Define LOCALE_SMONTHNAME5 3Ch
	#Define LOCALE_SMONTHNAME6 3Dh
	#Define LOCALE_SMONTHNAME7 3Eh
	#Define LOCALE_SMONTHNAME8 3Fh
	#Define LOCALE_SMONTHNAME9 40h
	#Define LOCALE_SMONTHNAME10 41h
	#Define LOCALE_SMONTHNAME11 42h
	#Define LOCALE_SMONTHNAME12 43h
	#Define LOCALE_SABBREVMONTHNAME1 44h
	#Define LOCALE_SABBREVMONTHNAME2 45h
	#Define LOCALE_SABBREVMONTHNAME3 46h
	#Define LOCALE_SABBREVMONTHNAME4 47h
	#Define LOCALE_SABBREVMONTHNAME5 48h
	#Define LOCALE_SABBREVMONTHNAME6 49h
	#Define LOCALE_SABBREVMONTHNAME7 4Ah
	#Define LOCALE_SABBREVMONTHNAME8 4Bh
	#Define LOCALE_SABBREVMONTHNAME9 4Ch
	#Define LOCALE_SABBREVMONTHNAME10 4Dh
	#Define LOCALE_SABBREVMONTHNAME11 4Eh
	#Define LOCALE_SABBREVMONTHNAME12 4Fh
	#Define LOCALE_SABBREVMONTHNAME13 100Fh
	#Define LOCALE_SPOSITIVESIGN 50h
	#Define LOCALE_SNEGATIVESIGN 51h
	#Define LOCALE_IPOSSIGNPOSN 52h
	#Define LOCALE_INEGSIGNPOSN 53h
	#Define LOCALE_IPOSSYMPRECEDES 54h
	#Define LOCALE_IPOSSEPBYSPACE 55h
	#Define LOCALE_INEGSYMPRECEDES 56h
	#Define LOCALE_INEGSEPBYSPACE 57h
	#define LOCALE_FONTSIGNATURE  58h
	#define LOCALE_SISO639LANGNAME  59h
	#define LOCALE_SISO3166CTRYNAME  5Ah
#ENDIF

#define LANG_NEUTRAL                     0x00
#define LANG_INVARIANT                   0x7f

#define LANG_AFRIKAANS                   0x36
#define LANG_ALBANIAN                    0x1c
#define LANG_ALSATIAN                    0x84
#define LANG_AMHARIC                     0x5e
#define LANG_ARABIC                      0x01
#define LANG_ARMENIAN                    0x2b
#define LANG_ASSAMESE                    0x4d
#define LANG_AZERI                       0x2c
#define LANG_BASHKIR                     0x6d
#define LANG_BASQUE                      0x2d
#define LANG_BELARUSIAN                  0x23
#define LANG_BENGALI                     0x45
#define LANG_BRETON                      0x7e
#define LANG_BOSNIAN                     0x1a   // Use with SUBLANG_BOSNIAN_* Sublanguage IDs
#define LANG_BOSNIAN_NEUTRAL           0x781a   // Use with the ConvertDefaultLocale function
#define LANG_BULGARIAN                   0x02
#define LANG_CATALAN                     0x03
#define LANG_CHINESE                     0x04   // Use with SUBLANG_CHINESE_* Sublanguage IDs
#define LANG_CHINESE_SIMPLIFIED          0x04   // Use with the ConvertDefaultLocale function
#define LANG_CHINESE_TRADITIONAL       0x7c04   // Use with the ConvertDefaultLocale function
#define LANG_CORSICAN                    0x83
#define LANG_CROATIAN                    0x1a
#define LANG_CZECH                       0x05
#define LANG_DANISH                      0x06
#define LANG_DARI                        0x8c
#define LANG_DIVEHI                      0x65
#define LANG_DUTCH                       0x13
#define LANG_ENGLISH                     0x09
#define LANG_ESTONIAN                    0x25
#define LANG_FAEROESE                    0x38
#define LANG_FARSI                       0x29   // Deprecated: use LANG_PERSIAN instead
#define LANG_FILIPINO                    0x64
#define LANG_FINNISH                     0x0b
#define LANG_FRENCH                      0x0c
#define LANG_FRISIAN                     0x62
#define LANG_GALICIAN                    0x56
#define LANG_GEORGIAN                    0x37
#define LANG_GERMAN                      0x07
#define LANG_GREEK                       0x08
#define LANG_GREENLANDIC                 0x6f
#define LANG_GUJARATI                    0x47
#define LANG_HAUSA                       0x68
#define LANG_HEBREW                      0x0d
#define LANG_HINDI                       0x39
#define LANG_HUNGARIAN                   0x0e
#define LANG_ICELANDIC                   0x0f
#define LANG_IGBO                        0x70
#define LANG_INDONESIAN                  0x21
#define LANG_INUKTITUT                   0x5d
#define LANG_IRISH                       0x3c   // Use with the SUBLANG_IRISH_IRELAND Sublanguage ID
#define LANG_ITALIAN                     0x10
#define LANG_JAPANESE                    0x11
#define LANG_KANNADA                     0x4b
#define LANG_KASHMIRI                    0x60
#define LANG_KAZAK                       0x3f
#define LANG_KHMER                       0x53
#define LANG_KICHE                       0x86
#define LANG_KINYARWANDA                 0x87
#define LANG_KONKANI                     0x57
#define LANG_KOREAN                      0x12
#define LANG_KYRGYZ                      0x40
#define LANG_LAO                         0x54
#define LANG_LATVIAN                     0x26
#define LANG_LITHUANIAN                  0x27
#define LANG_LOWER_SORBIAN               0x2e
#define LANG_LUXEMBOURGISH               0x6e
#define LANG_MACEDONIAN                  0x2f   // the Former Yugoslav Republic of Macedonia
#define LANG_MALAY                       0x3e
#define LANG_MALAYALAM                   0x4c
#define LANG_MALTESE                     0x3a
#define LANG_MANIPURI                    0x58
#define LANG_MAORI                       0x81
#define LANG_MAPUDUNGUN                  0x7a
#define LANG_MARATHI                     0x4e
#define LANG_MOHAWK                      0x7c
#define LANG_MONGOLIAN                   0x50
#define LANG_NEPALI                      0x61
#define LANG_NORWEGIAN                   0x14
#define LANG_OCCITAN                     0x82
#define LANG_ORIYA                       0x48
#define LANG_PASHTO                      0x63
#define LANG_PERSIAN                     0x29
#define LANG_POLISH                      0x15
#define LANG_PORTUGUESE                  0x16
#define LANG_PUNJABI                     0x46
#define LANG_QUECHUA                     0x6b
#define LANG_ROMANIAN                    0x18
#define LANG_ROMANSH                     0x17
#define LANG_RUSSIAN                     0x19
#define LANG_SAMI                        0x3b
#define LANG_SANSKRIT                    0x4f
#define LANG_SERBIAN                     0x1a   // Use with the SUBLANG_SERBIAN_* Sublanguage IDs
#define LANG_SERBIAN_NEUTRAL           0x7c1a   // Use with the ConvertDefaultLocale function
#define LANG_SINDHI                      0x59
#define LANG_SINHALESE                   0x5b
#define LANG_SLOVAK                      0x1b
#define LANG_SLOVENIAN                   0x24
#define LANG_SOTHO                       0x6c
#define LANG_SPANISH                     0x0a
#define LANG_SWAHILI                     0x41
#define LANG_SWEDISH                     0x1d
#define LANG_SYRIAC                      0x5a
#define LANG_TAJIK                       0x28
#define LANG_TAMAZIGHT                   0x5f
#define LANG_TAMIL                       0x49
#define LANG_TATAR                       0x44
#define LANG_TELUGU                      0x4a
#define LANG_THAI                        0x1e
#define LANG_TIBETAN                     0x51
#define LANG_TIGRIGNA                    0x73
#define LANG_TSWANA                      0x32
#define LANG_TURKISH                     0x1f
#define LANG_TURKMEN                     0x42
#define LANG_UIGHUR                      0x80
#define LANG_UKRAINIAN                   0x22
#define LANG_UPPER_SORBIAN               0x2e
#define LANG_URDU                        0x20
#define LANG_UZBEK                       0x43
#define LANG_VIETNAMESE                  0x2a
#define LANG_WELSH                       0x52
#define LANG_WOLOF                       0x88
#define LANG_XHOSA                       0x34
#define LANG_YAKUT                       0x85
#define LANG_YI                          0x78
#define LANG_YORUBA                      0x6a
#define LANG_ZULU                        0x35

#define SUBLANG_NEUTRAL                             0x00    // language neutral
#define SUBLANG_DEFAULT                             0x01    // user default
#define SUBLANG_SYS_DEFAULT                         0x02    // system default
#define SUBLANG_CUSTOM_DEFAULT                      0x03    // default custom language/locale
#define SUBLANG_CUSTOM_UNSPECIFIED                  0x04    // custom language/locale
#define SUBLANG_UI_CUSTOM_DEFAULT                   0x05    // Default custom MUI language/locale


#define SUBLANG_AFRIKAANS_SOUTH_AFRICA              0x01    // Afrikaans (South Africa) 0x0436 af-ZA
#define SUBLANG_ALBANIAN_ALBANIA                    0x01    // Albanian (Albania) 0x041c sq-AL
#define SUBLANG_ALSATIAN_FRANCE                     0x01    // Alsatian (France) 0x0484
#define SUBLANG_AMHARIC_ETHIOPIA                    0x01    // Amharic (Ethiopia) 0x045e
#define SUBLANG_ARABIC_SAUDI_ARABIA                 0x01    // Arabic (Saudi Arabia)
#define SUBLANG_ARABIC_IRAQ                         0x02    // Arabic (Iraq)
#define SUBLANG_ARABIC_EGYPT                        0x03    // Arabic (Egypt)
#define SUBLANG_ARABIC_LIBYA                        0x04    // Arabic (Libya)
#define SUBLANG_ARABIC_ALGERIA                      0x05    // Arabic (Algeria)
#define SUBLANG_ARABIC_MOROCCO                      0x06    // Arabic (Morocco)
#define SUBLANG_ARABIC_TUNISIA                      0x07    // Arabic (Tunisia)
#define SUBLANG_ARABIC_OMAN                         0x08    // Arabic (Oman)
#define SUBLANG_ARABIC_YEMEN                        0x09    // Arabic (Yemen)
#define SUBLANG_ARABIC_SYRIA                        0x0a    // Arabic (Syria)
#define SUBLANG_ARABIC_JORDAN                       0x0b    // Arabic (Jordan)
#define SUBLANG_ARABIC_LEBANON                      0x0c    // Arabic (Lebanon)
#define SUBLANG_ARABIC_KUWAIT                       0x0d    // Arabic (Kuwait)
#define SUBLANG_ARABIC_UAE                          0x0e    // Arabic (U.A.E)
#define SUBLANG_ARABIC_BAHRAIN                      0x0f    // Arabic (Bahrain)
#define SUBLANG_ARABIC_QATAR                        0x10    // Arabic (Qatar)
#define SUBLANG_ARMENIAN_ARMENIA                    0x01    // Armenian (Armenia) 0x042b hy-AM
#define SUBLANG_ASSAMESE_INDIA                      0x01    // Assamese (India) 0x044d
#define SUBLANG_AZERI_LATIN                         0x01    // Azeri (Latin)
#define SUBLANG_AZERI_CYRILLIC                      0x02    // Azeri (Cyrillic)
#define SUBLANG_BASHKIR_RUSSIA                      0x01    // Bashkir (Russia) 0x046d ba-RU
#define SUBLANG_BASQUE_BASQUE                       0x01    // Basque (Basque) 0x042d eu-ES
#define SUBLANG_BELARUSIAN_BELARUS                  0x01    // Belarusian (Belarus) 0x0423 be-BY
#define SUBLANG_BENGALI_INDIA                       0x01    // Bengali (India)
#define SUBLANG_BENGALI_BANGLADESH                  0x02    // Bengali (Bangladesh)
#define SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_LATIN    0x05    // Bosnian (Bosnia and Herzegovina - Latin) 0x141a bs-BA-Latn
#define SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_CYRILLIC 0x08    // Bosnian (Bosnia and Herzegovina - Cyrillic) 0x201a bs-BA-Cyrl
#define SUBLANG_BRETON_FRANCE                       0x01    // Breton (France) 0x047e
#define SUBLANG_BULGARIAN_BULGARIA                  0x01    // Bulgarian (Bulgaria) 0x0402
#define SUBLANG_CATALAN_CATALAN                     0x01    // Catalan (Catalan) 0x0403
#define SUBLANG_CHINESE_TRADITIONAL                 0x01    // Chinese (Taiwan) 0x0404 zh-TW
#define SUBLANG_CHINESE_SIMPLIFIED                  0x02    // Chinese (PR China) 0x0804 zh-CN
#define SUBLANG_CHINESE_HONGKONG                    0x03    // Chinese (Hong Kong S.A.R., P.R.C.) 0x0c04 zh-HK
#define SUBLANG_CHINESE_SINGAPORE                   0x04    // Chinese (Singapore) 0x1004 zh-SG
#define SUBLANG_CHINESE_MACAU                       0x05    // Chinese (Macau S.A.R.) 0x1404 zh-MO
#define SUBLANG_CORSICAN_FRANCE                     0x01    // Corsican (France) 0x0483
#define SUBLANG_CZECH_CZECH_REPUBLIC                0x01    // Czech (Czech Republic) 0x0405
#define SUBLANG_CROATIAN_CROATIA                    0x01    // Croatian (Croatia)
#define SUBLANG_CROATIAN_BOSNIA_HERZEGOVINA_LATIN   0x04    // Croatian (Bosnia and Herzegovina - Latin) 0x101a hr-BA
#define SUBLANG_DANISH_DENMARK                      0x01    // Danish (Denmark) 0x0406
#define SUBLANG_DARI_AFGHANISTAN                    0x01    // Dari (Afghanistan)
#define SUBLANG_DIVEHI_MALDIVES                     0x01    // Divehi (Maldives) 0x0465 div-MV
#define SUBLANG_DUTCH                               0x01    // Dutch
#define SUBLANG_DUTCH_BELGIAN                       0x02    // Dutch (Belgian)
#define SUBLANG_ENGLISH_US                          0x01    // English (USA)
#define SUBLANG_ENGLISH_UK                          0x02    // English (UK)
#define SUBLANG_ENGLISH_AUS                         0x03    // English (Australian)
#define SUBLANG_ENGLISH_CAN                         0x04    // English (Canadian)
#define SUBLANG_ENGLISH_NZ                          0x05    // English (New Zealand)
#define SUBLANG_ENGLISH_EIRE                        0x06    // English (Irish)
#define SUBLANG_ENGLISH_SOUTH_AFRICA                0x07    // English (South Africa)
#define SUBLANG_ENGLISH_JAMAICA                     0x08    // English (Jamaica)
#define SUBLANG_ENGLISH_CARIBBEAN                   0x09    // English (Caribbean)
#define SUBLANG_ENGLISH_BELIZE                      0x0a    // English (Belize)
#define SUBLANG_ENGLISH_TRINIDAD                    0x0b    // English (Trinidad)
#define SUBLANG_ENGLISH_ZIMBABWE                    0x0c    // English (Zimbabwe)
#define SUBLANG_ENGLISH_PHILIPPINES                 0x0d    // English (Philippines)
#define SUBLANG_ENGLISH_INDIA                       0x10    // English (India)
#define SUBLANG_ENGLISH_MALAYSIA                    0x11    // English (Malaysia)
#define SUBLANG_ENGLISH_SINGAPORE                   0x12    // English (Singapore)
#define SUBLANG_ESTONIAN_ESTONIA                    0x01    // Estonian (Estonia) 0x0425 et-EE
#define SUBLANG_FAEROESE_FAROE_ISLANDS              0x01    // Faroese (Faroe Islands) 0x0438 fo-FO
#define SUBLANG_FILIPINO_PHILIPPINES                0x01    // Filipino (Philippines) 0x0464 fil-PH
#define SUBLANG_FINNISH_FINLAND                     0x01    // Finnish (Finland) 0x040b
#define SUBLANG_FRENCH                              0x01    // French
#define SUBLANG_FRENCH_BELGIAN                      0x02    // French (Belgian)
#define SUBLANG_FRENCH_CANADIAN                     0x03    // French (Canadian)
#define SUBLANG_FRENCH_SWISS                        0x04    // French (Swiss)
#define SUBLANG_FRENCH_LUXEMBOURG                   0x05    // French (Luxembourg)
#define SUBLANG_FRENCH_MONACO                       0x06    // French (Monaco)
#define SUBLANG_FRISIAN_NETHERLANDS                 0x01    // Frisian (Netherlands) 0x0462 fy-NL
#define SUBLANG_GALICIAN_GALICIAN                   0x01    // Galician (Galician) 0x0456 gl-ES
#define SUBLANG_GEORGIAN_GEORGIA                    0x01    // Georgian (Georgia) 0x0437 ka-GE
#define SUBLANG_GERMAN                              0x01    // German
#define SUBLANG_GERMAN_SWISS                        0x02    // German (Swiss)
#define SUBLANG_GERMAN_AUSTRIAN                     0x03    // German (Austrian)
#define SUBLANG_GERMAN_LUXEMBOURG                   0x04    // German (Luxembourg)
#define SUBLANG_GERMAN_LIECHTENSTEIN                0x05    // German (Liechtenstein)
#define SUBLANG_GREEK_GREECE                        0x01    // Greek (Greece)
#define SUBLANG_GREENLANDIC_GREENLAND               0x01    // Greenlandic (Greenland) 0x046f kl-GL
#define SUBLANG_GUJARATI_INDIA                      0x01    // Gujarati (India (Gujarati Script)) 0x0447 gu-IN
#define SUBLANG_HAUSA_NIGERIA_LATIN                 0x01    // Hausa (Latin, Nigeria) 0x0468 ha-NG-Latn
#define SUBLANG_HEBREW_ISRAEL                       0x01    // Hebrew (Israel) 0x040d
#define SUBLANG_HINDI_INDIA                         0x01    // Hindi (India) 0x0439 hi-IN
#define SUBLANG_HUNGARIAN_HUNGARY                   0x01    // Hungarian (Hungary) 0x040e
#define SUBLANG_ICELANDIC_ICELAND                   0x01    // Icelandic (Iceland) 0x040f
#define SUBLANG_IGBO_NIGERIA                        0x01    // Igbo (Nigeria) 0x0470 ig-NG
#define SUBLANG_INDONESIAN_INDONESIA                0x01    // Indonesian (Indonesia) 0x0421 id-ID
#define SUBLANG_INUKTITUT_CANADA                    0x01    // Inuktitut (Syllabics) (Canada) 0x045d iu-CA-Cans
#define SUBLANG_INUKTITUT_CANADA_LATIN              0x02    // Inuktitut (Canada - Latin)
#define SUBLANG_IRISH_IRELAND                       0x02    // Irish (Ireland)
#define SUBLANG_ITALIAN                             0x01    // Italian
#define SUBLANG_ITALIAN_SWISS                       0x02    // Italian (Swiss)
#define SUBLANG_JAPANESE_JAPAN                      0x01    // Japanese (Japan) 0x0411
#define SUBLANG_KANNADA_INDIA                       0x01    // Kannada (India (Kannada Script)) 0x044b kn-IN
#define SUBLANG_KASHMIRI_SASIA                      0x02    // Kashmiri (South Asia)
#define SUBLANG_KASHMIRI_INDIA                      0x02    // For app compatibility only
#define SUBLANG_KAZAK_KAZAKHSTAN                    0x01    // Kazakh (Kazakhstan) 0x043f kk-KZ
#define SUBLANG_KHMER_CAMBODIA                      0x01    // Khmer (Cambodia) 0x0453 kh-KH
#define SUBLANG_KICHE_GUATEMALA                     0x01    // K'iche (Guatemala)
#define SUBLANG_KINYARWANDA_RWANDA                  0x01    // Kinyarwanda (Rwanda) 0x0487 rw-RW
#define SUBLANG_KONKANI_INDIA                       0x01    // Konkani (India) 0x0457 kok-IN
#define SUBLANG_KOREAN                              0x01    // Korean (Extended Wansung)
#define SUBLANG_KYRGYZ_KYRGYZSTAN                   0x01    // Kyrgyz (Kyrgyzstan) 0x0440 ky-KG
#define SUBLANG_LAO_LAO                             0x01    // Lao (Lao PDR) 0x0454 lo-LA
#define SUBLANG_LATVIAN_LATVIA                      0x01    // Latvian (Latvia) 0x0426 lv-LV
#define SUBLANG_LITHUANIAN                          0x01    // Lithuanian
#define SUBLANG_LOWER_SORBIAN_GERMANY               0x02    // Lower Sorbian (Germany) 0x082e wee-DE
#define SUBLANG_LUXEMBOURGISH_LUXEMBOURG            0x01    // Luxembourgish (Luxembourg) 0x046e lb-LU
#define SUBLANG_MACEDONIAN_MACEDONIA                0x01    // Macedonian (Macedonia (FYROM)) 0x042f mk-MK
#define SUBLANG_MALAY_MALAYSIA                      0x01    // Malay (Malaysia)
#define SUBLANG_MALAY_BRUNEI_DARUSSALAM             0x02    // Malay (Brunei Darussalam)
#define SUBLANG_MALAYALAM_INDIA                     0x01    // Malayalam (India (Malayalam Script) ) 0x044c ml-IN
#define SUBLANG_MALTESE_MALTA                       0x01    // Maltese (Malta) 0x043a mt-MT
#define SUBLANG_MAORI_NEW_ZEALAND                   0x01    // Maori (New Zealand) 0x0481 mi-NZ
#define SUBLANG_MAPUDUNGUN_CHILE                    0x01    // Mapudungun (Chile) 0x047a arn-CL
#define SUBLANG_MARATHI_INDIA                       0x01    // Marathi (India) 0x044e mr-IN
#define SUBLANG_MOHAWK_MOHAWK                       0x01    // Mohawk (Mohawk) 0x047c moh-CA
#define SUBLANG_MONGOLIAN_CYRILLIC_MONGOLIA         0x01    // Mongolian (Cyrillic, Mongolia)
#define SUBLANG_MONGOLIAN_PRC                       0x02    // Mongolian (PRC)
#define SUBLANG_NEPALI_INDIA                        0x02    // Nepali (India)
#define SUBLANG_NEPALI_NEPAL                        0x01    // Nepali (Nepal) 0x0461 ne-NP
#define SUBLANG_NORWEGIAN_BOKMAL                    0x01    // Norwegian (Bokmal)
#define SUBLANG_NORWEGIAN_NYNORSK                   0x02    // Norwegian (Nynorsk)
#define SUBLANG_OCCITAN_FRANCE                      0x01    // Occitan (France) 0x0482 oc-FR
#define SUBLANG_ORIYA_INDIA                         0x01    // Oriya (India (Oriya Script)) 0x0448 or-IN
#define SUBLANG_PASHTO_AFGHANISTAN                  0x01    // Pashto (Afghanistan)
#define SUBLANG_PERSIAN_IRAN                        0x01    // Persian (Iran) 0x0429 fa-IR
#define SUBLANG_POLISH_POLAND                       0x01    // Polish (Poland) 0x0415
#define SUBLANG_PORTUGUESE                          0x02    // Portuguese
#define SUBLANG_PORTUGUESE_BRAZILIAN                0x01    // Portuguese (Brazilian)
#define SUBLANG_PUNJABI_INDIA                       0x01    // Punjabi (India (Gurmukhi Script)) 0x0446 pa-IN
#define SUBLANG_QUECHUA_BOLIVIA                     0x01    // Quechua (Bolivia)
#define SUBLANG_QUECHUA_ECUADOR                     0x02    // Quechua (Ecuador)
#define SUBLANG_QUECHUA_PERU                        0x03    // Quechua (Peru)
#define SUBLANG_ROMANIAN_ROMANIA                    0x01    // Romanian (Romania) 0x0418
#define SUBLANG_ROMANSH_SWITZERLAND                 0x01    // Romansh (Switzerland) 0x0417 rm-CH
#define SUBLANG_RUSSIAN_RUSSIA                      0x01    // Russian (Russia) 0x0419
#define SUBLANG_SAMI_NORTHERN_NORWAY                0x01    // Northern Sami (Norway)
#define SUBLANG_SAMI_NORTHERN_SWEDEN                0x02    // Northern Sami (Sweden)
#define SUBLANG_SAMI_NORTHERN_FINLAND               0x03    // Northern Sami (Finland)
#define SUBLANG_SAMI_LULE_NORWAY                    0x04    // Lule Sami (Norway)
#define SUBLANG_SAMI_LULE_SWEDEN                    0x05    // Lule Sami (Sweden)
#define SUBLANG_SAMI_SOUTHERN_NORWAY                0x06    // Southern Sami (Norway)
#define SUBLANG_SAMI_SOUTHERN_SWEDEN                0x07    // Southern Sami (Sweden)
#define SUBLANG_SAMI_SKOLT_FINLAND                  0x08    // Skolt Sami (Finland)
#define SUBLANG_SAMI_INARI_FINLAND                  0x09    // Inari Sami (Finland)
#define SUBLANG_SANSKRIT_INDIA                      0x01    // Sanskrit (India) 0x044f sa-IN
#define SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_LATIN    0x06    // Serbian (Bosnia and Herzegovina - Latin)
#define SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_CYRILLIC 0x07    // Serbian (Bosnia and Herzegovina - Cyrillic)
#define SUBLANG_SERBIAN_CROATIA                     0x01    // Croatian (Croatia) 0x041a hr-HR
#define SUBLANG_SERBIAN_LATIN                       0x02    // Serbian (Latin)
#define SUBLANG_SERBIAN_CYRILLIC                    0x03    // Serbian (Cyrillic)
#define SUBLANG_SINDHI_INDIA                        0x01    // Sindhi (India) reserved 0x0459
#define SUBLANG_SINDHI_PAKISTAN                     0x02    // Sindhi (Pakistan) reserved 0x0859
#define SUBLANG_SINDHI_AFGHANISTAN                  0x02    // For app compatibility only
#define SUBLANG_SINHALESE_SRI_LANKA                 0x01    // Sinhalese (Sri Lanka)
#define SUBLANG_SOTHO_NORTHERN_SOUTH_AFRICA         0x01    // Northern Sotho (South Africa)
#define SUBLANG_SLOVAK_SLOVAKIA                     0x01    // Slovak (Slovakia) 0x041b sk-SK
#define SUBLANG_SLOVENIAN_SLOVENIA                  0x01    // Slovenian (Slovenia) 0x0424 sl-SI
#define SUBLANG_SPANISH                             0x01    // Spanish (Castilian)
#define SUBLANG_SPANISH_MEXICAN                     0x02    // Spanish (Mexican)
#define SUBLANG_SPANISH_MODERN                      0x03    // Spanish (Modern)
#define SUBLANG_SPANISH_GUATEMALA                   0x04    // Spanish (Guatemala)
#define SUBLANG_SPANISH_COSTA_RICA                  0x05    // Spanish (Costa Rica)
#define SUBLANG_SPANISH_PANAMA                      0x06    // Spanish (Panama)
#define SUBLANG_SPANISH_DOMINICAN_REPUBLIC          0x07    // Spanish (Dominican Republic)
#define SUBLANG_SPANISH_VENEZUELA                   0x08    // Spanish (Venezuela)
#define SUBLANG_SPANISH_COLOMBIA                    0x09    // Spanish (Colombia)
#define SUBLANG_SPANISH_PERU                        0x0a    // Spanish (Peru)
#define SUBLANG_SPANISH_ARGENTINA                   0x0b    // Spanish (Argentina)
#define SUBLANG_SPANISH_ECUADOR                     0x0c    // Spanish (Ecuador)
#define SUBLANG_SPANISH_CHILE                       0x0d    // Spanish (Chile)
#define SUBLANG_SPANISH_URUGUAY                     0x0e    // Spanish (Uruguay)
#define SUBLANG_SPANISH_PARAGUAY                    0x0f    // Spanish (Paraguay)
#define SUBLANG_SPANISH_BOLIVIA                     0x10    // Spanish (Bolivia)
#define SUBLANG_SPANISH_EL_SALVADOR                 0x11    // Spanish (El Salvador)
#define SUBLANG_SPANISH_HONDURAS                    0x12    // Spanish (Honduras)
#define SUBLANG_SPANISH_NICARAGUA                   0x13    // Spanish (Nicaragua)
#define SUBLANG_SPANISH_PUERTO_RICO                 0x14    // Spanish (Puerto Rico)
#define SUBLANG_SPANISH_US                          0x15    // Spanish (United States)
#define SUBLANG_SWAHILI_KENYA                       0x01    // Swahili (Kenya) 0x0441 sw-KE
#define SUBLANG_SWEDISH                             0x01    // Swedish
#define SUBLANG_SWEDISH_FINLAND                     0x02    // Swedish (Finland)
#define SUBLANG_SYRIAC_SYRIA                        0x01    // Syriac (Syria) 0x045a syr-SY
#define SUBLANG_TAJIK_TAJIKISTAN                    0x01    // Tajik (Tajikistan) 0x0428 tg-TJ-Cyrl
#define SUBLANG_TAMAZIGHT_ALGERIA_LATIN             0x02    // Tamazight (Latin, Algeria) 0x085f tmz-DZ-Latn
#define SUBLANG_TAMIL_INDIA                         0x01    // Tamil (India)
#define SUBLANG_TATAR_RUSSIA                        0x01    // Tatar (Russia) 0x0444 tt-RU
#define SUBLANG_TELUGU_INDIA                        0x01    // Telugu (India (Telugu Script)) 0x044a te-IN
#define SUBLANG_THAI_THAILAND                       0x01    // Thai (Thailand) 0x041e th-TH
#define SUBLANG_TIBETAN_PRC                         0x01    // Tibetan (PRC)
#define SUBLANG_TIGRIGNA_ERITREA                    0x02    // Tigrigna (Eritrea)
#define SUBLANG_TSWANA_SOUTH_AFRICA                 0x01    // Setswana / Tswana (South Africa) 0x0432 tn-ZA
#define SUBLANG_TURKISH_TURKEY                      0x01    // Turkish (Turkey) 0x041f tr-TR
#define SUBLANG_TURKMEN_TURKMENISTAN                0x01    // Turkmen (Turkmenistan) 0x0442 tk-TM
#define SUBLANG_UIGHUR_PRC                          0x01    // Uighur (PRC) 0x0480 ug-CN
#define SUBLANG_UKRAINIAN_UKRAINE                   0x01    // Ukrainian (Ukraine) 0x0422 uk-UA
#define SUBLANG_UPPER_SORBIAN_GERMANY               0x01    // Upper Sorbian (Germany) 0x042e wen-DE
#define SUBLANG_URDU_PAKISTAN                       0x01    // Urdu (Pakistan)
#define SUBLANG_URDU_INDIA                          0x02    // Urdu (India)
#define SUBLANG_UZBEK_LATIN                         0x01    // Uzbek (Latin)
#define SUBLANG_UZBEK_CYRILLIC                      0x02    // Uzbek (Cyrillic)
#define SUBLANG_VIETNAMESE_VIETNAM                  0x01    // Vietnamese (Vietnam) 0x042a vi-VN
#define SUBLANG_WELSH_UNITED_KINGDOM                0x01    // Welsh (United Kingdom) 0x0452 cy-GB
#define SUBLANG_WOLOF_SENEGAL                       0x01    // Wolof (Senegal)
#define SUBLANG_XHOSA_SOUTH_AFRICA                  0x01    // isiXhosa / Xhosa (South Africa) 0x0434 xh-ZA
#define SUBLANG_YAKUT_RUSSIA                        0x01    // Yakut (Russia) 0x0485 sah-RU
#define SUBLANG_YI_PRC                              0x01    // Yi (PRC)) 0x0478
#define SUBLANG_YORUBA_NIGERIA                      0x01    // Yoruba (Nigeria) 046a yo-NG
#define SUBLANG_ZULU_SOUTH_AFRICA                   0x01    // isiZulu / Zulu (South Africa) 0x0435 zu-ZA

#define SORT_DEFAULT  0x0
#define SORT_JAPANESE_XJIS  0x0
#define SORT_JAPANESE_UNICODE  0x1
#define SORT_CHINESE_BIG5  0x0
#define SORT_CHINESE_PRCP  0x0
#define SORT_CHINESE_UNICODE  0x1
#define SORT_CHINESE_PRC  0x2
#define SORT_CHINESE_BOPOMOFO  0x3
#define SORT_KOREAN_KSC  0x0
#define SORT_KOREAN_UNICODE  0x1
#define SORT_GERMAN_PHONE_BOOK  0x1
#define SORT_HUNGARIAN_DEFAULT  0x0
#define SORT_HUNGARIAN_TECHNICAL  0x1
#define SORT_GEORGIAN_TRADITIONAL  0x0
#define SORT_GEORGIAN_MODERN  0x1

#define LOCALE_CUSTOM_DEFAULT ((LANG_NEUTRAL | (SUBLANG_CUSTOM_DEFAULT<<10)) | (SORT_DEFAULT<<16))
#define LOCALE_CUSTOM_UNSPECIFIED ((LANG_NEUTRAL | (SUBLANG_CUSTOM_UNSPECIFIED<<10)) | (SORT_DEFAULT<<16))
#define LOCALE_CUSTOM_UI_DEFAULT ((LANG_NEUTRAL | (SUBLANG_UI_CUSTOM_DEFAULT<<10)) | (SORT_DEFAULT<<16))
#define LOCALE_NEUTRAL ((LANG_NEUTRAL | (SUBLANG_NEUTRAL<<10)) | (SORT_DEFAULT<<16))
#define LOCALE_INVARIANT ((LANG_INVARIANT | (SUBLANG_NEUTRAL<<10)) | (SORT_DEFAULT<<16))

#define STATUS_WAIT_0                    0x00000000
#define STATUS_ABANDONED_WAIT_0          0x00000080
#define STATUS_USER_APC                  0x000000C0
#define STATUS_TIMEOUT                   0x00000102
#define STATUS_PENDING                   0x00000103
#define DBG_EXCEPTION_HANDLED            0x00010001
#define DBG_CONTINUE                     0x00010002
#define STATUS_SEGMENT_NOTIFICATION      0x40000005
#define DBG_TERMINATE_THREAD             0x40010003
#define DBG_TERMINATE_PROCESS            0x40010004
#define DBG_CONTROL_C                    0x40010005
#define DBG_CONTROL_BREAK                0x40010008
#define DBG_COMMAND_EXCEPTION            0x40010009
#define STATUS_GUARD_PAGE_VIOLATION      0x80000001
#define STATUS_DATATYPE_MISALIGNMENT     0x80000002
#define STATUS_BREAKPOINT                0x80000003
#define STATUS_SINGLE_STEP               0x80000004
#define STATUS_LONGJUMP                  0x80000026
#define STATUS_UNWIND_CONSOLIDATE        0x80000029
#define DBG_EXCEPTION_NOT_HANDLED        0x80010001
#define STATUS_ACCESS_VIOLATION          0xC0000005
#define STATUS_IN_PAGE_ERROR             0xC0000006
#define STATUS_INVALID_HANDLE            0xC0000008
#define STATUS_INVALID_PARAMETER         0xC000000D
#define STATUS_NO_MEMORY                 0xC0000017
#define STATUS_ILLEGAL_INSTRUCTION       0xC000001D
#define STATUS_NONCONTINUABLE_EXCEPTION  0xC0000025
#define STATUS_INVALID_DISPOSITION       0xC0000026
#define STATUS_ARRAY_BOUNDS_EXCEEDED     0xC000008C
#define STATUS_FLOAT_DENORMAL_OPERAND    0xC000008D
#define STATUS_FLOAT_DIVIDE_BY_ZERO      0xC000008E
#define STATUS_FLOAT_INEXACT_RESULT      0xC000008F
#define STATUS_FLOAT_INVALID_OPERATION   0xC0000090
#define STATUS_FLOAT_OVERFLOW            0xC0000091
#define STATUS_FLOAT_STACK_CHECK         0xC0000092
#define STATUS_FLOAT_UNDERFLOW           0xC0000093
#define STATUS_INTEGER_DIVIDE_BY_ZERO    0xC0000094
#define STATUS_INTEGER_OVERFLOW          0xC0000095
#define STATUS_PRIVILEGED_INSTRUCTION    0xC0000096
#define STATUS_STACK_OVERFLOW            0xC00000FD
#define STATUS_CONTROL_C_EXIT            0xC000013A
#define STATUS_FLOAT_MULTIPLE_FAULTS     0xC00002B4
#define STATUS_FLOAT_MULTIPLE_TRAPS      0xC00002B5
#define STATUS_REG_NAT_CONSUMPTION       0xC00002C9
#define STATUS_STACK_BUFFER_OVERRUN      0xC0000409
#define STATUS_INVALID_CRUNTIME_PARAMETER 0xC0000417
#define STATUS_SXS_EARLY_DEACTIVATION    0xC015000F
#define STATUS_SXS_INVALID_DEACTIVATION  0xC0150010


#define MAXIMUM_WAIT_OBJECTS  64
#define MAXIMUM_SUSPEND_COUNT  MAXCHAR

#define EXCEPTION_NONCONTINUABLE  1
#define EXCEPTION_MAXIMUM_PARAMETERS  15

#define DELETE  0x00010000
#define READ_CONTROL  0x00020000
#define WRITE_DAC  0x00040000
#define WRITE_OWNER  0x00080000
#define SYNCHRONIZE  0x00100000

#define STANDARD_RIGHTS_REQUIRED  0x000F0000

#define STANDARD_RIGHTS_READ  READ_CONTROL
#define STANDARD_RIGHTS_WRITE  READ_CONTROL
#define STANDARD_RIGHTS_EXECUTE  READ_CONTROL
#define STANDARD_RIGHTS_ALL  0x001F0000

#define SPECIFIC_RIGHTS_ALL  0x0000FFFF

#define ACCESS_SYSTEM_SECURITY  0x01000000

#define MAXIMUM_ALLOWED  0x02000000

#define GENERIC_READ  0x80000000
#define GENERIC_WRITE  0x40000000
#define GENERIC_EXECUTE  0x20000000
#define GENERIC_ALL  0x10000000

#define SID_REVISION  1
#define SID_MAX_SUB_AUTHORITIES  15
#define SID_RECOMMENDED_SUB_AUTHORITIES  1

#define SECURITY_NULL_SID_AUTHORITY  <0,0,0,0,0,0>
#define SECURITY_WORLD_SID_AUTHORITY  <0,0,0,0,0,1>
#define SECURITY_LOCAL_SID_AUTHORITY  <0,0,0,0,0,2>
#define SECURITY_CREATOR_SID_AUTHORITY  <0,0,0,0,0,3>
#define SECURITY_NON_UNIQUE_AUTHORITY  <0,0,0,0,0,4>

#define SECURITY_NULL_RID  0x00000000
#define SECURITY_WORLD_RID  0x00000000
#define SECURITY_LOCAL_RID  0x00000000

#define SECURITY_CREATOR_OWNER_RID  0x00000000
#define SECURITY_CREATOR_GROUP_RID  0x00000001

#define SECURITY_CREATOR_OWNER_SERVER_RID  0x00000002
#define SECURITY_CREATOR_GROUP_SERVER_RID  0x00000003

#define SECURITY_NT_AUTHORITY  <0,0,0,0,0,5>

#define SECURITY_DIALUP_RID  0x00000001
#define SECURITY_NETWORK_RID  0x00000002
#define SECURITY_BATCH_RID  0x00000003
#define SECURITY_INTERACTIVE_RID  0x00000004
#define SECURITY_LOGON_IDS_RID  0x00000005
#define SECURITY_SERVICE_RID  0x00000006
#define SECURITY_ANONYMOUS_LOGON_RID  0x00000007
#define SECURITY_PROXY_RID  0x00000008
#define SECURITY_ENTERPRISE_CONTROLLERS_RID  0x00000009
#define SECURITY_SERVER_LOGON_RID  SECURITY_ENTERPRISE_CONTROLLERS_RID
#define SECURITY_PRINCIPAL_SELF_RID  0x0000000A
#define SECURITY_AUTHENTICATED_USER_RID  0x0000000B
#define SECURITY_RESTRICTED_CODE_RID  0x0000000C
#define SECURITY_TERMINAL_SERVER_RID  0x0000000D

#define SECURITY_REMOTE_LOGON_RID 0x0000000E
#define SECURITY_THIS_ORGANIZATION_RID 0x0000000F
#define SECURITY_IUSER_RID 0x00000011
#define SECURITY_LOCAL_SYSTEM_RID 0x00000012
#define SECURITY_LOCAL_SERVICE_RID 0x00000013
#define SECURITY_NETWORK_SERVICE_RID 0x00000014
#define SECURITY_NT_NON_UNIQUE  0x00000015

#define SECURITY_PACKAGE_NTLM_RID 0x0000000A
#define SECURITY_PACKAGE_SCHANNEL_RID 0x0000000E
#define SECURITY_PACKAGE_DIGEST_RID 0x00000015

#define SECURITY_BUILTIN_DOMAIN_RID 0x00000020
#define SECURITY_WRITE_RESTRICTED_CODE_RID 0x00000021
#define SECURITY_PACKAGE_BASE_RID 0x00000040

#define SECURITY_LOGON_IDS_RID_COUNT  3
#define SECURITY_PACKAGE_RID_COUNT 2
#define SECURITY_NT_NON_UNIQUE_SUB_AUTH_COUNT 3
#define SECURITY_SERVICE_ID_RID_COUNT 6
#define SECURITY_APPPOOL_ID_RID_COUNT 6
#define SECURITY_VIRTUALSERVER_ID_RID_COUNT 6
#define SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID 0x00000016

#define SECURITY_MIN_BASE_RID 0x00000050
#define SECURITY_SERVICE_ID_BASE_RID 0x00000050
#define SECURITY_RESERVED_ID_BASE_RID 0x00000051
#define SECURITY_APPPOOL_ID_BASE_RID 0x00000052
#define SECURITY_VIRTUALSERVER_ID_BASE_RID 0x00000053
#define SECURITY_MAX_BASE_RID 0x0000006F

#define SECURITY_MAX_ALWAYS_FILTERED 0x000003E7
#define SECURITY_MIN_NEVER_FILTERED 0x000003E8

#define SECURITY_OTHER_ORGANIZATION_RID 0x000003E8

#define SECURITY_BUILTIN_DOMAIN_RID  0x00000020

#define DOMAIN_USER_RID_ADMIN  0x000001F4
#define DOMAIN_USER_RID_GUEST  0x000001F5
#define DOMAIN_USER_RID_KRBTGT  0x000001F6

#define DOMAIN_GROUP_RID_ADMINS  0x00000200
#define DOMAIN_GROUP_RID_USERS  0x00000201
#define DOMAIN_GROUP_RID_GUESTS  0x00000202
#define DOMAIN_GROUP_RID_COMPUTERS  0x00000203
#define DOMAIN_GROUP_RID_CONTROLLERS  0x00000204
#define DOMAIN_GROUP_RID_CERT_ADMINS  0x00000205
#define DOMAIN_GROUP_RID_SCHEMA_ADMINS  0x00000206
#define DOMAIN_GROUP_RID_ENTERPRISE_ADMINS  0x00000207
#define DOMAIN_GROUP_RID_POLICY_ADMINS  0x00000208

#define DOMAIN_ALIAS_RID_ADMINS  0x00000220
#define DOMAIN_ALIAS_RID_USERS  0x00000221
#define DOMAIN_ALIAS_RID_GUESTS  0x00000222
#define DOMAIN_ALIAS_RID_POWER_USERS  0x00000223

#define DOMAIN_ALIAS_RID_ACCOUNT_OPS  0x00000224
#define DOMAIN_ALIAS_RID_SYSTEM_OPS  0x00000225
#define DOMAIN_ALIAS_RID_PRINT_OPS  0x00000226
#define DOMAIN_ALIAS_RID_BACKUP_OPS  0x00000227

#define DOMAIN_ALIAS_RID_REPLICATOR  0x00000228
#define DOMAIN_ALIAS_RID_RAS_SERVERS  0x00000229
#define DOMAIN_ALIAS_RID_PREW2KCOMPACCESS  0x0000022A
#define DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS 0x0000022B
#define DOMAIN_ALIAS_RID_NETWORK_CONFIGURATION_OPS 0x0000022C
#define DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS 0x0000022D

#define DOMAIN_ALIAS_RID_MONITORING_USERS 0x0000022E
#define DOMAIN_ALIAS_RID_LOGGING_USERS 0x0000022F
#define DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS 0x00000230
#define DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS 0x00000231
#define DOMAIN_ALIAS_RID_DCOM_USERS 0x00000232
#define DOMAIN_ALIAS_RID_IUSERS 0x00000238
#define DOMAIN_ALIAS_RID_CRYPTO_OPERATORS 0x00000239
#define DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_GROUP 0x0000023B
#define DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_GROUP 0x0000023C
#define DOMAIN_ALIAS_RID_EVENT_LOG_READERS_GROUP 0x0000023D
#define DOMAIN_ALIAS_RID_CERTSVC_DCOM_ACCESS_GROUP 0x0000023E

#define SECURITY_MANDATORY_LABEL_AUTHORITY <0,0,0,0,0,16>
#define SECURITY_MANDATORY_UNTRUSTED_RID 0x00000000
#define SECURITY_MANDATORY_LOW_RID 0x00001000
#define SECURITY_MANDATORY_MEDIUM_RID 0x00002000
#define SECURITY_MANDATORY_HIGH_RID 0x00003000
#define SECURITY_MANDATORY_SYSTEM_RID 0x00004000
#define SECURITY_MANDATORY_PROTECTED_PROCESS_RID 0x00005000

#define SECURITY_MANDATORY_MAXIMUM_USER_RID   SECURITY_MANDATORY_SYSTEM_RID

#IFNDEF WinBuiltinCertSvcDComAccessGroup
WinNullSid                                  = 0
WinWorldSid                                 = 1
WinLocalSid                                 = 2
WinCreatorOwnerSid                          = 3
WinCreatorGroupSid                          = 4
WinCreatorOwnerServerSid                    = 5
WinCreatorGroupServerSid                    = 6
WinNtAuthoritySid                           = 7
WinDialupSid                                = 8
WinNetworkSid                               = 9
WinBatchSid                                 = 10
WinInteractiveSid                           = 11
WinServiceSid                               = 12
WinAnonymousSid                             = 13
WinProxySid                                 = 14
WinEnterpriseControllersSid                 = 15
WinSelfSid                                  = 16
WinAuthenticatedUserSid                     = 17
WinRestrictedCodeSid                        = 18
WinTerminalServerSid                        = 19
WinRemoteLogonIdSid                         = 20
WinLogonIdsSid                              = 21
WinLocalSystemSid                           = 22
WinLocalServiceSid                          = 23
WinNetworkServiceSid                        = 24
WinBuiltinDomainSid                         = 25
WinBuiltinAdministratorsSid                 = 26
WinBuiltinUsersSid                          = 27
WinBuiltinGuestsSid                         = 28
WinBuiltinPowerUsersSid                     = 29
WinBuiltinAccountOperatorsSid               = 30
WinBuiltinSystemOperatorsSid                = 31
WinBuiltinPrintOperatorsSid                 = 32
WinBuiltinBackupOperatorsSid                = 33
WinBuiltinReplicatorSid                     = 34
WinBuiltinPreWindows2000CompatibleAccessSid = 35
WinBuiltinRemoteDesktopUsersSid             = 36
WinBuiltinNetworkConfigurationOperatorsSid  = 37
WinAccountAdministratorSid                  = 38
WinAccountGuestSid                          = 39
WinAccountKrbtgtSid                         = 40
WinAccountDomainAdminsSid                   = 41
WinAccountDomainUsersSid                    = 42
WinAccountDomainGuestsSid                   = 43
WinAccountComputersSid                      = 44
WinAccountControllersSid                    = 45
WinAccountCertAdminsSid                     = 46
WinAccountSchemaAdminsSid                   = 47
WinAccountEnterpriseAdminsSid               = 48
WinAccountPolicyAdminsSid                   = 49
WinAccountRasAndIasServersSid               = 50
WinNTLMAuthenticationSid                    = 51
WinDigestAuthenticationSid                  = 52
WinSChannelAuthenticationSid                = 53
WinThisOrganizationSid                      = 54
WinOtherOrganizationSid                     = 55
WinBuiltinIncomingForestTrustBuildersSid    = 56
WinBuiltinPerfMonitoringUsersSid            = 57
WinBuiltinPerfLoggingUsersSid               = 58
WinBuiltinAuthorizationAccessSid            = 59
WinBuiltinTerminalServerLicenseServersSid   = 60
WinBuiltinDCOMUsersSid                      = 61
WinBuiltinIUsersSid                         = 62
WinIUserSid                                 = 63
WinBuiltinCryptoOperatorsSid                = 64
WinUntrustedLabelSid                        = 65
WinLowLabelSid                              = 66
WinMediumLabelSid                           = 67
WinHighLabelSid                             = 68
WinSystemLabelSid                           = 69
WinWriteRestrictedCodeSid                   = 70
WinCreatorOwnerRightsSid                    = 71
WinCacheablePrincipalsGroupSid              = 72
WinNonCacheablePrincipalsGroupSid           = 73
WinEnterpriseReadonlyControllersSid         = 74
WinAccountReadonlyControllersSid            = 75
WinBuiltinEventLogReadersGroup              = 76
WinNewEnterpriseReadonlyControllersSid      = 77
WinBuiltinCertSvcDComAccessGroup 		    = 78
WinMediumPlusLabelSid                       = 79
WinLocalLogonSid                            = 80
WinConsoleLogonSid							= 81
WinThisOrganizationCertificateSid			= 82
#ENDIF

#define SYSTEM_LUID <0x3e7, 0x0>
#define ANONYMOUS_LOGON_LUID <0x3e6, 0x0>
#define LOCALSERVICE_LUID <0x3e5, 0x0>
#define NETWORKSERVICE_LUID <0x3e4, 0x0>
#define IUSER_LUID <0x3e3, 0x0>

#define SE_GROUP_MANDATORY  0x00000001
#define SE_GROUP_ENABLED_BY_DEFAULT  0x00000002
#define SE_GROUP_ENABLED  0x00000004
#define SE_GROUP_OWNER  0x00000008
#define SE_GROUP_USE_FOR_DENY_ONLY  0x00000010
#define SE_GROUP_LOGON_ID  0xC0000000
#define SE_GROUP_RESOURCE  0x20000000

#define SE_GROUP_VALID_ATTRIBUTES          (SE_GROUP_MANDATORY|SE_GROUP_ENABLED_BY_DEFAULT|SE_GROUP_ENABLED|SE_GROUP_OWNER| \
                                            SE_GROUP_USE_FOR_DENY_ONLY|SE_GROUP_LOGON_ID|SE_GROUP_RESOURCE|SE_GROUP_INTEGRITY|SE_GROUP_INTEGRITY_ENABLED)

#define ACL_REVISION  2
#define ACL_REVISION_DS  4
#define ACL_REVISION1  1
#define MIN_ACL_REVISION ACL_REVISION2
#define ACL_REVISION2  2
#define ACL_REVISION3  3
#define ACL_REVISION4  4
#define MAX_ACL_REVISION ACL_REVISION4

#define ACCESS_MIN_MS_ACE_TYPE  0x0
#define ACCESS_ALLOWED_ACE_TYPE  0x0
#define ACCESS_DENIED_ACE_TYPE  0x1
#define SYSTEM_AUDIT_ACE_TYPE  0x2
#define SYSTEM_ALARM_ACE_TYPE  0x3
#define ACCESS_MAX_MS_V2_ACE_TYPE  0x3

#define ACCESS_ALLOWED_COMPOUND_ACE_TYPE  0x4
#define ACCESS_MAX_MS_V3_ACE_TYPE  0x4

#define ACCESS_MIN_MS_OBJECT_ACE_TYPE  0x5
#define ACCESS_ALLOWED_OBJECT_ACE_TYPE  0x5
#define ACCESS_DENIED_OBJECT_ACE_TYPE  0x6
#define SYSTEM_AUDIT_OBJECT_ACE_TYPE  0x7
#define SYSTEM_ALARM_OBJECT_ACE_TYPE  0x8
#define ACCESS_MAX_MS_OBJECT_ACE_TYPE  0x8

#define ACCESS_MAX_MS_V4_ACE_TYPE  0x8
#define ACCESS_MAX_MS_ACE_TYPE  0x8

#define ACCESS_ALLOWED_CALLBACK_ACE_TYPE 0x9
#define ACCESS_DENIED_CALLBACK_ACE_TYPE 0xA
#define ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE 0xB
#define ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE 0xC
#define SYSTEM_AUDIT_CALLBACK_ACE_TYPE 0xD
#define SYSTEM_ALARM_CALLBACK_ACE_TYPE 0xE
#define SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE 0xF
#define SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE 0x10

#define SYSTEM_MANDATORY_LABEL_ACE_TYPE 0x11
#define ACCESS_MAX_MS_V5_ACE_TYPE 0x11

#define SYSTEM_MANDATORY_LABEL_NO_WRITE_UP         0x1
#define SYSTEM_MANDATORY_LABEL_NO_READ_UP          0x2
#define SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP       0x4

#define SYSTEM_MANDATORY_LABEL_VALID_MASK (SYSTEM_MANDATORY_LABEL_NO_WRITE_UP|SYSTEM_MANDATORY_LABEL_NO_READ_UP|SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP)

#define OBJECT_INHERIT_ACE  0x1
#define CONTAINER_INHERIT_ACE  0x2
#define NO_PROPAGATE_INHERIT_ACE  0x4
#define INHERIT_ONLY_ACE  0x8
#define INHERITED_ACE  0x10
#define VALID_INHERIT_FLAGS  0x1F

#define SUCCESSFUL_ACCESS_ACE_FLAG  0x40
#define FAILED_ACCESS_ACE_FLAG  0x80

#define ACE_OBJECT_TYPE_PRESENT  0x1
#define ACE_INHERITED_OBJECT_TYPE_PRESENT  0x2

#define SECURITY_DESCRIPTOR_REVISION  1
#define SECURITY_DESCRIPTOR_REVISION1  1

#define SECURITY_DESCRIPTOR_MIN_LENGTH  sizeof SECURITY_DESCRIPTOR

#define SE_OWNER_DEFAULTED  0x0001
#define SE_GROUP_DEFAULTED  0x0002
#define SE_DACL_PRESENT  0x0004
#define SE_DACL_DEFAULTED  0x0008
#define SE_SACL_PRESENT  0x0010
#define SE_SACL_DEFAULTED  0x0020
#define SE_DACL_AUTO_INHERIT_REQ  0x0100
#define SE_SACL_AUTO_INHERIT_REQ  0x0200
#define SE_DACL_AUTO_INHERITED  0x0400
#define SE_SACL_AUTO_INHERITED  0x0800
#define SE_DACL_PROTECTED  0x1000
#define SE_SACL_PROTECTED  0x2000
#define SE_RM_CONTROL_VALID  0x4000
#define SE_SELF_RELATIVE  0x8000

#define ACCESS_OBJECT_GUID  0
#define ACCESS_PROPERTY_SET_GUID 1
#define ACCESS_PROPERTY_GUID  2

#define ACCESS_MAX_LEVEL  4

#define AUDIT_ALLOW_NO_PRIVILEGE  0x1

#define ACCESS_DS_SOURCE_A  A"DS"
#define ACCESS_DS_SOURCE_W  L"DS"
#define ACCESS_DS_OBJECT_TYPE_NAME_A  A"Directory Service Object"
#define ACCESS_DS_OBJECT_TYPE_NAME_W  L"Directory Service Object"

#define SE_PRIVILEGE_ENABLED_BY_DEFAULT 0x00000001
#define SE_PRIVILEGE_ENABLED 0x00000002
#define SE_PRIVILEGE_REMOVED 0X00000004
#define SE_PRIVILEGE_USED_FOR_ACCESS 0x80000000

#define SE_PRIVILEGE_VALID_ATTRIBUTES   (SE_PRIVILEGE_ENABLED_BY_DEFAULT|SE_PRIVILEGE_ENABLED|SE_PRIVILEGE_REMOVED|SE_PRIVILEGE_USED_FOR_ACCESS)

#define PRIVILEGE_SET_ALL_NECESSARY  1

#define SE_CREATE_TOKEN_NAME  "SeCreateTokenPrivilege"
#define SE_ASSIGNPRIMARYTOKEN_NAME  "SeAssignPrimaryTokenPrivilege"
#define SE_LOCK_MEMORY_NAME  "SeLockMemoryPrivilege"
#define SE_INCREASE_QUOTA_NAME  "SeIncreaseQuotaPrivilege"
#define SE_UNSOLICITED_INPUT_NAME  "SeUnsolicitedInputPrivilege"
#define SE_MACHINE_ACCOUNT_NAME  "SeMachineAccountPrivilege"
#define SE_TCB_NAME  "SeTcbPrivilege"
#define SE_SECURITY_NAME  "SeSecurityPrivilege"
#define SE_TAKE_OWNERSHIP_NAME  "SeTakeOwnershipPrivilege"
#define SE_LOAD_DRIVER_NAME  "SeLoadDriverPrivilege"
#define SE_SYSTEM_PROFILE_NAME  "SeSystemProfilePrivilege"
#define SE_SYSTEMTIME_NAME  "SeSystemtimePrivilege"
#define SE_PROF_SINGLE_PROCESS_NAME  "SeProfileSingleProcessPrivilege"
#define SE_INC_BASE_PRIORITY_NAME  "SeIncreaseBasePriorityPrivilege"
#define SE_CREATE_PAGEFILE_NAME  "SeCreatePagefilePrivilege"
#define SE_CREATE_PERMANENT_NAME  "SeCreatePermanentPrivilege"
#define SE_BACKUP_NAME  "SeBackupPrivilege"
#define SE_RESTORE_NAME  "SeRestorePrivilege"
#define SE_SHUTDOWN_NAME  "SeShutdownPrivilege"
#define SE_DEBUG_NAME  "SeDebugPrivilege"
#define SE_AUDIT_NAME  "SeAuditPrivilege"
#define SE_SYSTEM_ENVIRONMENT_NAME  "SeSystemEnvironmentPrivilege"
#define SE_CHANGE_NOTIFY_NAME  "SeChangeNotifyPrivilege"
#define SE_REMOTE_SHUTDOWN_NAME  "SeRemoteShutdownPrivilege"
#define SE_UNDOCK_NAME  "SeUndockPrivilege"
#define SE_SYNC_AGENT_NAME  "SeSyncAgentPrivilege"
#define SE_ENABLE_DELEGATION_NAME  "SeEnableDelegationPrivilege"
#define SE_MANAGE_VOLUME_NAME "SeManageVolumePrivilege"
#define SE_IMPERSONATE_NAME "SeImpersonatePrivilege"
#define SE_CREATE_GLOBAL_NAME "SeCreateGlobalPrivilege"
#define SE_TRUSTED_CREDMAN_ACCESS_NAME "SeTrustedCredManAccessPrivilege"
#define SE_RELABEL_NAME "SeRelabelPrivilege"
#define SE_INC_WORKING_SET_NAME "SeIncreaseWorkingSetPrivilege"
#define SE_TIME_ZONE_NAME "SeTimeZonePrivilege"
#define SE_CREATE_SYMBOLIC_LINK_NAME "SeCreateSymbolicLinkPrivilege"

#define SECURITY_MAX_IMPERSONATION_LEVEL  SecurityDelegation
#define DEFAULT_IMPERSONATION_LEVEL  SecurityImpersonation

#define TOKEN_ASSIGN_PRIMARY  0x0001
#define TOKEN_DUPLICATE  0x0002
#define TOKEN_IMPERSONATE  0x0004
#define TOKEN_QUERY  0x0008
#define TOKEN_QUERY_SOURCE  0x0010
#define TOKEN_ADJUST_PRIVILEGES 0x0020
#define TOKEN_ADJUST_GROUPS  0x0040
#define TOKEN_ADJUST_DEFAULT  0x0080
#define TOKEN_ADJUST_SESSIONID  0x0100

#define TOKEN_ALL_ACCESS_P (STANDARD_RIGHTS_REQUIRED|TOKEN_ASSIGN_PRIMARY|TOKEN_DUPLICATE|TOKEN_IMPERSONATE|TOKEN_QUERY|TOKEN_QUERY_SOURCE|TOKEN_ADJUST_PRIVILEGES|TOKEN_ADJUST_GROUPS|TOKEN_ADJUST_DEFAULT)

#define TOKEN_ALL_ACCESS  (TOKEN_ALL_ACCESS_P|TOKEN_ADJUST_SESSIONID)

#define TOKEN_READ  (STANDARD_RIGHTS_READ|TOKEN_QUERY)
#define TOKEN_WRITE  (STANDARD_RIGHTS_WRITE|TOKEN_ADJUST_PRIVILEGES|TOKEN_ADJUST_GROUPS|TOKEN_ADJUST_DEFAULT)
#define TOKEN_EXECUTE  (STANDARD_RIGHTS_EXECUTE)

#define POLICY_AUDIT_SUBCATEGORY_COUNT 52
#define TOKEN_SOURCE_LENGTH 8

#define TOKEN_MANDATORY_POLICY_OFF             0x0
#define TOKEN_MANDATORY_POLICY_NO_WRITE_UP     0x1
#define TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN 0x2

#define TOKEN_MANDATORY_POLICY_VALID_MASK TOKEN_MANDATORY_POLICY_NO_WRITE_UP|TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN)

#define SECURITY_DYNAMIC_TRACKING  TRUE
#define SECURITY_STATIC_TRACKING  FALSE

#define DISABLE_MAX_PRIVILEGE  0x1
#define SANDBOX_INERT 0x2 
#define LUA_TOKEN 0x4 
#define WRITE_RESTRICTED 0x8 
#define LABEL_SECURITY_INFORMATION 0x10

#define OWNER_SECURITY_INFORMATION  0x00000001
#define GROUP_SECURITY_INFORMATION  0x00000002
#define DACL_SECURITY_INFORMATION  0x00000004
#define SACL_SECURITY_INFORMATION  0x00000008

#define PROTECTED_DACL_SECURITY_INFORMATION  0x80000000
#define PROTECTED_SACL_SECURITY_INFORMATION  0x40000000
#define UNPROTECTED_DACL_SECURITY_INFORMATION  0x20000000
#define UNPROTECTED_SACL_SECURITY_INFORMATION  0x10000000

#define PROCESS_TERMINATE  0x0001
#define PROCESS_CREATE_THREAD  0x0002
#define PROCESS_SET_SESSIONID  0x0004
#define PROCESS_VM_OPERATION  0x0008
#define PROCESS_VM_READ  0x0010
#define PROCESS_VM_WRITE  0x0020
#define PROCESS_DUP_HANDLE  0x0040
#define PROCESS_CREATE_PROCESS  0x0080
#define PROCESS_SET_QUOTA  0x0100
#define PROCESS_SET_INFORMATION  0x0200
#define PROCESS_QUERY_INFORMATION 0x0400
#define PROCESS_SUSPEND_RESUME 0x0800  
#define PROCESS_QUERY_LIMITED_INFORMATION 0x1000

#IF WINVER < NTDDI_VISTA
#define PROCESS_ALL_ACCESS  (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0xFFF)
#ELSE
#define PROCESS_ALL_ACCESS  (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0xFFFF)
#ENDIF

#IF X64
#define MAXIMUM_PROCESSORS 64
#ELSE
#define MAXIMUM_PROCESSORS 32
#ENDIF

#define THREAD_TERMINATE  0x0001
#define THREAD_SUSPEND_RESUME  0x0002
#define THREAD_GET_CONTEXT  0x0008
#define THREAD_SET_CONTEXT  0x0010
#define THREAD_SET_INFORMATION  0x0020
#define THREAD_QUERY_INFORMATION  0x0040
#define THREAD_SET_THREAD_TOKEN  0x0080
#define THREAD_IMPERSONATE  0x0100
#define THREAD_DIRECT_IMPERSONATION  0x0200
#define THREAD_SET_LIMITED_INFORMATION 0x0400  // winnt
#define THREAD_QUERY_LIMITED_INFORMATION 0x0800  // winnt

#IF WINVER < NTDDI_VISTA
#define THREAD_ALL_ACCESS  (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3FF)
#ELSE
#define THREAD_ALL_ACCESS  (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0xFFFF)
#ENDIF

#define JOB_OBJECT_ASSIGN_PROCESS  0x0001
#define JOB_OBJECT_SET_ATTRIBUTES  0x0002
#define JOB_OBJECT_QUERY  0x0004
#define JOB_OBJECT_TERMINATE  0x0008
#define JOB_OBJECT_SET_SECURITY_ATTRIBUTES  0x0010
#define JOB_OBJECT_ALL_ACCESS  (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x1F)

#define TLS_MINIMUM_AVAILABLE  64

#define THREAD_BASE_PRIORITY_LOWRT  15
#define THREAD_BASE_PRIORITY_MAX  2
#define THREAD_BASE_PRIORITY_MIN  -2
#define THREAD_BASE_PRIORITY_IDLE  -15

#define JOB_OBJECT_TERMINATE_AT_END_OF_JOB  0
#define JOB_OBJECT_POST_AT_END_OF_JOB  1

#define JOB_OBJECT_MSG_END_OF_JOB_TIME  1
#define JOB_OBJECT_MSG_END_OF_PROCESS_TIME  2
#define JOB_OBJECT_MSG_ACTIVE_PROCESS_LIMIT  3
#define JOB_OBJECT_MSG_ACTIVE_PROCESS_ZERO  4
#define JOB_OBJECT_MSG_NEW_PROCESS  6
#define JOB_OBJECT_MSG_EXIT_PROCESS  7
#define JOB_OBJECT_MSG_ABNORMAL_EXIT_PROCESS  8
#define JOB_OBJECT_MSG_PROCESS_MEMORY_LIMIT  9
#define JOB_OBJECT_MSG_JOB_MEMORY_LIMIT  10

#define JOB_OBJECT_LIMIT_WORKINGSET  0x00000001
#define JOB_OBJECT_LIMIT_PROCESS_TIME  0x00000002
#define JOB_OBJECT_LIMIT_JOB_TIME  0x00000004
#define JOB_OBJECT_LIMIT_ACTIVE_PROCESS  0x00000008
#define JOB_OBJECT_LIMIT_AFFINITY  0x00000010
#define JOB_OBJECT_LIMIT_PRIORITY_CLASS  0x00000020
#define JOB_OBJECT_LIMIT_PRESERVE_JOB_TIME  0x00000040
#define JOB_OBJECT_LIMIT_SCHEDULING_CLASS  0x00000080
#define JOB_OBJECT_LIMIT_PROCESS_MEMORY  0x00000100
#define JOB_OBJECT_LIMIT_JOB_MEMORY  0x00000200
#define JOB_OBJECT_LIMIT_DIE_ON_UNHANDLED_EXCEPTION 0x00000400
#define JOB_OBJECT_LIMIT_BREAKAWAY_OK  0x00000800
#define JOB_OBJECT_LIMIT_SILENT_BREAKAWAY_OK  0x00001000
#define JOB_OBJECT_LIMIT_RESERVED1  0x00002000
#define JOB_OBJECT_LIMIT_RESERVED2  0x00004000
#define JOB_OBJECT_LIMIT_RESERVED3  0x00008000
#define JOB_OBJECT_LIMIT_RESERVED4  0x00010000
#define JOB_OBJECT_LIMIT_RESERVED5  0x00020000
#define JOB_OBJECT_LIMIT_RESERVED6  0x00040000

#define JOB_OBJECT_LIMIT_VALID_FLAGS  0x0007FFFF

#define JOB_OBJECT_BASIC_LIMIT_VALID_FLAGS  0x000000FF
#define JOB_OBJECT_EXTENDED_LIMIT_VALID_FLAGS  0x00001FFF
#define JOB_OBJECT_RESERVED_LIMIT_VALID_FLAGS  0x0007FFFF

#define JOB_OBJECT_UILIMIT_NONE  0x00000000
#define JOB_OBJECT_UILIMIT_HANDLES  0x00000001
#define JOB_OBJECT_UILIMIT_READCLIPBOARD  0x00000002
#define JOB_OBJECT_UILIMIT_WRITECLIPBOARD  0x00000004
#define JOB_OBJECT_UILIMIT_SYSTEMPARAMETERS 0x00000008
#define JOB_OBJECT_UILIMIT_DISPLAYSETTINGS  0x00000010
#define JOB_OBJECT_UILIMIT_GLOBALATOMS  0x00000020
#define JOB_OBJECT_UILIMIT_DESKTOP  0x00000040
#define JOB_OBJECT_UILIMIT_EXITWINDOWS  0x00000080
#define JOB_OBJECT_UILIMIT_ALL  0x000000FF

#define JOB_OBJECT_UI_VALID_FLAGS  0x000000FF

#define JOB_OBJECT_SECURITY_NO_ADMIN  0x00000001
#define JOB_OBJECT_SECURITY_RESTRICTED_TOKEN  0x00000002
#define JOB_OBJECT_SECURITY_ONLY_TOKEN  0x00000004
#define JOB_OBJECT_SECURITY_FILTER_TOKENS  0x00000008
#define JOB_OBJECT_SECURITY_VALID_FLAGS  0x0000000F

#define EVENT_MODIFY_STATE  0x0002
#define EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#define MUTANT_QUERY_STATE  0x0001
#define MUTANT_ALL_ACCESS  (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|MUTANT_QUERY_STATE)
#define SEMAPHORE_MODIFY_STATE  0x0002
#define SEMAPHORE_ALL_ACCESS  (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#define TIMER_QUERY_STATE  0x0001
#define TIMER_MODIFY_STATE  0x0002
#define TIMER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|TIMER_QUERY_STATE|TIMER_MODIFY_STATE)

#define TIME_ZONE_ID_UNKNOWN  0
#define TIME_ZONE_ID_STANDARD 1
#define TIME_ZONE_ID_DAYLIGHT 2

#define PROCESSOR_INTEL_386  386
#define PROCESSOR_INTEL_486  486
#define PROCESSOR_INTEL_PENTIUM 586
#define PROCESSOR_INTEL_IA64  2200
#define PROCESSOR_MIPS_R4000  4000
#define PROCESSOR_ALPHA_21064  21064
#define PROCESSOR_PPC_601  601
#define PROCESSOR_PPC_603  603
#define PROCESSOR_PPC_604  604
#define PROCESSOR_PPC_620  620
#define PROCESSOR_HITACHI_SH3  10003
#define PROCESSOR_HITACHI_SH3E  10004
#define PROCESSOR_HITACHI_SH4  10005
#define PROCESSOR_MOTOROLA_821  821
#define PROCESSOR_SHx_SH3  103
#define PROCESSOR_SHx_SH4  104
#define PROCESSOR_STRONGARM  2577
#define PROCESSOR_ARM720  1824
#define PROCESSOR_ARM820  2080
#define PROCESSOR_ARM920  2336
#define PROCESSOR_ARM_7TDMI  70001
#define PROCESSOR_OPTIL  0x494F

#define PROCESSOR_ARCHITECTURE_INTEL  0
#define PROCESSOR_ARCHITECTURE_MIPS  1
#define PROCESSOR_ARCHITECTURE_ALPHA  2
#define PROCESSOR_ARCHITECTURE_PPC  3
#define PROCESSOR_ARCHITECTURE_SHX  4
#define PROCESSOR_ARCHITECTURE_ARM  5
#define PROCESSOR_ARCHITECTURE_IA64  6
#define PROCESSOR_ARCHITECTURE_ALPHA64  7
#define PROCESSOR_ARCHITECTURE_MSIL  8
#define PROCESSOR_ARCHITECTURE_AMD64            9
#define PROCESSOR_ARCHITECTURE_IA32_ON_WIN64    10

#define PROCESSOR_ARCHITECTURE_UNKNOWN 0xFFFF

#define PF_FLOATING_POINT_PRECISION_ERRATA  0
#define PF_FLOATING_POINT_EMULATED  1
#define PF_COMPARE_EXCHANGE_DOUBLE  2
#define PF_MMX_INSTRUCTIONS_AVAILABLE  3
#define PF_PPC_MOVEMEM_64BIT_OK  4
#define PF_ALPHA_BYTE_INSTRUCTIONS  5
#define PF_XMMI_INSTRUCTIONS_AVAILABLE  6
#define PF_3DNOW_INSTRUCTIONS_AVAILABLE  7
#define PF_RDTSC_INSTRUCTION_AVAILABLE  8
#define PF_PAE_ENABLED  9
#define PF_XMMI64_INSTRUCTIONS_AVAILABLE   10   
#define PF_SSE_DAZ_MODE_AVAILABLE          11   
#define PF_NX_ENABLED                      12   
#define PF_SSE3_INSTRUCTIONS_AVAILABLE     13   
#define PF_COMPARE_EXCHANGE128             14   
#define PF_COMPARE64_EXCHANGE128           15   
#define PF_CHANNELS_ENABLED                16 

#define SECTION_QUERY  0x0001
#define SECTION_MAP_WRITE  0x0002
#define SECTION_MAP_READ  0x0004
#define SECTION_MAP_EXECUTE 0x0008
#define SECTION_EXTEND_SIZE 0x0010
#define SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY|SECTION_MAP_WRITE|SECTION_MAP_READ|SECTION_MAP_EXECUTE|SECTION_EXTEND_SIZE)

#define SESSION_QUERY_ACCESS  0x0001
#define SESSION_MODIFY_ACCESS 0x0002

#define SESSION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SESSION_QUERY_ACCESS|SESSION_MODIFY_ACCESS)

#define PAGE_NOACCESS  0x01
#define PAGE_READONLY  0x02
#define PAGE_READWRITE  0x04
#define PAGE_WRITECOPY  0x08
#define PAGE_EXECUTE  0x10
#define PAGE_EXECUTE_READ  0x20

#define PAGE_EXECUTE_READWRITE 0x40
#define PAGE_EXECUTE_WRITECOPY 0x80
#define PAGE_GUARD  0x100
#define PAGE_NOCACHE  0x200
#define PAGE_WRITECOMBINE  0x400
#define MEM_COMMIT  0x1000
#define MEM_RESERVE  0x2000
#define MEM_DECOMMIT  0x4000
#define MEM_RELEASE  0x8000
#define MEM_FREE  0x10000
#define MEM_PRIVATE  0x20000
#define MEM_MAPPED  0x40000
#define MEM_RESET  0x80000
#define MEM_TOP_DOWN  0x100000
#define MEM_WRITE_WATCH  0x200000
#define MEM_PHYSICAL  0x400000
#define MEM_4MB_PAGES  0x80000000
#define SEC_FILE  0x800000
#define SEC_IMAGE  0x1000000
#define SEC_RESERVE  0x4000000
#define SEC_COMMIT  0x8000000
#define SEC_NOCACHE  0x10000000
#define MEM_IMAGE  SEC_IMAGE
#define WRITE_WATCH_FLAG_RESET 0x01

#define FILE_READ_DATA  0x0001
#define FILE_LIST_DIRECTORY  0x0001

#define FILE_WRITE_DATA  0x0002
#define FILE_ADD_FILE  0x0002

#define FILE_APPEND_DATA  0x0004
#define FILE_ADD_SUBDIRECTORY  0x0004
#define FILE_CREATE_PIPE_INSTANCE  0x0004
#define FILE_READ_EA  0x0008
#define FILE_WRITE_EA  0x0010
#define FILE_EXECUTE  0x0020
#define FILE_TRAVERSE  0x0020
#define FILE_DELETE_CHILD  0x0040
#define FILE_READ_ATTRIBUTES  0x0080
#define FILE_WRITE_ATTRIBUTES  0x0100


#define FILE_ALL_ACCESS  (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x1FF)
#define FILE_GENERIC_READ  (STANDARD_RIGHTS_READ|FILE_READ_DATA|FILE_READ_ATTRIBUTES|FILE_READ_EA|SYNCHRONIZE)
#define FILE_GENERIC_WRITE  (STANDARD_RIGHTS_WRITE|FILE_WRITE_DATA|FILE_WRITE_ATTRIBUTES|FILE_WRITE_EA|FILE_APPEND_DATA|SYNCHRONIZE)
#define FILE_GENERIC_EXECUTE  (STANDARD_RIGHTS_EXECUTE|FILE_READ_ATTRIBUTES|FILE_EXECUTE|SYNCHRONIZE)

#define FILE_SHARE_READ  0x00000001
#define FILE_SHARE_WRITE  0x00000002
#define FILE_SHARE_DELETE  0x00000004
#define FILE_ATTRIBUTE_READONLY  0x00000001
#define FILE_ATTRIBUTE_HIDDEN  0x00000002
#define FILE_ATTRIBUTE_SYSTEM  0x00000004
#define FILE_ATTRIBUTE_DIRECTORY  0x00000010
#define FILE_ATTRIBUTE_ARCHIVE  0x00000020
#define FILE_ATTRIBUTE_DEVICE  0x00000040
#define FILE_ATTRIBUTE_NORMAL  0x00000080
#define FILE_ATTRIBUTE_TEMPORARY  0x00000100
#define FILE_ATTRIBUTE_SPARSE_FILE  0x00000200
#define FILE_ATTRIBUTE_REPARSE_POINT  0x00000400
#define FILE_ATTRIBUTE_COMPRESSED  0x00000800
#define FILE_ATTRIBUTE_OFFLINE  0x00001000
#define FILE_ATTRIBUTE_NOT_CONTENT_INDEXED  0x00002000
#define FILE_ATTRIBUTE_ENCRYPTED  0x00004000
#define FILE_NOTIFY_CHANGE_FILE_NAME  0x00000001
#define FILE_NOTIFY_CHANGE_DIR_NAME  0x00000002
#define FILE_NOTIFY_CHANGE_ATTRIBUTES  0x00000004
#define FILE_NOTIFY_CHANGE_SIZE  0x00000008
#define FILE_NOTIFY_CHANGE_LAST_WRITE  0x00000010
#define FILE_NOTIFY_CHANGE_LAST_ACCESS  0x00000020
#define FILE_NOTIFY_CHANGE_CREATION  0x00000040
#define FILE_NOTIFY_CHANGE_SECURITY  0x00000100
#define FILE_ACTION_ADDED  0x00000001
#define FILE_ACTION_REMOVED  0x00000002
#define FILE_ACTION_MODIFIED  0x00000003
#define FILE_ACTION_RENAMED_OLD_NAME  0x00000004
#define FILE_ACTION_RENAMED_NEW_NAME  0x00000005
#define MAILSLOT_NO_MESSAGE  (-1)
#define MAILSLOT_WAIT_FOREVER  (-1)
#define FILE_CASE_SENSITIVE_SEARCH  0x00000001
#define FILE_CASE_PRESERVED_NAMES  0x00000002
#define FILE_UNICODE_ON_DISK  0x00000004
#define FILE_PERSISTENT_ACLS  0x00000008
#define FILE_FILE_COMPRESSION  0x00000010
#define FILE_VOLUME_QUOTAS  0x00000020
#define FILE_SUPPORTS_SPARSE_FILES  0x00000040
#define FILE_SUPPORTS_REPARSE_POINTS  0x00000080
#define FILE_SUPPORTS_REMOTE_STORAGE  0x00000100
#define FILE_VOLUME_IS_COMPRESSED  0x00008000
#define FILE_SUPPORTS_OBJECT_IDS  0x00010000
#define FILE_SUPPORTS_ENCRYPTION  0x00020000
#define FILE_NAMED_STREAMS  0x00040000
#define FILE_READ_ONLY_VOLUME           0x00080000  
#define FILE_SEQUENTIAL_WRITE_ONCE      0x00100000  
#define FILE_SUPPORTS_TRANSACTIONS      0x00200000  


#define MAXIMUM_REPARSE_DATA_BUFFER_SIZE  (16 * 1024)

#define IO_REPARSE_TAG_RESERVED_ZERO  0
#define IO_REPARSE_TAG_RESERVED_ONE  1
#define IO_REPARSE_TAG_RESERVED_RANGE  IO_REPARSE_TAG_RESERVED_ONE

#define IO_REPARSE_TAG_MOUNT_POINT  0xA0000003
#define IO_REPARSE_TAG_HSM  0xC0000004
#define IO_REPARSE_TAG_SIS  0x80000007
#define IO_COMPLETION_MODIFY_STATE  0x0002
#define IO_COMPLETION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#define DUPLICATE_CLOSE_SOURCE  0x00000001
#define DUPLICATE_SAME_ACCESS  0x00000002

#define ES_SYSTEM_REQUIRED  0x00000001
#define ES_DISPLAY_REQUIRED 0x00000002
#define ES_USER_PRESENT  0x00000004
#define ES_CONTINUOUS  0x80000000

#define IMAGE_DOS_SIGNATURE  0x5A4D
#define IMAGE_OS2_SIGNATURE  0x454E
#define IMAGE_OS2_SIGNATURE_LE  0x454C
#define IMAGE_VXD_SIGNATURE  0x454C
#define IMAGE_NT_SIGNATURE  0x00004550

#define IMAGE_SIZEOF_FILE_HEADER  20

#define IMAGE_FILE_RELOCS_STRIPPED  0x0001
#define IMAGE_FILE_EXECUTABLE_IMAGE  0x0002
#define IMAGE_FILE_LINE_NUMS_STRIPPED  0x0004
#define IMAGE_FILE_LOCAL_SYMS_STRIPPED  0x0008
#define IMAGE_FILE_AGGRESIVE_WS_TRIM  0x0010
#define IMAGE_FILE_LARGE_ADDRESS_AWARE  0x0020
#define IMAGE_FILE_BYTES_REVERSED_LO  0x0080
#define IMAGE_FILE_32BIT_MACHINE  0x0100
#define IMAGE_FILE_DEBUG_STRIPPED  0x0200
#define IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP  0x0400
#define IMAGE_FILE_NET_RUN_FROM_SWAP  0x0800
#define IMAGE_FILE_SYSTEM  0x1000
#define IMAGE_FILE_DLL  0x2000
#define IMAGE_FILE_UP_SYSTEM_ONLY  0x4000
#define IMAGE_FILE_BYTES_REVERSED_HI  0x8000

#define IMAGE_FILE_MACHINE_UNKNOWN  0
#define IMAGE_FILE_MACHINE_I386  0x014c
#define IMAGE_FILE_MACHINE_R3000  0x0162
#define IMAGE_FILE_MACHINE_R4000  0x0166
#define IMAGE_FILE_MACHINE_R10000  0x0168
#define IMAGE_FILE_MACHINE_WCEMIPSV2  0x0169
#define IMAGE_FILE_MACHINE_ALPHA  0x0184
#define IMAGE_FILE_MACHINE_POWERPC  0x01F0
#define IMAGE_FILE_MACHINE_SH3  0x01a2
#define IMAGE_FILE_MACHINE_SH3E  0x01a4
#define IMAGE_FILE_MACHINE_SH4  0x01a6
#define IMAGE_FILE_MACHINE_ARM  0x01c0
#define IMAGE_FILE_MACHINE_THUMB  0x01c2
#define IMAGE_FILE_MACHINE_IA64  0x0200
#define IMAGE_FILE_MACHINE_MIPS16  0x0266
#define IMAGE_FILE_MACHINE_MIPSFPU  0x0366
#define IMAGE_FILE_MACHINE_MIPSFPU16  0x0466
#define IMAGE_FILE_MACHINE_ALPHA64  0x0284
#define IMAGE_FILE_MACHINE_AXP64  IMAGE_FILE_MACHINE_ALPHA64
#define IMAGE_FILE_MACHINE_CEF  0xC0EF
#define IMAGE_FILE_MACHINE_EBC               0x0EBC  // EFI Byte Code
#define IMAGE_FILE_MACHINE_AMD64             0x8664  // AMD64 (K8)
#define IMAGE_FILE_MACHINE_M32R              0x9041  // M32R little-endian
#define IMAGE_FILE_MACHINE_CEE               0xC0EE

#define IMAGE_SIZEOF_ROM_OPTIONAL_HEADER  56
#define IMAGE_SIZEOF_STD_OPTIONAL_HEADER  28
#define IMAGE_SIZEOF_NT_OPTIONAL32_HEADER  224
#define IMAGE_SIZEOF_NT_OPTIONAL64_HEADER  240

#define IMAGE_NT_OPTIONAL_HDR32_MAGIC  0x10b
#define IMAGE_NT_OPTIONAL_HDR64_MAGIC  0x20b
#define IMAGE_ROM_OPTIONAL_HDR_MAGIC  0x107

#define IMAGE_SUBSYSTEM_UNKNOWN  0
#define IMAGE_SUBSYSTEM_NATIVE  1
#define IMAGE_SUBSYSTEM_WINDOWS_GUI  2
#define IMAGE_SUBSYSTEM_WINDOWS_CUI  3
#define IMAGE_SUBSYSTEM_OS2_CUI  5
#define IMAGE_SUBSYSTEM_POSIX_CUI  7
#define IMAGE_SUBSYSTEM_NATIVE_WINDOWS  8
#define IMAGE_SUBSYSTEM_WINDOWS_CE_GUI  9
#define IMAGE_SUBSYSTEM_EFI_APPLICATION  10
#define IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER  11
#define IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER  12
#define IMAGE_SUBSYSTEM_EFI_ROM 13
#define IMAGE_SUBSYSTEM_XBOX 14
#define IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION 16

#define IMAGE_DLLCHARACTERISTICS_NO_BIND  0x0800
#define IMAGE_DLLCHARACTERISTICS_WDM_DRIVER  0x2000
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE  0x8000
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#define IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY 0x0080
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#define IMAGE_DLLCHARACTERISTICS_NO_ISOLATION 0x0200
#define IMAGE_DLLCHARACTERISTICS_NO_SEH 0x0400

#define IMAGE_DIRECTORY_ENTRY_EXPORT  0
#define IMAGE_DIRECTORY_ENTRY_IMPORT  1
#define IMAGE_DIRECTORY_ENTRY_RESOURCE  2
#define IMAGE_DIRECTORY_ENTRY_EXCEPTION  3
#define IMAGE_DIRECTORY_ENTRY_SECURITY  4
#define IMAGE_DIRECTORY_ENTRY_BASERELOC  5
#define IMAGE_DIRECTORY_ENTRY_DEBUG  6
#define IMAGE_DIRECTORY_ENTRY_COPYRIGHT  7
#define IMAGE_DIRECTORY_ENTRY_ARCHITECTURE  7
#define IMAGE_DIRECTORY_ENTRY_GLOBALPTR  8
#define IMAGE_DIRECTORY_ENTRY_TLS  9
#define IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG  10
#define IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT  11
#define IMAGE_DIRECTORY_ENTRY_IAT  12
#define IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT  13
#define IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR 14

#define IMAGE_SIZEOF_SHORT_NAME  8
#define IMAGE_SIZEOF_SECTION_HEADER  40

#define IMAGE_SIZEOF_SYMBOL  18

#define IMAGE_SYM_UNDEFINED  0
#define IMAGE_SYM_ABSOLUTE  -1
#define IMAGE_SYM_DEBUG  -2

#define IMAGE_SYM_TYPE_NULL  0x0000
#define IMAGE_SYM_TYPE_VOID  0x0001
#define IMAGE_SYM_TYPE_CHAR  0x0002
#define IMAGE_SYM_TYPE_SHORT  0x0003
#define IMAGE_SYM_TYPE_INT  0x0004
#define IMAGE_SYM_TYPE_LONG  0x0005
#define IMAGE_SYM_TYPE_FLOAT  0x0006
#define IMAGE_SYM_TYPE_DOUBLE  0x0007
#define IMAGE_SYM_TYPE_STRUCT  0x0008
#define IMAGE_SYM_TYPE_UNION  0x0009
#define IMAGE_SYM_TYPE_ENUM  0x000A
#define IMAGE_SYM_TYPE_MOE  0x000B
#define IMAGE_SYM_TYPE_BYTE  0x000C
#define IMAGE_SYM_TYPE_WORD  0x000D
#define IMAGE_SYM_TYPE_UINT  0x000E
#define IMAGE_SYM_TYPE_DWORD  0x000F
#define IMAGE_SYM_TYPE_PCODE  0x8000

#define IMAGE_SYM_DTYPE_NULL  0
#define IMAGE_SYM_DTYPE_POINTER  1
#define IMAGE_SYM_DTYPE_FUNCTION  2
#define IMAGE_SYM_DTYPE_ARRAY  3

#define IMAGE_SYM_CLASS_END_OF_FUNCTION  -1
#define IMAGE_SYM_CLASS_NULL  0x0000
#define IMAGE_SYM_CLASS_AUTOMATIC  0x0001
#define IMAGE_SYM_CLASS_EXTERNAL  0x0002
#define IMAGE_SYM_CLASS_STATIC  0x0003
#define IMAGE_SYM_CLASS_REGISTER  0x0004
#define IMAGE_SYM_CLASS_EXTERNAL_DEF  0x0005
#define IMAGE_SYM_CLASS_LABEL  0x0006
#define IMAGE_SYM_CLASS_UNDEFINED_LABEL  0x0007
#define IMAGE_SYM_CLASS_MEMBER_OF_STRUCT  0x0008
#define IMAGE_SYM_CLASS_ARGUMENT  0x0009
#define IMAGE_SYM_CLASS_STRUCT_TAG  0x000A
#define IMAGE_SYM_CLASS_MEMBER_OF_UNION  0x000B
#define IMAGE_SYM_CLASS_UNION_TAG  0x000C
#define IMAGE_SYM_CLASS_TYPE_DEFINITION  0x000D
#define IMAGE_SYM_CLASS_UNDEFINED_STATIC  0x000E
#define IMAGE_SYM_CLASS_ENUM_TAG  0x000F
#define IMAGE_SYM_CLASS_MEMBER_OF_ENUM  0x0010
#define IMAGE_SYM_CLASS_REGISTER_PARAM  0x0011
#define IMAGE_SYM_CLASS_BIT_FIELD  0x0012

#define IMAGE_SYM_CLASS_FAR_EXTERNAL  0x0044

#define IMAGE_SYM_CLASS_BLOCK  0x0064
#define IMAGE_SYM_CLASS_FUNCTION  0x0065
#define IMAGE_SYM_CLASS_END_OF_STRUCT  0x0066
#define IMAGE_SYM_CLASS_FILE  0x0067
#define IMAGE_SYM_CLASS_SECTION  0x0068
#define IMAGE_SYM_CLASS_WEAK_EXTERNAL  0x0069

#define IMAGE_SIZEOF_AUX_SYMBOL  18

#define IMAGE_COMDAT_SELECT_NODUPLICATES  1
#define IMAGE_COMDAT_SELECT_ANY  2
#define IMAGE_COMDAT_SELECT_SAME_SIZE  3
#define IMAGE_COMDAT_SELECT_EXACT_MATCH  4
#define IMAGE_COMDAT_SELECT_ASSOCIATIVE  5
#define IMAGE_COMDAT_SELECT_LARGEST  6
#define IMAGE_COMDAT_SELECT_NEWEST  7

#define IMAGE_WEAK_EXTERN_SEARCH_NOLIBRARY  1
#define IMAGE_WEAK_EXTERN_SEARCH_LIBRARY  2
#define IMAGE_WEAK_EXTERN_SEARCH_ALIAS  3

#define IMAGE_SIZEOF_RELOCATION  10

#define IMAGE_REL_I386_ABSOLUTE  0x0000
#define IMAGE_REL_I386_DIR16  0x0001
#define IMAGE_REL_I386_REL16  0x0002
#define IMAGE_REL_I386_DIR32  0x0006
#define IMAGE_REL_I386_DIR32NB  0x0007
#define IMAGE_REL_I386_SEG12  0x0009
#define IMAGE_REL_I386_SECTION  0x000A
#define IMAGE_REL_I386_SECREL  0x000B
#define IMAGE_REL_I386_REL32  0x0014

#define IMAGE_REL_MIPS_ABSOLUTE         0x0000
#define IMAGE_REL_MIPS_REFHALF          0x0001
#define IMAGE_REL_MIPS_REFWORD          0x0002
#define IMAGE_REL_MIPS_JMPADDR          0x0003
#define IMAGE_REL_MIPS_REFHI            0x0004
#define IMAGE_REL_MIPS_REFLO            0x0005
#define IMAGE_REL_MIPS_GPREL            0x0006
#define IMAGE_REL_MIPS_LITERAL          0x0007
#define IMAGE_REL_MIPS_SECTION          0x000A
#define IMAGE_REL_MIPS_SECREL           0x000B
#define IMAGE_REL_MIPS_SECRELLO         0x000C
#define IMAGE_REL_MIPS_SECRELHI         0x000D
#define IMAGE_REL_MIPS_TOKEN            0x000E
#define IMAGE_REL_MIPS_JMPADDR16        0x0010
#define IMAGE_REL_MIPS_REFWORDNB        0x0022
#define IMAGE_REL_MIPS_PAIR             0x0025

//
// Alpha Relocation types.
//
#define IMAGE_REL_ALPHA_ABSOLUTE        0x0000
#define IMAGE_REL_ALPHA_REFLONG         0x0001
#define IMAGE_REL_ALPHA_REFQUAD         0x0002
#define IMAGE_REL_ALPHA_GPREL32         0x0003
#define IMAGE_REL_ALPHA_LITERAL         0x0004
#define IMAGE_REL_ALPHA_LITUSE          0x0005
#define IMAGE_REL_ALPHA_GPDISP          0x0006
#define IMAGE_REL_ALPHA_BRADDR          0x0007
#define IMAGE_REL_ALPHA_HINT            0x0008
#define IMAGE_REL_ALPHA_INLINE_REFLONG  0x0009
#define IMAGE_REL_ALPHA_REFHI           0x000A
#define IMAGE_REL_ALPHA_REFLO           0x000B
#define IMAGE_REL_ALPHA_PAIR            0x000C
#define IMAGE_REL_ALPHA_MATCH           0x000D
#define IMAGE_REL_ALPHA_SECTION         0x000E
#define IMAGE_REL_ALPHA_SECREL          0x000F
#define IMAGE_REL_ALPHA_REFLONGNB       0x0010
#define IMAGE_REL_ALPHA_SECRELLO        0x0011
#define IMAGE_REL_ALPHA_SECRELHI        0x0012
#define IMAGE_REL_ALPHA_REFQ3           0x0013
#define IMAGE_REL_ALPHA_REFQ2           0x0014
#define IMAGE_REL_ALPHA_REFQ1           0x0015
#define IMAGE_REL_ALPHA_GPRELLO         0x0016
#define IMAGE_REL_ALPHA_GPRELHI         0x0017

//
// IBM PowerPC relocation types.
//
#define IMAGE_REL_PPC_ABSOLUTE          0x0000
#define IMAGE_REL_PPC_ADDR64            0x0001
#define IMAGE_REL_PPC_ADDR32            0x0002
#define IMAGE_REL_PPC_ADDR24            0x0003
#define IMAGE_REL_PPC_ADDR16            0x0004
#define IMAGE_REL_PPC_ADDR14            0x0005
#define IMAGE_REL_PPC_REL24             0x0006
#define IMAGE_REL_PPC_REL14             0x0007
#define IMAGE_REL_PPC_TOCREL16          0x0008
#define IMAGE_REL_PPC_TOCREL14          0x0009

#define IMAGE_REL_PPC_ADDR32NB          0x000A
#define IMAGE_REL_PPC_SECREL            0x000B
#define IMAGE_REL_PPC_SECTION           0x000C
#define IMAGE_REL_PPC_IFGLUE            0x000D
#define IMAGE_REL_PPC_IMGLUE            0x000E
#define IMAGE_REL_PPC_SECREL16          0x000F
#define IMAGE_REL_PPC_REFHI             0x0010
#define IMAGE_REL_PPC_REFLO             0x0011
#define IMAGE_REL_PPC_PAIR              0x0012
#define IMAGE_REL_PPC_SECRELLO          0x0013
#define IMAGE_REL_PPC_SECRELHI          0x0014
#define IMAGE_REL_PPC_GPREL             0x0015
#define IMAGE_REL_PPC_TOKEN             0x0016

#define IMAGE_REL_PPC_TYPEMASK          0x00FF

// Flag bits in IMAGE_RELOCATION.TYPE

#define IMAGE_REL_PPC_NEG               0x0100
#define IMAGE_REL_PPC_BRTAKEN           0x0200
#define IMAGE_REL_PPC_BRNTAKEN          0x0400
#define IMAGE_REL_PPC_TOCDEFN           0x0800

//
// Hitachi SH3 relocation types.
//
#define IMAGE_REL_SH3_ABSOLUTE          0x0000
#define IMAGE_REL_SH3_DIRECT16          0x0001
#define IMAGE_REL_SH3_DIRECT32          0x0002
#define IMAGE_REL_SH3_DIRECT8           0x0003
#define IMAGE_REL_SH3_DIRECT8_WORD      0x0004
#define IMAGE_REL_SH3_DIRECT8_LONG      0x0005
#define IMAGE_REL_SH3_DIRECT4           0x0006
#define IMAGE_REL_SH3_DIRECT4_WORD      0x0007
#define IMAGE_REL_SH3_DIRECT4_LONG      0x0008
#define IMAGE_REL_SH3_PCREL8_WORD       0x0009
#define IMAGE_REL_SH3_PCREL8_LONG       0x000A
#define IMAGE_REL_SH3_PCREL12_WORD      0x000B
#define IMAGE_REL_SH3_STARTOF_SECTION   0x000C
#define IMAGE_REL_SH3_SIZEOF_SECTION    0x000D
#define IMAGE_REL_SH3_SECTION           0x000E
#define IMAGE_REL_SH3_SECREL            0x000F
#define IMAGE_REL_SH3_DIRECT32_NB       0x0010
#define IMAGE_REL_SH3_GPREL4_LONG       0x0011
#define IMAGE_REL_SH3_TOKEN             0x0012
#define IMAGE_REL_SHM_PCRELPT           0x0013
#define IMAGE_REL_SHM_REFLO             0x0014
#define IMAGE_REL_SHM_REFHALF           0x0015
#define IMAGE_REL_SHM_RELLO             0x0016
#define IMAGE_REL_SHM_RELHALF           0x0017
#define IMAGE_REL_SHM_PAIR              0x0018

#define IMAGE_REL_SH_NOMODE             0x8000


#define IMAGE_REL_ARM_ABSOLUTE          0x0000
#define IMAGE_REL_ARM_ADDR32            0x0001
#define IMAGE_REL_ARM_ADDR32NB          0x0002
#define IMAGE_REL_ARM_BRANCH24          0x0003
#define IMAGE_REL_ARM_BRANCH11          0x0004
#define IMAGE_REL_ARM_TOKEN             0x0005
#define IMAGE_REL_ARM_GPREL12           0x0006
#define IMAGE_REL_ARM_GPREL7            0x0007
#define IMAGE_REL_ARM_BLX24             0x0008
#define IMAGE_REL_ARM_BLX11             0x0009
#define IMAGE_REL_ARM_SECTION           0x000E
#define IMAGE_REL_ARM_SECREL            0x000F

#define IMAGE_REL_AM_ABSOLUTE           0x0000
#define IMAGE_REL_AM_ADDR32             0x0001
#define IMAGE_REL_AM_ADDR32NB           0x0002
#define IMAGE_REL_AM_CALL32             0x0003
#define IMAGE_REL_AM_FUNCINFO           0x0004
#define IMAGE_REL_AM_REL32_1            0x0005
#define IMAGE_REL_AM_REL32_2            0x0006
#define IMAGE_REL_AM_SECREL             0x0007
#define IMAGE_REL_AM_SECTION            0x0008
#define IMAGE_REL_AM_TOKEN              0x0009

//
// x64 relocations
//
#define IMAGE_REL_AMD64_ABSOLUTE        0x0000  // Reference is absolute, no relocation is necessary
#define IMAGE_REL_AMD64_ADDR64          0x0001  // 64-bit address (VA).
#define IMAGE_REL_AMD64_ADDR32          0x0002  // 32-bit address (VA).
#define IMAGE_REL_AMD64_ADDR32NB        0x0003  // 32-bit address w/o image base (RVA).
#define IMAGE_REL_AMD64_REL32           0x0004  // 32-bit relative address from byte following reloc
#define IMAGE_REL_AMD64_REL32_1         0x0005  // 32-bit relative address from byte distance 1 from reloc
#define IMAGE_REL_AMD64_REL32_2         0x0006  // 32-bit relative address from byte distance 2 from reloc
#define IMAGE_REL_AMD64_REL32_3         0x0007  // 32-bit relative address from byte distance 3 from reloc
#define IMAGE_REL_AMD64_REL32_4         0x0008  // 32-bit relative address from byte distance 4 from reloc
#define IMAGE_REL_AMD64_REL32_5         0x0009  // 32-bit relative address from byte distance 5 from reloc
#define IMAGE_REL_AMD64_SECTION         0x000A  // Section index
#define IMAGE_REL_AMD64_SECREL          0x000B  // 32 bit offset from base of section containing target
#define IMAGE_REL_AMD64_SECREL7         0x000C  // 7 bit unsigned offset from base of section containing target
#define IMAGE_REL_AMD64_TOKEN           0x000D  // 32 bit metadata token
#define IMAGE_REL_AMD64_SREL32          0x000E  // 32 bit signed span-dependent value emitted into object
#define IMAGE_REL_AMD64_PAIR            0x000F
#define IMAGE_REL_AMD64_SSPAN32         0x0010  // 32 bit signed span-dependent value applied at link time

//
// IA64 relocation types.
//
#define IMAGE_REL_IA64_ABSOLUTE  0x0000
#define IMAGE_REL_IA64_IMM14  0x0001
#define IMAGE_REL_IA64_IMM22  0x0002
#define IMAGE_REL_IA64_IMM64  0x0003
#define IMAGE_REL_IA64_DIR32  0x0004
#define IMAGE_REL_IA64_DIR64  0x0005
#define IMAGE_REL_IA64_PCREL21B  0x0006
#define IMAGE_REL_IA64_PCREL21M  0x0007
#define IMAGE_REL_IA64_PCREL21F  0x0008
#define IMAGE_REL_IA64_GPREL22  0x0009
#define IMAGE_REL_IA64_LTOFF22  0x000A
#define IMAGE_REL_IA64_SECTION  0x000B
#define IMAGE_REL_IA64_SECREL22  0x000C
#define IMAGE_REL_IA64_SECREL64I  0x000D
#define IMAGE_REL_IA64_SECREL32  0x000E
#define IMAGE_REL_IA64_LTOFF64  0x000F
#define IMAGE_REL_IA64_DIR32NB  0x0010
#define IMAGE_REL_IA64_SREL22  0x0011
#define IMAGE_REL_IA64_UREL22  0x0012
#define IMAGE_REL_IA64_SREL32  0x0013
#define IMAGE_REL_IA64_UREL32  0x0014
#define IMAGE_REL_IA64_ADDEND  0x001F
//
// CEF relocation types.
//
#define IMAGE_REL_CEF_ABSOLUTE          0x0000
#define IMAGE_REL_CEF_ADDR32            0x0001
#define IMAGE_REL_CEF_ADDR64            0x0002
#define IMAGE_REL_CEF_ADDR32NB          0x0003
#define IMAGE_REL_CEF_SECTION           0x0004
#define IMAGE_REL_CEF_SECREL            0x0005
#define IMAGE_REL_CEF_TOKEN             0x0006

//
// clr relocation types.
//
#define IMAGE_REL_CEE_ABSOLUTE          0x0000
#define IMAGE_REL_CEE_ADDR32            0x0001
#define IMAGE_REL_CEE_ADDR64            0x0002
#define IMAGE_REL_CEE_ADDR32NB          0x0003
#define IMAGE_REL_CEE_SECTION           0x0004
#define IMAGE_REL_CEE_SECREL            0x0005
#define IMAGE_REL_CEE_TOKEN             0x0006


#define IMAGE_REL_M32R_ABSOLUTE         0x0000
#define IMAGE_REL_M32R_ADDR32           0x0001
#define IMAGE_REL_M32R_ADDR32NB         0x0002
#define IMAGE_REL_M32R_ADDR24           0x0003
#define IMAGE_REL_M32R_GPREL16          0x0004
#define IMAGE_REL_M32R_PCREL24          0x0005
#define IMAGE_REL_M32R_PCREL16          0x0006
#define IMAGE_REL_M32R_PCREL8           0x0007
#define IMAGE_REL_M32R_REFHALF          0x0008
#define IMAGE_REL_M32R_REFHI            0x0009
#define IMAGE_REL_M32R_REFLO            0x000A
#define IMAGE_REL_M32R_PAIR             0x000B
#define IMAGE_REL_M32R_SECTION          0x000C
#define IMAGE_REL_M32R_SECREL32         0x000D
#define IMAGE_REL_M32R_TOKEN            0x000E

#define IMAGE_REL_EBC_ABSOLUTE          0x0000
#define IMAGE_REL_EBC_ADDR32NB          0x0001
#define IMAGE_REL_EBC_REL32             0x0002
#define IMAGE_REL_EBC_SECTION           0x0003
#define IMAGE_REL_EBC_SECREL            0x0004


#define EMARCH_ENC_I17_IMM7B_INST_WORD_X         3  // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM7B_SIZE_X              7  // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM7B_INST_WORD_POS_X     4  // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM7B_VAL_POS_X           0  // Intel-IA64-Filler

#define EMARCH_ENC_I17_IMM9D_INST_WORD_X         3  // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM9D_SIZE_X              9  // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM9D_INST_WORD_POS_X     18 // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM9D_VAL_POS_X           7  // Intel-IA64-Filler

#define EMARCH_ENC_I17_IMM5C_INST_WORD_X         3  // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM5C_SIZE_X              5  // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM5C_INST_WORD_POS_X     13 // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM5C_VAL_POS_X           16 // Intel-IA64-Filler

#define EMARCH_ENC_I17_IC_INST_WORD_X            3  // Intel-IA64-Filler
#define EMARCH_ENC_I17_IC_SIZE_X                 1  // Intel-IA64-Filler
#define EMARCH_ENC_I17_IC_INST_WORD_POS_X        12 // Intel-IA64-Filler
#define EMARCH_ENC_I17_IC_VAL_POS_X              21 // Intel-IA64-Filler

#define EMARCH_ENC_I17_IMM41a_INST_WORD_X        1  // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM41a_SIZE_X             10 // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM41a_INST_WORD_POS_X    14 // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM41a_VAL_POS_X          22 // Intel-IA64-Filler

#define EMARCH_ENC_I17_IMM41b_INST_WORD_X        1  // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM41b_SIZE_X             8  // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM41b_INST_WORD_POS_X    24 // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM41b_VAL_POS_X          32 // Intel-IA64-Filler

#define EMARCH_ENC_I17_IMM41c_INST_WORD_X        2  // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM41c_SIZE_X             23 // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM41c_INST_WORD_POS_X    0  // Intel-IA64-Filler
#define EMARCH_ENC_I17_IMM41c_VAL_POS_X          40 // Intel-IA64-Filler

#define EMARCH_ENC_I17_SIGN_INST_WORD_X          3  // Intel-IA64-Filler
#define EMARCH_ENC_I17_SIGN_SIZE_X               1  // Intel-IA64-Filler
#define EMARCH_ENC_I17_SIGN_INST_WORD_POS_X      27 // Intel-IA64-Filler
#define EMARCH_ENC_I17_SIGN_VAL_POS_X            63 // Intel-IA64-Filler

#define X3_OPCODE_INST_WORD_X                    3  // Intel-IA64-Filler
#define X3_OPCODE_SIZE_X                         4  // Intel-IA64-Filler
#define X3_OPCODE_INST_WORD_POS_X                28 // Intel-IA64-Filler
#define X3_OPCODE_SIGN_VAL_POS_X                 0  // Intel-IA64-Filler

#define X3_I_INST_WORD_X                         3  // Intel-IA64-Filler
#define X3_I_SIZE_X                              1  // Intel-IA64-Filler
#define X3_I_INST_WORD_POS_X                     27 // Intel-IA64-Filler
#define X3_I_SIGN_VAL_POS_X                      59 // Intel-IA64-Filler

#define X3_D_WH_INST_WORD_X                      3  // Intel-IA64-Filler
#define X3_D_WH_SIZE_X                           3  // Intel-IA64-Filler
#define X3_D_WH_INST_WORD_POS_X                  24 // Intel-IA64-Filler
#define X3_D_WH_SIGN_VAL_POS_X                   0  // Intel-IA64-Filler

#define X3_IMM20_INST_WORD_X                     3  // Intel-IA64-Filler
#define X3_IMM20_SIZE_X                          20 // Intel-IA64-Filler
#define X3_IMM20_INST_WORD_POS_X                 4  // Intel-IA64-Filler
#define X3_IMM20_SIGN_VAL_POS_X                  0  // Intel-IA64-Filler

#define X3_IMM39_1_INST_WORD_X                   2  // Intel-IA64-Filler
#define X3_IMM39_1_SIZE_X                        23 // Intel-IA64-Filler
#define X3_IMM39_1_INST_WORD_POS_X               0  // Intel-IA64-Filler
#define X3_IMM39_1_SIGN_VAL_POS_X                36 // Intel-IA64-Filler

#define X3_IMM39_2_INST_WORD_X                   1  // Intel-IA64-Filler
#define X3_IMM39_2_SIZE_X                        16 // Intel-IA64-Filler
#define X3_IMM39_2_INST_WORD_POS_X               16 // Intel-IA64-Filler
#define X3_IMM39_2_SIGN_VAL_POS_X                20 // Intel-IA64-Filler

#define X3_P_INST_WORD_X                         3  // Intel-IA64-Filler
#define X3_P_SIZE_X                              4  // Intel-IA64-Filler
#define X3_P_INST_WORD_POS_X                     0  // Intel-IA64-Filler
#define X3_P_SIGN_VAL_POS_X                      0  // Intel-IA64-Filler

#define X3_TMPLT_INST_WORD_X                     0  // Intel-IA64-Filler
#define X3_TMPLT_SIZE_X                          4  // Intel-IA64-Filler
#define X3_TMPLT_INST_WORD_POS_X                 0  // Intel-IA64-Filler
#define X3_TMPLT_SIGN_VAL_POS_X                  0  // Intel-IA64-Filler

#define X3_BTYPE_QP_INST_WORD_X                  2  // Intel-IA64-Filler
#define X3_BTYPE_QP_SIZE_X                       9  // Intel-IA64-Filler
#define X3_BTYPE_QP_INST_WORD_POS_X              23 // Intel-IA64-Filler
#define X3_BTYPE_QP_INST_VAL_POS_X               0  // Intel-IA64-Filler

#define X3_EMPTY_INST_WORD_X                     1  // Intel-IA64-Filler
#define X3_EMPTY_SIZE_X                          2  // Intel-IA64-Filler
#define X3_EMPTY_INST_WORD_POS_X                 14 // Intel-IA64-Filler
#define X3_EMPTY_INST_VAL_POS_X                  0  // Intel-IA64-Filler

#define IMAGE_REL_ARM_ABSOLUTE  0x0000
#define IMAGE_REL_ARM_ADDR32  0x0001
#define IMAGE_REL_ARM_ADDR32NB  0x0002
#define IMAGE_REL_ARM_BRANCH24  0x0003
#define IMAGE_REL_ARM_BRANCH11  0x0004
#define IMAGE_REL_ARM_SECTION  0x000E
#define IMAGE_REL_ARM_SECREL  0x000F

#define IMAGE_SIZEOF_LINENUMBER  6
#define IMAGE_SIZEOF_BASE_RELOCATION  8

#define IMAGE_REL_BASED_ABSOLUTE  0
#define IMAGE_REL_BASED_HIGH  1
#define IMAGE_REL_BASED_LOW  2
#define IMAGE_REL_BASED_HIGHLOW  3
#define IMAGE_REL_BASED_HIGHADJ  4
#define IMAGE_REL_BASED_MIPS_JMPADDR  5
#define IMAGE_REL_BASED_SECTION  6
#define IMAGE_REL_BASED_REL32  7

#define IMAGE_REL_BASED_MIPS_JMPADDR16  9
#define IMAGE_REL_BASED_IA64_IMM64  9
#define IMAGE_REL_BASED_DIR64  10
#define IMAGE_REL_BASED_HIGH3ADJ  11

#define IMAGE_ARCHIVE_START_SIZE  8
#define IMAGE_ARCHIVE_START  "!<arch>\n"
#define IMAGE_ARCHIVE_END  "`\n"
#define IMAGE_ARCHIVE_PAD  "\n"
#define IMAGE_ARCHIVE_LINKER_MEMBER  "/               "
#define IMAGE_ARCHIVE_LONGNAMES_MEMBER  "//              "

#define IMAGE_ORDINAL_FLAG64  0x8000000000000000
#define IMAGE_ORDINAL_FLAG32  0x80000000

#define IMAGE_RESOURCE_NAME_IS_STRING  0x80000000
#define IMAGE_RESOURCE_DATA_IS_DIRECTORY  0x80000000

#define IMAGE_DEBUG_TYPE_UNKNOWN  0
#define IMAGE_DEBUG_TYPE_COFF  1
#define IMAGE_DEBUG_TYPE_CODEVIEW  2
#define IMAGE_DEBUG_TYPE_FPO  3
#define IMAGE_DEBUG_TYPE_MISC  4
#define IMAGE_DEBUG_TYPE_EXCEPTION  5
#define IMAGE_DEBUG_TYPE_FIXUP  6
#define IMAGE_DEBUG_TYPE_OMAP_TO_SRC  7
#define IMAGE_DEBUG_TYPE_OMAP_FROM_SRC  8
#define IMAGE_DEBUG_TYPE_BORLAND  9
#define IMAGE_DEBUG_TYPE_RESERVED10  10
#define IMAGE_DEBUG_TYPE_CLSID  11

#define FRAME_FPO  0
#define FRAME_TRAP  1
#define FRAME_TSS  2
#define FRAME_NONFPO  3

#define SIZEOF_RFPO_DATA 16

#define IMAGE_DEBUG_MISC_EXENAME  1

#define IMAGE_SEPARATE_DEBUG_SIGNATURE 0x4944
#define IMAGE_SEPARATE_DEBUG_FLAGS_MASK 0x8000
#define IMAGE_SEPARATE_DEBUG_MISMATCH  0x8000

#define IMPORT_OBJECT_HDR_SIG2  0xffff

#define N_BTMASK  0x000F
#define N_TMASK  0x0030
#define N_TMASK1  0x00C0
#define N_TMASK2  0x00F0
#define N_BTSHFT  4
#define N_TSHIFT  2

#define HEAP_NO_SERIALIZE  0x00000001
#define HEAP_GROWABLE  0x00000002
#define HEAP_GENERATE_EXCEPTIONS  0x00000004
#define HEAP_ZERO_MEMORY  0x00000008
#define HEAP_REALLOC_IN_PLACE_ONLY  0x00000010
#define HEAP_TAIL_CHECKING_ENABLED  0x00000020
#define HEAP_FREE_CHECKING_ENABLED  0x00000040
#define HEAP_DISABLE_COALESCE_ON_FREE  0x00000080
#define HEAP_CREATE_ALIGN_16  0x00010000
#define HEAP_CREATE_ENABLE_TRACING  0x00020000
#define HEAP_MAXIMUM_TAG  0x0FFF
#define HEAP_PSEUDO_TAG_FLAG  0x8000
#define HEAP_TAG_SHIFT  18

#define IS_TEXT_UNICODE_ASCII16  0x0001
#define IS_TEXT_UNICODE_REVERSE_ASCII16  0x0010
#define IS_TEXT_UNICODE_STATISTICS  0x0002
#define IS_TEXT_UNICODE_REVERSE_STATISTICS  0x0020
#define IS_TEXT_UNICODE_CONTROLS  0x0004
#define IS_TEXT_UNICODE_REVERSE_CONTROLS  0x0040
#define IS_TEXT_UNICODE_SIGNATURE  0x0008
#define IS_TEXT_UNICODE_REVERSE_SIGNATURE  0x0080
#define IS_TEXT_UNICODE_ILLEGAL_CHARS  0x0100
#define IS_TEXT_UNICODE_ODD_LENGTH  0x0200
#define IS_TEXT_UNICODE_DBCS_LEADBYTE  0x0400
#define IS_TEXT_UNICODE_NULL_BYTES  0x1000
#define IS_TEXT_UNICODE_UNICODE_MASK  0x000F
#define IS_TEXT_UNICODE_REVERSE_MASK  0x00F0
#define IS_TEXT_UNICODE_NOT_UNICODE_MASK  0x0F00
#define IS_TEXT_UNICODE_NOT_ASCII_MASK  0xF000

#define COMPRESSION_FORMAT_NONE  0x0000
#define COMPRESSION_FORMAT_DEFAULT  0x0001
#define COMPRESSION_FORMAT_LZNT1  0x0002
#define COMPRESSION_ENGINE_STANDARD  0x0000
#define COMPRESSION_ENGINE_MAXIMUM  0x0100
#define COMPRESSION_ENGINE_HIBER  0x0200

#define MESSAGE_RESOURCE_UNICODE 0x0001

#define VER_EQUAL  1
#define VER_GREATER  2
#define VER_GREATER_EQUAL  3
#define VER_LESS  4
#define VER_LESS_EQUAL  5
#define VER_AND  6
#define VER_OR  7

#define VER_CONDITION_MASK  7
#define VER_NUM_BITS_PER_CONDITION_MASK 3

#define VER_MINORVERSION  0x0000001
#define VER_MAJORVERSION  0x0000002
#define VER_BUILDNUMBER  0x0000004
#define VER_PLATFORMID  0x0000008
#define VER_SERVICEPACKMINOR  0x0000010
#define VER_SERVICEPACKMAJOR  0x0000020
#define VER_SUITENAME  0x0000040
#define VER_PRODUCT_TYPE  0x0000080

#define VER_NT_WORKSTATION  0x0000001
#define VER_NT_DOMAIN_CONTROLLER  0x0000002
#define VER_NT_SERVER  0x0000003

#define VER_PLATFORM_WIN32s  0
#define VER_PLATFORM_WIN32_WINDOWS  1
#define VER_PLATFORM_WIN32_NT  2
#define VER_PLATFORM_WIN32_CE  3

#define RTL_CRITSECT_TYPE  0
#define RTL_RESOURCE_TYPE  1

#define SEF_DACL_AUTO_INHERIT  0x01
#define SEF_SACL_AUTO_INHERIT  0x02
#define SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT 0x04
#define SEF_AVOID_PRIVILEGE_CHECK  0x08
#define SEF_AVOID_OWNER_CHECK  0x10
#define SEF_DEFAULT_OWNER_FROM_PARENT  0x20
#define SEF_DEFAULT_GROUP_FROM_PARENT  0x40

#define WT_EXECUTEDEFAULT  0x00000000
#define WT_EXECUTEINIOTHREAD  0x00000001
#define WT_EXECUTEINUITHREAD  0x00000002
#define WT_EXECUTEINWAITTHREAD  0x00000004
#define WT_EXECUTEONLYONCE  0x00000008
#define WT_EXECUTEINTIMERTHREAD 0x00000020
#define WT_EXECUTELONGFUNCTION  0x00000010
#define WT_EXECUTEINPERSISTENTIOTHREAD  0x00000040
#define WT_EXECUTEINPERSISTENTTHREAD  0x00000080

#define WT_EXECUTEINLONGTHREAD  0x00000010
#define WT_EXECUTEDELETEWAIT  0x00000008
#define DLL_PROCESS_ATTACH  1
#define DLL_THREAD_ATTACH  2
#define DLL_THREAD_DETACH  3
#define DLL_PROCESS_DETACH  0

#define EVENTLOG_SEQUENTIAL_READ  0x0001
#define EVENTLOG_SEEK_READ  0x0002
#define EVENTLOG_FORWARDS_READ  0x0004
#define EVENTLOG_BACKWARDS_READ  0x0008

#define EVENTLOG_SUCCESS  0x0000
#define EVENTLOG_ERROR_TYPE  0x0001
#define EVENTLOG_WARNING_TYPE  0x0002
#define EVENTLOG_INFORMATION_TYPE  0x0004
#define EVENTLOG_AUDIT_SUCCESS  0x0008
#define EVENTLOG_AUDIT_FAILURE  0x0010

#define EVENTLOG_START_PAIRED_EVENT  0x0001
#define EVENTLOG_END_PAIRED_EVENT  0x0002
#define EVENTLOG_END_ALL_PAIRED_EVENTS 0x0004
#define EVENTLOG_PAIRED_EVENT_ACTIVE  0x0008
#define EVENTLOG_PAIRED_EVENT_INACTIVE  0x0010

#define MAXLOGICALLOGNAMESIZE  256

#define KEY_QUERY_VALUE  0x0001
#define KEY_SET_VALUE  0x0002
#define KEY_CREATE_SUB_KEY  0x0004
#define KEY_ENUMERATE_SUB_KEYS  0x0008
#define KEY_NOTIFY  0x0010
#define KEY_CREATE_LINK  0x0020
#define KEY_WOW64_32KEY 0x0200
#define KEY_WOW64_64KEY 0x0100
#define KEY_WOW64_RES 0x0300

#define KEY_READ 00020019h
#define KEY_WRITE 00020006h
#define KEY_ALL_ACCESS 000F003Fh
#define KEY_EXECUTE KEY_READ

#define REG_OPTION_RESERVED  0x00000000
#define REG_LEGAL_OPTION  (REG_OPTION_RESERVED|REG_OPTION_NON_VOLATILE|REG_OPTION_VOLATILE|REG_OPTION_CREATE_LINK|REG_OPTION_BACKUP_RESTORE|REG_OPTION_OPEN_LINK)
#define REG_LEGAL_CHANGE_FILTER  (REG_NOTIFY_CHANGE_NAME|REG_NOTIFY_CHANGE_ATTRIBUTES|REG_NOTIFY_CHANGE_LAST_SET|REG_NOTIFY_CHANGE_SECURITY)
//
// hive format to be used by Reg(Nt)SaveKeyEx
//
#define REG_STANDARD_FORMAT     1
#define REG_LATEST_FORMAT       2
#define REG_NO_COMPRESSION      4
//
// Key restore & hive load flags
//
#define REG_WHOLE_HIVE_VOLATILE         0x00000001   // Restore whole hive volatile
#define REG_REFRESH_HIVE                0x00000002   // Unwind changes to last flush
#define REG_NO_LAZY_FLUSH               0x00000004   // Never lazy flush this hive
#define REG_FORCE_RESTORE               0x00000008   // Force the restore process even when we have open handles on subkeys
#define REG_APP_HIVE                    0x00000010   // Loads the hive visible to the calling process
#define REG_PROCESS_PRIVATE             0x00000020   // Hive cannot be mounted by any other process while in use
#define REG_START_JOURNAL               0x00000040   // Starts Hive Journal
#define REG_HIVE_EXACT_FILE_GROWTH      0x00000080   // Grow hive file in exact 4k increments
#define REG_HIVE_NO_RM                  0x00000100   // No RM is started for this hive (no transactions)
#define REG_HIVE_SINGLE_LOG             0x00000200   // Legacy single logging is used for this hive

#define REG_FORCE_UNLOAD            1

#IFNDEF WINREG_H
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

#define SERVICE_KERNEL_DRIVER  0x00000001
#define SERVICE_FILE_SYSTEM_DRIVER  0x00000002
#define SERVICE_ADAPTER  0x00000004
#define SERVICE_RECOGNIZER_DRIVER  0x00000008
#define SERVICE_DRIVER  (SERVICE_KERNEL_DRIVER|SERVICE_FILE_SYSTEM_DRIVER|SERVICE_RECOGNIZER_DRIVER)

#define SERVICE_WIN32_OWN_PROCESS  0x00000010
#define SERVICE_WIN32_SHARE_PROCESS  0x00000020
#define SERVICE_WIN32  (SERVICE_WIN32_OWN_PROCESS|SERVICE_WIN32_SHARE_PROCESS)

#define SERVICE_INTERACTIVE_PROCESS  0x00000100

#define SERVICE_TYPE_ALL  (SERVICE_WIN32|SERVICE_ADAPTER|SERVICE_DRIVER|SERVICE_INTERACTIVE_PROCESS)

#define SERVICE_BOOT_START  0x00000000
#define SERVICE_SYSTEM_START  0x00000001
#define SERVICE_AUTO_START  0x00000002
#define SERVICE_DEMAND_START  0x00000003
#define SERVICE_DISABLED  0x00000004

#define SERVICE_ERROR_IGNORE  0x00000000
#define SERVICE_ERROR_NORMAL  0x00000001
#define SERVICE_ERROR_SEVERE  0x00000002
#define SERVICE_ERROR_CRITICAL  0x00000003

#define TAPE_ERASE_SHORT  0
#define TAPE_ERASE_LONG  1

#define TAPE_LOAD  0
#define TAPE_UNLOAD  1
#define TAPE_TENSION  2
#define TAPE_LOCK  3
#define TAPE_UNLOCK  4
#define TAPE_FORMAT  5

#define TAPE_SETMARKS  0
#define TAPE_FILEMARKS  1
#define TAPE_SHORT_FILEMARKS  2
#define TAPE_LONG_FILEMARKS  3

#define TAPE_ABSOLUTE_POSITION  0
#define TAPE_LOGICAL_POSITION  1
#define TAPE_PSEUDO_LOGICAL_POSITION 2

#define TAPE_REWIND  0
#define TAPE_ABSOLUTE_BLOCK  1
#define TAPE_LOGICAL_BLOCK  2
#define TAPE_PSEUDO_LOGICAL_BLOCK  3
#define TAPE_SPACE_END_OF_DATA  4
#define TAPE_SPACE_RELATIVE_BLOCKS  5
#define TAPE_SPACE_FILEMARKS  6
#define TAPE_SPACE_SEQUENTIAL_FMKS  7
#define TAPE_SPACE_SETMARKS  8
#define TAPE_SPACE_SEQUENTIAL_SMKS  9

#define TAPE_DRIVE_FIXED  0x00000001
#define TAPE_DRIVE_SELECT  0x00000002
#define TAPE_DRIVE_INITIATOR  0x00000004
#define TAPE_DRIVE_ERASE_SHORT  0x00000010
#define TAPE_DRIVE_ERASE_LONG  0x00000020
#define TAPE_DRIVE_ERASE_BOP_ONLY  0x00000040
#define TAPE_DRIVE_ERASE_IMMEDIATE  0x00000080
#define TAPE_DRIVE_TAPE_CAPACITY  0x00000100
#define TAPE_DRIVE_TAPE_REMAINING  0x00000200
#define TAPE_DRIVE_FIXED_BLOCK  0x00000400
#define TAPE_DRIVE_VARIABLE_BLOCK  0x00000800
#define TAPE_DRIVE_WRITE_PROTECT  0x00001000
#define TAPE_DRIVE_EOT_WZ_SIZE  0x00002000
#define TAPE_DRIVE_ECC  0x00010000
#define TAPE_DRIVE_COMPRESSION  0x00020000
#define TAPE_DRIVE_PADDING  0x00040000
#define TAPE_DRIVE_REPORT_SMKS  0x00080000
#define TAPE_DRIVE_GET_ABSOLUTE_BLK 0x00100000
#define TAPE_DRIVE_GET_LOGICAL_BLK  0x00200000
#define TAPE_DRIVE_SET_EOT_WZ_SIZE  0x00400000
#define TAPE_DRIVE_EJECT_MEDIA  0x01000000
#define TAPE_DRIVE_CLEAN_REQUESTS  0x02000000
#define TAPE_DRIVE_SET_CMP_BOP_ONLY 0x04000000
#define TAPE_DRIVE_RESERVED_BIT  0x80000000
#define TAPE_DRIVE_LOAD_UNLOAD  0x80000001
#define TAPE_DRIVE_TENSION  0x80000002
#define TAPE_DRIVE_LOCK_UNLOCK  0x80000004
#define TAPE_DRIVE_REWIND_IMMEDIATE 0x80000008
#define TAPE_DRIVE_SET_BLOCK_SIZE  0x80000010
#define TAPE_DRIVE_LOAD_UNLD_IMMED  0x80000020
#define TAPE_DRIVE_TENSION_IMMED  0x80000040
#define TAPE_DRIVE_LOCK_UNLK_IMMED  0x80000080
#define TAPE_DRIVE_SET_ECC  0x80000100
#define TAPE_DRIVE_SET_COMPRESSION  0x80000200
#define TAPE_DRIVE_SET_PADDING  0x80000400
#define TAPE_DRIVE_SET_REPORT_SMKS  0x80000800
#define TAPE_DRIVE_ABSOLUTE_BLK  0x80001000
#define TAPE_DRIVE_ABS_BLK_IMMED  0x80002000
#define TAPE_DRIVE_LOGICAL_BLK  0x80004000
#define TAPE_DRIVE_LOG_BLK_IMMED  0x80008000
#define TAPE_DRIVE_END_OF_DATA  0x80010000
#define TAPE_DRIVE_RELATIVE_BLKS  0x80020000
#define TAPE_DRIVE_FILEMARKS  0x80040000
#define TAPE_DRIVE_SEQUENTIAL_FMKS  0x80080000
#define TAPE_DRIVE_SETMARKS  0x80100000
#define TAPE_DRIVE_SEQUENTIAL_SMKS  0x80200000
#define TAPE_DRIVE_REVERSE_POSITION 0x80400000
#define TAPE_DRIVE_SPACE_IMMEDIATE  0x80800000
#define TAPE_DRIVE_WRITE_SETMARKS  0x81000000
#define TAPE_DRIVE_WRITE_FILEMARKS  0x82000000
#define TAPE_DRIVE_WRITE_SHORT_FMKS 0x84000000
#define TAPE_DRIVE_WRITE_LONG_FMKS  0x88000000
#define TAPE_DRIVE_WRITE_MARK_IMMED 0x90000000
#define TAPE_DRIVE_FORMAT  0xA0000000
#define TAPE_DRIVE_FORMAT_IMMEDIATE 0xC0000000
#define TAPE_DRIVE_HIGH_FEATURES  0x80000000

#define TAPE_FIXED_PARTITIONS  0
#define TAPE_SELECT_PARTITIONS  1
#define TAPE_INITIATOR_PARTITIONS  2

LIST_ENTRY STRUCT
	Flink PTR
	Blink PTR
ENDS

SINGLE_LIST_ENTRY STRUCT
	Next PTR
ENDS

LIST_ENTRY32 STRUCT
	Flink DD
	Blink DD
ENDS

LIST_ENTRY64 STRUCT
	Flink DQ
	Blink DQ
ENDS

OBJECTID STRUCT
	Lineage GUID
	Uniquifier DD
ENDS

GetFiberData=fs mov eax,[0x10] \
			mov eax,[eax]

GetCurrentFiber=fs mov eax,[0x10]

#define SIZE_OF_80387_REGISTERS  80

#define CONTEXT_i386 0x00010000
#define CONTEXT_i486 0x00010000
#define CONTEXT_AMD64 0x100000
#define CONTEXT_IA64 0x00080000

#define MAXIMUM_SUPPORTED_EXTENSION  512

M128A STRUCT
	Low DQ
	High DQ
ENDS

XMM_SAVE_AREA32 STRUCT
	ControlWord DW
	StatusWord DW
	TagWord DB
	Reserved1 DB
	ErrorOpcode DW
	ErrorOffset DD
	ErrorSelector DW
	Reserved2 DW
	DataOffset DD
	DataSelector DW
	Reserved3 DW
	MxCsr DD
	MxCsr_Mask DD
	FloatRegisters DB 16*8 DUP ; M128A
	XmmRegisters DB 16*16 DUP ; M128A
	Reserved4 DB 96 DUP
ENDS

#define LEGACY_SAVE_AREA_LENGTH sizeof XMM_SAVE_AREA32

FLOATING_SAVE_AREA STRUCT
	ControlWord DD
	StatusWord DD
	TagWord DD
 	ErrorOffset DD
	ErrorSelector DD
	DataOffset DD
	DataSelector DD
	RegisterArea DB SIZE_OF_80387_REGISTERS DUP
	Cr0NpxState DD
ENDS

#IF X64

#define EXCEPTION_READ_FAULT 0          // exception caused by a read
#define EXCEPTION_WRITE_FAULT 1         // exception caused by a write
#define EXCEPTION_EXECUTE_FAULT 8       // exception caused by an instruction fetch

#define CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1)
#define CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2)
#define CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4)
#define CONTEXT_FLOATING_POINT  (CONTEXT_AMD64 | 0x8)
#define CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x10)

#define CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT)

#define CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_POINT | CONTEXT_DEBUG_REGISTERS)

#define CONTEXT_EXCEPTION_ACTIVE 0x8000000
#define CONTEXT_SERVICE_ACTIVE 0x10000000
#define CONTEXT_EXCEPTION_REQUEST 0x40000000
#define CONTEXT_EXCEPTION_REPORTING 0x80000000

CONTEXT STRUCT

    //
    // Register parameter home addresses.
    //
    // N.B. These fields are for convience - they could be used to extend the
    //      context record in the future.
    //

	P1Home DQ
	P2Home DQ
	P3Home DQ
	P4Home DQ
	P5Home DQ
	P6Home DQ

    //
    // Control flags.
    //

	ContextFlags DD
	MxCsr DD

    //
    // Segment Registers and processor flags.
    //

	SegCs DW
	SegDs DW
	SegEs DW
	SegFs DW
	SegGs DW
	SegSs DW
	EFlags DD

    //
    // Debug registers
    //

	Dr0 DQ
	Dr1 DQ
	Dr2 DQ
	Dr3 DQ
	Dr6 DQ
	Dr7 DQ

    //
    // Integer registers.
    //

	Rax DQ
	Rcx DQ
	Rdx DQ
	Rbx DQ
	Rsp DQ
	Rbp DQ
	Rsi DQ
	Rdi DQ
	R8 DQ
	R9 DQ
	R10 DQ
	R11 DQ
	R12 DQ
	R13 DQ
	R14 DQ
	R15 DQ

    //
    // Program counter.
    //

	Rip DQ

    //
    // Floating point state.
    //

	UNION
		FltSave XMM_SAVE_AREA32
		STRUCT
			Header DB 16*2 DUP ; M128A
			Legacy DB 16*8 DUP ; M128A
			Xmm0 M128A
			Xmm1 M128A
			Xmm2 M128A
			Xmm3 M128A
			Xmm4 M128A
			Xmm5 M128A
			Xmm6 M128A
			Xmm7 M128A
			Xmm8 M128A
			Xmm9 M128A
			Xmm10 M128A
			Xmm11 M128A
			Xmm12 M128A
			Xmm13 M128A
			Xmm14 M128A
			Xmm15 M128A
		ENDS
	ENDUNION

    //
    // Vector registers.
    //

	VectorRegister DB 16*26 DUP ; M128A
	VectorControl DQ

    //
    // Special debug control registers.
    //

	DebugControl DQ
	LastBranchToRip DQ
	LastBranchFromRip DQ
	LastExceptionToRip DQ
	LastExceptionFromRip DQ
ENDS

KNONVOLATILE_CONTEXT_POINTERS STRUCT
	UNION
		FloatingContext PTR 16 DUP
        STRUCT
			Xmm0 PTR
			Xmm1 PTR
			Xmm2 PTR
			Xmm3 PTR
			Xmm4 PTR
			Xmm5 PTR
			Xmm6 PTR
			Xmm7 PTR
			Xmm8 PTR
			Xmm9 PTR
			Xmm10 PTR
			Xmm11 PTR
			Xmm12 PTR
			Xmm13 PTR
			Xmm14 PTR
			Xmm15 PTR
		ENDS
	ENDUNION

	UNION
		IntegerContext PTR 16 DUP
		STRUCT
			Rax PTR
			Rcx PTR
			Rdx PTR
			Rbx PTR
			Rsp PTR
			Rbp PTR
			Rsi PTR
			Rdi PTR
			R8 PTR
			R9 PTR
			R10 PTR
			R11 PTR
			R12 PTR
			R13 PTR
			R14 PTR
			R15 PTR
		ENDS
	ENDUNION
ENDS

#ELSE

#IFDEF IA64
	
	#define EXCEPTION_READ_FAULT          0 // Access violation was caused by a read
	#define EXCEPTION_WRITE_FAULT         1 // Access violation was caused by a write
	#define EXCEPTION_EXECUTE_FAULT       2 // Access violation was caused by an instruction fetch

	#define CONTEXT_CONTROL                 (CONTEXT_IA64 | 0x00000001)
	#define CONTEXT_LOWER_FLOATING_POINT    (CONTEXT_IA64 | 0x00000002)
	#define CONTEXT_HIGHER_FLOATING_POINT   (CONTEXT_IA64 | 0x00000004)
	#define CONTEXT_INTEGER                 (CONTEXT_IA64 | 0x00000008)
	#define CONTEXT_DEBUG                   (CONTEXT_IA64 | 0x00000010)
	#define CONTEXT_IA32_CONTROL            (CONTEXT_IA64 | 0x00000020)  // Includes StIPSR
	
	#define CONTEXT_FLOATING_POINT          (CONTEXT_LOWER_FLOATING_POINT | CONTEXT_HIGHER_FLOATING_POINT)
	#define CONTEXT_FULL                    (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)
	#define CONTEXT_ALL                     (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER | CONTEXT_DEBUG | CONTEXT_IA32_CONTROL)
	
	#define CONTEXT_EXCEPTION_ACTIVE        0x8000000
	#define CONTEXT_SERVICE_ACTIVE          0x10000000
	#define CONTEXT_EXCEPTION_REQUEST       0x40000000
	#define CONTEXT_EXCEPTION_REPORTING     0x80000000
	
	
	CONTEXT STRUCT
	
	    //
	    // The flags values within this flag control the contents of
	    // a CONTEXT record.
	    //
	    // If the context record is used as an input parameter, then
	    // for each portion of the context record controlled by a flag
	    // whose value is set, it is assumed that that portion of the
	    // context record contains valid context. If the context record
	    // is being used to modify a thread's context, then only that
	    // portion of the threads context will be modified.
	    //
	    // If the context record is used as an IN OUT parameter to capture
	    // the context of a thread, then only those portions of the thread's
	    // context corresponding to set flags will be returned.
	    //
	    // The context record is never used as an OUT only parameter.
	    //
	
		ContextFlags DD
		Fill1 DD 3 DUP         // for alignment of following on 16-byte boundary
	
	    //
	    // This section is specified/returned if the ContextFlags word contains
	    // the flag CONTEXT_DEBUG.
	    //
	    // N.B. CONTEXT_DEBUG is *not* part of CONTEXT_FULL.
	    //
	
		DbI0 DQ
		DbI1 DQ
		DbI2 DQ
		DbI3 DQ
		DbI4 DQ
		DbI5 DQ
		DbI6 DQ
		DbI7 DQ
	
		DbD0 DQ
		DbD1 DQ
		DbD2 DQ
		DbD3 DQ
		DbD4 DQ
		DbD5 DQ
		DbD6 DQ
		DbD7 DQ
	
	    //
	    // This section is specified/returned if the ContextFlags word contains
	    // the flag CONTEXT_LOWER_FLOATING_POINT.
	    //
	
		FltS0 FLOAT128
		FltS1 FLOAT128
		FltS2 FLOAT128
		FltS3 FLOAT128
		FltT0 FLOAT128
		FltT1 FLOAT128
		FltT2 FLOAT128
		FltT3 FLOAT128
		FltT4 FLOAT128
		FltT5 FLOAT128
		FltT6 FLOAT128
		FltT7 FLOAT128
		FltT8 FLOAT128
		FltT9 FLOAT128
	
	    //
	    // This section is specified/returned if the ContextFlags word contains
	    // the flag CONTEXT_HIGHER_FLOATING_POINT.
	    //
	
		FltS4 FLOAT128
		FltS5 FLOAT128
		FltS6 FLOAT128
		FltS7 FLOAT128
		FltS8 FLOAT128
		FltS9 FLOAT128
		FltS10 FLOAT128
		FltS11 FLOAT128
		FltS12 FLOAT128
		FltS13 FLOAT128
		FltS14 FLOAT128
		FltS15 FLOAT128
		FltS16 FLOAT128
		FltS17 FLOAT128
		FltS18 FLOAT128
		FltS19 FLOAT128
	
		FltF32 FLOAT128
		FltF33 FLOAT128
		FltF34 FLOAT128
		FltF35 FLOAT128
		FltF36 FLOAT128
		FltF37 FLOAT128
		FltF38 FLOAT128
		FltF39 FLOAT128
	
		FltF40 FLOAT128
		FltF41 FLOAT128
		FltF42 FLOAT128
		FltF43 FLOAT128
		FltF44 FLOAT128
		FltF45 FLOAT128
		FltF46 FLOAT128
		FltF47 FLOAT128
		FltF48 FLOAT128
		FltF49 FLOAT128
	
		FltF50 FLOAT128
		FltF51 FLOAT128
		FltF52 FLOAT128
		FltF53 FLOAT128
		FltF54 FLOAT128
		FltF55 FLOAT128
		FltF56 FLOAT128
		FltF57 FLOAT128
		FltF58 FLOAT128
		FltF59 FLOAT128
	
		FltF60 FLOAT128
		FltF61 FLOAT128
		FltF62 FLOAT128
		FltF63 FLOAT128
		FltF64 FLOAT128
		FltF65 FLOAT128
		FltF66 FLOAT128
		FltF67 FLOAT128
		FltF68 FLOAT128
		FltF69 FLOAT128
	
		FltF70 FLOAT128
		FltF71 FLOAT128
		FltF72 FLOAT128
		FltF73 FLOAT128
		FltF74 FLOAT128
		FltF75 FLOAT128
		FltF76 FLOAT128
		FltF77 FLOAT128
		FltF78 FLOAT128
		FltF79 FLOAT128
	
		FltF80 FLOAT128
		FltF81 FLOAT128
		FltF82 FLOAT128
		FltF83 FLOAT128
		FltF84 FLOAT128
		FltF85 FLOAT128
		FltF86 FLOAT128
		FltF87 FLOAT128
		FltF88 FLOAT128
		FltF89 FLOAT128
	
		FltF90 FLOAT128
		FltF91 FLOAT128
		FltF92 FLOAT128
		FltF93 FLOAT128
		FltF94 FLOAT128
		FltF95 FLOAT128
		FltF96 FLOAT128
		FltF97 FLOAT128
		FltF98 FLOAT128
		FltF99 FLOAT128
	
		FltF100 FLOAT128
		FltF101 FLOAT128
		FltF102 FLOAT128
		FltF103 FLOAT128
		FltF104 FLOAT128
		FltF105 FLOAT128
		FltF106 FLOAT128
		FltF107 FLOAT128
		FltF108 FLOAT128
		FltF109 FLOAT128
	
		FltF110 FLOAT128
		FltF111 FLOAT128
		FltF112 FLOAT128
		FltF113 FLOAT128
		FltF114 FLOAT128
		FltF115 FLOAT128
		FltF116 FLOAT128
		FltF117 FLOAT128
		FltF118 FLOAT128
		FltF119 FLOAT128
	
		FltF120 FLOAT128
		FltF121 FLOAT128
		FltF122 FLOAT128
		FltF123 FLOAT128
		FltF124 FLOAT128
		FltF125 FLOAT128
		FltF126 FLOAT128
		FltF127 FLOAT128
	
	    //
	    // This section is specified/returned if the ContextFlags word contains
	    // the flag CONTEXT_LOWER_FLOATING_POINT | CONTEXT_HIGHER_FLOATING_POINT | CONTEXT_CONTROL.
	    //
	
		StFPSR DQ       //  FP status
	
	    //
	    // This section is specified/returned if the ContextFlags word contains
	    // the flag CONTEXT_INTEGER.
	    //
	    // N.B. The registers gp, sp, rp are part of the control context
	    //
	
		IntGp DQ        //  r1, volatile
		IntT0 DQ        //  r2-r3, volatile
		IntT1 DQ        //
		IntS0 DQ        //  r4-r7, preserved
		IntS1 DQ
		IntS2 DQ
		IntS3 DQ
		IntV0 DQ        //  r8, volatile
		IntT2 DQ        //  r9-r11, volatile
		IntT3 DQ
		IntT4 DQ
		IntSp DQ        //  stack pointer (r12), special
		IntTeb DQ       //  teb (r13), special
		IntT5 DQ        //  r14-r31, volatile
		IntT6 DQ
		IntT7 DQ
		IntT8 DQ
		IntT9 DQ
		IntT10 DQ
		IntT11 DQ
		IntT12 DQ
		IntT13 DQ
		IntT14 DQ
		IntT15 DQ
		IntT16 DQ
		IntT17 DQ
		IntT18 DQ
		IntT19 DQ
		IntT20 DQ
		IntT21 DQ
		IntT22 DQ
	
		IntNats DQ      //  Nat bits for r1-r31
	                            //  r1-r31 in bits 1 thru 31.
		Preds DQ        //  predicates, preserved
	
		BrRp DQ         //  return pointer, b0, preserved
		BrS0 DQ         //  b1-b5, preserved
		BrS1 DQ
		BrS2 DQ
		BrS3 DQ
		BrS4 DQ
		BrT0 DQ         //  b6-b7, volatile
		BrT1 DQ
	
	    //
	    // This section is specified/returned if the ContextFlags word contains
	    // the flag CONTEXT_CONTROL.
	    //
	
	    // Other application registers
		ApUNAT DQ       //  User Nat collection register, preserved
		ApLC DQ         //  Loop counter register, preserved
		ApEC DQ         //  Epilog counter register, preserved
		ApCCV DQ        //  CMPXCHG value register, volatile
		ApDCR DQ        //  Default control register (TBD)
	
	    // Register stack info
		RsPFS DQ        //  Previous function state, preserved
		RsBSP DQ        //  Backing store pointer, preserved
		RsBSPSTORE DQ
		RsRSC DQ        //  RSE configuration, volatile
		RsRNAT DQ       //  RSE Nat collection register, preserved
	
	    // Trap Status Information
		StIPSR DQ       //  Interruption Processor Status
		StIIP DQ        //  Interruption IP
		StIFS DQ        //  Interruption Function State
	
	    // iA32 related control registers
		StFCR DQ        //  copy of Ar21
		Eflag DQ        //  Eflag copy of Ar24
		SegCSD DQ       //  iA32 CSDescriptor (Ar25)
		SegSSD DQ       //  iA32 SSDescriptor (Ar26)
		Cflag DQ        //  Cr0+Cr4 copy of Ar27
		StFSR DQ        //  x86 FP status (copy of AR28)
		StFIR DQ        //  x86 FP status (copy of AR29)
		StFDR DQ        //  x86 FP status (copy of AR30)
	
		UNUSEDPACK DQ   //  added to pack StFDR to 16-bytes
	
	ENDS
#ELSE
	
	#define EXCEPTION_READ_FAULT          0 // Access violation was caused by a read
	#define EXCEPTION_WRITE_FAULT         1 // Access violation was caused by a write
	#define EXCEPTION_EXECUTE_FAULT       8 // Access violation was caused by an instruction fetch
	
	#define CONTEXT_CONTROL  (CONTEXT_i386|0x00000001)
	#define CONTEXT_INTEGER  (CONTEXT_i386|0x00000002)
	#define CONTEXT_SEGMENTS  (CONTEXT_i386|0x00000004)
	#define CONTEXT_FLOATING_POINT  (CONTEXT_i386|0x00000008)
	#define CONTEXT_DEBUG_REGISTERS  (CONTEXT_i386|0x00000010)
	#define CONTEXT_EXTENDED_REGISTERS  (CONTEXT_i386|0x00000020)
	#define CONTEXT_FULL (CONTEXT_CONTROL|CONTEXT_INTEGER|CONTEXT_SEGMENTS)
	#define CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_POINT | CONTEXT_DEBUG_REGISTERS | CONTEXT_EXTENDED_REGISTERS)


	CONTEXT STRUCT
		ContextFlags DD
		Dr0 DD
		Dr1 DD
		Dr2 DD
		Dr3 DD
		Dr6 DD
		Dr7 DD
		FloatSave FLOATING_SAVE_AREA
		SegGs DD
		SegFs DD
		SegEs DD
		SegDs DD
		Edi DD
		Esi DD
		Ebx DD
		Edx DD
		Ecx DD
		Eax DD
		Ebp DD
		Eip DD
		SegCs DD
		EFlags DD
		Esp DD
		SegSs DD
		ExtendedRegisters DB MAXIMUM_SUPPORTED_EXTENSION DUP
	ENDS
#ENDIF

#ENDIF

EXCEPTION_RECORD STRUCT
	ExceptionCode DD
	ExceptionFlags DD
    ExceptionRecord DD
	ExceptionAddress DD
	NumberParameters DD
	ExceptionInformation DD EXCEPTION_MAXIMUM_PARAMETERS DUP
ENDS

EXCEPTION_RECORD32 STRUCT
	ExceptionCode DD
	ExceptionFlags DD
	ExceptionRecord DD
	ExceptionAddress DD
	NumberParameters DD
	ExceptionInformation DD EXCEPTION_MAXIMUM_PARAMETERS DUP
ENDS

EXCEPTION_RECORD64 STRUCT
	ExceptionCode DD
	ExceptionFlags DD
	ExceptionRecord DQ
	ExceptionAddress DQ
	NumberParameters DD
	__unusedAlignment DD
	ExceptionInformation DQ EXCEPTION_MAXIMUM_PARAMETERS DUP
ENDS

EXCEPTION_POINTERS STRUCT
	ExceptionRecord PTR
	ContextRecord PTR
ENDS

GENERIC_MAPPING STRUCT
	GenericRead DD
	GenericWrite DD
	GenericExecute DD
	GenericAll DD
ENDS

LUID_AND_ATTRIBUTES STRUCT
	Luid LUID
	Attributes DD
ENDS

SID_IDENTIFIER_AUTHORITY STRUCT
	Value DB 6 DUP
ENDS

SID STRUCT
	Revision DB
	SubAuthorityCount DB
	IdentifierAuthority SID_IDENTIFIER_AUTHORITY
	SubAuthority DD
ENDS

#define SidTypeUser 1
#define SidTypeGroup 2
#define SidTypeDomain 3
#define SidTypeAlias 4
#define SidTypeWellKnownGroup 5
#define SidTypeDeletedAccount 6
#define SidTypeInvalid 7
#define SidTypeUnknown 8
#define SidTypeComputer 9

////////////////////////////////////////////////////////////////////////
//                                                                    //
//                             ACCESS MASK                            //
//                                                                    //
////////////////////////////////////////////////////////////////////////

//
//  Define the access mask as a longword sized structure divided up as
//  follows:
//
//       3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//       1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//      +---------------+---------------+-------------------------------+
//      |G|G|G|G|Res'd|A| StandardRights|         SpecificRights        |
//      |R|W|E|A|     |S|               |                               |
//      +-+-------------+---------------+-------------------------------+
//
//      typedef struct _ACCESS_MASK {
//          WORD   SpecificRights;
//          BYTE  StandardRights;
//          BYTE  AccessSystemAcl : 1;
//          BYTE  Reserved : 3;
//          BYTE  GenericAll : 1;
//          BYTE  GenericExecute : 1;
//          BYTE  GenericWrite : 1;
//          BYTE  GenericRead : 1;
//      } ACCESS_MASK;
//      typedef ACCESS_MASK *PACCESS_MASK;
//
//  but to make life simple for programmer's we'll allow them to specify
//  a desired access mask by simply OR'ing together mulitple single rights
//  and treat an access mask as a DWORD.  For example
//
//      DesiredAccess = DELETE | READ_CONTROL
//
//  So we'll declare ACCESS_MASK as DWORD
//

#DEFINE ACCESS_MASK DD

SID_AND_ATTRIBUTES STRUCT
	Sid DD
	Attributes DD
ENDS

SID_AND_ATTRIBUTES_HASH STRUCT
	SidCount DD
	SidAttr PTR
	Hash ULONG_PTR SID_HASH_SIZE DUP
ENDS

ACL STRUCT
	AclRevision DB
	Sbz1 DB
	AclSize DW
	AceCount DW
	Sbz2 DW
ENDS

ACE_HEADER STRUCT
	AceType DB
	AceFlags DB
	AceSize DW
ENDS

ACCESS_ALLOWED_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	SidStart DD
ENDS

ACCESS_DENIED_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	SidStart DD
ENDS

SYSTEM_AUDIT_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	SidStart DD
ENDS

SYSTEM_ALARM_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	SidStart DD
ENDS

SYSTEM_MANDATORY_LABEL_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	SidStart DD
ENDS

ACCESS_ALLOWED_OBJECT_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	Flags DD
	ObjectType GUID
	InheritedObjectType  GUID
	SidStart DD
ENDS

ACCESS_DENIED_OBJECT_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	Flags DD
	ObjectType GUID
	InheritedObjectType  GUID
	SidStart DD
ENDS

SYSTEM_AUDIT_OBJECT_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	Flags DD
	ObjectType GUID
	InheritedObjectType  GUID
	SidStart DD
ENDS

SYSTEM_ALARM_OBJECT_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	Flags DD
	ObjectType GUID
	InheritedObjectType  GUID
	SidStart DD
ENDS

ACCESS_ALLOWED_CALLBACK_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	SidStart DD
    // Opaque resouce manager specific data
ENDS

ACCESS_DENIED_CALLBACK_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	SidStart DD
    // Opaque resouce manager specific data
ENDS

SYSTEM_AUDIT_CALLBACK_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	SidStart DD
    // Opaque resouce manager specific data
ENDS

SYSTEM_ALARM_CALLBACK_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	SidStart DD
    // Opaque resouce manager specific data
ENDS

ACCESS_ALLOWED_CALLBACK_OBJECT_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	Flags DD
	ObjectType GUID
	InheritedObjectType  GUID
	SidStart DD
    // Opaque resouce manager specific data
ENDS

ACCESS_DENIED_CALLBACK_OBJECT_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	Flags DD
	ObjectType GUID
	InheritedObjectType  GUID
	SidStart DD
    // Opaque resouce manager specific data
ENDS

SYSTEM_AUDIT_CALLBACK_OBJECT_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	Flags DD
	ObjectType GUID
	InheritedObjectType  GUID
	SidStart DD
    // Opaque resouce manager specific data
ENDS

SYSTEM_ALARM_CALLBACK_OBJECT_ACE STRUCT
	Header ACE_HEADER
	Mask DD
	Flags DD
	ObjectType GUID
	InheritedObjectType  GUID
	SidStart DD
    // Opaque resouce manager specific data
ENDS

#define AclRevisionInformation 1
#define AclSizeInformation 2

ACL_REVISION_INFORMATION STRUCT
	AclRevision DD
ENDS

ACL_SIZE_INFORMATION STRUCT
	AceCount DD
	AclBytesInUse DD
	AclBytesFree DD
ENDS

SECURITY_DESCRIPTOR_RELATIVE STRUCT
	Revision DB
	Sbz1 DB
	Control DW
	Owner DD
	Group DD
	Sacl DD
	Dacl DD
ENDS

SECURITY_DESCRIPTOR STRUCT
	Revision DB
	Sbz1 DB
	Control DW
	Owner PTR
	Group PTR
	Sacl PTR
	Dacl PTR
ENDS

OBJECT_TYPE_LIST STRUCT
	Level DW
	Sbz DW
	ObjectType PTR
ENDS

#define AuditEventObjectAccess 0
#define AuditEventDirectoryServiceAccess 1

PRIVILEGE_SET STRUCT
	PrivilegeCount DD
	Control DD
    Privilege LUID_AND_ATTRIBUTES
ENDS

#define SecurityAnonymous 0
#define SecurityIdentification 1
#define SecurityImpersonation 2
#define SecurityDelegation 3

#define TokenPrimary 1
#define TokenImpersonation 2

TokenElevationTypeDefault = 1
TokenElevationTypeFull = 2
TokenElevationTypeLimited = 3

#define TokenUser 1
#define TokenGroups 2
#define TokenPrivileges 3
#define TokenOwner 4
#define TokenPrimaryGroup 5
#define TokenDefaultDacl 6
#define TokenSource 7
#define TokenType 8
#define TokenImpersonationLevel 9
#define TokenStatistics 10
#define TokenRestrictedSids 11
#define TokenSessionId 12
#define TokenGroupsAndPrivileges 13
#define TokenSessionReference 14
#define TokenSandBoxInert 15
#define TokenAuditPolicy 16
#define TokenOrigin 17
#define TokenElevationType 18
#define TokenLinkedToken 19
#define TokenElevation 20
#define TokenHasRestrictions 21
#define TokenAccessInformation 22
#define TokenVirtualizationAllowed 23
#define TokenVirtualizationEnabled 24
#define TokenIntegrityLevel 25
#define TokenUIAccess 26
#define TokenMandatoryPolicy 27
#define TokenLogonSid 28
#define MaxTokenInfoClass 29

TOKEN_USER STRUCT
	User SID_AND_ATTRIBUTES
ENDS

TOKEN_GROUPS STRUCT
	GroupCount DD
	Groups SID_AND_ATTRIBUTES
ENDS

TOKEN_PRIVILEGES STRUCT
	PrivilegeCount DD
	Privileges LUID_AND_ATTRIBUTES
ENDS

TOKEN_OWNER STRUCT
	Owner PTR
ENDS

TOKEN_PRIMARY_GROUP STRUCT
	PrimaryGroup PTR
ENDS

TOKEN_GROUPS_AND_PRIVILEGES STRUCT
	SidCount DD
	SidLength DD
	Sids PTR
	RestrictedSidCount DD
	RestrictedSidLength DD
	RestrictedSids PTR
	PrivilegeCount DD
	PrivilegeLength DD
	Privileges PTR
	AuthenticationId LUID
ENDS

TOKEN_LINKED_TOKEN STRUCT
	LinkedToken HANDLE
ENDS

TOKEN_ELEVATION STRUCT
	TokenIsElevated DD
ENDS

TOKEN_MANDATORY_LABEL STRUCT
	Label SID_AND_ATTRIBUTES
ENDS

TOKEN_MANDATORY_POLICY STRUCT
	Policy DD
ENDS

TOKEN_ACCESS_INFORMATION STRUCT
	SidHash PTR
	RestrictedSidHash PTR
	Privileges PTR
	AuthenticationId LUID
	TokenType DD
	ImpersonationLevel DD
	MandatoryPolicy DD
	Flags DD
ENDS

TOKEN_DEFAULT_DACL STRUCT
	DefaultDacl PTR
ENDS

TOKEN_AUDIT_POLICY STRUCT
	PerUserPolicy DB ((POLICY_AUDIT_SUBCATEGORY_COUNT) >> 1) + 1 DUP
ENDS

TOKEN_SOURCE STRUCT
	SourceName DB TOKEN_SOURCE_LENGTH DUP
	SourceIdentifier LUID
ENDS

TOKEN_STATISTICS STRUCT
	TokenId LUID
	AuthenticationId LUID
	ExpirationTime LARGE_INTEGER
	TokenType DD
	ImpersonationLevel DD
	DynamicCharged DD
	DynamicAvailable DD
	GroupCount DD
	PrivilegeCount DD
	ModifiedId LUID
ENDS

TOKEN_CONTROL STRUCT
	TokenId LUID
	AuthenticationId LUID
	ModifiedId LUID
	TokenSource TOKEN_SOURCE
ENDS

TOKEN_ORIGIN STRUCT
	OriginatingLogonSession LUID
ENDS

MandatoryLevelUntrusted = 0
MandatoryLevelLow = 1
MandatoryLevelMedium = 2
MandatoryLevelHigh = 3
MandatoryLevelSystem = 4
MandatoryLevelSecureProcess = 5
MandatoryLevelCount = 6

SECURITY_QUALITY_OF_SERVICE STRUCT
	Length DD
	ImpersonationLevel DD
	ContextTrackingMode DB
	EffectiveOnly DB
ENDS

SE_IMPERSONATION_STATE STRUCT
	Token PTR
	CopyOnOpen DB
	EffectiveOnly DB
	Level DD
ENDS

/*
NT_TIB STRUCT
	ExceptionList PTR
	StackBase PTR
	StackLimit PTR
	SubSystemTib PTR
	UNION
		FiberData PTR
		Version DD
	ENDUNION
	ArbitraryUserPointer PTR
	Self PTR
ENDS
*/

NT_TIB32 STRUCT
	ExceptionList DD
	StackBase DD
	StackLimit DD
	SubSystemTib DD
	UNION
		FiberData DD
		Version DD
	ENDUNION
	ArbitraryUserPointer DD
	Self DD
ENDS

NT_TIB64 STRUCT
	ExceptionList DQ
	StackBase DQ
	StackLimit DQ
	SubSystemTib DQ
	UNION
		FiberData DQ
		Version DD
	ENDUNION
	ArbitraryUserPointer DQ
	Self DQ
ENDS

#IF !X64
	#define NT_TIB NT_TIB32
#ELSE
	#define NT_TIB NT_TIB64
#ENDIF

#IFNDEF QUOTA_LIMITS
QUOTA_LIMITS STRUCT
	PagedPoolLimit SIZE_T
	NonPagedPoolLimit SIZE_T
	MinimumWorkingSetSize SIZE_T
	MaximumWorkingSetSize SIZE_T
	PagefileLimit SIZE_T
	TimeLimit LARGE_INTEGER
ENDS
#ENDIF

#IFNDEF RATE_QUOTA_LIMIT
RATE_QUOTA_LIMIT UNION
	RateData DD
	RatePercent DD
ENDUNION

QUOTA_LIMITS_EX STRUCT
	PagedPoolLimit SIZE_T
	NonPagedPoolLimit SIZE_T
	MinimumWorkingSetSize SIZE_T
	MaximumWorkingSetSize SIZE_T
	PagefileLimit SIZE_T               // Limit expressed in pages
	TimeLimit LARGE_INTEGER
	WorkingSetLimit SIZE_T             // Limit expressed in pages
	Reserved2 SIZE_T
	Reserved3 SIZE_T
	Reserved4 SIZE_T
	Flags DD
	CpuRateLimit RATE_QUOTA_LIMIT
ENDS
#ENDIF

#IFNDEF IO_COUNTERS
IO_COUNTERS STRUCT
	ReadOperationCount DQ
	WriteOperationCount DQ
	OtherOperationCount DQ
	ReadTransferCount DQ
	WriteTransferCount DQ
	OtherTransferCount DQ
ENDS
#ENDIF

JOBOBJECT_BASIC_ACCOUNTING_INFORMATION STRUCT
	TotalUserTime LARGE_INTEGER
	TotalKernelTime LARGE_INTEGER
	ThisPeriodTotalUserTime LARGE_INTEGER
	ThisPeriodTotalKernelTime LARGE_INTEGER
	TotalPageFaultCount DD
	TotalProcesses DD
	ActiveProcesses DD
	TotalTerminatedProcesses DD
ENDS

JOBOBJECT_BASIC_LIMIT_INFORMATION STRUCT
	PerProcessUserTimeLimit LARGE_INTEGER
	PerJobUserTimeLimit LARGE_INTEGER
	LimitFlags DD
	MinimumWorkingSetSize SIZE_T
	MaximumWorkingSetSize SIZE_T
	ActiveProcessLimit DD
	Affinity ULONG_PTR
	PriorityClass DD
	SchedulingClass DD
ENDS

JOBOBJECT_EXTENDED_LIMIT_INFORMATION STRUCT
	BasicLimitInformation JOBOBJECT_BASIC_LIMIT_INFORMATION
	IoInfo IO_COUNTERS
	ProcessMemoryLimit SIZE_T
	JobMemoryLimit SIZE_T
	PeakProcessMemoryUsed SIZE_T
	PeakJobMemoryUsed SIZE_T
ENDS

JOBOBJECT_BASIC_PROCESS_ID_LIST STRUCT
	NumberOfAssignedProcesses DD
	NumberOfProcessIdsInList DD
	ProcessIdList ULONG_PTR
ENDS

JOBOBJECT_BASIC_UI_RESTRICTIONS STRUCT
	UIRestrictionsClass DD
ENDS

JOBOBJECT_SECURITY_LIMIT_INFORMATION STRUCT
	SecurityLimitFlags DD
	JobToken HANDLE
	SidsToDisable PTR
	PrivilegesToDelete PTR
	RestrictedSids PTR
ENDS

JOBOBJECT_END_OF_JOB_TIME_INFORMATION STRUCT
	EndOfJobTimeAction DD
ENDS

JOBOBJECT_ASSOCIATE_COMPLETION_PORT STRUCT
	CompletionKey DD
	CompletionPort DD
ENDS

JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION STRUCT
	BasicInfo JOBOBJECT_BASIC_ACCOUNTING_INFORMATION
	IoInfo IO_COUNTERS
ENDS

JOBOBJECT_JOBSET_INFORMATION STRUCT
	MemberLevel DD
ENDS

#define JobObjectBasicAccountingInformation 1
#define JobObjectBasicLimitInformation 2
#define JobObjectBasicProcessIdList 3
#define JobObjectBasicUIRestrictions 4
#define JobObjectSecurityLimitInformation 5
#define JobObjectEndOfJobTimeInformation 6
#define JobObjectAssociateCompletionPortInformation 7
#define JobObjectBasicAndIoAccountingInformation 8
#define JobObjectExtendedLimitInformation 9
#define JobObjectJobSetInformation 10
#define MaxJobObjectInfoClass 11

RelationProcessorCore = 0
RelationNumaNode = 1
RelationCache = 2
RelationProcessorPackage = 3

CacheUnified = 0
CacheInstruction = 1
CacheData = 2
CacheTrace = 3

#define LTP_PC_SMT 0x1
#define CACHE_FULLY_ASSOCIATIVE 0xFF

CACHE_DESCRIPTOR STRUCT
	Level DB
	Associativity DB
	LineSize DW
	Size DD
	Type DD
ENDS

SYSTEM_LOGICAL_PROCESSOR_INFORMATION STRUCT
	ProcessorMask ULONG_PTR
	Relationship DD
	UNION
		ProcessorCore STRUCT
			Flags DB
		ENDS
		NumaNode STRUCT
			NodeNumber DD
		ENDS
		Cache CACHE_DESCRIPTOR
		Reserved DQ 2 DUP
	ENDUNION
ENDS

MEMORY_BASIC_INFORMATION STRUCT
	BaseAddress PTR
	AllocationBase PTR
	AllocationProtect DD
	RegionSize SIZE_T
	State DD
	Protect DD
	Type DD
ENDS

MEMORY_BASIC_INFORMATION32 STRUCT
	BaseAddress DD
	AllocationBase DD
	AllocationProtect DD
	RegionSize DD
	State DD
	Protect DD
	Type DD
ENDS

MEMORY_BASIC_INFORMATION64 STRUCT
	BaseAddress DQ
	AllocationBase DQ
	AllocationProtect DD
	__alignment1 DD
	RegionSize DQ
	State DD
	Protect DD
	Type DD
	__alignment2 DD
ENDS

FILE_NOTIFY_INFORMATION STRUCT
	NextEntryOffset DD
	Action DD
	FileNameLength DD
	FileName DW
ENDS

FILE_SEGMENT_ELEMENT STRUCT
	Buffer PTR
	Alignment DQ
ENDS

#define FLUSH_FLAGS_FILE_DATA_ONLY     0x00000001

GREPBUF STRUCT
	DataBuffer PTR
ENDS

REPARSE_GUID_DATA_BUFFER STRUCT
	ReparseTag DD
	ReparseDataLength DW
	Reserved DW
	ReparseGuid GUID
	GenericReparseBuffer GREPBUF
ENDS

#Define LT_DONT_CARE 0
#Define LT_LOWEST_LATENCY 1

#define DIAGNOSTIC_REASON_VERSION              0

#define DIAGNOSTIC_REASON_SIMPLE_STRING        0x00000001
#define DIAGNOSTIC_REASON_DETAILED_STRING      0x00000002
#define DIAGNOSTIC_REASON_NOT_SPECIFIED        0x80000000
#define DIAGNOSTIC_REASON_INVALID_FLAGS        !0x80000003

#define POWER_REQUEST_CONTEXT_VERSION          0

#define POWER_REQUEST_CONTEXT_SIMPLE_STRING    0x00000001
#define POWER_REQUEST_CONTEXT_DETAILED_STRING  0x00000002

PowerRequestDisplayRequired = 0
PowerRequestSystemRequired = 1
PowerRequestAwayModeRequired = 2
#define PowerRequestMaximum 3

PowerSystemUnspecified = 0
PowerSystemWorking     = 1
PowerSystemSleeping1   = 2
PowerSystemSleeping2   = 3
PowerSystemSleeping3   = 4
PowerSystemHibernate   = 5
PowerSystemShutdown    = 6
PowerSystemMaximum     = 7

PowerActionNone = 0
PowerActionReserved = 1
PowerActionSleep = 2
PowerActionHibernate = 3
PowerActionShutdown = 4
PowerActionShutdownReset = 5
PowerActionShutdownOff = 6
PowerActionWarmEject = 7

PowerDeviceUnspecified = 0
PowerDeviceD0 = 1
PowerDeviceD1 = 2
PowerDeviceD2 = 3
PowerDeviceD3 = 4
PowerDeviceMaximum = 5

#define PDCAP_D0_SUPPORTED              0x00000001
#define PDCAP_D1_SUPPORTED              0x00000002
#define PDCAP_D2_SUPPORTED              0x00000004
#define PDCAP_D3_SUPPORTED              0x00000008
#define PDCAP_WAKE_FROM_D0_SUPPORTED    0x00000010
#define PDCAP_WAKE_FROM_D1_SUPPORTED    0x00000020
#define PDCAP_WAKE_FROM_D2_SUPPORTED    0x00000040
#define PDCAP_WAKE_FROM_D3_SUPPORTED    0x00000080
#define PDCAP_WARM_EJECT_SUPPORTED      0x00000100

CM_POWER_DATA STRUCT
	PD_Size DD
	PD_MostRecentPowerState DD
	PD_Capabilities DD
	PD_D1Latency DD
	PD_D2Latency DD
	PD_D3Latency DD
	PD_PowerStateMapping DD POWER_SYSTEM_MAXIMUM DUP
	PD_DeepestSystemWake DD
ENDS

SystemPowerPolicyAc = 0
SystemPowerPolicyDc = 1
VerifySystemPolicyAc = 2
VerifySystemPolicyDc = 3
SystemPowerCapabilities = 4
SystemBatteryState = 5
SystemPowerStateHandler = 6
ProcessorStateHandler = 7
SystemPowerPolicyCurrent = 8
AdministratorPowerPolicy = 9
SystemReserveHiberFile = 10
ProcessorInformation = 11
SystemPowerInformation = 12
ProcessorStateHandler2 = 13
LastWakeTime = 14
LastSleepTime = 15
SystemExecutionState = 16
SystemPowerStateNotifyHandler = 17
ProcessorPowerPolicyAc = 18
ProcessorPowerPolicyDc = 19
VerifyProcessorPowerPolicyAc = 20
VerifyProcessorPowerPolicyDc = 21
ProcessorPowerPolicyCurrent = 22
SystemPowerStateLogging = 23
SystemPowerLoggingEntry = 24
SetPowerSettingValue = 25
NotifyUserPowerSetting = 26
PowerInformationLevelUnused0 = 27
PowerInformationLevelUnused1 = 28
SystemVideoState = 29
TraceApplicationPowerMessage = 30
TraceApplicationPowerMessageEnd = 31
ProcessorPerfStates = 32
ProcessorIdleStates = 33
ProcessorCap = 34
SystemWakeSource = 35
SystemHiberFileInformation = 36
TraceServicePowerMessage = 37
ProcessorLoad = 38
PowerShutdownNotification = 39
MonitorCapabilities = 40
SessionPowerInit = 41
SessionDisplayState = 42
PowerRequestCreate = 43
PowerRequestAction = 44
GetPowerRequestList = 45
ProcessorInformationEx = 46
NotifyUserModeLegacyPowerEvent = 47
GroupPark = 48
ProcessorIdleDomains = 49
WakeTimerList = 50
SystemHiberFileSize = 51
PowerInformationLevelMaximum = 52

#define PO_TRANSITION_VETO_TYPE_WINDOW  0x00000001
#define PO_TRANSITION_VETO_TYPE_SERVICE 0x00000002
#define PO_TRANSITION_VETO_TYPE_DRIVER  0x00000004

#define PO_TRANSITION_VETO_TYPE_ALL (PO_TRANSITION_VETO_TYPE_WINDOW | PO_TRANSITION_VETO_TYPE_SERVICE)

PO_TRANSITION_VETO_REASON STRUCT
	ResourceId DD
	ModuleNameOffset DD
ENDS

PO_TRANSITION_VETO_WINDOW STRUCT
	Handle HANDLE
ENDS

PO_TRANSITION_VETO_SERVICE STRUCT
	ServiceNameOffset DD
ENDS

PO_TRANSITION_VETO_DRIVER STRUCT
	InstancePathOffset DD
	DriverNameOffset DD
ENDS

PO_TRANSITION_VETO STRUCT
	Type DD
	Reason PO_TRANSITION_VETO_REASON
	ProcessId DD
	UNION
		Window PO_TRANSITION_VETO_WINDOW
		Service PO_TRANSITION_VETO_SERVICE
		Driver PO_TRANSITION_VETO_DRIVER
	ENDUNION
ENDS

PO_TRANSITION_VETOES STRUCT
	Count DD
	Vetoes PO_TRANSITION_VETO
ENDS

PoAc = 0
PoDc = 1
PoHot = 2
PoConditionMaximum = 3

SET_POWER_SETTING_VALUE STRUCT
	Version DD
	Guid GUID
	PowerCondition DD
	DataLength DD
	Data DB
ENDS

#define POWER_SETTING_VALUE_VERSION (0x1)

NOTIFY_USER_POWER_SETTING STRUCT
	Guid GUID
ENDS

APPLICATIONLAUNCH_SETTING_VALUE STRUCT
	ActivationTime LARGE_INTEGER
	Flags DD
	ButtonInstanceID DD
ENDS

PlatformRoleUnspecified = 0
PlatformRoleDesktop = 1
PlatformRoleMobile = 2
PlatformRoleWorkstation = 3
PlatformRoleEnterpriseServer = 4
PlatformRoleSOHOServer = 5
PlatformRoleAppliancePC = 6
PlatformRolePerformanceServer = 7
PlatformRoleSlate = 8
PlatformRoleMaximum = 9

#define POWER_PLATFORM_ROLE_V1 1
#define POWER_PLATFORM_ROLE_V1_MAX 8

#define POWER_PLATFORM_ROLE_V2 2
#define POWER_PLATFORM_ROLE_V2_MAX 9


#if WINVER >= NTDDI_WIN8
	#define POWER_PLATFORM_ROLE_VERSION     POWER_PLATFORM_ROLE_V2
	#define POWER_PLATFORM_ROLE_VERSION_MAX POWER_PLATFORM_ROLE_V2_MAX
#else
	#define POWER_PLATFORM_ROLE_VERSION     POWER_PLATFORM_ROLE_V1
	#define POWER_PLATFORM_ROLE_VERSION_MAX POWER_PLATFORM_ROLE_V1_MAX
#endif

POWER_PLATFORM_INFORMATION STRUCT
	Role ENUM
	AoAc BOOLEAN
ENDS

DeviceWakeSourceType = 0
FixedWakeSourceType = 1

FixedWakeSourcePowerButton = 0
FixedWakeSourceSleepButton = 1
FixedWakeSourceRtc = 2

PO_WAKE_SOURCE_HEADER STRUCT
	Type DD
	Size DD
ENDS

PO_WAKE_SOURCE_DEVICE STRUCT
	Header PO_WAKE_SOURCE_HEADER
	InstancePath DW
ENDS

PO_WAKE_SOURCE_FIXED STRUCT
	Header PO_WAKE_SOURCE_HEADER
	FixedWakeSourceType DD
ENDS

PO_WAKE_SOURCE_INFO STRUCT
	Count DD
	Offsets DD
ENDS

PO_WAKE_SOURCE_HISTORY STRUCT
	Count DD
	Offsets DD
ENDS

BATTERY_REPORTING_SCALE STRUCT
	Granularity DD
	Capacity DD
ENDS

PPM_SIMULATED_PROCESSOR_LOAD STRUCT
	Enabled DD
	PercentBusy DB MAXIMUM_PROCESSORS DUP
ENDS

PPM_WMI_LEGACY_PERFSTATE STRUCT
	Frequency DD
	Flags DD
	PercentFrequency DD
ENDS

PPM_WMI_IDLE_STATE STRUCT
	Latency DD
	Power DD
	TimeCheck DD
	PromotePercent DB
	DemotePercent DB
	StateType DB
	Reserved DB
	StateFlags DD
	Context DD
	IdleHandler DD
	Reserved1 DD
ENDS

PPM_WMI_IDLE_STATES STRUCT
	Type DD
	Count DD
	TargetState DD
	OldState DD
	TargetProcessors DQ
	State PPM_WMI_IDLE_STATE
ENDS

PPM_WMI_PERF_STATE STRUCT
	Frequency DD
	Power DD
	PercentFrequency DB
	IncreaseLevel DB
	DecreaseLevel DB
	Type DB
	IncreaseTime DD
	DecreaseTime DD
	Control DQ
	Status DQ
	HitCount DD
	Reserved1 DD
	Reserved2 DQ
	Reserved3 DQ
ENDS

PPM_WMI_PERF_STATES STRUCT
	Count DD
	MaxFrequency DD
	CurrentState DD
	MaxPerfState DD
	MinPerfState DD
	LowestPerfState DD
	ThermalConstraint DD
	BusyAdjThreshold DB
	PolicyType DB
	Type DB
	Reserved DB
	TimerInterval DD
	TargetProcessors DQ
	PStateHandler DD
	PStateContext DD
	TStateHandler DD
	TStateContext DD
	FeedbackHandler DD
	Reserved1 DD
	Reserved2 DQ
	State PPM_WMI_PERF_STATE
ENDS

#define PROC_IDLE_BUCKET_COUNT  6

PPM_IDLE_STATE_ACCOUNTING STRUCT
	IdleTransitions DD
	FailedTransitions DD
	InvalidBucketIndex DD
	TotalTime DQ
	IdleTimeBuckets DD PROC_IDLE_BUCKET_COUNT DUP
ENDS

PPM_IDLE_ACCOUNTING STRUCT
	StateCount DD
	TotalTransitions DD
	ResetCount DD
	StartTime DQ
	State PPM_IDLE_STATE_ACCOUNTING
ENDS

#define ACPI_PPM_SOFTWARE_ALL     0xFC
#define ACPI_PPM_SOFTWARE_ANY     0xFD
#define ACPI_PPM_HARDWARE_ALL     0xFE
#define MS_PPM_SOFTWARE_ALL       0x1

PPM_PERFSTATE_EVENT STRUCT
	State DD
	Status DD
	Latency DD
	Speed DD
	Processor DD
ENDS

PPM_PERFSTATE_DOMAIN_EVENT STRUCT
	State DD
	Latency DD
	Speed DD
	Processors DQ
ENDS

PPM_IDLESTATE_EVENT STRUCT
	NewState DD
	OldState DD
	Processors DQ
ENDS

PPM_THERMALCHANGE_EVENT STRUCT
	ThermalConstraint DD
	Processors DQ
ENDS

PPM_THERMAL_POLICY_EVENT STRUCT
	Mode DB
	Processors DQ
ENDS

POWER_ACTION_POLICY STRUCT
	Action DD
	Flags DD
	EventCode DD
ENDS

#define POWER_ACTION_QUERY_ALLOWED      0x00000001
#define POWER_ACTION_UI_ALLOWED         0x00000002
#define POWER_ACTION_OVERRIDE_APPS      0x00000004
#define POWER_ACTION_PSEUDO_TRANSITION  0x08000000
#define POWER_ACTION_LIGHTEST_FIRST     0x10000000
#define POWER_ACTION_LOCK_CONSOLE       0x20000000
#define POWER_ACTION_DISABLE_WAKES      0x40000000
#define POWER_ACTION_CRITICAL           0x80000000

#define POWER_LEVEL_USER_NOTIFY_TEXT    0x00000001
#define POWER_LEVEL_USER_NOTIFY_SOUND   0x00000002
#define POWER_LEVEL_USER_NOTIFY_EXEC    0x00000004
#define POWER_USER_NOTIFY_BUTTON        0x00000008
#define POWER_USER_NOTIFY_SHUTDOWN      0x00000010
#define POWER_FORCE_TRIGGER_RESET       0x80000000

#define BATTERY_DISCHARGE_FLAGS_EVENTCODE_MASK  0x00000007
#define BATTERY_DISCHARGE_FLAGS_ENABLE  0x80000000

SYSTEM_POWER_LEVEL STRUCT
	Enable DB
	Spare DB 3 DUP
	BatteryLevel DD
	PowerPolicy DD
	MinSystemState DD
ENDS

#define NUM_DISCHARGE_POLICIES      4
#define DISCHARGE_POLICY_CRITICAL   0
#define DISCHARGE_POLICY_LOW        1

SYSTEM_POWER_POLICY STRUCT
	Revision DD       // 1
	PowerButton DD
	SleepButton DD
	LidClose DD
	LidOpenWake DD
	Reserved DD
	Idle DD
	IdleTimeout DD
	IdleSensitivity DB
	DynamicThrottle DB
	Spare2 DB 2 DUP
	MinSleep DD
	MaxSleep DD
	ReducedLatencySleep DD
	WinLogonFlags DD
	Spare3 DD
	DozeS4Timeout DD
	BroadcastCapacityResolution DD
	DischargePolicy DD NUM_DISCHARGE_POLICIES DUP
	VideoTimeout DD
	VideoDimDisplay DB
	VideoReserved DD 3 DUP
	SpindownTimeout DD
	OptimizeForPower DB
	FanThrottleTolerance DB
	ForcedThrottle DB
	MinThrottle DB
	OverThrottled DD
ENDS

#define PROCESSOR_IDLESTATE_POLICY_COUNT 0x3

PROCESSOR_IDLESTATE_INFO STRUCT
	TimeCheck DD
	DemotePercent DB
	PromotePercent DB
	Spare DB 2 DUP
ENDS

PROCESSOR_IDLESTATE_POLICY STRUCT
	Revision DW
	Flags UNION
		AsWORD DW
		STRUCT
			AllowScaling DW
			Disabled DW
			Reserved DW
		ENDS
	ENDUNION
	PolicyCount DD
	Policy PROCESSOR_IDLESTATE_INFO PROCESSOR_IDLESTATE_POLICY_COUNT DUP
ENDS

#define PO_THROTTLE_NONE            0
#define PO_THROTTLE_CONSTANT        1
#define PO_THROTTLE_DEGRADE         2
#define PO_THROTTLE_ADAPTIVE        3
#define PO_THROTTLE_MAXIMUM         4   // not a policy, just a limit

PROCESSOR_POWER_POLICY_INFO STRUCT
	TimeCheck DD
	DemoteLimit DD
	PromoteLimit DD
	DemotePercent DB
	PromotePercent DB
	Spare DB 2 DUP
	AllowDemotion DD
	AllowPromotion DD
	Reserved DD
ENDS

PROCESSOR_POWER_POLICY STRUCT
	Revision DD
	DynamicThrottle DB
	Spare DB 3 DUP
	DisableCStates DD
	Reserved DD
	PolicyCount DD
	Policy DB 28*3 DUP <> ; PROCESSOR_POWER_POLICY_INFO
ENDS

#define PERFSTATE_POLICY_CHANGE_IDEAL  0x00
#define PERFSTATE_POLICY_CHANGE_SINGLE 0x01
#define PERFSTATE_POLICY_CHANGE_ROCKET 0x02
#define PERFSTATE_POLICY_CHANGE_MAX PERFSTATE_POLICY_CHANGE_ROCKET

PROCESSOR_PERFSTATE_POLICY STRUCT
	Revision DD
	MaxThrottle DB
	MinThrottle DB
	BusyAdjThreshold DB
	UNION
		Spare DB
		Flags UNION
			AsBYTE DB
			STRUCT
				NoDomainAccounting DB
				IncreasePolicy DB
				DecreasePolicy DB
				Reserved DB
			ENDS
		ENDUNION
	ENDUNION
	TimeCheck DD
	IncreaseTime DD
	DecreaseTime DD
	IncreasePercent DD
	DecreasePercent DD
ENDS

ADMINISTRATOR_POWER_POLICY STRUCT
	MinSleep DD
	MaxSleep DD
	MinVideoTimeout DD
	MaxVideoTimeout DD
	MinSpindownTimeout DD
	MaxSpindownTimeout DD
ENDS

SYSTEM_POWER_CAPABILITIES STRUCT
    // Misc supported system features
	PowerButtonPresent DB
	SleepButtonPresent DB
	LidPresent DB
	SystemS1 DB
	SystemS2 DB
	SystemS3 DB
	SystemS4 DB
	SystemS5 DB
	HiberFilePresent DB
	FullWake DB
	VideoDimPresent DB
	ApmPresent DB
	UpsPresent DB

    // Processors
	ThermalControl DB
	ProcessorThrottle DB
	ProcessorMinThrottle DB

#IF WINVER >= NTDDI_VISTA
	ProcessorThrottleScale DB
	spare2 DB 4 DUP
#ELSEIF WINVER >= NTDDI_WINXP
	ProcessorThrottleScale DB
	spare2 DB 4 DUP
#ELSEIF WINVER >= NTDDI_WIN2K
	ProcessorThrottleScale DB
	spare2 DB 4 DUP
#ELSE
	ProcessorMaxThrottle DB
	FastSystemS4 DB
	spare2 DB 3 DUP
#ENDIF

    // Disk
	DiskSpinDown DB
	spare3 DB 8 DUP

    // System Battery
	SystemBatteriesPresent DB
	BatteriesAreShortTerm DB
	BatteryScale DD 3 DUP

    // Wake
	AcOnLineWake DD
	SoftLidWake DD
	RtcWake DD
	MinDeviceWakeState DD
	DefaultLowLatencyWake DD
ENDS

SYSTEM_BATTERY_STATE STRUCT
	AcOnLine DB
	BatteryPresent DB
	Charging DB
	Discharging DB
	Spare1 DB 4 DUP

	MaxCapacity DD
	RemainingCapacity DD
	Rate DD
	EstimatedTime DD

	DefaultAlert1 DD
	DefaultAlert2 DD
ENDS

IMAGE_DOS_HEADER STRUCT
	e_magic DW
	e_cblp DW
	e_cp DW
	e_crlc DW
	e_cparhdr DW
	e_minalloc DW
	e_maxalloc DW
	e_ss DW
	e_sp DW
	e_csum DW
	e_ip DW
	e_cs DW
	e_lfarlc DW
	e_ovno DW
	e_res DW 4 DUP
	e_oemid DW
	e_oeminfo DW
	e_res2 DW 10 DUP
	e_lfanew DD
ENDS

IMAGE_OS2_HEADER STRUCT
	ne_magic DW
	ne_ver DB
	ne_rev DB
	ne_enttab DW
	ne_cbenttab DW
	ne_crc DD
	ne_flags DW
	ne_autodata DW
	ne_heap DW
	ne_stack DW
	ne_csip DD
	ne_ssspDD
	ne_cseg DW
	ne_cmod DW
	ne_cbnrestab DW
	ne_segtab DW
	ne_rsrctab DW
	ne_restab DW
	ne_modtab DW
	ne_imptab DW
	ne_nrestab DD
	ne_cmovent DW
	ne_align DW
	ne_cres DW
	ne_exetyp DB
	ne_flagsothers DB
	ne_pretthunks DW
	ne_psegrefbytes DW
	ne_swaparea DW
	ne_expver DW
ENDS

IMAGE_VXD_HEADER STRUCT
	e32_magic DW
	e32_border DB
	e32_worder DB
	e32_level DD
	e32_cpu DW
	e32_os DW
	e32_ver DD
	e32_mflags DD
	e32_mpages DD
	e32_startobj DD
	e32_eip DD
	e32_stackobj DD
	e32_esp DD
	e32_pagesize DD
	e32_lastpagesize DD
	e32_fixupsize DD
	e32_fixupsum DD
	e32_ldrsize DD
	e32_ldrsum DD
	e32_objtab DD
	e32_objcnt DD
	e32_objmap DD
	e32_itermap DD
	e32_rsrctab DD
	e32_rsrccnt DD
	e32_restab DD
	e32_enttab DD
	e32_dirtab DD
	e32_dircnt DD
	e32_fpagetab DD
	e32_frectab DD
	e32_impmod DD
	e32_impmodcnt DD
	e32_impproc DD
	e32_pagesum DD
	e32_datapage DD
	e32_preload DD
	e32_nrestab DD
	e32_cbnrestab DD
	e32_nressum DD
	e32_autodata DD
	e32_debuginfo DD
	e32_debuglen DD
	e32_instpreload DD
	e32_instdemand DD
	e32_heapsize DD
	e32_res3 DB 12 DUP
	e32_winresoff DD
	e32_winreslen DD
	e32_devid DW
	e32_ddkver DW
ENDS

#DEFINE IMAGE_FILE_MACHINE_I386 0x014c
#DEFINE IMAGE_FILE_MACHINE_IA64 0x0200
#DEFINE IMAGE_FILE_MACHINE_AMD64 0x8664

#DEFINE IMAGE_FILE_RELOCS_STRIPPED 0x0001
#DEFINE IMAGE_FILE_EXECUTABLE_IMAGE 0x0002
#DEFINE IMAGE_FILE_LINE_NUMS_STRIPPED 0x0004
#DEFINE IMAGE_FILE_LOCAL_SYMS_STRIPPED 0x0008
#DEFINE IMAGE_FILE_AGGRESIVE_WS_TRIM 0x0010
#DEFINE IMAGE_FILE_LARGE_ADDRESS_AWARE 0x0020
#DEFINE IMAGE_FILE_BYTES_REVERSED_LO 0x0080
#DEFINE IMAGE_FILE_32BIT_MACHINE 0x0100
#DEFINE IMAGE_FILE_DEBUG_STRIPPED 0x0200
#DEFINE IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP 0x0400
#DEFINE IMAGE_FILE_NET_RUN_FROM_SWAP 0x0800
#DEFINE IMAGE_FILE_SYSTEM 0x1000
#DEFINE IMAGE_FILE_DLL 0x2000
#DEFINE IMAGE_FILE_UP_SYSTEM_ONLY 0x4000
#DEFINE IMAGE_FILE_BYTES_REVERSED_HI 0x8000

IMAGE_FILE_HEADER STRUCT
	Machine DW
	NumberOfSections DW
	TimeDateStamp DD
	PointerToSymbolTable DD
	NumberOfSymbols DD
	SizeOfOptionalHeader DW
	Characteristics DW
ENDS

IMAGE_DATA_DIRECTORY STRUCT
	VirtualAddress DD
	Size DD
ENDS

#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES  16

IMAGE_OPTIONAL_HEADER32 STRUCT
	Magic DW
	MajorLinkerVersion DB
	MinorLinkerVersion DB
	SizeOfCode DD
	SizeOfInitializedData DD
	SizeOfUninitializedData DD
	AddressOfEntryPoint DD
	BaseOfCode DD
	BaseOfData DD
	ImageBase DD
	SectionAlignment DD
	FileAlignment DD
	MajorOperatingSystemVersion DW
	MinorOperatingSystemVersion DW
	MajorImageVersion DW
	MinorImageVersion DW
	MajorSubsystemVersion DW
	MinorSubsystemVersion DW
	Win32VersionValue DD
	SizeOfImage DD
	SizeOfHeaders DD
	CheckSum DD
	Subsystem DW
	DllCharacteristics DW
	SizeOfStackReserve DD
	SizeOfStackCommit DD
	SizeOfHeapReserve DD
	SizeOfHeapCommit DD
	LoaderFlags DD
	NumberOfRvaAndSizes DD
	DataDirectory DB 8*IMAGE_NUMBEROF_DIRECTORY_ENTRIES DUP <> ; IMAGE_DATA_DIRECTORY
ENDS

IMAGE_ROM_OPTIONAL_HEADER STRUCT
	Magic DW
	MajorLinkerVersion DB
	MinorLinkerVersion DB
	SizeOfCode DD
	SizeOfInitializedData DD
	SizeOfUninitializedData DD
	AddressOfEntryPoint DD
	BaseOfCode DD
	BaseOfData DD
	BaseOfBss DD
	GprMask DD
	CprMask DD 4 DUP
	GpValue DD
ENDS

IMAGE_OPTIONAL_HEADER64 STRUCT
	Magic DW
	MajorLinkerVersion DB
	MinorLinkerVersion DB
	SizeOfCode DD
	SizeOfInitializedData DD
	SizeOfUninitializedData DD
	AddressOfEntryPoint DD
	BaseOfCode DD
	ImageBase DQ
	SectionAlignment DD
	FileAlignment DD
	MajorOperatingSystemVersion DW
	MinorOperatingSystemVersion DW
	MajorImageVersion DW
	MinorImageVersion DW
	MajorSubsystemVersion DW
	MinorSubsystemVersion DW
	Win32VersionValue DD
	SizeOfImage DD
	SizeOfHeaders DD
	CheckSum DD
	Subsystem DW
	DllCharacteristics DW
	SizeOfStackReserve DQ
	SizeOfStackCommit DQ
	SizeOfHeapReserve DQ
	SizeOfHeapCommit DQ
	LoaderFlags DD
	NumberOfRvaAndSizes DD
    DataDirectory DB 8*IMAGE_NUMBEROF_DIRECTORY_ENTRIES DUP <> ; IMAGE_DATA_DIRECTORY
ENDS

IMAGE_NT_HEADERS64 STRUCT
	Signature DD
	FileHeader IMAGE_FILE_HEADER
	OptionalHeader IMAGE_OPTIONAL_HEADER64
ENDS

IMAGE_NT_HEADERS STRUCT
	Signature DD
	FileHeader IMAGE_FILE_HEADER
	OptionalHeader IMAGE_OPTIONAL_HEADER32
ENDS

IMAGE_ROM_HEADERS STRUCT
	FileHeader IMAGE_FILE_HEADER
	OptionalHeader IMAGE_ROM_OPTIONAL_HEADER
ENDS

ANON_OBJECT_HEADER STRUCT
	Sig1 DW
	Sig2 DW
	Version DW
	Machine DW
	TimeDateStamp DD
	ClassID GUID
	SizeOfData DD
ENDS

ANON_OBJECT_HEADER_V2 STRUCT
	Sig1 DW
	Sig2 DW
	Version DW
	Machine DW
	TimeDateStamp DD
	ClassID GUID
	SizeOfData DD
	Flags DD
	MetaDataSize DD
	MetaDataOffset DD
ENDS

IMAGE_SECTION_HEADER STRUCT
	Name DB IMAGE_SIZEOF_SHORT_NAME DUP
	Misc UNION
		PhysicalAddress DD
		VirtualSize DD
	ENDUNION
	VirtualAddress DD
	SizeOfRawData DD
	PointerToRawData DD
	PointerToRelocations DD
	PointerToLinenumbers DD
	NumberOfRelocations DW
	NumberOfLinenumbers DW
	Characteristics DD
ENDS

#define ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION         1
#define ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION              2
#define ACTIVATION_CONTEXT_SECTION_WINDOW_CLASS_REDIRECTION     3
#define ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION       4
#define ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION    5
#define ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION 6
#define ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION       7
#define ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_TABLE   8
#define ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES               9
#define ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS         10
#define ACTIVATION_CONTEXT_SECTION_COMPATIBILITY_INFO           11

//
// Section characteristics.
//
#define IMAGE_SCN_TYPE_REG                   0x00000000  // Reserved.
#define IMAGE_SCN_TYPE_DSECT                 0x00000001  // Reserved.
#define IMAGE_SCN_TYPE_NOLOAD                0x00000002  // Reserved.
#define IMAGE_SCN_TYPE_GROUP                 0x00000004  // Reserved.
#define IMAGE_SCN_TYPE_NO_PAD                0x00000008  // Reserved.
#define IMAGE_SCN_TYPE_COPY                  0x00000010  // Reserved.

#define IMAGE_SCN_CNT_CODE                   0x00000020  // Section contains code.
#define IMAGE_SCN_CNT_INITIALIZED_DATA       0x00000040  // Section contains initialized data.
#define IMAGE_SCN_CNT_UNINITIALIZED_DATA     0x00000080  // Section contains uninitialized data.

#define IMAGE_SCN_LNK_OTHER                  0x00000100  // Reserved.
#define IMAGE_SCN_LNK_INFO                   0x00000200  // Section contains comments or some other type of information.
#define IMAGE_SCN_TYPE_OVER                  0x00000400  // Reserved.
#define IMAGE_SCN_LNK_REMOVE                 0x00000800  // Section contents will not become part of image.
#define IMAGE_SCN_LNK_COMDAT                 0x00001000  // Section contents comdat.
//                                           0x00002000  // Reserved.
#define IMAGE_SCN_MEM_PROTECTED - Obsolete   0x00004000
#define IMAGE_SCN_NO_DEFER_SPEC_EXC          0x00004000  // Reset speculative exceptions handling bits in the TLB entries for this section.
#define IMAGE_SCN_GPREL                      0x00008000  // Section content can be accessed relative to GP
#define IMAGE_SCN_MEM_FARDATA                0x00008000
#define IMAGE_SCN_MEM_SYSHEAP  - Obsolete    0x00010000
#define IMAGE_SCN_MEM_PURGEABLE              0x00020000
#define IMAGE_SCN_MEM_16BIT                  0x00020000
#define IMAGE_SCN_MEM_LOCKED                 0x00040000
#define IMAGE_SCN_MEM_PRELOAD                0x00080000

#define IMAGE_SCN_ALIGN_1BYTES               0x00100000  //
#define IMAGE_SCN_ALIGN_2BYTES               0x00200000  //
#define IMAGE_SCN_ALIGN_4BYTES               0x00300000  //
#define IMAGE_SCN_ALIGN_8BYTES               0x00400000  //
#define IMAGE_SCN_ALIGN_16BYTES              0x00500000  // Default alignment if no others are specified.
#define IMAGE_SCN_ALIGN_32BYTES              0x00600000  //
#define IMAGE_SCN_ALIGN_64BYTES              0x00700000  //
#define IMAGE_SCN_ALIGN_128BYTES             0x00800000  //
#define IMAGE_SCN_ALIGN_256BYTES             0x00900000  //
#define IMAGE_SCN_ALIGN_512BYTES             0x00A00000  //
#define IMAGE_SCN_ALIGN_1024BYTES            0x00B00000  //
#define IMAGE_SCN_ALIGN_2048BYTES            0x00C00000  //
#define IMAGE_SCN_ALIGN_4096BYTES            0x00D00000  //
#define IMAGE_SCN_ALIGN_8192BYTES            0x00E00000  //
// Unused                                    0x00F00000
#define IMAGE_SCN_ALIGN_MASK                 0x00F00000

#define IMAGE_SCN_LNK_NRELOC_OVFL            0x01000000  // Section contains extended relocations.
#define IMAGE_SCN_MEM_DISCARDABLE            0x02000000  // Section can be discarded.
#define IMAGE_SCN_MEM_NOT_CACHED             0x04000000  // Section is not cachable.
#define IMAGE_SCN_MEM_NOT_PAGED              0x08000000  // Section is not pageable.
#define IMAGE_SCN_MEM_SHARED                 0x10000000  // Section is shareable.
#define IMAGE_SCN_MEM_EXECUTE                0x20000000  // Section is executable.
#define IMAGE_SCN_MEM_READ                   0x40000000  // Section is readable.
#define IMAGE_SCN_MEM_WRITE                  0x80000000  // Section is writeable.
//
// TLS Chaacteristic Flags
//
#define IMAGE_SCN_SCALE_INDEX                0x00000001  // Tls index is scaled

IMAGE_SYMBOL STRUCT
	UNION
		ShortName DB 8 DUP
		Name STRUCT
			Short DD
			Long DD
		ENDS
		LongName DD 2 DUP
	ENDUNION
	Value DD
	SectionNumber DW
	Type DW
	StorageClass DB
	NumberOfAuxSymbols DB
ENDS

IMAGE_AUX_SYMBOL UNION
	Sym STRUCT
		TagIndex DD
		Misc UNION
			LnSz STRUCT
				Linenumber DW
				Size DW
			ENDS
			TotalSize DD
		ENDUNION
		FcnAry UNION
			Function STRUCT
				PointerToLinenumber DD
				PointerToNextFunction DD
			ENDS
			Array STRUCT
				Dimension DW 4 DUP
			ENDS
		ENDUNION
	TvIndex DW
	ENDS

	File STRUCT
		Name DB IMAGE_SIZEOF_SYMBOL DUP
	ENDS

	Section STRUCT
		Length DD
		NumberOfRelocations DW
		NumberOfLinenumbers DW
		CheckSum DD
		Number DW
		Selection DB
	ENDS
ENDUNION

IMAGE_AUX_SYMBOL_TYPE_TOKEN_DEF = 1

IMAGE_AUX_SYMBOL_TOKEN_DEF STRUCT
	bAuxType DB
	bReserved DB
	SymbolTableIndex DD
	rgbReserved DB 12 DUP
ENDS

IMAGE_RELOCATION STRUCT
	UNION
		VirtualAddress DD
		RelocCount DD
	ENDUNION
	SymbolTableIndex DD
	Type DW
ENDS

IMAGE_LINENUMBER STRUCT
	Type UNION
		SymbolTableIndex DD
		VirtualAddress DD
	ENDUNION
	Linenumber DW
ENDS

IMAGE_BASE_RELOCATION STRUCT
	VirtualAddress DD
	SizeOfBlock DD
ENDS

IMAGE_ARCHIVE_MEMBER_HEADER STRUCT
	Name DB 16 DUP
	Date DB 12 DUP
	UserID DB 6 DUP
	GroupID DB 6 DUP
	Mode DB 8 DUP
	Size DB 10 DUP
	EndHeader DB 2 DUP
ENDS

#define IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR  60

IMAGE_EXPORT_DIRECTORY STRUCT
	Characteristics DD
	TimeDateStamp DD
	MajorVersion DW
	MinorVersion DW
	Name DD
	Base DD
	NumberOfFunctions DD
	NumberOfNames DD
	AddressOfFunctions DD
	AddressOfNames DD
	AddressOfNameOrdinals DD
ENDS

IMAGE_IMPORT_BY_NAME STRUCT
	Hint DW
	Name DB
ENDS

IMAGE_THUNK_DATA64 STRUCT
	UNION
		ForwarderString DQ
		Function DQ
		Ordinal DQ
		AddressOfData DQ
	ENDUNION
ENDS

IMAGE_THUNK_DATA32 STRUCT
	UNION
		ForwarderString DD
		Function DD
		Ordinal DD
		AddressOfData DD
	ENDUNION
ENDS

IMAGE_TLS_DIRECTORY64 STRUCT
	StartAddressOfRawData DQ
	EndAddressOfRawData DQ
	AddressOfIndex DQ
	AddressOfCallBacks DQ
	SizeOfZeroFill DD
	Characteristics DD
ENDS

IMAGE_TLS_DIRECTORY32 STRUCT
	StartAddressOfRawData DD
	EndAddressOfRawData DD
	AddressOfIndex DD
	AddressOfCallBacks DD
	SizeOfZeroFill DD
	Characteristics DD
ENDS


IMAGE_IMPORT_DESCRIPTOR STRUCT
	UNION
		Characteristics DD
		OriginalFirstThunk DD
	ENDUNION
	TimeDateStamp DD
	ForwarderChain DD
	Name DD
	FirstThunk DD
ENDS

IMAGE_BOUND_IMPORT_DESCRIPTOR STRUCT
	TimeDateStamp DD
	OffsetModuleName DW
	NumberOfModuleForwarderRefs DW
ENDS

IMAGE_BOUND_FORWARDER_REF STRUCT
	TimeDateStamp DD
	OffsetModuleName DW
	Reserved DW
ENDS

IMAGE_RESOURCE_DIRECTORY STRUCT
	Characteristics DD
	TimeDateStamp DD
	MajorVersion DW
	MinorVersion DW
	NumberOfNamedEntries DW
	NumberOfIdEntries DW
ENDS

IMAGE_RESOURCE_DIRECTORY_STRING STRUCT
	Length DW
	NameString DB
ENDS

IMAGE_RESOURCE_DIR_STRING_U STRUCT
	Length DW
	NameString DW
ENDS

IMAGE_RESOURCE_DATA_ENTRY STRUCT
	UNION
		STRUCT
			NameOffset DD
			NameIsString DD
		ENDS
		Name DD
		Id DW
	ENDUNION
	UNION
		OffsetToData DD
		STRUCT
			Dummy DD
			OffsetToDirectory DD
		ENDS
	ENDUNION
ENDS

IMAGE_RESOURCE_DATA_ENTRY STRUCT
	OffsetToData DD
	Size DD
	CodePage DD
	Reserved DD
ENDS

IMAGE_LOAD_CONFIG_DIRECTORY32 STRUCT
	Characteristics DD
	TimeDateStamp DD
	MajorVersion DW
	MinorVersion DW
	GlobalFlagsClear DD
	GlobalFlagsSet DD
	CriticalSectionDefaultTimeout DD
	DeCommitFreeBlockThreshold DD
	DeCommitTotalFreeThreshold DD
	LockPrefixTable DD
	MaximumAllocationSize DD
	VirtualMemoryThreshold DD
	ProcessHeapFlags DD
	ProcessAffinityMask DD
	CSDVersion DW
	Reserved1 DW
	EditList DD
	Reserved DD
ENDS

IMAGE_LOAD_CONFIG_DIRECTORY64 STRUCT
	Characteristics DD
	TimeDateStamp DD
	MajorVersion DW
	MinorVersion DW
	GlobalFlagsClear DD
	GlobalFlagsSet DD
	CriticalSectionDefaultTimeout DD
	DeCommitFreeBlockThreshold DD
	DeCommitTotalFreeThreshold DD
	LockPrefixTable DQ
	MaximumAllocationSize DD
	VirtualMemoryThreshold DD
	ProcessHeapFlags DD
	ProcessAffinityMask DD
	CSDVersion DW
	Reserved1 DW
	EditList DQ
	Reserved DD
ENDS

IMAGE_RUNTIME_FUNCTION_ENTRY STRUCT
	BeginAddress PTR
	EndAddress PTR
	UnwindInfoAddress PTR
ENDS

#DEFINE IMAGE_IA64_RUNTIME_FUNCTION_ENTRY IMAGE_RUNTIME_FUNCTION_ENTRY

UNWIND_CODE UNION
	STRUCT
		CodeOffset DB
		UnwindOp DB
		OpInfo DB
	ENDS
	FrameOffset DW
ENDUNION

UNWIND_INFO STRUCT
	Version DB
	Flags DB
	SizeOfProlog DB
	CountOfCodes DB
 	FrameRegister DB
	FrameOffset DB
	UnwindCode UNWIND_CODE
ENDS

IMAGE_CE_RUNTIME_FUNCTION_ENTRY STRUCT
	FuncStart DD
	PrologLen DD
	FuncLen DD
	ThirtyTwoBit DD
	ExceptionFlag DD
ENDS

IMAGE_DEBUG_DIRECTORY STRUCT
	Characteristics DD
	TimeDateStamp DD
	MajorVersion DW
	MinorVersion DW
	Type DD
	SizeOfData DD
	AddressOfRawData DD
	PointerToRawData DD
ENDS

IMAGE_COFF_SYMBOLS_HEADER STRUCT
	NumberOfSymbols DD
	LvaToFirstSymbol DD
	NumberOfLinenumbers DD
	LvaToFirstLinenumber DD
	RvaToFirstByteOfCode DD
	RvaToLastByteOfCode DD
	RvaToFirstByteOfData DD
	RvaToLastByteOfData DD
ENDS

FPO_DATA STRUCT
	ulOffStart DD
	cbProcSize DD
	cdwLocals DD
	cdwParams DW
	cbProlog DW
	cbRegs DW
	fHasSEH DW
	fUseBP DW
	reserved DW
	cbFrame DW
ENDS

IMAGE_DEBUG_MISC STRUCT
	DataType DD
	Length DD
	Unicode DB
	Reserved DB 3 DUP
	Data DB
ENDS

IMAGE_FUNCTION_ENTRY STRUCT
	StartingAddress DD
	EndingAddress DD
	EndOfPrologue DD
ENDS

IMAGE_FUNCTION_ENTRY64 STRUCT
	StartingAddress DQ
	EndingAddress DQ
    UNION
		EndOfPrologue DQ
		UnwindInfoAddress DQ
    ENDUNION
ENDS

IMAGE_SEPARATE_DEBUG_HEADER STRUCT
	Signature DW
	Flags DW
	Machine DW
	Characteristics DW
	TimeDateStamp DD
	CheckSum DD
	ImageBase DD
	SizeOfImage DD
	NumberOfSections DD
	ExportedNamesSize DD
	DebugDirectorySize DD
	SectionAlignment DD
	Reserved DD 2 DUP
ENDS

;typedef struct _ImageArchitectureHeader 
;    unsigned int AmaskValue:1;
;    int:7;
;    unsigned int AmaskShift:8;
;    int:16;
;    DWORD FirstEntryRVA;
;} IMAGE_ARCHITECTURE_HEADER, *PIMAGE_ARCHITECTURE_HEADER;

IMAGE_ARCHITECTURE_ENTRY STRUCT
	FixupInstRVA DD
	NewInst DD
ENDS

IMPORT_OBJECT_HEADER STRUCT
	Sig1 DW
	Sig2 DW
	Version DW
	Machine DW
	TimeDateStamp DD
	SizeOfData DD
	UNION
		Ordinal DW
		Hint DW
	ENDUNION
	Type DW
	NameType DW
	Reserved DW
ENDS

#define IMPORT_OBJECT_CODE 0
#define IMPORT_OBJECT_DATA 1
#define IMPORT_OBJECT_CONST 2

#define IMPORT_OBJECT_ORDINAL 0
#define IMPORT_OBJECT_NAME 1
#define IMPORT_OBJECT_NAME_NO_PREFIX 2
#define IMPORT_OBJECT_NAME_UNDECORATE 3

MESSAGE_RESOURCE_ENTRY STRUCT
	Length DW
	Flags DW
	Text DB
ENDS

MESSAGE_RESOURCE_BLOCK STRUCT
	LowId DD
	HighId DD
	OffsetToEntries DD
ENDS

MESSAGE_RESOURCE_DATA STRUCT
	NumberOfBlocks DD
	Blocks MESSAGE_RESOURCE_BLOCK
ENDS

OSVERSIONINFOA STRUCT
	dwOSVersionInfoSize DD
	dwMajorVersion DD
	dwMinorVersion DD
	dwBuildNumber DD
	dwPlatformId DD
	szCSDVersion DB 128 DUP
ENDS

OSVERSIONINFOW STRUCT
	dwOSVersionInfoSize DD
	dwMajorVersion DD
	dwMinorVersion DD
	dwBuildNumber DD
	dwPlatformId DD
	szCSDVersion DW 128 DUP
ENDS

OSVERSIONINFOEXA STRUCT
	dwOSVersionInfoSize DD
	dwMajorVersion DD
	dwMinorVersion DD
	dwBuildNumber DD
	dwPlatformId DD
	szCSDVersion DB 128 DUP
	wServicePackMajor DW
	wServicePackMinor DW
	wSuiteMask DW
	wProductType DB
	wReserved DB
ENDS

OSVERSIONINFOEXW STRUCT
	dwOSVersionInfoSize DD
	dwMajorVersion DD
	dwMinorVersion DD
	dwBuildNumber DD
	dwPlatformId DD
	szCSDVersion DW 128 DUP
	wServicePackMajor DW
	wServicePackMinor DW
	wSuiteMask DW
	wProductType DB
	wReserved DB
ENDS

RTL_CRITICAL_SECTION_DEBUG STRUCT
	Type DW
	CreatorBackTraceIndex DW
	CriticalSection PTR
	ProcessLocksList LIST_ENTRY
	EntryCount DD
	ContentionCount DD
	Spare DD 2 DUP
ENDS

#define RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO         0x01000000
#define RTL_CRITICAL_SECTION_FLAG_DYNAMIC_SPIN          0x02000000
#define RTL_CRITICAL_SECTION_FLAG_STATIC_INIT           0x04000000
#define RTL_CRITICAL_SECTION_ALL_FLAG_BITS              0xFF000000
#define RTL_CRITICAL_SECTION_DEBUG_FLAG_STATIC_INIT     0x00000001

RTL_CRITICAL_SECTION STRUCT
	DebugInfo DD
	LockCount DD
	RecursionCount DD
	OwningThread DD
	LockSemaphore DD
	SpinCount DD
ENDS

EVENTLOGRECORD STRUCT
	Length DD
	Reserved DD
	RecordNumber DD
	TimeGenerated DD
	TimeWritten DD
	EventID DD
	EventType DW
	NumStrings DW
	EventCategory DW
	ReservedFlags DW
	ClosingRecordNumber DD
	StringOffset DD
	UserSidLength DD
	UserSidOffset DD
	DataLength DD
	DataOffset DD
ENDS

EVENTSFORLOGFILE STRUCT
	ulSize DD
	szLogicalLogFile DW MAXLOGICALLOGNAMESIZE DUP
	ulNumRecords DD
	pEventLogRecords DD ; EVENTLOGRECORD
ENDS

PACKEDEVENTINFO STRUCT
	ulSize DD
	ulNumEventsForLogFile DD
	ulOffsets DD
ENDS

ACTIVATION_CONTEXT_QUERY_INDEX STRUCT
	ulAssemblyIndex DD
	ulFileIndexInAssembly DD
ENDS

#define ACTIVATION_CONTEXT_PATH_TYPE_NONE 1
#define ACTIVATION_CONTEXT_PATH_TYPE_WIN32_FILE 2
#define ACTIVATION_CONTEXT_PATH_TYPE_URL 3
#define ACTIVATION_CONTEXT_PATH_TYPE_ASSEMBLYREF 4

ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION STRUCT
	ulFlags DD
	ulEncodedAssemblyIdentityLength DD      // in bytes
	ulManifestPathType DD                   // ACTIVATION_CONTEXT_PATH_TYPE_*
	ulManifestPathLength DD                 // in bytes
	liManifestLastWriteTime LARGE_INTEGER              // FILETIME
	ulPolicyPathType DD                     // ACTIVATION_CONTEXT_PATH_TYPE_*
	ulPolicyPathLength DD                   // in bytes
	liPolicyLastWriteTime LARGE_INTEGER                // FILETIME
	ulMetadataSatelliteRosterIndex DD
	ulManifestVersionMajor DD               // 1
	ulManifestVersionMinor DD               // 0
	ulPolicyVersionMajor DD                 // 0
	ulPolicyVersionMinor DD                 // 0
	ulAssemblyDirectoryNameLength DD        // in bytes
	lpAssemblyEncodedAssemblyIdentity PTR
	lpAssemblyManifestPath PTR
	lpAssemblyPolicyPath PTR
	lpAssemblyDirectoryName PTR
	ulFileCount DD
ENDS

ACTCTX_RUN_LEVEL_UNSPECIFIED = 0
ACTCTX_RUN_LEVEL_AS_INVOKER = 1
ACTCTX_RUN_LEVEL_HIGHEST_AVAILABLE = 2
ACTCTX_RUN_LEVEL_REQUIRE_ADMIN = 3
ACTCTX_RUN_LEVEL_NUMBERS = 4

ACTIVATION_CONTEXT_RUN_LEVEL_INFORMATION STRUCT
	ulFlags DD
	RunLevel DD
	UiAccess DD
ENDS

ACTIVATION_CONTEXT_DETAILED_INFORMATION STRUCT
	dwFlags DD
	ulFormatVersion DD
	ulAssemblyCount DD
	ulRootManifestPathType DD
	ulRootManifestPathChars DD
	ulRootConfigurationPathType DD
	ulRootConfigurationPathChars DD
	ulAppDirPathType DD
	ulAppDirPathChars DD
	lpRootManifestPath PTR
	lpRootConfigurationPath PTR
	lpAppDirPath PTR
ENDS

TAPE_ERASE STRUCT
	Type DD
	Immediate DB
ENDS

TAPE_PREPARE STRUCT
	Operation DD
	Immediate DB
ENDS

TAPE_WRITE_MARKS STRUCT
	Type DD
	Count DD
	Immediate DB
ENDS

TAPE_GET_POSITION STRUCT
	Type DD
	Partition DD
	Offset LARGE_INTEGER
ENDS

TAPE_SET_POSITION STRUCT
	Method DD
	Partition DD
	Offset LARGE_INTEGER
	Immediate DB
ENDS

TAPE_GET_DRIVE_PARAMETERS STRUCT
	ECC DB
	Compression DB
	DataPadding DB
	ReportSetmarks DB
	DefaultBlockSize DD
	MaximumBlockSize DD
	MinimumBlockSize DD
	MaximumPartitionCount DD
	FeaturesLow DD
	FeaturesHigh DD
	EOTWarningZoneSize DD
ENDS

TAPE_SET_DRIVE_PARAMETERS STRUCT
	ECC DB
	Compression DB
	DataPadding DB
	ReportSetmarks DB
	EOTWarningZoneSize DD
ENDS

TAPE_GET_MEDIA_PARAMETERS STRUCT
	Capacity LARGE_INTEGER
	Remaining LARGE_INTEGER
	BlockSize DD
	PartitionCount DD
	WriteProtected DB
ENDS

TAPE_SET_MEDIA_PARAMETERS STRUCT
	BlockSize DD
ENDS

TAPE_CREATE_PARTITION STRUCT
	Method DD
	Count DD
	Size DD
ENDS


// ReplacesCorHdrNumericDefines enumeration

COMIMAGE_FLAGS_ILONLY               =0x00000001
COMIMAGE_FLAGS_32BITREQUIRED        =0x00000002
COMIMAGE_FLAGS_IL_LIBRARY           =0x00000004
COMIMAGE_FLAGS_STRONGNAMESIGNED     =0x00000008
COMIMAGE_FLAGS_NATIVE_ENTRYPOINT    =0x00000010
COMIMAGE_FLAGS_TRACKDEBUGDATA       =0x00010000
COR_VERSION_MAJOR_V2                =2
COR_VERSION_MAJOR                   =2
COR_VERSION_MINOR                   =5
COR_DELETED_NAME_LENGTH             =8
COR_VTABLEGAP_NAME_LENGTH           =8
NATIVE_TYPE_MAX_CB                  =1
COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE=0xFF
IMAGE_COR_MIH_METHODRVA             =0x01
IMAGE_COR_MIH_EHRVA                 =0x02
IMAGE_COR_MIH_BASICBLOCK            =0x08
COR_VTABLE_32BIT                    =0x01         // V-table slots are 32-bits in size.
COR_VTABLE_64BIT                    =0x02         // V-table slots are 64-bits in size.
COR_VTABLE_FROM_UNMANAGED           =0x04         // If set, transition from unmanaged.
COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN  =0x08 // If set, transition from unmanaged with keeping the current appdomain.
COR_VTABLE_CALL_MOST_DERIVED        =0x10         // Call most derived method described by
IMAGE_COR_EATJ_THUNK_SIZE           =32           // Size of a jump thunk reserved range.
MAX_CLASS_NAME                      =1024
MAX_PACKAGE_NAME                    =1024

IMAGE_COR20_HEADER STRUCT
	cb DD
	MajorRuntimeVersion DW
	MinorRuntimeVersion DW
	MetaData IMAGE_DATA_DIRECTORY
	Flags DD
	UNION
		EntryPointToken DD
		EntryPointRVA DD
	ENDUNION
	Resources IMAGE_DATA_DIRECTORY
	StrongNameSignature IMAGE_DATA_DIRECTORY
	CodeManagerTable IMAGE_DATA_DIRECTORY
	VTableFixups IMAGE_DATA_DIRECTORY
	ExportAddressTableJumps IMAGE_DATA_DIRECTORY
	ManagedNativeHeader IMAGE_DATA_DIRECTORY
ENDS

#IF X64 | WIN64
	#define IMAGE_OPTIONAL_HEADER IMAGE_OPTIONAL_HEADER64
	#define IMAGE_SIZEOF_NT_OPTIONAL_HEADER IMAGE_SIZEOF_NT_OPTIONAL64_HEADER
	#define IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR64_MAGIC
	#define IMAGE_ORDINAL_FLAG  IMAGE_ORDINAL_FLAG64
#ELSE
	#define IMAGE_OPTIONAL_HEADER IMAGE_OPTIONAL_HEADER32
	#define IMAGE_SIZEOF_NT_OPTIONAL_HEADER IMAGE_SIZEOF_NT_OPTIONAL32_HEADER
	#define IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR32_MAGIC
	#define IMAGE_ORDINAL_FLAG  IMAGE_ORDINAL_FLAG32
#ENDIF



#IFDEF UNICODE
	OSVERSIONINFO=OSVERSIONINFOW
	OSVERSIONINFOEX=OSVERSIONINFOEXW
#ELSE
	OSVERSIONINFO=OSVERSIONINFOA
	OSVERSIONINFOEX=OSVERSIONINFOEXA
#ENDIF

#endif /* _WINNT_H */

