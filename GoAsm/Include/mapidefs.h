#ifndef MAPIDEFS_H
#define MAPIDEFS_H

/* MAPI client and service provider definitions */

#IFNDEF WINDOWS_H
	#include windows.h
#ENDIF

#IFNDEF OLE2_H
	#include ole2.h
#ENDIF

#ifndef MAPI_DIM
	#define MAPI_DIM  1
#endif

#define MAPI_NT_SERVICE  0x00010000

#define MAPI_MODIFY  0x00000001
#define MAPI_ACCESS_MODIFY  0x00000001
#define MAPI_ACCESS_READ  0x00000002
#define MAPI_ACCESS_DELETE  0x00000004
#define MAPI_ACCESS_CREATE_HIERARCHY 0x00000008
#define MAPI_ACCESS_CREATE_CONTENTS 0x00000010
#define MAPI_ACCESS_CREATE_ASSOCIATED 0x00000020
#define MAPI_UNICODE 0x80000000

#IFDEF UNICODE
	#define fMapiUnicode  MAPI_UNICODE
#else
	#define fMapiUnicode  0
#endif

#define hrSuccess  0
#define MAPI_ORIG  0
#define MAPI_TO  1
#define MAPI_CC  2
#define MAPI_BCC  3
#define MAPI_P1  0x10000000
#define MAPI_SUBMITTED  0x80000000

#define MAPI_SHORTTERM  0x80
#define MAPI_NOTRECIP  0x40
#define MAPI_THISSESSION  0x20
#define MAPI_NOW  0x10
#define MAPI_NOTRESERVED  0x08
#define MAPI_COMPOUND  0x80

#define GUID_MAPI_ONE_OFF_UID  <0x812b1fa4,0xbea3,0x1019,<0x9d,0x6e,0x00,0xdd,0x01,0x0f,0x54,0x02>>

#define MAPI_ONE_OFF_UNICODE  0x8000
#define MAPI_ONE_OFF_NO_RICH_INFO  0x0001

#define MAPI_STORE  0x00000001
#define MAPI_ADDRBOOK  0x00000002
#define MAPI_FOLDER  0x00000003
#define MAPI_ABCONT  0x00000004
#define MAPI_MESSAGE  0x00000005
#define MAPI_MAILUSER  0x00000006
#define MAPI_ATTACH  0x00000007
#define MAPI_DISTLIST  0x00000008
#define MAPI_PROFSECT  0x00000009
#define MAPI_STATUS  0x0000000A
#define MAPI_SESSION  0x0000000B
#define MAPI_FORMINFO  0x0000000C

#ifndef cchProfileNameMax
	#define cchProfileNameMax  64
	#define cchProfilePassMax  64
#endif

#define MV_FLAG  0x1000
#define PT_UNSPECIFIED  0
#define PT_NULL  1
#define PT_I2  2
#define PT_LONG  3
#define PT_R4  4
#define PT_DOUBLE  5
#define PT_CURRENCY  6
#define PT_APPTIME  7
#define PT_ERROR  10
#define PT_BOOLEAN  11
#define PT_OBJECT  13
#define PT_I8  20
#define PT_STRING8  30
#define PT_UNICODE  31
#define PT_SYSTIME  64
#define PT_CLSID  72
#define PT_BINARY  258

#define PT_SHORT  PT_I2
#define PT_I4  PT_LONG
#define PT_FLOAT  PT_R4
#define PT_R8  PT_DOUBLE
#define PT_LONGLONG PT_I8

#IFDEF UNICODE
	#define PT_TSTRING  PT_UNICODE
	#define PT_MV_TSTRING  (MV_FLAG|PT_UNICODE)
#else
	#define PT_TSTRING  PT_STRING8
	#define PT_MV_TSTRING  (MV_FLAG|PT_STRING8)
#endif

#define PROP_TYPE_MASK  0x0000FFFF
#define PROP_ID_NULL  0
#define PROP_ID_INVALID  0xFFFF
#define PR_NULL  0

#define PT_MV_I2  (MV_FLAG|PT_I2)
#define PT_MV_LONG  (MV_FLAG|PT_LONG)
#define PT_MV_R4  (MV_FLAG|PT_R4)
#define PT_MV_DOUBLE  (MV_FLAG|PT_DOUBLE)
#define PT_MV_CURRENCY  (MV_FLAG|PT_CURRENCY)
#define PT_MV_APPTIME  (MV_FLAG|PT_APPTIME)
#define PT_MV_SYSTIME  (MV_FLAG|PT_SYSTIME)
#define PT_MV_STRING8  (MV_FLAG|PT_STRING8)
#define PT_MV_BINARY  (MV_FLAG|PT_BINARY)
#define PT_MV_UNICODE  (MV_FLAG|PT_UNICODE)
#define PT_MV_CLSID  (MV_FLAG|PT_CLSID)
#define PT_MV_I8  (MV_FLAG|PT_I8)
#define PT_MV_SHORT  PT_MV_I2
#define PT_MV_I4  PT_MV_LONG
#define PT_MV_FLOAT  PT_MV_R4
#define PT_MV_R8  PT_MV_DOUBLE
#define PT_MV_LONGLONG  PT_MV_I8

#define MV_INSTANCE  0x2000
#define MVI_FLAG  (MV_FLAG|MV_INSTANCE)

