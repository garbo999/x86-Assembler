;=============================================================;
;          winnls.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINNLS_INC
#Define WINNLS_INC

#Define MAX_LEADBYTES             		12
#Define MAX_DEFAULTCHAR           		2

#Define MB_PRECOMPOSED            		000000001H
#Define MB_COMPOSITE              		000000002H
#Define MB_USEGLYPHCHARS          		000000004H
#Define MB_ERR_INVALID_CHARS      		000000008H

#Define WC_COMPOSITECHECK         		000000200H
#Define WC_DISCARDNS              		000000010H
#Define WC_SEPCHARS               		000000020H
#Define WC_DEFAULTCHAR            		000000040H
#Define WC_NO_BEST_FIT_CHARS      		000000400H

#Define CT_CTYPE1                 		000000001H
#Define CT_CTYPE2                 		000000002H
#Define CT_CTYPE3                 		000000004H

#Define C1_UPPER                  		00001H
#Define C1_LOWER                  		00002H
#Define C1_DIGIT                  		00004H
#Define C1_SPACE                  		00008H
#Define C1_PUNCT                  		00010H
#Define C1_CNTRL                  		00020H
#Define C1_BLANK                  		00040H
#Define C1_XDIGIT                 		00080H
#Define C1_ALPHA                  		00100H

#Define C2_LEFTTORIGHT            		00001H
#Define C2_RIGHTTOLEFT            		00002H

#Define C2_EUROPENUMBER           		00003H
#Define C2_EUROPESEPARATOR        		00004H
#Define C2_EUROPETERMINATOR       		00005H
#Define C2_ARABICNUMBER           		00006H
#Define C2_COMMONSEPARATOR        		00007H

#Define C2_BLOCKSEPARATOR         		00008H
#Define C2_SEGMENTSEPARATOR       		00009H
#Define C2_WHITESPACE             		0000AH
#Define C2_OTHERNEUTRAL           		0000BH

#Define C2_NOTAPPLICABLE          		00000H

#Define C3_NONSPACING             		00001H
#Define C3_DIACRITIC              		00002H
#Define C3_VOWELMARK              		00004H
#Define C3_SYMBOL                 		00008H

#Define C3_KATAKANA               		00010H
#Define C3_HIRAGANA               		00020H
#Define C3_HALFWIDTH              		00040H
#Define C3_FULLWIDTH              		00080H
#Define C3_IDEOGRAPH              		00100H
#Define C3_KASHIDA                		00200H
#Define C3_LEXICAL                		00400H

#Define C3_ALPHA                  		08000H

#Define C3_NOTAPPLICABLE          		00000H

#Define NORM_IGNORECASE           		000000001H
#Define NORM_IGNORENONSPACE       		000000002H
#Define NORM_IGNORESYMBOLS        		000000004H

#Define NORM_IGNOREKANATYPE       		000010000H
#Define NORM_IGNOREWIDTH          		000020000H

#Define MAP_FOLDCZONE             		000000010H
#Define MAP_PRECOMPOSED           		000000020H
#Define MAP_COMPOSITE             		000000040H
#Define MAP_FOLDDIGITS            		000000080H

#Define MAP_EXPAND_LIGATURES      		000002000H

#Define LCMAP_LOWERCASE           		000000100H
#Define LCMAP_UPPERCASE           		000000200H
#Define LCMAP_SORTKEY             		000000400H
#Define LCMAP_BYTEREV             		000000800H

#Define LCMAP_HIRAGANA            		000100000H
#Define LCMAP_KATAKANA            		000200000H
#Define LCMAP_HALFWIDTH           		000400000H
#Define LCMAP_FULLWIDTH           		000800000H

#Define LCMAP_LINGUISTIC_CASING   		001000000H

#Define LCMAP_SIMPLIFIED_CHINESE  		002000000H
#Define LCMAP_TRADITIONAL_CHINESE 		004000000H

#Define LCID_INSTALLED            		000000001H
#Define LCID_SUPPORTED            		000000002H
#Define LCID_ALTERNATE_SORTS      		000000004H

#Define CP_INSTALLED              		000000001H
#Define CP_SUPPORTED              		000000002H

#Define SORT_STRINGSORT           		000001000H

#Define CSTR_LESS_THAN            		1
#Define CSTR_EQUAL                		2
#Define CSTR_GREATER_THAN         		3

