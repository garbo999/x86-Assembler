;=============================================================;
;          winbase.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                (modified on November, 2007)                 ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINBASE_INC
#Define WINBASE_INC

#IFNDEF WINERROR_INC
	#Include <winerror.inc>
#ENDIF

#Define INVALID_HANDLE_VALUE	(-1)
#Define INVALID_FILE_SIZE		0FFFFFFFFH

#Define FILE_BEGIN           	0
#Define FILE_CURRENT         	1
#Define FILE_END             	2

#Define TIME_ZONE_ID_INVALID	0FFFFFFFFH

#Define WAIT_FAILED				0FFFFFFFFH
#Define WAIT_OBJECT_0			((STATUS_WAIT_0) + 0)

#Define WAIT_ABANDONED          (STATUS_ABANDONED_WAIT_0 + 0)
#Define WAIT_ABANDONED_0        (STATUS_ABANDONED_WAIT_0 + 0)

#Define WAIT_TIMEOUT                        STATUS_TIMEOUT
#Define WAIT_IO_COMPLETION                  STATUS_USER_APC
#Define STILL_ACTIVE                        STATUS_PENDING
#Define EXCEPTION_ACCESS_VIOLATION          STATUS_ACCESS_VIOLATION
#Define EXCEPTION_DATATYPE_MISALIGNMENT		STATUS_DATATYPE_MISALIGNMENT
#Define EXCEPTION_BREAKPOINT                STATUS_BREAKPOINT
#Define EXCEPTION_SINGLE_STEP               STATUS_SINGLE_STEP
#Define EXCEPTION_ARRAY_BOUNDS_EXCEEDED     STATUS_ARRAY_BOUNDS_EXCEEDED
#Define EXCEPTION_FLT_DENORMAL_OPERAND      STATUS_FLOAT_DENORMAL_OPERAND
#Define EXCEPTION_FLT_DIVIDE_BY_ZERO        STATUS_FLOAT_DIVIDE_BY_ZERO
#Define EXCEPTION_FLT_INEXACT_RESULT        STATUS_FLOAT_INEXACT_RESULT
#Define EXCEPTION_FLT_INVALID_OPERATION     STATUS_FLOAT_INVALID_OPERATION
#Define EXCEPTION_FLT_OVERFLOW              STATUS_FLOAT_OVERFLOW
#Define EXCEPTION_FLT_STACK_CHECK           STATUS_FLOAT_STACK_CHECK
#Define EXCEPTION_FLT_UNDERFLOW             STATUS_FLOAT_UNDERFLOW
#Define EXCEPTION_INT_DIVIDE_BY_ZERO        STATUS_INTEGER_DIVIDE_BY_ZERO
#Define EXCEPTION_INT_OVERFLOW              STATUS_INTEGER_OVERFLOW
#Define EXCEPTION_PRIV_INSTRUCTION          STATUS_PRIVILEGED_INSTRUCTION
#Define EXCEPTION_IN_PAGE_ERROR             STATUS_IN_PAGE_ERROR
#Define EXCEPTION_ILLEGAL_INSTRUCTION       STATUS_ILLEGAL_INSTRUCTION
#Define EXCEPTION_NONCONTINUABLE_EXCEPTION  STATUS_NONCONTINUABLE_EXCEPTION
#Define EXCEPTION_STACK_OVERFLOW            STATUS_STACK_OVERFLOW
#Define EXCEPTION_INVALID_DISPOSITION       STATUS_INVALID_DISPOSITION
#Define EXCEPTION_GUARD_PAGE                STATUS_GUARD_PAGE_VIOLATION
#Define EXCEPTION_INVALID_HANDLE            STATUS_INVALID_HANDLE
#Define CONTROL_C_EXIT                      STATUS_CONTROL_C_EXIT
#Define MoveMemory RtlMoveMemory
#Define CopyMemory RtlCopyMemory
#Define FillMemory RtlFillMemory
#Define ZeroMemory RtlZeroMemory

#Define FILE_FLAG_WRITE_THROUGH         080000000H
#Define FILE_FLAG_OVERLAPPED            040000000H
#Define FILE_FLAG_NO_BUFFERING          020000000H
#Define FILE_FLAG_RANDOM_ACCESS         010000000H
#Define FILE_FLAG_SEQUENTIAL_SCAN       008000000H
#Define FILE_FLAG_DELETE_ON_CLOSE       004000000H
#Define FILE_FLAG_BACKUP_SEMANTICS      002000000H
#Define FILE_FLAG_POSIX_SEMANTICS       001000000H
#Define FILE_FLAG_OPEN_REPARSE_POINT	000200000H
#Define FILE_FLAG_OPEN_NO_RECALL        000100000H

#Define CREATE_NEW          	1
#Define CREATE_ALWAYS       	2
#Define OPEN_EXISTING       	3
#Define OPEN_ALWAYS         	4
#Define TRUNCATE_EXISTING   	5

#Define PROGRESS_CONTINUE   	0
#Define PROGRESS_CANCEL     	1
#Define PROGRESS_STOP       	2
#Define PROGRESS_QUIET      	3

#Define CALLBACK_CHUNK_FINISHED	000000000H
#Define CALLBACK_STREAM_SWITCH	000000001H

#Define COPY_FILE_FAIL_IF_EXISTS        000000001H
#Define COPY_FILE_RESTARTABLE           000000002H
#Define COPY_FILE_OPEN_SOURCE_FOR_WRITE	000000004H

#Define PIPE_ACCESS_INBOUND     000000001H
#Define PIPE_ACCESS_OUTBOUND    000000002H
#Define PIPE_ACCESS_DUPLEX      000000003H

#Define PIPE_CLIENT_END         000000000H
#Define PIPE_SERVER_END         000000001H

#Define PIPE_WAIT               000000000H
#Define PIPE_NOWAIT             000000001H
#Define PIPE_READMODE_BYTE      000000000H
#Define PIPE_READMODE_MESSAGE   000000002H
#Define PIPE_TYPE_BYTE          000000000H
#Define PIPE_TYPE_MESSAGE       000000004H

#Define PIPE_UNLIMITED_INSTANCES	255

#Define SECURITY_ANONYMOUS		010000H ;(SecurityAnonymous << 16)
#Define SECURITY_IDENTIFICATION	020000H ;(SecurityIdentification << 16)
#Define SECURITY_IMPERSONATION	030000H; (SecurityImpersonation  << 16)
#Define SECURITY_DELEGATION		040000H; (SecurityDelegation << 16)

#Define SECURITY_CONTEXT_TRACKING  	000040000H
#Define SECURITY_EFFECTIVE_ONLY    	000080000H

#Define SECURITY_SQOS_PRESENT      	000100000H
#Define SECURITY_VALID_SQOS_FLAGS	0001F0000H

#Define RTL_CRITICAL_SECTION		CRITICAL_SECTION
#Define RTL_CRITICAL_SECTION_DEBUG	CRITICAL_SECTION_DEBUG

#Define MUTEX_MODIFY_STATE		MUTANT_QUERY_STATE
#Define MUTEX_ALL_ACCESS		MUTANT_ALL_ACCESS

#Define SP_SERIALCOMM    		000000001H

#Define PST_UNSPECIFIED      	000000000H
#Define PST_RS232            	000000001H
#Define PST_PARALLELPORT     	000000002H
#Define PST_RS422            	000000003H
#Define PST_RS423            	000000004H
#Define PST_RS449            	000000005H
#Define PST_MODEM				000000006H
#Define PST_FAX              	000000021H
#Define PST_SCANNER          	000000022H
#Define PST_NETWORK_BRIDGE   	000000100H
#Define PST_LAT              	000000101H
#Define PST_TCPIP_TELNET     	000000102H
#Define PST_X25					000000103H

