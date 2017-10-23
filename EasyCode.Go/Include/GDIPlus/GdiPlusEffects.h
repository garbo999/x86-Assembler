/*
 * GdiPlusEffects.h
 *
 * Windows GDI+
 *
 * This file is part of the w32api package.
 *
 * THIS SOFTWARE IS NOT COPYRIGHTED
 *
 * This source code is offered for use in the public domain. You may
 * use, modify or distribute it freely.
 *
 * This code is distributed in the hope that it will be useful but
 * WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 * DISCLAIMED. This includes but is not limited to warranties of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef GDIPLUSEFFECTS_H
#define GDIPLUSEFFECTS_H

#define GUID_BlurEffectGuid <0x633c80a4, 0x1843, 0x482b, <0x9e, 0xf2, 0xbe, 0x28, 0x34, 0xc5, 0xfd, 0xd4>>
#define GUID_BrightnessContrastEffectGuid <0xd3a1dbe1, 0x8ec4, 0x4c17, <0x9f, 0x4c, 0xea, 0x97, 0xad, 0x1c, 0x34, 0x3d>>
#define GUID_ColorBalanceEffectGuid <0x537e597d, 0x251e, 0x48da, <0x96, 0x64, 0x29, 0xca, 0x49, 0x6b, 0x70, 0xf8>>
#define GUID_ColorCurveEffectGuid <0xdd6a0022, 0x58e4, 0x4a67, <0x9d, 0x9b, 0xd4, 0x8e, 0xb8, 0x81, 0xa5, 0x3d>>
#define GUID_ColorLookupTableEffectGuid <0xa7ce72a9, 0xf7f, 0x40d7, <0xb3, 0xcc, 0xd0, 0xc0, 0x2d, 0x5c, 0x32, 0x12>>
#define GUID_ColorMatrixEffectGuid <0x718f2615, 0x7933, 0x40e3, <0xa5, 0x11, 0x5f, 0x68, 0xfe, 0x14, 0xdd, 0x74>>
#define GUID_HueSaturationLightnessEffectGuid <0x8b2dd6c3, 0xeb07, 0x4d87, <0xa5, 0xf0, 0x71, 0x8, 0xe2, 0x6a, 0x9c, 0x5f>>
#define GUID_LevelsEffectGuid <0x99c354ec, 0x2a31, 0x4f3a, <0x8c, 0x34, 0x17, 0xa8, 0x3, 0xb3, 0x3a, 0x25>>
#define GUID_RedEyeCorrectionEffectGuid <0x74d29d05, 0x69a4, 0x4266, <0x95, 0x49, 0x3c, 0xc5, 0x28, 0x36, 0xb6, 0x32>>
#define GUID_SharpenEffectGuid <0x63cbf3ee, 0xc526, 0x402c, <0x8f, 0x71, 0x62, 0xc5, 0x40, 0xbf, 0x51, 0x42>>
#define GUID_TintEffectGuid <0x1077af00, 0x2848, 0x4441, <0x94, 0x89, 0x44, 0xad, 0x4c, 0x2d, 0x7a, 0x2c>>

// CurveAdjustments
AdjustExposure = 0
AdjustDensity = 1
AdjustContrast = 2
AdjustHighlight = 3
AdjustShadow = 4
AdjustMidtone = 5
AdjustWhiteSaturation = 6
AdjustBlackSaturation = 7

// CurveChannel
CurveChannelAll = 0
CurveChannelRed = 1
CurveChannelGreen = 2
CurveChannelBlue = 3


BlurParams struct
	radius FLOAT
	expandEdge DD
ENDS

BrightnessContrastParams struct
	brightnessLevel DD
	contrastLevel DD
ENDS

ColorLUTParams STRUCT
	lutB DB 256 DUP
	lutG DB 256 DUP
	lutR DB 256 DUP
	lutA DB 256 DUP
ENDS

ColorBalanceParams struct
	cyanRed DD
	magentaGreen DD
	yellowBlue DD
ENDS

ColorCurveParams struct
	adjustment DD
	channel DD
	adjustValue DD
ENDS

HueSaturationLightnessParams struct
	hueLevel DD
	saturationLevel DD
	lightnessLevel DD
ENDS

LevelsParams struct
	highlight DD
	midtone DD
	shadow DD
ENDS

RedEyeCorrectionParams struct
	numberOfAreas DD
	areas PTR
ENDS

SharpenParams struct
	radius FLOAT
	amount FLOAT
ENDS

TintParams struct
	hue DD
	amount DD
ENDS

#endif
