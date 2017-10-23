#ifndef OLEDLG_H
#define OLEDLG_H

#IFNDEF WINDOWS_H
	#include windows.h
#ENDIF

#IFNDEF SHELLAPI_H
	#include shellapi.h
#ENDIF

#IFNDEF COMMDLG_H
	#include commdlg.h
#ENDIF

#IFNDEF OLE2_H
	#include ole2.h
#ENDIF

#IFNDEF DLGS_H
	#include dlgs.h
#ENDIF

#IFNDEF PRSHT_H
	#include prsht.h
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define IDC_OLEUIHELP  99

#define IDC_IO_CREATENEW  2100
#define IDC_IO_CREATEFROMFILE  2101
#define IDC_IO_LINKFILE  2102
#define IDC_IO_OBJECTTYPELIST  2103
#define IDC_IO_DISPLAYASICON  2104
#define IDC_IO_CHANGEICON  2105
#define IDC_IO_FILE  2106
#define IDC_IO_FILEDISPLAY  2107
#define IDC_IO_RESULTIMAGE  2108
#define IDC_IO_RESULTTEXT  2109
#define IDC_IO_ICONDISPLAY  2110
#define IDC_IO_OBJECTTYPETEXT  2111
#define IDC_IO_FILETEXT  2112
#define IDC_IO_FILETYPE  2113
#define IDC_IO_INSERTCONTROL  2114
#define IDC_IO_ADDCONTROL  2115
#define IDC_IO_CONTROLTYPELIST  2116

#define IDC_PS_PASTE  500
#define IDC_PS_PASTELINK  501
#define IDC_PS_SOURCETEXT  502
#define IDC_PS_PASTELIST  503
#define IDC_PS_PASTELINKLIST  504
#define IDC_PS_DISPLAYLIST  505
#define IDC_PS_DISPLAYASICON  506
#define IDC_PS_ICONDISPLAY  507
#define IDC_PS_CHANGEICON  508
#define IDC_PS_RESULTIMAGE  509
#define IDC_PS_RESULTTEXT  510

#define IDC_CI_GROUP  120
#define IDC_CI_CURRENT  121
#define IDC_CI_CURRENTICON  122
#define IDC_CI_DEFAULT  123
#define IDC_CI_DEFAULTICON  124
#define IDC_CI_FROMFILE  125
#define IDC_CI_FROMFILEEDIT  126
#define IDC_CI_ICONLIST  127
#define IDC_CI_LABEL  128
#define IDC_CI_LABELEDIT  129
#define IDC_CI_BROWSE  130
#define IDC_CI_ICONDISPLAY  131

#define IDC_CV_OBJECTTYPE  150
#define IDC_CV_DISPLAYASICON  152
#define IDC_CV_CHANGEICON  153
#define IDC_CV_ACTIVATELIST  154
#define IDC_CV_CONVERTTO  155
#define IDC_CV_ACTIVATEAS  156
#define IDC_CV_RESULTTEXT  157
#define IDC_CV_CONVERTLIST  158
#define IDC_CV_ICONDISPLAY  165

#define IDC_EL_CHANGESOURCE  201
#define IDC_EL_AUTOMATIC  202
#define IDC_EL_CANCELLINK  209
#define IDC_EL_UPDATENOW  210
#define IDC_EL_OPENSOURCE  211
#define IDC_EL_MANUAL  212
#define IDC_EL_LINKSOURCE  216
#define IDC_EL_LINKTYPE  217
#define IDC_EL_LINKSLISTBOX  206
#define IDC_EL_COL1  220
#define IDC_EL_COL2  221
#define IDC_EL_COL3  222

#define IDC_BZ_RETRY  600
#define IDC_BZ_ICON  601
#define IDC_BZ_MESSAGE1  602
#define IDC_BZ_SWITCHTO  604

#define IDC_UL_METER  1029
#define IDC_UL_STOP  1030
#define IDC_UL_PERCENT  1031
#define IDC_UL_PROGRESS  1032

#define IDC_PU_LINKS  900
#define IDC_PU_TEXT  901
#define IDC_PU_CONVERT  902
#define IDC_PU_ICON  908