#Define PCF_DTRDSR        		00001H
#Define PCF_RTSCTS        		00002H
#Define PCF_RLSD          		00004H
#Define PCF_PARITY_CHECK  		00008H
#Define PCF_XONXOFF       		00010H
#Define PCF_SETXCHAR      		00020H
#Define PCF_TOTALTIMEOUTS 		00040H
#Define PCF_INTTIMEOUTS   		00080H
#Define PCF_SPECIALCHARS  		00100H
#Define PCF_16BITMODE     		00200H

#Define SP_PARITY         		00001H
#Define SP_BAUD           		00002H
#Define SP_DATABITS       		00004H
#Define SP_STOPBITS       		00008H
#Define SP_HANDSHAKING    		00010H
#Define SP_PARITY_CHECK   		00020H
#Define SP_RLSD           		00040H

#Define BAUD_075          		000000001H
#Define BAUD_110          		000000002H
#Define BAUD_134_5        		000000004H
#Define BAUD_150          		000000008H
#Define BAUD_300          		000000010H
#Define BAUD_600          		000000020H
#Define BAUD_1200         		000000040H
#Define BAUD_1800         		000000080H
#Define BAUD_2400         		000000100H
#Define BAUD_4800         		000000200H
#Define BAUD_7200         		000000400H
#Define BAUD_9600         		000000800H
#Define BAUD_14400        		000001000H
#Define BAUD_19200        		000002000H
#Define BAUD_38400        		000004000H
#Define BAUD_56K          		000008000H
#Define BAUD_128K         		000010000H
#Define BAUD_115200       		000020000H
#Define BAUD_57600        		000040000H
#Define BAUD_USER         		010000000H

#Define DATABITS_5        		00001H
#Define DATABITS_6        		00002H
#Define DATABITS_7        		00004H
#Define DATABITS_8        		00008H
#Define DATABITS_16       		00010H
#Define DATABITS_16X      		00020H

#Define STOPBITS_10       		00001H
#Define STOPBITS_15       		00002H
#Define STOPBITS_20       		00004H
#Define PARITY_NONE       		00100H
#Define PARITY_ODD        		00200H
#Define PARITY_EVEN       		00400H
#Define PARITY_MARK       		00800H
#Define PARITY_SPACE      		01000H

#Define COMMPROP_INITIALIZED	0E73CF52EH

#Define DTR_CONTROL_DISABLE    	000H
#Define DTR_CONTROL_ENABLE     	001H
#Define DTR_CONTROL_HANDSHAKE   002H

#Define RTS_CONTROL_DISABLE    	000H
#Define RTS_CONTROL_ENABLE     	001H
#Define RTS_CONTROL_HANDSHAKE  	002H
#Define RTS_CONTROL_TOGGLE		003H

#Define GMEM_FIXED          	00000H
#Define GMEM_MOVEABLE       	00002H
#Define GMEM_NOCOMPACT      	00010H
#Define GMEM_NODISCARD      	00020H
#Define GMEM_ZEROINIT       	00040H
#Define GMEM_MODIFY         	00080H
#Define GMEM_DISCARDABLE    	00100H
#Define GMEM_NOT_BANKED     	01000H
#Define GMEM_SHARE          	02000H
#Define GMEM_DDESHARE       	02000H
#Define GMEM_NOTIFY         	04000H
#Define GMEM_LOWER          	GMEM_NOT_BANKED
#Define GMEM_VALID_FLAGS    	07F72H
#Define GMEM_INVALID_HANDLE 	08000H

#Define GHND                	(GMEM_MOVEABLE | GMEM_ZEROINIT)
#Define GPTR                	(GMEM_FIXED | GMEM_ZEROINIT)

#Define GMEM_DISCARDED      	04000H
#Define GMEM_LOCKCOUNT      	000FFH

#Define LMEM_FIXED          	00000H
#Define LMEM_MOVEABLE       	00002H
#Define LMEM_NOCOMPACT      	00010H
#Define LMEM_NODISCARD      	00020H
#Define LMEM_ZEROINIT       	00040H
#Define LMEM_MODIFY         	00080H
#Define LMEM_DISCARDABLE    	00F00H
#Define LMEM_VALID_FLAGS    	00F72H
#Define LMEM_INVALID_HANDLE		08000H

#Define LHND                	(LMEM_MOVEABLE | LMEM_ZEROINIT)
#Define LPTR                	(LMEM_FIXED | LMEM_ZEROINIT)

#Define NONZEROLHND         	(LMEM_MOVEABLE)
#Define NONZEROLPTR         	(LMEM_FIXED)

#Define LMEM_DISCARDED      	04000H
#Define LMEM_LOCKCOUNT      	000FFH

#Define DEBUG_PROCESS               	000000001H
#Define DEBUG_ONLY_THIS_PROCESS     	000000002H

#Define CREATE_SUSPENDED            	000000004H

#Define DETACHED_PROCESS            	000000008H

#Define CREATE_NEW_CONSOLE          	000000010H

#Define NORMAL_PRIORITY_CLASS       	000000020H
#Define IDLE_PRIORITY_CLASS         	000000040H
#Define HIGH_PRIORITY_CLASS         	000000080H
#Define REALTIME_PRIORITY_CLASS     	000000100H

#Define CREATE_NEW_PROCESS_GROUP    	000000200H
#Define CREATE_UNICODE_ENVIRONMENT  	000000400H

#Define CREATE_SEPARATE_WOW_VDM     	000000800H
#Define CREATE_SHARED_WOW_VDM       	000001000H
#Define CREATE_FORCEDOS             	000002000H

#Define CREATE_DEFAULT_ERROR_MODE   	004000000H
#Define CREATE_NO_WINDOW            	008000000H

#Define PROFILE_USER                	010000000H
#Define PROFILE_KERNEL              	020000000H
#Define PROFILE_SERVER              	040000000H

#Define THREAD_PRIORITY_LOWEST          THREAD_BASE_PRIORITY_MIN
#Define THREAD_PRIORITY_BELOW_NORMAL    (THREAD_PRIORITY_LOWEST + 1)
#Define THREAD_PRIORITY_NORMAL          0
#Define THREAD_PRIORITY_HIGHEST         THREAD_BASE_PRIORITY_MAX
#Define THREAD_PRIORITY_ABOVE_NORMAL    (THREAD_PRIORITY_HIGHEST - 1)
#Define THREAD_PRIORITY_ERROR_RETURN    (MAXLONG)

#Define THREAD_PRIORITY_TIME_CRITICAL   THREAD_BASE_PRIORITY_LOWRT
#Define THREAD_PRIORITY_IDLE         	THREAD_BASE_PRIORITY_IDLE

#Define EXCEPTION_DEBUG_EVENT       1
#Define CREATE_THREAD_DEBUG_EVENT   2
#Define CREATE_PROCESS_DEBUG_EVENT  3
#Define EXIT_THREAD_DEBUG_EVENT     4
#Define EXIT_PROCESS_DEBUG_EVENT    5
#Define LOAD_DLL_DEBUG_EVENT        6
#Define UNLOAD_DLL_DEBUG_EVENT      7
#Define OUTPUT_DEBUG_STRING_EVENT	8
#Define RIP_EVENT                   9

#Define DRIVE_UNKNOWN     		0
#Define DRIVE_NO_ROOT_DIR 		1
#Define DRIVE_REMOVABLE   		2
#Define DRIVE_FIXED       		3
#Define DRIVE_REMOTE      		4
#Define DRIVE_CDROM       		5
#Define DRIVE_RAMDISK     		6

#Define FILE_TYPE_UNKNOWN		00000H
#Define FILE_TYPE_DISK      	00001H
#Define FILE_TYPE_CHAR      	00002H
#Define FILE_TYPE_PIPE      	00003H
#Define FILE_TYPE_REMOTE    	08000H


