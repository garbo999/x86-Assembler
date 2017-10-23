;=============================================================;
;           shlobj.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                (modified on November, 2007)                 ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF SHLOBJ_INC
#Define SHLOBJ

#IFNDEF OLE2_INC
	#Include <ole2.inc>
#ENDIF

#IFNDEF PRSHT_INC
	#Include <prsht.inc>
#ENDIF

#IFNDEF COMMCTRL_INC
	#Include <commctrl.inc>
#ENDIF

#IFNDEF SHLGUID_INC
	#Include <shlguid.inc>
#ENDIF

#Define CMF_NORMAL              	000000000H
#Define CMF_DEFAULTONLY         	000000001H
#Define CMF_VERBSONLY           	000000002H
#Define CMF_EXPLORE             	000000004H
#Define CMF_NOVERBS             	000000008H
#Define CMF_CANRENAME           	000000010H
#Define CMF_NODEFAULT           	000000020H
#Define CMF_INCLUDESTATIC       	000000040H
#Define CMF_RESERVED            	0FFFF0000H

#Define GCS_VERBA        			000000000H
#Define GCS_HELPTEXTA    			000000001H
#Define GCS_VALIDATEA    			000000002H
#Define GCS_VERBW        			000000004H
#Define GCS_HELPTEXTW    			000000005H
#Define GCS_VALIDATEW    			000000006H
#Define GCS_UNICODE      			000000004H

#Define CMIC_MASK_HOTKEY        	SEE_MASK_HOTKEY
#Define CMIC_MASK_ICON          	SEE_MASK_ICON
#Define CMIC_MASK_FLAG_NO_UI    	SEE_MASK_FLAG_NO_UI
#Define CMIC_MASK_UNICODE       	SEE_MASK_UNICODE
#Define CMIC_MASK_NO_CONSOLE    	SEE_MASK_NO_CONSOLE
#Define CMIC_MASK_HASLINKNAME   	SEE_MASK_HASLINKNAME
#Define CMIC_MASK_FLAG_SEP_VDM  	SEE_MASK_FLAG_SEPVDM
#Define CMIC_MASK_HASTITLE      	SEE_MASK_HASTITLE
#Define CMIC_MASK_ASYNCOK       	SEE_MASK_ASYNCOK

#Define CMIC_MASK_PTINVOKE      	020000000H

#Define GIL_OPENICON     			00001H
#Define GIL_FORSHELL     			00002H
#Define GIL_ASYNC        			00020H

#Define GIL_SIMULATEDOC  			00001H
#Define GIL_PERINSTANCE  			00002H
#Define GIL_PERCLASS     			00004H
#Define GIL_NOTFILENAME  			00008H
#Define GIL_DONTCACHE    			00010H

#Define ISIOI_ICONFILE          	000000001H
#Define ISIOI_ICONINDEX         	000000002H
#Define ISIOI_SYSIMAGELISTINDEX		000000004H

;SLR_FLAGS enumeration
SLR_NO_UI           				Equ 00001H
SLR_ANY_MATCH       				Equ 00002H
SLR_UPDATE	       					Equ 00004H
SLR_NOUPDATE       					Equ 00008H

;SLGP_FLAGS enumeration
SLGP_SHORTPATH       				Equ 00001H
SLGP_UNCPRIORITY       				Equ 00002H
SLGP_RAWPATH       					Equ 00004H

#Define FO_MOVE           			00001H
#Define FO_COPY           			00002H
#Define FO_DELETE         			00003H
#Define FO_RENAME         			00004H

#Define FOF_MULTIDESTFILES      	00001H
#Define FOF_CONFIRMMOUSE        	00002H
#Define FOF_SILENT              	00004H
#Define FOF_RENAMEONCOLLISION   	00008H
#Define FOF_NOCONFIRMATION      	00010H
#Define FOF_WANTMAPPINGHANDLE   	00020H

#Define FOF_ALLOWUNDO              	00040H
#Define FOF_FILESONLY              	00080H
#Define FOF_SIMPLEPROGRESS         	00100H
#Define FOF_NOCONFIRMMKDIR         	00200H
#Define FOF_NOERRORUI              	00400H
#Define FOF_NOCOPYSECURITYATTRIBS  	00800H

#Define PO_DELETE       			00013H
#Define PO_RENAME       			00014H
#Define PO_PORTCHANGE   			00020H
#Define PO_REN_PORT     			00034H

#Define FVSIF_RECT      			000000001H
#Define FVSIF_PINNED    			000000002H

#Define FVSIF_NEWFAILED 			008000000H