#define IDC_GP_OBJECTNAME  1009
#define IDC_GP_OBJECTTYPE  1010
#define IDC_GP_OBJECTSIZE  1011
#define IDC_GP_CONVERT  1013
#define IDC_GP_OBJECTICON  1014
#define IDC_GP_OBJECTLOCATION  1022

#define IDC_VP_PERCENT  1000
#define IDC_VP_CHANGEICON  1001
#define IDC_VP_EDITABLE  1002
#define IDC_VP_ASICON  1003
#define IDC_VP_RELATIVE  1005
#define IDC_VP_SPIN  1006
#define IDC_VP_SCALETXT  1034
#define IDC_VP_ICONDISPLAY  1021
#define IDC_VP_RESULTIMAGE  1033

#define IDC_LP_OPENSOURCE  1006
#define IDC_LP_UPDATENOW  1007
#define IDC_LP_BREAKLINK  1008
#define IDC_LP_LINKSOURCE  1012
#define IDC_LP_CHANGESOURCE  1015
#define IDC_LP_AUTOMATIC  1016
#define IDC_LP_MANUAL  1017
#define IDC_LP_DATE  1018
#define IDC_LP_TIME  1019

#define IDD_INSERTOBJECT  1000
#define IDD_CHANGEICON  1001
#define IDD_CONVERT  1002
#define IDD_PASTESPECIAL  1003
#define IDD_EDITLINKS  1004
#define IDD_BUSY  1006
#define IDD_UPDATELINKS  1007
#define IDD_CHANGESOURCE  1009
#define IDD_INSERTFILEBROWSE  1010
#define IDD_CHANGEICONBROWSE  1011
#define IDD_CONVERTONLY  1012
#define IDD_CHANGESOURCE4  1013
#define IDD_GNRLPROPS  1100
#define IDD_VIEWPROPS  1101
#define IDD_LINKPROPS  1102
#define IDD_CONVERT4  1103
#define IDD_CONVERTONLY4  1104
#define IDD_EDITLINKS4  1105
#define IDD_GNRLPROPS4  1106
#define IDD_LINKPROPS4  1107
#define IDD_PASTESPECIAL4  1108

#define IDD_CANNOTUPDATELINK  1008
#define IDD_LINKSOURCEUNAVAILABLE  1020
#define IDD_SERVERNOTFOUND  1023
#define IDD_OUTOFMEMORY  1024
#define IDD_SERVERNOTREGW  1021
#define IDD_LINKTYPECHANGEDW  1022
#define IDD_SERVERNOTREGA  1025
#define IDD_LINKTYPECHANGEDA  1026

#define OLESTDDELIM "\"

#define SZOLEUI_MSG_HELP  "OLEUI_MSG_HELP"
#define SZOLEUI_MSG_ENDDIALOG  "OLEUI_MSG_ENDDIALOG"
#define SZOLEUI_MSG_BROWSE  "OLEUI_MSG_BROWSE"
#define SZOLEUI_MSG_CHANGEICON  "OLEUI_MSG_CHANGEICON"
#define SZOLEUI_MSG_CLOSEBUSYDIALOG  "OLEUI_MSG_CLOSEBUSYDIALOG"
#define SZOLEUI_MSG_CONVERT  "OLEUI_MSG_CONVERT"
#define SZOLEUI_MSG_CHANGESOURCE  "OLEUI_MSG_CHANGESOURCE"
#define SZOLEUI_MSG_ADDCONTROL  "OLEUI_MSG_ADDCONTROL"
#define SZOLEUI_MSG_BROWSE_OFN  "OLEUI_MSG_BROWSE_OFN"

#define PROP_HWND_CHGICONDLG  "HWND_CIDLG"

#define ID_BROWSE_CHANGEICON  1
#define ID_BROWSE_INSERTFILE  2
#define ID_BROWSE_ADDCONTROL  3
#define ID_BROWSE_CHANGESOURCE  4

#define OLEUI_FALSE  0
#define OLEUI_SUCCESS  1
#define OLEUI_OK  1
#define OLEUI_CANCEL  2

