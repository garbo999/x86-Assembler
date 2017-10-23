#ifndef GDIPLUSENUMS_H
#define GDIPLUSENUMS_H

FillModeAlternate = 0
FillModeWinding = 1

UnitWorld = 0      // 0 -- World coordinate (non-physical unit)
UnitDisplay = 1    // 1 -- Variable -- for PageTransform only
UnitPixel = 2      // 2 -- Each unit is one device pixel.
UnitPoint = 3      // 3 -- Each unit is a printer's point, or 1/72 inch.
UnitInch = 4       // 4 -- Each unit is 1 inch.
UnitDocument = 5   // 5 -- Each unit is 1/300 inch.
UnitMillimeter = 6  // 6 -- Each unit is 1 millimeter.

QualityModeInvalid = -1
QualityModeDefault = 0
QualityModeLow = 1 // Best performance
QualityModeHigh = 2  // Best rendering quality

CompositingModeSourceOver = 0
CompositingModeSourceCopy = 1

CompositingQualityInvalid = QualityModeInvalid
CompositingQualityDefault = QualityModeDefault
CompositingQualityHighSpeed = QualityModeLow
CompositingQualityHighQuality = QualityModeHigh
CompositingQualityGammaCorrected = 3
CompositingQualityAssumeLinear = 4

MetafileFrameUnitPixel      = UnitPixel
MetafileFrameUnitPoint      = UnitPoint
MetafileFrameUnitInch       = UnitInch
MetafileFrameUnitDocument   = UnitDocument
MetafileFrameUnitMillimeter = UnitMillimeter
MetafileFrameUnitGdi = 7

CoordinateSpaceWorld = 0
CoordinateSpacePage = 1
CoordinateSpaceDevice = 2

WrapModeTile = 0
WrapModeTileFlipX = 1
WrapModeTileFlipY = 2
WrapModeTileFlipXY = 3
WrapModeClamp = 4

DitherTypeNone = 0
DitherTypeSolid = 1
DitherTypeOrdered4x4 = 2
DitherTypeOrdered8x8 = 3
DitherTypeOrdered16x16 = 4
DitherTypeOrdered91x91 = 5
DitherTypeSpiral4x4 = 6
DitherTypeSpiral8x8 = 7
DitherTypeDualSpiral4x4 = 8
DitherTypeDualSpiral8x8 = 9
DitherTypeErrorDiffusion = 10

HatchStyleHorizontal = 0
HatchStyleVertical = 1
HatchStyleForwardDiagonal = 2
HatchStyleBackwardDiagonal = 3
HatchStyleCross = 4
HatchStyleDiagonalCross = 5
HatchStyle05Percent = 6
HatchStyle10Percent = 7
HatchStyle20Percent = 8
HatchStyle25Percent = 9
HatchStyle30Percent = 10
HatchStyle40Percent = 11
HatchStyle50Percent = 12
HatchStyle60Percent = 13
HatchStyle70Percent = 14
HatchStyle75Percent = 15
HatchStyle80Percent = 16
HatchStyle90Percent = 17
HatchStyleLightDownwardDiagonal = 18
HatchStyleLightUpwardDiagonal = 19
HatchStyleDarkDownwardDiagonal = 20
HatchStyleDarkUpwardDiagonal = 21
HatchStyleWideDownwardDiagonal = 22
HatchStyleWideUpwardDiagonal = 23
HatchStyleLightVertical = 24
HatchStyleLightHorizontal = 25
HatchStyleNarrowVertical = 26
HatchStyleNarrowHorizontal = 27
HatchStyleDarkVertical = 28
HatchStyleDarkHorizontal = 29
HatchStyleDashedDownwardDiagonal = 30
HatchStyleDashedUpwardDiagonal = 31
HatchStyleDashedHorizontal = 32
HatchStyleDashedVertical = 33
HatchStyleSmallConfetti = 34
HatchStyleLargeConfetti = 35
HatchStyleZigZag = 36
HatchStyleWave = 37
HatchStyleDiagonalBrick = 38
HatchStyleHorizontalBrick = 39
HatchStyleWeave = 40
HatchStylePlaid = 41
HatchStyleDivot = 42
HatchStyleDottedGrid = 43
HatchStyleDottedDiamond = 44
HatchStyleShingle = 45
HatchStyleTrellis = 46
HatchStyleSphere = 47
HatchStyleSmallGrid = 48
HatchStyleSmallCheckerBoard = 49
HatchStyleLargeCheckerBoard = 50
HatchStyleOutlinedDiamond = 51
HatchStyleSolidDiamond = 52
HatchStyleTotal = 53
HatchStyleLargeGrid = HatchStyleCross 
HatchStyleMin = HatchStyleHorizontal 
HatchStyleMax = HatchStyleTotal - 1

DashStyleSolid = 0
DashStyleDash = 1
DashStyleDot = 2
DashStyleDashDot = 3
DashStyleDashDotDot = 4
DashStyleCustom = 5

DashCapFlat = 0 
DashCapRound = 2 
DashCapTriangle = 3 

LineCapFlat = 0 
LineCapSquare = 1 
LineCapRound = 2 
LineCapTriangle = 3 
LineCapNoAnchor = 10h 
LineCapSquareAnchor = 11h 
LineCapRoundAnchor = 12h 
LineCapDiamondAnchor = 13h 
LineCapArrowAnchor = 14h 
LineCapCustom = 0ffh 
LineCapAnchorMask = 0f0h 

CustomLineCapTypeDefault = 0 
CustomLineCapTypeAdjustableArrow = 1 

LineJoinMiter = 0 
LineJoinBevel = 1 
LineJoinRound = 2 
LineJoinMiterClipped = 3 

