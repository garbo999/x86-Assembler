;=============================================================;
;          commdlg.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF COMMDLG_INC
#Define COMMDLG_INC

#Define OFN_READONLY                 000000001H
#Define OFN_OVERWRITEPROMPT          000000002H
#Define OFN_HIDEREADONLY             000000004H
#Define OFN_NOCHANGEDIR              000000008H
#Define OFN_SHOWHELP                 000000010H
#Define OFN_ENABLEHOOK               000000020H
#Define OFN_ENABLETEMPLATE           000000040H
#Define OFN_ENABLETEMPLATEHANDLE     000000080H
#Define OFN_NOVALIDATE               000000100H
#Define OFN_ALLOWMULTISELECT         000000200H
#Define OFN_EXTENSIONDIFFERENT       000000400H
#Define OFN_PATHMUSTEXIST            000000800H
#Define OFN_FILEMUSTEXIST            000001000H
#Define OFN_CREATEPROMPT             000002000H
#Define OFN_SHAREAWARE               000004000H
#Define OFN_NOREADONLYRETURN         000008000H
#Define OFN_NOTESTFILECREATE         000010000H
#Define OFN_NONETWORKBUTTON          000020000H
#Define OFN_NOLONGNAMES              000040000H
#Define OFN_EXPLORER                 000080000H
#Define OFN_NODEREFERENCELINKS       000100000H
#Define OFN_LONGNAMES                000200000H
#Define OFN_ENABLEINCLUDENOTIFY      000400000H
#Define OFN_ENABLESIZING             000800000H

#Define OFN_SHAREFALLTHROUGH    2
#Define OFN_SHARENOWARN         1
#Define OFN_SHAREWARN           0

#Define CDN_FIRST   			(0 - 601)
#Define CDN_LAST    			(0 - 699)

#Define CDN_INITDONE			(CDN_FIRST - 00000H)
#Define CDN_SELCHANGE			(CDN_FIRST - 00001H)
#Define CDN_FOLDERCHANGE		(CDN_FIRST - 00002H)
#Define CDN_SHAREVIOLATION		(CDN_FIRST - 00003H)
#Define CDN_HELP				(CDN_FIRST - 00004H)
#Define CDN_FILEOK				(CDN_FIRST - 00005H)
#Define CDN_TYPECHANGE			(CDN_FIRST - 00006H)
#Define CDN_INCLUDEITEM			(CDN_FIRST - 00007H)

#Define CDM_FIRST       		(WM_USER + 100)
#Define CDM_LAST        		(WM_USER + 200)

#Define CDM_GETSPEC             (CDM_FIRST + 00000H)
#Define CDM_GETFILEPATH         (CDM_FIRST + 00001H)
#Define CDM_GETFOLDERPATH       (CDM_FIRST + 00002H)
#Define CDM_GETFOLDERIDLIST     (CDM_FIRST + 00003H)
#Define CDM_SETCONTROLTEXT      (CDM_FIRST + 00004H)
#Define CDM_HIDECONTROL         (CDM_FIRST + 00005H)
#Define CDM_SETDEFEXT           (CDM_FIRST + 00006H)

#Define CC_RGBINIT               000000001H
#Define CC_FULLOPEN              000000002H
#Define CC_PREVENTFULLOPEN       000000004H
#Define CC_SHOWHELP              000000008H
#Define CC_ENABLEHOOK            000000010H
#Define CC_ENABLETEMPLATE        000000020H
#Define CC_ENABLETEMPLATEHANDLE  000000040H
#Define CC_SOLIDCOLOR            000000080H
#Define CC_ANYCOLOR              000000100H

