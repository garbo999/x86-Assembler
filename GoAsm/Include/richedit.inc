;=============================================================;
;          richedit.inc file for Easy Code visual IDE         ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF RICHEDIT_INC
#Define RICHEDIT_INC

#Define cchTextLimitDefault			32767

#Define _WPAD						DW
#Define LCID						DD

#Define RICHEDIT_CLASSA				"RichEdit20A"
#Define RICHEDIT_CLASSW				L"RichEdit20W"

#IFNDEF WM_CONTEXTMENU
	#Define WM_CONTEXTMENU			007BH
#ENDIF

#IFNDEF WM_PRINTCLIENT
	#Define WM_PRINTCLIENT			0318H
#ENDIF

#IFNDEF EM_GETLIMITTEXT
	#Define EM_GETLIMITTEXT			(WM_USER + 37)
#ENDIF

#IFNDEF EM_POSFROMCHAR
	#Define EM_POSFROMCHAR			(WM_USER + 38)
	#Define EM_CHARFROMPOS			(WM_USER + 39)
#ENDIF

#IFNDEF EM_SCROLLCARET
	#Define EM_SCROLLCARET			(WM_USER + 49)
#ENDIF

#Define EM_CANPASTE					(WM_USER + 50)
#Define EM_DISPLAYBAND				(WM_USER + 51)
#Define EM_EXGETSEL					(WM_USER + 52)
#Define EM_EXLIMITTEXT				(WM_USER + 53)
#Define EM_EXLINEFROMCHAR			(WM_USER + 54)
#Define EM_EXSETSEL					(WM_USER + 55)
#Define EM_FINDTEXT					(WM_USER + 56)
#Define EM_FORMATRANGE				(WM_USER + 57)
#Define EM_GETCHARFORMAT			(WM_USER + 58)
#Define EM_GETEVENTMASK				(WM_USER + 59)
#Define EM_GETOLEINTERFACE			(WM_USER + 60)
#Define EM_GETPARAFORMAT			(WM_USER + 61)
#Define EM_GETSELTEXT				(WM_USER + 62)
#Define EM_HIDESELECTION			(WM_USER + 63)
#Define EM_PASTESPECIAL				(WM_USER + 64)
#Define EM_REQUESTRESIZE			(WM_USER + 65)
#Define EM_SELECTIONTYPE			(WM_USER + 66)
#Define EM_SETBKGNDCOLOR			(WM_USER + 67)
#Define EM_SETCHARFORMAT			(WM_USER + 68)
#Define EM_SETEVENTMASK				(WM_USER + 69)
#Define EM_SETOLECALLBACK			(WM_USER + 70)
#Define EM_SETPARAFORMAT			(WM_USER + 71)
#Define EM_SETTARGETDEVICE			(WM_USER + 72)
#Define EM_STREAMIN					(WM_USER + 73)
#Define EM_STREAMOUT				(WM_USER + 74)
#Define EM_GETTEXTRANGE				(WM_USER + 75)
#Define EM_FINDWORDBREAK			(WM_USER + 76)
#Define EM_SETOPTIONS				(WM_USER + 77)
#Define EM_GETOPTIONS				(WM_USER + 78)
#Define EM_FINDTEXTEX				(WM_USER + 79)
#Define EM_GETWORDBREAKPROCEX		(WM_USER + 80)
#Define EM_SETWORDBREAKPROCEX		(WM_USER + 81)

#Define EM_SETUNDOLIMIT				(WM_USER + 82)
#Define EM_REDO						(WM_USER + 84)
#Define EM_CANREDO					(WM_USER + 85)
#Define EM_GETUNDONAME				(WM_USER + 86)
#Define EM_GETREDONAME				(WM_USER + 87)
#Define EM_STOPGROUPTYPING			(WM_USER + 88)

#Define EM_SETTEXTMODE				(WM_USER + 89)
#Define EM_GETTEXTMODE				(WM_USER + 90)

;TEXTMODE enuneration
TM_PLAINTEXT						Equ 1
TM_RICHTEXT							Equ 2
TM_SINGLELEVELUNDO					Equ 4
TM_MULTILEVELUNDO					Equ 8
TM_SINGLECODEPAGE					Equ 16
TM_MULTICODEPAGE					Equ 32

#Define EM_AUTOURLDETECT			(WM_USER + 91)
#Define EM_GETAUTOURLDETECT			(WM_USER + 92)
#Define EM_SETPALETTE				(WM_USER + 93)
#Define EM_GETTEXTEX				(WM_USER + 94)
#Define EM_GETTEXTLENGTHEX			(WM_USER + 95)

