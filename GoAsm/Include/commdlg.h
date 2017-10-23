#ifndef COMMDLG_H
#define COMMDLG_H

#define COMMDLG_H_REQVER 100

/* Windows Common Dialog API definitions */

/*
Dependancies
prsht.h
cderr.h
*/

/*
Switches
WIN9X ; shortens OPENFILENAME structure to Win9x/NT4 length
*/

#IFDEF LINKFILES
	#dynamiclinkfile comdlg32.dll
#ENDIF

#DEFINE GUID_IID_IPrintDialogCallback <0x5852a2c3,0x6530,0x11d1,<0xb6,0xa3,0x0,0x0,0xf8,0x75,0x7b,0xf9>>
#DEFINE GUID_IID_IPrintDialogServices <0x509aaeda,0x5639,0x11d1,<0xb6,0xa1,0x0,0x0,0xf8,0x75,0x7b,0xf9>>

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

IPrintDialogCallback STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	InitDone PTR
	SelectionChange PTR
	HandleMessage PTR
ENDS

IPrintDialogServices STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCurrentDevMode PTR
	GetCurrentPrinterName PTR
	GetCurrentPortName PTR
ENDS

#IFNDEF PRSHT_H
	#include prsht.h // WIN32/64
#ENDIF

#IFNDEF CDERR_H
	#include cderr.h // WIN32/64
#ENDIF

#define LBSELCHSTRINGA  A"commdlg_LBSelChangedNotify"
#define SHAREVISTRINGA  A"commdlg_ShareViolation"
#define FILEOKSTRINGA   A"commdlg_FileNameOK"
#define COLOROKSTRINGA  A"commdlg_ColorOK"
#define SETRGBSTRINGA   A"commdlg_SetRGBColor"
#define HELPMSGSTRINGA  A"commdlg_help"
#define FINDMSGSTRINGA  A"commdlg_FindReplace"

#define LBSELCHSTRINGW  L"commdlg_LBSelChangedNotify"
#define SHAREVISTRINGW  L"commdlg_ShareViolation"
#define FILEOKSTRINGW   L"commdlg_FileNameOK"
#define COLOROKSTRINGW  L"commdlg_ColorOK"
#define SETRGBSTRINGW   L"commdlg_SetRGBColor"
#define HELPMSGSTRINGW  L"commdlg_help"
#define FINDMSGSTRINGW  L"commdlg_FindReplace"

#define CDN_FIRST  -601
#define CDN_LAST  -699

#define CDN_INITDONE  (CDN_FIRST-0) ; -601
#define CDN_SELCHANGE  (CDN_FIRST-1) ; -602
#define CDN_FOLDERCHANGE  (CDN_FIRST-2) ; -603
#define CDN_SHAREVIOLATION  (CDN_FIRST-3) ; -604
#define CDN_HELP  (CDN_FIRST-4) ; -605
#define CDN_FILEOK  (CDN_FIRST-5) ; -606
#define CDN_TYPECHANGE  (CDN_FIRST-6) ; -607
#define CDN_INCLUDEITEM  (CDN_FIRST-7) ; -608

#define CDM_FIRST  (WM_USER+100)
#define CDM_LAST  (WM_USER+200)

#define CDM_GETSPEC  (CDM_FIRST+0) ; 1024
#define CDM_GETFILEPATH  (CDM_FIRST+1) ; 1025
#define CDM_GETFOLDERPATH  (CDM_FIRST+2) ; 1026
#define CDM_GETFOLDERIDLIST  (CDM_FIRST+3) ; 1027
#define CDM_SETCONTROLTEXT  (CDM_FIRST+4) ; 1028
#define CDM_HIDECONTROL  (CDM_FIRST+5) ; 1029
#define CDM_SETDEFEXT  (CDM_FIRST+6) ; 1030

#define WM_CHOOSEFONT_GETLOGFONT  (WM_USER+1)
#define WM_CHOOSEFONT_SETLOGFONT  (WM_USER+101)
#define WM_CHOOSEFONT_SETFLAGS  (WM_USER+102)

