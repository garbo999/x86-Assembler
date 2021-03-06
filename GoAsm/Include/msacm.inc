;=============================================================;
;           msacm.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF MSACM_INC
#Define MSACM_INC

#IFNDEF DRV_MAPPER_PREFERRED_INPUT_GET
	#Define DRV_MAPPER_PREFERRED_INPUT_GET  (DRV_USER + 0)
#ENDIF

#IFNDEF DRV_MAPPER_PREFERRED_OUTPUT_GET
	#Define DRV_MAPPER_PREFERRED_OUTPUT_GET (DRV_USER + 2)
#ENDIF

#IFNDEF DRVM_MAPPER_STATUS
	#Define DRVM_MAPPER_STATUS              (02000H)
#ENDIF

#IFNDEF WIDM_MAPPER_STATUS
	#Define WIDM_MAPPER_STATUS              (DRVM_MAPPER_STATUS + 0)
	#Define WAVEIN_MAPPER_STATUS_DEVICE     0
	#Define WAVEIN_MAPPER_STATUS_MAPPED     1
	#Define WAVEIN_MAPPER_STATUS_FORMAT     2
#ENDIF

#IFNDEF WODM_MAPPER_STATUS
	#Define WODM_MAPPER_STATUS              (DRVM_MAPPER_STATUS + 0)
	#Define WAVEOUT_MAPPER_STATUS_DEVICE    0
	#Define WAVEOUT_MAPPER_STATUS_MAPPED    1
	#Define WAVEOUT_MAPPER_STATUS_FORMAT    2
#ENDIF

#Define ACMERR_BASE                         512
#Define ACMERR_NOTPOSSIBLE                  (ACMERR_BASE + 0)
#Define ACMERR_BUSY                         (ACMERR_BASE + 1)
#Define ACMERR_UNPREPARED                   (ACMERR_BASE + 2)
#Define ACMERR_CANCELED                     (ACMERR_BASE + 3)

#Define MM_ACM_OPEN                         (MM_STREAM_OPEN)
#Define MM_ACM_CLOSE                        (MM_STREAM_CLOSE)
#Define MM_ACM_DONE                         (MM_STREAM_DONE)

#Define ACM_METRIC_COUNT_DRIVERS            1
#Define ACM_METRIC_COUNT_CODECS             2
#Define ACM_METRIC_COUNT_CONVERTERS         3
#Define ACM_METRIC_COUNT_FILTERS            4
#Define ACM_METRIC_COUNT_DISABLED           5
#Define ACM_METRIC_COUNT_HARDWARE           6
#Define ACM_METRIC_COUNT_LOCAL_DRIVERS      20
#Define ACM_METRIC_COUNT_LOCAL_CODECS       21
#Define ACM_METRIC_COUNT_LOCAL_CONVERTERS   22
#Define ACM_METRIC_COUNT_LOCAL_FILTERS      23
#Define ACM_METRIC_COUNT_LOCAL_DISABLED     24
#Define ACM_METRIC_HARDWARE_WAVE_INPUT      30
#Define ACM_METRIC_HARDWARE_WAVE_OUTPUT     31
#Define ACM_METRIC_MAX_SIZE_FORMAT          50
#Define ACM_METRIC_MAX_SIZE_FILTER          51
#Define ACM_METRIC_DRIVER_SUPPORT           100
#Define ACM_METRIC_DRIVER_PRIORITY          101

#Define ACM_DRIVERENUMF_NOLOCAL             040000000H
#Define ACM_DRIVERENUMF_DISABLED            080000000H

#Define ACM_DRIVERADDF_FUNCTION             000000003H
#Define ACM_DRIVERADDF_NOTIFYHWND           000000004H
#Define ACM_DRIVERADDF_TYPEMASK             000000007H
#Define ACM_DRIVERADDF_LOCAL                000000000H
#Define ACM_DRIVERADDF_GLOBAL               000000008H