#define fnevCriticalError  0x00000001
#define fnevNewMail  0x00000002
#define fnevObjectCreated  0x00000004
#define fnevObjectDeleted  0x00000008
#define fnevObjectModified  0x00000010
#define fnevObjectMoved  0x00000020
#define fnevObjectCopied  0x00000040
#define fnevSearchComplete  0x00000080
#define fnevTableModified  0x00000100
#define fnevStatusObjectModified  0x00000200
#define fnevReservedForMapi  0x40000000
#define fnevExtended  0x80000000

#define TABLE_CHANGED  1
#define TABLE_ERROR  2
#define TABLE_ROW_ADDED  3
#define TABLE_ROW_DELETED  4
#define TABLE_ROW_MODIFIED  5
#define TABLE_SORT_DONE  6
#define TABLE_RESTRICT_DONE 7
#define TABLE_SETCOL_DONE  8
#define TABLE_RELOAD  9

#define szMAPINotificationMsg  "MAPI Notify window message"

#define MAPI_TOP_LEVEL  0x00000001

#define MAPI_ERROR_VERSION  0x00000000
#define KEEP_OPEN_READONLY  0x00000001
#define KEEP_OPEN_READWRITE 0x00000002
#define FORCE_SAVE  0x00000004
#define MAPI_CREATE  0x00000002
#define STREAM_APPEND  0x00000004
#define MAPI_MOVE  0x00000001
#define MAPI_NOREPLACE  0x00000002
#define MAPI_DECLINE_OK 0x00000004

#ifndef MAPI_DIALOG
#define MAPI_DIALOG 0x00000008
#endif

#ifndef MAPI_USE_DEFAULT
#define MAPI_USE_DEFAULT  0x00000040
#endif

#define MAPI_NO_STRINGS 0x00000001
#define MAPI_NO_IDS  0x00000002
#define MNID_ID  0
#define MNID_STRING 1

#define TBLSTAT_COMPLETE  0
#define TBLSTAT_QCHANGED  7
#define TBLSTAT_SORTING  9
#define TBLSTAT_SORT_ERROR  10
#define TBLSTAT_SETTING_COLS  11
#define TBLSTAT_SETCOL_ERROR  13
#define TBLSTAT_RESTRICTING  14
#define TBLSTAT_RESTRICT_ERROR  15

#define TBLTYPE_SNAPSHOT  0
#define TBLTYPE_KEYSET  1
#define TBLTYPE_DYNAMIC  2

#define TABLE_SORT_ASCEND  0x00000000
#define TABLE_SORT_DESCEND  0x00000001
#define TABLE_SORT_COMBINE  0x00000002

#define BOOKMARK_BEGINNING 0
#define BOOKMARK_CURRENT 1
#define BOOKMARK_END  2

#define FL_FULLSTRING  0x00000000
#define FL_SUBSTRING  0x00000001
#define FL_PREFIX  0x00000002
#define FL_IGNORECASE  0x00010000
#define FL_IGNORENONSPACE  0x00020000
#define FL_LOOSE  0x00040000

#define RES_AND  0x00000000
#define RES_OR  0x00000001
#define RES_NOT  0x00000002
#define RES_CONTENT  0x00000003
#define RES_PROPERTY  0x00000004
#define RES_COMPAREPROPS  0x00000005
#define RES_BITMASK  0x00000006
#define RES_SIZE  0x00000007
#define RES_EXIST  0x00000008
#define RES_SUBRESTRICTION  0x00000009
#define RES_COMMENT  0x0000000A

#define RELOP_LT  0
#define RELOP_LE  1
#define RELOP_GT  2
#define RELOP_GE  3
#define RELOP_EQ  4
#define RELOP_NE  5
#define RELOP_RE  6

#define BMR_EQZ  0
#define BMR_NEZ  1

#define TBL_ALL_COLUMNS 0x00000001
#define TBL_LEAF_ROW  1
#define TBL_EMPTY_CATEGORY  2
#define TBL_EXPANDED_CATEGORY  3
#define TBL_COLLAPSED_CATEGORY  4
#define TBL_NOWAIT  0x00000001
#define TBL_ASYNC  0x00000001
#define TBL_BATCH  0x00000002

#define DIR_BACKWARD  0x00000001

#define TBL_NOADVANCE  0x00000001

#define MAPI_STORE_PROVIDER  33
#define MAPI_AB  34
#define MAPI_AB_PROVIDER  35
#define MAPI_TRANSPORT_PROVIDER  36
#define MAPI_SPOOLER  37
#define MAPI_PROFILE_PROVIDER  38
#define MAPI_SUBSYSTEM  39
#define MAPI_HOOK_PROVIDER  40

