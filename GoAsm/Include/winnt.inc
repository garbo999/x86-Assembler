;=============================================================;
;           winnt.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINNT_INC
#Define WINNT_INC

#Define ANYSIZE_ARRAY  			1

#IF x64
	#Define MAX_NATURAL_ALIGNMENT	8
#ELSE
	#Define MAX_NATURAL_ALIGNMENT	4
#ENDIF

#Define APPLICATION_ERROR_MASK       	020000000H
#Define ERROR_SEVERITY_SUCCESS       	000000000H
#Define ERROR_SEVERITY_INFORMATIONAL	040000000H
#Define ERROR_SEVERITY_WARNING       	080000000H
#Define ERROR_SEVERITY_ERROR         	0C0000000H

#Define MAXLONGLONG                     7FFFFFFFFFFFFFFFH

#Define ANSI_NULL 				0
#Define UNICODE_NULL			0

#Define MINCHAR     			080H
#Define MAXCHAR     			07FH
#Define MINSHORT    			08000H
#Define MAXSHORT    			07FFFH
#Define MINLONG     			080000000H
#Define MAXLONG     			07FFFFFFFH
#Define MAXBYTE     			0FFH
#Define MAXWORD     			0FFFFH
#Define MAXDWORD    			0FFFFFFFFH

#Define LANG_NEUTRAL            000H

#Define LANG_AFRIKAANS          036H
#Define LANG_ALBANIAN           01CH
#Define LANG_ARABIC             001H
#Define LANG_ARMENIAN           02BH
#Define LANG_ASSAMESE           04DH
#Define LANG_AZERI              02CH
#Define LANG_BASQUE             02DH
#Define LANG_BELARUSIAN         023H
#Define LANG_BENGALI            045H
#Define LANG_BULGARIAN          002H
#Define LANG_CATALAN            003H
#Define LANG_CHINESE            004H
#Define LANG_CROATIAN           01AH
#Define LANG_CZECH              005H
#Define LANG_DANISH             006H
#Define LANG_DUTCH              013H
#Define LANG_ENGLISH            009H
#Define LANG_ESTONIAN           025H
#Define LANG_FAEROESE           038H
#Define LANG_FARSI              029H
#Define LANG_FINNISH            00BH
#Define LANG_FRENCH             00CH
#Define LANG_GEORGIAN           037H
#Define LANG_GERMAN             007H
#Define LANG_GREEK              008H
#Define LANG_GUJARATI           047H
#Define LANG_HEBREW             00DH
#Define LANG_HINDI              039H
#Define LANG_HUNGARIAN          00EH
#Define LANG_ICELANDIC          00FH
#Define LANG_INDONESIAN         021H
#Define LANG_ITALIAN            010H
#Define LANG_JAPANESE           011H
#Define LANG_KANNADA            04BH
#Define LANG_KASHMIRI           060H
#Define LANG_KAZAK              03FH
#Define LANG_KONKANI            057H
#Define LANG_KOREAN             012H
#Define LANG_LATVIAN            026H
#Define LANG_LITHUANIAN         027H
#Define LANG_MACEDONIAN         02FH
#Define LANG_MALAY              03EH
#Define LANG_MALAYALAM          04CH
#Define LANG_MANIPURI           058H
#Define LANG_MARATHI            04EH
#Define LANG_NEPALI             061H
#Define LANG_NORWEGIAN          014H
#Define LANG_ORIYA              048H
#Define LANG_POLISH             015H
#Define LANG_PORTUGUESE         016H
#Define LANG_PUNJABI            046H
#Define LANG_ROMANIAN           018H
#Define LANG_RUSSIAN            019H
#Define LANG_SANSKRIT           04FH
#Define LANG_SERBIAN            01AH
#Define LANG_SINDHI             059H
#Define LANG_SLOVAK             01BH
#Define LANG_SLOVENIAN          024H
#Define LANG_SPANISH            00AH
#Define LANG_SWAHILI            041H
#Define LANG_SWEDISH            01DH
#Define LANG_TAMIL              049H
#Define LANG_TATAR              044H
#Define LANG_TELUGU             04AH
#Define LANG_THAI               01EH
#Define LANG_TURKISH            01FH
#Define LANG_UKRAINIAN          022H
#Define LANG_URDU               020H
#Define LANG_UZBEK              043H
#Define LANG_VIETNAMESE         02AH

#Define SUBLANG_NEUTRAL                  000H ; language neutral
#Define SUBLANG_DEFAULT                  001H ; user default
#Define SUBLANG_SYS_DEFAULT              002H ; system default

#Define SUBLANG_ARABIC_SAUDI_ARABIA      001H ; Arabic (Saudi Arabia)
#Define SUBLANG_ARABIC_IRAQ              002H ; Arabic (Iraq)
#Define SUBLANG_ARABIC_EGYPT             003H ; Arabic (Egypt)
#Define SUBLANG_ARABIC_LIBYA             004H ; Arabic (Libya)
#Define SUBLANG_ARABIC_ALGERIA           005H ; Arabic (Algeria)
#Define SUBLANG_ARABIC_MOROCCO           006H ; Arabic (Morocco)
#Define SUBLANG_ARABIC_TUNISIA           007H ; Arabic (Tunisia)
#Define SUBLANG_ARABIC_OMAN              008H ; Arabic (Oman)
#Define SUBLANG_ARABIC_YEMEN             009H ; Arabic (Yemen)
#Define SUBLANG_ARABIC_SYRIA             00AH ; Arabic (Syria)
#Define SUBLANG_ARABIC_JORDAN            00BH ; Arabic (Jordan)
#Define SUBLANG_ARABIC_LEBANON           00CH ; Arabic (Lebanon)
#Define SUBLANG_ARABIC_KUWAIT            00DH ; Arabic (Kuwait)
#Define SUBLANG_ARABIC_UAE               00EH ; Arabic (U.A.E)
#Define SUBLANG_ARABIC_BAHRAIN           00FH ; Arabic (Bahrain)
#Define SUBLANG_ARABIC_QATAR             010H ; Arabic (Qatar)
#Define SUBLANG_AZERI_LATIN              001H ; Azeri (Latin)
#Define SUBLANG_AZERI_CYRILLIC           002H ; Azeri (Cyrillic)
#Define SUBLANG_CHINESE_TRADITIONAL      001H ; Chinese (Taiwan Region)
#Define SUBLANG_CHINESE_SIMPLIFIED       002H ; Chinese (PR China)
#Define SUBLANG_CHINESE_HONGKONG         003H ; Chinese (Hong Kong)
#Define SUBLANG_CHINESE_SINGAPORE        004H ; Chinese (Singapore)
#Define SUBLANG_CHINESE_MACAU            005H ; Chinese (Macau)
#Define SUBLANG_DUTCH                    001H ; Dutch
#Define SUBLANG_DUTCH_BELGIAN            002H ; Dutch (Belgian)
#Define SUBLANG_ENGLISH_US               001H ; English (USA)
#Define SUBLANG_ENGLISH_UK               002H ; English (UK)
#Define SUBLANG_ENGLISH_AUS              003H ; English (Australian)
#Define SUBLANG_ENGLISH_CAN              004H ; English (Canadian)
#Define SUBLANG_ENGLISH_NZ               005H ; English (New Zealand)
#Define SUBLANG_ENGLISH_EIRE             006H ; English (Irish)
#Define SUBLANG_ENGLISH_SOUTH_AFRICA     007H ; English (South Africa)
#Define SUBLANG_ENGLISH_JAMAICA          008H ; English (Jamaica)
#Define SUBLANG_ENGLISH_CARIBBEAN        009H ; English (Caribbean)
#Define SUBLANG_ENGLISH_BELIZE           00AH ; English (Belize)
#Define SUBLANG_ENGLISH_TRINIDAD         00BH ; English (Trinidad)
#Define SUBLANG_ENGLISH_ZIMBABWE         00CH ; English (Zimbabwe)
#Define SUBLANG_ENGLISH_PHILIPPINES      00DH ; English (Philippines)
#Define SUBLANG_FRENCH                   001H ; French
#Define SUBLANG_FRENCH_BELGIAN           002H ; French (Belgian)
#Define SUBLANG_FRENCH_CANADIAN          003H ; French (Canadian)
#Define SUBLANG_FRENCH_SWISS             004H ; French (Swiss)
#Define SUBLANG_FRENCH_LUXEMBOURG        005H ; French (Luxembourg)
#Define SUBLANG_FRENCH_MONACO            006H ; French (Monaco)
#Define SUBLANG_GERMAN                   001H ; German
#Define SUBLANG_GERMAN_SWISS             002H ; German (Swiss)
#Define SUBLANG_GERMAN_AUSTRIAN          003H ; German (Austrian)
#Define SUBLANG_GERMAN_LUXEMBOURG        004H ; German (Luxembourg)
#Define SUBLANG_GERMAN_LIECHTENSTEIN     005H ; German (Liechtenstein)
#Define SUBLANG_ITALIAN                  001H ; Italian
#Define SUBLANG_ITALIAN_SWISS            002H ; Italian (Swiss)
#Define SUBLANG_KASHMIRI_INDIA           002H ; Kashmiri (India)
#Define SUBLANG_KOREAN                   001H ; Korean (Extended Wansung)
#Define SUBLANG_LITHUANIAN               001H ; Lithuanian
#Define SUBLANG_LITHUANIAN_CLASSIC       002H ; Lithuanian (Classic)
#Define SUBLANG_MALAY_MALAYSIA           001H ; Malay (Malaysia)
#Define SUBLANG_MALAY_BRUNEI_DARUSSALAM  002H ; Malay (Brunei Darussalam)
#Define SUBLANG_NEPALI_INDIA             002H ; Nepali (India)
#Define SUBLANG_NORWEGIAN_BOKMAL         001H ; Norwegian (Bokmal)
#Define SUBLANG_NORWEGIAN_NYNORSK        002H ; Norwegian (Nynorsk)
#Define SUBLANG_PORTUGUESE               002H ; Portuguese
#Define SUBLANG_PORTUGUESE_BRAZILIAN     001H ; Portuguese (Brazilian)
#Define SUBLANG_SERBIAN_LATIN            002H ; Serbian (Latin)
#Define SUBLANG_SERBIAN_CYRILLIC         003H ; Serbian (Cyrillic)
#Define SUBLANG_SPANISH                  001H ; Spanish (Castilian)
#Define SUBLANG_SPANISH_MEXICAN          002H ; Spanish (Mexican)
#Define SUBLANG_SPANISH_MODERN           003H ; Spanish (Modern)
#Define SUBLANG_SPANISH_GUATEMALA        004H ; Spanish (Guatemala)
#Define SUBLANG_SPANISH_COSTA_RICA       005H ; Spanish (Costa Rica)
#Define SUBLANG_SPANISH_PANAMA           006H ; Spanish (Panama)
#Define SUBLANG_SPANISH_DOMINICAN_REPUBLIC 007H ; Spanish (Dominican Republic)
#Define SUBLANG_SPANISH_VENEZUELA        008H ; Spanish (Venezuela)
#Define SUBLANG_SPANISH_COLOMBIA         009H ; Spanish (Colombia)
#Define SUBLANG_SPANISH_PERU             00AH ; Spanish (Peru)
#Define SUBLANG_SPANISH_ARGENTINA        00BH ; Spanish (Argentina)
#Define SUBLANG_SPANISH_ECUADOR          00CH ; Spanish (Ecuador)
#Define SUBLANG_SPANISH_CHILE            00DH ; Spanish (Chile)
#Define SUBLANG_SPANISH_URUGUAY          00EH ; Spanish (Uruguay)
#Define SUBLANG_SPANISH_PARAGUAY         00FH ; Spanish (Paraguay)
#Define SUBLANG_SPANISH_BOLIVIA          010H ; Spanish (Bolivia)
#Define SUBLANG_SPANISH_EL_SALVADOR      011H ; Spanish (El Salvador)
#Define SUBLANG_SPANISH_HONDURAS         012H ; Spanish (Honduras)
#Define SUBLANG_SPANISH_NICARAGUA        013H ; Spanish (Nicaragua)
#Define SUBLANG_SPANISH_PUERTO_RICO      014H ; Spanish (Puerto Rico)
#Define SUBLANG_SWEDISH                  001H ; Swedish
#Define SUBLANG_SWEDISH_FINLAND          002H ; Swedish (Finland)
#Define SUBLANG_URDU_PAKISTAN            001H ; Urdu (Pakistan)
#Define SUBLANG_URDU_INDIA               002H ; Urdu (India)
#Define SUBLANG_UZBEK_LATIN              001H ; Uzbek (Latin)
#Define SUBLANG_UZBEK_CYRILLIC           002H ; Uzbek (Cyrillic)

#Define SORT_DEFAULT                     00H ; sorting default

#Define SORT_JAPANESE_XJIS               00H ; Japanese XJIS order
#Define SORT_JAPANESE_UNICODE            01H ; Japanese Unicode order

#Define SORT_CHINESE_BIG5                00H ; Chinese BIG5 order
#Define SORT_CHINESE_PRCP                00H ; PRC Chinese Phonetic order
#Define SORT_CHINESE_UNICODE             01H ; Chinese Unicode order
#Define SORT_CHINESE_PRC                 02H ; PRC Chinese Stroke Count order
#Define SORT_CHINESE_BOPOMOFO            03H ; Traditional Chinese Bopomofo order

#Define SORT_KOREAN_KSC                  00H ; Korean KSC order
#Define SORT_KOREAN_UNICODE              01H ; Korean Unicode order

#Define SORT_GERMAN_PHONE_BOOK           01H ; German Phone Book order

#Define SORT_HUNGARIAN_DEFAULT           00H ; Hungarian Default order
#Define SORT_HUNGARIAN_TECHNICAL         01H ; Hungarian Technical order

#Define SORT_GEORGIAN_TRADITIONAL        00H ; Georgian Traditional order
#Define SORT_GEORGIAN_MODERN             01H ; Georgian Modern order

#Define NLS_VALID_LOCALE_MASK  	0000FFFFFH

#Define STATUS_WAIT_0                    000000000H
#Define STATUS_ABANDONED_WAIT_0          000000080H
#Define STATUS_USER_APC                  0000000C0H
#Define STATUS_TIMEOUT                   000000102H
#Define STATUS_PENDING                   000000103H
#Define STATUS_SEGMENT_NOTIFICATION      040000005H
#Define STATUS_GUARD_PAGE_VIOLATION      080000001H
#Define STATUS_DATATYPE_MISALIGNMENT     080000002H
#Define STATUS_BREAKPOINT                080000003H
#Define STATUS_SINGLE_STEP               080000004H
#Define STATUS_ACCESS_VIOLATION          0C0000005H
#Define STATUS_IN_PAGE_ERROR             0C0000006H
#Define STATUS_INVALID_HANDLE            0C0000008H
#Define STATUS_NO_MEMORY                 0C0000017H
#Define STATUS_ILLEGAL_INSTRUCTION       0C000001DH
#Define STATUS_NONCONTINUABLE_EXCEPTION  0C0000025H
#Define STATUS_INVALID_DISPOSITION       0C0000026H
#Define STATUS_ARRAY_BOUNDS_EXCEEDED     0C000008CH
#Define STATUS_FLOAT_DENORMAL_OPERAND    0C000008DH
#Define STATUS_FLOAT_DIVIDE_BY_ZERO      0C000008EH
#Define STATUS_FLOAT_INEXACT_RESULT      0C000008FH
#Define STATUS_FLOAT_INVALID_OPERATION   0C0000090H
#Define STATUS_FLOAT_OVERFLOW            0C0000091H
#Define STATUS_FLOAT_STACK_CHECK         0C0000092H
#Define STATUS_FLOAT_UNDERFLOW           0C0000093H
#Define STATUS_INTEGER_DIVIDE_BY_ZERO    0C0000094H
#Define STATUS_INTEGER_OVERFLOW          0C0000095H
#Define STATUS_PRIVILEGED_INSTRUCTION    0C0000096H
#Define STATUS_STACK_OVERFLOW            0C00000FDH
#Define STATUS_CONTROL_C_EXIT            0C000013AH
#Define STATUS_FLOAT_MULTIPLE_FAULTS     0C00002B4H
#Define STATUS_FLOAT_MULTIPLE_TRAPS      0C00002B5H
#Define STATUS_ILLEGAL_VLM_REFERENCE     0C00002C0H

