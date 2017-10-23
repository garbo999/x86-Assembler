#IFNDEF ADDINS_H
#DEFINE ADDINS_H

#IFNDEF RA
	#include Radasm\RAEdit.h
	#include Radasm\RAHexEd.h
	#include Radasm\RAGrid.h
	#include Radasm\RACodeComplete.h
	#include Radasm\RAFile.h
	#include Radasm\RAProject.h
	#include Radasm\RAProperty.h
	#include Radasm\RAResEd.h
	#include Radasm\RATools.h
#ENDIF

;Mdi child editor types
ID_EDITCODE						equ	1
ID_EDITTEXT						equ	2
ID_EDITHEX						equ	3
ID_EDITRES						equ 4
ID_EDITUSER						equ 5
ID_PROJECT						equ 6
ID_EXTERNAL						equ 7

;Mdi child ID's
ID_FIRSTCHILD					equ 65001
ID_LASTCHILD					equ 65499

;Code complete types
CCTYPE_NONE						equ 0
CCTYPE_PROC						equ 1
CCTYPE_TOOLTIP					equ 2
CCTYPE_CONST					equ 3
CCTYPE_ALL						equ 4
CCTYPE_STRUCT					equ 5
CCTYPE_USER						equ 6
CCTYPE_USERTOOLTIP				equ 7

;RadASM resource ID's
;Res\RadASMAcl.rc
IDA_ACCEL						equ 100
IDB_MNUARROW					equ 32101