#Define EM_SETPUNCTUATION			(WM_USER + 100)
#Define EM_GETPUNCTUATION			(WM_USER + 101)
#Define EM_SETWORDWRAPMODE			(WM_USER + 102)
#Define EM_GETWORDWRAPMODE			(WM_USER + 103)
#Define EM_SETIMECOLOR				(WM_USER + 104)
#Define EM_GETIMECOLOR				(WM_USER + 105)
#Define EM_SETIMEOPTIONS			(WM_USER + 106)
#Define EM_GETIMEOPTIONS			(WM_USER + 107)
#Define EM_CONVPOSITION 			(WM_USER + 108)

#Define EM_SETLANGOPTIONS			(WM_USER + 120)
#Define EM_GETLANGOPTIONS			(WM_USER + 121)
#Define EM_GETIMECOMPMODE			(WM_USER + 122)

#Define IMF_AUTOKEYBOARD			0001H
#Define IMF_AUTOFONT				0002H
#Define IMF_IMECANCELCOMPLETE		0004H
#Define IMF_IMEALWAYSSENDNOTIFY 	0008H

#Define ICM_NOTOPEN					0000H
#Define ICM_LEVEL3					0001H
#Define ICM_LEVEL2					0002H
#Define ICM_LEVEL2_5				0003H
#Define ICM_LEVEL2_SUI				0004H

#Define EN_MSGFILTER				0700H
#Define EN_REQUESTRESIZE			0701H
#Define EN_SELCHANGE				0702H
#Define EN_DROPFILES				0703H
#Define EN_PROTECTED				0704H
#Define EN_CORRECTTEXT				0705H
#Define EN_STOPNOUNDO				0706H
#Define EN_IMECHANGE				0707H
#Define EN_SAVECLIPBOARD			0708H
#Define EN_OLEOPFAILED				0709H
#Define EN_OBJECTPOSITIONS			070AH
#Define EN_LINK						070BH
#Define EN_DRAGDROPDONE				070CH

#Define ENM_NONE					00000000H
#Define ENM_CHANGE					00000001H
#Define ENM_UPDATE					00000002H
#Define ENM_SCROLL					00000004H
#Define ENM_KEYEVENTS				00010000H
#Define ENM_MOUSEEVENTS				00020000H
#Define ENM_REQUESTRESIZE			00040000H
#Define ENM_SELCHANGE				00080000H
#Define ENM_DROPFILES				00100000H
#Define ENM_PROTECTED				00200000H
#Define ENM_CORRECTTEXT				00400000H
#Define ENM_SCROLLEVENTS			00000008H
#Define ENM_DRAGDROPDONE			00000010H

#Define ENM_IMECHANGE				00800000H
#Define ENM_LANGCHANGE				01000000H
#Define ENM_OBJECTPOSITIONS			02000000H
#Define ENM_LINK					04000000H

#Define ES_SAVESEL					00008000H
#Define ES_SUNKEN					00004000H
#Define ES_DISABLENOSCROLL			00002000H

#Define ES_SELECTIONBAR				01000000H

#Define ES_NOOLEDRAGDROP			00000008H

#Define ES_EX_NOCALLOLEINIT			01000000H

#Define ES_VERTICAL					00400000H
#Define ES_NOIME					00080000H
#Define ES_SELFIME					00040000H

#Define ECO_AUTOWORDSELECTION		00000001H
#Define ECO_AUTOVSCROLL				00000040H
#Define ECO_AUTOHSCROLL				00000080H
#Define ECO_NOHIDESEL				00000100H
#Define ECO_READONLY				00000800H
#Define ECO_WANTRETURN				00001000H
#Define ECO_SAVESEL					00008000H
#Define ECO_SELECTIONBAR			01000000H
#Define ECO_VERTICAL				00400000H


#Define ECOOP_SET					0001H
#Define ECOOP_OR					0002H
#Define ECOOP_AND					0003H
#Define ECOOP_XOR					0004H

#Define WB_CLASSIFY					3
#Define WB_MOVEWORDLEFT				4
#Define WB_MOVEWORDRIGHT			5
#Define WB_LEFTBREAK				6
#Define WB_RIGHTBREAK				7

#Define WB_MOVEWORDPREV				4
#Define WB_MOVEWORDNEXT				5
#Define WB_PREVBREAK				6
#Define WB_NEXTBREAK				7

