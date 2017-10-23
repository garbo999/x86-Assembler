;===========================================================================
; Object type constants
;===========================================================================
ecDialogBox				Equ		1
ecMDIWindow				Equ		2
ecWindow				Equ		3
ecStatic				Equ		4
ecEdit					Equ		5
ecGroup					Equ		6
ecButton				Equ		7
ecCheck					Equ		8
ecRadio					Equ		9
ecList					Equ		10
ecCombo					Equ		11
ecPicture				Equ		12
ecImage					Equ		13
ecHScroll				Equ		14
ecVScroll				Equ		15
ecRichEdit				Equ		16
ecTreeView				Equ		17
ecListView				Equ		18
ecToolBar				Equ		19
ecStatusBar				Equ		20
ecProgressBar			Equ		21
ecSlider				Equ		22
ecTabStrip	 			Equ		23
ecUpDown				Equ		24
ecAnimate				Equ		25
ecIpAddress				Equ		26
ecImageCombo			Equ		27
ecCalendar				Equ		28
ecDateTime				Equ		29
ecHotKey				Equ		30
ecPager					Equ		31
ecImageList				Equ		32
ecHeader				Equ		33
ecRebar					Equ		34
ecUser					Equ		50


;===========================================================================
; Registry constants
;===========================================================================
ecClassesRoot			Equ		HKEY_CLASSES_ROOT
ecCurrentUser			Equ		HKEY_CURRENT_USER
ecLocalMachine			Equ		HKEY_LOCAL_MACHINE
ecUsers					Equ		HKEY_USERS
ecPerformanceData		Equ		HKEY_PERFORMANCE_DATA
ecCurrentConfig			Equ		HKEY_CURRENT_CONFIG
ecDynData				Equ		HKEY_DYN_DATA


;===========================================================================
; Scale mode constants
;===========================================================================
ecPixels				Equ		0
ecTwips					Equ		1


;===========================================================================
; Mouse cursor constants
;===========================================================================
ecDefault				Equ		0
ecArrow					Equ		1
ecIBeam					Equ		2
ecWait					Equ		3
ecCross					Equ		4
ecUpArrow				Equ		5
ecSizeAll				Equ		6
ecSizeNWSE				Equ		7
ecSizeNESW				Equ		8
ecSizeWE				Equ		9
ecSizeNS				Equ		10
ecNoDrop				Equ		11
ecAppStarting			Equ		12
ecHelp					Equ		13
ecCustom				Equ		14


;===========================================================================
; Drawing style constants
;===========================================================================
ecSolid					Equ		0
ecDash					Equ		1
ecDot					Equ		2
ecDashDot				Equ		3
ecDashDotDot			Equ		4
ecNull					Equ		5
ecInsideFrame			Equ		6


;===========================================================================
; Align constants
;===========================================================================
ecNone					Equ		0
ecAlignTop				Equ		1
ecAlignBottom			Equ		2
ecAlignLeft				Equ		3
ecAlignRight			Equ		4


;===========================================================================
; Scroll bars constants
;===========================================================================
ecNone					Equ		0
ecHorizontal			Equ		1
ecVertical				Equ		2
ecBoth					Equ		3


;===========================================================================
; Show mode constants
;===========================================================================
ecHidden				Equ		(-1)
ecNormal				Equ		0
ecMinimized				Equ		1
ecMaximized				Equ		2

;===========================================================================
; Mode constants
;===========================================================================
ecModeless				Equ		0
ecModal					Equ		1


;===========================================================================
; Center Window constants
;===========================================================================
ecLeft					Equ		0
ecCenter				Equ		1
ecRight					Equ		2


;===========================================================================
; OS System constants
;===========================================================================
ecWin95					Equ		1
ecWin98					Equ		2
ecWinME					Equ		2
ecWinNT					Equ		3
ecWin2K					Equ		4
ecWinXP					Equ		5
ecWinVista				Equ		6
ecWin7					Equ		7
ecWinSeven				Equ		7
ecWin8					Equ		8