#Define FVSIF_NEWFILE   			080000000H
#Define FVSIF_CANVIEWIT 			040000000H

#Define FCIDM_SHVIEWFIRST           00000H
#Define FCIDM_SHVIEWLAST            07FFFH
#Define FCIDM_BROWSERFIRST          0A000H
#Define FCIDM_BROWSERLAST           0BF00H
#Define FCIDM_GLOBALFIRST           08000H
#Define FCIDM_GLOBALLAST            09FFFH

#Define FCIDM_MENU_FILE             (FCIDM_GLOBALFIRST + 00000H)
#Define FCIDM_MENU_EDIT             (FCIDM_GLOBALFIRST + 00040H)
#Define FCIDM_MENU_VIEW             (FCIDM_GLOBALFIRST + 00080H)
#Define FCIDM_MENU_VIEW_SEP_OPTIONS (FCIDM_GLOBALFIRST + 00081H)
#Define FCIDM_MENU_TOOLS            (FCIDM_GLOBALFIRST + 000C0H)
#Define FCIDM_MENU_TOOLS_SEP_GOTO   (FCIDM_GLOBALFIRST + 000C1H)
#Define FCIDM_MENU_HELP             (FCIDM_GLOBALFIRST + 00100H)
#Define FCIDM_MENU_FIND             (FCIDM_GLOBALFIRST + 00140H)
#Define FCIDM_MENU_EXPLORE          (FCIDM_GLOBALFIRST + 00150H)
#Define FCIDM_MENU_FAVORITES        (FCIDM_GLOBALFIRST + 00170H)

#Define FCIDM_TOOLBAR      			(FCIDM_BROWSERFIRST + 0)
#Define FCIDM_STATUS       			(FCIDM_BROWSERFIRST + 1)

#Define IDC_OFFLINE_HAND        	103

;FOLDERFLAGS enumeration
FWF_AUTOARRANGE						Equ 00001H
FWF_ABBREVIATEDNAMES				Equ 00002H
FWF_SNAPTOGRID						Equ 00004H
FWF_OWNERDATA						Equ 00008H
FWF_BESTFITWINDOW					Equ 00010H
FWF_DESKTOP							Equ 00020H
FWF_SINGLESEL						Equ 00040H
FWF_NOSUBFOLDERS					Equ 00080H
FWF_TRANSPARENT						Equ 00100H
FWF_NOCLIENTEDGE					Equ 00200H
FWF_NOSCROLL						Equ 00400H
FWF_ALIGNLEFT						Equ 00800H
FWF_NOICONS							Equ 01000H
FWF_SINGLECLICKACTIVATE				Equ 08000H

;FOLDERVIEWMODE enumeration
FVM_ICON							Equ 1
FVM_SMALLICON						Equ 2
FVM_LIST							Equ 3
FVM_DETAILS							Equ 4

#Define SBSP_DEFBROWSER         	00000H
#Define SBSP_SAMEBROWSER        	00001H
#Define SBSP_NEWBROWSER         	00002H

#Define SBSP_DEFMODE            	00000H
#Define SBSP_OPENMODE           	00010H
#Define SBSP_EXPLOREMODE        	00020H

#Define SBSP_ABSOLUTE           	00000H
#Define SBSP_RELATIVE           	01000H
#Define SBSP_PARENT             	02000H
#Define SBSP_NAVIGATEBACK       	04000H
#Define SBSP_NAVIGATEFORWARD    	08000H

#Define SBSP_ALLOW_AUTONAVIGATE 	010000H

#Define SBSP_INITIATEDBYHLINKFRAME  080000000H
#Define SBSP_REDIRECT               040000000H

#Define SBSP_WRITENOHISTORY     	008000000H
#Define SBSP_NOAUTOSELECT       	004000000H

#Define FCW_STATUS      			00001H
#Define FCW_TOOLBAR     			00002H
#Define FCW_TREE        			00003H
#Define FCW_INTERNETBAR 			00006H
#Define FCW_PROGRESS    			00008H

#Define FCT_MERGE       			00001H
#Define FCT_CONFIGABLE  			00002H
#Define FCT_ADDTOEND    			00004H


;enumeration
SBSC_HIDE							Equ 0
SBSC_SHOW							Equ 1
SBSC_TOGGLE							Equ 2
SBSC_QUERY							Equ 3

;enumeration
SBO_DEFAULT							Equ 0
SBO_NOBROWSERPAGES					Equ 1

#Define CDBOSC_SETFOCUS     		000000000H
#Define CDBOSC_KILLFOCUS    		000000001H
#Define CDBOSC_SELCHANGE    		000000002H
#Define CDBOSC_RENAME       		000000003H

