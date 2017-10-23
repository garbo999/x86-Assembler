#ifndef OAIDL_H
#define OAIDL_H

#DEFINE OAIDL_H_REQVER 100

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF

#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#ifndef COM_NO_WINDOWS_H
	#IFNDEF WINDOWS_H
		#include "windows.h"
	#ENDIF
	#IFNDEF OLE2_H
		#include "ole2.h"
	#ENDIF
#endif /* COM_NO_WINDOWS_H */


#IFNDEF OBJIDL_H
	#include "objidl.h"
#ENDIF

#IFNDEF WTYPES_H
	#include "wtypes.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#IFNDEF DECIMAL
	DECIMAL STRUCT
		Hi32 DD
		Lo64 DQ
	ENDS
#ENDIF

SAFEARRAYBOUND STRUCT
	cElements DD
	lLbound DD
ENDS

SAFEARR_BSTR STRUCT
	Size DD
	aBstr PTR
ENDS

SAFEARR_UNKNOWN STRUCT
	Size DD
	apUnknown PTR
ENDS

SAFEARR_DISPATCH STRUCT
	Size DD
	apDispatch PTR
ENDS

SAFEARR_VARIANT STRUCT
	Size DD
	aVariant PTR
ENDS

SAFEARR_BRECORD STRUCT
	Size DD
	aRecord PTR
ENDS

SAFEARR_HAVEIID STRUCT
	Size DD
	apUnknown PTR
	iid GUID
ENDS

; VT_**** Constants are defined in wtypes.h
SF_ERROR = VT_ERROR
SF_I1 = VT_I1
SF_I2 = VT_I2
SF_I4 = VT_I4
SF_I8 = VT_I8
SF_BSTR = VT_BSTR
SF_UNKNOWN = VT_UNKNOWN
SF_DISPATCH = VT_DISPATCH
SF_VARIANT = VT_VARIANT
SF_RECORD = VT_RECORD
SF_HAVEIID = VT_UNKNOWN|VT_RESERVED

SAFEARRAY_UNION STRUCT
	sfType DD
	UNION
		BstrStr SAFEARR_BSTR
		UnknownStr SAFEARR_UNKNOWN
		DispatchStr SAFEARR_DISPATCH
		VariantStr SAFEARR_VARIANT
		RecordStr SAFEARR_BRECORD
		HaveIidStr SAFEARR_HAVEIID
		ByteStr BYTE_SIZEDARR
		WordStr WORD_SIZEDARR
		LongStr DWORD_SIZEDARR
		HyperStr HYPER_SIZEDARR
	ENDUNION
ENDS

wireSAFEARRAY STRUCT
	cDims DW
	fFeatures DW
	cbElements DD
	cLocks DD
	uArrayStructs SAFEARRAYUNION
	rgsabound SAFEARRAYBOUND
ENDS

SAFEARRAY STRUCT
	cDims DW
	fFeatures DW
	cbElements DD
	cLocks DD
	pvData PTR
	rgsabound SAFEARRAYBOUND
ENDS

#define FADF_AUTO  0x1
#define FADF_STATIC  0x2
#define FADF_EMBEDDED  0x4
#define FADF_FIXEDSIZE  0x10
#define FADF_RECORD  0x20
#define FADF_HAVEIID  0x40
#define FADF_HAVEVARTYPE  0x80
#define FADF_BSTR  0x100
#define FADF_UNKNOWN  0x200
#define FADF_DISPATCH  0x400
#define FADF_VARIANT  0x800
#define FADF_RESERVED  0xF008

