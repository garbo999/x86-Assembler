;=============================================================;
;         commctrl.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                (modified on November, 2007)                 ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF COMMCTRL_INC
#Define COMMCTRL_INC

#IFNDEF PRSHT_INC
	#Include <prsht.inc>
#ENDIF

#Define ICC_LISTVIEW_CLASSES	000000001H
#Define ICC_TREEVIEW_CLASSES	000000002H
#Define ICC_BAR_CLASSES			000000004H
#Define ICC_TAB_CLASSES			000000008H
#Define ICC_UPDOWN_CLASS		000000010H
#Define ICC_PROGRESS_CLASS		000000020H
#Define ICC_HOTKEY_CLASS		000000040H
#Define ICC_ANIMATE_CLASS		000000080H
#Define ICC_WIN95_CLASSES		0000000FFH
#Define ICC_DATE_CLASSES		000000100H
#Define ICC_USEREX_CLASSES		000000200H
#Define ICC_COOL_CLASSES		000000400H
#Define ICC_INTERNET_CLASSES	000000800H
#Define ICC_PAGESCROLLER_CLASS	000001000H
#Define ICC_NATIVEFNTCTL_CLASS	000002000H

#Define ODT_HEADER				100
#Define ODT_TAB					101
#Define ODT_LISTVIEW			102

#Define LVM_FIRST				01000H
#Define TV_FIRST				01100H
#Define HDM_FIRST				01200H
#Define TCM_FIRST				01300H

#Define PGM_FIRST				01400H
#Define CCM_FIRST				02000H

#Define CCM_SETBKCOLOR			(CCM_FIRST + 1)

#Define CCM_SETCOLORSCHEME		(CCM_FIRST + 2)
#Define CCM_GETCOLORSCHEME		(CCM_FIRST + 3)
#Define CCM_GETDROPTARGET		(CCM_FIRST + 4)
#Define CCM_SETUNICODEFORMAT	(CCM_FIRST + 5)
#Define CCM_GETUNICODEFORMAT	(CCM_FIRST + 6)

#Define INFOTIPSIZE				1024

#Define NM_OUTOFMEMORY			(NM_FIRST - 1)
#Define NM_CLICK				(NM_FIRST - 2)
#Define NM_DBLCLK				(NM_FIRST - 3)
#Define NM_RETURN				(NM_FIRST - 4)
#Define NM_RCLICK				(NM_FIRST - 5)
#Define NM_RDBLCLK				(NM_FIRST - 6)
#Define NM_SETFOCUS				(NM_FIRST - 7)
#Define NM_KILLFOCUS			(NM_FIRST - 8)
#Define NM_CUSTOMDRAW			(NM_FIRST - 12)
#Define NM_HOVER				(NM_FIRST - 13)
#Define NM_NCHITTEST			(NM_FIRST - 14)
#Define NM_KEYDOWN				(NM_FIRST - 15)
#Define NM_RELEASEDCAPTURE		(NM_FIRST - 16)
#Define NM_SETCURSOR			(NM_FIRST - 17)
#Define NM_CHAR					(NM_FIRST - 18)
#Define NMCLICK					NMMOUSE

#Define NM_FIRST				0
#Define NM_LAST					(-99)

#Define LVN_FIRST				(-100)
#Define LVN_LAST				(-199)

#Define HDN_FIRST				(-300)
#Define HDN_LAST				(-399)

#Define TVN_FIRST				(-400)
#Define TVN_LAST				(-499)

#Define TTN_FIRST				(-520)
#Define TTN_LAST				(-549)

#Define TCN_FIRST				(-550)
#Define TCN_LAST				(-580)

#Define CDN_FIRST				(-601)
#Define CDN_LAST				(-699)

#Define TBN_FIRST				(-700)
#Define TBN_LAST				(-720)

#Define UDN_FIRST				(-721)
#Define UDN_LAST				(-740)

#Define MCN_FIRST				(-750)
#Define MCN_LAST				(-759)

#Define DTN_FIRST				(-760)
#Define DTN_LAST				(-799)

#Define CBEN_FIRST				(-800)
#Define CBEN_LAST				(-830)

#Define RBN_FIRST				(-831)
#Define RBN_LAST				(-859)

#Define IPN_FIRST				(-860)
#Define IPN_LAST				(-879)

#Define SBN_FIRST				(-880)
#Define SBN_LAST				(-899)

#Define PGN_FIRST				(-900)
#Define PGN_LAST				(-950)

#Define MSGF_COMMCTRL_BEGINDRAG		04200H
#Define MSGF_COMMCTRL_SIZEHEADER	04201H
#Define MSGF_COMMCTRL_DRAGSELECT	04202H
#Define MSGF_COMMCTRL_TOOLBARCUST	04203H

#Define CDRF_DODEFAULT			000000000H
#Define CDRF_NEWFONT			000000002H
#Define CDRF_SKIPDEFAULT		000000004H

#Define CDRF_NOTIFYPOSTPAINT	000000010H
#Define CDRF_NOTIFYITEMDRAW		000000020H
#Define CDRF_NOTIFYSUBITEMDRAW	000000020H
#Define CDRF_NOTIFYPOSTERASE	000000040H

#Define CDDS_PREPAINT			000000001H
#Define CDDS_POSTPAINT			000000002H
#Define CDDS_PREERASE			000000003H
#Define CDDS_POSTERASE			000000004H

#Define CDDS_ITEM				000010000H
#Define CDDS_ITEMPREPAINT		(CDDS_ITEM | CDDS_PREPAINT)
#Define CDDS_ITEMPOSTPAINT		(CDDS_ITEM | CDDS_POSTPAINT)
#Define CDDS_ITEMPREERASE		(CDDS_ITEM | CDDS_PREERASE)
#define CDDS_ITEMPOSTERASE		(CDDS_ITEM | CDDS_POSTERASE)
#Define CDDS_SUBITEM			000020000H

#Define CDIS_SELECTED			00001H
#Define CDIS_GRAYED				00002H
#Define CDIS_DISABLED			00004H
#Define CDIS_CHECKED			00008H
#Define CDIS_FOCUS				00010H
#Define CDIS_DEFAULT			00020H
#Define CDIS_HOT				00040H
#Define CDIS_MARKED				00080H
#Define CDIS_INDETERMINATE		00100H

#Define CLR_NONE				0FFFFFFFFH
#Define CLR_DEFAULT				0FF000000H

#Define ILC_MASK				00001H
#Define ILC_COLOR				00000H
#Define ILC_COLORDDB			000FEH
#Define ILC_COLOR4				00004H
#Define ILC_COLOR8				00008H
#Define ILC_COLOR16				00010H
#Define ILC_COLOR24				00018H
#Define ILC_COLOR32				00020H
#Define ILC_PALETTE				00800H

#Define ILD_NORMAL				00000H
#Define ILD_TRANSPARENT			00001H
#Define ILD_MASK				00010H
#Define ILD_IMAGE				00020H
#Define ILD_ROP					00040H
#Define ILD_BLEND25				00002H
#Define ILD_BLEND50				00004H
#Define ILD_OVERLAYMASK			00F00H

#Define ILD_SELECTED			ILD_BLEND50
#Define ILD_FOCUS				ILD_BLEND25
#Define ILD_BLEND				ILD_BLEND50
#Define CLR_HILIGHT				CLR_DEFAULT

#Define ILCF_MOVE				000000000H
#Define ILCF_SWAP   			000000001H

#Define WC_HEADERA				"SysHeader32"
#Define WC_HEADERW				L"SysHeader32"

#Define HDS_HORZ                00000H
#Define HDS_BUTTONS             00002H
#Define HDS_HOTTRACK            00004H
#Define HDS_HIDDEN              00008H

#Define HDS_DRAGDROP            00040H
#Define HDS_FULLDRAG            00080H

#Define HD_ITEMA HDITEMA
#Define HD_ITEMW HDITEMW

#Define HDI_WIDTH               00001H
#Define HDI_HEIGHT              HDI_WIDTH
#Define HDI_TEXT                00002H
#Define HDI_FORMAT              00004H
#Define HDI_LPARAM              00008H
#Define HDI_BITMAP              00010H
#Define HDI_IMAGE               00020H
#Define HDI_DI_SETITEM          00040H
#Define HDI_ORDER               00080H

#Define HDF_LEFT                0
#Define HDF_RIGHT               1
#Define HDF_CENTER              2
#Define HDF_JUSTIFYMASK         00003H
#Define HDF_RTLREADING          4

#Define HDF_OWNERDRAW           08000H
#Define HDF_STRING              04000H
#Define HDF_BITMAP              02000H
#Define HDF_BITMAP_ON_RIGHT     01000H
#Define HDF_IMAGE               00800H

#Define HDM_GETITEMCOUNT        (HDM_FIRST + 0)

#Define HDM_INSERTITEMA         (HDM_FIRST + 1)
#Define HDM_INSERTITEMW         (HDM_FIRST + 10)

#Define HDM_DELETEITEM          (HDM_FIRST + 2)

#Define HDM_GETITEMA            (HDM_FIRST + 3)
#Define HDM_GETITEMW            (HDM_FIRST + 11)

#Define HDM_SETITEMA            (HDM_FIRST + 4)
#Define HDM_SETITEMW            (HDM_FIRST + 12)

#Define HD_LAYOUT				HDLAYOUT

#Define HDM_LAYOUT              (HDM_FIRST + 5)

#Define HHT_NOWHERE             00001H
#Define HHT_ONHEADER            00002H
#Define HHT_ONDIVIDER           00004H
#Define HHT_ONDIVOPEN           00008H
#Define HHT_ABOVE               00100H
#Define HHT_BELOW               00200H
#Define HHT_TORIGHT             00400H
#Define HHT_TOLEFT              00800H

#Define HD_HITTESTINFO			HDHITTESTINFO

#Define HDM_HITTEST             (HDM_FIRST + 6)
#Define HDM_GETITEMRECT			(HDM_FIRST + 7)
#Define HDM_SETIMAGELIST        (HDM_FIRST + 8)
#Define HDM_GETIMAGELIST        (HDM_FIRST + 9)
#Define HDM_ORDERTOINDEX        (HDM_FIRST + 15)
#Define HDM_CREATEDRAGIMAGE     (HDM_FIRST + 16)
#Define HDM_GETORDERARRAY       (HDM_FIRST + 17)
#Define HDM_SETORDERARRAY       (HDM_FIRST + 18)
#Define HDM_SETHOTDIVIDER       (HDM_FIRST + 19)
#Define HDM_SETUNICODEFORMAT    CCM_SETUNICODEFORMAT
#Define HDM_GETUNICODEFORMAT    CCM_GETUNICODEFORMAT

#Define HDN_ITEMCHANGINGA       (HDN_FIRST - 0)
#Define HDN_ITEMCHANGINGW       (HDN_FIRST - 20)
#Define HDN_ITEMCHANGEDA		(HDN_FIRST - 1)
#Define HDN_ITEMCHANGEDW        (HDN_FIRST - 21)
#Define HDN_ITEMCLICKA			(HDN_FIRST - 2)
#Define HDN_ITEMCLICKW          (HDN_FIRST - 22)
#Define HDN_ITEMDBLCLICKA		(HDN_FIRST - 3)
#Define HDN_ITEMDBLCLICKW       (HDN_FIRST - 23)
#Define HDN_DIVIDERDBLCLICKA	(HDN_FIRST - 5)
#Define HDN_DIVIDERDBLCLICKW    (HDN_FIRST - 25)
#Define HDN_BEGINTRACKA			(HDN_FIRST - 6)
#Define HDN_BEGINTRACKW         (HDN_FIRST - 26)
#Define HDN_ENDTRACKA			(HDN_FIRST - 7)
#Define HDN_ENDTRACKW           (HDN_FIRST - 27)
#Define HDN_TRACKA				(HDN_FIRST - 8)
#Define HDN_TRACKW              (HDN_FIRST - 28)
#Define HDN_GETDISPINFOA		(HDN_FIRST - 9)
#Define HDN_GETDISPINFOW		(HDN_FIRST - 29)
#Define HDN_BEGINDRAG			(HDN_FIRST - 10)
#Define HDN_ENDDRAG				(HDN_FIRST - 11)

#Define HDN_GETDISPINFO         HDN_GETDISPINFOA

#Define HD_NOTIFYA              NMHEADERA
#Define HD_NOTIFYW              NMHEADERW
#Define HD_NOTIFY               NMHEADER

#Define TOOLBARCLASSNAMEW       L"ToolbarWindow32"
#Define TOOLBARCLASSNAMEA       "ToolbarWindow32"

#Define CMB_MASKED              002H

#Define TBSTATE_CHECKED         001H
#Define TBSTATE_PRESSED         002H
#Define TBSTATE_ENABLED         004H
#Define TBSTATE_HIDDEN          008H
#Define TBSTATE_INDETERMINATE   010H
#Define TBSTATE_WRAP            020H
#Define TBSTATE_ELLIPSES        040H
#Define TBSTATE_MARKED          080H

#Define TBSTYLE_BUTTON          00000H
#Define TBSTYLE_SEP             00001H
#Define TBSTYLE_CHECK           00002H
#Define TBSTYLE_GROUP           00004H
#Define TBSTYLE_CHECKGROUP      (TBSTYLE_GROUP | TBSTYLE_CHECK)
#Define TBSTYLE_DROPDOWN        00008H
#Define TBSTYLE_AUTOSIZE        00010H
#Define TBSTYLE_NOPREFIX        00020H

#Define TBSTYLE_TOOLTIPS        00100H
#Define TBSTYLE_WRAPABLE        00200H
#Define TBSTYLE_ALTDRAG         00400H
#Define TBSTYLE_FLAT            00800H
#Define TBSTYLE_LIST            01000H
#Define TBSTYLE_CUSTOMERASE     02000H
#Define TBSTYLE_REGISTERDROP    04000H
#Define TBSTYLE_TRANSPARENT     08000H
#Define TBSTYLE_EX_DRAWDDARROWS 000000001H

#Define TBCDRF_NOEDGES			000010000H
#Define TBCDRF_HILITEHOTTRACK	000020000H
#Define TBCDRF_NOOFFSET			000040000H
#Define TBCDRF_NOMARK			000080000H
#Define TBCDRF_NOETCHEDEFFECT	000100000H

#Define TB_ENABLEBUTTON         (WM_USER + 1)
#Define TB_CHECKBUTTON          (WM_USER + 2)
#Define TB_PRESSBUTTON          (WM_USER + 3)
#Define TB_HIDEBUTTON           (WM_USER + 4)
#Define TB_INDETERMINATE        (WM_USER + 5)
#Define TB_MARKBUTTON			(WM_USER + 6)
#Define TB_ISBUTTONENABLED      (WM_USER + 9)
#Define TB_ISBUTTONCHECKED      (WM_USER + 10)
#Define TB_ISBUTTONPRESSED      (WM_USER + 11)
#Define TB_ISBUTTONHIDDEN       (WM_USER + 12)
#Define TB_ISBUTTONINDETERMINATE (WM_USER + 13)
#Define TB_ISBUTTONHIGHLIGHTED	(WM_USER + 14)
#Define TB_SETSTATE             (WM_USER + 17)
#Define TB_GETSTATE             (WM_USER + 18)
#Define TB_ADDBITMAP            (WM_USER + 19)

#Define HINST_COMMCTRL          (-1)
#Define IDB_STD_SMALL_COLOR     0
#Define IDB_STD_LARGE_COLOR     1
#Define IDB_VIEW_SMALL_COLOR    4
#Define IDB_VIEW_LARGE_COLOR    5
#Define IDB_HIST_SMALL_COLOR    8
#Define IDB_HIST_LARGE_COLOR    9

#Define STD_CUT                 0
#Define STD_COPY                1
#Define STD_PASTE               2
#Define STD_UNDO                3
#Define STD_REDOW               4
#Define STD_DELETE              5
#Define STD_FILENEW             6
#Define STD_FILEOPEN            7
#Define STD_FILESAVE            8
#Define STD_PRINTPRE            9
#Define STD_PROPERTIES          10
#Define STD_HELP                11
#Define STD_FIND                12
#Define STD_REPLACE             13
#Define STD_PRINT               14

