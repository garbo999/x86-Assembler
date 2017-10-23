/* Microsoft Corporation Copyright 1999 */
/* this ALWAYS GENERATED file contains the definitions for the interfaces */

#IFNDEF DHTMLED_H
#DEFINE DHTMLED_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF

#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#IFNDEF OAIDL_H
	#Include "oaidl.h"
#ENDIF

#IFNDEF OCIDL_H
	#Include "ocidl.h"
#ENDIF

#IFNDEF DOCOBJ_H
	#Include "docobj.h"
#ENDIF

#IFNDEF WINERROR_H
	#Include "winerror.h"
#ENDIF


#IFNDEF DHTMLDID_H
	#include "DHtmldid.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define DE_E_INVALIDARG                E_INVALIDARG
#define DE_E_PATH_NOT_FOUND            ERROR_PATH_NOT_FOUND
#define DE_E_FILE_NOT_FOUND            ERROR_FILE_NOT_FOUND
#define DE_E_UNEXPECTED                E_UNEXPECTED
#define DE_E_DISK_FULL                 ERROR_HANDLE_DISK_FULL
#define DE_E_NOTSUPPORTED              OLECMDERR_E_NOTSUPPORTED
#define DE_E_ACCESS_DENIED             ERROR_ACCESS_DENIED

#define DE_E_URL_SYNTAX                MK_E_SYNTAX
#define DE_E_INVALID_URL               0x800C0002
#define DE_E_NO_SESSION                0x800C0003
#define DE_E_CANNOT_CONNECT            0x800C0004
#define DE_E_RESOURCE_NOT_FOUND        0x800C0005
#define DE_E_OBJECT_NOT_FOUND          0x800C0006
#define DE_E_DATA_NOT_AVAILABLE        0x800C0007
#define DE_E_DOWNLOAD_FAILURE          0x800C0008
#define DE_E_AUTHENTICATION_REQUIRED   0x800C0009
#define DE_E_NO_VALID_MEDIA            0x800C000A
#define DE_E_CONNECTION_TIMEOUT        0x800C000B
#define DE_E_INVALID_REQUEST           0x800C000C
#define DE_E_UNKNOWN_PROTOCOL          0x800C000D
#define DE_E_SECURITY_PROBLEM          0x800C000E
#define DE_E_CANNOT_LOAD_DATA          0x800C000F
#define DE_E_CANNOT_INSTANTIATE_OBJECT 0x800C0010
#define DE_E_REDIRECT_FAILED           0x800C0014
#define DE_E_REDIRECT_TO_DIR           0x800C0015
#define DE_E_CANNOT_LOCK_REQUEST       0x800C0016

#define DE_E_FILTER_FRAMESET           0x80100001
#define DE_E_FILTER_SERVERSCRIPT       0x80100002
#define DE_E_FILTER_MULTIPLETAGS       0x80100004
#define DE_E_FILTER_SCRIPTLISTING      0x80100008
#define DE_E_FILTER_SCRIPTLABEL        0x80100010
#define DE_E_FILTER_SCRIPTTEXTAREA     0x80100020
#define DE_E_FILTER_SCRIPTSELECT       0x80100040

