#define WS_OVERLAPPED                   0x00000000
#define WS_POPUP                        0x80000000
#define WS_CHILD                        0x40000000
#define WS_VISIBLE                      0x10000000
#define WS_DISABLED                     0x08000000
#define WS_CLIPSIBLINGS                 0x04000000
#define WS_CLIPCHILDREN                 0x02000000
#define WS_CAPTION                      0x00C00000
#define WS_BORDER                       0x00800000
#define WS_DLGFRAME                     0x00400000
#define WS_VSCROLL                      0x00200000
#define WS_HSCROLL                      0x00100000
#define WS_SYSMENU                      0x00080000
#define WS_THICKFRAME                   0x00040000
#define WS_GROUP                        0x00020000
#define WS_TABSTOP                      0x00010000
#define WS_MINIMIZEBOX                  0x00020000
#define WS_MAXIMIZEBOX                  0x00010000

#define DS_ABSALIGN                     0x00000001
#define DS_SYSMODAL                     0x00000002
#define DS_SETFOREGROUND                0x00000200
#define DS_CONTROL                      0x00000400
#define DS_CENTER                       0x00000800
#define DS_CENTERMOUSE                  0x00001000
#define DS_SETFONT                      0x00000040
#define DS_MODALFRAME                   0x00000080
#define DS_CONTEXTHELP                  0x00002000
#define DS_NOIDLEMSG                    0x00000100
#define DS_LOCALEDIT                    0x00000020
#define DS_NOFAILCREATE                 0x00000010

#define WS_EX_DLGMODALFRAME             0x00000001
#define WS_EX_NOPARENTNOTIFY            0x00000004
#define WS_EX_TOPMOST                   0x00000008
#define WS_EX_ACCEPTFILES               0x00000010
#define WS_EX_TRANSPARENT               0x00000020
#define WS_EX_MDICHILD                  0x00000040
#define WS_EX_TOOLWINDOW                0x00000080
#define WS_EX_CLIENTEDGE                0x00000200
#define WS_EX_CONTEXTHELP               0x00000400
#define WS_EX_RTLREADING                0x00002000
#define WS_EX_LEFTSCROLLBAR             0x00004000
#define WS_EX_CONTROLPARENT             0x00010000
#define WS_EX_STATICEDGE                0x00020000
#define WS_EX_APPWINDOW                 0x00040000
#define WS_EX_RIGHT                     0x00001000

#define SS_CENTER                       0x00000001
#define SS_LEFTNOWORDWRAP               0x0000000C
#define SS_NOTIFY                       0x00000100
#define SS_NOPREFIX                     0x00000080
#define SS_RIGHT                        0x00000002
#define SS_SIMPLE                       0x0000000B
#define SS_SUNKEN                       0x00001000

#define ES_AUTOHSCROLL                  0x00000080
#define ES_AUTOVSCROLL                  0x00000040
#define ES_CENTER                       0x00000001
#define ES_LOWERCASE                    0x00000010
#define ES_MULTILINE                    0x00000004
#define ES_NOHIDESEL                    0x00000100
#define ES_NUMBER                       0x00002000
#define ES_PASSWORD                     0x00000020
#define ES_RIGHT                        0x00000002
#define ES_READONLY                     0x00000800
#define ES_UPPERCASE                    0x00000008
#define ES_WANTRETURN                   0x00001000
#define ES_DISABLENOSCROLL              0x00002000

#define BS_3STATE                       0x00000005
#define BS_AUTO3STATE                   0x00000006
#define BS_AUTOCHECKBOX                 0x00000003
#define BS_AUTORADIOBUTTON              0x00000009
#define BS_BITMAP                       0x00000080
#define BS_BOTTOM                       0x00000800
#define BS_CENTER                       0x00000300
#define BS_CHECKBOX                     0x00000002
#define BS_DEFPUSHBUTTON                0x00000001
#define BS_FLAT                         0x00008000
#define BS_GROUPBOX                     0x00000007
#define BS_ICON                         0x00000040
#define BS_LEFT                         0x00000100
#define BS_LEFTTEXT                     0x00000020
#define BS_MULTILINE                    0x00002000
#define BS_NOTIFY                       0x00004000
#define BS_OWNERDRAW                    0x0000000B
#define BS_PUSHBUTTON                   0x00000000
#define BS_PUSHLIKE                     0x00001000
#define BS_RADIOBUTTON                  0x00000004
#define BS_RIGHT                        0x00000200
#define BS_TOP                          0x00000400
#define BS_VCENTER                      0x00000C00