;RadASM.mnu
IDR_MENU						equ 10000
IDM_FILE						equ 10001
IDM_FILE_NEW					equ 10002
IDM_FILE_OPEN					equ 10006
IDM_FILE_OPENHEX				equ 10060
IDM_FILE_REOPEN					equ 10062
IDM_FILE_CLOSE					equ 10055
IDM_FILE_SAVE					equ 10007
IDM_FILE_SAVEAS					equ 10061
IDM_FILE_SAVEALL				equ 10008
IDM_FILE_PAGESETUP				equ 10056
IDM_FILE_PRINT					equ 10010
IDM_FILE_RECENTFILES			equ 10179
IDM_FILE_RECENTPROJECTS			equ 10180
IDM_FILE_EXIT					equ 10004
IDM_EDIT						equ 10011
IDM_EDIT_UNDO					equ 10019
IDM_EDIT_REDO					equ 10020
IDM_EDIT_CUT					equ 10012
IDM_EDIT_COPY					equ 10013
IDM_EDIT_PASTE					equ 10014
IDM_EDIT_DELETE					equ 10015
IDM_EDIT_SELECTALL				equ 10059
IDM_EDIT_FIND					equ 10017
IDM_EDIT_FINDNEXT				equ 10169
IDM_EDIT_FINDPREV				equ 10170
IDM_EDIT_REPLACE				equ 10018
IDM_EDIT_GOTODECLARE			equ 10172
IDM_EDIT_RETURN					equ 10173
IDM_EDIT_GOTOLINE				equ 10199
IDM_EDIT_BLOCK					equ 10022
IDM_EDIT_INDENT					equ 10028
IDM_EDIT_OUTDENT				equ 10029
IDM_EDIT_COMMENT				equ 10030
IDM_EDIT_UNCOMMENT				equ 10031
IDM_EDIT_UPPERCASE				equ 10188
IDM_EDIT_LOWERCASE				equ 10189
IDM_EDIT_TOSPACES				equ 10191
IDM_EDIT_TOTABS					equ 10192
IDM_EDIT_TRIM					equ 10190
IDM_EDIT_BLOCKMODE				equ 10185
IDM_EDIT_BLOCKINSERT			equ 10186
IDM_EDIT_BOKKMARK				equ 10023
IDM_EDIT_TOGGLEBM				equ 10024
IDM_EDIT_NEXTBM					equ 10025
IDM_EDIT_PREVBM					equ 10026
IDM_EDIT_CLEARBM				equ 10027
IDM_EDIT_ERROR					equ 10193
IDM_EDIT_NEXTERROR				equ 10194
IDM_EDIT_CLEARERRORS			equ 10195
IDM_VIEW						equ 10032
IDM_VIEW_TOOLBAR				equ 10046
IDM_VIEW_LOCK					equ 10063
IDM_VIEW_TBFILE					equ 10049
IDM_VIEW_TBEDIT					equ 10050
IDM_VIEW_TBBOOKMARK				equ 10053
IDM_VIEW_TBVIEW					equ 10051
IDM_VIEW_TBMAKE					equ 10052
IDM_VIEW_TBBUILD				equ 10054
IDM_VIEW_STATUSBAR				equ 10033
IDM_VIEW_PROJECT				equ 10047
IDM_VIEW_PROPERTIES				equ 10048
IDM_VIEW_OUTPUT					equ 10034
IDM_VIEW_TAB					equ 10035
IDM_FORMAT						equ 10041
IDM_FORMAT_LOCK					equ 10070
IDM_FORMAT_FRONT				equ 10071
IDM_FORMAT_BACK					equ 10072
IDM_FORMAT_SHOW					equ 10073
IDM_FORMAT_SNAP					equ 10074
IDM_FORMAT_ALIGN				equ 10076
IDM_FORMAT_ALIGNLEFT			equ 10080
IDM_FORMAT_ALIGNCENTER			equ 10081
IDM_FORMAT_ALIGNRIGHT			equ 10082
IDM_FORMAT_ALIGNTOP				equ 10084
IDM_FORMAT_ALIGNMIDDLE			equ 10085
IDM_FORMAT_ALIGNBOTTOM			equ 10086
IDM_FORMAT_SIZE					equ 10077
IDM_FORMAT_SIZEWIDTH			equ 10087
IDM_FORMAT_SIZEHEIGHT			equ 10088
IDM_FORMAT_SIZEBOTH				equ 10089
IDM_FORMAT_CENTER				equ 10078
IDM_FORMAT_CENTERHORIZONTAL		equ 10090
IDM_FORMAT_CENTERVERTICAL		equ 10091
IDM_FORMAT_INDEX				equ 10079
IDM_PROJECT						equ 10042
IDM_PROJECT_NEW					equ 10066
IDM_PROJECT_OPEN				equ 10067
IDM_PROJECT_CLOSE				equ 10068
IDM_PROJECT_ADD					equ 10092
IDM_PROJECT_ADDNEWFILE			equ 10094
IDM_PROJET_ADDEXISTING			equ 10095
IDM_PROJECT_ADDOPEN				equ 10096
IDM_PROJECT_ADDALLOPEN			equ 10097
IDM_PROJECT_ADDGROUP			equ 10098
IDM_PROJECT_REMOVE				equ 10093
IDM_PROJECT_REMOVEFILE			equ 10101
IDM_PROJECT_REMOVEGROUP			equ 10102
IDM_PROJECT_EDIT				equ 10150
IDM_PROJECT_EDITFILE			equ 10165
IDM_PROJECT_EDITGROUP			equ 10164
IDM_PROJECT_OPENITEM			equ 10166
IDM_PROJECT_OPENITEMFILE		equ 10167
IDM_PROJECT_OPENITEMGROUP		equ 10168
IDM_PROJECT_OPTION				equ 10103
IDM_PROJECTTEMPLATE				equ 10196
IDM_PROJECT_LANGUAGE			equ 10197
IDM_RESOURCE					equ 10065
IDM_RESOURCE_ADD				equ 10108
IDM_RESOURCE_ADDDIALOG			equ 10109
IDM_RESOURCE_ADDMENU			equ 10110
IDM_RESOURCE_ADDACCELERATOR		equ 10111
IDM_RESOURCE_ADDVERSION			equ 10112
IDM_RESOURCE_ADDSTRING			equ 10113
IDM_RESOURCE_ADDMANIFEST		equ 10114
IDM_RESOURCE_ADDRCDATA			equ 10115
IDM_RESOURCE_ADDTOLBAR			equ 10116
IDM_RESOURCE_LANGUAGE			equ 10117
IDM_RESOURCE_INCLUDE			equ 10118
IDM_RESOURCE_RESOURCE			equ 10119
IDM_RESOURCE_NAMES				equ 10120
IDM_RESOURCE_EXPORT				equ 10121
IDM_RESOURCE_REMOVE				equ 10123
IDM_RESOURCE_UNDO				equ 10124
IDM_MAKE						equ 10036
IDM_MAKE_COMPILE				equ 10104
IDM_MAKE_ASSEMBLE				equ 10037
IDM_MAKE_MODULES				equ 10141
IDM_MAKE_LINK					equ 10107
IDM_MAKE_BUILD					equ 10038
IDM_MAKE_GO						equ 10040
IDM_MAKE_RUN					equ 10039
IDM_MAKE_DEBUG					equ 10140
IDM_MAKE_TOGGLEMAIN				equ 10177
IDM_MAKE_TOGGLEMODULE			equ 10178
IDM_DEBUG						equ 10125
IDM_DEBUG_TOGGLE				equ 10128
IDM_DEBUG_CLEAR					equ 10129
IDM_DEBUG_RUN					equ 10131
IDM_DEBUG_BREAK					equ 10132
IDM_DEBUG_STOP					equ 10133
IDM_DEBUG_INTO					equ 10135
IDM_DEBUG_OVER					equ 10136
IDM_DEBUG_CARET					equ 10137
IDM_DEBUG_NODEBUG				equ 10139
IDM_TOOLS						equ 10043
IDM_TOOLS_SNIPLETS				equ 10174
IDM_WINDOW						equ 10005
IDM_WINDOW_CLOSE				equ 10055
IDM_WINDOW_CLOSEALL				equ 10151
IDM_WINDOW_CLOSEALLBUT			equ 10152
IDM_WINDOW_HORIZONTAL			equ 10142
IDM_WINDOW_VERTICAL				equ 10143
IDM_WIDDOW_CASCADE				equ 10144
IDM_WINDOW_ICONS				equ 10145
IDM_WINDOW_MAXIMIZE				equ 10147
IDM_WINDOW_RESTORE				equ 10148
IDM_WINDOW_MINIMIZE				equ 10149
IDM_OPTION						equ 10044
IDM_OPTION_PROGLANG				equ 10198
IDM_OPTION_CODE					equ 10154
IDM_OPTION_RESOURCE				equ 10155
IDM_OPTION_ENVIRONMENT			equ 10156
IDM_OPTION_MAKE					equ 10182
IDM_OPTION_EXTERNAL				equ 10158
IDM_OPTION_ADDIN				equ 10157
IDM_OPTION_TOOLS				equ 10160
IDM_OPTION_HELP					equ 10161
IDM_OPTION_F1					equ 10183
IDM_HELP						equ 10045
IDM_HELP_ABOUT					equ 10162