#Define SVSI_DESELECT   			00000H
#Define SVSI_SELECT     			00001H
#Define SVSI_EDIT       			00003H
#Define SVSI_DESELECTOTHERS 		00004H
#Define SVSI_ENSUREVISIBLE  		00008H
#Define SVSI_FOCUSED        		00010H
#Define SVSI_TRANSLATEPT    		00020H

#Define SVGIO_BACKGROUND    		000000000H
#Define SVGIO_SELECTION     		000000001H
#Define SVGIO_ALLVIEW       		000000002H

;SVUIA_STATUS enumeration
SVUIA_DEACTIVATE					Equ 0
SVUIA_ACTIVATE_NOFOCUS				Equ 1
SVUIA_ACTIVATE_FOCUS				Equ 2
SVUIA_INPLACEACTIVATE				Equ 3

#Define STRRET_WSTR     			00000H
#Define STRRET_OFFSET   			00001H
#Define STRRET_CSTR     			00002H

#Define CSIDL_DESKTOP               	00000H
#Define CSIDL_INTERNET                  00001H
#Define CSIDL_PROGRAMS                  00002H
#Define CSIDL_CONTROLS                  00003H
#Define CSIDL_PRINTERS                  00004H
#Define CSIDL_PERSONAL                  00005H
#Define CSIDL_FAVORITES                 00006H
#Define CSIDL_STARTUP                   00007H
#Define CSIDL_RECENT                    00008H
#Define CSIDL_SENDTO                    00009H
#Define CSIDL_BITBUCKET                 0000AH
#Define CSIDL_STARTMENU                 0000BH
#Define CSIDL_DESKTOPDIRECTORY          00010H
#Define CSIDL_DRIVES                    00011H
#Define CSIDL_NETWORK                   00012H
#Define CSIDL_NETHOOD                   00013H
#Define CSIDL_FONTS                     00014H
#Define CSIDL_TEMPLATES                 00015H
#Define CSIDL_COMMON_STARTMENU          00016H
#Define CSIDL_COMMON_PROGRAMS           00017H
#Define CSIDL_COMMON_STARTUP            00018H
#Define CSIDL_COMMON_DESKTOPDIRECTORY   00019H
#Define CSIDL_APPDATA                   0001AH
#Define CSIDL_PRINTHOOD                 0001BH
#Define CSIDL_ALTSTARTUP                0001DH
#Define CSIDL_COMMON_ALTSTARTUP         0001EH
#Define CSIDL_COMMON_FAVORITES          0001FH
#Define CSIDL_INTERNET_CACHE            00020H
#Define CSIDL_COOKIES                   00021H
#Define CSIDL_HISTORY                   00022H

#Define BIF_RETURNONLYFSDIRS   		00001H
#Define BIF_DONTGOBELOWDOMAIN  		00002H
#Define BIF_STATUSTEXT         		00004H
#Define BIF_RETURNFSANCESTORS  		00008H
#Define BIF_EDITBOX            		00010H
#Define BIF_VALIDATE           		00020H

#Define BIF_BROWSEFORCOMPUTER  		01000H
#Define BIF_BROWSEFORPRINTER   		02000H
#Define BIF_BROWSEINCLUDEFILES 		04000H

#Define BFFM_INITIALIZED        	1
#Define BFFM_SELCHANGED         	2
#Define BFFM_VALIDATEFAILEDA    	3
#Define BFFM_VALIDATEFAILEDW    	4

#Define BFFM_SETSTATUSTEXTA     	(WM_USER + 100)
#Define BFFM_ENABLEOK           	(WM_USER + 101)
#Define BFFM_SETSELECTIONA      	(WM_USER + 102)
#Define BFFM_SETSELECTIONW      	(WM_USER + 103)
#Define BFFM_SETSTATUSTEXTW     	(WM_USER + 104)

;SHGNO enumeration
SHGDN_NORMAL            			Equ 0
SHGDN_INFOLDER						Equ 1
SHGDN_INCLUDE_NONFILESYS			Equ 02000H
SHGDN_FORADDRESSBAR					Equ 04000H
SHGDN_FORPARSING					Equ 08000H

;SHCONTF enumeration
SHCONTF_FOLDERS         			Equ 2
SHCONTF_NONFOLDERS      			Equ 64
SHCONTF_INCLUDEHIDDEN   			Equ 128

