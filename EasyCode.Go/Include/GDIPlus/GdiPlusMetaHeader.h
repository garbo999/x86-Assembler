/*
 * GdiPlusMetaHeader.h
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

#ifndef GDIPLUSMETAHEADER_H
#define GDIPLUSMETAHEADER_H

#define GDIP_EMFPLUSFLAGS_DISPLAY 00000001h

ENHMETAHEADER3 struct
	iType DD
	nSize DD
	rclBounds RECTL <>
	rclFrame RECTL <>
	dSignature DD
	nVersion DD
	nBytes DD
	nRecords DD
	nHandles DW
	sReserved DW
	nDescription DD
	offDescription DD
	nPalEntries DD
	szlDevice SIZEL <>
	szlMillimeters SIZEL <>
ENDS

PWMFRect16 struct
	Left DW
	Top DW
	Right DW
	Bottom DW
ENDS

WmfPlaceableFileHeader struct
	Key DD
	Hmf DW
	BoundingBox PWMFRect16
	Inch DW
	Reserved DD
	Checksum DW
ENDS

// There are 3 conflicting definitions I have found for this structure
// I have included 2 of them though 1 is commented out

/*
// From http://www.koders.com/cpp/fid1C9F81D274CAFAB276DDC58E1DDB06FE66903ADE.aspx
MetafileHeader STRUCT
	DpiX DD
	DpiY DD
	EmfPlusFlags DD
	EmfPlusHeaderSize DD
	Height DD
	LogicalDpiX DD
	LogicalDpiY DD
	Type DD
	Version DD
	Width DD
	X DD
	Y DD
	UNION
		WmfHeader METAHEADER <>
		EmfHeader ENHMETAHEADER3 <>
	ENDUNION
ENDS
*/

// From PSDK header
MetafileHeader	struct
	Type	DD
	Size	DD
	Version	DD
	EmfPlusFlags	DD
	DpiX	DD
	DpiY	DD
	X	DD
	Y	DD
	Width	DD
	Height	DD
	UNION
		WmfHeader	METAHEADER
		EmfHeader	ENHMETAHEADER3
	ENDUNION
	EmfPlusHeaderSize	DD
	LogicalDpiX	DD
	LogicalDpiY	DD
ENDS

#endif /* _GDIPLUSMETAHEADER_H */