#Define CP_ACP                    		0
#Define CP_OEMCP                  		1
#Define CP_MACCP                  		2
#Define CP_THREAD_ACP             		3
#Define CP_SYMBOL                 		42

#Define CP_UTF7                   		65000
#Define CP_UTF8                   		65001

#Define CTRY_DEFAULT              		0

#Define CTRY_ALBANIA              		355
#Define CTRY_ALGERIA              		213
#Define CTRY_ARGENTINA            		54
#Define CTRY_AUSTRALIA            		61
#Define CTRY_AUSTRIA              		43
#Define CTRY_BAHRAIN              		973
#Define CTRY_BELARUS              		375
#Define CTRY_BELGIUM              		32
#Define CTRY_BELIZE               		501
#Define CTRY_BOLIVIA              		591
#Define CTRY_BRAZIL               		55
#Define CTRY_BRUNEI_DARUSSALAM    		673
#Define CTRY_BULGARIA             		359
#Define CTRY_CANADA               		2
#Define CTRY_CARIBBEAN            		1
#Define CTRY_CHILE                		56
#Define CTRY_COLOMBIA             		57
#Define CTRY_COSTA_RICA           		506
#Define CTRY_CROATIA              		385
#Define CTRY_CZECH                		420
#Define CTRY_DENMARK              		45
#Define CTRY_DOMINICAN_REPUBLIC   		1
#Define CTRY_ECUADOR              		593
#Define CTRY_EGYPT                		20
#Define CTRY_EL_SALVADOR          		503
#Define CTRY_ESTONIA              		372
#Define CTRY_FAEROE_ISLANDS       		298
#Define CTRY_FINLAND              		358
#Define CTRY_FRANCE               		33
#Define CTRY_GERMANY              		49
#Define CTRY_GREECE               		30
#Define CTRY_GUATEMALA            		502
#Define CTRY_HONDURAS             		504
#Define CTRY_HONG_KONG            		852
#Define CTRY_HUNGARY              		36
#Define CTRY_ICELAND              		354
#Define CTRY_INDIA                		91
#Define CTRY_INDONESIA            		62
#Define CTRY_IRAN                 		981
#Define CTRY_IRAQ                 		964
#Define CTRY_IRELAND              		353
#Define CTRY_ISRAEL               		972
#Define CTRY_ITALY                		39
#Define CTRY_JAMAICA              		1
#Define CTRY_JAPAN                		81
#Define CTRY_JORDAN               		962
#Define CTRY_KENYA                		254
#Define CTRY_KUWAIT               		965
#Define CTRY_LATVIA               		371
#Define CTRY_LEBANON              		961
#Define CTRY_LIBYA                		218
#Define CTRY_LIECHTENSTEIN        		41
#Define CTRY_LITHUANIA            		370
#Define CTRY_LUXEMBOURG           		352
#Define CTRY_MACAU                		853
#Define CTRY_MACEDONIA            		389
#Define CTRY_MALAYSIA             		60
#Define CTRY_MEXICO               		52
#Define CTRY_MONACO               		33
#Define CTRY_MOROCCO              		212
#Define CTRY_NETHERLANDS          		31
#Define CTRY_NEW_ZEALAND          		64
#Define CTRY_NICARAGUA            		505
#Define CTRY_NORWAY               		47
#Define CTRY_OMAN                 		968
#Define CTRY_PAKISTAN             		92
#Define CTRY_PANAMA               		507
#Define CTRY_PARAGUAY             		595
#Define CTRY_PERU                 		51
#Define CTRY_PHILIPPINES          		63
#Define CTRY_POLAND               		48
#Define CTRY_PORTUGAL             		351
#Define CTRY_PRCHINA              		86
#Define CTRY_PUERTO_RICO          		1
#Define CTRY_QATAR                		974
#Define CTRY_ROMANIA              		40
#Define CTRY_RUSSIA               		7
#Define CTRY_SAUDI_ARABIA         		966
#Define CTRY_SERBIA               		381
#Define CTRY_SINGAPORE            		65
#Define CTRY_SLOVAK               		421
#Define CTRY_SLOVENIA             		386
#Define CTRY_SOUTH_AFRICA         		27
#Define CTRY_SOUTH_KOREA          		82
#Define CTRY_SPAIN                		34
#Define CTRY_SWEDEN               		46
#Define CTRY_SWITZERLAND          		41
#Define CTRY_SYRIA                		963
#Define CTRY_TAIWAN               		886
#Define CTRY_THAILAND             		66
#Define CTRY_TRINIDAD_Y_TOBAGO    		1
#Define CTRY_TUNISIA              		216
#Define CTRY_TURKEY               		90
#Define CTRY_UAE                  		971
#Define CTRY_UKRAINE              		380
#Define CTRY_UNITED_KINGDOM       		44
#Define CTRY_UNITED_STATES        		1
#Define CTRY_URUGUAY              		598
#Define CTRY_VENEZUELA            		58
#Define CTRY_VIET_NAM             		84
#Define CTRY_YEMEN                		967
#Define CTRY_ZIMBABWE             		263

