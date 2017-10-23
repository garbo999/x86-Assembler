// Original 86537 lines

#ifndef MSHTML_H
#define MSHTML_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF
#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#ifndef COM_NO_WINDOWS_H
	#IFNDEF WINDOWS_H
		#include "windows.h"
	#ENDIF
	#IFNDEF OLE2_H
		#include "ole2.h"
	#ENDIF
#endif /*COM_NO_WINDOWS_H*/

#IFNDEF OCIDL_H
	#include "ocidl.h"
#ENDIF

#IFNDEF DIMM_H
	#include "dimm.h"
#ENDIF

#IFNDEF SHTYPES_H
	#include "shtypes.h"
#ENDIF
#IFNDEF OLECTL_H
	#include "olectl.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#DEFINE GUID_SID_SEditCommandTarget <0x3050f4b5,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_CGID_EditStateCommands <0x3050f4b6,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_SID_SHTMLEditHost <0x3050f6a0,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_SID_SHTMLEditServices <0x3050f7f9,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#define GUID_SID_SHTMLWindow GUID_IID_IHTMLWindow2
#define GUID_SID_SElementBehaviorFactory GUID_IID_IElementBehaviorFactory

// This information will be the LOWORD of the privacy flags stored in the privacy record
#define COOKIEACTION_NONE           0x00000000
#define COOKIEACTION_ACCEPT         0x00000001
#define COOKIEACTION_REJECT         0x00000002
#define COOKIEACTION_DOWNGRADE      0x00000004
#define COOKIEACTION_LEASH          0x00000008
#define COOKIEACTION_SUPPRESS       0x00000010
#define COOKIEACTION_READ           0x00000020

// Privacy info related to the url
// This information will be the HIWORD of the privacy flags stored in the privacy record
#define PRIVACY_URLISTOPLEVEL          0x00010000                   // Is this a top level url?
#define PRIVACY_URLHASCOMPACTPOLICY    0x00020000                   // Did the url have a compact policy used for privacy evaluations
#define PRIVACY_URLHASPOSTDATA         0x00080000                   // Is this a POST request?
#define PRIVACY_URLHASPOLICYREFLINK    0x00100000                   // Did the url have a privacy ref url in a link tag
#define PRIVACY_URLHASPOLICYREFHEADER  0x00200000                   // Did the url have a privacy ref url in a header tag
#define PRIVACY_URLHASP3PHEADER        0x00400000                   // Did the url have a privacy ref url in a header tag

#DEFINE GUID_IID_IHTMLFiltersCollection <3050f3ee,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFiltersCollection STRUCT
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
	get_length PTR
	get__newEnum PTR
	item PTR
ENDS

htmlDesignModeInherit	= -2
htmlDesignModeOn	= -1
htmlDesignModeOff	= 0
htmlDesignMode_Max	= 2147483647

htmlZOrderFront	= 0
htmlZOrderBack	= 1
htmlZOrder_Max	= 2147483647

htmlClearNotSet	= 0
htmlClearAll	= 1
htmlClearLeft	= 2
htmlClearRight	= 3
htmlClearBoth	= 4
htmlClearNone	= 5
htmlClear_Max	= 2147483647

htmlControlAlignNotSet	= 0
htmlControlAlignLeft	= 1
htmlControlAlignCenter	= 2
htmlControlAlignRight	= 3
htmlControlAlignTextTop	= 4
htmlControlAlignAbsMiddle	= 5
htmlControlAlignBaseline	= 6
htmlControlAlignAbsBottom	= 7
htmlControlAlignBottom	= 8
htmlControlAlignMiddle	= 9
htmlControlAlignTop	= 10
htmlControlAlign_Max	= 2147483647

htmlBlockAlignNotSet	= 0
htmlBlockAlignLeft	= 1
htmlBlockAlignCenter	= 2
htmlBlockAlignRight	= 3
htmlBlockAlignJustify	= 4
htmlBlockAlign_Max	= 2147483647

htmlReadyStateuninitialized	= 0
htmlReadyStateloading	= 1
htmlReadyStateloaded	= 2
htmlReadyStateinteractive	= 3
htmlReadyStatecomplete	= 4
htmlReadyState_Max	= 2147483647

htmlLoopLoopInfinite	= -1
htmlLoop_Max	= 2147483647

mediaTypeNotSet	= 0
mediaTypeAll	= 511
mediaTypeAural	= 1
mediaTypeBraille	= 2
mediaTypeEmbossed	= 4
mediaTypeHandheld	= 8
mediaTypePrint	= 16
mediaTypeProjection	= 32
mediaTypeScreen	= 64
mediaTypeTty	= 128
mediaTypeTv	= 256
mediaType_Max	= 2147483647

styleTextTransformNotSet	= 0
styleTextTransformCapitalize	= 1
styleTextTransformLowercase	= 2
styleTextTransformUppercase	= 3
styleTextTransformNone	= 4
styleTextTransform_Max	= 2147483647

styleDataRepeatNone	= 0
styleDataRepeatInner	= 1
styleDataRepeat_Max	= 2147483647

styleOverflowNotSet	= 0
styleOverflowAuto	= 1
styleOverflowHidden	= 2
styleOverflowVisible	= 3
styleOverflowScroll	= 4
styleOverflow_Max	= 2147483647

styleTableLayoutNotSet	= 0
styleTableLayoutAuto	= 1
styleTableLayoutFixed	= 2
styleTableLayout_Max	= 2147483647

styleBorderCollapseNotSet	= 0
styleBorderCollapseSeparate	= 1
styleBorderCollapseCollapse	= 2
styleBorderCollapse_Max	= 2147483647

styleFontStyleNotSet	= 0
styleFontStyleItalic	= 1
styleFontStyleOblique	= 2
styleFontStyleNormal	= 3
styleFontStyle_Max	= 2147483647

styleFontVariantNotSet	= 0
styleFontVariantSmallCaps	= 1
styleFontVariantNormal	= 2
styleFontVariant_Max	= 2147483647

styleBackgroundRepeatRepeat	= 0
styleBackgroundRepeatRepeatX	= 1
styleBackgroundRepeatRepeatY	= 2
styleBackgroundRepeatNoRepeat	= 3
styleBackgroundRepeatNotSet	= 4
styleBackgroundRepeat_Max	= 2147483647

styleBackgroundAttachmentFixed	= 0
styleBackgroundAttachmentScroll	= 1
styleBackgroundAttachmentNotSet	= 2
styleBackgroundAttachment_Max	= 2147483647

styleVerticalAlignAuto	= 0
styleVerticalAlignBaseline	= 1
styleVerticalAlignSub	= 2
styleVerticalAlignSuper	= 3
styleVerticalAlignTop	= 4
styleVerticalAlignTextTop	= 5
styleVerticalAlignMiddle	= 6
styleVerticalAlignBottom	= 7
styleVerticalAlignTextBottom	= 8
styleVerticalAlignInherit	= 9
styleVerticalAlignNotSet	= 10
styleVerticalAlign_Max	= 2147483647

styleFontWeightNotSet	= 0
styleFontWeight100	= 1
styleFontWeight200	= 2
styleFontWeight300	= 3
styleFontWeight400	= 4
styleFontWeight500	= 5
styleFontWeight600	= 6
styleFontWeight700	= 7
styleFontWeight800	= 8
styleFontWeight900	= 9
styleFontWeightNormal	= 10
styleFontWeightBold	= 11
styleFontWeightBolder	= 12
styleFontWeightLighter	= 13
styleFontWeight_Max	= 2147483647

styleBackgroundPositionXNotSet	= 0
styleBackgroundPositionXLeft	= 1
styleBackgroundPositionXCenter	= 2
styleBackgroundPositionXRight	= 3
styleBackgroundPositionX_Max	= 2147483647

styleBackgroundPositionYNotSet	= 0
styleBackgroundPositionYTop	= 1
styleBackgroundPositionYCenter	= 2
styleBackgroundPositionYBottom	= 3
styleBackgroundPositionY_Max	= 2147483647

styleFontSizeXXSmall	= 0
styleFontSizeXSmall	= 1
styleFontSizeSmall	= 2
styleFontSizeMedium	= 3
styleFontSizeLarge	= 4
styleFontSizeXLarge	= 5
styleFontSizeXXLarge	= 6
styleFontSizeSmaller	= 7
styleFontSizeLarger	= 8
styleFontSize_Max	= 2147483647

styleAutoAuto	= 0
styleAuto_Max	= 2147483647

styleNoneNone	= 0
styleNone_Max	= 2147483647

styleNormalNormal	= 0
styleNormal_Max	= 2147483647

styleBorderWidthThin	= 0
styleBorderWidthMedium	= 1
styleBorderWidthThick	= 2
styleBorderWidth_Max	= 2147483647

stylePositionNotSet	= 0
stylePositionstatic	= 1
stylePositionrelative	= 2
stylePositionabsolute	= 3
stylePositionfixed	= 4
stylePosition_Max	= 2147483647

styleBorderStyleNotSet	= 0
styleBorderStyleDotted	= 1
styleBorderStyleDashed	= 2
styleBorderStyleSolid	= 3
styleBorderStyleDouble	= 4
styleBorderStyleGroove	= 5
styleBorderStyleRidge	= 6
styleBorderStyleInset	= 7
styleBorderStyleOutset	= 8
styleBorderStyleWindowInset	= 9
styleBorderStyleNone	= 10
styleBorderStyle_Max	= 2147483647

styleStyleFloatNotSet	= 0
styleStyleFloatLeft	= 1
styleStyleFloatRight	= 2
styleStyleFloatNone	= 3
styleStyleFloat_Max	= 2147483647

styleDisplayNotSet	= 0
styleDisplayBlock	= 1
styleDisplayInline	= 2
styleDisplayListItem	= 3
styleDisplayNone	= 4
styleDisplayTableHeaderGroup	= 5
styleDisplayTableFooterGroup	= 6
styleDisplayInlineBlock	= 7
styleDisplay_Max	= 2147483647

styleVisibilityNotSet	= 0
styleVisibilityInherit	= 1
styleVisibilityVisible	= 2
styleVisibilityHidden	= 3
styleVisibility_Max	= 2147483647

styleListStyleTypeNotSet	= 0
styleListStyleTypeDisc	= 1
styleListStyleTypeCircle	= 2
styleListStyleTypeSquare	= 3
styleListStyleTypeDecimal	= 4
styleListStyleTypeLowerRoman	= 5
styleListStyleTypeUpperRoman	= 6
styleListStyleTypeLowerAlpha	= 7
styleListStyleTypeUpperAlpha	= 8
styleListStyleTypeNone	= 9
styleListStyleType_Max	= 2147483647

styleListStylePositionNotSet	= 0
styleListStylePositionInside	= 1
styleListStylePositionOutSide	= 2
styleListStylePosition_Max	= 2147483647

styleWhiteSpaceNotSet	= 0
styleWhiteSpaceNormal	= 1
styleWhiteSpacePre	= 2
styleWhiteSpaceNowrap	= 3
styleWhiteSpace_Max	= 2147483647

stylePageBreakNotSet	= 0
stylePageBreakAuto	= 1
stylePageBreakAlways	= 2
stylePageBreakLeft	= 3
stylePageBreakRight	= 4
stylePageBreak_Max	= 2147483647

styleCursorAuto	= 0
styleCursorCrosshair	= 1
styleCursorDefault	= 2
styleCursorHand	= 3
styleCursorMove	= 4
styleCursorE_resize	= 5
styleCursorNe_resize	= 6
styleCursorNw_resize	= 7
styleCursorN_resize	= 8
styleCursorSe_resize	= 9
styleCursorSw_resize	= 10
styleCursorS_resize	= 11
styleCursorW_resize	= 12
styleCursorText	= 13
styleCursorWait	= 14
styleCursorHelp	= 15
styleCursorPointer	= 16
styleCursorProgress	= 17
styleCursorNot_allowed	= 18
styleCursorNo_drop	= 19
styleCursorVertical_text	= 20
styleCursorall_scroll	= 21
styleCursorcol_resize	= 22
styleCursorrow_resize	= 23
styleCursorcustom	= 24
styleCursorNotSet	= 25
styleCursor_Max	= 2147483647

styleDirNotSet	= 0
styleDirLeftToRight	= 1
styleDirRightToLeft	= 2
styleDirInherit	= 3
styleDir_Max	= 2147483647

styleBidiNotSet	= 0
styleBidiNormal	= 1
styleBidiEmbed	= 2
styleBidiOverride	= 3
styleBidiInherit	= 4
styleBidi_Max	= 2147483647

styleImeModeAuto	= 0
styleImeModeActive	= 1
styleImeModeInactive	= 2
styleImeModeDisabled	= 3
styleImeModeNotSet	= 4
styleImeMode_Max	= 2147483647

styleRubyAlignNotSet	= 0
styleRubyAlignAuto	= 1
styleRubyAlignLeft	= 2
styleRubyAlignCenter	= 3
styleRubyAlignRight	= 4
styleRubyAlignDistributeLetter	= 5
styleRubyAlignDistributeSpace	= 6
styleRubyAlignLineEdge	= 7
styleRubyAlign_Max	= 2147483647

styleRubyPositionNotSet	= 0
styleRubyPositionAbove	= 1
styleRubyPositionInline	= 2
styleRubyPosition_Max	= 2147483647

styleRubyOverhangNotSet	= 0
styleRubyOverhangAuto	= 1
styleRubyOverhangWhitespace	= 2
styleRubyOverhangNone	= 3
styleRubyOverhang_Max	= 2147483647

styleLayoutGridCharNotSet	= 0
styleLayoutGridCharAuto	= 1
styleLayoutGridCharNone	= 2
styleLayoutGridChar_Max	= 2147483647

styleLayoutGridLineNotSet	= 0
styleLayoutGridLineAuto	= 1
styleLayoutGridLineNone	= 2
styleLayoutGridLine_Max	= 2147483647

styleLayoutGridModeNotSet	= 0
styleLayoutGridModeChar	= 1
styleLayoutGridModeLine	= 2
styleLayoutGridModeBoth	= 3
styleLayoutGridModeNone	= 4
styleLayoutGridMode_Max	= 2147483647

styleLayoutGridTypeNotSet	= 0
styleLayoutGridTypeLoose	= 1
styleLayoutGridTypeStrict	= 2
styleLayoutGridTypeFixed	= 3
styleLayoutGridType_Max	= 2147483647

styleLineBreakNotSet	= 0
styleLineBreakNormal	= 1
styleLineBreakStrict	= 2
styleLineBreak_Max	= 2147483647

styleWordBreakNotSet	= 0
styleWordBreakNormal	= 1
styleWordBreakBreakAll	= 2
styleWordBreakKeepAll	= 3
styleWordBreak_Max	= 2147483647

styleWordWrapNotSet	= 0
styleWordWrapOff	= 1
styleWordWrapOn	= 2
styleWordWrap_Max	= 2147483647

styleTextJustifyNotSet	= 0
styleTextJustifyInterWord	= 1
styleTextJustifyNewspaper	= 2
styleTextJustifyDistribute	= 3
styleTextJustifyDistributeAllLines	= 4
styleTextJustifyInterIdeograph	= 5
styleTextJustifyInterCluster	= 6
styleTextJustifyKashida	= 7
styleTextJustifyAuto	= 8
styleTextJustify_Max	= 2147483647

styleTextAlignLastNotSet	= 0
styleTextAlignLastLeft	= 1
styleTextAlignLastCenter	= 2
styleTextAlignLastRight	= 3
styleTextAlignLastJustify	= 4
styleTextAlignLastAuto	= 5
styleTextAlignLast_Max	= 2147483647

styleTextJustifyTrimNotSet	= 0
styleTextJustifyTrimNone	= 1
styleTextJustifyTrimPunctuation	= 2
styleTextJustifyTrimPunctAndKana	= 3
styleTextJustifyTrim_Max	= 2147483647

styleAcceleratorFalse	= 0
styleAcceleratorTrue	= 1
styleAccelerator_Max	= 2147483647

styleLayoutFlowHorizontal	= 0
styleLayoutFlowVerticalIdeographic	= 1
styleLayoutFlowNotSet	= 2
styleLayoutFlow_Max	= 2147483647

styleWritingModeLrtb	= 0
styleWritingModeTbrl	= 1
styleWritingModeRltb	= 2
styleWritingModeBtrl	= 3
styleWritingModeNotSet	= 4
styleWritingMode_Max	= 2147483647

styleBoolFalse	= 0
styleBoolTrue	= 1
styleBool_Max	= 2147483647

styleTextUnderlinePositionBelow	= 0
styleTextUnderlinePositionAbove	= 1
styleTextUnderlinePositionAuto	= 2
styleTextUnderlinePositionNotSet	= 3
styleTextUnderlinePosition_Max	= 2147483647

styleTextOverflowClip	= 0
styleTextOverflowEllipsis	= 1
styleTextOverflowNotSet	= 2
styleTextOverflow_Max	= 2147483647

styleInterpolationNotSet	= 0
styleInterpolationNN	= 1
styleInterpolationBCH	= 2
styleInterpolation_Max	= 2147483647

styleTextLineThroughStyleUndefined	= 0
styleTextLineThroughStyleSingle	= 1
styleTextLineThroughStyleDouble	= 2
styleTextLineThroughStyle_Max	= 2147483647

styleTextUnderlineStyleUndefined	= 0
styleTextUnderlineStyleSingle	= 1
styleTextUnderlineStyleDouble	= 2
styleTextUnderlineStyleWords	= 3
styleTextUnderlineStyleDotted	= 4
styleTextUnderlineStyleThick	= 5
styleTextUnderlineStyleDash	= 6
styleTextUnderlineStyleDotDash	= 7
styleTextUnderlineStyleDotDotDash	= 8
styleTextUnderlineStyleWave	= 9
styleTextUnderlineStyleSingleAccounting	= 10
styleTextUnderlineStyleDoubleAccounting	= 11
styleTextUnderlineStyleThickDash	= 12
styleTextUnderlineStyle_Max	= 2147483647

styleTextEffectNone	= 0
styleTextEffectEmboss	= 1
styleTextEffectEngrave	= 2
styleTextEffectOutline	= 3
styleTextEffect_Max	= 2147483647

styleDefaultTextSelectionFalse	= 0
styleDefaultTextSelectionTrue	= 1
styleDefaultTextSelection_Max	= 2147483647

styleTextDecorationNone	= 0
styleTextDecorationUnderline	= 1
styleTextDecorationOverline	= 2
styleTextDecorationLineThrough	= 3
styleTextDecorationBlink	= 4
styleTextDecoration_Max	= 2147483647

textDecorationNone	= 0
textDecorationUnderline	= 1
textDecorationOverline	= 2
textDecorationLineThrough	= 3
textDecorationBlink	= 4
textDecoration_Max	= 2147483647

htmlListTypeNotSet	= 0
htmlListTypeLargeAlpha	= 1
htmlListTypeSmallAlpha	= 2
htmlListTypeLargeRoman	= 3
htmlListTypeSmallRoman	= 4
htmlListTypeNumbers	= 5
htmlListTypeDisc	= 6
htmlListTypeCircle	= 7
htmlListTypeSquare	= 8
htmlListType_Max	= 2147483647

htmlMethodNotSet	= 0
htmlMethodGet	= 1
htmlMethodPost	= 2
htmlMethod_Max	= 2147483647

htmlWrapOff	= 1
htmlWrapSoft	= 2
htmlWrapHard	= 3
htmlWrap_Max	= 2147483647

htmlDirNotSet	= 0
htmlDirLeftToRight	= 1
htmlDirRightToLeft	= 2
htmlDir_Max	= 2147483647

htmlEditableInherit	= 0
htmlEditableTrue	= 1
htmlEditableFalse	= 2
htmlEditable_Max	= 2147483647

htmlInputNotSet	= 0
htmlInputButton	= 1
htmlInputCheckbox	= 2
htmlInputFile	= 3
htmlInputHidden	= 4
htmlInputImage	= 5
htmlInputPassword	= 6
htmlInputRadio	= 7
htmlInputReset	= 8
htmlInputSelectOne	= 9
htmlInputSelectMultiple	= 10
htmlInputSubmit	= 11
htmlInputText	= 12
htmlInputTextarea	= 13
htmlInputRichtext	= 14
htmlInput_Max	= 2147483647

htmlEncodingURL	= 0
htmlEncodingMultipart	= 1
htmlEncodingText	= 2
htmlEncoding_Max	= 2147483647

htmlAdjacencyBeforeBegin	= 1
htmlAdjacencyAfterBegin	= 2
htmlAdjacencyBeforeEnd	= 3
htmlAdjacencyAfterEnd	= 4
htmlAdjacency_Max	= 2147483647

htmlTabIndexNotSet	= -32768
htmlTabIndex_Max	= 2147483647

htmlComponentClient	= 0
htmlComponentSbLeft	= 1
htmlComponentSbPageLeft	= 2
htmlComponentSbHThumb	= 3
htmlComponentSbPageRight	= 4
htmlComponentSbRight	= 5
htmlComponentSbUp	= 6
htmlComponentSbPageUp	= 7
htmlComponentSbVThumb	= 8
htmlComponentSbPageDown	= 9
htmlComponentSbDown	= 10
htmlComponentSbLeft2	= 11
htmlComponentSbPageLeft2	= 12
htmlComponentSbRight2	= 13
htmlComponentSbPageRight2	= 14
htmlComponentSbUp2	= 15
htmlComponentSbPageUp2	= 16
htmlComponentSbDown2	= 17
htmlComponentSbPageDown2	= 18
htmlComponentSbTop	= 19
htmlComponentSbBottom	= 20
htmlComponentOutside	= 21
htmlComponentGHTopLeft	= 22
htmlComponentGHLeft	= 23
htmlComponentGHTop	= 24
htmlComponentGHBottomLeft	= 25
htmlComponentGHTopRight	= 26
htmlComponentGHBottom	= 27
htmlComponentGHRight	= 28
htmlComponentGHBottomRight	= 29
htmlComponent_Max	= 2147483647

htmlApplyLocationInside	= 0
htmlApplyLocationOutside	= 1
htmlApplyLocation_Max	= 2147483647

htmlGlyphModeNone	= 0
htmlGlyphModeBegin	= 1
htmlGlyphModeEnd	= 2
htmlGlyphModeBoth	= 3
htmlGlyphMode_Max	= 2147483647

htmlUnitCharacter	= 1
htmlUnitWord	= 2
htmlUnitSentence	= 3
htmlUnitTextEdit	= 6
htmlUnit_Max	= 2147483647

htmlEndPointsStartToStart	= 1
htmlEndPointsStartToEnd	= 2
htmlEndPointsEndToStart	= 3
htmlEndPointsEndToEnd	= 4
htmlEndPoints_Max	= 2147483647

htmlDirectionForward	= 99999
htmlDirectionBackward	= -99999
htmlDirection_Max	= 2147483647

htmlStartfileopen	= 0
htmlStartmouseover	= 1
htmlStart_Max	= 2147483647