#define WM_PSD_PAGESETUPDLG  (WM_USER+0)
#define WM_PSD_FULLPAGERECT  (WM_USER+1)
#define WM_PSD_MINMARGINRECT  (WM_USER+2)
#define WM_PSD_MARGINRECT  (WM_USER+3)
#define WM_PSD_GREEKTEXTRECT  (WM_USER+4)
#define WM_PSD_ENVSTAMPRECT  (WM_USER+5)
#define WM_PSD_YAFULLPAGERECT  (WM_USER+6)

#define CC_RGBINIT  0x00000001
#define CC_FULLOPEN   0x00000002
#define CC_PREVENTFULLOPEN  0x00000004
#define CC_SHOWHELP  0x00000008
#define CC_ENABLEHOOK  0x00000010
#define CC_ENABLETEMPLATE  0x00000020
#define CC_ENABLETEMPLATEHANDLE  0x00000040
#define CC_SOLIDCOLOR  0x00000080
#define CC_ANYCOLOR  0x00000100

#define CF_SCREENFONTS  0x00000001
#define CF_PRINTERFONTS  0x00000002
#define CF_BOTH  (CF_SCREENFONTS|CF_PRINTERFONTS)
#define CF_SHOWHELP  0x00000004
#define CF_ENABLEHOOK  0x00000008
#define CF_ENABLETEMPLATE  0x00000010
#define CF_ENABLETEMPLATEHANDLE  0x00000020
#define CF_INITTOLOGFONTSTRUCT  0x00000040
#define CF_USESTYLE  0x00000080
#define CF_EFFECTS  0x00000100
#define CF_APPLY  0x00000200
#define CF_ANSIONLY  0x00000400
#define CF_SCRIPTSONLY  CF_ANSIONLY
#define CF_NOVECTORFONTS  0x00000800
#define CF_NOOEMFONTS  CF_NOVECTORFONTS
#define CF_NOSIMULATIONS  0x00001000
#define CF_LIMITSIZE  0x00002000
#define CF_FIXEDPITCHONLY  0x00004000
#define CF_WYSIWYG  0x00008000
#define CF_FORCEFONTEXIST  0x00010000
#define CF_SCALABLEONLY  0x00020000
#define CF_TTONLY  0x00040000
#define CF_NOFACESEL  0x00080000
#define CF_NOSTYLESEL  0x00100000
#define CF_NOSIZESEL  0x00200000
#define CF_SELECTSCRIPT  0x00400000
#define CF_NOSCRIPTSEL  0x00800000
#define CF_NOVERTFONTS  0x01000000

#define SIMULATED_FONTTYPE  0x8000
#define PRINTER_FONTTYPE  0x4000
#define SCREEN_FONTTYPE  0x2000
#define BOLD_FONTTYPE  0x0100
#define ITALIC_FONTTYPE  0x0200
#define REGULAR_FONTTYPE  0x0400

#define OFN_READONLY  0x00000001
#define OFN_OVERWRITEPROMPT  0x00000002
#define OFN_HIDEREADONLY  0x00000004
#define OFN_NOCHANGEDIR  0x00000008
#define OFN_SHOWHELP  0x00000010
#define OFN_ENABLEHOOK  0x00000020
#define OFN_ENABLETEMPLATE  0x00000040
#define OFN_ENABLETEMPLATEHANDLE  0x00000080
#define OFN_NOVALIDATE  0x00000100
#define OFN_ALLOWMULTISELECT  0x00000200
#define OFN_EXTENSIONDIFFERENT  0x00000400
#define OFN_PATHMUSTEXIST  0x00000800
#define OFN_FILEMUSTEXIST  0x00001000
#define OFN_CREATEPROMPT  0x00002000
#define OFN_SHAREAWARE  0x00004000
#define OFN_NOREADONLYRETURN  0x00008000
#define OFN_NOTESTFILECREATE  0x00010000
#define OFN_NONETWORKBUTTON  0x00020000
#define OFN_NOLONGNAMES  0x00040000
#define OFN_EXPLORER  0x00080000
#define OFN_NODEREFERENCELINKS  0x00100000
#define OFN_LONGNAMES  0x00200000
#define OFN_ENABLEINCLUDENOTIFY  0x00400000
#define OFN_ENABLESIZING  0x00800000
#define OFN_DONTADDTORECENT  0x02000000
#define OFN_FORCESHOWHIDDEN  0x10000000
#define OFN_EX_NOPLACESBAR  0x00000001

