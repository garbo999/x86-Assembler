;=============================================================;
;         mapicode.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF MAPICODE_INC
#Define MAPICODE_INC

#IFNDEF WINERROR_INC
	#Include winerror.inc
#ENDIF

#IFDEF SUCCESS_SUCCESS
	#UNDEF SUCCESS_SUCCESS
#ENDIF
#Define SUCCESS_SUCCESS                     0

#Define MAPI_E_CALL_FAILED                  E_FAIL
#Define MAPI_E_NOT_ENOUGH_MEMORY            E_OUTOFMEMORY
#Define MAPI_E_INVALID_PARAMETER            E_INVALIDARG
#Define MAPI_E_INTERFACE_NOT_SUPPORTED      E_NOINTERFACE
#Define MAPI_E_NO_ACCESS                    E_ACCESSDENIED

#Define MAPI_E_NO_SUPPORT                   (1<<31 | FACILITY_ITF<<16 | 0102H)
#Define MAPI_E_BAD_CHARWIDTH                (1<<31 | FACILITY_ITF<<16 | 0103H)
#Define MAPI_E_STRING_TOO_LONG              (1<<31 | FACILITY_ITF<<16 | 0105H)
#Define MAPI_E_UNKNOWN_FLAGS                (1<<31 | FACILITY_ITF<<16 | 0106H)
#Define MAPI_E_INVALID_ENTRYID              (1<<31 | FACILITY_ITF<<16 | 0107H)
#Define MAPI_E_INVALID_OBJECT               (1<<31 | FACILITY_ITF<<16 | 0108H)
#Define MAPI_E_OBJECT_CHANGED               (1<<31 | FACILITY_ITF<<16 | 0109H)
#Define MAPI_E_OBJECT_DELETED               (1<<31 | FACILITY_ITF<<16 | 010AH)
#Define MAPI_E_BUSY                         (1<<31 | FACILITY_ITF<<16 | 010BH)
#Define MAPI_E_NOT_ENOUGH_DISK              (1<<31 | FACILITY_ITF<<16 | 010DH)
#Define MAPI_E_NOT_ENOUGH_RESOURCES         (1<<31 | FACILITY_ITF<<16 | 010EH)
#Define MAPI_E_NOT_FOUND                    (1<<31 | FACILITY_ITF<<16 | 010FH)
#Define MAPI_E_VERSION                      (1<<31 | FACILITY_ITF<<16 | 0110H)
#Define MAPI_E_LOGON_FAILED                 (1<<31 | FACILITY_ITF<<16 | 0111H)
#Define MAPI_E_SESSION_LIMIT                (1<<31 | FACILITY_ITF<<16 | 0112H)
#Define MAPI_E_USER_CANCEL                  (1<<31 | FACILITY_ITF<<16 | 0113H)
#Define MAPI_E_UNABLE_TO_ABORT              (1<<31 | FACILITY_ITF<<16 | 0114H)
#Define MAPI_E_NETWORK_ERROR                (1<<31 | FACILITY_ITF<<16 | 0115H)
#Define MAPI_E_DISK_ERROR                   (1<<31 | FACILITY_ITF<<16 | 0116H)
#Define MAPI_E_TOO_COMPLEX                  (1<<31 | FACILITY_ITF<<16 | 0117H)
#Define MAPI_E_BAD_COLUMN                   (1<<31 | FACILITY_ITF<<16 | 0118H)
#Define MAPI_E_EXTENDED_ERROR               (1<<31 | FACILITY_ITF<<16 | 0119H)
#Define MAPI_E_COMPUTED                     (1<<31 | FACILITY_ITF<<16 | 011AH)
#Define MAPI_E_CORRUPT_DATA                 (1<<31 | FACILITY_ITF<<16 | 011BH)
#Define MAPI_E_UNCONFIGURED                 (1<<31 | FACILITY_ITF<<16 | 011CH)
#Define MAPI_E_FAILONEPROVIDER              (1<<31 | FACILITY_ITF<<16 | 011DH)
#Define MAPI_E_UNKNOWN_CPID                 (1<<31 | FACILITY_ITF<<16 | 011EH)
#Define MAPI_E_UNKNOWN_LCID                 (1<<31 | FACILITY_ITF<<16 | 011FH)

#Define MAPI_E_PASSWORD_CHANGE_REQUIRED     (1<<31 | FACILITY_ITF<<16 | 0120H)
#Define MAPI_E_PASSWORD_EXPIRED             (1<<31 | FACILITY_ITF<<16 | 0121H)
#Define MAPI_E_INVALID_WORKSTATION_ACCOUNT  (1<<31 | FACILITY_ITF<<16 | 0122H)
#Define MAPI_E_INVALID_ACCESS_TIME          (1<<31 | FACILITY_ITF<<16 | 0123H)
#Define MAPI_E_ACCOUNT_DISABLED             (1<<31 | FACILITY_ITF<<16 | 0124H)

