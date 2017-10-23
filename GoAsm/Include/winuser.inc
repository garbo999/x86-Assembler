;=============================================================;
;          winuser.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINUSER_INC
#Define WINUSER_INC

#Define SB_HORZ             		0
#Define SB_VERT             		1
#Define SB_CTL              		2
#Define SB_BOTH             		3

#Define SB_LINEUP           		0
#Define SB_LINELEFT         		0
#Define SB_LINEDOWN         		1
#Define SB_LINERIGHT        		1
#Define SB_PAGEUP           		2
#Define SB_PAGELEFT         		2
#Define SB_PAGEDOWN         		3
#Define SB_PAGERIGHT        		3
#Define SB_THUMBPOSITION    		4
#Define SB_THUMBTRACK       		5
#Define SB_TOP              		6
#Define SB_LEFT             		6
#Define SB_BOTTOM           		7
#Define SB_RIGHT            		7
#Define SB_ENDSCROLL        		8

#Define SW_HIDE             		0
#Define SW_SHOWNORMAL       		1
#Define SW_NORMAL           		1
#Define SW_SHOWMINIMIZED    		2
#Define SW_SHOWMAXIMIZED    		3
#Define SW_MAXIMIZE         		3
#Define SW_SHOWNOACTIVATE   		4
#Define SW_SHOW             		5
#Define SW_MINIMIZE         		6
#Define SW_SHOWMINNOACTIVE  		7
#Define SW_SHOWNA           		8
#Define SW_RESTORE          		9
#Define SW_SHOWDEFAULT      		10
#Define SW_FORCEMINIMIZE    		11
#Define SW_MAX              		11

#Define HIDE_WINDOW         		0
#Define SHOW_OPENWINDOW     		1
#Define SHOW_ICONWINDOW     		2
#Define SHOW_FULLSCREEN     		3
#Define SHOW_OPENNOACTIVATE 		4

#Define SW_PARENTCLOSING    		1
#Define SW_OTHERZOOM        		2
#Define SW_PARENTOPENING    		3
#Define SW_OTHERUNZOOM      		4

#Define AW_HOR_POSITIVE         	000000001H
#Define AW_HOR_NEGATIVE         	000000002H
#Define AW_VER_POSITIVE         	000000004H
#Define AW_VER_NEGATIVE         	000000008H
#Define AW_CENTER               	000000010H
#Define AW_HIDE                 	000010000H
#Define AW_ACTIVATE             	000020000H
#Define AW_SLIDE                	000040000H
#Define AW_BLEND                	000080000H

#Define KF_EXTENDED         		00100H
#Define KF_DLGMODE          		00800H
#Define KF_MENUMODE         		01000H
#Define KF_ALTDOWN          		02000H
#Define KF_REPEAT           		04000H
#Define KF_UP               		08000H

#Define VK_LBUTTON        			001H
#Define VK_RBUTTON        			002H
#Define VK_CANCEL         			003H
#Define VK_MBUTTON        			004H

#Define VK_BACK           			008H
#Define VK_TAB            			009H

#Define VK_CLEAR          			00CH
#Define VK_RETURN        			00DH

#Define VK_SHIFT          			010H
#Define VK_CONTROL        			011H
#Define VK_MENU           			012H
#Define VK_PAUSE          			013H
#Define VK_CAPITAL        			014H

#Define VK_KANA           			015H
#Define VK_HANGEUL        			015H
#Define VK_HANGUL         			015H
#Define VK_JUNJA          			017H
#Define VK_FINAL          			018H
#Define VK_HANJA          			019H
#Define VK_KANJI          			019H

#Define VK_ESCAPE         			01BH

#Define VK_CONVERT        			01CH
#Define VK_NONCONVERT     			01DH
#Define VK_ACCEPT         			01EH
#Define VK_MODECHANGE     			01FH

#Define VK_SPACE          			020H
#Define VK_PRIOR          			021H
#Define VK_NEXT           			022H
#Define VK_END            			023H
#Define VK_HOME           			024H
#Define VK_LEFT           			025H
#Define VK_UP             			026H
#Define VK_RIGHT          			027H
#Define VK_DOWN           			028H
#Define VK_SELECT         			029H
#Define VK_PRINT          			02AH
#Define VK_EXECUTE        			02BH
#Define VK_SNAPSHOT     			02CH
#Define VK_INSERT         			02DH
#Define VK_DELETE         			02EH
#Define VK_HELP           			02FH

#Define VK_LWIN           			05BH
#Define VK_RWIN           			05CH
#Define VK_APPS           			05DH

#Define VK_NUMPAD0        			060H
#Define VK_NUMPAD1        			061H
#Define VK_NUMPAD2        			062H
#Define VK_NUMPAD3        			063H
#Define VK_NUMPAD4        			064H
#Define VK_NUMPAD5        			065H
#Define VK_NUMPAD6        			066H
#Define VK_NUMPAD7        			067H
#Define VK_NUMPAD8        			068H
#Define VK_NUMPAD9        			069H
#Define VK_MULTIPLY       			06AH
#Define VK_ADD            			06BH
#Define VK_SEPARATOR      			06CH
#Define VK_SUBTRACT       			06DH
#Define VK_DECIMAL        			06EH
#Define VK_DIVIDE         			06FH
#Define VK_F1             			070H
#Define VK_F2             			071H
#Define VK_F3             			072H
#Define VK_F4             			073H
#Define VK_F5             			074H
#Define VK_F6             			075H
#Define VK_F7             			076H
#Define VK_F8             			077H
#Define VK_F9             			078H
#Define VK_F10            			079H
#Define VK_F11            			07AH
#Define VK_F12            			07BH
#Define VK_F13            			07CH
#Define VK_F14            			07DH
#Define VK_F15            			07EH
#Define VK_F16            			07FH
#Define VK_F17            			080H
#Define VK_F18            			081H
#Define VK_F19            			082H
#Define VK_F20            			083H
#Define VK_F21            			084H
#Define VK_F22            			085H
#Define VK_F23            			086H
#Define VK_F24            			087H

#Define VK_NUMLOCK        			090H
#Define VK_SCROLL         			091H

#Define VK_LSHIFT         			0A0H
#Define VK_RSHIFT         			0A1H
#Define VK_LCONTROL       			0A2H
#Define VK_RCONTROL       			0A3H
#Define VK_LMENU          			0A4H
#Define VK_RMENU          			0A5H

#Define VK_PROCESSKEY     			0E5H

#Define VK_ATTN           			0F6H
#Define VK_CRSEL          			0F7H
#Define VK_EXSEL          			0F8H
#Define VK_EREOF          			0F9H
#Define VK_PLAY           			0FAH
#Define VK_ZOOM           			0FBH
#Define VK_NONAME         			0FCH
#Define VK_PA1            			0FDH
#Define VK_OEM_CLEAR      			0FEH

#Define WH_MIN              		(-1)
#Define WH_MSGFILTER        		(-1)
#Define WH_JOURNALRECORD    		0
#Define WH_JOURNALPLAYBACK  		1
#Define WH_KEYBOARD         		2
#Define WH_GETMESSAGE       		3
#Define WH_CALLWNDPROC      		4
#Define WH_CBT              		5
#Define WH_SYSMSGFILTER     		6
#Define WH_MOUSE            		7
#Define WH_HARDWARE         		8
#Define WH_DEBUG            		9
#Define WH_SHELL           			10
#Define WH_FOREGROUNDIDLE  			11
#Define WH_CALLWNDPROCRET  			12

#Define WH_KEYBOARD_LL     			13
#Define WH_MOUSE_LL        			14

#IF (_WINNT)
	#Define WH_MAX					14
#ELSE
	#Define WH_MAX					12
#ENDIF

#Define WH_MINHOOK         			WH_MIN
#Define WH_MAXHOOK         			WH_MAX

#Define HC_ACTION           		0
#Define HC_GETNEXT          		1
#Define HC_SKIP             		2
#Define HC_NOREMOVE         		3
#Define HC_NOREM            		HC_NOREMOVE
#Define HC_SYSMODALON       		4
#Define HC_SYSMODALOFF      		5

#Define HCBT_MOVESIZE       		0
#Define HCBT_MINMAX         		1
#Define HCBT_QS             		2
#Define HCBT_CREATEWND      		3
#Define HCBT_DESTROYWND     		4
#Define HCBT_ACTIVATE       		5
#Define HCBT_CLICKSKIPPED   		6
#Define HCBT_KEYSKIPPED     		7
#Define HCBT_SYSCOMMAND     		8
#Define HCBT_SETFOCUS       		9

#Define MSGF_DIALOGBOX      		0
#Define MSGF_MESSAGEBOX     		1
#Define MSGF_MENU           		2
#Define MSGF_SCROLLBAR      		5
#Define MSGF_NEXTWINDOW     		6
#Define MSGF_MAX            		8
#Define MSGF_USER           		4096

#Define HSHELL_WINDOWCREATED       	1
#Define HSHELL_WINDOWDESTROYED      2
#Define HSHELL_ACTIVATESHELLWINDOW  3

#define HSHELL_WINDOWACTIVATED      4
#Define HSHELL_GETMINRECT           5
#define HSHELL_REDRAW               6
#define HSHELL_TASKMAN              7
#define HSHELL_LANGUAGE             8
#define HSHELL_ACCESSIBILITYSTATE   11
#Define ACCESS_STICKYKEYS           00001H
#Define ACCESS_FILTERKEYS        	00002H
#Define ACCESS_MOUSEKEYS         	00003H

#Define LLKHF_EXTENDED       		000000001H
#Define LLKHF_INJECTED       		000000010H
#Define LLKHF_ALTDOWN        		000000020H
#Define LLKHF_UP             		000000080H

#Define LLMHF_INJECTED       		000000001H

#Define HKL_PREV            		0
#Define HKL_NEXT            		1

#Define KLF_ACTIVATE        		000000001H
#Define KLF_SUBSTITUTE_OK   		000000002H
#Define KLF_UNLOADPREVIOUS  		000000004H
#Define KLF_REORDER         		000000008H
#Define KLF_REPLACELANG     		000000010H
#Define KLF_NOTELLSHELL     		000000080H
#Define KLF_SETFORPROCESS   		000000100H

#Define GMMP_USE_DISPLAY_POINTS 	1
#Define GMMP_USE_DRIVER_POINTS  	2

#Define DESKTOP_READOBJECTS     	00001H
#Define DESKTOP_CREATEWINDOW    	00002H
#Define DESKTOP_CREATEMENU      	00004H
#Define DESKTOP_HOOKCONTROL     	00008H
#Define DESKTOP_JOURNALRECORD   	00010H
#Define DESKTOP_JOURNALPLAYBACK 	00020H
#Define DESKTOP_ENUMERATE       	00040H
#Define DESKTOP_WRITEOBJECTS    	00080H
#Define DESKTOP_SWITCHDESKTOP   	00100H

#Define DF_ALLOWOTHERACCOUNTHOOK	00001H

#Define WINSTA_ENUMDESKTOPS         00001H
#Define WINSTA_READATTRIBUTES       00002H
#Define WINSTA_ACCESSCLIPBOARD      00004H
#Define WINSTA_CREATEDESKTOP        00008H
#Define WINSTA_WRITEATTRIBUTES      00010H
#Define WINSTA_ACCESSGLOBALATOMS    00020H
#Define WINSTA_EXITWINDOWS          00040H
#Define WINSTA_ENUMERATE            00100H
#Define WINSTA_READSCREEN           00200H

#Define UOI_FLAGS       			1
#Define UOI_NAME        			2
#Define UOI_TYPE        			3
#Define UOI_USER_SID    			4

#Define GWL_WNDPROC         		(-4)
#Define GWL_HINSTANCE       		(-6)
#Define GWL_HWNDPARENT      		(-8)
#Define GWL_STYLE           		(-16)
#Define GWL_EXSTYLE         		(-20)
#Define GWL_USERDATA        		(-21)
#Define GWL_ID              		(-12)

#Define GCL_MENUNAME        		(-8)
#Define GCL_HBRBACKGROUND   		(-10)
#Define GCL_HCURSOR         		(-12)
#Define GCL_HICON           		(-14)
#Define GCL_HMODULE         		(-16)
#Define GCL_CBWNDEXTRA      		(-18)
#Define GCL_CBCLSEXTRA      		(-20)
#Define GCL_WNDPROC         		(-24)
#Define GCL_STYLE           		(-26)
#Define GCW_ATOM            		(-32)


#Define WM_NULL                 	00000H
#Define WM_CREATE               	00001H
#Define WM_DESTROY              	00002H
#Define WM_MOVE                 	00003H
#Define WM_SIZE                 	00005H

#Define WM_ACTIVATE             	00006H

#Define WA_INACTIVE     			0
#Define WA_ACTIVE       			1
#Define WA_CLICKACTIVE  			2

#Define WM_SETFOCUS             	00007H
#Define WM_KILLFOCUS            	00008H
#Define WM_ENABLE               	0000AH
#Define WM_SETREDRAW            	0000BH
#Define WM_SETTEXT              	0000CH
#Define WM_GETTEXT              	0000DH
#Define WM_GETTEXTLENGTH        	0000EH
#Define WM_PAINT                	0000FH
#Define WM_CLOSE                	00010H
#Define WM_QUERYENDSESSION      	00011H
#Define WM_QUIT                 	00012H
#Define WM_QUERYOPEN            	00013H
#Define WM_ERASEBKGND           	00014H
#Define WM_SYSCOLORCHANGE       	00015H
#Define WM_ENDSESSION           	00016H
#Define WM_SHOWWINDOW           	00018H
#Define WM_WININICHANGE         	0001AH
#Define WM_SETTINGCHANGE        	WM_WININICHANGE

#Define WM_DEVMODECHANGE        	0001BH
#Define WM_ACTIVATEAPP          	0001CH
#Define WM_FONTCHANGE           	0001DH
#Define WM_TIMECHANGE           	0001EH
#Define WM_CANCELMODE           	0001FH
#Define WM_SETCURSOR            	00020H
#Define WM_MOUSEACTIVATE        	00021H
#Define WM_CHILDACTIVATE        	00022H
#Define WM_QUEUESYNC            	00023H

#Define WM_GETMINMAXINFO        	00024H

#Define WM_PAINTICON            	00026H
#Define WM_ICONERASEBKGND       	00027H
#Define WM_NEXTDLGCTL           	00028H
#Define WM_SPOOLERSTATUS        	0002AH
#Define WM_DRAWITEM             	0002BH
#Define WM_MEASUREITEM          	0002CH
#Define WM_DELETEITEM           	0002DH
#Define WM_VKEYTOITEM           	0002EH
#Define WM_CHARTOITEM           	0002FH
#Define WM_SETFONT              	00030H
#Define WM_GETFONT              	00031H
#Define WM_SETHOTKEY            	00032H
#Define WM_GETHOTKEY            	00033H
#Define WM_QUERYDRAGICON        	00037H
#Define WM_COMPAREITEM          	00039H
#Define WM_GETOBJECT            	0003DH
#Define WM_COMPACTING           	00041H
#Define WM_COMMNOTIFY           	00044H
#Define WM_WINDOWPOSCHANGING    	00046H
#Define WM_WINDOWPOSCHANGED     	00047H

#Define WM_POWER                	00048H

#Define PWR_OK              		1
#Define PWR_FAIL            		(-1)
#Define PWR_SUSPENDREQUEST  		1
#Define PWR_SUSPENDRESUME   		2
#Define PWR_CRITICALRESUME  		3

#Define WM_COPYDATA             	0004AH
#Define WM_CANCELJOURNAL        	0004BH

#Define WM_NOTIFY                   0004EH
#Define WM_INPUTLANGCHANGEREQUEST   00050H
#Define WM_INPUTLANGCHANGE      	00051H
#Define WM_TCARD                	00052H
#Define WM_HELP                 	00053H
#Define WM_USERCHANGED          	00054H
#Define WM_NOTIFYFORMAT         	00055H

#Define NFR_ANSI                	1
#Define NFR_UNICODE             	2
#Define NF_QUERY                	3
#Define NF_REQUERY              	4

#Define WM_CONTEXTMENU          	0007BH
#Define WM_STYLECHANGING        	0007CH
#Define WM_STYLECHANGED         	0007DH
#Define WM_DISPLAYCHANGE        	0007EH
#Define WM_GETICON              	0007FH
#Define WM_SETICON              	00080H

#Define WM_NCCREATE                 00081H
#Define WM_NCDESTROY                00082H
#Define WM_NCCALCSIZE               00083H
#Define WM_NCHITTEST                00084H
#Define WM_NCPAINT                  00085H
#Define WM_NCACTIVATE               00086H
#Define WM_GETDLGCODE               00087H
#Define WM_SYNCPAINT                00088H
#Define WM_NCMOUSEMOVE              000A0H
#Define WM_NCLBUTTONDOWN            000A1H
#Define WM_NCLBUTTONUP              000A2H
#Define WM_NCLBUTTONDBLCLK          000A3H
#Define WM_NCRBUTTONDOWN            000A4H
#Define WM_NCRBUTTONUP              000A5H
#Define WM_NCRBUTTONDBLCLK          000A6H
#Define WM_NCMBUTTONDOWN            000A7H
#Define WM_NCMBUTTONUP              000A8H
#Define WM_NCMBUTTONDBLCLK          000A9H

#Define WM_KEYFIRST                 00100H
#Define WM_KEYDOWN                  00100H
#Define WM_KEYUP                    00101H
#Define WM_CHAR                     00102H
#Define WM_DEADCHAR                 00103H
#Define WM_SYSKEYDOWN               00104H
#Define WM_SYSKEYUP                 00105H
#Define WM_SYSCHAR                  00106H
#Define WM_SYSDEADCHAR              00107H
#Define WM_KEYLAST                  00108H