bodyScrollyes	= 1
bodyScrollno	= 2
bodyScrollauto	= 4
bodyScrolldefault	= 3
bodyScroll_Max	= 2147483647

htmlSelectTypeSelectOne	= 1
htmlSelectTypeSelectMultiple	= 2
htmlSelectType_Max	= 2147483647

htmlSelectExFlagNone	= 0
htmlSelectExFlagHideSelectionInDesign	= 0x1
htmlSelectExFlag_Max	= 2147483647

htmlSelectionNone	= 0
htmlSelectionText	= 1
htmlSelectionControl	= 2
htmlSelectionTable	= 3
htmlSelection_Max	= 2147483647

htmlMarqueeBehaviorscroll	= 1
htmlMarqueeBehaviorslide	= 2
htmlMarqueeBehavioralternate	= 3
htmlMarqueeBehavior_Max	= 2147483647

htmlMarqueeDirectionleft	= 1
htmlMarqueeDirectionright	= 3
htmlMarqueeDirectionup	= 5
htmlMarqueeDirectiondown	= 7
htmlMarqueeDirection_Max	= 2147483647

htmlPersistStateNormal	= 0
htmlPersistStateFavorite	= 1
htmlPersistStateHistory	= 2
htmlPersistStateSnapshot	= 3
htmlPersistStateUserData	= 4
htmlPersistState_Max	= 2147483647

htmlDropEffectCopy	= 0
htmlDropEffectLink	= 1
htmlDropEffectMove	= 2
htmlDropEffectNone	= 3
htmlDropEffect_Max	= 2147483647

htmlEffectAllowedCopy	= 0
htmlEffectAllowedLink	= 1
htmlEffectAllowedMove	= 2
htmlEffectAllowedCopyLink	= 3
htmlEffectAllowedCopyMove	= 4
htmlEffectAllowedLinkMove	= 5
htmlEffectAllowedAll	= 6
htmlEffectAllowedNone	= 7
htmlEffectAllowedUninitialized	= 8
htmlEffectAllowed_Max	= 2147483647

htmlCompatModeBackCompat	= 0
htmlCompatModeCSS1Compat	= 1
htmlCompatMode_Max	= 2147483647

htmlCaptionAlignNotSet	= 0
htmlCaptionAlignLeft	= 1
htmlCaptionAlignCenter	= 2
htmlCaptionAlignRight	= 3
htmlCaptionAlignJustify	= 4
htmlCaptionAlignTop	= 5
htmlCaptionAlignBottom	= 6
htmlCaptionAlign_Max	= 2147483647

htmlCaptionVAlignNotSet	= 0
htmlCaptionVAlignTop	= 1
htmlCaptionVAlignBottom	= 2
htmlCaptionVAlign_Max	= 2147483647

htmlFrameNotSet	= 0
htmlFramevoid	= 1
htmlFrameabove	= 2
htmlFramebelow	= 3
htmlFramehsides	= 4
htmlFramelhs	= 5
htmlFramerhs	= 6
htmlFramevsides	= 7
htmlFramebox	= 8
htmlFrameborder	= 9
htmlFrame_Max	= 2147483647

htmlRulesNotSet	= 0
htmlRulesnone	= 1
htmlRulesgroups	= 2
htmlRulesrows	= 3
htmlRulescols	= 4
htmlRulesall	= 5
htmlRules_Max	= 2147483647

htmlCellAlignNotSet	= 0
htmlCellAlignLeft	= 1
htmlCellAlignCenter	= 2
htmlCellAlignRight	= 3
htmlCellAlignMiddle	= htmlCellAlignCenter
htmlCellAlign_Max	= 2147483647

htmlCellVAlignNotSet	= 0
htmlCellVAlignTop	= 1
htmlCellVAlignMiddle	= 2
htmlCellVAlignBottom	= 3
htmlCellVAlignBaseline	= 4
htmlCellVAlignCenter	= htmlCellVAlignMiddle
htmlCellVAlign_Max	= 2147483647

frameScrollingyes	= 1
frameScrollingno	= 2
frameScrollingauto	= 4
frameScrolling_Max	= 2147483647

ELEMENT_CORNER_NONE	= 0
ELEMENT_CORNER_TOP	= 1
ELEMENT_CORNER_LEFT	= 2
ELEMENT_CORNER_BOTTOM	= 3
ELEMENT_CORNER_RIGHT	= 4
ELEMENT_CORNER_TOPLEFT	= 5
ELEMENT_CORNER_TOPRIGHT	= 6
ELEMENT_CORNER_BOTTOMLEFT	= 7
ELEMENT_CORNER_BOTTOMRIGHT	= 8
ELEMENT_CORNER_Max	= 2147483647

SUHV_PROMPTBEFORENO	= 0x1
SUHV_SILENTYES	= 0x2
SUHV_UNSECURESOURCE	= 0x4
SECUREURLHOSTVALIDATE_FLAGS_Max	= 2147483647

POINTER_GRAVITY_Left	= 0
POINTER_GRAVITY_Right	= 1
POINTER_GRAVITY_Max	= 2147483647

ELEM_ADJ_BeforeBegin	= 0
ELEM_ADJ_AfterBegin	= 1
ELEM_ADJ_BeforeEnd	= 2
ELEM_ADJ_AfterEnd	= 3
ELEMENT_ADJACENCY_Max	= 2147483647

CONTEXT_TYPE_None	= 0
CONTEXT_TYPE_Text	= 1
CONTEXT_TYPE_EnterScope	= 2
CONTEXT_TYPE_ExitScope	= 3
CONTEXT_TYPE_NoScope	= 4
MARKUP_CONTEXT_TYPE_Max	= 2147483647

FINDTEXT_BACKWARDS	= 0x1
FINDTEXT_WHOLEWORD	= 0x2
FINDTEXT_MATCHCASE	= 0x4
FINDTEXT_RAW	= 0x20000
FINDTEXT_MATCHDIAC	= 0x20000000
FINDTEXT_MATCHKASHIDA	= 0x40000000
FINDTEXT_MATCHALEFHAMZA	= 0x80000000
FINDTEXT_FLAGS_Max	= 2147483647

MOVEUNIT_PREVCHAR	= 0
MOVEUNIT_NEXTCHAR	= 1
MOVEUNIT_PREVCLUSTERBEGIN	= 2
MOVEUNIT_NEXTCLUSTERBEGIN	= 3
MOVEUNIT_PREVCLUSTEREND	= 4
MOVEUNIT_NEXTCLUSTEREND	= 5
MOVEUNIT_PREVWORDBEGIN	= 6
MOVEUNIT_NEXTWORDBEGIN	= 7
MOVEUNIT_PREVWORDEND	= 8
MOVEUNIT_NEXTWORDEND	= 9
MOVEUNIT_PREVPROOFWORD	= 10
MOVEUNIT_NEXTPROOFWORD	= 11
MOVEUNIT_NEXTURLBEGIN	= 12
MOVEUNIT_PREVURLBEGIN	= 13
MOVEUNIT_NEXTURLEND	= 14
MOVEUNIT_PREVURLEND	= 15
MOVEUNIT_PREVSENTENCE	= 16
MOVEUNIT_NEXTSENTENCE	= 17
MOVEUNIT_PREVBLOCK	= 18
MOVEUNIT_NEXTBLOCK	= 19
MOVEUNIT_ACTION_Max	= 2147483647

PARSE_ABSOLUTIFYIE40URLS	= 0x1
PARSE_FLAGS_Max	= 2147483647

TAGID_NULL	= 0
TAGID_UNKNOWN	= 1
TAGID_A	= 2
TAGID_ACRONYM	= 3
TAGID_ADDRESS	= 4
TAGID_APPLET	= 5
TAGID_AREA	= 6
TAGID_B	= 7
TAGID_BASE	= 8
TAGID_BASEFONT	= 9
TAGID_BDO	= 10
TAGID_BGSOUND	= 11
TAGID_BIG	= 12
TAGID_BLINK	= 13
TAGID_BLOCKQUOTE	= 14
TAGID_BODY	= 15
TAGID_BR	= 16
TAGID_BUTTON	= 17
TAGID_CAPTION	= 18
TAGID_CENTER	= 19
TAGID_CITE	= 20
TAGID_CODE	= 21
TAGID_COL	= 22
TAGID_COLGROUP	= 23
TAGID_COMMENT	= 24
TAGID_COMMENT_RAW	= 25
TAGID_DD	= 26
TAGID_DEL	= 27
TAGID_DFN	= 28
TAGID_DIR	= 29
TAGID_DIV	= 30
TAGID_DL	= 31
TAGID_DT	= 32
TAGID_EM	= 33
TAGID_EMBED	= 34
TAGID_FIELDSET	= 35
TAGID_FONT	= 36
TAGID_FORM	= 37
TAGID_FRAME	= 38
TAGID_FRAMESET	= 39
TAGID_GENERIC	= 40
TAGID_H1	= 41
TAGID_H2	= 42
TAGID_H3	= 43
TAGID_H4	= 44
TAGID_H5	= 45
TAGID_H6	= 46
TAGID_HEAD	= 47
TAGID_HR	= 48
TAGID_HTML	= 49
TAGID_I	= 50
TAGID_IFRAME	= 51
TAGID_IMG	= 52
TAGID_INPUT	= 53
TAGID_INS	= 54
TAGID_KBD	= 55
TAGID_LABEL	= 56
TAGID_LEGEND	= 57
TAGID_LI	= 58
TAGID_LINK	= 59
TAGID_LISTING	= 60
TAGID_MAP	= 61
TAGID_MARQUEE	= 62
TAGID_MENU	= 63
TAGID_META	= 64
TAGID_NEXTID	= 65
TAGID_NOBR	= 66
TAGID_NOEMBED	= 67
TAGID_NOFRAMES	= 68
TAGID_NOSCRIPT	= 69
TAGID_OBJECT	= 70
TAGID_OL	= 71
TAGID_OPTION	= 72
TAGID_P	= 73
TAGID_PARAM	= 74
TAGID_PLAINTEXT	= 75
TAGID_PRE	= 76
TAGID_Q	= 77
TAGID_RP	= 78
TAGID_RT	= 79
TAGID_RUBY	= 80
TAGID_S	= 81
TAGID_SAMP	= 82
TAGID_SCRIPT	= 83
TAGID_SELECT	= 84
TAGID_SMALL	= 85
TAGID_SPAN	= 86
TAGID_STRIKE	= 87
TAGID_STRONG	= 88
TAGID_STYLE	= 89
TAGID_SUB	= 90
TAGID_SUP	= 91
TAGID_TABLE	= 92
TAGID_TBODY	= 93
TAGID_TC	= 94
TAGID_TD	= 95
TAGID_TEXTAREA	= 96
TAGID_TFOOT	= 97
TAGID_TH	= 98
TAGID_THEAD	= 99
TAGID_TITLE	= 100
TAGID_TR	= 101
TAGID_TT	= 102
TAGID_U	= 103
TAGID_UL	= 104
TAGID_VAR	= 105
TAGID_WBR	= 106
TAGID_XMP	= 107
TAGID_ROOT	= 108
TAGID_OPTGROUP	= 109
TAGID_ABBR	= 110
TAGID_COUNT	= 111
TAGID_LAST_PREDEFINED	= 10000
ELEMENT_TAG_ID_Max	= 2147483647

SELECTION_TYPE_None	= 0
SELECTION_TYPE_Caret	= 1
SELECTION_TYPE_Text	= 2
SELECTION_TYPE_Control	= 3
SELECTION_TYPE_Max	= 2147483647

SAVE_SEGMENTS_NoIE4SelectionCompat	= 0x1
SAVE_SEGMENTS_FLAGS_Max	= 2147483647

CARET_DIRECTION_INDETERMINATE	= 0
CARET_DIRECTION_SAME	= 1
CARET_DIRECTION_BACKWARD	= 2
CARET_DIRECTION_FORWARD	= 3
CARET_DIRECTION_Max	= 2147483647

LINE_DIRECTION_RightToLeft	= 1
LINE_DIRECTION_LeftToRight	= 2
LINE_DIRECTION_Max	= 2147483647

HT_OPT_AllowAfterEOL	= 0x1
HT_OPTIONS_Max	= 2147483647

HT_RESULTS_Glyph	= 0x1
HT_RESULTS_Max	= 2147483647

DISPLAY_MOVEUNIT_PreviousLine	= 1
DISPLAY_MOVEUNIT_NextLine	= 2
DISPLAY_MOVEUNIT_CurrentLineStart	= 3
DISPLAY_MOVEUNIT_CurrentLineEnd	= 4
DISPLAY_MOVEUNIT_TopOfWindow	= 5
DISPLAY_MOVEUNIT_BottomOfWindow	= 6
DISPLAY_MOVEUNIT_Max	= 2147483647

DISPLAY_GRAVITY_PreviousLine	= 1
DISPLAY_GRAVITY_NextLine	= 2
DISPLAY_GRAVITY_Max	= 2147483647

DISPLAY_BREAK_None	= 0
DISPLAY_BREAK_Block	= 0x1
DISPLAY_BREAK_Break	= 0x2
DISPLAY_BREAK_Max	= 2147483647

COORD_SYSTEM_GLOBAL	= 0
COORD_SYSTEM_PARENT	= 1
COORD_SYSTEM_CONTAINER	= 2
COORD_SYSTEM_CONTENT	= 3
COORD_SYSTEM_FRAME	= 4
COORD_SYSTEM_Max	= 2147483647

HTMLPAINTER_OPAQUE	= 0x1
HTMLPAINTER_TRANSPARENT	= 0x2
HTMLPAINTER_ALPHA	= 0x4
HTMLPAINTER_COMPLEX	= 0x8
HTMLPAINTER_OVERLAY	= 0x10
HTMLPAINTER_HITTEST	= 0x20
HTMLPAINTER_SURFACE	= 0x100
HTMLPAINTER_3DSURFACE	= 0x200
HTMLPAINTER_NOBAND	= 0x400
HTMLPAINTER_NODC	= 0x1000
HTMLPAINTER_NOPHYSICALCLIP	= 0x2000
HTMLPAINTER_NOSAVEDC	= 0x4000
HTMLPAINTER_SUPPORTS_XFORM	= 0x8000
HTMLPAINTER_EXPAND	= 0x10000
HTMLPAINTER_NOSCROLLBITS	= 0x20000
HTML_PAINTER_Max	= 2147483647

HTMLPAINT_ZORDER_NONE	= 0
HTMLPAINT_ZORDER_REPLACE_ALL	= 1
HTMLPAINT_ZORDER_REPLACE_CONTENT	= 2
HTMLPAINT_ZORDER_REPLACE_BACKGROUND	= 3
HTMLPAINT_ZORDER_BELOW_CONTENT	= 4
HTMLPAINT_ZORDER_BELOW_FLOW	= 5
HTMLPAINT_ZORDER_ABOVE_FLOW	= 6
HTMLPAINT_ZORDER_ABOVE_CONTENT	= 7
HTMLPAINT_ZORDER_WINDOW_TOP	= 8
HTML_PAINT_ZORDER_Max	= 2147483647

HTMLPAINT_DRAW_UPDATEREGION	= 0x1
HTMLPAINT_DRAW_USE_XFORM	= 0x2
HTML_PAINT_DRAW_FLAGS_Max	= 2147483647

HTMLPAINT_EVENT_TARGET	= 0x1
HTMLPAINT_EVENT_SETCURSOR	= 0x2
HTML_PAINT_EVENT_FLAGS_Max	= 2147483647

HTMLPAINT_DRAWINFO_VIEWPORT	= 0x1
HTMLPAINT_DRAWINFO_UPDATEREGION	= 0x2
HTMLPAINT_DRAWINFO_XFORM	= 0x4
HTML_PAINT_DRAW_INFO_FLAGS_Max	= 2147483647

HTML_PAINTER_INFO STRUCT
	lFlags DD
	lZOrder DD
	iidDrawObject GUID
	rcExpand RECT
ENDS

HTML_PAINT_XFORM STRUCT
	eM11 FLOAT
	eM12 FLOAT
	eM21 FLOAT
	eM22 FLOAT
	eDx FLOAT
	eDy FLOAT
ENDS

HTML_PAINT_DRAW_INFO STRUCT
	rcViewport RECT
	hrgnUpdate HANDLE
	xform HTML_PAINT_XFORM
ENDS

HTMLDlgFlagNo	= 0
HTMLDlgFlagOff	= 0
HTMLDlgFlag0	= 0
HTMLDlgFlagYes	= 1
HTMLDlgFlagOn	= 1
HTMLDlgFlag1	= 1
HTMLDlgFlagNotSet	= -1
HTMLDlgFlag_Max	= 2147483647

HTMLDlgBorderThin	= 0
HTMLDlgBorderThick	= 0x40000
HTMLDlgBorder_Max	= 2147483647

HTMLDlgEdgeSunken	= 0
HTMLDlgEdgeRaised	= 16
HTMLDlgEdge_Max	= 2147483647

HTMLDlgCenterNo	= 0
HTMLDlgCenterOff	= 0
HTMLDlgCenter0	= 0
HTMLDlgCenterYes	= 1
HTMLDlgCenterOn	= 1
HTMLDlgCenter1	= 1
HTMLDlgCenterParent	= 1
HTMLDlgCenterDesktop	= 2
HTMLDlgCenter_Max	= 2147483647

HTMLAppFlagNo	= 0
HTMLAppFlagOff	= 0
HTMLAppFlag0	= 0
HTMLAppFlagYes	= 1
HTMLAppFlagOn	= 1
HTMLAppFlag1	= 1
HTMLAppFlag_Max	= 2147483647

HTMLMinimizeFlagNo	= 0
HTMLMinimizeFlagYes	= 0x20000
HTMLMinimizeFlag_Max	= 2147483647

HTMLMaximizeFlagNo	= 0
HTMLMaximizeFlagYes	= 0x10000
HTMLMaximizeFlag_Max	= 2147483647

HTMLCaptionFlagNo	= 0
HTMLCaptionFlagYes	= 0xc00000
HTMLCaptionFlag_Max	= 2147483647

HTMLSysMenuFlagNo	= 0
HTMLSysMenuFlagYes	= 0x80000
HTMLSysMenuFlag_Max	= 2147483647

HTMLBorderNone	= 0
HTMLBorderThick	= 0x40000
HTMLBorderDialog	= 0x400000
HTMLBorderThin	= 0x800000
HTMLBorder_Max	= 2147483647

HTMLBorderStyleNormal	= 0
HTMLBorderStyleRaised	= 0x100
HTMLBorderStyleSunken	= 0x200
HTMLBorderStylecombined	= 0x300
HTMLBorderStyleStatic	= 0x20000
HTMLBorderStyle_Max	= 2147483647

HTMLWindowStateNormal	= 1
HTMLWindowStateMaximize	= 3
HTMLWindowStateMinimize	= 6
HTMLWindowState_Max	= 2147483647

BEHAVIOREVENT_FIRST	= 0
BEHAVIOREVENT_CONTENTREADY	= 0
BEHAVIOREVENT_DOCUMENTREADY	= 1
BEHAVIOREVENT_APPLYSTYLE	= 2
BEHAVIOREVENT_DOCUMENTCONTEXTCHANGE	= 3
BEHAVIOREVENT_CONTENTSAVE	= 4
BEHAVIOREVENT_LAST	= 4
BEHAVIOR_EVENT_Max	= 2147483647

BEHAVIOREVENTFLAGS_BUBBLE	= 1
BEHAVIOREVENTFLAGS_STANDARDADDITIVE	= 2
BEHAVIOR_EVENT_FLAGS_Max	= 2147483647

BEHAVIORRENDERINFO_BEFOREBACKGROUND	= 0x1
BEHAVIORRENDERINFO_AFTERBACKGROUND	= 0x2
BEHAVIORRENDERINFO_BEFORECONTENT	= 0x4
BEHAVIORRENDERINFO_AFTERCONTENT	= 0x8
BEHAVIORRENDERINFO_AFTERFOREGROUND	= 0x20
BEHAVIORRENDERINFO_ABOVECONTENT	= 0x28
BEHAVIORRENDERINFO_ALLLAYERS	= 0xff
BEHAVIORRENDERINFO_DISABLEBACKGROUND	= 0x100
BEHAVIORRENDERINFO_DISABLENEGATIVEZ	= 0x200
BEHAVIORRENDERINFO_DISABLECONTENT	= 0x400
BEHAVIORRENDERINFO_DISABLEPOSITIVEZ	= 0x800
BEHAVIORRENDERINFO_DISABLEALLLAYERS	= 0xf00
BEHAVIORRENDERINFO_HITTESTING	= 0x1000
BEHAVIORRENDERINFO_SURFACE	= 0x100000
BEHAVIORRENDERINFO_3DSURFACE	= 0x200000
BEHAVIOR_RENDER_INFO_Max	= 2147483647

BEHAVIOR_FIRSTRELATION	= 0
BEHAVIOR_SAMEELEMENT	= 0
BEHAVIOR_PARENT	= 1
BEHAVIOR_CHILD	= 2
BEHAVIOR_SIBLING	= 3
BEHAVIOR_LASTRELATION	= 3
BEHAVIOR_RELATION_Max	= 2147483647

BEHAVIORLAYOUTINFO_FULLDELEGATION	= 0x1
BEHAVIORLAYOUTINFO_MODIFYNATURAL	= 0x2
BEHAVIORLAYOUTINFO_MAPSIZE	= 0x4
BEHAVIOR_LAYOUT_INFO_Max	= 2147483647

BEHAVIORLAYOUTMODE_NATURAL	= 0x1
BEHAVIORLAYOUTMODE_MINWIDTH	= 0x2
BEHAVIORLAYOUTMODE_MAXWIDTH	= 0x4
BEHAVIORLAYOUTMODE_MEDIA_RESOLUTION	= 0x4000
BEHAVIORLAYOUTMODE_FINAL_PERCENT	= 0x8000
BEHAVIOR_LAYOUT_MODE_Max	= 2147483647

ELEMENTDESCRIPTORFLAGS_LITERAL	= 1
ELEMENTDESCRIPTORFLAGS_NESTED_LITERAL	= 2
ELEMENTDESCRIPTOR_FLAGS_Max	= 2147483647

ELEMENTNAMESPACEFLAGS_ALLOWANYTAG	= 0x1
ELEMENTNAMESPACEFLAGS_QUERYFORUNKNOWNTAGS	= 0x2
ELEMENTNAMESPACE_FLAGS_Max	= 2147483647

#DEFINE GUID_IID_IHTMLEventObj <0x3050f32d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLEventObj STRUCT
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
	get_srcElement PTR
	get_altKey PTR
	get_ctrlKey PTR
	get_shiftKey PTR
	put_returnValue PTR
	get_returnValue PTR
	put_cancelBubble PTR
	get_cancelBubble PTR
	get_fromElement PTR
	get_toElement PTR
	put_keyCode PTR
	get_keyCode PTR
	get_button PTR
	get_type PTR
	get_qualifier PTR
	get_reason PTR
	get_x PTR
	get_y PTR
	get_clientX PTR
	get_clientY PTR
	get_offsetX PTR
	get_offsetY PTR
	get_screenX PTR
	get_screenY PTR
	get_srcFilter PTR