#Define STD_INPUT_HANDLE    	(-10)
#Define STD_OUTPUT_HANDLE   	(-11)
#Define STD_ERROR_HANDLE		(-12)

#Define NOPARITY            	0
#Define ODDPARITY           	1
#Define EVENPARITY          	2
#Define MARKPARITY          	3
#Define SPACEPARITY         	4

#Define ONESTOPBIT          	0
#Define ONE5STOPBITS        	1
#Define TWOSTOPBITS         	2

#Define IGNORE              	0
#Define INFINITE				0FFFFFFFFH

#Define CBR_110             	110
#Define CBR_300             	300
#Define CBR_600             	600
#Define CBR_1200            	1200
#Define CBR_2400            	2400
#Define CBR_4800            	4800
#Define CBR_9600            	9600
#Define CBR_14400           	14400
#Define CBR_19200           	19200
#Define CBR_38400           	38400
#Define CBR_56000           	56000
#Define CBR_57600           	57600
#Define CBR_115200          	115200
#Define CBR_128000          	128000
#Define CBR_256000          	256000

#Define CE_RXOVER           	00001H
#Define CE_OVERRUN          	00002H
#Define CE_RXPARITY         	00004H
#Define CE_FRAME            	00008H
#Define CE_BREAK            	00010H
#Define CE_TXFULL           	00100H
#Define CE_PTO              	00200H
#Define CE_IOE              	00400H
#Define CE_DNS              	00800H
#Define CE_OOP              	01000H
#Define CE_MODE             	08000H

#Define IE_BADID            	(-1)
#Define IE_OPEN             	(-2)
#Define IE_NOPEN            	(-3)
#Define IE_MEMORY           	(-4)
#Define IE_DEFAULT          	(-5)
#Define IE_HARDWARE         	(-10)
#Define IE_BYTESIZE         	(-11)
#Define IE_BAUDRATE         	(-12)

#Define EV_RXCHAR           	00001H
#Define EV_RXFLAG           	00002H
#Define EV_TXEMPTY          	00004H
#Define EV_CTS              	00008H
#Define EV_DSR              	00010H
#Define EV_RLSD             	00020H
#Define EV_BREAK            	00040H
#Define EV_ERR              	00080H
#Define EV_RING             	00100H
#Define EV_PERR             	00200H
#Define EV_RX80FULL         	00400H
#Define EV_EVENT1           	00800H
#Define EV_EVENT2           	01000H

#Define SETXOFF             	1
#Define SETXON              	2
#Define SETRTS              	3
#Define CLRRTS              	4
#Define SETDTR              	5
#Define CLRDTR              	6
#Define RESETDEV            	7
#Define SETBREAK            	8
#Define CLRBREAK            	9

#Define PURGE_TXABORT       	00001H
#Define PURGE_RXABORT       	00002H
#Define PURGE_TXCLEAR       	00004H
#Define PURGE_RXCLEAR       	00008H

#Define LPTx                	080H

#Define MS_CTS_ON           	00010H
#Define MS_DSR_ON           	00020H
#Define MS_RING_ON          	00040H
#Define MS_RLSD_ON          	00080H

#Define S_QUEUEEMPTY        	0
#Define S_THRESHOLD         	1
#Define S_ALLTHRESHOLD      	2

#Define S_NORMAL      			0
#Define S_LEGATO      			1
#Define S_STACCATO    			2

#Define S_PERIOD512   				0
#Define S_PERIOD1024  				1
#Define S_PERIOD2048  				2
#Define S_PERIODVOICE 				3
#Define S_WHITE512    				4
#Define S_WHITE1024   				5
#Define S_WHITE2048   				6
#Define S_WHITEVOICE  				7

#Define S_SERDVNA     				(-1)
#Define S_SEROFM      				(-2)
#Define S_SERMACT     				(-3)
#Define S_SERQFUL     				(-4)
#Define S_SERBDNT     				(-5)
#Define S_SERDLN      				(-6)
#Define S_SERDCC      				(-7)
#Define S_SERDTP      				(-8)
#Define S_SERDVL      				(-9)
#Define S_SERDMD      				(-10)
#Define S_SERDSH      				(-11)
#Define S_SERDPT      				(-12)
#Define S_SERDFQ      				(-13)
#Define S_SERDDR      				(-14)
#Define S_SERDSR      				(-15)
#Define S_SERDST      				(-16)

#Define NMPWAIT_WAIT_FOREVER        0FFFFFFFFH
#Define NMPWAIT_NOWAIT              000000001H
#Define NMPWAIT_USE_DEFAULT_WAIT    000000000H

#Define FS_CASE_IS_PRESERVED        FILE_CASE_PRESERVED_NAMES
#Define FS_CASE_SENSITIVE           FILE_CASE_SENSITIVE_SEARCH
#Define FS_UNICODE_STORED_ON_DISK	FILE_UNICODE_ON_DISK
#Define FS_PERSISTENT_ACLS          FILE_PERSISTENT_ACLS
#Define FS_VOL_IS_COMPRESSED        FILE_VOLUME_IS_COMPRESSED
#Define FS_FILE_COMPRESSION      	FILE_FILE_COMPRESSION

#Define FILE_MAP_COPY       	SECTION_QUERY
#Define FILE_MAP_WRITE      	SECTION_MAP_WRITE
#Define FILE_MAP_READ       	SECTION_MAP_READ
#Define FILE_MAP_ALL_ACCESS		SECTION_ALL_ACCESS

#Define OF_READ             	000000000H
#Define OF_WRITE            	000000001H
#Define OF_READWRITE        	000000002H
#Define OF_SHARE_COMPAT     	000000000H
#Define OF_SHARE_EXCLUSIVE  	000000010H
#Define OF_SHARE_DENY_WRITE 	000000020H
#Define OF_SHARE_DENY_READ  	000000030H
#Define OF_SHARE_DENY_NONE  	000000040H
#Define OF_PARSE            	000000100H
#Define OF_DELETE           	000000200H
#Define OF_VERIFY           	000000400H
#Define OF_CANCEL           	000000800H
#Define OF_CREATE           	000001000H
#Define OF_PROMPT           	000002000H
#Define OF_EXIST            	000004000H
#Define OF_REOPEN           	000008000H

#Define OFS_MAXPATHNAME			128

#Define InterlockedIncrement		_InterlockedIncrement
#Define InterlockedDecrement		_InterlockedDecrement
#Define InterlockedExchange			_InterlockedExchange
#Define InterlockedExchangeAdd		_InterlockedExchangeAdd
#Define InterlockedCompareExchange	_InterlockedCompareExchange

#Define MAXINTATOM				0C000H

#Define PROCESS_HEAP_REGION             00001H
#Define PROCESS_HEAP_UNCOMMITTED_RANGE	00002H
#Define PROCESS_HEAP_ENTRY_BUSY         00004H
#Define PROCESS_HEAP_ENTRY_MOVEABLE     00010H
#Define PROCESS_HEAP_ENTRY_DDESHARE     00020H

#Define SCS_32BIT_BINARY    	0
#Define SCS_DOS_BINARY      	1
#Define SCS_WOW_BINARY      	2
#Define SCS_PIF_BINARY      	3
#Define SCS_POSIX_BINARY    	4
#Define SCS_OS216_BINARY    	5

#Define SEM_FAILCRITICALERRORS      00001H
#Define SEM_NOGPFAULTERRORBOX       00002H
#Define SEM_NOALIGNMENTFAULTEXCEPT  00004H
#Define SEM_NOOPENFILEERRORBOX      08000H