#Define WM_IME_STARTCOMPOSITION     0010DH
#Define WM_IME_ENDCOMPOSITION       0010EH
#Define WM_IME_COMPOSITION          0010FH
#Define WM_IME_KEYLAST              0010FH

#Define WM_INITDIALOG               00110H
#Define WM_COMMAND                  00111H
#Define WM_SYSCOMMAND               00112H
#Define WM_TIMER                    00113H
#Define WM_HSCROLL                  00114H
#Define WM_VSCROLL                  00115H
#Define WM_INITMENU                 00116H
#Define WM_INITMENUPOPUP            00117H
#Define WM_MENUSELECT               0011FH
#Define WM_MENUCHAR                 00120H
#Define WM_ENTERIDLE                00121H
#Define WM_MENURBUTTONUP            00122H
#Define WM_MENUDRAG                 00123H
#Define WM_MENUGETOBJECT            00124H
#Define WM_UNINITMENUPOPUP          00125H
#Define WM_MENUCOMMAND              00126H

#Define WM_CTLCOLORMSGBOX           00132H
#Define WM_CTLCOLOREDIT             00133H
#Define WM_CTLCOLORLISTBOX          00134H
#Define WM_CTLCOLORBTN              00135H
#Define WM_CTLCOLORDLG              00136H
#Define WM_CTLCOLORSCROLLBAR        00137H
#Define WM_CTLCOLORSTATIC           00138H


#Define WM_MOUSEFIRST               00200H
#Define WM_MOUSEMOVE                00200H
#Define WM_LBUTTONDOWN              00201H
#Define WM_LBUTTONUP                00202H
#Define WM_LBUTTONDBLCLK            00203H
#Define WM_RBUTTONDOWN              00204H
#Define WM_RBUTTONUP                00205H
#Define WM_RBUTTONDBLCLK            00206H
#Define WM_MBUTTONDOWN              00207H
#Define WM_MBUTTONUP                00208H
#Define WM_MBUTTONDBLCLK            00209H

#Define WM_MOUSEWHEEL               0020AH
#Define WM_MOUSELAST                0020AH

#Define WHEEL_DELTA                 120
#Define WHEEL_PAGESCROLL            0FFFFFFFFH

#Define WM_PARENTNOTIFY             00210H
#Define WM_ENTERMENULOOP            00211H
#Define WM_EXITMENULOOP             00212H

#Define WM_NEXTMENU                 00213H

#Define WM_SIZING                   00214H
#Define WM_CAPTURECHANGED           00215H
#Define WM_MOVING                   00216H
#Define WM_POWERBROADCAST           00218H

#Define PBT_APMQUERYSUSPEND         00000H
#Define PBT_APMQUERYSTANDBY         00001H

#Define PBT_APMQUERYSUSPENDFAILED   00002H
#Define PBT_APMQUERYSTANDBYFAILED   00003H

#Define PBT_APMSUSPEND              00004H
#Define PBT_APMSTANDBY              00005H

#Define PBT_APMRESUMECRITICAL       00006H
#Define PBT_APMRESUMESUSPEND        00007H
#Define PBT_APMRESUMESTANDBY        00008H

#Define PBTF_APMRESUMEFROMFAILURE   000000001H

#Define PBT_APMBATTERYLOW           00009H
#Define PBT_APMPOWERSTATUSCHANGE    0000AH

#Define PBT_APMOEMEVENT             0000BH
#Define PBT_APMRESUMEAUTOMATIC      00012H

#Define WM_DEVICECHANGE             00219H

#Define WM_MDICREATE                00220H
#Define WM_MDIDESTROY               00221H
#Define WM_MDIACTIVATE              00222H
#Define WM_MDIRESTORE               00223H
#Define WM_MDINEXT                  00224H
#Define WM_MDIMAXIMIZE              00225H
#Define WM_MDITILE                  00226H
#Define WM_MDICASCADE               00227H
#Define WM_MDIICONARRANGE           00228H
#Define WM_MDIGETACTIVE             00229H

#Define WM_MDISETMENU               00230H
#Define WM_ENTERSIZEMOVE            00231H
#Define WM_EXITSIZEMOVE             00232H
#Define WM_DROPFILES                00233H
#Define WM_MDIREFRESHMENU           00234H

#Define WM_IME_SETCONTEXT           00281H
#Define WM_IME_NOTIFY               00282H
#Define WM_IME_CONTROL              00283H
#Define WM_IME_COMPOSITIONFULL      00284H
#Define WM_IME_SELECT               00285H
#Define WM_IME_CHAR                 00286H
#Define WM_IME_REQUEST              00288H
#Define WM_IME_KEYDOWN              00290H
#Define WM_IME_KEYUP                00291H

#Define WM_MOUSEHOVER               002A1H
#Define WM_MOUSELEAVE               002A3H

#Define WM_CUT                      00300H
#Define WM_COPY                     00301H
#Define WM_PASTE                    00302H
#Define WM_CLEAR                    00303H
#Define WM_UNDO                     00304H
#Define WM_RENDERFORMAT             00305H
#Define WM_RENDERALLFORMATS         00306H
#Define WM_DESTROYCLIPBOARD         00307H
#Define WM_DRAWCLIPBOARD            00308H
#Define WM_PAINTCLIPBOARD           00309H
#Define WM_VSCROLLCLIPBOARD         0030AH
#Define WM_SIZECLIPBOARD            0030BH
#Define WM_ASKCBFORMATNAME          0030CH
#Define WM_CHANGECBCHAIN            0030DH
#Define WM_HSCROLLCLIPBOARD         0030EH
#Define WM_QUERYNEWPALETTE          0030FH
#Define WM_PALETTEISCHANGING        00310H
#Define WM_PALETTECHANGED           00311H
#Define WM_HOTKEY                   00312H

#Define WM_PRINT                    00317H
#Define WM_PRINTCLIENT              00318H

#Define WM_HANDHELDFIRST            00358H
#Define WM_HANDHELDLAST             0035FH

#Define WM_AFXFIRST                 00360H
#Define WM_AFXLAST                  0037FH

#Define WM_PENWINFIRST              00380H
#Define WM_PENWINLAST               0038FH

#Define WM_APP                      08000H

#Define WM_USER                     00400H

#Define WMSZ_LEFT           		1
#Define WMSZ_RIGHT          		2
#Define WMSZ_TOP            		3
#Define WMSZ_TOPLEFT        		4
#Define WMSZ_TOPRIGHT       		5
#Define WMSZ_BOTTOM         		6
#Define WMSZ_BOTTOMLEFT     		7
#Define WMSZ_BOTTOMRIGHT    		8

#Define HTERROR             		(-2)
#Define HTTRANSPARENT       		(-1)
#Define HTNOWHERE           		0
#Define HTCLIENT            		1
#Define HTCAPTION           		2
#Define HTSYSMENU           		3
#Define HTGROWBOX           		4
#Define HTSIZE              		HTGROWBOX
#Define HTMENU              		5
#Define HTHSCROLL           		6
#Define HTVSCROLL           		7
#Define HTMINBUTTON         		8
#Define HTMAXBUTTON         		9
#Define HTLEFT              		10
#Define HTRIGHT             		11
#Define HTTOP               		12
#Define HTTOPLEFT           		13
#Define HTTOPRIGHT          		14
#Define HTBOTTOM            		15
#Define HTBOTTOMLEFT        		16
#Define HTBOTTOMRIGHT       		17
#Define HTBORDER            		18
#Define HTREDUCE            		HTMINBUTTON
#Define HTZOOM              		HTMAXBUTTON
#Define HTSIZEFIRST         		HTLEFT
#Define HTSIZELAST          		HTBOTTOMRIGHT
#Define HTOBJECT            		19
#Define HTCLOSE             		20
#Define HTHELP              		21

#Define SMTO_NORMAL         		00000H
#Define SMTO_BLOCK          		00001H
#Define SMTO_ABORTIFHUNG    		00002H
#Define SMTO_NOTIMEOUTIFNOTHUNG 	00008H

#Define MA_ACTIVATE         		1
#Define MA_ACTIVATEANDEAT   		2
#Define MA_NOACTIVATE       		3
#Define MA_NOACTIVATEANDEAT 		4

#Define ICON_SMALL          		0
#Define ICON_BIG            		1

#Define SIZE_RESTORED       		0
#Define SIZE_MINIMIZED      		1
#Define SIZE_MAXIMIZED      		2
#Define SIZE_MAXSHOW        		3
#Define SIZE_MAXHIDE        		4

#Define SIZENORMAL          		SIZE_RESTORED
#Define SIZEICONIC          		SIZE_MINIMIZED
#Define SIZEFULLSCREEN      		SIZE_MAXIMIZED
#Define SIZEZOOMSHOW        		SIZE_MAXSHOW
#Define SIZEZOOMHIDE        		SIZE_MAXHIDE

#Define WVR_ALIGNTOP        		00010H
#Define WVR_ALIGNLEFT       		00020H
#Define WVR_ALIGNBOTTOM     		00040H
#Define WVR_ALIGNRIGHT      		00080H
#Define WVR_HREDRAW         		00100H
#Define WVR_VREDRAW         		00200H
#Define WVR_REDRAW         			(WVR_HREDRAW | WVR_VREDRAW)
#Define WVR_VALIDRECTS      		00400H

#Define MK_LBUTTON          		00001H
#Define MK_RBUTTON          		00002H
#Define MK_SHIFT            		00004H
#Define MK_CONTROL          		00008H
#Define MK_MBUTTON          		00010H

#Define TME_HOVER       			000000001H
#Define TME_LEAVE       			000000002H
#Define TME_QUERY       			040000000H
#Define TME_CANCEL      			080000000H

#Define HOVER_DEFAULT   			0FFFFFFFFH

#Define WS_OVERLAPPED       		000000000H
#Define WS_POPUP            		080000000H
#Define WS_CHILD            		040000000H
#Define WS_MINIMIZE         		020000000H
#Define WS_VISIBLE          		010000000H
#Define WS_DISABLED         		008000000H
#Define WS_CLIPSIBLINGS     		004000000H
#Define WS_CLIPCHILDREN     		002000000H
#Define WS_MAXIMIZE         		001000000H
#Define WS_CAPTION          		000C00000H
#Define WS_BORDER           		000800000H
#Define WS_DLGFRAME         		000400000H
#Define WS_VSCROLL          		000200000H
#Define WS_HSCROLL          		000100000H
#Define WS_SYSMENU          		000080000H
#Define WS_THICKFRAME       		000040000H
#Define WS_GROUP            		000020000H
#Define WS_TABSTOP          		000010000H

#Define WS_MINIMIZEBOX      		000020000H
#Define WS_MAXIMIZEBOX      		000010000H

#Define WS_TILED            		WS_OVERLAPPED
#Define WS_ICONIC           		WS_MINIMIZE
#Define WS_SIZEBOX          		WS_THICKFRAME
#Define WS_TILEDWINDOW      		WS_OVERLAPPEDWINDOW

#Define WS_OVERLAPPEDWINDOW			(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)

#Define WS_POPUPWINDOW				(WS_POPUP | WS_BORDER | WS_SYSMENU)

#Define WS_CHILDWINDOW      		WS_CHILD

#Define WS_EX_DLGMODALFRAME     	000000001H
#Define WS_EX_NOPARENTNOTIFY    	000000004H
#Define WS_EX_TOPMOST           	000000008H
#Define WS_EX_ACCEPTFILES       	000000010H
#Define WS_EX_TRANSPARENT       	000000020H
#Define WS_EX_MDICHILD          	000000040H
#Define WS_EX_TOOLWINDOW        	000000080H
#Define WS_EX_WINDOWEDGE        	000000100H
#Define WS_EX_CLIENTEDGE        	000000200H
#Define WS_EX_CONTEXTHELP       	000000400H

#Define WS_EX_RIGHT             	000001000H
#Define WS_EX_LEFT              	000000000H
#Define WS_EX_RTLREADING        	000002000H
#Define WS_EX_LTRREADING        	000000000H
#Define WS_EX_LEFTSCROLLBAR     	000004000H
#Define WS_EX_RIGHTSCROLLBAR    	000000000H

#Define WS_EX_CONTROLPARENT     	000010000H
#Define WS_EX_STATICEDGE        	000020000H
#Define WS_EX_APPWINDOW         	000040000H

#Define WS_EX_OVERLAPPEDWINDOW  	(WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#Define WS_EX_PALETTEWINDOW     	(WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)

#Define CS_VREDRAW          		00001H
#Define CS_HREDRAW          		00002H
#Define CS_DBLCLKS          		00008H
#Define CS_OWNDC            		00020H
#Define CS_CLASSDC          		00040H
#Define CS_PARENTDC         		00080H
#Define CS_NOCLOSE          		00200H
#Define CS_SAVEBITS         		00800H
#Define CS_BYTEALIGNCLIENT  		01000H
#Define CS_BYTEALIGNWINDOW  		02000H
#Define CS_GLOBALCLASS      		04000H

#Define CS_IME              		000010000H

#Define PRF_CHECKVISIBLE    		000000001H
#Define PRF_NONCLIENT       		000000002H
#Define PRF_CLIENT          		000000004H
#Define PRF_ERASEBKGND      		000000008H
#Define PRF_CHILDREN        		000000010H
#Define PRF_OWNED           		000000020H

#Define BDR_RAISEDOUTER 			00001H
#Define BDR_SUNKENOUTER 			00002H
#Define BDR_RAISEDINNER 			00004H
#Define BDR_SUNKENINNER 			00008H

#Define BDR_OUTER       			00003H
#Define BDR_INNER       			0000CH

#Define EDGE_RAISED     			(BDR_RAISEDOUTER | BDR_RAISEDINNER)
#Define EDGE_SUNKEN     			(BDR_SUNKENOUTER | BDR_SUNKENINNER)
#Define EDGE_ETCHED     			(BDR_SUNKENOUTER | BDR_RAISEDINNER)
#Define EDGE_BUMP       			(BDR_RAISEDOUTER | BDR_SUNKENINNER)

#Define BF_LEFT         			00001H
#Define BF_TOP          			00002H
#Define BF_RIGHT        			00004H
#Define BF_BOTTOM       			00008H

#Define BF_TOPLEFT      			(BF_TOP | BF_LEFT)
#Define BF_TOPRIGHT     			(BF_TOP | BF_RIGHT)
#Define BF_BOTTOMLEFT   			(BF_BOTTOM | BF_LEFT)
#Define BF_BOTTOMRIGHT  			(BF_BOTTOM | BF_RIGHT)
#Define BF_RECT         			(BF_LEFT | BF_TOP | BF_RIGHT | BF_BOTTOM)

#Define BF_DIAGONAL     			00010H

#Define BF_DIAGONAL_ENDTOPRIGHT     (BF_DIAGONAL | BF_TOP | BF_RIGHT)
#define BF_DIAGONAL_ENDTOPLEFT      (BF_DIAGONAL | BF_TOP | BF_LEFT)
#define BF_DIAGONAL_ENDBOTTOMLEFT   (BF_DIAGONAL | BF_BOTTOM | BF_LEFT)
#define BF_DIAGONAL_ENDBOTTOMRIGHT  (BF_DIAGONAL | BF_BOTTOM | BF_RIGHT)

#Define BF_MIDDLE       			00800H
#Define BF_SOFT         			01000H
#Define BF_ADJUST       			02000H
#Define BF_FLAT         			04000H
#Define BF_MONO         			08000H

#Define DFC_CAPTION             	1
#Define DFC_MENU                	2
#Define DFC_SCROLL              	3
#Define DFC_BUTTON              	4
#Define DFC_POPUPMENU           	5

#Define DFCS_CAPTIONCLOSE       	00000H
#Define DFCS_CAPTIONMIN         	00001H
#Define DFCS_CAPTIONMAX         	00002H
#Define DFCS_CAPTIONRESTORE     	00003H
#Define DFCS_CAPTIONHELP        	00004H

#Define DFCS_MENUARROW          	00000H
#Define DFCS_MENUCHECK          	00001H
#Define DFCS_MENUBULLET         	00002H
#Define DFCS_MENUARROWRIGHT     	00004H
#Define DFCS_SCROLLUP           	00000H
#Define DFCS_SCROLLDOWN         	00001H
#Define DFCS_SCROLLLEFT         	00002H
#Define DFCS_SCROLLRIGHT        	00003H
#Define DFCS_SCROLLCOMBOBOX     	00005H
#Define DFCS_SCROLLSIZEGRIP     	00008H
#Define DFCS_SCROLLSIZEGRIPRIGHT 	00010H

#Define DFCS_BUTTONCHECK        	00000H
#Define DFCS_BUTTONRADIOIMAGE   	00001H
#Define DFCS_BUTTONRADIOMASK    	00002H
#Define DFCS_BUTTONRADIO        	00004H
#Define DFCS_BUTTON3STATE       	00008H
#Define DFCS_BUTTONPUSH         	00010H

#Define DFCS_INACTIVE           	00100H
#Define DFCS_PUSHED             	00200H
#Define DFCS_CHECKED            	00400H

#Define DFCS_TRANSPARENT        	00800H
#Define DFCS_HOT                	01000H

#Define DFCS_ADJUSTRECT         	02000H
#Define DFCS_FLAT               	04000H
#Define DFCS_MONO               	08000H

#Define DC_ACTIVE           		00001H
#Define DC_SMALLCAP         		00002H
#Define DC_ICON             		00004H
#Define DC_TEXT             		00008H
#Define DC_INBUTTON         		00010H
#Define DC_GRADIENT         		00020H

#Define IDANI_OPEN          		1
#Define IDANI_CLOSE         		2
#Define IDANI_CAPTION       		3