#define STATUS_VALIDATE_STATE  0x00000001
#define STATUS_SETTINGS_DIALOG  0x00000002
#define STATUS_CHANGE_PASSWORD  0x00000004
#define STATUS_FLUSH_QUEUES  0x00000008
#define STATUS_DEFAULT_OUTBOUND  0x00000001
#define STATUS_DEFAULT_STORE  0x00000002
#define STATUS_PRIMARY_IDENTITY  0x00000004
#define STATUS_SIMPLE_STORE  0x00000008
#define STATUS_XP_PREFER_LAST  0x00000010
#define STATUS_NO_PRIMARY_IDENTITY  0x00000020
#define STATUS_NO_DEFAULT_STORE  0x00000040
#define STATUS_TEMP_SECTION  0x00000080
#define STATUS_OWN_STORE  0x00000100
#define STATUS_NEED_IPM_TREE  0x00000800
#define STATUS_PRIMARY_STORE  0x00001000
#define STATUS_SECONDARY_STORE  0x00002000
#define STATUS_AVAILABLE  0x00000001
#define STATUS_OFFLINE  0x00000002
#define STATUS_FAILURE  0x00000004
#define STATUS_INBOUND_ENABLED  0x00010000
#define STATUS_INBOUND_ACTIVE  0x00020000
#define STATUS_INBOUND_FLUSH  0x00040000
#define STATUS_OUTBOUND_ENABLED 0x00100000
#define STATUS_OUTBOUND_ACTIVE  0x00200000
#define STATUS_OUTBOUND_FLUSH  0x00400000
#define STATUS_REMOTE_ACCESS  0x00800000

#define SUPPRESS_UI  0x00000001
#define REFRESH_XP_HEADER_CACHE  0x00010000
#define PROCESS_XP_HEADER_CACHE  0x00020000
#define FORCE_XP_CONNECT  0x00040000
#define FORCE_XP_DISCONNECT  0x00080000
#define CONFIG_CHANGED  0x00100000
#define ABORT_XP_HEADER_OPERATION  0x00200000
#define SHOW_XP_SESSION_UI  0x00400000

#define UI_READONLY 0x00000001

#define FLUSH_UPLOAD  0x00000002
#define FLUSH_DOWNLOAD  0x00000004
#define FLUSH_FORCE  0x00000008
#define FLUSH_NO_UI  0x00000010
#define FLUSH_ASYNC_OK  0x00000020

#define MAPI_BEST_ACCESS  0x00000010
#define CONVENIENT_DEPTH  0x00000001
#define SEARCH_RUNNING  0x00000001
#define SEARCH_REBUILD  0x00000002
#define SEARCH_RECURSIVE  0x00000004
#define SEARCH_FOREGROUND  0x00000008
#define STOP_SEARCH  0x00000001
#define RESTART_SEARCH  0x00000002
#define RECURSIVE_SEARCH  0x00000004
#define SHALLOW_SEARCH  0x00000008
#define FOREGROUND_SEARCH  0x00000010
#define BACKGROUND_SEARCH  0x00000020

#define AB_RECIPIENTS  0x00000001
#define AB_SUBCONTAINERS  0x00000002
#define AB_MODIFIABLE  0x00000004
#define AB_UNMODIFIABLE  0x00000008
#define AB_FIND_ON_OPEN  0x00000010
#define AB_NOT_DEFAULT  0x00000020

#define CREATE_CHECK_DUP_STRICT 0x00000001
#define CREATE_CHECK_DUP_LOOSE  0x00000002
#define CREATE_REPLACE  0x00000004

#define MAPI_UNRESOLVED 0x00000000
#define MAPI_AMBIGUOUS  0x00000001
#define MAPI_RESOLVED  0x00000002

#define MAPI_SEND_NO_RICH_INFO  0x00010000

#define MAPI_DIAG_NO_DIAGNOSTIC  -1
#define MAPI_DIAG_OR_NAME_UNRECOGNIZED  0
#define MAPI_DIAG_OR_NAME_AMBIGUOUS  1
#define MAPI_DIAG_MTS_CONGESTED  2
#define MAPI_DIAG_LOOP_DETECTED  3
#define MAPI_DIAG_RECIPIENT_UNAVAILABLE  4
#define MAPI_DIAG_MAXIMUM_TIME_EXPIRED  5
#define MAPI_DIAG_EITS_UNSUPPORTED  6
#define MAPI_DIAG_CONTENT_TOO_LONG  7
#define MAPI_DIAG_IMPRACTICAL_TO_CONVERT  8
#define MAPI_DIAG_PROHIBITED_TO_CONVERT  9
#define MAPI_DIAG_CONVERSION_UNSUBSCRIBED  10
#define MAPI_DIAG_PARAMETERS_INVALID  11
#define MAPI_DIAG_CONTENT_SYNTAX_IN_ERROR  12
#define MAPI_DIAG_LENGTH_CONSTRAINT_VIOLATD 13
#define MAPI_DIAG_NUMBER_CONSTRAINT_VIOLATD 14
#define MAPI_DIAG_CONTENT_TYPE_UNSUPPORTED  15
#define MAPI_DIAG_TOO_MANY_RECIPIENTS  16
#define MAPI_DIAG_NO_BILATERAL_AGREEMENT  17
#define MAPI_DIAG_CRITICAL_FUNC_UNSUPPORTED 18
#define MAPI_DIAG_CONVERSION_LOSS_PROHIB  19
#define MAPI_DIAG_LINE_TOO_LONG  20
#define MAPI_DIAG_PAGE_TOO_LONG  21
#define MAPI_DIAG_PICTORIAL_SYMBOL_LOST  22
#define MAPI_DIAG_PUNCTUATION_SYMBOL_LOST  23
#define MAPI_DIAG_ALPHABETIC_CHARACTER_LOST 24
#define MAPI_DIAG_MULTIPLE_INFO_LOSSES  25
#define MAPI_DIAG_REASSIGNMENT_PROHIBITED  26
#define MAPI_DIAG_REDIRECTION_LOOP_DETECTED 27
#define MAPI_DIAG_EXPANSION_PROHIBITED  28
#define MAPI_DIAG_SUBMISSION_PROHIBITED  29
#define MAPI_DIAG_EXPANSION_FAILED  30
#define MAPI_DIAG_RENDITION_UNSUPPORTED  31
#define MAPI_DIAG_MAIL_ADDRESS_INCORRECT  32
#define MAPI_DIAG_MAIL_OFFICE_INCOR_OR_INVD 33
#define MAPI_DIAG_MAIL_ADDRESS_INCOMPLETE  34
#define MAPI_DIAG_MAIL_RECIPIENT_UNKNOWN  35
#define MAPI_DIAG_MAIL_RECIPIENT_DECEASED  36
#define MAPI_DIAG_MAIL_ORGANIZATION_EXPIRED 37
#define MAPI_DIAG_MAIL_REFUSED  38
#define MAPI_DIAG_MAIL_UNCLAIMED  39
#define MAPI_DIAG_MAIL_RECIPIENT_MOVED  40
#define MAPI_DIAG_MAIL_RECIPIENT_TRAVELLING 41
#define MAPI_DIAG_MAIL_RECIPIENT_DEPARTED  42
#define MAPI_DIAG_MAIL_NEW_ADDRESS_UNKNOWN  43
#define MAPI_DIAG_MAIL_FORWARDING_UNWANTED  44
#define MAPI_DIAG_MAIL_FORWARDING_PROHIB  45
#define MAPI_DIAG_SECURE_MESSAGING_ERROR  46
#define MAPI_DIAG_DOWNGRADING_IMPOSSIBLE  47