IDM_FILE_RECENTFILESSTART		equ 12000
IDM_FILE_RECENTPROJECTSSTART	equ 12100
IDM_TOOLS_START					equ 12200
IDM_HELP_START					equ 12300
IDM_HELPF1						equ 12400
IDM_PROJECT_LANGUAGE_START		equ 12500

;Context.mnu
IDR_CONTEXTMENU					equ 11000
IDCM_RESOURCE					equ 11001
IDCM_FILE						equ 11005
IDCM_FILE_OPEN					equ 11014
IDCM_FILE_EXPLORE				equ 11019
IDCM_FILE_TOCODE				equ 11018
IDCM_PROJECT					equ 11006
IDCM_PROPERTY					equ 11008
IDM_PROPERTY_GOTO				equ 11025
IDM_PROPERTY_COPY				equ 11026
IDM_PROPERTY_PROTO				equ 11027
IDCM_OUTPUT						equ 11009
IDM_OUTPUT_HIDE					equ 11020
IDM_OUTPUT_CLEAR				equ 11024
IDM_OUTPUT_CUT					equ 11023
IDM_OUTPUT_COPY					equ 11022
IDCM_FILE_OPEN_CARET			equ 13000

;Messages to RadASM's main window
AIM_GETHANDLES					equ WM_USER+50			;Returns a poiner to a struct containing all useful handles. See ADDINHANDLES structure below.
AIM_GETPROCS					equ WM_USER+51			;Returns a poiner to a struct containing some procs in RadASM. See ADDINPROCS structure below.
AIM_GETDATA						equ WM_USER+52			;Returns a poiner to a struct comtaining data pointers. See ADDINDATA structure below.
AIM_GETMENUID					equ WM_USER+53			;Returns a free menu id. If you need more than one, wParam contains the number of id's to reserve.

