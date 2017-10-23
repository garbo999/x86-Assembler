;=============================================================;
;          prsht.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF PRSHT_INC
#Define PRSHT_INC


#Define PSP_DEFAULT             000000000H
#Define PSP_DLGINDIRECT         000000001H
#Define PSP_USEHICON            000000002H
#Define PSP_USEICONID           000000004H
#Define PSP_USETITLE            000000008H
#Define PSP_RTLREADING          000000010H

#Define PSP_HASHELP             000000020H
#Define PSP_USEREFPARENT        000000040H
#Define PSP_USECALLBACK         000000080H
#Define PSP_PREMATURE           000000400H

#Define PSP_HIDEHEADER          000000800H
#Define PSP_USEHEADERTITLE      000001000H
#Define PSP_USEHEADERSUBTITLE   000002000H

#Define PSPCB_RELEASE           1
#Define PSPCB_CREATE            2

#Define PSH_DEFAULT             000000000H
#Define PSH_PROPTITLE           000000001H
#Define PSH_USEHICON            000000002H
#Define PSH_USEICONID           000000004H
#Define PSH_PROPSHEETPAGE       000000008H
#Define PSH_WIZARDHASFINISH     000000010H
#Define PSH_WIZARD              000000020H
#Define PSH_USEPSTARTPAGE       000000040H
#Define PSH_NOAPPLYNOW          000000080H
#Define PSH_USECALLBACK         000000100H
#Define PSH_HASHELP             000000200H
#Define PSH_MODELESS            000000400H
#Define PSH_RTLREADING          000000800H
#Define PSH_WIZARDCONTEXTHELP   000001000H

#Define PSH_WIZARD97            000002000H
#Define PSH_WATERMARK           000008000H
#Define PSH_USEHBMWATERMARK     000010000H
#Define PSH_USEHPLWATERMARK     000020000H
#Define PSH_STRETCHWATERMARK    000040000H
#Define PSH_HEADER              000080000H
#Define PSH_USEHBMHEADER        000100000H
#Define PSH_USEPAGELANG         000200000H

#Define PSCB_INITIALIZED  		1
#Define PSCB_PRECREATE    		2

#Define PSN_FIRST               (0 - 200)
#Define PSN_LAST                (0 - 299)

#Define PSN_SETACTIVE           (PSN_FIRST - 0)
#Define PSN_KILLACTIVE          (PSN_FIRST - 1)
#Define PSN_APPLY               (PSN_FIRST - 2)
#Define PSN_RESET               (PSN_FIRST - 3)
#Define PSN_HELP                (PSN_FIRST - 5)
#Define PSN_WIZBACK             (PSN_FIRST - 6)
#Define PSN_WIZNEXT             (PSN_FIRST - 7)
#Define PSN_WIZFINISH           (PSN_FIRST - 8)
#Define PSN_QUERYCANCEL         (PSN_FIRST - 9)
#Define PSN_GETOBJECT           (PSN_FIRST - 10)

#Define PSNRET_NOERROR              0
#Define PSNRET_INVALID              1
#Define PSNRET_INVALID_NOCHANGEPAGE	2

#Define PSM_SETCURSEL           (WM_USER + 101)
#Define PSM_REMOVEPAGE          (WM_USER + 102)
#Define PSM_ADDPAGE             (WM_USER + 103)
#Define PSM_CHANGED             (WM_USER + 104)
#Define PSM_RESTARTWINDOWS      (WM_USER + 105)
#Define PSM_REBOOTSYSTEM        (WM_USER + 106)
#Define PSM_CANCELTOCLOSE       (WM_USER + 107)
#Define PSM_QUERYSIBLINGS       (WM_USER + 108)
#Define PSM_UNCHANGED           (WM_USER + 109)
#Define PSM_APPLY               (WM_USER + 110)

#Define PSM_SETTITLEA           (WM_USER + 111)
#Define PSM_SETTITLEW			(WM_USER + 120)

#Define PSM_SETWIZBUTTONS       (WM_USER + 112)

#Define PSWIZB_BACK             000000001H
#Define PSWIZB_NEXT             000000002H
#Define PSWIZB_FINISH           000000004H
#Define PSWIZB_DISABLEDFINISH   000000008H

#Define PSM_PRESSBUTTON         (WM_USER + 113)

#Define PSBTN_BACK              0
#Define PSBTN_NEXT              1
#Define PSBTN_FINISH            2
#Define PSBTN_OK                3
#Define PSBTN_APPLYNOW          4
#Define PSBTN_CANCEL            5
#Define PSBTN_HELP              6
#Define PSBTN_MAX               6