#define LBS_DISABLENOSCROLL             0x00001000
#define LBS_EXTENDEDSEL                 0x00000800
#define LBS_HASSTRINGS                  0x00000040
#define LBS_MULTICOLUMN                 0x00000200
#define LBS_MULTIPLESEL                 0x00000008
#define LBS_NOTIFY                      0x00000001
#define LBS_NOINTEGRALHEIGHT            0x00000100
#define LBS_OWNERDRAWFIXED              0x00000010
#define LBS_OWNERDRAWVARIABLE           0x00000020
#define LBS_SORT                        0x00000002
#define LBS_USETABSTOPS                 0x00000080
#define LBS_WANTKEYBOARDINPUT           0x00000400

#define CBS_AUTOHSCROLL                 0x00000040
#define CBS_DISABLENOSCROLL             0x00000800
#define CBS_DROPDOWN                    0x00000002
#define CBS_DROPDOWNLIST                0x00000003
#define CBS_HASSTRINGS                  0x00000200
#define CBS_LOWERCASE                   0x00004000
#define CBS_NOINTEGRALHEIGHT            0x00000400
#define CBS_OWNERDRAWFIXED              0x00000010
#define CBS_OWNERDRAWVARIABLE           0x00000020
#define CBS_SIMPLE                      0x00000001
#define CBS_SORT                        0x00000100
#define CBS_UPPERCASE                   0x00002000

#define SS_BITMAP                       0x0000000E
#define SS_BLACKFRAME                   0x00000007
#define SS_BLACKRECT                    0x00000004
#define SS_CENTERIMAGE                  0x00000200
#define SS_ETCHEDFRAME                  0x00000012
#define SS_GRAYFRAME                    0x00000008
#define SS_GRAYRECT                     0x00000005
#define SS_ICON                         0x00000003
#define SS_NOTIFY                       0x00000100
#define SS_REALSIZEIMAGE                0x00000800
#define SS_RIGHTJUST                    0x00000400
#define SS_SUNKEN                       0x00001000
#define SS_WHITEFRAME                   0x00000009
#define SS_WHITERECT                    0x00000006

#define SBS_HORZ                        0x00000000
#define SBS_VERT                        0x00000001
#define SBS_BOTTOMALIGN                 0x00000004
#define SBS_LEFTALIGN                   0x00000002
#define SBS_RIGHTALIGN                  0x00000004
#define SBS_TOPALIGN                    0x00000002

#define TVS_CHECKBOXES                  0x00000100
#define TVS_DISABLEDRAGDROP             0x00000010
#define TVS_EDITLABELS                  0x00000008
#define TVS_HASBUTTONS                  0x00000001
#define TVS_HASLINES                    0x00000002
#define TVS_LINESATROOT                 0x00000004
#define TVS_NOSCROLL                    0x00002000
#define TVS_NOTOOLTIPS                  0x00000080
#define TVS_SHOWSELALWAYS               0x00000020

#define LVS_ALIGNLEFT                   0x00000800
#define LVS_ALIGNTOP                    0x00000000
#define LVS_AUTOARRANGE                 0x00000100
#define LVS_EDITLABELS                  0x00000200
#define LVS_ICON                        0x00000000
#define LVS_LIST                        0x00000003
#define LVS_NOCOLUMNHEADER              0x00004000
#define LVS_NOLABELWRAP                 0x00000080
#define LVS_NOSCROLL                    0x00002000
#define LVS_NOSORTHEADER                0x00008000
#define LVS_REPORT                      0x00000001
#define LVS_SHOWSELALWAYS               0x00000008
#define LVS_SINGLESEL                   0x00000004
#define LVS_SMALLICON                   0x00000002
#define LVS_SORTASCENDING               0x00000010
#define LVS_SORTDESCENDING              0x00000020

#define CCS_TOP                         0x00000001
#define CCS_NOMOVEY                     0x00000002
#define CCS_BOTTOM                      0x00000003
#define CCS_NORESIZE                    0x00000004
#define CCS_NOPARENTALIGN               0x00000008
#define CCS_ADJUSTABLE                  0x00000020
#define CCS_NODIVIDER                   0x00000040
#define CCS_VERT                        0x00000080
#define CCS_LEFT                        0x00000081
#define CCS_RIGHT                       0x00000083
#define CCS_NOMOVEX                     0x00000082