/* VARIANT STRUCTURE
 *
 *  VARTYPE vt;
 *  WORD wReserved1;
 *  WORD wReserved2;
 *  WORD wReserved3;
 *  union {
 *    LONGLONG       VT_I8
 *    LONG           VT_I4
 *    BYTE           VT_UI1
 *    SHORT          VT_I2
 *    FLOAT          VT_R4
 *    DOUBLE         VT_R8
 *    VARIANT_BOOL   VT_BOOL
 *    SCODE          VT_ERROR
 *    CY             VT_CY
 *    DATE           VT_DATE
 *    BSTR           VT_BSTR
 *    IUnknown *     VT_UNKNOWN
 *    IDispatch *    VT_DISPATCH
 *    SAFEARRAY *    VT_ARRAY
 *    BYTE *         VT_BYREF|VT_UI1
 *    SHORT *        VT_BYREF|VT_I2
 *    LONG *         VT_BYREF|VT_I4
 *    LONGLONG *     VT_BYREF|VT_I8
 *    FLOAT *        VT_BYREF|VT_R4
 *    DOUBLE *       VT_BYREF|VT_R8
 *    VARIANT_BOOL * VT_BYREF|VT_BOOL
 *    SCODE *        VT_BYREF|VT_ERROR
 *    CY *           VT_BYREF|VT_CY
 *    DATE *         VT_BYREF|VT_DATE
 *    BSTR *         VT_BYREF|VT_BSTR
 *    IUnknown **    VT_BYREF|VT_UNKNOWN
 *    IDispatch **   VT_BYREF|VT_DISPATCH
 *    SAFEARRAY **   VT_BYREF|VT_ARRAY
 *    VARIANT *      VT_BYREF|VT_VARIANT
 *    PVOID          VT_BYREF (Generic ByRef)
 *    CHAR           VT_I1
 *    USHORT         VT_UI2
 *    ULONG          VT_UI4
 *    ULONGLONG      VT_UI8
 *    INT            VT_INT
 *    UINT           VT_UINT
 *    DECIMAL *      VT_BYREF|VT_DECIMAL
 *    CHAR *         VT_BYREF|VT_I1
 *    USHORT *       VT_BYREF|VT_UI2
 *    ULONG *        VT_BYREF|VT_UI4
 *    ULONGLONG *    VT_BYREF|VT_UI8
 *    INT *          VT_BYREF|VT_INT
 *    UINT *         VT_BYREF|VT_UINT
 *  }

struct tagVARIANT
    {
    union 
        {
        struct __tagVARIANT
            {
            VARTYPE vt;
            WORD wReserved1;
            WORD wReserved2;
            WORD wReserved3;
            union 
                {
                LONGLONG llVal;
                LONG lVal;
                BYTE bVal;
                SHORT iVal;
                FLOAT fltVal;
                DOUBLE dblVal;
                VARIANT_BOOL boolVal;
                _VARIANT_BOOL bool;
                SCODE scode;
                CY cyVal;
                DATE date;
                BSTR bstrVal;
                IUnknown *punkVal;
                IDispatch *pdispVal;
                SAFEARRAY *parray;
                BYTE *pbVal;
                SHORT *piVal;
                LONG *plVal;
                LONGLONG *pllVal;
                FLOAT *pfltVal;
                DOUBLE *pdblVal;
                VARIANT_BOOL *pboolVal;
                _VARIANT_BOOL *pbool;
                SCODE *pscode;
                CY *pcyVal;
                DATE *pdate;
                BSTR *pbstrVal;
                IUnknown **ppunkVal;
                IDispatch **ppdispVal;
                SAFEARRAY **pparray;
                VARIANT *pvarVal;
                PVOID byref;
                CHAR cVal;
                USHORT uiVal;
                ULONG ulVal;
                ULONGLONG ullVal;
                INT intVal;
                UINT uintVal;
                DECIMAL *pdecVal;
                CHAR *pcVal;
                USHORT *puiVal;
                ULONG *pulVal;
                ULONGLONG *pullVal;
                INT *pintVal;
                UINT *puintVal;
                struct __tagBRECORD
                    {
                    PVOID pvRecord;
                    IRecordInfo *pRecInfo;
                    } 	__VARIANT_NAME_4;
                } 	__VARIANT_NAME_3;
            } 	__VARIANT_NAME_2;
        DECIMAL decVal;
        } 	__VARIANT_NAME_1;
    } ;
typedef VARIANT *LPVARIANT;
*/