;===========================================================================
; String method constants
;===========================================================================
ecBinary				Equ		0
ecDecimal				Equ		1
ecHexa					Equ		2
ecOctal					Equ		3


;===========================================================================
; Open text file constants
;===========================================================================
ecRead					Equ		GENERIC_READ
ecWrite					Equ		GENERIC_WRITE

ecCreateNew				Equ		CREATE_NEW
ecCreateAlways			Equ		CREATE_ALWAYS
ecOpenExisting			Equ		OPEN_EXISTING
ecOpenAlways			Equ		OPEN_ALWAYS
ecTruncateExisting		Equ		TRUNCATE_EXISTING


;===========================================================================
; Easy Code messages
;===========================================================================
ECM_LINKCLICKED			Equ		(WM_USER + 1030)
ECM_LINKPUSHED			Equ		ECM_LINKCLICKED
ECM_AFTERCREATE			Equ		(WM_USER + 1049)
ECM_REDRAWBACKGROUND	Equ		(WM_USER + 1054)


;===========================================================================
; Object properties enumeration
;===========================================================================
p_Align					Equ		0
p_AutoSize				Equ		4
p_BackColor				Equ		8
p_crBackColor			Equ		12
p_Brush					Equ		16
p_CaseStyle				Equ		20
p_Center				Equ		24
p_CursorIcon			Equ		28
p_CursorShape			Equ		32
p_DisableClose			Equ		36
p_DrawingStyle			Equ		40
p_DrawingWidth			Equ		44
p_Enabled				Equ		48
p_Focus					Equ		52
p_Font					Equ		56
p_FontBold				Equ		60
p_FontItalic			Equ		64
p_FontName				Equ		68
p_FontSize				Equ		72
p_FontStrikethru		Equ		76
p_FontUnderline			Equ		80
p_ForeColor				Equ		84
p_crForeColor			Equ		88
p_Height				Equ		92
p_hWnd					Equ		96
p_hWndClient			Equ		100
p_IconBig				Equ		104
p_IconSmall				Equ		108
p_ImageHeight			Equ		112
p_ImageType				Equ		116
p_ImageWidth			Equ		120
p_KeepSize				Equ		124
p_Left					Equ		128
p_Main					Equ		132
p_MaxLength				Equ		136
p_MDIChild				Equ		140
p_Menu					Equ		144
p_Name					Equ		148
p_NoPrefix				Equ		152
p_Offset				Equ		156
p_Parent				Equ		160
p_PasswordChar			Equ		164
p_Pen					Equ		168
p_Picture				Equ		172
p_RightToLeft			Equ		176
p_ScaleMode				Equ		180
p_ScrollBars			Equ		184
p_ShowMode				Equ		188
p_Stretch				Equ		192
p_TabOrder				Equ		196
p_TabStop				Equ		200
p_Text					Equ		204
p_TextAlignment			Equ		208
p_TextLength			Equ		212
p_Timer					Equ		216
p_TimerID				Equ		220
p_Top					Equ		224
p_Transparent			Equ		228
p_Type					Equ		232
p_Value					Equ		236
p_Visible				Equ		240
p_Width					Equ		244
p_WindowProc			Equ		248
p_WndOldControlProc		Equ		252
p_DialogID				Equ		256
p_Children				Equ		260
p_DefButton				Equ		264
p_ExStyle				Equ		268
p_Style					Equ		272
p_ButtonStruct			Equ		276
p_OldFont				Equ		280
p_ToolTip				Equ		284
p_PropertyCount			Equ		284