;Messages sendt to addins
AIM_ADDINSLOADED				equ WM_USER+100			;This message is sendt to the addins after all addins are loaded. hWin=Main window, wParam=0, lParam=0
AIM_COMMAND						equ WM_USER+101			;This message is sendt to the addins when user makes a menu selection or clicks a toolbar button. hWin=Main window, wParam and lParam as for WM_COMMAND
AIM_CLOSE						equ WM_USER+102			;RadASM requests closing. Return TRUE to prevent RadASM from closing. hWin=Main window, wParam and lParam as for WM_CLOSE
AIM_DESTROY						equ WM_USER+103			;RadASM is about to be destroyed. Now is the time to free memory and resources that your addin allocated. Always return FALSE. hWin=Main window, wParam and lParam as for WM_DESTROY
AIM_MENUUPDATE					equ WM_USER+104			;RadASM has updated its menues. Now is the time to add menu items. Always return FALSE. hWin=Main window, wParam=hMnu, lParam=hContextMnu. NOTE: This command can be sendt more than once. Do not allocate MenuID's here
AIM_FILEOPEN					equ WM_USER+105			;A file is about to be opened. Return TRUE to prevent RadASM from opening the file. hWin=Main window, wParam=ID_EDITCODE, ID_EDITTEXT, ID_EDITHEX, ID_EDITRES or ID_PROJECT, lParam=lpFileName
AIM_FILEOPENED					equ WM_USER+106			;A file has ben opened.. Always return FALSE. hWin=Main window, wParam=ID_EDITCODE, ID_EDITTEXT, ID_EDITHEX, ID_EDITRES or ID_PROJECT, lParam=lpFileName
AIM_FILECLOSE					equ WM_USER+107			;A file is about to be closed.. Return TRUE to prevent RadASM from closing the file. hWin=Mdi child window, wParam=ID_EDITCODE, ID_EDITTEXT, ID_EDITHEX or ID_EDITRES, lParam=lpFileName
AIM_FILECLOSED					equ WM_USER+108			;A file has been closed.. Always return FALSE. hWin=Mdi child window, wParam=ID_EDITCODE, ID_EDITTEXT, ID_EDITHEX or ID_EDITRES, lParam=lpFileName
AIM_FILESAVE					equ WM_USER+109			;A file is about to be saved. Return TRUE to prevent RadASM from saving the file. hWin=Mdi child window, wParam=ID_EDITCODE, ID_EDITTEXT, ID_EDITHEX, ID_EDITRES or ID_EDITUSER, lParam=lpFileName
AIM_FILESAVEAS					equ WM_USER+110			;A file is about to be saved with a new name. Return TRUE to prevent RadASM from saving the file. hWin=Mdi child window, wParam=ID_EDITCODE, ID_EDITTEXT, ID_EDITHEX, ID_EDITRES or ID_EDITUSER, lParam=lpFileName
AIM_FILESAVED					equ WM_USER+111			;A file has been saved. Always return FALSE. hWin=Mdi child window, wParam=ID_EDITCODE, ID_EDITTEXT, ID_EDITHEX, ID_EDITRES or ID_EDITUSER, lParam=lpFileName
AIM_GETMODIFY					equ WM_USER+112			;RadASM requests if a file is changed. Return TRUE if it is your file and it has changed. hWin=Mdi child window, wParam=ID_EDITUSER, lParam=lpFileName
AIM_MAKEBEGIN					equ WM_USER+113			;RadASM starts a make process. Return TRUE to prevent RadASM from running the make process. hWin=Main window, wParam=IDM_MAKE_COMPILE, IDM_MAKE_ASSEMBLE, IDM_MAKE_LINK, IDM_MAKE_BUILD, IDM_MAKE_RUN or IDM_MAKE_GO, lParam=Main file
AIM_MAKEDONE					equ WM_USER+114			;RadASM finished the make process. Always return FALSE. hWin=Main window, wParam=IDM_MAKE_COMPILE, IDM_MAKE_ASSEMBLE, IDM_MAKE_LINK, IDM_MAKE_BUILD, IDM_MAKE_RUN or IDM_MAKE_GO, lParam=Main file
AIM_GETFILETYPE					equ WM_USER+115			;RadASM requests a filetype. Return ID_EDITUSER if your addin handles the filetype, else return FALSE. hWin=Main window,wParam=0, lParam=lpFileName
AIM_FILENAMECHANGED				equ WM_USER+116			;RadASM has changed a filename. Return TRUE if this is your file, else return FALSE. hWin=Mdi child window,wParam=Old filename, lParam=New filename
AIM_MENUENABLE					equ WM_USER+117			;RadASM requests you to enable / disable your menu items. Always return FALSE. hWin=Main window,wParam=IDM_FILE,IDM_EDIT,IDM_VIEW,IDM_FORMAT,IDM_PROJECT,IDM_RESOURCE,IDM_MAKE,IDM_DEBUG,IDM_TOOLS,IDM_WINDOW,IDM_OPTION or IDM_HELP, lParam=0
AIM_RASELCHANGE					equ WM_USER+118			;This message is sendt when a ID_EDITCODE window has a selection change. Always return FALSE. hWin=Mdi child window,wParam=lpTABMEM,lParam=lpRASELCHANE
AIM_MDIACTIVATE					equ WM_USER+119			;This message is sendt when a mdi child is activated or deactivated. Always return FALSE. hWin=Mdi child window,wParam and lParam as M_MDIACIVATE
AIM_PARSEFILE					equ WM_USER+120			;This message is sendt when RadASM is done parsing a file. Always return FALSE. hWin=Mdi child window or NULL if it is a file.,wParam=nOwner, lParam=Pointer to file data.

