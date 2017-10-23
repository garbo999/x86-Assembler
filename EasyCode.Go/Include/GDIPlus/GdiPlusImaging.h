/**************************************************************************\
* 
* Copyright (c) 1999-2000  Microsoft Corporation
*
* Module Name:
*
*   GdiplusImaging.h
*
* Abstract:
*
*   GUIDs defined and used by the imaging library
*
\**************************************************************************/


#ifndef GDIPLUSIMAGING_H
#define GDIPLUSIMAGING_H

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

//---------------------------------------------------------------------------
// Image file format identifiers
//---------------------------------------------------------------------------

#define GUID_ImageEncoderBMP <0x557cf400, 0x1a04, 0x11d3, <0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e>>
#define GUID_ImageEncoderJPEG <0x557cf401, 0x1a04, 0x11d3, <0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e>>
#define GUID_ImageEncoderGIF <0x557cf402, 0x1a04, 0x11d3, <0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e>>
#define GUID_ImageEncoderEMF <0x557cf403, 0x1a04, 0x11d3, <0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e>>
#define GUID_ImageEncoderWMF <0x557cf404, 0x1a04, 0x11d3, <0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e>>
#define GUID_ImageEncoderTIFF <0x557cf405, 0x1a04, 0x11d3, <0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e>>
#define GUID_ImageEncoderPNG <0x557cf406, 0x1a04, 0x11d3, <0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e>>
#define GUID_ImageEncoderICON <0x557cf407, 0x1a04, 0x11d3, <0x9a, 0x73, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e>>

#define GUID_ImageFormatUndefined <0b96b3ca9h , 0728h , 11d3h , <9dh , 7bh , 00h , 00h , 0f8h , 1eh , 0f3h , 2eh>>
#define GUID_ImageFormatMemoryBMP <0b96b3caah , 0728h , 11d3h , <9dh , 7bh , 00h , 00h , 0f8h , 1eh , 0f3h , 2eh>>
#define GUID_ImageFormatBMP <0b96b3cabh , 0728h , 11d3h , <9dh , 7bh , 00h , 00h , 0f8h , 1eh , 0f3h , 2eh>>
#define GUID_ImageFormatEMF <0b96b3cach , 0728h , 11d3h , <9dh , 7bh , 00h , 00h , 0f8h , 1eh , 0f3h , 2eh>>
#define GUID_ImageFormatWMF <0b96b3cadh , 0728h , 11d3h , <9dh , 7bh , 00h , 00h , 0f8h , 1eh , 0f3h , 2eh>>
#define GUID_ImageFormatJPEG <0b96b3caeh , 0728h , 11d3h , <9dh , 7bh , 00h , 00h , 0f8h , 1eh , 0f3h , 2eh>>
#define GUID_ImageFormatPNG <0xb96b3caf,0x0728,0x11d3,<0x9d,0x7b,0x00,0x00,0xf8,0x1e,0xf3,0x2e>>
#define GUID_ImageFormatGIF <0b96b3cb0h , 0728h , 11d3h , <9dh , 7bh , 00h , 00h , 0f8h , 1eh , 0f3h , 2eh>>
#define GUID_ImageFormatTIFF <0b96b3cb1h , 0728h , 11d3h , <9dh , 7bh , 00h , 00h , 0f8h , 1eh , 0f3h , 2eh>>
#define GUID_ImageFormatEXIF <0b96b3cb2h , 0728h , 11d3h , <9dh , 7bh , 00h , 00h , 0f8h , 1eh , 0f3h , 2eh>>
#ifndef DCR_USE_NEW_140855
	#define GUID_ImageFormatPhotoCD <0xb96b3cb3,0x0728,0x11d3,<0x9d,0x7b,0x00,0x00,0xf8,0x1e,0xf3,0x2e>>
	#define GUID_ImageFormatFlashPIX <0xb96b3cb4,0x0728,0x11d3,<0x9d,0x7b,0x00,0x00,0xf8,0x1e,0xf3,0x2e>>
