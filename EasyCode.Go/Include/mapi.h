#ifndef MAPI_H
#define MAPI_H

/* Messaging Applications Programming Interface (MAPI) definitions */

#IFDEF LINKFILES
	#dynamiclinkfile mapi32.dll
#ENDIF

#define lhSessionNull 0

#define MAPI_OLE  0x00000001
#define MAPI_OLE_STATIC  0x00000002

#ifndef MAPI_ORIG
	#define MAPI_ORIG  0
	#define MAPI_TO  1
	#define MAPI_CC  2
	#define MAPI_BCC  3
#endif

#define MAPI_UNREAD  0x00000001
#define MAPI_RECEIPT_REQUESTED  0x00000002
#define MAPI_SENT  0x00000004

#define MAPI_LOGON_UI  0x00000001
#ifndef MAPI_PASSWORD_UI
	#define MAPI_PASSWORD_UI  0x00020000
#endif
#define MAPI_NEW_SESSION  0x00000002
#define MAPI_FORCE_DOWNLOAD  0x00001000
#define MAPI_EXTENDED  0x00000020

#ifndef MAPI_DIALOG
	#define MAPI_DIALOG  0x00000008
#endif

#define MAPI_UNREAD_ONLY  0x00000020
#define MAPI_GUARANTEE_FIFO  0x00000100
#define MAPI_LONG_MSGID  0x00004000

#define MAPI_PEEK  0x00000080
#define MAPI_SUPPRESS_ATTACH  0x00000800
#define MAPI_ENVELOPE_ONLY  0x00000040
#define MAPI_BODY_AS_FILE  0x00000200

#define MAPI_AB_NOMODIFY  0x00000400

#ifndef SUCCESS_SUCCESS
	#define SUCCESS_SUCCESS  0
#endif

#define MAPI_USER_ABORT  1
#define MAPI_E_USER_ABORT  MAPI_USER_ABORT
#define MAPI_E_FAILURE  2
#define MAPI_E_LOGON_FAILURE  3
#define MAPI_E_LOGIN_FAILURE  MAPI_E_LOGON_FAILURE
#define MAPI_E_DISK_FULL  4
#define MAPI_E_INSUFFICIENT_MEMORY  5
#define MAPI_E_ACCESS_DENIED  6
#define MAPI_E_TOO_MANY_SESSIONS  8
#define MAPI_E_TOO_MANY_FILES  9
#define MAPI_E_TOO_MANY_RECIPIENTS  10
#define MAPI_E_ATTACHMENT_NOT_FOUND  11
#define MAPI_E_ATTACHMENT_OPEN_FAILURE  12
#define MAPI_E_ATTACHMENT_WRITE_FAILURE 13
#define MAPI_E_UNKNOWN_RECIPIENT  14
#define MAPI_E_BAD_RECIPTYPE  15
#define MAPI_E_NO_MESSAGES  16
#define MAPI_E_INVALID_MESSAGE  17
#define MAPI_E_TEXT_TOO_LARGE  18
#define MAPI_E_INVALID_SESSION  19
#define MAPI_E_TYPE_NOT_SUPPORTED  20
#define MAPI_E_AMBIGUOUS_RECIPIENT  21
#define MAPI_E_AMBIG_RECIP  MAPI_E_AMBIGUOUS_RECIPIENT
#define MAPI_E_MESSAGE_IN_USE  22
#define MAPI_E_NETWORK_FAILURE  23
#define MAPI_E_INVALID_EDITFIELDS  24
#define MAPI_E_INVALID_RECIPS  25
#define MAPI_E_NOT_SUPPORTED  26

MapiFileDesc STRUCT
	ulReserved DD
	flFlags DD
	nPosition DD
	lpszPathName PTR
	lpszFileName PTR
	lpFileType PTR
ENDS

MapiFileTagExt STRUCT
	ulReserved DD
	cbTag DD
	lpTag PTR
	cbEncoding DD
	lpEncoding PTR
ENDS

MapiRecipDesc STRUCT
	ulReserved DD
	ulRecipClass DD
	lpszName PTR
	lpszAddress PTR
	ulEIDSize DD
	lpEntryID PTR
ENDS

MapiMessage STRUCT
	ulReserved DD
	lpszSubject PTR
	lpszNoteText PTR
	lpszMessageType PTR
	lpszDateReceived PTR
	lpszConversationID PTR
	flFlags DD
	lpOriginator PTR
	nRecipCount DD
	lpRecips PTR
	nFileCount DD
	lpFiles PTR
ENDS

#endif /* _MAPI_H */