#Define LOCKFILE_FAIL_IMMEDIATELY   000000001H
#Define LOCKFILE_EXCLUSIVE_LOCK     000000002H

#Define HANDLE_FLAG_INHERIT             000000001H
#Define HANDLE_FLAG_PROTECT_FROM_CLOSE	000000002H

#Define HINSTANCE_ERROR			32

#Define GET_TAPE_MEDIA_INFORMATION	0
#Define GET_TAPE_DRIVE_INFORMATION	1

#Define SET_TAPE_MEDIA_INFORMATION	0
#Define SET_TAPE_DRIVE_INFORMATION	1

#Define FORMAT_MESSAGE_ALLOCATE_BUFFER	000000100H
#Define FORMAT_MESSAGE_IGNORE_INSERTS	000000200H
#Define FORMAT_MESSAGE_FROM_STRING		000000400H
#Define FORMAT_MESSAGE_FROM_HMODULE		000000800H
#Define FORMAT_MESSAGE_FROM_SYSTEM		000001000H
#Define FORMAT_MESSAGE_ARGUMENT_ARRAY	000002000H
#Define FORMAT_MESSAGE_MAX_WIDTH_MASK	0000000FFH

#Define EFS_USE_RECOVERY_KEYS	01H

#Define CREATE_FOR_IMPORT  		1
#Define CREATE_FOR_DIR     		2

#Define TLS_OUT_OF_INDEXES		0FFFFFFFFH

#Define BACKUP_INVALID          000000000H
#Define BACKUP_DATA             000000001H
#Define BACKUP_EA_DATA          000000002H
#Define BACKUP_SECURITY_DATA    000000003H
#Define BACKUP_ALTERNATE_DATA   000000004H
#Define BACKUP_LINK             000000005H
#Define BACKUP_PROPERTY_DATA    000000006H
#Define BACKUP_OBJECT_ID        000000007H
#Define BACKUP_REPARSE_DATA     000000008H
#Define BACKUP_SPARSE_BLOCK     000000009H

#Define STREAM_NORMAL_ATTRIBUTE     000000000H
#Define STREAM_MODIFIED_WHEN_READ   000000001H
#Define STREAM_CONTAINS_SECURITY    000000002H
#Define STREAM_CONTAINS_PROPERTIES  000000004H
#Define STREAM_SPARSE_ATTRIBUTE   	000000008H

#Define STARTF_USESHOWWINDOW    000000001H
#Define STARTF_USESIZE          000000002H
#Define STARTF_USEPOSITION      000000004H
#Define STARTF_USECOUNTCHARS    000000008H
#Define STARTF_USEFILLATTRIBUTE 000000010H
#Define STARTF_RUNFULLSCREEN    000000020H
#Define STARTF_FORCEONFEEDBACK  000000040H
#Define STARTF_FORCEOFFFEEDBACK 000000080H
#Define STARTF_USESTDHANDLES    000000100H
#Define STARTF_USEHOTKEY        000000200H

#Define SHUTDOWN_NORETRY        000000001H

#Define DONT_RESOLVE_DLL_REFERENCES     000000001H
#Define LOAD_LIBRARY_AS_DATAFILE        000000002H
#Define LOAD_WITH_ALTERED_SEARCH_PATH	000000008H

#Define DDD_RAW_TARGET_PATH         000000001H
#Define DDD_REMOVE_DEFINITION       000000002H
#Define DDD_EXACT_MATCH_ON_REMOVE   000000004H
#Define DDD_NO_BROADCAST_SYSTEM     000000008H

;FINDEX_INFO_LEVELS enumeration
FindExInfoStandard					Equ 0
FindExInfoMaxInfoLevel				Equ 1

;FINDEX_SEARCH_OPS enumeration
FindExSearchNameMatch				Equ 0
FindExSearchLimitToDirectories		Equ 1
FindExSearchLimitToDevices			Equ 2
FindExSearchMaxSearchOp				Equ 3

#Define FIND_FIRST_EX_CASE_SENSITIVE	000000001H

#Define MOVEFILE_REPLACE_EXISTING       000000001H
#Define MOVEFILE_COPY_ALLOWED           000000002H
#Define MOVEFILE_DELAY_UNTIL_REBOOT     000000004H
#Define MOVEFILE_WRITE_THROUGH          000000008H
#Define MOVEFILE_CREATE_HARDLINK        000000010H
#Define MOVEFILE_FAIL_IF_NOT_TRACKABLE	000000020H

#Define MAX_COMPUTERNAME_LENGTH		15

#Define LOGON32_LOGON_INTERACTIVE   2
#Define LOGON32_LOGON_NETWORK       3
#Define LOGON32_LOGON_BATCH         4
#Define LOGON32_LOGON_SERVICE       5

#Define LOGON32_PROVIDER_DEFAULT    0
#Define LOGON32_PROVIDER_WINNT35    1
#Define LOGON32_PROVIDER_WINNT40    2
#Define LOGON32_PROVIDER_WINNT50    3

#Define HW_PROFILE_GUIDLEN          39
#Define MAX_PROFILE_LEN             80

#Define DOCKINFO_UNDOCKED			01H
#Define DOCKINFO_DOCKED				02H
#Define DOCKINFO_USER_SUPPLIED		04H
#Define DOCKINFO_USER_UNDOCKED		(DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#Define DOCKINFO_USER_DOCKED		(DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

#Define VER_PLATFORM_WIN32s       	0
#Define VER_PLATFORM_WIN32_WINDOWS	1
#Define VER_PLATFORM_WIN32_NT		2

#Define TC_NORMAL       		0
#Define TC_HARDERR      		1
#Define TC_GP_TRAP      		2
#Define TC_SIGNAL       		3

#Define AC_LINE_OFFLINE         000H
#Define AC_LINE_ONLINE          001H
#Define AC_LINE_BACKUP_POWER    002H
#Define AC_LINE_UNKNOWN         0FFH

#Define BATTERY_FLAG_HIGH       001H
#Define BATTERY_FLAG_LOW        002H
#Define BATTERY_FLAG_CRITICAL   004H
#Define BATTERY_FLAG_CHARGING   008H
#Define BATTERY_FLAG_NO_BATTERY 080H
#Define BATTERY_FLAG_UNKNOWN    0FFH

#Define BATTERY_PERCENTAGE_UNKNOWN	0FFH

#Define BATTERY_LIFE_UNKNOWN        0FFFFFFFFH

#Define WIN_CERT_REVISION_1_0           00100H
#Define WIN_CERT_REVISION_2_0           00200H

#Define WIN_CERT_TYPE_X509              00001H
#Define WIN_CERT_TYPE_PKCS_SIGNED_DATA	00002H
#Define WIN_CERT_TYPE_RESERVED_1		00003H