#define OFN_SHAREFALLTHROUGH  2
#define OFN_SHARENOWARN  1
#define OFN_SHAREWARN  0

#define FR_DOWN  0x00000001
#define FR_WHOLEWORD  0x00000002
#define FR_MATCHCASE  0x00000004
#define FR_FINDNEXT  0x00000008
#define FR_REPLACE  0x00000010
#define FR_REPLACEALL  0x00000020
#define FR_DIALOGTERM  0x00000040
#define FR_SHOWHELP  0x00000080
#define FR_ENABLEHOOK  0x00000100
#define FR_ENABLETEMPLATE  0x00000200
#define FR_NOUPDOWN  0x00000400
#define FR_NOMATCHCASE  0x00000800
#define FR_NOWHOLEWORD  0x00001000
#define FR_ENABLETEMPLATEHANDLE  0x00002000
#define FR_HIDEUPDOWN  0x00004000
#define FR_HIDEMATCHCASE  0x00008000
#define FR_HIDEWHOLEWORD  0x00010000
#define FR_RAW  0x00020000
#define FR_MATCHDIAC  0x20000000
#define FR_MATCHKASHIDA  0x40000000
#define FR_MATCHALEFHAMZA  0x80000000

#define PD_ALLPAGES  0x00000000
#define PD_SELECTION  0x00000001
#define PD_PAGENUMS  0x00000002
#define PD_NOSELECTION  0x00000004
#define PD_NOPAGENUMS  0x00000008
#define PD_COLLATE  0x00000010
#define PD_PRINTTOFILE  0x00000020
#define PD_PRINTSETUP  0x00000040
#define PD_NOWARNING  0x00000080
#define PD_RETURNDC  0x00000100
#define PD_RETURNIC  0x00000200
#define PD_RETURNDEFAULT  0x00000400
#define PD_SHOWHELP  0x00000800
#define PD_ENABLEPRINTHOOK  0x00001000
#define PD_ENABLESETUPHOOK  0x00002000
#define PD_ENABLEPRINTTEMPLATE  0x00004000
#define PD_ENABLESETUPTEMPLATE  0x00008000
#define PD_ENABLEPRINTTEMPLATEHANDLE  0x00010000
#define PD_ENABLESETUPTEMPLATEHANDLE  0x00020000
#define PD_USEDEVMODECOPIES  0x00040000
#define PD_USEDEVMODECOPIESANDCOLLATE  0x00040000
#define PD_DISABLEPRINTTOFILE  0x00080000
#define PD_HIDEPRINTTOFILE  0x00100000
#define PD_NONETWORKBUTTON  0x00200000
#define PD_CURRENTPAGE  0x00400000
#define PD_NOCURRENTPAGE  0x00800000
#define PD_EXCLUSIONFLAGS  0x01000000
#define PD_USELARGETEMPLATE  0x10000000
#define PD_EXCL_COPIESANDCOLLATE  (DM_COPIES|DM_COLLATE)
#define PD_RESULT_CANCEL  0
#define PD_RESULT_PRINT  1
#define PD_RESULT_APPLY  2
#define START_PAGE_GENERAL  0xFFFFFFFF

#define PSD_DEFAULTMINMARGINS  0x00000000
#define PSD_INWININIINTLMEASURE  0x00000000
#define PSD_MINMARGINS  0x00000001
#define PSD_MARGINS  0x00000002
#define PSD_INTHOUSANDTHSOFINCHES  0x00000004
#define PSD_INHUNDREDTHSOFMILLIMETERS  0x00000008
#define PSD_DISABLEMARGINS  0x00000010
#define PSD_DISABLEPRINTER  0x00000020
#define PSD_NOWARNING  0x00000080
#define PSD_DISABLEORIENTATION  0x00000100
#define PSD_RETURNDEFAULT  0x00000400
#define PSD_DISABLEPAPER  0x00000200
#define PSD_SHOWHELP  0x00000800
#define PSD_ENABLEPAGESETUPHOOK  0x00002000
#define PSD_ENABLEPAGESETUPTEMPLATE  0x00008000
#define PSD_ENABLEPAGESETUPTEMPLATEHANDLE  0x00020000
#define PSD_ENABLEPAGEPAINTHOOK  0x00040000
#define PSD_DISABLEPAGEPAINTING  0x00080000
#define PSD_NONETWORKBUTTON  0x00200000

