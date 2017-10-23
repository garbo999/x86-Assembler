#ifndef APPAVCAP_H
#define APPAVCAP_H

/* Network audio/video application capability interface definitions */

#IFNDEF MMREG_H
	#include mmreg.h
#ENDIF

#IFNDEF MSACM_H
	#include msacm.h
#ENDIF

#define INVALID_AUDIO_FORMAT  0xffffffff
#define INVALID_MEDIA_FORMAT  0xffffffff
#define INVALID_VIDEO_FORMAT  0xffffffff

#define VARIABLE_DIM  1

#define LNH_48_CPU  97
#define LNH_8_CPU  47
#define LNH_12_CPU  48
#define LNH_16_CPU  49
#define MS_G723_CPU  70
#define CCITT_A_CPU  24
#define CCITT_U_CPU  25

BASIC_AUDCAP_INFO STRUCT
	wFormatTag DW
	Id DD
	szFormat DB ACMFORMATDETAILS_FORMAT_CHARS DUP
	uMaxBitrate DD
	uAvgBitrate DD
	wCPUUtilizationEncode DW
	wCPUUtilizationDecode DW
	bSendEnabled DD
	bRecvEnabled DD
	wSortIndex DW
ENDS

#define AUDCAP_INFO BASIC_AUDCAP_INFO

AUDCAP_INFO_LIST STRUCT
	cFormats DD
	aFormats AUDCAP_INFO
ENDS

Small = 0
Medium = 1
Large = 2

BASIC_VIDCAP_INFO STRUCT
	dwFormatTag DD
	Id DD
	szFormat DB ACMFORMATDETAILS_FORMAT_CHARS DUP
	wCPUUtilizationEncode DW
	wCPUUtilizationDecode DW
	bSendEnabled DD
	bRecvEnabled DD
	wSortIndex DW
	enumVideoSize DD
	bih BITMAPINFOHEADER
	uFrameRate DD
	dwBitsPerSample DD
	uAvgBitrate DD
	uMaxBitrate DD
ENDS

#define VIDCAP_INFO BASIC_VIDCAP_INFO

VIDCAP_INFO_LIST STRUCT
	cFormats DD
	aFormats VIDCAP_INFO
ENDS

#endif /* _APPAVCAP_H */