;HOOK flags returned in hook1 of HOOK structure
HOOK_ADDINSLOADED				equ 000001h
HOOK_COMMAND					equ 000002h
HOOK_CLOSE						equ 000004h
HOOK_DESTROY					equ 000008h
HOOK_MENUUPDATE					equ 000010h
HOOK_FILEOPEN					equ 000020h
HOOK_FILEOPENED					equ 000040h
HOOK_FILECLOSE					equ 000080h
HOOK_FILECLOSED					equ 000100h
HOOK_FILESAVE					equ 000200h
HOOK_FILESAVEAS					equ 000300h
HOOK_FILESAVED					equ 000800h
HOOK_GETMODIFY					equ 001000h
HOOK_MAKEBEGIN					equ 002000h
HOOK_MAKEDONE					equ 004000h
HOOK_GETFILETYPE				equ 008000h
HOOK_FILENAMECHANGED			equ 010000h
HOOK_MENUENABLE					equ 020000h
HOOK_RASELCHANGE				equ 040000h
HOOK_MDIACTIVATE				equ 080000h
HOOK_PARSEFILE					equ 100000h

HOOK struct
	hook1				DD							;Combinations of HOOK_ flags
	hook2				DD							;Not used must be zero
	hook3				DD							;Not used must be zero
	hook4				DD							;Not used must be zero