#Define WIN_TRUST_SUBJTYPE_RAW_FILE			{0959DC450H, 08D9EH, 011CFH, {087H, 036H, 00H, 0AAH, 00H, 0A4H, 085H, 0EBH}}
#Define WIN_TRUST_SUBJTYPE_PE_IMAGE			{043C9A1E0H, 08DA0H, 011CFH, {087H, 036H, 00H, 0AAH, 00H, 0A4H, 085H, 0EBH}}
#Define WIN_TRUST_SUBJTYPE_JAVA_CLASS		{008AD3990H, 08DA1H, 011CFH, {087H, 036H, 00H, 0AAH, 00H, 0A4H, 085H, 0EBH}}
#Define WIN_TRUST_SUBJTYPE_CABINET			{0D17C5374H, 0A392H, 011CFH, {09DH, 0F5H, 00H, 0AAH, 00H, 0C1H, 084H, 0E0H}}
#Define WIN_TRUST_SUBJTYPE_RAW_FILEEX		{06F458110H, 0C2F1H, 011CFH, {08AH, 069H, 00H, 0AAH, 00H, 06CH, 037H, 06H}}
#Define WIN_TRUST_SUBJTYPE_PE_IMAGEEX		{06F458111H, 0C2F1H, 011CFH, {08AH, 069H, 00H, 0AAH, 00H, 06CH, 037H, 06H}}
#Define WIN_TRUST_SUBJTYPE_JAVA_CLASSEX		{06F458113H, 0C2F1H, 011CFH, {08AH, 069H, 00H, 0AAH, 00H, 06CH, 037H, 06H}}
#Define WIN_TRUST_SUBJTYPE_CABINETEX		{06F458114H, 0C2F1H, 011CFH, {08AH, 069H, 00H, 0AAH, 00H, 06CH, 037H, 06H}}
#Define WIN_TRUST_SUBJTYPE_OLE_STORAGE		{0C257E740H, 08DA0H, 011CFH, {087H, 036H, 00H, 0AAH, 00H, 0A4H, 085H, 0EBH}}
#Define WIN_SPUB_ACTION_TRUSTED_PUBLISHER	{066426730H, 08DA1H, 011CFH, {087H, 036H, 00H, 0AAH, 00H, 0A4H, 085H, 0EBH}}
#Define WIN_SPUB_ACTION_NT_ACTIVATE_IMAGE	{08BC96B00H, 08DA1H, 011CFH, {087H, 036H, 00H, 0AAH, 00H, 0A4H, 085H, 0EBH}}
#Define WIN_SPUB_ACTION_PUBLISHED_SOFTWARE	{064B9D180H, 08DA2H, 011CFH, {087H, 036H, 00H, 0AAH, 00H, 0A4H, 085H, 0EBH}}


OVERLAPPED Struct
	Internal DD
	InternalHigh DD
	Offset DD
	OffsetHigh DD
	hEvent DD
EndS

SECURITY_ATTRIBUTES Struct
	nLength DD
	lpSecurityDescriptor DD
	bInheritHandle DD
EndS

PROCESS_INFORMATION Struct
	hProcess DD
	hThread DD
	dwProcessId DD
	dwThreadId DD
EndS

FILETIME Struct
	dwLowDateTime DD
	dwHighDateTime DD
EndS

SYSTEMTIME Struct
	wYear DW
	wMonth DW
	wDayOfWeek DW
	wDay DW
	wHour DW
	wMinute DW
	wSecond DW
	wMilliseconds DW
EndS

COMMPROP Struct
	wPacketLength DW
	wPacketVersion DW
	dwServiceMask DD
	dwReserved1 DD
	dwMaxTxQueue DD
	dwMaxRxQueue DD
	dwMaxBaud DD
	dwProvSubType DD
	dwProvCapabilities DD
	dwSettableParams DD
	dwSettableBaud DD
	wSettableData DW
	wSettableStopParity DW
	dwCurrentTxQueue DD
	dwCurrentRxQueue DD
	dwProvSpec1 DD
	dwProvSpec2 DD
	wcProvChar DW 1 Dup ?
EndS

COMSTAT Struct
	fCtsHold DD ;1
	fDsrHold DD ;1
	fRlsdHold DD ;1
	fXoffHold DD ;1
	fXoffSent DD ;1
	fEof DD ;1
	fTxim DD ;1
	fReserved DD ;25
	cbInQue DD
	cbOutQue DD
EndS

DCB Struct
	DCBlength DD
	BaudRate DD
	Flags DD	;fBinary:1, fParity:1, fOutxCtsFlow:1, fOutxDsrFlow:1, fDtrControl:2, fDsrSensitivity:1, fTXContinueOnXoff:1, fOutX:1, fInX DD:1, fErrorChar:1, fNull:1, fRtsControl:2, fAbortOnError:1, fDummy2:17
	wReserved DW
	XonLim DW
	XoffLim DW
	ByteSize DB
	Parity DB
	StopBits DB
	XonChar DB
	XoffChar DB
	ErrorChar DB
	EofChar DB
	EvtChar DB
	wReserved1 DW
EndS

COMMTIMEOUTS Struct
	ReadIntervalTimeout DD
	ReadTotalTimeoutMultiplier DD
	ReadTotalTimeoutConstant DD
	WriteTotalTimeoutMultiplier DD
	WriteTotalTimeoutConstant DD
EndS

COMMCONFIG Struct
	dwSize DD
	wVersion DW
	wReserved DW
	dcb DCB <>
    DWORD dwProviderSubType DD
    DWORD dwProviderOffset DD
    DWORD dwProviderSize DD
    WCHAR wcProviderData DW
EndS

SYSTEM_INFO Struct
	Union
		dwOemId DD
        Struct
			wProcessorArchitecture DW
			wReserved DW
		EndS
	EndUnion
	dwPageSize DD
	lpMinimumApplicationAddress DD
	lpMaximumApplicationAddress DD
	dwActiveProcessorMask DD
	dwNumberOfProcessors DD
	dwProcessorType DD
	dwAllocationGranularity DD
	wProcessorLevel DW
	wProcessorRevision DW
EndS

MEMORYSTATUS Struct
	dwLength DD
	dwMemoryLoad DD
	dwTotalPhys DD
	dwAvailPhys DD
	dwTotalPageFile DD
	dwAvailPageFile DD
	dwTotalVirtual DD
	dwAvailVirtual DD
EndS

EXCEPTION_DEBUG_INFO Struct
	ExceptionRecord EXCEPTION_RECORD <>
	dwFirstChance DD
EndS

CREATE_THREAD_DEBUG_INFO Struct
	hThread DD
	lpThreadLocalBase DD
	lpStartAddress DD
EndS

CREATE_PROCESS_DEBUG_INFO Struct
	hFile DD
	hProcess DD
	hThread DD
	lpBaseOfImage DD
	dwDebugInfoFileOffset DD
	nDebugInfoSize DD
	lpThreadLocalBase DD
	lpStartAddress DD
	lpImageName DD
	fUnicode DW
EndS

EXIT_THREAD_DEBUG_INFO Struct
	dwExitCode DD
EndS

EXIT_PROCESS_DEBUG_INFO Struct
	dwExitCode DD
EndS

LOAD_DLL_DEBUG_INFO Struct
	hFile DD
	lpBaseOfDll DD
	dwDebugInfoFileOffset DD
	nDebugInfoSize DD
	lpImageName DD
	fUnicode DW
EndS

UNLOAD_DLL_DEBUG_INFO Struct
	lpBaseOfDll DD
EndS

OUTPUT_DEBUG_STRING_INFO Struct
	lpDebugStringData DD
	fUnicode DW
	nDebugStringLength DW
EndS

RIP_INFO Struct
	dwError DD
	dwType DD
EndS

DEBUG_EVENT Struct
	dwDebugEventCode DD
	dwProcessId DD
	dwThreadId DD
	Union
		Exception EXCEPTION_DEBUG_INFO <>
		CreateThread CREATE_THREAD_DEBUG_INFO <>
		CreateProcessInfo CREATE_PROCESS_DEBUG_INFO <>
		ExitThread EXIT_THREAD_DEBUG_INFO <>
		ExitProcess EXIT_PROCESS_DEBUG_INFO <>
		LoadDll LOAD_DLL_DEBUG_INFO <>
		UnloadDll UNLOAD_DLL_DEBUG_INFO <>
		DebugString OUTPUT_DEBUG_STRING_INFO <>
		RipInfo RIP_INFO <>
	EndUnion
EndS

OFSTRUCT Struct
	cBytes DB
	fFixedDisk DB
	nErrCode DW
	Reserved1 DW
	Reserved2 DW
	szPathName DB OFS_MAXPATHNAME Dup ?
EndS

