#ifndef USP10_H
#define USP10_H

/* Unicode Complex Script processor (USP) definitions */

#IFNDEF WINDOWS_H
	#include "windows.h"
#ENDIF

#IFDEF LINKFILES
	#dynamiclinkfile usp10.dll
#ENDIF

#define USPBUILD  0325

#define SCRIPT_UNDEFINED  0

#define USP_E_SCRIPT_NOT_IN_FONT (SEVERITY_ERROR<<31)|(FACILITY_ITF<<16)|0x200

#define SGCM_RTL  0x00000001

#define SSA_PASSWORD  0x00000001
#define SSA_TAB  0x00000002
#define SSA_CLIP  0x00000004
#define SSA_FIT  0x00000008
#define SSA_DZWG  0x00000010
#define SSA_FALLBACK  0x00000020
#define SSA_BREAK  0x00000040
#define SSA_GLYPHS  0x00000080
#define SSA_RTL  0x00000100
#define SSA_GCP  0x00000200
#define SSA_HOTKEY  0x00000400
#define SSA_METAFILE  0x00000800
#define SSA_LINK  0x00001000
#define SSA_HIDEHOTKEY  0x00002000
#define SSA_HOTKEYONLY  0x00002400

#define SSA_FULLMEASURE  0x04000000
#define SSA_LPKANSIFALLBACK  0x08000000
#define SSA_PIDX  0x10000000
#define SSA_LAYOUTRTL  0x20000000
#define SSA_DONTGLYPH  0x40000000
#define SSA_NOKASHIDA  0x80000000

#define SIC_COMPLEX  1
#define SIC_ASCIIDIGIT  2
#define SIC_NEUTRAL  4

#define SCRIPT_DIGITSUBSTITUTE_CONTEXT  0
#define SCRIPT_DIGITSUBSTITUTE_NONE  1
#define SCRIPT_DIGITSUBSTITUTE_NATIONAL  2
#define SCRIPT_DIGITSUBSTITUTE_TRADITIONAL  3


SCRIPT_CONTROL STRUCT
	uDefaultLanguage DD
	fContextDigits DD
	fInvertPreBoundDir DD
	fInvertPostBoundDir DD
	fLinkStringBefore DD
	fLinkStringAfter DD
	fNeutralOverride DD
	fNumericOverride DD
	fLegacyBidiClass DD
	fReserved DD
ENDS

SCRIPT_STATE STRUCT
	uBidiLevel DW
	fOverrideDirection DW
	fInhibitSymSwap DW
	fCharShape DW
	fDigitSubstitute DW
	fInhibitLigate DW
	fDisplayZWG DW
	fArabicNumContext DW
	fGcpClusters DW
	fReserved DW
	fEngineReserved DW
ENDS

SCRIPT_ANALYSIS STRUCT
	eScript DW
	fRTL DW
	fLayoutRTL DW
	fLinkBefore DW
	fLinkAfter DW
	fLogicalOrder DW
	fNoGlyphIndex DW
	s SCRIPT_STATE<>
ENDS

SCRIPT_ITEM STRUCT
	iCharPos DD
	a SCRIPT_ANALYSIS
ENDS

SCRIPT_JUSTIFY_NONE = 0
SCRIPT_JUSTIFY_ARABIC_BLANK = 1
SCRIPT_JUSTIFY_CHARACTER = 2
SCRIPT_JUSTIFY_RESERVED1 = 3
SCRIPT_JUSTIFY_BLANK = 4
SCRIPT_JUSTIFY_RESERVED2 = 5
SCRIPT_JUSTIFY_RESERVED3 = 6
SCRIPT_JUSTIFY_ARABIC_NORMAL = 7
SCRIPT_JUSTIFY_ARABIC_KASHIDA = 8
SCRIPT_JUSTIFY_ARABIC_ALEF = 9
SCRIPT_JUSTIFY_ARABIC_HA = 10
SCRIPT_JUSTIFY_ARABIC_RA = 11
SCRIPT_JUSTIFY_ARABIC_BA = 12
SCRIPT_JUSTIFY_ARABIC_BARA = 13
SCRIPT_JUSTIFY_ARABIC_SEEN = 14
SCRIPT_JUSTIFY_RESERVED4 = 15

SCRIPT_VISATTR STRUCT
	uJustification DW
	fClusterStart DW
	fDiacritic DW
	fZeroWidth DW
	fReserved DW
	fShapeReserved DW
ENDS

#ifndef LSDEFS_DEFINED
GOFFSET STRUCT
	du DD
	dv DD
ENDS
#endif

SCRIPT_LOGATTR STRUCT
	fSoftBreak DB
	fWhiteSpace DB
	fCharStop DB
	fWordStop DB
	fInvalid DB
	fReserved DB
ENDS

SCRIPT_PROPERTIES STRUCT
	langid DD
	fNumeric DD
	fComplex DD
	fNeedsWordBreaking DD
	fNeedsCaretInfo DD
	bCharSet DD
	fControl DD
	fPrivateUseArea DD
	fNeedsCharacterJustify DD
	fInvalidGlyph DD
	fInvalidLogAttr DD
	fCDM DD
	fAmbiguousCharSet DD
	fClusterSizeVaries DD
	fRejectInvalid DD
ENDS

SCRIPT_FONTPROPERTIES STRUCT
	cBytes DD
	wgBlank DW
	wgDefault DW
	wgInvalid DW
	wgKashida DW
	iKashidaWidth DD
ENDS

SCRIPT_TABDEF STRUCT
	cTabStops DD
	iScale DD
	pTabStops PTR
	iTabOrigin DD
ENDS

SCRIPT_DIGITSUBSTITUTE STRUCT
	NationalDigitLanguage DD
	TraditionalDigitLanguage DD
	DigitSubstitute DD
	dwReserved DD
ENDS

#endif /* _USP10_H */