#define OLEUI_ERR_STANDARDMIN  100
#define OLEUI_ERR_OLEMEMALLOC  100
#define OLEUI_ERR_STRUCTURENULL  101
#define OLEUI_ERR_STRUCTUREINVALID  102
#define OLEUI_ERR_CBSTRUCTINCORRECT  103
#define OLEUI_ERR_HWNDOWNERINVALID  104
#define OLEUI_ERR_LPSZCAPTIONINVALID  105
#define OLEUI_ERR_LPFNHOOKINVALID  106
#define OLEUI_ERR_HINSTANCEINVALID  107
#define OLEUI_ERR_LPSZTEMPLATEINVALID  108
#define OLEUI_ERR_HRESOURCEINVALID  109
#define OLEUI_ERR_FINDTEMPLATEFAILURE  110
#define OLEUI_ERR_LOADTEMPLATEFAILURE  111
#define OLEUI_ERR_DIALOGFAILURE  112
#define OLEUI_ERR_LOCALMEMALLOC  113
#define OLEUI_ERR_GLOBALMEMALLOC  114
#define OLEUI_ERR_LOADSTRING  115
#define OLEUI_ERR_STANDARDMAX  116

#define OLEUI_IOERR_LPSZFILEINVALID  OLEUI_ERR_STANDARDMAX+0
#define OLEUI_IOERR_LPSZLABELINVALID  OLEUI_ERR_STANDARDMAX+1
#define OLEUI_IOERR_HICONINVALID  OLEUI_ERR_STANDARDMAX+2
#define OLEUI_IOERR_LPFORMATETCINVALID  OLEUI_ERR_STANDARDMAX+3
#define OLEUI_IOERR_PPVOBJINVALID  OLEUI_ERR_STANDARDMAX+4
#define OLEUI_IOERR_LPIOLECLIENTSITEINVALID  OLEUI_ERR_STANDARDMAX+5
#define OLEUI_IOERR_LPISTORAGEINVALID  OLEUI_ERR_STANDARDMAX+6
#define OLEUI_IOERR_SCODEHASERROR  OLEUI_ERR_STANDARDMAX+7
#define OLEUI_IOERR_LPCLSIDEXCLUDEINVALID  OLEUI_ERR_STANDARDMAX+8
#define OLEUI_IOERR_CCHFILEINVALID  OLEUI_ERR_STANDARDMAX+9
#define OLEUI_IOERR_SRCDATAOBJECTINVALID  OLEUI_ERR_STANDARDMAX+0
#define OLEUI_IOERR_ARRPASTEENTRIESINVALID  OLEUI_ERR_STANDARDMAX+1
#define OLEUI_IOERR_ARRLINKTYPESINVALID  OLEUI_ERR_STANDARDMAX+2
#define OLEUI_PSERR_CLIPBOARDCHANGED  OLEUI_ERR_STANDARDMAX+3
#define OLEUI_PSERR_GETCLIPBOARDFAILED  OLEUI_ERR_STANDARDMAX+4
#define OLEUI_ELERR_LINKCNTRNULL  OLEUI_ERR_STANDARDMAX+0
#define OLEUI_ELERR_LINKCNTRINVALID  OLEUI_ERR_STANDARDMAX+1
#define OLEUI_CIERR_MUSTHAVECLSID  OLEUI_ERR_STANDARDMAX+0
#define OLEUI_CIERR_MUSTHAVECURRENTMETAFILE  OLEUI_ERR_STANDARDMAX+1
#define OLEUI_CIERR_SZICONEXEINVALID  OLEUI_ERR_STANDARDMAX+2
#define OLEUI_CTERR_CLASSIDINVALID  OLEUI_ERR_STANDARDMAX+1
#define OLEUI_CTERR_DVASPECTINVALID  OLEUI_ERR_STANDARDMAX+2
#define OLEUI_CTERR_CBFORMATINVALID  OLEUI_ERR_STANDARDMAX+3
#define OLEUI_CTERR_HMETAPICTINVALID  OLEUI_ERR_STANDARDMAX+4
#define OLEUI_CTERR_STRINGINVALID  OLEUI_ERR_STANDARDMAX+5
#define OLEUI_BZERR_HTASKINVALID  OLEUI_ERR_STANDARDMAX+0
#define OLEUI_BZ_SWITCHTOSELECTED  OLEUI_ERR_STANDARDMAX+1
#define OLEUI_BZ_RETRYSELECTED  OLEUI_ERR_STANDARDMAX+2
#define OLEUI_BZ_CALLUNBLOCKED  OLEUI_ERR_STANDARDMAX+3
#define OLEUI_CSERR_LINKCNTRNULL  OLEUI_ERR_STANDARDMAX+0
#define OLEUI_CSERR_LINKCNTRINVALID  OLEUI_ERR_STANDARDMAX+1
#define OLEUI_CSERR_FROMNOTNULL  OLEUI_ERR_STANDARDMAX+2
#define OLEUI_CSERR_TONOTNULL  OLEUI_ERR_STANDARDMAX+3
#define OLEUI_CSERR_SOURCENULL  OLEUI_ERR_STANDARDMAX+4
#define OLEUI_CSERR_SOURCEINVALID  OLEUI_ERR_STANDARDMAX+5
#define OLEUI_CSERR_SOURCEPARSERROR  OLEUI_ERR_STANDARDMAX+6
#define OLEUI_CSERR_SOURCEPARSEERROR  OLEUI_ERR_STANDARDMAX+6
#define OLEUI_OPERR_SUBPROPNULL  OLEUI_ERR_STANDARDMAX+0
#define OLEUI_OPERR_SUBPROPINVALID  OLEUI_ERR_STANDARDMAX+1
#define OLEUI_OPERR_PROPSHEETNULL  OLEUI_ERR_STANDARDMAX+2
#define OLEUI_OPERR_PROPSHEETINVALID  OLEUI_ERR_STANDARDMAX+3
#define OLEUI_OPERR_SUPPROP  OLEUI_ERR_STANDARDMAX+4
#define OLEUI_OPERR_PROPSINVALID  OLEUI_ERR_STANDARDMAX+5
#define OLEUI_OPERR_PAGESINCORRECT  OLEUI_ERR_STANDARDMAX+6
#define OLEUI_OPERR_INVALIDPAGES  OLEUI_ERR_STANDARDMAX+7
#define OLEUI_OPERR_NOTSUPPORTED  OLEUI_ERR_STANDARDMAX+8
#define OLEUI_OPERR_DLGPROCNOTNULL  OLEUI_ERR_STANDARDMAX+9
#define OLEUI_OPERR_LPARAMNOTZERO  OLEUI_ERR_STANDARDMAX+10
#define OLEUI_GPERR_STRINGINVALID  OLEUI_ERR_STANDARDMAX+11
#define OLEUI_GPERR_CLASSIDINVALID  OLEUI_ERR_STANDARDMAX+12
#define OLEUI_GPERR_LPCLSIDEXCLUDEINVALID  OLEUI_ERR_STANDARDMAX+13
#define OLEUI_GPERR_CBFORMATINVALID  OLEUI_ERR_STANDARDMAX+14
#define OLEUI_VPERR_METAPICTINVALID  OLEUI_ERR_STANDARDMAX+15
#define OLEUI_VPERR_DVASPECTINVALID  OLEUI_ERR_STANDARDMAX+16
#define OLEUI_LPERR_LINKCNTRNULL  OLEUI_ERR_STANDARDMAX+17
#define OLEUI_LPERR_LINKCNTRINVALID  OLEUI_ERR_STANDARDMAX+18
#define OLEUI_OPERR_PROPERTYSHEET  OLEUI_ERR_STANDARDMAX+19
#define OLEUI_OPERR_OBJINFOINVALID  OLEUI_ERR_STANDARDMAX+20
#define OLEUI_OPERR_LINKINFOINVALID  OLEUI_ERR_STANDARDMAX+21