#Define MAXIMUM_WAIT_OBJECTS 	64
#Define MAXIMUM_SUSPEND_COUNT	MAXCHAR

#Define CONTEXT_PORTABLE_32BIT  000100000H
#Define CONTEXT_ALPHA           000020000H

#Define CONTEXT_FULL			(CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER)

#Define SIZE_OF_80387_REGISTERS 80

#Define CONTEXT_CONTROL         	(CONTEXT_i386 | 000000001H)
#Define CONTEXT_INTEGER         	(CONTEXT_i386 | 000000002H)
#Define CONTEXT_SEGMENTS        	(CONTEXT_i386 | 000000004H)
#Define CONTEXT_FLOATING_POINT  	(CONTEXT_i386 | 000000008H)
#Define CONTEXT_DEBUG_REGISTERS 	(CONTEXT_i386 | 000000010H)
#Define CONTEXT_EXTENDED_REGISTERS  (CONTEXT_i386 | 000000020H)

#Define MAXIMUM_SUPPORTED_EXTENSION	512

#Define EXCEPTION_NONCONTINUABLE		01H
#Define EXCEPTION_MAXIMUM_PARAMETERS	15

#Define DELETE                  (000010000H)
#Define READ_CONTROL            (000020000H)
#Define WRITE_DAC               (000040000H)
#Define WRITE_OWNER             (000080000H)
#Define SYNCHRONIZE             (000100000H)

#Define STANDARD_RIGHTS_REQUIRED	(0000F0000H)

#Define STANDARD_RIGHTS_READ    (READ_CONTROL)
#Define STANDARD_RIGHTS_WRITE   (READ_CONTROL)
#Define STANDARD_RIGHTS_EXECUTE (READ_CONTROL)

#Define STANDARD_RIGHTS_ALL     (0001F0000H)

#Define SPECIFIC_RIGHTS_ALL     (00000FFFFH)

#Define ACCESS_SYSTEM_SECURITY	(001000000H)

#Define MAXIMUM_ALLOWED         (002000000H)

#Define GENERIC_READ            (080000000H)
#Define GENERIC_WRITE           (040000000H)
#Define GENERIC_EXECUTE         (020000000H)
#Define GENERIC_ALL             (010000000H)

#Define SID_REVISION                	1
#Define SID_MAX_SUB_AUTHORITIES         15
#Define SID_RECOMMENDED_SUB_AUTHORITIES 1

;SID_NAME_USE enumeration
SidTypeUser						Equ 1
SidTypeGroup					Equ 2
SidTypeDomain					Equ 3
SidTypeAlias					Equ 4
SidTypeWellKnownGroup			Equ 5
SidTypeDeletedAccount			Equ 6
SidTypeInvalid					Equ 7
SidTypeUnknown					Equ 8
SidTypeComputer					Equ 9

#Define SECURITY_NULL_SID_AUTHORITY       	<0, 0, 0, 0, 0, 0>
#Define SECURITY_WORLD_SID_AUTHORITY      	<0, 0, 0, 0, 0, 1>
#Define SECURITY_LOCAL_SID_AUTHORITY      	<0, 0, 0, 0, 0, 2>
#Define SECURITY_CREATOR_SID_AUTHORITY    	<0, 0, 0, 0, 0, 3>
#Define SECURITY_NON_UNIQUE_AUTHORITY		<0, 0, 0, 0, 0, 4>

#Define SECURITY_NULL_RID                 	(000000000H)
#Define SECURITY_WORLD_RID                	(000000000H)
#Define SECURITY_LOCAL_RID                	(000000000H)

#Define SECURITY_CREATOR_OWNER_RID        	(000000000H)
#Define SECURITY_CREATOR_GROUP_RID        	(000000001H)

#Define SECURITY_CREATOR_OWNER_SERVER_RID	(000000002H)
#Define SECURITY_CREATOR_GROUP_SERVER_RID 	(000000003H)

#Define SECURITY_NT_AUTHORITY           {0, 0, 0, 0, 0, 5}

#Define SECURITY_DIALUP_RID             (000000001H)
#Define SECURITY_NETWORK_RID            (000000002H)
#Define SECURITY_BATCH_RID              (000000003H)
#Define SECURITY_INTERACTIVE_RID        (000000004H)
#Define SECURITY_SERVICE_RID            (000000006H)
#Define SECURITY_ANONYMOUS_LOGON_RID    (000000007H)
#Define SECURITY_PROXY_RID              (000000008H)
#Define SECURITY_ENTERPRISE_CONTROLLERS_RID	(000000009H)
#define SECURITY_SERVER_LOGON_RID       SECURITY_ENTERPRISE_CONTROLLERS_RID
#Define SECURITY_PRINCIPAL_SELF_RID     (00000000AH)
#Define SECURITY_AUTHENTICATED_USER_RID (00000000BH)
#Define SECURITY_RESTRICTED_CODE_RID    (00000000CH)

#Define SECURITY_LOGON_IDS_RID          (000000005H)
#Define SECURITY_LOGON_IDS_RID_COUNT    (3)

#Define SECURITY_LOCAL_SYSTEM_RID       (000000012H)

#Define SECURITY_NT_NON_UNIQUE          (000000015H)

#Define SECURITY_BUILTIN_DOMAIN_RID     (000000020H)

#Define DOMAIN_USER_RID_ADMIN          	(0000001F4H)
#Define DOMAIN_USER_RID_GUEST          	(0000001F5H)
#Define DOMAIN_USER_RID_KRBTGT         	(0000001F6H)

#Define DOMAIN_GROUP_RID_ADMINS        	(000000200H)
#Define DOMAIN_GROUP_RID_USERS         	(000000201H)
#Define DOMAIN_GROUP_RID_GUESTS        	(000000202H)
#Define DOMAIN_GROUP_RID_COMPUTERS     	(000000203H)
#Define DOMAIN_GROUP_RID_CONTROLLERS   	(000000204H)
#Define DOMAIN_GROUP_RID_CERT_ADMINS   	(000000205H)
#Define DOMAIN_GROUP_RID_SCHEMA_ADMINS 	(000000206H)


#Define DOMAIN_ALIAS_RID_ADMINS        	(000000220H)
#Define DOMAIN_ALIAS_RID_USERS         	(000000221H)
#Define DOMAIN_ALIAS_RID_GUESTS        	(000000222H)
#Define DOMAIN_ALIAS_RID_POWER_USERS   	(000000223H)

#Define DOMAIN_ALIAS_RID_ACCOUNT_OPS   	(000000224H)
#Define DOMAIN_ALIAS_RID_SYSTEM_OPS    	(000000225H)
#Define DOMAIN_ALIAS_RID_PRINT_OPS     	(000000226H)
#Define DOMAIN_ALIAS_RID_BACKUP_OPS    	(000000227H)

#Define DOMAIN_ALIAS_RID_REPLICATOR    	(000000228H)

#Define SYSTEM_LUID             		<03E7H, 00H>
#Define ANONYMOUS_LOGON_LUID            <03E6H, 00H>

#Define SE_GROUP_MANDATORY              (000000001H)
#Define SE_GROUP_ENABLED_BY_DEFAULT     (000000002H)
#Define SE_GROUP_ENABLED                (000000004H)
#Define SE_GROUP_OWNER                  (000000008H)
#Define SE_GROUP_USE_FOR_DENY_ONLY      (000000010H)
#Define SE_GROUP_LOGON_ID               (0C0000000H)

#Define ACL_REVISION     		(2)
#Define ACL_REVISION_DS  		(4)

#Define ACL_REVISION1   		(1)
#Define MIN_ACL_REVISION		ACL_REVISION2
#Define ACL_REVISION2   		(2)
#Define ACL_REVISION3   		(3)
#Define ACL_REVISION4   		(4)
#Define MAX_ACL_REVISION		ACL_REVISION4

#Define ACCESS_MIN_MS_ACE_TYPE        		(00H)
#Define ACCESS_ALLOWED_ACE_TYPE             (00H)
#Define ACCESS_DENIED_ACE_TYPE              (01H)
#Define SYSTEM_AUDIT_ACE_TYPE               (02H)
#Define SYSTEM_ALARM_ACE_TYPE               (03H)
#Define ACCESS_MAX_MS_V2_ACE_TYPE           (03H)

#Define ACCESS_ALLOWED_COMPOUND_ACE_TYPE    (04H)
#Define ACCESS_MAX_MS_V3_ACE_TYPE           (04H)

#Define ACCESS_MIN_MS_OBJECT_ACE_TYPE       (05H)
#Define ACCESS_ALLOWED_OBJECT_ACE_TYPE      (05H)
#Define ACCESS_DENIED_OBJECT_ACE_TYPE       (06H)
#Define SYSTEM_AUDIT_OBJECT_ACE_TYPE        (07H)
#Define SYSTEM_ALARM_OBJECT_ACE_TYPE        (08H)
#Define ACCESS_MAX_MS_OBJECT_ACE_TYPE       (08H)

#Define ACCESS_MAX_MS_V4_ACE_TYPE           (08H)
#Define ACCESS_MAX_MS_ACE_TYPE              (08H)

#Define OBJECT_INHERIT_ACE				(01H)
#Define CONTAINER_INHERIT_ACE           (02H)
#Define NO_PROPAGATE_INHERIT_ACE        (04H)
#Define INHERIT_ONLY_ACE                (08H)
#Define INHERITED_ACE                   (010H)
#Define VALID_INHERIT_FLAGS             (01FH)

#Define SUCCESSFUL_ACCESS_ACE_FLAG      (040H)
#Define FAILED_ACCESS_ACE_FLAG          (080H)

#Define ACE_OBJECT_TYPE_PRESENT           	01H
#Define ACE_INHERITED_OBJECT_TYPE_PRESENT	02H

;ACL_INFORMATION_CLASS enumeration
AclRevisionInformation			Equ 1
AclSizeInformation				Equ 2

#Define SECURITY_DESCRIPTOR_REVISION	1
#Define SECURITY_DESCRIPTOR_REVISION1   1

#Define SECURITY_DESCRIPTOR_MIN_LENGTH	SizeOf SECURITY_DESCRIPTOR

#Define SE_OWNER_DEFAULTED          (00001H)
#Define SE_GROUP_DEFAULTED          (00002H)
#Define SE_DACL_PRESENT             (00004H)
#Define SE_DACL_DEFAULTED           (00008H)
#Define SE_SACL_PRESENT             (00010H)
#Define SE_SACL_DEFAULTED           (00020H)
#Define SE_DACL_AUTO_INHERIT_REQ    (00100H)
#Define SE_SACL_AUTO_INHERIT_REQ    (00200H)
#Define SE_DACL_AUTO_INHERITED      (00400H)
#Define SE_SACL_AUTO_INHERITED      (00800H)
#Define SE_DACL_PROTECTED           (01000H)
#Define SE_SACL_PROTECTED           (02000H)
#Define SE_SELF_RELATIVE			(08000H)

#Define ACCESS_OBJECT_GUID       	0
#Define ACCESS_PROPERTY_SET_GUID 	1
#Define ACCESS_PROPERTY_GUID     	2

#Define ACCESS_MAX_LEVEL         	4

;AUDIT_EVENT_TYPE enumeration
AuditEventObjectAccess				Equ 0
AuditEventDirectoryServiceAccess	Equ 1

#Define AUDIT_ALLOW_NO_PRIVILEGE	01H

#Define ACCESS_DS_SOURCE_A				"DS"
#Define ACCESS_DS_SOURCE_W				L"DS"
#Define ACCESS_DS_OBJECT_TYPE_NAME_A	"Directory Service Object"
#Define ACCESS_DS_OBJECT_TYPE_NAME_W	L"Directory Service Object"

#Define SE_PRIVILEGE_ENABLED_BY_DEFAULT (000000001H)
#Define SE_PRIVILEGE_ENABLED            (000000002H)
#Define SE_PRIVILEGE_USED_FOR_ACCESS    (080000000H)

#IF STRINGS UNICODE
	#Define SE_CREATE_TOKEN_NAME        L"SeCreateTokenPrivilege"
	#Define SE_ASSIGNPRIMARYTOKEN_NAME  L"SeAssignPrimaryTokenPrivilege"
	#Define SE_LOCK_MEMORY_NAME         L"SeLockMemoryPrivilege"
	#Define SE_INCREASE_QUOTA_NAME      L"SeIncreaseQuotaPrivilege"
	#Define SE_UNSOLICITED_INPUT_NAME   L"SeUnsolicitedInputPrivilege"
	#Define SE_MACHINE_ACCOUNT_NAME     L"SeMachineAccountPrivilege"
	#Define SE_TCB_NAME                 L"SeTcbPrivilege"
	#Define SE_SECURITY_NAME            L"SeSecurityPrivilege"
	#Define SE_TAKE_OWNERSHIP_NAME      L"SeTakeOwnershipPrivilege"
	#Define SE_LOAD_DRIVER_NAME         L"SeLoadDriverPrivilege"
	#Define SE_SYSTEM_PROFILE_NAME      L"SeSystemProfilePrivilege"
	#Define SE_SYSTEMTIME_NAME          L"SeSystemtimePrivilege"
	#Define SE_PROF_SINGLE_PROCESS_NAME L"SeProfileSingleProcessPrivilege"
	#Define SE_INC_BASE_PRIORITY_NAME   L"SeIncreaseBasePriorityPrivilege"
	#Define SE_CREATE_PAGEFILE_NAME     L"SeCreatePagefilePrivilege"
	#Define SE_CREATE_PERMANENT_NAME    L"SeCreatePermanentPrivilege"
	#Define SE_BACKUP_NAME              L"SeBackupPrivilege"
	#Define SE_RESTORE_NAME             L"SeRestorePrivilege"
	#Define SE_SHUTDOWN_NAME            L"SeShutdownPrivilege"
	#Define SE_DEBUG_NAME               L"SeDebugPrivilege"
	#Define SE_AUDIT_NAME               L"SeAuditPrivilege"
	#Define SE_SYSTEM_ENVIRONMENT_NAME  L"SeSystemEnvironmentPrivilege"
	#Define SE_CHANGE_NOTIFY_NAME       L"SeChangeNotifyPrivilege"
	#Define SE_REMOTE_SHUTDOWN_NAME     L"SeRemoteShutdownPrivilege"