#Define FR_DOWN                 000000001H
#Define FR_WHOLEWORD            000000002H
#Define FR_MATCHCASE            000000004H
#Define FR_FINDNEXT             000000008H
#Define FR_REPLACE              000000010H
#Define FR_REPLACEALL           000000020H
#Define FR_DIALOGTERM           000000040H
#Define FR_SHOWHELP             000000080H
#Define FR_ENABLEHOOK           000000100H
#Define FR_ENABLETEMPLATE       000000200H
#Define FR_NOUPDOWN             000000400H
#Define FR_NOMATCHCASE          000000800H
#Define FR_NOWHOLEWORD          000001000H
#Define FR_ENABLETEMPLATEHANDLE 000002000H
#Define FR_HIDEUPDOWN           000004000H
#Define FR_HIDEMATCHCASE        000008000H
#Define FR_HIDEWHOLEWORD        000010000H

#Define CF_SCREENFONTS          000000001H
#Define CF_PRINTERFONTS         000000002H
#Define CF_BOTH                 (CF_SCREENFONTS | CF_PRINTERFONTS)
#Define CF_SHOWHELP             000000004H
#Define CF_ENABLEHOOK           000000008H
#Define CF_ENABLETEMPLATE       000000010H
#Define CF_ENABLETEMPLATEHANDLE 000000020H
#Define CF_INITTOLOGFONTSTRUCT  000000040H
#Define CF_USESTYLE             000000080H
#Define CF_EFFECTS              000000100H
#Define CF_APPLY                000000200H
#Define CF_ANSIONLY             000000400H
#Define CF_SCRIPTSONLY          CF_ANSIONLY
#Define CF_NOVECTORFONTS        000000800H
#Define CF_NOOEMFONTS           CF_NOVECTORFONTS
#Define CF_NOSIMULATIONS        000001000H
#Define CF_LIMITSIZE            000002000H
#Define CF_FIXEDPITCHONLY       000004000H
#Define CF_WYSIWYG              000008000H
#Define CF_FORCEFONTEXIST       000010000H
#Define CF_SCALABLEONLY         000020000H
#Define CF_TTONLY               000040000H
#Define CF_NOFACESEL            000080000H
#Define CF_NOSTYLESEL           000100000H
#Define CF_NOSIZESEL            000200000H
#Define CF_SELECTSCRIPT         000400000H
#Define CF_NOSCRIPTSEL          000800000H
#Define CF_NOVERTFONTS          001000000H

#Define SIMULATED_FONTTYPE    	08000H
#Define PRINTER_FONTTYPE      	04000H
#Define SCREEN_FONTTYPE       	02000H
#Define BOLD_FONTTYPE         	00100H
#Define ITALIC_FONTTYPE       	00200H
#Define REGULAR_FONTTYPE      	00400H

#Define OPENTYPE_FONTTYPE     	010000H
#Define TYPE1_FONTTYPE        	020000H
#Define DSIG_FONTTYPE         	040000H

#Define WM_CHOOSEFONT_GETLOGFONT	(WM_USER + 1)
#Define WM_CHOOSEFONT_SETLOGFONT	(WM_USER + 101)
#Define WM_CHOOSEFONT_SETFLAGS		(WM_USER + 102)

#Define LBSELCHSTRINGA  		"commdlg_LBSelChangedNotify"
#Define SHAREVISTRINGA  		"commdlg_ShareViolation"
#Define FILEOKSTRINGA   		"commdlg_FileNameOK"
#Define COLOROKSTRINGA  		"commdlg_ColorOK"
#Define SETRGBSTRINGA   		"commdlg_SetRGBColor"
#Define HELPMSGSTRINGA  		"commdlg_help"
#Define FINDMSGSTRINGA  		"commdlg_FindReplace"

#Define LBSELCHSTRINGW  		L"commdlg_LBSelChangedNotify"
#Define SHAREVISTRINGW  		L"commdlg_ShareViolation"
#Define FILEOKSTRINGW   		L"commdlg_FileNameOK"
#Define COLOROKSTRINGW  		L"commdlg_ColorOK"
#Define SETRGBSTRINGW   		L"commdlg_SetRGBColor"
#Define HELPMSGSTRINGW  		L"commdlg_help"
#Define FINDMSGSTRINGW  		L"commdlg_FindReplace"