#Define PC_FOLLOWING				1
#Define PC_LEADING					2
#Define PC_OVERFLOW					3
#Define PC_DELIMITER				4
#Define WBF_WORDWRAP				010H
#Define WBF_WORDBREAK				020H
#Define WBF_OVERFLOW				040H
#Define WBF_LEVEL1					080H
#Define WBF_LEVEL2					100H
#Define WBF_CUSTOM					200H

#Define IMF_FORCENONE           	0001H
#Define IMF_FORCEENABLE         	0002H
#Define IMF_FORCEDISABLE        	0004H
#Define IMF_CLOSESTATUSWINDOW   	0008H
#Define IMF_VERTICAL            	0020H
#Define IMF_FORCEACTIVE         	0040H
#Define IMF_FORCEINACTIVE       	0080H
#Define IMF_FORCEREMEMBER       	0100H
#Define IMF_MULTIPLEEDIT        	0400H

#Define WBF_CLASS					0FH
#Define WBF_ISWHITE					10H
#Define WBF_BREAKLINE				20H
#Define WBF_BREAKAFTER				40H

#Define CFM_BOLD					00000001H
#Define CFM_ITALIC					00000002H
#Define CFM_UNDERLINE				00000004H
#Define CFM_STRIKEOUT				00000008H
#Define CFM_PROTECTED				00000010H
#Define CFM_LINK					00000020H
#Define CFM_SIZE					80000000H
#Define CFM_COLOR					40000000H
#Define CFM_FACE					20000000H
#Define CFM_OFFSET					10000000H
#Define CFM_CHARSET					08000000H

#Define CFE_BOLD					0001H
#Define CFE_ITALIC					0002H
#Define CFE_UNDERLINE				0004H
#Define CFE_STRIKEOUT				0008H
#Define CFE_PROTECTED				0010H
#Define CFE_LINK					0020H
#Define CFE_AUTOCOLOR				40000000H

#Define yHeightCharPtsMost			1638

#Define SCF_SELECTION				0001H
#Define SCF_WORD					0002H
#Define SCF_DEFAULT					0000H
#Define SCF_ALL						0004H
#Define SCF_USEUIRULES				0008H

#Define SF_TEXT						0001H
#Define SF_RTF						0002H
#Define SF_RTFNOOBJS				0003H
#Define SF_TEXTIZED					0004H
#Define SF_UNICODE					0010H

#Define SFF_SELECTION				8000H

#Define SFF_PLAINRTF				4000H

#Define MAX_TAB_STOPS				32
#Define lDefaultTab					720

#Define PFM_STARTINDENT				00000001H
#Define PFM_RIGHTINDENT				00000002H
#Define PFM_OFFSET					00000004H
#Define PFM_ALIGNMENT				00000008H
#Define PFM_TABSTOPS				00000010H
#Define PFM_NUMBERING				00000020H
#Define PFM_OFFSETINDENT			80000000H

#Define PFN_BULLET					0001H

#Define PFA_LEFT					0001H
#Define PFA_RIGHT					0002H
#Define PFA_CENTER					0003H

#Define CHARFORMATDELTA				(SizeOf CHARFORMAT2A - SizeOf CHARFORMATA)

#Define CFM_EFFECTS					(CFM_BOLD | CFM_ITALIC | CFM_UNDERLINE | CFM_COLOR | CFM_STRIKEOUT | CFE_PROTECTED | CFM_LINK)
#Define CFM_ALL						(CFM_EFFECTS | CFM_SIZE | CFM_FACE | CFM_OFFSET | CFM_CHARSET)

#Define PFM_ALL						(PFM_STARTINDENT | PFM_RIGHTINDENT | PFM_OFFSET | PFM_ALIGNMENT | PFM_TABSTOPS | PFM_NUMBERING | PFM_OFFSETINDENT)

#Define CFM_SMALLCAPS				0040H
#Define CFM_ALLCAPS					0080H
#Define CFM_HIDDEN					0100H
#Define CFM_OUTLINE					0200H
#Define CFM_SHADOW					0400H
#Define CFM_EMBOSS					0800H
#Define CFM_IMPRINT					1000H
#Define CFM_DISABLED				2000H
#Define CFM_REVISED					4000H