#Define CF_TEXT             		1
#Define CF_BITMAP           		2
#Define CF_METAFILEPICT     		3
#Define CF_SYLK             		4
#Define CF_DIF              		5
#Define CF_TIFF             		6
#Define CF_OEMTEXT          		7
#Define CF_DIB              		8
#Define CF_PALETTE          		9
#Define CF_PENDATA          		10
#Define CF_RIFF             		11
#Define CF_WAVE            			12
#Define CF_UNICODETEXT      		13
#Define CF_ENHMETAFILE      		14
#Define CF_HDROP            		15
#Define CF_LOCALE           		16
#Define CF_MAX              		17

#Define CF_OWNERDISPLAY     		00080H
#Define CF_DSPTEXT          		00081H
#Define CF_DSPBITMAP        		00082H
#Define CF_DSPMETAFILEPICT  		00083H
#Define CF_DSPENHMETAFILE   		0008EH

#Define CF_PRIVATEFIRST     		00200H
#Define CF_PRIVATELAST      		002FFH

#Define CF_GDIOBJFIRST      		00300H
#Define CF_GDIOBJLAST       		003FFH

#Define FVIRTKEY  					TRUE
#Define FNOINVERT 					002H
#Define FSHIFT    					004H
#Define FCONTROL  					008H
#Define FALT      					010H

#Define WPF_SETMINPOSITION      	00001H
#Define WPF_RESTORETOMAXIMIZED  	00002H

#Define ODT_MENU        			1
#Define ODT_LISTBOX     			2
#Define ODT_COMBOBOX    			3
#Define ODT_BUTTON      			4
#Define ODT_STATIC      			5

#Define ODA_DRAWENTIRE  			00001H
#Define ODA_SELECT      			00002H
#Define ODA_FOCUS       			00004H

#Define ODS_SELECTED    			00001H
#Define ODS_GRAYED      			00002H
#Define ODS_DISABLED    			00004H
#Define ODS_CHECKED     			00008H
#Define ODS_FOCUS       			00010H
#Define ODS_DEFAULT         		00020H
#Define ODS_COMBOBOXEDIT    		01000H
#Define ODS_HOTLIGHT        		00040H
#Define ODS_INACTIVE        		00080H

#Define PM_NOREMOVE         		00000H
#Define PM_REMOVE           		00001H
#Define PM_NOYIELD          		00002H

#Define MOD_ALT         			00001H
#Define MOD_CONTROL     			00002H
#Define MOD_SHIFT       			00004H
#Define MOD_WIN         			00008H

#Define IDHOT_SNAPWINDOW        	(-1)
#Define IDHOT_SNAPDESKTOP       	(-2)

#Define ENDSESSION_LOGOFF    		080000000H

#Define EWX_LOGOFF           		0
#Define EWX_SHUTDOWN         		000000001H
#Define EWX_REBOOT           		000000002H
#Define EWX_FORCE            		000000004H
#Define EWX_POWEROFF         		000000008H
#Define EWX_FORCEIFHUNG      		000000010H

#Define BSM_ALLCOMPONENTS       	000000000H
#Define BSM_VXDS                	000000001H
#Define BSM_NETDRIVER           	000000002H
#Define BSM_INSTALLABLEDRIVERS  	000000004H
#Define BSM_APPLICATIONS        	000000008H
#Define BSM_ALLDESKTOPS         	000000010H

#Define BSF_QUERY               	000000001H
#Define BSF_IGNORECURRENTTASK   	000000002H
#Define BSF_FLUSHDISK           	000000004H
#Define BSF_NOHANG              	000000008H
#Define BSF_POSTMESSAGE         	000000010H
#Define BSF_FORCEIFHUNG         	000000020H
#Define BSF_NOTIMEOUTIFNOTHUNG  	000000040H

#Define BROADCAST_QUERY_DENY        0424D5144H

#Define DEVICE_NOTIFY_WINDOW_HANDLE	000000000H

#Define HWND_MESSAGE     			(-3)

#Define ISMEX_NOSEND      			000000000H
#Define ISMEX_SEND        			000000001H
#Define ISMEX_NOTIFY      			000000002H
#Define ISMEX_CALLBACK    			000000004H
#Define ISMEX_REPLIED     			000000008H

#Define CW_USEDEFAULT       		080000000H

#Define HWND_DESKTOP        		0

#Define FLASHW_STOP         		0
#Define FLASHW_CAPTION      		000000001H
#Define FLASHW_TRAY         		000000002H
#Define FLASHW_ALL          		(FLASHW_CAPTION | FLASHW_TRAY)
#Define FLASHW_TIMER        		000000004H
#Define FLASHW_TIMERNOFG    		00000000CH

#Define SWP_NOSIZE          		00001H
#Define SWP_NOMOVE          		00002H
#Define SWP_NOZORDER        		00004H
#Define SWP_NOREDRAW        		00008H
#Define SWP_NOACTIVATE      		00010H
#Define SWP_FRAMECHANGED    		00020H
#Define SWP_SHOWWINDOW      		00040H
#Define SWP_HIDEWINDOW      		00080H
#Define SWP_NOCOPYBITS      		00100H
#Define SWP_NOOWNERZORDER   		00200H
#Define SWP_NOSENDCHANGING  		00400H

#Define SWP_DRAWFRAME       		SWP_FRAMECHANGED
#Define SWP_NOREPOSITION    		SWP_NOOWNERZORDER

#Define SWP_DEFERERASE      		02000H
#Define SWP_ASYNCWINDOWPOS  		04000H

#Define HWND_TOP        			0
#Define HWND_BOTTOM     			1
#Define HWND_TOPMOST    			(-1)
#Define HWND_NOTOPMOST  			(-2)

#Define DLGWINDOWEXTRA				30

#Define KEYEVENTF_EXTENDEDKEY 		00001H
#Define KEYEVENTF_KEYUP       		00002H

#Define MOUSEEVENTF_MOVE        	00001H
#Define MOUSEEVENTF_LEFTDOWN    	00002H
#Define MOUSEEVENTF_LEFTUP      	00004H
#Define MOUSEEVENTF_RIGHTDOWN   	00008H
#Define MOUSEEVENTF_RIGHTUP     	00010H
#Define MOUSEEVENTF_MIDDLEDOWN  	00020H
#Define MOUSEEVENTF_MIDDLEUP    	00040H
#Define MOUSEEVENTF_WHEEL       	00800H
#Define MOUSEEVENTF_ABSOLUTE    	08000H

#Define INPUT_MOUSE     			0
#Define INPUT_KEYBOARD  			1
#Define INPUT_HARDWARE  			2

#Define MWMO_WAITALL        		00001H
#Define MWMO_ALERTABLE      		00002H
#Define MWMO_INPUTAVAILABLE 		00004H

#Define QS_KEY              		00001H
#Define QS_MOUSEMOVE        		00002H
#Define QS_MOUSEBUTTON      		00004H
#Define QS_POSTMESSAGE      		00008H
#Define QS_TIMER            		00010H
#Define QS_PAINT            		00020H
#Define QS_SENDMESSAGE      		00040H
#Define QS_HOTKEY           		00080H
#Define QS_ALLPOSTMESSAGE   		00100H

#Define QS_MOUSE           			(QS_MOUSEMOVE | QS_MOUSEBUTTON)
#Define QS_INPUT           			(QS_MOUSE | QS_KEY)
#Define QS_ALLEVENTS       			(QS_INPUT | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY)
#Define QS_ALLINPUT        			(QS_INPUT | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY | QS_SENDMESSAGE)

#Define SM_CXSCREEN             	0
#Define SM_CYSCREEN             	1
#Define SM_CXVSCROLL            	2
#Define SM_CYHSCROLL            	3
#Define SM_CYCAPTION            	4
#Define SM_CXBORDER             	5
#Define SM_CYBORDER             	6
#Define SM_CXDLGFRAME           	7
#Define SM_CYDLGFRAME           	8
#Define SM_CYVTHUMB             	9
#Define SM_CXHTHUMB             	10
#Define SM_CXICON               	11
#Define SM_CYICON               	12
#Define SM_CXCURSOR             	13
#Define SM_CYCURSOR             	14
#Define SM_CYMENU               	15
#Define SM_CXFULLSCREEN         	16
#Define SM_CYFULLSCREEN         	17
#Define SM_CYKANJIWINDOW        	18
#Define SM_MOUSEPRESENT         	19
#Define SM_CYVSCROLL            	20
#Define SM_CXHSCROLL            	21
#Define SM_DEBUG                	22
#Define SM_SWAPBUTTON           	23
#Define SM_RESERVED1            	24
#Define SM_RESERVED2            	25
#Define SM_RESERVED3            	26
#Define SM_RESERVED4            	27
#Define SM_CXMIN                	28
#Define SM_CYMIN                	29
#Define SM_CXSIZE               	30
#Define SM_CYSIZE               	31
#Define SM_CXFRAME              	32
#Define SM_CYFRAME              	33
#Define SM_CXMINTRACK           	34
#Define SM_CYMINTRACK           	35
#Define SM_CXDOUBLECLK          	36
#Define SM_CYDOUBLECLK          	37
#Define SM_CXICONSPACING        	38
#Define SM_CYICONSPACING        	39
#Define SM_MENUDROPALIGNMENT    	40
#Define SM_PENWINDOWS           	41
#Define SM_DBCSENABLED          	42
#Define SM_CMOUSEBUTTONS        	43

#Define SM_CXFIXEDFRAME           	SM_CXDLGFRAME
#Define SM_CYFIXEDFRAME           	SM_CYDLGFRAME
#Define SM_CXSIZEFRAME            	SM_CXFRAME
#Define SM_CYSIZEFRAME            	SM_CYFRAME

#Define SM_SECURE               	44
#Define SM_CXEDGE               	45
#Define SM_CYEDGE               	46
#Define SM_CXMINSPACING         	47
#Define SM_CYMINSPACING         	48
#Define SM_CXSMICON             	49
#Define SM_CYSMICON             	50
#Define SM_CYSMCAPTION          	51
#Define SM_CXSMSIZE             	52
#Define SM_CYSMSIZE             	53
#Define SM_CXMENUSIZE           	54
#Define SM_CYMENUSIZE           	55
#Define SM_ARRANGE              	56
#Define SM_CXMINIMIZED          	57
#Define SM_CYMINIMIZED          	58
#Define SM_CXMAXTRACK           	59
#Define SM_CYMAXTRACK           	60
#Define SM_CXMAXIMIZED          	61
#Define SM_CYMAXIMIZED          	62
#Define SM_NETWORK              	63
#Define SM_CLEANBOOT            	67
#Define SM_CXDRAG               	68
#Define SM_CYDRAG               	69
#Define SM_SHOWSOUNDS           	70
#Define SM_CXMENUCHECK          	71
#Define SM_CYMENUCHECK          	72
#Define SM_SLOWMACHINE          	73
#Define SM_MIDEASTENABLED       	74
#Define SM_MOUSEWHEELPRESENT    	75

#Define SM_XVIRTUALSCREEN       	76
#Define SM_YVIRTUALSCREEN       	77
#Define SM_CXVIRTUALSCREEN      	78
#Define SM_CYVIRTUALSCREEN      	79
#Define SM_CMONITORS            	80
#Define SM_SAMEDISPLAYFORMAT    	81

#Define SM_CMETRICS             	83

#Define MNC_IGNORE  				0
#Define MNC_CLOSE   				1
#Define MNC_EXECUTE 				2
#Define MNC_SELECT  				3

#Define MNS_NOCHECK         		080000000H
#Define MNS_MODELESS        		040000000H
#Define MNS_DRAGDROP        		020000000H
#Define MNS_AUTODISMISS     		010000000H
#Define MNS_NOTIFYBYPOS     		008000000H
#Define MNS_CHECKORBMP      		004000000H

#Define MIM_MAXHEIGHT               000000001H
#Define MIM_BACKGROUND              000000002H
#Define MIM_HELPID                  000000004H
#Define MIM_MENUDATA                000000008H
#Define MIM_STYLE                   000000010H
#Define MIM_APPLYTOSUBMENUS         080000000H

#Define MND_CONTINUE       			0
#Define MND_ENDMENU        			1

#Define MNGO_NOINTERFACE     		000000000H
#Define MNGO_NOERROR         		000000001H

#Define MIIM_STATE       			000000001H
#Define MIIM_ID          			000000002H
#Define MIIM_SUBMENU     			000000004H
#Define MIIM_CHECKMARKS  			000000008H
#Define MIIM_TYPE        			000000010H
#Define MIIM_DATA        			000000020H

#Define MIIM_STRING      			000000040H
#Define MIIM_BITMAP      			000000080H
#Define MIIM_FTYPE       			000000100H

#Define HBMMENU_CALLBACK            (-1)
#Define HBMMENU_SYSTEM              1
#Define HBMMENU_MBAR_RESTORE        2
#Define HBMMENU_MBAR_MINIMIZE       3
#Define HBMMENU_MBAR_CLOSE          5
#Define HBMMENU_MBAR_CLOSE_D        6
#Define HBMMENU_MBAR_MINIMIZE_D     7
#Define HBMMENU_POPUP_CLOSE         8
#Define HBMMENU_POPUP_RESTORE       9
#Define HBMMENU_POPUP_MAXIMIZE      10
#Define HBMMENU_POPUP_MINIMIZE      11

#Define GMDI_USEDISABLED    		00001H
#Define GMDI_GOINTOPOPUPS   		00002H

#Define TPM_LEFTBUTTON  			00000H
#Define TPM_RIGHTBUTTON 			00002H
#Define TPM_LEFTALIGN   			00000H
#Define TPM_CENTERALIGN 			00004H
#Define TPM_RIGHTALIGN  			00008H
#Define TPM_TOPALIGN        		00000H
#Define TPM_VCENTERALIGN    		00010H
#Define TPM_BOTTOMALIGN     		00020H

#Define TPM_HORIZONTAL      		00000H
#Define TPM_VERTICAL        		00040H
#Define TPM_NONOTIFY        		00080H
#Define TPM_RETURNCMD       		00100H
#Define TPM_RECURSE         		00001H

#Define DOF_EXECUTABLE      		08001H
#Define DOF_DOCUMENT        		08002H
#Define DOF_DIRECTORY       		08003H
#Define DOF_MULTIPLE        		08004H
#Define DOF_PROGMAN         		00001H
#Define DOF_SHELLDATA       		00002H

#Define DO_DROPFILE         		0454C4946H
#Define DO_PRINTFILE        		0544E5250H

#Define DT_TOP              		000000000H
#Define DT_LEFT             		000000000H
#Define DT_CENTER           		000000001H
#Define DT_RIGHT            		000000002H
#Define DT_VCENTER          		000000004H
#Define DT_BOTTOM           		000000008H
#Define DT_WORDBREAK        		000000010H
#Define DT_SINGLELINE       		000000020H
#Define DT_EXPANDTABS       		000000040H
#Define DT_TABSTOP          		000000080H
#Define DT_NOCLIP           		000000100H
#Define DT_EXTERNALLEADING  		000000200H
#Define DT_CALCRECT         		000000400H
#Define DT_NOPREFIX         		000000800H
#Define DT_INTERNAL         		000001000H

#Define DT_EDITCONTROL      		000002000H
#Define DT_PATH_ELLIPSIS    		000004000H
#Define DT_END_ELLIPSIS     		000008000H
#Define DT_MODIFYSTRING     		000010000H
#Define DT_RTLREADING       		000020000H
#Define DT_WORD_ELLIPSIS    		000040000H

#Define DST_COMPLEX     			00000H
#Define DST_TEXT        			00001H
#Define DST_PREFIXTEXT  			00002H
#Define DST_ICON        			00003H
#Define DST_BITMAP      			00004H

#Define DSS_NORMAL      			00000H
#Define DSS_UNION       			00010H
#Define DSS_DISABLED    			00020H
#Define DSS_MONO        			00080H
#Define DSS_RIGHT       			08000H

#Define DCX_WINDOW           		000000001H
#Define DCX_CACHE            		000000002H
#Define DCX_NORESETATTRS     		000000004H
#Define DCX_CLIPCHILDREN     		000000008H
#Define DCX_CLIPSIBLINGS     		000000010H
#Define DCX_PARENTCLIP       		000000020H

#Define DCX_EXCLUDERGN       		000000040H
#Define DCX_INTERSECTRGN     		000000080H

#Define DCX_EXCLUDEUPDATE    		000000100H
#Define DCX_INTERSECTUPDATE  		000000200H

#Define DCX_LOCKWINDOWUPDATE 		000000400H

#Define DCX_VALIDATE         		000200000H

#Define CUDR_NORMAL             	00000H
#Define CUDR_NOSNAPTOGRID       	00001H
#Define CUDR_NORESOLVEPOSITIONS 	00002H
#Define CUDR_NOCLOSEGAPS        	00004H
#Define CUDR_NEGATIVECOORDS     	00008H
#Define CUDR_NOPRIMARY          	00010H

#Define RDW_INVALIDATE          	00001H
#Define RDW_INTERNALPAINT       	00002H
#Define RDW_ERASE               	00004H

#Define RDW_VALIDATE            	00008H
#Define RDW_NOINTERNALPAINT     	00010H
#Define RDW_NOERASE             	00020H

#Define RDW_NOCHILDREN          	00040H
#Define RDW_ALLCHILDREN         	00080H

#Define RDW_UPDATENOW           	00100H
#Define RDW_ERASENOW            	00200H

#Define RDW_FRAME               	00400H
#Define RDW_NOFRAME             	00800H

#Define SW_SCROLLCHILDREN   		00001H
#Define SW_INVALIDATE       		00002H
#Define SW_ERASE            		00004H
#Define SW_SMOOTHSCROLL     		00010H

#Define ESB_ENABLE_BOTH     		00000H
#Define ESB_DISABLE_BOTH    		00003H