ENDS

#DEFINE GUID_IID_IElementBehaviorSite <0x3050f427,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementBehaviorSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetElement PTR
	RegisterNotification PTR
ENDS

#DEFINE GUID_IID_IElementBehavior <0x3050f425,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementBehavior STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Init PTR
	Notify PTR
	Detach PTR
ENDS

#DEFINE GUID_IID_IElementBehaviorFactory <0x3050f429,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementBehaviorFactory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	FindBehavior PTR
ENDS

#DEFINE GUID_IID_IElementBehaviorSiteOM <0x3050f489,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementBehaviorSiteOM STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	RegisterEvent PTR
	GetEventCookie PTR
	FireEvent PTR
	CreateEventObject PTR
	RegisterName PTR
	RegisterUrn PTR
ENDS

#DEFINE GUID_IID_IElementBehaviorRender <0x3050f4aa,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementBehaviorRender STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Draw PTR
	GetRenderInfo PTR
	HitTestPoint PTR
ENDS

#DEFINE GUID_IID_IElementBehaviorSiteRender <0x3050f4a7,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementBehaviorSiteRender STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Invalidate PTR
	InvalidateRenderInfo PTR
	InvalidateStyle PTR
ENDS

#DEFINE GUID_IID_IHTMLStyle <0x3050f25e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLStyle STRUCT
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
	put_fontFamily PTR
	get_fontFamily PTR
	put_fontStyle PTR
	get_fontStyle PTR
	put_fontVariant PTR
	get_fontVariant PTR
	put_fontWeight PTR
	get_fontWeight PTR
	put_fontSize PTR
	get_fontSize PTR
	put_font PTR
	get_font PTR
	put_color PTR
	get_color PTR
	put_background PTR
	get_background PTR
	put_backgroundColor PTR
	get_backgroundColor PTR
	put_backgroundImage PTR
	get_backgroundImage PTR
	put_backgroundRepeat PTR
	get_backgroundRepeat PTR
	put_backgroundAttachment PTR
	get_backgroundAttachment PTR
	put_backgroundPosition PTR
	get_backgroundPosition PTR
	put_backgroundPositionX PTR
	get_backgroundPositionX PTR
	put_backgroundPositionY PTR
	get_backgroundPositionY PTR
	put_wordSpacing PTR
	get_wordSpacing PTR
	put_letterSpacing PTR
	get_letterSpacing PTR
	put_textDecoration PTR
	get_textDecoration PTR
	put_textDecorationNone PTR
	get_textDecorationNone PTR
	put_textDecorationUnderline PTR
	get_textDecorationUnderline PTR
	put_textDecorationOverline PTR
	get_textDecorationOverline PTR
	put_textDecorationLineThrough PTR
	get_textDecorationLineThrough PTR
	put_textDecorationBlink PTR
	get_textDecorationBlink PTR
	put_verticalAlign PTR
	get_verticalAlign PTR
	put_textTransform PTR
	get_textTransform PTR
	put_textAlign PTR
	get_textAlign PTR
	put_textIndent PTR
	get_textIndent PTR
	put_lineHeight PTR
	get_lineHeight PTR
	put_marginTop PTR
	get_marginTop PTR
	put_marginRight PTR
	get_marginRight PTR
	put_marginBottom PTR
	get_marginBottom PTR
	put_marginLeft PTR
	get_marginLeft PTR
	put_margin PTR
	get_margin PTR
	put_paddingTop PTR
	get_paddingTop PTR
	put_paddingRight PTR
	get_paddingRight PTR
	put_paddingBottom PTR
	get_paddingBottom PTR
	put_paddingLeft PTR
	get_paddingLeft PTR
	put_padding PTR
	get_padding PTR
	put_border PTR
	get_border PTR
	put_borderTop PTR
	get_borderTop PTR
	put_borderRight PTR
	get_borderRight PTR
	put_borderBottom PTR
	get_borderBottom PTR
	put_borderLeft PTR
	get_borderLeft PTR
	put_borderColor PTR
	get_borderColor PTR
	put_borderTopColor PTR
	get_borderTopColor PTR
	put_borderRightColor PTR
	get_borderRightColor PTR
	put_borderBottomColor PTR
	get_borderBottomColor PTR
	put_borderLeftColor PTR
	get_borderLeftColor PTR
	put_borderWidth PTR
	get_borderWidth PTR
	put_borderTopWidth PTR
	get_borderTopWidth PTR
	put_borderRightWidth PTR
	get_borderRightWidth PTR
	put_borderBottomWidth PTR
	get_borderBottomWidth PTR
	put_borderLeftWidth PTR
	get_borderLeftWidth PTR
	put_borderStyle PTR
	get_borderStyle PTR
	put_borderTopStyle PTR
	get_borderTopStyle PTR
	put_borderRightStyle PTR
	get_borderRightStyle PTR
	put_borderBottomStyle PTR
	get_borderBottomStyle PTR
	put_borderLeftStyle PTR
	get_borderLeftStyle PTR
	put_width PTR
	get_width PTR
	put_height PTR
	get_height PTR
	put_styleFloat PTR
	get_styleFloat PTR
	put_clear PTR
	get_clear PTR
	put_display PTR
	get_display PTR
	put_visibility PTR
	get_visibility PTR
	put_listStyleType PTR
	get_listStyleType PTR
	put_listStylePosition PTR
	get_listStylePosition PTR
	put_listStyleImage PTR
	get_listStyleImage PTR
	put_listStyle PTR
	get_listStyle PTR
	put_whiteSpace PTR
	get_whiteSpace PTR
	put_top PTR
	get_top PTR
	put_left PTR
	get_left PTR
	get_position PTR
	put_zIndex PTR
	get_zIndex PTR
	put_overflow PTR
	get_overflow PTR
	put_pageBreakBefore PTR
	get_pageBreakBefore PTR
	put_pageBreakAfter PTR
	get_pageBreakAfter PTR
	put_cssText PTR
	get_cssText PTR
	put_pixelTop PTR
	get_pixelTop PTR
	put_pixelLeft PTR
	get_pixelLeft PTR
	put_pixelWidth PTR
	get_pixelWidth PTR
	put_pixelHeight PTR
	get_pixelHeight PTR
	put_posTop PTR
	get_posTop PTR
	put_posLeft PTR
	get_posLeft PTR
	put_posWidth PTR
	get_posWidth PTR
	put_posHeight PTR
	get_posHeight PTR
	put_cursor PTR
	get_cursor PTR
	put_clip PTR
	get_clip PTR
	put_filter PTR
	get_filter PTR
	setAttribute PTR
	getAttribute PTR
	removeAttribute PTR
	toString PTR
ENDS

#DEFINE GUID_IID_IHTMLStyle2 <0x3050f4a2,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLStyle2 STRUCT
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
	put_tableLayout PTR
	get_tableLayout PTR
	put_borderCollapse PTR
	get_borderCollapse PTR
	put_direction PTR
	get_direction PTR
	put_behavior PTR
	get_behavior PTR
	setExpression PTR
	getExpression PTR
	removeExpression PTR
	put_position PTR
	get_position PTR
	put_unicodeBidi PTR
	get_unicodeBidi PTR
	put_bottom PTR
	get_bottom PTR
	put_right PTR
	get_right PTR
	put_pixelBottom PTR
	get_pixelBottom PTR
	put_pixelRight PTR
	get_pixelRight PTR
	put_posBottom PTR
	get_posBottom PTR
	put_posRight PTR
	get_posRight PTR
	put_imeMode PTR
	get_imeMode PTR
	put_rubyAlign PTR
	get_rubyAlign PTR
	put_rubyPosition PTR
	get_rubyPosition PTR
	put_rubyOverhang PTR
	get_rubyOverhang PTR
	put_layoutGridChar PTR
	get_layoutGridChar PTR
	put_layoutGridLine PTR
	get_layoutGridLine PTR
	put_layoutGridMode PTR
	get_layoutGridMode PTR
	put_layoutGridType PTR
	get_layoutGridType PTR
	put_layoutGrid PTR
	put_wordBreak PTR
	get_wordBreak PTR
	put_lineBreak PTR
	get_lineBreak PTR
	put_textJustify PTR
	get_textJustify PTR
	put_textJustifyTrim PTR
	get_textJustifyTrim PTR
	put_textKashida PTR
	get_textKashida PTR
	put_textAutospace PTR
	get_textAutospace PTR
	put_overflowX PTR
	get_overflowX PTR
	put_overflowY PTR
	get_overflowY PTR
	put_accelerator PTR
	get_accelerator PTR
ENDS

#DEFINE GUID_IID_IHTMLStyle3 <0x3050f656,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLStyle3 STRUCT
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
	put_layoutFlow PTR
	get_layoutFlow PTR
	put_zoom PTR
	get_zoom PTR
	put_wordWrap PTR
	get_wordWrap PTR
	put_textUnderlinePosition PTR
	get_textUnderlinePosition PTR
	put_scrollbarBaseColor PTR
	get_scrollbarBaseColor PTR
	put_scrollbarFaceColor PTR
	get_scrollbarFaceColor PTR
	put_scrollbar3dLightColor PTR
	get_scrollbar3dLightColor PTR
	put_scrollbarShadowColor PTR
	get_scrollbarShadowColor PTR
	put_scrollbarHighlightColor PTR
	get_scrollbarHighlightColor PTR
	put_scrollbarDarkShadowColor PTR
	get_scrollbarDarkShadowColor PTR
	put_scrollbarArrowColor PTR
	get_scrollbarArrowColor PTR
	put_scrollbarTrackColor PTR
	get_scrollbarTrackColor PTR
	put_writingMode PTR
	get_writingMode PTR
	put_textAlignLast PTR
	get_textAlignLast PTR
	put_textKashidaSpace PTR
	get_textKashidaSpace PTR
ENDS

#DEFINE GUID_IID_IHTMLStyle4 <0x3050f816,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLStyle4 STRUCT
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
	put_textOverflow PTR
	get_textOverflow PTR
	put_minHeight PTR
	get_minHeight PTR
ENDS

#DEFINE GUID_IID_IHTMLStyle5 <0x3050f33a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLStyle5 STRUCT
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
	put_msInterpolationMode PTR
	get_msInterpolationMode PTR
	put_maxHeight PTR
	get_maxHeight PTR
	put_minWidth PTR
	get_minWidth PTR
	put_maxWidth PTR
	get_maxWidth PTR
ENDS

#DEFINE GUID_IID_IHTMLRuleStyle <0x3050f3cf,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLRuleStyle STRUCT
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
	put_fontFamily PTR
	get_fontFamily PTR
	put_fontStyle PTR
	get_fontStyle PTR
	put_fontVariant PTR
	get_fontVariant PTR
	put_fontWeight PTR
	get_fontWeight PTR
	put_fontSize PTR
	get_fontSize PTR
	put_font PTR
	get_font PTR
	put_color PTR
	get_color PTR
	put_background PTR
	get_background PTR
	put_backgroundColor PTR
	get_backgroundColor PTR
	put_backgroundImage PTR
	get_backgroundImage PTR
	put_backgroundRepeat PTR
	get_backgroundRepeat PTR
	put_backgroundAttachment PTR
	get_backgroundAttachment PTR
	put_backgroundPosition PTR
	get_backgroundPosition PTR
	put_backgroundPositionX PTR
	get_backgroundPositionX PTR
	put_backgroundPositionY PTR
	get_backgroundPositionY PTR
	put_wordSpacing PTR
	get_wordSpacing PTR
	put_letterSpacing PTR
	get_letterSpacing PTR
	put_textDecoration PTR
	get_textDecoration PTR
	put_textDecorationNone PTR
	get_textDecorationNone PTR
	put_textDecorationUnderline PTR
	get_textDecorationUnderline PTR
	put_textDecorationOverline PTR
	get_textDecorationOverline PTR
	put_textDecorationLineThrough PTR
	get_textDecorationLineThrough PTR
	put_textDecorationBlink PTR
	get_textDecorationBlink PTR
	put_verticalAlign PTR
	get_verticalAlign PTR
	put_textTransform PTR
	get_textTransform PTR
	put_textAlign PTR
	get_textAlign PTR
	put_textIndent PTR
	get_textIndent PTR
	put_lineHeight PTR
	get_lineHeight PTR
	put_marginTop PTR
	get_marginTop PTR
	put_marginRight PTR
	get_marginRight PTR
	put_marginBottom PTR
	get_marginBottom PTR
	put_marginLeft PTR
	get_marginLeft PTR
	put_margin PTR
	get_margin PTR
	put_paddingTop PTR
	get_paddingTop PTR
	put_paddingRight PTR
	get_paddingRight PTR
	put_paddingBottom PTR
	get_paddingBottom PTR
	put_paddingLeft PTR
	get_paddingLeft PTR
	put_padding PTR
	get_padding PTR
	put_border PTR
	get_border PTR
	put_borderTop PTR
	get_borderTop PTR
	put_borderRight PTR
	get_borderRight PTR
	put_borderBottom PTR
	get_borderBottom PTR
	put_borderLeft PTR
	get_borderLeft PTR
	put_borderColor PTR
	get_borderColor PTR
	put_borderTopColor PTR
	get_borderTopColor PTR
	put_borderRightColor PTR
	get_borderRightColor PTR
	put_borderBottomColor PTR
	get_borderBottomColor PTR
	put_borderLeftColor PTR
	get_borderLeftColor PTR
	put_borderWidth PTR
	get_borderWidth PTR
	put_borderTopWidth PTR
	get_borderTopWidth PTR
	put_borderRightWidth PTR
	get_borderRightWidth PTR
	put_borderBottomWidth PTR
	get_borderBottomWidth PTR
	put_borderLeftWidth PTR
	get_borderLeftWidth PTR
	put_borderStyle PTR
	get_borderStyle PTR
	put_borderTopStyle PTR
	get_borderTopStyle PTR
	put_borderRightStyle PTR
	get_borderRightStyle PTR
	put_borderBottomStyle PTR
	get_borderBottomStyle PTR
	put_borderLeftStyle PTR
	get_borderLeftStyle PTR
	put_width PTR
	get_width PTR
	put_height PTR
	get_height PTR
	put_styleFloat PTR
	get_styleFloat PTR
	put_clear PTR
	get_clear PTR
	put_display PTR
	get_display PTR
	put_visibility PTR
	get_visibility PTR
	put_listStyleType PTR
	get_listStyleType PTR
	put_listStylePosition PTR
	get_listStylePosition PTR
	put_listStyleImage PTR
	get_listStyleImage PTR
	put_listStyle PTR
	get_listStyle PTR
	put_whiteSpace PTR
	get_whiteSpace PTR
	put_top PTR
	get_top PTR
	put_left PTR
	get_left PTR
	get_position PTR
	put_zIndex PTR
	get_zIndex PTR
	put_overflow PTR
	get_overflow PTR
	put_pageBreakBefore PTR
	get_pageBreakBefore PTR
 	put_pageBreakAfter PTR
	get_pageBreakAfter PTR
	put_cssText PTR
	get_cssText PTR
	put_cursor PTR
	get_cursor PTR
	put_clip PTR
	get_clip PTR
	put_filter PTR
	get_filter PTR
	setAttribute PTR
	getAttribute PTR
	removeAttribute PTR
ENDS

#DEFINE GUID_IID_IHTMLRuleStyle2 <0x3050f4ac,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLRuleStyle2 STRUCT
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
	put_tableLayout PTR
	get_tableLayout PTR
	put_borderCollapse PTR
	get_borderCollapse PTR
	put_direction PTR
	get_direction PTR
	put_behavior PTR
	get_behavior PTR
	put_position PTR
	get_position PTR
	put_unicodeBidi PTR
	get_unicodeBidi PTR
	put_bottom PTR
	get_bottom PTR
	put_right PTR
	get_right PTR
	put_pixelBottom PTR
	get_pixelBottom PTR
	put_pixelRight PTR
	get_pixelRight PTR
	put_posBottom PTR
	get_posBottom PTR
	put_posRight PTR
	get_posRight PTR
	put_imeMode PTR
	get_imeMode PTR
	put_rubyAlign PTR
	get_rubyAlign PTR
	put_rubyPosition PTR
	get_rubyPosition PTR
	put_rubyOverhang PTR
	get_rubyOverhang PTR
	put_layoutGridChar PTR
	get_layoutGridChar PTR
	put_layoutGridLine PTR
	get_layoutGridLine PTR
	put_layoutGridMode PTR
	get_layoutGridMode PTR
	put_layoutGridType PTR
	get_layoutGridType PTR
	put_layoutGrid PTR
	get_layoutGrid PTR
	put_textAutospace PTR
	get_textAutospace PTR
	put_wordBreak PTR
	get_wordBreak PTR
	put_lineBreak PTR
	get_lineBreak PTR
	put_textJustify PTR
	get_textJustify PTR
	put_textJustifyTrim PTR
	get_textJustifyTrim PTR
	put_textKashida PTR
	get_textKashida PTR
	put_overflowX PTR
	get_overflowX PTR
	put_overflowY PTR
	get_overflowY PTR
	put_accelerator PTR
	get_accelerator PTR
ENDS

#DEFINE GUID_IID_IHTMLRuleStyle3 <0x3050f657,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLRuleStyle3 STRUCT
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
	put_layoutFlow PTR
	get_layoutFlow PTR
	put_zoom PTR
	get_zoom PTR
	put_wordWrap PTR
	get_wordWrap PTR
	put_textUnderlinePosition PTR
	get_textUnderlinePosition PTR
	put_scrollbarBaseColor PTR
	get_scrollbarBaseColor PTR
	put_scrollbarFaceColor PTR
	get_scrollbarFaceColor PTR
	put_scrollbar3dLightColor PTR
	get_scrollbar3dLightColor PTR
	put_scrollbarShadowColor PTR
	get_scrollbarShadowColor PTR
	put_scrollbarHighlightColor PTR
	get_scrollbarHighlightColor PTR
	put_scrollbarDarkShadowColor PTR
	get_scrollbarDarkShadowColor PTR
	put_scrollbarArrowColor PTR
	get_scrollbarArrowColor PTR
	put_scrollbarTrackColor PTR
	get_scrollbarTrackColor PTR
	put_writingMode PTR
	get_writingMode PTR
	put_textAlignLast PTR
	get_textAlignLast PTR
	put_textKashidaSpace PTR
	get_textKashidaSpace PTR
ENDS

#DEFINE GUID_IID_IHTMLRuleStyle4 <0x3050f817,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLRuleStyle4 STRUCT
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
	put_textOverflow PTR
	get_textOverflow PTR
	put_minHeight PTR
	get_minHeight PTR
ENDS

#DEFINE GUID_IID_IHTMLRuleStyle5 <0x3050f335,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLRuleStyle5 STRUCT
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
	put_msInterpolationMode PTR
	get_msInterpolationMode PTR
	put_maxHeight PTR
	get_maxHeight PTR
	put_minWidth PTR
	get_minWidth PTR
	put_maxWidth PTR
	get_maxWidth PTR
ENDS

#DEFINE GUID_DIID_DispHTMLStyle <0x3050f55a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLStyle STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLStyle <0x3050f285,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLRuleStyle <0x3050f55c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLRuleStyle STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLRuleStyle <0x3050f3d0,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLRenderStyle <0x3050f6ae,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLRenderStyle STRUCT
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
	put_textLineThroughStyle PTR
	get_textLineThroughStyle PTR
	put_textUnderlineStyle PTR
	get_textUnderlineStyle PTR
	put_textEffect PTR
	get_textEffect PTR
	put_textColor PTR
	get_textColor PTR
	put_textBackgroundColor PTR
	get_textBackgroundColor PTR
	put_textDecorationColor PTR
	get_textDecorationColor PTR
	put_renderingPriority PTR
	get_renderingPriority PTR
	put_defaultTextSelection PTR
	get_defaultTextSelection PTR
	put_textDecoration PTR
	get_textDecoration PTR
ENDS

#DEFINE GUID_DIID_DispHTMLRenderStyle <0x3050f58b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLRenderStyle STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLRenderStyle <0x3050f6aa,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLCurrentStyle <0x3050f3db,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLCurrentStyle STRUCT
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
	get_position PTR
	get_styleFloat PTR
	get_color PTR
	get_backgroundColor PTR
	get_fontFamily PTR
	get_fontStyle PTR
	get_fontVariant PTR
	get_fontWeight PTR
	get_fontSize PTR
	get_backgroundImage PTR
	get_backgroundPositionX PTR
	get_backgroundPositionY PTR
	get_backgroundRepeat PTR
	get_borderLeftColor PTR
	get_borderTopColor PTR
	get_borderRightColor PTR
	get_borderBottomColor PTR
	get_borderTopStyle PTR
	get_borderRightStyle PTR
	get_borderBottomStyle PTR
	get_borderLeftStyle PTR
	get_borderTopWidth PTR
	get_borderRightWidth PTR
	get_borderBottomWidth PTR
	get_borderLeftWidth PTR
	get_left PTR
	get_top PTR
	get_width PTR
	get_height PTR
	get_paddingLeft PTR
	get_paddingTop PTR
	get_paddingRight PTR
	get_paddingBottom PTR
	get_textAlign PTR
	get_textDecoration PTR
	get_display PTR
	get_visibility PTR
	get_zIndex PTR
	get_letterSpacing PTR
	get_lineHeight PTR
	get_textIndent PTR
	get_verticalAlign PTR
	get_backgroundAttachment PTR
	get_marginTop PTR
	get_marginRight PTR
	get_marginBottom PTR
	get_marginLeft PTR
	get_clear PTR
	get_listStyleType PTR
	get_listStylePosition PTR
	get_listStyleImage PTR
	get_clipTop PTR
	get_clipRight PTR
	get_clipBottom PTR
	get_clipLeft PTR
	get_overflow PTR
	get_pageBreakBefore PTR
	get_pageBreakAfter PTR
	get_cursor PTR
	get_tableLayout PTR
	get_borderCollapse PTR
	get_direction PTR
	get_behavior PTR
	getAttribute PTR
	get_unicodeBidi PTR
	get_right PTR
	get_bottom PTR
	get_imeMode PTR
	get_rubyAlign PTR
	get_rubyPosition PTR
	get_rubyOverhang PTR
	get_textAutospace PTR
	get_lineBreak PTR
	get_wordBreak PTR
	get_textJustify PTR
	get_textJustifyTrim PTR
	get_textKashida PTR
	get_blockDirection PTR
	get_layoutGridChar PTR
	get_layoutGridLine PTR
	get_layoutGridMode PTR
	get_layoutGridType PTR
	get_borderStyle PTR
	get_borderColor PTR
	get_borderWidth PTR
	get_padding PTR
	get_margin PTR
	get_accelerator PTR
	get_overflowX PTR
	get_overflowY PTR
	get_textTransform PTR
ENDS