#Define ACMDM_USER                          (DRV_USER + 00000H)
#Define ACMDM_RESERVED_LOW                  (DRV_USER + 02000H)
#Define ACMDM_RESERVED_HIGH                 (DRV_USER + 02FFFH)

#Define ACMDM_BASE                          ACMDM_RESERVED_LOW

#Define ACMDM_DRIVER_ABOUT                  (ACMDM_BASE + 11)

#Define ACM_DRIVERPRIORITYF_ENABLE          000000001H
#Define ACM_DRIVERPRIORITYF_DISABLE         000000002H
#Define ACM_DRIVERPRIORITYF_ABLEMASK        000000003H
#Define ACM_DRIVERPRIORITYF_BEGIN           000010000H
#Define ACM_DRIVERPRIORITYF_END             000020000H
#Define ACM_DRIVERPRIORITYF_DEFERMASK       000030000H

#Define ACMDRIVERDETAILS_SHORTNAME_CHARS    32
#Define ACMDRIVERDETAILS_LONGNAME_CHARS     128
#Define ACMDRIVERDETAILS_COPYRIGHT_CHARS    80
#Define ACMDRIVERDETAILS_LICENSING_CHARS    128
#Define ACMDRIVERDETAILS_FEATURES_CHARS     512

ACMDRIVERDETAILSA Struct
	cbStruct DD
	fccType DD
	fccComp DD
	wMid DW
	wPid DW
	vdwACM DD
	vdwDriver DD
	fdwSupport DD
	cFormatTags DD
	cFilterTags DD
	hicon DD
	szShortName DB ACMDRIVERDETAILS_SHORTNAME_CHARS Dup ?
	szLongName DB ACMDRIVERDETAILS_LONGNAME_CHARS Dup ?
	szCopyright DB ACMDRIVERDETAILS_COPYRIGHT_CHARS Dup ?
	szLicensing DB ACMDRIVERDETAILS_LICENSING_CHARS Dup ?
	szFeatures DB ACMDRIVERDETAILS_FEATURES_CHARS Dup ?
EndS

ACMDRIVERDETAILSW Struct
	cbStruct DD
	fccType DD
	fccComp DD
	wMid DW
	wPid DW
	vdwACM DD
	vdwDriver DD
	fdwSupport DD
	cFormatTags DD
	cFilterTags DD
	hicon DD
	szShortName DW ACMDRIVERDETAILS_SHORTNAME_CHARS Dup ?
	szLongName DW ACMDRIVERDETAILS_LONGNAME_CHARS Dup ?
	szCopyright DW ACMDRIVERDETAILS_COPYRIGHT_CHARS Dup ?
	szLicensing DW ACMDRIVERDETAILS_LICENSING_CHARS Dup ?
	szFeatures DW ACMDRIVERDETAILS_FEATURES_CHARS Dup ?
EndS

#Define ACMDRIVERDETAILS_FCCTYPE_AUDIOCODEC A'audc'
;#Define ACMDRIVERDETAILS_FCCCOMP_UNDEFINED  A'\0', '\0', '\0', '\0'

#Define ACMDRIVERDETAILS_SUPPORTF_CODEC     000000001H
#Define ACMDRIVERDETAILS_SUPPORTF_CONVERTER 000000002H
#Define ACMDRIVERDETAILS_SUPPORTF_FILTER    000000004H
#Define ACMDRIVERDETAILS_SUPPORTF_HARDWARE  000000008H
#Define ACMDRIVERDETAILS_SUPPORTF_ASYNC     000000010H
#Define ACMDRIVERDETAILS_SUPPORTF_LOCAL     040000000H
#Define ACMDRIVERDETAILS_SUPPORTF_DISABLED  080000000H

#Define ACMFORMATTAGDETAILS_FORMATTAG_CHARS 48