DECMD_BOLD	EQU 5000 
DECMD_COPY	EQU 5002 
DECMD_CUT	EQU 5003
DECMD_DELETE	EQU 5004
DECMD_DELETECELLS	EQU 5005
DECMD_DELETECOLS	EQU 5006
DECMD_DELETEROWS	EQU 5007
DECMD_FINDTEXT	EQU 5008
DECMD_FONT	EQU 5009
DECMD_GETBACKCOLOR	EQU 5010
DECMD_GETBLOCKFMT	EQU 5011
DECMD_GETBLOCKFMTNAMES	EQU 5012
DECMD_GETFONTNAME	EQU 5013
DECMD_GETFONTSIZE	EQU 5014
DECMD_GETFORECOLOR	EQU 5015
DECMD_HYPERLINK	EQU 5016
DECMD_IMAGE	EQU 5017
DECMD_INDENT	EQU 5018
DECMD_INSERTCELL	EQU 5019
DECMD_INSERTCOL	EQU 5020
DECMD_INSERTROW	EQU 5021
DECMD_INSERTTABLE	EQU 5022
DECMD_ITALIC	EQU 5023
DECMD_JUSTIFYCENTER	EQU 5024
DECMD_JUSTIFYLEFT	EQU 5025
DECMD_JUSTIFYRIGHT	EQU 5026
DECMD_LOCK_ELEMENT	EQU 5027
DECMD_MAKE_ABSOLUTE	EQU 5028
DECMD_MERGECELLS	EQU 5029
DECMD_ORDERLIST	EQU 5030
DECMD_OUTDENT	EQU 5031
DECMD_PASTE	EQU 5032
DECMD_REDO	EQU 5033
DECMD_REMOVEFORMAT	EQU 5034
DECMD_SELECTALL	EQU 5035
DECMD_SEND_BACKWARD	EQU 5036
DECMD_BRING_FORWARD	EQU 5037
DECMD_SEND_BELOW_TEXT	EQU 5038
DECMD_BRING_ABOVE_TEXT	EQU 5039
DECMD_SEND_TO_BACK	EQU 5040
DECMD_BRING_TO_FRONT	EQU 5041
DECMD_SETBACKCOLOR	EQU 5042
DECMD_SETBLOCKFMT	EQU 5043
DECMD_SETFONTNAME	EQU 5044
DECMD_SETFONTSIZE	EQU 5045
DECMD_SETFORECOLOR	EQU 5046
DECMD_SPLITCELL	EQU 5047
DECMD_UNDERLINE	EQU 5048
DECMD_UNDO	EQU 5049
DECMD_UNLINK	EQU 5050
DECMD_UNORDERLIST	EQU 5051
DECMD_PROPERTIES	EQU 5052

DECMDF_NOTSUPPORTED	= 0,
DECMDF_DISABLED	= 0x1
DECMDF_ENABLED	= 0x3
DECMDF_LATCHED	= 0x7
DECMDF_NINCHED	= 0xb

DEAPPEARANCE_FLAT	= 0
DEAPPEARANCE_3D	= 0x1

#DEFINE GUID_IID_IDEGetBlockFmtNamesParam <0x8D91090D,0xB955,0x11D1,<0xAD,0xC5,0x00,0x60,0x08,0xA5,0x84,0x8C>>

IDEGetBlockFmtNamesParam STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Names DD
	put_Names DD
ENDS

#DEFINE GUID_IID_IDHTMLSafe <0xCE04B590,0x2B1F,0x11d2,<0x8D,0x1E,0x00,0xA0,0xC9,0x59,0xBC,0x0A>>

IDHTMLSafe STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	ExecCommand PTR
	QueryStatus PTR
	SetContextMenu PTR
	NewDocument PTR
	LoadURL PTR
	FilterSourceCode PTR
	Refresh PTR
	get_DOM PTR
	get_DocumentHTML PTR
	put_DocumentHTML PTR
	get_ActivateApplets PTR
	put_ActivateApplets PTR
	get_ActivateActiveXControls PTR
	put_ActivateActiveXControls PTR
	get_ActivateDTCs PTR
	put_ActivateDTCs PTR
	get_ShowDetails PTR
	put_ShowDetails PTR
	get_ShowBorders PTR
	put_ShowBorders PTR
	get_Appearance PTR
	put_Appearance PTR
	get_Scrollbars PTR
	put_Scrollbars PTR
	get_ScrollbarAppearance PTR
	put_ScrollbarAppearance PTR
	get_SourceCodePreservation PTR
	put_SourceCodePreservation PTR
	get_AbsoluteDropMode PTR
	put_AbsoluteDropMode PTR
	get_SnapToGridX PTR
	put_SnapToGridX PTR
	get_SnapToGridY PTR
	put_SnapToGridY PTR
	get_SnapToGrid PTR
	put_SnapToGrid PTR
	get_IsDirty PTR
	get_CurrentDocumentPath PTR
	get_BaseURL PTR
	put_BaseURL PTR
	get_DocumentTitle PTR
	get_UseDivOnCarriageReturn PTR
	put_UseDivOnCarriageReturn PTR
	get_Busy PTR