#DEFINE GUID_IID_IHTMLCurrentStyle2 <0x3050f658,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLCurrentStyle2 STRUCT
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
	get_layoutFlow PTR
	get_wordWrap PTR
	get_textUnderlinePosition PTR
	get_hasLayout PTR
	get_scrollbarBaseColor PTR
	get_scrollbarFaceColor PTR
	get_scrollbar3dLightColor PTR
	get_scrollbarShadowColor PTR
	get_scrollbarHighlightColor PTR
	get_scrollbarDarkShadowColor PTR
	get_scrollbarArrowColor PTR
	get_scrollbarTrackColor PTR
	get_writingMode PTR
	get_zoom PTR
	get_filter PTR
	get_textAlignLast PTR
	get_textKashidaSpace PTR
	get_isBlock PTR
ENDS

#DEFINE GUID_IID_IHTMLCurrentStyle3 <0x3050f818,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLCurrentStyle3 STRUCT
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
	get_textOverflow PTR
	get_minHeight PTR
	get_wordSpacing PTR
	get_whiteSpace PTR
ENDS

#DEFINE GUID_IID_IHTMLCurrentStyle4 <0x3050f33b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLCurrentStyle4 STRUCT
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
	get_msInterpolationMode PTR
	get_maxHeight PTR
	get_minWidth PTR
	get_maxWidth PTR
ENDS

#DEFINE GUID_DIID_DispHTMLCurrentStyle <0x3050f557,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLCurrentStyle STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLCurrentStyle <0x3050f3dc,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLElement <0x3050f1ff,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLElement STRUCT
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
	setAttribute PTR
	getAttribute PTR
	removeAttribute PTR
	put_className PTR
	get_className PTR
	put_id PTR
	get_id PTR
	get_tagName PTR
	get_parentElement PTR
	get_style PTR
	put_onhelp PTR
	get_onhelp PTR
	put_onclick PTR
	get_onclick PTR
	put_ondblclick PTR
	get_ondblclick PTR
	put_onkeydown PTR
	get_onkeydown PTR
	put_onkeyup PTR
	get_onkeyup PTR
	put_onkeypress PTR
	get_onkeypress PTR
	put_onmouseout PTR
	get_onmouseout PTR
	put_onmouseover PTR
	get_onmouseover PTR
	put_onmousemove PTR
	get_onmousemove PTR
	put_onmousedown PTR
	get_onmousedown PTR
	put_onmouseup PTR
	get_onmouseup PTR
	get_document PTR
	put_title PTR
	get_title PTR
	put_language PTR
	get_language PTR
	put_onselectstart PTR
	get_onselectstart PTR
	scrollIntoView PTR
	contains PTR
	get_sourceIndex PTR
	get_recordNumber PTR
	put_lang PTR
	get_lang PTR
	get_offsetLeft PTR
	get_offsetTop PTR
	get_offsetWidth PTR
	get_offsetHeight PTR
	get_offsetParent PTR
	put_innerHTML PTR
	get_innerHTML PTR
	put_innerText PTR
	get_innerText PTR
	put_outerHTML PTR
	get_outerHTML PTR
	put_outerText PTR
	get_outerText PTR
	insertAdjacentHTML PTR
	insertAdjacentText PTR
	get_parentTextEdit PTR
	get_isTextEdit PTR
	click PTR
	get_filters PTR
	put_ondragstart PTR
	get_ondragstart PTR
	toString PTR
	put_onbeforeupdate PTR
	get_onbeforeupdate PTR
	put_onafterupdate PTR
	get_onafterupdate PTR
	put_onerrorupdate PTR
	get_onerrorupdate PTR
	put_onrowexit PTR
	get_onrowexit PTR
	put_onrowenter PTR
	get_onrowenter PTR
	put_ondatasetchanged PTR
	get_ondatasetchanged PTR
	put_ondataavailable PTR
	get_ondataavailable PTR
	put_ondatasetcomplete PTR
	get_ondatasetcomplete PTR
	put_onfilterchange PTR
	get_onfilterchange PTR
	get_children PTR
	get_all PTR
ENDS

#DEFINE GUID_IID_IHTMLRect <0x3050f4a3,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLRect STRUCT
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
	put_left PTR
	get_left PTR
	put_top PTR
	get_top PTR
	put_right PTR
	get_right PTR
	put_bottom PTR
	get_bottom PTR
ENDS

#DEFINE GUID_IID_IHTMLRectCollection <0x3050f4a4,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLRectCollection STRUCT
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
	get_length PTR
	get__newEnum PTR
	item PTR
ENDS

#DEFINE GUID_IID_IHTMLDOMNode <0x3050f5da,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDOMNode STRUCT
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
	get_nodeType PTR
	get_parentNode PTR
	hasChildNodes PTR
	get_childNodes PTR
	get_attributes PTR
	insertBefore PTR
	removeChild PTR
	replaceChild PTR
	cloneNode PTR
	removeNode PTR
	swapNode PTR
	replaceNode PTR
	appendChild PTR
	get_nodeName PTR
	put_nodeValue PTR
	get_nodeValue PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
ENDS

#DEFINE GUID_IID_IHTMLDOMNode2 <0x3050f80b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDOMNode2 STRUCT
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
	get_ownerDocument PTR
ENDS

#DEFINE GUID_IID_IHTMLDOMAttribute <0x3050f4b0,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDOMAttribute STRUCT
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
	get_nodeName PTR
	put_nodeValue PTR
	get_nodeValue PTR
	get_specified PTR
ENDS

#DEFINE GUID_IID_IHTMLDOMAttribute2 <0x3050f810,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDOMAttribute2 STRUCT
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
	get_name PTR
	put_value PTR
	get_value PTR
	get_expando PTR
	get_nodeType PTR
	get_parentNode PTR
	get_childNodes PTR
	get_firstChild PTR
	get_lastChild PTR
	get_previousSibling PTR
	get_nextSibling PTR
	get_attributes PTR
	get_ownerDocument PTR
	insertBefore PTR
	replaceChild PTR
	removeChild PTR
	appendChild PTR
	hasChildNodes PTR
	cloneNode PTR
ENDS

#DEFINE GUID_IID_IHTMLDOMTextNode <0x3050f4b1,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDOMTextNode STRUCT
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
	put_data PTR
	get_data PTR
	toString PTR
	get_length PTR
	splitText PTR
ENDS

#DEFINE GUID_IID_IHTMLDOMTextNode2 <0x3050f809,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDOMTextNode2 STRUCT
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
	substringData PTR
	appendData PTR
	insertData PTR
	deleteData PTR
	replaceData PTR
ENDS

#DEFINE GUID_IID_IHTMLDOMImplementation <0x3050f80d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDOMImplementation STRUCT
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
	hasFeature PTR
ENDS

#DEFINE GUID_DIID_DispHTMLDOMAttribute <0x3050f564,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLDOMAttribute STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLDOMAttribute <0x3050f4b2,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_DIID_DispHTMLDOMTextNode <0x3050f565,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLDOMTextNode STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLDOMTextNode <0x3050f4ba,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_DIID_DispHTMLDOMImplementation <0x3050f58f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLDOMImplementation STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLDOMImplementation <0x3050f80e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLAttributeCollection <0x3050f4c3,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLAttributeCollection STRUCT
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
	get_length PTR
	get__newEnum PTR
	item PTR
ENDS

#DEFINE GUID_IID_IHTMLAttributeCollection2 <0x3050f80a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLAttributeCollection2 STRUCT
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
	getNamedItem PTR
	setNamedItem PTR
	removeNamedItem PTR
ENDS

#DEFINE GUID_IID_IHTMLDOMChildrenCollection <0x3050f5ab,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDOMChildrenCollection STRUCT
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
	get_length PTR
	get__newEnum PTR
	item PTR
ENDS

#DEFINE GUID_DIID_DispHTMLAttributeCollection <0x3050f56c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLAttributeCollection STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLAttributeCollection <0x3050f4cc,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispDOMChildrenCollection <0x3050f577,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispDOMChildrenCollection STANDARD_DISPATCH

#DEFINE GUID_CLSID_DOMChildrenCollection <0x3050f5aa,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLElementEvents2 <0x3050f60f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLElementEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLElementEvents <0x3050f33c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLElementEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLElementCollection <0x3050f21f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLElementCollection STRUCT
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
	toString PTR
	put_length PTR
	get_length PTR
	get__newEnum PTR
	item PTR
	tags PTR
ENDS

#DEFINE GUID_IID_IHTMLElement2 <0x3050f434,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLElement2 STRUCT
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
	get_scopeName PTR
	setCapture PTR
	releaseCapture PTR
	put_onlosecapture PTR
	get_onlosecapture PTR
	componentFromPoint PTR
	doScroll PTR
	put_onscroll PTR
	get_onscroll PTR
	put_ondrag PTR
	get_ondrag PTR
	put_ondragend PTR
	get_ondragend PTR
	put_ondragenter PTR
	get_ondragenter PTR
	put_ondragover PTR
	get_ondragover PTR
	put_ondragleave PTR
	get_ondragleave PTR
	put_ondrop PTR
	get_ondrop PTR
	put_onbeforecut PTR
	get_onbeforecut PTR
	put_oncut PTR
	get_oncut PTR
	put_onbeforecopy PTR
	get_onbeforecopy PTR
	put_oncopy PTR
	get_oncopy PTR
	put_onbeforepaste PTR
	get_onbeforepaste PTR
	put_onpaste PTR
	get_onpaste PTR
	get_currentStyle PTR
	put_onpropertychange PTR
	get_onpropertychange PTR
	getClientRects PTR
	getBoundingClientRect PTR
	setExpression PTR
	getExpression PTR
	removeExpression PTR
	put_tabIndex PTR
	get_tabIndex PTR
	focus PTR
	put_accessKey PTR
	get_accessKey PTR
	put_onblur PTR
	get_onblur PTR
	put_onfocus PTR
	get_onfocus PTR
	put_onresize PTR
	get_onresize PTR
	blur PTR
	addFilter PTR
	removeFilter PTR
	get_clientHeight PTR
	get_clientWidth PTR
	get_clientTop PTR
	get_clientLeft PTR
	attachEvent PTR
	detachEvent PTR
	get_readyState PTR
	put_onreadystatechange PTR
	get_onreadystatechange PTR
	put_onrowsdelete PTR
	get_onrowsdelete PTR
	put_onrowsinserted PTR
	get_onrowsinserted PTR
	put_oncellchange PTR
	get_oncellchange PTR
	put_dir PTR
	get_dir PTR
	createControlRange PTR
	get_scrollHeight PTR
	get_scrollWidth PTR
	put_scrollTop PTR
	get_scrollTop PTR
	put_scrollLeft PTR
	get_scrollLeft PTR
	clearAttributes PTR
	mergeAttributes PTR
	put_oncontextmenu PTR
	get_oncontextmenu PTR
	insertAdjacentElement PTR
	applyElement PTR
	getAdjacentText PTR
	replaceAdjacentText PTR
	get_canHaveChildren PTR
	addBehavior PTR
	removeBehavior PTR
	get_runtimeStyle PTR
	get_behaviorUrns PTR
	put_tagUrn PTR
	get_tagUrn PTR
	put_onbeforeeditfocus PTR
	get_onbeforeeditfocus PTR
	get_readyStateValue PTR
	getElementsByTagName PTR
ENDS

#DEFINE GUID_IID_IHTMLElement3 <0x3050f673,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLElement3 STRUCT
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
	mergeAttributes PTR
	get_isMultiLine PTR
	get_canHaveHTML PTR
	put_onlayoutcomplete PTR
	get_onlayoutcomplete PTR
	put_onpage PTR
	get_onpage PTR
	put_inflateBlock PTR
	get_inflateBlock PTR
	put_onbeforedeactivate PTR
	get_onbeforedeactivate PTR
	setActive PTR
	put_contentEditable PTR
	get_contentEditable PTR
	get_isContentEditable PTR
	put_hideFocus PTR
	get_hideFocus PTR
	put_disabled PTR
	get_disabled PTR
	get_isDisabled PTR
	put_onmove PTR
	get_onmove PTR
	put_oncontrolselect PTR
	get_oncontrolselect PTR
	fireEvent PTR
	put_onresizestart PTR
	get_onresizestart PTR
	put_onresizeend PTR
	get_onresizeend PTR
	put_onmovestart PTR
	get_onmovestart PTR
	put_onmoveend PTR
	get_onmoveend PTR
	put_onmouseenter PTR
	get_onmouseenter PTR
	put_onmouseleave PTR
	get_onmouseleave PTR
	put_onactivate PTR
	get_onactivate PTR
	put_ondeactivate PTR
	get_ondeactivate PTR
	dragDrop PTR
	get_glyphMode PTR
ENDS

#DEFINE GUID_IID_IHTMLElement4 <0x3050f80f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLElement4 STRUCT
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
	put_onmousewheel PTR
	get_onmousewheel PTR
	normalize PTR
	getAttributeNode PTR
	setAttributeNode PTR
	removeAttributeNode PTR
	put_onbeforeactivate PTR
	get_onbeforeactivate PTR
	put_onfocusin PTR
	get_onfocusin PTR
	put_onfocusout PTR
	get_onfocusout PTR
ENDS

#DEFINE GUID_IID_IHTMLElementRender <0x3050f669,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLElementRender STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	DrawToDC PTR
	SetDocumentPrinter PTR
ENDS

#DEFINE GUID_IID_IHTMLUniqueName <0x3050f4d0,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLUniqueName STRUCT
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
	get_uniqueNumber PTR
	get_uniqueID PTR
ENDS

#DEFINE GUID_IID_IHTMLDatabinding <0x3050f3f2,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDatabinding STRUCT
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
	put_dataFld PTR
	get_dataFld PTR
	put_dataSrc PTR
	get_dataSrc PTR
	put_dataFormatAs PTR
	get_dataFormatAs PTR
ENDS

#DEFINE GUID_IID_IHTMLDocument <0x626FC520,0xA41E,0x11cf,<0xA7,0x31,0x00,0xA0,0xC9,0x08,0x26,0x37>>

IHTMLDocument STRUCT
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
	get_Script PTR
ENDS

#DEFINE GUID_IID_IHTMLElementDefaults <0x3050f6c9,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLElementDefaults STRUCT
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
	get_style PTR
	put_tabStop PTR
	get_tabStop PTR
	put_viewInheritStyle PTR
	get_viewInheritStyle PTR
	put_viewMasterTab PTR
	get_viewMasterTab PTR
	put_scrollSegmentX PTR
	get_scrollSegmentX PTR
	put_scrollSegmentY PTR
	get_scrollSegmentY PTR
	put_isMultiLine PTR
	get_isMultiLine PTR
	put_contentEditable PTR
	get_contentEditable PTR
	put_canHaveHTML PTR
	get_canHaveHTML PTR
	putref_viewLink PTR
	get_viewLink PTR
	put_frozen PTR
	get_frozen PTR
ENDS

#DEFINE GUID_DIID_DispHTMLDefaults <0x3050f58c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLDefaults STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLDefaults <0x3050f6c8,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTCDefaultDispatch <0x3050f4fd,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTCDefaultDispatch STRUCT
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
	get_element PTR
	createEventObject PTR
	get_defaults PTR
	get_document PTR
ENDS

#DEFINE GUID_IID_IHTCPropertyBehavior <0x3050f5df,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTCPropertyBehavior STRUCT
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
	fireChange PTR
	put_value PTR
	get_value PTR
ENDS

#DEFINE GUID_IID_IHTCMethodBehavior <0x3050f631,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTCMethodBehavior STRUCT
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
ENDS

#DEFINE GUID_IID_IHTCEventBehavior <0x3050f4ff,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTCEventBehavior STRUCT
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
	fire PTR
ENDS

#DEFINE GUID_IID_IHTCAttachBehavior <0x3050f5f4,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTCAttachBehavior STRUCT
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
	fireEvent PTR
	detachEvent PTR
ENDS

#DEFINE GUID_IID_IHTCAttachBehavior2 <0x3050f7eb,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTCAttachBehavior2 STRUCT
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
	fireEvent PTR
ENDS

#DEFINE GUID_IID_IHTCDescBehavior <0x3050f5dc,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTCDescBehavior STRUCT
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
	get_urn PTR
	get_name PTR
ENDS

#DEFINE GUID_DIID_DispHTCDefaultDispatch <0x3050f573,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTCDefaultDispatch STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTCDefaultDispatch <0x3050f4fc,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTCPropertyBehavior <0x3050f57f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTCPropertyBehavior STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTCPropertyBehavior <0x3050f5de,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTCMethodBehavior <0x3050f587,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTCMethodBehavior STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTCMethodBehavior <0x3050f630,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTCEventBehavior <0x3050f574,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTCEventBehavior STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTCEventBehavior <0x3050f4fe,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTCAttachBehavior <0x3050f583,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTCAttachBehavior STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTCAttachBehavior <0x3050f5f5,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTCDescBehavior <0x3050f57e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTCDescBehavior STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTCDescBehavior <0x3050f5dd,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLUrnCollection <0x3050f5e2,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLUrnCollection STRUCT
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
	get_length PTR
	item PTR
ENDS

#DEFINE GUID_CLSID_HTMLUrnCollection <0x3050f580,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLGenericElement <0x3050f4b7,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLGenericElement STRUCT
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
	get_recordset PTR
	namedRecordset PTR
ENDS

#DEFINE GUID_DIID_DispHTMLGenericElement <0x3050f563,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLGenericElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLGenericElement <0x3050f4b8,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLStyleSheetRule <0x3050f357,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLStyleSheetRule STRUCT
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
	put_selectorText PTR
	get_selectorText PTR
	get_style PTR
	get_readOnly PTR
ENDS

#DEFINE GUID_IID_IHTMLStyleSheetRulesCollection <0x3050f2e5,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLStyleSheetRulesCollection STRUCT
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
	get_length PTR
	item PTR
ENDS

#DEFINE GUID_CLSID_HTMLStyleSheetRule <0x3050f3ce,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_CLSID_HTMLStyleSheetRulesCollection <0x3050f3cd,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLStyleSheetPage <0x3050f7ee,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLStyleSheetPage STRUCT
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
	get_selector PTR
	get_pseudoClass PTR
ENDS

#DEFINE GUID_IID_IHTMLStyleSheetPagesCollection <0x3050f7f0,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLStyleSheetPagesCollection STRUCT
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
	get_length PTR
	item PTR
ENDS

#DEFINE GUID_CLSID_HTMLStyleSheetPage <0x3050f7ef,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_CLSID_HTMLStyleSheetPagesCollection <0x3050f7f1,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLStyleSheetsCollection <0x3050f37e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLStyleSheetsCollection STRUCT
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
	get_length PTR
	get__newEnum PTR
	item PTR
ENDS

#DEFINE GUID_IID_IHTMLStyleSheet <0x3050f2e3,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLStyleSheet STRUCT
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
	put_title PTR
	get_title PTR
	get_parentStyleSheet PTR
	get_owningElement PTR
	put_disabled PTR
	get_disabled PTR
	get_readOnly PTR
	get_imports PTR
	put_href PTR
	get_href PTR
	get_type PTR
	get_id PTR
	addImport PTR
	addRule PTR
	removeImport PTR
	removeRule PTR
	put_media PTR
	get_media PTR
	put_cssText PTR
	get_cssText PTR
	get_rules PTR
ENDS

#DEFINE GUID_IID_IHTMLStyleSheet2 <0x3050f3d1,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLStyleSheet2 STRUCT
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
	get_pages PTR
	addPageRule PTR
ENDS

#DEFINE GUID_DIID_DispHTMLStyleSheet <0x3050f58d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#define DispHTMLStyleSheet STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLStyleSheet <0x3050f2e4,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_CLSID_HTMLStyleSheetsCollection <0x3050f37f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLLinkElementEvents2 <0x3050f61d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#define HTMLLinkElementEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLLinkElementEvents <0x3050f3cc,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#define HTMLLinkElementEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLLinkElement <0x3050f205,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLLinkElement STRUCT
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
	put_href PTR
	get_href PTR
	put_rel PTR
	get_rel PTR
	put_rev PTR
	get_rev PTR
	put_type PTR
	get_type PTR
	get_readyState PTR
	put_onreadystatechange PTR
	get_onreadystatechange PTR
	put_onload PTR
	get_onload PTR
	put_onerror PTR
	get_onerror PTR
	get_styleSheet PTR
	put_disabled PTR
	get_disabled PTR
	put_media PTR
	get_media PTR
ENDS

#DEFINE GUID_IID_IHTMLLinkElement2 <0X3050f4e5,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLLinkElement2 STRUCT
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
	put_target PTR
	get_target PTR
ENDS

#DEFINE GUID_IID_IHTMLLinkElement3 <0x3050f81e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLLinkElement3 STRUCT
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
	put_charset PTR
	get_charset PTR
	put_hreflang PTR
	get_hreflang PTR
ENDS

#DEFINE GUID_DIID_DispHTMLLinkElement <0x3050f524,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLLinkElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLLinkElement <0x3050f277,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLTxtRange <0x3050f220,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTxtRange STRUCT
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
	get_htmlText PTR
	put_text PTR
	get_text PTR
	parentElement PTR
	duplicate PTR
	inRange PTR
	isEqual PTR
	scrollIntoView PTR
	collapse PTR
	expand PTR
	move PTR
	moveStart PTR
	ActualCount);
	select PTR
	pasteHTML PTR
	moveToElementText PTR
	setEndPoint PTR
	compareEndPoints PTR
	findText PTR
	moveToPoint PTR
	getBookmark PTR
	moveToBookmark PTR
	queryCommandSupported PTR
	queryCommandEnabled PTR
	queryCommandState PTR
	queryCommandIndeterm PTR
	queryCommandText PTR
	queryCommandValue PTR
	execCommand PTR
	execCommandShowHelp PTR
ENDS

#DEFINE GUID_IID_IHTMLTextRangeMetrics <0x3050f40b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTextRangeMetrics STRUCT
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
	get_offsetTop PTR
	get_offsetLeft PTR
	get_boundingTop PTR
	get_boundingLeft PTR
	get_boundingWidth PTR
	get_boundingHeight PTR
ENDS

#DEFINE GUID_IID_IHTMLTextRangeMetrics2 <0x3050f4a6,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTextRangeMetrics2 STRUCT
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
	getClientRects PTR
	getBoundingClientRect PTR
ENDS

#DEFINE GUID_IID_IHTMLTxtRangeCollection <0x3050f7ed,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTxtRangeCollection STRUCT
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
	get_length PTR
	get__newEnum PTR
	item PTR
ENDS

#DEFINE GUID_DIID_HTMLFormElementEvents2 <0x3050f614,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE HTMLFormElementEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLFormElementEvents <0x3050f364,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLFormElementEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLFormElement <0x3050f1f7,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFormElement STRUCT
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
	put_action PTR
	get_action PTR
	put_dir PTR
	get_dir PTR
	put_encoding PTR
	get_encoding PTR
	put_method PTR
	get_method PTR
	get_elements PTR
	put_target PTR
	get_target PTR
	put_name PTR
	get_name PTR
	put_onsubmit PTR
	get_onsubmit PTR
	put_onreset PTR
	get_onreset PTR
	submit PTR
	reset PTR
	put_length PTR
	get_length PTR
	get__newEnum PTR
	item PTR
	tags PTR
