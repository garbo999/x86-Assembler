// Generated .IDL file (by the OLE/COM Object Viewer)
// 
// typelib filename: hxvz.dll
#IFNDEF MSHELPCONTROLS_H
#DEFINE MSHELPCONTROLS_H

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define GUID_TLBID_MSHelpControls <0x314111BA,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

#define GUID_IID_IHxTreeViewEvents <0x314111BB,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>
#define DISP_NODECLICK 0x00002000
;#define IHxTreeViewEvents_NodeClick 0x00002000
#define DISP_NODERIGHTCLICK 0x00002003
;#define IHxTreeViewEvents_NodeRightClick 0x00002003

#DEFINE GUID_IID_IHxIndexViewEvents <0x314111DF,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>
#define DISP_ITEMCLICK 0x00002001
;#define IHxIndexViewEvents_ItemClick 0x00002001
#define DISP_ITEMSELECT 0x00002002
;IHxIndexViewEvents_ItemSelect 0x00002002

#define GUID_CLSID_HxTocCtrl <0x314111B8,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>
#define GUID_IID_IHxTreeView <0x314111B9,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxTreeView STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_Hierarchy PTR
	put_Hierarchy PTR
	put_ImageList PTR
	get_ImageList PTR
	get_HideSelection PTR
	put_HideSelection PTR
	get_LineStyle PTR
	put_LineStyle PTR
	get_TreeStyle PTR
	put_TreeStyle PTR
	put_BackColor PTR
	get_BackColor PTR
	put_ForeColor PTR
	get_ForeColor PTR
	put_BorderStyle PTR
	get_BorderStyle PTR
 	put_Appearance PTR
	get_Appearance PTR
	put_MousePointer PTR
	get_MousePointer PTR
	Refresh PTR
	put_Font PTR
	put_ref_Font PTR
	get_Font PTR
	Synchronize PTR
	get_Selection PTR
	get_LangId PTR
	put_LangId PTR
	get_FontSource PTR
	put_FontSource PTR
ENDS

HxTreeLineStyle_TreeLines = 0
HxTreeLineStyle_RootLines = 1

HxTreeStyle_TextOnly = 0
HxTreeStyle_PictureText = 1
HxTreeStyle_PlusMinusText = 2
HxTreeStyle_PlusPictureText = 3
HxTreeStyle_TreelinesText = 4
HxTreeStyle_TreelinesPictureText = 5
HxTreeStyle_TreelinesPlusMinusText = 6
HxTreeStyle_TreelinesPlusMinusPictureText = 7

HxBorderStyle_None = 0
HxBorderStyle_FixedSingle = 1

HxAppearance_Flat = 0
HxAppearance_3D = 1

HxMousePointer_Default = 0
HxMousePointer_Arrow = 1
HxMousePointer_Cross = 2
HxMousePointer_IBeam = 3
HxMousePointer_Icon = 4
HxMousePointer_Size = 5
HxMousePointer_SizeNESW = 6
HxMousePointer_SizeNS = 7
HxMousePointer_SizeNWSE = 8
HxMousePointer_SizeEW = 9
HxMousePointer_UpArrow = 10,
HxMousePointer_Hourglass = 11
HxMousePointer_NoDrop = 12
HxMousePointer_ArrowHourglass = 13
HxMousePointer_ArrowQuestion = 14
HxMousePointer_SizeAll = 15
HxMousePointer_Custom = 99

HxFontCollection = 0
HxFontExternal = 1

#DEFINE GUID_CLSID_HxIndexCtrl <0x314111C6,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>
#DEFINE GUID_IID_IHxIndexView <0x314111C4,0xA502,0x11D2,<0xBB,0xCA,0x00,0xC0,0x4F,0x8E,0xC2,0x94>>

IHxIndexView STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	get_IndexData PTR
	put_IndexData PTR
	put_Selection PTR
	get_Selection PTR
	put_BackColor PTR
	get_BackColor PTR
	put_ForeColor PTR
	get_ForeColor PTR
	put_BorderStyle PTR
	get_BorderStyle PTR
	put_Appearance PTR
	get_Appearance PTR
	put_MousePointer PTR
	get_MousePointer PTR
	SelectItem PTR
	ClickItem PTR
	Refresh PTR
	put_Font PTR
	put_ref_Font PTR
	get_Font PTR
	put_HighlightForeColor PTR
	get_HighlightForeColor PTR
	put_HighlightBackColor PTR
	get_HighlightBackColor PTR
	put_FocusHighlightForeColor PTR
	get_FocusHighlightForeColor PTR
	put_FocusHighlightBackColor PTR
	get_FocusHighlightBackColor PTR
	get_LangId PTR
	put_LangId PTR
	get_FontSource PTR
	put_FontSource PTR
ENDS

#ENDIF