#Define MAPI_E_END_OF_SESSION               (1<<31 | FACILITY_ITF<<16 | 0200H)
#Define MAPI_E_UNKNOWN_ENTRYID              (1<<31 | FACILITY_ITF<<16 | 0201H)
#Define MAPI_E_MISSING_REQUIRED_COLUMN      (1<<31 | FACILITY_ITF<<16 | 0202H)
#Define MAPI_W_NO_SERVICE                   (1<<31 | FACILITY_ITF<<16 | 0203H)

#Define MAPI_E_BAD_VALUE                    (1<<31 | FACILITY_ITF<<16 | 0301H)
#Define MAPI_E_INVALID_TYPE                 (1<<31 | FACILITY_ITF<<16 | 0302H)
#Define MAPI_E_TYPE_NO_SUPPORT              (1<<31 | FACILITY_ITF<<16 | 0303H)
#Define MAPI_E_UNEXPECTED_TYPE              (1<<31 | FACILITY_ITF<<16 | 0304H)
#Define MAPI_E_TOO_BIG                      (1<<31 | FACILITY_ITF<<16 | 0305H)
#Define MAPI_E_DECLINE_COPY                 (1<<31 | FACILITY_ITF<<16 | 0306H)
#Define MAPI_E_UNEXPECTED_ID                (1<<31 | FACILITY_ITF<<16 | 0307H)

#Define MAPI_W_ERRORS_RETURNED              (1<<31 | FACILITY_ITF<<16 | 0380H)

#Define MAPI_E_UNABLE_TO_COMPLETE           (1<<31 | FACILITY_ITF<<16 | 0400H)
#Define MAPI_E_TIMEOUT                      (1<<31 | FACILITY_ITF<<16 | 0401H)
#Define MAPI_E_TABLE_EMPTY                  (1<<31 | FACILITY_ITF<<16 | 0402H)
#Define MAPI_E_TABLE_TOO_BIG                (1<<31 | FACILITY_ITF<<16 | 0403H)

#Define MAPI_E_INVALID_BOOKMARK             (1<<31 | FACILITY_ITF<<16 | 0405H)

#Define MAPI_W_POSITION_CHANGED             (1<<31 | FACILITY_ITF<<16 | 0481H)
#Define MAPI_W_APPROX_COUNT                 (1<<31 | FACILITY_ITF<<16 | 0482H)

#Define MAPI_E_WAIT                         (1<<31 | FACILITY_ITF<<16 | 0500H)
#Define MAPI_E_CANCEL                       (1<<31 | FACILITY_ITF<<16 | 0501H)
#Define MAPI_E_NOT_ME                       (1<<31 | FACILITY_ITF<<16 | 0502H)

#Define MAPI_W_CANCEL_MESSAGE               (1<<31 | FACILITY_ITF<<16 | 0580H)

#Define MAPI_E_CORRUPT_STORE                (1<<31 | FACILITY_ITF<<16 | 0600H)
#Define MAPI_E_NOT_IN_QUEUE                 (1<<31 | FACILITY_ITF<<16 | 0601H)
#Define MAPI_E_NO_SUPPRESS                  (1<<31 | FACILITY_ITF<<16 | 0602H)
#Define MAPI_E_COLLISION                    (1<<31 | FACILITY_ITF<<16 | 0604H)
#Define MAPI_E_NOT_INITIALIZED              (1<<31 | FACILITY_ITF<<16 | 0605H)
#Define MAPI_E_NON_STANDARD                 (1<<31 | FACILITY_ITF<<16 | 0606H)
#Define MAPI_E_NO_RECIPIENTS                (1<<31 | FACILITY_ITF<<16 | 0607H)
#Define MAPI_E_SUBMITTED                    (1<<31 | FACILITY_ITF<<16 | 0608H)
#Define MAPI_E_HAS_FOLDERS                  (1<<31 | FACILITY_ITF<<16 | 0609H)
#Define MAPI_E_HAS_MESSAGES                 (1<<31 | FACILITY_ITF<<16 | 060AH)
#Define MAPI_E_FOLDER_CYCLE                 (1<<31 | FACILITY_ITF<<16 | 060BH)

#Define MAPI_W_PARTIAL_COMPLETION           (1<<31 | FACILITY_ITF<<16 | 0680H)

#Define MAPI_E_AMBIGUOUS_RECIP              (1<<31 | FACILITY_ITF<<16 | 0700H)

#ENDIF ;MAPICODE_INC
