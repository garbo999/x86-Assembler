;=============================================================;
;           lmuse.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMUSE_INC
#Define LMUSE_INC

#IFNDEF LMUSEFLG_INC
	#Include lmuseflg.inc
#ENDIF

USE_INFO_0 Struct
	ui0_local DD
	ui0_remote DD
EndS

USE_INFO_1 Struct
	ui1_local DD
	ui1_remote DD
	ui1_password DD
	ui1_status DD
	ui1_asg_type DD
	ui1_refcount DD
	ui1_usecount DD
EndS

USE_INFO_2 Struct
	ui2_local DD
	ui2_remote DD
	ui2_password DD
	ui2_status DD
	ui2_asg_type DD
	ui2_refcount DD
	ui2_usecount DD
	ui2_username DD
	ui2_domainname DD
EndS

USE_INFO_3 Struct
	ui3_ui2 USE_INFO_2
	ui3_flags DD
EndS

#Define USE_LOCAL_PARMNUM                   1
#Define USE_REMOTE_PARMNUM                  2
#Define USE_PASSWORD_PARMNUM                3
#Define USE_ASGTYPE_PARMNUM                 4
#Define USE_USERNAME_PARMNUM                5
#Define USE_DOMAINNAME_PARMNUM              6

#Define USE_OK                              0
#Define USE_PAUSED                          1
#Define USE_SESSLOST                        2
#Define USE_DISCONN                         2
#Define USE_NETERR                          3
#Define USE_CONN                            4
#Define USE_RECONN                          5

#Define USE_WILDCARD                        (-1)
#Define USE_DISKDEV                         0
#Define USE_SPOOLDEV                        1
#Define USE_CHARDEV                         2
#Define USE_IPC                             3

#Define CREATE_NO_CONNECT                   01H

#ENDIF ;LMUSE_INC
