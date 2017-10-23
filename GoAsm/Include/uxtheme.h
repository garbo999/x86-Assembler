#ifndef UXTHEME_H
#define UXTHEME_H

/* Windows Theme API definitions (Windows XP) */
#IFNDEF COMMCTRL_H
	#include commctrl.h
#ENDIF

#IFDEF LINKFILES
	#dynamiclinkfile uxtheme.dll
#ENDIF

#define DTT_GRAYED  0x1

; ENUM BP_BUFFERFORMAT
BPBF_COMPATIBLEBITMAP = 0
BPBF_DIB = 1
BPBF_TOPDOWNDIB = 2
BPBF_TOPDOWNMONODIB = 3

#define HTTB_BACKGROUNDSEG  0x0000
#define HTTB_FIXEDBORDER  0x0002
#define HTTB_CAPTION  0x0004
#define HTTB_RESIZINGBORDER_LEFT  0x0010
#define HTTB_RESIZINGBORDER_TOP  0x0020
#define HTTB_RESIZINGBORDER_RIGHT  0x0040
#define HTTB_RESIZINGBORDER_BOTTOM  0x0080
#define HTTB_RESIZINGBORDER  (HTTB_RESIZINGBORDER_LEFT|HTTB_RESIZINGBORDER_TOP|HTTB_RESIZINGBORDER_RIGHT|HTTB_RESIZINGBORDER_BOTTOM)
#define HTTB_SIZINGTEMPLATE  0x0100
#define HTTB_SYSTEMSIZINGMARGINS  0x0200

#IF WINVER >= NTDDI_VISTA
	#define MAX_INTLIST_COUNT 402
	#define MAX_THEMECOLOR  64
	#define MAX_THEMESIZE   64
#ELSE
	#define MAX_INTLIST_COUNT  10
#ENDIF

#IF WINVER >= NTDDI_VISTA
	#define DTPB_WINDOWDC           0x00000001
	#define DTPB_USECTLCOLORSTATIC  0x00000002
	#define DTPB_USEERASEBKGND      0x00000004
#ENDIF

WTA_NONCLIENT = 1

WTA_OPTIONS STRUCT
	dwFlags DD          // values for each style option specified in the bitmask
	dwMask DD           // bitmask for flags that are changing
                        // valid options are: WTNCA_NODRAWCAPTION, WTNCA_NODRAWICON, WTNCA_NOSYSMENU
ENDS

#define WTNCA_NODRAWCAPTION       0x00000001    // don't draw the window caption
#define WTNCA_NODRAWICON          0x00000002    // don't draw the system icon
#define WTNCA_NOSYSMENU           0x00000004    // don't expose the system menu icon functionality
#define WTNCA_NOMIRRORHELP        0x00000008    // don't mirror the question mark, even in RTL layout
#define WTNCA_VALIDBITS           (WTNCA_NODRAWCAPTION | WTNCA_NODRAWICON | WTNCA_NOSYSMENU | WTNCA_NOMIRRORHELP)


#define ETDT_DISABLE  0x00000001
#define ETDT_ENABLE  0x00000002
#define ETDT_USETABTEXTURE  0x00000004
#define ETDT_ENABLETAB  (ETDT_ENABLE|ETDT_USETABTEXTURE)
#if WINVER >= NTDDI_VISTA
	#define ETDT_USEAEROWIZARDTABTEXTURE    0x00000008
	#define ETDT_ENABLEAEROWIZARDTAB (ETDT_ENABLE | ETDT_USEAEROWIZARDTABTEXTURE)
	#define ETDT_VALIDBITS (ETDT_DISABLE | ETDT_ENABLE | ETDT_USETABTEXTURE | ETDT_USEAEROWIZARDTABTEXTURE)
#endif

#define STAP_ALLOW_NONCLIENT (1<<0)
#define STAP_ALLOW_CONTROLS (1<<1)
#define STAP_ALLOW_WEBCONTENT (1<<2)
#define STAP_VALIDBITS (STAP_ALLOW_NONCLIENT | STAP_ALLOW_CONTROLS | STAP_ALLOW_WEBCONTENT)

#define SZ_THDOCPROP_DISPLAYNAME  L"DisplayName"
#define SZ_THDOCPROP_CANONICALNAME  L"ThemeName"
#define SZ_THDOCPROP_TOOLTIP  L"ToolTip"
#define SZ_THDOCPROP_AUTHOR  L"author"

#define OTD_FORCE_RECT_SIZING 0x00000001          // make all parts size to rect
#define OTD_NONCLIENT 0x00000002          // set if hTheme to be used for nonclient area
#define OTD_VALIDBITS 0x00000003

#define DTBG_CLIPRECT 0x00000001  // rcClip has been specified
#define DTBG_DRAWSOLID 0x00000002  // DEPRECATED: draw transparent/alpha images as solid
#define DTBG_OMITBORDER 0x00000004  // don't draw border of part
#define DTBG_OMITCONTENT 0x00000008  // don't draw content area of part
#define DTBG_COMPUTINGREGION 0x00000010  // TRUE if calling to compute region
#define DTBG_MIRRORDC 0x00000020  // assume the hdc is mirrorred and
                                            // flip images as appropriate (currently 
                                            // only supported for bgtype=imagefile)
