;=============================================================;
;           mapix.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF MAPIX_INC
#Define MAPIX_INC

#IFNDEF MAPIDEFS_INC
	#Include mapidefs.inc
#ENDIF

#IFNDEF MAPICODE_INC
	#Include mapicode.inc
#ENDIF

#IFNDEF MAPIGUID_INC
	#Include mapiguid.inc
#ENDIF

#IFNDEF MAPITAGS_INC
	#Include mapitags.inc
#ENDIF

#Define MAPI_LOGON_UI                       000000001H
#Define MAPI_NEW_SESSION                    000000002H
#Define MAPI_ALLOW_OTHERS                   000000008H
#Define MAPI_EXPLICIT_PROFILE               000000010H
#Define MAPI_EXTENDED                       000000020H
#Define MAPI_FORCE_DOWNLOAD                 000001000H
#Define MAPI_SERVICE_UI_ALWAYS              000002000H
#Define MAPI_NO_MAIL                        000008000H

#IFNDEF MAPI_PASSWORD_UI
	#Define MAPI_PASSWORD_UI                000020000H
#ENDIF

#Define MAPI_TIMEOUT_SHORT                  000100000H

#Define MAPI_SIMPLE_DEFAULT                 (MAPI_LOGON_UI | MAPI_FORCE_DOWNLOAD | MAPI_ALLOW_OTHERS)
#Define MAPI_SIMPLE_EXPLICIT                (MAPI_NEW_SESSION | MAPI_FORCE_DOWNLOAD | MAPI_EXPLICIT_PROFILE)

MAPIINIT_0 Struct
	ulVersion DD
	ulFlags DD
EndS

#Define MAPI_INIT_VERSION                   0

#Define MAPI_MULTITHREAD_NOTIFICATIONS      000000001H

#Define MAPI_LOGOFF_SHARED                  000000001H
#Define MAPI_LOGOFF_UI                      000000002H

#Define MAPI_DEFAULT_STORE                  000000001H
#Define MAPI_SIMPLE_STORE_TEMPORARY         000000002H
#Define MAPI_SIMPLE_STORE_PERMANENT         000000003H
#Define MAPI_PRIMARY_STORE                  000000004H
#Define MAPI_SECONDARY_STORE                000000005H

#Define MAPI_POST_MESSAGE                   000000001H
#Define MAPI_NEW_MESSAGE                    000000002H

#Define MAPI_DEFAULT_SERVICES               000000001H

#Define SERVICE_DEFAULT_STORE               000000001H
#Define SERVICE_SINGLE_COPY                 000000002H
#Define SERVICE_CREATE_WITH_STORE           000000004H
#Define SERVICE_PRIMARY_IDENTITY            000000008H
#Define SERVICE_NO_PRIMARY_IDENTITY         000000020H

#ENDIF ;MAPIX_INC