#define IOF_SHOWHELP  0x00000001
#define IOF_SELECTCREATENEW  0x00000002
#define IOF_SELECTCREATEFROMFILE  0x00000004
#define IOF_CHECKLINK  0x00000008
#define IOF_CHECKDISPLAYASICON  0x00000010
#define IOF_CREATENEWOBJECT  0x00000020
#define IOF_CREATEFILEOBJECT  0x00000040
#define IOF_CREATELINKOBJECT  0x00000080
#define IOF_DISABLELINK  0x00000100
#define IOF_VERIFYSERVERSEXIST  0x00000200
#define IOF_DISABLEDISPLAYASICON  0x00000400
#define IOF_HIDECHANGEICON  0x00000800
#define IOF_SHOWINSERTCONTROL  0x00001000
#define IOF_SELECTCREATECONTROL  0x00002000

#define PS_MAXLINKTYPES  8

#define PSF_SHOWHELP  0x00000001
#define PSF_SELECTPASTE  0x00000002
#define PSF_SELECTPASTELINK  0x00000004
#define PSF_CHECKDISPLAYASICON  0x00000008
#define PSF_DISABLEDISPLAYASICON  0x00000010
#define PSF_HIDECHANGEICON  0x00000020
#define PSF_STAYONCLIPBOARDCHANGE  0x00000040
#define PSF_NOREFRESHDATAOBJECT  0x00000080