#define MAPI_MH_DP_PUBLIC_UA  0
#define MAPI_MH_DP_PRIVATE_UA  1
#define MAPI_MH_DP_MS  2
#define MAPI_MH_DP_ML  3
#define MAPI_MH_DP_PDAU  4
#define MAPI_MH_DP_PDS_PATRON  5
#define MAPI_MH_DP_OTHER_AU  6

#define FOLDER_ROOT  0x00000000
#define FOLDER_GENERIC  0x00000001
#define FOLDER_SEARCH  0x00000002

#define MESSAGE_MOVE  0x00000001
#define MESSAGE_DIALOG  0x00000002

#define OPEN_IF_EXISTS  0x00000001

#define DEL_MESSAGES  0x00000001
#define FOLDER_DIALOG  0x00000002
#define DEL_FOLDERS  0x00000004

#define DEL_ASSOCIATED  0x00000008

#define FOLDER_MOVE 0x00000001
#define COPY_SUBFOLDERS 0x00000010

#define MSGSTATUS_HIGHLIGHTED  0x00000001
#define MSGSTATUS_TAGGED  0x00000002
#define MSGSTATUS_HIDDEN  0x00000004
#define MSGSTATUS_DELMARKED  0x00000008
#define MSGSTATUS_REMOTE_DOWNLOAD  0x00001000
#define MSGSTATUS_REMOTE_DELETE  0x00002000

#define RECURSIVE_SORT  0x00000002

#define FLDSTATUS_HIGHLIGHTED  0x00000001
#define FLDSTATUS_TAGGED  0x00000002
#define FLDSTATUS_HIDDEN  0x00000004
#define FLDSTATUS_DELMARKED  0x00000008

#define STORE_ENTRYID_UNIQUE  0x00000001
#define STORE_READONLY  0x00000002
#define STORE_SEARCH_OK  0x00000004
#define STORE_MODIFY_OK  0x00000008
#define STORE_CREATE_OK  0x00000010
#define STORE_ATTACH_OK  0x00000020
#define STORE_OLE_OK  0x00000040
#define STORE_SUBMIT_OK  0x00000080
#define STORE_NOTIFY_OK  0x00000100
#define STORE_MV_PROPS_OK  0x00000200
#define STORE_CATEGORIZE_OK  0x00000400
#define STORE_RTF_OK  0x00000800
#define STORE_RESTRICTION_OK  0x00001000
#define STORE_SORT_OK  0x00002000
#define STORE_PUBLIC_FOLDERS  0x00004000
#define STORE_UNCOMPRESSED_RTF  0x00008000
#define STORE_HAS_SEARCHES  0x01000000

#define LOGOFF_NO_WAIT  0x00000001
#define LOGOFF_ORDERLY  0x00000002
#define LOGOFF_PURGE  0x00000004
#define LOGOFF_ABORT  0x00000008
#define LOGOFF_QUIET  0x00000010
#define LOGOFF_COMPLETE  0x00010000
#define LOGOFF_INBOUND  0x00020000
#define LOGOFF_OUTBOUND  0x00040000
#define LOGOFF_OUTBOUND_QUEUE  0x00080000

#define MSG_LOCKED  0x00000001
#define MSG_UNLOCKED  0x00000000

#define FOLDER_IPM_SUBTREE_VALID  0x00000001
#define FOLDER_IPM_INBOX_VALID  0x00000002
#define FOLDER_IPM_OUTBOX_VALID  0x00000004
#define FOLDER_IPM_WASTEBASKET_VALID  0x00000008
#define FOLDER_IPM_SENTMAIL_VALID  0x00000010
#define FOLDER_VIEWS_VALID  0x00000020
#define FOLDER_COMMON_VIEWS_VALID  0x00000040
#define FOLDER_FINDER_VALID  0x00000080

