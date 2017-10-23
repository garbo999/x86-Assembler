;=============================================================;
;         appavcap.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF APPAVCAP_INC
#Define APPAVCAP_INC

#IFNDEF MMREG_INC
	#Include mmreg.inc
#ENDIF

#IFNDEF MSACM_INC
	#Include msacm.inc
#ENDIF

#Define VARIABLE_DIM                        1

#Define LNH_48_CPU                          97
#Define LNH_8_CPU                           47
#Define LNH_12_CPU                          48
#Define LNH_16_CPU                          49
#Define MS_G723_CPU                         70
#Define CCITT_A_CPU                         24
#Define CCITT_U_CPU                         25

#Define INVALID_AUDIO_FORMAT                0FFFFFFFFH
#Define INVALID_MEDIA_FORMAT                0FFFFFFFFH
#Define INVALID_VIDEO_FORMAT                0FFFFFFFFH

BASIC_AUDCAP_INFO Struct
	wFormatTag DW
	Id DD
	szFormat DB ACMFORMATDETAILS_FORMAT_CHARS Dup ?
	uMaxBitrate DD
	uAvgBitrate DD
	wCPUUtilizationEncode DW
	wCPUUtilizationDecode DW
	bSendEnabled DD
	bRecvEnabled DD
	wSortIndex DW
EndS

#Define AUDCAP_INFO BASIC_AUDCAP_INFO

AUDCAP_INFO_LIST Struct
	cFormats DD
	aFormats AUDCAP_INFO <>
EndS

;VIDEO_SIZES enumeration
#Define Small                               0
#Define Medium                              1
#Define Large                               2

BASIC_VIDCAP_INFO Struct
	dwFormatTag DD
	Id DD
	szFormat DB ACMFORMATDETAILS_FORMAT_CHARS Dup ?
	wCPUUtilizationEncode DW
	wCPUUtilizationDecode DW
	bSendEnabled DD
	bRecvEnabled DD
	wSortIndex DW
	enumVideoSize DD
	bih BITMAPINFOHEADER <>
	uFrameRate DD
	dwBitsPerSample DD
	uAvgBitrate DD
	uMaxBitrate DD
EndS

#Define VIDCAP_INFO BASIC_VIDCAP_INFO

VIDCAP_INFO_LIST Struct
	cFormats DD
	aFormats VIDCAP_INFO <>
EndS

#ENDIF ;APPAVCAP_INC
