;=============================================================;
;          oleauto.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF OLEAUTO_INC
#Define OLEAUTO_INC


#Define STDOLE_MAJORVERNUM			01H
#Define STDOLE_MINORVERNUM			00H
#Define STDOLE_LCID					00000H

#Define STDOLE2_MAJORVERNUM			02H
#Define STDOLE2_MINORVERNUM			00H
#Define STDOLE2_LCID				00000H

#Define VARIANT_NOVALUEPROP      	001H
#Define VARIANT_ALPHABOOL        	002H
#Define VARIANT_NOUSEROVERRIDE  	004H
#Define VARIANT_CALENDAR_HIJRI		008H
#Define VARIANT_LOCALBOOL        	010H

#Define VAR_TIMEVALUEONLY       	000000001H
#Define VAR_DATEVALUEONLY       	000000002H
#Define VAR_VALIDDATE           	000000004H
#Define VAR_CALENDAR_HIJRI      	000000008H
#Define VAR_LOCALBOOL           	000000010H
#Define VAR_FORMAT_NOSUBSTITUTE 	000000020H
#Define VAR_FOURDIGITYEARS			000000040H

#Define VarUI1FromInt       		VarUI1FromI4
#Define VarUI1FromUint      		VarUI1FromUI4
#Define VarI2FromInt        		VarI2FromI4
#Define VarI2FromUint       		VarI2FromUI4
#Define VarI4FromInt        		VarI4FromI4
#Define VarI4FromUint       		VarI4FromUI4
#Define VarR4FromInt        		VarR4FromI4
#Define VarR4FromUint       		VarR4FromUI4
#Define VarR8FromInt        		VarR8FromI4
#Define VarR8FromUint       		VarR8FromUI4
#Define VarDateFromInt      		VarDateFromI4
#Define VarDateFromUint     		VarDateFromUI4
#Define VarCyFromInt        		VarCyFromI4
#Define VarCyFromUint       		VarCyFromUI4
#Define VarBstrFromInt      		VarBstrFromI4
#Define VarBstrFromUint     		VarBstrFromUI4
#Define VarBoolFromInt      		VarBoolFromI4
#Define VarBoolFromUint     		VarBoolFromUI4
#Define VarI1FromInt        		VarI1FromI4
#Define VarI1FromUint       		VarI1FromUI4
#Define VarUI2FromInt       		VarUI2FromI4
#Define VarUI2FromUint      		VarUI2FromUI4
#Define VarUI4FromInt       		VarUI4FromI4
#Define VarUI4FromUint      		VarUI4FromUI4
#Define VarDecFromInt       		VarDecFromI4
#Define VarDecFromUint      		VarDecFromUI4
#Define VarIntFromUI1       		VarI4FromUI1
#Define VarIntFromI2        		VarI4FromI2
#Define VarIntFromI4        		VarI4FromI4
#Define VarIntFromR4        		VarI4FromR4
#Define VarIntFromR8        		VarI4FromR8
#Define VarIntFromDate      		VarI4FromDate
#Define VarIntFromCy        		VarI4FromCy
#Define VarIntFromStr       		VarI4FromStr
#Define VarIntFromDisp      		VarI4FromDisp
#Define VarIntFromBool      		VarI4FromBool
#Define VarIntFromI1        		VarI4FromI1
#Define VarIntFromUI2       		VarI4FromUI2
#Define VarIntFromUI4       		VarI4FromUI4
#Define VarIntFromDec       		VarI4FromDec
#Define VarIntFromUint      		VarI4FromUI4
#Define VarUintFromUI1      		VarUI4FromUI1
#Define VarUintFromI2       		VarUI4FromI2
#Define VarUintFromI4       		VarUI4FromI4
#Define VarUintFromR4       		VarUI4FromR4
#Define VarUintFromR8       		VarUI4FromR8
#Define VarUintFromDate     		VarUI4FromDate
#Define VarUintFromCy       		VarUI4FromCy
#Define VarUintFromStr      		VarUI4FromStr
#Define VarUintFromDisp     		VarUI4FromDisp
#Define VarUintFromBool     		VarUI4FromBool
#Define VarUintFromI1       		VarUI4FromI1
#Define VarUintFromUI2      		VarUI4FromUI2
#Define VarUintFromUI4      		VarUI4FromUI4
#Define VarUintFromDec      		VarUI4FromDec
#Define VarUintFromInt      		VarUI4FromI4

