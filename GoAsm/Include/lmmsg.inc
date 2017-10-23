;=============================================================;
;           lmmsg.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMMSG_INC
#Define LMMSG_INC

MSG_INFO_0 Struct
	msgi0_name DD
EndS

MSG_INFO_1 Struct
	msgi1_name DD
	msgi1_forward_flag DD
	msgi1_forward DD
EndS

#Define MSGNAME_NOT_FORWARDED               0
#Define MSGNAME_FORWARDED_TO                004H
#Define MSGNAME_FORWARDED_FROM              010H

#ENDIF ;LMMSG_INC
