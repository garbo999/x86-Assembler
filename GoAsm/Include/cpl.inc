;=============================================================;
;            cpl.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF CPL_INC
#Define CPL_INC

#Define WM_CPL_LAUNCH                       (WM_USER + 1000)
#Define WM_CPL_LAUNCHED                     (WM_USER + 1001)

CPLINFO Struct
	idIcon DD
	idName DD
	idInfo DD
	lData DD
EndS

NEWCPLINFOA Struct
	dwSize DD
	dwFlags DD
	dwHelpContext DD
	lData DD
	hIcon DD
	szName DB 32 Dup ?
	szInfo DB 64 Dup ?
	szHelpFile DB 128 Dup ?
EndS

NEWCPLINFOW Struct
	dwSize DD
	dwFlags DD
	dwHelpContext DD
	lData DD
	hIcon DD
	szName DW 32 Dup ?
	szInfo DW 64 Dup ?
	szHelpFile DW 128 Dup ?
EndS

#Define CPL_DYNAMIC_RES                     0
#Define CPL_INIT                            1
#Define CPL_GETCOUNT                        2
#Define CPL_INQUIRE                         3
#Define CPL_SELECT                          4
#Define CPL_DBLCLK                          5
#Define CPL_STOP                            6
#Define CPL_EXIT                            7
#Define CPL_NEWINQUIRE                      8

#Define CPL_STARTWPARMSA                    9
#Define CPL_STARTWPARMSW                    10

#Define CPL_SETUP                           200

#IF STRINGS UNICODE
	#Define NEWCPLINFO NEWCPLINFOW
	#Define CPL_STARTWPARMS CPL_STARTWPARMSW
#ELSE
	#Define NEWCPLINFO NEWCPLINFOA
	#Define CPL_STARTWPARMS CPL_STARTWPARMSA
#ENDIF

#ENDIF ;CPL_INC