#define FORCE_SUBMIT  0x00000001
#define MSGFLAG_READ  0x00000001
#define MSGFLAG_UNMODIFIED  0x00000002
#define MSGFLAG_SUBMIT  0x00000004
#define MSGFLAG_UNSENT  0x00000008
#define MSGFLAG_HASATTACH  0x00000010
#define MSGFLAG_FROMME  0x00000020
#define MSGFLAG_ASSOCIATED  0x00000040
#define MSGFLAG_RESEND  0x00000080
#define MSGFLAG_RN_PENDING  0x00000100
#define MSGFLAG_NRN_PENDING 0x00000200

#define SUBMITFLAG_LOCKED  0x00000001
#define SUBMITFLAG_PREPROCESS  0x00000002

#define MODRECIP_ADD  0x00000002
#define MODRECIP_MODIFY 0x00000004
#define MODRECIP_REMOVE 0x00000008

#define SUPPRESS_RECEIPT  0x00000001
#define CLEAR_READ_FLAG  0x00000004
#define GENERATE_RECEIPT_ONLY  0x00000010
#define CLEAR_RN_PENDING  0x00000020
#define CLEAR_NRN_PENDING  0x00000040

#define ATTACH_DIALOG  0x00000001

#define SECURITY_SIGNED  0x00000001
#define SECURITY_ENCRYPTED  0x00000002

#define PRIO_URGENT 1
#define PRIO_NORMAL 0
#define PRIO_NONURGENT -1

#define SENSITIVITY_NONE  0x00000000
#define SENSITIVITY_PERSONAL  0x00000001
#define SENSITIVITY_PRIVATE  0x00000002
#define SENSITIVITY_COMPANY_CONFIDENTIAL  0x00000003

#define IMPORTANCE_LOW  0
#define IMPORTANCE_NORMAL 1
#define IMPORTANCE_HIGH 2

#define NO_ATTACHMENT  0x00000000
#define ATTACH_BY_VALUE  0x00000001
#define ATTACH_BY_REFERENCE  0x00000002
#define ATTACH_BY_REF_RESOLVE  0x00000003
#define ATTACH_BY_REF_ONLY  0x00000004
#define ATTACH_EMBEDDED_MSG  0x00000005
#define ATTACH_OLE  0x00000006

#define ADRPARM_HELP_CTX  0x00000000
#define DIALOG_MODAL  0x00000001
#define DIALOG_SDI  0x00000002
#define DIALOG_OPTIONS  0x00000004
#define ADDRESS_ONE  0x00000008
#define AB_SELECTONLY  0x00000010
#define AB_RESOLVE  0x00000020

#define DT_MAILUSER  0x00000000
#define DT_DISTLIST  0x00000001
#define DT_FORUM  0x00000002
#define DT_AGENT  0x00000003
#define DT_ORGANIZATION  0x00000004
#define DT_PRIVATE_DISTLIST 0x00000005
#define DT_REMOTE_MAILUSER  0x00000006
#define DT_MODIFIABLE  0x00010000
#define DT_GLOBAL  0x00020000
#define DT_LOCAL  0x00030000
#define DT_WAN  0x00040000
#define DT_NOT_SPECIFIC 0x00050000
#define DT_FOLDER  0x01000000
#define DT_FOLDER_LINK  0x02000000
#define DT_FOLDER_SPECIAL  0x04000000

#define MAPI_DEFERRED_ERRORS  0x00000008
#define MAPI_ASSOCIATED 0x00000040
#define MDB_NO_DIALOG  0x00000001
#define MDB_WRITE  0x00000004
#define MDB_TEMPORARY  0x00000020
#define MDB_NO_MAIL  0x00000080
#define AB_NO_DIALOG  0x00000001

#define MAPI_ENABLED  0x00000000
#define MAPI_DISABLED  0x00000001

#define DT_MULTILINE  0x00000001
#define DT_EDITABLE  0x00000002
#define DT_REQUIRED  0x00000004
#define DT_SET_IMMEDIATE  0x00000008
#define DT_PASSWORD_EDIT  0x00000010
#define DT_ACCEPT_DBCS  0x00000020
#define DT_SET_SELECTION  0x00000040

#define DTCT_LABEL  0x00000000
#define DTCT_EDIT  0x00000001
#define DTCT_LBX  0x00000002
#define DTCT_COMBOBOX  0x00000003
#define DTCT_DDLBX  0x00000004
#define DTCT_CHECKBOX  0x00000005
#define DTCT_GROUPBOX  0x00000006
#define DTCT_BUTTON  0x00000007
#define DTCT_PAGE  0x00000008
#define DTCT_RADIOBUTTON  0x00000009
#define DTCT_MVLISTBOX  0x0000000B
#define DTCT_MVDDLBX  0x0000000C

#define MAPI_NO_HBAR  0x00000001
#define MAPI_NO_VBAR  0x00000002

#define UI_SERVICE  0x00000002
#define SERVICE_UI_ALWAYS  0x00000002
#define SERVICE_UI_ALLOWED  0x00000010
#define UI_CURRENT_PROVIDER_FIRST  0x00000004

ENTRYID STRUCT
	abFlags DB 4 DUP (?)
	ab DB