#ELSE
	#Define SE_CREATE_TOKEN_NAME        "SeCreateTokenPrivilege"
	#Define SE_ASSIGNPRIMARYTOKEN_NAME  "SeAssignPrimaryTokenPrivilege"
	#Define SE_LOCK_MEMORY_NAME         "SeLockMemoryPrivilege"
	#Define SE_INCREASE_QUOTA_NAME      "SeIncreaseQuotaPrivilege"
	#Define SE_UNSOLICITED_INPUT_NAME   "SeUnsolicitedInputPrivilege"
	#Define SE_MACHINE_ACCOUNT_NAME     "SeMachineAccountPrivilege"
	#Define SE_TCB_NAME                 "SeTcbPrivilege"
	#Define SE_SECURITY_NAME            "SeSecurityPrivilege"
	#Define SE_TAKE_OWNERSHIP_NAME      "SeTakeOwnershipPrivilege"
	#Define SE_LOAD_DRIVER_NAME         "SeLoadDriverPrivilege"
	#Define SE_SYSTEM_PROFILE_NAME      "SeSystemProfilePrivilege"
	#Define SE_SYSTEMTIME_NAME          "SeSystemtimePrivilege"
	#Define SE_PROF_SINGLE_PROCESS_NAME "SeProfileSingleProcessPrivilege"
	#Define SE_INC_BASE_PRIORITY_NAME   "SeIncreaseBasePriorityPrivilege"
	#Define SE_CREATE_PAGEFILE_NAME     "SeCreatePagefilePrivilege"
	#Define SE_CREATE_PERMANENT_NAME    "SeCreatePermanentPrivilege"
	#Define SE_BACKUP_NAME              "SeBackupPrivilege"
	#Define SE_RESTORE_NAME             "SeRestorePrivilege"
	#Define SE_SHUTDOWN_NAME            "SeShutdownPrivilege"
	#Define SE_DEBUG_NAME               "SeDebugPrivilege"
	#Define SE_AUDIT_NAME               "SeAuditPrivilege"
	#Define SE_SYSTEM_ENVIRONMENT_NAME  "SeSystemEnvironmentPrivilege"
	#Define SE_CHANGE_NOTIFY_NAME       "SeChangeNotifyPrivilege"
	#Define SE_REMOTE_SHUTDOWN_NAME     "SeRemoteShutdownPrivilege"
#ENDIF

;SECURITY_IMPERSONATION_LEVEL enumeration
SecurityAnonymous				Equ 1
SecurityIdentification			Equ 2
SecurityImpersonation			Equ 3
SecurityDelegation				Equ 4

#Define SECURITY_MAX_IMPERSONATION_LEVEL	SecurityDelegation
#Define DEFAULT_IMPERSONATION_LEVEL		SecurityImpersonation

#Define TOKEN_ASSIGN_PRIMARY    (00001H)
#Define TOKEN_DUPLICATE         (00002H)
#Define TOKEN_IMPERSONATE       (00004H)
#Define TOKEN_QUERY             (00008H)
#Define TOKEN_QUERY_SOURCE      (00010H)
#Define TOKEN_ADJUST_PRIVILEGES (00020H)
#Define TOKEN_ADJUST_GROUPS     (00040H)
#Define TOKEN_ADJUST_DEFAULT    (00080H)
#Define TOKEN_ADJUST_SESSIONID  (00100H)

#Define TOKEN_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | TOKEN_ASSIGN_PRIMARY | TOKEN_DUPLICATE | TOKEN_IMPERSONATE | TOKEN_QUERY | TOKEN_QUERY_SOURCE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_SESSIONID | TOKEN_ADJUST_DEFAULT)
#Define TOKEN_READ       (STANDARD_RIGHTS_READ | TOKEN_QUERY)
#Define TOKEN_WRITE      (STANDARD_RIGHTS_WRITE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)
#Define TOKEN_EXECUTE    (STANDARD_RIGHTS_EXECUTE)

;TOKEN_TYPE enumeration
TokenPrimary					Equ 1
TokenImpersonation				Equ 2

;TOKEN_INFORMATION_CLASS enumeration
TokenUser						Equ 1
TokenGroups						Equ 2
TokenPrivileges					Equ 3
TokenOwner						Equ 4
TokenPrimaryGroup				Equ 5
TokenDefaultDacl				Equ 6
TokenSource						Equ 7
TokenType						Equ 8
TokenImpersonationLevel			Equ 9
TokenStatistics					Equ 10
TokenRestrictedSids				Equ 11
TokenSessionId					Equ 12

#Define TOKEN_SOURCE_LENGTH		8

#Define SECURITY_DYNAMIC_TRACKING	TRUE
#Define SECURITY_STATIC_TRACKING	FALSE

#Define OWNER_SECURITY_INFORMATION  (000000001H)
#Define GROUP_SECURITY_INFORMATION  (000000002H)
#Define DACL_SECURITY_INFORMATION   (000000004H)
#Define SACL_SECURITY_INFORMATION   (000000008H)
#Define PROCESS_TERMINATE         	(00001H)
#Define PROCESS_CREATE_THREAD     	(00002H)
#Define PROCESS_SET_SESSIONID     	(00004H)
#Define PROCESS_VM_OPERATION      	(00008H)
#Define PROCESS_VM_READ           	(00010H)
#Define PROCESS_VM_WRITE          	(00020H)
#Define PROCESS_DUP_HANDLE        	(00040H)
#Define PROCESS_CREATE_PROCESS    	(00080H)
#Define PROCESS_SET_QUOTA         	(00100H)
#Define PROCESS_SET_INFORMATION   	(00200H)
#Define PROCESS_QUERY_INFORMATION 	(00400H)
#Define PROCESS_ALL_ACCESS        	(STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0FFFH)

#Define MAXIMUM_PROCESSORS 32

#Define THREAD_TERMINATE               	(00001H)
#Define THREAD_SUSPEND_RESUME          	(00002H)
#Define THREAD_GET_CONTEXT             	(00008H)
#Define THREAD_SET_CONTEXT             	(00010H)
#Define THREAD_SET_INFORMATION         	(00020H)
#Define THREAD_QUERY_INFORMATION       	(00040H)
#Define THREAD_SET_THREAD_TOKEN        	(00080H)
#Define THREAD_IMPERSONATE             	(00100H)
#Define THREAD_DIRECT_IMPERSONATION    	(00200H)

#Define THREAD_ALL_ACCESS       (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 03FFH)

#Define JOB_OBJECT_ASSIGN_PROCESS           (00001H)
#Define JOB_OBJECT_SET_ATTRIBUTES           (00002H)
#Define JOB_OBJECT_QUERY                    (00004H)
#Define JOB_OBJECT_TERMINATE                (00008H)
#Define JOB_OBJECT_SET_SECURITY_ATTRIBUTES  (00010H)
#Define JOB_OBJECT_ALL_ACCESS   		    (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 01FH)

#Define TLS_MINIMUM_AVAILABLE 	64

#Define THREAD_BASE_PRIORITY_LOWRT  15
#Define THREAD_BASE_PRIORITY_MAX    2
#Define THREAD_BASE_PRIORITY_MIN    (-2)
#Define THREAD_BASE_PRIORITY_IDLE   (-15)

#Define JOB_OBJECT_TERMINATE_AT_END_OF_JOB	0
#Define JOB_OBJECT_POST_AT_END_OF_JOB       1

#Define JOB_OBJECT_MSG_END_OF_JOB_TIME      1
#Define JOB_OBJECT_MSG_END_OF_PROCESS_TIME  2
#Define JOB_OBJECT_MSG_ACTIVE_PROCESS_LIMIT 3
#Define JOB_OBJECT_MSG_ACTIVE_PROCESS_ZERO  4


#Define JOB_OBJECT_LIMIT_WORKINGSET         000000001H
#Define JOB_OBJECT_LIMIT_PROCESS_TIME       000000002H
#Define JOB_OBJECT_LIMIT_JOB_TIME           000000004H
#Define JOB_OBJECT_LIMIT_ACTIVE_PROCESS     000000008H
#Define JOB_OBJECT_LIMIT_AFFINITY           000000010H
#Define JOB_OBJECT_LIMIT_PRIORITY_CLASS     000000020H
#Define JOB_OBJECT_LIMIT_PRESERVE_JOB_TIME  000000040H

#Define JOB_OBJECT_LIMIT_VALID_FLAGS        00000007FH

#Define JOB_OBJECT_UILIMIT_NONE             000000000H

#Define JOB_OBJECT_UILIMIT_HANDLES          000000001H
#Define JOB_OBJECT_UILIMIT_READCLIPBOARD    000000002H
#Define JOB_OBJECT_UILIMIT_WRITECLIPBOARD   000000004H
#Define JOB_OBJECT_UILIMIT_SYSTEMPARAMETERS 000000008H
#Define JOB_OBJECT_UILIMIT_DISPLAYSETTINGS  000000010H
#Define JOB_OBJECT_UILIMIT_GLOBALATOMS      000000020H
#Define JOB_OBJECT_UILIMIT_DESKTOP          000000040H
#Define JOB_OBJECT_UILIMIT_EXITWINDOWS      000000080H

#Define JOB_OBJECT_UILIMIT_ALL              0000000FFH

#Define JOB_OBJECT_UI_VALID_FLAGS           0000000FFH

#Define JOB_OBJECT_SECURITY_NO_ADMIN			000000001H
#Define JOB_OBJECT_SECURITY_RESTRICTED_TOKEN	000000002H
#Define JOB_OBJECT_SECURITY_ONLY_TOKEN          000000004H
#Define JOB_OBJECT_SECURITY_FILTER_TOKENS       000000008H

#Define JOB_OBJECT_SECURITY_VALID_FLAGS         00000000FH

;JOBOBJECTINFOCLASS enumeration
JobObjectBasicAccountingInformation			Equ 1
JobObjectBasicLimitInformation				Equ 2
JobObjectBasicProcessIdList					Equ 3
JobObjectBasicUIRestrictions				Equ 4
JobObjectSecurityLimitInformation			Equ 5
JobObjectEndOfJobTimeInformation			Equ 6
JobObjectAssociateCompletionPortInformation	Equ 7
MaxJobObjectInfoClass						Equ 8

#Define EVENT_MODIFY_STATE      00002H
#Define EVENT_ALL_ACCESS		(STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 03H)
#Define MUTANT_QUERY_STATE      00001H

#Define MUTANT_ALL_ACCESS		(STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | MUTANT_QUERY_STATE)
#Define SEMAPHORE_MODIFY_STATE  00002H
#Define SEMAPHORE_ALL_ACCESS	(STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 03H)

#Define TIMER_QUERY_STATE       00001H
#Define TIMER_MODIFY_STATE		00002H

#Define TIMER_ALL_ACCESS		(STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | TIMER_QUERY_STATE | TIMER_MODIFY_STATE)


#Define TIME_ZONE_ID_UNKNOWN  	0
#Define TIME_ZONE_ID_STANDARD 	1
#Define TIME_ZONE_ID_DAYLIGHT 	2

#Define PROCESSOR_INTEL_386     386
#Define PROCESSOR_INTEL_486     486
#Define PROCESSOR_INTEL_PENTIUM 586
#Define PROCESSOR_MIPS_R4000    4000
#Define PROCESSOR_ALPHA_21064   21064
#Define PROCESSOR_PPC_601       601
#Define PROCESSOR_PPC_603       603
#Define PROCESSOR_PPC_604       604
#Define PROCESSOR_PPC_620       620
#Define PROCESSOR_HITACHI_SH3   10003
#Define PROCESSOR_HITACHI_SH3E  10004
#Define PROCESSOR_HITACHI_SH4   10005
#Define PROCESSOR_MOTOROLA_821	821
#Define PROCESSOR_SHx_SH3       103
#Define PROCESSOR_SHx_SH4       104
#Define PROCESSOR_STRONGARM     2577
#Define PROCESSOR_ARM720        1824
#Define PROCESSOR_ARM820        2080
#Define PROCESSOR_ARM920        2336
#Define PROCESSOR_ARM_7TDMI     70001

#Define PROCESSOR_ARCHITECTURE_INTEL 		0
#Define PROCESSOR_ARCHITECTURE_MIPS  		1
#Define PROCESSOR_ARCHITECTURE_ALPHA 		2
#Define PROCESSOR_ARCHITECTURE_PPC   		3
#Define PROCESSOR_ARCHITECTURE_SHX   		4
#Define PROCESSOR_ARCHITECTURE_ARM			5
#Define PROCESSOR_ARCHITECTURE_IA64			6
#Define PROCESSOR_ARCHITECTURE_ALPHA64		7
#Define PROCESSOR_ARCHITECTURE_UNKNOWN		0FFFFH

#Define PF_FLOATING_POINT_PRECISION_ERRATA  0
#Define PF_FLOATING_POINT_EMULATED          1
#Define PF_COMPARE_EXCHANGE_DOUBLE          2
#Define PF_MMX_INSTRUCTIONS_AVAILABLE       3
#Define PF_PPC_MOVEMEM_64BIT_OK             4
#Define PF_ALPHA_BYTE_INSTRUCTIONS          5
#Define PF_XMMI_INSTRUCTIONS_AVAILABLE      6
#Define PF_AMD3D_INSTRUCTIONS_AVAILABLE     7
#Define SYSTEM_FLAG_REMOTE_BOOT_CLIENT		000000001H
#Define SYSTEM_FLAG_DISKLESS_CLIENT			000000002H

#Define SECTION_QUERY       	00001H
#Define SECTION_MAP_WRITE   	00002H
#Define SECTION_MAP_READ    	00004H
#Define SECTION_MAP_EXECUTE 	00008H
#Define SECTION_EXTEND_SIZE		00010H

#Define SECTION_ALL_ACCESS		(STANDARD_RIGHTS_REQUIRED | SECTION_QUERY | SECTION_MAP_WRITE | SECTION_MAP_READ | SECTION_MAP_EXECUTE | SECTION_EXTEND_SIZE)

#Define PAGE_NOACCESS          	001H
#Define PAGE_READONLY          	002H
#Define PAGE_READWRITE         	004H
#Define PAGE_WRITECOPY         	008H
#Define PAGE_EXECUTE           	010H
#Define PAGE_EXECUTE_READ      	020H
#Define PAGE_EXECUTE_READWRITE 	040H
#Define PAGE_EXECUTE_WRITECOPY 	080H
#Define PAGE_GUARD            	0100H
#Define PAGE_NOCACHE          	0200H
#Define PAGE_WRITECOMBINE     	0400H
#Define MEM_COMMIT           	01000H
#Define MEM_RESERVE          	02000H
#Define MEM_DECOMMIT         	04000H
#Define MEM_RELEASE          	08000H
#Define MEM_FREE            	010000H
#Define MEM_PRIVATE         	020000H
#Define MEM_MAPPED          	040000H
#Define MEM_RESET           	080000H
#Define MEM_TOP_DOWN       		0100000H
#Define MEM_4MB_PAGES    		080000000H
#Define SEC_FILE           		0800000H
#Define SEC_IMAGE         		01000000H
#Define SEC_VLM           		02000000H
#Define SEC_RESERVE       		04000000H
#Define SEC_COMMIT        		08000000H
#Define SEC_NOCACHE      		010000000H
#Define MEM_IMAGE         		SEC_IMAGE