ACMFORMATTAGDETAILSA Struct
	cbStruct DD
	dwFormatTagIndex DD
	dwFormatTag DD
	cbFormatSize DD
	fdwSupport DD
	cStandardFormats DD
	szFormatTag DB ACMFORMATTAGDETAILS_FORMATTAG_CHARS Dup ?
EndS

ACMFORMATTAGDETAILSW Struct
	cbStruct DD
	dwFormatTagIndex DD
	dwFormatTag DD
	cbFormatSize DD
	fdwSupport DD
	cStandardFormats DD
	szFormatTag DW ACMFORMATTAGDETAILS_FORMATTAG_CHARS Dup ?
EndS

#Define ACM_FORMATTAGDETAILSF_INDEX         000000000H
#Define ACM_FORMATTAGDETAILSF_FORMATTAG     000000001H
#Define ACM_FORMATTAGDETAILSF_LARGESTSIZE   000000002H
#Define ACM_FORMATTAGDETAILSF_QUERYMASK     00000000FH

#Define ACMFORMATDETAILS_FORMAT_CHARS       128

ACMFORMATDETAILSA Struct
	cbStruct DD
	dwFormatIndex DD
	dwFormatTag DD
	fdwSupport DD
	pwfx DD
	cbwfx DD
	szFormat DB ACMFORMATDETAILS_FORMAT_CHARS Dup ?
EndS

ACMFORMATDETAILSW Struct
	cbStruct DD
	dwFormatIndex DD
	dwFormatTag DD
	fdwSupport DD
	pwfx DD
	cbwfx DD
	szFormat DW ACMFORMATDETAILS_FORMAT_CHARS Dup ?
EndS

#Define ACM_FORMATDETAILSF_INDEX            000000000H
#Define ACM_FORMATDETAILSF_FORMAT           000000001H
#Define ACM_FORMATDETAILSF_QUERYMASK        00000000FH

#Define ACM_FORMATENUMF_WFORMATTAG          000010000H
#Define ACM_FORMATENUMF_NCHANNELS           000020000H
#Define ACM_FORMATENUMF_NSAMPLESPERSEC      000040000H
#Define ACM_FORMATENUMF_WBITSPERSAMPLE      000080000H
#Define ACM_FORMATENUMF_CONVERT             000100000H
#Define ACM_FORMATENUMF_SUGGEST             000200000H
#Define ACM_FORMATENUMF_HARDWARE            000400000H
#Define ACM_FORMATENUMF_INPUT               000800000H
#Define ACM_FORMATENUMF_OUTPUT              001000000H

#Define ACM_FORMATSUGGESTF_WFORMATTAG       000010000H
#Define ACM_FORMATSUGGESTF_NCHANNELS        000020000H
#Define ACM_FORMATSUGGESTF_NSAMPLESPERSEC   000040000H
#Define ACM_FORMATSUGGESTF_WBITSPERSAMPLE   000080000H

#Define ACM_FORMATSUGGESTF_TYPEMASK         000FF0000H

#Define ACMHELPMSGSTRINGA                   A"acmchoose_help"
#Define ACMHELPMSGSTRINGW                   L"acmchoose_help"
#Define ACMHELPMSGCONTEXTMENUA              A"acmchoose_contextmenu"
#Define ACMHELPMSGCONTEXTMENUW              L"acmchoose_contextmenu"
#Define ACMHELPMSGCONTEXTHELPA              A"acmchoose_contexthelp"
#Define ACMHELPMSGCONTEXTHELPW              L"acmchoose_contexthelp"

#Define MM_ACM_FORMATCHOOSE                 (08000H)

#Define FORMATCHOOSE_MESSAGE                0
#Define FORMATCHOOSE_FORMATTAG_VERIFY       (FORMATCHOOSE_MESSAGE + 0)
#Define FORMATCHOOSE_FORMAT_VERIFY          (FORMATCHOOSE_MESSAGE + 1)
#Define FORMATCHOOSE_CUSTOM_VERIFY          (FORMATCHOOSE_MESSAGE + 2)