#define ELF_SHOWHELP  0x00000001
#define ELF_DISABLEUPDATENOW  0x00000002
#define ELF_DISABLEOPENSOURCE  0x00000004
#define ELF_DISABLECHANGESOURCE  0x00000008
#define ELF_DISABLECANCELLINK  0x00000010

#define CIF_SHOWHELP  0x00000001
#define CIF_SELECTCURRENT  0x00000002
#define CIF_SELECTDEFAULT  0x00000004
#define CIF_SELECTFROMFILE  0x00000008
#define CIF_USEICONEXE  0x00000010

#define CF_SHOWHELPBUTTON  0x00000001
#define CF_SETCONVERTDEFAULT  0x00000002
#define CF_SETACTIVATEDEFAULT  0x00000004
#define CF_SELECTCONVERTTO  0x00000008
#define CF_SELECTACTIVATEAS  0x00000010
#define CF_DISABLEDISPLAYASICON  0x00000020
#define CF_DISABLEACTIVATEAS  0x00000040
#define CF_HIDECHANGEICON  0x00000080
#define CF_CONVERTONLY  0x00000100

#define BZ_DISABLECANCELBUTTON  0x00000001
#define BZ_DISABLESWITCHTOBUTTON  0x00000002
#define BZ_DISABLERETRYBUTTON  0x00000004
#define BZ_NOTRESPONDINGDIALOG  0x00000008

#define CSF_SHOWHELP  0x00000001
#define CSF_VALIDSOURCE  0x00000002
#define CSF_ONLYGETSOURCE  0x00000004
#define CSF_EXPLORER  0x00000008

#define VPF_SELECTRELATIVE  0x00000001
#define VPF_DISABLERELATIVE  0x00000002
#define VPF_DISABLESCALE  0x00000004

#define OPF_OBJECTISLINK  0x00000001
#define OPF_NOFILLDEFAULT  0x00000002
#define OPF_SHOWHELP  0x00000004
#define OPF_DISABLECONVERT  0x00000008

#define OLEUI_QUERY_GETCLASSID  0xFF00
#define OLEUI_QUERY_LINKBROKEN  0xFF01

IOleUILinkContainerW STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetNextLink PTR
	SetLinkUpdateOptions PTR
	GetLinkUpdateOptions PTR
	SetLinkSource PTR
	GetLinkSource PTR
	OpenLinkSource PTR
	UpdateLink PTR
	CancelLink PTR
ENDS

IOleUILinkContainerA STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetNextLink PTR
	SetLinkUpdateOptions PTR
	GetLinkUpdateOptions PTR
	SetLinkSource PTR
	GetLinkSource PTR
	OpenLinkSource PTR
	UpdateLink PTR
	CancelLink PTR
ENDS

