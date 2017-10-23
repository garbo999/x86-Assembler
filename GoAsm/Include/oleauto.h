#ifndef OLEAUTO_H
#define OLEAUTO_H

#DEFINE OLEAUTO_H_REQVER 100

/* Windows OLE Automation support definitions */

/*
Dependancies
oaidl.h
*/

/*
Switches used
None
*/

#IFDEF LINKFILES
	#dynamiclinkfile oleaut32.dll
#ENDIF

#IFNDEF SYSTEMTIME
	SYSTEMTIME STRUCT
		wYear DW
		wMonth DW
		wDayOfWeek DW
		wDay DW
		wHour DW
		wMinute DW
		wSecond DW
		wMilliseconds DW
	ENDS
#ENDIF

#define LOAD_TLB_AS_32BIT	0x20
#define LOAD_TLB_AS_64BIT	0x40
#define MASK_TO_RESET_TLB_BITS !(LOAD_TLB_AS_32BIT | LOAD_TLB_AS_64BIT)

#define STDOLE_MAJORVERNUM  0x1
#define STDOLE_MINORVERNUM  0x0
#define STDOLE_LCID  0x0000

#define STDOLE2_MAJORVERNUM  0x2
#define STDOLE2_MINORVERNUM  0x0
#define STDOLE2_LCID  0x0000

#IFNDEF OAIDL_H
	#include oaidl.h
#ENDIF

#define VARIANT_NOVALUEPROP  0x01
#define VARIANT_ALPHABOOL  0x02
#define VARIANT_NOUSEROVERRIDE  0x04
#define VARIANT_CALENDAR_HIJRI  0x08
#define VARIANT_LOCALBOOL  0x10

#define VAR_TIMEVALUEONLY  1
#define VAR_DATEVALUEONLY  2
#define VAR_VALIDDATE  4
#define VAR_CALENDAR_HIJRI  8
#define VAR_LOCALBOOL  16
#define VAR_FORMAT_NOSUBSTITUTE  32

#define NUMPRS_LEADING_WHITE  0x0001
#define NUMPRS_TRAILING_WHITE  0x0002
#define NUMPRS_LEADING_PLUS  0x0004
#define NUMPRS_TRAILING_PLUS  0x0008
#define NUMPRS_LEADING_MINUS  0x0010
#define NUMPRS_TRAILING_MINUS  0x0020
#define NUMPRS_HEX_OCT  0x0040
#define NUMPRS_PARENS  0x0080
#define NUMPRS_DECIMAL  0x0100
#define NUMPRS_THOUSANDS  0x0200
#define NUMPRS_CURRENCY  0x0400
#define NUMPRS_EXPONENT  0x0800
#define NUMPRS_USE_ALL  0x1000
#define NUMPRS_STD  0x1FFF
#define NUMPRS_NEG  0x10000
#define NUMPRS_INEXACT  0x20000

;#define VTBIT_I1  (1<<VT_I1)
;#define VTBIT_UI1  (1<<VT_UI1)
;#define VTBIT_I2  (1<<VT_I2)
;#define VTBIT_UI2  (1<<VT_UI2)
;#define VTBIT_I4  (1<<VT_I4)
;#define VTBIT_UI4  (1<<VT_UI4)
;#define VTBIT_R4  (1<<VT_R4)
;#define VTBIT_R8  (1<<VT_R8)
;#define VTBIT_CY  (1<<VT_CY)
;#define VTBIT_DECIMAL  (1<<VT_DECIMAL)

#define VARCMP_LT  0
#define VARCMP_EQ  1
#define VARCMP_GT  2
#define VARCMP_NULL  3

#define VT_HARDTYPE  VT_RESERVED

#define MEMBERID_NIL  DISPID_UNKNOWN
#define ID_DEFAULTINST  -2

#define DISPATCH_METHOD  0x1
#define DISPATCH_PROPERTYGET  0x2
#define DISPATCH_PROPERTYPUT  0x4
#define DISPATCH_PROPERTYPUTREF  0x8