ACMFORMATCHOOSEA Struct
	cbStruct DD
	fdwStyle DD
	hwndOwner DD
	pwfx DD
	cbwfx DD
	pszTitle DD
	szFormatTag DB ACMFORMATTAGDETAILS_FORMATTAG_CHARS Dup ?
	szFormat DB ACMFORMATDETAILS_FORMAT_CHARS Dup ?
	pszName DD
	cchName DD
	fdwEnum DD
	pwfxEnum DD
	hInstance DD
	pszTemplateName DD
	lCustData DD
	pfnHook DD
EndS

ACMFORMATCHOOSEW Struct
	cbStruct DD
	fdwStyle DD
	hwndOwner DD
	pwfx DD
	cbwfx DD
	pszTitle DD
	szFormatTag DW ACMFORMATTAGDETAILS_FORMATTAG_CHARS Dup ?
	szFormat DW ACMFORMATDETAILS_FORMAT_CHARS Dup ?
	pszName DD
	cchName DD
	fdwEnum DD
	pwfxEnum DD
	hInstance DD
	pszTemplateName DD
	lCustData DD
	pfnHook DD
EndS

#Define ACMFORMATCHOOSE_STYLEF_SHOWHELP              000000004H
#Define ACMFORMATCHOOSE_STYLEF_ENABLEHOOK            000000008H
#Define ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATE        000000010H
#Define ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATEHANDLE  000000020H
#Define ACMFORMATCHOOSE_STYLEF_INITTOWFXSTRUCT       000000040H
#Define ACMFORMATCHOOSE_STYLEF_CONTEXTHELP           000000080H

#define ACMFILTERTAGDETAILS_FILTERTAG_CHARS          48

ACMFILTERTAGDETAILSA Struct
	cbStruct DD
	dwFilterTagIndex DD
	dwFilterTag DD
	cbFilterSize DD
	fdwSupport DD
 	cStandardFilters DD
	szFilterTag DB ACMFILTERTAGDETAILS_FILTERTAG_CHARS Dup ?
EndS

ACMFILTERTAGDETAILSW Struct
	cbStruct DD
	dwFilterTagIndex DD
	dwFilterTag DD
	cbFilterSize DD
	fdwSupport DD
 	cStandardFilters DD
	szFilterTag DW ACMFILTERTAGDETAILS_FILTERTAG_CHARS Dup ?
EndS

#Define ACM_FILTERTAGDETAILSF_INDEX         000000000H
#Define ACM_FILTERTAGDETAILSF_FILTERTAG     000000001H
#Define ACM_FILTERTAGDETAILSF_LARGESTSIZE   000000002H
#Define ACM_FILTERTAGDETAILSF_QUERYMASK     00000000FH

#Define ACMFILTERDETAILS_FILTER_CHARS       128

ACMFILTERDETAILSA Struct
	cbStruct DD
	dwFilterIndex DD
	dwFilterTag DD
	fdwSupport DD
	pwfltr DD
	cbwfltr DD
	szFilter DB ACMFILTERDETAILS_FILTER_CHARS Dup ?
EndS

ACMFILTERDETAILSW Struct
	cbStruct DD
	dwFilterIndex DD
	dwFilterTag DD
	fdwSupport DD
	pwfltr DD
	cbwfltr DD
	szFilter DW ACMFILTERDETAILS_FILTER_CHARS Dup ?
EndS

#Define ACM_FILTERDETAILSF_INDEX            000000000H
#Define ACM_FILTERDETAILSF_FILTER           000000001H
#Define ACM_FILTERDETAILSF_QUERYMASK        00000000FH

#Define ACM_FILTERENUMF_DWFILTERTAG         000010000H

#Define MM_ACM_FILTERCHOOSE                 (08000H)