#define TBSTYLE_TOOLTIPS                0x00000100
#define TBSTYLE_WRAPABLE                0x00000200
#define TBSTYLE_ALTDRAG                 0x00000400
#define TBSTYLE_FLAT                    0x00000800
#define TBSTYLE_LIST                    0x00001000
#define TBSTYLE_CUSTOMERASE             0x00002000
#define TBSTYLE_REGISTERDROP            0x00004000
#define TBSTYLE_TRANSPARENT             0x00008000

#define SBARS_SIZEGRIP                  0x00000100

#define PBS_SMOOTH                      0x00000001
#define PBS_VERTICAL                    0x00000004

#define TBS_AUTOTICKS                   0x00000001
#define TBS_VERT                        0x00000002
#define TBS_HORZ                        0x00000000
#define TBS_TOP                         0x00000004
#define TBS_BOTTOM                      0x00000000
#define TBS_LEFT                        0x00000004
#define TBS_RIGHT                       0x00000000
#define TBS_BOTH                        0x00000008
#define TBS_NOTICKS                     0x00000010
#define TBS_ENABLESELRANGE              0x00000020
#define TBS_FIXEDLENGTH                 0x00000040
#define TBS_NOTHUMB                     0x00000080
#define TBS_TOOLTIPS                    0x00000100

#define TCS_SCROLLOPPOSITE              0x00000001
#define TCS_BOTTOM                      0x00000002
#define TCS_RIGHT                       0x00000002
#define TCS_MULTISELECT                 0x00000004
#define TCS_FLATBUTTONS                 0x00000008
#define TCS_FORCEICONLEFT               0x00000010
#define TCS_FORCELABELLEFT              0x00000020
#define TCS_HOTTRACK                    0x00000040
#define TCS_VERTICAL                    0x00000080
#define TCS_TABS                        0x00000000
#define TCS_BUTTONS                     0x00000100
#define TCS_SINGLELINE                  0x00000000
#define TCS_MULTILINE                   0x00000200
#define TCS_RIGHTJUSTIFY                0x00000000
#define TCS_FIXEDWIDTH                  0x00000400
#define TCS_RAGGEDRIGHT                 0x00000800
#define TCS_FOCUSONBUTTONDOWN           0x00001000
#define TCS_OWNERDRAWFIXED              0x00002000
#define TCS_TOOLTIPS                    0x00004000
#define TCS_FOCUSNEVER                  0x00008000

#define UDS_WRAP                        0x00000001
#define UDS_SETBUDDYINT                 0x00000002
#define UDS_ALIGNRIGHT                  0x00000004
#define UDS_ALIGNLEFT                   0x00000008
#define UDS_AUTOBUDDY                   0x00000010
#define UDS_ARROWKEYS                   0x00000020
#define UDS_HORZ                        0x00000040
#define UDS_NOTHOUSANDS                 0x00000080
#define UDS_HOTTRACK                    0x00000100

#define ACS_CENTER                      0x00000001
#define ACS_TRANSPARENT                 0x00000002
#define ACS_AUTOPLAY                    0x00000004
#define ACS_TIMER                       0x00000008

#define MCS_DAYSTATE                    0x00000001
#define MCS_MULTISELECT                 0x00000002
#define MCS_WEEKNUMBERS                 0x00000004
#define MCS_NOTODAYCIRCLE               0x00000008
#define MCS_NOTODAY                     0x00000010

#define DTS_UPDOWN                      0x00000001
#define DTS_SHOWNONE                    0x00000002
#define DTS_SHORTDATEFORMAT             0x00000000
#define DTS_LONGDATEFORMAT              0x00000004
#define DTS_TIMEFORMAT                  0x00000009
#define DTS_APPCANPARSE                 0x00000010
#define DTS_RIGHTALIGN                  0x00000020

#define PGS_VERT                        0x00000000
#define PGS_HORZ                        0x00000001
#define PGS_AUTOSCROLL                  0x00000002
#define PGS_DRAGNDROP                   0x00000004