#Define ESB_DISABLE_LEFT    		00001H
#Define ESB_DISABLE_RIGHT   		00002H

#Define ESB_DISABLE_UP      		00001H
#Define ESB_DISABLE_DOWN    		00002H

#Define ESB_DISABLE_LTUP    		ESB_DISABLE_LEFT
#Define ESB_DISABLE_RTDN    		ESB_DISABLE_RIGHT

#Define HELPINFO_WINDOW    			00001H
#Define HELPINFO_MENUITEM  			00002H

#Define MB_OK                       000000000H
#Define MB_OKCANCEL                 000000001H
#Define MB_ABORTRETRYIGNORE         000000002H
#Define MB_YESNOCANCEL              000000003H
#Define MB_YESNO                    000000004H
#Define MB_RETRYCANCEL              000000005H

#Define MB_ICONHAND                 000000010H
#Define MB_ICONQUESTION             000000020H
#Define MB_ICONEXCLAMATION          000000030H
#Define MB_ICONASTERISK             000000040H

#Define MB_USERICON                 000000080H
#define MB_ICONWARNING              MB_ICONEXCLAMATION
#define MB_ICONERROR                MB_ICONHAND

#Define MB_ICONINFORMATION          MB_ICONASTERISK
#define MB_ICONSTOP                 MB_ICONHAND

#Define MB_DEFBUTTON1               000000000H
#Define MB_DEFBUTTON2               000000100H
#Define MB_DEFBUTTON3               000000200H
#Define MB_DEFBUTTON4               000000300H

#Define MB_APPLMODAL                000000000H
#Define MB_SYSTEMMODAL              000001000H
#Define MB_TASKMODAL                000002000H
#Define MB_HELP                     000004000H

#Define MB_NOFOCUS                  000008000H
#Define MB_SETFOREGROUND            000010000H
#Define MB_DEFAULT_DESKTOP_ONLY     000020000H

#Define MB_TOPMOST                  000040000H
#Define MB_RIGHT                    000080000H
#Define MB_RTLREADING               000100000H

#Define MB_SERVICE_NOTIFICATION     000200000H

#Define MB_TYPEMASK                 00000000FH
#Define MB_ICONMASK                 0000000F0H
#Define MB_DEFMASK                  000000F00H
#Define MB_MODEMASK                 000003000H
#Define MB_MISCMASK                 00000C000H

#Define CWP_ALL             		00000H
#Define CWP_SKIPINVISIBLE   		00001H
#Define CWP_SKIPDISABLED    		00002H
#Define CWP_SKIPTRANSPARENT 		00004H

#Define CTLCOLOR_MSGBOX         	0
#Define CTLCOLOR_EDIT           	1
#Define CTLCOLOR_LISTBOX        	2
#Define CTLCOLOR_BTN            	3
#Define CTLCOLOR_DLG            	4
#Define CTLCOLOR_SCROLLBAR      	5
#Define CTLCOLOR_STATIC         	6
#Define CTLCOLOR_MAX            	7

#Define COLOR_SCROLLBAR         	0
#Define COLOR_BACKGROUND        	1
#Define COLOR_ACTIVECAPTION     	2
#Define COLOR_INACTIVECAPTION   	3
#Define COLOR_MENU              	4
#Define COLOR_WINDOW            	5
#Define COLOR_WINDOWFRAME       	6
#Define COLOR_MENUTEXT          	7
#Define COLOR_WINDOWTEXT        	8
#Define COLOR_CAPTIONTEXT       	9
#Define COLOR_ACTIVEBORDER      	10
#Define COLOR_INACTIVEBORDER    	11
#Define COLOR_APPWORKSPACE      	12
#Define COLOR_HIGHLIGHT         	13
#Define COLOR_HIGHLIGHTTEXT     	14
#Define COLOR_BTNFACE           	15
#Define COLOR_BTNSHADOW         	16
#Define COLOR_GRAYTEXT          	17
#Define COLOR_BTNTEXT           	18
#Define COLOR_INACTIVECAPTIONTEXT 	19
#Define COLOR_BTNHIGHLIGHT      	20

#Define COLOR_3DDKSHADOW        	21
#Define COLOR_3DLIGHT           	22
#Define COLOR_INFOTEXT          	23
#Define COLOR_INFOBK            	24

#Define COLOR_HOTLIGHT					26
#Define COLOR_GRADIENTACTIVECAPTION		27
#Define COLOR_GRADIENTINACTIVECAPTION	28

#Define COLOR_DESKTOP           	COLOR_BACKGROUND
#Define COLOR_3DFACE            	COLOR_BTNFACE
#Define COLOR_3DSHADOW          	COLOR_BTNSHADOW
#Define COLOR_3DHIGHLIGHT       	COLOR_BTNHIGHLIGHT
#Define COLOR_3DHILIGHT         	COLOR_BTNHIGHLIGHT
#Define COLOR_BTNHILIGHT        	COLOR_BTNHIGHLIGHT

#Define GW_HWNDLAST         		1
#Define GW_HWNDNEXT         		2
#Define GW_HWNDPREV         		3
#Define GW_OWNER            		4
#Define GW_CHILD            		5

#IF (WINVER>0400H)
	#Define GW_ENABLEDPOPUP     	6
	#Define GW_MAX              	6
#ELSE
	#Define GW_MAX              	6
#ENDIF

#Define MF_INSERT           		000000000H
#Define MF_CHANGE           		000000080H
#Define MF_APPEND           		000000100H
#Define MF_DELETE           		000000200H
#Define MF_REMOVE           		000001000H

#Define MF_BYCOMMAND        		000000000H
#Define MF_BYPOSITION       		000000400H

#Define MF_SEPARATOR        		000000800H

#Define MF_ENABLED          		000000000H
#Define MF_GRAYED           		000000001H
#Define MF_DISABLED         		000000002H

#Define MF_UNCHECKED        		000000000H
#Define MF_CHECKED          		000000008H
#Define MF_USECHECKBITMAPS  		000000200H

#Define MF_STRING           		000000000H
#Define MF_BITMAP           		000000004H
#Define MF_OWNERDRAW        		000000100H

#Define MF_POPUP            		000000010H
#Define MF_MENUBARBREAK     		000000020H
#Define MF_MENUBREAK        		000000040H

#Define MF_UNHILITE         		000000000H
#Define MF_HILITE           		000000080H

#Define MF_DEFAULT          		000001000H
#Define MF_SYSMENU          		000002000H
#Define MF_HELP             		000004000H
#Define MF_RIGHTJUSTIFY     		000004000H

#Define MF_MOUSESELECT      		000008000H
#Define MF_END              		000000080H

#Define MFT_STRING          		MF_STRING
#Define MFT_BITMAP          		MF_BITMAP
#Define MFT_MENUBARBREAK    		MF_MENUBARBREAK
#Define MFT_MENUBREAK       		MF_MENUBREAK
#Define MFT_OWNERDRAW       		MF_OWNERDRAW
#Define MFT_RADIOCHECK      		000000200H
#Define MFT_SEPARATOR       		MF_SEPARATOR
#Define MFT_RIGHTORDER      		000002000H
#Define MFT_RIGHTJUSTIFY    		MF_RIGHTJUSTIFY

#Define MFS_GRAYED          		000000003H
#Define MFS_DISABLED        		MFS_GRAYED
#Define MFS_CHECKED         		MF_CHECKED
#Define MFS_HILITE          		MF_HILITE
#Define MFS_ENABLED         		MF_ENABLED
#Define MFS_UNCHECKED       		MF_UNCHECKED
#Define MFS_UNHILITE        		MF_UNHILITE
#Define MFS_DEFAULT         		MF_DEFAULT
#Define MFS_MASK            		00000108BH
#Define MFS_HOTTRACKDRAWN   		010000000H
#Define MFS_CACHEDBMP       		020000000H
#Define MFS_BOTTOMGAPDROP   		040000000H
#Define MFS_TOPGAPDROP      		080000000H
#Define MFS_GAPDROP         		0C0000000H

#Define MF_END             			000000080H

#Define SC_SIZE         			0F000H
#Define SC_MOVE         			0F010H
#Define SC_MINIMIZE     			0F020H
#Define SC_MAXIMIZE     			0F030H
#Define SC_NEXTWINDOW   			0F040H
#Define SC_PREVWINDOW   			0F050H
#Define SC_CLOSE        			0F060H
#Define SC_VSCROLL      			0F070H
#Define SC_HSCROLL      			0F080H
#Define SC_MOUSEMENU    			0F090H
#Define SC_KEYMENU      			0F100H
#Define SC_ARRANGE      			0F110H
#Define SC_RESTORE      			0F120H
#Define SC_TASKLIST     			0F130H
#Define SC_SCREENSAVE   			0F140H
#Define SC_HOTKEY       			0F150H
#Define SC_DEFAULT      			0F160H
#Define SC_MONITORPOWER 			0F170H
#Define SC_CONTEXTHELP  			0F180H
#Define SC_SEPARATOR    			0F00FH

#Define SC_ICON         			SC_MINIMIZE
#Define SC_ZOOM         			SC_MAXIMIZE

#Define IDC_ARROW           		32512
#Define IDC_IBEAM           		32513
#Define IDC_WAIT            		32514
#Define IDC_CROSS           		32515
#Define IDC_UPARROW         		32516
#Define IDC_SIZE            		32640
#Define IDC_ICON            		32641
#Define IDC_SIZENWSE        		32642
#Define IDC_SIZENESW        		32643
#Define IDC_SIZEWE          		32644
#Define IDC_SIZENS          		32645
#Define IDC_SIZEALL         		32646
#Define IDC_NO              		32648
#Define IDC_HAND            		32649
#Define IDC_APPSTARTING     		32650
#Define IDC_HELP            		32651

#Define IMAGE_BITMAP        		0
#Define IMAGE_ICON          		1
#Define IMAGE_CURSOR        		2
#Define IMAGE_ENHMETAFILE   		3

#Define LR_DEFAULTCOLOR     		00000H
#Define LR_MONOCHROME       		00001H
#Define LR_COLOR            		00002H
#Define LR_COPYRETURNORG    		00004H
#Define LR_COPYDELETEORG    		00008H
#Define LR_LOADFROMFILE     		00010H
#Define LR_LOADTRANSPARENT  		00020H
#Define LR_DEFAULTSIZE      		00040H
#Define LR_VGACOLOR         		00080H
#Define LR_LOADMAP3DCOLORS  		01000H
#Define LR_CREATEDIBSECTION 		02000H
#Define LR_COPYFROMRESOURCE 		04000H
#Define LR_SHARED           		08000H

#Define DI_MASK         			00001H
#Define DI_IMAGE        			00002H
#Define DI_NORMAL       			00003H
#Define DI_COMPAT       			00004H
#Define DI_DEFAULTSIZE  			00008H

#Define RES_ICON    				1
#Define RES_CURSOR  				2

#Define OBM_CLOSE           		32754
#Define OBM_UPARROW         		32753
#Define OBM_DNARROW         		32752
#Define OBM_RGARROW         		32751
#Define OBM_LFARROW         		32750
#Define OBM_REDUCE          		32749
#Define OBM_ZOOM            		32748
#Define OBM_RESTORE         		32747
#Define OBM_REDUCED         		32746
#Define OBM_ZOOMD           		32745
#Define OBM_RESTORED        		32744
#Define OBM_UPARROWD        		32743
#Define OBM_DNARROWD        		32742
#Define OBM_RGARROWD        		32741
#Define OBM_LFARROWD        		32740
#Define OBM_MNARROW         		32739
#Define OBM_COMBO           		32738
#Define OBM_UPARROWI        		32737
#Define OBM_DNARROWI        		32736
#Define OBM_RGARROWI        		32735
#Define OBM_LFARROWI        		32734

#Define OBM_OLD_CLOSE       		32767
#Define OBM_SIZE            		32766
#Define OBM_OLD_UPARROW     		32765
#Define OBM_OLD_DNARROW     		32764
#Define OBM_OLD_RGARROW     		32763
#Define OBM_OLD_LFARROW     		32762
#Define OBM_BTSIZE          		32761
#Define OBM_CHECK           		32760
#Define OBM_CHECKBOXES      		32759
#Define OBM_BTNCORNERS      		32758
#Define OBM_OLD_REDUCE      		32757
#Define OBM_OLD_ZOOM        		32756
#Define OBM_OLD_RESTORE     		32755

#Define OCR_NORMAL          		32512
#Define OCR_IBEAM           		32513
#Define OCR_WAIT            		32514
#Define OCR_CROSS           		32515
#Define OCR_UP              		32516
#Define OCR_SIZE            		32640
#Define OCR_ICON            		32641
#Define OCR_SIZENWSE        		32642
#Define OCR_SIZENESW        		32643
#Define OCR_SIZEWE          		32644
#Define OCR_SIZENS          		32645
#Define OCR_SIZEALL         		32646
#Define OCR_ICOCUR          		32647
#Define OCR_NO              		32648

#Define OCR_HAND            		32649
#Define OCR_APPSTARTING     		32650

#Define OIC_SAMPLE          		32512
#Define OIC_HAND            		32513
#Define OIC_QUES            		32514
#Define OIC_BANG            		32515
#Define OIC_NOTE            		32516
#Define OIC_WINLOGO         		32517
#Define OIC_WARNING         		OIC_BANG
#Define OIC_ERROR           		OIC_HAND
#Define OIC_INFORMATION     		OIC_NOTE

#Define ORD_LANGDRIVER    			1

#Define IDI_APPLICATION     		32512
#Define IDI_HAND            		32513
#Define IDI_QUESTION        		32514
#Define IDI_EXCLAMATION     		32515
#Define IDI_ASTERISK        		32516
#Define IDI_WINLOGO         		32517

#Define IDI_WARNING     			IDI_EXCLAMATION
#Define IDI_ERROR       			IDI_HAND
#Define IDI_INFORMATION 			IDI_ASTERISK

#Define IDOK                		1
#Define IDCANCEL            		2
#Define IDABORT             		3
#Define IDRETRY             		4
#Define IDIGNORE            		5
#Define IDYES               		6
#Define IDNO                		7
#Define IDCLOSE         			8
#Define IDHELP          			9

#Define ES_LEFT             		00000H
#Define ES_CENTER           		00001H
#Define ES_RIGHT            		00002H
#Define ES_MULTILINE        		00004H
#Define ES_UPPERCASE        		00008H
#Define ES_LOWERCASE        		00010H
#Define ES_PASSWORD         		00020H
#Define ES_AUTOVSCROLL      		00040H
#Define ES_AUTOHSCROLL      		00080H
#Define ES_NOHIDESEL        		00100H
#Define ES_OEMCONVERT       		00400H
#Define ES_READONLY         		00800H
#Define ES_WANTRETURN       		01000H
#Define ES_NUMBER           		02000H

#Define EN_SETFOCUS         		00100H
#Define EN_KILLFOCUS        		00200H
#Define EN_CHANGE           		00300H
#Define EN_UPDATE           		00400H
#Define EN_ERRSPACE         		00500H
#Define EN_MAXTEXT          		00501H
#Define EN_HSCROLL          		00601H
#Define EN_VSCROLL          		00602H

#Define EC_LEFTMARGIN       		00001H
#Define EC_RIGHTMARGIN      		00002H
#Define EC_USEFONTINFO      		0FFFFH

#Define EMSIS_COMPOSITIONSTRING     00001H

#Define EIMES_GETCOMPSTRATONCE          00001H
#Define EIMES_CANCELCOMPSTRINFOCUS      00002H
#Define EIMES_COMPLETECOMPSTRKILLFOCUS	00004H

#Define EM_GETSEL               	000B0H
#Define EM_SETSEL               	000B1H
#Define EM_GETRECT              	000B2H
#Define EM_SETRECT              	000B3H
#Define EM_SETRECTNP            	000B4H
#Define EM_SCROLL               	000B5H
#Define EM_LINESCROLL           	000B6H
#Define EM_SCROLLCARET          	000B7H
#Define EM_GETMODIFY            	000B8H
#Define EM_SETMODIFY            	000B9H
#Define EM_GETLINECOUNT         	000BAH
#Define EM_LINEINDEX            	000BBH
#Define EM_SETHANDLE            	000BCH
#Define EM_GETHANDLE            	000BDH
#Define EM_GETTHUMB             	000BEH
#Define EM_LINELENGTH           	000C1H
#Define EM_REPLACESEL           	000C2H
#Define EM_GETLINE              	000C4H
#Define EM_LIMITTEXT            	000C5H
#Define EM_CANUNDO              	000C6H
#Define EM_UNDO                 	000C7H
#Define EM_FMTLINES             	000C8H
#Define EM_LINEFROMCHAR         	000C9H
#Define EM_SETTABSTOPS          	000CBH
#Define EM_SETPASSWORDCHAR      	000CCH
#Define EM_EMPTYUNDOBUFFER      	000CDH
#Define EM_GETFIRSTVISIBLELINE  	000CEH
#Define EM_SETREADONLY          	000CFH
#Define EM_SETWORDBREAKPROC     	000D0H
#Define EM_GETWORDBREAKPROC     	000D1H
#Define EM_GETPASSWORDCHAR      	000D2H

#Define EM_SETMARGINS           	000D3H
#Define EM_GETMARGINS           	000D4H
#Define EM_SETLIMITTEXT         	EM_LIMITTEXT
#Define EM_GETLIMITTEXT         	000D5H
#Define EM_POSFROMCHAR          	000D6H
#Define EM_CHARFROMPOS          	000D7H

#Define EM_SETIMESTATUS         	000D8H
#Define EM_GETIMESTATUS         	000D9H

#Define WB_LEFT            			0
#Define WB_RIGHT           			1
#Define WB_ISDELIMITER     			2