VARIANT UNION
	STRUCT
		vt VARTYPE
		wReserved1 DW
		wReserved2 DW
		wReserved3 DW
		UNION
			ullVal LONGLONG
			llVal LONGLONG
			lVal LONG
			bVal DB
			iVal SHORT
			fltVal FLOAT
			dblVal DOUBLE
			boolVal VARIANT_BOOL
			bool VARIANT_BOOL // Deprecated
			scode DD
			cyVal DQ
			date DATE
			bstrVal PTR
			punkVal PTR
			pdispVal PTR
			parray PTR
			pbVal PTR
			piVal PTR
			plVal PTR
			pllVal PTR
			pfltVal PTR
			pdblVal PTR
			pboolVal PTR
			pbool PTR // Deprecated
			pscode PTR
			pcyVal PTR
			pdate PTR
			pbstrVal PTR
			ppunkVal PTR
			ppdispVal PTR
			pparray PTR
			pvarVal PTR
			byref PTR
			cVal DB
			uiVal SHORT
			ulVal LONG
			intVal LONG
			uintVal LONG
			pdecVal PTR
			pcVal PTR
			puiVal PTR
			pulVal PTR
			pullVal PTR
			pintVal PTR
			puintVal PTR
			STRUCT
				pvRecord PTR
				pRecInfo PTR
			ENDS
		ENDS
	ENDS
	decVal DECIMAL
ENDS

#define VARIANTARG VARIANT

wireBRECORD STRUCT
	fFlags DD
	clSize DD
	pRecInfo PTR
	pRecord PTR
ENDS

wireSAFEARR_BSTR STRUCT
	Size LONG
	aBstr PTR
ENDS

wireSAFEARR_UNKNOWN STRUCT
	Size LONG
	apUnknown PTR
ENDS

wireSAFEARR_DISPATCH STRUCT
	Size LONG
	apDispatch PTR
ENDS

wireSAFEARR_VARIANT STRUCT
	Size LONG
	aVariant PTR
ENDS

wireSAFEARR_BRECORD STRUCT
	Size LONG
	aRecord PTR
ENDS

wireSAFEARR_HAVEIID STRUCT
	Size LONG
	apUnknown PTR
	iid GUID
ENDS

wireVARIANT STRUCT
	clSize DD
	rpcReserved DD
	vt SHORT
	wReserved1 SHORT
	wReserved2 SHORT
	wReserved3 SHORT
	UNION
		llVal LONGLONG
		lVal LONG
		bVal DB
		iVal SHORT
		fltVal FLOAT
		dblVal DOUBLE
		boolVal VARIANT_BOOL
		scode DD
		cyVal DQ
		date DATE
		bstrVal wireSAFEARR_BSTR
		punkVal PTR
		pdispVal PTR
		parray PTR
		brecVal wireBRECORD
		pbVal PTR
		piVal PTR
		plVal PTR
		pllVal PTR
		pfltVal PTR
		pdblVal PTR
		pboolVal PTR
		pscode PTR
		pcyVal PTR
		pdate PTR
		pbstrVal PTR
		ppunkVal PTR
		ppdispVal PTR
		pparray PTR
		pvarVal PTR
		cVal CHAR
		uiVal SHORT
		ulVal LONG
		ullVal LONGLONG
		intVal LONG
		uintVal LONG
		decVal DECIMAL
		pdecVal PTR
		pcVal PTR
		puiVal PTR
		pulVal PTR
		pullVal PTR
		pintVal PTR
		puintVal PTR
	ENDUNION
ENDS

TKIND_ENUM = 0
TKIND_RECORD = 1
TKIND_MODULE = 2
TKIND_INTERFACE = 3
TKIND_DISPATCH = 4
TKIND_COCLASS = 5
TKIND_ALIAS = 6
TKIND_UNION = 7
TKIND_MAX = 8

TYPEDESC STRUCT
	UNION
		lptdesc PTR
		lpadesc PTR
		hreftype HANDLE
	ENDUNION
	vt VARTYPE
ENDS

ARRAYDESC STRUCT
	tdescElem TYPEDESC
	cDims SHORT
	rgbounds SAFEARRAYBOUND
ENDS

PARAMDESCEX STRUCT
	cBytes DD
	varDefaultValue VARIANTARG
ENDS

PARAMDESC STRUCT
	pparamdescex PTR
	wParamFlags SHORT
ENDS

#define PARAMFLAG_NONE  0
#define PARAMFLAG_FIN  0x1
#define PARAMFLAG_FOUT  0x2
#define PARAMFLAG_FLCID  0x4
#define PARAMFLAG_FRETVAL  0x8
#define PARAMFLAG_FOPT  0x10
#define PARAMFLAG_FHASDEFAULT  0x20
#define PARAMFLAG_FHASCUSTDATA  0x40