ends

ADDINHANDLES struct
	hInstance			DD
	hWnd				DD
	hClient				DD
	hMdi				DD
	hEdt				DD
	hMenu				DD
	hContextMenu		DD
	hAccel				DD
	hIcon				DD
	hCursor				DD
	hSplitCurV			DD
	hSplitCurH			DD
	hTool				DD
	hToolProject		DD
	hTabProject			DD
	hFileBrowser		DD
	hProjectBrowser		DD
	hToolProperties		DD
	hProperty			DD
	hToolOutput			DD
	hTabOutput			DD
	hOutput				DD
	hImmediate			DD
	hToolTab			DD
	hTab				DD
	hStatus				DD
	hReBar				DD
	hStcBuild			DD
	hCboBuild			DD
	hToolDebug			DD
	hTabDebug			DD
	hREGDebug			DD
	hFPUDebug			DD
	hMMXDebug			DD
	hWATCHDebug			DD
	hToolFont			DD
	racf				RAFONT
	ratf				RAFONT
	rahf				HEFONT
	hImlTbr				DD
	hImlTbrGray			DD
	hMnuIml				DD
	hTbrFile			DD
	hTbrEdit1			DD
	hTbrEdit2			DD
	hTbrView			DD
	hTbrMake			DD
	hDiv1				DD
	hDiv2				DD
	hCC					DD
	hTT					DD
	hModeless			DD
	hHtmlOcx			DD
	hFind				DD
	hDbgTip				DD
ends

ADDINPROCS struct
	lpOpenTheFile		DD							;Opens a file. lpFileName:DWORD,fType:DWORD
	lpSetOutputTab		DD							;Selects Output or Immediate. nSel:DWORD (0 or 1)
	lpShowOutput		DD							;Shows or hides the output tool. fShow:DWORD (TRUE or FALSE)
	lpTextOutput		DD							;Outputs a text string to selected output. lpString:DWORD
	lpTabToolSetChanged	DD							;Sets the tabs changed state. hWin:HWND,fChanged:DWORD (TRUE or FALSE)
	lpTabToolGetMem		DD							;Gets a pointer to TABMEM. hWin:HWND
	lpTabToolAdd		DD							;Adds a new tab. hWin:HWND,lpFileName:DWORD
	lpTabToolActivate	DD							;Activates the current tab.
	lpUpdateFileName	DD							;Changes the filename for current selected tab. hWin:HWND,lpFileName:DWORD
	lpUpdateFileTime	DD							;Updates the filetime. lpTABMEM:DWORD
	lpUpdateAll			DD							;Loops through all tabs performing selected UAM_ message. lParam:DWORD depends on message.
ends

VIEW_STATUSBAR					equ 1

PRNPOS struct
	margins				RECT
	pagesize			POINT
	nlinespage			DD
ends

WIN struct
	x					DD
	y					DD
	wt					DD
	ht					DD
	fmax				DD
	ftopmost			DD
	fcldmax				DD
	fView				DD
	ccwt				DD
	ccht				DD
	ptfind				POINT
	ptgoto				POINT
ends

;16+20+12=48
RADCOLOR struct
	kwcol				DD 16 DUP					;Keywords
	racol				RACOLOR						;RAEdit
	toolback			DD
	tooltext			DD
	dialogback			DD
	dialogtext			DD
	styles				DD
	words				DD
	ccback				DD
	cctext				DD
	ttback				DD
	tttext				DD
	ttapi				DD
	ttsel				DD
ends

THEME struct
	szname				DB 32 DUP
	radcol				RADCOLOR
ends