#Define SFGAO_CANCOPY           	DROPEFFECT_COPY
#Define SFGAO_CANMOVE           	DROPEFFECT_MOVE
#Define SFGAO_CANLINK           	DROPEFFECT_LINK
#Define SFGAO_CANRENAME         	000000010H
#Define SFGAO_CANDELETE         	000000020H
#Define SFGAO_HASPROPSHEET      	000000040H
#Define SFGAO_DROPTARGET        	000000100H
#Define SFGAO_CAPABILITYMASK    	000000177H
#Define SFGAO_LINK              	000010000H
#Define SFGAO_SHARE             	000020000H
#Define SFGAO_READONLY          	000040000H
#Define SFGAO_GHOSTED           	000080000H
#Define SFGAO_HIDDEN            	000080000H
#Define SFGAO_DISPLAYATTRMASK   	0000F0000H
#Define SFGAO_FILESYSANCESTOR   	010000000H
#Define SFGAO_FOLDER            	020000000H
#Define SFGAO_FILESYSTEM        	040000000H
#Define SFGAO_HASSUBFOLDER      	080000000H
#Define SFGAO_CONTENTSMASK      	080000000H
#Define SFGAO_VALIDATE          	001000000H
#Define SFGAO_REMOVABLE         	002000000H
#Define SFGAO_COMPRESSED        	004000000H
#Define SFGAO_BROWSABLE         	008000000H
#Define SFGAO_NONENUMERATED     	000100000H
#Define SFGAO_NEWCONTENT        	000200000H

#Define DWFRF_NORMAL            	00000H
#Define DWFRF_DELETECONFIGDATA  	00001H

#Define DWFAF_HIDDEN  				00001H

#Define DBIM_MINSIZE    			00001H
#Define DBIM_MAXSIZE    			00002H
#Define DBIM_INTEGRAL   			00004H
#Define DBIM_ACTUAL     			00008H
#Define DBIM_TITLE      			00010H
#Define DBIM_MODEFLAGS  			00020H
#Define DBIM_BKCOLOR    			00040H

#Define DBIMF_NORMAL            	00000H
#Define DBIMF_VARIABLEHEIGHT    	00008H
#Define DBIMF_DEBOSSED          	00020H
#Define DBIMF_BKCOLOR           	00040H

#Define DBIF_VIEWMODE_NORMAL        00000H
#Define DBIF_VIEWMODE_VERTICAL      00001H
#Define DBIF_VIEWMODE_FLOATING      00002H
#Define DBIF_VIEWMODE_TRANSPARENT   00004H

;enumeration
DBID_BANDINFOCHANGED				Equ 0
DBID_SHOWONLY						Equ 1
DBID_MAXIMIZEBAND					Equ 2

#Define COMPONENT_TOP 				07FFFFFFFH

#Define COMP_TYPE_HTMLDOC       	0
#Define COMP_TYPE_PICTURE       	1
#Define COMP_TYPE_WEBSITE       	2
#Define COMP_TYPE_CONTROL       	3
#Define COMP_TYPE_CFHTML        	4
#Define COMP_TYPE_MAX           	4

#Define AD_APPLY_SAVE         		000000001H
#Define AD_APPLY_HTMLGEN      		000000002H
#Define AD_APPLY_REFRESH      		000000004H
#Define AD_APPLY_ALL     			(AD_APPLY_SAVE | AD_APPLY_HTMLGEN | AD_APPLY_REFRESH)
#Define AD_APPLY_FORCE        		000000008H
#Define AD_APPLY_BUFFERED_REFRESH 	000000010H

#Define WPSTYLE_CENTER      		0
#Define WPSTYLE_TILE        		1
#Define WPSTYLE_STRETCH     		2
#Define WPSTYLE_MAX         		3

#Define COMP_ELEM_TYPE          	000000001H
#Define COMP_ELEM_CHECKED       	000000002H
#Define COMP_ELEM_DIRTY         	000000004H
#Define COMP_ELEM_NOSCROLL      	000000008H
#Define COMP_ELEM_POS_LEFT      	000000010H
#Define COMP_ELEM_POS_TOP       	000000020H
#Define COMP_ELEM_SIZE_WIDTH    	000000040H
#Define COMP_ELEM_SIZE_HEIGHT   	000000080H
#Define COMP_ELEM_POS_ZINDEX    	000000100H
#Define COMP_ELEM_SOURCE        	000000200H
#Define COMP_ELEM_FRIENDLYNAME  	000000400H
#Define COMP_ELEM_SUBSCRIBEDURL 	000000800H