#endif
#define GUID_ImageFormatIcon <0b96b3cb5h , 0728h , 11d3h , <9dh , 7bh , 00h , 00h , 0f8h , 1eh , 0f3h , 2eh>>

//---------------------------------------------------------------------------
// Predefined multi-frame dimension IDs
//---------------------------------------------------------------------------

#define GUID_FrameDimensionTime <6aedbd6dh , 3fb5h , 418ah , <83h , 0a6h , 7fh , 45h , 22h , 9dh , 0c8h , 72h>>
#define GUID_FrameDimensionResolution <84236f7bh , 3bd3h , 428fh , <8dh , 0abh , 4eh , 0a1h , 43h , 9ch , 0a3h , 15h>>
#define GUID_FrameDimensionPage <7462dc86h , 6180h , 4c7eh , <8eh , 3fh , 0eeh , 73h , 33h , 0a7h , 0a4h , 83h>>

//---------------------------------------------------------------------------
// Property sets
//---------------------------------------------------------------------------

#define GUID_FormatIDImageInformation <0e5836cbeh , 5eefh , 4f1dh , <0ach , 0deh , 0aeh , 4ch , 43h , 0b6h , 08h , 0ceh>>
#define GUID_FormatIDJpegAppHeaders <1c4afdcdh , 6177h , 43cfh , <0abh , 0c7h , 5fh , 51h , 0afh , 39h , 0eeh , 85h>>

#ifndef DCR_USE_NEW_140855
	//---------------------------------------------------------------------------
	// Decoder parameter sets
	//---------------------------------------------------------------------------
	#define GUID_DecoderTransColor <0xb7a98c8f,0xdce7,0x457d,<0xbf,0xa5,0xce,0xa7,0x1b,0xd1,0x4d,0xd6>>
	#define GUID_DecoderTransRange <0xabeed189,0xd988,0x4d03,<0xb4,0x25,0x57,0x10,0x55,0xc7,0x6a,0xd1>>
	#define GUID_DecoderOutputChannel <0x2ff8f51e,0x724d,0x45fe,<0x86,0xce,0x17,0x77,0xa0,0x56,0xda,0x60>>
	#define GUID_DecoderIconRes <0x5c656eec,0xe94f,0x45ba,<0xa6,0xf6,0x10,0x62,0xe8,0x5f,0x4a,0x7f>>
#endif

//---------------------------------------------------------------------------
// Encoder parameter sets
//---------------------------------------------------------------------------

#define GUID_EncoderCompression <0e09d739dh , 0ccd4h , 44eeh , <8eh , 0bah , 3fh , 0bfh , 8bh , 0e4h , 0fch , 58h>>
#define GUID_EncoderColorDepth <66087055h , 0ad66h , 4c7ch , <9ah , 18h , 38h , 0a2h , 31h , 0bh , 83h , 37h>>
#define GUID_EncoderScanMethod <3a4e2661h , 3109h , 4e56h , <85h , 36h , 42h , 0c1h , 56h , 0e7h , 0dch , 0fah>>
#define GUID_EncoderVersion <24d18c76h , 814ah , 41a4h , <0bfh , 53h , 1ch , 21h , 9ch , 0cch , 0f7h , 97h>>
#define GUID_EncoderRenderMethod <6d42c53ah , 229ah , 4825h , <8bh , 0b7h , 5ch , 99h , 0e2h , 0b9h , 0a8h , 0b8h>>
#define GUID_EncoderQuality <1d5be4b5h , 0fa4ah , 452dh , <9ch , 0ddh , 5dh , 0b3h , 51h , 05h , 0e7h , 0ebh>>
#define GUID_EncoderTransformation <8d0eb2d1h , 0a58eh , 4ea8h , <0aah , 14h , 10h , 80h , 74h , 0b7h , 0b6h , 0f9h>>
#define GUID_EncoderLuminanceTable <0edb33bceh , 0266h , 4a77h , <0b9h , 04h , 27h , 21h , 60h , 99h , 0e7h , 17h>>
#define GUID_EncoderChrominanceTable <0f2e455dch , 09b3h , 4316h , <82h , 60h , 67h , 6ah , 0dah , 32h , 48h , 1ch>>
#define GUID_EncoderSaveFlag <292266fch , 0ac40h , 47bfh , <8ch , 0fch , 0a8h , 5bh , 89h , 0a6h , 55h , 0deh>>

