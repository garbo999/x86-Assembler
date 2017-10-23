;=============================================================;
;         mapidefs.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF MAPIDEFS_INC
#Define MAPIDEFS_INC

#IFNDEF WINDOWS_INC
	#Include windows.inc
#ENDIF

#IFNDEF OLE2_INC
	#Include ole2.inc
#ENDIF

#IFNDEF MAPI_DIM
	#Define MAPI_DIM                        1
#ENDIF

#Define MAPI_NT_SERVICE                     (000010000H)

#IF STRINGS UNICODE
	#Define TCHAR DW
#ELSE
	#Define TCHAR DB
#ENDIF

#IFNDEF FILETIME
	FILETIME Struct
	    dwLowDateTime DD
	    dwHighDateTime DD
	EndS
#ENDIF

#Define MAPI_MODIFY                         (000000001H)
#Define MAPI_ACCESS_MODIFY                  (000000001H)
#Define MAPI_ACCESS_READ                    (000000002H)
#Define MAPI_ACCESS_DELETE                  (000000004H)
#Define MAPI_ACCESS_CREATE_HIERARCHY        (000000008H)
#Define MAPI_ACCESS_CREATE_CONTENTS         (000000010H)
#Define MAPI_ACCESS_CREATE_ASSOCIATED       (000000020H)

#Define MAPI_UNICODE                        (080000000H)

#IF STRINGS UNICODE
	#Define fMapiUnicode                    MAPI_UNICODE
#ELSE
	#Define fMapiUnicode                    0
#ENDIF

#Define hrSuccess                           0

#IFNDEF MAPI_ORIG
	#Define MAPI_ORIG                       0
	#Define MAPI_TO                         1
	#Define MAPI_CC                         2
	#Define MAPI_BCC                        3
	#Define MAPI_P1                         010000000H
	#Define MAPI_SUBMITTED                  080000000H
#ENDIF

#Define MAPI_SHORTTERM                      080H
#Define MAPI_NOTRECIP                       040H
#Define MAPI_THISSESSION                    020H
#Define MAPI_NOW                            010H
#Define MAPI_NOTRESERVED                    008H

#Define MAPI_COMPOUND                       080H

ENTRYID Struct
	abFlags DB 4 Dup ?
	ab DB MAPI_DIM Dup ?
EndS

MAPIUID Struct
	ab DB 16 Dup ?
EndS

#Define MAPI_ONE_OFF_UID               <0812B1FA4H, 0BEA3H, 01019H, 09DH, 06EH, 000H, 0DDH, 001H, 00FH, 054H, 002H>
#Define MAPI_ONE_OFF_UNICODE           08000H
#Define MAPI_ONE_OFF_NO_RICH_INFO      00001H

#Define MAPI_STORE                     000000001H
#Define MAPI_ADDRBOOK                  000000002H
#Define MAPI_FOLDER                    000000003H
#Define MAPI_ABCONT                    000000004H
#Define MAPI_MESSAGE                   000000005H
#Define MAPI_MAILUSER                  000000006H
#Define MAPI_ATTACH                    000000007H
#Define MAPI_DISTLIST                  000000008H
#Define MAPI_PROFSECT                  000000009H
#Define MAPI_STATUS                    00000000AH
#Define MAPI_SESSION                   00000000BH
#Define MAPI_FORMINFO                  00000000CH

#IFNDEF cchProfileNameMax
	#Define cchProfileNameMax               64
	#Define cchProfilePassMax               64
#ENDIF


#Define MV_FLAG                             01000H

#Define PT_UNSPECIFIED                      0
#Define PT_NULL                             1
#Define PT_I2                               2
#Define PT_LONG                             3
#Define PT_R4                               4
#Define PT_DOUBLE                           5
#Define PT_CURRENCY                         6
#Define PT_APPTIME                          7
#Define PT_ERROR                            10
#Define PT_BOOLEAN                          11
#Define PT_OBJECT                           13
#Define PT_I8                               20
#Define PT_STRING8                          30
#Define PT_UNICODE                          31
#Define PT_SYSTIME                          64
#Define PT_CLSID                            72
#Define PT_BINARY                           258

#Define PT_SHORT                            PT_I2
#Define PT_I4                               PT_LONG
#Define PT_FLOAT                            PT_R4
#Define PT_R8                               PT_DOUBLE
#Define PT_LONGLONG                         PT_I8

#IF STRINGS UNICODE
	#Define PT_TSTRING                      PT_UNICODE
	#Define PT_MV_TSTRING                   (MV_FLAG | PT_UNICODE)
#ELSE
	#Define PT_TSTRING                      PT_STRING8
	#Define PT_MV_TSTRING                   (MV_FLAG | PT_STRING8)
#ENDIF

#Define PROP_TYPE_MASK                      00000FFFFH
#Define PROP_ID_NULL                        0
#Define PROP_ID_INVALID                     0FFFFH
#Define PR_NULL                             0

#Define PT_MV_I2                            (MV_FLAG | PT_I2)
#Define PT_MV_LONG                          (MV_FLAG | PT_LONG)
#Define PT_MV_R4                            (MV_FLAG | PT_R4)
#Define PT_MV_DOUBLE                        (MV_FLAG | PT_DOUBLE)
#Define PT_MV_CURRENCY                      (MV_FLAG | PT_CURRENCY)
#Define PT_MV_APPTIME                       (MV_FLAG | PT_APPTIME)
#Define PT_MV_SYSTIME                       (MV_FLAG | PT_SYSTIME)
#Define PT_MV_STRING8                       (MV_FLAG | PT_STRING8)
#Define PT_MV_BINARY                        (MV_FLAG | PT_BINARY)
#Define PT_MV_UNICODE                       (MV_FLAG | PT_UNICODE)
#Define PT_MV_CLSID                         (MV_FLAG | PT_CLSID)
#Define PT_MV_I8                            (MV_FLAG | PT_I8)

#Define PT_MV_SHORT                         PT_MV_I2
#Define PT_MV_I4                            PT_MV_LONG
#Define PT_MV_FLOAT                         PT_MV_R4
#Define PT_MV_R8                            PT_MV_DOUBLE
#Define PT_MV_LONGLONG                      PT_MV_I8

#Define MV_INSTANCE                         0x2000
#Define MVI_FLAG                            (MV_FLAG | MV_INSTANCE)

SPropTagArray Struct
	cValues DD
	aulPropTag DD
EndS

SBinary Struct
	cb DD
	lpb DD
EndS

SShortArray Struct
	cValues DD
	lpi DD
EndS

SGuidArray Struct
	cValues DD
	lpguid DD
EndS

SRealArray Struct
	cValues DD
	lpflt DD
EndS

SLongArray Struct
	cValues DD
	lpl DD
EndS

SLargeIntegerArray Struct
	cValues DD
	lpli DD
EndS

SDateTimeArray Struct
	cValues DD
	lpft DD
EndS

SAppTimeArray Struct
	cValues DD
	lpat DD
EndS

SCurrencyArray Struct
	cValues DD
	lpcur DD
EndS

SBinaryArray Struct
	cValues DD
	lpbin DD
EndS

SDoubleArray Struct
	cValues DD
	lpdbl DD
EndS

SWStringArray Struct
	cValues DD
	lppszW DD
EndS

SLPSTRArray Struct
	cValues DD
	lppszA DD
EndS

SPropProblem Struct
	ulIndex DD
	ulPropTag DD
	scode DD
EndS

SPropProblemArray Struct
	cProblem DD
	aProblem SPropProblem <>
EndS

FLATENTRY Struct
	cb DD
	abEntry DB
EndS

FLATENTRYLIST Struct
	cEntries DD
	cbEntries DD
	abEntries DB
EndS

MTSID Struct
	cb DD
	ab DB
EndS

FLATMTSIDLIST Struct
	cMTSIDs DD
	cbMTSIDs DD
	abMTSIDs DB
EndS

ADRENTRY Struct
	ulReserved1 DD
	cValues DD
	rgPropVals DD
EndS

ADRLIST Struct
	cEntries DD
	aEntries ADRENTRY <>
EndS

SRow Struct
	ulAdrEntryPad DD
	cValues DD
	lpProps DD
EndS

SRowSet Struct
	cRows DD 
	aRow SRow <>
EndS

MAPIERROR Struct
	ulVersion DD
	lpszError DD
	lpszComponent DD
	ulLowLevelError DD
	ulContext DD
EndS

#Define fnevCriticalError                   000000001H
#Define fnevNewMail                         000000002H
#Define fnevObjectCreated                   000000004H
#Define fnevObjectDeleted                   000000008H
#Define fnevObjectModified                  000000010H
#Define fnevObjectMoved                     000000020H
#Define fnevObjectCopied                    000000040H
#Define fnevSearchComplete                  000000080H
#Define fnevTableModified                   000000100H
#Define fnevStatusObjectModified            000000200H
#Define fnevReservedForMapi                 040000000H
#Define fnevExtended                        080000000H

#Define TABLE_CHANGED                       1
#Define TABLE_ERROR                         2
#Define TABLE_ROW_ADDED                     3
#Define TABLE_ROW_DELETED                   4
#Define TABLE_ROW_MODIFIED                  5
#Define TABLE_SORT_DONE                     6
#Define TABLE_RESTRICT_DONE                 7
#Define TABLE_SETCOL_DONE                   8
#Define TABLE_RELOAD                        9

ERROR_NOTIFICATION Struct
	cbEntryID DD
	lpEntryID DD
	scode DD
	ulFlags DD
	lpMAPIError DD
EndS

NEWMAIL_NOTIFICATION Struct
	cbEntryID DD
	lpEntryID DD
	cbParentID DD
	lpParentID DD
	ulFlags DD
	lpszMessageClass DD
	ulMessageFlags DD
EndS

OBJECT_NOTIFICATION Struct
	cbEntryID DD
	lpEntryID DD
	ulObjType DD
	cbParentID DD
	lpParentID DD
	cbOldID DD
	lpOldID DD
	cbOldParentID DD
	lpOldParentID DD
	lpPropTagArray DD
EndS

TABLE_NOTIFICATION Struct
	ulTableEvent DD
	hResult DD
	propIndex DD
	propPrior DD
	row DD
	ulPad DD