IDLDESC STRUCT
	dwReserved ULONG_PTR
	wIDLFlags DW
ENDS

#define IDLFLAG_NONE  (PARAMFLAG_NONE)
#define IDLFLAG_FIN  (PARAMFLAG_FIN)
#define IDLFLAG_FOUT  (PARAMFLAG_FOUT)
#define IDLFLAG_FLCID  (PARAMFLAG_FLCID)
#define IDLFLAG_FRETVAL (PARAMFLAG_FRETVAL)

ELEMDESC STRUCT
	tdesc TYPEDESC
	UNION
		idldesc IDLDESC
		paramdesc PARAMDESC
	ENDUNION
ENDS

TYPEATTR STRUCT
	guid GUID
	lcid LCID
	dwReserved LONG
	memidConstructor DD
	memidDestructor DD
	lpstrSchema PTR
	cbSizeInstance LONG
	typekind DD
	cFuncs SHORT
	cVars SHORT
	cImplTypes SHORT
	cbSizeVft SHORT
	cbAlignment SHORT
	wTypeFlags SHORT
	wMajorVerNum SHORT
	wMinorVerNum SHORT
	tdescAlias TYPEDESC
	idldescType IDLDESC
ENDS

DISPPARAMS STRUCT
	rgvarg PTR
	rgdispidNamedArgs PTR
	cArgs DD
	cNamedArgs DD
ENDS

EXCEPINFO STRUCT
	wCode DW
	wReserved DW
	bstrSource PTR
	bstrDescription PTR
	bstrHelpFile PTR
	dwHelpContext DD
	pvReserved PTR
	pfnDeferredFillIn PTR
	scode DD
ENDS

#define CC_FASTCALL 0
#define CC_CDECL 1
#define CC_MSCPASCAL 2
#define CC_PASCAL 3
#define CC_MACPASCAL 4
#define CC_STDCALL 5
#define CC_FPFASTCALL 6
#define CC_SYSCALL 7
#define CC_MPWCDECL 8
#define CC_MPWPASCAL 9
#define CC_MAX 10

#define FUNC_VIRTUAL 0
#define FUNC_PUREVIRTUAL 1
#define FUNC_NONVIRTUAL 2
#define FUNC_STATIC 3
#define FUNC_DISPATCH 4

#define INVOKE_FUNC 1
#define INVOKE_PROPERTYGET 2
#define INVOKE_PROPERTYPUT 4
#define INVOKE_PROPERTYPUTREF 8

FUNCDESC STRUCT
	memid DD
	lprgscode PTR
	lprgelemdescParam PTR
	funckind DD
	invkind DD
	callconv DD
	cParams DW
	cParamsOpt DW
	oVft DW
	cScodes DW
	elemdescFunc ELEMDESC
	wFuncFlags DW
ENDS

VAR_PERINSTANCE = 0
VAR_STATIC = 1
VAR_CONST = 2
VAR_DISPATCH = 3

#define IMPLTYPEFLAG_FDEFAULT  0x1
#define IMPLTYPEFLAG_FSOURCE  0x2
#define IMPLTYPEFLAG_FRESTRICTED  0x4
#define IMPLTYPEFLAG_FDEFAULTVTABLE  0x8

VARDESC STRUCT
	memid DD
	lpstrSchema PTR
	    UNION
			oInst DD
			lpvarValue PTR
	    ENDUNION
	elemdescVar  ELEMDESC
	wVarFlags DW
	varkind DD
ENDS

#define TYPEFLAG_FAPPOBJECT 0x1 ; ENUM
#define TYPEFLAG_FCANCREATE 0x2
#define TYPEFLAG_FLICENSED 0x4
#define TYPEFLAG_FPREDECLID 0x8
#define TYPEFLAG_FHIDDEN 0x10
#define TYPEFLAG_FCONTROL 0x20
#define TYPEFLAG_FDUAL 0x40
#define TYPEFLAG_FNONEXTENSIBLE 0x80
#define TYPEFLAG_FOLEAUTOMATION 0x100
#define TYPEFLAG_FRESTRICTED 0x200
#define TYPEFLAG_FAGGREGATABLE 0x400
#define TYPEFLAG_FREPLACEABLE 0x800
#define TYPEFLAG_FDISPATCHABLE 0x1000
#define TYPEFLAG_FREVERSEBIND 0x2000
#define TYPEFLAG_FPROXY 0x4000