#Define LOCALE_NOUSEROVERRIDE         	080000000H
#Define LOCALE_USE_CP_ACP             	040000000H

#Define LOCALE_RETURN_NUMBER          	020000000H

#Define LOCALE_ILANGUAGE              	000000001H
#Define LOCALE_SLANGUAGE              	000000002H
#Define LOCALE_SENGLANGUAGE           	000001001H
#Define LOCALE_SABBREVLANGNAME        	000000003H
#Define LOCALE_SNATIVELANGNAME        	000000004H

#Define LOCALE_ICOUNTRY               	000000005H
#Define LOCALE_SCOUNTRY               	000000006H
#Define LOCALE_SENGCOUNTRY            	000001002H
#Define LOCALE_SABBREVCTRYNAME        	000000007H
#Define LOCALE_SNATIVECTRYNAME        	000000008H

#Define LOCALE_IDEFAULTLANGUAGE       	000000009H
#Define LOCALE_IDEFAULTCOUNTRY        	00000000AH
#Define LOCALE_IDEFAULTCODEPAGE       	00000000BH
#Define LOCALE_IDEFAULTANSICODEPAGE   	000001004H
#Define LOCALE_IDEFAULTMACCODEPAGE    	000001011H

#Define LOCALE_SLIST                  	00000000CH
#Define LOCALE_IMEASURE               	00000000DH

#Define LOCALE_SDECIMAL               	00000000EH
#Define LOCALE_STHOUSAND              	00000000FH
#Define LOCALE_SGROUPING              	000000010H
#Define LOCALE_IDIGITS                	000000011H
#Define LOCALE_ILZERO                 	000000012H
#Define LOCALE_INEGNUMBER             	000001010H
#Define LOCALE_SNATIVEDIGITS          	000000013H

#Define LOCALE_SCURRENCY              	000000014H
#Define LOCALE_SINTLSYMBOL            	000000015H
#Define LOCALE_SMONDECIMALSEP         	000000016H
#Define LOCALE_SMONTHOUSANDSEP        	000000017H
#Define LOCALE_SMONGROUPING           	000000018H
#Define LOCALE_ICURRDIGITS            	000000019H
#Define LOCALE_IINTLCURRDIGITS        	00000001AH
#Define LOCALE_ICURRENCY              	00000001BH
#Define LOCALE_INEGCURR               	00000001CH

#Define LOCALE_SDATE                  	00000001DH
#Define LOCALE_STIME                  	00000001EH
#Define LOCALE_SSHORTDATE             	00000001FH
#Define LOCALE_SLONGDATE              	000000020H
#Define LOCALE_STIMEFORMAT            	000001003H
#Define LOCALE_IDATE                  	000000021H
#Define LOCALE_ILDATE                 	000000022H
#Define LOCALE_ITIME                  	000000023H
#Define LOCALE_ITIMEMARKPOSN          	000001005H
#Define LOCALE_ICENTURY               	000000024H
#Define LOCALE_ITLZERO                	000000025H
#Define LOCALE_IDAYLZERO              	000000026H
#Define LOCALE_IMONLZERO              	000000027H
#Define LOCALE_S1159                  	000000028H
#Define LOCALE_S2359                  	000000029H

#Define LOCALE_ICALENDARTYPE          	000001009H
#Define LOCALE_IOPTIONALCALENDAR      	00000100BH
#Define LOCALE_IFIRSTDAYOFWEEK        	00000100CH
#Define LOCALE_IFIRSTWEEKOFYEAR       	00000100DH