#Define VIEW_LARGEICONS         0
#Define VIEW_SMALLICONS         1
#Define VIEW_LIST               2
#Define VIEW_DETAILS            3
#Define VIEW_SORTNAME           4
#Define VIEW_SORTSIZE           5
#Define VIEW_SORTDATE           6
#Define VIEW_SORTTYPE           7
#Define VIEW_PARENTFOLDER       8
#Define VIEW_NETCONNECT         9
#Define VIEW_NETDISCONNECT      10
#Define VIEW_NEWFOLDER          11
#Define VIEW_VIEWMENU           12

#Define HIST_BACK               0
#Define HIST_FORWARD            1
#Define HIST_FAVORITES          2
#Define HIST_ADDTOFAVORITES     3
#Define HIST_VIEWTREE           4

#Define TB_ADDBUTTONSA			(WM_USER + 20)
#Define TB_INSERTBUTTONA		(WM_USER + 21)
#Define TB_DELETEBUTTON         (WM_USER + 22)
#Define TB_GETBUTTON            (WM_USER + 23)
#Define TB_BUTTONCOUNT          (WM_USER + 24)
#Define TB_COMMANDTOINDEX       (WM_USER + 25)

#Define TB_SAVERESTOREA			(WM_USER + 26)
#Define TB_SAVERESTOREW			(WM_USER + 76)
#Define TB_CUSTOMIZE            (WM_USER + 27)
#Define TB_ADDSTRINGA			(WM_USER + 28)
#Define TB_ADDSTRINGW			(WM_USER + 77)
#Define TB_GETITEMRECT          (WM_USER + 29)
#Define TB_BUTTONSTRUCTSIZE     (WM_USER + 30)
#Define TB_SETBUTTONSIZE        (WM_USER + 31)
#Define TB_SETBITMAPSIZE        (WM_USER + 32)
#Define TB_AUTOSIZE             (WM_USER + 33)
#Define TB_GETTOOLTIPS          (WM_USER + 35)
#Define TB_SETTOOLTIPS          (WM_USER + 36)
#Define TB_SETPARENT            (WM_USER + 37)
#Define TB_SETROWS              (WM_USER + 39)
#Define TB_GETROWS              (WM_USER + 40)
#Define TB_SETCMDID             (WM_USER + 42)
#Define TB_CHANGEBITMAP         (WM_USER + 43)
#Define TB_GETBITMAP            (WM_USER + 44)
#Define TB_GETBUTTONTEXTA		(WM_USER + 45)
#Define TB_GETBUTTONTEXTW		(WM_USER + 75)
#Define TB_REPLACEBITMAP        (WM_USER + 46)
#Define TB_SETINDENT            (WM_USER + 47)
#Define TB_SETIMAGELIST         (WM_USER + 48)
#Define TB_GETIMAGELIST         (WM_USER + 49)
#Define TB_LOADIMAGES           (WM_USER + 50)
#Define TB_GETRECT              (WM_USER + 51)
#Define TB_SETHOTIMAGELIST      (WM_USER + 52)
#Define TB_GETHOTIMAGELIST      (WM_USER + 53)
#Define TB_SETDISABLEDIMAGELIST (WM_USER + 54)
#Define TB_GETDISABLEDIMAGELIST (WM_USER + 55)
#Define TB_SETSTYLE             (WM_USER + 56)
#Define TB_GETSTYLE             (WM_USER + 57)
#Define TB_GETBUTTONSIZE        (WM_USER + 58)
#Define TB_SETBUTTONWIDTH       (WM_USER + 59)
#Define TB_SETMAXTEXTROWS       (WM_USER + 60)
#Define TB_GETTEXTROWS          (WM_USER + 61)

#Define TB_GETOBJECT            (WM_USER + 62)
#Define TB_GETHOTITEM           (WM_USER + 71)
#Define TB_SETHOTITEM           (WM_USER + 72)
#Define TB_SETANCHORHIGHLIGHT   (WM_USER + 73)
#Define TB_GETANCHORHIGHLIGHT   (WM_USER + 74)
#Define TB_MAPACCELERATORA		(WM_USER + 78)

#Define TBIMHT_AFTER      		000000001H
#Define TBIMHT_BACKGROUND 		000000002H

#Define TB_GETINSERTMARK		(WM_USER + 79)
#Define TB_SETINSERTMARK		(WM_USER + 80)
#Define TB_INSERTMARKHITTEST	(WM_USER + 81)
#Define TB_MOVEBUTTON			(WM_USER + 82)
#Define TB_GETMAXSIZE			(WM_USER + 83)
#Define TB_SETEXTENDEDSTYLE     (WM_USER + 84)
#Define TB_GETEXTENDEDSTYLE		(WM_USER + 85)
#Define TB_GETPADDING			(WM_USER + 86)
#Define TB_SETPADDING			(WM_USER + 87)
#Define TB_SETINSERTMARKCOLOR	(WM_USER + 88)
#Define TB_GETINSERTMARKCOLOR	(WM_USER + 89)

#Define TB_SETCOLORSCHEME       CCM_SETCOLORSCHEME
#Define TB_GETCOLORSCHEME       CCM_GETCOLORSCHEME

#Define TB_SETUNICODEFORMAT     CCM_SETUNICODEFORMAT
#Define TB_GETUNICODEFORMAT     CCM_GETUNICODEFORMAT

#Define TB_MAPACCELERATORW		(WM_USER + 90)

#Define TBBF_LARGE              00001H

#Define TB_GETBITMAPFLAGS       (WM_USER + 41)

#Define TBIF_IMAGE              000000001H
#Define TBIF_TEXT               000000002H
#Define TBIF_STATE              000000004H
#Define TBIF_STYLE              000000008H
#Define TBIF_LPARAM             000000010H
#Define TBIF_COMMAND            000000020H
#Define TBIF_SIZE               000000040H

#Define TB_GETBUTTONINFOW		(WM_USER + 63)
#Define TB_SETBUTTONINFOW		(WM_USER + 64)
#Define TB_GETBUTTONINFOA		(WM_USER + 65)
#Define TB_SETBUTTONINFOA		(WM_USER + 66)
#Define TB_INSERTBUTTONW		(WM_USER + 67)
#Define TB_ADDBUTTONSW			(WM_USER + 68)
#Define TB_HITTEST				(WM_USER + 69)
#Define TB_SETDRAWTEXTFLAGS		(WM_USER + 70)

#Define TBN_GETBUTTONINFOA      (TBN_FIRST - 0)
#Define TBN_GETBUTTONINFOW		(TBN_FIRST - 20)
#Define TBN_BEGINDRAG           (TBN_FIRST - 1)
#Define TBN_ENDDRAG             (TBN_FIRST - 2)
#Define TBN_BEGINADJUST         (TBN_FIRST - 3)
#Define TBN_ENDADJUST           (TBN_FIRST - 4)
#Define TBN_RESET               (TBN_FIRST - 5)
#Define TBN_QUERYINSERT         (TBN_FIRST - 6)
#Define TBN_QUERYDELETE         (TBN_FIRST - 7)
#Define TBN_TOOLBARCHANGE       (TBN_FIRST - 8)
#Define TBN_CUSTHELP            (TBN_FIRST - 9)
#Define TBN_DROPDOWN            (TBN_FIRST - 10)
#Define TBN_GETOBJECT           (TBN_FIRST - 12)

#Define HICF_OTHER          	000000000H
#Define HICF_MOUSE          	000000001H
#Define HICF_ARROWKEYS      	000000002H
#Define HICF_ACCELERATOR    	000000004H
#Define HICF_DUPACCEL       	000000008H
#Define HICF_ENTERING       	000000010H
#Define HICF_LEAVING        	000000020H
#Define HICF_RESELECT       	000000040H


#Define TBN_HOTITEMCHANGE       (TBN_FIRST - 13)
#Define TBN_DRAGOUT             (TBN_FIRST - 14)
#Define TBN_DELETINGBUTTON		(TBN_FIRST - 15)
#Define TBN_GETDISPINFOA		(TBN_FIRST - 16)
#Define TBN_GETDISPINFOW		(TBN_FIRST - 17)
#define TBN_GETINFOTIPA         (TBN_FIRST - 18)
#define TBN_GETINFOTIPW         (TBN_FIRST - 19)

#Define TBNF_IMAGE              000000001H
#Define TBNF_TEXT               000000002H
#Define TBNF_DI_SETITEM         010000000H

#Define TBDDRET_DEFAULT         0
#Define TBDDRET_NODEFAULT       1
#Define TBDDRET_TREATPRESSED    2

#Define TBNOTIFYA				NMTOOLBARA
#Define TBNOTIFYW				NMTOOLBARW
#Define TBNOTIFY       			NMTOOLBAR

#Define REBARCLASSNAMEW         L"ReBarWindow32"
#define REBARCLASSNAMEA         "ReBarWindow32"

#Define RBIM_IMAGELIST  		000000001H

#Define RBS_TOOLTIPS        	00100H
#Define RBS_VARHEIGHT       	00200H
#Define RBS_BANDBORDERS     	00400H
#Define RBS_FIXEDORDER      	00800H
#Define RBS_REGISTERDROP    	01000H
#Define RBS_AUTOSIZE        	02000H
#Define RBS_VERTICALGRIPPER 	04000H
#Define RBS_DBLCLKTOGGLE    	08000H

#Define RBBS_BREAK          	000000001H
#Define RBBS_FIXEDSIZE      	000000002H
#Define RBBS_CHILDEDGE      	000000004H
#Define RBBS_HIDDEN         	000000008H
#Define RBBS_NOVERT         	000000010H
#Define RBBS_FIXEDBMP       	000000020H
#Define RBBS_VARIABLEHEIGHT 	000000040H
#Define RBBS_GRIPPERALWAYS  	000000080H
#Define RBBS_NOGRIPPER      	000000100H

#Define RBBIM_STYLE         	000000001H
#Define RBBIM_COLORS        	000000002H
#Define RBBIM_TEXT          	000000004H
#Define RBBIM_IMAGE         	000000008H
#Define RBBIM_CHILD         	000000010H
#Define RBBIM_CHILDSIZE     	000000020H
#Define RBBIM_SIZE          	000000040H
#Define RBBIM_BACKGROUND    	000000080H
#Define RBBIM_ID            	000000100H
#Define RBBIM_IDEALSIZE     	000000200H
#Define RBBIM_LPARAM        	000000400H
#Define RBBIM_HEADERSIZE    	000000800H

#Define RB_INSERTBANDA  		(WM_USER + 1)
#Define RB_DELETEBAND   		(WM_USER + 2)
#Define RB_GETBARINFO   		(WM_USER + 3)
#Define RB_SETBARINFO   		(WM_USER + 4)
#Define RB_GETBANDINFO  		(WM_USER + 5)
#Define RB_SETBANDINFOA			(WM_USER + 6)
#Define RB_SETPARENT    		(WM_USER + 7)
#Define RB_HITTEST      		(WM_USER + 8)
#Define RB_GETRECT      		(WM_USER + 9)
#define RB_INSERTBANDW  		(WM_USER + 10)
#Define RB_SETBANDINFOW			(WM_USER + 11)
#Define RB_GETBANDCOUNT 		(WM_USER + 12)
#Define RB_GETROWCOUNT  		(WM_USER + 13)
#Define RB_GETROWHEIGHT 		(WM_USER + 14)
#Define RB_IDTOINDEX    		(WM_USER + 16)
#Define RB_GETTOOLTIPS  		(WM_USER + 17)
#Define RB_SETTOOLTIPS  		(WM_USER + 18)
#Define RB_SETBKCOLOR   		(WM_USER + 19)
#Define RB_GETBKCOLOR   		(WM_USER + 20)
#Define RB_SETTEXTCOLOR 		(WM_USER + 21)
#Define RB_GETTEXTCOLOR 		(WM_USER + 22)
#Define RB_SIZETORECT   		(WM_USER + 23)

#Define RB_SETCOLORSCHEME   	CCM_SETCOLORSCHEME
#Define RB_GETCOLORSCHEME   	CCM_GETCOLORSCHEME

#Define RB_BEGINDRAG    		(WM_USER + 24)
#Define RB_ENDDRAG      		(WM_USER + 25)
#Define RB_DRAGMOVE     		(WM_USER + 26)
#Define RB_GETBARHEIGHT 		(WM_USER + 27)
#Define RB_GETBANDINFOW			(WM_USER + 28)
#Define RB_GETBANDINFOA			(WM_USER + 29)

#Define RB_MINIMIZEBAND 		(WM_USER + 30)
#Define RB_MAXIMIZEBAND 		(WM_USER + 31)

#Define RB_GETDROPTARGET 		(CCM_GETDROPTARGET)

#Define RB_GETBANDBORDERS 		(WM_USER + 34)

#Define RB_SHOWBAND     		(WM_USER + 35)
#Define RB_SETPALETTE   		(WM_USER + 37)
#Define RB_GETPALETTE   		(WM_USER + 38)
#Define RB_MOVEBAND     		(WM_USER + 39)

#Define RB_SETUNICODEFORMAT     CCM_SETUNICODEFORMAT
#Define RB_GETUNICODEFORMAT     CCM_GETUNICODEFORMAT

#Define RBN_HEIGHTCHANGE    	(RBN_FIRST - 0)

#Define RBN_GETOBJECT       	(RBN_FIRST - 1)
#Define RBN_LAYOUTCHANGED   	(RBN_FIRST - 2)
#Define RBN_AUTOSIZE        	(RBN_FIRST - 3)
#Define RBN_BEGINDRAG       	(RBN_FIRST - 4)
#Define RBN_ENDDRAG         	(RBN_FIRST - 5)
#Define RBN_DELETINGBAND    	(RBN_FIRST - 6)
#Define RBN_DELETEDBAND     	(RBN_FIRST - 7)
#Define RBN_CHILDSIZE       	(RBN_FIRST - 8)

#Define RBNM_ID         		000000001H
#Define RBNM_STYLE      		000000002H
#Define RBNM_LPARAM     		000000004H

#Define RBHT_NOWHERE    		00001H
#Define RBHT_CAPTION    		00002H
#Define RBHT_CLIENT     		00003H
#Define RBHT_GRABBER    		00004H

#Define TOOLTIPS_CLASSW         L"tooltips_class32"
#define TOOLTIPS_CLASSA         "tooltips_class32"

#Define TOOLINFOA       		TTTOOLINFOA
#Define TOOLINFOW       		TTTOOLINFOW

#Define TOOLINFO        		TTTOOLINFO

#Define TTS_ALWAYSTIP           001H
#Define TTS_NOPREFIX            002H

#Define TTF_IDISHWND            00001H

#Define TTF_CENTERTIP           00002H
#Define TTF_RTLREADING          00004H
#Define TTF_SUBCLASS            00010H
#Define TTF_TRACK               00020H
#Define TTF_ABSOLUTE            00080H
#Define TTF_TRANSPARENT         00100H
#Define TTF_DI_SETITEM          08000H

#Define TTDT_AUTOMATIC          0
#Define TTDT_RESHOW             1
#Define TTDT_AUTOPOP            2
#Define TTDT_INITIAL            3

#Define TTM_ACTIVATE            (WM_USER + 1)
#Define TTM_SETDELAYTIME        (WM_USER + 3)
#Define TTM_ADDTOOLA			(WM_USER + 4)
#Define TTM_ADDTOOLW            (WM_USER + 50)
#Define TTM_DELTOOLA			(WM_USER + 5)
#Define TTM_DELTOOLW            (WM_USER + 51)
#Define TTM_NEWTOOLRECTA		(WM_USER + 6)
#Define TTM_NEWTOOLRECTW        (WM_USER + 52)
#Define TTM_RELAYEVENT          (WM_USER + 7)

#Define TTM_GETTOOLINFOA		(WM_USER + 8)
#Define TTM_GETTOOLINFOW        (WM_USER + 53)

#Define TTM_SETTOOLINFOA		(WM_USER + 9)
#Define TTM_SETTOOLINFOW        (WM_USER + 54)