#Define CFM_BACKCOLOR				04000000H
#Define CFM_LCID					02000000H
#Define CFM_UNDERLINETYPE			00800000H
#Define CFM_WEIGHT					00400000H
#Define CFM_SPACING					00200000H
#Define CFM_KERNING					00100000H
#Define CFM_STYLE					00080000H
#Define CFM_ANIMATION				00040000H
#Define CFM_REVAUTHOR				00008000H

#Define CFE_SUBSCRIPT				00010000H
#Define CFE_SUPERSCRIPT				00020000H

#Define CFM_SUBSCRIPT				(CFE_SUBSCRIPT | CFE_SUPERSCRIPT)
#Define CFM_SUPERSCRIPT				CFM_SUBSCRIPT

#Define CFM_EFFECTS2				(CFM_EFFECTS | CFM_DISABLED | CFM_SMALLCAPS | CFM_ALLCAPS | CFM_HIDDEN | CFM_OUTLINE | CFM_SHADOW | CFM_EMBOSS | CFM_IMPRINT | CFM_DISABLED | CFM_REVISED | CFM_SUBSCRIPT | CFM_SUPERSCRIPT | CFM_BACKCOLOR)

#Define CFM_ALL2					(CFM_ALL | CFM_EFFECTS2 | CFM_BACKCOLOR | CFM_LCID | CFM_UNDERLINETYPE | CFM_WEIGHT | CFM_REVAUTHOR | CFM_SPACING | CFM_KERNING | CFM_STYLE | CFM_ANIMATION)

#Define CFE_SMALLCAPS				CFM_SMALLCAPS
#Define CFE_ALLCAPS					CFM_ALLCAPS
#Define CFE_HIDDEN					CFM_HIDDEN
#Define CFE_OUTLINE					CFM_OUTLINE
#Define CFE_SHADOW					CFM_SHADOW
#Define CFE_EMBOSS					CFM_EMBOSS
#Define CFE_IMPRINT					CFM_IMPRINT
#Define CFE_DISABLED				CFM_DISABLED
#Define CFE_REVISED					CFM_REVISED

#Define CFE_AUTOBACKCOLOR			CFM_BACKCOLOR

#Define CFU_CF1UNDERLINE			0FFH
#Define CFU_INVERT					0FEH
#Define CFU_UNDERLINEDOTTED			4H
#Define CFU_UNDERLINEDOUBLE			3H
#Define CFU_UNDERLINEWORD			2H
#Define CFU_UNDERLINE				1H
#Define CFU_UNDERLINENONE			0H

#Define wEffects					wReserved

#Define PFM_SPACEBEFORE				00000040H
#Define PFM_SPACEAFTER				00000080H
#Define PFM_LINESPACING				00000100H
#Define PFM_STYLE					00000400H
#Define PFM_BORDER					00000800H
#Define PFM_SHADING					00001000H
#Define PFM_NUMBERINGSTYLE			00002000H
#Define PFM_NUMBERINGTAB			00004000H
#Define PFM_NUMBERINGSTART			00008000H

#Define PFM_RTLPARA					00010000H
#Define PFM_KEEP					00020000H
#Define PFM_KEEPNEXT				00040000H
#Define PFM_PAGEBREAKBEFORE			00080000H
#Define PFM_NOLINENUMBER			00100000H
#Define PFM_NOWIDOWCONTROL			00200000H
#Define PFM_DONOTHYPHEN				00400000H
#Define PFM_SIDEBYSIDE				00800000H

#Define PFM_TABLE					0C0000000H

#Define PFM_EFFECTS					(PFM_RTLPARA | PFM_KEEP | PFM_KEEPNEXT | PFM_TABLE | PFM_PAGEBREAKBEFORE | PFM_NOLINENUMBER | PFM_NOWIDOWCONTROL | PFM_DONOTHYPHEN | PFM_SIDEBYSIDE | PFM_TABLE)

#Define PFM_ALL2					(PFM_ALL | PFM_EFFECTS | PFM_SPACEBEFORE | PFM_SPACEAFTER | PFM_LINESPACING | PFM_STYLE | PFM_SHADING | PFM_BORDER | PFM_NUMBERINGTAB | PFM_NUMBERINGSTART | PFM_NUMBERINGSTYLE)

#Define PFE_RTLPARA					(PFM_RTLPARA>>16)
#Define PFE_KEEP					(PFM_KEEP>>16)
#Define PFE_KEEPNEXT				(PFM_KEEPNEXT>>16)
#Define PFE_PAGEBREAKBEFORE			(PFM_PAGEBREAKBEFORE>>16)
#Define PFE_NOLINENUMBER			(PFM_NOLINENUMBER>>16)
#Define PFE_NOWIDOWCONTROL			(PFM_NOWIDOWCONTROL>>16)
#Define PFE_DONOTHYPHEN				(PFM_DONOTHYPHEN>>16)
#Define PFE_SIDEBYSIDE				(PFM_SIDEBYSIDE>>16)