EndS

EXTENDED_NOTIFICATION Struct
	ulEvent DD
	cb DD
	pbEventParameters DD
EndS

STATUS_OBJECT_NOTIFICATION Struct
	cbEntryID DD
	lpEntryID DD
	cValues DD
	lpPropVals DD
EndS

NOTIFICATION Struct
	ulEventType DD
	ulAlignPad DD
	Union
		err ERROR_NOTIFICATION <>
		newmail NEWMAIL_NOTIFICATION <>
		obj OBJECT_NOTIFICATION <>
		tab TABLE_NOTIFICATION <>
		ext EXTENDED_NOTIFICATION <>
		statobj STATUS_OBJECT_NOTIFICATION <>
	EndUnion
EndS

#Define szMAPINotificationMsg               "MAPI Notify window message"

#Define MAPI_TOP_LEVEL                      000000001H

#Define MAPI_ERROR_VERSION                  000000000H

#Define KEEP_OPEN_READONLY                  000000001H
#Define KEEP_OPEN_READWRITE                 000000002H
#Define FORCE_SAVE                          000000004H

#Define MAPI_CREATE                         000000002H
#Define STREAM_APPEND                       000000004H

#Define MAPI_MOVE                           000000001H
#Define MAPI_NOREPLACE                      000000002H
#Define MAPI_DECLINE_OK                     000000004H

#IFNDEF MAPI_DIALOG
	#Define MAPI_DIALOG                     000000008H
#ENDIF

#IFNDEF MAPI_USE_DEFAULT
	#Define MAPI_USE_DEFAULT                000000040H
#ENDIF

#Define MAPI_NO_STRINGS                     000000001H
#Define MAPI_NO_IDS                         000000002H

#Define MNID_ID                             0
#Define MNID_STRING                         1
MAPINAMEID Struct
	lpguid DD
	ulKind DD
	Union
		lID DD
		lpwstrName DD
	EndUnion
EndS

#Define TBLSTAT_COMPLETE                    0
#Define TBLSTAT_QCHANGED                    7
#Define TBLSTAT_SORTING                     9
#Define TBLSTAT_SORT_ERROR                  10
#Define TBLSTAT_SETTING_COLS                11
#Define TBLSTAT_SETCOL_ERROR                13
#Define TBLSTAT_RESTRICTING                 14
#Define TBLSTAT_RESTRICT_ERROR              15

#Define TBLTYPE_SNAPSHOT                    0
#Define TBLTYPE_KEYSET                      1
#Define TBLTYPE_DYNAMIC                     2

#Define TABLE_SORT_ASCEND                   000000000H
#Define TABLE_SORT_DESCEND                  000000001H
#Define TABLE_SORT_COMBINE                  000000002H


SSortOrder Struct
	ulPropTag DD
	ulOrder DD
EndS

SSortOrderSet Struct
	cSorts DD
	cCategories DD
	cExpanded DD
	aSort SSortOrder <>
EndS

#Define BOOKMARK_BEGINNING                  0
#Define BOOKMARK_CURRENT                    1
#Define BOOKMARK_END                        2

/* Fuzzy Level */

#Define FL_FULLSTRING                       000000000H
#Define FL_SUBSTRING                        000000001H
#Define FL_PREFIX                           000000002H

#Define FL_IGNORECASE                       000010000H
#Define FL_IGNORENONSPACE                   000020000H
#Define FL_LOOSE                            000040000H

#Define RES_AND                             000000000H
#Define RES_OR                              000000001H
#Define RES_NOT                             000000002H
#Define RES_CONTENT                         000000003H
#Define RES_PROPERTY                        000000004H
#Define RES_COMPAREPROPS                    000000005H
#Define RES_BITMASK                         000000006H
#Define RES_SIZE                            000000007H
#Define RES_EXIST                           000000008H
#Define RES_SUBRESTRICTION                  000000009H
#Define RES_COMMENT                         00000000AH

#Define RELOP_LT                            0
#Define RELOP_LE                            1
#Define RELOP_GT                            2
#Define RELOP_GE                            3
#Define RELOP_EQ                            4
#Define RELOP_NE                            5
#Define RELOP_RE                            6

#Define BMR_EQZ                             0
#Define BMR_NEZ                             1

SAndRestriction Struct
	cRes DD
	lpRes DD
EndS

SOrRestriction Struct
	cRes DD
	lpRes DD
EndS

SNotRestriction Struct
	ulReserved DD
	lpRes DD
EndS

SContentRestriction Struct
	ulFuzzyLevel DD
	ulPropTag DD
	lpProp DD
EndS

SBitMaskRestriction Struct
	relBMR DD
	ulPropTag DD
	ulMask DD
EndS

typedef struct _SPropertyRestriction
{
    ULONG           relop;
    ULONG           ulPropTag;
    LPSPropValue    lpProp;
} SPropertyRestriction;

typedef struct _SComparePropsRestriction
{
    ULONG           relop;
    ULONG           ulPropTag1;
    ULONG           ulPropTag2;
} SComparePropsRestriction;

typedef struct _SSizeRestriction
{
    ULONG           relop;
    ULONG           ulPropTag;
    ULONG           cb;
} SSizeRestriction;

typedef struct _SExistRestriction
{
    ULONG           ulReserved1;
    ULONG           ulPropTag;
    ULONG           ulReserved2;
} SExistRestriction;

typedef struct _SSubRestriction
{
    ULONG           ulSubObject;
    LPSRestriction  lpRes;
} SSubRestriction;

typedef struct _SCommentRestriction
{
    ULONG           cValues; /* # of properties in lpProp */
    LPSRestriction  lpRes;
    LPSPropValue    lpProp;
} SCommentRestriction;

typedef struct _SRestriction
{
    ULONG   rt;         /* Restriction type */
    union
    {
        SComparePropsRestriction    resCompareProps;    /* first */
        SAndRestriction             resAnd;
        SOrRestriction              resOr;
        SNotRestriction             resNot;
        SContentRestriction         resContent;
        SPropertyRestriction        resProperty;
        SBitMaskRestriction         resBitMask;
        SSizeRestriction            resSize;
        SExistRestriction           resExist;
        SSubRestriction             resSub;
        SCommentRestriction         resComment;
    } res;
} SRestriction;

/* SComparePropsRestriction is first in the union so that */
/* static initializations of 3-value restriction work.    */

/* Flags of the methods of IMAPITable */

/* QueryColumn */

#define TBL_ALL_COLUMNS     ((ULONG) 0x00000001)

/* QueryRows */
/* Possible values for PR_ROW_TYPE (for categorization) */

#define TBL_LEAF_ROW            ((ULONG) 1)
#define TBL_EMPTY_CATEGORY      ((ULONG) 2)
#define TBL_EXPANDED_CATEGORY   ((ULONG) 3)
#define TBL_COLLAPSED_CATEGORY  ((ULONG) 4)

/* Table wait flag */

#define TBL_NOWAIT          ((ULONG) 0x00000001)
/* alternative name for TBL_NOWAIT */
#define TBL_ASYNC           ((ULONG) 0x00000001)
#define TBL_BATCH           ((ULONG) 0x00000002)

/* FindRow */

#define DIR_BACKWARD        ((ULONG) 0x00000001)

/* Table cursor states */

#define TBL_NOADVANCE       ((ULONG) 0x00000001)