ENDS

MAPIUID STRUCT
	ab DB 16 DUP (?)
ENDS

SPropTagArray STRUCT
	cValues DD
	aulPropTag DD
ENDS

SBinary STRUCT
	cb DD
	lpb PTR
ENDS

SShortArray STRUCT
	cValues DD
	lpi PTR
ENDS

SGuidArray STRUCT
	cValues DD
	lpguid PTR
ENDS

SRealArray STRUCT
	cValues DD
	lpflt PTR
ENDS

SLongArray STRUCT
	cValues DD
	lpl PTR
ENDS

SLargeIntegerArray STRUCT
	cValues DD
	lpli PTR
ENDS

SDateTimeArray STRUCT
	cValues DD
	lpft DD
ENDS

SAppTimeArray STRUCT
	cValues DD
	lpat PTR
ENDS

SCurrencyArray STRUCT
	cValues DD
	lpcur PTR
ENDS

SBinaryArray STRUCT
	cValues DD
	lpbin PTR
ENDS

SDoubleArray STRUCT
	cValues DD
	lpdbl PTR
ENDS

SWStringArray STRUCT
	cValues DD
	lppszW PTR
ENDS

SLPSTRArray STRUCT
	cValues DD
	lppszA PTR
ENDS

SPropProblem STRUCT
	ulIndex DD
	ulPropTag DD
	scode DD
ENDS

SPropProblemArray STRUCT
	cProblem DD
	aProblem SPropProblem <>
ENDS

FLATENTRY STRUCT
	cb DD
	abEntry DB
ENDS

FLATENTRYLIST STRUCT
	cEntries DD
	cbEntries DD
	abEntries DB
ENDS

MTSID STRUCT
	cb DD
	ab DB
ENDS

FLATMTSIDLIST STRUCT
	cMTSIDs DD
	cbMTSIDs DD
	abMTSIDs DB
ENDS

ADRENTRY STRUCT
	ulReserved1 DD
	cValues DD
	rgPropVals PTR
ENDS

ADRLIST STRUCT
	cEntries DD
	aEntries ADRENTRY <>
ENDS

SRow STRUCT
	ulAdrEntryPad DD
	cValues DD
	lpProps PTR
ENDS

SRowSet STRUCT
	cRows DD 
	aRow SRow <>
ENDS

MAPIERROR STRUCT
	ulVersion DD
	lpszError PTR
	lpszComponent PTR
	ulLowLevelError DD
	ulContext DD
ENDS

ERROR_NOTIFICATION STRUCT
	cbEntryID DD
	lpEntryID PTR
	scode DD
	ulFlags DD
	lpMAPIError PTR
ENDS

NEWMAIL_NOTIFICATION STRUCT
	cbEntryID DD
	lpEntryID PTR
	cbParentID DD
	lpParentID PTR
	ulFlags DD
	lpszMessageClass PTR
	ulMessageFlags DD
ENDS

OBJECT_NOTIFICATION STRUCT
	cbEntryID DD
	lpEntryID PTR
	ulObjType DD
	cbParentID DD
	lpParentID PTR
	cbOldID DD
	lpOldID PTR
	cbOldParentID DD
	lpOldParentID PTR
	lpPropTagArray PTR
ENDS

TABLE_NOTIFICATION STRUCT
	ulTableEvent DD
	hResult HANDLE
	propIndex SPropValue
	propPrior SPropValue
	row SRow
	ulPad DD
ENDS

EXTENDED_NOTIFICATION STRUCT
	ulEvent DD
	cb DD
	pbEventParameters PTR
ENDS

STATUS_OBJECT_NOTIFICATION
	cbEntryID DD
	lpEntryID PTR
	cValues DD
	lpPropVals PTR
ENDS

NOTIFICATION STRUCT
	ulEventType DD
	ulAlignPad DD
	UNION
		err ERROR_NOTIFICATION <>
		newmail NEWMAIL_NOTIFICATION <>
		obj OBJECT_NOTIFICATION <>
		tab TABLE_NOTIFICATION <>
		ext EXTENDED_NOTIFICATION <>
		statobj STATUS_OBJECT_NOTIFICATION <>
	ENDUNION
ENDS

IMAPIAdviseSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnNotify PTR
ENDS

IMAPIProgress STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Progress PTR
	GetFlags PTR
	GetMax PTR
	GetMin PTR
	SetLimits PTR
ENDS

MAPINAMEID STRUCT
	lpguid PTR
	ulKind DD
	UNION
		lID DD
		lpwstrName PTR
	ENDUNION
ENDS

IMAPIProp STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	SaveChanges PTR
	GetProps PTR
	GetPropList PTR
	OpenProperty PTR
	SetProps PTR
	DeleteProps PTR
	CopyTo PTR
	CopyProps PTR
	GetNamesFromIDs PTR
	GetIDsFromNames PTR
ENDS

SSortOrder STRUCT
	ulPropTag DD
	ulOrder DD
ENDS

SSortOrderSet STRUCT
	cSorts DD
	cCategories DD
	cExpanded DD
	aSort SSortOrder <>
ENDS

SAndRestriction STRUCT
	cRes DD
	lpRes PTR
ENDS

SOrRestriction STRUCT
	cRes DD
	lpRes PTR
ENDS

SNotRestriction STRUCT
	ulReserved DD
	lpRes PTR
