#ifndef GDIPLUSPIXELFORMATS_H
#define GDIPLUSPIXELFORMATS_H

ALPHA_SHIFT	EQU	24
RED_SHIFT	EQU	16
GREEN_SHIFT	EQU	8
BLUE_SHIFT	EQU	0
ALPHA_MASK	EQU	0ff000000h 

PixelFormatIndexed	EQU	00010000h
PixelFormatGDI	EQU	00020000h
PixelFormatAlpha	EQU	00040000h
PixelFormatPAlpha	EQU	00080000h
PixelFormatExtended	EQU	00100000h
PixelFormatCanonical	EQU	00200000h
PixelFormatUndefined	EQU	0
PixelFormatDontCare	EQU	0

PixelFormat1bppIndexed	EQU	1  | 256 | PixelFormatIndexed | PixelFormatGDI
PixelFormat4bppIndexed	EQU	2  | 1024 | PixelFormatIndexed | PixelFormatGDI
PixelFormat8bppIndexed	EQU	3 | 2048 | PixelFormatIndexed | PixelFormatGDI
PixelFormat16bppGrayScale	EQU	4 | 4096 | PixelFormatExtended
PixelFormat16bppRGB555	EQU	5 | 4096 | PixelFormatGDI
PixelFormat16bppRGB565	EQU	6 | 4096 | PixelFormatGDI
PixelFormat16bppARGB1555	EQU	7 | 4096 | PixelFormatAlpha | PixelFormatGDI
PixelFormat24bppRGB	EQU	8 | 6144 | PixelFormatGDI
PixelFormat32bppRGB	EQU	9 | 8192 | PixelFormatGDI
PixelFormat32bppARGB	EQU	10 | 8192 | PixelFormatAlpha | PixelFormatGDI | PixelFormatCanonical
PixelFormat32bppPARGB	EQU	11 | 8192 | PixelFormatAlpha | PixelFormatPAlpha | PixelFormatGDI
PixelFormat48bppRGB	EQU	12 | 12288 | PixelFormatExtended
PixelFormat64bppARGB	EQU	13 | 16384 | PixelFormatAlpha | PixelFormatCanonical | PixelFormatExtended
PixelFormat64bppPARGB	EQU	14 | 16384 | PixelFormatAlpha | PixelFormatPAlpha | PixelFormatExtended
PixelFormatMax	EQU	15

PaletteTypeCustom = 0
PaletteTypeOptimal = 1
PaletteTypeFixedBW = 2
PaletteTypeFixedHalftone8 = 3
PaletteTypeFixedHalftone27 = 4
PaletteTypeFixedHalftone64 = 5
PaletteTypeFixedHalftone125 = 6
PaletteTypeFixedHalftone216 = 7
PaletteTypeFixedHalftone252 = 8
PaletteTypeFixedHalftone256 = 9

Size_PaletteTypeFixedBW = 2
Size_PaletteTypeFixedHalftone8 = 16
Size_PaletteTypeFixedHalftone27 = 36
Size_PaletteTypeFixedHalftone64 = 73
Size_PaletteTypeFixedHalftone125 = 134
Size_PaletteTypeFixedHalftone216 = 225
Size_PaletteTypeFixedHalftone252 = 253
Size_PaletteTypeFixedHalftone256 = 256

PaletteFlagsHasAlpha = 0001h 
PaletteFlagsGrayScale = 0002h 
PaletteFlagsHalftone = 0004h 

ColorPalette	struct 
	Flags	DD
	Count	DD
	Entries	DD 1 dup (?)
ENDS

#endif 
