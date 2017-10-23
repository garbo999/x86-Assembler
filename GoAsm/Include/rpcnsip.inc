;=============================================================;
;          rpcnsip.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF RPCNSIP_INC
#Define RPCNSIP_INC

RPC_IMPORT_CONTEXT_P Struct
	LookupContext DD
	ProposedHandle DD
	Bindings DD
EndS

#ENDIF ;RPCNSIP_INC
