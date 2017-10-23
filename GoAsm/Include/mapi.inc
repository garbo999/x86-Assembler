;=============================================================;
;           mapi.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF MAPI_INC
#Define MAPI_INC

#Define lhSessionNull                       0

MapiFileDesc Struct
	ulReserved DD
	flFlags DD
	nPosition DD
	lpszPathName DD
	lpszFileName DD
	lpFileType DD
EndS

#Define MAPI_OLE                            000000001H
#Define MAPI_OLE_STATIC                     000000002H

MapiFileTagExt Struct
	ulReserved DD
	cbTag DD
	lpTag DD
	cbEncoding DD
	lpEncoding DD
EndS

MapiRecipDesc Struct
	ulReserved DD
	ulRecipClass DD
	lpszName DD
	lpszAddress DD
	ulEIDSize DD
	lpEntryID DD
EndS

#IFNDEF MAPI_ORIG
	#Define MAPI_ORIG                       0
	#Define MAPI_TO                         1
	#Define MAPI_CC                         2
	#Define MAPI_BCC                        3
#ENDIF

MapiMessage Struct
	ulReserved DD
	lpszSubject DD
	lpszNoteText DD
	lpszMessageType DD
	lpszDateReceived DD
	lpszConversationID DD
	flFlags DD
	lpOriginator DD
	nRecipCount DD
	lpRecips DD
	nFileCount DD
	lpFiles DD
EndS

#Define MAPI_UNREAD                         000000001H
#Define MAPI_RECEIPT_REQUESTED              000000002H
#Define MAPI_SENT                           000000004H

#Define MAPI_LOGON_UI                       000000001H
#IFNDEF MAPI_PASSWORD_UI
	#Define MAPI_PASSWORD_UI                000020000H
#ENDIF
#Define MAPI_NEW_SESSION                    000000002H
#Define MAPI_FORCE_DOWNLOAD                 000001000H
#Define MAPI_EXTENDED                       000000020H

#IFNDEF MAPI_DIALOG
	#Define MAPI_DIALOG                     000000008H
#ENDIF

#Define MAPI_UNREAD_ONLY                    000000020H
#Define MAPI_GUARANTEE_FIFO                 000000100H
#Define MAPI_LONG_MSGID                     000004000H

#Define MAPI_PEEK                           000000080H
#Define MAPI_SUPPRESS_ATTACH                000000800H
#Define MAPI_ENVELOPE_ONLY                  000000040H
#Define MAPI_BODY_AS_FILE                   000000200H

#Define MAPI_AB_NOMODIFY                    000000400H

#IFNDEF SUCCESS_SUCCESS
	#Define SUCCESS_SUCCESS                 0
#ENDIF

#Define MAPI_USER_ABORT                     1
#Define MAPI_E_USER_ABORT                   MAPI_USER_ABORT
#Define MAPI_E_FAILURE                      2
#Define MAPI_E_LOGON_FAILURE                3
#Define MAPI_E_LOGIN_FAILURE                MAPI_E_LOGON_FAILURE
#Define MAPI_E_DISK_FULL                    4
#Define MAPI_E_INSUFFICIENT_MEMORY          5
#Define MAPI_E_ACCESS_DENIED                6
#Define MAPI_E_TOO_MANY_SESSIONS            8
#Define MAPI_E_TOO_MANY_FILES               9
#Define MAPI_E_TOO_MANY_RECIPIENTS          10
#Define MAPI_E_ATTACHMENT_NOT_FOUND         11
#Define MAPI_E_ATTACHMENT_OPEN_FAILURE      12
#Define MAPI_E_ATTACHMENT_WRITE_FAILURE     13
#Define MAPI_E_UNKNOWN_RECIPIENT            14
#Define MAPI_E_BAD_RECIPTYPE                15
#Define MAPI_E_NO_MESSAGES                  16
#Define MAPI_E_INVALID_MESSAGE              17
#Define MAPI_E_TEXT_TOO_LARGE               18
#Define MAPI_E_INVALID_SESSION              19
#Define MAPI_E_TYPE_NOT_SUPPORTED           20
#Define MAPI_E_AMBIGUOUS_RECIPIENT          21
#Define MAPI_E_AMBIG_RECIP                  MAPI_E_AMBIGUOUS_RECIPIENT
#Define MAPI_E_MESSAGE_IN_USE               22
#Define MAPI_E_NETWORK_FAILURE              23
#Define MAPI_E_INVALID_EDITFIELDS           24
#Define MAPI_E_INVALID_RECIPS               25
#Define MAPI_E_NOT_SUPPORTED                26

#ENDIF ;MAPI_INC