#Define TTM_HITTESTA			(WM_USER + 10)
#Define TTM_HITTESTW            (WM_USER + 55)
#Define TTM_GETTEXTA			(WM_USER + 11)
#Define TTM_GETTEXTW            (WM_USER + 56)
#Define TTM_UPDATETIPTEXTA		(WM_USER + 12)
#Define TTM_UPDATETIPTEXTW      (WM_USER + 57)
#Define TTM_GETTOOLCOUNT        (WM_USER + 13)
#Define TTM_ENUMTOOLSA			(WM_USER + 14)
#Define TTM_ENUMTOOLSW          (WM_USER + 58)
#Define TTM_GETCURRENTTOOLA		(WM_USER + 15)
#Define TTM_GETCURRENTTOOLW     (WM_USER + 59)
#Define TTM_WINDOWFROMPOINT     (WM_USER + 16)
#Define TTM_TRACKACTIVATE		(WM_USER + 17)
#Define TTM_TRACKPOSITION		(WM_USER + 18)
#Define TTM_SETTIPBKCOLOR		(WM_USER + 19)
#Define TTM_SETTIPTEXTCOLOR		(WM_USER + 20)
#Define TTM_GETDELAYTIME		(WM_USER + 21)
#Define TTM_GETTIPBKCOLOR		(WM_USER + 22)
#Define TTM_GETTIPTEXTCOLOR		(WM_USER + 23)
#Define TTM_SETMAXTIPWIDTH		(WM_USER + 24)
#Define TTM_GETMAXTIPWIDTH		(WM_USER + 25)
#Define TTM_SETMARGIN			(WM_USER + 26)
#Define TTM_GETMARGIN			(WM_USER + 27)
#Define TTM_POP					(WM_USER + 28)

#Define TTM_UPDATE				(WM_USER + 29)

#Define TTN_GETDISPINFOA		(TTN_FIRST - 0)
#Define TTN_GETDISPINFOW		(TTN_FIRST - 10)
#Define TTN_SHOW                (TTN_FIRST - 1)
#Define TTN_POP                 (TTN_FIRST - 2)

#Define TTN_NEEDTEXT            TTN_GETDISPINFO
#Define TTN_NEEDTEXTA           TTN_GETDISPINFOA
#Define TTN_NEEDTEXTW           TTN_GETDISPINFOW

#Define TOOLTIPTEXTW 			NMTTDISPINFOW
#Define TOOLTIPTEXTA 			NMTTDISPINFOA

#Define TOOLTIPTEXT    NMTTDISPINFO

#Define SBARS_SIZEGRIP			0100H

#Define STATUSCLASSNAMEW        L"msctls_statusbar32"
#define STATUSCLASSNAMEA        "msctls_statusbar32"

#Define SB_SETTEXTA             (WM_USER + 1)
#Define SB_SETTEXTW             (WM_USER + 11)
#Define SB_GETTEXTA				(WM_USER + 2)
#Define SB_GETTEXTW             (WM_USER + 13)
#Define SB_GETTEXTLENGTHA		(WM_USER + 3)
#Define SB_GETTEXTLENGTHW       (WM_USER + 12)

#Define SB_SETPARTS             (WM_USER + 4)
#Define SB_GETPARTS             (WM_USER + 6)
#Define SB_GETBORDERS           (WM_USER + 7)
#Define SB_SETMINHEIGHT         (WM_USER + 8)
#Define SB_SIMPLE               (WM_USER + 9)
#Define SB_GETRECT              (WM_USER + 10)
#Define SB_ISSIMPLE				(WM_USER + 14)
#Define SB_SETICON				(WM_USER + 15)
#Define SB_SETTIPTEXTA			(WM_USER + 16)
#Define SB_SETTIPTEXTW			(WM_USER + 17)
#Define SB_GETTIPTEXTA			(WM_USER + 18)
#Define SB_GETTIPTEXTW			(WM_USER + 19)
#Define SB_GETICON				(WM_USER + 20)
#Define SB_SETUNICODEFORMAT     CCM_SETUNICODEFORMAT
#Define SB_GETUNICODEFORMAT     CCM_GETUNICODEFORMAT

#Define SBT_OWNERDRAW           01000H
#Define SBT_NOBORDERS           00100H
#Define SBT_POPOUT              00200H
#Define SBT_RTLREADING          00400H
#Define SBT_TOOLTIPS            00800H

#Define SB_SETBKCOLOR           CCM_SETBKCOLOR

#Define SBN_SIMPLEMODECHANGE	(SBN_FIRST - 0)

#Define MINSYSCOMMAND   		SC_SIZE

#Define TRACKBAR_CLASSA         "msctls_trackbar32"
#define TRACKBAR_CLASSW         L"msctls_trackbar32"

#Define TBS_AUTOTICKS           00001H
#Define TBS_VERT                00002H
#Define TBS_HORZ                00000H
#Define TBS_TOP                 00004H
#Define TBS_BOTTOM              00000H
#Define TBS_LEFT                00004H
#Define TBS_RIGHT               00000H
#Define TBS_BOTH                00008H
#Define TBS_NOTICKS             00010H
#Define TBS_ENABLESELRANGE      00020H
#Define TBS_FIXEDLENGTH         00040H
#Define TBS_NOTHUMB             00080H
#Define TBS_TOOLTIPS            00100H

#Define TBM_GETPOS              (WM_USER)
#Define TBM_GETRANGEMIN         (WM_USER + 1)
#Define TBM_GETRANGEMAX         (WM_USER + 2)
#Define TBM_GETTIC              (WM_USER + 3)
#Define TBM_SETTIC              (WM_USER + 4)
#Define TBM_SETPOS              (WM_USER + 5)
#Define TBM_SETRANGE            (WM_USER + 6)
#Define TBM_SETRANGEMIN         (WM_USER + 7)
#Define TBM_SETRANGEMAX         (WM_USER + 8)
#Define TBM_CLEARTICS           (WM_USER + 9)
#Define TBM_SETSEL              (WM_USER + 10)
#Define TBM_SETSELSTART         (WM_USER + 11)
#Define TBM_SETSELEND           (WM_USER + 12)
#Define TBM_GETPTICS            (WM_USER + 14)
#Define TBM_GETTICPOS           (WM_USER + 15)
#Define TBM_GETNUMTICS          (WM_USER + 16)
#Define TBM_GETSELSTART         (WM_USER + 17)
#Define TBM_GETSELEND           (WM_USER + 18)
#Define TBM_CLEARSEL            (WM_USER + 19)
#Define TBM_SETTICFREQ          (WM_USER + 20)
#Define TBM_SETPAGESIZE         (WM_USER + 21)
#Define TBM_GETPAGESIZE         (WM_USER + 22)
#Define TBM_SETLINESIZE         (WM_USER + 23)
#Define TBM_GETLINESIZE         (WM_USER + 24)
#Define TBM_GETTHUMBRECT        (WM_USER + 25)
#Define TBM_GETCHANNELRECT      (WM_USER + 26)
#Define TBM_SETTHUMBLENGTH      (WM_USER + 27)
#Define TBM_GETTHUMBLENGTH      (WM_USER + 28)
#Define TBM_SETTOOLTIPS			(WM_USER + 29)
#Define TBM_GETTOOLTIPS			(WM_USER + 30)
#Define TBM_SETTIPSIDE			(WM_USER + 31)
#Define TBTS_TOP                0
#Define TBTS_LEFT               1
#Define TBTS_BOTTOM             2
#Define TBTS_RIGHT              3

#Define TBM_SETBUDDY			(WM_USER + 32)
#Define TBM_GETBUDDY			(WM_USER + 33)

#Define TBM_SETUNICODEFORMAT    CCM_SETUNICODEFORMAT
#define TBM_GETUNICODEFORMAT    CCM_GETUNICODEFORMAT

#Define TB_LINEUP               0
#define TB_LINEDOWN             1
#define TB_PAGEUP               2
#define TB_PAGEDOWN             3
#define TB_THUMBPOSITION        4
#define TB_THUMBTRACK           5
#define TB_TOP                  6
#define TB_BOTTOM               7
#define TB_ENDTRACK             8

#Define TBCD_TICS    			00001H
#Define TBCD_THUMB   			00002H
#Define TBCD_CHANNEL 			00003H

#Define DL_BEGINDRAG            (WM_USER + 133)
#Define DL_DRAGGING             (WM_USER + 134)
#Define DL_DROPPED              (WM_USER + 135)
#Define DL_CANCELDRAG           (WM_USER + 136)

#Define DL_CURSORSET            0
#Define DL_STOPCURSOR           1
#Define DL_COPYCURSOR           2
#Define DL_MOVECURSOR           3

#Define DRAGLISTMSGSTRING       "commctrl_DragListMsg"

#Define UPDOWN_CLASSA           "msctls_updown32"
#Define UPDOWN_CLASSW           L"msctls_updown32"

#Define UD_MAXVAL               07FFFH
#Define UD_MINVAL               (-UD_MAXVAL)

#Define UDS_WRAP                00001H
#Define UDS_SETBUDDYINT         00002H
#Define UDS_ALIGNRIGHT          00004H
#Define UDS_ALIGNLEFT           00008H
#Define UDS_AUTOBUDDY           00010H
#Define UDS_ARROWKEYS           00020H
#Define UDS_HORZ                00040H
#Define UDS_NOTHOUSANDS         00080H
#Define UDS_HOTTRACK            00100H

#Define UDM_SETRANGE            (WM_USER + 101)
#Define UDM_GETRANGE            (WM_USER + 102)
#Define UDM_SETPOS              (WM_USER + 103)
#Define UDM_GETPOS              (WM_USER + 104)
#Define UDM_SETBUDDY            (WM_USER + 105)
#Define UDM_GETBUDDY            (WM_USER + 106)
#Define UDM_SETACCEL            (WM_USER + 107)
#Define UDM_GETACCEL            (WM_USER + 108)
#Define UDM_SETBASE             (WM_USER + 109)
#Define UDM_GETBASE             (WM_USER + 110)
#Define UDM_SETRANGE32			(WM_USER + 111)
#Define UDM_GETRANGE32			(WM_USER + 112)
#Define UDM_SETUNICODEFORMAT    CCM_SETUNICODEFORMAT
#Define UDM_GETUNICODEFORMAT    CCM_GETUNICODEFORMAT

#Define NM_UPDOWN      			NMUPDOWN

#Define UDN_DELTAPOS            (UDN_FIRST - 1)

#Define PROGRESS_CLASSA         "msctls_progress32"
#Define PROGRESS_CLASSW         L"msctls_progress32"

#Define PBS_SMOOTH              001H
#Define PBS_VERTICAL            004H

#Define PBM_SETRANGE            (WM_USER + 1)
#Define PBM_SETPOS              (WM_USER + 2)
#Define PBM_DELTAPOS            (WM_USER + 3)
#Define PBM_SETSTEP             (WM_USER + 4)
#Define PBM_STEPIT              (WM_USER + 5)
#Define PBM_SETRANGE32          (WM_USER + 6)

#Define PBM_GETRANGE            (WM_USER + 7)
#Define PBM_GETPOS              (WM_USER + 8)

#Define PBM_SETBARCOLOR         (WM_USER + 9)

#Define PBM_SETBKCOLOR          CCM_SETBKCOLOR

#Define HOTKEYF_SHIFT           001H
#Define HOTKEYF_CONTROL         002H
#Define HOTKEYF_ALT             004H

#Define HOTKEYF_EXT             008H

#Define HKCOMB_NONE             00001H
#Define HKCOMB_S                00002H
#Define HKCOMB_C                00004H
#Define HKCOMB_A                00008H
#Define HKCOMB_SC               00010H
#Define HKCOMB_SA               00020H
#Define HKCOMB_CA               00040H
#Define HKCOMB_SCA              00080H

#Define HKM_SETHOTKEY           (WM_USER + 1)
#Define HKM_GETHOTKEY           (WM_USER + 2)
#Define HKM_SETRULES            (WM_USER + 3)

#Define HOTKEY_CLASSA           "msctls_hotkey32"
#Define HOTKEY_CLASSW           L"msctls_hotkey32"

#Define CCS_TOP                 000000001H
#Define CCS_NOMOVEY             000000002H
#Define CCS_BOTTOM              000000003H
#Define CCS_NORESIZE            000000004H
#Define CCS_NOPARENTALIGN       000000008H
#Define CCS_ADJUSTABLE          000000020H
#Define CCS_NODIVIDER           000000040H
#Define CCS_VERT                000000080H
#Define CCS_LEFT                (CCS_VERT | CCS_TOP)
#Define CCS_RIGHT               (CCS_VERT | CCS_BOTTOM)
#Define CCS_NOMOVEX             (CCS_VERT | CCS_NOMOVEY)

#Define WC_LISTVIEWA            "SysListView32"
#Define WC_LISTVIEWW            L"SysListView32"

#Define LVS_ICON                00000H
#Define LVS_REPORT              00001H
#Define LVS_SMALLICON           00002H
#Define LVS_LIST                00003H
#Define LVS_TYPEMASK            00003H
#Define LVS_SINGLESEL           00004H
#Define LVS_SHOWSELALWAYS       00008H
#Define LVS_SORTASCENDING       00010H
#Define LVS_SORTDESCENDING      00020H
#Define LVS_SHAREIMAGELISTS     00040H
#Define LVS_NOLABELWRAP         00080H
#Define LVS_AUTOARRANGE         00100H
#Define LVS_EDITLABELS          00200H
#Define LVS_OWNERDATA           01000H
#Define LVS_NOSCROLL            02000H

#Define LVS_TYPESTYLEMASK       0FC00H

#Define LVS_ALIGNTOP            00000H
#Define LVS_ALIGNLEFT           00800H
#Define LVS_ALIGNMASK           00C00H

#Define LVS_OWNERDRAWFIXED      00400H
#Define LVS_NOCOLUMNHEADER      04000H
#Define LVS_NOSORTHEADER        08000H

#Define LVM_SETUNICODEFORMAT	CCM_SETUNICODEFORMAT
#Define LVM_GETUNICODEFORMAT	CCM_GETUNICODEFORMAT
#Define LVM_GETBKCOLOR          (LVM_FIRST + 0)
#Define LVM_SETBKCOLOR          (LVM_FIRST + 1)
#Define LVM_GETIMAGELIST        (LVM_FIRST + 2)
#Define LVM_SETIMAGELIST        (LVM_FIRST + 3)
#Define LVM_GETITEMCOUNT        (LVM_FIRST + 4)

#Define LVSIL_NORMAL            0
#Define LVSIL_SMALL             1
#Define LVSIL_STATE             2

#Define LVIF_TEXT               00001H
#Define LVIF_IMAGE              00002H
#Define LVIF_PARAM              00004H
#Define LVIF_STATE              00008H
#Define LVIF_INDENT             00010H
#Define LVIF_NORECOMPUTE        00800H

#Define LVIS_FOCUSED            00001H
#Define LVIS_SELECTED           00002H
#Define LVIS_CUT                00004H
#Define LVIS_DROPHILITED        00008H
#Define LVIS_ACTIVATING         00020H

#Define LVIS_OVERLAYMASK        00F00H
#Define LVIS_STATEIMAGEMASK     0F000H

#Define I_INDENTCALLBACK		(-1)
#Define LV_ITEMA LVITEMA
#Define LV_ITEMW LVITEMW

#Define LV_ITEM LVITEM

#Define I_IMAGECALLBACK         (-1)

#Define LVM_GETITEMA			(LVM_FIRST + 5)
#Define LVM_GETITEMW            (LVM_FIRST + 75)

#Define LVM_SETITEMA            (LVM_FIRST + 6)
#Define LVM_SETITEMW            (LVM_FIRST + 76)

#Define LVM_INSERTITEMA         (LVM_FIRST + 7)
#Define LVM_INSERTITEMW         (LVM_FIRST + 77)

#Define LVM_DELETEITEM          (LVM_FIRST + 8)
#Define LVM_DELETEALLITEMS      (LVM_FIRST + 9)
#Define LVM_GETCALLBACKMASK     (LVM_FIRST + 10)
#Define LVM_SETCALLBACKMASK     (LVM_FIRST + 11)
#Define LVM_GETNEXTITEM         (LVM_FIRST + 12)

#Define LVNI_ALL                00000H
#Define LVNI_FOCUSED            00001H
#Define LVNI_SELECTED           00002H
#Define LVNI_CUT                00004H
#Define LVNI_DROPHILITED        00008H

#Define LVNI_ABOVE              00100H
#Define LVNI_BELOW              00200H
#Define LVNI_TOLEFT             00400H
#Define LVNI_TORIGHT            00800H

#Define LVFI_PARAM              00001H
#Define LVFI_STRING             00002H
#Define LVFI_PARTIAL            00008H
#Define LVFI_WRAP               00020H
#Define LVFI_NEARESTXY          00040H

#Define LV_FINDINFOA    		LVFINDINFOA
#Define LV_FINDINFOW    		LVFINDINFOW

#Define LV_FINDINFO				LVFINDINFO