#Define CD_LBSELNOITEMS 		(-1)
#Define CD_LBSELCHANGE   		0
#Define CD_LBSELSUB      		1
#Define CD_LBSELADD      		2

#Define PD_ALLPAGES                    000000000H
#Define PD_SELECTION                   000000001H
#Define PD_PAGENUMS                    000000002H
#Define PD_NOSELECTION                 000000004H
#Define PD_NOPAGENUMS                  000000008H
#Define PD_COLLATE                     000000010H
#Define PD_PRINTTOFILE                 000000020H
#Define PD_PRINTSETUP                  000000040H
#Define PD_NOWARNING                   000000080H
#Define PD_RETURNDC                    000000100H
#Define PD_RETURNIC                    000000200H
#Define PD_RETURNDEFAULT               000000400H
#Define PD_SHOWHELP                    000000800H
#Define PD_ENABLEPRINTHOOK             000001000H
#Define PD_ENABLESETUPHOOK             000002000H
#Define PD_ENABLEPRINTTEMPLATE         000004000H
#Define PD_ENABLESETUPTEMPLATE         000008000H
#Define PD_ENABLEPRINTTEMPLATEHANDLE   000010000H
#Define PD_ENABLESETUPTEMPLATEHANDLE   000020000H
#Define PD_USEDEVMODECOPIES            000040000H
#Define PD_USEDEVMODECOPIESANDCOLLATE  000040000H
#Define PD_DISABLEPRINTTOFILE          000080000H
#Define PD_HIDEPRINTTOFILE             000100000H
#Define PD_NONETWORKBUTTON             000200000H

#Define DN_DEFAULTPRN      		00001H

#Define WM_PSD_PAGESETUPDLG     (WM_USER + 0)
#Define WM_PSD_FULLPAGERECT     (WM_USER + 1)
#Define WM_PSD_MINMARGINRECT    (WM_USER + 2)
#Define WM_PSD_MARGINRECT       (WM_USER + 3)
#Define WM_PSD_GREEKTEXTRECT    (WM_USER + 4)
#Define WM_PSD_ENVSTAMPRECT     (WM_USER + 5)
#Define WM_PSD_YAFULLPAGERECT   (WM_USER + 6)

#Define PSD_DEFAULTMINMARGINS             	000000000H
#Define PSD_INWININIINTLMEASURE           	000000000H

#Define PSD_MINMARGINS                    	000000001H
#Define PSD_MARGINS                       	000000002H
#Define PSD_INTHOUSANDTHSOFINCHES         	000000004H
#Define PSD_INHUNDREDTHSOFMILLIMETERS     	000000008H
#Define PSD_DISABLEMARGINS                	000000010H
#Define PSD_DISABLEPRINTER                	000000020H
#Define PSD_NOWARNING                     	000000080H
#Define PSD_DISABLEORIENTATION            	000000100H
#Define PSD_RETURNDEFAULT                 	000000400H
#Define PSD_DISABLEPAPER                  	000000200H
#Define PSD_SHOWHELP                      	000000800H
#Define PSD_ENABLEPAGESETUPHOOK           	000002000H
#Define PSD_ENABLEPAGESETUPTEMPLATE       	000008000H
#Define PSD_ENABLEPAGESETUPTEMPLATEHANDLE 	000020000H
#Define PSD_ENABLEPAGEPAINTHOOK           	000040000H
#Define PSD_DISABLEPAGEPAINTING           	000080000H
#Define PSD_NONETWORKBUTTON       			000200000H


OPENFILENAMEA Struct
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
EndS

OPENFILENAMEW Struct
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
EndS

OFNOTIFYA Struct
	hdr NMHDR <>
	lpOFN DD
	pszFile DD
EndS

OFNOTIFYW Struct
	hdr NMHDR <>
	lpOFN DD
	pszFile DD
EndS

