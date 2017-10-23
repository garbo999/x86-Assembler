;=============================================================;
;         lzexpand.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LZEXPAND_INC
#Define LZEXPAND_INC

#Define LZERROR_BADINHANDLE   			(-1)
#Define LZERROR_BADOUTHANDLE  			(-2)
#Define LZERROR_READ          			(-3)
#Define LZERROR_WRITE         			(-4)
#Define LZERROR_GLOBALLOC     			(-5)
#Define LZERROR_GLOBLOCK      			(-6)
#Define LZERROR_BADVALUE      			(-7)
#Define LZERROR_UNKNOWNALG    			(-8)


#IF STRINGS UNICODE
	#Define GetExpandedName GetExpandedNameW
	#Define LZOpenFile LZOpenFileW
#ELSE
	#Define GetExpandedName GetExpandedNameA
	#Define LZOpenFile LZOpenFileA
#ENDIF

#ENDIF ;LZEXPAND_INC
