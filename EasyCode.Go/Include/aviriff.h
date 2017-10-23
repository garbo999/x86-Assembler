#ifndef AVIRIFF_H
#define AVIRIFF_H

#IFDEF LINKFILES
	#dynamiclinkfile msVfw32.dll
#ENDIF

#define ckidMAINAVIHEADER A'avih'

#define AVIF_HASINDEX  0x00000010
#define AVIF_MUSTUSEINDEX  0x00000020
#define AVIF_ISINTERLEAVED  0x00000100
#define AVIF_TRUSTCKTYPE  0x00000800
#define AVIF_WASCAPTUREFILE  0x00010000
#define AVIF_COPYRIGHTED  0x00020000

#define ckidODML  A'odml'
#define ckidAVIEXTHEADER  A'dmlh'
#define ckidSTREAMLIST  A'strl'

#ifndef ckidSTREAMHEADER
#define ckidSTREAMHEADER  A'strh'
#endif

#ifndef ckidSTREAMFORMAT
#define ckidSTREAMFORMAT  A'strf'
#endif

#define ckidAVIOLDINDEX  A'idx1'
#define ckidAVISUPERINDEX  A'indx'

#ifndef streamtypeVIDEO
#define streamtypeVIDEO  A'vids'
#define streamtypeAUDIO  A'auds'
#define streamtypeMIDI  A'mids'
#define streamtypeTEXT  A'txts'
#endif

#define AVISF_DISABLED  0x00000001
#define AVISF_VIDEO_PALCHANGES  0x00010000

#ifndef AVIIF_LIST
#define AVIIF_LIST  0x00000001
#define AVIIF_KEYFRAME  0x00000010
#endif

#define AVIIF_NO_TIME  0x00000100
#define AVIIF_COMPRESSOR  0x0FFF0000

#define TIMECODE_RATE_30DROP  0

#define TIMECODE_SMPTE_BINARY_GROUP  0x07
#define TIMECODE_SMPTE_COLOR_FRAME  0x08

#define AVI_INDEX_OF_INDEXES  0x00
#define AVI_INDEX_OF_CHUNKS  0x01
#define AVI_INDEX_OF_TIMED_CHUNKS  0x02
#define AVI_INDEX_OF_SUB_2FIELD  0x03
#define AVI_INDEX_IS_DATA  0x80

#define AVI_INDEX_SUB_DEFAULT  0x00
#define AVI_INDEX_SUB_2FIELD  0x01

#define STDINDEXSIZE  0x4000
#define AVISTDINDEX_DELTAFRAME  0x80000000
#define AVISTDINDEX_SIZEMASK  !0x80000000

RIFFCHUNK STRUCT
	fcc DD
	cb DD
ENDS

RIFFLIST STRUCT
	fcc DD
	cb DD
	fccListType DD
ENDS

AVIMAINHEADER STRUCT
	fcc DD
	cb DD
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
	dwReserved DD 4 DUP (?)
ENDS

AVIEXTHEADER STRUCT
	fcc DD
	cb DD
	dwGrandFrames DD
	dwFuture DD 61 DUP (?)
ENDS


AVISTREAMHEADER STRUCT
	fcc DD
	cb DD
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

AVIOLDINDEX STRUCT
	fcc DD
	cb DD
	aIndex STRUCT
		dwChunkId DD
		dwFlags DD
		dwOffset DD
		dwSize DD
	ENDS
ENDS

#ifndef TIMECODE
	TIMECODE STRUCT
		wFrameRate DW
		wFrameFract DW
		cFrames DD
		qw DQ
	ENDS
#endif

TIMECODEDATA STRUCT
	time TIMECODE <>
	dwSMPTEflags DD
	dwUser DD
ENDS

AVIMETAINDEX STRUCT
	fcc DD
	cb DD
	wLongsPerEntry DW
	bIndexSubType DB
	bIndexType DB
	nEntriesInUse DD
	dwChunkId DD
	dwReserved DD 3 DUP (?)
	adwIndex DD
ENDS

avisuperindex_entry STRUCT
	qwOffset DQ
	dwSize DD
	dwDuration DD
ENDS

AVISUPERINDEX STRUCT
	fcc DD
	cb DD
	wLongsPerEntry DW
	bIndexSubType DB
	bIndexType DB
	nEntriesInUse DD
	dwChunkId DD
	dwReserved DD 3 DUP (?)
	aIndex avisuperindex_entry 4 DUP <>
ENDS

AVISTDINDEX_ENTRY STRUCT
	dwOffset DD
	dwSize DD
ENDS

AVISTDINDEX STRUCT
	fcc DD
	cb DD
	wLongsPerEntry DW
	bIndexSubType DB
	bIndexType DB
	nEntriesInUse DD
	dwChunkId DD
	qwBaseOffset DQ
	dwReserved_3 DD
	aIndex AVISTDINDEX_ENTRY 2 DUP <>
ENDS

AVITIMEDINDEX_ENTRY STRUCT
	dwOffset DD
	dwSize DD
	dwDuration DD
ENDS

AVITIMEDINDEX STRUCT
	fcc DD
	cb DD
	wLongsPerEntry DW
	bIndexSubType DB
	bIndexType DB
	nEntriesInUse DD
	dwChunkId DD
	qwBaseOffset DQ
	dwReserved_3 DD
	aIndex AVITIMEDINDEX_ENTRY 3 DUP <>
	adwTrailingFill DD 3 DUP (?)
ENDS

AVITIMECODEINDEX STRUCT
	fcc DD
	cb DD
	wLongsPerEntry DW
	bIndexSubType DB
	bIndexType DB
	nEntriesInUse DD
	dwChunkId DD
	dwReserved DD 3 DUP (?)
    aIndex TIMECODEDATA <>
ENDS

AVITCDLINDEX_ENTRY STRUCT
	dwTick DD
	time TIMECODE <>
	dwSMPTEflags DD
	dwUser DD
    TCHAR szReelId DB 12 DUP (?)
ENDS

AVITCDLINDEX STRUCT
	fcc DD
	cb DD
	wLongsPerEntry DW
	bIndexSubType DB
	bIndexType DB
	nEntriesInUse DD
	dwChunkId DD
	dwReserved DD 3 DUP (?)
	aIndex AVITCDLINDEX_ENTRY 7 DUP <> 
	adwTrailingFill DD 7 DUP (?)
ENDS

AVIFIELDINDEX STRUCT
	fcc DD
	cb DD
	wLongsPerEntry DW
	bIndexSubType DB
	bIndexType DB
	nEntriesInUse DD
	dwChunkId DD
	qwBaseOffset DQ
	dwReserved3 DD
	aIndex STRUCT
		dwOffset DD
		dwSize DD
		dwOffsetField2 DD
	ENDS
ENDS

#endif /* _AVIRIFF_H */