#Define FILE_READ_DATA          00001H
#Define FILE_LIST_DIRECTORY     00001H

#Define FILE_WRITE_DATA           	00002H
#Define FILE_ADD_FILE             	00002H
#Define FILE_APPEND_DATA          	00004H
#Define FILE_ADD_SUBDIRECTORY     	00004H
#Define FILE_CREATE_PIPE_INSTANCE	00004H


#Define FILE_READ_EA            00008H
#Define FILE_WRITE_EA           00010H
#Define FILE_EXECUTE            00020H
#Define FILE_TRAVERSE           00020H
#Define FILE_DELETE_CHILD       00040H
#Define FILE_READ_ATTRIBUTES    00080H
#Define FILE_WRITE_ATTRIBUTES	00100H

#Define FILE_ALL_ACCESS			(STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 03FFH)
#Define FILE_GENERIC_READ       (STANDARD_RIGHTS_READ | FILE_READ_DATA | FILE_READ_ATTRIBUTES | FILE_READ_EA | SYNCHRONIZE)
#Define FILE_GENERIC_WRITE      (STANDARD_RIGHTS_WRITE | FILE_WRITE_DATA | FILE_WRITE_ATTRIBUTES | FILE_WRITE_EA | FILE_APPEND_DATA | SYNCHRONIZE)
#Define FILE_GENERIC_EXECUTE    (STANDARD_RIGHTS_EXECUTE  | FILE_READ_ATTRIBUTES | FILE_EXECUTE | SYNCHRONIZE)

#Define FILE_SHARE_READ                 000000001
#Define FILE_SHARE_WRITE                000000002
#Define FILE_SHARE_DELETE               000000004H
#Define FILE_ATTRIBUTE_READONLY         000000001H
#Define FILE_ATTRIBUTE_HIDDEN           000000002H
#Define FILE_ATTRIBUTE_SYSTEM           000000004H
#Define FILE_ATTRIBUTE_DIRECTORY        000000010H
#Define FILE_ATTRIBUTE_ARCHIVE          000000020H
#Define FILE_ATTRIBUTE_ENCRYPTED        000000040H
#Define FILE_ATTRIBUTE_NORMAL           000000080H
#Define FILE_ATTRIBUTE_TEMPORARY        000000100H
#Define FILE_ATTRIBUTE_SPARSE_FILE      000000200H
#Define FILE_ATTRIBUTE_REPARSE_POINT    000000400H
#Define FILE_ATTRIBUTE_COMPRESSED       000000800H
#Define FILE_ATTRIBUTE_OFFLINE          000001000H
#Define FILE_ATTRIBUTE_NOT_CONTENT_INDEXED  000002000H
#Define FILE_NOTIFY_CHANGE_FILE_NAME    000000001H
#Define FILE_NOTIFY_CHANGE_DIR_NAME     000000002H
#Define FILE_NOTIFY_CHANGE_ATTRIBUTES   000000004H
#Define FILE_NOTIFY_CHANGE_SIZE         000000008H
#Define FILE_NOTIFY_CHANGE_LAST_WRITE   000000010H
#Define FILE_NOTIFY_CHANGE_LAST_ACCESS  000000020H
#Define FILE_NOTIFY_CHANGE_CREATION     000000040H
#Define FILE_NOTIFY_CHANGE_SECURITY     000000100H
#Define FILE_ACTION_ADDED               000000001H
#Define FILE_ACTION_REMOVED             000000002H
#Define FILE_ACTION_MODIFIED            000000003H
#Define FILE_ACTION_RENAMED_OLD_NAME    000000004H
#Define FILE_ACTION_RENAMED_NEW_NAME    000000005H
#Define MAILSLOT_NO_MESSAGE             (-1)
#Define MAILSLOT_WAIT_FOREVER           (-1)
#Define FILE_CASE_SENSITIVE_SEARCH      000000001H
#Define FILE_CASE_PRESERVED_NAMES       000000002H
#Define FILE_UNICODE_ON_DISK            000000004H
#Define FILE_PERSISTENT_ACLS            000000008H
#Define FILE_FILE_COMPRESSION           000000010H
#Define FILE_VOLUME_QUOTAS              000000020H
#Define FILE_SUPPORTS_SPARSE_FILES      000000040H
#Define FILE_SUPPORTS_REPARSE_POINTS    000000080H
#Define FILE_SUPPORTS_REMOTE_STORAGE    000000100H
#Define FILE_VOLUME_IS_COMPRESSED       000008000H
#Define FILE_SUPPORTS_OBJECT_IDS        000010000H
#Define FILE_SUPPORTS_ENCRYPTION		000020000H

#Define MAXIMUM_REPARSE_DATA_BUFFER_SIZE	(16 * 1024)

#Define IO_REPARSE_TAG_RESERVED_ZERO	0
#Define IO_REPARSE_TAG_RESERVED_ONE     1
#Define IO_REPARSE_TAG_RESERVED_RANGE   IO_REPARSE_TAG_RESERVED_ONE
#Define IO_REPARSE_TAG_VALID_VALUES     0E000FFFFH

#Define IO_REPARSE_TAG_SYMBOLIC_LINK    IO_REPARSE_TAG_RESERVED_ZERO
#Define IO_REPARSE_TAG_MOUNT_POINT      0A0000003H
#Define IO_REPARSE_TAG_HSM              0C0000004H
#Define IO_REPARSE_TAG_NSS              080000005H
#Define IO_REPARSE_TAG_NSSRECOVER       080000006H
#Define IO_REPARSE_TAG_SIS              080000007H
#Define IO_REPARSE_TAG_DFS              080000008H

#Define IO_COMPLETION_MODIFY_STATE		00002H
#Define IO_COMPLETION_ALL_ACCESS		(STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 03H)
#Define DUPLICATE_CLOSE_SOURCE      	000000001H
#Define DUPLICATE_SAME_ACCESS       	000000002H

#Define ES_SYSTEM_REQUIRED  			000000001H
#Define ES_DISPLAY_REQUIRED 			000000002H
#Define ES_USER_PRESENT     			000000004H
#Define ES_CONTINUOUS       			080000000H

;LATENCY_TIME enumeration
LT_DONT_CARE					Equ 1
LT_LOWEST_LATENCY				Equ 2

#Define IMAGE_DOS_SIGNATURE		05A4DH
#Define IMAGE_OS2_SIGNATURE     0454EH
#Define IMAGE_OS2_SIGNATURE_LE  0454CH
#Define IMAGE_VXD_SIGNATURE     0454CH
#Define IMAGE_NT_SIGNATURE      000004550H

#Define IMAGE_SIZEOF_FILE_HEADER             20


#Define IMAGE_FILE_RELOCS_STRIPPED          00001H
#Define IMAGE_FILE_EXECUTABLE_IMAGE         00002H
#Define IMAGE_FILE_LINE_NUMS_STRIPPED       00004H
#Define IMAGE_FILE_LOCAL_SYMS_STRIPPED      00008H
#Define IMAGE_FILE_AGGRESIVE_WS_TRIM        00010H
#Define IMAGE_FILE_LARGE_ADDRESS_AWARE      00020H
#Define IMAGE_FILE_BYTES_REVERSED_LO        00080H
#Define IMAGE_FILE_32BIT_MACHINE            00100H
#Define IMAGE_FILE_DEBUG_STRIPPED           00200H
#Define IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP  00400H
#Define IMAGE_FILE_NET_RUN_FROM_SWAP        00800H
#Define IMAGE_FILE_SYSTEM                   01000H
#Define IMAGE_FILE_DLL                      02000H
#Define IMAGE_FILE_UP_SYSTEM_ONLY           04000H
#Define IMAGE_FILE_BYTES_REVERSED_HI    	08000H

#Define IMAGE_FILE_MACHINE_UNKNOWN      0
#Define IMAGE_FILE_MACHINE_I386         0014CH
#Define IMAGE_FILE_MACHINE_R3000        00162H
#Define IMAGE_FILE_MACHINE_R4000        00166H
#Define IMAGE_FILE_MACHINE_R10000       00168H
#Define IMAGE_FILE_MACHINE_WCEMIPSV2    00169H
#Define IMAGE_FILE_MACHINE_ALPHA        00184H
#Define IMAGE_FILE_MACHINE_POWERPC      001F0H
#Define IMAGE_FILE_MACHINE_SH3          001A2H
#Define IMAGE_FILE_MACHINE_SH3E         001A4H
#Define IMAGE_FILE_MACHINE_SH4          001A6H
#Define IMAGE_FILE_MACHINE_ARM          001C0H
#Define IMAGE_FILE_MACHINE_THUMB        001C2H
#Define IMAGE_FILE_MACHINE_IA64         00200H
#Define IMAGE_FILE_MACHINE_MIPS16       00266H
#Define IMAGE_FILE_MACHINE_MIPSFPU      00366H
#Define IMAGE_FILE_MACHINE_MIPSFPU16    00466H
#Define IMAGE_FILE_MACHINE_ALPHA64      00284H
#Define IMAGE_FILE_MACHINE_AXP64		IMAGE_FILE_MACHINE_ALPHA64

#Define IMAGE_NUMBEROF_DIRECTORY_ENTRIES	16

#Define IMAGE_SIZEOF_ROM_OPTIONAL_HEADER	56
#Define IMAGE_SIZEOF_STD_OPTIONAL_HEADER    28
#Define IMAGE_SIZEOF_NT_OPTIONAL32_HEADER   224
#Define IMAGE_SIZEOF_NT_OPTIONAL64_HEADER   240

#Define IMAGE_NT_OPTIONAL_HDR32_MAGIC      	010BH
#Define IMAGE_NT_OPTIONAL_HDR64_MAGIC      	020BH
#Define IMAGE_ROM_OPTIONAL_HDR_MAGIC       	0107H

#IF x64
	#Define IMAGE_OPTIONAL_HEADER64			IMAGE_OPTIONAL_HEADER
	#Define PIMAGE_OPTIONAL_HEADER64        PIMAGE_OPTIONAL_HEADER
	#Define IMAGE_SIZEOF_NT_OPTIONAL_HEADER IMAGE_SIZEOF_NT_OPTIONAL64_HEADER
	#Define IMAGE_NT_OPTIONAL_HDR_MAGIC     IMAGE_NT_OPTIONAL_HDR64_MAGIC
	#Define IMAGE_NT_HEADERS64         		IMAGE_NT_HEADERS
	#Define PIMAGE_NT_HEADERS64             PIMAGE_NT_HEADERS
#ELSE
	#Define IMAGE_OPTIONAL_HEADER32         IMAGE_OPTIONAL_HEADER
	#Define PIMAGE_OPTIONAL_HEADER32        PIMAGE_OPTIONAL_HEADER
	#Define IMAGE_SIZEOF_NT_OPTIONAL_HEADER	IMAGE_SIZEOF_NT_OPTIONAL32_HEADER
	#Define IMAGE_NT_OPTIONAL_HDR_MAGIC     IMAGE_NT_OPTIONAL_HDR32_MAGIC
	#Define IMAGE_NT_HEADERS32              IMAGE_NT_HEADERS
	#Define PIMAGE_NT_HEADERS32             PIMAGE_NT_HEADERS
#ENDIF

#Define IMAGE_SUBSYSTEM_UNKNOWN				0
#Define IMAGE_SUBSYSTEM_NATIVE              1
#Define IMAGE_SUBSYSTEM_WINDOWS_GUI         2
#Define IMAGE_SUBSYSTEM_WINDOWS_CUI         3
#Define IMAGE_SUBSYSTEM_OS2_CUI             5
#Define IMAGE_SUBSYSTEM_POSIX_CUI           7
#Define IMAGE_SUBSYSTEM_NATIVE_WINDOWS      8
#Define IMAGE_SUBSYSTEM_WINDOWS_CE_GUI      9

#Define IMAGE_DLLCHARACTERISTICS_WDM_DRIVER	02000H

#Define IMAGE_DIRECTORY_ENTRY_EXPORT          	0
#Define IMAGE_DIRECTORY_ENTRY_IMPORT          	1
#Define IMAGE_DIRECTORY_ENTRY_RESOURCE        	2
#Define IMAGE_DIRECTORY_ENTRY_EXCEPTION       	3
#Define IMAGE_DIRECTORY_ENTRY_SECURITY        	4
#Define IMAGE_DIRECTORY_ENTRY_BASERELOC       	5
#Define IMAGE_DIRECTORY_ENTRY_DEBUG           	6
#Define IMAGE_DIRECTORY_ENTRY_ARCHITECTURE    	7
#Define IMAGE_DIRECTORY_ENTRY_GLOBALPTR       	8
#Define IMAGE_DIRECTORY_ENTRY_TLS             	9
#Define IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG    	10
#Define IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT   	11
#Define IMAGE_DIRECTORY_ENTRY_IAT            	12
#Define IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT   	13
#Define IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR	14

#Define IMAGE_SIZEOF_SHORT_NAME				8
#Define IMAGE_SIZEOF_SECTION_HEADER			40

#Define IMAGE_SCN_TYPE_NO_PAD           	000000008H

#Define IMAGE_SCN_CNT_CODE              	000000020H
#Define IMAGE_SCN_CNT_INITIALIZED_DATA		000000040H
#Define IMAGE_SCN_CNT_UNINITIALIZED_DATA	000000080H

#Define IMAGE_SCN_LNK_OTHER					000000100H
#Define IMAGE_SCN_LNK_INFO					000000200H
#Define IMAGE_SCN_LNK_REMOVE				000000800H
#Define IMAGE_SCN_LNK_COMDAT				000001000H
#Define IMAGE_SCN_NO_DEFER_SPEC_EXC         000004000H
#Define IMAGE_SCN_GPREL                     000008000H
#Define IMAGE_SCN_MEM_FARDATA               000008000H
#Define IMAGE_SCN_MEM_PURGEABLE             000020000H
#Define IMAGE_SCN_MEM_16BIT                 000020000H
#Define IMAGE_SCN_MEM_LOCKED                000040000H
#Define IMAGE_SCN_MEM_PRELOAD               000080000H
#Define IMAGE_SCN_ALIGN_1BYTES              000100000H
#Define IMAGE_SCN_ALIGN_2BYTES              000200000H
#Define IMAGE_SCN_ALIGN_4BYTES              000300000H
#Define IMAGE_SCN_ALIGN_8BYTES              000400000H
#Define IMAGE_SCN_ALIGN_16BYTES             000500000H
#Define IMAGE_SCN_ALIGN_32BYTES             000600000H
#Define IMAGE_SCN_ALIGN_64BYTES             000700000H
#Define IMAGE_SCN_ALIGN_128BYTES            000800000H
#Define IMAGE_SCN_ALIGN_256BYTES            000900000H
#Define IMAGE_SCN_ALIGN_512BYTES            000A00000H
#Define IMAGE_SCN_ALIGN_1024BYTES           000B00000H
#Define IMAGE_SCN_ALIGN_2048BYTES           000C00000H
#Define IMAGE_SCN_ALIGN_4096BYTES           000D00000H
#Define IMAGE_SCN_ALIGN_8192BYTES           000E00000H
#Define IMAGE_SCN_LNK_NRELOC_OVFL           001000000H
#Define IMAGE_SCN_MEM_DISCARDABLE           002000000H
#Define IMAGE_SCN_MEM_NOT_CACHED            004000000H
#Define IMAGE_SCN_MEM_NOT_PAGED             008000000H
#Define IMAGE_SCN_MEM_SHARED                010000000H
#Define IMAGE_SCN_MEM_EXECUTE               020000000H
#Define IMAGE_SCN_MEM_READ                  040000000H
#Define IMAGE_SCN_MEM_WRITE                 080000000H
#Define IMAGE_SCN_SCALE_INDEX               000000001H