#Define LOCALE_SDAYNAME1              	00000002AH
#Define LOCALE_SDAYNAME2              	00000002BH
#Define LOCALE_SDAYNAME3              	00000002CH
#Define LOCALE_SDAYNAME4              	00000002DH
#Define LOCALE_SDAYNAME5              	00000002EH
#Define LOCALE_SDAYNAME6              	00000002FH
#Define LOCALE_SDAYNAME7              	000000030H
#Define LOCALE_SABBREVDAYNAME1        	000000031H
#Define LOCALE_SABBREVDAYNAME2        	000000032H
#Define LOCALE_SABBREVDAYNAME3        	000000033H
#Define LOCALE_SABBREVDAYNAME4        	000000034H
#Define LOCALE_SABBREVDAYNAME5        	000000035H
#Define LOCALE_SABBREVDAYNAME6        	000000036H
#Define LOCALE_SABBREVDAYNAME7        	000000037H
#Define LOCALE_SMONTHNAME1            	000000038H
#Define LOCALE_SMONTHNAME2            	000000039H
#Define LOCALE_SMONTHNAME3            	00000003AH
#Define LOCALE_SMONTHNAME4            	00000003BH
#Define LOCALE_SMONTHNAME5            	00000003CH
#Define LOCALE_SMONTHNAME6            	00000003DH
#Define LOCALE_SMONTHNAME7            	00000003EH
#Define LOCALE_SMONTHNAME8            	00000003FH
#Define LOCALE_SMONTHNAME9            	000000040H
#Define LOCALE_SMONTHNAME10           	000000041H
#Define LOCALE_SMONTHNAME11           	000000042H
#Define LOCALE_SMONTHNAME12           	000000043H
#Define LOCALE_SMONTHNAME13           	00000100EH
#Define LOCALE_SABBREVMONTHNAME1      	000000044H
#Define LOCALE_SABBREVMONTHNAME2      	000000045H
#Define LOCALE_SABBREVMONTHNAME3      	000000046H
#Define LOCALE_SABBREVMONTHNAME4      	000000047H
#Define LOCALE_SABBREVMONTHNAME5      	000000048H
#Define LOCALE_SABBREVMONTHNAME6      	000000049H
#Define LOCALE_SABBREVMONTHNAME7      	00000004AH
#Define LOCALE_SABBREVMONTHNAME8      	00000004BH
#Define LOCALE_SABBREVMONTHNAME9      	00000004CH
#Define LOCALE_SABBREVMONTHNAME10     	00000004DH
#Define LOCALE_SABBREVMONTHNAME11     	00000004EH
#Define LOCALE_SABBREVMONTHNAME12     	00000004FH
#Define LOCALE_SABBREVMONTHNAME13     	00000100FH

#Define LOCALE_SPOSITIVESIGN          	000000050H
#Define LOCALE_SNEGATIVESIGN          	000000051H
#Define LOCALE_IPOSSIGNPOSN           	000000052H
#Define LOCALE_INEGSIGNPOSN           	000000053H
#Define LOCALE_IPOSSYMPRECEDES        	000000054H
#Define LOCALE_IPOSSEPBYSPACE         	000000055H
#Define LOCALE_INEGSYMPRECEDES        	000000056H
#Define LOCALE_INEGSEPBYSPACE         	000000057H

#Define LOCALE_FONTSIGNATURE          	000000058H
#Define LOCALE_SISO639LANGNAME        	000000059H
#Define LOCALE_SISO3166CTRYNAME       	00000005AH

#Define LOCALE_IDEFAULTEBCDICCODEPAGE 	000001012H
#Define LOCALE_IPAPERSIZE             	00000100AH
#Define LOCALE_SENGCURRNAME           	000001007H
#Define LOCALE_SNATIVECURRNAME        	000001008H
#Define LOCALE_SYEARMONTH             	000001006H
#Define LOCALE_SSORTNAME              	000001013H
#Define LOCALE_IDIGITSUBSTITUTION     	000001014H

#Define TIME_NOMINUTESORSECONDS   		000000001H
#Define TIME_NOSECONDS            		000000002H
#Define TIME_NOTIMEMARKER         		000000004H
#Define TIME_FORCE24HOURFORMAT    		000000008H

#Define DATE_SHORTDATE            		000000001H
#Define DATE_LONGDATE             		000000002H
#Define DATE_USE_ALT_CALENDAR     		000000004H

#Define DATE_YEARMONTH            		000000008H
#Define DATE_LTRREADING           		000000010H
#Define DATE_RTLREADING           		000000020H