PathPointTypeStart = 0 
PathPointTypeLine = 1 
PathPointTypeBezier = 3 
PathPointTypePathTypeMask = 07h 
PathPointTypeDashMode = 10h 
PathPointTypePathMarker = 20h 
PathPointTypeCloseSubpath = 80h 
PathPointTypeBezier3 = 3 

WarpModePerspective = 0
WarpModeBilinear = 1

LinearGradientModeHorizontal = 0
LinearGradientModeVertical = 1
LinearGradientModeForwardDiagonal = 2
LinearGradientModeBackwardDiagonal = 3

CombineModeReplace = 0
CombineModeIntersect = 1
CombineModeUnion = 2
CombineModeXor = 3
CombineModeExclude = 4
CombineModeComplement = 5

ImageTypeUnknown = 0
ImageTypeBitmap = 1
ImageTypeMetafile = 2

InterpolationModeInvalid = QualityModeInvalid
InterpolationModeDefault = QualityModeDefault
InterpolationModeLowQuality = QualityModeLow
InterpolationModeHighQuality = QualityModeHigh
InterpolationModeBilinear = 1
InterpolationModeBicubic = 2
InterpolationModeNearestNeighbor = 3
InterpolationModeHighQualityBilinear = 4
InterpolationModeHighQualityBicubic = 5

PenAlignmentCenter = 0 
PenAlignmentInset = 1 

BrushTypeSolidColor = 0 
BrushTypeHatchFill = 1 
BrushTypeTextureFill = 2 
BrushTypePathGradient = 3 
BrushTypeLinearGradient = 4 

PenTypeSolidColor = BrushTypeSolidColor
PenTypeHatchFill = BrushTypeHatchFill
PenTypeTextureFill = BrushTypeTextureFill
PenTypePathGradient = BrushTypePathGradient
PenTypeLinearGradient = BrushTypeLinearGradient
PenTypeUnknown = - 1 

MatrixOrderPrepend = 0 
MatrixOrderAppend = 1 

GenericFontFamilySerif = 0
GenericFontFamilySansSerif = 1
GenericFontFamilyMonospace = 2

FontStyleRegular = 0 
FontStyleBold = 1 
FontStyleItalic = 2 
FontStyleBoldItalic = 3 
FontStyleUnderline = 4 
FontStyleStrikeout = 8 

SmoothingModeInvalid = QualityModeInvalid
SmoothingModeDefault = QualityModeDefault
SmoothingModeHighSpeed = QualityModeLow
SmoothingModeHighQuality = QualityModeHigh
SmoothingModeNone = 1
SmoothingModeAntiAlias = 2

PixelOffsetModeInvalid = QualityModeInvalid
PixelOffsetModeDefault = QualityModeDefault
PixelOffsetModeHighSpeed = QualityModeLow
PixelOffsetModeHighQuality = QualityModeHigh
PixelOffsetModeNone = 1
PixelOffsetModeHalf = 2

TextRenderingHintSystemDefault = 0 
TextRenderingHintSingleBitPerPixelGridFit = 1
TextRenderingHintSingleBitPerPixel = 2
TextRenderingHintAntiAliasGridFit = 3
TextRenderingHintAntiAlias = 4
TextRenderingHintClearTypeGridFit = 5

MetafileTypeInvalid = 0
MetafileTypeWmf = 1
MetafileTypeWmfPlaceable = 2
MetafileTypeEmf = 3
MetafileTypeEmfPlusOnly = 4
MetafileTypeEmfPlusDual = 5

EmfTypeEmfOnly = MetafileTypeEmf
EmfTypeEmfPlusOnly = MetafileTypeEmfPlusOnly
EmfTypeEmfPlusDual = MetafileTypeEmfPlusDual

ObjectTypeInvalid = 0
ObjectTypeBrush = 1
ObjectTypePen = 2
ObjectTypePath = 3
ObjectTypeRegion = 4
ObjectTypeImage = 5
ObjectTypeFont = 6
ObjectTypeStringFormat = 7
ObjectTypeImageAttributes = 8
ObjectTypeCustomLineCap = 9
ObjectTypeMax = ObjectTypeCustomLineCap
ObjectTypeMin = ObjectTypeBrush

