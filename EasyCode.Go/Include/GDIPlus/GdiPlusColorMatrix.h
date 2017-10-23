/*
 * GdiPlusColorMatrix.h
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

#ifndef GDIPLUSCOLORMATRIX_H
#define GDIPLUSCOLORMATRIX_H

ColorMap struct
	oldColor DD
	newColor DD
ENDS

ColorMatrix STRUCT
	m DD 25 DUP
ENDS

//ColorAdjustType enum
ColorAdjustTypeDefault = 0
ColorAdjustTypeBitmap = 1
ColorAdjustTypeBrush = 2
ColorAdjustTypePen = 3
ColorAdjustTypeText = 4
ColorAdjustTypeCount = 5
ColorAdjustTypeAny = 6

//ColorMatrixFlags enum
ColorMatrixFlagsDefault = 0
ColorMatrixFlagsSkipGrays = 1
ColorMatrixFlagsAltGray = 2

#endif /* GDIPLUSCOLORMATRIX_H */
