;===========================================================================
; RS Edit constants
;===========================================================================

GWL_EDITORDATA		Equ		0

RSC_PREV			Equ		1
RSC_NEXT			Equ		2

RSC_DOWN			Equ		1
RSC_MATCHCASE		Equ		2
RSC_WHOLEWORD		Equ		4


;===========================================================================
; RS Edit events
;===========================================================================

EV_CHANGE			Equ		00000001H
EV_HSCROLL			Equ		00000002H
EV_UPDATE			Equ		00000004H
EV_VSCROLL			Equ		00000008H
EV_SELCHANGE		Equ		00000010H


;===========================================================================
; RS Edit messages
;===========================================================================

RSM_CANPASTE			Equ		WM_USER + 101
RSM_CANREDO				Equ		WM_USER + 102
RSM_CANUNDO				Equ		WM_USER + 103
RSM_CLEARUNDOBUFFER		Equ		WM_USER + 104
RSM_FINDWORD			Equ		WM_USER + 105
RSM_FINDTEXT			Equ		WM_USER + 106
RSM_GETBACKCOLOR		Equ		WM_USER + 107
RSM_GETEVENTMASK		Equ		WM_USER + 108
RSM_GETFIRSTVISIBLELINE Equ		WM_USER + 109
RSM_GETHANDLE			Equ		WM_USER + 110
RSM_GETHIDESELECTION	Equ 	WM_USER + 111
RSM_GETLINE				Equ		WM_USER + 112
RSM_GETLINECOUNT		Equ		WM_USER + 113
RSM_GETLINEFROMCHAR		Equ		WM_USER + 114
RSM_GETLINEINDEX		Equ		WM_USER + 115
RSM_GETLINELENGTH		Equ		WM_USER + 116
RSM_GETMODIFY			Equ		WM_USER + 117
RSM_GETPOSITION			Equ		WM_USER + 118
RSM_GETSELBACKCOLOR		Equ		WM_USER + 119
RSM_GETMARGINCOLOR		Equ		WM_USER + 120
RSM_GETMARGINWIDTH		Equ		WM_USER + 121
RSM_GETSELECTION		Equ		WM_USER + 122
RSM_GETSELTEXT			Equ		WM_USER + 123
RSM_GETSELTEXTCOLOR		Equ		WM_USER + 124
RSM_GETTEXTCOLOR		Equ		WM_USER + 125
RSM_EDITORSCROLL		Equ		WM_USER + 126
RSM_REDO				Equ		WM_USER + 127
RSM_REPLACESEL			Equ		WM_USER + 128
RSM_SETAUTOINDENT		Equ		WM_USER + 129
RSM_SETBACKCOLOR		Equ		WM_USER + 130
RSM_SETCARETWIDTH		Equ 	WM_USER + 131
RSM_SETEVENTMASK		Equ		WM_USER + 132
RSM_SETFINDPROC			Equ		WM_USER + 133
RSM_SETHIDESELECTION	Equ 	WM_USER + 134
RSM_SETHSCROLLBAR		Equ 	WM_USER + 135
RSM_SETMODIFY			Equ		WM_USER + 136
RSM_SETPAINTPROC		Equ		WM_USER + 137
RSM_SETREADONLY 		Equ		WM_USER + 138
RSM_SETSELBACKCOLOR		Equ		WM_USER + 139
RSM_SETMARGINCOLOR		Equ		WM_USER + 140
RSM_SETMARGINWIDTH		Equ		WM_USER + 141
RSM_SETSELECTION		Equ		WM_USER + 142
RSM_SETSELTEXTCOLOR		Equ		WM_USER + 143
RSM_SETTABSTOPS 		Equ		WM_USER + 144
RSM_SETTEXTCOLOR		Equ		WM_USER + 145
RSM_SETUNDOLIMIT		Equ		WM_USER + 146
RSM_SETVSCROLLBAR		Equ 	WM_USER + 147


.Data

RSSCHARSEL Struct
	lMin DD
	lMax DD
EndS

RSSFINDTEXT Struct
	chr RSSCHARSEL <>
	lpstr DD
EndS


;===========================================================================
; Data structure for RS Edit control
;===========================================================================

EDITORDATA			Struct
	bAutoIndent			DD
	bCaret				DD
	bChanged			DD
	bHideSelection		DD
	bHScrollBar			DD
	bInsert 			DD
	bModified			DD
	bReadOnly			DD
	bSelCol				DD
	bTimer				DD
	bVScrollBar			DD
	lCaretWidth			DD
	lCols				DD
	lHScrollMax			DD
	lHScrollPos			DD
	lHScrollPage		DD
	lLines				DD
	lRealCol			DD
	lLineIndex			DD
	lFirstLineIndex 	DD
	lRealCols			DD
	lSelCol 			DD
	lMarginWidth		DD
	lTabStops			DD
	lTextLength			DD
	lBufferLength		DD
	lStart				DD
	lStartPos			DD
	lVScrollPage		DD
	lVScrollPos			DD
	dwEventMask			DD
	hWnd				DD
	hWndOwner			DD
	lStartModified		DD
	lUndoLimit			DD
	lUndoCount			DD
	lUndoStart			DD
	lpszUndoText		DD
	lpUndoBuffer		DD
	ptPos				POINTL		<>
	chrPos				RSSCHARSEL 	<>
	chrSel				RSSCHARSEL 	<>
	szFont				SIZEL		<>
	szSize				SIZEL		<>
	hFont				DD
	prFindProc			DD
	prPaintProc			DD
	crBackColor			DD
	crBackSelect		DD
	crTextColor			DD
	crTextSelect		DD
	crMarginColor		DD
	crRealBackColor		DD
	crRealTextColor 	DD
	crRealBackSelect	DD
	crRealTextSelect	DD
	crRealMarginColor	DD
	lpszLine			DD
	lpszText			DD
	lpszMemPtr			DD
EndS