ENDS

#DEFINE GUID_IID_IHTMLFormElement2 <0x3050f4f6,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFormElement2 STRUCT
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
	put_acceptCharset PTR
	get_acceptCharset PTR
	urns PTR
ENDS

#DEFINE GUID_IID_IHTMLFormElement3 <0x3050f836,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFormElement3 STRUCT
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
	namedItem PTR 
ENDS

#DEFINE GUID_IID_IHTMLSubmitData <0x3050f645,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLSubmitData STRUCT
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
	appendNameValuePair PTR
	appendNameFilePair PTR
	appendItemSeparator PTR
ENDS

#DEFINE GUID_DIID_DispHTMLFormElement <0x3050f510,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLFormElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLFormElement <0x3050f251,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLControlElementEvents2 <0x3050f612,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLControlElementEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLControlElementEvents <0x3050f4ea,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLControlElementEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLControlElement <0x3050f4e9,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLControlElement STRUCT
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
	put_tabIndex PTR
	get_tabIndex PTR
	focus PTR
	put_accessKey PTR
	get_accessKey PTR
	put_onblur PTR
	get_onblur PTR
	put_onfocus PTR
	get_onfocus PTR
	put_onresize PTR
	get_onresize PTR
	blur PTR
	addFilter PTR
	removeFilter PTR
	get_clientHeight PTR
	get_clientWidth PTR
	get_clientTop PTR
	get_clientLeft PTR
ENDS

#DEFINE GUID_IID_IHTMLTextElement <0x3050f218,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define IHTMLTextElement STANDARD_DISPATCH

#DEFINE GUID_DIID_DispHTMLTextElement <0x3050f537,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLTextElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLTextElement <0x3050f26a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLTextContainerEvents2 <0x3050f624,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLTextContainerEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLTextContainerEvents <0x1FF6AA72,0x5842,0x11cf,<0xA7,0x07,0x00,0xAA,0x00,0xC0,0x09,0x8D>>

#define HTMLTextContainerEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLTextContainer <0x3050f230,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTextContainer STRUCT
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
	createControlRange PTR
	get_scrollHeight PTR
	get_scrollWidth PTR
	put_scrollTop PTR
	get_scrollTop PTR
	put_scrollLeft PTR
	get_scrollLeft PTR
	put_onscroll PTR
	get_onscroll PTR
ENDS

#DEFINE GUID_IID_IHTMLControlRange <0x3050f29c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLControlRange STRUCT
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
	select PTR
	add PTR
	remove PTR
	item PTR
	scrollIntoView PTR
	queryCommandSupported PTR
	queryCommandEnabled PTR
	queryCommandState PTR
	queryCommandIndeterm PTR
	queryCommandText PTR
	queryCommandValue PTR
	execCommand PTR
	execCommandShowHelp PTR
	commonParentElement PTR
	get_length PTR
ENDS

#DEFINE GUID_IID_IHTMLControlRange2 <0x3050f65e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLControlRange2 STRUCT
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
	addElement PTR
ENDS

#DEFINE GUID_DIID_HTMLImgEvents2 <0x3050f616,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLImgEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLImgEvents <0x3050f25b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLImgEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLImgElement <0x050f240,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLImgElement STRUCT
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
	put_isMap PTR
	get_isMap PTR
	put_useMap PTR
	get_useMap PTR
	get_mimeType PTR
	get_fileSize PTR
	get_fileCreatedDate PTR
	get_fileModifiedDate PTR
	get_fileUpdatedDate PTR
	get_protocol PTR
	get_href PTR
	get_nameProp PTR
	put_border PTR
	get_border PTR
	put_vspace PTR
	get_vspace PTR
	put_hspace PTR
	get_hspace PTR
	put_alt PTR
	get_alt PTR
	put_src PTR
	get_src PTR
	put_lowsrc PTR
	get_lowsrc PTR
	put_vrml PTR
	get_vrml PTR
	put_dynsrc PTR
	get_dynsrc PTR
	get_readyState PTR
	get_complete PTR
	put_loop PTR
	get_loop PTR
	put_align PTR
	get_align PTR
	put_onload PTR
	get_onload PTR
	put_onerror PTR
	get_onerror PTR
	put_onabort PTR
	get_onabort PTR
	put_name PTR
	get_name PTR
	put_width PTR
	get_width PTR
	put_height PTR
	get_height PTR
	put_start PTR
	get_start PTR
ENDS

#DEFINE GUID_IID_IHTMLImgElement2 <0x3050f826,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLImgElement2 STRUCT
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
	put_longDesc PTR
	get_longDesc PTR
ENDS

#DEFINE GUID_IID_IHTMLImageElementFactory <0x3050f38e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLImageElementFactory STRUCT
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
	create PTR
ENDS

#DEFINE GUID_DIID_DispHTMLImg <0x3050f51c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLImg STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLImg <0x3050f241,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_CLSID_HTMLImageElementFactory <0x3050f38f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLXMLHttpRequest <0x3051040a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLXMLHttpRequest STRUCT
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
	get_readyState PTR
	get_responseBody PTR
	get_responseText PTR
	get_responseXML PTR
	get_status PTR
	get_statusText PTR
	put_onreadystatechange PTR
	get_onreadystatechange PTR
	abort PTR
	open PTR
	send PTR
	getAllResponseHeaders PTR
	getResponseHeader PTR
	setRequestHeader PTR
ENDS

#DEFINE GUID_IID_IHTMLXMLHttpRequestFactory <0x3051040c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLXMLHttpRequestFactory  STRUCT
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
	create PTR
ENDS

#DEFINE GUID_DIID_DispHTMLXMLHttpRequest <0x3050f596,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLXMLHttpRequest STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLXMLHttpRequest <0x3051040b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_CLSID_HTMLXMLHttpRequestFactory <0x3051040d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLBodyElement <0x3050f1d8,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLBodyElement STRUCT
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
	put_background PTR
	get_background PTR
	put_bgProperties PTR
	get_bgProperties PTR
	put_leftMargin PTR
	get_leftMargin PTR
	put_topMargin PTR
	get_topMargin PTR
	put_rightMargin PTR
	get_rightMargin PTR
	put_bottomMargin PTR
	get_bottomMargin PTR
	put_noWrap PTR
	get_noWrap PTR
	put_bgColor PTR
	get_bgColor PTR
	put_text PTR
	get_text PTR
	put_link PTR
	get_link PTR
	put_vLink PTR
	get_vLink PTR
	put_aLink PTR
	get_aLink PTR
	put_onload PTR
	get_onload PTR
	put_onunload PTR
	get_onunload PTR
	put_scroll PTR
	get_scroll PTR
	put_onselect PTR
	get_onselect PTR
	put_onbeforeunload PTR
	get_onbeforeunload PTR
	createTextRange PTR
ENDS

#DEFINE GUID_IID_IHTMLBodyElement2 <0x3050f5c5,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLBodyElement2 STRUCT
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
	put_onbeforeprint PTR
	get_onbeforeprint PTR
	put_onafterprint PTR
	get_onafterprint PTR
ENDS

#DEFINE GUID_DIID_DispHTMLBody <0x3050f507,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLBody STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLBody <0x3050f24a,0x98b5,0x11cf,<0xb,0xb82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLFontElement <0x3050f1d9,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFontElement STRUCT
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
	put_color PTR
	get_color PTR
	put_face PTR
	get_face PTR
	put_size PTR
	get_size PTR
ENDS

#DEFINE GUID_DIID_DispHTMLFontElement <0x3050f512,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLFontElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLFontElement <0x3050f27b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLAnchorEvents2 <0x3050f610,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLAnchorEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLAnchorEvents <0x3050f29d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLAnchorEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLAnchorElement <0x3050f1da,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLAnchorElement STRUCT
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
	put_href PTR
	get_href PTR
	put_target PTR
	get_target PTR
	put_rel PTR
	get_rel PTR
	put_rev PTR
	get_rev PTR
	put_urn PTR
	get_urn PTR
	put_Methods PTR
	get_Methods PTR
	put_name PTR
	get_name PTR
	put_host PTR
	get_host PTR
	put_hostname PTR
	get_hostname PTR
	put_pathname PTR
	get_pathname PTR
	put_port PTR
	get_port PTR
	put_protocol PTR
	get_protocol PTR
	put_search PTR
	get_search PTR
	put_hash PTR
	get_hash PTR
	put_onblur PTR
	get_onblur PTR
	put_onfocus PTR
	get_onfocus PTR
	put_accessKey PTR
	get_accessKey PTR
	get_protocolLong PTR
	get_mimeType PTR
	get_nameProp PTR
	put_tabIndex PTR
	get_tabIndex PTR
	focus PTR
	blur PTR
ENDS

#DEFINE GUID_IID_IHTMLAnchorElement2 <0x3050f825,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLAnchorElement2 STRUCT
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
	put_charset PTR
	get_charset PTR
	put_coords PTR
	get_coords PTR
	put_hreflang PTR
	get_hreflang PTR
	put_shape PTR
	get_shape PTR
	put_type PTR
	get_type PTR
ENDS

#DEFINE GUID_DIID_DispHTMLAnchorElement <0x3050f502,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLAnchorElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLAnchorElement <0x3050f248,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLLabelEvents2 <0x3050f61c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLLabelEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLLabelEvents <0x3050f329,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLLabelEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLLabelElement <0x3050f32a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLLabelElement STRUCT
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
	put_htmlFor PTR
	get_htmlFor PTR
	put_accessKey PTR
	get_accessKey PTR
ENDS

#DEFINE GUID_IID_IHTMLLabelElement2 <0x3050f832,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLLabelElement2 STRUCT
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
	get_form PTR
ENDS

#DEFINE GUID_DIID_DispHTMLLabelElement <0x3050f522,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLLabelElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLLabelElement <0x3050f32b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLListElement <0x3050f20e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define IHTMLListElement STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLListElement2 <0x3050f822,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLListElement2 STRUCT
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
	put_compact PTR
	get_compact PTR
ENDS

#DEFINE GUID_DIID_DispHTMLListElement <0x3050f525,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLListElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLListElement <0x3050f272,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLUListElement <0x3050f1dd,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLUListElement STRUCT
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
	put_compact PTR
	get_compact PTR
	put_type PTR
	get_type PTR
ENDS

#DEFINE GUID_DIID_DispHTMLUListElement <0x3050f538,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLUListElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLUListElement <0x3050f269,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLOListElement <0x3050f1de,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLOListElement STRUCT
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
	put_compact PTR
	get_compact PTR
	put_start PTR
	get_start PTR
	put_type PTR
	get_type PTR
ENDS

#DEFINE GUID_DIID_DispHTMLOListElement <0x3050f52a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLOListElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLOListElement <0x3050f270,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLLIElement <0x3050f1e0,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLLIElement STRUCT
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
	put_type PTR
	get_type PTR
	put_value PTR
	get_value PTR
ENDS

#DEFINE GUID_DIID_DispHTMLLIElement <0x3050f523,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLLIElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLLIElement <0x3050f273,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLBlockElement <0x3050f208,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLBlockElement STRUCT
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
	put_clear PTR
	get_clear PTR
ENDS

#DEFINE GUID_IID_IHTMLBlockElement2 <0x3050f823,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLBlockElement2 STRUCT
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
	put_cite PTR
	get_cite PTR
	put_width PTR
	get_width PTR
ENDS

#DEFINE GUID_DIID_DispHTMLBlockElement <0x3050f506,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLBlockElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLBlockElement <0x3050f281,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLDivElement <0x3050f200,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDivElement STRUCT
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
	put_align PTR
	get_align PTR
	put_noWrap PTR
	get_noWrap PTR
ENDS

#DEFINE GUID_DIID_DispHTMLDivElement <0x3050f50c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLDivElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLDivElement <0x3050f27e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLDDElement <0x3050f1f2,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDDElement STRUCT
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
	put_noWrap PTR
	get_noWrap PTR
ENDS

#DEFINE GUID_DIID_DispHTMLDDElement <0x3050f50b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLDDElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLDDElement <0x3050f27f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLDTElement <0x3050f1f3,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDTElement STRUCT
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
	put_noWrap PTR
	get_noWrap PTR
ENDS

#DEFINE GUID_DIID_DispHTMLDTElement <0x3050f50d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLDTElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLDTElement <0x3050f27c,0x98b5,0x11cf,<0xb,0xb82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLBRElement <0x3050f1f0,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLBRElement STRUCT
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
	put_clear PTR
	get_clear PTR
ENDS

#DEFINE GUID_DIID_DispHTMLBRElement <0x3050f53a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLBRElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLBRElement <0x3050f280,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLDListElement <0x3050f1f1,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDListElement STRUCT
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
	put_compact PTR
	get_compact PTR
ENDS

#DEFINE GUID_DIID_DispHTMLDListElement <0x3050f53b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLDListElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLDListElement <0x3050f27d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLHRElement <0x3050f1f4,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLHRElement STRUCT
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
	put_align PTR
	get_align PTR
	put_color PTR
	get_color PTR
	put_noShade PTR
	get_noShade PTR
	put_width PTR
	get_width PTR
	put_size PTR
	get_size PTR
ENDS

#DEFINE GUID_DIID_DispHTMLHRElement <0x3050f53d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLHRElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLHRElement <0x3050f252,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLParaElement <0x3050f1f5,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLParaElement STRUCT
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
	put_align PTR
	get_align PTR
ENDS

#DEFINE GUID_DIID_DispHTMLParaElement <0x3050f52c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLParaElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLParaElement <0x3050f26f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLElementCollection2 <0x3050f5ee,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLElementCollection2 STRUCT
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
	urns PTR
ENDS

#DEFINE GUID_IID_IHTMLElementCollection3 <0x3050f835,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLElementCollection3 STRUCT
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
	namedItem PTR
ENDS

#DEFINE GUID_DIID_DispHTMLElementCollection <0x3050f56b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLElementCollection STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLElementCollection <0x3050f4cb,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLHeaderElement <0x3050f1f6,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLHeaderElement STRUCT
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
	put_align PTR
	get_align PTR
ENDS

#DEFINE GUID_DIID_DispHTMLHeaderElement <0x3050f515,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLHeaderElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLHeaderElement <0x3050f27a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLSelectElementEvents2 <0x3050f622,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLSelectElementEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLSelectElementEvents <0x3050f302,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLSelectElementEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLSelectElementEx <0x3050f2d1,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLSelectElementEx STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ShowDropdown PTR
	SetSelectExFlags PTR
	GetSelectExFlags PTR
	GetDropdownOpen PTR
ENDS

#DEFINE GUID_IID_IHTMLSelectElement <0x3050f244,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>  

IHTMLSelectElement STRUCT
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
	put_size PTR
	get_size PTR
	put_multiple PTR
	get_multiple PTR
	put_name PTR
	get_name PTR
	get_options PTR
	put_onchange PTR
	get_onchange PTR
	put_selectedIndex PTR
	get_selectedIndex PTR
	get_type PTR
	put_value PTR
	get_value PTR
	put_disabled PTR
	get_disabled PTR
	get_form PTR
	add PTR
	remove PTR
	put_length PTR
	get_length PTR
	get__newEnum PTR
	item PTR
	tags PTR
ENDS

#DEFINE GUID_IID_IHTMLSelectElement2 <0x3050f5ed,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLSelectElement2 STRUCT
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
	urns PTR
ENDS

#DEFINE GUID_IID_IHTMLSelectElement4 <0x3050f838,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLSelectElement4 STRUCT
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
	namedItem PTR
ENDS

#DEFINE GUID_DIID_DispHTMLSelectElement <0x3050f531,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLSelectElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLSelectElement <0x3050f245,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLWndSelectElement <0x3050f597,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLWndSelectElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLWndSelectElement <0x3050f2cf,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLSelectionObject <0x3050f25A,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLSelectionObject STRUCT
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
	createRange PTR
	empty PTR
	clear PTR
	get_type PTR
ENDS

#DEFINE GUID_IID_IHTMLSelectionObject2 <0x3050f7ec,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLSelectionObject2 STRUCT
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
	createRangeCollection PTR
	get_typeDetail PTR
ENDS

#DEFINE GUID_IID_IHTMLOptionElement <0x3050f211,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLOptionElement STRUCT
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
	put_selected PTR
	get_selected PTR
	put_value PTR
	get_value PTR
	put_defaultSelected PTR
	get_defaultSelected PTR
	put_index PTR
	get_index PTR
	put_text PTR
	get_text PTR
	get_form PTR
ENDS

#DEFINE GUID_IID_IHTMLOptionElement3 <0x3050f820,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLOptionElement3 STRUCT
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
	put_label PTR
	get_label PTR
ENDS

#DEFINE GUID_IID_IHTMLOptionElementFactory <0x3050f38c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLOptionElementFactory STRUCT
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
	create PTR
ENDS

#DEFINE GUID_DIID_DispHTMLOptionElement <0x3050f52b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLOptionElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLOptionElement <0x3050f24d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_CLSID_HTMLOptionElementFactory <0x3050f38d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLWndOptionElement <0x3050f598,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLWndOptionElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLWndOptionElement <0x3050f2d0,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLButtonElementEvents2 <0x3050f617,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLButtonElementEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLButtonElementEvents <0x3050f2b3,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLButtonElementEvents STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLInputTextElementEvents2 <0x3050f618,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLInputTextElementEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLOptionButtonElementEvents2 <0x3050f619,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLOptionButtonElementEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLInputFileElementEvents2 <0x3050f61a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLInputFileElementEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLInputImageEvents2 <0x3050f61b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLInputImageEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLInputTextElementEvents <0x3050f2a7,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLInputTextElementEvents STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLOptionButtonElementEvents <0x3050f2bd,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLOptionButtonElementEvents STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLInputFileElementEvents <0x3050f2af,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLInputFileElementEvents STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLInputImageEvents <0x3050f2c3,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLInputImageEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLInputElement <0x3050f5d2,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLInputElement STRUCT
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
	put_type PTR
	get_type PTR
	put_value PTR
	get_value PTR
	put_name PTR
	get_name PTR
	put_status PTR
	get_status PTR
	put_disabled PTR
	get_disabled PTR
	get_form PTR
	put_size PTR
	get_size PTR
	put_maxLength PTR
	get_maxLength PTR
	select PTR
	put_onchange PTR
	get_onchange PTR
	put_onselect PTR
	get_onselect PTR
	put_defaultValue PTR
	get_defaultValue PTR
	put_readOnly PTR
	get_readOnly PTR
	createTextRange PTR
	put_indeterminate PTR
	get_indeterminate PTR
	put_defaultChecked PTR
	get_defaultChecked PTR
	put_checked PTR
	get_checked PTR
	put_border PTR
	get_border PTR
	put_vspace PTR
	get_vspace PTR
	put_hspace PTR
	get_hspace PTR
	put_alt PTR
	get_alt PTR
	put_src PTR
	get_src PTR
	put_lowsrc PTR
	get_lowsrc PTR
	put_vrml PTR
	get_vrml PTR
	put_dynsrc PTR
	get_dynsrc PTR
	get_readyState PTR
	get_complete PTR
	put_loop PTR
	get_loop PTR
	put_align PTR
	get_align PTR
	put_onload PTR
	get_onload PTR
	put_onerror PTR
	get_onerror PTR
	put_onabort PTR
	get_onabort PTR
	put_width PTR
	get_width PTR
	put_height PTR
	get_height PTR
	put_start PTR
	get_start PTR
ENDS

#DEFINE GUID_IID_IHTMLInputElement2 <0x3050f821,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLInputElement2 STRUCT
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
	put_accept PTR
	get_accept PTR
	put_useMap PTR
	get_useMap PTR
ENDS

#DEFINE GUID_IID_IHTMLInputButtonElement <0x3050f2b2,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLInputButtonElement STRUCT
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
	get_type PTR
	put_value PTR
	get_value PTR
	put_name PTR
	get_name PTR
	put_status PTR
	get_status PTR
	put_disabled PTR
	get_disabled PTR
	get_form PTR
	createTextRange PTR
ENDS

#DEFINE GUID_IID_IHTMLInputHiddenElement <0x3050f2a4,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLInputHiddenElement STRUCT
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
	get_type PTR
	put_value PTR
	get_value PTR
	put_name PTR
	get_name PTR
	put_status PTR
	get_status PTR
	put_disabled PTR
	get_disabled PTR
	get_form PTR
	createTextRange PTR
ENDS

#DEFINE GUID_IID_IHTMLInputTextElement <0x3050f2a6,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLInputTextElement STRUCT
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
	get_type PTR
	put_value PTR
	get_value PTR
	put_name PTR
	get_name PTR
	put_status PTR
	get_status PTR
	put_disabled PTR
	get_disabled PTR
	get_form PTR
	put_defaultValue PTR
	get_defaultValue PTR
	put_size PTR
	get_size PTR
	put_maxLength PTR
	get_maxLength PTR
	select PTR
	put_onchange PTR
	get_onchange PTR
	put_onselect PTR
	get_onselect PTR
	put_readOnly PTR
	get_readOnly PTR
	createTextRange PTR
ENDS

#DEFINE GUID_IID_IHTMLInputFileElement <0x3050f2ad,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLInputFileElement STRUCT
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
	get_type PTR
	put_name PTR
	get_name PTR
	put_status PTR
	get_status PTR
	put_disabled PTR
	get_disabled PTR
	get_form PTR
	put_size PTR
	get_size PTR
	put_maxLength PTR
	get_maxLength PTR
	select PTR
	put_onchange PTR
	get_onchange PTR
	put_onselect PTR
	get_onselect PTR
	put_value PTR
	get_value PTR
ENDS

#DEFINE GUID_IID_IHTMLOptionButtonElement <0x3050f2bc,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLOptionButtonElement STRUCT
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
	put_value PTR
	get_value PTR
	get_type PTR
	put_name PTR
	get_name PTR
	put_checked PTR
	get_checked PTR
	put_defaultChecked PTR
	get_defaultChecked PTR
	put_onchange PTR
	get_onchange PTR
	put_disabled PTR
	get_disabled PTR
	put_status PTR
	get_status PTR
	put_indeterminate PTR
	get_indeterminate PTR
	get_form PTR
ENDS

#DEFINE GUID_IID_IHTMLInputImage <0x3050f2c2,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLInputImage STRUCT
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
	get_type PTR
	put_disabled PTR
	get_disabled PTR
	put_border PTR
	get_border PTR
	put_vspace PTR
	get_vspace PTR
	put_hspace PTR
	get_hspace PTR
	put_alt PTR
	get_alt PTR
	put_src PTR
	get_src PTR
	put_lowsrc PTR
	get_lowsrc PTR
	put_vrml PTR
	get_vrml PTR
	put_dynsrc PTR
	get_dynsrc PTR
	get_readyState PTR
	get_complete PTR
	put_loop PTR
	get_loop PTR
	put_align PTR
	get_align PTR
	put_onload PTR
	get_onload PTR
	put_onerror PTR
	get_onerror PTR
	put_onabort PTR
	get_onabort PTR
	put_name PTR
	get_name PTR
	put_width PTR
	get_width PTR
	put_height PTR
	get_height PTR
	put_start PTR
	get_start PTR