#Define IMAGE_SIZEOF_SYMBOL                 18

#Define IMAGE_SYM_UNDEFINED				0
#Define IMAGE_SYM_ABSOLUTE            	(-1)
#Define IMAGE_SYM_DEBUG               	(-2)
#Define IMAGE_SYM_TYPE_NULL             00000H
#Define IMAGE_SYM_TYPE_VOID             00001H
#Define IMAGE_SYM_TYPE_CHAR             00002H
#Define IMAGE_SYM_TYPE_SHORT            00003H
#Define IMAGE_SYM_TYPE_INT              00004H
#Define IMAGE_SYM_TYPE_LONG             00005H
#Define IMAGE_SYM_TYPE_FLOAT            00006H
#Define IMAGE_SYM_TYPE_DOUBLE           00007H
#Define IMAGE_SYM_TYPE_STRUCT           00008H
#Define IMAGE_SYM_TYPE_UNION            00009H
#Define IMAGE_SYM_TYPE_ENUM             0000AH
#Define IMAGE_SYM_TYPE_MOE              0000BH
#Define IMAGE_SYM_TYPE_BYTE             0000CH
#Define IMAGE_SYM_TYPE_WORD             0000DH
#Define IMAGE_SYM_TYPE_UINT             0000EH
#Define IMAGE_SYM_TYPE_DWORD            0000FH
#Define IMAGE_SYM_TYPE_PCODE            08000H

#Define IMAGE_SYM_DTYPE_NULL            0
#Define IMAGE_SYM_DTYPE_POINTER         1
#Define IMAGE_SYM_DTYPE_FUNCTION        2
#Define IMAGE_SYM_DTYPE_ARRAY           3

#Define IMAGE_SYM_CLASS_END_OF_FUNCTION     (-1)
#Define IMAGE_SYM_CLASS_NULL                00000H
#Define IMAGE_SYM_CLASS_AUTOMATIC           00001H
#Define IMAGE_SYM_CLASS_EXTERNAL            00002H
#Define IMAGE_SYM_CLASS_STATIC              00003H
#Define IMAGE_SYM_CLASS_REGISTER            00004H
#Define IMAGE_SYM_CLASS_EXTERNAL_DEF        00005H
#Define IMAGE_SYM_CLASS_LABEL               00006H
#Define IMAGE_SYM_CLASS_UNDEFINED_LABEL     00007H
#Define IMAGE_SYM_CLASS_MEMBER_OF_STRUCT    00008H
#Define IMAGE_SYM_CLASS_ARGUMENT            00009H
#Define IMAGE_SYM_CLASS_STRUCT_TAG          0000AH
#Define IMAGE_SYM_CLASS_MEMBER_OF_UNION     0000BH
#Define IMAGE_SYM_CLASS_UNION_TAG           0000CH
#Define IMAGE_SYM_CLASS_TYPE_DEFINITION     0000DH
#Define IMAGE_SYM_CLASS_UNDEFINED_STATIC    0000EH
#Define IMAGE_SYM_CLASS_ENUM_TAG            0000FH
#Define IMAGE_SYM_CLASS_MEMBER_OF_ENUM      00010H
#Define IMAGE_SYM_CLASS_REGISTER_PARAM      00011H
#Define IMAGE_SYM_CLASS_BIT_FIELD           00012H

#Define IMAGE_SYM_CLASS_FAR_EXTERNAL        00044H

#Define IMAGE_SYM_CLASS_BLOCK               00064H
#Define IMAGE_SYM_CLASS_FUNCTION            00065H
#Define IMAGE_SYM_CLASS_END_OF_STRUCT		00066H
#Define IMAGE_SYM_CLASS_FILE                00067H

#Define IMAGE_SYM_CLASS_SECTION             00068H
#Define IMAGE_SYM_CLASS_WEAK_EXTERNAL       00069H

#Define N_BTMASK                            0000FH
#Define N_TMASK                             00030H
#Define N_TMASK1                            000C0H
#Define N_TMASK2                            000F0H
#define N_BTSHFT                            4
#define N_TSHIFT                            2

#Define IMAGE_SIZEOF_AUX_SYMBOL             18

#Define IMAGE_COMDAT_SELECT_NODUPLICATES    1
#Define IMAGE_COMDAT_SELECT_ANY             2
#Define IMAGE_COMDAT_SELECT_SAME_SIZE       3
#Define IMAGE_COMDAT_SELECT_EXACT_MATCH     4
#Define IMAGE_COMDAT_SELECT_ASSOCIATIVE     5
#Define IMAGE_COMDAT_SELECT_LARGEST         6
#Define IMAGE_COMDAT_SELECT_NEWEST          7

#Define IMAGE_WEAK_EXTERN_SEARCH_NOLIBRARY  1
#Define IMAGE_WEAK_EXTERN_SEARCH_LIBRARY    2
#Define IMAGE_WEAK_EXTERN_SEARCH_ALIAS      3

#Define IMAGE_SIZEOF_RELOCATION         	10

#Define IMAGE_REL_I386_ABSOLUTE			00000H
#Define IMAGE_REL_I386_DIR16            00001H
#Define IMAGE_REL_I386_REL16            00002H
#Define IMAGE_REL_I386_DIR32            00006H
#Define IMAGE_REL_I386_DIR32NB          00007H
#Define IMAGE_REL_I386_SEG12            00009H
#Define IMAGE_REL_I386_SECTION          0000AH
#Define IMAGE_REL_I386_SECREL           0000BH
#Define IMAGE_REL_I386_REL32            00014H

#Define IMAGE_REL_MIPS_ABSOLUTE         00000H
#Define IMAGE_REL_MIPS_REFHALF          00001H
#Define IMAGE_REL_MIPS_REFWORD          00002H
#Define IMAGE_REL_MIPS_JMPADDR          00003H
#Define IMAGE_REL_MIPS_REFHI            00004H
#Define IMAGE_REL_MIPS_REFLO            00005H
#Define IMAGE_REL_MIPS_GPREL            00006H
#Define IMAGE_REL_MIPS_LITERAL          00007H
#Define IMAGE_REL_MIPS_SECTION          0000AH
#Define IMAGE_REL_MIPS_SECREL           0000BH
#Define IMAGE_REL_MIPS_SECRELLO         0000CH
#Define IMAGE_REL_MIPS_SECRELHI         0000DH
#Define IMAGE_REL_MIPS_JMPADDR16        00010H
#Define IMAGE_REL_MIPS_REFWORDNB        00022H
#Define IMAGE_REL_MIPS_PAIR             00025H

#Define IMAGE_REL_ALPHA_ABSOLUTE        00000H
#Define IMAGE_REL_ALPHA_REFLONG         00001H
#Define IMAGE_REL_ALPHA_REFQUAD         00002H
#Define IMAGE_REL_ALPHA_GPREL32         00003H
#Define IMAGE_REL_ALPHA_LITERAL         00004H
#Define IMAGE_REL_ALPHA_LITUSE          00005H
#Define IMAGE_REL_ALPHA_GPDISP          00006H
#Define IMAGE_REL_ALPHA_BRADDR          00007H
#Define IMAGE_REL_ALPHA_HINT            00008H
#Define IMAGE_REL_ALPHA_INLINE_REFLONG  00009H
#Define IMAGE_REL_ALPHA_REFHI           0000AH
#Define IMAGE_REL_ALPHA_REFLO           0000BH
#Define IMAGE_REL_ALPHA_PAIR            0000CH
#Define IMAGE_REL_ALPHA_MATCH           0000DH
#Define IMAGE_REL_ALPHA_SECTION         0000EH
#Define IMAGE_REL_ALPHA_SECREL          0000FH
#Define IMAGE_REL_ALPHA_REFLONGNB       00010H
#Define IMAGE_REL_ALPHA_SECRELLO        00011H
#Define IMAGE_REL_ALPHA_SECRELHI        00012H
#Define IMAGE_REL_ALPHA_REFQ3           00013H
#Define IMAGE_REL_ALPHA_REFQ2           00014H
#Define IMAGE_REL_ALPHA_REFQ1           00015H
#Define IMAGE_REL_ALPHA_GPRELLO         00016H
#Define IMAGE_REL_ALPHA_GPRELHI         00017H

#Define IMAGE_REL_PPC_ABSOLUTE          00000H
#Define IMAGE_REL_PPC_ADDR64            00001H
#Define IMAGE_REL_PPC_ADDR32            00002H
#Define IMAGE_REL_PPC_ADDR24            00003H
#Define IMAGE_REL_PPC_ADDR16            00004H
#Define IMAGE_REL_PPC_ADDR14            00005H
#Define IMAGE_REL_PPC_REL24             00006H
#Define IMAGE_REL_PPC_REL14             00007H
#Define IMAGE_REL_PPC_TOCREL16          00008H
#Define IMAGE_REL_PPC_TOCREL14          00009H

#Define IMAGE_REL_PPC_ADDR32NB          0000AH
#Define IMAGE_REL_PPC_SECREL            0000BH
#Define IMAGE_REL_PPC_SECTION           0000CH
#Define IMAGE_REL_PPC_IFGLUE            0000DH
#Define IMAGE_REL_PPC_IMGLUE			0000EH
#Define IMAGE_REL_PPC_SECREL16			0000FH
#Define IMAGE_REL_PPC_REFHI				00010H
#Define IMAGE_REL_PPC_REFLO				00011H
#Define IMAGE_REL_PPC_PAIR				00012H
#Define IMAGE_REL_PPC_SECRELLO			00013H
#Define IMAGE_REL_PPC_SECRELHI			00014H
#Define IMAGE_REL_PPC_GPREL				00015H

#Define IMAGE_REL_PPC_TYPEMASK			000FFH

#Define IMAGE_REL_PPC_NEG               00100H
#Define IMAGE_REL_PPC_BRTAKEN           00200H
#Define IMAGE_REL_PPC_BRNTAKEN          00400H
#Define IMAGE_REL_PPC_TOCDEFN           00800H

#Define IMAGE_REL_SH3_ABSOLUTE          00000H
#Define IMAGE_REL_SH3_DIRECT16          00001H
#Define IMAGE_REL_SH3_DIRECT32          00002H
#Define IMAGE_REL_SH3_DIRECT8           00003H
#Define IMAGE_REL_SH3_DIRECT8_WORD      00004H
#Define IMAGE_REL_SH3_DIRECT8_LONG      00005H
#Define IMAGE_REL_SH3_DIRECT4           00006H
#Define IMAGE_REL_SH3_DIRECT4_WORD      00007H
#Define IMAGE_REL_SH3_DIRECT4_LONG      00008H
#Define IMAGE_REL_SH3_PCREL8_WORD       00009H
#Define IMAGE_REL_SH3_PCREL8_LONG       0000AH
#Define IMAGE_REL_SH3_PCREL12_WORD      0000BH
#Define IMAGE_REL_SH3_STARTOF_SECTION   0000CH
#Define IMAGE_REL_SH3_SIZEOF_SECTION    0000DH
#Define IMAGE_REL_SH3_SECTION           0000EH
#Define IMAGE_REL_SH3_SECREL            0000FH
#Define IMAGE_REL_SH3_DIRECT32_NB       00010H

#Define IMAGE_REL_ARM_ABSOLUTE          00000H
#Define IMAGE_REL_ARM_ADDR32            00001H
#Define IMAGE_REL_ARM_ADDR32NB          00002H
#Define IMAGE_REL_ARM_BRANCH24          00003H
#Define IMAGE_REL_ARM_BRANCH11          00004H
#Define IMAGE_REL_ARM_SECTION           0000EH
#Define IMAGE_REL_ARM_SECREL            0000FH

#Define IMAGE_REL_IA64_ABSOLUTE         00000H
#Define IMAGE_REL_IA64_IMM14            00001H
#Define IMAGE_REL_IA64_IMM22            00002H
#Define IMAGE_REL_IA64_IMM64            00003H
#Define IMAGE_REL_IA64_DIR32            00004H
#Define IMAGE_REL_IA64_DIR64            00005H
#Define IMAGE_REL_IA64_PCREL21B         00006H
#Define IMAGE_REL_IA64_PCREL21M         00007H
#Define IMAGE_REL_IA64_PCREL21F         00008H
#Define IMAGE_REL_IA64_GPREL22          00009H
#Define IMAGE_REL_IA64_LTOFF22          0000AH
#Define IMAGE_REL_IA64_SECTION          0000BH
#Define IMAGE_REL_IA64_SECREL22         0000CH
#Define IMAGE_REL_IA64_SECREL64I        0000DH
#Define IMAGE_REL_IA64_SECREL32         0000EH
#Define IMAGE_REL_IA64_LTOFF64          0000FH
#Define IMAGE_REL_IA64_DIR32NB          00010H
#Define IMAGE_REL_IA64_RESERVED_11      00011H
#Define IMAGE_REL_IA64_RESERVED_12      00012H
#Define IMAGE_REL_IA64_RESERVED_13      00013H
#Define IMAGE_REL_IA64_RESERVED_14      00014H
#Define IMAGE_REL_IA64_RESERVED_15      00015H
#Define IMAGE_REL_IA64_RESERVED_16      00016H
#Define IMAGE_REL_IA64_ADDEND           0001FH

#Define IMAGE_SIZEOF_LINENUMBER         6
#Define IMAGE_SIZEOF_BASE_RELOCATION    8

#Define IMAGE_REL_BASED_ABSOLUTE        0
#Define IMAGE_REL_BASED_HIGH            1
#Define IMAGE_REL_BASED_LOW             2
#Define IMAGE_REL_BASED_HIGHLOW         3
#Define IMAGE_REL_BASED_HIGHADJ         4
#Define IMAGE_REL_BASED_MIPS_JMPADDR    5
#Define IMAGE_REL_BASED_SECTION         6
#Define IMAGE_REL_BASED_REL32           7

#Define IMAGE_REL_BASED_MIPS_JMPADDR16  9
#Define IMAGE_REL_BASED_IA64_IMM64      9
#Define IMAGE_REL_BASED_DIR64           10
#Define IMAGE_REL_BASED_HIGH3ADJ		11

#Define IMAGE_ARCHIVE_START_SIZE        8
#Define IMAGE_ARCHIVE_START             "!<arch>\n"
#Define IMAGE_ARCHIVE_END               "`\n"
#Define IMAGE_ARCHIVE_PAD               "\n"
#Define IMAGE_ARCHIVE_LINKER_MEMBER     "/               "
#Define IMAGE_ARCHIVE_LONGNAMES_MEMBER  "//              "

