;=============================================================;
;          windows.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINDOWS_INC
#Define WINDOWS_INC

#IFNDEF WINVER
	#Define WINVER 00400H
#ENDIF

#Include windef.inc
#Include winbase.inc
#Include wingdi.inc
#Include winuser.inc
#Include winnls.inc
#Include wincon.inc
#Include winver.inc
#Include winreg.inc
#Include winnetwk.inc

#IFNDEF WIN32_LEAN_AND_MEAN
	#Include <cderr.inc>
	#Include <dde.inc>
	#Include <ddeml.inc>
	#Include <dlgs.inc>
	#Include <lzexpand.inc>
	#include <mmsystem.inc>
	#Include <nb30.inc>
	#Include <shellapi.inc>
	#Include <winperf.inc>
	#IFNDEF WIN9x
		#Include <winsock2.inc>
		#Include <mswsock.inc>
	#ELSE
		#Include <winsock.inc>
	#ENDIF

;	#IFNDEF NOCRYPT
;		#Include <wincrypt.inc>
;	#ENDIF

	#Include <commdlg.inc>
	#Include <winspool.inc>

#ENDIF

#IFNDEF NOSERVICE
	#Include <winsvc.inc>
#ENDIF

#IF (WINVER >= 00400H)
	#Include <mcx.inc>
#ENDIF

#ENDIF ;WINDOWS_INC
