#ifndef WINBASE_H
#define WINBASE_H

#DEFINE WINBASE_H_REQVER 100

/*
Dependancies
dbgapi.h (CE only)
kfuncs.h (CE only)
winerror.h
*/

/*
Switches used:
WINCE = Set definitions for Windows CE (note: some are not compatible with 9x/NT)
UNICODE = Use UNICODE versions
*/

#IFDEF LINKFILES
	#dynamiclinkfile Kernel32.dll
	#dynamiclinkfile Advapi32.dll
#ENDIF

#if WINVER = NTDDI_WINCE
	#include dbgapi.h  // WIN3264
	; I do not have a copy of kfuncs.h if someone does please email me
	;#include kfuncs.h
#endif

#IFNDEF WINERROR_H
	#include winerror.h  // WIN3264
#ENDIF

// Vista has file information extensions that are available in XP
// with a redistributable. They are defined in a separate header
// and included for NTDDI_WINXP and above. Note that the APIs
// associated with this file are not shipped with XP.
#IF WINVER >= NTDDI_WINXP
	#ifndef FILEEXTD_H
		#include "fileextd.h"
	#ENDIF
#ENDIF

// Aliases used for backward comptibility
#define LockSegment GlobalFix
#define UnlockSegment GlobalUnfix
#define GetCurrentTime GetTickCount
#define MoveMemory RtlMoveMemory
;#define CopyMemory RtlCopyMemory
#define FillMemory RtlFillMemory
#define ZeroMemory RtlZeroMemory
#define SecureZeroMemory RtlSecureZeroMemory
#define CaptureStackBackTrace RtlCaptureStackBackTrace

#Define STATUS_WAIT_0 00000000h
#Define STATUS_ABANDONED_WAIT_0 00000080h
#Define STATUS_USER_APC 000000C0h
#Define STATUS_TIMEOUT 00000102h
#Define STATUS_PENDING 00000103h
#Define STATUS_DATATYPE_MISALIGNMENT 80000002h
#Define STATUS_BREAKPOINT 80000003h
#Define STATUS_SINGLE_STEP 80000004h
#Define STATUS_ACCESS_VIOLATION 0C0000005h
#Define STATUS_IN_PAGE_ERROR 0C0000006h
#Define STATUS_NO_MEMORY 0C0000017h
#Define STATUS_ILLEGAL_INSTRUCTION 0C000001Dh
#Define STATUS_NONCONTINUABLE_EXCEPTION 0C0000025h
#Define STATUS_INVALID_DISPOSITION 0C0000026h
#Define STATUS_ARRAY_BOUNDS_EXCEEDED 0C000008Ch
#Define STATUS_FLOAT_DENORMAL_OPERAND 0C000008Dh
#Define STATUS_FLOAT_DIVIDE_BY_ZERO 0C000008Eh
#Define STATUS_FLOAT_INEXACT_RESULT 0C000008Fh
#Define STATUS_FLOAT_INVALID_OPERATION 0C0000090h
#Define STATUS_FLOAT_OVERFLOW 0C0000091h
#Define STATUS_FLOAT_STACK_CHECK 0C0000092h
#Define STATUS_FLOAT_UNDERFLOW 0C0000093h
#Define STATUS_INTEGER_DIVIDE_BY_ZERO 0C0000094h
#Define STATUS_INTEGER_OVERFLOW 0C0000095h
#Define STATUS_PRIVILEGED_INSTRUCTION 0C0000096h
#Define STATUS_STACK_OVERFLOW 0C00000FDh
#Define STATUS_CONTROL_C_EXIT 0C000013Ah
#define STATUS_POSSIBLE_DEADLOCK 0xC0000194

#define INVALID_HANDLE_VALUE -1
#define INVALID_FILE_SIZE 0xFFFFFFFF
#define INVALID_SET_FILE_POINTER -1
#define INVALID_FILE_ATTRIBUTES -1

#define FILE_BEGIN 0
#define FILE_CURRENT 1
#define FILE_END 2
#define TIME_ZONE_ID_INVALID 0xFFFFFFFF
#define WAIT_FAILED 0xFFFFFFFF
#define WAIT_OBJECT_0 0
#define WAIT_ABANDONED 00000080h
#define WAIT_ABANDONED_0 00000080h
#define WAIT_IO_COMPLETION 000000C0h
#define STILL_ACTIVE 00000103h

#define EXCEPTION_ACCESS_VIOLATION 0C0000005h
#define EXCEPTION_DATATYPE_MISALIGNMENT 80000002h
#define EXCEPTION_BREAKPOINT 80000003h
#define EXCEPTION_SINGLE_STEP 80000004h
#define EXCEPTION_ARRAY_BOUNDS_EXCEEDED 0C000008Ch
#define EXCEPTION_FLT_DENORMAL_OPERAND  0C000008Dh
#define EXCEPTION_FLT_DIVIDE_BY_ZERO  0C000008Eh
#define EXCEPTION_FLT_INEXACT_RESULT  0C000008Fh
#define EXCEPTION_FLT_INVALID_OPERATION  0C0000090h
#define EXCEPTION_FLT_OVERFLOW  0C0000091h
#define EXCEPTION_FLT_STACK_CHECK  0C0000092h
#define EXCEPTION_FLT_UNDERFLOW  0C0000093h
#define EXCEPTION_INT_DIVIDE_BY_ZERO  0C0000094h
#define EXCEPTION_INT_OVERFLOW  0C0000095h
#define EXCEPTION_PRIV_INSTRUCTION  0C0000096h
#define EXCEPTION_IN_PAGE_ERROR  0C0000006h
#define EXCEPTION_ILLEGAL_INSTRUCTION  0C000001Dh
#define EXCEPTION_NONCONTINUABLE_EXCEPTION  0C0000025h
#define EXCEPTION_STACK_OVERFLOW  0C00000FDh
#define EXCEPTION_INVALID_DISPOSITION  0C0000026h
#define EXCEPTION_GUARD_PAGE  080000001h
#define EXCEPTION_INVALID_HANDLE  0C0000008h
#define CONTROL_C_EXIT  0C000013Ah
#define EXCEPTION_POSSIBLE_DEADLOCK STATUS_POSSIBLE_DEADLOCK

#define FILE_FLAG_WRITE_THROUGH  0x80000000
#define FILE_FLAG_OVERLAPPED  0x40000000
#define FILE_FLAG_NO_BUFFERING  0x20000000
#define FILE_FLAG_RANDOM_ACCESS  0x10000000
#define FILE_FLAG_SEQUENTIAL_SCAN  0x08000000
#define FILE_FLAG_DELETE_ON_CLOSE  0x04000000
#define FILE_FLAG_BACKUP_SEMANTICS  0x02000000
#define FILE_FLAG_POSIX_SEMANTICS  0x01000000
#define FILE_FLAG_OPEN_REPARSE_POINT  0x00200000
#define FILE_FLAG_OPEN_NO_RECALL  0x00100000
#define FILE_FLAG_FIRST_PIPE_INSTANCE   0x00080000

#define CREATE_NEW  1
#define CREATE_ALWAYS  2
#define OPEN_EXISTING  3
#define OPEN_ALWAYS  4
#define TRUNCATE_EXISTING  5