#Define FILTERCHOOSE_MESSAGE                0
#Define FILTERCHOOSE_FILTERTAG_VERIFY       (FILTERCHOOSE_MESSAGE + 0)
#Define FILTERCHOOSE_FILTER_VERIFY          (FILTERCHOOSE_MESSAGE + 1)
#Define FILTERCHOOSE_CUSTOM_VERIFY          (FILTERCHOOSE_MESSAGE + 2)

ACMFILTERCHOOSEA Struct
	cbStruct DD
 	fdwStyle DD
	hwndOwner DD
	pwfltr DD
	cbwfltr DD
	pszTitle DD
	szFilterTag DB ACMFILTERTAGDETAILS_FILTERTAG_CHARS Dup ?
	szFilter DB ACMFILTERDETAILS_FILTER_CHARS Dup ?
	pszName DD
	cchName DD
	fdwEnum DD
	pwfltrEnum DD
	hInstance DD
	pszTemplateName DD
	lCustData DD
	pfnHook DD
EndS

ACMFILTERCHOOSEW Struct
	cbStruct DD
 	fdwStyle DD
	hwndOwner DD
	pwfltr DD
	cbwfltr DD
	pszTitle DD
	szFilterTag DW ACMFILTERTAGDETAILS_FILTERTAG_CHARS Dup ?
	szFilter DW ACMFILTERDETAILS_FILTER_CHARS Dup ?
	pszName DD
	cchName DD
	fdwEnum DD
	pwfltrEnum DD
	hInstance DD
	pszTemplateName DD
	lCustData DD
	pfnHook DD
EndS

#Define ACMFILTERCHOOSE_STYLEF_SHOWHELP              000000004H
#Define ACMFILTERCHOOSE_STYLEF_ENABLEHOOK            000000008H
#Define ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATE        000000010H
#Define ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATEHANDLE  000000020H
#Define ACMFILTERCHOOSE_STYLEF_INITTOFILTERSTRUCT    000000040H
#Define ACMFILTERCHOOSE_STYLEF_CONTEXTHELP           000000080H

ACMSTREAMHEADER Struct
	cbStruct DD
	fdwStatus DD
	dwUser DD
	pbSrc DD
	cbSrcLength DD
	cbSrcLengthUsed DD
	dwSrcUser DD
	pbDst DD
	cbDstLength DD
	cbDstLengthUsed DD
	dwDstUser DD
	dwReservedDriver DD 10 Dup ?
EndS

#Define ACMSTREAMHEADER_STATUSF_DONE        000010000H
#Define ACMSTREAMHEADER_STATUSF_PREPARED    000020000H
#Define ACMSTREAMHEADER_STATUSF_INQUEUE     000100000H

#Define ACM_STREAMOPENF_QUERY               000000001H
#Define ACM_STREAMOPENF_ASYNC               000000002H
#Define ACM_STREAMOPENF_NONREALTIME         000000004H

#Define ACM_STREAMSIZEF_SOURCE              000000000H
#Define ACM_STREAMSIZEF_DESTINATION         000000001H
#Define ACM_STREAMSIZEF_QUERYMASK           00000000FH

#Define ACM_STREAMCONVERTF_BLOCKALIGN       000000004H
#Define ACM_STREAMCONVERTF_START            000000010H
#Define ACM_STREAMCONVERTF_END              000000020H
                                       