IOleUIObjInfoW STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetObjectInfo PTR
	GetConvertInfo PTR
	ConvertObject PTR
	GetViewInfo PTR
	SetViewInfo PTR
ENDS

IOleUIObjInfoA STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetObjectInfo PTR
	GetConvertInfo PTR
	ConvertObject PTR
	GetViewInfo PTR
	SetViewInfo PTR
ENDS

IOleUILinkInfoW STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetNextLink PTR
	SetLinkUpdateOptions PTR
	GetLinkUpdateOptions PTR
	SetLinkSource PTR
	GetLinkSource PTR
	OpenLinkSource PTR
	UpdateLink PTR
	CancelLink PTR
	GetLastUpdate PTR
ENDS

IOleUILinkInfoA STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetNextLink PTR
	SetLinkUpdateOptions PTR
	GetLinkUpdateOptions PTR
	SetLinkSource PTR
	GetLinkSource PTR
	OpenLinkSource PTR
	UpdateLink PTR
	CancelLink PTR
	GetLastUpdate PTR
ENDS

OLEUIINSERTOBJECTW STRUCT
	cbStruct DD
	dwFlags DD
	hWndOwner HANDLE
	lpszCaption PTR
	lpfnHook PTR
	lCustData LPARAM
	hInstance HANDLE
	lpszTemplate PTR
	hResource HANDLE
	clsid GUID
	lpszFile PTR
	cchFile DD
	cClsidExclude DD
	lpClsidExclude PTR
	iid GUID
	oleRender DD
	lpFormatEtc PTR
	lpIOleClientSite PTR
	lpIStorage PTR
	ppvObj PTR
	sc DD
	hMetaPict HANDLE
ENDS

OLEUIINSERTOBJECTA STRUCT
	cbStruct DD
	dwFlags DD
	hWndOwner HANDLE
	lpszCaption PTR
	lpfnHook PTR
	lCustData LPARAM
	hInstance HANDLE
	lpszTemplate PTR
	hResource HANDLE
	clsid GUID
	lpszFile PTR
	cchFile DD
	cClsidExclude DD
	lpClsidExclude PTR
	iid GUID
	oleRender DD
	lpFormatEtc PTR
	lpIOleClientSite PTR
	lpIStorage PTR
	ppvObj PTR
	sc DD
	hMetaPict HANDLE
ENDS

OLEUIPASTE_ENABLEICON = 2048
OLEUIPASTE_PASTEONLY = 0
OLEUIPASTE_PASTE = 512
OLEUIPASTE_LINKANYTYPE = 1024
OLEUIPASTE_LINKTYPE1 = 1
OLEUIPASTE_LINKTYPE2 = 2
OLEUIPASTE_LINKTYPE3 = 4
OLEUIPASTE_LINKTYPE4 = 8
OLEUIPASTE_LINKTYPE5 = 16
OLEUIPASTE_LINKTYPE6 = 32
OLEUIPASTE_LINKTYPE7 = 64
OLEUIPASTE_LINKTYPE8 = 128

OLEUIPASTEENTRYW STRUCT
	fmtetc FORMATETC
	lpstrFormatName PTR
	lpstrResultText PTR
	dwFlags DD
	dwScratchSpace DD
ENDS

#define OLEUIPASTEENTRYA OLEUIPASTEENTRYW

OLEUIPASTESPECIALW STRUCT
	cbStruct DD
	dwFlags DD
	hWndOwner HANDLE
	lpszCaption PTR
	lpfnHook PTR
	lCustData LPARAM
	hInstance HANDLE
	lpszTemplate PTR
	hResource HANDLE
	lpSrcDataObj PTR
	arrPasteEntries PTR
	cPasteEntries DD
	arrLinkTypes PTR
	cLinkTypes DD
	cClsidExclude DD
	lpClsidExclude PTR
	nSelectedIndex DD
	fLink DD
	hMetaPict HANDLE
	sizel SIZE
ENDS

#define OLEUIPASTESPECIALA OLEUIPASTESPECIALW

