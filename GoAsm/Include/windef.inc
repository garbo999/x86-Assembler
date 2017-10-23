;=============================================================;
;          windef.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINDEF_INC
#Define WINDEF_INC

#Define MAX_PATH          		260

#IFNDEF NULL
	#Define NULL    			0
#ENDIF

#IFNDEF FALSE
	#Define FALSE               0
#ENDIF

#IFNDEF TRUE
	#Define TRUE                1
#ENDIF

#IFNDEF NT_EXCLUDED
	#IFNDEF WINNT_INC
		#Include <winnt.inc>
	#ENDIF
#ENDIF

#Define HFILE_ERROR				(-1)

#Define DM_UPDATE           	1
#Define DM_COPY             	2
#Define DM_PROMPT           	4
#Define DM_MODIFY           	8

#Define DM_IN_BUFFER        	DM_MODIFY
#Define DM_IN_PROMPT        	DM_PROMPT
#Define DM_OUT_BUFFER       	DM_COPY
#Define DM_OUT_DEFAULT      	DM_UPDATE

#Define DC_FIELDS           	1
#Define DC_PAPERS           	2
#Define DC_PAPERSIZE        	3
#Define DC_MINEXTENT        	4
#Define DC_MAXEXTENT        	5
#Define DC_BINS             	6
#Define DC_DUPLEX           	7
#Define DC_SIZE             	8
#Define DC_EXTRA            	9
#Define DC_VERSION          	10
#Define DC_DRIVER           	11
#Define DC_BINNAMES         	12
#Define DC_ENUMRESOLUTIONS  	13
#Define DC_FILEDEPENDENCIES 	14
#Define DC_TRUETYPE         	15
#Define DC_PAPERNAMES       	16
#Define DC_ORIENTATION      	17
#Define DC_COPIES           	18


RECT Struct
	left DD
	top DD
	right DD
	bottom DD
EndS

RECTL Struct
	left DD
	top DD
	right DD
	bottom DD
EndS

POINT Struct
	x DD
	y DD
EndS

POINTL Struct
	x DD
	y DD
EndS

SIZE Struct
	x DD
	y DD
EndS

SIZEL Struct
	x DD
	y DD
EndS

POINTS Struct
	x DW
	y DW
EndS

#ENDIF ;WINDEF_INC