#IF STRINGS UNICODE
	#Define acmDriverAdd acmDriverAddW
	#Define ACMDRIVERDETAILS ACMDRIVERDETAILSW
	#Define acmDriverDetails acmDriverDetailsW
	#Define ACMFORMATTAGDETAILS ACMFORMATTAGDETAILSW
	#Define acmFormatTagDetails acmFormatTagDetailsW
	#Define ACMFORMATTAGENUMCB ACMFORMATTAGENUMCBW
	#Define acmFormatTagEnum acmFormatTagEnumW
	#Define ACMFORMATDETAILS ACMFORMATDETAILSW
	#Define acmFormatDetails acmFormatDetailsW
	#Define ACMFORMATENUMCB ACMFORMATENUMCBW
	#Define acmFormatEnum acmFormatEnumW
	#Define ACMHELPMSGSTRING ACMHELPMSGSTRINGW
	#Define ACMHELPMSGCONTEXTMENU ACMHELPMSGCONTEXTMENUW
	#Define ACMHELPMSGCONTEXTHELP ACMHELPMSGCONTEXTHELPW
	#Define ACMFORMATCHOOSEHOOKPROC ACMFORMATCHOOSEHOOKPROCW
	#Define ACMFORMATCHOOSE ACMFORMATCHOOSEW
	#Define acmFormatChoose acmFormatChooseW
	#Define ACMFILTERTAGDETAILS ACMFILTERTAGDETAILSW
	#Define acmFilterTagDetails acmFilterTagDetailsW
	#Define ACMFILTERTAGENUMCB ACMFILTERTAGENUMCBW
	#Define acmFilterTagEnum acmFilterTagEnumW
	#Define ACMFILTERDETAILS ACMFILTERDETAILSW
 	#Define acmFilterDetails acmFilterDetailsW
	#Define ACMFILTERENUMCB ACMFILTERENUMCBW
	#Define acmFilterEnum acmFilterEnumW
	#Define ACMFILTERCHOOSEHOOKPROC ACMFILTERCHOOSEHOOKPROCW
	#Define ACMFILTERCHOOSE ACMFILTERCHOOSEW
	#Define acmFilterChoose acmFilterChooseW
#ELSE
	#Define acmDriverAdd acmDriverAddA
	#Define ACMDRIVERDETAILS ACMDRIVERDETAILSA
	#Define acmDriverDetails acmDriverDetailsA
	#Define ACMFORMATTAGDETAILS ACMFORMATTAGDETAILSA
	#Define acmFormatTagDetails acmFormatTagDetailsA
	#Define ACMFORMATTAGENUMCB ACMFORMATTAGENUMCBA
	#Define acmFormatTagEnum acmFormatTagEnumA
	#Define ACMFORMATDETAILS ACMFORMATDETAILSA
	#Define acmFormatDetails acmFormatDetailsA
	#Define ACMFORMATENUMCB ACMFORMATENUMCBA
	#Define acmFormatEnum acmFormatEnumA
	#Define ACMHELPMSGSTRING ACMHELPMSGSTRINGA
	#Define ACMHELPMSGCONTEXTMENU ACMHELPMSGCONTEXTMENUA
	#Define ACMHELPMSGCONTEXTHELP ACMHELPMSGCONTEXTHELPA
	#Define ACMFORMATCHOOSEHOOKPROC ACMFORMATCHOOSEHOOKPROCA
	#Define ACMFORMATCHOOSE ACMFORMATCHOOSEA
	#Define acmFormatChoose acmFormatChooseA
	#Define ACMFILTERTAGDETAILS ACMFILTERTAGDETAILSA
	#Define acmFilterTagDetails acmFilterTagDetailsA
	#Define ACMFILTERTAGENUMCB ACMFILTERTAGENUMCBA
	#Define acmFilterTagEnum acmFilterTagEnumA
	#Define ACMFILTERDETAILS ACMFILTERDETAILSA
 	#Define acmFilterDetails acmFilterDetailsA
	#Define ACMFILTERENUMCB ACMFILTERENUMCBA
	#Define acmFilterEnum acmFilterEnumA
	#Define ACMFILTERCHOOSEHOOKPROC ACMFILTERCHOOSEHOOKPROCA
	#Define ACMFILTERCHOOSE ACMFILTERCHOOSEA
	#Define acmFilterChoose acmFilterChooseA
#ENDIF

#ENDIF ;MSACM_INC