#Define CAL_ICALINTVALUE          		000000001H
#Define CAL_SCALNAME              		000000002H
#Define CAL_IYEAROFFSETRANGE      		000000003H
#Define CAL_SERASTRING            		000000004H
#Define CAL_SSHORTDATE            		000000005H
#Define CAL_SLONGDATE             		000000006H
#Define CAL_SDAYNAME1             		000000007H
#Define CAL_SDAYNAME2             		000000008H
#Define CAL_SDAYNAME3             		000000009H
#Define CAL_SDAYNAME4             		00000000AH
#Define CAL_SDAYNAME5             		00000000BH
#Define CAL_SDAYNAME6             		00000000CH
#Define CAL_SDAYNAME7             		00000000DH
#Define CAL_SABBREVDAYNAME1       		00000000EH
#Define CAL_SABBREVDAYNAME2       		00000000FH
#Define CAL_SABBREVDAYNAME3       		000000010H
#Define CAL_SABBREVDAYNAME4       		000000011H
#Define CAL_SABBREVDAYNAME5       		000000012H
#Define CAL_SABBREVDAYNAME6       		000000013H
#Define CAL_SABBREVDAYNAME7       		000000014H
#Define CAL_SMONTHNAME1           		000000015H
#Define CAL_SMONTHNAME2           		000000016H
#Define CAL_SMONTHNAME3           		000000017H
#Define CAL_SMONTHNAME4           		000000018H
#Define CAL_SMONTHNAME5           		000000019H
#Define CAL_SMONTHNAME6           		00000001AH
#Define CAL_SMONTHNAME7           		00000001BH
#Define CAL_SMONTHNAME8           		00000001CH
#Define CAL_SMONTHNAME9           		00000001DH
#Define CAL_SMONTHNAME10          		00000001EH
#Define CAL_SMONTHNAME11          		00000001FH
#Define CAL_SMONTHNAME12          		000000020H
#Define CAL_SMONTHNAME13          		000000021H
#Define CAL_SABBREVMONTHNAME1     		000000022H
#Define CAL_SABBREVMONTHNAME2     		000000023H
#Define CAL_SABBREVMONTHNAME3     		000000024H
#Define CAL_SABBREVMONTHNAME4     		000000025H
#Define CAL_SABBREVMONTHNAME5     		000000026H
#Define CAL_SABBREVMONTHNAME6     		000000027H
#Define CAL_SABBREVMONTHNAME7     		000000028H
#Define CAL_SABBREVMONTHNAME8     		000000029H
#Define CAL_SABBREVMONTHNAME9     		00000002AH
#Define CAL_SABBREVMONTHNAME10    		00000002BH
#Define CAL_SABBREVMONTHNAME11    		00000002CH
#Define CAL_SABBREVMONTHNAME12    		00000002DH
#Define CAL_SABBREVMONTHNAME13    		00000002EH

#Define CAL_SYEARMONTH            		00000002FH

#Define ENUM_ALL_CALENDARS        		0FFFFFFFFH

#Define CAL_GREGORIAN                  1
#Define CAL_GREGORIAN_US               2
#Define CAL_JAPAN                      3
#Define CAL_TAIWAN                     4
#Define CAL_KOREA                      5
#Define CAL_HIJRI                      6
#Define CAL_THAI                       7
#Define CAL_HEBREW                     8
#Define CAL_GREGORIAN_ME_FRENCH        9
#Define CAL_GREGORIAN_ARABIC           10
#Define CAL_GREGORIAN_XLIT_ENGLISH     11
#Define CAL_GREGORIAN_XLIT_FRENCH      12


CPINFO Struct
	MaxCharSize DD
	DefaultChar DB MAX_DEFAULTCHAR Dup ?
	LeadByte DB MAX_LEADBYTES Dup ?
EndS

CPINFOEXA Struct
	MaxCharSize DD
	DefaultChar DB MAX_DEFAULTCHAR Dup ?
	LeadByte DB MAX_LEADBYTES Dup ?
	UnicodeDefaultChar DW
	CodePage DD
	CodePageName DB MAX_PATH Dup ?
EndS

CPINFOEXW Struct
	MaxCharSize DD
	DefaultChar DB MAX_DEFAULTCHAR Dup ?
	LeadByte DB MAX_LEADBYTES Dup ?
	UnicodeDefaultChar DW
	CodePage DD
	CodePageName DW MAX_PATH Dup ?
EndS

NUMBERFMTA Struct
	NumDigits DD
	LeadingZero DD
	Grouping DD
	lpDecimalSep DD
	lpThousandSep DD
	NegativeOrder DD
