;=============================================================;
;          avifmt.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF AVIFMT_INC
#Define AVIFMT_INC

#Define formtypeAVI                         A'AVI '
#Define listtypeAVIHEADER                   A'hdrl'
#Define ckidAVIMAINHDR                      A'avih'
#Define listtypeSTREAMHEADER                A'strl'
#Define ckidSTREAMHEADER                    A'strh'
#Define ckidSTREAMFORMAT                    A'strf'
#Define ckidSTREAMHANDLERDATA               A'strd'
#Define ckidSTREAMNAME                      A'strn'

#Define listtypeAVIMOVIE                    A'movi'
#Define listtypeAVIRECORD                   A'rec '
#Define ckidAVINEWINDEX                     A'idx1'

#Define streamtypeVIDEO                     A'vids'
#Define streamtypeAUDIO                     A'auds'
#Define streamtypeMIDI                      A'mids'
#Define streamtypeTEXT                      A'txts'

#Define cktypeDIBbits                       A'db'
#Define cktypeDIBcompressed                 A'dc'
#Define cktypePALchange                     A'pc'
#Define cktypeWAVEbytes                     A'wb'

#Define ckidAVIPADDING                      A'JUNK'
		
#Define AVIF_HASINDEX                       000000010H
#Define AVIF_MUSTUSEINDEX                   000000020H
#Define AVIF_ISINTERLEAVED                  000000100H
#Define AVIF_TRUSTCKTYPE                    000000800H
#Define AVIF_WASCAPTUREFILE                 000010000H
#Define AVIF_COPYRIGHTED                    000020000H

#Define AVI_HEADERSIZE                      2048

MainAVIHeader Struct
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
	dwReserved DD 4 Dup (?)
EndS

#Define AVISF_DISABLED         	            000000001H

#Define AVISF_VIDEO_PALCHANGES              000010000H

AVIStreamHeader Struct
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
	rcFrame RECT <>
EndS

#Define AVIIF_LIST                          000000001H
#Define AVIIF_KEYFRAME                      000000010H

#Define AVIIF_NOTIME	                    000000100H
#Define AVIIF_COMPUSE                       00FFF0000H

AVIINDEXENTRY Struct
	ckid DD
	dwFlags DD
	dwChunkOffset DD
	dwChunkLength DD
EndS

AVIPALCHANGE Struct
	bFirstEntry DB
	bNumEntries DB
	wFlags DW
	peNew PALETTEENTRY <>
EndS

#ENDIF ;AVIFMT_INC