#define DTBG_NOMIRROR 0x00000040  // don't mirror the output, overrides everything else 
#define DTBG_VALIDBITS (DTBG_CLIPRECT | DTBG_DRAWSOLID | DTBG_OMITBORDER | DTBG_OMITCONTENT | DTBG_COMPUTINGREGION | DTBG_MIRRORDC | DTBG_NOMIRROR)

#define GBF_DIRECT      0x00000001      // direct dereferencing.
#define GBF_COPY        0x00000002      // create a copy of the bitmap
#define GBF_VALIDBITS   (GBF_DIRECT | GBF_COPY)

DTBGOPTS STRUCT
	dwSize DD            // size of the struct
	dwFlags DD           // which options have been specified
	rcClip RECT          // clipping rectangle
ENDS

#define DTT_TEXTCOLOR       (1 << 0)      // crText has been specified
#define DTT_BORDERCOLOR     (1 << 1)      // crBorder has been specified
#define DTT_SHADOWCOLOR     (1 << 2)      // crShadow has been specified
#define DTT_SHADOWTYPE      (1 << 3)      // iTextShadowType has been specified
#define DTT_SHADOWOFFSET    (1 << 4)      // ptShadowOffset has been specified
#define DTT_BORDERSIZE      (1 << 5)      // iBorderSize has been specified
#define DTT_FONTPROP        (1 << 6)      // iFontPropId has been specified
#define DTT_COLORPROP       (1 << 7)      // iColorPropId has been specified
#define DTT_STATEID         (1 << 8)      // IStateId has been specified
#define DTT_CALCRECT        (1 << 9)      // Use pRect as and in/out parameter
#define DTT_APPLYOVERLAY    (1 << 10)     // fApplyOverlay has been specified
#define DTT_GLOWSIZE        (1 << 11)     // iGlowSize has been specified
#define DTT_CALLBACK        (1 << 12)     // pfnDrawTextCallback has been specified
#define DTT_COMPOSITED      (1 << 13)     // Draws text with antialiased alpha (needs a DIB section)
#define DTT_VALIDBITS       8191

DTTOPTS STRUCT
	dwSize DD              // size of the struct
	dwFlags DD             // which options have been specified
	crText COLORREF              // color to use for text fill
	crBorder COLORREF            // color to use for text outline
	crShadow COLORREF            // color to use for text shadow
	iTextShadowType INT32     // TST_SINGLE or TST_CONTINUOUS
	ptShadowOffset POINT      // where shadow is drawn (relative to text)
	iBorderSize INT32         // Border radius around text
	iFontPropId INT32         // Font property to use for the text instead of TMT_FONT
	iColorPropId INT32        // Color property to use for the text instead of TMT_TEXTCOLOR
	iStateId INT32            // Alternate state id
	fApplyOverlay BOOL       // Overlay text on top of any text effect?
	iGlowSize INT32           // Glow radious around text
	pfnDrawTextCallback PTR // Callback for DrawText
	lParam LPARAM              // Parameter for callback
ENDS

// enum BP_BUFFERFORMAT
BPBF_COMPATIBLEBITMAP = 0    // Compatible bitmap
BPBF_DIB = 1                 // Device-independent bitmap
BPBF_TOPDOWNDIB = 2          // Top-down device-independent bitmap
BPBF_TOPDOWNMONODIB = 3       // Top-down monochrome device-independent bitmap

#define BPBF_COMPOSITED BPBF_TOPDOWNDIB

// enum BP_ANIMATIONSTYLE
BPAS_NONE = 0                // No animation
BPAS_LINEAR = 1              // Linear fade animation
BPAS_CUBIC = 2               // Cubic fade animation
BPAS_SINE = 3                // Sinusoid fade animation

// BP_ANIMATIONPARAMS
BP_ANIMATIONPARAMS STRUCT
	cbSize DD
	dwFlags DD // BPAF_ flags
	style ENUM
	dwDuration DD
ENDS

#define BPPF_ERASE               0x0001 // Empty the buffer during BeginBufferedPaint()
#define BPPF_NOCLIP              0x0002 // Don't apply the target DC's clip region to the double buffer
#define BPPF_NONCLIENT           0x0004 // Using a non-client DC

#define DTT_GRAYED 0x00000001          // draw a grayed-out string (this is deprecated)
#define DTT_FLAGS2VALIDBITS 0x00000001

TS_MIN = 0
TS_TRUE = 1
TS_DRAW = 2

BPPF_ERASE = 1
BPPF_NOCLIP = 2
BPPF_NONCLIENT = 4

MARGINS STRUCT
	cxLeftWidth DD
	cxRightWidth DD
	cyTopHeight DD
	cyBottomHeight DD
ENDS

INTLIST STRUCT
	iValueCount DD
	iValues DD MAX_INTLIST_COUNT DUP
ENDS

BP_PAINTPARAMS STRUCT
	cbSize DD
	dwFlags DD
	prcExclude PTR
	pBlendFunction PTR
ENDS

PO_STATE = 0
PO_PART = 1
PO_CLASS = 2
PO_GLOBAL = 3
PO_NOTFOUND = 4

#endif /* UXTHEME_H */