#define CD_LBSELNOITEMS  (-1)
#define CD_LBSELCHANGE  0
#define CD_LBSELSUB  1
#define CD_LBSELADD  2

#define DN_DEFAULTPRN  1

CHOOSECOLORA STRUCT
	lStructSize DD
	hwndOwner HANDLE
	hInstance HANDLE
	rgbResult DD
	lpCustColors PTR
	Flags DD
	lCustData LPARAM
	lpfnHook PTR
	lpTemplateName PTR
ENDS

CHOOSECOLORW STRUCT 
	lStructSize DD
	hwndOwner HANDLE
	hInstance HANDLE
	rgbResult DD
	lpCustColors PTR
	Flags DD
	lCustData LPARAM
	lpfnHook PTR
	lpTemplateName PTR
ENDS

CHOOSEFONTA STRUCT
	lStructSize DD
	hwndOwner HANDLE
	hDC HANDLE
	lpLogFont PTR
	iPointSize DD
	Flags DD
	rgbColors DD
	lCustData LPARAM
	lpfnHook PTR
	lpTemplateName PTR
	hInstance HANDLE
	lpszStyle PTR
	nFontType DW
	padding DW
	nSizeMin DD
	nSizeMax DD
ENDS

CHOOSEFONTW STRUCT
	lStructSize DD
	hwndOwner HANDLE
	hDC HANDLE
	lpLogFont PTR
	iPointSize DD
	Flags DD
	rgbColors DD
	lCustData LPARAM
	lpfnHook PTR
	lpTemplateName PTR
	hInstance HANDLE
	lpszStyle PTR
	nFontType DW
	padding DW
	nSizeMin DD
	nSizeMax DD
ENDS

DEVNAMES STRUCT
	wDriverOffset DW
	wDeviceOffset DW
	wOutputOffset DW
	wDefault DW
ENDS

FINDREPLACEA STRUCT
	lStructSize DD
	hwndOwner HANDLE
	hInstance HANDLE
	Flags DD
	lpstrFindWhat PTR
	lpstrReplaceWith PTR
	wFindWhatLen DW
	wReplaceWithLen DW
	lCustData LPARAM
	lpfnHook PTR
	lpTemplateName PTR
ENDS

FINDREPLACEW STRUCT
	lStructSize DD
	hwndOwner HANDLE
	hInstance HANDLE
	Flags DD
	lpstrFindWhat PTR
	lpstrReplaceWith PTR
	wFindWhatLen DW
	wReplaceWithLen DW
	lCustData LPARAM
	lpfnHook PTR
	lpTemplateName PTR
ENDS

// OPENFILENAME_NT4 has no 64 bit version
OPENFILENAME_NT4 STRUCT
	lStructSize DD
	hwndOwner DD
	hInstance DD
	lpstrFilter DD
	lpstrCustomFilter DD
	nMaxCustFilter DD
	nFilterIndex DD
	lpstrFile DD
	nMaxFile DD
	lpstrFileTitle DD
	nMaxFileTitle DD
	lpstrInitialDir DD
	lpstrTitle DD
	Flags DD
	nFileOffset DW
	nFileExtension DW
	lpstrDefExt DD
	lCustData DD
	lpfnHook DD
	lpTemplateName DD
ENDS

OPENFILENAMEA STRUCT
	lStructSize DD
	hwndOwner HANDLE
	hInstance HANDLE
	lpstrFilter PTR
	lpstrCustomFilter PTR
	nMaxCustFilter DD
	nFilterIndex DD
	lpstrFile PTR
	nMaxFile DD
	lpstrFileTitle PTR
	nMaxFileTitle DD
	lpstrInitialDir PTR
	lpstrTitle PTR
	Flags DD
	nFileOffset DW
	nFileExtension DW
	lpstrDefExt PTR
	lCustData LPARAM
	lpfnHook PTR
	lpTemplateName PTR
#IF WINVER >= NTDDI_WIN2K
	// WIN9X has no 64 bit pointers
	pvReserved PTR
	dwReserved DD
	FlagsEx DD