PROCESS_HEAP_ENTRY Struct
	lpData DD
	cbData DD
	cbOverhead DB
	iRegionIndex DB
	wFlags DW
	Union
		Block Struct
			hMem DD
			dwReserved DD 3 Dup ?
		EndS
		Region Struct
			dwCommittedSize DD
			dwUnCommittedSize DD
			lpFirstBlock DD
			lpLastBlock DD
		EndS
	EndUnion
EndS

BY_HANDLE_FILE_INFORMATION Struct
	dwFileAttributes DD
	ftCreationTime FILETIME <>
	ftLastAccessTime FILETIME <>
	ftLastWriteTime FILETIME <>
	dwVolumeSerialNumber DD
	nFileSizeHigh DD
	nFileSizeLow DD
	nNumberOfLinks DD
	nFileIndexHigh DD
	nFileIndexLow DD
EndS

TIME_ZONE_INFORMATION Struct
	Bias DD
	StandardName DW 32 Dup ?
	StandardDate SYSTEMTIME <>
	StandardBias DD
	DaylightName DW 32 Dup ?
	DaylightDate SYSTEMTIME<>
	DaylightBias DD
EndS

RECOVERY_AGENT_INFORMATIONA Struct
	NextEntryOffset DD
	AgentNameLength DD
	AgentInformation DB
EndS

RECOVERY_AGENT_INFORMATIONW Struct
	NextEntryOffset DD
	AgentNameLength DD
	AgentInformation DW
EndS

WIN32_STREAM_ID Struct
	dwStreamId DD
	dwStreamAttributes DD
	Size LARGE_INTEGER <>
	dwStreamNameSize DD
	cStreamName DW ANYSIZE_ARRAY Dup ?
EndS

STARTUPINFOA Struct
	cb DD
	lpReserved DD
	lpDesktop DD
	lpTitle DD
	dwX DD
	dwY DD
	dwXSize DD
	dwYSize DD
	dwXCountChars DD
	dwYCountChars DD
	dwFillAttribute DD
	dwFlags DD
	wShowWindow DW
	cbReserved2 DW
	lpReserved2 DD
	hStdInput DD
	hStdOutput DD
	hStdError DD
EndS

STARTUPINFOW Struct
	cb DD
	lpReserved DD
	lpDesktop DD
	lpTitle DD
	dwX DD
	dwY DD
	dwXSize DD
	dwYSize DD
	dwXCountChars DD
	dwYCountChars DD
	dwFillAttribute DD
	dwFlags DD
	wShowWindow DW
	cbReserved2 DW
	lpReserved2 DD
	hStdInput DD
	hStdOutput DD
	hStdError DD
EndS

WIN32_FIND_DATAA Struct
	dwFileAttributes DD
	ftCreationTime FILETIME <>
	ftLastAccessTime FILETIME <>
	ftLastWriteTime FILETIME <>
	nFileSizeHigh DD
	nFileSizeLow DD
	dwReserved0 DD
	dwReserved1 DD
	cFileName DB MAX_PATH Dup ?
	cAlternateFileName DB 14 Dup ?
EndS

WIN32_FIND_DATAW Struct
	dwFileAttributes DD
	ftCreationTime FILETIME <>
	ftLastAccessTime FILETIME <>
	ftLastWriteTime FILETIME <>
	nFileSizeHigh DD
	nFileSizeLow DD
	dwReserved0 DD
	dwReserved1 DD
	cFileName DW MAX_PATH Dup ?
	cAlternateFileName DW 14 Dup ?
EndS

WIN32_FILE_ATTRIBUTE_DATA Struct
	dwFileAttributes DD
	ftCreationTime FILETIME <>
	ftLastAccessTime FILETIME <>
	ftLastWriteTime FILETIME <>
	nFileSizeHigh DD
	nFileSizeLow DD
EndS

HW_PROFILE_INFOA Struct
	dwDockInfo DD
	szHwProfileGuid DB HW_PROFILE_GUIDLEN Dup ?
	szHwProfileName DB MAX_PROFILE_LEN Dup ?
EndS

HW_PROFILE_INFOW Struct
	dwDockInfo DD
	szHwProfileGuid DW HW_PROFILE_GUIDLEN Dup ?
	szHwProfileName DW MAX_PROFILE_LEN Dup ?
EndS

OSVERSIONINFOA Struct
	dwOSVersionInfoSize DD
	dwMajorVersion DD
	dwMinorVersion DD
	dwBuildNumber DD
	dwPlatformId DD
	szCSDVersion DB 128 Dup ?
EndS

OSVERSIONINFOW Struct
	dwOSVersionInfoSize DD
	dwMajorVersion DD
	dwMinorVersion DD
	dwBuildNumber DD
	dwPlatformId DD
	szCSDVersion DW 128 Dup ?
EndS

OSVERSIONINFOEXA Struct
	dwOSVersionInfoSize DD
	dwMajorVersion DD
	dwMinorVersion DD
	dwBuildNumber DD
	dwPlatformId DD
	szCSDVersion DB 128 Dup ?
	wServicePackMajor DW
	wServicePackMinor DW
	wReserved DW 2 Dup ?
EndS

OSVERSIONINFOEXW Struct
	dwOSVersionInfoSize DD
	dwMajorVersion DD
	dwMinorVersion DD
	dwBuildNumber DD
	dwPlatformId DD
	szCSDVersion DW 128 Dup ?
	wServicePackMajor DW
	wServicePackMinor DW
	wReserved DW 2 Dup ?
EndS

SYSTEM_POWER_STATUS Struct
	ACLineStatus DB
	BatteryFlag DB
	BatteryLifePercent DB
	Reserved1 DB
	BatteryLifeTime DD
	BatteryFullLifeTime DD
EndS

WIN_CERTIFICATE Struct
	dwLength DD
	wRevision DW
	wCertificateType DW
	bCertificate DB ANYSIZE_ARRAY Dup ?
EndS

WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT Struct
	hClientToken DD
	SubjectType DD
	Subject DD
EndS

WIN_TRUST_ACTDATA_SUBJECT_ONLY Struct
	SubjectType DD
	Subject DD
EndS

WIN_TRUST_SUBJECT_FILE Struct
	hFile DD
	lpPath DD
EndS

WIN_TRUST_SUBJECT_FILE_AND_DISPLAY Struct
	hFile DD
	lpPath DD
	lpDisplayName DD
EndS

WIN_SPUB_TRUSTED_PUBLISHER_DATA Struct
	hClientToken DD
	lpCertificate DD
EndS

MEMORYSTATUSVLM Struct
	dwLength DD
	dwMemoryLoad DD
	ullTotalPhys DQ
	ullAvailPhys DQ
	ullTotalPageFile DQ
	ullAvailPageFile DQ
	ullTotalVirtual DQ
	ullAvailVirtual DQ
	ullAvailExtendedVirtual DQ
EndS