#Define IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR	60

#Define IMAGE_ORDINAL_FLAG64	08000000000000000H
#Define IMAGE_ORDINAL_FLAG32	080000000H

#IF x64
	#define IMAGE_ORDINAL_FLAG              IMAGE_ORDINAL_FLAG64
	#Define IMAGE_THUNK_DATA64              IMAGE_THUNK_DATA
	#Define PIMAGE_THUNK_DATA64             PIMAGE_THUNK_DATA
	#Define IMAGE_TLS_DIRECTORY64           IMAGE_TLS_DIRECTORY
	#Define PIMAGE_TLS_DIRECTORY64          PIMAGE_TLS_DIRECTORY
#ELSE
	#define IMAGE_ORDINAL_FLAG              IMAGE_ORDINAL_FLAG32
	#Define IMAGE_THUNK_DATA32              IMAGE_THUNK_DATA
	#Define PIMAGE_THUNK_DATA32             PIMAGE_THUNK_DATA
	#Define IMAGE_TLS_DIRECTORY32           IMAGE_TLS_DIRECTORY
	#Define PIMAGE_TLS_DIRECTORY32          PIMAGE_TLS_DIRECTORY
#ENDIF

#Define IMAGE_RESOURCE_NAME_IS_STRING		080000000H
#Define IMAGE_RESOURCE_DATA_IS_DIRECTORY	080000000H

#Define IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY	IMAGE_AXP64_RUNTIME_FUNCTION_ENTRY

#Define IMAGE_IA64_RUNTIME_FUNCTION_ENTRY  	IMAGE_RUNTIME_FUNCTION_ENTRY

#Define IMAGE_DEBUG_TYPE_UNKNOWN        0
#Define IMAGE_DEBUG_TYPE_COFF           1
#Define IMAGE_DEBUG_TYPE_CODEVIEW       2
#Define IMAGE_DEBUG_TYPE_FPO            3
#Define IMAGE_DEBUG_TYPE_MISC           4
#Define IMAGE_DEBUG_TYPE_EXCEPTION      5
#Define IMAGE_DEBUG_TYPE_FIXUP          6
#Define IMAGE_DEBUG_TYPE_OMAP_TO_SRC    7
#Define IMAGE_DEBUG_TYPE_OMAP_FROM_SRC  8
#Define IMAGE_DEBUG_TYPE_BORLAND        9
#Define IMAGE_DEBUG_TYPE_RESERVED10		10

#Define FRAME_FPO       		0
#Define FRAME_TRAP      		1
#Define FRAME_TSS       		2
#Define FRAME_NONFPO    		3

#Define SIZEOF_RFPO_DATA		16

#Define IMAGE_DEBUG_MISC_EXENAME    1

#Define IMAGE_SEPARATE_DEBUG_SIGNATURE	04944H
#Define IMAGE_SEPARATE_DEBUG_FLAGS_MASK	08000H
#Define IMAGE_SEPARATE_DEBUG_MISMATCH   08000H

#Define IMPORT_OBJECT_HDR_SIG2  0FFFFH


;IMPORT_OBJECT_TYPE enumeration
IMPORT_OBJECT_CODE				Equ 0
IMPORT_OBJECT_DATA				Equ 1
IMPORT_OBJECT_CONST				Equ 2

;IMPORT_OBJECT_NAME_TYPE enumeration
IMPORT_OBJECT_ORDINAL			Equ 0
IMPORT_OBJECT_NAME				Equ 1
IMPORT_OBJECT_NAME_NO_PREFIX	Equ 2
IMPORT_OBJECT_NAME_UNDECORATE	Equ 3

#Define HEAP_NO_SERIALIZE               000000001H
#Define HEAP_GROWABLE                   000000002H
#Define HEAP_GENERATE_EXCEPTIONS        000000004H
#Define HEAP_ZERO_MEMORY                000000008H
#Define HEAP_REALLOC_IN_PLACE_ONLY      000000010H
#Define HEAP_TAIL_CHECKING_ENABLED      000000020H
#Define HEAP_FREE_CHECKING_ENABLED      000000040H
#Define HEAP_DISABLE_COALESCE_ON_FREE   000000080H
#Define HEAP_CREATE_ALIGN_16            000010000H
#Define HEAP_CREATE_ENABLE_TRACING      000020000H
#Define HEAP_MAXIMUM_TAG                00FFFH
#Define HEAP_PSEUDO_TAG_FLAG            08000H
#Define HEAP_TAG_SHIFT                	18

#Define IS_TEXT_UNICODE_ASCII16             00001H
#Define IS_TEXT_UNICODE_REVERSE_ASCII16		00010H

#Define IS_TEXT_UNICODE_STATISTICS          00002H
#Define IS_TEXT_UNICODE_REVERSE_STATISTICS  00020H

#Define IS_TEXT_UNICODE_CONTROLS            00004H
#Define IS_TEXT_UNICODE_REVERSE_CONTROLS    00040H

#Define IS_TEXT_UNICODE_SIGNATURE           00008H
#Define IS_TEXT_UNICODE_REVERSE_SIGNATURE   00080H

#Define IS_TEXT_UNICODE_ILLEGAL_CHARS       00100H
#Define IS_TEXT_UNICODE_ODD_LENGTH          00200H
#Define IS_TEXT_UNICODE_DBCS_LEADBYTE       00400H
#Define IS_TEXT_UNICODE_NULL_BYTES          01000H

#Define IS_TEXT_UNICODE_UNICODE_MASK        0000FH
#Define IS_TEXT_UNICODE_REVERSE_MASK        000F0H
#Define IS_TEXT_UNICODE_NOT_UNICODE_MASK    00F00H
#Define IS_TEXT_UNICODE_NOT_ASCII_MASK      0F000H

#Define COMPRESSION_FORMAT_NONE			(00000H)
#Define COMPRESSION_FORMAT_DEFAULT      (00001H)
#Define COMPRESSION_FORMAT_LZNT1        (00002H)
#Define COMPRESSION_ENGINE_STANDARD     (00000H)
#Define COMPRESSION_ENGINE_MAXIMUM      (00100H)

#Define MESSAGE_RESOURCE_UNICODE	00001H

#Define RTL_CRITSECT_TYPE		0
#Define RTL_RESOURCE_TYPE		1

#Define SEF_DACL_AUTO_INHERIT             01H
#Define SEF_SACL_AUTO_INHERIT             02H
#Define SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT 04H
#Define SEF_AVOID_PRIVILEGE_CHECK         08H

#Define WT_EXECUTEDEFAULT       000000000H
#Define WT_EXECUTEINIOTHREAD    000000001H
#Define WT_EXECUTEINUITHREAD    000000002H
#Define WT_EXECUTEINWAITTHREAD  000000004H
#Define WT_EXECUTEDELETEWAIT    000000008H
#Define WT_EXECUTEINLONGTHREAD	000000010H

#Define DLL_PROCESS_ATTACH		1
#Define DLL_THREAD_ATTACH		2
#Define DLL_THREAD_DETACH		3
#Define DLL_PROCESS_DETACH		0

#Define EVENTLOG_SEQUENTIAL_READ    00001H
#Define EVENTLOG_SEEK_READ          00002H
#Define EVENTLOG_FORWARDS_READ      00004H
#Define EVENTLOG_BACKWARDS_READ		00008H

#Define EVENTLOG_SUCCESS            00000H
#Define EVENTLOG_ERROR_TYPE         00001H
#Define EVENTLOG_WARNING_TYPE       00002H
#Define EVENTLOG_INFORMATION_TYPE   00004H
#Define EVENTLOG_AUDIT_SUCCESS      00008H
#Define EVENTLOG_AUDIT_FAILURE      00010H

#Define EVENTLOG_START_PAIRED_EVENT		00001H
#Define EVENTLOG_END_PAIRED_EVENT		00002H
#Define EVENTLOG_END_ALL_PAIRED_EVENTS	00004H
#Define EVENTLOG_PAIRED_EVENT_ACTIVE	00008H
#Define EVENTLOG_PAIRED_EVENT_INACTIVE	00010H

#Define MAXLOGICALLOGNAMESIZE	256

#Define DBG_CONTINUE        			000010002H
#Define DBG_TERMINATE_THREAD            040010003H
#Define DBG_TERMINATE_PROCESS           040010004H
#Define DBG_CONTROL_C                   040010005H
#Define DBG_CONTROL_BREAK               040010008H
#Define DBG_EXCEPTION_NOT_HANDLED       080010001H

#Define KEY_QUERY_VALUE         00001H
#Define KEY_SET_VALUE           00002H
#Define KEY_CREATE_SUB_KEY      00004H
#Define KEY_ENUMERATE_SUB_KEYS  00008H
#Define KEY_NOTIFY              00010H
#Define KEY_CREATE_LINK         00020H

#Define KEY_READ                00020019H ;((STANDARD_RIGHTS_READ | KEY_QUERY_VALUE | KEY_ENUMERATE_SUB_KEYS | KEY_NOTIFY) & (~SYNCHRONIZE))
#Define KEY_WRITE               00020006H ;((STANDARD_RIGHTS_WRITE | KEY_SET_VALUE | KEY_CREATE_SUB_KEY) & (~SYNCHRONIZE))

#Define KEY_EXECUTE             KEY_READ ;((KEY_READ) & (~SYNCHRONIZE))

#Define KEY_ALL_ACCESS          000F003FH ;((STANDARD_RIGHTS_ALL | KEY_QUERY_VALUE | KEY_SET_VALUE | KEY_CREATE_SUB_KEY | KEY_ENUMERATE_SUB_KEYS | KEY_NOTIFY | KEY_CREATE_LINK) & (~SYNCHRONIZE))

#Define REG_OPTION_RESERVED         000000000H
#Define REG_OPTION_NON_VOLATILE     000000000H
#Define REG_OPTION_VOLATILE         000000001H
#Define REG_OPTION_CREATE_LINK      000000002H
#Define REG_OPTION_BACKUP_RESTORE   000000004H
#Define REG_OPTION_OPEN_LINK        000000008H

#Define REG_LEGAL_OPTION            (REG_OPTION_RESERVED | REG_OPTION_NON_VOLATILE | REG_OPTION_VOLATILE | REG_OPTION_CREATE_LINK | REG_OPTION_BACKUP_RESTORE | REG_OPTION_OPEN_LINK)

#Define REG_CREATED_NEW_KEY         000000001H
#Define REG_OPENED_EXISTING_KEY     000000002H

#Define REG_WHOLE_HIVE_VOLATILE     000000001H
#Define REG_REFRESH_HIVE            000000002H
#Define REG_NO_LAZY_FLUSH           000000004H

#Define REG_NOTIFY_CHANGE_NAME          (000000001H)
#Define REG_NOTIFY_CHANGE_ATTRIBUTES    (000000002H)
#Define REG_NOTIFY_CHANGE_LAST_SET      (000000004H)
#Define REG_NOTIFY_CHANGE_SECURITY      (000000008H)

#Define REG_LEGAL_CHANGE_FILTER			(REG_NOTIFY_CHANGE_NAME | REG_NOTIFY_CHANGE_ATTRIBUTES | REG_NOTIFY_CHANGE_LAST_SET | REG_NOTIFY_CHANGE_SECURITY)

#Define REG_NONE						0
#Define REG_SZ                      	1
#Define REG_EXPAND_SZ               	2
#Define REG_BINARY                  	3
#Define REG_DWORD                   	4
#Define REG_DWORD_LITTLE_ENDIAN     	4
#Define REG_DWORD_BIG_ENDIAN        	5
#Define REG_LINK                    	6
#Define REG_MULTI_SZ                	7
#Define REG_RESOURCE_LIST           	8
#Define REG_FULL_RESOURCE_DESCRIPTOR	9
#Define REG_RESOURCE_REQUIREMENTS_LIST	10

#Define SERVICE_KERNEL_DRIVER       000000001H
#Define SERVICE_FILE_SYSTEM_DRIVER  000000002H
#Define SERVICE_ADAPTER             000000004H
#Define SERVICE_RECOGNIZER_DRIVER   000000008H

#Define SERVICE_DRIVER              (SERVICE_KERNEL_DRIVER | SERVICE_FILE_SYSTEM_DRIVER | SERVICE_RECOGNIZER_DRIVER)

#Define SERVICE_WIN32_OWN_PROCESS   000000010H
#Define SERVICE_WIN32_SHARE_PROCESS 000000020H
#Define SERVICE_WIN32               (SERVICE_WIN32_OWN_PROCESS | SERVICE_WIN32_SHARE_PROCESS)

#Define SERVICE_INTERACTIVE_PROCESS 000000100H

#Define SERVICE_TYPE_ALL            (SERVICE_WIN32 | SERVICE_ADAPTER | SERVICE_DRIVER | SERVICE_INTERACTIVE_PROCESS)

#Define SERVICE_BOOT_START          000000000H
#Define SERVICE_SYSTEM_START        000000001H
#Define SERVICE_AUTO_START          000000002H
#Define SERVICE_DEMAND_START        000000003H
#Define SERVICE_DISABLED            000000004H

#Define SERVICE_ERROR_IGNORE        000000000H
#Define SERVICE_ERROR_NORMAL        000000001H
#Define SERVICE_ERROR_SEVERE        000000002H
#Define SERVICE_ERROR_CRITICAL		000000003H

;SERVICE_NODE_TYPE enumeration
DriverType               		Equ SERVICE_KERNEL_DRIVER
FileSystemType					Equ SERVICE_FILE_SYSTEM_DRIVER
Win32ServiceOwnProcess			Equ SERVICE_WIN32_OWN_PROCESS
Win32ServiceShareProcess		Equ SERVICE_WIN32_SHARE_PROCESS
AdapterType						Equ SERVICE_ADAPTER
RecognizerType					Equ SERVICE_RECOGNIZER_DRIVER

;SERVICE_LOAD_TYPE enumeration
BootLoad    					Equ SERVICE_BOOT_START
SystemLoad						Equ SERVICE_SYSTEM_START
AutoLoad						Equ SERVICE_AUTO_START
DemandLoad						Equ SERVICE_DEMAND_START
DisableLoad						Equ SERVICE_DISABLED

;SERVICE_ERROR_TYPE enumeration
IgnoreError						Equ SERVICE_ERROR_IGNORE
NormalError						Equ SERVICE_ERROR_NORMAL
SevereError						Equ SERVICE_ERROR_SEVERE
CriticalError					SERVICE_ERROR_CRITICAL

#Define TAPE_ERASE_SHORT        0
#Define TAPE_ERASE_LONG         1

#Define TAPE_LOAD               0
#Define TAPE_UNLOAD             1
#Define TAPE_TENSION            2
#Define TAPE_LOCK               3
#Define TAPE_UNLOCK             4
#Define TAPE_FORMAT             5

#Define TAPE_SETMARKS           0
#Define TAPE_FILEMARKS          1
#Define TAPE_SHORT_FILEMARKS    2
#Define TAPE_LONG_FILEMARKS     3

#Define TAPE_ABSOLUTE_POSITION       	0
#Define TAPE_LOGICAL_POSITION        	1
#Define TAPE_PSEUDO_LOGICAL_POSITION	2