ENDS

SContentRestriction STRUCT
	ulFuzzyLevel DD
	ulPropTag DD
	lpProp PTR
ENDS

SBitMaskRestriction STRUCT
	relBMR DD
	ulPropTag DD
	ulMask DD
ENDS

SPropertyRestriction STRUCT
	relop DD
	ulPropTag DD
	lpProp PTR
ENDS

SComparePropsRestriction STRUCT
	relop DD
	ulPropTag1 DD
	ulPropTag2 DD
ENDS

SSizeRestriction STRUCT
	relop DD
	ulPropTag DD
	cb DD
ENDS

SExistRestriction STRUCT
	ulReserved1 DD
	ulPropTag DD
	ulReserved2 DD
ENDS

SSubRestriction STRUCT
	ulSubObject DD
	lpRes PTR
ENDS

SCommentRestriction STRUCT
	cValues DD
	lpRes DD
	lpProp PTR
ENDS

SRestriction STRUCT
	rt DD
	UNION
		resCompareProps SComparePropsRestriction <>
		resAnd SAndRestriction <>
		resOr SOrRestriction <>
		resNot SNotRestriction <>
		resContent SContentRestriction <>
		resProperty SPropertyRestriction <>
		resBitMask SBitMaskRestriction <>
		resSize SSizeRestriction <>
		resExist SExistRestriction <>
		resSub SSubRestriction <>
		resComment SCommentRestriction <>
	ENDUNION
ENDS

IMAPITable STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	Advise PTR
	Unadvise PTR
	GetStatus PTR
	SetColumns PTR
	QueryColumns PTR
	GetRowCount PTR
	SeekRow PTR
	SeekRowApprox PTR
	QueryPosition PTR
	FindRow PTR
	Restrict PTR
	CreateBookmark PTR
	FreeBookmark PTR
	SortTable PTR
	QuerySortOrder PTR
	QueryRows PTR
	Abort PTR
	ExpandRow PTR
	CollapseRow PTR
	WaitForCompletion PTR
	GetCollapseState PTR
	SetCollapseState PTR
ENDS

#define PS_PROFILE_PROPERTIES_INIT <0x9815AC08,0xAAB0,0x101A,0x8C,0x93,0x08,0x00,0x2B,0x2A,0x56,0xC2>

IProfSect STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	SaveChanges PTR
	GetProps PTR
	GetPropList PTR
	OpenProperty PTR
	SetProps PTR
	DeleteProps PTR
	CopyTo PTR
	CopyProps PTR
	GetNamesFromIDs PTR
	GetIDsFromNames PTR
	PR_OBJECT_TYPE PTR
	PR_PROFILE_NAME PTR
ENDS

IMAPIStatus STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	SaveChanges PTR
	GetProps PTR
	GetPropList PTR
	OpenProperty PTR
	SetProps PTR
	DeleteProps PTR
	CopyTo PTR
	CopyProps PTR
	GetNamesFromIDs PTR
	GetIDsFromNames PTR

	ValidateState PTR
	SettingsDialog PTR
	ChangePassword PTR
	FlushQueues PTR
ENDS

IMAPIContainer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	SaveChanges PTR
	GetProps PTR
	GetPropList PTR
	OpenProperty PTR
	SetProps PTR
	DeleteProps PTR
	CopyTo PTR
	CopyProps PTR
	GetNamesFromIDs PTR
	GetIDsFromNames PTR

	GetContentsTable PTR
	GetHierarchyTable PTR
	OpenEntry PTR
	SetSearchCriteria PTR
	GetSearchCriteria PTR
ENDS

flaglist STRUCT
	cFlags DD
	ulFlag DD
ENDS

IABContainer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	SaveChanges PTR
	GetProps PTR
	GetPropList PTR
	OpenProperty PTR
	SetProps PTR
	DeleteProps PTR
	CopyTo PTR
	CopyProps PTR
	GetNamesFromIDs PTR
	GetIDsFromNames PTR

	GetContentsTable PTR
	GetHierarchyTable PTR
	OpenEntry PTR
	SetSearchCriteria PTR
	GetSearchCriteria PTR

	CreateEntry PTR
	CopyEntries PTR
	DeleteEntries PTR
	ResolveNames PTR
ENDS

IMailUser STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	SaveChanges PTR
	GetProps PTR
	GetPropList PTR
	OpenProperty PTR
	SetProps PTR
	DeleteProps PTR
	CopyTo PTR
	CopyProps PTR
	GetNamesFromIDs PTR
	GetIDsFromNames PTR

	PR_ADDRTYPE PTR
	PR_DISPLAY_NAME PTR
	PR_DISPLAY_TYPE PTR
	PR_EMAIL_ADDRESS PTR
	PR_ENTRYID PTR
	PR_OBJECT_TYPE PTR
	PR_RECORD_KEY PTR
	PR_SEARCH_KEY PTR
ENDS

IDistList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	SaveChanges PTR
	GetProps PTR
	GetPropList PTR
	OpenProperty PTR
	SetProps PTR
	DeleteProps PTR
	CopyTo PTR
	CopyProps PTR
	GetNamesFromIDs PTR
	GetIDsFromNames PTR

	GetContentsTable PTR
	GetHierarchyTable PTR
	OpenEntry PTR
	SetSearchCriteria PTR
	GetSearchCriteria PTR

	CreateEntry PTR
	CopyEntries PTR
	DeleteEntries PTR
	ResolveNames PTR