#IFNDEF META_ENUMERATION
#DEFINE META_ENUMERATION
	#define META_SETBKCOLOR  0x0201
	#define META_SETBKMODE  0x0102
	#define META_SETMAPMODE  0x0103
	#define META_SETROP2  0x0104
	#define META_SETRELABS  0x0105
	#define META_SETPOLYFILLMODE  0x0106
	#define META_SETSTRETCHBLTMODE  0x0107
	#define META_SETTEXTCHAREXTRA  0x0108
	#define META_SETTEXTCOLOR  0x0209
	#define META_SETTEXTJUSTIFICATION  0x020A
	#define META_SETWINDOWORG  0x020B
	#define META_SETWINDOWEXT  0x020C
	#define META_SETVIEWPORTORG  0x020D
	#define META_SETVIEWPORTEXT  0x020E
	#define META_OFFSETWINDOWORG  0x020F
	#define META_SCALEWINDOWEXT  0x0410
	#define META_OFFSETVIEWPORTORG  0x0211
	#define META_SCALEVIEWPORTEXT  0x0412
	#define META_LINETO  0x0213
	#define META_MOVETO  0x0214
	#define META_EXCLUDECLIPRECT  0x0415
	#define META_INTERSECTCLIPRECT  0x0416
	#define META_ARC  0x0817
	#define META_ELLIPSE  0x0418
	#define META_FLOODFILL  0x0419
	#define META_PIE  0x081A
	#define META_RECTANGLE  0x041B
	#define META_ROUNDRECT  0x061C
	#define META_PATBLT  0x061D
	#define META_SAVEDC  0x001E
	#define META_SETPIXEL  0x041F
	#define META_OFFSETCLIPRGN  0x0220
	#define META_TEXTOUT  0x0521
	#define META_BITBLT  0x0922
	#define META_STRETCHBLT  0x0B23
	#define META_POLYGON  0x0324
	#define META_POLYLINE  0x0325
	#define META_ESCAPE  0x0626
	#define META_RESTOREDC  0x0127
	#define META_FILLREGION  0x0228
	#define META_FRAMEREGION  0x0429
	#define META_INVERTREGION  0x012A
	#define META_PAINTREGION  0x012B
	#define META_SELECTCLIPREGION  0x012C
	#define META_SELECTOBJECT  0x012D
	#define META_SETTEXTALIGN  0x012E
	#define META_CHORD  0x0830
	#define META_SETMAPPERFLAGS  0x0231
	#define META_EXTTEXTOUT  0x0a32
	#define META_SETDIBTODEV  0x0d33
	#define META_SELECTPALETTE  0x0234
	#define META_REALIZEPALETTE  0x0035
	#define META_ANIMATEPALETTE  0x0436
	#define META_SETPALENTRIES  0x0037
	#define META_POLYPOLYGON  0x0538
	#define META_RESIZEPALETTE  0x0139
	#define META_DIBBITBLT  0x0940
	#define META_DIBSTRETCHBLT  0x0b41
	#define META_DIBCREATEPATTERNBRUSH  0x0142
	#define META_STRETCHDIB  0x0f43
	#define META_EXTFLOODFILL  0x0548
	#define META_SETLAYOUT  0x0149
	#define META_DELETEOBJECT  0x01f0
	#define META_CREATEPALETTE  0x00f7
	#define META_CREATEPATTERNBRUSH  0x01F9
	#define META_CREATEPENINDIRECT  0x02FA
	#define META_CREATEFONTINDIRECT  0x02FB
	#define META_CREATEBRUSHINDIRECT  0x02FC
	#define META_CREATEREGION  0x06FF
#ENDIF

GDIP_EMFPLUS_RECORD_BASE	EQU	00004000h
GDIP_WMF_RECORD_BASE	EQU	00010000h

/*
GDIP_WMF_RECORD_TO_EMFPLUS macro n
	exitm <( ( EmfPlusRecordType ) ( ( n )  or  GDIP_WMF_RECORD_BASE ) ) >
	endm
GDIP_EMFPLUS_RECORD_TO_WMF macro n
	exitm <( ( n )  and  (  not  GDIP_WMF_RECORD_BASE ) ) >
	endm
GDIP_IS_WMF_RECORDTYPE macro n
	exitm <( ( ( n )  and  GDIP_WMF_RECORD_BASE ) != 0 ) >
	endm
*/