#Define COMP_ELEM_ALL				(COMP_ELEM_TYPE | COMP_ELEM_CHECKED | COMP_ELEM_DIRTY | COMP_ELEM_NOSCROLL | COMP_ELEM_POS_LEFT | COMP_ELEM_SIZE_WIDTH | COMP_ELEM_SIZE_HEIGHT | COMP_ELEM_POS_ZINDEX | COMP_ELEM_SOURCE | COMP_ELEM_FRIENDLYNAME)

;enumeration
DTI_ADDUI_DEFAULT					Equ 000000000H
DTI_ADDUI_DISPSUBWIZARD				Equ 000000001H

#Define ADDURL_SILENT           	00001H

#Define CFSTR_SHELLIDLIST       	TEXT("Shell IDList Array")
#Define CFSTR_SHELLIDLISTOFFSET 	TEXT("Shell Object Offsets")
#Define CFSTR_NETRESOURCES      	TEXT("Net Resource")
#Define CFSTR_FILECONTENTS      	TEXT("FileContents")
#Define CFSTR_PRINTERGROUP      	TEXT("PrinterFriendlyName")
#Define CFSTR_SHELLURL          	TEXT("UniformResourceLocator")
#Define CFSTR_PREFERREDDROPEFFECT	TEXT("Preferred DropEffect")
#Define CFSTR_PERFORMEDDROPEFFECT	TEXT("Performed DropEffect")
#Define CFSTR_PASTESUCCEEDED    	TEXT("Paste Succeeded")
#Define CFSTR_INDRAGLOOP        	TEXT("InShellDragLoop")

#Define CFSTR_FILEDESCRIPTORA   	"FileGroupDescriptor"
#Define CFSTR_FILENAMEA         	"FileName"
#Define CFSTR_FILENAMEMAPA      	"FileNameMap"
#Define CFSTR_FILEDESCRIPTORW   	L"FileGroupDescriptorW"
#Define CFSTR_FILENAMEW         	L"FileNameW"
#Define CFSTR_FILENAMEMAPW      	L"FileNameMapW"

#IF STRINGS UNICODE
	#Define CFSTR_FILEDESCRIPTOR	   	CFSTR_FILEDESCRIPTORW
	#Define CFSTR_FILENAME         		CFSTR_FILENAMEW
	#Define CFSTR_FILENAMEMAP      		CFSTR_FILENAMEMAPW
#ELSE
	#Define CFSTR_FILEDESCRIPTOR	   	CFSTR_FILEDESCRIPTORA
	#Define CFSTR_FILENAME         		CFSTR_FILENAMEA
	#Define CFSTR_FILENAMEMAP	      	CFSTR_FILENAMEMAPA
#ENDIF

#Define CMDSTR_NEWFOLDERA   		"NewFolder"
#Define CMDSTR_VIEWLISTA    		"ViewList"
#Define CMDSTR_VIEWDETAILSA 		"ViewDetails"
#Define CMDSTR_NEWFOLDERW   		L"NewFolder"
#Define CMDSTR_VIEWLISTW    		L"ViewList"
#Define CMDSTR_VIEWDETAILSW 		L"ViewDetails"

#IF STRINGS UNICODE
	#Define CMDSTR_NEWFOLDER    		CMDSTR_NEWFOLDERW
	#Define CMDSTR_VIEWLIST     		CMDSTR_VIEWLISTW
	#Define CMDSTR_VIEWDETAILS  		CMDSTR_VIEWDETAILSW
#ELSE
	#Define CMDSTR_NEWFOLDER    		CMDSTR_NEWFOLDERA
	#Define CMDSTR_VIEWLIST     		CMDSTR_VIEWLISTA
	#Define CMDSTR_VIEWDETAILS  		CMDSTR_VIEWDETAILSA
#ENDIF

;FD_FLAGS enumeration
FD_CLSID							Equ 00001H
FD_SIZEPOINT						Equ 00002H
FD_ATTRIBUTES						Equ 00004H
FD_CREATETIME						Equ 00008H
FD_ACCESSTIME						Equ 00010H
FD_WRITESTIME						Equ 00020H
FD_FILESIZE							Equ 00040H
FD_LINKUI							Equ 08000H

#Define SHCNE_RENAMEITEM          	000000001H
#Define SHCNE_CREATE              	000000002H
#Define SHCNE_DELETE              	000000004H
#Define SHCNE_MKDIR               	000000008H
#Define SHCNE_RMDIR               	000000010H
#Define SHCNE_MEDIAINSERTED       	000000020H
#Define SHCNE_MEDIAREMOVED        	000000040H
#Define SHCNE_DRIVEREMOVED        	000000080H
#Define SHCNE_DRIVEADD            	000000100H
#Define SHCNE_NETSHARE            	000000200H
#Define SHCNE_NETUNSHARE          	000000400H
#Define SHCNE_ATTRIBUTES          	000000800H
#Define SHCNE_UPDATEDIR           	000001000H
#Define SHCNE_UPDATEITEM          	000002000H
#Define SHCNE_SERVERDISCONNECT    	000004000H
#Define SHCNE_UPDATEIMAGE         	000008000H
#Define SHCNE_DRIVEADDGUI         	000010000H
#Define SHCNE_RENAMEFOLDER        	000020000H
#Define SHCNE_FREESPACE           	000040000H