#Define PSM_SETCURSELID         (WM_USER + 114)

#Define PSM_SETFINISHTEXTA      (WM_USER + 115)
#Define PSM_SETFINISHTEXTW		(WM_USER + 121)

#Define PSM_GETTABCONTROL       (WM_USER + 116)
#Define PSM_ISDIALOGMESSAGE     (WM_USER + 117)
#Define PSM_GETCURRENTPAGEHWND  (WM_USER + 118)

#Define ID_PSRESTARTWINDOWS     02H
#Define ID_PSREBOOTSYSTEM		(ID_PSRESTARTWINDOWS | 01H)

#Define WIZ_CXDLG               276
#Define WIZ_CYDLG               140

#Define WIZ_CXBMP               80

#Define WIZ_BODYX               92
#Define WIZ_BODYCX              184

#Define PROP_SM_CXDLG           212
#Define PROP_SM_CYDLG           188

#Define PROP_MED_CXDLG          227
#Define PROP_MED_CYDLG          215

#Define PROP_LG_CXDLG           252
#Define PROP_LG_CYDLG           218


PROPSHEETPAGEA Struct
	dwSize DD
	dwFlags DD
	hInstance DD
	Union ;DUMMYUNIONNAME
		pszTemplate DD
		pResource DD
	EndUnion
	Union ;DUMMYUNIONNAME2
		hIcon DD
		pszIcon DD
	EndUnion
	pszTitle DD
	pfnDlgProc DD
	lParam DD
	pfnCallback DD
	pcRefParent DD
	pszHeaderTitle DD
	pszHeaderSubTitle DD
EndS

PROPSHEETPAGEW Struct
	dwSize DD
	dwFlags DD
	hInstance DD
	Union ;DUMMYUNIONNAME
		pszTemplate DD
		pResource DD
	EndUnion
	Union ;DUMMYUNIONNAME2
		hIcon DD
		pszIcon DD
	EndUnion
	pszTitle DD
	pfnDlgProc DD
	lParam DD
	pfnCallback DD
	pcRefParent DD
	pszHeaderTitle DD
	pszHeaderSubTitle DD
EndS

PROPSHEETHEADERA Struct
	dwSize DD
	dwFlags DD
	hwndParent DD
	hInstance DD
	Union ;DUMMYUNIONNAME
		hIcon DD
		pszIcon DD
	EndUnion
	pszCaption DD
	nPages DD
	Union ;DUMMYUNIONNAME
		nStartPage DD
		pStartPage DD
	EndUnion
	Union ;DUMMYUNIONNAME
		ppsp DD
		phpage DD
	EndUnion
	pfnCallback DD
	Union ;DUMMYUNIONNAME4
		hbmWatermark DD
		pszbmWatermark DD
	EndUnion
	hplWatermark DD
	Union ;DUMMYUNIONNAME4
		hbmHeader DD
		pszbmHeader DD
	EndUnion
EndS

PROPSHEETHEADERW Struct
	dwSize DD
	dwFlags DD
	hwndParent DD
	hInstance DD
	Union ;DUMMYUNIONNAME
		hIcon DD
		pszIcon DD
	EndUnion
	pszCaption DD
	nPages DD
	Union ;DUMMYUNIONNAME
		nStartPage DD
		pStartPage DD
	EndUnion
	Union ;DUMMYUNIONNAME
		ppsp DD
		phpage DD
	EndUnion
	pfnCallback DD
	Union ;DUMMYUNIONNAME4
		hbmWatermark DD
		pszbmWatermark DD
	EndUnion
	hplWatermark DD
	Union ;DUMMYUNIONNAME4
		hbmHeader DD
		pszbmHeader DD
	EndUnion
EndS

PSHNOTIFY Struct
	hdr NMHDR <>
	lParam DD
EndS


#IF STRINGS UNICODE
	#Define PROPSHEETPAGE PROPSHEETPAGEW
	#Define PROPSHEETHEADER PROPSHEETHEADERW
	#Define CREATEPROPERTYSHEETPAGE CreatePropertySheetPageW
	#Define PSM_SETTITLE PSM_SETTITLEW
	#Define PSM_SETFINISHTEXT PSM_SETFINISHTEXTW
#ELSE
	#Define PROPSHEETPAGE PROPSHEETPAGEA
	#Define PROPSHEETHEADER PROPSHEETHEADERA
	#Define CREATEPROPERTYSHEETPAGE CreatePropertySheetPageA
	#Define PSM_SETTITLE PSM_SETTITLEA
	#Define PSM_SETFINISHTEXT PSM_SETFINISHTEXTA
#ENDIF

#ENDIF ;PRSHT_INC