#Define LVM_FINDITEMA			(LVM_FIRST + 13)
#Define LVM_FINDITEMW           (LVM_FIRST + 83)

#Define LVIR_BOUNDS             0
#Define LVIR_ICON               1
#Define LVIR_LABEL              2
#Define LVIR_SELECTBOUNDS       3

#Define LVM_GETITEMRECT         (LVM_FIRST + 14)
#Define LVM_SETITEMPOSITION     (LVM_FIRST + 15)
#Define LVM_GETITEMPOSITION     (LVM_FIRST + 16)

#Define LVM_GETSTRINGWIDTHA		(LVM_FIRST + 17)
#Define LVM_GETSTRINGWIDTHW     (LVM_FIRST + 87)

#Define LVHT_NOWHERE            00001H
#Define LVHT_ONITEMICON         00002H
#Define LVHT_ONITEMLABEL        00004H
#Define LVHT_ONITEMSTATEICON    00008H
#Define LVHT_ONITEM             (LVHT_ONITEMICON | LVHT_ONITEMLABEL | LVHT_ONITEMSTATEICON)

#Define LVHT_ABOVE              00008H
#Define LVHT_BELOW              00010H
#Define LVHT_TORIGHT            00020H
#Define LVHT_TOLEFT             00040H

#Define LV_HITTESTINFO 			LVHITTESTINFO

#Define LVM_HITTEST             (LVM_FIRST + 18)
#Define LVM_ENSUREVISIBLE       (LVM_FIRST + 19)
#Define LVM_SCROLL              (LVM_FIRST + 20)
#Define LVM_REDRAWITEMS         (LVM_FIRST + 21)
#Define LVM_ARRANGE             (LVM_FIRST + 22)

#Define LVA_DEFAULT             00000H
#Define LVA_ALIGNLEFT           00001H
#Define LVA_ALIGNTOP            00002H
#Define LVA_SNAPTOGRID          00005H

#Define LVM_EDITLABELA			(LVM_FIRST + 23)
#Define LVM_EDITLABELW          (LVM_FIRST + 118)

#Define LVM_GETEDITCONTROL      (LVM_FIRST + 24)

#Define LV_COLUMNA      		LVCOLUMNA
#Define LV_COLUMNW      		LVCOLUMNW

#Define LV_COLUMN       		LVCOLUMN

#Define LVCF_FMT                00001H
#Define LVCF_WIDTH              00002H
#Define LVCF_TEXT               00004H
#Define LVCF_SUBITEM            00008H
#Define LVCF_IMAGE              00010H
#Define LVCF_ORDER              00020H

#Define LVCFMT_LEFT             00000H
#Define LVCFMT_RIGHT            00001H
#Define LVCFMT_CENTER           00002H
#Define LVCFMT_JUSTIFYMASK      00003H
#Define LVCFMT_IMAGE            00800H
#Define LVCFMT_BITMAP_ON_RIGHT  01000H
#Define LVCFMT_COL_HAS_IMAGES   08000H

#Define LVM_GETCOLUMNA			(LVM_FIRST + 25)
#Define LVM_GETCOLUMNW          (LVM_FIRST + 95)

#Define LVM_SETCOLUMNA			(LVM_FIRST + 26)
#Define LVM_SETCOLUMNW          (LVM_FIRST + 96)

#Define LVM_INSERTCOLUMNA		(LVM_FIRST + 27)
#Define LVM_INSERTCOLUMNW       (LVM_FIRST + 97)

#Define LVM_DELETECOLUMN        (LVM_FIRST + 28)
#Define LVM_GETCOLUMNWIDTH      (LVM_FIRST + 29)

#Define LVSCW_AUTOSIZE          (-1)
#Define LVSCW_AUTOSIZE_USEHEADER	(-2)
#Define LVM_SETCOLUMNWIDTH      (LVM_FIRST + 30)
#Define LVM_GETHEADER			(LVM_FIRST + 31)
#Define LVM_CREATEDRAGIMAGE     (LVM_FIRST + 33)
#Define LVM_GETVIEWRECT         (LVM_FIRST + 34)
#Define LVM_GETTEXTCOLOR        (LVM_FIRST + 35)
#Define LVM_SETTEXTCOLOR        (LVM_FIRST + 36)
#Define LVM_GETTEXTBKCOLOR      (LVM_FIRST + 37)
#Define LVM_SETTEXTBKCOLOR      (LVM_FIRST + 38)
#Define LVM_GETTOPINDEX         (LVM_FIRST + 39)
#Define LVM_GETCOUNTPERPAGE     (LVM_FIRST + 40)
#Define LVM_GETORIGIN           (LVM_FIRST + 41)
#Define LVM_UPDATE              (LVM_FIRST + 42)
#Define LVM_SETITEMSTATE        (LVM_FIRST + 43)
#Define LVM_GETITEMSTATE        (LVM_FIRST + 44)

#Define LVM_GETITEMTEXTA		(LVM_FIRST + 45)
#Define LVM_GETITEMTEXTW        (LVM_FIRST + 115)

#Define LVM_SETITEMTEXTA		(LVM_FIRST + 46)
#Define LVM_SETITEMTEXTW        (LVM_FIRST + 116)

#Define LVSICF_NOINVALIDATEALL  000000001H
#Define LVSICF_NOSCROLL         000000002H

#Define LVM_SETITEMCOUNT        (LVM_FIRST + 47)
#Define LVM_SORTITEMS           (LVM_FIRST + 48)
#Define LVM_SETITEMPOSITION32   (LVM_FIRST + 49)
#Define LVM_GETSELECTEDCOUNT    (LVM_FIRST + 50)
#Define LVM_GETITEMSPACING      (LVM_FIRST + 51)

#Define LVM_GETISEARCHSTRINGA	(LVM_FIRST + 52)
#Define LVM_GETISEARCHSTRINGW   (LVM_FIRST + 117)

#Define LVM_SETICONSPACING		(LVM_FIRST + 53)
#Define LVM_SETEXTENDEDLISTVIEWSTYLE	(LVM_FIRST + 54)
#Define LVM_GETEXTENDEDLISTVIEWSTYLE	(LVM_FIRST + 55)

#Define LVS_EX_GRIDLINES        000000001H
#Define LVS_EX_SUBITEMIMAGES    000000002H
#Define LVS_EX_CHECKBOXES       000000004H
#Define LVS_EX_TRACKSELECT      000000008H
#Define LVS_EX_HEADERDRAGDROP   000000010H
#Define LVS_EX_FULLROWSELECT    000000020H
#Define LVS_EX_ONECLICKACTIVATE 000000040H
#Define LVS_EX_TWOCLICKACTIVATE 000000080H
#Define LVS_EX_FLATSB           000000100H
#Define LVS_EX_REGIONAL         000000200H
#Define LVS_EX_INFOTIP          000000400H
#Define LVS_EX_UNDERLINEHOT     000000800H
#Define LVS_EX_UNDERLINECOLD    000001000H
#Define LVS_EX_MULTIWORKAREAS   000002000H

#Define LVM_GETSUBITEMRECT		(LVM_FIRST + 56)
#Define LVM_SUBITEMHITTEST      (LVM_FIRST + 57)
#Define LVM_SETCOLUMNORDERARRAY (LVM_FIRST + 58)
#Define LVM_GETCOLUMNORDERARRAY (LVM_FIRST + 59)
#Define LVM_SETHOTITEM			(LVM_FIRST + 60)
#Define LVM_GETHOTITEM			(LVM_FIRST + 61)
#Define LVM_SETHOTCURSOR		(LVM_FIRST + 62)
#Define LVM_GETHOTCURSOR		(LVM_FIRST + 63)
#Define LVM_APPROXIMATEVIEWRECT (LVM_FIRST + 64)

#Define LV_MAX_WORKAREAS        16
#Define LVM_SETWORKAREAS		(LVM_FIRST + 65)

#Define LVM_GETWORKAREAS        (LVM_FIRST + 70)
#Define LVM_GETNUMBEROFWORKAREAS	(LVM_FIRST + 73)

#Define LVM_GETSELECTIONMARK    (LVM_FIRST + 66)
#Define LVM_SETSELECTIONMARK    (LVM_FIRST + 67)

#Define LVM_SETHOVERTIME        (LVM_FIRST + 71)
#Define LVM_GETHOVERTIME        (LVM_FIRST + 72)
#Define LVM_SETTOOLTIPS			(LVM_FIRST + 74)
#Define LVM_GETTOOLTIPS			(LVM_FIRST + 78)


#Define LVBKIF_SOURCE_NONE      000000000H
#Define LVBKIF_SOURCE_HBITMAP   000000001H
#Define LVBKIF_SOURCE_URL       000000002H
#Define LVBKIF_SOURCE_MASK      000000003H
#Define LVBKIF_STYLE_NORMAL     000000000H
#Define LVBKIF_STYLE_TILE       000000010H
#Define LVBKIF_STYLE_MASK       000000010H

#Define LVM_SETBKIMAGEA			(LVM_FIRST + 68)
#Define LVM_SETBKIMAGEW			(LVM_FIRST + 138)
#Define LVM_GETBKIMAGEA			(LVM_FIRST + 69)
#Define LVM_GETBKIMAGEW			(LVM_FIRST + 139)

#Define NM_LISTVIEW     		NMLISTVIEW

#Define LVKF_ALT       			00001H
#Define LVKF_CONTROL   			00002H
#Define LVKF_SHIFT     			00004H

#Define NM_CACHEHINT    		NMLVCACHEHINT

#Define NM_FINDITEM     		NMLVFINDITEM

#Define NM_ODSTATECHANGE    	NMLVODSTATECHANGE

#Define LVN_ITEMCHANGING        (LVN_FIRST - 0)
#Define LVN_ITEMCHANGED         (LVN_FIRST - 1)
#Define LVN_INSERTITEM          (LVN_FIRST - 2)
#Define LVN_DELETEITEM          (LVN_FIRST - 3)
#Define LVN_DELETEALLITEMS      (LVN_FIRST - 4)
#Define LVN_BEGINLABELEDITA		(LVN_FIRST - 5)
#Define LVN_BEGINLABELEDITW     (LVN_FIRST - 75)
#Define LVN_ENDLABELEDITA		(LVN_FIRST - 6)
#Define LVN_ENDLABELEDITW       (LVN_FIRST - 76)
#Define LVN_COLUMNCLICK         (LVN_FIRST - 8)
#Define LVN_BEGINDRAG           (LVN_FIRST - 9)
#Define LVN_BEGINRDRAG          (LVN_FIRST - 11)

#Define LVN_ODCACHEHINT			(LVN_FIRST - 13)
#Define LVN_ODFINDITEMA			(LVN_FIRST - 52)
#Define LVN_ODFINDITEMW			(LVN_FIRST - 79)

#Define LVN_ITEMACTIVATE		(LVN_FIRST - 14)
#Define LVN_ODSTATECHANGED		(LVN_FIRST - 15)

#Define LVN_HOTTRACK            (LVN_FIRST - 21)

#Define LVN_GETDISPINFOA        (LVN_FIRST - 50)
#Define LVN_GETDISPINFOW        (LVN_FIRST - 77)
#Define LVN_SETDISPINFOA		(LVN_FIRST - 51)
#Define LVN_SETDISPINFOW        (LVN_FIRST - 78)

#Define LVIF_DI_SETITEM         01000H
#Define LV_DISPINFOA    		NMLVDISPINFOA
#Define LV_DISPINFOW    		NMLVDISPINFOW

#Define LV_DISPINFO     		NMLVDISPINFO

#Define LVN_KEYDOWN             (LVN_FIRST - 55)
#Define LVN_MARQUEEBEGIN        (LVN_FIRST - 56)

#Define LV_KEYDOWN              NMLVKEYDOWN

#Define LVGIT_UNFOLDED  		00001H

#Define LVN_GETINFOTIPA			(LVN_FIRST - 57)
#Define LVN_GETINFOTIPW			(LVN_FIRST - 58)

#Define WC_TREEVIEWA            "SysTreeView32"
#Define WC_TREEVIEWW            L"SysTreeView32"

#Define TVS_HASBUTTONS          00001H
#Define TVS_HASLINES            00002H
#Define TVS_LINESATROOT         00004H
#Define TVS_EDITLABELS          00008H
#Define TVS_DISABLEDRAGDROP     00010H
#Define TVS_SHOWSELALWAYS       00020H
#Define TVS_RTLREADING          00040H

#Define TVS_NOTOOLTIPS          00080H
#Define TVS_CHECKBOXES          00100H
#Define TVS_TRACKSELECT         00200H
#Define TVS_SINGLEEXPAND        00400H
#Define TVS_INFOTIP             00800H
#Define TVS_FULLROWSELECT       01000H
#Define TVS_NOSCROLL            02000H
#Define TVS_NONEVENHEIGHT       04000H


#Define TVIF_TEXT               00001H
#Define TVIF_IMAGE              00002H
#Define TVIF_PARAM              00004H
#Define TVIF_STATE              00008H
#Define TVIF_HANDLE             00010H
#Define TVIF_SELECTEDIMAGE      00020H
#Define TVIF_CHILDREN           00040H
#Define TVIF_INTEGRAL           00080H
#Define TVIS_SELECTED           00002H
#Define TVIS_CUT                00004H
#Define TVIS_DROPHILITED        00008H
#Define TVIS_BOLD               00010H
#Define TVIS_EXPANDED           00020H
#Define TVIS_EXPANDEDONCE       00040H
#Define TVIS_EXPANDPARTIAL      00080H

#Define TVIS_OVERLAYMASK        00F00H
#Define TVIS_STATEIMAGEMASK     0F000H
#Define TVIS_USERMASK           0F000H

#Define I_CHILDRENCALLBACK  	(-1)

#Define LPTV_ITEMW              LPTVITEMW
#Define LPTV_ITEMA              LPTVITEMA
#Define TV_ITEMW                TVITEMW
#Define TV_ITEMA                TVITEMA

#Define TV_ITEM                 TVITEM

#Define TVI_ROOT                0FFFF0000H
#Define TVI_FIRST               0FFFF0001H
#Define TVI_LAST                0FFFF0002H
#Define TVI_SORT                0FFFF0003H

#Define LPTV_INSERTSTRUCTA      LPTVINSERTSTRUCTA
#Define LPTV_INSERTSTRUCTW      LPTVINSERTSTRUCTW
#Define TV_INSERTSTRUCTA        TVINSERTSTRUCTA
#Define TV_INSERTSTRUCTW        TVINSERTSTRUCTW

#Define TV_INSERTSTRUCT         TVINSERTSTRUCT

#Define TVM_INSERTITEMA			(TV_FIRST + 0)
#Define TVM_INSERTITEMW         (TV_FIRST + 50)

#Define TVM_DELETEITEM          (TV_FIRST + 1)
#Define TVM_EXPAND              (TV_FIRST + 2)

#Define TVE_COLLAPSE            00001H
#Define TVE_EXPAND              00002H
#Define TVE_TOGGLE              00003H
#Define TVE_EXPANDPARTIAL       04000H
#Define TVE_COLLAPSERESET       08000H

#Define TVM_GETITEMRECT         (TV_FIRST + 4)
#Define TVM_GETCOUNT            (TV_FIRST + 5)
#Define TVM_GETINDENT           (TV_FIRST + 6)
#Define TVM_SETINDENT           (TV_FIRST + 7)
#Define TVM_GETIMAGELIST        (TV_FIRST + 8)

#Define TVSIL_NORMAL            0
#Define TVSIL_STATE             2

#Define TVM_SETIMAGELIST        (TV_FIRST + 9)
#Define TVM_GETNEXTITEM         (TV_FIRST + 10)

#Define TVGN_ROOT               00000H
#Define TVGN_NEXT               00001H
#Define TVGN_PREVIOUS           00002H
#Define TVGN_PARENT             00003H
#Define TVGN_CHILD              00004H
#Define TVGN_FIRSTVISIBLE       00005H
#Define TVGN_NEXTVISIBLE        00006H
#Define TVGN_PREVIOUSVISIBLE    00007H
#Define TVGN_DROPHILITE         00008H
#Define TVGN_CARET              00009H
#Define TVGN_LASTVISIBLE        0000AH

#Define TVM_SELECTITEM          (TV_FIRST + 11)

#Define TVM_GETITEMA			(TV_FIRST + 12)
#Define TVM_GETITEMW            (TV_FIRST + 62)