ENDS


#DEFINE GUID_IID_IDHTMLEdit <0xCE04B591,0x2B1F,0x11d2,<0x8D,0x1E,0x00,0xA0,0xC9,0x59,0xBC,0x0A>>

IDHTMLEdit STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	ExecCommand PTR
	QueryStatus PTR
	SetContextMenu PTR
	NewDocument PTR
	LoadURL PTR
	FilterSourceCode PTR
	Refresh PTR
	get_DOM PTR
	get_DocumentHTML PTR
	put_DocumentHTML PTR
	get_ActivateApplets PTR
	put_ActivateApplets PTR
	get_ActivateActiveXControls PTR
	put_ActivateActiveXControls PTR
	get_ActivateDTCs PTR
	put_ActivateDTCs PTR
	get_ShowDetails PTR
	put_ShowDetails PTR
	get_ShowBorders PTR
	put_ShowBorders PTR
	get_Appearance PTR
	put_Appearance PTR
	get_Scrollbars PTR
	put_Scrollbars PTR
	get_ScrollbarAppearance PTR
	put_ScrollbarAppearance PTR
	get_SourceCodePreservation PTR
	put_SourceCodePreservation PTR
	get_AbsoluteDropMode PTR
	put_AbsoluteDropMode PTR
	get_SnapToGridX PTR
	put_SnapToGridX PTR
	get_SnapToGridY PTR
	put_SnapToGridY PTR
	get_SnapToGrid PTR
	put_SnapToGrid PTR
	get_IsDirty PTR
	get_CurrentDocumentPath PTR
	get_BaseURL PTR
	put_BaseURL PTR
	get_DocumentTitle PTR
	get_UseDivOnCarriageReturn PTR
	put_UseDivOnCarriageReturn PTR
	get_Busy PTR

	LoadDocument PTR
	SaveDocument PTR
	PrintDocument PTR
	get_BrowseMode PTR
	put_BrowseMode PTR
ENDS

#DEFINE GUID_IID_IDEInsertTableParam <0x47B0DFC6,0xB7A3,0x11D1,<0xAD,0xC5,0x00,0x60,0x08,0xA5,0x84,0x8C>>

IDEInsertTableParam STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_NumRows PTR
	put_NumRows PTR
	get_NumCols PTR
	put_NumCols PTR
	get_TableAttrs PTR
	put_TableAttrs PTR
	get_CellAttrs PTR
	put_CellAttrs PTR
	get_Caption PTR
	put_Caption PTR
ENDS


#DEFINE GUID_DIID__DHTMLSafeEvents <0xD1FC78E8,0xB380,0x11d1,<0xAD,0xC5,0x00,0x60,0x08,0xA5,0x84,0x8C>>

_DHTMLSafeEvents STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
ENDS


#DEFINE GUID_DIID__DHTMLEditEvents <0x588D5040,0xCF28,0x11d1,<0x8C,0xD3,0x00,0xA0,0xC9,0x59,0xBC,0x0A>>

_DHTMLEditEvents STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
ENDS

#DEFINE GUID_CLSID_DHTMLEdit <0x2D360200,0xFFF5,0x11d1,<0x8D,0x03,0x00,0xA0,0xC9,0x59,0xBC,0x0A>>
#DEFINE GUID_CLSID CLSID_DHTMLSafe <0x2D360201,0xFFF5,0x11d1,<0x8D,0x03,0x00,0xA0,0xC9,0x59,0xBC,0x0A>>
#DEFINE GUID_CLSID CLSID_DEInsertTableParam <0x47B0DFC7,0xB7A3,0x11D1,<0xAD,0xC5,0x00,0x60,0x08,0xA5,0x84,0x8C>>
#DEFINE GUID_CLSID_DEGetBlockFmtNamesParam <0x8D91090E,0xB955,0x11D1,<0xAD,0xC5,0x00,0x60,0x08,0xA5,0x84,0x8C>>

#endif