ENDS

IMAPIFolder STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	SaveChanges PTR
	GetProps PTR
	GetPropList PTR
	OpenProperty PTR
	SetProps PTR
	DeleteProps PTR
	CopyTo PTR
	CopyProps PTR
	GetNamesFromIDs PTR
	GetIDsFromNames PTR

	GetContentsTable PTR
	GetHierarchyTable PTR
	OpenEntry PTR
	SetSearchCriteria PTR
	GetSearchCriteria PTR

	CreateMessage PTR
	CopyMessages PTR
	DeleteMessages PTR
	CreateFolder PTR
	CopyFolder PTR
	DeleteFolder PTR
	SetReadFlags PTR
	GetMessageStatus PTR
	SetMessageStatus PTR
	SaveContentsSort PTR
	EmptyFolder PTR
ENDS

IMsgStore STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	SaveChanges PTR
	GetProps PTR
	GetPropList PTR
	OpenProperty PTR
	SetProps PTR
	DeleteProps PTR
	CopyTo PTR
	CopyProps PTR
	GetNamesFromIDs PTR
	GetIDsFromNames PTR

	Advise PTR
	Unadvise PTR
	CompareEntryIDs PTR
	OpenEntry PTR
	SetReceiveFolder PTR
	GetReceiveFolder PTR
	GetReceiveFolderTable PTR
	StoreLogoff PTR
	AbortSubmit PTR
	GetOutgoingQueue PTR
	SetLockState PTR
	FinishedMsg PTR
	NotifyNewMail PTR
ENDS

IMessage STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	SaveChanges PTR
	GetProps PTR
	GetPropList PTR
	OpenProperty PTR
	SetProps PTR
	DeleteProps PTR
	CopyTo PTR
	CopyProps PTR
	GetNamesFromIDs PTR
	GetIDsFromNames PTR

	GetAttachmentTable PTR
	OpenAttach PTR
	CreateAttach PTR
	DeleteAttach PTR
	GetRecipientTable PTR
	ModifyRecipients PTR
	SubmitMessage PTR
	SetReadFlag PTR
ENDS

IAttach STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	SaveChanges PTR
	GetProps PTR
	GetPropList PTR
	OpenProperty PTR
	SetProps PTR
	DeleteProps PTR
	CopyTo PTR
	CopyProps PTR
	GetNamesFromIDs PTR
	GetIDsFromNames PTR
	PR_OBJECT_TYPE PTR
	PR_ATTACH_METHOD PTR
	PR_RENDERING_POSITION PTR
ENDS

ADRPARM STRUCT
	cbABContEntryID DD
	lpABContEntryID PTR
	ulFlags DD
	lpReserved PTR
	ulHelpContext DD
	lpszHelpFileName PTR
	lpfnABSDI PTR
	lpfnDismiss PTR
	lpvDismissContext PTR
	lpszCaption PTR
	lpszNewEntryTitle PTR
	lpszDestWellsTitle PTR
	cDestFields DD
	nDestFieldFocus DD
	lppszDestTitles PTR
	lpulDestComps PTR
	lpContRestriction PTR
	lpHierRestriction PTR
ENDS

IMAPIControl STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	Activate PTR
	GetState PTR
ENDS

DTBLLABEL STRUCT
	ulbLpszLabelName DD
	ulFlags DD
ENDS

DTBLEDIT STRUCT
	ulbLpszCharsAllowed DD
	ulFlags DD
	ulNumCharsAllowed DD
	ulPropTag DD
ENDS

DTBLLBX STRUCT
	ulFlags DD
	ulPRSetProperty DD
	ulPRTableName DD
ENDS

DTBLCOMBOBOX STRUCT
	ulbLpszCharsAllowed DD
	ulFlags DD
	ulNumCharsAllowed DD
	ulPRPropertyName DD
	ulPRTableName DD
ENDS

DTBLDDLBX STRUCT
	ulFlags DD
	ulPRDisplayProperty DD
	ulPRSetProperty DD
	ulPRTableName DD
ENDS

DTBLCHECKBOX STRUCT
	ulbLpszLabel DD
	ulFlags DD
	ulPRPropertyName DD
ENDS

DTBLGROUPBOX STRUCT
	ulbLpszLabel DD
	ulFlags DD
ENDS

DTBLBUTTON STRUCT
	ulbLpszLabel DD
	ulFlags DD
	ulPRControl DD
ENDS

DTBLPAGE STRUCT
	ulbLpszLabel DD
	ulFlags DD
	ulbLpszComponent DD
	ulContext DD
ENDS

DTBLRADIOBUTTON STRUCT
	ulbLpszLabel DD
	ulFlags DD
	ulcButtons DD
	ulPropTag DD
	lReturnValue PTR
ENDS

DTBLMVLISTBOX STRUCT
	ulFlags DD
	ulMVPropTag DD
ENDS

DTBLMVDDLBX STRUCT
	ulFlags DD
	ulMVPropTag DD
ENDS

IProviderAdmin STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetLastError PTR
	GetProviderTable PTR
	CreateProvider PTR
	DeleteProvider PTR
	OpenProfileSection PTR
ENDS

#endif /* _MAPIDEFS_H */