ENDS

#DEFINE GUID_DIID_DispHTMLInputElement <0x3050f57d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLInputElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLInputElement <0x3050f5d8,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLTextAreaElement <0x3050f2aa,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTextAreaElement STRUCT
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
	get_type PTR
	put_value PTR
	get_value PTR
	put_name PTR
	get_name PTR
	put_status PTR
	get_status PTR
	put_disabled PTR
	get_disabled PTR
	get_form PTR
	put_defaultValue PTR
	get_defaultValue PTR
	select PTR
	put_onchange PTR
	get_onchange PTR
	put_onselect PTR
	get_onselect PTR
	put_readOnly PTR
	get_readOnly PTR
	put_rows PTR
	get_rows PTR
	put_cols PTR
	get_cols PTR
	put_wrap PTR
	get_wrap PTR
	createTextRange PTR
ENDS

#DEFINE GUID_DIID_DispHTMLTextAreaElement <0x3050f521,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLTextAreaElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLTextAreaElement <0x3050f2ac,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLRichtextElement <0x3050f54d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLRichtextElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLRichtextElement <0x3050f2df,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLButtonElement <0x3050f2bb,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLButtonElement STRUCT
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
	get_type PTR
	put_value PTR
	get_value PTR
	put_name PTR
	get_name PTR
	put_status PTR
	get_status PTR
	put_disabled PTR
	get_disabled PTR
	get_form PTR
	createTextRange PTR
ENDS

#DEFINE GUID_DIID_DispHTMLButtonElement <0x3050f51f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLButtonElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLButtonElement <0x3050f2c6,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLMarqueeElementEvents2 <0x050f61f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLMarqueeElementEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLMarqueeElementEvents <0x3050f2b8,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLMarqueeElementEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLMarqueeElement <0x3050f2b5,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLMarqueeElement STRUCT
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
	put_bgColor PTR
	get_bgColor PTR
	put_scrollDelay PTR
	get_scrollDelay PTR
	put_direction PTR
	get_direction PTR
	put_behavior PTR
	get_behavior PTR
	put_scrollAmount PTR
	get_scrollAmount PTR
	put_loop PTR
	get_loop PTR
	put_vspace PTR
	get_vspace PTR
	put_hspace PTR
	get_hspace PTR
	put_onfinish PTR
	get_onfinish PTR
	put_onstart PTR
	get_onstart PTR
	put_onbounce PTR
	get_onbounce PTR
	put_width PTR
	get_width PTR
	put_height PTR
	get_height PTR
	put_trueSpeed PTR
	get_trueSpeed PTR
	start PTR
	stop PTR
ENDS

#DEFINE GUID_DIID_DispHTMLMarqueeElement <0x3050f527,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLMarqueeElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLMarqueeElement <0x3050f2b9,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLHtmlElement <0x3050f81c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLHtmlElement STRUCT
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
	put_version PTR
	get_version PTR
ENDS

#DEFINE GUID_IID_IHTMLHeadElement <0x3050f81d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLHeadElement STRUCT
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
	put_profile PTR
	get_profile PTR
ENDS

#DEFINE GUID_IID_IHTMLTitleElement <0x3050f322,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTitleElement STRUCT
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
	put_text PTR
	get_text PTR
ENDS

#DEFINE GUID_IID_IHTMLMetaElement <0x3050f203,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLMetaElement STRUCT
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
	put_httpEquiv PTR
	get_httpEquiv PTR
	put_content PTR
	get_content PTR
	put_name PTR
	get_name PTR
	put_url PTR
	get_url PTR
	put_charset PTR
	get_charset PTR
ENDS

#DEFINE GUID_IID_IHTMLMetaElement2 <0x3050f81f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLMetaElement2 STRUCT
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
	put_scheme PTR
	get_scheme PTR
ENDS

#DEFINE GUID_IID_IHTMLBaseElement <0x3050f204,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLBaseElement STRUCT
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
	put_href PTR
	get_href PTR
	put_target PTR
	get_target PTR
ENDS

#DEFINE GUID_IID_IHTMLIsIndexElement <0x3050f206,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLIsIndexElement STRUCT
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
	put_prompt PTR
	get_prompt PTR
	put_action PTR
	get_action PTR
ENDS

#DEFINE GUID_IID_IHTMLIsIndexElement2 <0x3050f82f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLIsIndexElement2 STRUCT
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
	get_form PTR
ENDS

#DEFINE GUID_IID_IHTMLNextIdElement <0x3050f207,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLNextIdElement STRUCT
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
	put_n PTR
	get_n PTR
ENDS

#DEFINE GUID_DIID_DispHTMLHtmlElement <0x3050f560,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLHtmlElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLHtmlElement <0x3050f491,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLHeadElement <0x3050f561,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLHeadElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLHeadElement <0x3050f493,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLTitleElement <0x3050f516,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLTitleElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLTitleElement <0x3050f284,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLMetaElement <0x3050f517,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLMetaElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLMetaElement <0x3050f275,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLBaseElement <0x3050f518,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLBaseElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLBaseElement <0x3050f276,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLIsIndexElement <0x3050f519,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLIsIndexElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLIsIndexElement <0x3050f278,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLNextIdElement <0x3050f51a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLNextIdElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLNextIdElement <0x3050f279,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLBaseFontElement <0x3050f202,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLBaseFontElement STRUCT
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
	put_color PTR
	get_color PTR
	put_face PTR
	get_face PTR
	put_size PTR
	get_size PTR
ENDS

#DEFINE GUID_DIID_DispHTMLBaseFontElement <0x3050f504,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLBaseFontElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLBaseFontElement <0x3050f282,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLUnknownElement <0x3050f209,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define IHTMLUnknownElement STANDARD_DISPATCH

#DEFINE GUID_DIID_DispHTMLUnknownElement <0x3050f539,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLUnknownElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLUnknownElement <0x3050f268,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IOmHistory <0xFECEAAA2,0x8405,0x11cf,<0x8B,0xA1,0x00,0xAA,0x00,0x47,0x6D,0xA6>>

IOmHistory STRUCT
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
	get_length PTR
	back PTR
	forward PTR
	go PTR
ENDS

#DEFINE GUID_IID_IHTMLMimeTypesCollection <0x3050f3fc,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLMimeTypesCollection STRUCT
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
	get_length PTR
ENDS

#DEFINE GUID_IID_IHTMLPluginsCollection <0x3050f3fd-98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLPluginsCollection STRUCT
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
	get_length PTR
	refresh PTR
ENDS

#DEFINE GUID_IID_IHTMLOpsProfile <0x3050f401,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLOpsProfile STRUCT
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
	addRequest PTR
	clearRequest PTR
	doRequest PTR
	getAttribute PTR
	setAttribute PTR
	commitChanges PTR
	addReadRequest PTR
	doReadRequest PTR
	doWriteRequest PTR
ENDS

#DEFINE GUID_IID_IOmNavigator <0xFECEAAA5,0x8405,0x11cf,<0x8B,0xA1,0x00,0xAA,0x00,0x47,0x6D,0xA6>>

IOmNavigator STRUCT
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
	get_appCodeName PTR
	get_appName PTR
	get_appVersion PTR
	get_userAgent PTR
	javaEnabled PTR
	taintEnabled PTR
	get_mimeTypes PTR
	get_plugins PTR
	get_cookieEnabled PTR
	get_opsProfile PTR
	toString PTR
	get_cpuClass PTR
	get_systemLanguage PTR
	get_browserLanguage PTR
	get_userLanguage PTR
	get_platform PTR
	get_appMinorVersion PTR
	get_connectionSpeed PTR
	get_onLine PTR
	get_userProfile PTR
ENDS

#DEFINE GUID_IID_IHTMLLocation <0x163BB1E0,0x6E00,0x11cf,<0x83,0x7A,0x48,0xDC,0x04,0xC1,0x00,0x00>>

IHTMLLocation STRUCT
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
	put_href PTR
	get_href PTR
	put_protocol PTR
	get_protocol PTR
	put_host PTR
	get_host PTR
	put_hostname PTR
	get_hostname PTR
	put_port PTR
	get_port PTR
	put_pathname PTR
	get_pathname PTR
	put_search PTR
	get_search PTR
	put_hash PTR
	get_hash PTR
	reload PTR
	replace PTR
	assign PTR
	toString PTR
ENDS

#DEFINE GUID_CLSID_HTMLHistory <0xFECEAAA3,0x8405,0x11cf,<0x8B,0xA1,0x00,0xAA,0x00,0x47,0x6D,0xA6>>
#DEFINE GUID_CLSID_CMimeTypes <0x3050f3fe,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_CLSID_CPlugins <0x3050f3ff,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
// GUIDS done automatically fromthis point on
#DEFINE GUID_CLSID_COpsProfile <0x3050f402,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_CLSID_HTMLNavigator <0xFECEAAA6,0x8405,0x11cf,<0x8B,0xA1,0x00,0xAA,0x00,0x47,0x6D,0xA6>>
#DEFINE GUID_CLSID_HTMLLocation <0x163BB1E1,0x6E00,0x11cf,<0x83,0x7A,0x48,0xDC,0x04,0xC1,0x00,0x00>>

#DEFINE GUID_IID_IHTMLBookmarkCollection <0x3050f4ce,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLBookmarkCollection STRUCT
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
	get_length PTR
	get__newEnum PTR
	item PTR
ENDS

#DEFINE GUID_IID_IHTMLDataTransfer <0x3050f4b3,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDataTransfer STRUCT
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
	setData PTR
	getData PTR
	clearData PTR
	put_dropEffect PTR
	get_dropEffect PTR
	put_effectAllowed PTR
	get_effectAllowed PTR
ENDS

#DEFINE GUID_IID_IHTMLEventObj2 <0x3050f48B,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLEventObj2 STRUCT
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
	setAttribute PTR
	getAttribute PTR
	removeAttribute PTR
	put_propertyName PTR
	get_propertyName PTR
	putref_bookmarks PTR
	get_bookmarks PTR
	putref_recordset PTR
	get_recordset PTR
	put_dataFld PTR
	get_dataFld PTR
	putref_boundElements PTR
	get_boundElements PTR
	put_repeat PTR
	get_repeat PTR
	put_srcUrn PTR
	get_srcUrn PTR
	putref_srcElement PTR
	get_srcElement PTR
	put_altKey PTR
	get_altKey PTR
	put_ctrlKey PTR
	get_ctrlKey PTR
	put_shiftKey PTR
	get_shiftKey PTR
	putref_fromElement PTR
	get_fromElement PTR
	putref_toElement PTR
	get_toElement PTR
	put_button PTR
	get_button PTR
	put_type PTR
	get_type PTR
	put_qualifier PTR
	get_qualifier PTR
	put_reason PTR
	get_reason PTR
	put_x PTR
	get_x PTR
	put_y PTR
	get_y PTR
	put_clientX PTR
	get_clientX PTR
	put_clientY PTR
	get_clientY PTR
	put_offsetX PTR
	get_offsetX PTR
	put_offsetY PTR
	get_offsetY PTR
	put_screenX PTR
	get_screenX PTR
	put_screenY PTR
	get_screenY PTR
	putref_srcFilter PTR
	get_srcFilter PTR
	get_dataTransfer PTR
ENDS

#DEFINE GUID_IID_IHTMLEventObj3 <0x3050f680,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLEventObj3 STRUCT
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
	get_contentOverflow PTR
	put_shiftLeft PTR
	get_shiftLeft PTR
	put_altLeft PTR
	get_altLeft PTR
	put_ctrlLeft PTR
	get_ctrlLeft PTR
	get_imeCompositionChange PTR
	get_imeNotifyCommand PTR
	get_imeNotifyData PTR
	get_imeRequest PTR
	get_imeRequestData PTR
	get_keyboardLayout PTR
	get_behaviorCookie PTR
	get_behaviorPart PTR
	get_nextPage PTR
ENDS

#DEFINE GUID_IID_IHTMLEventObj4 <0x3050f814,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLEventObj4 STRUCT
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
	get_wheelDelta PTR
ENDS

#DEFINE GUID_DIID_DispCEventObj <0x3050f558,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispCEventObj STANDARD_DISPATCH

#DEFINE GUID_CLSID_CEventObj <0x3050f48A,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLWindowEvents2 <0x3050f625,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLWindowEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLWindowEvents <0x96A0A4E0,0xD062,0x11cf,<0x94,0xB6,0x00,0xAA,0x00,0x60,0x27,0x5C>>

#define HTMLWindowEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLDocument2 <0x332c4425,0x26cb,0x11d0,<0xb4,0x83,0x00,0xc0,0x4f,0xd9,0x01,0x19>>

IHTMLDocument2 STRUCT
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
	get_Script PTR
	get_all PTR
	get_body PTR
	get_activeElement PTR
	get_images PTR
	get_applets PTR
	get_links PTR
	get_forms PTR
	get_anchors PTR
	put_title PTR
	get_title PTR
	get_scripts PTR
	put_designMode PTR
	get_designMode PTR
	get_selection PTR
	get_readyState PTR
	get_frames PTR
	get_embeds PTR
	get_plugins PTR
	put_alinkColor PTR
	get_alinkColor PTR
	put_bgColor PTR
	get_bgColor PTR
	put_fgColor PTR
	get_fgColor PTR
	put_linkColor PTR
	get_linkColor PTR
	put_vlinkColor PTR
	get_vlinkColor PTR
	get_referrer PTR
	get_location PTR
	get_lastModified PTR
	put_URL PTR
	get_URL PTR
	put_domain PTR
	get_domain PTR
	put_cookie PTR
	get_cookie PTR
	put_expando PTR
	get_expando PTR
	put_charset PTR
	get_charset PTR
	put_defaultCharset PTR
	get_defaultCharset PTR
	get_mimeType PTR
	get_fileSize PTR
	get_fileCreatedDate PTR
	get_fileModifiedDate PTR
	get_fileUpdatedDate PTR
	get_security PTR
	get_protocol PTR
	get_nameProp PTR
	write PTR
	writeln PTR
	open PTR
	close PTR
	clear PTR
	queryCommandSupported PTR
	queryCommandEnabled PTR
	queryCommandState PTR
	queryCommandIndeterm PTR
	queryCommandText PTR
	queryCommandValue PTR
	execCommand PTR
	execCommandShowHelp PTR
	createElement PTR
	put_onhelp PTR
	get_onhelp PTR
	put_onclick PTR
	get_onclick PTR
	put_ondblclick PTR
	get_ondblclick PTR
	put_onkeyup PTR
	get_onkeyup PTR
	put_onkeydown PTR
	get_onkeydown PTR
	put_onkeypress PTR
	get_onkeypress PTR
	put_onmouseup PTR
	get_onmouseup PTR
	put_onmousedown PTR
	get_onmousedown PTR
	put_onmousemove PTR
	get_onmousemove PTR
	put_onmouseout PTR
	get_onmouseout PTR
	put_onmouseover PTR
	get_onmouseover PTR
	put_onreadystatechange PTR
	get_onreadystatechange PTR
	put_onafterupdate PTR
	get_onafterupdate PTR
	put_onrowexit PTR
	get_onrowexit PTR
	put_onrowenter PTR
	get_onrowenter PTR
	put_ondragstart PTR
	get_ondragstart PTR
	put_onselectstart PTR
	get_onselectstart PTR
	elementFromPoint PTR
	get_parentWindow PTR
	get_styleSheets PTR
	put_onbeforeupdate PTR
	get_onbeforeupdate PTR
	put_onerrorupdate PTR
	get_onerrorupdate PTR
	toString PTR
	createStyleSheet PTR
ENDS

#DEFINE GUID_IID_IHTMLFramesCollection2 <0x332c4426,0x26cb,0x11d0,<0xb4,0x83,0x00,0xc0,0x4f,0xd9,0x01,0x19>>

IHTMLFramesCollection2 STRUCT
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
	item PTR
	get_length PTR
ENDS

#DEFINE GUID_IID_IHTMLWindow2 <0x332c4427,0x26cb,0x11d0,<0xb4,0x83,0x00,0xc0,0x4f,0xd9,0x01,0x19>>

IHTMLWindow2 STRUCT
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
	item PTR
	get_length PTR
	get_frames PTR
	put_defaultStatus PTR
	get_defaultStatus PTR
	put_status PTR
	get_status PTR
	setTimeout PTR
	clearTimeout PTR
	alert PTR
	confirm PTR
	prompt PTR
	get_Image PTR
	get_location PTR
	get_history PTR
	close PTR
	put_opener PTR
	get_opener PTR
	get_navigator PTR
	put_name PTR
	get_name PTR
	get_parent PTR
	open PTR
	get_self PTR
	get_top PTR
	get_window PTR
	navigate PTR
	put_onfocus PTR
	get_onfocus PTR
	put_onblur PTR
	get_onblur PTR
	put_onload PTR
	get_onload PTR
	put_onbeforeunload PTR
	get_onbeforeunload PTR
	put_onunload PTR
	get_onunload PTR
	put_onhelp PTR
	get_onhelp PTR
	put_onerror PTR
	get_onerror PTR
	put_onresize PTR
	get_onresize PTR
	put_onscroll PTR
	get_onscroll PTR
	get_document PTR
	get_event PTR
	get__newEnum PTR
	showModalDialog PTR
	showHelp PTR
	get_screen PTR
	get_Option PTR
	focus PTR
	get_closed PTR
	blur PTR
	scroll PTR
	get_clientInformation PTR
	setInterval PTR
	clearInterval PTR
	put_offscreenBuffering PTR
	get_offscreenBuffering PTR
	execScript PTR
	toString PTR
	scrollBy PTR
	scrollTo PTR
	moveTo PTR
	moveBy PTR
	resizeTo PTR
	resizeBy PTR
	get_external PTR
ENDS

#DEFINE GUID_IID_IHTMLWindow3 <0x3050f4ae,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLWindow3 STRUCT
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
	get_screenLeft PTR
	get_screenTop PTR
	attachEvent PTR
	detachEvent PTR
	setTimeout PTR
	setInterval PTR
	print PTR
	put_onbeforeprint PTR
	get_onbeforeprint PTR
	put_onafterprint PTR
	get_onafterprint PTR
	get_clipboardData PTR
	showModelessDialog PTR
ENDS

#DEFINE GUID_IID_IHTMLFrameBase <0x3050f311,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFrameBase STRUCT
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
	put_src PTR
	get_src PTR
	put_name PTR
	get_name PTR
	put_border PTR
	get_border PTR
	put_frameBorder PTR
	get_frameBorder PTR
	put_frameSpacing PTR
	get_frameSpacing PTR
	put_marginWidth PTR
	get_marginWidth PTR
	put_marginHeight PTR
	get_marginHeight PTR
	put_noResize PTR
	get_noResize PTR
	put_scrolling PTR
	get_scrolling PTR
ENDS

#DEFINE GUID_IID_IHTMLScreen <0x3050f35c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLScreen STRUCT
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
	get_colorDepth PTR
	put_bufferDepth PTR
	get_bufferDepth PTR
	get_width PTR
	get_height PTR
	put_updateInterval PTR
	get_updateInterval PTR
	get_availHeight PTR
	get_availWidth PTR
	get_fontSmoothingEnabled PTR
ENDS

#DEFINE GUID_IID_IHTMLScreen2 <0x3050f84a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLScreen2 STRUCT
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
	get_logicalXDPI PTR
	get_logicalYDPI PTR
	get_deviceXDPI PTR
	get_deviceYDPI PTR
ENDS

#DEFINE GUID_IID_IHTMLWindow4 <0x3050f6cf,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLWindow4 STRUCT
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
	createPopup PTR
	get_frameElement PTR
ENDS

#DEFINE GUID_IID_IHTMLWindow5 <0x3051040e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLWindow5 STRUCT
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
	put_XMLHttpRequest PTR
	get_XMLHttpRequest PTR
ENDS

#DEFINE GUID_CLSID_FramesCollection <0x3050f7f6,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLScreen <0x3050f591,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLScreen STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLScreen <0x3050f35d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLWindow2 <0x3050f55d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLWindow2 STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLWindow2 <0xD48A6EC6,0x6A4A,0x11cf,<0x94,0xA7,0x44,0x45,0x53,0x54,0x00,0x00>>

#DEFINE GUID_DIID_DispHTMLWindowProxy <0x3050f55e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLWindowProxy STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLWindowProxy <0x3050f391,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLDocumentEvents2 <0x3050f613,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLDocumentEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLDocumentEvents <0x3050f260,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLDocumentEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLDocument3 <0x3050f485,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDocument3 STRUCT
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
	releaseCapture PTR
	recalc PTR
	createTextNode PTR
	get_documentElement PTR
	get_uniqueID PTR
	attachEvent PTR
	detachEvent PTR
	put_onrowsdelete PTR
	get_onrowsdelete PTR
	put_onrowsinserted PTR
	get_onrowsinserted PTR
	put_oncellchange PTR
	get_oncellchange PTR
	put_ondatasetchanged PTR
	get_ondatasetchanged PTR
	put_ondataavailable PTR
	get_ondataavailable PTR
	put_ondatasetcomplete PTR
	get_ondatasetcomplete PTR
	put_onpropertychange PTR
	get_onpropertychange PTR
	put_dir PTR
	get_dir PTR
	put_oncontextmenu PTR
	get_oncontextmenu PTR
	put_onstop PTR
	get_onstop PTR
	createDocumentFragment PTR
	get_parentDocument PTR
	put_enableDownload PTR
	get_enableDownload PTR
	put_baseUrl PTR
	get_baseUrl PTR
	get_childNodes PTR
	put_inheritStyleSheets PTR
	get_inheritStyleSheets PTR
	put_onbeforeeditfocus PTR
	get_onbeforeeditfocus PTR
	getElementsByName PTR
	getElementById PTR
	getElementsByTagName PTR
ENDS

#DEFINE GUID_IID_IHTMLDocument4 <0x3050f69a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDocument4 STRUCT
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
	focus PTR
	hasFocus PTR
	put_onselectionchange PTR
	get_onselectionchange PTR
	get_namespaces PTR
	createDocumentFromUrl PTR
	put_media PTR
	get_media PTR
	createEventObject PTR
	fireEvent PTR
	createRenderStyle PTR
	put_oncontrolselect PTR
	get_oncontrolselect PTR
	get_URLUnencoded PTR
ENDS