#define ACTIVEOBJECT_STRONG  0x0
#define ACTIVEOBJECT_WEAK  0x1

/*
#define VarUI1FromInt VarUI1FromI4
#define VarUI1FromUint VarUI1FromUI4
#define VarI2FromInt VarI2FromI4
#define VarI2FromUint VarI2FromUI4
#define VarI4FromInt VarI4FromI4
#define VarI4FromUint VarI4FromUI4
#define VarR4FromInt VarR4FromI4
#define VarR4FromUint VarR4FromUI4
#define VarR8FromInt VarR8FromI4
#define VarR8FromUint VarR8FromUI4
#define VarDateFromInt VarDateFromI4
#define VarDateFromUint VarDateFromUI4
#define VarCyFromInt VarCyFromI4
#define VarCyFromUint VarCyFromUI4
#define VarBstrFromInt VarBstrFromI4
#define VarBstrFromUint VarBstrFromUI4
#define VarBoolFromInt VarBoolFromI4
#define VarBoolFromUint VarBoolFromUI4
#define VarI1FromInt VarI1FromI4
#define VarI1FromUint VarI1FromUI4
#define VarUI2FromInt VarUI2FromI4
#define VarUI2FromUint VarUI2FromUI4
#define VarUI4FromInt VarUI4FromI4
#define VarUI4FromUint VarUI4FromUI4
#define VarDecFromInt VarDecFromI4
#define VarDecFromUint VarDecFromUI4
#define VarIntFromUI1 VarI4FromUI1
#define VarIntFromI2 VarI4FromI2
#define VarIntFromI4 VarI4FromI4
#define VarIntFromR4 VarI4FromR4
#define VarIntFromR8 VarI4FromR8
#define VarIntFromDate VarI4FromDate
#define VarIntFromCy VarI4FromCy
#define VarIntFromStr VarI4FromStr
#define VarIntFromDisp VarI4FromDisp
#define VarIntFromBool VarI4FromBool
#define VarIntFromI1 VarI4FromI1
#define VarIntFromUI2 VarI4FromUI2
#define VarIntFromUI4 VarI4FromUI4
#define VarIntFromDec VarI4FromDec
#define VarIntFromUint VarI4FromUI4
#define VarUintFromUI1 VarUI4FromUI1
#define VarUintFromI2 VarUI4FromI2
#define VarUintFromI4 VarUI4FromI4
#define VarUintFromR4 VarUI4FromR4
#define VarUintFromR8 VarUI4FromR8
#define VarUintFromDate VarUI4FromDate
#define VarUintFromCy VarUI4FromCy
#define VarUintFromStr VarUI4FromStr
#define VarUintFromDisp VarUI4FromDisp
#define VarUintFromBool VarUI4FromBool
#define VarUintFromI1 VarUI4FromI1
#define VarUintFromUI2 VarUI4FromUI2
#define VarUintFromUI4 VarUI4FromUI4
#define VarUintFromDec VarUI4FromDec
#define VarUintFromInt VarUI4FromI4
*/

NUMPARSE STRUCT
	cDig DD
	dwInFlags DD
	dwOutFlags DD
	cchUsed DD
	nBaseShift DD
	nPwr10 DD
ENDS

UDATE STRUCT
	st SYSTEMTIME <>
	wDayOfYear DW
ENDS

REGKIND_DEFAULT=0
REGKIND_REGISTER=1
REGKIND_NONE=2

PARAMDATA STRUCT
	szName PTR
	vt DD
ENDS

METHODDATA STRUCT
	szName PTR
	ppdata PTR
	dispid DD
	iMeth DD
	cc DD
	cArgs DD
	wFlags DW
	vtReturn DD
ENDS

INTERFACEDATA STRUCT
	pmethdata PTR
	cMembers DD
ENDS

#endif