#Define TVM_SETITEMA			(TV_FIRST + 13)
#Define TVM_SETITEMW            (TV_FIRST + 63)

#Define TVM_EDITLABELA			(TV_FIRST + 14)
#Define TVM_EDITLABELW          (TV_FIRST + 65)

#Define TVM_GETEDITCONTROL      (TV_FIRST + 15)
#Define TVM_GETVISIBLECOUNT     (TV_FIRST + 16)
#Define TVM_HITTEST             (TV_FIRST + 17)

#Define TV_HITTESTINFO     		TVHITTESTINFO

#Define TVHT_NOWHERE            00001H
#Define TVHT_ONITEMICON         00002H
#Define TVHT_ONITEMLABEL        00004H
#Define TVHT_ONITEM             (TVHT_ONITEMICON | TVHT_ONITEMLABEL | TVHT_ONITEMSTATEICON)
#Define TVHT_ONITEMINDENT       00008H
#Define TVHT_ONITEMBUTTON       00010H
#Define TVHT_ONITEMRIGHT        00020H
#Define TVHT_ONITEMSTATEICON    00040H

#Define TVHT_ABOVE              00100H
#Define TVHT_BELOW              00200H
#Define TVHT_TORIGHT            00400H
#Define TVHT_TOLEFT             00800H


#Define TVM_CREATEDRAGIMAGE     (TV_FIRST + 18)
#Define TVM_SORTCHILDREN        (TV_FIRST + 19)
#Define TVM_ENSUREVISIBLE       (TV_FIRST + 20)
#Define TVM_SORTCHILDRENCB      (TV_FIRST + 21)
#Define TVM_ENDEDITLABELNOW     (TV_FIRST + 22)

#Define TVM_GETISEARCHSTRINGA   (TV_FIRST + 23)
#Define TVM_GETISEARCHSTRINGW   (TV_FIRST + 64)

#Define TVM_SETTOOLTIPS         (TV_FIRST + 24)
#Define TVM_GETTOOLTIPS         (TV_FIRST + 25)
#Define TVM_SETINSERTMARK       (TV_FIRST + 26)

#Define TVM_SETUNICODEFORMAT    CCM_SETUNICODEFORMAT
#Define TVM_GETUNICODEFORMAT    CCM_GETUNICODEFORMAT

#Define TVM_SETITEMHEIGHT		(TV_FIRST + 27)
#Define TVM_GETITEMHEIGHT		(TV_FIRST + 28)
#Define TVM_SETBKCOLOR			(TV_FIRST + 29)
#Define TVM_SETTEXTCOLOR		(TV_FIRST + 30)
#Define TVM_GETBKCOLOR          (TV_FIRST + 31)
#Define TVM_GETTEXTCOLOR        (TV_FIRST + 32)
#Define TVM_SETSCROLLTIME       (TV_FIRST + 33)
#Define TVM_GETSCROLLTIME       (TV_FIRST + 34)

#Define TVM_SETINSERTMARKCOLOR  (TV_FIRST + 37)
#Define TVM_GETINSERTMARKCOLOR  (TV_FIRST + 38)

#Define TV_SORTCB      			TVSORTCB

#Define NM_TREEVIEWW            NMTREEVIEWW
#Define NM_TREEVIEWA            NMTREEVIEWA
#Define NM_TREEVIEW             NMTREEVIEW

#Define TVN_SELCHANGINGA        (TVN_FIRST - 1)
#Define TVN_SELCHANGINGW        (TVN_FIRST - 50)
#Define TVN_SELCHANGEDA         (TVN_FIRST - 2)
#Define TVN_SELCHANGEDW         (TVN_FIRST - 51)

#Define TVC_UNKNOWN             00000H
#Define TVC_BYMOUSE             00001H
#Define TVC_BYKEYBOARD          00002H

#Define TVN_GETDISPINFOA        (TVN_FIRST - 3)
#Define TVN_GETDISPINFOW        (TVN_FIRST - 52)
#Define TVN_SETDISPINFOA        (TVN_FIRST - 4)
#Define TVN_SETDISPINFOW        (TVN_FIRST - 53)

#Define TVIF_DI_SETITEM         01000H

#Define TV_DISPINFOA            NMTVDISPINFOA
#Define TV_DISPINFOW            NMTVDISPINFOW

#Define TV_DISPINFO             NMTVDISPINFO

#Define TVN_ITEMEXPANDINGA		(TVN_FIRST - 5)
#Define TVN_ITEMEXPANDINGW      (TVN_FIRST - 54)
#Define TVN_ITEMEXPANDEDA		(TVN_FIRST - 6)
#Define TVN_ITEMEXPANDEDW       (TVN_FIRST - 55)
#Define TVN_BEGINDRAGA			(TVN_FIRST - 7)
#Define TVN_BEGINDRAGW          (TVN_FIRST - 56)
#Define TVN_BEGINRDRAGA			(TVN_FIRST - 8)
#Define TVN_BEGINRDRAGW         (TVN_FIRST - 57)
#Define TVN_DELETEITEMA			(TVN_FIRST - 9)
#Define TVN_DELETEITEMW         (TVN_FIRST - 58)
#Define TVN_BEGINLABELEDITA		(TVN_FIRST - 10)
#Define TVN_BEGINLABELEDITW     (TVN_FIRST - 59)
#Define TVN_ENDLABELEDITA		(TVN_FIRST - 11)
#Define TVN_ENDLABELEDITW       (TVN_FIRST - 60)
#Define TVN_KEYDOWN             (TVN_FIRST - 12)

#Define TVN_GETINFOTIPA			(TVN_FIRST - 13)
#Define TVN_GETINFOTIPW			(TVN_FIRST - 14)
#Define TVN_SINGLEEXPAND		(TVN_FIRST - 15)

#Define TV_KEYDOWN      		NMTVKEYDOWN

#Define TVCDRF_NOIMAGES         000010000H

#Define WC_COMBOBOXEXW          L"ComboBoxEx32"
#Define WC_COMBOBOXEXA          "ComboBoxEx32"

#Define CBEIF_TEXT              000000001H
#Define CBEIF_IMAGE             000000002H
#Define CBEIF_SELECTEDIMAGE     000000004H
#Define CBEIF_OVERLAY           000000008H
#Define CBEIF_INDENT            000000010H
#Define CBEIF_LPARAM            000000020H

#Define CBEIF_DI_SETITEM        010000000H

#Define CBEM_INSERTITEMA		(WM_USER + 1)
#Define CBEM_SETIMAGELIST		(WM_USER + 2)
#Define CBEM_GETIMAGELIST		(WM_USER + 3)
#Define CBEM_GETITEMA			(WM_USER + 4)
#Define CBEM_SETITEMA			(WM_USER + 5)
#Define CBEM_DELETEITEM         CB_DELETESTRING
#Define CBEM_GETCOMBOCONTROL	(WM_USER + 6)
#Define CBEM_GETEDITCONTROL		(WM_USER + 7)
#Define CBEM_SETEXSTYLE			(WM_USER + 8)
#Define CBEM_SETEXTENDEDSTYLE	(WM_USER + 14)
#Define CBEM_GETEXSTYLE			(WM_USER + 9)
#Define CBEM_GETEXTENDEDSTYLE	(WM_USER + 9)
#Define CBEM_SETUNICODEFORMAT   CCM_SETUNICODEFORMAT
#Define CBEM_GETUNICODEFORMAT   CCM_GETUNICODEFORMAT

#Define CBES_EX_NOEDITIMAGE         000000001H
#Define CBES_EX_NOEDITIMAGEINDENT   000000002H
#Define CBES_EX_PATHWORDBREAKPROC   000000004H
#Define CBES_EX_NOSIZELIMIT         000000008H
#Define CBES_EX_CASESENSITIVE		000000010H

#Define CBEN_GETDISPINFOA		(CBEN_FIRST - 0)
#Define CBEN_INSERTITEM			(CBEN_FIRST - 1)
#Define CBEN_DELETEITEM			(CBEN_FIRST - 2)
#Define CBEN_BEGINEDIT			(CBEN_FIRST - 4)
#Define CBEN_ENDEDITA			(CBEN_FIRST - 5)
#Define CBEN_ENDEDITW			(CBEN_FIRST - 6)
#Define CBEN_GETDISPINFOW		(CBEN_FIRST - 7)
#Define CBEN_DRAGBEGINA			(CBEN_FIRST - 8)
#Define CBEN_DRAGBEGINW			(CBEN_FIRST - 9)

#Define CBENF_KILLFOCUS         1
#Define CBENF_RETURN            2
#Define CBENF_ESCAPE            3
#Define CBENF_DROPDOWN          4

#Define CBEMAXSTRLEN 			260

#Define WC_TABCONTROLA          "SysTabControl32"
#Define WC_TABCONTROLW          L"SysTabControl32"

#Define TCS_SCROLLOPPOSITE      00001H
#Define TCS_BOTTOM              00002H
#Define TCS_RIGHT               00002H
#Define TCS_MULTISELECT         00004H
#Define TCS_FLATBUTTONS         00008H
#Define TCS_FORCEICONLEFT       00010H
#Define TCS_FORCELABELLEFT      00020H
#Define TCS_HOTTRACK            00040H
#Define TCS_VERTICAL            00080H
#Define TCS_TABS                00000H
#Define TCS_BUTTONS             00100H
#Define TCS_SINGLELINE          00000H
#Define TCS_MULTILINE           00200H
#Define TCS_RIGHTJUSTIFY        00000H
#Define TCS_FIXEDWIDTH          00400H
#Define TCS_RAGGEDRIGHT         00800H
#Define TCS_FOCUSONBUTTONDOWN   01000H
#Define TCS_OWNERDRAWFIXED      02000H
#Define TCS_TOOLTIPS            04000H
#Define TCS_FOCUSNEVER          08000H

#Define TCS_EX_FLATSEPARATORS   000000001H
#Define TCS_EX_REGISTERDROP     000000002H

#Define TCM_GETIMAGELIST        (TCM_FIRST + 2)
#Define TCM_SETIMAGELIST        (TCM_FIRST + 3)
#Define TCM_GETITEMCOUNT        (TCM_FIRST + 4)

#Define TCIF_TEXT               00001H
#Define TCIF_IMAGE              00002H
#Define TCIF_RTLREADING         00004H
#Define TCIF_PARAM              00008H
#Define TCIF_STATE              00010H

#Define TCIS_BUTTONPRESSED      00001H
#Define TCIS_HIGHLIGHTED        00002H

#Define TC_ITEMHEADERA          TCITEMHEADERA
#Define TC_ITEMHEADERW          TCITEMHEADERW

#Define TC_ITEMHEADER           TCITEMHEADER

#Define TC_ITEMA                TCITEMA
#Define TC_ITEMW                TCITEMW
#Define TC_ITEM                 TCITEM

#Define TCM_GETITEMA			(TCM_FIRST + 5)
#Define TCM_GETITEMW			(TCM_FIRST + 60)

#Define TCM_SETITEMA            (TCM_FIRST + 6)
#Define TCM_SETITEMW            (TCM_FIRST + 61)

#Define TCM_INSERTITEMA         (TCM_FIRST + 7)
#Define TCM_INSERTITEMW         (TCM_FIRST + 62)

#Define TCM_DELETEITEM          (TCM_FIRST + 8)
#Define TCM_DELETEALLITEMS      (TCM_FIRST + 9)
#Define TCM_GETITEMRECT         (TCM_FIRST + 10)
#Define TCM_GETCURSEL           (TCM_FIRST + 11)
#Define TCM_SETCURSEL           (TCM_FIRST + 12)

#Define TCHT_NOWHERE            00001H
#Define TCHT_ONITEMICON         00002H
#Define TCHT_ONITEMLABEL        00004H
#Define TCHT_ONITEM             (TCHT_ONITEMICON | TCHT_ONITEMLABEL)

#Define LPTC_HITTESTINFO        LPTCHITTESTINFO
#Define TC_HITTESTINFO          TCHITTESTINFO

#Define TCM_HITTEST             (TCM_FIRST + 13)
#Define TCM_SETITEMEXTRA        (TCM_FIRST + 14)

#Define TCM_ADJUSTRECT          (TCM_FIRST + 40)
#Define TCM_SETITEMSIZE         (TCM_FIRST + 41)
#Define TCM_REMOVEIMAGE         (TCM_FIRST + 42)
#Define TCM_SETPADDING          (TCM_FIRST + 43)
#Define TCM_GETROWCOUNT         (TCM_FIRST + 44)
#Define TCM_GETTOOLTIPS         (TCM_FIRST + 45)
#Define TCM_SETTOOLTIPS         (TCM_FIRST + 46)
#Define TCM_GETCURFOCUS         (TCM_FIRST + 47)
#Define TCM_SETCURFOCUS         (TCM_FIRST + 48)
#Define TCM_SETMINTABWIDTH      (TCM_FIRST + 49)
#Define TCM_DESELECTALL         (TCM_FIRST + 50)
#Define TCM_HIGHLIGHTITEM       (TCM_FIRST + 51)
#Define TCM_SETEXTENDEDSTYLE	(TCM_FIRST + 52)
#Define TCM_GETEXTENDEDSTYLE    (TCM_FIRST + 53)

#Define TCM_SETUNICODEFORMAT     CCM_SETUNICODEFORMAT
#Define TCM_GETUNICODEFORMAT     CCM_GETUNICODEFORMAT

#Define TCN_KEYDOWN             (TCN_FIRST - 0)
#Define TC_KEYDOWN              NMTCKEYDOWN

#Define TCN_SELCHANGE           (TCN_FIRST - 1)
#Define TCN_SELCHANGING         (TCN_FIRST - 2)
#Define TCN_GETOBJECT			(TCN_FIRST - 3)

#Define ANIMATE_CLASSW          L"SysAnimate32"
#Define ANIMATE_CLASSA          "SysAnimate32"

#Define ACS_CENTER              00001H
#Define ACS_TRANSPARENT         00002H
#Define ACS_AUTOPLAY            00004H
#Define ACS_TIMER               00008H

#Define ACM_OPENA				(WM_USER + 100)
#Define ACM_OPENW               (WM_USER + 103)

#Define ACM_PLAY                (WM_USER + 101)
#define ACM_STOP                (WM_USER+102)

#Define ACN_START               1
#Define ACN_STOP                2

#Define MONTHCAL_CLASSW         L"SysMonthCal32"
#Define MONTHCAL_CLASSA         "SysMonthCal32"

#Define MCM_FIRST           	01000H

#Define MCM_GETCURSEL       	(MCM_FIRST + 1)
#Define MCM_SETCURSEL       	(MCM_FIRST + 2)
#Define MCM_GETMAXSELCOUNT  	(MCM_FIRST + 3)
#Define MCM_SETMAXSELCOUNT  	(MCM_FIRST + 4)
#Define MCM_GETSELRANGE     	(MCM_FIRST + 5)
#Define MCM_SETSELRANGE     	(MCM_FIRST + 6)
#Define MCM_GETMONTHRANGE   	(MCM_FIRST + 7)
#Define MCM_SETDAYSTATE     	(MCM_FIRST + 8)
#Define MCM_GETMINREQRECT   	(MCM_FIRST + 9)
#Define MCM_SETCOLOR            (MCM_FIRST + 10)
#Define MCM_GETCOLOR            (MCM_FIRST + 11)

#Define MCSC_BACKGROUND			0
#Define MCSC_TEXT				1
#Define MCSC_TITLEBK			2
#Define MCSC_TITLETEXT			3
#Define MCSC_MONTHBK			4
#Define MCSC_TRAILINGTEXT		5

#Define MCM_SETTODAY    		(MCM_FIRST + 12)
#Define MCM_GETTODAY    		(MCM_FIRST + 13)
#Define MCM_HITTEST          	(MCM_FIRST + 14)

#Define MCHT_TITLE              000010000H
#Define MCHT_CALENDAR           000020000H
#Define MCHT_TODAYLINK          000030000H

#Define MCHT_NEXT               001000000H
#Define MCHT_PREV               002000000H

#Define MCHT_NOWHERE            000000000H

#Define MCHT_TITLEBK			(MCHT_TITLE)
#Define MCHT_TITLEMONTH			(MCHT_TITLE | 00001H)
#Define MCHT_TITLEYEAR			(MCHT_TITLE | 00002H)
#Define MCHT_TITLEBTNNEXT		(MCHT_TITLE | MCHT_NEXT | 00003H)
#Define MCHT_TITLEBTNPREV		(MCHT_TITLE | MCHT_PREV | 00003H)