#ENDIF
ENDS

OPENFILENAMEW STRUCT
	lStructSize DD
	hwndOwner HANDLE
	hInstance HANDLE
	lpstrFilter PTR
	lpstrCustomFilter PTR
	nMaxCustFilter DD
	nFilterIndex DD
	lpstrFile PTR
	nMaxFile DD
	lpstrFileTitle PTR
	nMaxFileTitle DD
	lpstrInitialDir PTR
	lpstrTitle PTR
	Flags DD
	nFileOffset DW
	nFileExtension DW
	lpstrDefExt PTR
	lCustData LPARAM
	lpfnHook PTR
	lpTemplateName PTR
#IF WINVER >= NTDDI_WIN2K
	// WIN9X has no 64 bit pointers
	pvReserved PTR
	dwReserved DD
	FlagsEx DD
#ENDIF
ENDS

OFNOTIFYA STRUCT
	hdr NMHDR
	lpOFN PTR
	pszFile PTR
ENDS

OFNOTIFYW STRUCT
	hdr NMHDR
	lpOFN PTR
	pszFile PTR
ENDS

OFNOTIFYEXA STRUCT
	hdr NMHDR
	lpOFN PTR
	psf PTR
	pidl PTR
ENDS

OFNOTIFYEXW STRUCT
	hdr NMHDR
	lpOFN PTR
	psf PTR
	pidl PTR
ENDS

PAGESETUPDLGA STRUCT
	lStructSize DD
	hwndOwner HANDLE
	hDevMode HANDLE
	hDevNames HANDLE
	Flags DD
	ptPaperSize POINT
	rtMinMargin RECT
	rtMargin RECT
	hInstance HANDLE
	lCustData LPARAM
	lpfnPageSetupHook PTR
	lpfnPagePaintHook PTR
	lpPageSetupTemplateName PTR
	hPageSetupTemplate HANDLE
ENDS

PAGESETUPDLGW STRUCT
	lStructSize DD
	hwndOwner HANDLE
	hDevMode HANDLE
	hDevNames HANDLE
	Flags DD
	ptPaperSize POINT
	rtMinMargin RECT
	rtMargin RECT
	hInstance HANDLE
	lCustData LPARAM
	lpfnPageSetupHook PTR
	lpfnPagePaintHook PTR
	lpPageSetupTemplateName PTR
	hPageSetupTemplate HANDLE
ENDS

PRINTDLGA STRUCT
	lStructSize DD
	hwndOwner HANDLE
	hDevMode HANDLE
	hDevNames HANDLE
	hDC HANDLE
	Flags DD
	nFromPage DW
	nToPage DW
	nMinPage DW
	nMaxPage DW
	nCopies DW
	hInstance HANDLE
	lCustData LPARAM
	lpfnPrintHook PTR
	lpfnSetupHook PTR
	lpPrintTemplateName PTR
	lpSetupTemplateName PTR
	hPrintTemplate HANDLE
	hSetupTemplate HANDLE
ENDS

PRINTDLGW STRUCT
	lStructSize DD
	hwndOwner HANDLE
	hDevMode HANDLE
	hDevNames HANDLE
	hDC HANDLE
	Flags DD
	nFromPage DW
	nToPage DW
	nMinPage DW
	nMaxPage DW
	nCopies DW
	hInstance HANDLE
	lCustData LPARAM
	lpfnPrintHook PTR
	lpfnSetupHook PTR
	lpPrintTemplateName PTR
	lpSetupTemplateName PTR
	hPrintTemplate HANDLE
	hSetupTemplate HANDLE
ENDS

PRINTPAGERANGE STRUCT
	nFromPage DD
	nToPage DD
ENDS

PRINTDLGEXA STRUCT
	lStructSize DD
	hwndOwner HANDLE
	hDevMode HANDLE
	hDevNames HANDLE
	hDC HANDLE
	Flags DD
	Flags2 DD
	ExclusionFlags DD
	nPageRanges DD
	nMaxPageRanges DD
	lpPageRanges PTR
	nMinPage DD
	nMaxPage DD
	nCopies DD
	hInstance HANDLE
	lpPrintTemplateName PTR
	lpCallback PTR
	nPropertyPages DD
	lphPropertyPages PTR
	nStartPage DD
	dwResultAction DD