#Define PFE_TABLEROW				0C000H
#Define PFE_TABLECELLEND			08000H
#Define PFE_TABLECELL				04000H

#Define PFA_JUSTIFY					4

#IFNDEF WM_NOTIFY
	#Define WM_NOTIFY				004EH
	NMHDR Struct
		hwndFrom DD
		_wPad1 DW
		idFrom DD
		_wPad2 DW
		code DD
		_wPad3 DW
	EndS
#ENDIF

#Define SEL_EMPTY					0000H
#Define SEL_TEXT					0001H
#Define SEL_OBJECT					0002H
#Define SEL_MULTICHAR				0004H
#Define SEL_MULTIOBJECT				0008H

#Define GCM_RIGHTMOUSEDROP  		8000H

#Define OLEOP_DOVERB				1

#IF STRINGS UNICODE
	#Define CF_RTF 					L"Rich Text Format"
	#Define CF_RTFNOOBJS 			L"Rich Text Format Without Objects"
	#Define CF_RETEXTOBJ 			L"RichEdit Text and Objects"
#ELSE
	#Define CF_RTF 					"Rich Text Format"
	#Define CF_RTFNOOBJS 			"Rich Text Format Without Objects"
	#Define CF_RETEXTOBJ 			"RichEdit Text and Objects"
#ENDIF

REPASTESPECIAL Struct
	dwAspect DD
	dwParam DD
EndS

#Define UID_UNKNOWN					0
#Define UID_TYPING					1
#Define UID_DELETE					2
#Define UID_DRAGDROP				3
#Define UID_CUT						4
#Define UID_PASTE					5

#Define GT_DEFAULT					0
#Define GT_USECRLF					1

#Define GTL_DEFAULT					0
#Define GTL_USECRLF					1
#Define GTL_PRECISE					2
#Define GTL_CLOSE					4
#Define GTL_NUMCHARS				8
#Define GTL_NUMBYTES				16


CHARFORMATA Struct
	cbSize DD
	_wPad1 DW
	dwMask DD
	dwEffects DD
	yHeight DD
	yOffset DD
	crTextColor DD
	bCharSet DB
	bPitchAndFamily DB
	szFaceName DB LF_FACESIZE Dup ?
	_wPad2 DW
EndS

CHARFORMATW Struct
	cbSize DD
	_wPad1 DW
	dwMask DD
	dwEffects DD
	yHeight DD
	yOffset DD
	crTextColor DD
	bCharSet DB
	bPitchAndFamily DB
	szFaceName DW LF_FACESIZE Dup ?
	_wPad2 DW
EndS

CHARRANGE Struct
	cpMin DD
	cpMax DD
EndS

TEXTRANGEA Struct
	chrg CHARRANGE <>
	lpstrText DD
EndS

TEXTRANGEW Struct
	chrg CHARRANGE <>
	lpstrText DD
EndS

EDITSTREAM Struct
	dwCookie DD
	dwError DD
	pfnCallback DD
EndS

FINDTEXTA Struct
	chrg CHARRANGE <>
	lpstrText DD
EndS

FINDTEXTW Struct
	chrg CHARRANGE <>
	lpstrText DD
EndS

FINDTEXTEXA Struct
	chrg CHARRANGE <>
	lpstrText DD
	chrgText CHARRANGE <>
EndS

FINDTEXTEXW Struct
	chrg CHARRANGE <>
	lpstrText DD
	chrgText CHARRANGE <>
EndS

FORMATRANGE Struct
	hdc DD
	hdcTarget DD
	rc RECT <>
	rcPage RECT <>
	chrg CHARRANGE <>
EndS

PARAFORMAT Struct
	cbSize DD
	_wPad1 DW
	dwMask DD
	wNumbering DW
	wReserved DW
	dxStartIndent DD
	dxRightIndent DD
	dxOffset DD
	wAlignment DW
	cTabCount DW
	rgxTabs DD MAX_TAB_STOPS Dup ?
EndS