#define MAPI_IMAPITABLE_METHODS(IPURE)                                  \
    MAPIMETHOD(GetLastError)                                            \
        (THIS_  HRESULT                     hResult,                    \
                ULONG                       ulFlags,                    \
                LPMAPIERROR FAR *           lppMAPIError) IPURE;        \
    MAPIMETHOD(Advise)                                                  \
        (THIS_  ULONG                       ulEventMask,                \
                LPMAPIADVISESINK            lpAdviseSink,               \
                ULONG FAR *                 lpulConnection) IPURE;      \
    MAPIMETHOD(Unadvise)                                                \
        (THIS_  ULONG                       ulConnection) IPURE;        \
    MAPIMETHOD(GetStatus)                                               \
        (THIS_  ULONG FAR *                 lpulTableStatus,            \
                ULONG FAR *                 lpulTableType) IPURE;       \
    MAPIMETHOD(SetColumns)                                              \
        (THIS_  LPSPropTagArray             lpPropTagArray,             \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(QueryColumns)                                            \
        (THIS_  ULONG                       ulFlags,                    \
                LPSPropTagArray FAR *       lpPropTagArray) IPURE;      \
    MAPIMETHOD(GetRowCount)                                             \
        (THIS_  ULONG                       ulFlags,                    \
                ULONG FAR *                 lpulCount) IPURE;           \
    MAPIMETHOD(SeekRow)                                                 \
        (THIS_  BOOKMARK                    bkOrigin,                   \
                LONG                        lRowCount,                  \
                LONG FAR *                  lplRowsSought) IPURE;       \
    MAPIMETHOD(SeekRowApprox)                                           \
        (THIS_  ULONG                       ulNumerator,                \
                ULONG                       ulDenominator) IPURE;       \
    MAPIMETHOD(QueryPosition)                                           \
        (THIS_  ULONG FAR *                 lpulRow,                    \
                ULONG FAR *                 lpulNumerator,              \
                ULONG FAR *                 lpulDenominator) IPURE;     \
    MAPIMETHOD(FindRow)                                                 \
        (THIS_  LPSRestriction              lpRestriction,              \
                BOOKMARK                    bkOrigin,                   \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(Restrict)                                                \
        (THIS_  LPSRestriction              lpRestriction,              \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(CreateBookmark)                                          \
        (THIS_  BOOKMARK FAR *              lpbkPosition) IPURE;        \
    MAPIMETHOD(FreeBookmark)                                            \
        (THIS_  BOOKMARK                    bkPosition) IPURE;          \
    MAPIMETHOD(SortTable)                                               \
        (THIS_  LPSSortOrderSet             lpSortCriteria,             \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(QuerySortOrder)                                          \
        (THIS_  LPSSortOrderSet FAR *       lppSortCriteria) IPURE;     \
    MAPIMETHOD(QueryRows)                                               \
        (THIS_  LONG                        lRowCount,                  \
                ULONG                       ulFlags,                    \
                LPSRowSet FAR *             lppRows) IPURE;             \
    MAPIMETHOD(Abort) (THIS) IPURE;                                     \
    MAPIMETHOD(ExpandRow)                                               \
        (THIS_  ULONG                       cbInstanceKey,              \
                LPBYTE                      pbInstanceKey,              \
                ULONG                       ulRowCount,                 \
                ULONG                       ulFlags,                    \
                LPSRowSet FAR *             lppRows,                    \
                ULONG FAR *                 lpulMoreRows) IPURE;        \
    MAPIMETHOD(CollapseRow)                                             \
        (THIS_  ULONG                       cbInstanceKey,              \
                LPBYTE                      pbInstanceKey,              \
                ULONG                       ulFlags,                    \
                ULONG FAR *                 lpulRowCount) IPURE;        \
    MAPIMETHOD(WaitForCompletion)                                       \
        (THIS_  ULONG                       ulFlags,                    \
                ULONG                       ulTimeout,                  \
                ULONG FAR *                 lpulTableStatus) IPURE;     \
    MAPIMETHOD(GetCollapseState)                                        \
        (THIS_  ULONG                       ulFlags,                    \
                ULONG                       cbInstanceKey,              \
                LPBYTE                      lpbInstanceKey,             \
                ULONG FAR *                 lpcbCollapseState,          \
                LPBYTE FAR *                lppbCollapseState) IPURE;   \
    MAPIMETHOD(SetCollapseState)                                        \
        (THIS_  ULONG                       ulFlags,                    \
                ULONG                       cbCollapseState,            \
                LPBYTE                      pbCollapseState,            \
                BOOKMARK FAR *              lpbkLocation) IPURE;        \

#undef       INTERFACE
#define      INTERFACE  IMAPITable
DECLARE_MAPI_INTERFACE_(IMAPITable, IUnknown)
{
    BEGIN_INTERFACE
    MAPI_IUNKNOWN_METHODS(PURE)
    MAPI_IMAPITABLE_METHODS(PURE)
};

/* IProfSect Interface ----------------------------------------------------- */

/* Standard section for public profile properties */

#define PS_PROFILE_PROPERTIES_INIT \
{   0x98, 0x15, 0xAC, 0x08, 0xAA, 0xB0, 0x10, 0x1A, \
    0x8C, 0x93, 0x08, 0x00, 0x2B, 0x2A, 0x56, 0xC2  }


#define MAPI_IPROFSECT_METHODS(IPURE)

#undef       INTERFACE
#define      INTERFACE  IProfSect
DECLARE_MAPI_INTERFACE_(IProfSect, IMAPIProp)
{
    BEGIN_INTERFACE
    MAPI_IUNKNOWN_METHODS(PURE)
    MAPI_IMAPIPROP_METHODS(PURE)
    MAPI_IPROFSECT_METHODS(PURE)
};

/* IMAPIStatus Interface --------------------------------------------------- */

/* Values for PR_RESOURCE_TYPE, _METHODS, _FLAGS */

#define MAPI_STORE_PROVIDER     ((ULONG) 33)    /* Message Store */
#define MAPI_AB                 ((ULONG) 34)    /* Address Book */
#define MAPI_AB_PROVIDER        ((ULONG) 35)    /* Address Book Provider */
#define MAPI_TRANSPORT_PROVIDER ((ULONG) 36)    /* Transport Provider */
#define MAPI_SPOOLER            ((ULONG) 37)    /* Message Spooler */
#define MAPI_PROFILE_PROVIDER   ((ULONG) 38)    /* Profile Provider */
#define MAPI_SUBSYSTEM          ((ULONG) 39)    /* Overall Subsystem Status */
#define MAPI_HOOK_PROVIDER      ((ULONG) 40)    /* Spooler Hook */

#define STATUS_VALIDATE_STATE   ((ULONG) 0x00000001)
#define STATUS_SETTINGS_DIALOG  ((ULONG) 0x00000002)
#define STATUS_CHANGE_PASSWORD  ((ULONG) 0x00000004)
#define STATUS_FLUSH_QUEUES     ((ULONG) 0x00000008)

#define STATUS_DEFAULT_OUTBOUND ((ULONG) 0x00000001)
#define STATUS_DEFAULT_STORE    ((ULONG) 0x00000002)
#define STATUS_PRIMARY_IDENTITY ((ULONG) 0x00000004)
#define STATUS_SIMPLE_STORE     ((ULONG) 0x00000008)
#define STATUS_XP_PREFER_LAST   ((ULONG) 0x00000010)
#define STATUS_NO_PRIMARY_IDENTITY ((ULONG) 0x00000020)
#define STATUS_NO_DEFAULT_STORE ((ULONG) 0x00000040)
#define STATUS_TEMP_SECTION     ((ULONG) 0x00000080)
#define STATUS_OWN_STORE        ((ULONG) 0x00000100)
/****** HOOK_INBOUND            ((ULONG) 0x00000200) Defined in MAPIHOOK.H */
/****** HOOK_OUTBOUND           ((ULONG) 0x00000400) Defined in MAPIHOOK.H */
#define STATUS_NEED_IPM_TREE    ((ULONG) 0x00000800)
#define STATUS_PRIMARY_STORE    ((ULONG) 0x00001000)
#define STATUS_SECONDARY_STORE  ((ULONG) 0x00002000)


/*
 * PR_STATUS_CODE bit. Low 16 bits for common values; High 16 bits
 * for provider type-specific values. (DCR 304)
 */

#define STATUS_AVAILABLE        ((ULONG) 0x00000001)
#define STATUS_OFFLINE          ((ULONG) 0x00000002)
#define STATUS_FAILURE          ((ULONG) 0x00000004)

/* Transport values of PR_STATUS_CODE */

#define STATUS_INBOUND_ENABLED  ((ULONG) 0x00010000)
#define STATUS_INBOUND_ACTIVE   ((ULONG) 0x00020000)
#define STATUS_INBOUND_FLUSH    ((ULONG) 0x00040000)
#define STATUS_OUTBOUND_ENABLED ((ULONG) 0x00100000)
#define STATUS_OUTBOUND_ACTIVE  ((ULONG) 0x00200000)
#define STATUS_OUTBOUND_FLUSH   ((ULONG) 0x00400000)
#define STATUS_REMOTE_ACCESS    ((ULONG) 0x00800000)

/* ValidateState flags */

#define SUPPRESS_UI                 ((ULONG) 0x00000001)
#define REFRESH_XP_HEADER_CACHE     ((ULONG) 0x00010000)
#define PROCESS_XP_HEADER_CACHE     ((ULONG) 0x00020000)
#define FORCE_XP_CONNECT            ((ULONG) 0x00040000)
#define FORCE_XP_DISCONNECT         ((ULONG) 0x00080000)
#define CONFIG_CHANGED              ((ULONG) 0x00100000)
#define ABORT_XP_HEADER_OPERATION   ((ULONG) 0x00200000)
#define SHOW_XP_SESSION_UI          ((ULONG) 0x00400000)

/* SettingsDialog flags */

#define UI_READONLY     ((ULONG) 0x00000001)

/* FlushQueues flags */

#define FLUSH_UPLOAD        ((ULONG) 0x00000002)
#define FLUSH_DOWNLOAD      ((ULONG) 0x00000004)
#define FLUSH_FORCE         ((ULONG) 0x00000008)
#define FLUSH_NO_UI         ((ULONG) 0x00000010)
#define FLUSH_ASYNC_OK      ((ULONG) 0x00000020)

#define MAPI_IMAPISTATUS_METHODS(IPURE)                                 \
    MAPIMETHOD(ValidateState)                                           \
        (THIS_  ULONG                       ulUIParam,                  \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(SettingsDialog)                                          \
        (THIS_  ULONG                       ulUIParam,                  \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(ChangePassword)                                          \
        (THIS_  LPTSTR                      lpOldPass,                  \
                LPTSTR                      lpNewPass,                  \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(FlushQueues)                                             \
        (THIS_  ULONG                       ulUIParam,                  \
                ULONG                       cbTargetTransport,          \
                LPENTRYID                   lpTargetTransport,          \
                ULONG                       ulFlags) IPURE;             \

#undef       INTERFACE
#define      INTERFACE  IMAPIStatus
DECLARE_MAPI_INTERFACE_(IMAPIStatus, IMAPIProp)
{
    BEGIN_INTERFACE
    MAPI_IUNKNOWN_METHODS(PURE)
    MAPI_IMAPIPROP_METHODS(PURE)
    MAPI_IMAPISTATUS_METHODS(PURE)
};

/* IMAPIContainer Interface ------------------------------------------------ */

/* Flags for OpenEntry() */

/****** MAPI_MODIFY             ((ULONG) 0x00000001) above */
/****** MAPI_DEFERRED_ERRORS    ((ULONG) 0x00000008) below */
#define MAPI_BEST_ACCESS        ((ULONG) 0x00000010)

/* GetContentsTable() */
/****** MAPI_UNICODE            ((ULONG) 0x80000000) above */
/****** MAPI_DEFERRED_ERRORS    ((ULONG) 0x00000008) below */
/****** MAPI_ASSOCIATED         ((ULONG) 0x00000040) below */

/* GetHierarchyTable() */
/****** MAPI_UNICODE            ((ULONG) 0x80000000) above */
#define CONVENIENT_DEPTH        ((ULONG) 0x00000001)
/****** MAPI_DEFERRED_ERRORS    ((ULONG) 0x00000008) below */

/* GetSearchCriteria */
/****** MAPI_UNICODE            ((ULONG) 0x80000000) above */
#define SEARCH_RUNNING          ((ULONG) 0x00000001)
#define SEARCH_REBUILD          ((ULONG) 0x00000002)
#define SEARCH_RECURSIVE        ((ULONG) 0x00000004)
#define SEARCH_FOREGROUND       ((ULONG) 0x00000008)

/* SetSearchCriteria */
#define STOP_SEARCH             ((ULONG) 0x00000001)
#define RESTART_SEARCH          ((ULONG) 0x00000002)
#define RECURSIVE_SEARCH        ((ULONG) 0x00000004)
#define SHALLOW_SEARCH          ((ULONG) 0x00000008)
#define FOREGROUND_SEARCH       ((ULONG) 0x00000010)
#define BACKGROUND_SEARCH       ((ULONG) 0x00000020)

#define MAPI_IMAPICONTAINER_METHODS(IPURE)                              \
    MAPIMETHOD(GetContentsTable)                                        \
        (THIS_  ULONG                       ulFlags,                    \
                LPMAPITABLE FAR *           lppTable) IPURE;            \
    MAPIMETHOD(GetHierarchyTable)                                       \
        (THIS_  ULONG                       ulFlags,                    \
                LPMAPITABLE FAR *           lppTable) IPURE;            \
    MAPIMETHOD(OpenEntry)                                               \
        (THIS_  ULONG                       cbEntryID,                  \
                LPENTRYID                   lpEntryID,                  \
                LPCIID                      lpInterface,                \
                ULONG                       ulFlags,                    \
                ULONG FAR *                 lpulObjType,                \
                LPUNKNOWN FAR *             lppUnk) IPURE;              \
    MAPIMETHOD(SetSearchCriteria)                                       \
        (THIS_  LPSRestriction              lpRestriction,              \
                LPENTRYLIST                 lpContainerList,            \
                ULONG                       ulSearchFlags) IPURE;       \
    MAPIMETHOD(GetSearchCriteria)                                       \
        (THIS_  ULONG                       ulFlags,                    \
                LPSRestriction FAR *        lppRestriction,             \
                LPENTRYLIST FAR *           lppContainerList,           \
                ULONG FAR *                 lpulSearchState)IPURE;      \

#undef       INTERFACE
#define      INTERFACE  IMAPIContainer
DECLARE_MAPI_INTERFACE_(IMAPIContainer, IMAPIProp)
{
    BEGIN_INTERFACE
    MAPI_IUNKNOWN_METHODS(PURE)
    MAPI_IMAPIPROP_METHODS(PURE)
    MAPI_IMAPICONTAINER_METHODS(PURE)
};

/* IABContainer Interface -------------------------------------------------- */

/*
 *  IABContainer PR_CONTAINER_FLAGS values
 *  If AB_UNMODIFIABLE and AB_MODIFIABLE are both set, it means the container
 *  doesn't know if it's modifiable or not, and the client should
 *  try to modify the contents but we won't expect it to work.
 *  If the AB_RECIPIENTS flag is set and neither AB_MODIFIABLE or AB_UNMODIFIABLE
 *  bits are set, it is an error.
 */

typedef struct _flaglist
{
    ULONG cFlags;
    ULONG ulFlag[MAPI_DIM];
} FlagList, FAR * LPFlagList;


/*
 *  Container flags
 */
#define AB_RECIPIENTS           ((ULONG) 0x00000001)
#define AB_SUBCONTAINERS        ((ULONG) 0x00000002)
#define AB_MODIFIABLE           ((ULONG) 0x00000004)
#define AB_UNMODIFIABLE         ((ULONG) 0x00000008)
#define AB_FIND_ON_OPEN         ((ULONG) 0x00000010)
#define AB_NOT_DEFAULT          ((ULONG) 0x00000020)

/* CreateEntry() */

#define CREATE_CHECK_DUP_STRICT ((ULONG) 0x00000001)
#define CREATE_CHECK_DUP_LOOSE  ((ULONG) 0x00000002)
#define CREATE_REPLACE          ((ULONG) 0x00000004)

/* ResolveNames() - ulFlags */
/****** MAPI_UNICODE            ((ULONG) 0x80000000) above */

/* ResolveNames() - rgulFlags */
#define MAPI_UNRESOLVED         ((ULONG) 0x00000000)
#define MAPI_AMBIGUOUS          ((ULONG) 0x00000001)
#define MAPI_RESOLVED           ((ULONG) 0x00000002)


#define MAPI_IABCONTAINER_METHODS(IPURE)                                \
    MAPIMETHOD(CreateEntry)                                             \
        (THIS_  ULONG                       cbEntryID,                  \
                LPENTRYID                   lpEntryID,                  \
                ULONG                       ulCreateFlags,              \
                LPMAPIPROP FAR  *           lppMAPIPropEntry) IPURE;    \
    MAPIMETHOD(CopyEntries)                                             \
        (THIS_  LPENTRYLIST                 lpEntries,                  \
                ULONG                       ulUIParam,                  \
                LPMAPIPROGRESS              lpProgress,                 \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(DeleteEntries)                                           \
        (THIS_  LPENTRYLIST                 lpEntries,                  \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(ResolveNames)                                            \
        (THIS_  LPSPropTagArray             lpPropTagArray,             \
                ULONG                       ulFlags,                    \
                LPADRLIST                   lpAdrList,                  \
                LPFlagList                  lpFlagList) IPURE;          \

#undef       INTERFACE
#define      INTERFACE  IABContainer
DECLARE_MAPI_INTERFACE_(IABContainer, IMAPIContainer)
{
    BEGIN_INTERFACE
    MAPI_IUNKNOWN_METHODS(PURE)
    MAPI_IMAPIPROP_METHODS(PURE)
    MAPI_IMAPICONTAINER_METHODS(PURE)
    MAPI_IABCONTAINER_METHODS(PURE)
};

/* IMailUser Interface ----------------------------------------------------- */

/*  Any call which can create a one-off entryID (i.e. MAPISupport::CreateOneOff
    or IAdrBook::CreateOneOff) can encode the value for PR_SEND_RICH_INFO by
    passing in the following flag in the ulFlags parameter.  Setting this flag
    indicates that PR_SEND_RICH_INFO will be FALSE.
*/
#define MAPI_SEND_NO_RICH_INFO      ((ULONG) 0x00010000)




/* Values of PR_NDR_DIAG_CODE */

#define MAPI_DIAG(_code)    ((LONG) _code)

#define MAPI_DIAG_NO_DIAGNOSTIC                     MAPI_DIAG( -1 )
#define MAPI_DIAG_OR_NAME_UNRECOGNIZED              MAPI_DIAG( 0 )
#define MAPI_DIAG_OR_NAME_AMBIGUOUS                 MAPI_DIAG( 1 )
#define MAPI_DIAG_MTS_CONGESTED                     MAPI_DIAG( 2 )
#define MAPI_DIAG_LOOP_DETECTED                     MAPI_DIAG( 3 )
#define MAPI_DIAG_RECIPIENT_UNAVAILABLE             MAPI_DIAG( 4 )
#define MAPI_DIAG_MAXIMUM_TIME_EXPIRED              MAPI_DIAG( 5 )
#define MAPI_DIAG_EITS_UNSUPPORTED                  MAPI_DIAG( 6 )
#define MAPI_DIAG_CONTENT_TOO_LONG                  MAPI_DIAG( 7 )
#define MAPI_DIAG_IMPRACTICAL_TO_CONVERT            MAPI_DIAG( 8 )
#define MAPI_DIAG_PROHIBITED_TO_CONVERT             MAPI_DIAG( 9 )
#define MAPI_DIAG_CONVERSION_UNSUBSCRIBED           MAPI_DIAG( 10 )
#define MAPI_DIAG_PARAMETERS_INVALID                MAPI_DIAG( 11 )
#define MAPI_DIAG_CONTENT_SYNTAX_IN_ERROR           MAPI_DIAG( 12 )
#define MAPI_DIAG_LENGTH_CONSTRAINT_VIOLATD         MAPI_DIAG( 13 )
#define MAPI_DIAG_NUMBER_CONSTRAINT_VIOLATD         MAPI_DIAG( 14 )
#define MAPI_DIAG_CONTENT_TYPE_UNSUPPORTED          MAPI_DIAG( 15 )
#define MAPI_DIAG_TOO_MANY_RECIPIENTS               MAPI_DIAG( 16 )
#define MAPI_DIAG_NO_BILATERAL_AGREEMENT            MAPI_DIAG( 17 )
#define MAPI_DIAG_CRITICAL_FUNC_UNSUPPORTED         MAPI_DIAG( 18 )
#define MAPI_DIAG_CONVERSION_LOSS_PROHIB            MAPI_DIAG( 19 )
#define MAPI_DIAG_LINE_TOO_LONG                     MAPI_DIAG( 20 )
#define MAPI_DIAG_PAGE_TOO_LONG                     MAPI_DIAG( 21 )
#define MAPI_DIAG_PICTORIAL_SYMBOL_LOST             MAPI_DIAG( 22 )
#define MAPI_DIAG_PUNCTUATION_SYMBOL_LOST           MAPI_DIAG( 23 )
#define MAPI_DIAG_ALPHABETIC_CHARACTER_LOST         MAPI_DIAG( 24 )
#define MAPI_DIAG_MULTIPLE_INFO_LOSSES              MAPI_DIAG( 25 )
#define MAPI_DIAG_REASSIGNMENT_PROHIBITED           MAPI_DIAG( 26 )
#define MAPI_DIAG_REDIRECTION_LOOP_DETECTED         MAPI_DIAG( 27 )
#define MAPI_DIAG_EXPANSION_PROHIBITED              MAPI_DIAG( 28 )
#define MAPI_DIAG_SUBMISSION_PROHIBITED             MAPI_DIAG( 29 )
#define MAPI_DIAG_EXPANSION_FAILED                  MAPI_DIAG( 30 )
#define MAPI_DIAG_RENDITION_UNSUPPORTED             MAPI_DIAG( 31 )
#define MAPI_DIAG_MAIL_ADDRESS_INCORRECT            MAPI_DIAG( 32 )
#define MAPI_DIAG_MAIL_OFFICE_INCOR_OR_INVD         MAPI_DIAG( 33 )
#define MAPI_DIAG_MAIL_ADDRESS_INCOMPLETE           MAPI_DIAG( 34 )
#define MAPI_DIAG_MAIL_RECIPIENT_UNKNOWN            MAPI_DIAG( 35 )
#define MAPI_DIAG_MAIL_RECIPIENT_DECEASED           MAPI_DIAG( 36 )
#define MAPI_DIAG_MAIL_ORGANIZATION_EXPIRED         MAPI_DIAG( 37 )
#define MAPI_DIAG_MAIL_REFUSED                      MAPI_DIAG( 38 )
#define MAPI_DIAG_MAIL_UNCLAIMED                    MAPI_DIAG( 39 )
#define MAPI_DIAG_MAIL_RECIPIENT_MOVED              MAPI_DIAG( 40 )
#define MAPI_DIAG_MAIL_RECIPIENT_TRAVELLING         MAPI_DIAG( 41 )
#define MAPI_DIAG_MAIL_RECIPIENT_DEPARTED           MAPI_DIAG( 42 )
#define MAPI_DIAG_MAIL_NEW_ADDRESS_UNKNOWN          MAPI_DIAG( 43 )
#define MAPI_DIAG_MAIL_FORWARDING_UNWANTED          MAPI_DIAG( 44 )
#define MAPI_DIAG_MAIL_FORWARDING_PROHIB            MAPI_DIAG( 45 )
#define MAPI_DIAG_SECURE_MESSAGING_ERROR            MAPI_DIAG( 46 )
#define MAPI_DIAG_DOWNGRADING_IMPOSSIBLE            MAPI_DIAG( 47 )

/* Values of PR_DELIVERY_POINT (MH_T_DELIVERY_POINT) */

#define MAPI_MH_DP_PUBLIC_UA                        ((ULONG) 0)
#define MAPI_MH_DP_PRIVATE_UA                       ((ULONG) 1)
#define MAPI_MH_DP_MS                               ((ULONG) 2)
#define MAPI_MH_DP_ML                               ((ULONG) 3)
#define MAPI_MH_DP_PDAU                             ((ULONG) 4)
#define MAPI_MH_DP_PDS_PATRON                       ((ULONG) 5)
#define MAPI_MH_DP_OTHER_AU                         ((ULONG) 6)


#define MAPI_IMAILUSER_METHODS(IPURE)

#undef       INTERFACE
#define      INTERFACE  IMailUser
DECLARE_MAPI_INTERFACE_(IMailUser, IMAPIProp)
{
    BEGIN_INTERFACE
    MAPI_IUNKNOWN_METHODS(PURE)
    MAPI_IMAPIPROP_METHODS(PURE)
    MAPI_IMAILUSER_METHODS(PURE)
};

/* IDistList Interface ----------------------------------------------------- */

#define MAPI_IDISTLIST_METHODS(IPURE)                                   \
    MAPIMETHOD(CreateEntry)                                             \
        (THIS_  ULONG                       cbEntryID,                  \
                LPENTRYID                   lpEntryID,                  \
                ULONG                       ulCreateFlags,              \
                LPMAPIPROP FAR  *           lppMAPIPropEntry) IPURE;    \
    MAPIMETHOD(CopyEntries)                                             \
        (THIS_  LPENTRYLIST                 lpEntries,                  \
                ULONG                       ulUIParam,                  \
                LPMAPIPROGRESS              lpProgress,                 \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(DeleteEntries)                                           \
        (THIS_  LPENTRYLIST                 lpEntries,                  \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(ResolveNames)                                            \
        (THIS_  LPSPropTagArray             lpPropTagArray,             \
                ULONG                       ulFlags,                    \
                LPADRLIST                   lpAdrList,                  \
                LPFlagList                  lpFlagList) IPURE;          \

#undef       INTERFACE
#define      INTERFACE  IDistList
DECLARE_MAPI_INTERFACE_(IDistList, IMAPIContainer)
{
    BEGIN_INTERFACE
    MAPI_IUNKNOWN_METHODS(PURE)
    MAPI_IMAPIPROP_METHODS(PURE)
    MAPI_IMAPICONTAINER_METHODS(PURE)
    MAPI_IDISTLIST_METHODS(PURE)
};

/* IMAPIFolder Interface --------------------------------------------------- */

/* IMAPIFolder folder type (enum) */

#define FOLDER_ROOT             ((ULONG) 0x00000000)
#define FOLDER_GENERIC          ((ULONG) 0x00000001)
#define FOLDER_SEARCH           ((ULONG) 0x00000002)

/* CreateMessage */
/****** MAPI_DEFERRED_ERRORS    ((ULONG) 0x00000008) below */
/****** MAPI_ASSOCIATED         ((ULONG) 0x00000040) below */

/* CopyMessages */

#define MESSAGE_MOVE            ((ULONG) 0x00000001)
#define MESSAGE_DIALOG          ((ULONG) 0x00000002)
/****** MAPI_DECLINE_OK         ((ULONG) 0x00000004) above */

/* CreateFolder */

#define OPEN_IF_EXISTS          ((ULONG) 0x00000001)
/****** MAPI_DEFERRED_ERRORS    ((ULONG) 0x00000008) below */
/****** MAPI_UNICODE            ((ULONG) 0x80000000) above */

/* DeleteFolder */

#define DEL_MESSAGES            ((ULONG) 0x00000001)
#define FOLDER_DIALOG           ((ULONG) 0x00000002)
#define DEL_FOLDERS             ((ULONG) 0x00000004)

/* EmptyFolder */
#define DEL_ASSOCIATED          ((ULONG) 0x00000008)

/* CopyFolder */

#define FOLDER_MOVE             ((ULONG) 0x00000001)
/****** FOLDER_DIALOG           ((ULONG) 0x00000002) above */
/****** MAPI_DECLINE_OK         ((ULONG) 0x00000004) above */
#define COPY_SUBFOLDERS         ((ULONG) 0x00000010)
/****** MAPI_UNICODE            ((ULONG) 0x80000000) above */


/* SetReadFlags */

/****** SUPPRESS_RECEIPT        ((ULONG) 0x00000001) below */
/****** FOLDER_DIALOG           ((ULONG) 0x00000002) above */
/****** CLEAR_READ_FLAG         ((ULONG) 0x00000004) below */
/****** MAPI_DEFERRED_ERRORS    ((ULONG) 0x00000008) below */
/****** GENERATE_RECEIPT_ONLY   ((ULONG) 0x00000010) below */
/****** CLEAR_RN_PENDING        ((ULONG) 0x00000020) below */
/****** CLEAR_NRN_PENDING       ((ULONG) 0x00000040) below */


/* GetMessageStatus */

#define MSGSTATUS_HIGHLIGHTED   ((ULONG) 0x00000001)
#define MSGSTATUS_TAGGED        ((ULONG) 0x00000002)
#define MSGSTATUS_HIDDEN        ((ULONG) 0x00000004)
#define MSGSTATUS_DELMARKED     ((ULONG) 0x00000008)

/* Bits for remote message status */

#define MSGSTATUS_REMOTE_DOWNLOAD   ((ULONG) 0x00001000)
#define MSGSTATUS_REMOTE_DELETE     ((ULONG) 0x00002000)

/* SaveContentsSort */

#define RECURSIVE_SORT          ((ULONG) 0x00000002)

/* PR_STATUS property */

#define FLDSTATUS_HIGHLIGHTED   ((ULONG) 0x00000001)
#define FLDSTATUS_TAGGED        ((ULONG) 0x00000002)
#define FLDSTATUS_HIDDEN        ((ULONG) 0x00000004)
#define FLDSTATUS_DELMARKED     ((ULONG) 0x00000008)

#define MAPI_IMAPIFOLDER_METHODS(IPURE)                                 \
    MAPIMETHOD(CreateMessage)                                           \
        (THIS_  LPCIID                      lpInterface,                \
                ULONG                       ulFlags,                    \
                LPMESSAGE FAR *             lppMessage) IPURE;          \
    MAPIMETHOD(CopyMessages)                                            \
        (THIS_  LPENTRYLIST                 lpMsgList,                  \
                LPCIID                      lpInterface,                \
                LPVOID                      lpDestFolder,               \
                ULONG                       ulUIParam,                  \
                LPMAPIPROGRESS              lpProgress,                 \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(DeleteMessages)                                          \
        (THIS_  LPENTRYLIST                 lpMsgList,                  \
                ULONG                       ulUIParam,                  \
                LPMAPIPROGRESS              lpProgress,                 \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(CreateFolder)                                            \
        (THIS_  ULONG                       ulFolderType,               \
                LPTSTR                      lpszFolderName,             \
                LPTSTR                      lpszFolderComment,          \
                LPCIID                      lpInterface,                \
                ULONG                       ulFlags,                    \
                LPMAPIFOLDER FAR *          lppFolder) IPURE;           \
    MAPIMETHOD(CopyFolder)                                              \
        (THIS_  ULONG                       cbEntryID,                  \
                LPENTRYID                   lpEntryID,                  \
                LPCIID                      lpInterface,                \
                LPVOID                      lpDestFolder,               \
                LPTSTR                      lpszNewFolderName,          \
                ULONG                       ulUIParam,                  \
                LPMAPIPROGRESS              lpProgress,                 \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(DeleteFolder)                                            \
        (THIS_  ULONG                       cbEntryID,                  \
                LPENTRYID                   lpEntryID,                  \
                ULONG                       ulUIParam,                  \
                LPMAPIPROGRESS              lpProgress,                 \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(SetReadFlags)                                            \
        (THIS_  LPENTRYLIST                 lpMsgList,                  \
                ULONG                       ulUIParam,                  \
                LPMAPIPROGRESS              lpProgress,                 \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(GetMessageStatus)                                        \
        (THIS_  ULONG                       cbEntryID,                  \
                LPENTRYID                   lpEntryID,                  \
                ULONG                       ulFlags,                    \
                ULONG FAR *                 lpulMessageStatus) IPURE;   \
    MAPIMETHOD(SetMessageStatus)                                        \
        (THIS_  ULONG                       cbEntryID,                  \
                LPENTRYID                   lpEntryID,                  \
                ULONG                       ulNewStatus,                \
                ULONG                       ulNewStatusMask,            \
                ULONG FAR *                 lpulOldStatus) IPURE;       \
    MAPIMETHOD(SaveContentsSort)                                        \
        (THIS_  LPSSortOrderSet             lpSortCriteria,             \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(EmptyFolder)                                             \
        (THIS_  ULONG                       ulUIParam,                  \
                LPMAPIPROGRESS              lpProgress,                 \
                ULONG                       ulFlags) IPURE;             \

#undef       INTERFACE
#define      INTERFACE  IMAPIFolder
DECLARE_MAPI_INTERFACE_(IMAPIFolder, IMAPIContainer)
{
    BEGIN_INTERFACE
    MAPI_IUNKNOWN_METHODS(PURE)
    MAPI_IMAPIPROP_METHODS(PURE)
    MAPI_IMAPICONTAINER_METHODS(PURE)
    MAPI_IMAPIFOLDER_METHODS(PURE)
};

/* IMsgStore Interface ----------------------------------------------------- */

/*  PR_STORE_SUPPORT_MASK bits */
#define STORE_ENTRYID_UNIQUE    ((ULONG) 0x00000001)
#define STORE_READONLY          ((ULONG) 0x00000002)
#define STORE_SEARCH_OK         ((ULONG) 0x00000004)
#define STORE_MODIFY_OK         ((ULONG) 0x00000008)
#define STORE_CREATE_OK         ((ULONG) 0x00000010)
#define STORE_ATTACH_OK         ((ULONG) 0x00000020)
#define STORE_OLE_OK            ((ULONG) 0x00000040)
#define STORE_SUBMIT_OK         ((ULONG) 0x00000080)
#define STORE_NOTIFY_OK         ((ULONG) 0x00000100)
#define STORE_MV_PROPS_OK       ((ULONG) 0x00000200)
#define STORE_CATEGORIZE_OK     ((ULONG) 0x00000400)
#define STORE_RTF_OK            ((ULONG) 0x00000800)
#define STORE_RESTRICTION_OK    ((ULONG) 0x00001000)
#define STORE_SORT_OK           ((ULONG) 0x00002000)
#define STORE_PUBLIC_FOLDERS    ((ULONG) 0x00004000)
#define STORE_UNCOMPRESSED_RTF  ((ULONG) 0x00008000)

/* PR_STORE_STATE bits, try not to collide with PR_STORE_SUPPORT_MASK */

#define STORE_HAS_SEARCHES      ((ULONG) 0x01000000)


/* OpenEntry() */

/****** MAPI_MODIFY             ((ULONG) 0x00000001) above */
/****** MAPI_DEFERRED_ERRORS    ((ULONG) 0x00000008) below */
/****** MAPI_BEST_ACCESS        ((ULONG) 0x00000010) above */

/* SetReceiveFolder() */

/****** MAPI_UNICODE            ((ULONG) 0x80000000) above */

/* GetReceiveFolder() */

/****** MAPI_UNICODE            ((ULONG) 0x80000000) above */

/* GetReceiveFolderTable() */

/****** MAPI_DEFERRED_ERRORS    ((ULONG) 0x00000008) below */

/* StoreLogoff() */

#define LOGOFF_NO_WAIT          ((ULONG) 0x00000001)
#define LOGOFF_ORDERLY          ((ULONG) 0x00000002)
#define LOGOFF_PURGE            ((ULONG) 0x00000004)
#define LOGOFF_ABORT            ((ULONG) 0x00000008)
#define LOGOFF_QUIET            ((ULONG) 0x00000010)

#define LOGOFF_COMPLETE         ((ULONG) 0x00010000)
#define LOGOFF_INBOUND          ((ULONG) 0x00020000)
#define LOGOFF_OUTBOUND         ((ULONG) 0x00040000)
#define LOGOFF_OUTBOUND_QUEUE   ((ULONG) 0x00080000)

/* SetLockState() */

#define MSG_LOCKED              ((ULONG) 0x00000001)
#define MSG_UNLOCKED            ((ULONG) 0x00000000)

/* Flag bits for PR_VALID_FOLDER_MASK */

#define FOLDER_IPM_SUBTREE_VALID        ((ULONG) 0x00000001)
#define FOLDER_IPM_INBOX_VALID          ((ULONG) 0x00000002)
#define FOLDER_IPM_OUTBOX_VALID         ((ULONG) 0x00000004)
#define FOLDER_IPM_WASTEBASKET_VALID    ((ULONG) 0x00000008)
#define FOLDER_IPM_SENTMAIL_VALID       ((ULONG) 0x00000010)
#define FOLDER_VIEWS_VALID              ((ULONG) 0x00000020)
#define FOLDER_COMMON_VIEWS_VALID       ((ULONG) 0x00000040)
#define FOLDER_FINDER_VALID             ((ULONG) 0x00000080)

#define MAPI_IMSGSTORE_METHODS(IPURE)                                   \
    MAPIMETHOD(Advise)                                                  \
        (THIS_  ULONG                       cbEntryID,                  \
                LPENTRYID                   lpEntryID,                  \
                ULONG                       ulEventMask,                \
                LPMAPIADVISESINK            lpAdviseSink,               \
                ULONG FAR *                 lpulConnection) IPURE;      \
    MAPIMETHOD(Unadvise)                                                \
        (THIS_  ULONG                       ulConnection) IPURE;        \
    MAPIMETHOD(CompareEntryIDs)                                         \
        (THIS_  ULONG                       cbEntryID1,                 \
                LPENTRYID                   lpEntryID1,                 \
                ULONG                       cbEntryID2,                 \
                LPENTRYID                   lpEntryID2,                 \
                ULONG                       ulFlags,                    \
                ULONG FAR *                 lpulResult) IPURE;          \
    MAPIMETHOD(OpenEntry)                                               \
        (THIS_  ULONG                       cbEntryID,                  \
                LPENTRYID                   lpEntryID,                  \
                LPCIID                      lpInterface,                \
                ULONG                       ulFlags,                    \
                ULONG FAR *                 lpulObjType,                \
                LPUNKNOWN FAR *             lppUnk) IPURE;              \
    MAPIMETHOD(SetReceiveFolder)                                        \
        (THIS_  LPTSTR                      lpszMessageClass,           \
                ULONG                       ulFlags,                    \
                ULONG                       cbEntryID,                  \
                LPENTRYID                   lpEntryID) IPURE;           \
    MAPIMETHOD(GetReceiveFolder)                                        \
        (THIS_  LPTSTR                      lpszMessageClass,           \
                ULONG                       ulFlags,                    \
                ULONG FAR *                 lpcbEntryID,                \
                LPENTRYID FAR *             lppEntryID,                 \
                LPTSTR FAR *                lppszExplicitClass) IPURE;  \
    MAPIMETHOD(GetReceiveFolderTable)                                   \
        (THIS_  ULONG                       ulFlags,                    \
                LPMAPITABLE FAR *           lppTable) IPURE;            \
    MAPIMETHOD(StoreLogoff)                                             \
        (THIS_  ULONG FAR *                 lpulFlags) IPURE;           \
    MAPIMETHOD(AbortSubmit)                                             \
        (THIS_  ULONG                       cbEntryID,                  \
                LPENTRYID                   lpEntryID,                  \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(GetOutgoingQueue)                                        \
        (THIS_  ULONG                       ulFlags,                    \
                LPMAPITABLE FAR *           lppTable) IPURE;            \
    MAPIMETHOD(SetLockState)                                            \
        (THIS_  LPMESSAGE                   lpMessage,                  \
                ULONG                       ulLockState) IPURE;         \
    MAPIMETHOD(FinishedMsg)                                             \
        (THIS_  ULONG                       ulFlags,                    \
                ULONG                       cbEntryID,                  \
                LPENTRYID                   lpEntryID) IPURE;           \
    MAPIMETHOD(NotifyNewMail)                                           \
        (THIS_  LPNOTIFICATION              lpNotification) IPURE;      \

#undef       INTERFACE
#define      INTERFACE  IMsgStore
DECLARE_MAPI_INTERFACE_(IMsgStore, IMAPIProp)
{
    BEGIN_INTERFACE
    MAPI_IUNKNOWN_METHODS(PURE)
    MAPI_IMAPIPROP_METHODS(PURE)
    MAPI_IMSGSTORE_METHODS(PURE)
};

/* IMessage Interface ------------------------------------------------------ */

/* SubmitMessage */

#define FORCE_SUBMIT                ((ULONG) 0x00000001)

/* Flags defined in PR_MESSAGE_FLAGS */

#define MSGFLAG_READ            ((ULONG) 0x00000001)
#define MSGFLAG_UNMODIFIED      ((ULONG) 0x00000002)
#define MSGFLAG_SUBMIT          ((ULONG) 0x00000004)
#define MSGFLAG_UNSENT          ((ULONG) 0x00000008)
#define MSGFLAG_HASATTACH       ((ULONG) 0x00000010)
#define MSGFLAG_FROMME          ((ULONG) 0x00000020)
#define MSGFLAG_ASSOCIATED      ((ULONG) 0x00000040)
#define MSGFLAG_RESEND          ((ULONG) 0x00000080)
#define MSGFLAG_RN_PENDING      ((ULONG) 0x00000100)
#define MSGFLAG_NRN_PENDING     ((ULONG) 0x00000200)

/* Flags defined in PR_SUBMIT_FLAGS */

#define SUBMITFLAG_LOCKED       ((ULONG) 0x00000001)
#define SUBMITFLAG_PREPROCESS   ((ULONG) 0x00000002)

/* GetAttachmentTable() */
/****** MAPI_UNICODE            ((ULONG) 0x80000000) above */

/* GetRecipientTable() */
/****** MAPI_UNICODE            ((ULONG) 0x80000000) above */

/* ModifyRecipients */

/* ((ULONG) 0x00000001 is not a valid flag on ModifyRecipients. */
#define MODRECIP_ADD            ((ULONG) 0x00000002)
#define MODRECIP_MODIFY         ((ULONG) 0x00000004)
#define MODRECIP_REMOVE         ((ULONG) 0x00000008)

/* SetReadFlag */

#define SUPPRESS_RECEIPT        ((ULONG) 0x00000001)
#define CLEAR_READ_FLAG         ((ULONG) 0x00000004)
/****** MAPI_DEFERRED_ERRORS    ((ULONG) 0x00000008) below */
#define GENERATE_RECEIPT_ONLY   ((ULONG) 0x00000010)
#define CLEAR_RN_PENDING        ((ULONG) 0x00000020)
#define CLEAR_NRN_PENDING       ((ULONG) 0x00000040)

/* DeleteAttach */

#define ATTACH_DIALOG           ((ULONG) 0x00000001)

/* PR_SECURITY values */
#define SECURITY_SIGNED         ((ULONG) 0x00000001)
#define SECURITY_ENCRYPTED      ((ULONG) 0x00000002)

/* PR_PRIORITY values */
#define PRIO_URGENT             ((long)  1)
#define PRIO_NORMAL             ((long)  0)
#define PRIO_NONURGENT          ((long) -1)

/* PR_SENSITIVITY values */
#define SENSITIVITY_NONE                    ((ULONG) 0x00000000)
#define SENSITIVITY_PERSONAL                ((ULONG) 0x00000001)
#define SENSITIVITY_PRIVATE                 ((ULONG) 0x00000002)
#define SENSITIVITY_COMPANY_CONFIDENTIAL    ((ULONG) 0x00000003)

/* PR_IMPORTANCE values */
#define IMPORTANCE_LOW          ((long) 0)
#define IMPORTANCE_NORMAL       ((long) 1)
#define IMPORTANCE_HIGH         ((long) 2)

#define MAPI_IMESSAGE_METHODS(IPURE)                                    \
    MAPIMETHOD(GetAttachmentTable)                                      \
        (THIS_  ULONG                       ulFlags,                    \
                LPMAPITABLE FAR *           lppTable) IPURE;            \
    MAPIMETHOD(OpenAttach)                                              \
        (THIS_  ULONG                       ulAttachmentNum,            \
                LPCIID                      lpInterface,                \
                ULONG                       ulFlags,                    \
                LPATTACH FAR *              lppAttach) IPURE;           \
    MAPIMETHOD(CreateAttach)                                            \
        (THIS_  LPCIID                      lpInterface,                \
                ULONG                       ulFlags,                    \
                ULONG FAR *                 lpulAttachmentNum,          \
                LPATTACH FAR *              lppAttach) IPURE;           \
    MAPIMETHOD(DeleteAttach)                                            \
        (THIS_  ULONG                       ulAttachmentNum,            \
                ULONG                       ulUIParam,                  \
                LPMAPIPROGRESS              lpProgress,                 \
                ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(GetRecipientTable)                                       \
        (THIS_  ULONG                       ulFlags,                    \
                LPMAPITABLE FAR *           lppTable) IPURE;            \
    MAPIMETHOD(ModifyRecipients)                                        \
        (THIS_  ULONG                       ulFlags,                    \
                LPADRLIST                   lpMods) IPURE;              \
    MAPIMETHOD(SubmitMessage)                                           \
        (THIS_  ULONG                       ulFlags) IPURE;             \
    MAPIMETHOD(SetReadFlag)                                             \
        (THIS_  ULONG                       ulFlags) IPURE;             \

#undef       INTERFACE
#define      INTERFACE  IMessage
DECLARE_MAPI_INTERFACE_(IMessage, IMAPIProp)
{
    BEGIN_INTERFACE
    MAPI_IUNKNOWN_METHODS(PURE)
    MAPI_IMAPIPROP_METHODS(PURE)
    MAPI_IMESSAGE_METHODS(PURE)
};

/* IAttach Interface ------------------------------------------------------- */

/* IAttach attachment methods: PR_ATTACH_METHOD values */

#define NO_ATTACHMENT           ((ULONG) 0x00000000)
#define ATTACH_BY_VALUE         ((ULONG) 0x00000001)
#define ATTACH_BY_REFERENCE     ((ULONG) 0x00000002)
#define ATTACH_BY_REF_RESOLVE   ((ULONG) 0x00000003)
#define ATTACH_BY_REF_ONLY      ((ULONG) 0x00000004)
#define ATTACH_EMBEDDED_MSG     ((ULONG) 0x00000005)
#define ATTACH_OLE              ((ULONG) 0x00000006)

#define MAPI_IATTACH_METHODS(IPURE)

#undef       INTERFACE
#define      INTERFACE  IAttach
DECLARE_MAPI_INTERFACE_(IAttach, IMAPIProp)
{
    BEGIN_INTERFACE
    MAPI_IUNKNOWN_METHODS(PURE)
    MAPI_IMAPIPROP_METHODS(PURE)
    MAPI_IATTACH_METHODS(PURE)
};

/* --------------------------------- */
/* Address Book interface definition */

/* ADRPARM ulFlags - top 4 bits used for versioning */

#define GET_ADRPARM_VERSION(ulFlags)  (((ULONG)ulFlags) & 0xF0000000)
#define SET_ADRPARM_VERSION(ulFlags, ulVersion)  (((ULONG)ulVersion) | (((ULONG)ulFlags) & 0x0FFFFFFF))

/*  Current versions of ADRPARM  */
#define ADRPARM_HELP_CTX        ((ULONG) 0x00000000)


/*  ulFlags   - bit fields */
#define DIALOG_MODAL            ((ULONG) 0x00000001)
#define DIALOG_SDI              ((ULONG) 0x00000002)
#define DIALOG_OPTIONS          ((ULONG) 0x00000004)
#define ADDRESS_ONE             ((ULONG) 0x00000008)
#define AB_SELECTONLY           ((ULONG) 0x00000010)
#define AB_RESOLVE              ((ULONG) 0x00000020)

/* --------------------------------- */
/*  PR_DISPLAY_TYPEs                 */
/*
 *  These standard display types are
 *  by default handled by MAPI.
 *  They have default icons associated
 *  with them.
 */

/*  For address book contents tables */
#define DT_MAILUSER         ((ULONG) 0x00000000)
#define DT_DISTLIST         ((ULONG) 0x00000001)
#define DT_FORUM            ((ULONG) 0x00000002)
#define DT_AGENT            ((ULONG) 0x00000003)
#define DT_ORGANIZATION     ((ULONG) 0x00000004)
#define DT_PRIVATE_DISTLIST ((ULONG) 0x00000005)
#define DT_REMOTE_MAILUSER  ((ULONG) 0x00000006)

/*  For address book hierarchy tables */
#define DT_MODIFIABLE       ((ULONG) 0x00010000)
#define DT_GLOBAL           ((ULONG) 0x00020000)
#define DT_LOCAL            ((ULONG) 0x00030000)
#define DT_WAN              ((ULONG) 0x00040000)
#define DT_NOT_SPECIFIC     ((ULONG) 0x00050000)

/*  For folder hierarchy tables */
#define DT_FOLDER           ((ULONG) 0x01000000)
#define DT_FOLDER_LINK      ((ULONG) 0x02000000)
#define DT_FOLDER_SPECIAL   ((ULONG) 0x04000000)

/*  Accelerator callback for DIALOG_SDI form of AB UI */
typedef BOOL (STDMETHODCALLTYPE ACCELERATEABSDI)(ULONG ulUIParam,
                                                LPVOID lpvmsg);
typedef ACCELERATEABSDI FAR * LPFNABSDI;

/*  Callback to application telling it that the DIALOG_SDI form of the */
/*  AB UI has been dismissed.  This is so that the above LPFNABSDI     */
/*  function doesn't keep being called.                                */
typedef void (STDMETHODCALLTYPE DISMISSMODELESS)(ULONG ulUIParam,
                                                LPVOID lpvContext);
typedef DISMISSMODELESS FAR * LPFNDISMISS;

/*
 * Prototype for the client function hooked to an optional button on
 * the address book dialog
 */

typedef SCODE (STDMETHODCALLTYPE FAR * LPFNBUTTON)(
    ULONG               ulUIParam,
    LPVOID              lpvContext,
    ULONG               cbEntryID,
    LPENTRYID           lpSelection,
    ULONG               ulFlags
);


/* Parameters for the address book dialog */
typedef struct _ADRPARM
{
    ULONG           cbABContEntryID;
    LPENTRYID       lpABContEntryID;
    ULONG           ulFlags;

    LPVOID          lpReserved;
    ULONG           ulHelpContext;
    LPTSTR          lpszHelpFileName;

    LPFNABSDI       lpfnABSDI;
    LPFNDISMISS     lpfnDismiss;
    LPVOID          lpvDismissContext;
    LPTSTR          lpszCaption;
    LPTSTR          lpszNewEntryTitle;
    LPTSTR          lpszDestWellsTitle;
    ULONG           cDestFields;
    ULONG           nDestFieldFocus;
    LPTSTR FAR *    lppszDestTitles;
    ULONG FAR *     lpulDestComps;
    LPSRestriction  lpContRestriction;
    LPSRestriction  lpHierRestriction;
} ADRPARM, FAR * LPADRPARM;


/* ------------ */
/* Random flags */

/* Flag for deferred error */
#define MAPI_DEFERRED_ERRORS    ((ULONG) 0x00000008)

/* Flag for creating and using Folder Associated Information Messages */
#define MAPI_ASSOCIATED         ((ULONG) 0x00000040)

/* Flags for OpenMessageStore() */

#define MDB_NO_DIALOG           ((ULONG) 0x00000001)
#define MDB_WRITE               ((ULONG) 0x00000004)
/****** MAPI_DEFERRED_ERRORS    ((ULONG) 0x00000008) above */
/****** MAPI_BEST_ACCESS        ((ULONG) 0x00000010) above */
#define MDB_TEMPORARY           ((ULONG) 0x00000020)
#define MDB_NO_MAIL             ((ULONG) 0x00000080)

/* Flags for OpenAddressBook */

#define AB_NO_DIALOG            ((ULONG) 0x00000001)

/* IMAPIControl Interface -------------------------------------------------- */

/* Interface used in controls (particularly the button) defined by */
/* Display Tables. */

/*  Flags for GetState */

#define  MAPI_ENABLED       ((ULONG) 0x00000000)
#define  MAPI_DISABLED      ((ULONG) 0x00000001)

#define MAPI_IMAPICONTROL_METHODS(IPURE)                                \
    MAPIMETHOD(GetLastError)                                            \
        (THIS_  HRESULT                     hResult,                    \
                ULONG                       ulFlags,                    \
                LPMAPIERROR FAR *           lppMAPIError) IPURE;        \
    MAPIMETHOD(Activate)                                                \
        (THIS_  ULONG                       ulFlags,                    \
                ULONG                       ulUIParam) IPURE;           \
    MAPIMETHOD(GetState)                                                \
        (THIS_  ULONG                       ulFlags,                    \
                ULONG FAR *                 lpulState) IPURE;           \

#undef       INTERFACE
#define      INTERFACE  IMAPIControl
DECLARE_MAPI_INTERFACE_(IMAPIControl, IUnknown)
{
    BEGIN_INTERFACE
    MAPI_IUNKNOWN_METHODS(PURE)
    MAPI_IMAPICONTROL_METHODS(PURE)
};

DECLARE_MAPI_INTERFACE_PTR(IMAPIControl, LPMAPICONTROL);

/* Display Tables ---------------------------------------------------------- */

/* Flags used in display tables - that is, PR_CONTROL_FLAGS */

#define DT_MULTILINE        ((ULONG) 0x00000001)
#define DT_EDITABLE         ((ULONG) 0x00000002)
#define DT_REQUIRED         ((ULONG) 0x00000004)
#define DT_SET_IMMEDIATE    ((ULONG) 0x00000008)
#define DT_PASSWORD_EDIT    ((ULONG) 0x00000010)
#define DT_ACCEPT_DBCS      ((ULONG) 0x00000020)
#define DT_SET_SELECTION    ((ULONG) 0x00000040)

/* Display Table structures */

#define DTCT_LABEL          ((ULONG) 0x00000000)
#define DTCT_EDIT           ((ULONG) 0x00000001)
#define DTCT_LBX            ((ULONG) 0x00000002)
#define DTCT_COMBOBOX       ((ULONG) 0x00000003)
#define DTCT_DDLBX          ((ULONG) 0x00000004)
#define DTCT_CHECKBOX       ((ULONG) 0x00000005)
#define DTCT_GROUPBOX       ((ULONG) 0x00000006)
#define DTCT_BUTTON         ((ULONG) 0x00000007)
#define DTCT_PAGE           ((ULONG) 0x00000008)
#define DTCT_RADIOBUTTON    ((ULONG) 0x00000009)
#define DTCT_MVLISTBOX      ((ULONG) 0x0000000B)
#define DTCT_MVDDLBX        ((ULONG) 0x0000000C)

/* Labels */
/* Valid ulFlags:
 *   MAPI_UNICODE
 */
typedef struct _DTBLLABEL
{
    ULONG ulbLpszLabelName;
    ULONG ulFlags;
} DTBLLABEL, FAR * LPDTBLLABEL;
#define SizedDtblLabel(n,u) \
struct _DTBLLABEL_ ## u \
{ \
    DTBLLABEL   dtbllabel; \
    TCHAR       lpszLabelName[n]; \
} u


/*  Simple Text Edits  */
/* Valid ulFlags:
 *   MAPI_UNICODE
 */
typedef struct _DTBLEDIT
{
    ULONG ulbLpszCharsAllowed;
    ULONG ulFlags;
    ULONG ulNumCharsAllowed;
    ULONG ulPropTag;
} DTBLEDIT, FAR * LPDTBLEDIT;
#define SizedDtblEdit(n,u) \
struct _DTBLEDIT_ ## u \
{ \
    DTBLEDIT    dtbledit; \
    TCHAR       lpszCharsAllowed[n]; \
} u

/*  List Box  */
/* Valid ulFlags:
 */
#define MAPI_NO_HBAR        ((ULONG) 0x00000001)
#define MAPI_NO_VBAR        ((ULONG) 0x00000002)

typedef struct _DTBLLBX
{
    ULONG ulFlags;
    ULONG ulPRSetProperty;
    ULONG ulPRTableName;
} DTBLLBX, FAR * LPDTBLLBX;


/*  Combo Box   */
/* Valid ulFlags:
 *   MAPI_UNICODE
 */
typedef struct _DTBLCOMBOBOX
{
    ULONG ulbLpszCharsAllowed;
    ULONG ulFlags;
    ULONG ulNumCharsAllowed;
    ULONG ulPRPropertyName;
    ULONG ulPRTableName;
} DTBLCOMBOBOX, FAR * LPDTBLCOMBOBOX;
#define SizedDtblComboBox(n,u) \
struct _DTBLCOMBOBOX_ ## u \
{ \
    DTBLCOMBOBOX    dtblcombobox; \
    TCHAR           lpszCharsAllowed[n]; \
} u


/*  Drop Down   */
/* Valid ulFlags:
 *   none
 */
typedef struct _DTBLDDLBX
{
    ULONG ulFlags;
    ULONG ulPRDisplayProperty;
    ULONG ulPRSetProperty;
    ULONG ulPRTableName;
} DTBLDDLBX, FAR * LPDTBLDDLBX;


/*  Check Box   */
/* Valid ulFlags:
 *   MAPI_UNICODE
 */
typedef struct _DTBLCHECKBOX
{
    ULONG ulbLpszLabel;
    ULONG ulFlags;
    ULONG ulPRPropertyName;
} DTBLCHECKBOX, FAR * LPDTBLCHECKBOX;
#define SizedDtblCheckBox(n,u) \
struct _DTBLCHECKBOX_ ## u \
{ \
    DTBLCHECKBOX    dtblcheckbox; \
    TCHAR       lpszLabel[n]; \
} u



/*  Group Box   */
/* Valid ulFlags:
 *   MAPI_UNICODE
 */
typedef struct _DTBLGROUPBOX
{
    ULONG ulbLpszLabel;
    ULONG ulFlags;
} DTBLGROUPBOX, FAR * LPDTBLGROUPBOX;
#define SizedDtblGroupBox(n,u) \
struct _DTBLGROUPBOX_ ## u \
{ \
    DTBLGROUPBOX    dtblgroupbox; \
    TCHAR           lpszLabel[n]; \
} u

/*  Button control   */
/* Valid ulFlags:
 *   MAPI_UNICODE
 */
typedef struct _DTBLBUTTON
{
    ULONG ulbLpszLabel;
    ULONG ulFlags;
    ULONG ulPRControl;
} DTBLBUTTON, FAR * LPDTBLBUTTON;
#define SizedDtblButton(n,u) \
struct _DTBLBUTTON_ ## u \
{ \
    DTBLBUTTON  dtblbutton; \
    TCHAR       lpszLabel[n]; \
} u

/*  Pages   */
/* Valid ulFlags:
 *   MAPI_UNICODE
 */
typedef struct _DTBLPAGE
{
    ULONG ulbLpszLabel;
    ULONG ulFlags;
    ULONG ulbLpszComponent;
    ULONG ulContext;
} DTBLPAGE, FAR * LPDTBLPAGE;
#define SizedDtblPage(n,n1,u) \
struct _DTBLPAGE_ ## u \
{ \
    DTBLPAGE    dtblpage; \
    TCHAR       lpszLabel[n]; \
    TCHAR       lpszComponent[n1]; \
} u

/*  Radio button   */
/* Valid ulFlags:
 *   MAPI_UNICODE
 */
typedef struct _DTBLRADIOBUTTON
{
    ULONG ulbLpszLabel;
    ULONG ulFlags;
    ULONG ulcButtons;
    ULONG ulPropTag;
    long lReturnValue;
} DTBLRADIOBUTTON, FAR * LPDTBLRADIOBUTTON;
#define SizedDtblRadioButton(n,u) \
struct _DTBLRADIOBUTTON_ ## u \
{ \
    DTBLRADIOBUTTON dtblradiobutton; \
    TCHAR           lpszLabel[n]; \
} u


/*  MultiValued listbox */
/* Valid ulFlags:
 *   none
 */
typedef struct _DTBLMVLISTBOX
{
    ULONG ulFlags;
    ULONG ulMVPropTag;
} DTBLMVLISTBOX, FAR * LPDTBLMVLISTBOX;


/*  MultiValued dropdown */
/* Valid ulFlags:
 *   none
 */
typedef struct _DTBLMVDDLBX
{
    ULONG ulFlags;
    ULONG ulMVPropTag;
} DTBLMVDDLBX, FAR * LPDTBLMVDDLBX;





/* IProviderAdmin Interface ---------------------------------------------- */

/* Flags for ConfigureMsgService */

#define UI_SERVICE                  0x00000002
#define SERVICE_UI_ALWAYS           0x00000002      /* Duplicate UI_SERVICE for consistency and compatibility */
#define SERVICE_UI_ALLOWED          0x00000010
#define UI_CURRENT_PROVIDER_FIRST   0x00000004
/* MSG_SERVICE_UI_READ_ONLY         0x00000008 - in MAPISPI.H */

/* GetProviderTable() */
/****** MAPI_UNICODE            ((ULONG) 0x80000000) above */

/* Values for PR_RESOURCE_FLAGS in message service table */

#define MAPI_IPROVIDERADMIN_METHODS(IPURE)                              \
    MAPIMETHOD(GetLastError)                                            \
        (THIS_  HRESULT                     hResult,                    \
                ULONG                       ulFlags,                    \
                LPMAPIERROR FAR *           lppMAPIError) IPURE;        \
    MAPIMETHOD(GetProviderTable)                                        \
        (THIS_  ULONG                       ulFlags,                    \
                LPMAPITABLE FAR *           lppTable) IPURE;            \
    MAPIMETHOD(CreateProvider)                                          \
        (THIS_  LPTSTR                      lpszProvider,               \
                ULONG                       cValues,                    \
                LPSPropValue                lpProps,                    \
                ULONG                       ulUIParam,                  \
                ULONG                       ulFlags,                    \
                MAPIUID FAR *               lpUID) IPURE;               \
    MAPIMETHOD(DeleteProvider)                                          \
        (THIS_  LPMAPIUID                   lpUID) IPURE;               \
    MAPIMETHOD(OpenProfileSection)                                      \
        (THIS_  LPMAPIUID                   lpUID,                      \
                LPCIID                      lpInterface,                \
                ULONG                       ulFlags,                    \
                LPPROFSECT FAR *            lppProfSect) IPURE;         \


#undef       INTERFACE
#define      INTERFACE  IProviderAdmin
DECLARE_MAPI_INTERFACE_(IProviderAdmin, IUnknown)
{
    BEGIN_INTERFACE
    MAPI_IUNKNOWN_METHODS(PURE)
    MAPI_IPROVIDERADMIN_METHODS(PURE)
};

#ENDIF ;MAPIDEFS_INC