#Define BS_PUSHBUTTON       		000000000H
#Define BS_DEFPUSHBUTTON    		000000001H
#Define BS_CHECKBOX         		000000002H
#Define BS_AUTOCHECKBOX     		000000003H
#Define BS_RADIOBUTTON      		000000004H
#Define BS_3STATE           		000000005H
#Define BS_AUTO3STATE       		000000006H
#Define BS_GROUPBOX         		000000007H
#Define BS_USERBUTTON       		000000008H
#Define BS_AUTORADIOBUTTON  		000000009H
#Define BS_OWNERDRAW        		00000000BH
#Define BS_LEFTTEXT         		000000020H
#Define BS_TEXT             		000000000H
#Define BS_ICON             		000000040H
#Define BS_BITMAP           		000000080H
#Define BS_LEFT             		000000100H
#Define BS_RIGHT            		000000200H
#Define BS_CENTER           		000000300H
#Define BS_TOP              		000000400H
#Define BS_BOTTOM           		000000800H
#Define BS_VCENTER          		000000C00H
#Define BS_PUSHLIKE         		000001000H
#Define BS_MULTILINE        		000002000H
#Define BS_NOTIFY           		000004000H
#Define BS_FLAT             		000008000H
#Define BS_RIGHTBUTTON      		BS_LEFTTEXT

#Define BN_CLICKED          		0
#Define BN_PAINT            		1
#Define BN_HILITE           		2
#Define BN_UNHILITE         		3
#Define BN_DISABLE          		4
#Define BN_DOUBLECLICKED    		5
#Define BN_PUSHED           		BN_HILITE
#Define BN_UNPUSHED         		BN_UNHILITE
#Define BN_DBLCLK           		BN_DOUBLECLICKED
#Define BN_SETFOCUS         		6
#Define BN_KILLFOCUS        		7

#Define BM_GETCHECK        			000F0H
#Define BM_SETCHECK        			000F1H
#Define BM_GETSTATE        			000F2H
#Define BM_SETSTATE        			000F3H
#Define BM_SETSTYLE        			000F4H
#Define BM_CLICK           			000F5H
#Define BM_GETIMAGE        			000F6H
#Define BM_SETIMAGE        			000F7H

#Define BST_UNCHECKED      			00000H
#Define BST_CHECKED        			00001H
#Define BST_INDETERMINATE  			00002H
#Define BST_PUSHED         			00004H
#Define BST_FOCUS          			00008H

#Define SS_LEFT             		000000000H
#Define SS_CENTER           		000000001H
#Define SS_RIGHT            		000000002H
#Define SS_ICON             		000000003H
#Define SS_BLACKRECT        		000000004H
#Define SS_GRAYRECT         		000000005H
#Define SS_WHITERECT        		000000006H
#Define SS_BLACKFRAME       		000000007H
#Define SS_GRAYFRAME        		000000008H
#Define SS_WHITEFRAME       		000000009H
#Define SS_USERITEM         		00000000AH
#Define SS_SIMPLE           		00000000BH
#Define SS_LEFTNOWORDWRAP   		00000000CH
#Define SS_OWNERDRAW        		00000000DH
#Define SS_BITMAP           		00000000EH
#Define SS_ENHMETAFILE      		00000000FH
#Define SS_ETCHEDHORZ       		000000010H
#Define SS_ETCHEDVERT       		000000011H
#Define SS_ETCHEDFRAME      		000000012H
#Define SS_TYPEMASK         		00000001FH
#Define SS_NOPREFIX         		000000080H
#Define SS_NOTIFY           		000000100H
#Define SS_CENTERIMAGE      		000000200H
#Define SS_RIGHTJUST        		000000400H
#Define SS_REALSIZEIMAGE    		000000800H
#Define SS_SUNKEN           		000001000H
#Define SS_ENDELLIPSIS      		000004000H
#Define SS_PATHELLIPSIS     		000008000H
#Define SS_WORDELLIPSIS     		00000C000H
#Define SS_ELLIPSISMASK     		00000C000H

#Define STM_SETICON         		00170H
#Define STM_GETICON         		00171H
#Define STM_SETIMAGE        		00172H
#Define STM_GETIMAGE        		00173H
#Define STN_CLICKED         		0
#Define STN_DBLCLK          		1
#Define STN_ENABLE          		2
#Define STN_DISABLE         		3
#Define STM_MSGMAX          		00174H

#Define WC_DIALOG       			08002H

#Define DWL_MSGRESULT   			0
#Define DWL_DLGPROC     			4
#Define DWL_USER        			8

#Define DDL_READWRITE       		00000H
#Define DDL_READONLY        		00001H
#Define DDL_HIDDEN          		00002H
#Define DDL_SYSTEM          		00004H
#Define DDL_DIRECTORY       		00010H
#Define DDL_ARCHIVE         		00020H

#Define DDL_POSTMSGS        		02000H
#Define DDL_DRIVES          		04000H
#Define DDL_EXCLUSIVE       		08000H

#Define DS_ABSALIGN         		001H
#Define DS_SYSMODAL         		002H
#Define DS_LOCALEDIT        		020H
#Define DS_SETFONT          		040H
#Define DS_MODALFRAME       		080H
#Define DS_NOIDLEMSG        		0100H
#Define DS_SETFOREGROUND    		0200H

#Define DS_3DLOOK           		00004H
#Define DS_FIXEDSYS         		00008H
#Define DS_NOFAILCREATE     		00010H
#Define DS_CONTROL          		00400H
#Define DS_CENTER           		00800H
#Define DS_CENTERMOUSE      		01000H
#Define DS_CONTEXTHELP      		02000H

#Define DM_GETDEFID         		(WM_USER + 0)
#Define DM_SETDEFID         		(WM_USER + 1)
#Define DM_REPOSITION       		(WM_USER + 2)

#Define DC_HASDEFID         		0534BH

#Define DLGC_WANTARROWS     		00001H
#Define DLGC_WANTTAB        		00002H
#Define DLGC_WANTALLKEYS    		00004H
#Define DLGC_WANTMESSAGE    		00004H
#Define DLGC_HASSETSEL      		00008H
#Define DLGC_DEFPUSHBUTTON  		00010H
#Define DLGC_UNDEFPUSHBUTTON 		00020H
#Define DLGC_RADIOBUTTON    		00040H
#Define DLGC_WANTCHARS      		00080H
#Define DLGC_STATIC         		00100H
#Define DLGC_BUTTON         		02000H

#Define LB_CTLCODE          		0

#Define LB_OKAY             		0
#Define LB_ERR              		(-1)
#Define LB_ERRSPACE         		(-2)

#Define LBN_ERRSPACE        		(-2)
#Define LBN_SELCHANGE       		1
#Define LBN_DBLCLK          		2
#Define LBN_SELCANCEL       		3
#Define LBN_SETFOCUS        		4
#Define LBN_KILLFOCUS       		5

#Define LB_ADDSTRING            	00180H
#Define LB_INSERTSTRING         	00181H
#Define LB_DELETESTRING         	00182H
#Define LB_SELITEMRANGEEX       	00183H
#Define LB_RESETCONTENT         	00184H
#Define LB_SETSEL               	00185H
#Define LB_SETCURSEL            	00186H
#Define LB_GETSEL               	00187H
#Define LB_GETCURSEL            	00188H
#Define LB_GETTEXT              	00189H
#Define LB_GETTEXTLEN           	0018AH
#Define LB_GETCOUNT             	0018BH
#Define LB_SELECTSTRING         	0018CH
#Define LB_DIR                  	0018DH
#Define LB_GETTOPINDEX          	0018EH
#Define LB_FINDSTRING           	0018FH
#Define LB_GETSELCOUNT          	00190H
#Define LB_GETSELITEMS          	00191H
#Define LB_SETTABSTOPS          	00192H
#Define LB_GETHORIZONTALEXTENT  	00193H
#Define LB_SETHORIZONTALEXTENT  	00194H
#Define LB_SETCOLUMNWIDTH       	00195H
#Define LB_ADDFILE              	00196H
#Define LB_SETTOPINDEX          	00197H
#Define LB_GETITEMRECT          	00198H
#Define LB_GETITEMDATA          	00199H
#Define LB_SETITEMDATA          	0019AH
#Define LB_SELITEMRANGE         	0019BH
#Define LB_SETANCHORINDEX       	0019CH
#Define LB_GETANCHORINDEX       	0019DH
#Define LB_SETCARETINDEX        	0019EH
#Define LB_GETCARETINDEX        	0019FH
#Define LB_SETITEMHEIGHT        	001A0H
#Define LB_GETITEMHEIGHT        	001A1H
#Define LB_FINDSTRINGEXACT      	001A2H
#Define LB_SETLOCALE            	001A5H
#Define LB_GETLOCALE            	001A6H
#Define LB_SETCOUNT             	001A7H
#Define LB_INITSTORAGE          	001A8H
#Define LB_ITEMFROMPOINT        	001A9H
#Define LB_MSGMAX               	001B0H

#Define LBS_NOTIFY            		00001H
#Define LBS_SORT              		00002H
#Define LBS_NOREDRAW          		00004H
#Define LBS_MULTIPLESEL       		00008H
#Define LBS_OWNERDRAWFIXED    		00010H
#Define LBS_OWNERDRAWVARIABLE 		00020H
#Define LBS_HASSTRINGS        		00040H
#Define LBS_USETABSTOPS       		00080H
#Define LBS_NOINTEGRALHEIGHT  		00100H
#Define LBS_MULTICOLUMN       		00200H
#Define LBS_WANTKEYBOARDINPUT 		00400H
#Define LBS_EXTENDEDSEL       		00800H
#Define LBS_DISABLENOSCROLL   		01000H
#Define LBS_NODATA            		02000H
#Define LBS_NOSEL             		04000H

#Define LBS_STANDARD          		(LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)

#Define CB_OKAY             		0
#Define CB_ERR              		(-1)
#Define CB_ERRSPACE         		(-2)

#Define CBN_ERRSPACE        		(-1)
#Define CBN_SELCHANGE       		1
#Define CBN_DBLCLK          		2
#Define CBN_SETFOCUS        		3
#Define CBN_KILLFOCUS       		4
#Define CBN_EDITCHANGE      		5
#Define CBN_EDITUPDATE      		6
#Define CBN_DROPDOWN        		7
#Define CBN_CLOSEUP         		8
#Define CBN_SELENDOK        		9
#Define CBN_SELENDCANCEL    		10

#Define CBS_SIMPLE            		00001H
#Define CBS_DROPDOWN          		00002H
#Define CBS_DROPDOWNLIST      		00003H
#Define CBS_OWNERDRAWFIXED    		00010H
#Define CBS_OWNERDRAWVARIABLE 		00020H
#Define CBS_AUTOHSCROLL       		00040H
#Define CBS_OEMCONVERT        		00080H
#Define CBS_SORT              		00100H
#Define CBS_HASSTRINGS        		00200H
#Define CBS_NOINTEGRALHEIGHT  		00400H
#Define CBS_DISABLENOSCROLL   		00800H
#Define CBS_UPPERCASE           	02000H
#Define CBS_LOWERCASE           	04000H

#Define CB_GETEDITSEL               00140H
#Define CB_LIMITTEXT                00141H
#Define CB_SETEDITSEL               00142H
#Define CB_ADDSTRING                00143H
#Define CB_DELETESTRING             00144H
#Define CB_DIR                      00145H
#Define CB_GETCOUNT                 00146H
#Define CB_GETCURSEL                00147H
#Define CB_GETLBTEXT                00148H
#Define CB_GETLBTEXTLEN             00149H
#Define CB_INSERTSTRING             0014AH
#Define CB_RESETCONTENT             0014BH
#Define CB_FINDSTRING               0014CH
#Define CB_SELECTSTRING             0014DH
#Define CB_SETCURSEL                0014EH
#Define CB_SHOWDROPDOWN             0014FH
#Define CB_GETITEMDATA              00150H
#Define CB_SETITEMDATA              00151H
#Define CB_GETDROPPEDCONTROLRECT    00152H
#Define CB_SETITEMHEIGHT            00153H
#Define CB_GETITEMHEIGHT            00154H
#Define CB_SETEXTENDEDUI            00155H
#Define CB_GETEXTENDEDUI            00156H
#Define CB_GETDROPPEDSTATE          00157H
#Define CB_FINDSTRINGEXACT          00158H
#Define CB_SETLOCALE                00159H
#Define CB_GETLOCALE                0015AH
#Define CB_GETTOPINDEX              0015BH
#Define CB_SETTOPINDEX              0015CH
#Define CB_GETHORIZONTALEXTENT      0015DH
#Define CB_SETHORIZONTALEXTENT      0015EH
#Define CB_GETDROPPEDWIDTH          0015FH
#Define CB_SETDROPPEDWIDTH          00160H
#Define CB_INITSTORAGE              00161H
#Define CB_MSGMAX                   00162H

#Define SBS_HORZ                    00000H
#Define SBS_VERT                    00001H
#Define SBS_TOPALIGN                00002H
#Define SBS_LEFTALIGN               00002H
#Define SBS_BOTTOMALIGN             00004H
#Define SBS_RIGHTALIGN              00004H
#Define SBS_SIZEBOXTOPLEFTALIGN     00002H
#Define SBS_SIZEBOXBOTTOMRIGHTALIGN 00004H
#Define SBS_SIZEBOX                 00008H
#Define SBS_SIZEGRIP                00010H

#Define SBM_SETPOS                  000E0H
#Define SBM_GETPOS                  000E1H
#Define SBM_SETRANGE                000E2H
#Define SBM_SETRANGEREDRAW          000E6H
#Define SBM_GETRANGE                000E3H
#Define SBM_ENABLE_ARROWS           000E4H
#Define SBM_SETSCROLLINFO           000E9H
#Define SBM_GETSCROLLINFO           000EAH

#Define SIF_RANGE           		00001H
#Define SIF_PAGE            		00002H
#Define SIF_POS             		00004H
#Define SIF_DISABLENOSCROLL 		00008H
#Define SIF_TRACKPOS        		00010H
#Define SIF_ALL             		(SIF_RANGE | SIF_PAGE | SIF_POS | SIF_TRACKPOS)

#Define MDIS_ALLCHILDSTYLES    		00001H

#Define MDITILE_VERTICAL       		00000H
#Define MDITILE_HORIZONTAL     		00001H
#Define MDITILE_SKIPDISABLED   		00002H

#Define HELP_CONTEXT      			00001H
#Define HELP_QUIT         			00002H
#Define HELP_INDEX        			00003H
#Define HELP_CONTENTS     			00003H
#Define HELP_HELPONHELP   			00004H
#Define HELP_SETINDEX     			00005H
#Define HELP_SETCONTENTS  			00005H
#Define HELP_CONTEXTPOPUP 			00008H
#Define HELP_FORCEFILE    			00009H
#Define HELP_KEY          			00101H
#Define HELP_COMMAND      			00102H
#Define HELP_PARTIALKEY   			00105H
#Define HELP_MULTIKEY     			00201H
#Define HELP_SETWINPOS    			00203H
#Define HELP_CONTEXTMENU  			0000AH
#Define HELP_FINDER       			0000BH
#Define HELP_WM_HELP      			0000CH
#Define HELP_SETPOPUP_POS 			0000DH

#Define HELP_TCARD              	08000H
#Define HELP_TCARD_DATA         	00010H
#Define HELP_TCARD_OTHER_CALLER 	00011H

#Define IDH_NO_HELP                 28440
#Define IDH_MISSING_CONTEXT         28441
#Define IDH_GENERIC_HELP_BUTTON     28442
#Define IDH_OK                      28443
#Define IDH_CANCEL                  28444
#Define IDH_HELP                    28445

#Define GR_GDIOBJECTS     			0
#Define GR_USEROBJECTS    			1

#Define SPI_GETBEEP                 1
#define SPI_SETBEEP                 2
#define SPI_GETMOUSE                3
#define SPI_SETMOUSE                4
#define SPI_GETBORDER               5
#define SPI_SETBORDER               6
#Define SPI_GETKEYBOARDSPEED       	10
#Define SPI_SETKEYBOARDSPEED       	11
#Define SPI_LANGDRIVER             	12
#Define SPI_ICONHORIZONTALSPACING  	13
#Define SPI_GETSCREENSAVETIMEOUT   	14
#Define SPI_SETSCREENSAVETIMEOUT   	15
#Define SPI_GETSCREENSAVEACTIVE    	16
#Define SPI_SETSCREENSAVEACTIVE    	17
#Define SPI_GETGRIDGRANULARITY     	18
#Define SPI_SETGRIDGRANULARITY     	19
#Define SPI_SETDESKWALLPAPER       	20
#Define SPI_SETDESKPATTERN         	21
#Define SPI_GETKEYBOARDDELAY       	22
#Define SPI_SETKEYBOARDDELAY       	23
#Define SPI_ICONVERTICALSPACING    	24
#Define SPI_GETICONTITLEWRAP       	25
#Define SPI_SETICONTITLEWRAP       	26
#Define SPI_GETMENUDROPALIGNMENT   	27
#Define SPI_SETMENUDROPALIGNMENT   	28
#Define SPI_SETDOUBLECLKWIDTH      	29
#Define SPI_SETDOUBLECLKHEIGHT     	30
#Define SPI_GETICONTITLELOGFONT    	31
#Define SPI_SETDOUBLECLICKTIME     	32
#Define SPI_SETMOUSEBUTTONSWAP     	33
#Define SPI_SETICONTITLELOGFONT    	34
#Define SPI_GETFASTTASKSWITCH      	35
#Define SPI_SETFASTTASKSWITCH      	36
#Define SPI_SETDRAGFULLWINDOWS     	37
#Define SPI_GETDRAGFULLWINDOWS     	38
#Define SPI_GETNONCLIENTMETRICS    	41
#Define SPI_SETNONCLIENTMETRICS    	42
#Define SPI_GETMINIMIZEDMETRICS    	43
#Define SPI_SETMINIMIZEDMETRICS    	44
#Define SPI_GETICONMETRICS         	45
#Define SPI_SETICONMETRICS         	46
#Define SPI_SETWORKAREA            	47
#Define SPI_GETWORKAREA            	48
#Define SPI_SETPENWINDOWS          	49