#define WmfRecordTypeSetBkColor (GDIP_WMF_RECORD_BASE |META_SETBKCOLOR)
#define WmfRecordTypeSetBkMode (GDIP_WMF_RECORD_BASE |META_SETBKMODE)
#define WmfRecordTypeSetMapMode (GDIP_WMF_RECORD_BASE |META_SETMAPMODE)
#define WmfRecordTypeSetROP2 (GDIP_WMF_RECORD_BASE |META_SETROP2)
#define WmfRecordTypeSetRelAbs (GDIP_WMF_RECORD_BASE |META_SETRELABS)
#define WmfRecordTypeSetPolyFillMode (GDIP_WMF_RECORD_BASE |META_SETPOLYFILLMODE)
#define WmfRecordTypeSetStretchBltMode (GDIP_WMF_RECORD_BASE |META_SETSTRETCHBLTMODE)
#define WmfRecordTypeSetTextCharExtra (GDIP_WMF_RECORD_BASE |META_SETTEXTCHAREXTRA)
#define WmfRecordTypeSetTextColor (GDIP_WMF_RECORD_BASE |META_SETTEXTCOLOR)
#define WmfRecordTypeSetTextJustification (GDIP_WMF_RECORD_BASE |META_SETTEXTJUSTIFICATION)
#define WmfRecordTypeSetWindowOrg (GDIP_WMF_RECORD_BASE |META_SETWINDOWORG)
#define WmfRecordTypeSetWindowExt (GDIP_WMF_RECORD_BASE |META_SETWINDOWEXT)
#define WmfRecordTypeSetViewportOrg (GDIP_WMF_RECORD_BASE |META_SETVIEWPORTORG)
#define WmfRecordTypeSetViewportExt (GDIP_WMF_RECORD_BASE |META_SETVIEWPORTEXT)
#define WmfRecordTypeOffsetWindowOrg (GDIP_WMF_RECORD_BASE |META_OFFSETWINDOWORG)
#define WmfRecordTypeScaleWindowExt (GDIP_WMF_RECORD_BASE |META_SCALEWINDOWEXT)
#define WmfRecordTypeOffsetViewportOrg (GDIP_WMF_RECORD_BASE |META_OFFSETVIEWPORTORG)
#define WmfRecordTypeScaleViewportExt (GDIP_WMF_RECORD_BASE |META_SCALEVIEWPORTEXT)
#define WmfRecordTypeLineTo (GDIP_WMF_RECORD_BASE |META_LINETO)
#define WmfRecordTypeMoveTo (GDIP_WMF_RECORD_BASE |META_MOVETO)
#define WmfRecordTypeExcludeClipRect (GDIP_WMF_RECORD_BASE |META_EXCLUDECLIPRECT)
#define WmfRecordTypeIntersectClipRect (GDIP_WMF_RECORD_BASE |META_INTERSECTCLIPRECT)
#define WmfRecordTypeArc (GDIP_WMF_RECORD_BASE |META_ARC)
#define WmfRecordTypeEllipse (GDIP_WMF_RECORD_BASE |META_ELLIPSE)
#define WmfRecordTypeFloodFill (GDIP_WMF_RECORD_BASE |META_FLOODFILL)
#define WmfRecordTypePie (GDIP_WMF_RECORD_BASE |META_PIE)
#define WmfRecordTypeRectangle (GDIP_WMF_RECORD_BASE |META_RECTANGLE)
#define WmfRecordTypeRoundRect (GDIP_WMF_RECORD_BASE |META_ROUNDRECT)
#define WmfRecordTypePatBlt (GDIP_WMF_RECORD_BASE |META_PATBLT)
#define WmfRecordTypeSaveDC (GDIP_WMF_RECORD_BASE |META_SAVEDC)
#define WmfRecordTypeSetPixel (GDIP_WMF_RECORD_BASE |META_SETPIXEL)
#define WmfRecordTypeOffsetClipRgn (GDIP_WMF_RECORD_BASE |META_OFFSETCLIPRGN)
#define WmfRecordTypeTextOut (GDIP_WMF_RECORD_BASE |META_TEXTOUT)
#define WmfRecordTypeBitBlt (GDIP_WMF_RECORD_BASE |META_BITBLT)
#define WmfRecordTypeStretchBlt (GDIP_WMF_RECORD_BASE |META_STRETCHBLT)
#define WmfRecordTypePolygon (GDIP_WMF_RECORD_BASE |META_POLYGON)
#define WmfRecordTypePolyline (GDIP_WMF_RECORD_BASE |META_POLYLINE)
#define WmfRecordTypeEscape (GDIP_WMF_RECORD_BASE |META_ESCAPE)
#define WmfRecordTypeRestoreDC (GDIP_WMF_RECORD_BASE |META_RESTOREDC)
#define WmfRecordTypeFillRegion (GDIP_WMF_RECORD_BASE |META_FILLREGION)
#define WmfRecordTypeFrameRegion (GDIP_WMF_RECORD_BASE |META_FRAMEREGION)
#define WmfRecordTypeInvertRegion (GDIP_WMF_RECORD_BASE |META_INVERTREGION)
#define WmfRecordTypePaintRegion (GDIP_WMF_RECORD_BASE |META_PAINTREGION)
#define WmfRecordTypeSelectClipRegion (GDIP_WMF_RECORD_BASE |META_SELECTCLIPREGION)
#define WmfRecordTypeSelectObject (GDIP_WMF_RECORD_BASE |META_SELECTOBJECT)
#define WmfRecordTypeSetTextAlign (GDIP_WMF_RECORD_BASE |META_SETTEXTALIGN)
#define WmfRecordTypeDrawText (GDIP_WMF_RECORD_BASE |062Fh)
#define WmfRecordTypeChord (GDIP_WMF_RECORD_BASE |META_CHORD)
#define WmfRecordTypeSetMapperFlags (GDIP_WMF_RECORD_BASE |META_SETMAPPERFLAGS)
#define WmfRecordTypeExtTextOut (GDIP_WMF_RECORD_BASE |META_EXTTEXTOUT)
#define WmfRecordTypeSetDIBToDev (GDIP_WMF_RECORD_BASE |META_SETDIBTODEV)
#define WmfRecordTypeSelectPalette (GDIP_WMF_RECORD_BASE |META_SELECTPALETTE)
#define WmfRecordTypeRealizePalette (GDIP_WMF_RECORD_BASE |META_REALIZEPALETTE)
#define WmfRecordTypeAnimatePalette (GDIP_WMF_RECORD_BASE |META_ANIMATEPALETTE)
#define WmfRecordTypeSetPalEntries (GDIP_WMF_RECORD_BASE |META_SETPALENTRIES)
#define WmfRecordTypePolyPolygon (GDIP_WMF_RECORD_BASE |META_POLYPOLYGON)
#define WmfRecordTypeResizePalette (GDIP_WMF_RECORD_BASE |META_RESIZEPALETTE)
#define WmfRecordTypeDIBBitBlt (GDIP_WMF_RECORD_BASE |META_DIBBITBLT)
#define WmfRecordTypeDIBStretchBlt (GDIP_WMF_RECORD_BASE |META_DIBSTRETCHBLT)
#define WmfRecordTypeDIBCreatePatternBrush (GDIP_WMF_RECORD_BASE |META_DIBCREATEPATTERNBRUSH)
#define WmfRecordTypeStretchDIB (GDIP_WMF_RECORD_BASE |META_STRETCHDIB)
#define WmfRecordTypeExtFloodFill (GDIP_WMF_RECORD_BASE |META_EXTFLOODFILL)
#define WmfRecordTypeSetLayout (GDIP_WMF_RECORD_BASE |0149h)
#define WmfRecordTypeResetDC (GDIP_WMF_RECORD_BASE |014Ch)
#define WmfRecordTypeStartDoc (GDIP_WMF_RECORD_BASE |014Dh)
#define WmfRecordTypeStartPage (GDIP_WMF_RECORD_BASE |004Fh)
#define WmfRecordTypeEndPage (GDIP_WMF_RECORD_BASE |0050h)
#define WmfRecordTypeAbortDoc (GDIP_WMF_RECORD_BASE |0052h)
#define WmfRecordTypeEndDoc (GDIP_WMF_RECORD_BASE |005Eh)
#define WmfRecordTypeDeleteObject (GDIP_WMF_RECORD_BASE |META_DELETEOBJECT)
#define WmfRecordTypeCreatePalette (GDIP_WMF_RECORD_BASE |META_CREATEPALETTE)
#define WmfRecordTypeCreateBrush (GDIP_WMF_RECORD_BASE |00F8h)
#define WmfRecordTypeCreatePatternBrush (GDIP_WMF_RECORD_BASE |META_CREATEPATTERNBRUSH)
#define WmfRecordTypeCreatePenIndirect (GDIP_WMF_RECORD_BASE |META_CREATEPENINDIRECT)
#define WmfRecordTypeCreateFontIndirect (GDIP_WMF_RECORD_BASE |META_CREATEFONTINDIRECT)
#define WmfRecordTypeCreateBrushIndirect (GDIP_WMF_RECORD_BASE |META_CREATEBRUSHINDIRECT)
#define WmfRecordTypeCreateBitmapIndirect (GDIP_WMF_RECORD_BASE |02FDh)
#define WmfRecordTypeCreateBitmap (GDIP_WMF_RECORD_BASE |06FEh)
#define WmfRecordTypeCreateRegion (GDIP_WMF_RECORD_BASE |META_CREATEREGION)