EDTOPT_EXPTAB					equ 1
EDTOPT_INDENT					equ 2
EDTOPT_LINEHI					equ 4
EDTOPT_CMNTHI					equ 8
EDTOPT_LINENR					equ 16
EDTOPT_SESSION					equ 32
EDTOPT_BRACE					equ 64
EDTOPT_SHOWTIP					equ 128

EDTOPT struct
	tabsize				DD
	fopt				DD
ends

RESOPT_LOCK						equ 1
RESOPT_GRID						equ 2
RESOPT_SNAP						equ 4
RESOPT_LINE						equ 8
RESOPT_HEX						equ 16
RESOPT_AUTO						equ 32
RESOPT_TIP						equ 64

CUSTCTRL struct
	hDll				DD
	szFileName			DB 128 DUP
	szStyleMask			DB 16 DUP
ends

RESOPT struct
	gridx				DD							;Assembler.ini
	gridy				DD							;Assembler.ini
	color				DD							;Assembler.ini
	fopt				DD							;Assembler.ini
	nExport				DD							;Assembler.ini
	szUserExport		DB 64 DUP					;Assembler.ini
	szExport			DB 64 DUP					;Assembler.ini
	nOutput				DD							;Assembler.ini
	custctrl			DB 148*32 DUP ; CUSTCTRL 32 dup <?>
	custstyle			DB 72*64 DUP ; CUSTSTYLE 64 dup <?>
	custtype			DB 228*32 DUP ;RARSTYPE 32 dup <?>
ends

EXTERNAL struct
	szprog				DB MAX_PATH DUP
	szfiles				DB 64 DUP
ends

MAKE struct
	szType				DB 128 DUP
	szCompileRC			DB 128 DUP
	szOutCompileRC		DB 32 DUP
	szAssemble			DB 128 DUP
	szOutAssemble		DB 32 DUP
	szLink				DB 128 DUP
	szOutLink			DB 32 DUP
	szLib				DB 128 DUP
	szOutLib			DB 32 DUP
ends

FIND struct
	fr					DD
	fdir				DD
	fscope				DD
	fres				DD
	fproc				DD
	nfound				DD
	nreplace			DD
	initchrg			CHARRANGE
	scopechrg			CHARRANGE
	ft					FINDTEXTEX
	szfindbuff			DB MAX_PATH DUP
	szreplacebuff		DB MAX_PATH DUP
	repdiff				DD
	szfindhistory		DB 10*256 DUP
ends