#DEFINE GUID_IID_IHTMLDocument5 <0x3050f80c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDocument5 STRUCT
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
	put_onmousewheel PTR
	get_onmousewheel PTR
	get_doctype PTR
	get_implementation PTR
	createAttribute PTR
	createComment PTR
	put_onfocusin PTR
	get_onfocusin PTR
	put_onfocusout PTR
	get_onfocusout PTR
	put_onactivate PTR
	get_onactivate PTR
	put_ondeactivate PTR
	get_ondeactivate PTR
	put_onbeforeactivate PTR
	get_onbeforeactivate PTR
	put_onbeforedeactivate PTR
	get_onbeforedeactivate PTR
	get_compatMode PTR
ENDS

#DEFINE GUID_DIID_DispHTMLDocument <0x3050f55f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLDocument STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLDocument <0x25336920,0x03F9,0x11cf,<0x8F,0xD0,0x00,0xAA,0x00,0x68,0x6F,0x13>>

#DEFINE GUID_DIID_DWebBridgeEvents <0xA6D897FF,0x0A95,0x11d1,<0xB0,0xBA,0x00,0x60,0x08,0x16,0x6E,0x11>>

#define DWebBridgeEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IWebBridge <0xAE24FDAD,0x03C6,0x11D1,<0x8B,0x76,0x00,0x80,0xC7,0x44,0xF3,0x89>>

IWebBridge STRUCT
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
	put_URL PTR
	get_URL PTR
	put_Scrollbar PTR
	get_Scrollbar PTR
	put_embed PTR
	get_embed PTR
	get_event PTR
	get_readyState PTR
	AboutBox PTR
ENDS

#DEFINE GUID_IID_IWBScriptControl <0xA5170870,0x0CF8,0x11D1,<0x8B,0x91,0x00,0x80,0xC7,0x44,0xF3,0x89>>

IWBScriptControl STRUCT
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
	raiseEvent PTR
	bubbleEvent PTR
	setContextMenu PTR
	put_selectableContent PTR
	get_selectableContent PTR
	get_frozen PTR
	put_scrollbar PTR
	get_scrollbar PTR
	get_version PTR
	get_visibility PTR
	put_onvisibilitychange PTR
	get_onvisibilitychange PTR
ENDS

#DEFINE GUID_CLSID_Scriptlet <0xAE24FDAE,0x03C6,0x11D1,<0x8B,0x76,0x00,0x80,0xC7,0x44,0xF3,0x89>>

#DEFINE GUID_IID_IHTMLEmbedElement <0x3050f25f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLEmbedElement STRUCT
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
	put_hidden PTR
	get_hidden PTR
	get_palette PTR
	get_pluginspage PTR
	put_src PTR
	get_src PTR
	put_units PTR
	get_units PTR
	put_name PTR
	get_name PTR
	put_width PTR
	get_width PTR
	put_height PTR
	get_height PTR
ENDS

#DEFINE GUID_DIID_DispHTMLEmbed <0x3050f52e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLEmbed STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLEmbed <0x3050f25d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLMapEvents2 <0x3050f61e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLMapEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLMapEvents <0x3050f3ba,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLMapEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLAreasCollection <0x3050f383,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLAreasCollection STRUCT
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
	put_length PTR
	get_length PTR
	get__newEnum PTR
	item PTR
	tags PTR
	add PTR
	remove PTR
ENDS

#DEFINE GUID_IID_IHTMLAreasCollection2 <0x3050f5ec,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLAreasCollection2 STRUCT
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
	urns PTR
ENDS

#DEFINE GUID_IID_IHTMLAreasCollection3 <0x3050f837,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLAreasCollection3 STRUCT
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
	namedItem PTR
ENDS

#DEFINE GUID_IID_IHTMLMapElement <0x3050f266,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLMapElement STRUCT
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
	get_areas PTR
	put_name PTR
	get_name PTR
ENDS

#DEFINE GUID_DIID_DispHTMLAreasCollection <0x3050f56a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLAreasCollection STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLAreasCollection <0x3050f4ca,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLMapElement <0x3050f526,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLMapElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLMapElement <0x3050f271,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLAreaEvents2 <0x3050f611,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLAreaEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLAreaEvents <0x3050f366,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLAreaEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLAreaElement <0x3050f265,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLAreaElement STRUCT
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
	put_shape PTR
	get_shape PTR
	put_coords PTR
	get_coords PTR
	put_href PTR
	get_href PTR
	put_target PTR
	get_target PTR
	put_alt PTR
	get_alt PTR
	put_noHref PTR
	get_noHref PTR
	put_host PTR
	get_host PTR
	put_hostname PTR
	get_hostname PTR
	put_pathname PTR
	get_pathname PTR
	put_port PTR
	get_port PTR
	put_protocol PTR
	get_protocol PTR
	put_search PTR
	get_search PTR
	put_hash PTR
	get_hash PTR
	put_onblur PTR
	get_onblur PTR
	put_onfocus PTR
	get_onfocus PTR
	put_tabIndex PTR
	get_tabIndex PTR
	focus PTR
	blur PTR
ENDS

#DEFINE GUID_DIID_DispHTMLAreaElement <0x3050f503,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLAreaElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLAreaElement <0x3050f283,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLTableCaption <0x3050f2eb,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTableCaption STRUCT
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
	put_align PTR
	get_align PTR
	put_vAlign PTR
	get_vAlign PTR
ENDS

#DEFINE GUID_DIID_DispHTMLTableCaption <0x3050f508,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLTableCaption STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLTableCaption <0x3050f2ec,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLCommentElement <0x3050f20c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLCommentElement STRUCT
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
	put_text PTR
	get_text PTR
	put_atomic PTR
	get_atomic PTR
ENDS

#DEFINE GUID_IID_IHTMLCommentElement2 <0x3050f813,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLCommentElement2 STRUCT
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
	put_data PTR
	get_data PTR
	get_length PTR
	substringData PTR
	appendData PTR
	insertData PTR
	deleteData PTR
	replaceData PTR
ENDS

#DEFINE GUID_DIID_DispHTMLCommentElement <0x3050f50a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLCommentElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLCommentElement <0x3050f317,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLPhraseElement <0x3050f20a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define IHTMLPhraseElement STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLPhraseElement2 <0x3050f824,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLPhraseElement2 STRUCT
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
	put_cite PTR
	get_cite PTR
	put_dateTime PTR
	get_dateTime PTR
ENDS

#DEFINE GUID_IID_IHTMLSpanElement <0x3050f3f3,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define IHTMLSpanElement STANDARD_DISPATCH

#DEFINE GUID_DIID_DispHTMLPhraseElement <0x3050f52d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLPhraseElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLPhraseElement <0x3050f26e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLSpanElement <0x3050f548,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLSpanElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLSpanElement <0x3050f3f5,0x98b4,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLTableEvents2 <0x3050f623,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLTableEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLTableEvents <0x3050f407,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLTableEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLTableSection <0x3050f23b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTableSection STRUCT
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
	put_align PTR
	get_align PTR
	put_vAlign PTR
	get_vAlign PTR
	put_bgColor PTR
	get_bgColor PTR
	get_rows PTR
	insertRow PTR
	deleteRow PTR
ENDS

#DEFINE GUID_IID_IHTMLTable <0x3050f21e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTable STRUCT
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
	put_cols PTR
	get_cols PTR
	put_border PTR
	get_border PTR
	put_frame PTR
	get_frame PTR
	put_rules PTR
	get_rules PTR
	put_cellSpacing PTR
	get_cellSpacing PTR
	put_cellPadding PTR
	get_cellPadding PTR
	put_background PTR
	get_background PTR
	put_bgColor PTR
	get_bgColor PTR
	put_borderColor PTR
	get_borderColor PTR
	put_borderColorLight PTR
	get_borderColorLight PTR
	put_borderColorDark PTR
	get_borderColorDark PTR
	put_align PTR
	get_align PTR
	refresh PTR
	get_rows PTR
	put_width PTR
	get_width PTR
	put_height PTR
	get_height PTR
	put_dataPageSize PTR
	get_dataPageSize PTR
	nextPage PTR
	previousPage PTR
	get_tHead PTR
	get_tFoot PTR
	get_tBodies PTR
	get_caption PTR
	createTHead PTR
	deleteTHead PTR
	createTFoot PTR
	deleteTFoot PTR
	createCaption PTR
	deleteCaption PTR
	insertRow PTR
	deleteRow PTR
	get_readyState PTR
	put_onreadystatechange PTR
	get_onreadystatechange PTR
ENDS

#DEFINE GUID_IID_IHTMLTable2 <0x3050f4ad,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTable2 STRUCT
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
	firstPage PTR
	lastPage PTR
	get_cells PTR
	moveRow PTR
ENDS

#DEFINE GUID_IID_IHTMLTable3 <0x3050f829,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTable3 STRUCT
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
	put_summary PTR
	get_summary PTR
ENDS

#DEFINE GUID_IID_IHTMLTableCol <0x3050f23a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTableCol STRUCT
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
	put_span PTR
	get_span PTR
	put_width PTR
	get_width PTR
	put_align PTR
	get_align PTR
	put_vAlign PTR
	get_vAlign PTR
ENDS

#DEFINE GUID_IID_IHTMLTableCol2 <0x3050f82a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTableCol2 STRUCT
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
	put_ch PTR
	get_ch PTR
	put_chOff PTR
	get_chOff PTR
ENDS

#DEFINE GUID_IID_IHTMLTableSection2 <0x3050f5c7,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTableSection2 STRUCT
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
	moveRow PTR
ENDS

#DEFINE GUID_IID_IHTMLTableSection3 <0x3050f82b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTableSection3 STRUCT
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
	put_ch PTR
	get_ch PTR
	put_chOff PTR
	get_chOff PTR
ENDS

#DEFINE GUID_IID_IHTMLTableRow <0x3050f23c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTableRow STRUCT
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
	put_align PTR
	get_align PTR
	put_vAlign PTR
	get_vAlign PTR
	put_bgColor PTR
	get_bgColor PTR
	put_borderColor PTR
	get_borderColor PTR
	put_borderColorLight PTR
	get_borderColorLight PTR
	put_borderColorDark PTR
	get_borderColorDark PTR
	get_rowIndex PTR
	get_sectionRowIndex PTR
	get_cells PTR
	insertCell PTR
	deleteCell PTR
ENDS

#DEFINE GUID_IID_IHTMLTableRow2 <0x3050f4a1,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTableRow2 STRUCT
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
	put_height PTR
	get_height PTR
ENDS

#DEFINE GUID_IID_IHTMLTableRow3 <0x3050f82c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTableRow3 STRUCT
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
	put_ch PTR
	get_ch PTR
	put_chOff PTR
	get_chOff PTR
ENDS

#DEFINE GUID_IID_IHTMLTableRowMetrics <0x3050f413,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTableRowMetrics STRUCT
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
	get_clientHeight PTR
	get_clientWidth PTR
	get_clientTop PTR
	get_clientLeft PTR
ENDS

#DEFINE GUID_IID_IHTMLTableCell <0x3050f23d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTableCell STRUCT
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
	put_rowSpan PTR
	get_rowSpan PTR
	put_colSpan PTR
	get_colSpan PTR
	put_align PTR
	get_align PTR
	put_vAlign PTR
	get_vAlign PTR
	put_bgColor PTR
	get_bgColor PTR
	put_noWrap PTR
	get_noWrap PTR
	put_background PTR
	get_background PTR
	put_borderColor PTR
	get_borderColor PTR
	put_borderColorLight PTR
	get_borderColorLight PTR
	put_borderColorDark PTR
	get_borderColorDark PTR
	put_width PTR
	get_width PTR
	put_height PTR
	get_height PTR
	get_cellIndex PTR
ENDS

#DEFINE GUID_IID_IHTMLTableCell2 <0x3050f82d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLTableCell2 STRUCT
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
	put_abbr PTR
	get_abbr PTR
	put_axis PTR
	get_axis PTR
	put_ch PTR
	get_ch PTR
	put_chOff PTR
	get_chOff PTR
	put_headers PTR
	get_headers PTR
	put_scope PTR
	get_scope PTR
ENDS

#DEFINE GUID_DIID_DispHTMLTable <0x3050f532,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLTable STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLTable <0x3050f26b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLTableCol <0x3050f533,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLTableCol STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLTableCol <0x3050f26c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLTableSection <0x3050f534,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLTableSection STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLTableSection <0x3050f2e9,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLTableRow <0x3050f535,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLTableRow STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLTableRow <0x3050f26d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLTableCell <0x3050f536,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLTableCell STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLTableCell <0x3050f246,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLScriptEvents2 <0x3050f621,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLScriptEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLScriptEvents <0x3050f3e2,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLScriptEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLScriptElement <0x3050f28b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLScriptElement STRUCT
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
	put_src PTR
	get_src PTR
	put_htmlFor PTR
	get_htmlFor PTR
	put_event PTR
	get_event PTR
	put_text PTR
	get_text PTR
	put_defer PTR
	get_defer PTR
	get_readyState PTR
	put_onerror PTR
	get_onerror PTR
	put_type PTR
	get_type PTR
ENDS

#DEFINE GUID_IID_IHTMLScriptElement2 <0x3050f828,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLScriptElement2 STRUCT
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
	put_charset PTR
	get_charset PTR
ENDS

#DEFINE GUID_DIID_DispHTMLScriptElement <0x3050f530,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLScriptElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLScriptElement <0x3050f28c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLNoShowElement <0x3050f38a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define IHTMLNoShowElement STANDARD_DISPATCH

#DEFINE GUID_DIID_DispHTMLNoShowElement <0x3050f528,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLNoShowElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLNoShowElement <0x3050f38b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLObjectElementEvents2 <0x3050f620,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLObjectElementEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLObjectElementEvents <0x3050f3c4,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLObjectElementEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLObjectElement <0x3050f24f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLObjectElement STRUCT
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
	get_object PTR
	get_classid PTR
	get_data PTR
	putref_recordset PTR
	get_recordset PTR
	put_align PTR
	get_align PTR
	put_name PTR
	get_name PTR
	put_codeBase PTR
	get_codeBase PTR
	put_codeType PTR
	get_codeType PTR
	put_code PTR
	get_code PTR
	get_BaseHref PTR
	put_type PTR
	get_type PTR
	get_form PTR
	put_width PTR
	get_width PTR
	put_height PTR
	get_height PTR
	get_readyState PTR
	put_onreadystatechange PTR
	get_onreadystatechange PTR
	put_onerror PTR
	get_onerror PTR
	put_altHtml PTR
	get_altHtml PTR
	put_vspace PTR
	get_vspace PTR
	put_hspace PTR
	get_hspace PTR
ENDS

#DEFINE GUID_IID_IHTMLObjectElement2 <0x3050f4cd,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLObjectElement2 STRUCT
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
	namedRecordset PTR
	put_classid PTR
	get_classid PTR
	put_data PTR
	get_data PTR
ENDS

#DEFINE GUID_IID_IHTMLObjectElement3 <0x3050f827,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLObjectElement3 STRUCT
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
	put_archive PTR
	get_archive PTR
	put_alt PTR
	get_alt PTR
	put_declare PTR
	get_declare PTR
	put_standby PTR
	get_standby PTR
	put_border PTR
	get_border PTR
	put_useMap PTR
	get_useMap PTR
ENDS

#DEFINE GUID_IID_IHTMLParamElement <0x3050f83d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLParamElement STRUCT
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
	put_name PTR
	get_name PTR
	put_value PTR
	get_value PTR
	put_type PTR
	get_type PTR
	put_valueType PTR
	get_valueType PTR
ENDS

#DEFINE GUID_DIID_DispHTMLObjectElement <0x3050f529,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLObjectElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLObjectElement <0x3050f24e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLParamElement <0x3050f590,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLParamElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLParamElement <0x3050f83e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLFrameSiteEvents2 <0x3050f7ff,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLFrameSiteEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLFrameSiteEvents <0x3050f800,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLFrameSiteEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLFrameBase2 <0x3050f6db,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFrameBase2 STRUCT
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
	get_contentWindow PTR
	put_onload PTR
	get_onload PTR
	put_onreadystatechange PTR
	get_onreadystatechange PTR
	get_readyState PTR
	put_allowTransparency PTR
	get_allowTransparency PTR
ENDS

#DEFINE GUID_IID_IHTMLFrameBase3 <0x3050f82e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFrameBase3 STRUCT
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
	put_longDesc PTR
	get_longDesc PTR
ENDS

#DEFINE GUID_DIID_DispHTMLFrameBase <0x3050f541,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLFrameBase STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLFrameBase <0x3050f312,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLFrameElement <0x3050f313,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFrameElement STRUCT
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
	put_borderColor PTR
	get_borderColor PTR
ENDS

#DEFINE GUID_IID_IHTMLFrameElement2 <0x3050f7f5,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFrameElement2 STRUCT
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
	put_height PTR
	get_height PTR
	put_width PTR
	get_width PTR
ENDS

#DEFINE GUID_DIID_DispHTMLFrameElement <0x3050f513,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLFrameElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLFrameElement <0x3050f314,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLIFrameElement <0x3050f315,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLIFrameElement STRUCT
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
	put_vspace PTR
	get_vspace PTR
	put_hspace PTR
	get_hspace PTR
	put_align PTR
	get_align PTR
ENDS

#DEFINE GUID_IID_IHTMLIFrameElement2 <0x3050f4e6,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLIFrameElement2 STRUCT
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
	put_height PTR
	get_height PTR
	put_width PTR
	get_width PTR
ENDS

#DEFINE GUID_DIID_DispHTMLIFrame <0x3050f51b,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLIFrame STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLIFrame <0x3050f316,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLDivPosition <0x3050f212,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDivPosition STRUCT
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
	put_align PTR
	get_align PTR
ENDS

#DEFINE GUID_IID_IHTMLFieldSetElement <0x3050f3e7,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFieldSetElement STRUCT
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
	put_align PTR
	get_align PTR
ENDS

#DEFINE GUID_IID_IHTMLFieldSetElement2 <0x3050f833,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFieldSetElement2 STRUCT
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
	get_form PTR
ENDS

#DEFINE GUID_IID_IHTMLLegendElement <0x3050f3ea,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLLegendElement STRUCT
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
	put_align PTR
	get_align PTR
ENDS

#DEFINE GUID_IID_IHTMLLegendElement2 <0x3050f834,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLLegendElement2 STRUCT
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
	get_form PTR
ENDS

#DEFINE GUID_DIID_DispHTMLDivPosition <0x3050f50f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLDivPosition STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLDivPosition <0x3050f249,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLFieldSetElement <0x3050f545,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLFieldSetElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLFieldSetElement <0x3050f3e8,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispHTMLLegendElement <0x3050f546,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLLegendElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLLegendElement <0x3050f3e9,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLSpanFlow <0x3050f3e5,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLSpanFlow STRUCT
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
	put_align PTR
	get_align PTR
ENDS

#DEFINE GUID_DIID_DispHTMLSpanFlow <0x3050f544,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLSpanFlow STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLSpanFlow <0x3050f3e6,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLFrameSetElement <0x3050f319,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFrameSetElement STRUCT
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
	put_rows PTR
	get_rows PTR
	put_cols PTR
	get_cols PTR
	put_border PTR
	get_border PTR
	put_borderColor PTR
	get_borderColor PTR
	put_frameBorder PTR
	get_frameBorder PTR
	put_frameSpacing PTR
	get_frameSpacing PTR
	put_name PTR
	get_name PTR
	put_onload PTR
	get_onload PTR
	put_onunload PTR
	get_onunload PTR
	put_onbeforeunload PTR
	get_onbeforeunload PTR
ENDS

#DEFINE GUID_IID_IHTMLFrameSetElement2 <0x3050f5c6,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFrameSetElement2 STRUCT
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
	put_onbeforeprint PTR
	get_onbeforeprint PTR
	put_onafterprint PTR
	get_onafterprint PTR
ENDS

#DEFINE GUID_DIID_DispHTMLFrameSetSite <0x3050f514,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLFrameSetSite STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLFrameSetSite <0x3050f31A,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLBGsound <0x3050f369,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLBGsound STRUCT
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
	put_src PTR
	get_src PTR
	put_loop PTR
	get_loop PTR
	put_volume PTR
	get_volume PTR
	put_balance PTR
	get_balance PTR
ENDS

#DEFINE GUID_DIID_DispHTMLBGsound <0x3050f53c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLBGsound STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLBGsound <0x3050f370,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLFontNamesCollection <0x3050f376,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFontNamesCollection STRUCT
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
	get_length PTR
	get__newEnum PTR
	item PTR
ENDS

#DEFINE GUID_IID_IHTMLFontSizesCollection <0x3050f377,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLFontSizesCollection STRUCT
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
	get_length PTR
	get__newEnum PTR
	get_forFont PTR
	item PTR
ENDS

#DEFINE GUID_IID_IHTMLOptionsHolder <0x3050f378,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLOptionsHolder STRUCT
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
	get_document PTR
	get_fonts PTR
	put_execArg PTR
	get_execArg PTR
	put_errorLine PTR
	get_errorLine PTR
	put_errorCharacter PTR
	get_errorCharacter PTR
	put_errorCode PTR
	get_errorCode PTR
	put_errorMessage PTR
	get_errorMessage PTR
	put_errorDebug PTR
	get_errorDebug PTR
	get_unsecuredWindowOfDocument PTR
	put_findText PTR
	get_findText PTR
	put_anythingAfterFrameset PTR
	get_anythingAfterFrameset PTR
	sizes PTR
	openfiledlg PTR
	savefiledlg PTR
	choosecolordlg PTR
	showSecurityInfo PTR
	isApartmentModel PTR
	getCharset PTR
	get_secureConnectionInfo PTR
ENDS

#DEFINE GUID_DIID_HTMLStyleElementEvents2 <0x3050f615,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLStyleElementEvents2 STANDARD_DISPATCH

#DEFINE GUID_DIID_HTMLStyleElementEvents <0x3050f3cb,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLStyleElementEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLStyleElement <0x3050f375,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLStyleElement STRUCT
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
	put_type PTR
	get_type PTR
	get_readyState PTR
	put_onreadystatechange PTR
	get_onreadystatechange PTR
	put_onload PTR
	get_onload PTR
	put_onerror PTR
	get_onerror PTR
	get_styleSheet PTR
	put_disabled PTR
	get_disabled PTR
	put_media PTR
	get_media PTR
ENDS

#DEFINE GUID_DIID_DispHTMLStyleElement <0x3050f511,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLStyleElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLStyleElement <0x3050f37d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLStyleFontFace <0x3050f3d5,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLStyleFontFace STRUCT
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
	put_fontsrc PTR
	get_fontsrc PTR
ENDS

#DEFINE GUID_CLSID_HTMLStyleFontFace <0x3050f3d4,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_ICSSFilterSite <0x3050f3ed,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

ICSSFilterSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetElement PTR
	FireOnFilterChangeEvent PTR
ENDS