#define PROGRESS_CONTINUE  0
#define PROGRESS_CANCEL  1
#define PROGRESS_STOP  2
#define PROGRESS_QUIET  3
#define CALLBACK_CHUNK_FINISHED  0x00000000
#define CALLBACK_STREAM_SWITCH  0x00000001
#define COPY_FILE_FAIL_IF_EXISTS  0x00000001
#define COPY_FILE_RESTARTABLE  0x00000002
#define COPY_FILE_OPEN_SOURCE_FOR_WRITE  0x00000004
#define REPLACEFILE_WRITE_THROUGH  0x00000001
#define REPLACEFILE_IGNORE_MERGE_ERRORS  0x00000002

#define PIPE_ACCESS_INBOUND  0x00000001
#define PIPE_ACCESS_OUTBOUND  0x00000002
#define PIPE_ACCESS_DUPLEX  0x00000003

#define PIPE_CLIENT_END  0x00000000
#define PIPE_SERVER_END  0x00000001

#define PIPE_WAIT  0x00000000
#define PIPE_NOWAIT  0x00000001
#define PIPE_READMODE_BYTE  0x00000000
#define PIPE_READMODE_MESSAGE  0x00000002
#define PIPE_TYPE_BYTE  0x00000000
#define PIPE_TYPE_MESSAGE  0x00000004
#define PIPE_ACCEPT_REMOTE_CLIENTS  0x00000000
#define PIPE_REJECT_REMOTE_CLIENTS  0x00000008

#define PIPE_UNLIMITED_INSTANCES  255

#IFNDEF SecurityAnonymous
    SecurityAnonymous = 0
    SecurityIdentification = 1
    SecurityImpersonation = 2
    SecurityDelegation = 3
#ENDIF

#define SECURITY_ANONYMOUS ( SecurityAnonymous<<16)
#define SECURITY_IDENTIFICATION ( SecurityIdentification<<16)
#define SECURITY_IMPERSONATION ( SecurityImpersonation<<16)
#define SECURITY_DELEGATION ( SecurityDelegation<<16)
#define SECURITY_CONTEXT_TRACKING  0x00040000
#define SECURITY_EFFECTIVE_ONLY  0x00080000
#define SECURITY_SQOS_PRESENT  0x00100000
#define SECURITY_VALID_SQOS_FLAGS  0x001F0000

#define MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#define MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS

#define SP_SERIALCOMM  0x00000001

#define PST_UNSPECIFIED  0x00000000
#define PST_RS232  0x00000001
#define PST_PARALLELPORT  0x00000002
#define PST_RS422  0x00000003
#define PST_RS423  0x00000004
#define PST_RS449  0x00000005
#define PST_MODEM  0x00000006
#define PST_FAX  0x00000021
#define PST_SCANNER  0x00000022
#define PST_NETWORK_BRIDGE  0x00000100
#define PST_LAT  0x00000101
#define PST_TCPIP_TELNET  0x00000102
#define PST_X25  0x00000103

#define PCF_DTRDSR  0x0001
#define PCF_RTSCTS  0x0002
#define PCF_RLSD  0x0004
#define PCF_PARITY_CHECK  0x0008
#define PCF_XONXOFF  0x0010
#define PCF_SETXCHAR  0x0020
#define PCF_TOTALTIMEOUTS  0x0040
#define PCF_INTTIMEOUTS  0x0080
#define PCF_SPECIALCHARS  0x0100
#define PCF_16BITMODE  0x0200

#define SP_PARITY  0x0001
#define SP_BAUD  0x0002
#define SP_DATABITS  0x0004
#define SP_STOPBITS  0x0008
#define SP_HANDSHAKING  0x0010
#define SP_PARITY_CHECK  0x0020
#define SP_RLSD  0x0040

#define BAUD_075  0x00000001
#define BAUD_110  0x00000002
#define BAUD_134_5  0x00000004
#define BAUD_150  0x00000008
#define BAUD_300  0x00000010
#define BAUD_600  0x00000020
#define BAUD_1200  0x00000040
#define BAUD_1800  0x00000080
#define BAUD_2400  0x00000100
#define BAUD_4800  0x00000200
#define BAUD_7200  0x00000400
#define BAUD_9600  0x00000800
#define BAUD_14400  0x00001000
#define BAUD_19200  0x00002000
#define BAUD_38400  0x00004000
#define BAUD_56K  0x00008000
#define BAUD_128K  0x00010000
#define BAUD_115200  0x00020000
#define BAUD_57600  0x00040000
#define BAUD_USER  0x10000000

#define DATABITS_5  0x0001
#define DATABITS_6  0x0002
#define DATABITS_7  0x0004
#define DATABITS_8  0x0008
#define DATABITS_16  0x0010
#define DATABITS_16X  0x0020

#define STOPBITS_10  0x0001
#define STOPBITS_15  0x0002
#define STOPBITS_20  0x0004
#define PARITY_NONE  0x0100
#define PARITY_ODD  0x0200
#define PARITY_EVEN  0x0400
#define PARITY_MARK  0x0800
#define PARITY_SPACE  0x1000

#define COMMPROP_INITIALIZED 0xE73CF52E

#define DTR_CONTROL_DISABLE  0x00
#define DTR_CONTROL_ENABLE  0x01
#define DTR_CONTROL_HANDSHAKE  0x02

#define RTS_CONTROL_DISABLE  0x00
#define RTS_CONTROL_ENABLE  0x01
#define RTS_CONTROL_HANDSHAKE  0x02
#define RTS_CONTROL_TOGGLE  0x03

#define GMEM_FIXED  0x0000
#define GMEM_MOVEABLE  0x0002
#define GMEM_NOCOMPACT  0x0010
#define GMEM_NODISCARD  0x0020
#define GMEM_ZEROINIT  0x0040
#define GMEM_MODIFY  0x0080
#define GMEM_DISCARDABLE  0x0100
#define GMEM_NOT_BANKED  0x1000
#define GMEM_SHARE  0x2000
#define GMEM_DDESHARE  0x2000
#define GMEM_NOTIFY  0x4000
#define GMEM_LOWER  GMEM_NOT_BANKED
#define GMEM_VALID_FLAGS  0x7F72
#define GMEM_INVALID_HANDLE  0x8000
#define GMEM_DISCARDED 0x4000
#define GMEM_LOCKCOUNT 0x00FF

#define GHND  GMEM_MOVEABLE|GMEM_ZEROINIT
#define GPTR  GMEM_FIXED|GMEM_ZEROINIT

#define LMEM_FIXED  0x0000
#define LMEM_MOVEABLE  0x0002
#define LMEM_NOCOMPACT  0x0010
#define LMEM_NODISCARD  0x0020
#define LMEM_ZEROINIT  0x0040
#define LMEM_MODIFY  0x0080
#define LMEM_DISCARDABLE  0x0F00
#define LMEM_VALID_FLAGS  0x0F72
#define LMEM_INVALID_HANDLE  0x8000
#define LMEM_DISCARDED  0x4000
#define LMEM_LOCKCOUNT  0x00FF

#define LHND  LMEM_MOVEABLE|LMEM_ZEROINIT
#define LPTR  LMEM_FIXED|LMEM_ZEROINIT

#define NONZEROLHND  LMEM_MOVEABLE
#define NONZEROLPTR  LMEM_FIXED