#Define MCHT_CALENDARBK			(MCHT_CALENDAR)
#Define MCHT_CALENDARDATE		(MCHT_CALENDAR | 00001H)
#Define MCHT_CALENDARDATENEXT	(MCHT_CALENDARDATE | MCHT_NEXT)
#Define MCHT_CALENDARDATEPREV	(MCHT_CALENDARDATE | MCHT_PREV)
#Define MCHT_CALENDARDAY		(MCHT_CALENDAR | 00002H)
#Define MCHT_CALENDARWEEKNUM	(MCHT_CALENDAR | 00003H)

#Define MCM_SETFIRSTDAYOFWEEK 	(MCM_FIRST + 15)
#Define MCM_GETFIRSTDAYOFWEEK 	(MCM_FIRST + 16)
#Define MCM_GETRANGE 			(MCM_FIRST + 17)
#Define MCM_SETRANGE 			(MCM_FIRST + 18)
#Define MCM_GETMONTHDELTA		(MCM_FIRST + 19)
#Define MCM_SETMONTHDELTA 		(MCM_FIRST + 20)
#Define MCM_GETMAXTODAYWIDTH	(MCM_FIRST + 21)

#Define MCM_SETUNICODEFORMAT    CCM_SETUNICODEFORMAT
#Define MCM_GETUNICODEFORMAT    CCM_GETUNICODEFORMAT

#Define MCN_SELCHANGE			(MCN_FIRST + 1)

#Define MCN_GETDAYSTATE			(MCN_FIRST + 3)
#Define MCN_SELECT          	(MCN_FIRST + 4)

#Define MCS_DAYSTATE        	00001H
#Define MCS_MULTISELECT     	00002H
#Define MCS_WEEKNUMBERS     	00004H
#Define MCS_NOTODAYCIRCLE   	00008H
#Define MCS_NOTODAY         	00010H

#Define GMR_VISIBLE     		0
#Define GMR_DAYSTATE    		1

#Define DATETIMEPICK_CLASSW     L"SysDateTimePick32"
#Define DATETIMEPICK_CLASSA     "SysDateTimePick32"

#Define DTM_FIRST        		01000H

#Define DTM_GETSYSTEMTIME   	(DTM_FIRST + 1)
#Define DTM_SETSYSTEMTIME   	(DTM_FIRST + 2)
#Define DTM_GETRANGE 			(DTM_FIRST + 3)
#Define DTM_SETRANGE 			(DTM_FIRST + 4)

#Define DTM_SETFORMATA			(DTM_FIRST + 5)
#Define DTM_SETFORMATW			(DTM_FIRST + 50)

#Define DTM_SETMCCOLOR    		(DTM_FIRST + 6)
#Define DTM_GETMCCOLOR    		(DTM_FIRST + 7)
#Define DTM_GETMONTHCAL   		(DTM_FIRST + 8)
#Define DTM_SETMCFONT			(DTM_FIRST + 9)
#Define DTM_GETMCFONT     		(DTM_FIRST + 10)

#Define DTS_UPDOWN          	00001H
#Define DTS_SHOWNONE        	00002H
#Define DTS_SHORTDATEFORMAT		00000H
#Define DTS_LONGDATEFORMAT		00004H
#Define DTS_TIMEFORMAT			00009H
#Define DTS_APPCANPARSE			00010H
#Define DTS_RIGHTALIGN			00020H

#Define DTN_DATETIMECHANGE		(DTN_FIRST + 1)

#Define DTN_USERSTRINGA			(DTN_FIRST + 2)
#Define DTN_USERSTRINGW			(DTN_FIRST + 15)

#Define DTN_WMKEYDOWNA			(DTN_FIRST + 3)
#Define DTN_WMKEYDOWNW			(DTN_FIRST + 16)

#Define DTN_FORMATA				(DTN_FIRST + 4)
#Define DTN_FORMATW				(DTN_FIRST + 17)

#Define DTN_FORMATQUERYA		(DTN_FIRST + 5)
#Define DTN_FORMATQUERYW		(DTN_FIRST + 18)

#Define DTN_DROPDOWN			(DTN_FIRST + 6)
#Define DTN_CLOSEUP				(DTN_FIRST + 7)

#Define GDTR_MIN				00001H
#Define GDTR_MAX				00002H

#Define GDT_ERROR				(-1)
#Define GDT_VALID				0
#Define GDT_NONE				1

#Define WC_IPADDRESSW           L"SysIPAddress32"
#Define WC_IPADDRESSA           "SysIPAddress32"

#Define IPM_CLEARADDRESS		(WM_USER + 100)
#Define IPM_SETADDRESS			(WM_USER + 101)
#Define IPM_GETADDRESS			(WM_USER + 102)
#Define IPM_SETRANGE			(WM_USER + 103)
#Define IPM_SETFOCUS			(WM_USER + 104)
#Define IPM_ISBLANK				(WM_USER + 105)

#Define IPN_FIELDCHANGED		(IPN_FIRST - 0)

#Define WC_PAGESCROLLERW        L"SysPager"
#Define WC_PAGESCROLLERA        "SysPager"

#Define PGS_VERT                000000000H
#Define PGS_HORZ                000000001H
#Define PGS_AUTOSCROLL          000000002H
#Define PGS_DRAGNDROP           000000004H

#Define PGF_INVISIBLE			0
#Define PGF_NORMAL				1
#Define PGF_GRAYED				2
#Define PGF_DEPRESSED			4
#Define PGF_HOT         		8

#Define PGB_TOPORLEFT       	0
#Define PGB_BOTTOMORRIGHT   	1

#Define PGM_SETCHILD			(PGM_FIRST + 1)
#Define PGM_RECALCSIZE          (PGM_FIRST + 2)
#Define PGM_FORWARDMOUSE        (PGM_FIRST + 3)
#Define PGM_SETBKCOLOR          (PGM_FIRST + 4)
#Define PGM_GETBKCOLOR          (PGM_FIRST + 5)
#Define PGM_SETBORDER			(PGM_FIRST + 6)
#Define PGM_GETBORDER			(PGM_FIRST + 7)
#Define PGM_SETPOS              (PGM_FIRST + 8)
#Define PGM_GETPOS              (PGM_FIRST + 9)
#Define PGM_SETBUTTONSIZE       (PGM_FIRST + 10)
#Define PGM_GETBUTTONSIZE       (PGM_FIRST + 11)
#Define PGM_GETBUTTONSTATE      (PGM_FIRST + 12)

#Define PGM_GETDROPTARGET       CCM_GETDROPTARGET

#Define PGN_SCROLL				(PGN_FIRST - 1)

#Define PGF_SCROLLUP        	1
#Define PGF_SCROLLDOWN      	2
#Define PGF_SCROLLLEFT      	4
#Define PGF_SCROLLRIGHT     	8

#Define PGK_SHIFT           	1
#Define PGK_CONTROL         	2
#Define PGK_MENU            	4

#Define PGN_CALCSIZE			(PGN_FIRST - 2)

#Define PGF_CALCWIDTH			1
#Define PGF_CALCHEIGHT			2

#Define WC_NATIVEFONTCTLW       L"NativeFontCtl"
#Define WC_NATIVEFONTCTLA       "NativeFontCtl"

#Define NFS_EDIT                00001H
#Define NFS_STATIC              00002H
#Define NFS_LISTCOMBO           00004H
#Define NFS_BUTTON              00008H
#Define NFS_ALL                 00010H

#IFNDEF WM_MOUSEHOVER
	#Define WM_MOUSEHOVER		002A1H
	#Define WM_MOUSELEAVE		002A3H
#ENDIF

#IFNDEF TME_HOVER
	#Define TME_HOVER       	000000001H
	#Define TME_LEAVE       	000000002H
	#Define TME_QUERY       	040000000H
	#Define TME_CANCEL      	080000000H

	#Define HOVER_DEFAULT   	0FFFFFFFFH

	TRACKMOUSEEVENT Struct
		cbSize DD
		dwFlags DD
		hwndTrack DD
		dwHoverTime DD
	EndS
#ENDIF

#Define WSB_PROP_CYVSCROLL  	000000001H
#Define WSB_PROP_CXHSCROLL  	000000002H
#Define WSB_PROP_CYHSCROLL  	000000004H
#Define WSB_PROP_CXVSCROLL  	000000008H
#Define WSB_PROP_CXHTHUMB   	000000010H
#Define WSB_PROP_CYVTHUMB   	000000020H
#Define WSB_PROP_VBKGCOLOR  	000000040H
#Define WSB_PROP_HBKGCOLOR  	000000080H
#Define WSB_PROP_VSTYLE     	000000100H
#Define WSB_PROP_HSTYLE     	000000200H
#Define WSB_PROP_WINSTYLE   	000000400H
#Define WSB_PROP_PALETTE    	000000800H
#Define WSB_PROP_MASK       	000000FFFH

#Define FSB_FLAT_MODE			2
#Define FSB_ENCARTA_MODE		1
#Define FSB_REGULAR_MODE		0


INITCOMMONCONTROLSEX Struct
	dwSize DD
	dwICC DD
EndS

COLORSCHEME Struct
	dwSize DD
	clrBtnHighlight DD
	clrBtnShadow DD
EndS

NMMOUSE Struct
	hdr NMHDR <>
	dwItemSpec DD
	dwItemData DD
	pt POINT <>
	dwHitInfo DD
EndS

NMOBJECTNOTIFY Struct
	hdr NMHDR <>
	iItem DD
	piid DD
	pObject DD
	hResult DD
	dwFlags DD
EndS

NMKEY Struct
	hdr NMHDR <>
	nVKey DD
	uFlags DD
EndS

NMCHAR Struct
	hdr NMHDR <>
	chr DD
	dwItemPrev DD
	dwItemNext DD
EndS

NMCUSTOMDRAW Struct
	hdr NMHDR <>
	dwDrawStage DD
	hdc DD
	rc RECT <>
	dwItemSpec DD
	uItemState DD
	lItemlParam DD
EndS

NMTTCUSTOMDRAW Struct
	nmcd NMCUSTOMDRAW <>
	uDrawFlags DD
EndS

IMAGELISTDRAWPARAMS Struct
	cbSize DD
	himl DD
	i DD
	hdcDst DD
	x DD
	y DD
	lx DD
	cy DD
	xBitmap DD
	yBitmap DD
	rgbBk DD
	rgbFg DD
	fStyle DD
	dwRop DD
EndS

IMAGEINFO Struct
	hbmImage DD
	hbmMask DD
	Unused1 DD
	Unused2 DD
	rcImage RECT <>
EndS

HDITEMA Struct
	mask DD
	cxy DD
	pszText DD
	hbm DD
	cchTextMax DD
	fmt DD
	lParam DD
	iImage DD
	iOrder DD
EndS

HDITEMW Struct
	mask DD
	cxy DD
	pszText DD
	hbm DD
	cchTextMax DD
	fmt DD
	lParam DD
	iImage DD
	iOrder DD
EndS

HDLAYOUT Struct
	prc DD
	pwpos DD
EndS

HDHITTESTINFO Struct
	pt POINT <>
    flags DD
    iItem DD
EndS

NMHEADERA Struct
	hdr NMHDR <>
	iItem DD
	iButton DD
	pitem DD
EndS

NMHEADERW Struct
	hdr NMHDR <>
	iItem DD
	iButton DD
	pitem DD
EndS

NMHDDISPINFOA Struct
	hdr NMHDR <>
	iItem DD
	mask DD
	pszText DD
	cchTextMax DD
	iImage DD
	lParam DD
EndS

NMHDDISPINFOW Struct
	hdr NMHDR <>
	iItem DD
	mask DD
	pszText DD
	cchTextMax DD
	iImage DD
	lParam DD
EndS

TBBUTTON Struct
	iBitmap DD
	idCommand DD
	fsState DB
	fsStyle DB
	bReserved DW
	dwData DD
	iString DD
EndS

COLORMAP Struct
	from DD
	to DD
EndS

NMTBCUSTOMDRAW Struct
	nmcd NMCUSTOMDRAW <>
	hbrMonoDither DD
	hbrLines DD
	hpenLines DD
	clrText DD
	clrMark DD
	clrTextHighlight DD
	clrBtnFace DD
	clrBtnHighlight DD
	clrHighlightHotTrack DD
	rcText RECT <>
	nStringBkMode DD
	nHLStringBkMode DD
EndS

TBADDBITMAP Struct
	hInst DD
	nID DD
EndS

TBSAVEPARAMSA Struct
	hkr DD
	pszSubKey DD
	pszValueName DD
EndS

TBSAVEPARAMSW Struct
	hkr DD
	pszSubKey DD
	pszValueName DD
EndS

TBINSERTMARK Struct
	iButton DD
	dwFlags DD
EndS

TBREPLACEBITMAP Struct
	hInstOld DD
	nIDOld DD
	hInstNew DD
	nIDNew DD
	nButtons DD
EndS

TBBUTTONINFOA Struct
	cbSize DD
	dwMask DD
	idCommand DD
	iImage DD
	fsState DB
	fsStyle DB
	lx DW
	lParam DD
	pszText DD
	cchText DD
EndS

TBBUTTONINFOW Struct
	cbSize DD
	dwMask DD
	idCommand DD
	iImage DD
	fsState DB
	fsStyle DB
	lx DW
	lParam DD
	pszText DD
	cchText DD
EndS

NMTBHOTITEM Struct
	hdr NMHDR <>
	idOld DD
	idNew DD
	dwFlags DD
EndS

NMTBGETINFOTIPA Struct
	hdr NMHDR <>
	pszText DD
	cchTextMax DD
	iItem DD
	lParam DD
EndS

NMTBGETINFOTIPW Struct
	hdr NMHDR <>
	pszText DD
	cchTextMax DD
	iItem DD
	lParam DD
EndS

NMTBDISPINFOA Struct
	hdr NMHDR <>
	dwMask DD
	idCommand DD
	lParam DD
	iImage DD
	pszText DD
	cchText DD
EndS

NMTBDISPINFOW Struct
	hdr NMHDR <>
	dwMask DD
	idCommand DD
	lParam DD
	iImage DD
	pszText DD
	cchText DD
EndS

NMTOOLBARA Struct
	hdr NMHDR <>
	iItem DD
    tbButton TBBUTTON <>
	cchText DD
	pszText DD
EndS

NMTOOLBARW Struct
	hdr NMHDR <>
	iItem DD
    tbButton TBBUTTON <>
	cchText DD
	pszText DD
EndS

REBARINFO Struct
	cbSize DD
	fMask DD
	himl DD
EndS

REBARBANDINFOA Struct
	cbSize DD
	fMask DD
	fStyle DD
	clrFore DD
	clrBack DD
	lpText DD
	cch DD
	iImage DD
	hwndChild DD
	cxMinChild DD
	cyMinChild DD
	lx DD
	hbmBack DD
	wID DD
	cyChild DD
	cyMaxChild DD
	cyIntegral DD
	cxIdeal DD
	lParam DD
	cxHeader DD
EndS

REBARBANDINFOW Struct
	cbSize DD
	fMask DD
	fStyle DD
	clrFore DD
	clrBack DD
	lpText DD
	cch DD
	iImage DD
	hwndChild DD
	cxMinChild DD
	cyMinChild DD
	lx DD
	hbmBack DD
	wID DD
	cyChild DD
	cyMaxChild DD
	cyIntegral DD
	cxIdeal DD
	lParam DD
	cxHeader DD
EndS

NMREBARCHILDSIZE Struct
	hdr NMHDR <>
	uBand DD
	wID DD
	rcChild RECT <>
	rcBand <>
EndS

NMREBAR Struct
	hdr NMHDR <>
	dwMask DD
	uBand DD
	fStyle DD
	wID DD
	lParam DD
EndS

NMRBAUTOSIZE Struct
	hdr NMHDR <>
	fChanged DD
	rcTarget RECT <>
	rcActual RECT <>
EndS

RBHITTESTINFO Struct
	pt POINT <>
	flags DD
	iBand DD
EndS

TTTOOLINFOA Struct
	cbSize DD
	uFlags DD
	hwnd DD
	uId DD
	rect RECT <>
	hInst DD
	lpszText DD
	lParam DD
EndS