ADDINDATA struct
	Version				DD
	lpszVersion			DD
	win					WIN
	winres				WINSIZE
	radcolor			RADCOLOR
	szAppPath			DB MAX_PATH DUP
	szRadASMIni			DB MAX_PATH DUP
	szAssemblerIni		DB MAX_PATH DUP
	szAssemblerPath		DB MAX_PATH DUP
	szProjectFile		DB MAX_PATH DUP
	szProjectPath		DB MAX_PATH DUP
	szDefProjectPath	DB MAX_PATH DUP
	szAssemblers		DB 256 DUP
	szAssembler			DB 32 DUP
	nAsm				DD
	szFileName			DB MAX_PATH DUP
	szFBPath			DB MAX_PATH DUP
	fProject			DD
	tabinx				DD
	fTimer				DD
	nLastLine			DD
	fChanged			DD
	rabdstr				DB 2048 DUP
	rabd				DB 20*32 DUP ;RABLOCKDEF 32 dup <?>
	szCmntStart			DB 64 DUP
	szCmntEnd			DB 64 DUP
	szBraceMatch		DB 64 DUP
	cctype				DD
	inprogress			DD
	lpCharTab			DD
	edtopt				EDTOPT
	resopt				RESOPT
	fLockToolbar		DD
	szFilter			DB 64 DUP
	szCodeFiles			DB 32 DUP
	szTextFiles			DB 32 DUP
	szHexFiles			DB 32 DUP
	szResourceFiles		DB 32 DUP
	szProjectFiles		DB 32 DUP
	szTplTxt			DB 256 DUP
	szTplBin			DB 256 DUP
	szCCTrig			DB 128 DUP
	szCCInc				DB 32 DUP
	szCCLib				DB 32 DUP
	external			DB 324*20 DUP ;EXTERNAL 20 dup <?>
	szCODEString		DB 64 DUP
	szRESString			DB 64 DUP
	szTXTString			DB 64 DUP
	szANYString			DB 64 DUP
	szPROString			DB 64 DUP
	szALLString			DB 64*4 DUP
	szTypes				DB 256 DUP
	szCompileRC			DB 128 DUP
	szCompileRCHelp		DB 128 DUP
	szCompileRCHelpKw	DB 128 DUP
	szAssemble			DB 128 DUP
	szAssembleHelp		DB 128 DUP
	szAssembleHelpKw	DB 128 DUP
	szLink				DB 128 DUP
	szLinkHelp			DB 128 DUP
	szLinkHelpKw		DB 128 DUP
	szLib				DB 128 DUP
	szLibHelp			DB 128 DUP
	szLibHelpKw			DB 128 DUP
	make				DB 768*32 DUP ;MAKE 32 dup <?>
	szMainRC			DB 128 DUP
	szMainAsm			DB 128 DUP
	szDebug				DB 128 DUP
	szCommandLine		DB 128 DUP
	fCmdExe				DD
	szCmdExe			DB 64 DUP
	szPOApiFiles		DB 256 DUP
	fDelMinor			DD
	szMruFiles			DB 10*MAX_PATH DUP
	szMruProjects		DB 10*MAX_PATH DUP
	pHtmlHelpProc		DD
	szHelpF1			DB 3*MAX_PATH DUP
	find				FIND
	nBackup				DD
	fDebugging			DD
	ti					TOOLINFO
	fCanDebug			DD
	szDbgFileName		DB MAX_PATH DUP
	szNoDebug			DB 1024*8 DUP
	fMainThread			DD
	nErrID				DD
	ErrID				DD 256 DUP
	fNoChangeNotify		DD
	szError				DB 64 DUP
	fExternal			DD
	ccchrg				CHARRANGE
	tti					TTITEM
	fIncBuild			DD
ends

FILEINFO struct
	pid					DD
	idparent			DD
	flag				DD
	ID					DD
	rect				RECT
	nline				DD
	filename			DB MAX_PATH DUP
ends

TABMEM struct
	hwnd				DD							;Handle of the mdi child window.
	hedt				DD							;Handle of the edit window
	pid					DD							;Project id
	filename			DB MAX_PATH DUP			;Filename including full path.
	ft					FILETIME					;Filetime for last write.
	nchange				DD
	fchanged			DD
	fupdate				DD
	fnonotify			DD
	nlastsize			DD
	nlastpropline		DD
ends

;Messages to the UpdateAll proc
UAM_ISOPEN						equ 1
UAM_ISOPENACTIVATE				equ 2
UAM_ISRESOPEN					equ 3
UAM_SAVEALL						equ 4
UAM_CLOSEALL					equ 5
UAM_SETCOLORS					equ 6
UAM_SETFONTS					equ 7
UAM_PARSE						equ 8
UAM_ANYBOOKMARKS				equ 9
UAM_CLEARBOOKMARKS				equ 10
UAM_ANYBREAKPOINTS				equ 11
UAM_CLEARBREAKPOINTS			equ 12
UAM_CLEARERRORS					equ 13
UAM_FINDERROR					equ 14
UAM_UNSAVED_SOURCE_FILES		equ 15
UAM_NEWER_SOURCE_FILES			equ 16
UAM_SET_BREAKPOINTS				equ 17
UAM_LOCK_SOURCE_FILES			equ 18
UAM_UNLOCK_SOURCE_FILES			equ 19
UAM_IS_CHANGED					equ 20
UAM_CLEAR_CHANGED				equ 21
#ENDIF