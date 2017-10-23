;=============================================================;
;          aviriff.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF AVIRIFF_INC
#Define AVIRIFF_INC

#IFNDEF TCHAR
	#IF STRINGS UNICODE
		#Define TCHAR DW
	#ELSE
		#Define TCHAR DB
	#ENDIF
#ENDIF

RIFFCHUNK Struct
	fcc DD
	cb DD
EndS

RIFFLIST Struct
	fcc DD
	cb DD
	fccListType DD
EndS

wRECT Struct
	left DW
	top DW
	right DW
	bottom DW
EndS

#Define ckidMAINAVIHEADER                   A'avih'

#Define AVIF_HASINDEX                       000000010H
#Define AVIF_MUSTUSEINDEX                   000000020H
#Define AVIF_ISINTERLEAVED                  000000100H
#Define AVIF_TRUSTCKTYPE                    000000800H
#Define AVIF_WASCAPTUREFILE                 000010000H
#Define AVIF_COPYRIGHTED                    000020000H

AVIMAINHEADER Struct
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
	dwReserved DD 4 Dup ?
EndS

#Define ckidODML                            A'odml'
#Define ckidAVIEXTHEADER                    A'dmlh'

AVIEXTHEADER Struct
	fcc DD
	cb DD
	dwGrandFrames DD
	dwFuture DD 61 Dup ?
EndS

#Define ckidSTREAMLIST                      A'strl'

#IFNDEF ckidSTREAMHEADER
	#Define ckidSTREAMHEADER                A'strh'
#ENDIF

#IFNDEF streamtypeVIDEO
	#Define streamtypeVIDEO                 A'vids'
	#Define streamtypeAUDIO                 A'auds'
	#Define streamtypeMIDI                  A'mids'
	#Define streamtypeTEXT                  A'txts'
#ENDIF

#Define AVISF_DISABLED                      000000001H
#Define AVISF_VIDEO_PALCHANGES              000010000H

AVISTREAMHEADER Struct
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
    rcFrame wRECT <>
EndS

#IFNDEF ckidSTREAMFORMAT
	#Define ckidSTREAMFORMAT                A'strf'
#ENDIF

#IFNDEF ckidSTREAMFORMAT
	#Define ckidSTREAMFORMAT                A'strf'
#ENDIF

#Define ckidAVIOLDINDEX                     A'idx1'

#IFNDEF AVIIF_LIST
	#Define AVIIF_LIST                      000000001H
	#Define AVIIF_KEYFRAME                  000000010H
#endif

#Define AVIIF_NO_TIME                       000000100H
#Define AVIIF_COMPRESSOR                    00FFF0000H

avioldindex_entry Struct
	dwChunkId DD
	dwFlags DD
	dwOffset DD
	dwSize DD
EndS

AVIOLDINDEX Struct
	fcc DD
	cb DD
	aIndex avioldindex_entry <>
EndS


#IFNDEF TIMECODE
	TIMECODE Struct
		wFrameRate DW
		wFrameFract DW
		cFrames DD
		qw DQ
	EndS
#ENDIF

#Define TIMECODE_RATE_30DROP                0

TIMECODEDATA Struct
	time TIMECODE <>
	dwSMPTEflags DD
	dwUser DD
EndS

#Define TIMECODE_SMPTE_BINARY_GROUP         007H
#Define TIMECODE_SMPTE_COLOR_FRAME          008H

#Define AVI_INDEX_OF_INDEXES                000H
#Define AVI_INDEX_OF_CHUNKS                 001H
#Define AVI_INDEX_OF_TIMED_CHUNKS           002H
#Define AVI_INDEX_OF_SUB_2FIELD             003H
#Define AVI_INDEX_IS_DATA                   080H

#Define AVI_INDEX_SUB_DEFAULT               000H

#Define AVI_INDEX_SUB_2FIELD                001H

AVIMETAINDEX Struct
	fcc DD
	cb DD
	wLongsPerEntry DW
	bIndexSubType DB
	bIndexType DB
	nEntriesInUse DD
	dwChunkId DD
	dwReserved DD 3 Dup ?
	adwIndex DD
EndS

#Define STDINDEXSIZE                        04000H

#Define ckidAVISUPERINDEX                   A'indx'

avisuperindex_entry Struct
	qwOffset DQ
	dwSize DD
	dwDuration DD
EndS

AVISUPERINDEX Struct
	fcc DD
	cb DD
	wLongsPerEntry DW
	bIndexSubType DB
	bIndexType DB
	nEntriesInUse DD
	dwChunkId DD
	dwReserved DD 3 Dup (?)
	aIndex avisuperindex_entry 4 Dup <>
EndS

AVISTDINDEX_ENTRY Struct
	dwOffset DD
	dwSize DD
EndS

#Define AVISTDINDEX_DELTAFRAME              (080000000H)
#Define AVISTDINDEX_SIZEMASK                (!080000000H)

AVISTDINDEX_ENTRY Struct
	dwOffset DD
	dwSize DD
EndS

AVISTDINDEX Struct
	fcc DD
	cb DD
	wLongsPerEntry DW
	bIndexSubType DB
	bIndexType DB
	nEntriesInUse DD
	dwChunkId DD
	qwBaseOffset DQ
	dwReserved_3 DD
	aIndex AVISTDINDEX_ENTRY 2 Dup <>
EndS

AVITIMEDINDEX_ENTRY Struct
	dwOffset DD
	dwSize DD
	dwDuration DD
EndS

AVITIMEDINDEX Struct
	fcc DD
	cb DD
	wLongsPerEntry DW
	bIndexSubType DB
	bIndexType DB
	nEntriesInUse DD
	dwChunkId DD
	qwBaseOffset DQ
	dwReserved_3 DD
	aIndex AVITIMEDINDEX_ENTRY 3 Dup <>
	adwTrailingFill DD 3 Dup ?
EndS

AVITIMECODEINDEX Struct
	fcc DD
	cb DD
	wLongsPerEntry DW
	bIndexSubType DB
	bIndexType DB
	nEntriesInUse DD
	dwChunkId DD
	dwReserved DD 3 Dup ?
    aIndex TIMECODEDATA <>
EndS

AVITCDLINDEX_ENTRY Struct
	dwTick DD
	time TIMECODE <>
	dwSMPTEflags DD
	dwUser DD
	szReelId TCHAR 12 Dup ?
EndS

AVITCDLINDEX Struct
	fcc DD
	cb DD
	wLongsPerEntry DW
	bIndexSubType DB
	bIndexType DB
	nEntriesInUse DD
	dwChunkId DD
	dwReserved DD 3 Dup ?
	aIndex AVITCDLINDEX_ENTRY 7 Dup <>
	adwTrailingFill DD 7 Dup ?
EndS

avifieldindex_entry Struct
	dwOffset DD
	dwSize DD
	dwOffsetField2 DD
EndS

AVIFIELDINDEX Struct
	fcc DD
	cb DD
	wLongsPerEntry DW
	bIndexSubType DB
	bIndexType DB
	nEntriesInUse DD
	dwChunkId DD
	qwBaseOffset DQ
	dwReserved3 DD
	aIndex avifieldindex_entry <>
EndS

#ENDIF ;AVIRIFF_INC