#define FUNCFLAG_FRESTRICTED 0x1 ; ENUM
#define FUNCFLAG_FSOURCE 0x2
#define FUNCFLAG_FBINDABLE 0x4
#define FUNCFLAG_FREQUESTEDIT 0x8
#define FUNCFLAG_FDISPLAYBIND 0x10
#define FUNCFLAG_FDEFAULTBIND 0x20
#define FUNCFLAG_FHIDDEN 0x40
#define FUNCFLAG_FUSESGETLASTERROR 0x80
#define FUNCFLAG_FDEFAULTCOLLELEM 0x100
#define FUNCFLAG_FUIDEFAULT 0x200
#define FUNCFLAG_FNONBROWSABLE 0x400
#define FUNCFLAG_FREPLACEABLE 0x800
#define FUNCFLAG_FIMMEDIATEBIND 0x1000

#define VARFLAG_FREADONLY 0x1 ; ENUM
#define VARFLAG_FSOURCE 0x2
#define VARFLAG_FBINDABLE 0x4
#define VARFLAG_FREQUESTEDIT 0x8
#define VARFLAG_FDISPLAYBIND 0x10
#define VARFLAG_FDEFAULTBIND 0x20
#define VARFLAG_FHIDDEN 0x40
#define VARFLAG_FRESTRICTED 0x80
#define VARFLAG_FDEFAULTCOLLELEM 0x100
#define VARFLAG_FUIDEFAULT 0x200
#define VARFLAG_FNONBROWSABLE 0x400
#define VARFLAG_FREPLACEABLE 0x800
#define VARFLAG_FIMMEDIATEBIND 0x1000

CLEANLOCALSTORAGE STRUCT
	pInterface PTR
	pStorage PTR
	flags DD
ENDS

CUSTDATAITEM STRUCT
	guid GUID
	varValue VARIANTARG
ENDS

CUSTDATA STRUCT
	cCustData DD
	prgCustData PTR
ENDS

#define GUID_IID_ICreateTypeInfo <0x00020405-0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
ICreateTypeInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetGuid PTR
	SetTypeFlags PTR
	SetDocString PTR
	SetHelpContext PTR
	SetVersion PTR
	AddRefTypeInfo PTR
	AddFuncDesc PTR
	AddImplType PTR
	SetImplTypeFlags PTR
	SetAlignment PTR
	SetSchema PTR
	AddVarDesc PTR
	SetFuncAndParamNames PTR
	SetVarName PTR
	SetTypeDescAlias PTR
	DefineFuncAsDllEntry PTR
	SetFuncDocString PTR
	SetVarDocString PTR
	SetFuncHelpContext PTR
	SetVarHelpContext PTR
	SetMops PTR
	SetTypeIdldesc PTR
	LayOut PTR
ENDS

#define GUID_IID_ICreateTypeInfo2 <0x0002040E,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
ICreateTypeInfo2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetGuid PTR
	SetTypeFlags PTR
	SetDocString PTR
	SetHelpContext PTR
	SetVersion PTR
	AddRefTypeInfo PTR
	AddFuncDesc PTR
	AddImplType PTR
	SetImplTypeFlags PTR
	SetAlignment PTR
	SetSchema PTR
	AddVarDesc PTR
	SetFuncAndParamNames PTR
	SetVarName PTR
	SetTypeDescAlias PTR
	DefineFuncAsDllEntry PTR
	SetFuncDocString PTR
	SetVarDocString PTR
	SetFuncHelpContext PTR
	SetVarHelpContext PTR
	SetMops PTR
	SetTypeIdldesc PTR
	LayOut PTR
	DeleteFuncDesc PTR
	DeleteFuncDescByMemId PTR
	DeleteVarDesc PTR
	DeleteVarDescByMemId PTR
	DeleteImplType PTR
	SetCustData PTR
	SetFuncCustData PTR
	SetParamCustData PTR
	SetVarCustData PTR
	SetImplTypeCustData PTR
	SetHelpStringContext PTR
	SetFuncHelpStringContext PTR
	SetVarHelpStringContext PTR
	Invalidate PTR
	SetName PTR
ENDS