OLEUIEDITLINKSW STRUCT
	cbStruct DD
	dwFlags DD
	hWndOwner HANDLE
	lpszCaption PTR
	lpfnHook PTR
	lCustData LPARAM
	hInstance HANDLE
	lpszTemplate PTR
	hResource HANDLE
	lpOleUILinkContainer PTR
ENDS

#define OLEUIEDITLINKSA OLEUIEDITLINKSW

OLEUICHANGEICONW STRUCT
	cbStruct DD
	dwFlags DD
	hWndOwner HANDLE
	lpszCaption PTR
	lpfnHook PTR
	lCustData LPARAM
	hInstance HANDLE
	lpszTemplate PTR
	hResource HANDLE
	hMetaPict HANDLE
	clsid GUID
	szIconExe DW MAX_PATH DUP (?)
	cchIconExe DD
ENDS

OLEUICHANGEICONA STRUCT
	cbStruct DD
	dwFlags DD
	hWndOwner HANDLE
	lpszCaption PTR
	lpfnHook PTR
	lCustData LPARAM
	hInstance HANDLE
	lpszTemplate PTR
	hResource HANDLE
	hMetaPict HANDLE
	clsid GUID
	szIconExe DB MAX_PATH DUP (?)
	cchIconExe DD
ENDS

OLEUICONVERTW STRUCT
	cbStruct DD
	dwFlags DD
	hWndOwner HANDLE
	lpszCaption PTR
	lpfnHook PTR
	lCustData LPARAM
	hInstance HANDLE
	lpszTemplate PTR
	hResource HANDLE
	clsid GUID
	clsidConvertDefault GUID
	clsidActivateDefault GUID
	clsidNew GUID
	dvAspect DD
	wFormat DW
	fIsLinkedObject DD
	hMetaPict HANDLE
	lpszUserType PTR
	fObjectsIconChanged DD
	lpszDefLabel PTR
	cClsidExclude DD
	lpClsidExclude PTR
ENDS

#define OLEUICONVERTA OLEUICONVERTW

OLEUIBUSYW STRUCT
	cbStruct DD
	dwFlags DD
	hWndOwner HANDLE
	lpszCaption PTR
	lpfnHook PTR
	lCustData LPARAM
	hInstance HANDLE
	lpszTemplate PTR
	hResource HANDLE
	hTask HANDLE
	lphWndDialog PTR
ENDS

#define OLEUIBUSYA OLEUIBUSYW

OLEUICHANGESOURCEW STRUCT
	cbStruct DD
	dwFlags DD
	hWndOwner HANDLE
	lpszCaption PTR
	lpfnHook PTR
	lCustData LPARAM
	hInstance HANDLE
	lpszTemplate PTR
	hResource HANDLE
	lpOFN PTR
	dwReserved1 DD 4 DUP (?)
	lpOleUILinkContainer PTR
	dwLink DD
	lpszDisplayName PTR
	nFileLength DD
	lpszFrom PTR
	lpszTo PTR
ENDS

#define OLEUICHANGESOURCEA OLEUICHANGESOURCEW

OLEUIGNRLPROPSW STRUCT
	cbStruct DD
	dwFlags DD
	dwReserved1 DD 2 DUP (?)
	lpfnHook PTR
	lCustData LPARAM
	dwReserved2 DD 3 DUP (?)
	lpOP PTR
ENDS

#define OLEUIGNRLPROPSA OLEUIGNRLPROPSW

OLEUIVIEWPROPSW STRUCT
	cbStruct DD
	dwFlags DD
	dwReserved1 DD 2 DUP (?)
	lpfnHook PTR
	lCustData LPARAM
	dwReserved2 DD 3 DUP (?)
	lpOP PTR
	nScaleMin DD
	nScaleMax DD
ENDS

#define OLEUIVIEWPROPSA OLEUIVIEWPROPSW

#define OLEUILINKPROPSW OLEUIGNRLPROPSW

#define OLEUILINKPROPSA OLEUIGNRLPROPSW

OLEUIOBJECTPROPSW STRUCT
	cbStruct DD
	dwFlags DD
	lpPS PTR
	dwObject DD
	lpObjInfo PTR
	dwLink DD
	lpLinkInfo PTR
	lpGP PTR
	lpVP PTR
	lpLP PTR
