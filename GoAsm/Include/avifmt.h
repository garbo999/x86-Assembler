#ifndef AVIFMT_H
#define AVIFMT_H

#IFDEF LINKFILES
	#dynamiclinkfile msVfw32.dll
#ENDIF

/* Windows AVI file definitions */

#define formtypeAVI  A'AVI '
#define listtypeAVIHEADER  A'hdrl'
#define ckidAVIMAINHDR  A'avih'
#define listtypeSTREAMHEADER  A'strl'
#define ckidSTREAMHEADER  A'strh'
#define ckidSTREAMFORMAT  A'strf'
#define ckidSTREAMHANDLERDATA  A'strd'
#define ckidSTREAMNAME  A'strn'
#define listtypeAVIMOVIE  A'movi'
#define listtypeAVIRECORD  A'rec '
#define ckidAVINEWINDEX  A'idx1'

#define streamtypeVIDEO  A'vids'
#define streamtypeAUDIO  A'auds'
#define streamtypeMIDI  A'mids'
#define streamtypeTEXT  A'txts'

#define cktypeDIBbits  A'db'
#define cktypeDIBcompressed  A'dc'
#define cktypePALchange  A'pc'
#define cktypeWAVEbytes  A'wb'

#define ckidAVIPADDING  A'JUNK'

#define AVIF_HASINDEX  0x00000010
#define AVIF_MUSTUSEINDEX  0x00000020
#define AVIF_ISINTERLEAVED  0x00000100
#define AVIF_TRUSTCKTYPE  0x00000800
#define AVIF_WASCAPTUREFILE  0x00010000
#define AVIF_COPYRIGHTED  0x00020000

#define AVI_HEADERSIZE  2048

#define AVISF_DISABLED  0x00000001
#define AVISF_VIDEO_PALCHANGES  0x00010000

#define AVIIF_LIST  0x00000001
#define AVIIF_KEYFRAME  0x00000010
#define AVIIF_NOTIME  0x00000100
#define AVIIF_COMPUSE  0x0FFF0000

MainAVIHeader STRUCT
	dwMicroSecPerFrame DD
	dwMaxBytesPerSec DD
	dwPaddingGranularity DD
	dwFlags DD
	dwTotalFrames DD
	dwInitialFrames DD
	dwStreams DD
	dwSuggestedBufferSize DD
	dwWidth DD
	dwHeight DD
	dwReserved DD 4 DUP
ENDS

AVIStreamHeader STRUCT
	fccType DD
	fccHandler DD
	dwFlags DD
	wPriority DW
	wLanguage DW
	dwInitialFrames DD
	dwScale DD
	dwRate DD
	dwStart DD
	dwLength DD
	dwSuggestedBufferSize DD
	dwQuality DD
	dwSampleSize DD
	rcFrame STRUCT
		left DW
		top DW
		right DW
		bottom DW
	ENDS
ENDS

AVIINDEXENTRY STRUCT
	ckid DD
	dwFlags DD
	dwChunkOffset DD
	dwChunkLength DD
ENDS

AVIPALCHANGE STRUCT
	bFirstEntry DB
	bNumEntries DB
	wFlags DW
	peNew PALETTEENTRY <>
ENDS

#endif /* _AVIFMT_H */