#DEFINE GUID_IID_IMarkupPointer <0x3050f49f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IMarkupPointer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OwningDoc PTR
	Gravity PTR
	SetGravity PTR
	Cling PTR
	SetCling PTR
	Unposition PTR
	IsPositioned PTR
	GetContainer PTR
	MoveAdjacentToElement PTR
	MoveToPointer PTR
	MoveToContainer PTR
	Left PTR
	Right PTR
	CurrentScope PTR
	IsLeftOf PTR
	IsLeftOfOrEqualTo PTR
	IsRightOf PTR
	IsRightOfOrEqualTo PTR
	IsEqualTo PTR
	MoveUnit PTR
	FindText PTR
ENDS

#DEFINE GUID_IID_IMarkupContainer <0x3050f5f9,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IMarkupContainer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OwningDoc PTR
ENDS

#DEFINE GUID_IID_IMarkupContainer2 <0x3050f648,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IMarkupContainer2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OwningDoc PTR
	CreateChangeLog PTR
	RegisterForDirtyRange PTR
	UnRegisterForDirtyRange PTR
	GetAndClearDirtyRange PTR
	GetVersionNumber PTR
	GetMasterElement PTR
ENDS

#DEFINE GUID_IID_IHTMLChangeLog <0x3050f649,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLChangeLog STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetNextChange PTR
ENDS

#DEFINE GUID_IID_IHTMLChangeSink <0x3050f64a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLChangeSink STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Notify PTR
ENDS

#DEFINE GUID_IID_IActiveIMMApp <0x08c0e040,0x62d1,0x11d1,<0x93,0x26,0x00,0x60,0xb0,0x67,0xb8,0x6e>>

IActiveIMMApp STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AssociateContext PTR
	ConfigureIMEA PTR
	ConfigureIMEW PTR
	CreateContext PTR
	DestroyContext PTR
	EnumRegisterWordA PTR
	EnumRegisterWordW PTR
	EscapeA PTR
	EscapeW PTR
	GetCandidateListA PTR
	GetCandidateListW PTR
	GetCandidateListCountA PTR
	GetCandidateListCountW PTR
	GetCandidateWindow PTR
	GetCompositionFontA PTR
	GetCompositionFontW PTR
	GetCompositionStringA PTR
	GetCompositionStringW PTR
	GetCompositionWindow PTR
	GetContext PTR
	GetConversionListA PTR
	GetConversionListW PTR
	GetConversionStatus PTR
	GetDefaultIMEWnd PTR
	GetDescriptionA PTR
	GetDescriptionW PTR
	GetGuideLineA PTR
	GetGuideLineW PTR
	GetIMEFileNameA PTR
	GetIMEFileNameW PTR
	GetOpenStatus PTR
	GetProperty PTR
	GetRegisterWordStyleA PTR
	GetRegisterWordStyleW PTR
	GetStatusWindowPos PTR
	GetVirtualKey PTR
	InstallIMEA PTR
	InstallIMEW PTR
	IsIME PTR
	IsUIMessageA PTR
	IsUIMessageW PTR
	NotifyIME PTR
	RegisterWordA PTR
	RegisterWordW PTR
	ReleaseContext PTR
	SetCandidateWindow PTR
	SetCompositionFontA PTR
	SetCompositionFontW PTR
	SetCompositionStringA PTR
	SetCompositionStringW PTR
	SetCompositionWindow PTR
	SetConversionStatus PTR
	SetOpenStatus PTR
	SetStatusWindowPos PTR
	SimulateHotKey PTR
	UnregisterWordA PTR
	UnregisterWordW PTR
	Activate PTR
	Deactivate PTR
	OnDefWindowProc PTR
	FilterClientWindows PTR
	GetCodePageA PTR
	GetLangId PTR
	AssociateContextEx PTR
	DisableIME PTR
	GetImeMenuItemsA PTR
	GetImeMenuItemsW PTR
	EnumInputContext PTR
ENDS

#DEFINE GUID_IID_ISegmentList <0x3050f605,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

ISegmentList STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateIterator PTR
	GetType PTR
	IsEmpty PTR
ENDS

#DEFINE GUID_IID_ISegmentListIterator <0x3050f692,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

ISegmentListIterator STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Current PTR
	First PTR
	IsDone PTR
	Advance PTR
ENDS

#DEFINE GUID_IID_IHTMLCaret <0x3050f604,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLCaret STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	MoveCaretToPointer PTR
	MoveCaretToPointerEx PTR
	MoveMarkupPointerToCaret PTR
	MoveDisplayPointerToCaret PTR
	IsVisible PTR
	Show PTR
	Hide PTR
	InsertText PTR
	ScrollIntoView PTR
	GetLocation PTR
	GetCaretDirection PTR
	SetCaretDirection PTR
ENDS

#DEFINE GUID_IID_ISegment <0x3050f683,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

ISegment STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPointers PTR
ENDS

#DEFINE GUID_IID_IElementSegment <0x3050f68f,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementSegment STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPointers PTR
	GetElement PTR
	SetPrimary PTR
	IsPrimary PTR
ENDS

#DEFINE GUID_IID_IHighlightSegment <0x3050f690,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHighlightSegment STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetPointers PTR
ENDS

#DEFINE GUID_IID_IHighlightRenderingServices <0x3050f606,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHighlightRenderingServices STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddSegment PTR
	MoveSegmentToPointers PTR
	RemoveSegment PTR
ENDS

#DEFINE GUID_IID_ILineInfo <0x3050f7e2,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

ILineInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_x PTR
	get_baseLine PTR
	get_textDescent PTR
	get_textHeight PTR
	get_lineDirection PTR
ENDS

#DEFINE GUID_IID_IDisplayPointer <0x3050f69e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IDisplayPointer STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	MoveToPoint PTR
	MoveUnit PTR
	PositionMarkupPointer PTR
	MoveToPointer PTR
	SetPointerGravity PTR
	GetPointerGravity PTR
	SetDisplayGravity PTR
	GetDisplayGravity PTR
	IsPositioned PTR
	Unposition PTR
	IsEqualTo PTR
	IsLeftOf PTR
	IsRightOf PTR
	IsAtBOL PTR
	MoveToMarkupPointer PTR
	ScrollIntoView PTR
	GetLineInfo PTR
	GetFlowElement PTR
	QueryBreaks PTR
ENDS

#DEFINE GUID_IID_IDisplayServices <0x3050f69d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IDisplayServices STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateDisplayPointer PTR
	TransformRect PTR
	TransformPoint PTR
	GetCaret PTR
	GetComputedStyle PTR
	ScrollRectIntoView PTR
	HasFlowLayout PTR
ENDS

#DEFINE GUID_IID_IHtmlDlgSafeHelper <0x3050f81a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHtmlDlgSafeHelper STRUCT
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
	choosecolordlg PTR
	getCharset PTR
	get_Fonts PTR
	get_BlockFormats PTR
ENDS

#DEFINE GUID_IID_IBlockFormats <0x3050f830,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IBlockFormats STRUCT
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
	get__NewEnum PTR
	get_Count PTR
	Item PTR
ENDS

#DEFINE GUID_IID_IFontNames <0x3050f839,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IFontNames STRUCT
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
	get__NewEnum PTR
	get_Count PTR
	Item PTR
ENDS

#DEFINE GUID_IID_ICSSFilter <0x3050f3ec,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

ICSSFilter STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetSite PTR
	OnAmbientPropertyChange PTR
ENDS

#DEFINE GUID_IID_ISecureUrlHost <0xc81984c4,0x74c8,0x11d2,<0xba,0xa9,0x00,0xc0,0x4f,0xc2,0x04,0x0e>>

ISecureUrlHost STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ValidateSecureUrl PTR
ENDS

#DEFINE GUID_IID_IMarkupServices <0x3050f4a0,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IMarkupServices STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateMarkupPointer PTR
	CreateMarkupContainer PTR
	CreateElement PTR
	CloneElement PTR
	InsertElement PTR
	RemoveElement PTR
	Remove PTR
	Copy PTR
	Move PTR
	InsertText PTR
	ParseString PTR
	ParseGlobal PTR
	IsScopedElement PTR
	GetElementTagId PTR
	GetTagIDForName PTR
	GetNameForTagID PTR
	MovePointersToRange PTR
	MoveRangeToPointers PTR
	BeginUndoUnit PTR
	EndUndoUnit PTR
ENDS

#DEFINE GUID_IID_IMarkupServices2 <0x3050f682,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IMarkupServices2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CreateMarkupPointer PTR
	CreateMarkupContainer PTR
	CreateElement PTR
	CloneElement PTR
	InsertElement PTR
	RemoveElement PTR
	Remove PTR
	Copy PTR
	Move PTR
	InsertText PTR
	ParseString PTR
	ParseGlobal PTR
	IsScopedElement PTR
	GetElementTagId PTR
	GetTagIDForName PTR
	GetNameForTagID PTR
	MovePointersToRange PTR
	MoveRangeToPointers PTR
	BeginUndoUnit PTR
	EndUndoUnit PTR
	ParseGlobalEx PTR
	ValidateElements PTR
	SaveSegmentsToClipboard PTR
ENDS

#DEFINE GUID_IID_IHTMLChangePlayback <0x3050f6e0,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLChangePlayback STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	ExecChange PTR
ENDS

#DEFINE GUID_IID_IMarkupPointer2 <0x3050f675,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IMarkupPointer2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OwningDoc PTR
	Gravity PTR
	SetGravity PTR
	Cling PTR
	SetCling PTR
	Unposition PTR
	IsPositioned PTR
	GetContainer PTR
	MoveAdjacentToElement PTR
	MoveToPointer PTR
	MoveToContainer PTR
	Left PTR
	Right PTR
	CurrentScope PTR
	IsLeftOf PTR
	IsLeftOfOrEqualTo PTR
	IsRightOf PTR
	IsRightOfOrEqualTo PTR
	IsEqualTo PTR
	MoveUnit PTR
	FindText PTR
	IsAtWordBreak PTR
	GetMarkupPosition PTR
	MoveToMarkupPosition PTR
	MoveUnitBounded PTR
	IsInsideURL PTR
	MoveToContent PTR
ENDS

#DEFINE GUID_IID_IMarkupTextFrags <0x3050f5fa,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IMarkupTextFrags STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetTextFragCount PTR
	GetTextFrag PTR
	RemoveTextFrag PTR
	InsertTextFrag PTR
	FindTextFragFromMarkupPointer PTR
ENDS

#DEFINE GUID_IID_IXMLGenericParse <0xE4E23071,0x4D07,0x11d2,<0xAE,0x76,0x00,0x80,0xC7,0x3B,0xC1,0x99>>

IXMLGenericParse STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetGenericParse PTR
ENDS

#DEFINE GUID_IID_IHTMLEditHost <0x3050f6a0,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLEditHost STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SnapRect PTR
ENDS

#DEFINE GUID_IID_IHTMLEditHost2 <0x3050f848,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0d>>

IHTMLEditHost2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SnapRect PTR
	PreDrag PTR
ENDS

#DEFINE GUID_IID_ISequenceNumber <0x3050f6c1,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

ISequenceNumber STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetSequenceNumber PTR
ENDS

#DEFINE GUID_IID_IIMEServices <0x3050f6ca,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IIMEServices STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetActiveIMM PTR
ENDS

#DEFINE GUID_IID_ISelectionServicesListener <0x3050f699,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

ISelectionServicesListener STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	BeginSelectionUndo PTR
	EndSelectionUndo PTR
	OnSelectedElementExit PTR
	OnChangeType PTR
	GetTypeDetail PTR
ENDS

#DEFINE GUID_IID_ISelectionServices <0x3050f684,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

ISelectionServices STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	SetSelectionType PTR
	GetMarkupContainer PTR
	AddSegment PTR
	AddElementSegment PTR
	RemoveSegment PTR
	GetSelectionServicesListener PTR
ENDS

#DEFINE GUID_IID_IHTMLEditDesigner <0x3050f662,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLEditDesigner STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	PreHandleEvent PTR
	PostHandleEvent PTR
	TranslateAccelerator PTR
	PostEditorEventNotify PTR
ENDS

#DEFINE GUID_IID_IHTMLEditServices <0x3050f663,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLEditServices STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddDesigner PTR
	RemoveDesigner PTR
	GetSelectionServices PTR
	MoveToSelectionAnchor PTR
	MoveToSelectionEnd PTR
	SelectRange PTR
ENDS

#DEFINE GUID_IID_IHTMLEditServices2 <0x3050f812,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLEditServices2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddDesigner PTR
	RemoveDesigner PTR
	GetSelectionServices PTR
	MoveToSelectionAnchor PTR
	MoveToSelectionEnd PTR
	SelectRange PTR
	MoveToSelectionAnchorEx PTR
	MoveToSelectionEndEx PTR
	FreezeVirtualCaretPos PTR
	UnFreezeVirtualCaretPos PTR
ENDS

#DEFINE GUID_IID_IHTMLComputedStyle <0x3050f6c3,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLComputedStyle STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	get_bold PTR
	get_italic PTR
	get_underline PTR
	get_overline PTR
	get_strikeOut PTR
	get_subScript PTR
	get_superScript PTR
	get_explicitFace PTR
	get_fontWeight PTR
	get_fontSize PTR
	get_fontName PTR
	get_hasBgColor PTR
	get_textColor PTR
	get_backgroundColor PTR
	get_preFormatted PTR
	get_direction PTR
	get_blockDirection PTR
	get_OL PTR
	IsEqual PTR
ENDS

#DEFINE GUID_CLSID_HtmlDlgSafeHelper <0x3050f819,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_CLSID_BlockFormats <0x3050f831,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_CLSID_FontNames <0x3050f83a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_HTMLNamespaceEvents <0x3050f6bd,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define HTMLNamespaceEvents STANDARD_DISPATCH

#DEFINE GUID_IID_IHTMLNamespace <0x3050f6bb,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLNamespace STRUCT
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
	get_name PTR
	get_urn PTR
	get_tagNames PTR
	get_readyState PTR
	put_onreadystatechange PTR
	get_onreadystatechange PTR
	doImport PTR
	attachEvent PTR
	detachEvent PTR
ENDS

#DEFINE GUID_IID_IHTMLNamespaceCollection <0x3050f6b8,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLNamespaceCollection STRUCT
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
	get_length PTR
	item PTR
	add PTR
ENDS

#DEFINE GUID_CLSID_HTMLNamespace <0x3050f6bc,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_CLSID_HTMLNamespaceCollection <0x3050f6b9,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLPainter <0x3050f6a6,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLPainter STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Draw PTR
	OnResize PTR
	GetPainterInfo PTR
	HitTestPoint PTR
ENDS

#DEFINE GUID_IID_IHTMLPaintSite <0x3050f6a7,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLPaintSite STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	InvalidatePainterInfo PTR
	InvalidateRect PTR
	InvalidateRegion PTR
	GetDrawInfo PTR
	TransformGlobalToLocal PTR
	TransformLocalToGlobal PTR
	GetHitTestCookie PTR
ENDS

#DEFINE GUID_IID_IHTMLPainterEventInfo <0x3050f6df,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLPainterEventInfo STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetEventInfoFlags PTR
	GetEventTarget PTR
	SetCursor PTR
	StringFromPartID PTR
ENDS

#DEFINE GUID_IID_IHTMLPainterOverlay <0x3050f7e3,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLPainterOverlay STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	OnMove PTR
ENDS

#DEFINE GUID_IID_IHTMLIPrintCollection <0x3050f6b5,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLIPrintCollection STRUCT
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
	get_length PTR
	get__newEnum PTR
	item PTR
ENDS

#DEFINE GUID_IID_IEnumPrivacyRecords <0x3050f844,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IEnumPrivacyRecords STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Reset PTR
	GetSize PTR
	GetPrivacyImpacted PTR
	Next PTR
ENDS

#DEFINE GUID_IID_IWPCBlockedUrls <0x30510413,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IWPCBlockedUrls STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCount PTR
	GetUrl PTR
ENDS

#DEFINE GUID_IID_IHTMLDialog <0x3050f216,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDialog STRUCT
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
	put_dialogTop PTR
	get_dialogTop PTR
	put_dialogLeft PTR
	get_dialogLeft PTR
	put_dialogWidth PTR
	get_dialogWidth PTR
	put_dialogHeight PTR
	get_dialogHeight PTR
	get_dialogArguments PTR
	get_menuArguments PTR
	put_returnValue PTR
	get_returnValue PTR
	close PTR
	toString PTR
ENDS

#DEFINE GUID_IID_IHTMLDialog2 <0x3050f5e0,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDialog2 STRUCT
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
	put_status PTR
	get_status PTR
	put_resizable PTR
	get_resizable PTR
ENDS

#DEFINE GUID_IID_IHTMLDialog3 <0x3050f388,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLDialog3 STRUCT
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
	put_unadorned PTR
	get_unadorned PTR
	put_dialogHide PTR
	get_dialogHide PTR
ENDS

#DEFINE GUID_IID_IHTMLModelessInit <0x3050f5e4,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLModelessInit STRUCT
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
	get_parameters PTR
	get_optionString PTR
	get_moniker PTR
	get_document PTR
ENDS

#DEFINE GUID_CLSID_ThreadDialogProcParam <0x3050f5eb,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_CLSID_HTMLDialog <0x3050f28a,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLPopup <0x3050f666,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLPopup STRUCT
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
	show PTR
	hide PTR
	get_document PTR
	get_isOpen PTR
ENDS

#DEFINE GUID_DIID_DispHTMLPopup <0x3050f589,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLPopup STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLPopup <0x3050f667,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IHTMLAppBehavior <0x3050f5ca,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLAppBehavior STRUCT
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
	put_applicationName PTR
	get_applicationName PTR
	put_version PTR
	get_version PTR
	put_icon PTR
	get_icon PTR
	put_singleInstance PTR
	get_singleInstance PTR
	put_minimizeButton PTR
	get_minimizeButton PTR
	put_maximizeButton PTR
	get_maximizeButton PTR
	put_border PTR
	get_border PTR
	put_borderStyle PTR
	get_borderStyle PTR
	put_sysMenu PTR
	get_sysMenu PTR
	put_caption PTR
	get_caption PTR
	put_windowState PTR
	get_windowState PTR
	put_showInTaskBar PTR
	get_showInTaskBar PTR
	get_commandLine PTR
ENDS

#DEFINE GUID_IID_IHTMLAppBehavior2 <0x3050f5c9,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLAppBehavior2 STRUCT
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
	put_contextMenu PTR
	get_contextMenu PTR
	put_innerBorder PTR
	get_innerBorder PTR
	put_scroll PTR
	get_scroll PTR
	put_scrollFlat PTR
	get_scrollFlat PTR
	put_selection PTR
	get_selection PTR
ENDS

#DEFINE GUID_IID_IHTMLAppBehavior3 <0x3050f5cd,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHTMLAppBehavior3 STRUCT
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
	put_navigable PTR
	get_navigable PTR
ENDS

#DEFINE GUID_DIID_DispHTMLAppBehavior <0x3050f57c,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispHTMLAppBehavior STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLAppBehavior <0x3050f5cb,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>
#DEFINE GUID_CLSID_OldHTMLDocument <0xD48A6EC9,0x6A4A,0x11CF,<0x94,0xA7,0x44,0x45,0x53,0x54,0x00,0x00>>
#DEFINE GUID_CLSID_OldHTMLFormElement <0x0D04D285,0x6BEC,0x11CF,<0x8B,0x97,0x00,0xAA,0x00,0x47,0x6D,0xA6>>

#DEFINE GUID_DIID_DispIHTMLInputButtonElement <0x3050f51e,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispIHTMLInputButtonElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLInputButtonElement <0x3050f2b4,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispIHTMLInputTextElement <0x3050f520,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispIHTMLInputTextElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLInputTextElement <0x3050f2ab,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispIHTMLInputFileElement <0x3050f542,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispIHTMLInputFileElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLInputFileElement <0x3050f2ae,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispIHTMLOptionButtonElement <0x3050f509,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispIHTMLOptionButtonElement STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLOptionButtonElement <0x3050f2be,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_DIID_DispIHTMLInputImage <0x3050f51d,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#define DispIHTMLInputImage STANDARD_DISPATCH

#DEFINE GUID_CLSID_HTMLInputImage <0x3050f2c4,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

#DEFINE GUID_IID_IElementNamespace <0x3050f671,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementNamespace STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddTag PTR
ENDS

#DEFINE GUID_IID_IElementNamespaceTable <0x3050f670,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementNamespaceTable STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddNamespace PTR
ENDS

#DEFINE GUID_IID_IElementNamespaceFactory <0x3050f672,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementNamespaceFactory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Create PTR
ENDS

#DEFINE GUID_IID_IElementNamespaceFactory2 <0x3050f805,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementNamespaceFactory2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Create PTR
	CreateWithImplementation PTR
ENDS

#DEFINE GUID_IID_IElementNamespaceFactoryCallback <0x3050f7fd,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementNamespaceFactoryCallback STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	Resolve PTR
ENDS

#DEFINE GUID_IID_IElementBehaviorSiteOM2 <0x3050f659,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementBehaviorSiteOM2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	RegisterEvent PTR
	GetEventCookie PTR
	FireEvent PTR
	CreateEventObject PTR
	RegisterName PTR
	RegisterUrn PTR
	GetDefaults PTR
ENDS

#DEFINE GUID_IID_IElementBehaviorCategory <0x3050f4ed,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementBehaviorCategory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetCategory PTR
ENDS

#DEFINE GUID_IID_IElementBehaviorSiteCategory <0x3050f4ee,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementBehaviorSiteCategory STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetRelatedBehaviors PTR
ENDS

#DEFINE GUID_IID_IElementBehaviorSubmit <0x3050f646,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementBehaviorSubmit STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetSubmitInfo PTR
	Reset PTR
ENDS

#DEFINE GUID_IID_IElementBehaviorFocus <0x3050f6b6,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementBehaviorFocus STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetFocusRect PTR
ENDS

#DEFINE GUID_IID_IElementBehaviorLayout <0x3050f6ba,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementBehaviorLayout STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetSize PTR
	GetLayoutInfo PTR
	GetPosition PTR
	MapSize PTR
ENDS

#DEFINE GUID_IID_IElementBehaviorLayout2 <0x3050f846,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementBehaviorLayout2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetTextDescent PTR
ENDS

#DEFINE GUID_IID_IElementBehaviorSiteLayout <0x3050f6b7,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementBehaviorSiteLayout STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	InvalidateLayoutInfo PTR
	InvalidateSize PTR
	GetMediaResolution PTR
ENDS

#DEFINE GUID_IID_IElementBehaviorSiteLayout2 <0x3050f847,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IElementBehaviorSiteLayout2 STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	GetFontInfo PTR
ENDS

#DEFINE GUID_IID_IHostBehaviorInit <0x3050f842,0x98b5,0x11cf,<0xbb,0x82,0x00,0xaa,0x00,0xbd,0xce,0x0b>>

IHostBehaviorInit STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	PopulateNamespaceTable PTR
ENDS

#endif