#IFNDEF EMR_ENUMERATION
#DEFINE EMR_ENUMERATION
	#define EMR_HEADER  1
	#define EMR_POLYBEZIER  2
	#define EMR_POLYGON  3
	#define EMR_POLYLINE  4
	#define EMR_POLYBEZIERTO  5
	#define EMR_POLYLINETO  6
	#define EMR_POLYPOLYLINE  7
	#define EMR_POLYPOLYGON  8
	#define EMR_SETWINDOWEXTEX  9
	#define EMR_SETWINDOWORGEX  10
	#define EMR_SETVIEWPORTEXTEX  11
	#define EMR_SETVIEWPORTORGEX  12
	#define EMR_SETBRUSHORGEX  13
	#define EMR_EOF  14
	#define EMR_SETPIXELV  15
	#define EMR_SETMAPPERFLAGS  16
	#define EMR_SETMAPMODE  17
	#define EMR_SETBKMODE  18
	#define EMR_SETPOLYFILLMODE  19
	#define EMR_SETROP2  20
	#define EMR_SETSTRETCHBLTMODE  21
	#define EMR_SETTEXTALIGN  22
	#define EMR_SETCOLORADJUSTMENT  23
	#define EMR_SETTEXTCOLOR  24
	#define EMR_SETBKCOLOR  25
	#define EMR_OFFSETCLIPRGN  26
	#define EMR_MOVETOEX  27
	#define EMR_SETMETARGN  28
	#define EMR_EXCLUDECLIPRECT  29
	#define EMR_INTERSECTCLIPRECT  30
	#define EMR_SCALEVIEWPORTEXTEX  31
	#define EMR_SCALEWINDOWEXTEX  32
	#define EMR_SAVEDC  33
	#define EMR_RESTOREDC  34
	#define EMR_SETWORLDTRANSFORM  35
	#define EMR_MODIFYWORLDTRANSFORM  36
	#define EMR_SELECTOBJECT  37
	#define EMR_CREATEPEN  38
	#define EMR_CREATEBRUSHINDIRECT  39
	#define EMR_DELETEOBJECT  40
	#define EMR_ANGLEARC  41
	#define EMR_ELLIPSE  42
	#define EMR_RECTANGLE  43
	#define EMR_ROUNDRECT  44
	#define EMR_ARC  45
	#define EMR_CHORD  46
	#define EMR_PIE  47
	#define EMR_SELECTPALETTE  48
	#define EMR_CREATEPALETTE  49
	#define EMR_SETPALETTEENTRIES  50
	#define EMR_RESIZEPALETTE  51
	#define EMR_REALIZEPALETTE  52
	#define EMR_EXTFLOODFILL  53
	#define EMR_LINETO  54
	#define EMR_ARCTO  55
	#define EMR_POLYDRAW  56
	#define EMR_SETARCDIRECTION  57
	#define EMR_SETMITERLIMIT  58
	#define EMR_BEGINPATH  59
	#define EMR_ENDPATH  60
	#define EMR_CLOSEFIGURE  61
	#define EMR_FILLPATH  62
	#define EMR_STROKEANDFILLPATH  63
	#define EMR_STROKEPATH  64
	#define EMR_FLATTENPATH  65
	#define EMR_WIDENPATH  66
	#define EMR_SELECTCLIPPATH  67
	#define EMR_ABORTPATH  68
	#define EMR_GDICOMMENT  70
	#define EMR_FILLRGN  71
	#define EMR_FRAMERGN  72
	#define EMR_INVERTRGN  73
	#define EMR_PAINTRGN  74
	#define EMR_EXTSELECTCLIPRGN  75
	#define EMR_BITBLT  76
	#define EMR_STRETCHBLT  77
	#define EMR_MASKBLT  78
	#define EMR_PLGBLT  79
	#define EMR_SETDIBITSTODEVICE  80
	#define EMR_STRETCHDIBITS  81
	#define EMR_EXTCREATEFONTINDIRECTW  82
	#define EMR_EXTTEXTOUTA  83
	#define EMR_EXTTEXTOUTW  84
	#define EMR_POLYBEZIER16  85
	#define EMR_POLYGON16  86
	#define EMR_POLYLINE16  87
	#define EMR_POLYBEZIERTO16  88
	#define EMR_POLYLINETO16  89
	#define EMR_POLYPOLYLINE16  90
	#define EMR_POLYPOLYGON16  91
	#define EMR_POLYDRAW16  92
	#define EMR_CREATEMONOBRUSH  93
	#define EMR_CREATEDIBPATTERNBRUSHPT  94
	#define EMR_EXTCREATEPEN  95
	#define EMR_POLYTEXTOUTA  96
	#define EMR_POLYTEXTOUTW  97
	#define EMR_SETICMMODE  98
	#define EMR_CREATECOLORSPACE  99
	#define EMR_SETCOLORSPACE  100
	#define EMR_DELETECOLORSPACE  101
	#define EMR_GLSRECORD  102
	#define EMR_GLSBOUNDEDRECORD  103
	#define EMR_PIXELFORMAT  104
	#define EMR_RESERVED_105  105
	#define EMR_RESERVED_106  106
	#define EMR_RESERVED_107  107
	#define EMR_RESERVED_108  108
	#define EMR_RESERVED_109  109
	#define EMR_RESERVED_110  110
	#define EMR_COLORCORRECTPALETTE  111
	#define EMR_SETICMPROFILEA  112
	#define EMR_SETICMPROFILEW  113
	#define EMR_ALPHABLEND  114
	#define EMR_SETLAYOUT  115
	#define EMR_TRANSPARENTBLT  116
	#define EMR_GRADIENTFILL  118
	#define EMR_RESERVED_119  119
	#define EMR_RESERVED_120  120
	#define EMR_COLORMATCHTOTARGETW  121
	#define EMR_CREATECOLORSPACEW  122
	
	#define EMR_MIN  1
	#define EMR_MAX  122