#Define SHCNE_EXTENDED_EVENT      	004000000H

#Define SHCNE_ASSOCCHANGED        	008000000H

#Define SHCNE_DISKEVENTS          	00002381FH
#Define SHCNE_GLOBALEVENTS        	00C0581E0H
#Define SHCNE_ALLEVENTS           	07FFFFFFFH
#Define SHCNE_INTERRUPT           	080000000H

#Define SHCNEE_ORDERCHANGED       	000000002H

#Define SHCNF_IDLIST      			00000H
#Define SHCNF_PATHA       			00001H
#Define SHCNF_PRINTERA    			00002H
#Define SHCNF_DWORD       			00003H
#Define SHCNF_PATHW       			00005H
#Define SHCNF_PRINTERW    			00006H
#Define SHCNF_TYPE        			000FFH
#Define SHCNF_FLUSH       			01000H
#Define SHCNF_FLUSHNOWAIT 			02000H

#Define QIF_CACHED           		000000001H
#Define QIF_DONTEXPANDFOLDER 		000000002H

#Define SHARD_PIDL      			000000001H
#Define SHARD_PATHA     			000000002H
#Define SHARD_PATHW     			000000003H

#Define SHGDFIL_FINDDATA        	1
#Define SHGDFIL_NETRESOURCE     	2
#Define SHGDFIL_DESCRIPTIONID   	3

#Define SHDID_ROOT_REGITEM          1
#Define SHDID_FS_FILE               2
#Define SHDID_FS_DIRECTORY          3
#Define SHDID_FS_OTHER              4
#Define SHDID_COMPUTER_DRIVE35      5
#Define SHDID_COMPUTER_DRIVE525     6
#Define SHDID_COMPUTER_REMOVABLE    7
#Define SHDID_COMPUTER_FIXED        8
#Define SHDID_COMPUTER_NETDRIVE     9
#Define SHDID_COMPUTER_CDROM        10
#Define SHDID_COMPUTER_RAMDISK      11
#Define SHDID_COMPUTER_OTHER        12
#Define SHDID_NET_DOMAIN            13
#Define SHDID_NET_SERVER            14
#Define SHDID_NET_SHARE             15
#Define SHDID_NET_RESTOFNET         16
#Define SHDID_NET_OTHER             17

#Define PID_IS_URL           		2
#Define PID_IS_NAME          		4
#Define PID_IS_WORKINGDIR    		5
#Define PID_IS_HOTKEY        		6
#Define PID_IS_SHOWCMD       		7
#Define PID_IS_ICONINDEX     		8
#Define PID_IS_ICONFILE      		9
#Define PID_IS_WHATSNEW      		10
#Define PID_IS_AUTHOR        		11
#Define PID_IS_DESCRIPTION   		12
#Define PID_IS_COMMENT       		13

#Define PID_INTSITE_WHATSNEW      	2
#Define PID_INTSITE_AUTHOR        	3
#Define PID_INTSITE_LASTVISIT     	4
#Define PID_INTSITE_LASTMOD       	5
#Define PID_INTSITE_VISITCOUNT    	6
#Define PID_INTSITE_DESCRIPTION   	7
#Define PID_INTSITE_COMMENT       	8
#Define PID_INTSITE_FLAGS         	9
#Define PID_INTSITE_CONTENTLEN    	10
#Define PID_INTSITE_CONTENTCODE   	11
#Define PID_INTSITE_RECURSE       	12
#Define PID_INTSITE_WATCH         	13
#Define PID_INTSITE_SUBSCRIPTION  	14
#Define PID_INTSITE_URL           	15
#Define PID_INTSITE_TITLE         	16
#Define PID_INTSITE_CODEPAGE      	18
#Define PID_INTSITE_TRACKING      	19

#Define PIDISF_RECENTLYCHANGED  	000000001H
#Define PIDISF_CACHEDSTICKY     	000000002H
#Define PIDISF_CACHEIMAGES      	000000010H
#Define PIDISF_FOLLOWALLLINKS   	000000020H