#define GUID_CodecIImageBytes <025d1823h , 6c7dh , 447bh , <0bbh , 0dbh , 0a3h , 0cbh , 0c3h , 0dfh , 0a2h , 0fch>>

IImageBytes struct 
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	CountBytes 	PTR
	LockBytes 	PTR
	UnlockBytes PTR
ENDS

ImageCodecInfo struct 
	Clsid			GUID	<>
	FormatID		GUID	<>
	CodecName		PTR
	DllName			PTR
	FormatDescription	PTR
	FilenameExtension	PTR
	MimeType		PTR
	Flags			DD
	Version			DD
	SigCount		DD
	SigSize			DD
	SigPattern		PTR
	SigMask			PTR
ENDS

ImageCodecFlagsEncoder = 00000001h 
ImageCodecFlagsDecoder = 00000002h 
ImageCodecFlagsSupportBitmap = 00000004h 
ImageCodecFlagsSupportVector = 00000008h 
ImageCodecFlagsSeekableEncode = 00000010h 
ImageCodecFlagsBlockingDecode = 00000020h 
ImageCodecFlagsBuiltin = 00010000h 
ImageCodecFlagsSystem = 00020000h 
ImageCodecFlagsUser = 00040000h 

ImageLockModeRead = 0001h 
ImageLockModeWrite = 0002h 
ImageLockModeUserInputBuf = 0004h 

BitmapData struct 
	Width		DD
	Height		DD
	Stride		DD
	PixelFormat	DD
	Scan0		PTR
	Reserved	UINT_PTR
ENDS

ImageFlagsNone = 0 
ImageFlagsScalable = 0001h 
ImageFlagsHasAlpha = 0002h 
ImageFlagsHasTranslucent = 0004h 
ImageFlagsPartiallyScalable = 0008h 
ImageFlagsColorSpaceRGB = 0010h 
ImageFlagsColorSpaceCMYK = 0020h 
ImageFlagsColorSpaceGRAY = 0040h 
ImageFlagsColorSpaceYCBCR = 0080h 
ImageFlagsColorSpaceYCCK = 0100h 
ImageFlagsHasRealDPI = 1000h 
ImageFlagsHasRealPixelSize = 2000h 
ImageFlagsReadOnly = 00010000h 
ImageFlagsCaching = 00020000h 

RotateNoneFlipNone = 0 
Rotate90FlipNone = 1 
Rotate180FlipNone = 2 
Rotate270FlipNone = 3 
RotateNoneFlipX = 4 
Rotate90FlipX = 5 
Rotate180FlipX = 6 
Rotate270FlipX = 7 
RotateNoneFlipY = Rotate180FlipX 
Rotate90FlipY = Rotate270FlipX 
Rotate180FlipY = RotateNoneFlipX 
Rotate270FlipY = Rotate90FlipX 
RotateNoneFlipXY = Rotate180FlipNone 
Rotate90FlipXY = Rotate270FlipNone 
Rotate180FlipXY = RotateNoneFlipNone 
Rotate270FlipXY = Rotate90FlipNone 

EncoderParameter struct 
	Guid	GUID	<>
	NumberOfValues	DD
	Type	DD
	Value	PTR
ENDS

EncoderParameters struct 
	Count		DD
	Parameter 	EncoderParameter 1 dup <>
ENDS

PropertyItem	struct 
	id	DD
	length	DD
	type	DW
	value	PTR
