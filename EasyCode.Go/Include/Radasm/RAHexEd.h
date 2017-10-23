#IFNDEF RAHEXED_H
#DEFINE RAHEXED_H

DEFBCKCOL				equ 00C0F0F0h
DEFADRTXTCOL			equ 00800000h
DEFDTATXTCOL			equ 00000000h
DEFASCTXTCOL			equ 00008000h
DEFSELBCKCOL			equ 00800000h
DEFLFSELBCKCOL			equ 00C0C0C0h
DEFSELTXTCOL			equ 00FFFFFFh
DEFSELASCCOL			equ 00C0C0C0h
DEFSELBARCOL			equ 00C0C0C0h
DEFSELBARPEN			equ 00808080h
DEFLNRCOL				equ 00800000h

HEM_RAINIT				equ WM_USER+9999	;wParam=0, lParam=pointer to controls DIALOG struct
HEM_BASE				equ WM_USER+1000

;Private messages
HEM_SETFONT				equ HEM_BASE+1		;wParam=nLineSpacing, lParam=lpHEFONT
HEM_GETFONT				equ HEM_BASE+2		;wParam=0, lParam=lpHEFONT
HEM_SETCOLOR			equ HEM_BASE+3		;wParam=0, lParam=lpHECOLOR
HEM_GETCOLOR			equ HEM_BASE+4		;wParam=0, lParam=lpHECOLOR
HEM_VCENTER				equ HEM_BASE+5		;wParam=0, lParam=0
HEM_REPAINT				equ HEM_BASE+6		;wParam=0, lParam=0
HEM_ANYBOOKMARKS		equ HEM_BASE+7		;wParam=0, lParam=0
HEM_TOGGLEBOOKMARK		equ HEM_BASE+8		;wParam=nLine, lParam=0
HEM_CLEARBOOKMARKS		equ HEM_BASE+9		;wParam=0, lParam=0
HEM_NEXTBOOKMARK		equ HEM_BASE+10		;wParam=0, lParam=0
HEM_PREVIOUSBOOKMARK	equ HEM_BASE+11		;wParam=0, lParam=0
HEM_SELBARWIDTH			equ HEM_BASE+12		;wParam=nWidth, lParam=0
HEM_LINENUMBERWIDTH		equ HEM_BASE+13		;wParam=nWidth, lParam=0
HEM_SETSPLIT			equ HEM_BASE+14		;wParam=nSplitt, lParam=0
HEM_GETSPLIT			equ HEM_BASE+15		;wParam=0, lParam=0
HEM_GETBYTE				equ HEM_BASE+16		;wParam=cp, lParam=0
HEM_SETBYTE				equ HEM_BASE+16		;wParam=cp, lParam=ByteVal
HEM_GETOFFSET			equ HEM_BASE+17		;wParam=0, lParam=0
HEM_SETOFFSET			equ HEM_BASE+18		;wParam=ofs, lParam=0

FR_HEX					equ 2

HEX_STYLE_NOSPLITT		equ 001h			;No splitt button
HEX_STYLE_NOLINENUMBER	equ 002h			;No linenumber button
HEX_STYLE_NOHSCROLL		equ 004h			;No horizontal scrollbar
HEX_STYLE_NOVSCROLL		equ 008h			;No vertical scrollbar
HEX_STYLE_NOSIZEGRIP	equ 010h			;No size grip
HEX_STYLE_NOSTATE		equ 020h			;No state indicator
HEX_STYLE_NOADDRESS		equ 040h			;No adress field
HEX_STYLE_NOASCII		equ 080h			;No ascii field
HEX_STYLE_NOUPPERCASE	equ 100h			;Hex numbers is lowercase letters
HEX_STYLE_READONLY		equ 200h			;Text is locked

HEFONT struct
	hFont			dd		;Code edit normal
	hLnrFont		dd		;Line numbers
ENDS

HECOLOR struct
	bckcol			dd		;Back color
	adrtxtcol		dd		;Text color
	dtatxtcol		dd		;Text color
	asctxtcol		dd		;Text color
	selbckcol		dd		;Sel back color
	sellfbckcol		dd		;Sel lost focus back color
	seltxtcol		dd		;Sel text color
	selascbckcol	dd		;Sel back color
	selbarbck		dd		;Selection bar
	selbarpen		dd		;Selection bar pen
	lnrcol			dd		;Line numbers color
ENDS

HESELCHANGE struct
	nmhdr			NMHDR
	chrg			CHARRANGE
	seltyp			dw		;SEL_TEXT or SEL_OBJECT
					dw
	line			dd		;Line number
	nlines			dd		;Total number of lines
	fchanged		dd		;TRUE if changed since last
ENDS

HEBMK struct
	hWin			dd		;Handle of window having the bookmark
	nLine			dd		;Bokkmarked line
ENDS

;.const

szRAHexEdClassName	equ 'RAHEXEDIT',0
szHexChildClassName	equ 'RAHEXEDITCHILD',0
#ENDIF