OFNOTIFYEXA Struct
	hdr NMHDR <>
	lpOFN DD
	psf DD
	pidl DD
EndS

OFNOTIFYEXW Struct
	hdr NMHDR <>
	lpOFN DD
	psf DD
	pidl DD
EndS

CHOOSECOLORA Struct
	lStructSize DD
	hwndOwner DD
	hInstance DD
	rgbResult DD
	lpCustColors DD
	Flags DD
	lCustData DD
	lpfnHook DD
	lpTemplateName DD
EndS

CHOOSECOLORW Struct
	lStructSize DD
	hwndOwner DD
	hInstance DD
	rgbResult DD
	lpCustColors DD
	Flags DD
	lCustData DD
	lpfnHook DD
	lpTemplateName DD
EndS

FINDREPLACEA Struct
	lStructSize DD
	hwndOwner DD
	hInstance DD
	Flags DD
	lpstrFindWhat DD
	lpstrReplaceWith DD
	wFindWhatLen DW
	wReplaceWithLen DW
	lCustData DD
	lpfnHook DD
	lpTemplateName DD
EndS

FINDREPLACEW Struct
	lStructSize DD
	hwndOwner DD
	hInstance DD
	Flags DD
	lpstrFindWhat DD
	lpstrReplaceWith DD
	wFindWhatLen DW
	wReplaceWithLen DW
	lCustData DD
	lpfnHook DD
	lpTemplateName DD
EndS

CHOOSEFONTA Struct
	lStructSize DD
	hwndOwner DD
	hDC DD
	lpLogFont DD
	iPointSize DD
	Flags DD
	rgbColors DD
	lCustData DD
	lpfnHook DD
	lpTemplateName DD
	hInstance DD
	lpszStyle DD
	nFontType DW
	missAlignment DW
	nSizeMin DD
	nSizeMax DD
EndS

CHOOSEFONTW Struct
	lStructSize DD
	hwndOwner DD
	hDC DD
	lpLogFont DD
	iPointSize DD
	Flags DD
	rgbColors DD
	lCustData DD
	lpfnHook DD
	lpTemplateName DD
	hInstance DD
	lpszStyle DD
	nFontType DW
	missAlignment DW
	nSizeMin DD
	nSizeMax DD
EndS

PRINTDLGA Struct
	lStructSize DD
	hwndOwner DD
	hDevMode DD
	hDevNames DD
	hDC DD
	Flags DD
	nFromPage DW
	nToPage DW
	nMinPage DW
	nMaxPage DW
	nCopies DW
	hInstance DD
	lCustData DD
	lpfnPrintHook DD
	lpfnSetupHook DD
	lpPrintTemplateName DD
	lpSetupTemplateName DD
	hPrintTemplate DD
	hSetupTemplate DD
EndS

PRINTDLGW Struct
	lStructSize DD
	hwndOwner DD
	hDevMode DD
	hDevNames DD
	hDC DD
	Flags DD
	nFromPage DW
	nToPage DW
	nMinPage DW
	nMaxPage DW
	nCopies DW
	hInstance DD
	lCustData DD
	lpfnPrintHook DD
	lpfnSetupHook DD
	lpPrintTemplateName DD
	lpSetupTemplateName DD
	hPrintTemplate DD
	hSetupTemplate DD
EndS

DEVNAMES Struct
	wDriverOffset DW
	wDeviceOffset DW
	wOutputOffset DW
	wDefault DW
EndS

PAGESETUPDLGA Struct
	lStructSize DD
	hwndOwner DD
	hDevMode DD
	hDevNames DD
	Flags DD
	ptPaperSize POINT <>
	rtMinMargin RECT <>
	rtMargin RECT <>
	hInstance DD
	lCustData DD
	lpfnPageSetupHook DD
	lpfnPagePaintHook DD
	lpPageSetupTemplateName DD
	hPageSetupTemplate DD
EndS