#define DEBUG_PROCESS  0x00000001
#define DEBUG_ONLY_THIS_PROCESS  0x00000002
#define CREATE_SUSPENDED  0x00000004
#define DETACHED_PROCESS  0x00000008
#define CREATE_NEW_CONSOLE  0x00000010
#define NORMAL_PRIORITY_CLASS  0x00000020
#define IDLE_PRIORITY_CLASS  0x00000040
#define HIGH_PRIORITY_CLASS  0x00000080
#define REALTIME_PRIORITY_CLASS  0x00000100
#define CREATE_NEW_PROCESS_GROUP  0x00000200
#define CREATE_UNICODE_ENVIRONMENT  0x00000400
#define CREATE_SEPARATE_WOW_VDM  0x00000800
#define CREATE_SHARED_WOW_VDM  0x00001000
#define CREATE_FORCEDOS  0x00002000
#define BELOW_NORMAL_PRIORITY_CLASS  0x00004000
#define ABOVE_NORMAL_PRIORITY_CLASS  0x00008000
#define CREATE_BREAKAWAY_FROM_JOB  0x01000000
#define CREATE_WITH_USERPROFILE  0x02000000
#define CREATE_DEFAULT_ERROR_MODE  0x04000000
#define CREATE_NO_WINDOW  0x08000000
#define PROFILE_USER  0x10000000
#define PROFILE_KERNEL  0x20000000
#define PROFILE_SERVER  0x40000000

#ifndef THREAD_BASE_PRIORITY_MIN
	#define THREAD_BASE_PRIORITY_MIN -2
	#define THREAD_BASE_PRIORITY_MAX 2
	#define THREAD_BASE_PRIORITY_LOWRT 15
	#define THREAD_BASE_PRIORITY_IDLE -15
#endif

#define THREAD_PRIORITY_LOWEST  THREAD_BASE_PRIORITY_MIN
#define THREAD_PRIORITY_BELOW_NORMAL  (THREAD_PRIORITY_LOWEST+1)
#define THREAD_PRIORITY_NORMAL  0
#define THREAD_PRIORITY_HIGHEST  THREAD_BASE_PRIORITY_MAX
#define THREAD_PRIORITY_ABOVE_NORMAL  (THREAD_PRIORITY_HIGHEST-1)
#define THREAD_PRIORITY_ERROR_RETURN  (MAXLONG)
#define THREAD_PRIORITY_TIME_CRITICAL  THREAD_BASE_PRIORITY_LOWRT
#define THREAD_PRIORITY_IDLE  THREAD_BASE_PRIORITY_IDLE

#define EXCEPTION_DEBUG_EVENT  1
#define CREATE_THREAD_DEBUG_EVENT  2
#define CREATE_PROCESS_DEBUG_EVENT  3
#define EXIT_THREAD_DEBUG_EVENT  4
#define EXIT_PROCESS_DEBUG_EVENT  5
#define LOAD_DLL_DEBUG_EVENT  6
#define UNLOAD_DLL_DEBUG_EVENT  7
#define OUTPUT_DEBUG_STRING_EVENT  8
#define RIP_EVENT  9

#define DRIVE_UNKNOWN  0
#define DRIVE_NO_ROOT_DIR  1
#define DRIVE_REMOVABLE  2
#define DRIVE_FIXED  3
#define DRIVE_REMOTE  4
#define DRIVE_CDROM  5
#define DRIVE_RAMDISK  6

#define FILE_TYPE_UNKNOWN  0x0000
#define FILE_TYPE_DISK  0x0001
#define FILE_TYPE_CHAR  0x0002
#define FILE_TYPE_PIPE  0x0003
#define FILE_TYPE_REMOTE  0x8000

#define STD_INPUT_HANDLE  -10
#define STD_OUTPUT_HANDLE  -11
#define STD_ERROR_HANDLE  -12

#define NOPARITY  0
#define ODDPARITY  1
#define EVENPARITY  2
#define MARKPARITY  3
#define SPACEPARITY  4

#define ONESTOPBIT  0
#define ONE5STOPBITS  1
#define TWOSTOPBITS  2

#define IGNORE  0
#define INFINITE  0xFFFFFFFF

#define CBR_110  110
#define CBR_300  300
#define CBR_600  600
#define CBR_1200  1200
#define CBR_2400  2400
#define CBR_4800  4800
#define CBR_9600  9600
#define CBR_14400  14400
#define CBR_19200  19200
#define CBR_38400  38400
#define CBR_56000  56000
#define CBR_57600  57600
#define CBR_115200  115200
#define CBR_128000  128000
#define CBR_256000  256000

#define CE_RXOVER  0x0001
#define CE_OVERRUN  0x0002
#define CE_RXPARITY  0x0004
#define CE_FRAME  0x0008
#define CE_BREAK  0x0010
#define CE_TXFULL  0x0100
#define CE_PTO  0x0200
#define CE_IOE  0x0400
#define CE_DNS  0x0800
#define CE_OOP  0x1000
#define CE_MODE  0x8000

#define IE_BADID  -1
#define IE_OPEN  -2
#define IE_NOPEN  -3
#define IE_MEMORY  -4
#define IE_DEFAULT  -5
#define IE_HARDWARE  -10
#define IE_BYTESIZE  -11
#define IE_BAUDRATE  -12

#define EV_RXCHAR  0x0001
#define EV_RXFLAG  0x0002
#define EV_TXEMPTY  0x0004
#define EV_CTS  0x0008
#define EV_DSR  0x0010
#define EV_RLSD  0x0020
#define EV_BREAK  0x0040
#define EV_ERR  0x0080
#define EV_RING  0x0100
#define EV_PERR  0x0200
#define EV_RX80FULL  0x0400
#define EV_EVENT1  0x0800
#define EV_EVENT2  0x1000

#define SETXOFF  1
#define SETXON  2
#define SETRTS  3
#define CLRRTS  4
#define SETDTR  5
#define CLRDTR  6
#define RESETDEV  7
#define SETBREAK  8
#define CLRBREAK  9

#define PURGE_TXABORT  0x0001
#define PURGE_RXABORT  0x0002
#define PURGE_TXCLEAR  0x0004
#define PURGE_RXCLEAR  0x0008

#define LPTx  0x80

#define MS_CTS_ON  0x0010
#define MS_DSR_ON  0x0020
#define MS_RING_ON  0x0040
#define MS_RLSD_ON  0x0080

#define S_QUEUEEMPTY  0
#define S_THRESHOLD  1
#define S_ALLTHRESHOLD  2

#define S_NORMAL  0
#define S_LEGATO  1
#define S_STACCATO  2

#define S_PERIOD512  0
#define S_PERIOD1024  1
#define S_PERIOD2048  2
#define S_PERIODVOICE  3
#define S_WHITE512  4
#define S_WHITE1024  5
#define S_WHITE2048  6
#define S_WHITEVOICE  7

#define S_SERDVNA  -1
#define S_SEROFM  -2
#define S_SERMACT  -3
#define S_SERQFUL  -4
#define S_SERBDNT  -5
#define S_SERDLN  -6
#define S_SERDCC  -7
#define S_SERDTP  -8
#define S_SERDVL  -9
#define S_SERDMD  -10
#define S_SERDSH  -11
#define S_SERDPT  -12
#define S_SERDFQ  -13
#define S_SERDDR  -14
#define S_SERDSR  -15
#define S_SERDST  -16

#define NMPWAIT_WAIT_FOREVER  0xFFFFFFFF
#define NMPWAIT_NOWAIT  0x00000001
#define NMPWAIT_USE_DEFAULT_WAIT  0x00000000