#Define PIDISM_GLOBAL           	0
#Define PIDISM_WATCH            	1
#Define PIDISM_DONTWATCH        	2

#Define SSF_SHOWALLOBJECTS          00001H
#Define SSF_SHOWEXTENSIONS          00002H
#Define SSF_SHOWCOMPCOLOR           00008H
#Define SSF_SHOWSYSFILES            00020H
#Define SSF_DOUBLECLICKINWEBVIEW    00080H
#Define SSF_SHOWATTRIBCOL           00100H
#Define SSF_DESKTOPHTML             00200H
#Define SSF_WIN95CLASSIC            00400H
#Define SSF_DONTPRETTYPATH          00800H
#Define SSF_SHOWINFOTIP             02000H
#Define SSF_MAPNETDRVBUTTON         01000H
#Define SSF_NOCONFIRMRECYCLE        08000H
#Define SSF_HIDEICONS               04000H


SHITEMID Struct
	cb  DW
	abID DB
EndS

ITEMIDLIST Struct
	mkid SHITEMID <>
EndS

CMINVOKECOMMANDINFO Struct
	cbSize DD
	fMask DD
	hwnd DD
	lpVerb DD
	lpParameters DD
	lpDirectory DD
	nShow DD
	dwHotKey DD
	hIcon DD
EndS

CMINVOKECOMMANDINFOEX Struct
	cbSize DD
	fMask DD
	hwnd DD
	lpVerb DD
	lpParameters DD
	lpDirectory DD
	nShow DD
	dwHotKey DD
	hIcon DD
	lpTitle DD
	lpVerbW DD
	lpParametersW DD
	lpDirectoryW DD
	lpTitleW DD
	ptInvoke POINT <>
EndS

FVSHOWINFO Struct
	cbSize DD
	hwndOwner DD
	iShow DD
	dwFlags DD
	rect RECT<>
	punkRel DD
    strNewFile DW MAX_PATH Dup ?
EndS

FOLDERSETTINGS Struct
	ViewMode DD
	fFlags DD
EndS

SV2CVW2_PARAMS Struct
	cbSize DD
	psvPrev DD
	pfs DD
	psbOwner DD
	prcView DD
	pvid DD
	hwndView DD
EndS

STRRET Struct
	uType DD
	DUMMYUNIONNAME Union
		pOleStr DD
		pStr DD
		uOffset DD
		cStr DB MAX_PATH Dup ?
    EndUnion
EndS

BROWSEINFOA Struct
	hwndOwner DD
	pidlRoot DD
	pszDisplayName DD
	lpszTitle DD
	ulFlags DD
	lpfn DD
	lParam DD
	iImage DD
EndS

BROWSEINFOW Struct
	hwndOwner DD
	pidlRoot DD
	pszDisplayName DD
	lpszTitle DD
	ulFlags DD
	lpfn DD
	lParam DD
	iImage DD
EndS

DESKBANDINFO Struct
	dwMask DD
	ptMinSize POINTL <>
	ptMaxSize POINTL <>
	ptIntegral POINTL <>
	ptActual POINTL <>
	wszTitle DW 256 Dup ?
	dwModeFlags DD
	crBkgnd DD
EndS

WALLPAPEROPT Struct
	dwSize DD
	dwStyle DD
EndS

COMPONENTSOPT Struct
	dwSize DD
	fEnableComponents DD
	fActiveDesktop DD
EndS

COMPPOS Struct
	dwSize DD
	iLeft DD
	iTop DD
	dwWidth DD
	dwHeight DD
	izIndex DD
	fCanResize DD
	fCanResizeX DD
	fCanResizeY DD
	iPreferredLeftPercent DD
	iPreferredTopPercent DD
EndS

COMPONENT Struct
	dwSize DD
	dwID DD
	iComponentType DD
	fChecked DD
	fDirty DD
	fNoScroll DD
	cpPos COMPPOS <>
	wszFriendlyName DW MAX_PATH Dup ?
	wszSource DW INTERNET_MAX_URL_LENGTH Dup ?
	wszSubscribedURL DW INTERNET_MAX_URL_LENGTH Dup ?
EndS

NRESARRAY Struct
	cItems DD
	nr NETRESOURCE <>
EndS

CIDA Struct
	cidl DD
	aoffset DD
EndS

FILEDESCRIPTORA Struct
	dwFlags DD
	clsid GUID <>
	sizel SIZEL <>
	pointl POINTL <>
	dwFileAttributes DD
	ftCreationTime FILETIME <>
	ftLastAccessTime FILETIME <>
	ftLastWriteTime FILETIME <>
	nFileSizeHigh DD
	nFileSizeLow DD
	cFileName DB MAX_PATH Dup ?