EndS

NUMBERFMTW Struct
	NumDigits DD
	LeadingZero DD
	Grouping DD
	lpDecimalSep DD
	lpThousandSep DD
	NegativeOrder DD
EndS

CURRENCYFMTA Struct
	NumDigits DD
	LeadingZero DD
	Grouping DD
	lpDecimalSep DD
	lpThousandSep DD
	NegativeOrder DD
	PositiveOrder DD
	lpCurrencySymbol DD
EndS

CURRENCYFMTW Struct
	NumDigits DD
	LeadingZero DD
	Grouping DD
	lpDecimalSep DD
	lpThousandSep DD
	NegativeOrder DD
	PositiveOrder DD
	lpCurrencySymbol DD
EndS


#IF STRINGS UNICODE
	#Define CPINFOEX CPINFOEXW
	#Define NUMBERFMT NUMBERFMTW
	#Define CURRENCYFMT CURRENCYFMTW
	#Define LOCALE_ENUMPROC LOCALE_ENUMPROCW
	#Define CODEPAGE_ENUMPROC CODEPAGE_ENUMPROCW
	#Define DATEFMT_ENUMPROC DATEFMT_ENUMPROCW
	#Define DATEFMT_ENUMPROCEX DATEFMT_ENUMPROCEXW
	#Define TIMEFMT_ENUMPROC TIMEFMT_ENUMPROCW
	#Define CALINFO_ENUMPROC CALINFO_ENUMPROCW
	#Define GetCPInfoEx GetCPInfoExW
	#Define CompareString CompareStringW
	#Define LCMapString LCMapStringW
	#Define GetLocaleInfo GetLocaleInfoW
	#Define SetLocaleInfo SetLocaleInfoW
	#Define GetTimeFormat GetTimeFormatW
	#Define GetDateFormat GetDateFormatW
	#Define GetNumberFormat GetNumberFormatW
	#Define GetCurrencyFormat GetCurrencyFormatW
	#Define EnumCalendarInfo EnumCalendarInfoW
	#Define EnumCalendarInfoEx EnumCalendarInfoExW
	#Define EnumTimeFormats EnumTimeFormatsW
	#Define EnumDateFormats EnumDateFormatsW
	#Define EnumDateFormatsEx EnumDateFormatsExW
	#Define GetStringTypeEx GetStringTypeExW
	#Define GetStringType GetStringTypeW	; ???
	#Define FoldString  FoldStringW
	#Define EnumSystemLocales EnumSystemLocalesW
	#Define EnumSystemCodePages EnumSystemCodePagesW
#ELSE
	#Define CPINFOEX CPINFOEXA
	#Define NUMBERFMT NUMBERFMTA
	#Define CURRENCYFMT CURRENCYFMTA
	#Define LOCALE_ENUMPROC LOCALE_ENUMPROCA
	#Define CODEPAGE_ENUMPROC CODEPAGE_ENUMPROCA
	#Define DATEFMT_ENUMPROC DATEFMT_ENUMPROCA
	#Define DATEFMT_ENUMPROCEX DATEFMT_ENUMPROCEXA
	#Define TIMEFMT_ENUMPROC TIMEFMT_ENUMPROCA
	#Define CALINFO_ENUMPROC CALINFO_ENUMPROCA
	#Define GetCPInfoEx GetCPInfoExA
	#Define CompareString CompareStringA
	#Define LCMapString LCMapStringA
	#Define GetLocaleInfo GetLocaleInfoA
	#Define SetLocaleInfo SetLocaleInfoA
	#Define GetTimeFormat GetTimeFormatA
	#Define GetDateFormat GetDateFormatA
	#Define GetNumberFormat GetNumberFormatA
	#Define GetCurrencyFormat GetCurrencyFormatA
	#Define EnumCalendarInfo EnumCalendarInfoA
	#Define EnumCalendarInfoEx EnumCalendarInfoExA
	#Define EnumTimeFormats EnumTimeFormatsA
	#Define EnumDateFormats EnumDateFormatsA
	#Define EnumDateFormatsEx EnumDateFormatsExA
	#Define GetStringTypeEx GetStringTypeExA
	#Define GetStringType GetStringTypeA	; ???
	#Define FoldString  FoldStringA
	#Define EnumSystemLocales EnumSystemLocalesA
	#Define EnumSystemCodePages EnumSystemCodePagesA
#ENDIF

#ENDIF ;WINNLS_INC