#define FS_CASE_IS_PRESERVED  2
#define FS_CASE_SENSITIVE  1
#define FS_UNICODE_STORED_ON_DISK  4
#define FS_PERSISTENT_ACLS  8
#define FS_VOL_IS_COMPRESSED  8000h
#define FS_FILE_COMPRESSION  10h
#define FS_FILE_ENCRYPTION  00020000h

#define FILE_MAP_COPY  1
#define FILE_MAP_WRITE  2
#define FILE_MAP_READ  4
#define FILE_MAP_ALL_ACCESS  10h

#define OF_READ  0x00000000
#define OF_WRITE  0x00000001
#define OF_READWRITE  0x00000002
#define OF_SHARE_COMPAT  0x00000000
#define OF_SHARE_EXCLUSIVE  0x00000010
#define OF_SHARE_DENY_WRITE  0x00000020
#define OF_SHARE_DENY_READ  0x00000030
#define OF_SHARE_DENY_NONE  0x00000040
#define OF_PARSE  0x00000100
#define OF_DELETE  0x00000200
#define OF_VERIFY  0x00000400
#define OF_CANCEL  0x00000800
#define OF_CREATE  0x00001000
#define OF_PROMPT  0x00002000
#define OF_EXIST  0x00004000
#define OF_REOPEN  0x00008000

#define MAXINTATOM  0xC000
#define INVALID_ATOM  0

#define PROCESS_HEAP_REGION  0x0001
#define PROCESS_HEAP_UNCOMMITTED_RANGE  0x0002
#define PROCESS_HEAP_ENTRY_BUSY  0x0004
#define PROCESS_HEAP_ENTRY_MOVEABLE  0x0010
#define PROCESS_HEAP_ENTRY_DDESHARE  0x0020

#define SCS_32BIT_BINARY  0
#define SCS_DOS_BINARY  1
#define SCS_WOW_BINARY  2
#define SCS_PIF_BINARY  3
#define SCS_POSIX_BINARY  4
#define SCS_OS216_BINARY  5
#define SCS_64BIT_BINARY    6

#IFDEF WIN64
	#define SCS_THIS_PLATFORM_BINARY SCS_64BIT_BINARY
#ELSE
	#define SCS_THIS_PLATFORM_BINARY SCS_32BIT_BINARY
#ENDIF

#define SEM_FAILCRITICALERRORS  0x0001
#define SEM_NOGPFAULTERRORBOX  0x0002
#define SEM_NOALIGNMENTFAULTEXCEPT  0x0004
#define SEM_NOOPENFILEERRORBOX  0x8000

#define LOCKFILE_FAIL_IMMEDIATELY  0x00000001
#define LOCKFILE_EXCLUSIVE_LOCK  0x00000002

#define HANDLE_FLAG_INHERIT  0x00000001
#define HANDLE_FLAG_PROTECT_FROM_CLOSE  0x00000002

#define HINSTANCE_ERROR  32

#define GET_TAPE_MEDIA_INFORMATION  0
#define GET_TAPE_DRIVE_INFORMATION  1

#define SET_TAPE_MEDIA_INFORMATION  0
#define SET_TAPE_DRIVE_INFORMATION  1

#define FORMAT_MESSAGE_ALLOCATE_BUFFER  0x00000100
#define FORMAT_MESSAGE_IGNORE_INSERTS  0x00000200
#define FORMAT_MESSAGE_FROM_STRING  0x00000400
#define FORMAT_MESSAGE_FROM_HMODULE  0x00000800
#define FORMAT_MESSAGE_FROM_SYSTEM  0x00001000
#define FORMAT_MESSAGE_ARGUMENT_ARRAY  0x00002000
#define FORMAT_MESSAGE_MAX_WIDTH_MASK  0x000000FF

#define FILE_ENCRYPTABLE  0
#define FILE_IS_ENCRYPTED  1
#define FILE_SYSTEM_ATTR  2
#define FILE_ROOT_DIR  3
#define FILE_SYSTEM_DIR  4
#define FILE_UNKNOWN  5
#define FILE_SYSTEM_NOT_SUPPORT  6
#define FILE_USER_DISALLOWED  7
#define FILE_READ_ONLY  8
#define FILE_DIR_DISALLOWED  9

#define EFS_USE_RECOVERY_KEYS  1

#define CREATE_FOR_IMPORT  1
#define CREATE_FOR_DIR  2

#define TLS_OUT_OF_INDEXES  0xFFFFFFFF

#define BACKUP_INVALID  0x00000000
#define BACKUP_DATA  0x00000001
#define BACKUP_EA_DATA  0x00000002
#define BACKUP_SECURITY_DATA  0x00000003
#define BACKUP_ALTERNATE_DATA  0x00000004
#define BACKUP_LINK  0x00000005
#define BACKUP_PROPERTY_DATA  0x00000006
#define BACKUP_OBJECT_ID  0x00000007
#define BACKUP_REPARSE_DATA  0x00000008
#define BACKUP_SPARSE_BLOCK  0x00000009

#define STREAM_NORMAL_ATTRIBUTE  0x00000000
#define STREAM_MODIFIED_WHEN_READ  0x00000001
#define STREAM_CONTAINS_SECURITY  0x00000002
#define STREAM_CONTAINS_PROPERTIES  0x00000004
#define STREAM_SPARSE_ATTRIBUTE  0x00000008

#define STARTF_USESHOWWINDOW  0x00000001
#define STARTF_USESIZE  0x00000002
#define STARTF_USEPOSITION  0x00000004
#define STARTF_USECOUNTCHARS  0x00000008
#define STARTF_USEFILLATTRIBUTE  0x00000010
#define STARTF_RUNFULLSCREEN  0x00000020
#define STARTF_FORCEONFEEDBACK  0x00000040
#define STARTF_FORCEOFFFEEDBACK  0x00000080
#define STARTF_USESTDHANDLES  0x00000100
#define STARTF_USEHOTKEY  0x00000200

#define SHUTDOWN_NORETRY  0x00000001

#define DONT_RESOLVE_DLL_REFERENCES  0x00000001
#define LOAD_LIBRARY_AS_DATAFILE  0x00000002
#define LOAD_WITH_ALTERED_SEARCH_PATH  0x00000008

#define DDD_RAW_TARGET_PATH  0x00000001
#define DDD_REMOVE_DEFINITION  0x00000002
#define DDD_EXACT_MATCH_ON_REMOVE  0x00000004
#define DDD_NO_BROADCAST_SYSTEM  0x00000008

#define FIND_FIRST_EX_CASE_SENSITIVE  0x00000001

#define MOVEFILE_REPLACE_EXISTING  0x00000001
#define MOVEFILE_COPY_ALLOWED  0x00000002
#define MOVEFILE_DELAY_UNTIL_REBOOT  0x00000004
#define MOVEFILE_WRITE_THROUGH  0x00000008
#define MOVEFILE_CREATE_HARDLINK  0x00000010
#define MOVEFILE_FAIL_IF_NOT_TRACKABLE  0x00000020

#define EVENTLOG_FULL_INFO  0

#define MAX_COMPUTERNAME_LENGTH  15

#define LOGON32_LOGON_INTERACTIVE  2
#define LOGON32_LOGON_NETWORK  3
#define LOGON32_LOGON_BATCH  4
#define LOGON32_LOGON_SERVICE  5
#define LOGON32_LOGON_UNLOCK  7
#define LOGON32_LOGON_NETWORK_CLEARTEXT  8
#define LOGON32_LOGON_NEW_CREDENTIALS  9