CHARFORMAT2A Struct
	cbSize DD
	_wPad1 DW
	dwMask DD
	dwEffects DD
	yHeight DD
	yOffset DD
	crTextColor DD
	bCharSet DB
	bPitchAndFamily DB
	szFaceName DB LF_FACESIZE Dup ?
	_wPad2 DW
	wWeight DW
	sSpacing DW
	crBackColor DD
	lcid LCID
	dwReserved DD
	sStyle DW
	wKerning DW
	bUnderlineType DB
	bAnimation DB
	bRevAuthor DB
	bReserved1 DB
EndS

CHARFORMAT2W Struct
	cbSize DD
	_wPad1 DW
	dwMask DD
	dwEffects DD
	yHeight DD
	yOffset DD
	crTextColor DD
	bCharSet DB
	bPitchAndFamily DB
	szFaceName DW LF_FACESIZE Dup ?
	_wPad2 DW
	wWeight DW
	sSpacing DW
	crBackColor DD
	lcid LCID
	dwReserved DD
	sStyle DW
	wKerning DW
	bUnderlineType DB
	bAnimation DB
	bRevAuthor DB
	bReserved1 DB
EndS

PARAFORMAT2 Struct
	cbSize DD
	_wPad1 DW
	dwMask DD
	wNumbering DW
	wReserved DW
	dxStartIndent DD
	dxRightIndent DD
	dxOffset DD
	wAlignment DW
	cTabCount DW
	rgxTabs	DD MAX_TAB_STOPS Dup ?
 	dySpaceBefore DD
	dySpaceAfter DD
	dyLineSpacing DD
	sStyle DW
	bLineSpacingRule DB
	bCRC DB
	wShadingWeight DW
	wShadingStyle DW
	wNumberingStart DW
	wNumberingStyle DW
	wNumberingTab DW
	wBorderSpace DW
	wBorderWidth DW
	wBorders DW
EndS

MSGFILTER Struct
	nmhdr NMHDR <>
	msg DD
	_wPad1 DW
	wParam DD
	_wPad2 DW
	lParam DD
EndS

REQRESIZE Struct
	nmhdr NMHDR <>
	rc RECT <>
EndS

SELCHANGE Struct
	nmhdr NMHDR <>
	chrg CHARRANGE <>
	seltyp DW
EndS

ENDROPFILES Struct
	nmhdr NMHDR <>
	hDrop DD
	cp DD
	fProtected DD
EndS

ENPROTECTED Struct
	nmhdr NMHDR <>
	msg DD
	_wPad1 DW
	wParam DD
	_wPad2 DW
	lParam DD
	chrg CHARRANGE <>
EndS

ENSAVECLIPBOARD Struct
	nmhdr NMHDR <>
	cObjectCount DD
	cch DD
EndS

OBJECTPOSITIONS Struct
	nmhdr NMHDR <>
	cObjectCount DD
	pcpPositions DD
EndS

ENLINK Struct
	nmhdr NMHDR <>
	msg DD
	_wPad1 DW
	wParam DD
	_wPad2 DW
	lParam DD
	chrg CHARRANGE <>
EndS

ENCORRECTTEXT Struct
	nmhdr NMHDR <>
	chrg CHARRANGE <>
	seltyp DW
EndS

PUNCTUATION Struct
	iSize DD
	szPunctuation DD
EndS

COMPCOLOR Struct
	crText DD
	crBackground DD
	dwEffects DD
EndS

GETTEXTEX Struct
	cb DD
	flags DD
	codepage DD
	lpDefaultChar DD
	lpUsedDefChar DD
EndS

GETTEXTLENGTHEX Struct
	flags DD
	codepage DD
EndS


#IF STRINGS UNICODE
	#Define RICHEDIT_CLASS RICHEDIT_CLASSW
	#Define CHARFORMAT CHARFORMATW
	#Define TEXTRANGE TEXTRANGEW
	#Define FindText FINDTEXTW
	#Define FINDTEXTEX FINDTEXTEXW
	#Define CHARFORMAT2 CHARFORMAT2W
#ELSE
	#Define RICHEDIT_CLASS RICHEDIT_CLASSA
	#Define CHARFORMAT CHARFORMATA
	#Define TEXTRANGE TEXTRANGEA
	#Define FindText FINDTEXTA
	#Define FINDTEXTEX FINDTEXTEXA
	#Define CHARFORMAT2 CHARFORMAT2A
#ENDIF

#IFNDEF WCH_EMBEDDING
	#Define WCH_EMBEDDING			0FFFCH
#ENDIF

#ENDIF ;RICHEDIT_INC