#define GUID_IID_ICreateTypeLib <0x00020406,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
ICreateTypeLib STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateTypeInfo PTR
	SetName PTR
	SetVersion PTR
	SetGuid PTR
	SetDocString PTR
	SetHelpFileName PTR
	SetHelpContext PTR
	SetLcid PTR
	SetLibFlags PTR
	SaveAllChanges PTR
ENDS

#define GUID_IID_ICreateTypeLib2 <0x0002040F,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
ICreateTypeLib2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateTypeInfo PTR
	SetName PTR
	SetVersion PTR
	SetGuid PTR
	SetDocString PTR
	SetHelpFileName PTR
	SetHelpContext PTR
	SetLcid PTR
	SetLibFlags PTR
	SaveAllChanges PTR
	DeleteTypeInfo PTR
	SetCustData PTR
	SetHelpStringContext PTR
	SetHelpStringDll PTR
ENDS

#define DISPID_UNKNOWN  (-1)
#define DISPID_VALUE  (0)
#define DISPID_PROPERTYPUT  (-3)
#define DISPID_NEWENUM  (-4)
#define DISPID_EVALUATE  (-5)
#define DISPID_CONSTRUCTOR  (-6)
#define DISPID_DESTRUCTOR  (-7)
#define DISPID_COLLECT  (-8)

#define GUID_IID_IEnumVARIANT <0x00020404,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IEnumVARIANT STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Next PTR
	Skip PTR
	Reset PTR
	Clone PTR
ENDS

DESCKIND_NONE = 0
DESCKIND_FUNCDESC = 1
DESCKIND_VARDESC = 2
DESCKIND_TYPECOMP = 3
DESCKIND_IMPLICITAPPOBJ = 4
DESCKIND_MAX = 5

BINDPTR UNION
	lpfuncdesc PTR
	lpvardesc PTR
	lptcomp PTR
ENDUNION

#define GUID_IID_ITypeComp <0x00020403,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
ITypeComp STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ITypeComp PTR
	ITypeComp PTR
ENDS

#define GUID_IID_ITypeInfo <0x00020401,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
ITypeInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetTypeAttr PTR
	GetTypeComp PTR
	GetFuncDesc PTR
	GetVarDesc PTR
	GetNames PTR
	GetRefTypeOfImplType PTR
	GetImplTypeFlags PTR
	GetIDsOfNames PTR
	Invoke PTR
	GetDocumentation PTR
	GetDllEntry PTR
	GetRefTypeInfo PTR
	AddressOfMember PTR
	CreateInstance PTR
	GetMops PTR
	GetContainingTypeLib PTR
	ReleaseTypeAttr PTR
	ReleaseFuncDesc PTR
	ReleaseVarDesc PTR
ENDS

#define GUID_IID_ITypeInfo2 <0x00020412,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
ITypeInfo2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetTypeAttr PTR
	GetTypeComp PTR
	GetFuncDesc PTR
	GetVarDesc PTR
	GetNames PTR
	GetRefTypeOfImplType PTR
	GetImplTypeFlags PTR
	GetIDsOfNames PTR
	Invoke PTR
	GetDocumentation PTR
	GetDllEntry PTR
	GetRefTypeInfo PTR
	AddressOfMember PTR
	CreateInstance PTR
	GetMops PTR
	GetContainingTypeLib PTR
	ReleaseTypeAttr PTR
	ReleaseFuncDesc PTR
	ReleaseVarDesc PTR
	GetTypeKind PTR
	GetTypeFlags PTR
	GetFuncIndexOfMemId PTR
	GetVarIndexOfMemId PTR
	GetCustData PTR
	GetFuncCustData PTR
	GetParamCustData PTR
	GetVarCustData PTR
	GetImplTypeCustData PTR
	GetDocumentation2 PTR
	GetAllCustData PTR
	GetAllFuncCustData PTR
	GetAllParamCustData PTR
	GetAllVarCustData PTR
	GetAllImplTypeCustData PTR
ENDS

SYS_WIN16 = 0
SYS_WIN32 = 1
SYS_MAC = 2
SYS_WIN64 = 3

LIBFLAG_FRESTRICTED = 0x1
LIBFLAG_FCONTROL = 0x2
LIBFLAG_FHIDDEN = 0x4
LIBFLAG_FHASDISKIMAGE = 0x8