#define LOGON32_PROVIDER_DEFAULT  0
#define LOGON32_PROVIDER_WINNT35  1
#define LOGON32_PROVIDER_WINNT40  2
#define LOGON32_PROVIDER_WINNT50  3

#define LOGON_WITH_PROFILE  0x00000001
#define LOGON_NETCREDENTIALS_ONLY  0x00000002

#define MAX_MANGLED_SITE  27

#define HW_PROFILE_GUIDLEN  39
#define MAX_PROFILE_LEN  80

#define DOCKINFO_UNDOCKED  1
#define DOCKINFO_DOCKED  2
#define DOCKINFO_USER_SUPPLIED  4
#define DOCKINFO_USER_UNDOCKED  DOCKINFO_USER_SUPPLIED|DOCKINFO_UNDOCKED
#define DOCKINFO_USER_DOCKED  DOCKINFO_USER_SUPPLIED|DOCKINFO_DOCKED

#define TC_NORMAL  0
#define TC_HARDERR  1
#define TC_GP_TRAP  2
#define TC_SIGNAL  3

#define AC_LINE_OFFLINE  0x00
#define AC_LINE_ONLINE  0x01
#define AC_LINE_BACKUP_POWER  0x02
#define AC_LINE_UNKNOWN  0xFF

#define BATTERY_FLAG_HIGH  0x01
#define BATTERY_FLAG_LOW  0x02
#define BATTERY_FLAG_CRITICAL  0x04
#define BATTERY_FLAG_CHARGING  0x08
#define BATTERY_FLAG_NO_BATTERY  0x80
#define BATTERY_FLAG_UNKNOWN  0xFF
#define BATTERY_PERCENTAGE_UNKNOWN  0xFF
#define BATTERY_LIFE_UNKNOWN  0xFFFFFFFF

#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A  A"GetSystemWow64DirectoryA"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W  L"GetSystemWow64DirectoryA"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T  A"GetSystemWow64DirectoryA"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A  A"GetSystemWow64DirectoryW"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W  L"GetSystemWow64DirectoryW"
#define GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T  L"GetSystemWow64DirectoryW"

OVERLAPPED STRUCT
	Internal PTR
	InternalHigh PTR
	UNION
		STRUCT
				Offset DD
				OffsetHigh DD
		ENDS
		Pointer PTR
	ENDUNION
	hEvent HANDLE
ENDS

OVERLAPPED_ENTRY STRUCT
	lpCompletionKey PTR
	lpOverlapped PTR
	Internal PTR
	dwNumberOfBytesTransferred DD
ENDS

SECURITY_ATTRIBUTES STRUCT
	nLength DD
	lpSecurityDescriptor PTR
	bInheritHandle DD
ENDS

PROCESS_INFORMATION STRUCT
	hProcess HANDLE
	hThread HANDLE
	dwProcessId DD
	dwThreadId DD
ENDS

#IFNDEF FILETIME
	FILETIME STRUCT
		dwLowDateTime DD
		dwHighDateTime DD
	ENDS
#ENDIF

#IFNDEF SYSTEMTIME
	SYSTEMTIME STRUCT
		wYear DW
		wMonth DW
		wDayOfWeek DW
		wDay DW
		wHour DW
		wMinute DW
		wSecond DW
		wMilliseconds DW
	ENDS
#ENDIF

COMMPROP STRUCT
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
	wcProvChar DW
ENDS

COMSTAT STRUCT
	fCtsHold DD
	fDsrHold DD
	fRlsdHold DD
	fXoffHold DD
	fXoffSent DD
	fEof DD
	fTxim DD
	fReserved DD
	cbInQue DD
	cbOutQue DD
ENDS

DCB Struct
    DCBlength     DD
    BaudRate      DD
    fbits         DD    ;Members BaudRate to fDummy2 are included here
    wReserved     DD
    XonLim        DW
    XoffLim       DW
    ByteSize      DB
    Parity        DB
    StopBits      DB
    XonChar       DB
    XoffChar      DB
    ErrorChar     DB
    EofChar       DB
    EvtChar       DB
    wReserved1    DW
EndS

COMMTIMEOUTS STRUCT
	ReadIntervalTimeout DD
	ReadTotalTimeoutMultiplier DD
	ReadTotalTimeoutConstant DD
	WriteTotalTimeoutMultiplier DD
	WriteTotalTimeoutConstant DD
ENDS

COMMCONFIG STRUCT
	dwSize DD
	wVersion DW
	wReserved DW
	dcb DCB
	dwProviderSubType DD
	dwProviderOffset DD
	dwProviderSize DD
	wcProviderData DW
ENDS

SYSTEM_INFO STRUCT
	UNION
		dwOemId DD
		STRUCT
			wProcessorArchitecture DW
			wReserved DW
		ENDS
	ENDUNION
	dwPageSize DD
	lpMinimumApplicationAddress PTR
	lpMaximumApplicationAddress PTR
	dwActiveProcessorMask DWORD_PTR
	dwNumberOfProcessors DD
	dwProcessorType DD
	dwAllocationGranularity DD
	wProcessorLevel DW
	wProcessorRevision DW
ENDS

MEMORYSTATUS STRUCT
	dwLength DD
	dwMemoryLoad DD
	dwTotalPhys SIZE_T
	dwAvailPhys SIZE_T
	dwTotalPageFile SIZE_T
	dwAvailPageFile SIZE_T
	dwTotalVirtual SIZE_T
	dwAvailVirtual SIZE_T
ENDS

EXCEPTION_DEBUG_INFO STRUCT
	ExceptionRecord EXCEPTION_RECORD
	dwFirstChance DD
ENDS

CREATE_THREAD_DEBUG_INFO STRUCT
	hThread HANDLE
	lpThreadLocalBase PTR
	lpStartAddress PTR
ENDS

CREATE_PROCESS_DEBUG_INFO STRUCT
	hFile HANDLE
	hProcess HANDLE
	hThread HANDLE
	lpBaseOfImage PTR
	dwDebugInfoFileOffset DD
	nDebugInfoSize DD
	lpThreadLocalBase PTR
	lpStartAddress PTR
	lpImageName PTR
	fUnicode DW
ENDS

EXIT_THREAD_DEBUG_INFO STRUCT
	dwExitCode DD
ENDS

EXIT_PROCESS_DEBUG_INFO STRUCT
	dwExitCode DD
ENDS

LOAD_DLL_DEBUG_INFO STRUCT
	hFile HANDLE
	lpBaseOfDll PTR
	dwDebugInfoFileOffset DD
	nDebugInfoSize DD
	lpImageName PTR
	fUnicode DW
ENDS

UNLOAD_DLL_DEBUG_INFO STRUCT
	lpBaseOfDll PTR
ENDS

OUTPUT_DEBUG_STRING_INFO STRUCT
	lpDebugStringData PTR
	fUnicode DW
	nDebugStringLength DW
ENDS

RIP_INFO STRUCT
	dwError DD
	dwType DD
ENDS