#IF STRINGS UNICODE
	#Define GetBinaryType GetBinaryTypeW
	#Define GetShortPathName GetShortPathNameW
	#Define GetLongPathName GetLongPathNameW
	#Define GetEnvironmentStrings GetEnvironmentStringsW
	#Define FreeEnvironmentStrings FreeEnvironmentStringsW
	#Define FormatMessage FormatMessageW
	#Define CreateMailslot CreateMailslotW
	#Define EncryptFile EncryptFileW
	#Define DecryptFile DecryptFileW
	#Define OpenRaw OpenRawW
	#Define RECOVERY_AGENT_INFORMATION RECOVERY_AGENT_INFORMATIONW
	#Define QueryRecoveryAgents QueryRecoveryAgentsW
	#Define lstrcmp lstrcmpW
	#Define lstrcmpi lstrcmpiW
	#Define lstrcpyn lstrcpynW
	#Define lstrcpy lstrcpyW
	#Define lstrcat lstrcatW
	#Define lstrlen lstrlenW
	#Define STARTUPINFO STARTUPINFOW
	#Define WIN32_FIND_DATA WIN32_FIND_DATAW
	#Define CreateMutex CreateMutexW
	#Define OpenMutex OpenMutexW
	#Define CreateEvent CreateEventW
	#Define OpenEvent OpenEventW
	#Define CreateSemaphore CreateSemaphoreW
	#Define OpenSemaphore OpenSemaphoreW
	#Define CreateWaitableTimer CreateWaitableTimerW
	#Define OpenWaitableTimer OpenWaitableTimerW
	#Define CreateFileMapping CreateFileMappingW
	#Define OpenFileMapping OpenFileMappingW
	#Define GetLogicalDriveStrings GetLogicalDriveStringsW
	#Define LoadLibrary LoadLibraryW
	#Define LoadLibraryEx LoadLibraryExW
	#Define GetModuleFileName GetModuleFileNameW
	#Define GetModuleHandle GetModuleHandleW
	#Define CreateProcess CreateProcessW
	#Define FatalAppExit FatalAppExitW
	#Define GetStartupInfo GetStartupInfoW
	#Define GetCommandLine GetCommandLineW
	#Define GetEnvironmentVariable GetEnvironmentVariableW
	#Define SetEnvironmentVariable SetEnvironmentVariableW
	#Define ExpandEnvironmentStrings ExpandEnvironmentStringsW
	#Define OutputDebugString OutputDebugStringW
	#Define FindResource FindResourceW
	#Define FindResourceEx FindResourceExW
	#Define EnumResourceTypes EnumResourceTypesW
	#Define EnumResourceNames EnumResourceNamesW
	#Define EnumResourceLanguages EnumResourceLanguagesW
	#Define BeginUpdateResource BeginUpdateResourceW
	#Define UpdateResource UpdateResourceW
	#Define EndUpdateResource EndUpdateResourceW
	#Define GlobalAddAtom GlobalAddAtomW
	#Define GlobalFindAtom GlobalFindAtomW
	#Define GlobalGetAtomName GlobalGetAtomNameW
	#Define AddAtom AddAtomW
	#Define FindAtom FindAtomW
	#Define GetAtomName GetAtomNameW
	#Define GetProfileInt GetProfileIntW
	#Define GetProfileString GetProfileStringW
	#Define WriteProfileString WriteProfileStringW
	#Define GetProfileSection GetProfileSectionW
	#Define WriteProfileSection WriteProfileSectionW
	#Define GetPrivateProfileInt GetPrivateProfileIntW
	#Define GetPrivateProfileString GetPrivateProfileStringW
	#Define WritePrivateProfileString WritePrivateProfileStringW
	#Define GetPrivateProfileSection GetPrivateProfileSectionW
	#Define WritePrivateProfileSection WritePrivateProfileSectionW
	#Define GetPrivateProfileSectionNames GetPrivateProfileSectionNamesW
	#Define GetPrivateProfileStruct GetPrivateProfileStructW
	#Define WritePrivateProfileStruct WritePrivateProfileStructW
	#Define GetDriveType GetDriveTypeW
	#Define GetSystemDirectory GetSystemDirectoryW
	#Define GetTempPath GetTempPathW
	#Define GetTempFileName GetTempFileNameW
	#Define GetWindowsDirectory GetWindowsDirectoryW
	#Define SetCurrentDirectory SetCurrentDirectoryW
	#Define GetCurrentDirectory GetCurrentDirectoryW
	#Define GetDiskFreeSpace GetDiskFreeSpaceW
	#Define GetDiskFreeSpaceEx GetDiskFreeSpaceExW
	#Define CreateDirectory CreateDirectoryW
	#Define CreateDirectoryEx CreateDirectoryExW
	#Define RemoveDirectory RemoveDirectoryW
	#Define GetFullPathName GetFullPathNameW
	#Define DefineDosDevice DefineDosDeviceW
	#Define QueryDosDevice QueryDosDeviceW
	#Define CreateFile CreateFileW
	#Define SetFileAttributes SetFileAttributesW
	#Define GetFileAttributes GetFileAttributesW
	#Define GetFileAttributesEx GetFileAttributesExW
	#Define GetCompressedFileSize GetCompressedFileSizeW
	#Define DeleteFile DeleteFileW
	#Define FindFirstFileEx FindFirstFileExW
	#Define FindFirstFile FindFirstFileW
	#Define FindNextFile FindNextFileW
	#Define SearchPath SearchPathW
	#Define CopyFile CopyFileW
	#Define CopyFileEx CopyFileExW
	#Define MoveFile MoveFileW
	#Define MoveFileEx MoveFileExW
	#Define MoveFileWithProgress MoveFileWithProgressW
	#Define CreateHardLink CreateHardLinkW
	#Define CreateNamedPipe CreateNamedPipeW
	#Define GetNamedPipeHandleState GetNamedPipeHandleStateW
	#Define CallNamedPipe CallNamedPipeW
	#Define WaitNamedPipe WaitNamedPipeW
	#Define SetVolumeLabel SetVolumeLabelW
	#Define GetVolumeInformation GetVolumeInformationW
	#Define ClearEventLog ClearEventLogW
	#Define BackupEventLog BackupEventLogW
	#Define OpenEventLog OpenEventLogW
	#Define RegisterEventSource RegisterEventSourceW
	#Define OpenBackupEventLog OpenBackupEventLogW
	#Define ReadEventLog ReadEventLogW
	#Define ReportEvent ReportEventW
	#Define AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
	#Define AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
	#Define AccessCheckByTypeResultListAndAuditAlarm AccessCheckByTypeResultListAndAuditAlarmW
	#Define ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
	#Define ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
	#Define ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
	#Define ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
	#Define PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
	#Define SetFileSecurity SetFileSecurityW
	#Define GetFileSecurity GetFileSecurityW
	#Define FindFirstChangeNotification FindFirstChangeNotificationW
	#Define IsBadStringPtr IsBadStringPtrW
	#Define LookupAccountSid LookupAccountSidW
	#Define LookupAccountName LookupAccountNameW
	#Define LookupPrivilegeValue LookupPrivilegeValueW
	#Define LookupPrivilegeName LookupPrivilegeNameW
	#Define LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
	#Define BuildCommDCB BuildCommDCBW
	#Define BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
	#Define CommConfigDialog CommConfigDialogW
	#Define GetDefaultCommConfig GetDefaultCommConfigW
	#Define SetDefaultCommConfig SetDefaultCommConfigW
	#Define GetComputerName GetComputerNameW
	#Define SetComputerName SetComputerNameW
	#Define GetUserName GetUserNameW
	#Define LogonUser LogonUserW
	#Define CreateProcessAsUser CreateProcessAsUserW
	#Define HW_PROFILE_INFO HW_PROFILE_INFOW
	#Define GetCurrentHwProfile GetCurrentHwProfileW
	#Define OSVERSIONINFO OSVERSIONINFOW
	#Define OSVERSIONINFOEX OSVERSIONINFOEXW
	#Define GetVersionEx GetVersionExW
	#Define CreateJobObject CreateJobObjectW
	#Define OpenJobObject OpenJobObjectW