#Define TAPE_REWIND                 0
#Define TAPE_ABSOLUTE_BLOCK         1
#Define TAPE_LOGICAL_BLOCK          2
#Define TAPE_PSEUDO_LOGICAL_BLOCK   3
#Define TAPE_SPACE_END_OF_DATA      4
#Define TAPE_SPACE_RELATIVE_BLOCKS  5
#Define TAPE_SPACE_FILEMARKS        6
#Define TAPE_SPACE_SEQUENTIAL_FMKS  7
#Define TAPE_SPACE_SETMARKS         8
#Define TAPE_SPACE_SEQUENTIAL_SMKS	9

#Define TAPE_DRIVE_FIXED            000000001H
#Define TAPE_DRIVE_SELECT           000000002H
#Define TAPE_DRIVE_INITIATOR        000000004H

#Define TAPE_DRIVE_ERASE_SHORT      000000010H
#Define TAPE_DRIVE_ERASE_LONG       000000020H
#Define TAPE_DRIVE_ERASE_BOP_ONLY   000000040H
#Define TAPE_DRIVE_ERASE_IMMEDIATE  000000080H

#Define TAPE_DRIVE_TAPE_CAPACITY    000000100H
#Define TAPE_DRIVE_TAPE_REMAINING   000000200H
#Define TAPE_DRIVE_FIXED_BLOCK      000000400H
#Define TAPE_DRIVE_VARIABLE_BLOCK   000000800H

#Define TAPE_DRIVE_WRITE_PROTECT    000001000H
#Define TAPE_DRIVE_EOT_WZ_SIZE      000002000H

#Define TAPE_DRIVE_ECC              000010000H
#Define TAPE_DRIVE_COMPRESSION      000020000H
#Define TAPE_DRIVE_PADDING          000040000H
#Define TAPE_DRIVE_REPORT_SMKS      000080000H

#Define TAPE_DRIVE_GET_ABSOLUTE_BLK 000100000H
#Define TAPE_DRIVE_GET_LOGICAL_BLK  000200000H
#Define TAPE_DRIVE_SET_EOT_WZ_SIZE  000400000H

#Define TAPE_DRIVE_EJECT_MEDIA      001000000H
#Define TAPE_DRIVE_CLEAN_REQUESTS   002000000H
#Define TAPE_DRIVE_SET_CMP_BOP_ONLY 004000000H

#Define TAPE_DRIVE_RESERVED_BIT		080000000H

#Define TAPE_DRIVE_LOAD_UNLOAD      080000001H
#Define TAPE_DRIVE_TENSION          080000002H
#Define TAPE_DRIVE_LOCK_UNLOCK      080000004H
#Define TAPE_DRIVE_REWIND_IMMEDIATE 080000008H

#Define TAPE_DRIVE_SET_BLOCK_SIZE   080000010H
#Define TAPE_DRIVE_LOAD_UNLD_IMMED  080000020H
#Define TAPE_DRIVE_TENSION_IMMED    080000040H
#Define TAPE_DRIVE_LOCK_UNLK_IMMED  080000080H

#Define TAPE_DRIVE_SET_ECC          080000100H
#Define TAPE_DRIVE_SET_COMPRESSION  080000200H
#Define TAPE_DRIVE_SET_PADDING      080000400H
#Define TAPE_DRIVE_SET_REPORT_SMKS  080000800H

#Define TAPE_DRIVE_ABSOLUTE_BLK     080001000H
#Define TAPE_DRIVE_ABS_BLK_IMMED    080002000H
#Define TAPE_DRIVE_LOGICAL_BLK      080004000H
#Define TAPE_DRIVE_LOG_BLK_IMMED    080008000H

#Define TAPE_DRIVE_END_OF_DATA      080010000H
#Define TAPE_DRIVE_RELATIVE_BLKS    080020000H
#Define TAPE_DRIVE_FILEMARKS        080040000H
#Define TAPE_DRIVE_SEQUENTIAL_FMKS  080080000H

#Define TAPE_DRIVE_SETMARKS         080100000H
#Define TAPE_DRIVE_SEQUENTIAL_SMKS  080200000H
#Define TAPE_DRIVE_REVERSE_POSITION 080400000H
#Define TAPE_DRIVE_SPACE_IMMEDIATE  080800000H

#Define TAPE_DRIVE_WRITE_SETMARKS   081000000H
#Define TAPE_DRIVE_WRITE_FILEMARKS  082000000H
#Define TAPE_DRIVE_WRITE_SHORT_FMKS 084000000H
#Define TAPE_DRIVE_WRITE_LONG_FMKS  088000000H

#Define TAPE_DRIVE_WRITE_MARK_IMMED 090000000H
#Define TAPE_DRIVE_FORMAT           0A0000000H
#Define TAPE_DRIVE_FORMAT_IMMEDIATE 0C0000000H
#Define TAPE_DRIVE_HIGH_FEATURES	080000000H

#Define TAPE_FIXED_PARTITIONS       0
#Define TAPE_SELECT_PARTITIONS      1
#Define TAPE_INITIATOR_PARTITIONS   2


FLOAT128 Struct
	LowPart DQ
	HighPart DQ
EndS

LARGE_INTEGER Struct
	LowPart DD
	HighPart DD
EndS

ULARGE_INTEGER Struct
	LowPart DD
	HighPart DD
EndS

LUID Struct
	LowPart DD
	HighPart DD
EndS

LIST_ENTRY Struct
	Flink DD
	Blink DD
EndS

SINGLE_LIST_ENTRY Struct
	Next DD
EndS

#IFNDEF GUID_DEFINED
	#Define GUID_DEFINED
	GUID Struct
		Data1 DD
		Data2 DW
		Data3 DW
		Data4 DB 8 Dup ?
	EndS
#ENDIF

#IFNDEF OBJECTID_DEFINED
	#Define OBJECTID_DEFINED
	OBJECTID Struct
		Lineage GUID <>
		Uniquifier DD
	EndS
#ENDIF

CONTEXT Struct
	ContextFlags DD
	Dr0 DD
	Dr1 DD
	Dr2 DD
	Dr3 DD
	Dr6 DD
	Dr7 DD
    FloatSave FLOATING_SAVE_AREA <>
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
	ExtendedRegisters DB MAXIMUM_SUPPORTED_EXTENSION DUP ?
EndS

FLOATING_SAVE_AREA Struct
	ControlWord DD
	StatusWord DD
	TagWord DD
	ErrorOffset DD
	ErrorSelector DD
	DataOffset DD
	DataSelector DD
	RegisterArea DB SIZE_OF_80387_REGISTERS Dup ?
	Cr0NpxState DD
EndS

EXCEPTION_RECORD Struct
	ExceptionCode DD
	ExceptionFlags DD
    ExceptionRecord DD
    PVOID ExceptionAddress DD
    DWORD NumberParameters DD
    ExceptionInformation DD EXCEPTION_MAXIMUM_PARAMETERS Dup ?
EndS

EXCEPTION_POINTERS Struct
	ExceptionRecord DD
    ContextRecord DD
EndS

GENERIC_MAPPING Struct
	GenericRead DD
	GenericWrite DD
	GenericExecute DD
	GenericAll DD
EndS

LUID_AND_ATTRIBUTES Struct
    Luid LUID <>
	Attributes DD
EndS

#IFNDEF SID_IDENTIFIER_AUTHORITY_DEFINED
	#Define SID_IDENTIFIER_AUTHORITY_DEFINED
	SID_IDENTIFIER_AUTHORITY Struct
			Value DB 6 Dup ?
	EndS
#ENDIF

#IFNDEF SID_DEFINED
	#Define SID_DEFINED
	SID Struct
		Revision DB
		SubAuthorityCount DB
		IdentifierAuthority SID_IDENTIFIER_AUTHORITY <>
		SubAuthority DD ANYSIZE_ARRAY Dup ?
	EndS
#ENDIF

SID_AND_ATTRIBUTES Struct
    Sid DD
	Attributes DD
EndS

ACL Struct
	AclRevision DB
	Sbz1 DB
	AclSize DW
	AceCount DW
	Sbz2 DW
EndS

ACE_HEADER Struct
	AceType DB
	AceFlags DB
	AceSize DW
EndS

ACCESS_ALLOWED_ACE Struct
    Header ACE_HEADER <>
	Mask DD
	SidStart DD
EndS

ACCESS_DENIED_ACE Struct
    Header ACE_HEADER <>
	Mask DD
	SidStart DD
EndS

SYSTEM_AUDIT_ACE Struct
    Header ACE_HEADER <>
	Mask DD
	SidStart DD
EndS

SYSTEM_ALARM_ACE Struct
    Header ACE_HEADER <>
	Mask DD
	SidStart DD
EndS

ACCESS_ALLOWED_OBJECT_ACE Struct
    Header ACE_HEADER <>
	Mask DD
	Flags DD
	ObjectType  GUID <>
	InheritedObjectType  GUID <>
	SidStart DD
EndS

ACCESS_DENIED_OBJECT_ACE Struct
    Header ACE_HEADER <>
	Mask DD
	Flags DD
	ObjectType  GUID <>
	InheritedObjectType  GUID <>
	SidStart DD
EndS

SYSTEM_AUDIT_OBJECT_ACE Struct
    Header ACE_HEADER <>
	Mask DD
	Flags DD
	ObjectType  GUID <>
	InheritedObjectType  GUID <>
	SidStart DD
EndS

SYSTEM_ALARM_OBJECT_ACE Struct
    Header ACE_HEADER <>
	Mask DD
	Flags DD
	ObjectType  GUID <>
	InheritedObjectType  GUID <>
	SidStart DD
EndS

ACL_REVISION_INFORMATION Struct
	AclRevision DD
EndS

ACL_SIZE_INFORMATION Struct
	AceCount DD
	AclBytesInUse DD
	AclBytesFree DD
EndS

SECURITY_DESCRIPTOR_RELATIVE Struct
	Revision DB
	Sbz1 DB
	Control DW
	Owner DD
	Group DD
	Sacl DD
	Dacl DD
EndS

SECURITY_DESCRIPTOR Struct
	Revision DB
	Sbz1 DB
	Control DW
	Owner DD
	Group DD
	Sacl DD
	Dacl DD
EndS

OBJECT_TYPE_LIST Struct
	Level DW
	Sbz DW
	ObjectType DD
EndS

PRIVILEGE_SET Struct
	PrivilegeCount DD
	Control DD
    Privilege LUID_AND_ATTRIBUTES ANYSIZE_ARRAY Dup <>
EndS

TOKEN_USER Struct
	User SID_AND_ATTRIBUTES <>
EndS

TOKEN_GROUPS Struct
	GroupCount DD
	Groups SID_AND_ATTRIBUTES ANYSIZE_ARRAY Dup <>
EndS

TOKEN_PRIVILEGES Struct
	PrivilegeCount DD
	Privileges LUID_AND_ATTRIBUTES ANYSIZE_ARRAY Dup <>
EndS

TOKEN_OWNER Struct
	Owner DD
EndS

TOKEN_PRIMARY_GROUP Struct
	PrimaryGroup DD
EndS

TOKEN_DEFAULT_DACL Struct
	DefaultDacl DD
EndS

TOKEN_SOURCE Struct
	SourceName DB TOKEN_SOURCE_LENGTH Dup ?
	SourceIdentifier LUID <>
EndS

TOKEN_STATISTICS Struct
	TokenId LUID <>
	AuthenticationId LUID <>
    ExpirationTime LARGE_INTEGER <>
	TokenType DD
	ImpersonationLevel DD
	DynamicCharged DD
	DynamicAvailable DD
	GroupCount DD
	PrivilegeCount DD
	ModifiedId LUID <>
EndS

TOKEN_CONTROL Struct
	TokenId LUID <>
	AuthenticationId LUID <>
	ModifiedId LUID <>
	TokenSource TOKEN_SOURCE <>
EndS

SECURITY_QUALITY_OF_SERVICE Struct
	Length DD
	ImpersonationLevel DD
	ContextTrackingMode DB
	EffectiveOnly DB
EndS

SE_IMPERSONATION_STATE Struct
	Token DD
	CopyOnOpen DB
	EffectiveOnly DB
	Level DD
EndS

NT_TIB Struct
	ExceptionList DD
	StackBase DD
	StackLimit DD
	SubSystemTib DD
	Union
		FiberData DD
		DWORD Version DD
	EndUnion
	ArbitraryUserPointer DD
	Self DD
EndS

QUOTA_LIMITS Struct
	PagedPoolLimit DD
	NonPagedPoolLimit DD
	MinimumWorkingSetSize DD
	MaximumWorkingSetSize DD
	PagefileLimit DD
	TimeLimit LARGE_INTEGER <>
EndS

JOBOBJECT_BASIC_ACCOUNTING_INFORMATION Struct
	TotalUserTime LARGE_INTEGER <>
	TotalKernelTime LARGE_INTEGER <>
	ThisPeriodTotalUserTime LARGE_INTEGER <>
	ThisPeriodTotalKernelTime LARGE_INTEGER <>
	TotalPageFaultCount DD
	TotalProcesses DD
	ActiveProcesses DD
	TotalTerminatedProcesses DD
EndS

JOBOBJECT_BASIC_LIMIT_INFORMATION Struct
	PerProcessUserTimeLimit LARGE_INTEGER <>
	PerJobUserTimeLimit LARGE_INTEGER <>
	LimitFlags DD
	MinimumWorkingSetSize DD
	MaximumWorkingSetSize DD
	ActiveProcessLimit DD
	Affinity DD
	PriorityClass DD
EndS

JOBOBJECT_BASIC_PROCESS_ID_LIST Struct
	NumberOfAssignedProcesses DD
	NumberOfProcessIdsInList DD
	ProcessIdList DD
EndS

JOBOBJECT_BASIC_UI_RESTRICTIONS Struct
	UIRestrictionsClass DD
EndS

JOBOBJECT_SECURITY_LIMIT_INFORMATION Struct
	SecurityLimitFlags DD
	JobToken DD
	SidsToDisable DD
	PrivilegesToDelete DD
	RestrictedSids DD
EndS

JOBOBJECT_END_OF_JOB_TIME_INFORMATION Struct
	EndOfJobTimeAction DD
EndS

JOBOBJECT_ASSOCIATE_COMPLETION_PORT Struct
	CompletionKey DD
	CompletionPort DD
EndS

MEMORY_BASIC_INFORMATION Struct
	BaseAddress DD
	AllocationBase DD
	AllocationProtect DD
	RegionSize DD
	State DD
	Protect DD
	Type DD
EndS

MEMORY_BASIC_INFORMATION_VLM Struct
	Union
		BaseAddress DD
		BaseAddressAsUlongLong DQ
    EndUnion
    Union
		AllocationBase DD
		AllocationBaseAsUlongLong DQ
    EndUnion
	RegionSize DQ
	AllocationProtect DD
	State DD
	Protect DD
	Type DD
EndS

FILE_NOTIFY_INFORMATION Struct
	NextEntryOffset DD
	Action DD
	FileNameLength DD
    FileName DW 1 Dup ?
EndS

FILE_SEGMENT_ELEMENT Union
	Buffer DD
	Alignment DQ
EndUnion