DEBUG_EVENT STRUCT
	dwDebugEventCode DD
	dwProcessId DD
	dwThreadId DD
	u UNION
		Exception EXCEPTION_DEBUG_INFO
		CreateThread CREATE_THREAD_DEBUG_INFO
		CreateProcessInfo CREATE_PROCESS_DEBUG_INFO
		ExitThread EXIT_THREAD_DEBUG_INFO
		ExitProcess EXIT_PROCESS_DEBUG_INFO
		LoadDll LOAD_DLL_DEBUG_INFO
		UnloadDll UNLOAD_DLL_DEBUG_INFO
		DebugString OUTPUT_DEBUG_STRING_INFO
		RipInfo RIP_INFO
	ENDUNION
ENDS

#define OFS_MAXPATHNAME 128

OFSTRUCT STRUCT
	cBytes DB
	fFixedDisk DB
	nErrCode DW
	Reserved1 DW
	Reserved2 DW
	szPathName DB OFS_MAXPATHNAME DUP
ENDS

MEMORYSTATUSEX STRUCT
	dwLength DD
	dwMemoryLoad DD
	ullTotalPhys DQ
	ullAvailPhys DQ
	ullTotalPageFile DQ
	ullAvailPageFile DQ
	ullTotalVirtual DQ
	ullAvailVirtual DQ
	ullAvailExtendedVirtual DQ
ENDS

PROCESS_HEAP_ENTRY STRUCT
	lpData PTR
	cbData DD
	cbOverhead DB
	iRegionIndex DB
	wFlags DW
	UNION
		Block STRUCT
			hMem DD
			dwReserved DD 3 DUP
		ENDS
		Region STRUCT
			dwCommittedSize DD
			dwUnCommittedSize DD
			lpFirstBlock PTR
			lpLastBlock PTR
		ENDS
	ENDUNION
ENDS

BY_HANDLE_FILE_INFORMATION STRUCT
	dwFileAttributes DD
	ftCreationTime FILETIME
	ftLastAccessTime FILETIME
	ftLastWriteTime FILETIME
	dwVolumeSerialNumber DD
	nFileSizeHigh DD
	nFileSizeLow DD
	nNumberOfLinks DD
	nFileIndexHigh DD
	nFileIndexLow DD
ENDS

TIME_ZONE_INFORMATION STRUCT
	Bias DD
	StandardName DW 32 DUP
	StandardDate SYSTEMTIME
	StandardBias DD
	DaylightName DW 32 DUP
	DaylightDate SYSTEMTIME
	DaylightBias DD
ENDS

WIN32_STREAM_ID STRUCT
	dwStreamId DD
	dwStreamAttributes DD
	Size DQ
	dwStreamNameSize DD
	cStreamName DW
ENDS

STARTUPINFOA STRUCT
	cb DD
	lpReserved PTR
	lpDesktop PTR
	lpTitle PTR
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
	lpReserved2 PTR
	hStdInput HANDLE
	hStdOutput HANDLE
	hStdError HANDLE
ENDS

STARTUPINFOW STRUCT
	cb DD
	lpReserved PTR
	lpDesktop PTR
	lpTitle PTR
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
	lpReserved2 PTR
	hStdInput HANDLE
	hStdOutput HANDLE
	hStdError HANDLE
ENDS

WIN32_FIND_DATA STRUCT
	dwFileAttributes DD
	ftCreationTime FILETIME
	ftLastAccessTime FILETIME
	ftLastWriteTime FILETIME
	nFileSizeHigh DD
	nFileSizeLow DD
	dwReserved0 DD
	dwReserved1 DD
	cFileName TCHAR MAX_PATH DUP
	cAlternateFileName TCHAR 14 DUP
ENDS

WIN32_FILE_ATTRIBUTE_DATA STRUCT
	dwFileAttributes DD
	ftCreationTime FILETIME
	ftLastAccessTime FILETIME
	ftLastWriteTime FILETIME
	nFileSizeHigh DD
	nFileSizeLow DD
ENDS

GetFileExInfoStandard = 0
GetFileExMaxInfoLevel = 1

FindExInfoStandard = 0
FindExInfoMaxInfoLevel = 1

FindExSearchNameMatch = 0
FindExSearchLimitToDirectories = 1
FindExSearchLimitToDevices = 2
FindExSearchMaxSearchOp = 3

EVENTLOG_FULL_INFORMATION STRUCT
	dwFull DD
ENDS


ComputerNameNetBIOS = 0
ComputerNameDnsHostname = 1
ComputerNameDnsDomain = 2
ComputerNameDnsFullyQualified = 3
ComputerNamePhysicalNetBIOS = 4
ComputerNamePhysicalDnsHostname = 5
ComputerNamePhysicalDnsDomain = 6
ComputerNamePhysicalDnsFullyQualified = 7
ComputerNameMax = 8

HW_PROFILE_INFO STRUCT
	dwDockInfo DD
	szHwProfileGuid	TCHAR HW_PROFILE_GUIDLEN DUP
	szHwProfileName TCHAR MAX_PROFILE_LEN DUP
ENDS

SYSTEM_POWER_STATUS struct
	ACLineStatus DB
	BatteryFlag DB
	BatteryLifePercent DB
	Reserved1 DB
	BatteryLifeTime DD
	BatteryFullLifeTime DD
ENDS

LowMemoryResourceNotification = 0
HighMemoryResourceNotification = 1

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