TLIBATTR STRUCT
	guid GUID
	lcid LCID
	syskind DD
	wMajorVerNum DW
	wMinorVerNum DW
	wLibFlags DW
ENDS

#Define GUID_IID_ITypeLib <0x00020402,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
ITypeLib STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetTypeInfoCount PTR
	GetTypeInfo PTR
	GetTypeInfoType PTR
	GetTypeInfoOfGuid PTR
	GetLibAttr PTR
	GetTypeComp PTR
	GetDocumentation PTR
	IsName PTR
	FindName PTR
	ReleaseTLibAttr PTR
ENDS

#Define GUID_IID_ITypeLib2 <0x00020411,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
ITypeLib2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetTypeInfoCount PTR
	GetTypeInfo PTR
	GetTypeInfoType PTR
	GetTypeInfoOfGuid PTR
	GetLibAttr PTR
	GetTypeComp PTR
	GetDocumentation PTR
	IsName PTR
	FindName PTR
	ReleaseTLibAttr PTR
	GetCustData PTR
	GetLibStatistics PTR
	GetDocumentation2 PTR
	GetAllCustData PTR
ENDS

CHANGEKIND_ADDMEMBER = 0
CHANGEKIND_DELETEMEMBER = 1
CHANGEKIND_SETNAMES = 2
CHANGEKIND_SETDOCUMENTATION = 3
CHANGEKIND_GENERAL = 4
CHANGEKIND_INVALIDATE = 5
CHANGEKIND_CHANGEFAILED = 6
CHANGEKIND_MAX = 7

#Define GUID_IID_ITypeChangeEvents <0x00020410,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
ITypeChangeEvents STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	RequestTypeChange PTR
	AfterTypeChange PTR
ENDS

#Define GUID_IID_IErrorInfo <0x1CF2B120,0x547D,0x101B,<0x8E,0x65,0x08,0x00,0x2B,0x2B,0xD1,0x19>>
IErrorInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetGUID PTR
	GetSource PTR
	GetDescription PTR
	GetHelpFile PTR
	GetHelpContext PTR
ENDS

#Define GUID_IID_ICreateErrorInfo <0x22F03340,0x547D,0x101B,<0x8E,0x65,0x08,0x00,0x2B,0x2B,0xD1,0x19>>
ICreateErrorInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetGUID PTR
	SetSource PTR
	SetDescription PTR
	SetHelpFile PTR
	SetHelpContext PTR
ENDS

#Define GUID_IID_ISupportErrorInfo <0xDF0B3D60,0x548F,0x101B,<0x8E,0x65,0x08,0x00,0x2B,0x2B,0xD1,0x19>>
ISupportErrorInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	InterfaceSupportsErrorInfo PTR
ENDS

#Define GUID_IID_ITypeFactory <0x0000002E,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
ITypeFactory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateFromTypeInfo PTR
ENDS

#Define GUID_IID_ITypeMarshal <0x0000002D,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
ITypeMarshal STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Size PTR
	Marshal PTR
	Unmarshal PTR
	Free PTR
ENDS

#Define GUID_IID_IRecordInfo <0x0000002F,0x0000,0x0000,<0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46>>
IRecordInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	RecordInit PTR
	RecordClear PTR
	RecordCopy PTR
	GetGuid PTR
	GetName PTR
	GetSize PTR
	GetTypeInfo PTR
	GetField PTR
	GetFieldNoCopy PTR
	PutField PTR
	PutFieldNoCopy PTR
	GetFieldNames PTR
	IsMatchingType PTR
	RecordCreate PTR
	RecordCreateCopy PTR
	RecordDestroy PTR
ENDS

#Define GUID_IID_IErrorLog <0x3127CA40,0x446E,0x11CE,<0x81,0x35,0x00,0xAA,0x00,0x4B,0xB8,0x51>>
IErrorLog STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddError PTR
ENDS

#Define GUID_IID_IPropertyBag <0x55272A00,0x42CB,0x11CE,<0x81,0x35,0x00,0xAA,0x00,0x4B,0xB8,0x51>>
IPropertyBag STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Read PTR
	Write PTR
ENDS

#endif /* _OAIDL_H */