REPARSE_DATA_BUFFER Struct
	ReparseTag DD
    WORD   ReparseDataLength DW
    WORD   Reserved DW
    Union
		SymbolicLinkReparseBuffer Struct
		SubstituteNameOffset DW
		SubstituteNameLength DW
		PrintNameOffset DW
		PrintNameLength DW
		PathBuffe DW 1 Dup ?
		EndS
		MountPointReparseBuffer Struct
			SubstituteNameOffset DW
			SubstituteNameLength DW
			PrintNameOffset DW
			PrintNameLength DW
			PathBuffer DW 1 Dup ?
        EndS
		GenericReparseBuffer Struct
			DataBuffer DB 1 Dup ?
		EndS
    EndUnion
EndS

REPARSE_GUID_DATA_BUFFER Struct
	ReparseTag DD
	ReparseDataLength DW
	Reserved DW
	ReparseGuid GUID <>
	GenericReparseBuffer Struct
		DataBuffer DB 1 Dup ?
	EndS
EndS

REPARSE_POINT_INFORMATION Struct
	ReparseDataLength DW
	UnparsedNameLength DW
EndS

POWER_DEVICE_TIMEOUTS Struct
	ConservationIdleTime DD
	PerformanceIdleTime DD
EndS

IMAGE_DOS_HEADER Struct
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
	e_res DW 4 Dup ?
	e_oemid DW
	e_oeminfo DW
	e_res2 DW 10 Dup ?
	e_lfanew DD
EndS

IMAGE_OS2_HEADER Struct
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
	ne_sssp DD
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
EndS

IMAGE_VXD_HEADER Struct
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
	e32_res3 DB 12 Dup ?
	e32_winresoff DD
	e32_winreslen DD
	e32_devid DW
	e32_ddkver DW
EndS

IMAGE_FILE_HEADER Struct
	Machine DW
	NumberOfSections DW
	TimeDateStamp DD
	PointerToSymbolTable DD
	NumberOfSymbols DD
	SizeOfOptionalHeader DW
	Characteristics DW
EndS

IMAGE_DATA_DIRECTORY Struct
	VirtualAddress DD
	Size DD
EndS

IMAGE_OPTIONAL_HEADER32 Struct
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
	DataDirectory IMAGE_DATA_DIRECTORY IMAGE_NUMBEROF_DIRECTORY_ENTRIES Dup <>
EndS

IMAGE_ROM_OPTIONAL_HEADER Struct
    WORD   Magic DW
    BYTE   MajorLinkerVersion DB
    BYTE   MinorLinkerVersion DB
    DWORD  SizeOfCode DD
    DWORD  SizeOfInitializedData DD
    DWORD  SizeOfUninitializedData DD
    DWORD  AddressOfEntryPoint DD
    DWORD  BaseOfCode DD
    DWORD  BaseOfData DD
    DWORD  BaseOfBss DD
    DWORD  GprMask DD
    DWORD  CprMask DD 4 Dup ?
    DWORD  GpValue DD
EndS

IMAGE_OPTIONAL_HEADER64 Struct
    WORD        Magic DW
    BYTE        MajorLinkerVersion DB
    BYTE        MinorLinkerVersion DB
    DWORD       SizeOfCode DD
    DWORD       SizeOfInitializedData DD
    DWORD       SizeOfUninitializedData DD
    DWORD       AddressOfEntryPoint DD
    DWORD       BaseOfCode DD
    ULONGLONG   ImageBase DQ
    DWORD       SectionAlignment DD
    DWORD       FileAlignment DD
    WORD        MajorOperatingSystemVersion DW
    WORD        MinorOperatingSystemVersion DW
    WORD        MajorImageVersion DW
    WORD        MinorImageVersion DW
    WORD        MajorSubsystemVersion DW
    WORD        MinorSubsystemVersion DW
    DWORD       Win32VersionValue DD
    DWORD       SizeOfImage DD
    DWORD       SizeOfHeaders DD
    DWORD       CheckSum DD
    WORD        Subsystem DW
    WORD        DllCharacteristics DW
    ULONGLONG   SizeOfStackReserve DQ
    ULONGLONG   SizeOfStackCommit DQ
    ULONGLONG   SizeOfHeapReserve DQ
    ULONGLONG   SizeOfHeapCommit DQ
    DWORD       LoaderFlags DD
    DWORD       NumberOfRvaAndSizes DD
    DataDirectory IMAGE_DATA_DIRECTORY IMAGE_NUMBEROF_DIRECTORY_ENTRIES Dup <>
EndS

IMAGE_NT_HEADERS64 Struct
	Signature DD
	FileHeader IMAGE_FILE_HEADER <>
	OptionalHeader IMAGE_OPTIONAL_HEADER64 <>
EndS

IMAGE_NT_HEADERS32 Struct
	Signature DD
	FileHeader IMAGE_FILE_HEADER <>
	OptionalHeader IMAGE_OPTIONAL_HEADER32 <>
EndS

IMAGE_ROM_HEADERS Struct
	FileHeader IMAGE_FILE_HEADER <>
	OptionalHeader IMAGE_ROM_OPTIONAL_HEADER <>
EndS

IMAGE_SECTION_HEADER Struct
    Name DB IMAGE_SIZEOF_SHORT_NAME Dup ?
	Union
		PhysicalAddress DD
		VirtualSize DD
    EndUnion
	VirtualAddress DD
	SizeOfRawData DD
	PointerToRawData DD
	PointerToRelocations DD
	PointerToLinenumbers DD
	NumberOfRelocations DW
	NumberOfLinenumbers DW
	Characteristics DD
EndS

IMAGE_SYMBOL Struct
	Union
        ShortName DB 8 Dup ?
		Name Struct
			Short DD
			Long DD
        EndS
        LongName DD 2 Dup ?
    EndUnion
    Value DD
	SectionNumber DW
	Type DW
	StorageClass DB
	NumberOfAuxSymbols DB
EndS

IMAGE_AUX_SYMBOL Union
	Sym Struct
        TagIndex DD
        Union
            LnSz Struct
				Linenumber DW
				Size DW
			EndS
			TotalSize DD
        EndUnion
		Union
			Function Struct
				PointerToLinenumber DD
				PointerToNextFunction DD
            EndS
			Array Struct
				Dimension DW 4 Dup ?
            EndS
        EndUnion
		TvIndex DW
    EndS
	File Struct
		Name DB IMAGE_SIZEOF_SYMBOL Dup ?
    EndS
    Section Struct
		Length DD
		NumberOfRelocations DW
		NumberOfLinenumbers DW
		CheckSum DD
		Number DW
		Selection DB
    EndS
EndUnion

IMAGE_RELOCATION Struct
    Union
		VirtualAddress DD
		RelocCount DD
    EndUnion
	SymbolTableIndex DD
	Type DW
EndS

IMAGE_LINENUMBER Struct
	Union
		SymbolTableIndex DD
		VirtualAddress DD
	EndUnion
    Linenumber DW
EndS

IMAGE_BASE_RELOCATION Struct
	VirtualAddress DD
	SizeOfBlock DD
	;TypeOffset DW 1 Dup ?
EndS

IMAGE_ARCHIVE_MEMBER_HEADER Struct
	Name DB 16 Dup ?
	Date DB 12 Dup ?
	UserID DB 6 Dup ?
	GroupID DB 6 Dup ?
	Mode DB 8 Dup ?
	Size DB 10 Dup ?
	EndHeader DB 2 Dup ?
EndS

IMAGE_EXPORT_DIRECTORY Struct
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
EndS

IMAGE_IMPORT_BY_NAME Struct
	Hint DW
	Name DB 1 Dup ?
EndS

IMAGE_THUNK_DATA64 Struct
	Union
		ForwarderString DQ
		Function DQ
		Ordinal  DQ
		AddressOfData DQ
    EndUnion
EndS

IMAGE_THUNK_DATA32 Struct
	Union
		ForwarderString DD
		Function DD
		Ordinal DD
		AddressOfData DD
	EndUnion
EndS

IMAGE_TLS_DIRECTORY64 Struct
	StartAddressOfRawData DQ
	EndAddressOfRawData DQ
	AddressOfIndex DQ
	AddressOfCallBacks DQ
	SizeOfZeroFill DD
	Characteristics DD
EndS

IMAGE_TLS_DIRECTORY32 Struct
	StartAddressOfRawData DD
	EndAddressOfRawData DD
	AddressOfIndex DD
	AddressOfCallBacks DD
	SizeOfZeroFill DD
	Characteristics DD
EndS

IMAGE_IMPORT_DESCRIPTOR Struct
	Union
		Characteristics DD
		OriginalFirstThunk DD
	EndUnion
	TimeDateStamp DD
	ForwarderChain DD
	Name DD
	FirstThunk DD
EndS

IMAGE_BOUND_IMPORT_DESCRIPTOR Struct
	TimeDateStamp DD
	OffsetModuleName DW
	NumberOfModuleForwarderRefs DW
EndS

IMAGE_BOUND_FORWARDER_REF Struct
	TimeDateStamp DD
	OffsetModuleName DW
	Reserved DW
EndS

IMAGE_RESOURCE_DIRECTORY Struct
	Characteristics DD
	TimeDateStamp DD
	MajorVersion DW
	MinorVersion DW
	NumberOfNamedEntries DW
	NumberOfIdEntries DW
EndS

IMAGE_RESOURCE_DIRECTORY_STRING Struct
	Length DW
	NameString DB 1 Dup ?
EndS

IMAGE_RESOURCE_DIR_STRING_U Struct
	Length DW
    NameString DW 1 Dup ?
EndS

IMAGE_RESOURCE_DATA_ENTRY Struct
	OffsetToData DD
	Size DD
	CodePage DD
	Reserved DD
EndS

IMAGE_LOAD_CONFIG_DIRECTORY Struct
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
	Reserved DD 1 Dup ?
EndS

IMAGE_IA64_RUNTIME_FUNCTION_ENTRY Struct
	BeginAddress DD
	EndAddress DD
	UnwindInfoAddress DD
EndS

IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY Struct
	BeginAddress DD
	EndAddress DD
	ExceptionHandler DD
	HandlerData DD
	PrologEndAddress DD
EndS

IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY Struct
	BeginAddress DQ
	EndAddress DQ
	ExceptionHandler DQ
	HandlerData DQ
	PrologEndAddress DQ
EndS

IMAGE_CE_RUNTIME_FUNCTION_ENTRY Struct
	FuncStart DD
	PrologLen DD ;8
	FuncLen DD ;22
	ThirtyTwoBit DD ;1
	ExceptionFlag DD ;1
EndS

IMAGE_DEBUG_DIRECTORY Struct
	Characteristics DD
	TimeDateStamp DD
	MajorVersion DW
	MinorVersion DW
	Type DD
	SizeOfData DD
	AddressOfRawData DD
	PointerToRawData DD
EndS

IMAGE_COFF_SYMBOLS_HEADER Struct
	NumberOfSymbols DD
	LvaToFirstSymbol DD
	NumberOfLinenumbers DD
	LvaToFirstLinenumber DD
	RvaToFirstByteOfCode DD
	RvaToLastByteOfCode DD
	RvaToFirstByteOfData DD
	RvaToLastByteOfData DD
EndS

FPO_DATA Struct
	ulOffStart DD
	cbProcSize DD
	cdwLocals DD
	cdwParams DW
	cbProlog DW ;8
	cbRegs DW ;3
	fHasSEH DW ;1
	fUseBP DW ;1
	reserved DW ;1
	cbFrame DW ;2
EndS

IMAGE_DEBUG_MISC Struct
	DataType DD
	Length DD
	Unicode DB
	Reserved DB 3 Dup ?
	Data DB 1 Dup ?
EndS

IMAGE_FUNCTION_ENTRY Struct
	StartingAddress DD
	EndingAddress DD
	EndOfPrologue DD
EndS

IMAGE_FUNCTION_ENTRY64 Struct
	StartingAddress DQ
	EndingAddress DQ
	EndOfPrologue DQ
EndS

IMAGE_SEPARATE_DEBUG_HEADER Struct
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
	Reserved DD 2 Dup ?
EndS

IMAGE_ARCHITECTURE_ENTRY Struct
	FixupInstRVA DD
	NewInst DD
EndS

IMPORT_OBJECT_HEADER Struct
	Sig1 DW
	Sig2 DW
	Version DW
	Machine DW
	TimeDateStamp DD
	SizeOfData DD
	Union
		Ordinal DW
		Hint DW
	EndUnion
	Type DW ;2
	NameType DW ;3
	Reserved DW ;11
EndS

MESSAGE_RESOURCE_ENTRY Struct
	Length DW
	Flags DW
	Text DB 1 Dup ?
EndS

MESSAGE_RESOURCE_BLOCK Struct
	LowId DD
	HighId DD
	OffsetToEntries DD
EndS

MESSAGE_RESOURCE_DATA Struct
	NumberOfBlocks DD
	Blocks MESSAGE_RESOURCE_BLOCK 1 Dup <>
EndS

RTL_CRITICAL_SECTION_DEBUG Struct
	Type DW
	CreatorBackTraceIndex DW
	CriticalSection DD
	ProcessLocksList LIST_ENTRY <>
	EntryCount DD
	ContentionCount DD
	Spare DD 2 Dup ?
EndS

RTL_CRITICAL_SECTION Struct
	DebugInfo DD
	LockCount DD
	RecursionCount DD
	OwningThread DD
	LockSemaphore DD
	SpinCount DD
EndS

EVENTLOGRECORD Struct
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
EndS

EVENTSFORLOGFILE Struct
	ulSize DD
	szLogicalLogFile DW MAXLOGICALLOGNAMESIZE Dup ?
	ulNumRecords DD
	pEventLogRecords DD ;EVENTLOGRECORD
EndS

PACKEDEVENTINFO Struct
	ulSize DD
	ulNumEventsForLogFile DD
	ulOffsets DD
EndS

TAPE_ERASE Struct
	Type DD
	Immediate DB
EndS

TAPE_PREPARE Struct
	Operation DD
	Immediate DB
EndS

TAPE_WRITE_MARKS Struct
	Type DD
	Count DD
	Immediate DB
EndS

TAPE_GET_POSITION Struct
	Type DD
	Partition DD
	Offset LARGE_INTEGER <>
EndS

TAPE_SET_POSITION Struct
	Method DD
	Partition DD
	Offset LARGE_INTEGER <>
	Immediate DB
EndS

TAPE_GET_DRIVE_PARAMETERS Struct
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
EndS

TAPE_SET_DRIVE_PARAMETERS Struct
	ECC DB
	Compression DB
	DataPadding DB
	ReportSetmarks DB
	EOTWarningZoneSize DD
EndS

TAPE_GET_MEDIA_PARAMETERS Struct
	Capacity LARGE_INTEGER <>
	Remaining LARGE_INTEGER <>
	BlockSize DD
	PartitionCount DD
	WriteProtected DB
EndS

TAPE_SET_MEDIA_PARAMETERS Struct
	BlockSize DD
EndS

TAPE_CREATE_PARTITION Struct
	Method DD
	Count DD
	Size DD
EndS


#IFNDEF TCHAR
	#IF STRINGS UNICODE
		#Define TCHAR DB
	#ELSE
		#Define TCHAR DW
	#ENDIF
#ENDIF


#ENDIF ;WINNT_INC