#IFDEF UNICODE
	#DEFINE STARTUPINFO STARTUPINFOW
	#define GetSystemWow64Directory  GetSystemWow64DirectoryW
	#define GetBinaryType GetBinaryTypeW
	#define GetShortPathName GetShortPathNameW
	#define GetLongPathName GetLongPathNameW
	#define GetEnvironmentStrings GetEnvironmentStringsW
	#define FreeEnvironmentStrings FreeEnvironmentStringsW
	#define FormatMessage FormatMessageW
	#define CreateMailslot CreateMailslotW
	#define EncryptFile EncryptFileW
	#define DecryptFile DecryptFileW
	#define FileEncryptionStatus FileEncryptionStatusW
	#define OpenEncryptedFileRaw OpenEncryptedFileRawW
	#define lstrcmp lstrcmpW
	#define lstrcmpi lstrcmpiW
	#define lstrcpyn lstrcpynW
	#define lstrcpy lstrcpyW
	#define lstrcat lstrcatW
	#define lstrlen lstrlenW
	#define CreateMutex CreateMutexW
	#define OpenMutex OpenMutexW
	#define CreateEvent CreateEventW
	#define OpenEvent OpenEventW
	#define CreateSemaphore CreateSemaphoreW
	#define OpenSemaphore OpenSemaphoreW
	#define CreateWaitableTimer CreateWaitableTimerW
	#define OpenWaitableTimer OpenWaitableTimerW
	#define CreateFileMapping CreateFileMappingW
	#define OpenFileMapping OpenFileMappingW
	#define GetLogicalDriveStrings GetLogicalDriveStringsW
	#define LoadLibrary LoadLibraryW
	#define LoadLibraryEx LoadLibraryExW
	#define GetModuleFileName GetModuleFileNameW
	#define GetModuleHandle GetModuleHandleW
	#define CreateProcess CreateProcessW
	#define FatalAppExit FatalAppExitW
	#define GetStartupInfo GetStartupInfoW
	#define GetCommandLine GetCommandLineW
	#define GetEnvironmentVariable GetEnvironmentVariableW
	#define SetEnvironmentVariable SetEnvironmentVariableW
	#define ExpandEnvironmentStrings ExpandEnvironmentStringsW
	#define OutputDebugString OutputDebugStringW
	#define FindResource FindResourceW
	#define FindResourceEx FindResourceExW
	#define EnumResourceTypes EnumResourceTypesW
	#define EnumResourceNames EnumResourceNamesW
	#define EnumResourceLanguages EnumResourceLanguagesW
	#define BeginUpdateResource BeginUpdateResourceW
	#define UpdateResource UpdateResourceW
	#define EndUpdateResource EndUpdateResourceW
	#define GlobalAddAtom GlobalAddAtomW
	#define GlobalFindAtom GlobalFindAtomW
	#define GlobalGetAtomName GlobalGetAtomNameW
	#define AddAtom AddAtomW
	#define FindAtom FindAtomW
	#define GetAtomName GetAtomNameW
	#define GetProfileInt GetProfileIntW
	#define GetProfileString GetProfileStringW
	#define WriteProfileString WriteProfileStringW
	#define GetProfileSection GetProfileSectionW
	#define WriteProfileSection WriteProfileSectionW
	#define GetPrivateProfileInt GetPrivateProfileIntW
	#define GetPrivateProfileString GetPrivateProfileStringW
	#define WritePrivateProfileString WritePrivateProfileStringW
	#define GetPrivateProfileSection GetPrivateProfileSectionW
	#define WritePrivateProfileSection WritePrivateProfileSectionW
	#define GetPrivateProfileSectionNames GetPrivateProfileSectionNamesW
	#define GetPrivateProfileStruct GetPrivateProfileStructW
	#define WritePrivateProfileStruct WritePrivateProfileStructW
	#define GetDriveType GetDriveTypeW
	#define GetSystemDirectory GetSystemDirectoryW
	#define GetTempPath GetTempPathW
	#define GetTempFileName GetTempFileNameW
	#define GetWindowsDirectory GetWindowsDirectoryW
	#define GetSystemWindowsDirectory GetSystemWindowsDirectoryW
	#define SetCurrentDirectory SetCurrentDirectoryW
	#define GetCurrentDirectory GetCurrentDirectoryW
	#define GetDiskFreeSpace GetDiskFreeSpaceW
	#define GetDiskFreeSpaceEx GetDiskFreeSpaceExW
	#define CreateDirectory CreateDirectoryW
	#define CreateDirectoryEx CreateDirectoryExW
	#define RemoveDirectory RemoveDirectoryW
	#define GetFullPathName GetFullPathNameW
	#define DefineDosDevice DefineDosDeviceW
	#define QueryDosDevice QueryDosDeviceW
	#define CreateFile CreateFileW
	#define SetFileAttributes SetFileAttributesW
	#define GetFileAttributes GetFileAttributesW
	#define GetFileAttributesEx GetFileAttributesExW
	#define GetCompressedFileSize GetCompressedFileSizeW
	#define DeleteFile DeleteFileW
	#define FindFirstFileEx FindFirstFileExW
	#define FindFirstFile FindFirstFileW
	#define FindNextFile FindNextFileW
	#define SearchPath SearchPathW
	#define CopyFile CopyFileW
	#define CopyFileEx CopyFileExW
	#define MoveFile MoveFileW
	#define MoveFileEx MoveFileExW
	#define MoveFileWithProgress MoveFileWithProgressW
	#define ReplaceFile ReplaceFileW
	#define CreateHardLink CreateHardLinkW
	#define CreateNamedPipe CreateNamedPipeW
	#define GetNamedPipeHandleState GetNamedPipeHandleStateW
	#define CallNamedPipe CallNamedPipeW
	#define WaitNamedPipe WaitNamedPipeW
	#define SetVolumeLabel SetVolumeLabelW
	#define GetVolumeInformation GetVolumeInformationW
	#define ClearEventLog ClearEventLogW
	#define BackupEventLog BackupEventLogW
	#define OpenEventLog OpenEventLogW
	#define RegisterEventSource RegisterEventSourceW
	#define OpenBackupEventLog OpenBackupEventLogW
	#define ReadEventLog ReadEventLogW
	#define ReportEvent ReportEventW
	#define AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
	#define AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
	#define AccessCheckByTypeResultListAndAuditAlarm AccessCheckByTypeResultListAndAuditAlarmW
	#define AccessCheckByTypeResultListAndAuditAlarmByHandle AccessCheckByTypeResultListAndAuditAlarmByHandleW
	#define ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
	#define ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
	#define ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
	#define ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
	#define PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
	#define SetFileSecurity SetFileSecurityW
	#define GetFileSecurity GetFileSecurityW
	#define FindFirstChangeNotification FindFirstChangeNotificationW
	#define IsBadStringPtr IsBadStringPtrW
	#define LookupAccountSid LookupAccountSidW
	#define LookupAccountName LookupAccountNameW
	#define LookupPrivilegeValue LookupPrivilegeValueW
	#define LookupPrivilegeName LookupPrivilegeNameW
	#define LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
	#define BuildCommDCB BuildCommDCBW
	#define BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
	#define CommConfigDialog CommConfigDialogW
	#define GetDefaultCommConfig GetDefaultCommConfigW
	#define SetDefaultCommConfig SetDefaultCommConfigW
	#define GetComputerName GetComputerNameW
	#define SetComputerName SetComputerNameW
	#define GetComputerNameEx GetComputerNameExW
	#define SetComputerNameEx SetComputerNameExW
	#define DnsHostnameToComputerName DnsHostnameToComputerNameW
	#define GetUserName GetUserNameW
	#define LogonUser LogonUserW
	#define CreateProcessAsUser CreateProcessAsUserW
	#define GetSiteDirectory GetSiteDirectoryW
	#define GetCurrentHwProfile GetCurrentHwProfileW
	#define GetVersionEx GetVersionExW
	#define VerifyVersionInfo VerifyVersionInfoW
	#define CreateJobObject CreateJobObjectW
	#define OpenJobObject OpenJobObjectW
	#define FindFirstVolume FindFirstVolumeW
	#define FindNextVolume FindNextVolumeW
	#define FindFirstVolumeMountPoint FindFirstVolumeMountPointW
	#define FindNextVolumeMountPoint FindNextVolumeMountPointW
	#define SetVolumeMountPoint SetVolumeMountPointW
	#define DeleteVolumeMountPoint DeleteVolumeMountPointW
	#define GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointW
	#define GetVolumePathName GetVolumePathNameW