#Define SPI_GETHIGHCONTRAST        	66
#Define SPI_SETHIGHCONTRAST        	67
#Define SPI_GETKEYBOARDPREF        	68
#Define SPI_SETKEYBOARDPREF        	69
#Define SPI_GETSCREENREADER        	70
#Define SPI_SETSCREENREADER        	71
#Define SPI_GETANIMATION           	72
#Define SPI_SETANIMATION           	73
#Define SPI_GETFONTSMOOTHING       	74
#Define SPI_SETFONTSMOOTHING       	75
#Define SPI_SETDRAGWIDTH           	76
#Define SPI_SETDRAGHEIGHT          	77
#Define SPI_SETHANDHELD            	78
#Define SPI_GETLOWPOWERTIMEOUT     	79
#Define SPI_GETPOWEROFFTIMEOUT     	80
#Define SPI_SETLOWPOWERTIMEOUT     	81
#Define SPI_SETPOWEROFFTIMEOUT     	82
#Define SPI_GETLOWPOWERACTIVE      	83
#Define SPI_GETPOWEROFFACTIVE      	84
#Define SPI_SETLOWPOWERACTIVE      	85
#Define SPI_SETPOWEROFFACTIVE      	86
#Define SPI_SETCURSORS             	87
#Define SPI_SETICONS               	88
#Define SPI_GETDEFAULTINPUTLANG    	89
#Define SPI_SETDEFAULTINPUTLANG    	90
#Define SPI_SETLANGTOGGLE          	91
#Define SPI_GETWINDOWSEXTENSION    	92
#Define SPI_SETMOUSETRAILS         	93
#Define SPI_GETMOUSETRAILS         	94
#Define SPI_SETSCREENSAVERRUNNING  	97
#Define SPI_SCREENSAVERRUNNING     	SPI_SETSCREENSAVERRUNNING
#Define SPI_GETFILTERKEYS          	50
#Define SPI_SETFILTERKEYS          	51
#Define SPI_GETTOGGLEKEYS          	52
#Define SPI_SETTOGGLEKEYS          	53
#Define SPI_GETMOUSEKEYS           	54
#Define SPI_SETMOUSEKEYS           	55
#Define SPI_GETSHOWSOUNDS          	56
#Define SPI_SETSHOWSOUNDS          	57
#Define SPI_GETSTICKYKEYS          	58
#Define SPI_SETSTICKYKEYS          	59
#Define SPI_GETACCESSTIMEOUT       	60
#Define SPI_SETACCESSTIMEOUT       	61
#Define SPI_GETSERIALKEYS          	62
#Define SPI_SETSERIALKEYS          	63
#Define SPI_GETSOUNDSENTRY         	64
#Define SPI_SETSOUNDSENTRY         	65

#Define SPI_GETMOUSEHOVERWIDTH     	98
#Define SPI_SETMOUSEHOVERWIDTH     	99
#Define SPI_GETMOUSEHOVERHEIGHT   	100
#Define SPI_SETMOUSEHOVERHEIGHT   	101
#Define SPI_GETMOUSEHOVERTIME     	102
#Define SPI_SETMOUSEHOVERTIME     	103
#Define SPI_GETWHEELSCROLLLINES   	104
#Define SPI_SETWHEELSCROLLLINES   	105

#Define SPI_GETSHOWIMEUI          	110
#Define SPI_SETSHOWIMEUI          	111

#Define SPI_GETMOUSESPEED         	112
#Define SPI_SETMOUSESPEED         	113
#Define SPI_GETSCREENSAVERRUNNING 	114
#Define SPI_GETACTIVEWINDOWTRACKING   	01000H
#Define SPI_SETACTIVEWINDOWTRACKING   	01001H
#Define SPI_GETMENUANIMATION          	01002H
#Define SPI_SETMENUANIMATION          	01003H
#Define SPI_GETCOMBOBOXANIMATION      	01004H
#Define SPI_SETCOMBOBOXANIMATION      	01005H
#Define SPI_GETLISTBOXSMOOTHSCROLLING 	01006H
#Define SPI_SETLISTBOXSMOOTHSCROLLING 	01007H
#Define SPI_GETGRADIENTCAPTIONS         01008H
#Define SPI_SETGRADIENTCAPTIONS         01009H
#Define SPI_GETMENUUNDERLINES           0100AH
#Define SPI_SETMENUUNDERLINES           0100BH
#Define SPI_GETACTIVEWNDTRKZORDER       0100CH
#Define SPI_SETACTIVEWNDTRKZORDER       0100DH
#Define SPI_GETHOTTRACKING              0100EH
#Define SPI_SETHOTTRACKING              0100FH
#Define SPI_GETFOREGROUNDLOCKTIMEOUT    02000H
#Define SPI_SETFOREGROUNDLOCKTIMEOUT    02001H
#Define SPI_GETACTIVEWNDTRKTIMEOUT      02002H
#Define SPI_SETACTIVEWNDTRKTIMEOUT      02003H
#Define SPI_GETFOREGROUNDFLASHCOUNT     02004H
#Define SPI_SETFOREGROUNDFLASHCOUNT		02005H

#Define SPIF_UPDATEINIFILE    		00001H
#Define SPIF_SENDWININICHANGE 		00002H
#Define SPIF_SENDCHANGE       		SPIF_SENDWININICHANGE

#Define METRICS_USEDEFAULT 			(-1)

#Define ARW_BOTTOMLEFT              00000H
#Define ARW_BOTTOMRIGHT             00001H
#Define ARW_TOPLEFT                 00002H
#Define ARW_TOPRIGHT                00003H
#Define ARW_STARTMASK               00003H
#Define ARW_STARTRIGHT              00001H
#Define ARW_STARTTOP                00002H

#Define ARW_LEFT                    00000H
#Define ARW_RIGHT                   00000H
#Define ARW_UP                      00004H
#Define ARW_DOWN                    00004H
#Define ARW_HIDE                    00008H

#Define SERKF_SERIALKEYSON  		000000001H
#Define SERKF_AVAILABLE     		000000002H
#Define SERKF_INDICATOR     		000000004H

#Define HCF_HIGHCONTRASTON  		000000001H
#Define HCF_AVAILABLE       		000000002H
#Define HCF_HOTKEYACTIVE    		000000004H
#Define HCF_CONFIRMHOTKEY   		000000008H
#Define HCF_HOTKEYSOUND     		000000010H
#Define HCF_INDICATOR       		000000020H
#Define HCF_HOTKEYAVAILABLE 		000000040H

#Define CDS_UPDATEREGISTRY  		000000001H
#Define CDS_TEST            		000000002H
#Define CDS_FULLSCREEN      		000000004H
#Define CDS_GLOBAL          		000000008H
#Define CDS_SET_PRIMARY     		000000010H
#Define CDS_RESET           		040000000H
#Define CDS_SETRECT         		020000000H
#Define CDS_NORESET         		010000000H

#Define DISP_CHANGE_SUCCESSFUL      0
#Define DISP_CHANGE_RESTART         1
#Define DISP_CHANGE_FAILED          (-1)
#Define DISP_CHANGE_BADMODE         (-2)
#Define DISP_CHANGE_NOTUPDATED      (-3)
#Define DISP_CHANGE_BADFLAGS        (-4)
#Define DISP_CHANGE_BADPARAM        (-5)
#Define ENUM_CURRENT_SETTINGS       (-1)
#Define ENUM_REGISTRY_SETTINGS      (-2)

#Define FKF_FILTERKEYSON    		000000001H
#Define FKF_AVAILABLE       		000000002H
#Define FKF_HOTKEYACTIVE    		000000004H
#Define FKF_CONFIRMHOTKEY   		000000008H
#Define FKF_HOTKEYSOUND     		000000010H
#Define FKF_INDICATOR       		000000020H
#Define FKF_CLICKON         		000000040H

#Define SKF_STICKYKEYSON    		000000001H
#Define SKF_AVAILABLE       		000000002H
#Define SKF_HOTKEYACTIVE    		000000004H
#Define SKF_CONFIRMHOTKEY   		000000008H
#Define SKF_HOTKEYSOUND     		000000010H
#Define SKF_INDICATOR       		000000020H
#Define SKF_AUDIBLEFEEDBACK 		000000040H
#Define SKF_TRISTATE        		000000080H
#Define SKF_TWOKEYSOFF      		000000100H
#Define SKF_LALTLATCHED       		010000000H
#Define SKF_LCTLLATCHED       		004000000H
#Define SKF_LSHIFTLATCHED     		001000000H
#Define SKF_RALTLATCHED       		020000000H
#Define SKF_RCTLLATCHED       		008000000H
#Define SKF_RSHIFTLATCHED     		002000000H
#Define SKF_LWINLATCHED       		040000000H
#Define SKF_RWINLATCHED       		080000000H
#Define SKF_LALTLOCKED        		000100000H
#Define SKF_LCTLLOCKED        		000040000H
#Define SKF_LSHIFTLOCKED      		000010000H
#Define SKF_RALTLOCKED        		000200000H
#Define SKF_RCTLLOCKED        		000080000H
#Define SKF_RSHIFTLOCKED      		000020000H
#Define SKF_LWINLOCKED        		000400000H
#Define SKF_RWINLOCKED        		000800000H

#Define MKF_MOUSEKEYSON     		000000001H
#Define MKF_AVAILABLE       		000000002H
#Define MKF_HOTKEYACTIVE    		000000004H
#Define MKF_CONFIRMHOTKEY   		000000008H
#Define MKF_HOTKEYSOUND     		000000010H
#Define MKF_INDICATOR       		000000020H
#Define MKF_MODIFIERS       		000000040H
#Define MKF_REPLACENUMBERS  		000000080H
#Define MKF_LEFTBUTTONSEL   		010000000H
#Define MKF_RIGHTBUTTONSEL  		020000000H
#Define MKF_LEFTBUTTONDOWN  		001000000H
#Define MKF_RIGHTBUTTONDOWN 		002000000H
#Define MKF_MOUSEMODE       		080000000H

#Define ATF_TIMEOUTON       		000000001H
#Define ATF_ONOFFFEEDBACK   		000000002H

#Define SSGF_NONE       			0
#Define SSGF_DISPLAY    			3

#Define SSTF_NONE       			0
#Define SSTF_CHARS      			1
#Define SSTF_BORDER     			2
#Define SSTF_DISPLAY    			3

#Define SSWF_NONE     				0
#Define SSWF_TITLE    				1
#Define SSWF_WINDOW   				2
#Define SSWF_DISPLAY  				3
#Define SSWF_CUSTOM   				4

#Define SSF_SOUNDSENTRYON   		000000001H
#Define SSF_AVAILABLE       		000000002H
#Define SSF_INDICATOR       		000000004H

#Define TKF_TOGGLEKEYSON    		000000001H
#Define TKF_AVAILABLE       		000000002H
#Define TKF_HOTKEYACTIVE    		000000004H
#Define TKF_CONFIRMHOTKEY   		000000008H
#Define TKF_HOTKEYSOUND     		000000010H
#Define TKF_INDICATOR       		000000020H

#Define SLE_ERROR       			000000001H
#Define SLE_MINORERROR  			000000002H
#Define SLE_WARNING     			000000003H

#Define MONITOR_DEFAULTTONULL       000000000H
#Define MONITOR_DEFAULTTOPRIMARY    000000001H
#Define MONITOR_DEFAULTTONEAREST    000000002H

#Define MONITORINFOF_PRIMARY        000000001H

#Define CHILDID_SELF        		0
#Define INDEXID_OBJECT      		0
#Define INDEXID_CONTAINER   		0

#Define OBJID_WINDOW        		000000000H
#Define OBJID_SYSMENU       		0FFFFFFFFH
#Define OBJID_TITLEBAR      		0FFFFFFFEH
#Define OBJID_MENU          		0FFFFFFFDH
#Define OBJID_CLIENT        		0FFFFFFFCH
#Define OBJID_VSCROLL       		0FFFFFFFBH
#Define OBJID_HSCROLL       		0FFFFFFFAH
#Define OBJID_SIZEGRIP      		0FFFFFFF9H
#Define OBJID_CARET         		0FFFFFFF8H
#Define OBJID_CURSOR        		0FFFFFFF7H
#Define OBJID_ALERT         		0FFFFFFF6H
#Define OBJID_SOUND         		0FFFFFFF5H

#Define EVENT_MIN           		000000001H
#Define EVENT_MAX           		07FFFFFFFH

#Define EVENT_SYSTEM_SOUND          	00001H
#Define EVENT_SYSTEM_ALERT          	00002H
#Define EVENT_SYSTEM_FOREGROUND     	00003H
#Define EVENT_SYSTEM_MENUSTART      	00004H
#Define EVENT_SYSTEM_MENUEND        	00005H
#Define EVENT_SYSTEM_MENUPOPUPSTART 	00006H
#Define EVENT_SYSTEM_MENUPOPUPEND   	00007H
#Define EVENT_SYSTEM_CAPTURESTART   	00008H
#Define EVENT_SYSTEM_CAPTUREEND     	00009H
#Define EVENT_SYSTEM_MOVESIZESTART      0000AH
#Define EVENT_SYSTEM_MOVESIZEEND        0000BH
#Define EVENT_SYSTEM_CONTEXTHELPSTART   0000CH
#Define EVENT_SYSTEM_CONTEXTHELPEND     0000DH
#Define EVENT_SYSTEM_DRAGDROPSTART      0000EH
#Define EVENT_SYSTEM_DRAGDROPEND        0000FH
#Define EVENT_SYSTEM_DIALOGSTART        00010H
#Define EVENT_SYSTEM_DIALOGEND          00011H
#Define EVENT_SYSTEM_SCROLLINGSTART     00012H
#Define EVENT_SYSTEM_SCROLLINGEND       00013H
#Define EVENT_SYSTEM_SWITCHSTART        00014H
#Define EVENT_SYSTEM_SWITCHEND          00015H
#Define EVENT_SYSTEM_MINIMIZESTART      00016H
#Define EVENT_SYSTEM_MINIMIZEEND        00017H

#Define EVENT_OBJECT_CREATE             08000H
#Define EVENT_OBJECT_DESTROY            08001H
#Define EVENT_OBJECT_SHOW               08002H
#Define EVENT_OBJECT_HIDE               08003H
#Define EVENT_OBJECT_REORDER            08004H
#Define EVENT_OBJECT_FOCUS              08005H
#Define EVENT_OBJECT_SELECTION          08006H
#Define EVENT_OBJECT_SELECTIONADD       08007H
#Define EVENT_OBJECT_SELECTIONREMOVE    08008H
#Define EVENT_OBJECT_SELECTIONWITHIN    08009H
#Define EVENT_OBJECT_STATECHANGE        0800AH
#Define EVENT_OBJECT_LOCATIONCHANGE     0800BH
#Define EVENT_OBJECT_NAMECHANGE         0800CH
#Define EVENT_OBJECT_DESCRIPTIONCHANGE  0800DH
#Define EVENT_OBJECT_VALUECHANGE        0800EH
#Define EVENT_OBJECT_PARENTCHANGE       0800FH
#Define EVENT_OBJECT_HELPCHANGE         08010H
#Define EVENT_OBJECT_DEFACTIONCHANGE    08011H
#Define EVENT_OBJECT_ACCELERATORCHANGE  08012H

#Define SOUND_SYSTEM_STARTUP            1
#Define SOUND_SYSTEM_SHUTDOWN           2
#Define SOUND_SYSTEM_BEEP               3
#Define SOUND_SYSTEM_ERROR              4
#Define SOUND_SYSTEM_QUESTION           5
#Define SOUND_SYSTEM_WARNING            6
#Define SOUND_SYSTEM_INFORMATION        7
#Define SOUND_SYSTEM_MAXIMIZE           8
#Define SOUND_SYSTEM_MINIMIZE           9
#Define SOUND_SYSTEM_RESTOREUP          10
#Define SOUND_SYSTEM_RESTOREDOWN        11
#Define SOUND_SYSTEM_APPSTART           12
#Define SOUND_SYSTEM_FAULT              13
#Define SOUND_SYSTEM_APPEND             14
#Define SOUND_SYSTEM_MENUCOMMAND        15
#Define SOUND_SYSTEM_MENUPOPUP          16
#Define CSOUND_SYSTEM                   16

#Define ALERT_SYSTEM_INFORMATIONAL      1
#Define ALERT_SYSTEM_WARNING            2
#Define ALERT_SYSTEM_ERROR              3
#Define ALERT_SYSTEM_QUERY              4
#Define ALERT_SYSTEM_CRITICAL           5
#Define CALERT_SYSTEM                   6

#Define WINEVENT_OUTOFCONTEXT   		00000H
#Define WINEVENT_SKIPOWNTHREAD  		00001H
#Define WINEVENT_SKIPOWNPROCESS 		00002H
#Define WINEVENT_INCONTEXT      		00004H

#Define GUI_CARETBLINKING   			000000001H
#Define GUI_INMOVESIZE      			000000002H
#Define GUI_INMENUMODE      			000000004H
#Define GUI_SYSTEMMENUMODE  			000000008H
#Define GUI_POPUPMENUMODE   			000000010H

