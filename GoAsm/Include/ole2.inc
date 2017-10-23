;=============================================================;
;           ole2.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF OLE2_INC
#Define OLE2_INC

#IFNDEF WINERROR_INC
	#Include <winerror.inc>
#ENDIF

#IFNDEF OBJBASE_INC
	#Include <objbase.inc>
#ENDIF

#IFNDEF OLEAUTO_INC
	#Include <oleauto.inc>
#ENDIF

#Define E_DRAW                  	VIEW_E_DRAW
#Define DATA_E_FORMATETC        	DV_E_FORMATETC

#Define OLEIVERB_PRIMARY            0
#Define OLEIVERB_SHOW               (-1)
#Define OLEIVERB_OPEN               (-2)
#Define OLEIVERB_HIDE               (-3)
#Define OLEIVERB_UIACTIVATE         (-4)
#Define OLEIVERB_INPLACEACTIVATE    (-5)
#Define OLEIVERB_DISCARDUNDOSTATE   (-6)

#Define EMBDHLP_INPROC_HANDLER   	00000H
#Define EMBDHLP_INPROC_SERVER    	00001H
#Define EMBDHLP_CREATENOW    		000000000H
#Define EMBDHLP_DELAYCREATE  		000010000H

#Define OLECREATE_LEAVERUNNING		000000001H

#IFNDEF OLEIDL_INC
	#Include <oleidl.inc>
#ENDIF


OLESTREAMVTBL Struct
	Get DD
	Put DD
EndS

OLESTREAM Struct
	lpstbl DD
EndS

#ENDIF ;OLE2_INC