#ELSE
	#DEFINE STARTUPINFO STARTUPINFOA
	#define GetSystemWow64Directory GetSystemWow64DirectoryA
	#define GetBinaryType GetBinaryTypeA
	#define GetShortPathName GetShortPathNameA
	#define GetLongPathName GetLongPathNameA
	#define GetEnvironmentStringsA GetEnvironmentStrings
	#define FreeEnvironmentStrings FreeEnvironmentStringsA
	#define FormatMessage FormatMessageA
	#define CreateMailslot CreateMailslotA
	#define EncryptFile EncryptFileA
	#define DecryptFile DecryptFileA
	#define FileEncryptionStatus FileEncryptionStatusA
	#define OpenEncryptedFileRaw OpenEncryptedFileRawA
	#define lstrcmp lstrcmpA
	#define lstrcmpi lstrcmpiA
	#define lstrcpyn lstrcpynA
	#define lstrcpy lstrcpyA
	#define lstrcat lstrcatA
	#define lstrlen lstrlenA
	#define CreateMutex CreateMutexA
	#define OpenMutex OpenMutexA
	#define CreateEvent CreateEventA
	#define OpenEvent OpenEventA
	#define CreateSemaphore CreateSemaphoreA
	#define OpenSemaphore OpenSemaphoreA
	#define CreateWaitableTimer CreateWaitableTimerA
	#define OpenWaitableTimer OpenWaitableTimerA
	#define CreateFileMapping CreateFileMappingA
	#define OpenFileMapping OpenFileMappingA
	#define GetLogicalDriveStrings GetLogicalDriveStringsA
	#define LoadLibrary LoadLibraryA
	#define LoadLibraryEx LoadLibraryExA
	#define GetModuleFileName GetModuleFileNameA
	#define GetModuleHandle GetModuleHandleA
	#define CreateProcess CreateProcessA
	#define FatalAppExit FatalAppExitA
	#define GetStartupInfo GetStartupInfoA
	#define GetCommandLine GetCommandLineA
	#define GetEnvironmentVariable GetEnvironmentVariableA
	#define SetEnvironmentVariable SetEnvironmentVariableA
	#define ExpandEnvironmentStrings ExpandEnvironmentStringsA
	#define OutputDebugString OutputDebugStringA
	#define FindResource FindResourceA
	#define FindResourceEx FindResourceExA
	#define EnumResourceTypes EnumResourceTypesA
	#define EnumResourceNames EnumResourceNamesA
	#define EnumResourceLanguages EnumResourceLanguagesA
	#define BeginUpdateResource BeginUpdateResourceA
	#define UpdateResource UpdateResourceA
	#define EndUpdateResource EndUpdateResourceA
	#define GlobalAddAtom GlobalAddAtomA
	#define GlobalFindAtom GlobalFindAtomA
	#define GlobalGetAtomName GlobalGetAtomNameA
	#define AddAtom AddAtomA
	#define FindAtom FindAtomA
	#define GetAtomName GetAtomNameA
	#define GetProfileInt GetProfileIntA
	#define GetProfileString GetProfileStringA
	#define WriteProfileString WriteProfileStringA
	#define GetProfileSection GetProfileSectionA
	#define WriteProfileSection WriteProfileSectionA
	#define GetPrivateProfileInt GetPrivateProfileIntA
	#define GetPrivateProfileString GetPrivateProfileStringA
	#define WritePrivateProfileString WritePrivateProfileStringA
	#define GetPrivateProfileSection GetPrivateProfileSectionA
	#define WritePrivateProfileSection WritePrivateProfileSectionA
	#define GetPrivateProfileSectionNames GetPrivateProfileSectionNamesA
	#define GetPrivateProfileStruct GetPrivateProfileStructA
	#define WritePrivateProfileStruct WritePrivateProfileStructA
	#define GetDriveType GetDriveTypeA
	#define GetSystemDirectory GetSystemDirectoryA
	#define GetTempPath GetTempPathA
	#define GetTempFileName GetTempFileNameA
	#define GetWindowsDirectory GetWindowsDirectoryA
	#define GetSystemWindowsDirectory GetSystemWindowsDirectoryA
	#define SetCurrentDirectory SetCurrentDirectoryA
	#define GetCurrentDirectory GetCurrentDirectoryA
	#define GetDiskFreeSpace GetDiskFreeSpaceA
	#define GetDiskFreeSpaceEx GetDiskFreeSpaceExA
	#define CreateDirectory CreateDirectoryA
	#define CreateDirectoryEx CreateDirectoryExA
	#define RemoveDirectory RemoveDirectoryA
	#define GetFullPathName GetFullPathNameA
	#define DefineDosDevice DefineDosDeviceA
	#define QueryDosDevice QueryDosDeviceA
	#define CreateFile CreateFileA
	#define SetFileAttributes SetFileAttributesA
	#define GetFileAttributes GetFileAttributesA
	#define GetFileAttributesEx GetFileAttributesExA
	#define GetCompressedFileSize GetCompressedFileSizeA
	#define DeleteFile DeleteFileA
	#define FindFirstFileEx FindFirstFileExA
	#define FindFirstFile FindFirstFileA
	#define FindNextFile FindNextFileA
	#define SearchPath SearchPathA
	#define CopyFile CopyFileA
	#define CopyFileEx CopyFileExA
	#define MoveFile MoveFileA
	#define MoveFileEx MoveFileExA
	#define MoveFileWithProgress MoveFileWithProgressA
	#define ReplaceFile ReplaceFileA
	#define CreateHardLink CreateHardLinkA
	#define CreateNamedPipe CreateNamedPipeA
	#define GetNamedPipeHandleState GetNamedPipeHandleStateA
	#define CallNamedPipe CallNamedPipeA
	#define WaitNamedPipe WaitNamedPipeA
	#define SetVolumeLabel SetVolumeLabelA
	#define GetVolumeInformation GetVolumeInformationA
	#define ClearEventLog ClearEventLogA
	#define BackupEventLog BackupEventLogA
	#define OpenEventLog OpenEventLogA
	#define RegisterEventSource RegisterEventSourceA
	#define OpenBackupEventLog OpenBackupEventLogA
	#define ReadEventLog ReadEventLogA
	#define ReportEvent ReportEventA
	#define AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
	#define AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
	#define AccessCheckByTypeResultListAndAuditAlarm AccessCheckByTypeResultListAndAuditAlarmA
	#define AccessCheckByTypeResultListAndAuditAlarmByHandle AccessCheckByTypeResultListAndAuditAlarmByHandleA
	#define ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
	#define ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
	#define ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
	#define ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
	#define PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
	#define SetFileSecurity SetFileSecurityA
	#define GetFileSecurity GetFileSecurityA
	#define FindFirstChangeNotification FindFirstChangeNotificationA
	#define IsBadStringPtr IsBadStringPtrA
	#define LookupAccountSid LookupAccountSidA
	#define LookupAccountName LookupAccountNameA
	#define LookupPrivilegeValue LookupPrivilegeValueA
	#define LookupPrivilegeName LookupPrivilegeNameA
	#define LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
	#define BuildCommDCB BuildCommDCBA
	#define BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
	#define CommConfigDialog CommConfigDialogA
	#define GetDefaultCommConfig GetDefaultCommConfigA
	#define SetDefaultCommConfig SetDefaultCommConfigA
	#define GetComputerName GetComputerNameA
	#define SetComputerName SetComputerNameA
	#define GetComputerNameEx GetComputerNameExA
	#define SetComputerNameEx SetComputerNameExA
	#define DnsHostnameToComputerName DnsHostnameToComputerNameA
	#define GetUserName GetUserNameA
	#define LogonUser LogonUserA
	#define CreateProcessAsUser CreateProcessAsUserA
	#define GetSiteDirectory GetSiteDirectoryA
	#define GetCurrentHwProfile GetCurrentHwProfileA
	#define GetVersionEx GetVersionExA
	#define VerifyVersionInfo VerifyVersionInfoA
	#define CreateJobObject CreateJobObjectA
	#define OpenJobObject OpenJobObjectA
	#define FindFirstVolume FindFirstVolumeA
	#define FindNextVolume FindNextVolumeA
	#define FindFirstVolumeMountPoint FindFirstVolumeMountPointA
	#define FindNextVolumeMountPoint FindNextVolumeMountPointA
	#define SetVolumeMountPoint SetVolumeMountPointA
	#define DeleteVolumeMountPoint DeleteVolumeMountPointA
	#define GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointA
	#define GetVolumePathName GetVolumePathNameA
#ENDIF

#ENDIF /* WINBASE_H */