#Define STATE_SYSTEM_UNAVAILABLE        000000001H
#Define STATE_SYSTEM_SELECTED           000000002H
#Define STATE_SYSTEM_FOCUSED            000000004H
#Define STATE_SYSTEM_PRESSED            000000008H
#Define STATE_SYSTEM_CHECKED            000000010H
#Define STATE_SYSTEM_MIXED              000000020H
#Define STATE_SYSTEM_READONLY           000000040H
#Define STATE_SYSTEM_HOTTRACKED         000000080H
#Define STATE_SYSTEM_DEFAULT            000000100H
#Define STATE_SYSTEM_EXPANDED           000000200H
#Define STATE_SYSTEM_COLLAPSED          000000400H
#Define STATE_SYSTEM_BUSY               000000800H
#Define STATE_SYSTEM_FLOATING           000001000H
#Define STATE_SYSTEM_MARQUEED           000002000H
#Define STATE_SYSTEM_ANIMATED           000004000H
#Define STATE_SYSTEM_INVISIBLE          000008000H
#Define STATE_SYSTEM_OFFSCREEN          000010000H
#Define STATE_SYSTEM_SIZEABLE           000020000H
#Define STATE_SYSTEM_MOVEABLE           000040000H
#Define STATE_SYSTEM_SELFVOICING        000080000H
#Define STATE_SYSTEM_FOCUSABLE          000100000H
#Define STATE_SYSTEM_SELECTABLE         000200000H
#Define STATE_SYSTEM_LINKED             000400000H
#Define STATE_SYSTEM_TRAVERSED          000800000H
#Define STATE_SYSTEM_MULTISELECTABLE    001000000H
#Define STATE_SYSTEM_EXTSELECTABLE      002000000H
#Define STATE_SYSTEM_ALERT_LOW          004000000H
#Define STATE_SYSTEM_ALERT_MEDIUM       008000000H
#Define STATE_SYSTEM_ALERT_HIGH         010000000H
#Define STATE_SYSTEM_VALID              01FFFFFFFH

#Define CCHILDREN_TITLEBAR              5
#Define CCHILDREN_SCROLLBAR             5

#Define CURSOR_SHOWING     				000000001H

#Define WS_ACTIVECAPTION    			00001H

#Define GA_MIC          				1
#Define GA_PARENT       				1
#Define GA_ROOT         				2
#Define GA_ROOTOWNER    				3
#Define GA_MAC          				4


CBT_CREATEWNDA Struct
	lpcs DD
	hwndInsertAfter DD
EndS

CBT_CREATEWNDW Struct
	lpcs DD
	hwndInsertAfter DD
EndS

CBTACTIVATESTRUCT Struct
	fMouse DD
	hWndActive DD
EndS

EVENTMSG Struct
	message DD
	paramL DD
	paramH DD
	time DD
	hwnd DD
EndS

CWPSTRUCT Struct
	lParam DD
	wParam DD
	message DD
	hwnd DD
EndS

CWPRETSTRUCT Struct
	lResult DD
	lParam DD
	wParam DD
	message DD
	hwnd DD
EndS

KBDLLHOOKSTRUCT Struct
	vkCode DD
	scanCode DD
	flags DD
	time DD
	dwExtraInfo DD
EndS

MSLLHOOKSTRUCT Struct
	pt POINT <>
	mouseData DD
	flags DD
	time DD
	dwExtraInfo DD
EndS

DEBUGHOOKINFO Struct
	idThread DD
	idThreadInstaller DD
	lParam DD
	wParam DD
	code DD
EndS

MOUSEHOOKSTRUCT Struct
	pt POINT <>
	hwnd DD
	wHitTestCode DD
	dwExtraInfo DD
EndS

HARDWAREHOOKSTRUCT Struct
	hwnd DD
	message DD
	wParam DD
	lParam DD
EndS

MOUSEMOVEPOINT Struct
	x DD
	y DD
	time DD
	dwExtraInfo DD
EndS

USEROBJECTFLAGS Struct
	fInherit DD
	fReserved DD
	dwFlags DD
EndS

WNDCLASSEXA Struct
	cbSize DD
	style DD
	lpfnWndProc DD
	cbClsExtra DD
	cbWndExtra DD
	hInstance DD
	hIcon DD
	hCursor DD
	hbrBackground DD
	lpszMenuName DD
	lpszClassName DD
	hIconSm DD
EndS

WNDCLASSEXW Struct
	cbSize DD
	style DD
	lpfnWndProc DD
	cbClsExtra DD
	cbWndExtra DD
	hInstance DD
	hIcon DD
	hCursor DD
	hbrBackground DD
	lpszMenuName DD
	lpszClassName DD
	hIconSm DD
EndS

WNDCLASSA Struct
	style DD
	lpfnWndProc DD
	cbClsExtra DD
	cbWndExtra DD
	hInstance DD
	hIcon DD
	hCursor DD
	hbrBackground DD
	lpszMenuName DD
	lpszClassName DD
EndS

WNDCLASSW Struct
	style DD
	lpfnWndProc DD
	cbClsExtra DD
	cbWndExtra DD
	hInstance DD
	hIcon DD
	hCursor DD
	hbrBackground DD
	lpszMenuName DD
	lpszClassName DD
EndS

MSG Struct
	hwnd DD
	message DD
	wParam DD
	lParam DD
	time DD
	pt POINT <>
EndS

MINMAXINFO Struct
	ptReserved POINT <>
	ptMaxSize POINT <>
	ptMaxPosition POINT <>
	ptMinTrackSize POINT <>
	ptMaxTrackSize POINT <>
EndS

COPYDATASTRUCT Struct
	dwData DD
	cbData DD
	lpData DD
EndS

MDINEXTMENU Struct
	hmenuIn DD
	hmenuNext DD
	hwndNext DD
EndS

WINDOWPOS Struct
	hwnd DD
	hwndInsertAfter DD
	x DD
	y DD
	lx DD
	cy DD
	flags DD
EndS

NCCALCSIZE_PARAMS Struct
	rgrc RECT 3 Dup <>
	lppos DD
EndS

TRACKMOUSEEVENT Struct
	cbSize DD
	dwFlags DD
	hwndTrack DD
	dwHoverTime DD
EndS

ACCEL Struct
	fVirt DB
	key DW
	cmd DW
EndS

PAINTSTRUCT Struct
	hdc DD
	fErase DD
	rcPaint RECT <>
	fRestore DD
	fIncUpdate DD
	rgbReserved DB 32 Dup ?
EndS

CREATESTRUCTA Struct
	lpCreateParams DD
	hInstance DD
	hMenu DD
	hwndParent DD
	cy DD
	lx DD
	y DD
	x DD
	style DD
	lpszName DD
	lpszClass DD
	dwExStyle DD
EndS

CREATESTRUCTW Struct
	lpCreateParams DD
	hInstance DD
	hMenu DD
	hwndParent DD
	cy DD
	lx DD
	y DD
	x DD
	style DD
	lpszName DD
	lpszClass DD
	dwExStyle DD
EndS

WINDOWPLACEMENT Struct
	length DD
	flags DD
	showCmd DD
	ptMinPosition POINT <>
	ptMaxPosition POINT <>
	rcNormalPosition RECT <>
EndS

NMHDR Struct
	hwndFrom DD
	idFrom DD
	code DD
EndS

STYLESTRUCT Struct
	styleOld DD
	styleNew DD
EndS

MEASUREITEMSTRUCT Struct
	CtlType DD
	CtlID DD
	itemID DD
	itemWidth DD
	itemHeight DD
	itemData DD
EndS

DRAWITEMSTRUCT Struct
	CtlType DD
	CtlID DD
	itemID DD
	itemAction DD
	itemState DD
	hwndItem DD
	hDC DD
	rcItem RECT <>
	itemData DD
EndS

DELETEITEMSTRUCT Struct
	CtlType DD
	CtlID DD
	itemID DD
	hwndItem DD
	itemData DD
EndS

COMPAREITEMSTRUCT Struct
	CtlType DD
	CtlID DD
	hwndItem DD
	itemID1 DD
	itemData1 DD
	itemID2 DD
	itemData2 DD
	dwLocaleId DD
EndS

DLGTEMPLATE Struct
	style DD
	dwExtendedStyle DD
	cdit DW
	x DW
	y DW
	lx DW
	cy DW
EndS

DLGITEMTEMPLATE Struct
	style DD
	dwExtendedStyle DD
	x DW
	y DW
	lx DW
	cy DW
	id DW
EndS

MOUSEINPUT Struct
	lx DD
	dy DD
	mouseData DD
	dwFlags DD
	time DD
	dwExtraInfo DD
EndS

KEYBDINPUT Struct
	wVk DW
	wScan DW
	dwFlags DD
	time DD
	dwExtraInfo DD
EndS

HARDWAREINPUT Struct
	uMsg DD
	wParamL DW
	wParamH DW
EndS

INPUT Struct
	type DD
	Union
		mi MOUSEINPUT <>
		ki KEYBDINPUT <>
		hi HARDWAREINPUT <>
    EndUnion
EndS

LASTINPUTINFO Struct
	cbSize DD
	dwTime DD
EndS

TPMPARAMS Struct
	cbSize DD
	rcExclude RECT <>
EndS

MENUINFO Struct
	cbSize DD
	fMask DD
	dwStyle DD
	cyMax DD
	hbrBack DD
	dwContextHelpID DD
	dwMenuData DD
EndS

MENUGETOBJECTINFO Struct
	dwFlags DD
	uPos DD
	hmenu DD
	riid DD
	pvObj DD
EndS

MENUITEMINFOA Struct
	cbSize DD
	fMask DD
	fType DD
	fState DD
	wID DD
	hSubMenu DD
	hbmpChecked DD
	hbmpUnchecked DD
	dwItemData DD
	dwTypeData DD
	cch DD
#IF (WINVER >= 00500H)
	hbmpItem DD
#ENDIF
EndS

MENUITEMINFOW Struct
	cbSize DD
	fMask DD
	fType DD
	fState DD
	wID DD
	hSubMenu DD
	hbmpChecked DD
	hbmpUnchecked DD
	dwItemData DD
	dwTypeData DD
	cch DD
#IF (WINVER >= 00500H)
	hbmpItem DD
#ENDIF
EndS

DROPSTRUCT Struct
	hwndSource DD
	hwndSink DD
	wFmt DD
	dwData DD
	ptDrop POINT <>
	dwControlData DD
EndS

DRAWTEXTPARAMS Struct
	cbSize DD
	iTabLength DD
	iLeftMargin DD
	iRightMargin DD
	uiLengthDrawn DD
EndS

HELPINFO Struct
	cbSize DD
	iContextType DD
	iCtrlId DD
	hItemHandle DD
	dwContextId DD
	MousePos POINT <>
EndS

MSGBOXPARAMSA Struct
	cbSize DD
	hwndOwner DD
	hInstance DD
	lpszText DD
	lpszCaption DD
	dwStyle DD
	lpszIcon DD
	dwContextHelpId DD
	lpfnMsgBoxCallback DD
	dwLanguageId DD
EndS

MSGBOXPARAMSW Struct
	cbSize DD
	hwndOwner DD
	hInstance DD
	lpszText DD
	lpszCaption DD
	dwStyle DD
	lpszIcon DD
	dwContextHelpId DD
	lpfnMsgBoxCallback DD
	dwLanguageId DD
EndS

MENUITEMTEMPLATEHEADER Struct
	versionNumber DW
	offset DW
EndS

MENUITEMTEMPLATE Struct
	mtOption DW
	mtID DW
	mtString DW
EndS

ICONINFO Struct
	fIcon DD
	xHotspot DD
	yHotspot DD
	hbmMask DD
	hbmColor DD
EndS

CURSORSHAPE Struct
	xHotSpot DD
	yHotSpot DD
	lx DD
	cy DD
	cbWidth DD
	Planes DB
	BitsPixel DB
EndS

SCROLLINFO Struct
	cbSize DD
	fMask DD
	nMin DD
	nMax DD
	nPage DD
	nPos DD
	nTrackPos DD
EndS

MDICREATESTRUCTA Struct
	szClass DD
	szTitle DD
	hOwner DD
	x DD
	y DD
	lx DD
	cy DD
	style DD
	lParam DD
EndS

MDICREATESTRUCTW Struct
	szClass DD
	szTitle DD
	hOwner DD
	x DD
	y DD
	lx DD
	cy DD
	style DD
	lParam DD
EndS

CLIENTCREATESTRUCT Struct
	hWindowMenu DD
	idFirstChild DD
EndS

MULTIKEYHELPA Struct
	mkSize DD
	mkKeylist DB
	szKeyphrase DB
EndS

MULTIKEYHELPW Struct
	mkSize DD
	mkKeylist DW
	szKeyphrase DW
EndS

HELPWININFOA Struct
	wStructSize DD
	x DD
	y DD
	lx DD
	dy DD
	wMax DD
	rgchMember DB 2 Dup ?
EndS

HELPWININFOW Struct
	wStructSize DD
	x DD
	y DD
	lx DD
	dy DD
	wMax DD
	rgchMember DW 2 Dup ?
EndS

NONCLIENTMETRICSA Struct
	cbSize DD
	iBorderWidth DD
	iScrollWidth DD
	iScrollHeight DD
	iCaptionWidth DD
	iCaptionHeight DD
	lfCaptionFont LOGFONTA <>
	iSmCaptionWidth DD
	iSmCaptionHeight DD
	lfSmCaptionFont LOGFONTA <>
	iMenuWidth DD
	iMenuHeight DD
	lfMenuFont LOGFONTA <>
	lfStatusFont LOGFONTA <>
	lfMessageFont LOGFONTA <>
EndS

NONCLIENTMETRICSW Struct
	cbSize DD
	iBorderWidth DD
	iScrollWidth DD
	iScrollHeight DD
	iCaptionWidth DD
	iCaptionHeight DD
	lfCaptionFont LOGFONTW <>
	iSmCaptionWidth DD
	iSmCaptionHeight DD
	lfSmCaptionFont LOGFONTW <>
	iMenuWidth DD
	iMenuHeight DD
	lfMenuFont LOGFONTW <>
	lfStatusFont LOGFONTW <>
	lfMessageFont LOGFONTW <>
EndS

MINIMIZEDMETRICS Struct
	cbSize DD
	iWidth DD
	iHorzGap DD
	iVertGap DD
	iArrange DD
EndS

ICONMETRICSA Struct
	cbSize DD
	iHorzSpacing DD
	iVertSpacing DD
	iTitleWrap DD
	lfFont LOGFONTA <>
EndS

ICONMETRICSW Struct
	cbSize DD
	iHorzSpacing DD
	iVertSpacing DD
	iTitleWrap DD
	lfFont LOGFONTW <>
EndS

ANIMATIONINFO Struct
	cbSize DD
	iMinAnimate DD
EndS

SERIALKEYSA Struct
	cbSize DD
	dwFlags DD
	lpszActivePort DD
	lpszPort DD
	iBaudRate DD
	iPortState DD
	iActive DD
EndS

SERIALKEYSW Struct
	cbSize DD
	dwFlags DD
	lpszActivePort DD
	lpszPort DD
	iBaudRate DD
	iPortState DD
	iActive DD
EndS

HIGHCONTRASTA Struct
	cbSize DD
	dwFlags DD
	lpszDefaultScheme DD
EndS

HIGHCONTRASTW Struct
	cbSize DD
	dwFlags DD
	lpszDefaultScheme DD
EndS

FILTERKEYS Struct
	cbSize DD
	dwFlags DD
	iWaitMSec DD
	iDelayMSec DD
	iRepeatMSec DD
	iBounceMSec DD
EndS

STICKYKEYS Struct
	cbSize DD
	dwFlags DD
EndS

MOUSEKEYS Struct
	cbSize DD
	dwFlags DD
	iMaxSpeed DD
	iTimeToMaxSpeed DD
	iCtrlSpeed DD
	dwReserved1 DD
	dwReserved2 DD
EndS

ACCESSTIMEOUT Struct
	cbSize DD
	dwFlags DD
	iTimeOutMSec DD
EndS

SOUNDSENTRYA Struct
	cbSize DD
	dwFlags DD
	iFSTextEffect DD
	iFSTextEffectMSec DD
	iFSTextEffectColorBits DD
	iFSGrafEffect DD
	iFSGrafEffectMSec DD
	iFSGrafEffectColor DD
	iWindowsEffect DD
	iWindowsEffectMSec DD
	lpszWindowsEffectDLL DD
	iWindowsEffectOrdinal DD
EndS

SOUNDSENTRYW Struct
	cbSize DD
	dwFlags DD
	iFSTextEffect DD
	iFSTextEffectMSec DD
	iFSTextEffectColorBits DD
	iFSGrafEffect DD
	iFSGrafEffectMSec DD
	iFSGrafEffectColor DD
	iWindowsEffect DD
	iWindowsEffectMSec DD
	lpszWindowsEffectDLL DD
	iWindowsEffectOrdinal DD
EndS

TOGGLEKEYS Struct
	cbSize DD
	dwFlags DD
EndS

MONITORINFO Struct
	cbSize DD
	rcMonitor RECT <>
	rcWork RECT <>
	dwFlags DD
EndS

MONITORINFOEXA Struct
	cbSize DD
	rcMonitor RECT <>
	rcWork RECT <>
	dwFlags DD
	szDevice DB CCHDEVICENAME Dup ?
EndS

MONITORINFOEXW Struct
	cbSize DD
	rcMonitor RECT <>
	rcWork RECT <>
	dwFlags DD
	szDevice DW CCHDEVICENAME Dup ?
EndS

GUITHREADINFO Struct
	cbSize DD
	flags DD
	hwndActive DD
	hwndFocus DD
	hwndCapture DD
	hwndMenuOwner DD
	hwndMoveSize DD
	hwndCaret DD
	rcCaret RECT <>
EndS

CURSORINFO Struct
	cbSize DD
	flags DD
	hCursor DD
	ptScreenPos POINT <>