TTTOOLINFOW Struct
	cbSize DD
	uFlags DD
	hwnd DD
	uId DD
	rect RECT <>
	hInst DD
	lpszText DD
	lParam DD
EndS

TTHITTESTINFOA Struct
	hwnd DD
	pt POINT <>
	ti TTTOOLINFOA <>
EndS

TTHITTESTINFOW Struct
	hwnd DD
	pt POINT <>
	ti TTTOOLINFOW <>
EndS

NMTTDISPINFOA Struct
	hdr NMHDR <>
	lpszText DD
	szText DB 80 Dup ?
	hInst DD
	uFlags DD
	lParam DD
EndS

NMTTDISPINFOW Struct
	hdr NMHDR <>
	lpszText DD
	szText DW 80 Dup ?
	hInst DD
	uFlags DD
	lParam DD
EndS

DRAGLISTINFO Struct
	uNotification DD
	hWnd DD
	ptCursor POINT <>
EndS

UDACCEL Struct
	nSec DD
	nInc DD
EndS

NMUPDOWN Struct
	hdr NMHDR <>
	iPos DD
	iDelta DD
EndS

PBRANGE Struct
	iLow DD
	iHigh DD
EndS

LVITEMA Struct
	mask DD
	iItem DD
	iSubItem DD
	state DD
	stateMask DD
	pszText DD
	cchTextMax DD
	iImage DD
	lParam DD
	iIndent DD
EndS

LVITEMW Struct
	mask DD
	iItem DD
	iSubItem DD
	state DD
	stateMask DD
	pszText DD
	cchTextMax DD
	iImage DD
	lParam DD
	iIndent DD
EndS

LVFINDINFOA Struct
	flags DD
	psz DD
	lParam DD
	pt POINT <>
	vkDirection DD
EndS

LVFINDINFOW Struct
	flags DD
	psz DD
	lParam DD
	pt POINT <>
	vkDirection DD
EndS

LVHITTESTINFO Struct
	pt POINT <>
	flags DD
	iItem DD
	iSubItem DD
EndS

LVCOLUMNA Struct
	mask DD
	fmt DD
	lx DD
	pszText DD
	cchTextMax DD
	iSubItem DD
	iImage DD
	iOrder  DD
EndS

LVCOLUMNW Struct
	mask DD
	fmt DD
	lx DD
	pszText DD
	cchTextMax DD
	iSubItem DD
	iImage DD
	iOrder  DD
EndS

LVBKIMAGEA Struct
	ulFlags DD
	hbm DD
	pszImage DD
	cchImageMax DD
	xOffsetPercent DD
	yOffsetPercent DD
EndS

LVBKIMAGEW Struct
	ulFlags DD
	hbm DD
	pszImage DD
	cchImageMax DD
	xOffsetPercent DD
	yOffsetPercent DD
EndS

NMLISTVIEW Struct
	hdr NMHDR <>
	iItem DD
	iSubItem DD
	uNewState DD
	uOldState DD
	uChanged DD
	ptAction POINT <>
	lParam DD
EndS

NMITEMACTIVATE Struct
	hdr NMHDR <>
	iItem DD
	iSubItem DD
	uNewState DD
	uOldState DD
	uChanged DD
	ptAction POINT <>
	lParam DD
	uKeyFlags DD
EndS

NMLVCUSTOMDRAW Struct
	nmcd NMCUSTOMDRAW <>
	clrText DD
	clrTextBk DD
	iSubItem DD
EndS

NMLVCACHEHINT Struct
	hdr NMHDR <>
	iFrom DD
	iTo DD
EndS

NMLVFINDITEM Struct
	hdr NMHDR <>
	iStart DD
	lvfi LVFINDINFO <>
EndS

NMLVODSTATECHANGE Struct
	hdr NMHDR <>
	iFrom DD
	iTo DD
	uNewState DD
	uOldState DD
EndS

NMLVDISPINFOA Struct
	hdr NMHDR <>
    item LVITEMA <>
EndS

NMLVDISPINFOW Struct
	hdr NMHDR <>
    item LVITEMW <>
EndS

NMLVKEYDOWN Struct
	hdr NMHDR <>
	wVKey DW
	flags DD
EndS

NMLVGETINFOTIPA Struct
	hdr NMHDR <>
	dwFlags DD
	pszText DD
	cchTextMax DD
	iItem DD
	iSubItem DD
	lParam DD
EndS

NMLVGETINFOTIPW Struct
	hdr NMHDR <>
	dwFlags DD
	pszText DD
	cchTextMax DD
	iItem DD
	iSubItem DD
	lParam DD
EndS

TVITEMA Struct
	mask DD
	hItem DD
	state DD
	stateMask DD
	pszText DD
	cchTextMax DD
	iImage DD
	iSelectedImage DD
	cChildren DD
	lParam DD
EndS

TVITEMW Struct
	mask DD
	hItem DD
	state DD
	stateMask DD
	pszText DD
	cchTextMax DD
	iImage DD
	iSelectedImage DD
	cChildren DD
	lParam DD
EndS

TVITEMEXA Struct
	mask DD
	hItem DD
	state DD
	stateMask DD
	pszText DD
	cchTextMax DD
	iImage DD
	iSelectedImage DD
	cChildren DD
	lParam DD
	iIntegral DD
EndS

TVITEMEXW Struct
	mask DD
	hItem DD
	state DD
	stateMask DD
	pszText DD
	cchTextMax DD
	iImage DD
	iSelectedImage DD
	cChildren DD
	lParam DD
	iIntegral DD
EndS

TVINSERTSTRUCTA Struct
	hParent DD
	hInsertAfter DD
	Union
		itemex TVITEMEXA <>
		item TV_ITEMA <>
	EndUnion
EndS

TVINSERTSTRUCTW Struct
	hParent DD
	hInsertAfter DD
	Union
		itemex TVITEMEXW <>
		item TV_ITEMW <>
	EndUnion
EndS

TVHITTESTINFO Struct
	pt POINT <>
	flags DD
	hItem DD
EndS

TVSORTCB Struct
	hParent DD
	lpfnCompare DD
	lParam DD
EndS

NMTREEVIEWA Struct
	hdr NMHDR <>
	action DD
	itemOld TVITEMA <>
	itemNew TVITEMA <>
	ptDrag POINT <>
EndS

NMTREEVIEWW Struct
	hdr NMHDR <>
	action DD
	itemOld TVITEMW <>
	itemNew TVITEMW <>
	ptDrag POINT <>
EndS

NMTVDISPINFOA Struct
	hdr NMHDR <>
	item TVITEMA <>
EndS

NMTVDISPINFOW Struct
	hdr NMHDR <>
	item TVITEMW <>
EndS

NMTVKEYDOWN Struct
	hdr NMHDR <>
	wVKey DW
	flags DD
EndS

NMTVCUSTOMDRAW Struct
	nmcd NMCUSTOMDRAW <>
	clrText DD
	clrTextBk DD
	iLevel DD
EndS

NMTVGETINFOTIPA Struct
	hdr NMHDR <>
	pszText DD
	cchTextMax DD
	hItem DD
	lParam DD
EndS

NMTVGETINFOTIPW Struct
	hdr NMHDR <>
	pszText DD
	cchTextMax DD
	hItem DD
	lParam DD
EndS

COMBOBOXEXITEMA Struct
	mask DD
	iItem DD
	pszText DD
	cchTextMax DD
	iImage DD
	iSelectedImage DD
	iOverlay DD
	iIndent DD
	lParam DD
EndS

COMBOBOXEXITEMW Struct
	mask DD
	iItem DD
	pszText DD
	cchTextMax DD
	iImage DD
	iSelectedImage DD
	iOverlay DD
	iIndent DD
	lParam DD
EndS

NMCOMBOBOXEXA Struct
	hdr NMHDR <>
	ceItem COMBOBOXEXITEMA <>
EndS

NMCOMBOBOXEXW Struct
	hdr NMHDR <>
	ceItem COMBOBOXEXITEMW <>
EndS

NMCBEDRAGBEGINA Struct
	hdr NMHDR <>
	iItemid DD
	szText DB CBEMAXSTRLEN Dup ?
EndS

NMCBEDRAGBEGINW Struct
	hdr NMHDR <>
	iItemid DD
	szText DW CBEMAXSTRLEN Dup ?
EndS

NMCBEENDEDITA Struct
	hdr NMHDR <>
	fChanged DD
	iNewSelection DD
	szText DB CBEMAXSTRLEN Dup ?
	iWhy DD
EndS

NMCBEENDEDITW Struct
	hdr NMHDR <>
	fChanged DD
	iNewSelection DD
	szText DW CBEMAXSTRLEN Dup ?
	iWhy DD
EndS

TCITEMHEADERA Struct
	mask DD
	lpReserved1 DD
	lpReserved2 DD
	pszText DD
	cchTextMax DD
	iImage DD
EndS

TCITEMHEADERW Struct
	mask DD
	lpReserved1 DD
	lpReserved2 DD
	pszText DD
	cchTextMax DD
	iImage DD
EndS

TCITEMA Struct
	mask DD
	dwState DD
	dwStateMask DD
	pszText DD
	cchTextMax DD
	iImage DD
	lParam DD
EndS

TCITEMW Struct
	mask DD
	dwState DD
	dwStateMask DD
	pszText DD
	cchTextMax DD
	iImage DD
	lParam DD
EndS

TCHITTESTINFO Struct
	pt POINT <>
	flags DD
EndS

NMTCKEYDOWN Struct
	hdr NMHDR <>
	wVKey DW
	flags DD
EndS

MCHITTESTINFO Struct
	cbSize DD
	pt POINT <>
	uHit  DD
	st SYSTEMTIME <>
EndS

NMSELCHANGE Struct
	nmhdr NMHDR <>
	stSelStart SYSTEMTIME <>
	stSelEnd SYSTEMTIME <>
EndS

NMDAYSTATE Struct
	nmhdr NMHDR <>
	stStart SYSTEMTIME <>
	cDayState DD
	prgDayState DD
EndS

NMDATETIMECHANGE Struct
	nmhdr NMHDR <>
	dwFlags DD
	st SYSTEMTIME <>
EndS

NMDATETIMESTRINGA Struct
	nmhdr NMHDR <>
	pszUserString DD
	st SYSTEMTIME <>
	dwFlags DD
EndS

NMDATETIMESTRINGW Struct
	nmhdr NMHDR <>
	pszUserString DD
	st SYSTEMTIME <>
	dwFlags DD
EndS

NMDATETIMEWMKEYDOWNA Struct
	nmhdr NMHDR <>
	nVirtKey DD
	pszFormat DD
	st SYSTEMTIME <>
EndS

NMDATETIMEWMKEYDOWNW Struct
	nmhdr NMHDR <>
	nVirtKey DD
	pszFormat DD
	st SYSTEMTIME <>
EndS

NMDATETIMEFORMATA Struct
	nmhdr NMHDR <>
	pszFormat DD
	st SYSTEMTIME <>
	pszDisplay DD
	szDisplay DB 64 Dup ?
EndS

NMDATETIMEFORMATW Struct
	nmhdr NMHDR <>
	pszFormat DD
	st SYSTEMTIME <>
	pszDisplay DD
	szDisplay DW 64 Dup ?
EndS

NMDATETIMEFORMATQUERYA Struct
	nmhdr NMHDR <>
	pszFormat DD
	szMax SIZE <>
EndS

NMDATETIMEFORMATQUERYW Struct
	nmhdr NMHDR <>
	pszFormat DD
	szMax SIZE <>
EndS

NMIPADDRESS Struct
	hdr NMHDR <>
	iField DD
	iValue DD
EndS

NMPGSCROLL Struct
	hdr NMHDR <>
	fwKeys DW
	rcParent RECT <>
	iDir DD
	iXpos DD
	iYpos DD
	iScroll DD
EndS

NMPGCALCSIZE Struct
	hdr NMHDR <>
	dwFlag DD
	iWidth DD
	iHeight DD
EndS