ENDS

PRINTDLGEXW STRUCT
	lStructSize DD
	hwndOwner HANDLE
	hDevMode HANDLE
	hDevNames HANDLE
	hDC HANDLE
	Flags DD
	Flags2 DD
	ExclusionFlags DD
	nPageRanges DD
	nMaxPageRanges DD
	lpPageRanges PTR
	nMinPage DD
	nMaxPage DD
	nCopies DD
	hInstance HANDLE
	lpPrintTemplateName PTR
	lpCallback PTR
	nPropertyPages DD
	lphPropertyPages PTR
	nStartPage DD
	dwResultAction DD
ENDS

#IFDEF UNICODE
	#define OFNOTIFY OFNOTIFYW
	#define OFNOTIFYEX OFNOTIFYEXW
	#define PAGESETUPDLG PAGESETUPDLGW
	#define PRINTDLG PRINTDLGW
	#define PRINTDLGEX PRINTDLGEXW
	#define LBSELCHSTRING LBSELCHSTRINGW
	#define SHAREVISTRING SHAREVISTRINGW
	#define FILEOKSTRING FILEOKSTRINGW
	#define COLOROKSTRING COLOROKSTRINGW
	#define SETRGBSTRING SETRGBSTRINGW
	#define HELPMSGSTRING HELPMSGSTRINGW
	#define FINDMSGSTRING FINDMSGSTRINGW
	#define OPENFILENAME OPENFILENAMEW
	#define CHOOSEFONT CHOOSEFONTW
	#define CHOOSECOLOR CHOOSECOLORW
	#define FINDREPLACE FINDREPLACEW
	#define ChooseColor ChooseColorW
	#define ChooseFont ChooseFontW
	#define FindText FindTextW
	#define GetFileTitle GetFileTitleW
	#define GetOpenFileName GetOpenFileNameW
	#define GetSaveFileName GetSaveFileNameW
	#define PrintDlg PrintDlgW
	#define PageSetupDlg PageSetupDlgW
	#define ReplaceText ReplaceTextW
	#define CommDlg_OpenSave_GetSpec CommDlg_OpenSave_GetSpecW
	#define CommDlg_OpenSave_GetFilePath CommDlg_OpenSave_GetFilePathW
	#define CommDlg_OpenSave_GetFolderPath CommDlg_OpenSave_GetFolderPathW
	#define PrintDlgEx PrintDlgExW
#else /* UNICODE */
	#define OFNOTIFY OFNOTIFYA
	#define OFNOTIFYEX OFNOTIFYEXA
	#define PAGESETUPDLG PAGESETUPDLGA
	#define PRINTDLG PRINTDLGA
	#define PRINTDLGEX PRINTDLGEXA
	#define LBSELCHSTRING LBSELCHSTRINGA
	#define SHAREVISTRING SHAREVISTRINGA
	#define FILEOKSTRING FILEOKSTRINGA
	#define COLOROKSTRING COLOROKSTRINGA
	#define SETRGBSTRING SETRGBSTRINGA
	#define HELPMSGSTRING HELPMSGSTRINGA
	#define FINDMSGSTRING FINDMSGSTRINGA
	#define OPENFILENAME OPENFILENAMEA
	#define CHOOSEFONT CHOOSEFONTA
	#define CHOOSECOLOR CHOOSECOLORA
	#define FINDREPLACE FINDREPLACEA
	#define ChooseColor ChooseColorA
	#define ChooseFont ChooseFontA
	#define FindText FindTextA
	#define GetFileTitle GetFileTitleA
	#define GetOpenFileName GetOpenFileNameA
	#define GetSaveFileName GetSaveFileNameA
	#define PrintDlg PrintDlgA
	#define PageSetupDlg PageSetupDlgA
	#define ReplaceText ReplaceTextA
	#define CommDlg_OpenSave_GetSpec CommDlg_OpenSave_GetSpecA
	#define CommDlg_OpenSave_GetFilePath CommDlg_OpenSave_GetFilePathA
	#define CommDlg_OpenSave_GetFolderPath CommDlg_OpenSave_GetFolderPathA
	#define PrintDlgEx PrintDlgExA
#endif /* UNICODE */

#endif /* COMMDLG_H */