PAGESETUPDLGW Struct
	lStructSize DD
	hwndOwner DD
	hDevMode DD
	hDevNames DD
	Flags DD
	ptPaperSize POINT <>
	rtMinMargin RECT <>
	rtMargin RECT <>
	hInstance DD
	lCustData DD
	lpfnPageSetupHook DD
	lpfnPagePaintHook DD
	lpPageSetupTemplateName DD
	hPageSetupTemplate DD
EndS


#IF STRINGS UNICODE
	#Define OPENFILENAME OPENFILENAMEW
	#Define GetOpenFileName GetOpenFileNameW
	#Define GetSaveFileName GetSaveFileNameW
	#Define GetFileTitle GetFileTitleW
	#Define OFNOTIFY OFNOTIFYW
	#Define OFNOTIFYEX OFNOTIFYEXW
	#Define CommDlg_OpenSave_GetSpec CommDlg_OpenSave_GetSpecW
	#Define CommDlg_OpenSave_GetFilePath CommDlg_OpenSave_GetFilePathW
	#Define CommDlg_OpenSave_GetFolderPath CommDlg_OpenSave_GetFolderPathW
	#Define CHOOSECOLOR CHOOSECOLORW
	#Define ChooseColor ChooseColorW
	#Define FINDREPLACE FINDREPLACEW
	#Define FindText FindTextW
	#Define ReplaceText ReplaceTextW
	#Define AfxReplaceText AfxReplaceTextW
	#Define CHOOSEFONT CHOOSEFONTW
	#Define ChooseFont ChooseFontW
	#Define LBSELCHSTRING LBSELCHSTRINGW
	#Define SHAREVISTRING SHAREVISTRINGW
	#Define FILEOKSTRING FILEOKSTRINGW
	#Define COLOROKSTRING COLOROKSTRINGW
	#Define SETRGBSTRING SETRGBSTRINGW
	#Define HELPMSGSTRING HELPMSGSTRINGW
	#Define FINDMSGSTRING FINDMSGSTRINGW
	#Define PRINTDLG PRINTDLGW
	#Define PrintDlg PrintDlgW
	#Define PAGESETUPDLG PAGESETUPDLGW
	#Define PageSetupDlg PageSetupDlgW
#ELSE
	#Define OPENFILENAME OPENFILENAMEA
	#Define GetOpenFileName GetOpenFileNameA
	#Define GetSaveFileName GetSaveFileNameA
	#Define GetFileTitle GetFileTitleA
	#Define OFNOTIFY OFNOTIFYA
	#Define OFNOTIFYEX OFNOTIFYEXA
	#Define CommDlg_OpenSave_GetSpec CommDlg_OpenSave_GetSpecA
	#Define CommDlg_OpenSave_GetFilePath CommDlg_OpenSave_GetFilePathA
	#Define CommDlg_OpenSave_GetFolderPath CommDlg_OpenSave_GetFolderPathA
	#Define ChooseColor ChooseColorA
	#Define FINDREPLACE FINDREPLACEA
	#Define FindText FindTextA
	#Define ReplaceText ReplaceTextA
	#Define AfxReplaceText AfxReplaceTextA
	#Define CHOOSEFONT CHOOSEFONTA
	#Define ChooseFont ChooseFontA
	#Define LBSELCHSTRING LBSELCHSTRINGA
	#Define SHAREVISTRING SHAREVISTRINGA
	#Define FILEOKSTRING FILEOKSTRINGA
	#Define COLOROKSTRING COLOROKSTRINGA
	#Define SETRGBSTRING SETRGBSTRINGA
	#Define HELPMSGSTRING HELPMSGSTRINGA
	#Define FINDMSGSTRING FINDMSGSTRINGA
	#Define PRINTDLG PRINTDLGA
	#Define PrintDlg PrintDlgA	
	#Define PAGESETUPDLG PAGESETUPDLGA
	#Define PageSetupDlg PageSetupDlgA
#ENDIF

#ENDIF ;COMMDLG_INC