#Define NUMPRS_LEADING_WHITE    	00001H
#Define NUMPRS_TRAILING_WHITE   	00002H
#Define NUMPRS_LEADING_PLUS     	00004H
#Define NUMPRS_TRAILING_PLUS    	00008H
#Define NUMPRS_LEADING_MINUS    	00010H
#Define NUMPRS_TRAILING_MINUS   	00020H
#Define NUMPRS_HEX_OCT          	00040H
#Define NUMPRS_PARENS           	00080H
#Define NUMPRS_DECIMAL          	00100H
#Define NUMPRS_THOUSANDS        	00200H
#Define NUMPRS_CURRENCY         	00400H
#Define NUMPRS_EXPONENT         	00800H
#Define NUMPRS_USE_ALL          	01000H
#Define NUMPRS_STD              	01FFFH

#Define NUMPRS_NEG              	010000H
#Define NUMPRS_INEXACT          	020000H

#Define VTBIT_I1        			010000H ;(1 << VT_I1) = (1 << 16)
#Define VTBIT_UI1       			020000H ;(1 << VT_UI1) = (1 << 17)
#Define VTBIT_I2        			000004H ;(1 << VT_I2) = (1 << 2)
#Define VTBIT_UI2       			040000H ;(1 << VT_UI2) = (1 << 18)
#Define VTBIT_I4        			000008H ;(1 << VT_I4) = (1 << 3)
#Define VTBIT_UI4       			080000H ;(1 << VT_UI4) = (1 << 19)
#Define VTBIT_R4        			000010H ;(1 << VT_R4) = (1 << 4)
#Define VTBIT_R8        			000020H ;(1 << VT_R8) = (1 << 5)
#Define VTBIT_CY        			000040H ;(1 << VT_CY) = (1 << 6)
#Define VTBIT_DECIMAL   			004000H ;(1 << VT_DECIMAL) = (1 << 14)

#Define VARCMP_LT					0
#Define VARCMP_EQ					1
#Define VARCMP_GT					2
#Define VARCMP_NULL					3

#Define VT_HARDTYPE					08000H ;VT_RESERVED

#Define MEMBERID_NIL 				DISPID_UNKNOWN
#Define ID_DEFAULTINST  			(-2)

#Define DISPATCH_METHOD         	01H
#Define DISPATCH_PROPERTYGET    	02H
#Define DISPATCH_PROPERTYPUT    	04H
#Define DISPATCH_PROPERTYPUTREF 	08H

;REGKIND enumeration
REGKIND_DEFAULT						Equ 0
REGKIND_REGISTER					Equ 1
REGKIND_NONE						Equ 2

#Define ACTIVEOBJECT_STRONG 		00H
#Define ACTIVEOBJECT_WEAK 			01H


NUMPARSE Struct
	cDig DD
	dwInFlags DD
	dwOutFlags DD
	cchUsed DD
	nBaseShift DD
	nPwr10 DD
EndS

UDATE Struct
	st SYSTEMTIME <>
	wDayOfYear DW
EndS

PARAMDATA Struct
	szName DD
	vt DW
EndS

METHODDATA Struct
	szName DD
	ppdata DD
	dispid DD
	iMeth DD
	cc DD
	cArgs DD
	wFlags DW
	vtReturn DW
EndS

INTERFACEDATA Struct
	pmethdata DD
	cMembers DD
EndS

#ENDIF ;OLEAUTO_INC
