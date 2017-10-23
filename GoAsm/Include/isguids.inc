;=============================================================;
;          isguids.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF ISGUIDS_INC
#Define ISGUIDS_INC

#IFNDEF CLSID_InternetShortcut

#Define CLSID_InternetShortcut			<0FBF23B40H, 0E3F0H, 0101BH, 084H, 088H, 000H, 0AAH, 000H, 03EH, 056H, 0F8H>
#Define IID_IUniformResourceLocatorA	<0FBF23B80H, 0E3F0H, 0101BH, 084H, 088H, 000H, 0AAH, 000H, 03EH, 056H, 0F8H>
#Define IID_IUniformResourceLocatorW	<0CABB0DA0H, 0DA57H, 011CFH, 099H, 074H, 000H, 020H, 0AFH, 0D7H, 097H, 062H>

#IF STRINGS UNICODE
	#Define IID_IUniformResourceLocator IID_IUniformResourceLocatorW
#ELSE
	#Define IID_IUniformResourceLocator IID_IUniformResourceLocatorA
#ENDIF

#ENDIF

#ENDIF ;ISGUIDS_INC