#ELSE
	#Define GetBinaryType GetBinaryTypeA
	#Define GetShortPathName GetShortPathNameA
	#Define GetLongPathName GetLongPathNameA
	#Define GetEnvironmentStrings GetEnvironmentStringsA
	#Define FreeEnvironmentStrings FreeEnvironmentStringsA
	#Define FormatMessage FormatMessageA
	#Define CreateMailslot CreateMailslotA
	#Define EncryptFile EncryptFileA
	#Define DecryptFile DecryptFileA
	#Define OpenRaw OpenRawA
	#Define RECOVERY_AGENT_INFORMATION RECOVERY_AGENT_INFORMATIONA
	#Define QueryRecoveryAgents QueryRecoveryAgentsA
	#Define lstrcmp lstrcmpA
	#Define lstrcmpi lstrcmpiA
	#Define lstrcpyn lstrcpynA
	#Define lstrcpy lstrcpyA
	#Define lstrcat lstrcatA
	#Define lstrlen lstrlenA
	#Define STARTUPINFO STARTUPINFOA
	#Define WIN32_FIND_DATA WIN32_FIND_DATAA
	#Define CreateMutex CreateMutexA
	#Define OpenMutex OpenMutexA
	#Define CreateEvent CreateEventA
	#Define OpenEvent OpenEventA
	#Define CreateSemaphore CreateSemaphoreA
	#Define OpenSemaphore OpenSemaphoreA
	#Define CreateWaitableTimer CreateWaitableTimerA
	#Define OpenWaitableTimer OpenWaitableTimerA
	#Define CreateFileMapping CreateFileMappingA
	#Define OpenFileMapping OpenFileMappingA
	#Define GetLogicalDriveStrings GetLogicalDriveStringsA
	#Define LoadLibrary LoadLibraryA
	#Define LoadLibraryEx LoadLibraryExA
	#Define GetModuleFileName GetModuleFileNameA
	#Define GetModuleHandle GetModuleHandleA
	#Define CreateProcess CreateProcessA
	#Define FatalAppExit FatalAppExitA
	#Define GetStartupInfo GetStartupInfoA
	#Define GetCommandLine GetCommandLineA
	#Define GetEnvironmentVariable GetEnvironmentVariableA
	#Define SetEnvironmentVariable SetEnvironmentVariableA
	#Define ExpandEnvironmentStrings ExpandEnvironmentStringsA
	#Define OutputDebugString OutputDebugStringA
	#Define FindResource FindResourceA
	#Define FindResourceEx FindResourceExA
	#Define EnumResourceTypes EnumResourceTypesA
	#Define EnumResourceNames EnumResourceNamesA
	#Define EnumResourceLanguages EnumResourceLanguagesA
	#Define BeginUpdateResource BeginUpdateResourceA
	#Define UpdateResource UpdateResourceA
	#Define EndUpdateResource EndUpdateResourceA
	#Define GlobalAddAtom GlobalAddAtomA
	#Define GlobalFindAtom GlobalFindAtomA
	#Define GlobalGetAtomName GlobalGetAtomNameA
	#Define AddAtom AddAtomA
	#Define FindAtom FindAtomA
	#Define GetAtomName GetAtomNameA
	#Define GetProfileInt GetProfileIntA
	#Define GetProfileString GetProfileStringA
	#Define WriteProfileString WriteProfileStringA
	#Define GetProfileSection GetProfileSectionA
	#Define WriteProfileSection WriteProfileSectionA
	#Define GetPrivateProfileInt GetPrivateProfileIntA
	#Define GetPrivateProfileString GetPrivateProfileStringA
	#Define WritePrivateProfileString WritePrivateProfileStringA
	#Define GetPrivateProfileSection GetPrivateProfileSectionA
	#Define WritePrivateProfileSection WritePrivateProfileSectionA
	#Define GetPrivateProfileSectionNames GetPrivateProfileSectionNamesA
	#Define GetPrivateProfileStruct GetPrivateProfileStructA
	#Define WritePrivateProfileStruct WritePrivateProfileStructA
	#Define GetDriveType GetDriveTypeA
	#Define GetSystemDirectory GetSystemDirectoryA
	#Define GetTempPath GetTempPathA
	#Define GetTempFileName GetTempFileNameA
	#Define GetWindowsDirectory GetWindowsDirectoryA
	#Define SetCurrentDirectory SetCurrentDirectoryA
	#Define GetCurrentDirectory GetCurrentDirectoryA
	#Define GetDiskFreeSpace GetDiskFreeSpaceA
	#Define GetDiskFreeSpaceEx GetDiskFreeSpaceExA
	#Define CreateDirectory CreateDirectoryA
	#Define CreateDirectoryEx CreateDirectoryExA
	#Define RemoveDirectory RemoveDirectoryA
	#Define GetFullPathName GetFullPathNameA
	#Define DefineDosDevice DefineDosDeviceA
	#Define QueryDosDevice QueryDosDeviceA
	#Define CreateFile CreateFileA
	#Define SetFileAttributes SetFileAttributesA
	#Define GetFileAttributes GetFileAttributesA
	#Define GetFileAttributesEx GetFileAttributesExA
	#Define GetCompressedFileSize GetCompressedFileSizeA
	#Define DeleteFile DeleteFileA
	#Define FindFirstFileEx FindFirstFileExA
	#Define FindFirstFile FindFirstFileA
	#Define FindNextFile FindNextFileA
	#Define SearchPath SearchPathA
	#Define CopyFile CopyFileA
	#Define CopyFileEx CopyFileExA
	#Define MoveFile MoveFileA
	#Define MoveFileEx MoveFileExA
	#Define MoveFileWithProgress MoveFileWithProgressA
	#Define CreateHardLink CreateHardLinkA
	#Define CreateNamedPipe CreateNamedPipeA
	#Define GetNamedPipeHandleState GetNamedPipeHandleStateA
	#Define CallNamedPipe CallNamedPipeA
	#Define WaitNamedPipe WaitNamedPipeA
	#Define SetVolumeLabel SetVolumeLabelA
	#Define GetVolumeInformation GetVolumeInformationA
	#Define ClearEventLog ClearEventLogA
	#Define BackupEventLog BackupEventLogA
	#Define OpenEventLog OpenEventLogA
	#Define RegisterEventSource RegisterEventSourceA
	#Define OpenBackupEventLog OpenBackupEventLogA
	#Define ReadEventLog ReadEventLogA
	#Define ReportEvent ReportEventA
	#Define AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
	#Define AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
	#Define AccessCheckByTypeResultListAndAuditAlarm AccessCheckByTypeResultListAndAuditAlarmA
	#Define ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
	#Define ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
	#Define ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
	#Define ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
	#Define PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
	#Define SetFileSecurity SetFileSecurityA
	#Define GetFileSecurity GetFileSecurityA
	#Define FindFirstChangeNotification FindFirstChangeNotificationA
	#Define IsBadStringPtr IsBadStringPtrA
	#Define LookupAccountSid LookupAccountSidA
	#Define LookupAccountName LookupAccountNameA
	#Define LookupPrivilegeValue LookupPrivilegeValueA
	#Define LookupPrivilegeName LookupPrivilegeNameA
	#Define LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
	#Define BuildCommDCB BuildCommDCBA
	#Define BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
	#Define CommConfigDialog CommConfigDialogA
	#Define GetDefaultCommConfig GetDefaultCommConfigA
	#Define SetDefaultCommConfig SetDefaultCommConfigA
	#Define GetComputerName GetComputerNameA
	#Define SetComputerName SetComputerNameA
	#Define GetUserName GetUserNameA
	#Define LogonUser LogonUserA
	#Define CreateProcessAsUser CreateProcessAsUserA
	#Define HW_PROFILE_INFO HW_PROFILE_INFOA
	#Define GetCurrentHwProfile GetCurrentHwProfileA
	#Define OSVERSIONINFO OSVERSIONINFOA
	#Define OSVERSIONINFOEX OSVERSIONINFOEXA
	#Define GetVersionEx GetVersionExA
	#Define CreateJobObject CreateJobObjectA
	#Define OpenJobObject OpenJobObjectA
#ENDIF


#ENDIF ;WINBASE_INC