EndS

FILEDESCRIPTORW Struct
	dwFlags DD
	clsid GUID <>
	sizel SIZEL <>
	pointl POINTL <>
	dwFileAttributes DD
	ftCreationTime FILETIME <>
	ftLastAccessTime FILETIME <>
	ftLastWriteTime FILETIME <>
	nFileSizeHigh DD
	nFileSizeLow DD
	cFileName DW MAX_PATH Dup ?
EndS

FILEGROUPDESCRIPTORA Struct
	cItems DD
	fgd FILEDESCRIPTORA <>
EndS

FILEGROUPDESCRIPTORW Struct
	cItems DD
	fgd FILEDESCRIPTORW <>
EndS

DROPFILES Struct
	pFiles DD
	pt POINT <>
	fNC DD
	fWide DD
EndS

SHDESCRIPTIONID Struct
	dwDescriptionId DD
	clsid GUID <>
EndS

SHELLFLAGSTATE Struct
	usFlags DD
EndS


#IF STRINGS UNICODE
	#Define GCS_VERB GCS_VERBW
	#Define GCS_HELPTEXT GCS_HELPTEXTW
	#Define GCS_VALIDATE GCS_VALIDATEW
	#Define CMDSTR_NEWFOLDER CMDSTR_NEWFOLDERW
	#Define CMDSTR_VIEWLIST CMDSTR_VIEWLISTW
	#Define CMDSTR_VIEWDETAILS CMDSTR_VIEWDETAILSW
	#Define IExtractIcon IExtractIconW
	#Define IShellLink IShellLinkW
	#Define IShellExecuteHook IShellExecuteHookW
	#Define INewShortcutHook INewShortcutHookW
	#Define ICopyHook ICopyHookW
	#Define IFileViewer IFileViewerW
	#Define SHGetPathFromIDList SHGetPathFromIDListW
	#Define SHGetSpecialFolderPath SHGetSpecialFolderPathW
	#Define BROWSEINFO BROWSEINFOW
	#Define SHBrowseForFolder SHBrowseForFolderW
	#Define CFSTR_FILEDESCRIPTOR CFSTR_FILEDESCRIPTORW
	#Define CFSTR_FILENAME CFSTR_FILENAMEW
	#Define CFSTR_FILENAMEMAP CFSTR_FILENAMEMAPW
	#Define FILEDESCRIPTOR FILEDESCRIPTORW
	#Define FILEGROUPDESCRIPTOR FILEGROUPDESCRIPTORW
	#Define SHCNF_PATH SHCNF_PATHW
	#Define SHCNF_PRINTER SHCNF_PRINTERW
	#Define SHARD_PATH SHARD_PATHW
	#Define SHGetDataFromIDList SHGetDataFromIDListW
#ELSE
	#Define GCS_VERB GCS_VERBA
	#Define GCS_HELPTEXT GCS_HELPTEXTA
	#Define GCS_VALIDATE GCS_VALIDATEA
	#Define CMDSTR_NEWFOLDER CMDSTR_NEWFOLDERA
	#Define CMDSTR_VIEWLIST CMDSTR_VIEWLISTA
	#Define CMDSTR_VIEWDETAILS CMDSTR_VIEWDETAILSA
	#Define IExtractIcon IExtractIconA
	#Define IShellLink IShellLinkA
	#Define IShellExecuteHook IShellExecuteHookA
	#Define INewShortcutHook INewShortcutHookA
	#Define ICopyHook ICopyHookA
	#Define IFileViewer IFileViewerA
	#Define SHGetPathFromIDList SHGetPathFromIDListA
	#Define SHGetSpecialFolderPath SHGetSpecialFolderPathA
	#Define BROWSEINFO BROWSEINFOA
	#Define SHBrowseForFolder SHBrowseForFolderA
	#Define CFSTR_FILEDESCRIPTOR CFSTR_FILEDESCRIPTORA
	#Define CFSTR_FILENAME CFSTR_FILENAMEA
	#Define CFSTR_FILENAMEMAP CFSTR_FILENAMEMAPA
	#Define FILEDESCRIPTOR FILEDESCRIPTORA
	#Define FILEGROUPDESCRIPTOR FILEGROUPDESCRIPTORA
	#Define SHCNF_PATH SHCNF_PATHA
	#Define SHCNF_PRINTER SHCNF_PRINTERA
	#Define SHARD_PATH SHARD_PATHA
	#Define SHGetDataFromIDList SHGetDataFromIDListA
#ENDIF

#ENDIF ;SHLOBJ