ENDS

#define PropertyTagTypeByte	1
#define PropertyTagTypeASCII	2
#define PropertyTagTypeShort	3
#define PropertyTagTypeLong	4
#define PropertyTagTypeRational	5
#define PropertyTagTypeUndefined	7
#define PropertyTagTypeSLONG	9
#define PropertyTagTypeSRational	10
#define PropertyTagExifIFD	8769h
#define PropertyTagGpsIFD	8825h
#define PropertyTagNewSubfileType	00FEh
#define PropertyTagSubfileType	00FFh
#define PropertyTagImageWidth	0100h
#define PropertyTagImageHeight	0101h
#define PropertyTagBitsPerSample	0102h
#define PropertyTagCompression	0103h
#define PropertyTagPhotometricInterp	0106h
#define PropertyTagThreshHolding	0107h
#define PropertyTagCellWidth	0108h
#define PropertyTagCellHeight	0109h
#define PropertyTagFillOrder	010Ah
#define PropertyTagDocumentName	010Dh
#define PropertyTagImageDescription	010Eh
#define PropertyTagEquipMake	010Fh
#define PropertyTagEquipModel	0110h
#define PropertyTagStripOffsets	0111h
#define PropertyTagOrientation	0112h
#define PropertyTagSamplesPerPixel	0115h
#define PropertyTagRowsPerStrip	0116h
#define PropertyTagStripBytesCount	0117h
#define PropertyTagMinSampleValue	0118h
#define PropertyTagMaxSampleValue	0119h
#define PropertyTagXResolution	011Ah
#define PropertyTagYResolution	011Bh
#define PropertyTagPlanarConfig	011Ch
#define PropertyTagPageName	011Dh
#define PropertyTagXPosition	011Eh
#define PropertyTagYPosition	011Fh
#define PropertyTagFreeOffset	0120h
#define PropertyTagFreeByteCounts	0121h
#define PropertyTagGrayResponseUnit	0122h
#define PropertyTagGrayResponseCurve	0123h
#define PropertyTagT4Option	0124h
#define PropertyTagT6Option	0125h
#define PropertyTagResolutionUnit	0128h
#define PropertyTagPageNumber	0129h
#define PropertyTagTransferFuncition	012Dh
#define PropertyTagSoftwareUsed	0131h
#define PropertyTagDateTime	0132h
#define PropertyTagArtist	013Bh
#define PropertyTagHostComputer	013Ch
#define PropertyTagPredictor	013Dh
#define PropertyTagWhitePoint	013Eh
#define PropertyTagPrimaryChromaticities	013Fh
#define PropertyTagColorMap	0140h
#define PropertyTagHalftoneHints	0141h
#define PropertyTagTileWidth	0142h
#define PropertyTagTileLength	0143h
#define PropertyTagTileOffset	0144h
#define PropertyTagTileByteCounts	0145h
#define PropertyTagInkSet	014Ch
#define PropertyTagInkNames	014Dh
#define PropertyTagNumberOfInks	014Eh
#define PropertyTagDotRange	0150h
#define PropertyTagTargetPrinter	0151h
#define PropertyTagExtraSamples	0152h
#define PropertyTagSampleFormat	0153h
#define PropertyTagSMinSampleValue	0154h
#define PropertyTagSMaxSampleValue	0155h
#define PropertyTagTransferRange	0156h
#define PropertyTagJPEGProc	0200h
#define PropertyTagJPEGInterFormat	0201h
#define PropertyTagJPEGInterLength	0202h
#define PropertyTagJPEGRestartInterval	0203h
#define PropertyTagJPEGLosslessPredictors	0205h
#define PropertyTagJPEGPointTransforms	0206h
#define PropertyTagJPEGQTables	0207h
#define PropertyTagJPEGDCTables	0208h
#define PropertyTagJPEGACTables	0209h
#define PropertyTagYCbCrCoefficients	0211h
#define PropertyTagYCbCrSubsampling	0212h
#define PropertyTagYCbCrPositioning	0213h
#define PropertyTagREFBlackWhite	0214h
#define PropertyTagICCProfile	8773h
#define PropertyTagGamma	0301h
#define PropertyTagICCProfileDescriptor	0302h
#define PropertyTagSRGBRenderingIntent	0303h
#define PropertyTagImageTitle	0320h
#define PropertyTagCopyright	8298h
#define PropertyTagResolutionXUnit	5001h
#define PropertyTagResolutionYUnit	5002h
#define PropertyTagResolutionXLengthUnit	5003h
#define PropertyTagResolutionYLengthUnit	5004h
#define PropertyTagPrintFlags	5005h
#define PropertyTagPrintFlagsVersion	5006h
#define PropertyTagPrintFlagsCrop	5007h
#define PropertyTagPrintFlagsBleedWidth	5008h
#define PropertyTagPrintFlagsBleedWidthScale	5009h
#define PropertyTagHalftoneLPI	500Ah
#define PropertyTagHalftoneLPIUnit	500Bh
#define PropertyTagHalftoneDegree	500Ch
#define PropertyTagHalftoneShape	500Dh
#define PropertyTagHalftoneMisc	500Eh
#define PropertyTagHalftoneScreen	500Fh
#define PropertyTagJPEGQuality	5010h
#define PropertyTagGridSize	5011h
#define PropertyTagThumbnailFormat	5012h
#define PropertyTagThumbnailWidth	5013h
#define PropertyTagThumbnailHeight	5014h
#define PropertyTagThumbnailColorDepth	5015h
#define PropertyTagThumbnailPlanes	5016h
#define PropertyTagThumbnailRawBytes	5017h
#define PropertyTagThumbnailSize	5018h
#define PropertyTagThumbnailCompressedSize	5019h
#define PropertyTagColorTransferFunction	501Ah
#define PropertyTagThumbnailData	501Bh
#define PropertyTagThumbnailImageWidth	5020h
#define PropertyTagThumbnailImageHeight	5021h
#define PropertyTagThumbnailBitsPerSample	5022h
#define PropertyTagThumbnailCompression	5023h
#define PropertyTagThumbnailPhotometricInterp	5024h
#define PropertyTagThumbnailImageDescription	5025h
#define PropertyTagThumbnailEquipMake	5026h
#define PropertyTagThumbnailEquipModel	5027h
#define PropertyTagThumbnailStripOffsets	5028h
#define PropertyTagThumbnailOrientation	5029h
#define PropertyTagThumbnailSamplesPerPixel	502Ah
#define PropertyTagThumbnailRowsPerStrip	502Bh
#define PropertyTagThumbnailStripBytesCount	502Ch
#define PropertyTagThumbnailResolutionX	502Dh
#define PropertyTagThumbnailResolutionY	502Eh
#define PropertyTagThumbnailPlanarConfig	502Fh
#define PropertyTagThumbnailResolutionUnit	5030h
#define PropertyTagThumbnailTransferFunction	5031h
#define PropertyTagThumbnailSoftwareUsed	5032h
#define PropertyTagThumbnailDateTime	5033h
#define PropertyTagThumbnailArtist	5034h
#define PropertyTagThumbnailWhitePoint	5035h
#define PropertyTagThumbnailPrimaryChromaticities	5036h
#define PropertyTagThumbnailYCbCrCoefficients	5037h
#define PropertyTagThumbnailYCbCrSubsampling	5038h
#define PropertyTagThumbnailYCbCrPositioning	5039h
#define PropertyTagThumbnailRefBlackWhite	503Ah
#define PropertyTagThumbnailCopyRight	503Bh
#define PropertyTagLuminanceTable	5090h
#define PropertyTagChrominanceTable	5091h
#define PropertyTagFrameDelay	5100h
#define PropertyTagLoopCount	5101h
#define PropertyTagPixelUnit	5110h
#define PropertyTagPixelPerUnitX	5111h
#define PropertyTagPixelPerUnitY	5112h
#define PropertyTagPaletteHistogram	5113h
#define PropertyTagExifExposureTime	829Ah
#define PropertyTagExifFNumber	829Dh
#define PropertyTagExifExposureProg	8822h
#define PropertyTagExifSpectralSense	8824h
#define PropertyTagExifISOSpeed	8827h
#define PropertyTagExifOECF	8828h
#define PropertyTagExifVer	9000h
#define PropertyTagExifDTOrig	9003h
#define PropertyTagExifDTDigitized	9004h
#define PropertyTagExifCompConfig	9101h
#define PropertyTagExifCompBPP	9102h
#define PropertyTagExifShutterSpeed	9201h
#define PropertyTagExifAperture	9202h
#define PropertyTagExifBrightness	9203h
#define PropertyTagExifExposureBias	9204h
#define PropertyTagExifMaxAperture	9205h
#define PropertyTagExifSubjectDist	9206h
#define PropertyTagExifMeteringMode	9207h
#define PropertyTagExifLightSource	9208h
#define PropertyTagExifFlash	9209h
#define PropertyTagExifFocalLength	920Ah
#define PropertyTagExifMakerNote	927Ch
#define PropertyTagExifUserComment	9286h
#define PropertyTagExifDTSubsec	9290h
#define PropertyTagExifDTOrigSS	9291h
#define PropertyTagExifDTDigSS	9292h
#define PropertyTagExifFPXVer	0A000h
#define PropertyTagExifColorSpace	0A001h
#define PropertyTagExifPixXDim	0A002h
#define PropertyTagExifPixYDim	0A003h
#define PropertyTagExifRelatedWav	0A004h
#define PropertyTagExifInterop	0A005h
#define PropertyTagExifFlashEnergy	0A20Bh
#define PropertyTagExifSpatialFR	0A20Ch
#define PropertyTagExifFocalXRes	0A20Eh
#define PropertyTagExifFocalYRes	0A20Fh
#define PropertyTagExifFocalResUnit	0A210h
#define PropertyTagExifSubjectLoc	0A214h
#define PropertyTagExifExposureIndex	0A215h
#define PropertyTagExifSensingMethod	0A217h
#define PropertyTagExifFileSource	0A300h
#define PropertyTagExifSceneType	0A301h
#define PropertyTagExifCfaPattern	0A302h
#define PropertyTagGpsVer	0000h
#define PropertyTagGpsLatitudeRef	0001h
#define PropertyTagGpsLatitude	0002h
#define PropertyTagGpsLongitudeRef	0003h
#define PropertyTagGpsLongitude	0004h
#define PropertyTagGpsAltitudeRef	0005h
#define PropertyTagGpsAltitude	0006h
#define PropertyTagGpsGpsTime	0007h
#define PropertyTagGpsGpsSatellites	0008h
#define PropertyTagGpsGpsStatus	0009h
#define PropertyTagGpsGpsMeasureMode	00Ah
#define PropertyTagGpsGpsDop	000Bh
#define PropertyTagGpsSpeedRef	000Ch
#define PropertyTagGpsSpeed	000Dh
#define PropertyTagGpsTrackRef	000Eh
#define PropertyTagGpsTrack	000Fh
#define PropertyTagGpsImgDirRef	0010h
#define PropertyTagGpsImgDir	0011h
#define PropertyTagGpsMapDatum	0012h
#define PropertyTagGpsDestLatRef	0013h
#define PropertyTagGpsDestLat	0014h
#define PropertyTagGpsDestLongRef	0015h
#define PropertyTagGpsDestLong	0016h
#define PropertyTagGpsDestBearRef	0017h
#define PropertyTagGpsDestBear	0018h
#define PropertyTagGpsDestDistRef	0019h
#define PropertyTagGpsDestDist	001Ah

#endif 