p_Alignment				Equ		p_AutoSize
p_AlignMode				Equ		p_Transparent
p_AutoRedraw			Equ		p_PasswordChar
p_BandCount				Equ		p_DrawingStyle
p_BandStruct			Equ		p_ButtonStruct
p_Border				Equ		p_CaseStyle
p_ButtonCount			Equ		p_DrawingStyle
p_ButtonHeight			Equ		p_CaseStyle
p_ButtonSize			Equ		p_Center
p_ButtonWidth			Equ		p_Center
p_Cancel				Equ		p_AutoSize
p_ChildOffset			Equ		p_OldFont
p_ColorQuality			Equ		p_TextAlignment
p_CurrentX				Equ		p_NoPrefix
p_CurrentY				Equ		p_Offset
p_Default				Equ		p_DisableClose
p_DisableNoScroll		Equ		p_DisableClose
p_DrawFlags				Equ		p_Value
p_DrawFocus				Equ		p_Transparent
p_FlickerFree			Equ		p_DisableClose
p_GripperCursor			Equ		p_NoPrefix
p_HideSelection			Equ		p_AutoSize
p_HitTest				Equ		p_Offset
p_HyperColor			Equ		p_ScrollBars
p_HyperLink				Equ		p_MaxLength
p_ImageCount			Equ		p_Transparent
p_ImageList				Equ		p_DrawingStyle
p_ImageStruct			Equ		p_ButtonStruct
p_Indentation			Equ		p_CaseStyle
p_ItemCount				Equ		p_DrawingStyle
p_ItemStruct			Equ		p_ButtonStruct
p_KeyPreview			Equ		p_NoPrefix
p_LvwExStyle			Equ		p_TextAlignment
p_MaxValue				Equ		p_ScrollBars
p_MinValue				Equ		p_ShowMode
p_Modal					Equ		p_Stretch
p_MultiLine				Equ		p_NoPrefix
p_NormalStyle			Equ		p_Style
p_OwnerDraw				Equ		p_DrawingStyle
p_PageSize				Equ		p_TextAlignment
p_PannelCount			Equ		p_DrawingStyle
p_PannelStruct			Equ		p_ButtonStruct
p_PicturePosition		Equ		p_MaxLength
p_SelStart				Equ		p_Offset
p_SelEnd				Equ		p_Stretch
p_TabCount				Equ		p_DrawingStyle
p_TabStruct				Equ		p_ButtonStruct
p_TickFrequency			Equ		p_Transparent
p_ToolTipText			Equ		p_ToolTip
p_VisibleRows			Equ		p_MaxLength


;===========================================================================
; Error Object struct
;===========================================================================
ECErrorStruct Struct
	dwEsp		DD		0	;0
	dwEbp		DD		0	;4
	dwEip		DD		0	;8
	Code		DD		0	;12
	Description	DD		0	;16
EndS


;===========================================================================
; App Object struct
;===========================================================================
ECApplication Struct
	Accel		DD		0	;0
	CommandLine	DD		0	;4
	FileName	DD		0	;8
	Header		DD		0	;12
	Instance	DD		0	;16
	Main		DD		0	;20
	Major		DD		0	;24
	Minor		DD		0	;28
	Previous	DD		0	;32
	Revision	DD		0	;36
	Path		DD		0	;40
	ProcessID	DD		0	;44
	ThreadID	DD		0	;48
EndS


;===========================================================================
; StatusBar Object struct
;===========================================================================
STBPANNEL Struct
	nWidth		DD		0
	nBevel		DD		0
	lpszText	DD		0
EndS


;===========================================================================
; ImageList Object struct
;===========================================================================
IMAGESTRUCT Struct
	lType		DD		0
	lpszResID	DD		0
EndS


;===========================================================================
; Header Object struct
;===========================================================================
ITEMSTRUCT Struct
	iImage		DD		0
	nWidth		DD		0
	lTextAlign	DD		0
	lpszText	DD		0
EndS


;===========================================================================
; Rebar Object struct
;===========================================================================
BANDSTRUCT Struct
	lHeader		DD		0
	lLength		DD		0
	lMinHeight	DD		0
	lMinWidth	DD		0
	dwStyle		DD		0
	hBitmap		DD		0
	hWndChild	DD		0
	lpszBitmap	DD		0
	lpszChild	DD		0
	lpszText	DD		0
EndS


;===========================================================================
; CPU Info struct
;===========================================================================
CPUINFO Struct
	Description  DB 32 Dup ?
	Stepping     DD 0
	Family       DD 0
	Model        DD 0
	CPUType      DD 0
	ModelID      DD 0
	FeaturesID   DD 0
	ExFeaturesID DD 0
EndS