#ENDIF

EmfRecordTypeHeader = EMR_HEADER 
EmfRecordTypePolyBezier = EMR_POLYBEZIER 
EmfRecordTypePolygon = EMR_POLYGON 
EmfRecordTypePolyline = EMR_POLYLINE 
EmfRecordTypePolyBezierTo = EMR_POLYBEZIERTO 
EmfRecordTypePolyLineTo = EMR_POLYLINETO 
EmfRecordTypePolyPolyline = EMR_POLYPOLYLINE 
EmfRecordTypePolyPolygon = EMR_POLYPOLYGON 
EmfRecordTypeSetWindowExtEx = EMR_SETWINDOWEXTEX 
EmfRecordTypeSetWindowOrgEx = EMR_SETWINDOWORGEX 
EmfRecordTypeSetViewportExtEx = EMR_SETVIEWPORTEXTEX 
EmfRecordTypeSetViewportOrgEx = EMR_SETVIEWPORTORGEX 
EmfRecordTypeSetBrushOrgEx = EMR_SETBRUSHORGEX 
EmfRecordTypeEOF = EMR_EOF 
EmfRecordTypeSetPixelV = EMR_SETPIXELV 
EmfRecordTypeSetMapperFlags = EMR_SETMAPPERFLAGS 
EmfRecordTypeSetMapMode = EMR_SETMAPMODE 
EmfRecordTypeSetBkMode = EMR_SETBKMODE 
EmfRecordTypeSetPolyFillMode = EMR_SETPOLYFILLMODE 
EmfRecordTypeSetROP2 = EMR_SETROP2 
EmfRecordTypeSetStretchBltMode = EMR_SETSTRETCHBLTMODE 
EmfRecordTypeSetTextAlign = EMR_SETTEXTALIGN 
EmfRecordTypeSetColorAdjustment = EMR_SETCOLORADJUSTMENT 
EmfRecordTypeSetTextColor = EMR_SETTEXTCOLOR 
EmfRecordTypeSetBkColor = EMR_SETBKCOLOR 
EmfRecordTypeOffsetClipRgn = EMR_OFFSETCLIPRGN 
EmfRecordTypeMoveToEx = EMR_MOVETOEX 
EmfRecordTypeSetMetaRgn = EMR_SETMETARGN 
EmfRecordTypeExcludeClipRect = EMR_EXCLUDECLIPRECT 
EmfRecordTypeIntersectClipRect = EMR_INTERSECTCLIPRECT 
EmfRecordTypeScaleViewportExtEx = EMR_SCALEVIEWPORTEXTEX 
EmfRecordTypeScaleWindowExtEx = EMR_SCALEWINDOWEXTEX 
EmfRecordTypeSaveDC = EMR_SAVEDC 
EmfRecordTypeRestoreDC = EMR_RESTOREDC 
EmfRecordTypeSetWorldTransform = EMR_SETWORLDTRANSFORM 
EmfRecordTypeModifyWorldTransform = EMR_MODIFYWORLDTRANSFORM 
EmfRecordTypeSelectObject = EMR_SELECTOBJECT 
EmfRecordTypeCreatePen = EMR_CREATEPEN 
EmfRecordTypeCreateBrushIndirect = EMR_CREATEBRUSHINDIRECT 
EmfRecordTypeDeleteObject = EMR_DELETEOBJECT 
EmfRecordTypeAngleArc = EMR_ANGLEARC 
EmfRecordTypeEllipse = EMR_ELLIPSE 
EmfRecordTypeRectangle = EMR_RECTANGLE 
EmfRecordTypeRoundRect = EMR_ROUNDRECT 
EmfRecordTypeArc = EMR_ARC 
EmfRecordTypeChord = EMR_CHORD 
EmfRecordTypePie = EMR_PIE 
EmfRecordTypeSelectPalette = EMR_SELECTPALETTE 
EmfRecordTypeCreatePalette = EMR_CREATEPALETTE 
EmfRecordTypeSetPaletteEntries = EMR_SETPALETTEENTRIES 
EmfRecordTypeResizePalette = EMR_RESIZEPALETTE 
EmfRecordTypeRealizePalette = EMR_REALIZEPALETTE 
EmfRecordTypeExtFloodFill = EMR_EXTFLOODFILL 
EmfRecordTypeLineTo = EMR_LINETO 
EmfRecordTypeArcTo = EMR_ARCTO 
EmfRecordTypePolyDraw = EMR_POLYDRAW 
EmfRecordTypeSetArcDirection = EMR_SETARCDIRECTION 
EmfRecordTypeSetMiterLimit = EMR_SETMITERLIMIT 
EmfRecordTypeBeginPath = EMR_BEGINPATH 
EmfRecordTypeEndPath = EMR_ENDPATH 
EmfRecordTypeCloseFigure = EMR_CLOSEFIGURE 
EmfRecordTypeFillPath = EMR_FILLPATH 
EmfRecordTypeStrokeAndFillPath = EMR_STROKEANDFILLPATH 
EmfRecordTypeStrokePath = EMR_STROKEPATH 
EmfRecordTypeFlattenPath = EMR_FLATTENPATH 
EmfRecordTypeWidenPath = EMR_WIDENPATH 
EmfRecordTypeSelectClipPath = EMR_SELECTCLIPPATH 
EmfRecordTypeAbortPath = EMR_ABORTPATH 
EmfRecordTypeReserved_069 = 69 
EmfRecordTypeGdiComment = EMR_GDICOMMENT 
EmfRecordTypeFillRgn = EMR_FILLRGN 
EmfRecordTypeFrameRgn = EMR_FRAMERGN 
EmfRecordTypeInvertRgn = EMR_INVERTRGN 
EmfRecordTypePaintRgn = EMR_PAINTRGN 
EmfRecordTypeExtSelectClipRgn = EMR_EXTSELECTCLIPRGN 
EmfRecordTypeBitBlt = EMR_BITBLT 
EmfRecordTypeStretchBlt = EMR_STRETCHBLT 
EmfRecordTypeMaskBlt = EMR_MASKBLT 
EmfRecordTypePlgBlt = EMR_PLGBLT 
EmfRecordTypeSetDIBitsToDevice = EMR_SETDIBITSTODEVICE 
EmfRecordTypeStretchDIBits = EMR_STRETCHDIBITS 
EmfRecordTypeExtCreateFontIndirect = EMR_EXTCREATEFONTINDIRECTW 
EmfRecordTypeExtTextOutA = EMR_EXTTEXTOUTA 
EmfRecordTypeExtTextOutW = EMR_EXTTEXTOUTW 
EmfRecordTypePolyBezier16 = EMR_POLYBEZIER16 
EmfRecordTypePolygon16 = EMR_POLYGON16 
EmfRecordTypePolyline16 = EMR_POLYLINE16 
EmfRecordTypePolyBezierTo16 = EMR_POLYBEZIERTO16 
EmfRecordTypePolylineTo16 = EMR_POLYLINETO16 
EmfRecordTypePolyPolyline16 = EMR_POLYPOLYLINE16 
EmfRecordTypePolyPolygon16 = EMR_POLYPOLYGON16 
EmfRecordTypePolyDraw16 = EMR_POLYDRAW16 
EmfRecordTypeCreateMonoBrush = EMR_CREATEMONOBRUSH 
EmfRecordTypeCreateDIBPatternBrushPt = EMR_CREATEDIBPATTERNBRUSHPT 
EmfRecordTypeExtCreatePen = EMR_EXTCREATEPEN 
EmfRecordTypePolyTextOutA = EMR_POLYTEXTOUTA 
EmfRecordTypePolyTextOutW = EMR_POLYTEXTOUTW 
EmfRecordTypeSetICMMode = 98 
EmfRecordTypeCreateColorSpace = 99 
EmfRecordTypeSetColorSpace = 100 
EmfRecordTypeDeleteColorSpace = 101 
EmfRecordTypeGLSRecord = 102 
EmfRecordTypeGLSBoundedRecord = 103 
EmfRecordTypePixelFormat = 104 
EmfRecordTypeDrawEscape = 105 
EmfRecordTypeExtEscape = 106 
EmfRecordTypeStartDoc = 107 
EmfRecordTypeSmallTextOut = 108 
EmfRecordTypeForceUFIMapping = 109 
EmfRecordTypeNamedEscape = 110 
EmfRecordTypeColorCorrectPalette = 111 
EmfRecordTypeSetICMProfileA = 112 
EmfRecordTypeSetICMProfileW = 113 
EmfRecordTypeAlphaBlend = 114 
EmfRecordTypeSetLayout = 115 
EmfRecordTypeTransparentBlt = 116 
EmfRecordTypeReserved_117 = 117 
EmfRecordTypeGradientFill = 118 
EmfRecordTypeSetLinkedUFIs = 119 
EmfRecordTypeSetTextJustification = 120 
EmfRecordTypeColorMatchToTargetW = 121 
EmfRecordTypeCreateColorSpaceW = 122 
EmfRecordTypeMax = 122 
EmfRecordTypeMin = 1 
EmfPlusRecordTypeInvalid = GDIP_EMFPLUS_RECORD_BASE
EmfPlusRecordTypeHeader = 1
EmfPlusRecordTypeEndOfFile = 2
EmfPlusRecordTypeComment = 3
EmfPlusRecordTypeGetDC = 4
EmfPlusRecordTypeMultiFormatStart = 5
EmfPlusRecordTypeMultiFormatSection = 6
EmfPlusRecordTypeMultiFormatEnd = 7
EmfPlusRecordTypeObject = 8
EmfPlusRecordTypeClear = 9
EmfPlusRecordTypeFillRects = 10
EmfPlusRecordTypeDrawRects = 11
EmfPlusRecordTypeFillPolygon = 12
EmfPlusRecordTypeDrawLines = 13
EmfPlusRecordTypeFillEllipse = 14
EmfPlusRecordTypeDrawEllipse = 15
EmfPlusRecordTypeFillPie = 16
EmfPlusRecordTypeDrawPie = 17
EmfPlusRecordTypeDrawArc = 18
EmfPlusRecordTypeFillRegion = 19
EmfPlusRecordTypeFillPath = 20
EmfPlusRecordTypeDrawPath = 21
EmfPlusRecordTypeFillClosedCurve = 22
EmfPlusRecordTypeDrawClosedCurve = 23
EmfPlusRecordTypeDrawCurve = 24
EmfPlusRecordTypeDrawBeziers = 25
EmfPlusRecordTypeDrawImage = 26
EmfPlusRecordTypeDrawImagePoints = 27
EmfPlusRecordTypeDrawString = 28
EmfPlusRecordTypeSetRenderingOrigin = 29
EmfPlusRecordTypeSetAntiAliasMode = 30
EmfPlusRecordTypeSetTextRenderingHint = 31
EmfPlusRecordTypeSetTextContrast = 32
EmfPlusRecordTypeSetInterpolationMode = 33
EmfPlusRecordTypeSetPixelOffsetMode = 34
EmfPlusRecordTypeSetCompositingMode = 35
EmfPlusRecordTypeSetCompositingQuality = 36
EmfPlusRecordTypeSave = 37
EmfPlusRecordTypeRestore = 38
EmfPlusRecordTypeBeginContainer = 39
EmfPlusRecordTypeBeginContainerNoParams = 40
EmfPlusRecordTypeEndContainer = 41
EmfPlusRecordTypeSetWorldTransform = 42
EmfPlusRecordTypeResetWorldTransform = 43
EmfPlusRecordTypeMultiplyWorldTransform = 44
EmfPlusRecordTypeTranslateWorldTransform = 45
EmfPlusRecordTypeScaleWorldTransform = 46
EmfPlusRecordTypeRotateWorldTransform = 47
EmfPlusRecordTypeSetPageTransform = 48
EmfPlusRecordTypeResetClip = 49
EmfPlusRecordTypeSetClipRect = 50
EmfPlusRecordTypeSetClipPath = 51
EmfPlusRecordTypeSetClipRegion = 52
EmfPlusRecordTypeOffsetClip = 53
EmfPlusRecordTypeDrawDriverString = 54
EmfPlusRecordTotal = 55
EmfPlusRecordTypeMax = EmfPlusRecordTotal - 1
EmfPlusRecordTypeMin = EmfPlusRecordTypeHeader

