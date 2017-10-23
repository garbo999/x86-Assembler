;=============================================================;
;            dde.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF DDE_INC
#Define DDE_INC

#IFNDEF WINDEF_INC
	#Include <windef.inc>
#ENDIF

#Define WM_DDE_FIRST	    			003E0H
#Define WM_DDE_INITIATE     			(WM_DDE_FIRST)
#Define WM_DDE_TERMINATE    			(WM_DDE_FIRST + 1)
#Define WM_DDE_ADVISE	    			(WM_DDE_FIRST + 2)
#Define WM_DDE_UNADVISE     			(WM_DDE_FIRST + 3)
#Define WM_DDE_ACK	        			(WM_DDE_FIRST + 4)
#Define WM_DDE_DATA	        			(WM_DDE_FIRST + 5)
#Define WM_DDE_REQUEST	    			(WM_DDE_FIRST + 6)
#Define WM_DDE_POKE	        			(WM_DDE_FIRST + 7)
#Define WM_DDE_EXECUTE	    			(WM_DDE_FIRST + 8)
#Define WM_DDE_LAST	        			(WM_DDE_FIRST + 8)


DDEACK Struct
	usFlags DW
EndS

DDEADVISE Struct
	usFlags DW
EndS

DDEDATA Struct
	usFlags DW
	cfFormat DW
	Value DB 1 Dup ?
EndS

DDEPOKE Struct
	usFlags DW
	cfFormat DW
	Value DB 1 Dup ?
EndS

DDELN Struct
	usFlags DW
	cfFormat DW
EndS

DDEUP Struct
	usFlags DW
	cfFormat DW
	rgb DB
EndS

#ENDIF ;DDE_INC