EndS

WINDOWINFO Struct
	cbSize DD
	rcWindow RECT <>
	rcClient RECT <>
	dwStyle DD
	dwExStyle DD
	dwOtherStuff DD
	cxWindowBorders DD
	cyWindowBorders DD
    ATOM  atomWindowType DW
	wCreatorVersion DW
EndS

MENUBARINFO Struct
    DWORD cbSize DD
	rcBar RECT <>
	hMenu DD
	hwndMenu DD
	fBarFocused DD
	fFocused DD
EndS

SCROLLBARINFO Struct
	cbSize DD
	rcScrollBar RECT <>
	dxyLineButton DD
	xyThumbTop DD
	xyThumbBottom DD
	bogus DD
    rgstate DD CCHILDREN_SCROLLBAR + 1 Dup ?
EndS

COMBOBOXINFO Struct
	cbSize DD
	rcItem RECT <>
	rcButton RECT <>
	stateButton DD
	hwndCombo DD
	hwndItem DD
	hwndList DD
EndS

ALTTABINFO Struct
	cbSize DD
	cItems DD
	cColumns DD
	cRows DD
	iColFocus DD
	iRowFocus DD
	cxItem DD
	cyItem DD
	ptStart POINT <>
EndS


#IF STRINGS UNICODE
	#Define wvsprintf wvsprintfW
	#Define wsprintf wsprintfW
	#Define CBT_CREATEWND CBT_CREATEWNDW
	#Define LoadKeyboardLayout LoadKeyboardLayoutW
	#Define GetKeyboardLayoutName GetKeyboardLayoutNameW
	#Define CreateDesktop CreateDesktopW
	#Define OpenDesktop OpenDesktopW
	#Define EnumDesktops EnumDesktopsW
	#Define CreateWindowStation CreateWindowStationW
	#Define OpenWindowStation OpenWindowStationW
	#Define EnumWindowStations EnumWindowStationsW
	#Define GetUserObjectInformation GetUserObjectInformationW
	#Define SetUserObjectInformation SetUserObjectInformationW
	#Define WNDCLASSEX WNDCLASSEXW
	#Define WNDCLASS WNDCLASSW
	#Define RegisterWindowMessage RegisterWindowMessageW
	#Define CREATESTRUCT CREATESTRUCTW
	#Define GetMessage GetMessageW
	#Define DispatchMessage DispatchMessageW
	#Define PeekMessage PeekMessageW
	#Define SendMessage SendMessageW
	#Define SendMessageTimeout SendMessageTimeoutW
	#Define SendNotifyMessage SendNotifyMessageW
	#Define SendMessageCallback SendMessageCallbackW
	#Define BroadcastSystemMessage BroadcastSystemMessageW
	#Define RegisterDeviceNotification RegisterDeviceNotificationW
	#Define PostMessage PostMessageW
	#Define PostThreadMessage PostThreadMessageW
	#Define PostAppMessage PostAppMessageW
	#Define DefWindowProc DefWindowProcW
	#Define CallWindowProc CallWindowProcW
	#Define CallWindowProc CallWindowProcW
	#Define RegisterClass RegisterClassW
	#Define UnregisterClass UnregisterClassW
	#Define GetClassInfo GetClassInfoW
	#Define RegisterClassEx RegisterClassExW
	#Define GetClassInfoEx GetClassInfoExW
	#Define CreateWindowEx CreateWindowExW
	#Define CreateWindow CreateWindowW
	#Define CreateDialogParam CreateDialogParamW
	#Define CreateDialogIndirectParam CreateDialogIndirectParamW
	#Define CreateDialog CreateDialogW
	#Define CreateDialogIndirect CreateDialogIndirectW
	#Define DialogBoxParam DialogBoxParamW
	#Define DialogBoxIndirectParam DialogBoxIndirectParamW
	#Define DialogBox DialogBoxW
	#Define DialogBoxIndirect DialogBoxIndirectW
	#Define SetDlgItemText SetDlgItemTextW
	#Define GetDlgItemText GetDlgItemTextW
	#Define SendDlgItemMessage SendDlgItemMessageW
	#Define DefDlgProc DefDlgProcW
	#Define CallMsgFilter CallMsgFilterW
	#Define RegisterClipboardFormat RegisterClipboardFormatW
	#Define GetClipboardFormatName GetClipboardFormatNameW
	#Define CharToOem CharToOemW
	#Define OemToChar OemToCharW
	#Define CharToOemBuff CharToOemBuffW
	#Define OemToCharBuff OemToCharBuffW
	#Define CharUpper CharUpperW
	#Define CharUpperBuff CharUpperBuffW
	#Define CharLower CharLowerW
	#Define CharLowerBuff CharLowerBuffW
	#Define CharNext CharNextW
	#Define CharPrev CharPrevW
	#Define IsCharAlpha IsCharAlphaW
	#Define IsCharAlphaNumeric IsCharAlphaNumericW
	#Define IsCharUpper IsCharUpperW
	#Define IsCharLower IsCharLowerW
	#Define GetKeyNameText GetKeyNameTextW
	#Define VkKeyScan VkKeyScanW
	#Define VkKeyScanEx VkKeyScanExW
	#Define MapVirtualKey MapVirtualKeyW
	#Define MapVirtualKeyEx MapVirtualKeyExW
	#Define LoadAccelerators LoadAcceleratorsW
	#Define CreateAcceleratorTable CreateAcceleratorTableW
	#Define CopyAcceleratorTable CopyAcceleratorTableW
	#Define TranslateAccelerator TranslateAcceleratorW
	#Define LoadMenu LoadMenuW
	#Define LoadMenuIndirect LoadMenuIndirectW
	#Define ChangeMenu ChangeMenuW
	#Define GetMenuString GetMenuStringW
	#Define InsertMenu InsertMenuW
	#Define AppendMenu AppendMenuW
	#Define ModifyMenu ModifyMenuW
	#Define MENUITEMINFO MENUITEMINFOW
	#Define InsertMenuItem InsertMenuItemW
	#Define GetMenuItemInfo GetMenuItemInfoW
	#Define SetMenuItemInfo SetMenuItemInfoW
	#Define DrawText DrawTextW
	#Define DrawTextEx DrawTextExW
	#Define GrayString GrayStringW
	#Define DrawState DrawStateW
	#Define TabbedTextOut TabbedTextOutW
	#Define GetTabbedTextExtent GetTabbedTextExtentW
	#Define SetProp SetPropW
	#Define GetProp GetPropW
	#Define RemoveProp RemovePropW
	#Define EnumPropsEx EnumPropsExW
	#Define EnumProps EnumPropsW
	#Define SetWindowText SetWindowTextW
	#Define GetWindowText GetWindowTextW
	#Define GetWindowTextLength GetWindowTextLengthW
	#Define MessageBox MessageBoxW
	#Define MessageBoxEx MessageBoxExW
	#Define MSGBOXPARAMS MSGBOXPARAMSW
	#Define MessageBoxIndirect MessageBoxIndirectW
	#Define GetWindowLong GetWindowLongW
	#Define SetWindowLong SetWindowLongW
	#Define GetClassLong GetClassLongW
	#Define SetClassLong SetClassLongW
	#Define FindWindow FindWindowW
	#Define FindWindowEx FindWindowExW
	#Define GetClassName GetClassNameW
	#Define SetWindowsHook SetWindowsHookW
	#Define SetWindowsHookEx SetWindowsHookExW
	#Define LoadBitmap LoadBitmapW
	#Define LoadCursor LoadCursorW
	#Define LoadCursorFromFile LoadCursorFromFileW
	#Define LoadIcon LoadIconW
	#Define LoadImage LoadImageW
	#Define LoadString LoadStringW
	#Define IsDialogMessage IsDialogMessageW
	#Define DlgDirList DlgDirListW
	#Define DlgDirSelectEx DlgDirSelectExA
	#Define DlgDirListComboBox DlgDirListComboBoxW
	#Define DlgDirSelectComboBoxEx DlgDirSelectComboBoxExW
	#Define MDICREATESTRUCT MDICREATESTRUCTW
	#Define DefFrameProc DefFrameProcW
	#Define DefMDIChildProc DefMDIChildProcW
	#Define CreateMDIWindow CreateMDIWindowW
	#Define MULTIKEYHELP MULTIKEYHELPW
	#Define HELPWININFO HELPWININFOW
	#Define WinHelp WinHelpW
	#Define NONCLIENTMETRICS NONCLIENTMETRICSW
	#Define ICONMETRICS ICONMETRICSW
	#Define SERIALKEYS SERIALKEYSW
	#Define HIGHCONTRAST HIGHCONTRASTW
	#Define ChangeDisplaySettings ChangeDisplaySettingsW
	#Define ChangeDisplaySettingsEx ChangeDisplaySettingsExW
	#Define EnumDisplaySettings EnumDisplaySettingsW
	#Define EnumDisplayDevices EnumDisplayDevicesW
	#Define SystemParametersInfo SystemParametersInfoW
	#Define SOUNDSENTRY SOUNDSENTRYW
	#Define MONITORINFOEX MONITORINFOEXW
	#Define GetMonitorInfo GetMonitorInfoW
	#Define GetWindowModuleFileName GetWindowModuleFileNameW
	#Define RealGetWindowClass RealGetWindowClassW
	#Define GetAltTabInfo GetAltTabInfoW
#ELSE
	#Define wvsprintf wvsprintfA
	#Define wsprintf wsprintfA
	#Define CBT_CREATEWND CBT_CREATEWNDA
	#Define LoadKeyboardLayout LoadKeyboardLayoutA
	#Define GetKeyboardLayoutName GetKeyboardLayoutNameA
	#Define CreateDesktop CreateDesktopA
	#Define OpenDesktop OpenDesktopA
	#Define EnumDesktops EnumDesktopsA
	#Define CreateWindowStation CreateWindowStationA
	#Define OpenWindowStation OpenWindowStationA
	#Define EnumWindowStations EnumWindowStationsA
	#Define GetUserObjectInformation GetUserObjectInformationA
	#Define SetUserObjectInformation SetUserObjectInformationA
	#Define WNDCLASSEX WNDCLASSEXA
	#Define WNDCLASS WNDCLASSA
	#Define RegisterWindowMessage RegisterWindowMessageA
	#Define CREATESTRUCT CREATESTRUCTA
	#Define GetMessage GetMessageA
	#Define DispatchMessage DispatchMessageA
	#Define PeekMessage PeekMessageA
	#Define SendMessage SendMessageA
	#Define SendMessageTimeout SendMessageTimeoutA
	#Define SendNotifyMessage SendNotifyMessageA
	#Define SendMessageCallback SendMessageCallbackA
	#Define BroadcastSystemMessage BroadcastSystemMessageA
	#Define RegisterDeviceNotification RegisterDeviceNotificationA
	#Define PostMessage PostMessageA
	#Define PostThreadMessage PostThreadMessageA
	#Define PostAppMessage PostAppMessageA
	#Define DefWindowProc DefWindowProcA
	#Define CallWindowProc CallWindowProcA
	#Define CallWindowProc CallWindowProcA
	#Define RegisterClass RegisterClassA
	#Define UnregisterClass UnregisterClassA
	#Define GetClassInfo GetClassInfoA
	#Define RegisterClassEx RegisterClassExA
	#Define GetClassInfoEx GetClassInfoExA
	#Define CreateWindowEx CreateWindowExA
	#Define CreateWindow CreateWindowA
	#Define CreateDialogParam CreateDialogParamA
	#Define CreateDialogIndirectParam CreateDialogIndirectParamA
	#Define CreateDialog CreateDialogA
	#Define CreateDialogIndirect CreateDialogIndirectA
	#Define DialogBoxParam DialogBoxParamA
	#Define DialogBoxIndirectParam DialogBoxIndirectParamA
	#Define DialogBox DialogBoxA
	#Define DialogBoxIndirect DialogBoxIndirectA
	#Define SetDlgItemText SetDlgItemTextA
	#Define GetDlgItemText GetDlgItemTextA
	#Define SendDlgItemMessage SendDlgItemMessageA
	#Define DefDlgProc DefDlgProcA
	#Define CallMsgFilter CallMsgFilterA
	#Define RegisterClipboardFormat RegisterClipboardFormatA
	#Define GetClipboardFormatName GetClipboardFormatNameA
	#Define CharToOem CharToOemA
	#Define OemToChar OemToCharA
	#Define CharToOemBuff CharToOemBuffA
	#Define OemToCharBuff OemToCharBuffA
	#Define CharUpper CharUpperA
	#Define CharUpperBuff CharUpperBuffA
	#Define CharLower CharLowerA
	#Define CharLowerBuff CharLowerBuffA
	#Define CharNext CharNextA
	#Define CharPrev CharPrevA
	#Define IsCharAlpha IsCharAlphaA
	#Define IsCharAlphaNumeric IsCharAlphaNumericA
	#Define IsCharUpper IsCharUpperA
	#Define IsCharLower IsCharLowerA
	#Define GetKeyNameText GetKeyNameTextA
	#Define VkKeyScan VkKeyScanA
	#Define VkKeyScanEx VkKeyScanExA
	#Define MapVirtualKey MapVirtualKeyA
	#Define MapVirtualKeyEx MapVirtualKeyExA
	#Define LoadAccelerators LoadAcceleratorsA
	#Define CreateAcceleratorTable CreateAcceleratorTableA
	#Define CopyAcceleratorTable CopyAcceleratorTableA
	#Define TranslateAccelerator TranslateAcceleratorA
	#Define LoadMenu LoadMenuA
	#Define LoadMenuIndirect LoadMenuIndirectA
	#Define ChangeMenu ChangeMenuA
	#Define GetMenuString GetMenuStringA
	#Define InsertMenu InsertMenuA
	#Define AppendMenu AppendMenuA
	#Define ModifyMenu ModifyMenuA
	#Define MENUITEMINFO MENUITEMINFOA
	#Define InsertMenuItem InsertMenuItemA
	#Define GetMenuItemInfo GetMenuItemInfoA
	#Define SetMenuItemInfo SetMenuItemInfoA
	#Define DrawText DrawTextA
	#Define DrawTextEx DrawTextExA
	#Define GrayString GrayStringA
	#Define DrawState DrawStateA
	#Define TabbedTextOut TabbedTextOutA
	#Define GetTabbedTextExtent GetTabbedTextExtentA
	#Define SetProp SetPropA
	#Define GetProp GetPropA
	#Define RemoveProp RemovePropA
	#Define EnumPropsEx EnumPropsExA
	#Define EnumProps EnumPropsA
	#Define SetWindowText SetWindowTextA
	#Define GetWindowText GetWindowTextA
	#Define GetWindowTextLength GetWindowTextLengthA
	#Define MessageBox MessageBoxA
	#Define MessageBoxEx MessageBoxExA
	#Define MSGBOXPARAMS MSGBOXPARAMSA
	#Define MessageBoxIndirect MessageBoxIndirectA
	#Define GetWindowLong GetWindowLongA
	#Define SetWindowLong SetWindowLongA
	#Define GetClassLong GetClassLongA
	#Define SetClassLong SetClassLongA
	#Define FindWindow FindWindowA
	#Define FindWindowEx FindWindowExA
	#Define GetClassName GetClassNameA
	#Define SetWindowsHook SetWindowsHookA
	#Define SetWindowsHookEx SetWindowsHookExA
	#Define LoadBitmap LoadBitmapA
	#Define LoadCursor LoadCursorA
	#Define LoadCursorFromFile LoadCursorFromFileA
	#Define LoadIcon LoadIconA
	#Define LoadImage LoadImageA
	#Define LoadString LoadStringA
	#Define IsDialogMessage IsDialogMessageA
	#Define DlgDirList DlgDirListA
	#Define DlgDirSelectEx DlgDirSelectExA
	#Define DlgDirListComboBox DlgDirListComboBoxA
	#Define DlgDirSelectComboBoxEx DlgDirSelectComboBoxExA
	#Define MDICREATESTRUCT MDICREATESTRUCTA
	#Define DefFrameProc DefFrameProcA
	#Define DefMDIChildProc DefMDIChildProcA
	#Define CreateMDIWindow CreateMDIWindowA
	#Define MULTIKEYHELP MULTIKEYHELPA
	#Define HELPWININFO HELPWININFOA
	#Define WinHelp WinHelpA
	#Define NONCLIENTMETRICS NONCLIENTMETRICSA
	#Define ICONMETRICS ICONMETRICSA
	#Define SERIALKEYS SERIALKEYSA
	#Define HIGHCONTRAST HIGHCONTRASTA
	#Define ChangeDisplaySettings ChangeDisplaySettingsA
	#Define ChangeDisplaySettingsEx ChangeDisplaySettingsExA
	#Define EnumDisplaySettings EnumDisplaySettingsA
	#Define EnumDisplayDevices EnumDisplayDevicesA
	#Define SystemParametersInfo SystemParametersInfoA
	#Define SOUNDSENTRY SOUNDSENTRYA
	#Define MONITORINFOEX MONITORINFOEXA
	#Define GetMonitorInfo GetMonitorInfoA
	#Define GetWindowModuleFileName GetWindowModuleFileNameA
	#Define RealGetWindowClass RealGetWindowClassA
	#Define GetAltTabInfo GetAltTabInfoA
#ENDIF

#Define AnsiToOem CharToOemA
#define OemToAnsi OemToCharA
#define AnsiToOemBuff CharToOemBuffA
#define OemToAnsiBuff OemToCharBuffA
#define AnsiUpper CharUpperA
#define AnsiUpperBuff CharUpperBuffA
#define AnsiLower CharLowerA
#define AnsiLowerBuff CharLowerBuffA
#define AnsiNext CharNextA
#define AnsiPrev CharPrevA

#ENDIF ;WINUSER_INC