ENDS

#define OLEUIOBJECTPROPSA OLEUIOBJECTPROPSW

#IFDEF UNICODE
	#define IDD_SERVERNOTREG  IDD_SERVERNOTREGW
	#define IDD_LINKTYPECHANGED  IDD_LINKTYPECHANGEDW
	#define OLEUIINSERTOBJECT OLEUIINSERTOBJECTW
	#define OleUIInsertObject OleUIInsertObjectW
	#define OLEUIPASTEENTRY OLEUIPASTEENTRYW
	#define OLEUIPASTESPECIAL OLEUIPASTESPECIALW
	#define IOleUILinkContainer IOleUILinkContainerW
	#define OLEUIEDITLINKS OLEUIEDITLINKSW
	#define OLEUICHANGEICON OLEUICHANGEICONW
	#define OLEUICONVERT OLEUICONVERTW
	#define OLEUIBUSY OLEUIBUSYW
	#define OLEUICHANGESOURCE OLEUICHANGESOURCEW
	#define IOleUIObjInfo IOleUIObjInfoW
	#define IOleUILinkInfo IOleUILinkInfoW
	#define OLEUIGNRLPROPS OLEUIGNRLPROPSW
	#define OLEUIVIEWPROPS OLEUIVIEWPROPSW
	#define OLEUILINKPROPS OLEUILINKPROPSW
	#define OLEUIOBJECTPROPS OLEUIOBJECTPROPSW
	#define OleUIObjectProperties OleUIObjectPropertiesW
	#define OleUIChangeSource OleUIChangeSourceW
	#define OleUIBusy OleUIBusyW
	#define OleUIConvert OleUIConvertW
	#define OleUIChangeIcon OleUIChangeIconW
	#define OleUIAddVerbMenu OleUIAddVerbMenuW
	#define OleUIPasteSpecial OleUIPasteSpecialW
	#define OleUIEditLinks OleUIEditLinksW
	#define OleUIPromptUser OleUIPromptUserW
	#define OleUIUpdateLinks OleUIUpdateLinksW
#else
	#define IDD_SERVERNOTREG  IDD_SERVERNOTREGA
	#define IDD_LINKTYPECHANGED  IDD_LINKTYPECHANGEDA
	#define OLEUIINSERTOBJECT OLEUIINSERTOBJECTA
	#define OleUIInsertObject OleUIInsertObjectA
	#define OLEUIPASTEENTRY OLEUIPASTEENTRYA
	#define OLEUIPASTESPECIAL OLEUIPASTESPECIALA
	#define IOleUILinkContainer IOleUILinkContainerA
	#define OLEUIEDITLINKS OLEUIEDITLINKSA
	#define OLEUICHANGEICON OLEUICHANGEICONA
	#define OLEUICONVERT OLEUICONVERTA
	#define OLEUIBUSY OLEUIBUSYA
	#define OLEUICHANGESOURCE OLEUICHANGESOURCEA
	#define IOleUIObjInfo IOleUIObjInfoA
	#define IOleUILinkInfo IOleUILinkInfoA
	#define OLEUIGNRLPROPS OLEUIGNRLPROPSA
	#define OLEUIVIEWPROPS OLEUIVIEWPROPSA
	#define OLEUILINKPROPS OLEUILINKPROPSA
	#define OLEUIOBJECTPROPS OLEUIOBJECTPROPSA
	#define OleUIObjectProperties OleUIObjectPropertiesA
	#define OleUIChangeSource OleUIChangeSourceA
	#define OleUIBusy OleUIBusyA
	#define OleUIConvert OleUIConvertA
	#define OleUIChangeIcon OleUIChangeIconA
	#define OleUIAddVerbMenu OleUIAddVerbMenuA
	#define OleUIPasteSpecial OleUIPasteSpecialA
	#define OleUIEditLinks OleUIEditLinksA
	#define OleUIPromptUser OleUIPromptUserA
	#define OleUIUpdateLinks OleUIUpdateLinksA
#endif /* UNICODE */

#endif /* _OLEDLG_H */
