;=============================================================;
;          objbase.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF OBJBASE_INC
#Define OBJBASE_INC

;#IFNDEF RPCNDR_INC
;	#Include <rpcndr.inc>
;#ENDIF

#Define CLSCTX_INPROC           	(CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER)
#Define CLSCTX_ALL              	(CLSCTX_INPROC_SERVER | CLSCTX_INPROC_HANDLER | CLSCTX_LOCAL_SERVER | CLSCTX_REMOTE_SERVER)
#Define CLSCTX_SERVER           	(CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER | CLSCTX_REMOTE_SERVER)

;REGCLS enumeration
REGCLS_SINGLEUSE					Equ 0
REGCLS_MULTIPLEUSE					Equ 1
REGCLS_MULTI_SEPARATE				Equ 2
REGCLS_SUSPENDED					Equ 4
REGCLS_SURROGATE					Equ 8

#Define CWCSTORAGENAME				32

#Define STGM_DIRECT             	000000000H
#Define STGM_TRANSACTED         	000010000H
#Define STGM_SIMPLE             	008000000H

#Define STGM_READ               	000000000H
#Define STGM_WRITE              	000000001H
#Define STGM_READWRITE          	000000002H

#Define STGM_SHARE_DENY_NONE    	000000040H
#Define STGM_SHARE_DENY_READ    	000000030H
#Define STGM_SHARE_DENY_WRITE   	000000020H
#Define STGM_SHARE_EXCLUSIVE    	000000010H

#Define STGM_PRIORITY           	000040000H
#Define STGM_DELETEONRELEASE    	004000000H
#Define STGM_NOSCRATCH          	000100000H

#Define STGM_CREATE             	000001000H
#Define STGM_CONVERT            	000020000H
#Define STGM_FAILIFTHERE        	000000000H

#Define STGM_NOSNAPSHOT         	000200000H

#Define ASYNC_MODE_COMPATIBILITY    000000001H
#Define ASYNC_MODE_DEFAULT          000000000H

#Define STGTY_REPEAT                000000100H
#Define STG_TOEND                   0FFFFFFFFH

#Define STG_LAYOUT_SEQUENTIAL       000000000H
#Define STG_LAYOUT_INTERLEAVED      000000001H

#Define STGFMT_STORAGE          	0
#Define STGFMT_NATIVE           	1
#Define STGFMT_FILE             	3
#Define STGFMT_ANY              	4
#Define STGFMT_DOCFILE          	5

#Define STGFMT_DOCUMENT         	0

#IFNDEF WTYPES_INC
	#Include <wtypes.inc>
#ENDIF

#IFNDEF OBJIDL_INC
	#Include <objidl.inc>
#ENDIF

;COINIT enumeration
COINIT_APARTMENTTHREADED			Equ 02H
COINIT_MULTITHREADED				Equ 00H
COINIT_DISABLE_OLE1DDE				Equ 04H
COINIT_SPEED_OVER_MEMORY			Equ 08H

;STDMSHLFLAGS enumeration
SMEXF_SERVER						Equ 01H
SMEXF_HANDLER						Equ 02H

#Define COM_RIGHTS_EXECUTE 			1


#ENDIF ;OBJBASE_INC