#define HDS_HORZ                        0x00000000
#define HDS_DRAGDROP                    0x00000040
#define HDS_FULLDRAG                    0x00000080
#define HDS_BUTTONS                     0x00000002
#define HDS_HIDDEN                      0x00000008
#define HDS_HOTTRACK                    0x00000004

#define VK_ADD                          0x0000006B
#define VK_APPS                         0x0000005D
#define VK_ATTN                         0x000000F6
#define VK_BACK                         0x00000008
#define VK_CANCEL                       0x00000003
#define VK_CAPITAL                      0x00000014
#define VK_CLEAR                        0x0000000C
#define VK_CONTROL                      0x00000011
#define VK_CRSEL                        0x000000F7
#define VK_DECIMAL                      0x0000006E
#define VK_DELETE                       0x0000002E
#define VK_DIVIDE                       0x0000006F
#define VK_DOWN                         0x00000028
#define VK_END                          0x00000023
#define VK_EREOF                        0x000000F9
#define VK_ESCAPE                       0x0000001B
#define VK_EXECUTE                      0x0000002B
#define VK_EXSEL                        0x000000F8
#define VK_F1                           0x00000070
#define VK_F2                           0x00000071
#define VK_F3                           0x00000072
#define VK_F4                           0x00000073
#define VK_F5                           0x00000074
#define VK_F6                           0x00000075
#define VK_F7                           0x00000076
#define VK_F8                           0x00000077
#define VK_F9                           0x00000078
#define VK_F10                          0x00000079
#define VK_F11                          0x0000007A
#define VK_F12                          0x0000007B
#define VK_F13                          0x0000007C
#define VK_F14                          0x0000007D
#define VK_F15                          0x0000007E
#define VK_F16                          0x0000007F
#define VK_F17                          0x00000080
#define VK_F18                          0x00000081
#define VK_F19                          0x00000082
#define VK_F20                          0x00000083
#define VK_F21                          0x00000084
#define VK_F22                          0x00000085
#define VK_F23                          0x00000086
#define VK_F24                          0x00000087
#define VK_HELP                         0x0000002F
#define VK_HOME                         0x00000024
#define VK_INSERT                       0x0000002D
#define VK_LBUTTON                      0x00000001
#define VK_LEFT                         0x00000025
#define VK_LWIN                         0x0000005B
#define VK_MBUTTON                      0x00000004
#define VK_MENU                         0x00000012
#define VK_MULTIPLY                     0x0000006A
#define VK_NUMLOCK                      0x00000090
#define VK_NUMPAD0                      0x00000060
#define VK_NUMPAD1                      0x00000062
#define VK_NUMPAD2                      0x00000062
#define VK_NUMPAD3                      0x00000063
#define VK_NUMPAD4                      0x00000064
#define VK_NUMPAD5                      0x00000065
#define VK_NUMPAD6                      0x00000066
#define VK_NUMPAD7                      0x00000067
#define VK_NUMPAD8                      0x00000068
#define VK_NUMPAD9                      0x00000069
#define VK_NEXT                         0x00000022
#define VK_NONAME                       0x000000FC
#define VK_OEM_CLEAR                    0x000000FE
#define VK_PA1                          0x000000FD
#define VK_PAUSE                        0x00000013
#define VK_PLAY                         0x000000FA
#define VK_PRINT                        0x0000002A
#define VK_PRIOR                        0x00000021
#define VK_PROCESSKEY                   0x000000E5
#define VK_RBUTTON                      0x00000002
#define VK_RETURN                       0x0000000D
#define VK_RIGHT                        0x00000027
#define VK_RWIN                         0x0000005C
#define VK_SCROLL                       0x00000091
#define VK_SELECT                       0x00000029
#define VK_SEPARATOR                    0x0000006C
#define VK_SHIFT                        0x00000010
#define VK_SNAPSHOT                     0x0000002C
#define VK_SPACE                        0x00000020
#define VK_SUBTRACT                     0x0000006D
#define VK_TAB                          0x00000009
#define VK_UP                           0x00000026
#define VK_ZOOM                         0x000000FB

#define IDR_VERSION                     1
#define IDR_EC_ACCEL_TABLE              100
#define IDC_STATIC                      -1
#define IDOK                            1
#define IDCANCEL                        2
#define RT_FILEDATA                     256
#define IDC_GRAYLINE_BTN1               1000