#IF STRINGS UNICODE
	#Define ImageList_LoadImage ImageList_LoadImageW
	#Define WC_HEADER WC_HEADERW
	#Define HDITEM HDITEMW
	#Define HDM_INSERTITEM HDM_INSERTITEMW
	#Define HDM_GETITEM HDM_GETITEMW
	#Define HDM_SETITEM HDM_SETITEMW
	#Define HDN_ITEMCHANGING HDN_ITEMCHANGINGW
	#Define HDN_ITEMCHANGED HDN_ITEMCHANGEDW
	#Define HDN_ITEMCLICK HDN_ITEMCLICKW
	#Define HDN_ITEMDBLCLICK HDN_ITEMDBLCLICKW
	#Define HDN_DIVIDERDBLCLICK HDN_DIVIDERDBLCLICKW
	#Define HDN_BEGINTRACK HDN_BEGINTRACKW
	#Define HDN_ENDTRACK HDN_ENDTRACKW
	#Define HDN_TRACK HDN_TRACKW
	#Define NMHEADER NMHEADERW
	#Define NMHDDISPINFO NMHDDISPINFOW
	#Define TOOLBARCLASSNAME TOOLBARCLASSNAMEW
	#Define TBSAVEPARAMS TBSAVEPARAMSW
	#Define TB_GETBUTTONTEXT TB_GETBUTTONTEXTW
	#Define TB_SAVERESTORE TB_SAVERESTOREW
	#Define TB_ADDSTRING TB_ADDSTRINGW
	#Define TB_MAPACCELERATOR TB_MAPACCELERATORW
	#Define TBBUTTONINFO TBBUTTONINFOW
	#Define TB_GETBUTTONINFO TB_GETBUTTONINFOW
	#Define TB_SETBUTTONINFO TB_SETBUTTONINFOW
	#Define TB_INSERTBUTTON TB_INSERTBUTTONW
	#Define TB_ADDBUTTONS TB_ADDBUTTONSW
	#Define TBN_GETINFOTIP TBN_GETINFOTIPW
	#Define NMTBGETINFOTIP NMTBGETINFOTIPW
	#Define TBN_GETDISPINFO TBN_GETDISPINFOW
	#Define NMTBDISPINFO NMTBDISPINFOW
	#Define TBN_GETBUTTONINFO TBN_GETBUTTONINFOW
	#Define NMTOOLBAR NMTOOLBARW
	#Define REBARCLASSNAME REBARCLASSNAMEW
	#Define REBARBANDINFO REBARBANDINFOW
	#Define RB_INSERTBAND RB_INSERTBANDW
	#Define RB_SETBANDINFO RB_SETBANDINFOW
	#Define RB_GETBANDINFO RB_GETBANDINFOW
	#Define RB_GETBANDINFO RB_GETBANDINFOW
	#Define TOOLTIPS_CLASS TOOLTIPS_CLASSW
	#Define TTTOOLINFO TTTOOLINFOW
	#Define TTM_ADDTOOL TTM_ADDTOOLW
	#Define TTM_DELTOOL TTM_DELTOOLW
	#Define TTM_NEWTOOLRECT TTM_NEWTOOLRECTW
	#Define TTM_GETTOOLINFO TTM_GETTOOLINFOW
	#Define TTM_SETTOOLINFO TTM_SETTOOLINFOW
	#Define TTM_HITTEST TTM_HITTESTW
	#Define TTM_GETTEXT TTM_GETTEXTW
	#Define TTM_UPDATETIPTEXT TTM_UPDATETIPTEXTW
	#Define TTM_ENUMTOOLS TTM_ENUMTOOLSW
	#Define TTM_GETCURRENTTOOL TTM_GETCURRENTTOOLW
	#Define TTHITTESTINFO TTHITTESTINFOW
	#Define TTN_GETDISPINFO TTN_GETDISPINFOW
	#Define NMTTDISPINFO NMTTDISPINFOW
	#Define CreateStatusWindow CreateStatusWindowW
	#Define DrawStatusText DrawStatusTextW
	#Define STATUSCLASSNAME STATUSCLASSNAMEW
	#Define SB_GETTEXT SB_GETTEXTW
	#Define SB_SETTEXT SB_SETTEXTW
	#Define SB_GETTEXTLENGTH SB_GETTEXTLENGTHW
	#Define SB_SETTIPTEXT SB_SETTIPTEXTW
	#Define SB_GETTIPTEXT SB_GETTIPTEXTW
	#Define TRACKBAR_CLASS TRACKBAR_CLASSW
	#Define UPDOWN_CLASS UPDOWN_CLASSW
	#Define PROGRESS_CLASS PROGRESS_CLASSW
	#Define HOTKEY_CLASS HOTKEY_CLASSW
	#Define WC_LISTVIEW WC_LISTVIEWW
	#Define LVITEM LVITEMW
	#Define LVM_GETITEM LVM_GETITEMW
	#Define LVM_SETITEM LVM_SETITEMW
	#Define LVM_INSERTITEM LVM_INSERTITEMW
	#Define LVFINDINFO LVFINDINFOW
	#Define LVM_FINDITEM LVM_FINDITEMW
	#Define LVM_GETSTRINGWIDTH LVM_GETSTRINGWIDTHW
	#Define LVM_EDITLABEL LVM_EDITLABELW
	#Define LVCOLUMN LVCOLUMNW
	#Define LVM_GETCOLUMN LVM_GETCOLUMNW
	#Define LVM_SETCOLUMN LVM_SETCOLUMNW
	#Define LVM_INSERTCOLUMN LVM_INSERTCOLUMNW
	#Define LVM_GETITEMTEXT LVM_GETITEMTEXTW
	#Define LVM_SETITEMTEXT LVM_SETITEMTEXTW
	#Define LVM_GETISEARCHSTRING LVM_GETISEARCHSTRINGW
	#Define LVBKIMAGE LVBKIMAGEW
	#Define LVM_SETBKIMAGE LVM_SETBKIMAGEW
	#Define LVM_GETBKIMAGE LVM_GETBKIMAGEW
	#Define LVN_ODFINDITEM LVN_ODFINDITEMW
	#Define LVN_BEGINLABELEDIT LVN_BEGINLABELEDITW
	#Define LVN_ENDLABELEDIT LVN_ENDLABELEDITW
	#Define LVN_GETDISPINFO LVN_GETDISPINFOW
	#Define LVN_SETDISPINFO LVN_SETDISPINFOW
	#Define NMLVDISPINFO NMLVDISPINFOW
	#Define LVN_GETINFOTIP LVN_GETINFOTIPW
	#Define NMLVGETINFOTIP NMLVGETINFOTIPW
	#Define WC_TREEVIEW WC_TREEVIEWW
	#Define TVITEM TVITEMW
	#Define TVITEMEX TVITEMEXW
	#Define TVINSERTSTRUCT TVINSERTSTRUCTW
	#Define TVM_INSERTITEM TVM_INSERTITEMW
	#Define TVM_GETITEM TVM_GETITEMW
	#Define TVM_SETITEM TVM_SETITEMW
	#Define TVM_EDITLABEL TVM_EDITLABELW
	#Define TVM_GETISEARCHSTRING TVM_GETISEARCHSTRINGW
	#Define NMTREEVIEW NMTREEVIEWW
	#Define NMTVDISPINFO NMTVDISPINFOW
	#Define TVN_SELCHANGING TVN_SELCHANGINGW
	#Define TVN_SELCHANGED TVN_SELCHANGEDW
	#Define TVN_GETDISPINFO TVN_GETDISPINFOW
	#Define TVN_SETDISPINFO TVN_SETDISPINFOW
	#Define TVN_ITEMEXPANDING TVN_ITEMEXPANDINGW
	#Define TVN_ITEMEXPANDED TVN_ITEMEXPANDEDW
	#Define TVN_BEGINDRAG TVN_BEGINDRAGW
	#Define TVN_BEGINRDRAG TVN_BEGINRDRAGW
	#Define TVN_DELETEITEM TVN_DELETEITEMW
	#Define TVN_BEGINLABELEDIT TVN_BEGINLABELEDITW
	#Define TVN_ENDLABELEDIT TVN_ENDLABELEDITW
	#Define TVN_GETINFOTIP TVN_GETINFOTIPW
	#Define NMTVGETINFOTIP NMTVGETINFOTIPW
	#Define WC_COMBOBOXEX WC_COMBOBOXEXW
	#Define COMBOBOXEXITEM COMBOBOXEXITEMW
	#Define CBEM_INSERTITEM CBEM_INSERTITEMW
	#Define CBEM_SETITEM CBEM_SETITEMW
	#Define CBEM_GETITEM CBEM_GETITEMW
	#Define NMCOMBOBOXEX NMCOMBOBOXEXW
	#Define CBEN_GETDISPINFO CBEN_GETDISPINFOW
	#Define CBEN_DRAGBEGIN CBEN_DRAGBEGINW
	#Define CBEN_ENDEDIT CBEN_ENDEDITW
	#Define NMCBEDRAGBEGIN NMCBEDRAGBEGINW
	#Define NMCBEENDEDIT NMCBEENDEDITW
	#Define WC_TABCONTROL WC_TABCONTROLW
	#Define TCITEMHEADER TCITEMHEADERW
	#Define TCITEM TCITEMW
	#Define TCM_GETITEM TCM_GETITEMW
	#Define TCM_SETITEM TCM_SETITEMW
	#Define TCM_INSERTITEM TCM_INSERTITEMW
	#Define ANIMATE_CLASS ANIMATE_CLASSW
	#Define ACM_OPEN ACM_OPENW
	#Define MONTHCAL_CLASS MONTHCAL_CLASSW
	#Define DATETIMEPICK_CLASS DATETIMEPICK_CLASSW
	#Define DTM_SETFORMAT DTM_SETFORMATW
	#Define DTN_USERSTRING DTN_USERSTRINGW
	#Define NMDATETIMESTRING NMDATETIMESTRINGW
	#Define DTN_WMKEYDOWN DTN_WMKEYDOWNW
	#Define DTN_FORMAT DTN_FORMATW
	#Define NMDATETIMEFORMAT NMDATETIMEFORMATW
	#Define DTN_FORMATQUERY DTN_FORMATQUERYW
	#Define NMDATETIMEFORMATQUERY NMDATETIMEFORMATQUERYW
	#Define WC_IPADDRESS WC_IPADDRESSW
	#Define WC_PAGESCROLLER WC_PAGESCROLLERW
	#Define WC_NATIVEFONTCTL WC_NATIVEFONTCTLW
#ELSE
	#Define ImageList_LoadImage ImageList_LoadImageA
	#Define WC_HEADER WC_HEADERA
	#Define HDITEM HDITEMA
	#Define HDM_INSERTITEM HDM_INSERTITEMA
	#Define HDM_GETITEM HDM_GETITEMA
	#Define HDM_SETITEM HDM_SETITEMA
	#Define HDN_ITEMCHANGING HDN_ITEMCHANGINGA
	#Define HDN_ITEMCHANGED HDN_ITEMCHANGEDA
	#Define HDN_ITEMCLICK HDN_ITEMCLICKA
	#Define HDN_ITEMDBLCLICK HDN_ITEMDBLCLICKA
	#Define HDN_DIVIDERDBLCLICK HDN_DIVIDERDBLCLICKA
	#Define HDN_BEGINTRACK HDN_BEGINTRACKA
	#Define HDN_ENDTRACK HDN_ENDTRACKA
	#Define HDN_TRACK HDN_TRACKA
	#Define NMHEADER NMHEADERA
	#Define NMHDDISPINFO NMHDDISPINFOA
	#Define TOOLBARCLASSNAME TOOLBARCLASSNAMEA
	#Define TBSAVEPARAMS TBSAVEPARAMSA
	#Define TB_GETBUTTONTEXT TB_GETBUTTONTEXTA
	#Define TB_SAVERESTORE TB_SAVERESTOREA
	#Define TB_ADDSTRING TB_ADDSTRINGA
	#Define TB_MAPACCELERATOR TB_MAPACCELERATORA
	#Define TBBUTTONINFO TBBUTTONINFOA
	#Define TB_GETBUTTONINFO TB_GETBUTTONINFOA
	#Define TB_SETBUTTONINFO TB_SETBUTTONINFOA
	#Define TB_INSERTBUTTON TB_INSERTBUTTONA
	#Define TB_ADDBUTTONS TB_ADDBUTTONSA
	#Define TBN_GETINFOTIP TBN_GETINFOTIPA
	#Define NMTBGETINFOTIP NMTBGETINFOTIPA
	#Define TBN_GETDISPINFO TBN_GETDISPINFOA
	#Define NMTBDISPINFO NMTBDISPINFOA
	#Define TBN_GETBUTTONINFO TBN_GETBUTTONINFOA
	#Define NMTOOLBAR NMTOOLBARA
	#Define REBARCLASSNAME REBARCLASSNAMEA
	#Define REBARBANDINFO REBARBANDINFOA
	#Define RB_INSERTBAND RB_INSERTBANDA
	#Define RB_SETBANDINFO RB_SETBANDINFOA
	#Define RB_GETBANDINFO RB_GETBANDINFOA
	#Define RB_GETBANDINFO RB_GETBANDINFOA
	#Define TOOLTIPS_CLASS TOOLTIPS_CLASSA
	#Define TTTOOLINFO TTTOOLINFOA
	#Define TTM_ADDTOOL TTM_ADDTOOLA
	#Define TTM_DELTOOL TTM_DELTOOLA
	#Define TTM_NEWTOOLRECT TTM_NEWTOOLRECTA
	#Define TTM_GETTOOLINFO TTM_GETTOOLINFOA
	#Define TTM_SETTOOLINFO TTM_SETTOOLINFOA
	#Define TTM_HITTEST TTM_HITTESTA
	#Define TTM_GETTEXT TTM_GETTEXTA
	#Define TTM_UPDATETIPTEXT TTM_UPDATETIPTEXTA
	#Define TTM_ENUMTOOLS TTM_ENUMTOOLSA
	#Define TTM_GETCURRENTTOOL TTM_GETCURRENTTOOLA
	#Define TTHITTESTINFO TTHITTESTINFOA
	#Define TTN_GETDISPINFO TTN_GETDISPINFOA
	#Define NMTTDISPINFO NMTTDISPINFOA
	#Define CreateStatusWindow CreateStatusWindowA
	#Define DrawStatusText DrawStatusTextA
	#Define STATUSCLASSNAME STATUSCLASSNAMEA
	#Define SB_GETTEXT SB_GETTEXTA
	#Define SB_SETTEXT SB_SETTEXTA
	#Define SB_GETTEXTLENGTH SB_GETTEXTLENGTHA
	#Define SB_SETTIPTEXT SB_SETTIPTEXTA
	#Define SB_GETTIPTEXT SB_GETTIPTEXTA
	#Define TRACKBAR_CLASS TRACKBAR_CLASSA
	#Define UPDOWN_CLASS UPDOWN_CLASSA
	#Define PROGRESS_CLASS PROGRESS_CLASSA
	#Define HOTKEY_CLASS HOTKEY_CLASSA
	#Define WC_LISTVIEW WC_LISTVIEWA
	#Define LVITEM LVITEMA
	#Define LVM_GETITEM LVM_GETITEMA
	#Define LVM_SETITEM LVM_SETITEMA
	#Define LVM_INSERTITEM LVM_INSERTITEMA
	#Define LVFINDINFO LVFINDINFOA
	#Define LVM_FINDITEM LVM_FINDITEMA
	#Define LVM_GETSTRINGWIDTH LVM_GETSTRINGWIDTHA
	#Define LVM_EDITLABEL LVM_EDITLABELA
	#Define LVCOLUMN LVCOLUMNA
	#Define LVM_GETCOLUMN LVM_GETCOLUMNA
	#Define LVM_SETCOLUMN LVM_SETCOLUMNA
	#Define LVM_INSERTCOLUMN LVM_INSERTCOLUMNA
	#Define LVM_GETITEMTEXT LVM_GETITEMTEXTA
	#Define LVM_SETITEMTEXT LVM_SETITEMTEXTA
	#Define LVM_GETISEARCHSTRING LVM_GETISEARCHSTRINGA
	#Define LVBKIMAGE LVBKIMAGEA
	#Define LVM_SETBKIMAGE LVM_SETBKIMAGEA
	#Define LVM_GETBKIMAGE LVM_GETBKIMAGEA
	#Define LVN_ODFINDITEM LVN_ODFINDITEMA
	#Define LVN_BEGINLABELEDIT LVN_BEGINLABELEDITA
	#Define LVN_ENDLABELEDIT LVN_ENDLABELEDITA
	#Define LVN_GETDISPINFO LVN_GETDISPINFOA
	#Define LVN_SETDISPINFO LVN_SETDISPINFOA
	#Define NMLVDISPINFO NMLVDISPINFOA
	#Define LVN_GETINFOTIP LVN_GETINFOTIPA
	#Define NMLVGETINFOTIP NMLVGETINFOTIPA
	#Define WC_TREEVIEW WC_TREEVIEWA
	#Define TVITEM TVITEMA
	#Define TVITEMEX TVITEMEXA
	#Define TVINSERTSTRUCT TVINSERTSTRUCTA
	#Define TVM_INSERTITEM TVM_INSERTITEMA
	#Define TVM_GETITEM TVM_GETITEMA
	#Define TVM_SETITEM TVM_SETITEMA
	#Define TVM_EDITLABEL TVM_EDITLABELA
	#Define TVM_GETISEARCHSTRING TVM_GETISEARCHSTRINGA
	#Define NMTREEVIEW NMTREEVIEWA
	#Define NMTVDISPINFO NMTVDISPINFOA
	#Define TVN_SELCHANGING TVN_SELCHANGINGA
	#Define TVN_SELCHANGED TVN_SELCHANGEDA
	#Define TVN_GETDISPINFO TVN_GETDISPINFOA
	#Define TVN_SETDISPINFO TVN_SETDISPINFOA
	#Define TVN_ITEMEXPANDING TVN_ITEMEXPANDINGA
	#Define TVN_ITEMEXPANDED TVN_ITEMEXPANDEDA
	#Define TVN_BEGINDRAG TVN_BEGINDRAGA
	#Define TVN_BEGINRDRAG TVN_BEGINRDRAGA
	#Define TVN_DELETEITEM TVN_DELETEITEMA
	#Define TVN_BEGINLABELEDIT TVN_BEGINLABELEDITA
	#Define TVN_ENDLABELEDIT TVN_ENDLABELEDITA
	#Define TVN_GETINFOTIP TVN_GETINFOTIPA
	#Define NMTVGETINFOTIP NMTVGETINFOTIPA
	#Define WC_COMBOBOXEX WC_COMBOBOXEXA
	#Define COMBOBOXEXITEM COMBOBOXEXITEMA
	#Define CBEM_INSERTITEM CBEM_INSERTITEMA
	#Define CBEM_SETITEM CBEM_SETITEMA
	#Define CBEM_GETITEM CBEM_GETITEMA
	#Define NMCOMBOBOXEX NMCOMBOBOXEXA
	#Define CBEN_GETDISPINFO CBEN_GETDISPINFOA
	#Define CBEN_DRAGBEGIN CBEN_DRAGBEGINA
	#Define CBEN_ENDEDIT CBEN_ENDEDITA
	#Define NMCBEDRAGBEGIN NMCBEDRAGBEGINA
	#Define NMCBEENDEDIT NMCBEENDEDITA
	#Define WC_TABCONTROL WC_TABCONTROLA
	#Define TCITEMHEADER TCITEMHEADERA
	#Define TCITEM TCITEMA
	#Define TCM_GETITEM TCM_GETITEMA
	#Define TCM_SETITEM TCM_SETITEMA
	#Define TCM_INSERTITEM TCM_INSERTITEMA
	#Define ANIMATE_CLASS ANIMATE_CLASSA
	#Define ACM_OPEN ACM_OPENA
	#Define MONTHCAL_CLASS MONTHCAL_CLASSA
	#Define DATETIMEPICK_CLASS DATETIMEPICK_CLASSA
	#Define DTM_SETFORMAT DTM_SETFORMATA
	#Define DTN_USERSTRING DTN_USERSTRINGA
	#Define NMDATETIMESTRING NMDATETIMESTRINGA
	#Define DTN_WMKEYDOWN DTN_WMKEYDOWNA
	#Define DTN_FORMAT DTN_FORMATA
	#Define NMDATETIMEFORMAT NMDATETIMEFORMATA
	#Define DTN_FORMATQUERY DTN_FORMATQUERYA
	#Define NMDATETIMEFORMATQUERY NMDATETIMEFORMATQUERYA
	#Define WC_IPADDRESS WC_IPADDRESSA
	#Define WC_PAGESCROLLER WC_PAGESCROLLERA
	#Define WC_NATIVEFONTCTL WC_NATIVEFONTCTLA
#ENDIF

#ENDIF ;COMMCTRL_INC