StringFormatFlagsDirectionRightToLeft = 00000001h 
StringFormatFlagsDirectionVertical = 00000002h 
StringFormatFlagsNoFitBlackBox = 00000004h 
StringFormatFlagsDisplayFormatControl = 00000020h 
StringFormatFlagsNoFontFallback = 00000400h 
StringFormatFlagsMeasureTrailingSpaces = 00000800h 
StringFormatFlagsNoWrap = 00001000h 
StringFormatFlagsLineLimit = 00002000h 
StringFormatFlagsNoClip = 00004000h 

StringTrimmingNone = 0 
StringTrimmingCharacter = 1 
StringTrimmingWord = 2 
StringTrimmingEllipsisCharacter = 3 
StringTrimmingEllipsisWord = 4 
StringTrimmingEllipsisPath = 5 

StringDigitSubstituteUser = 0 
StringDigitSubstituteNone = 1 
StringDigitSubstituteNational = 2 
StringDigitSubstituteTraditional = 3 

HotkeyPrefixNone = 0 
HotkeyPrefixShow = 1 
HotkeyPrefixHide = 2 

StringAlignmentNear = 0 
StringAlignmentCenter = 1 
StringAlignmentFar = 2 

DriverStringOptionsCmapLookup = 1 
DriverStringOptionsVertical = 2 
DriverStringOptionsRealizedAdvance = 4 
DriverStringOptionsLimitSubpixel = 8 

