;=============================================================;
;            rpc.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF RPC_INC
#Define RPC_INC

#IFNDEF WINDOWS_INC
	#Include windows.inc
#ENDIF

#IFNDEF RPCDCE_INC
	#Include rpcdce.inc
#ENDIF

#IFNDEF RPCNSI_INC
	#Include rpcnsi.inc
#ENDIF

#IFNDEF RPCNTERR_INC
	#Include rpcnterr.inc
#ENDIF

#IFNDEF EXCPT_INC
	#Include excpt.inc
#ENDIF

#IFNDEF WINERROR_INC
	#Include winerror.inc
#ENDIF

#IFNDEF RPCASYNC_INC
	#Include rpcasync.inc
#ENDIF

#ENDIF ;RPC_INC