FlushIntentionFlush = 0 
FlushIntentionSync = 1 

EncoderParameterValueTypeByte = 1 
EncoderParameterValueTypeASCII = 2 
EncoderParameterValueTypeShort = 3 
EncoderParameterValueTypeLong = 4 
EncoderParameterValueTypeRational = 5 
EncoderParameterValueTypeLongRange = 6 
EncoderParameterValueTypeUndefined = 7 
EncoderParameterValueTypeRationalRange = 8 

EncoderValueColorTypeCMYK = 0
EncoderValueColorTypeYCCK = 1
EncoderValueCompressionLZW = 2
EncoderValueCompressionCCITT3 = 3
EncoderValueCompressionCCITT4 = 4
EncoderValueCompressionRle = 5
EncoderValueCompressionNone = 6
EncoderValueScanMethodInterlaced = 7
EncoderValueScanMethodNonInterlaced = 8
EncoderValueVersionGif87 = 9
EncoderValueVersionGif89 = 10
EncoderValueRenderProgressive = 11
EncoderValueRenderNonProgressive = 12
EncoderValueTransformRotate90 = 13
EncoderValueTransformRotate180 = 14
EncoderValueTransformRotate270 = 15
EncoderValueTransformFlipHorizontal = 16
EncoderValueTransformFlipVertical = 17
EncoderValueMultiFrame = 18
EncoderValueLastFrame = 19
EncoderValueFlush = 20
EncoderValueFrameDimensionTime = 21
EncoderValueFrameDimensionResolution = 22
EncoderValueFrameDimensionPage = 23

EmfToWmfBitsFlagsDefault = 00000000h 
EmfToWmfBitsFlagsEmbedEmf = 00000001h 
EmfToWmfBitsFlagsIncludePlaceable = 00000002h 
EmfToWmfBitsFlagsNoXORClip = 00000004h 

TestControlForceBilinear = 0 
TestControlNoICM = 1 
TestControlGetBuildNumber = 2 

#endif 

