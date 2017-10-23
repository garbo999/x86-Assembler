;=============================================================;
;          wingdi.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                 (modified on January, 2009)                 ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WINGDI_INC
#Define WINGDI_INC

#Define R2_BLACK            		1
#Define R2_NOTMERGEPEN      		2
#Define R2_MASKNOTPEN       		3
#Define R2_NOTCOPYPEN       		4
#Define R2_MASKPENNOT       		5
#Define R2_NOT              		6
#Define R2_XORPEN           		7
#Define R2_NOTMASKPEN       		8
#Define R2_MASKPEN          		9
#Define R2_NOTXORPEN        		10
#Define R2_NOP              		11
#Define R2_MERGENOTPEN      		12
#Define R2_COPYPEN          		13
#Define R2_MERGEPENNOT      		14
#Define R2_MERGEPEN         		15
#Define R2_WHITE            		16
#Define R2_LAST             		16

#Define SRCCOPY             		000CC0020H
#Define SRCPAINT            		000EE0086H
#Define SRCAND              		0008800C6H
#Define SRCINVERT           		000660046H
#Define SRCERASE            		000440328H
#Define NOTSRCCOPY          		000330008H
#Define NOTSRCERASE         		0001100A6H
#Define MERGECOPY           		000C000CAH
#Define MERGEPAINT          		000BB0226H
#Define PATCOPY             		000F00021H
#Define PATPAINT            		000FB0A09H
#Define PATINVERT           		0005A0049H
#Define DSTINVERT           		000550009H
#Define BLACKNESS           		000000042H
#Define WHITENESS           		000FF0062H

#Define GDI_ERROR					0FFFFFFFFH
#Define HGDI_ERROR					0FFFFFFFFH

#Define ERROR               		0
#Define NULLREGION          		1
#Define SIMPLEREGION        		2
#Define COMPLEXREGION       		3
#Define RGN_ERROR 					ERROR

#Define RGN_AND             		1
#Define RGN_OR              		2
#Define RGN_XOR             		3
#Define RGN_DIFF            		4
#Define RGN_COPY            		5
#Define RGN_MIN             		RGN_AND
#Define RGN_MAX             		RGN_COPY

#Define BLACKONWHITE                1
#Define WHITEONBLACK                2
#Define COLORONCOLOR                3
#Define HALFTONE                    4
#Define MAXSTRETCHBLTMODE           4

#Define STRETCH_ANDSCANS    		BLACKONWHITE
#Define STRETCH_ORSCANS     		WHITEONBLACK
#Define STRETCH_DELETESCANS 		COLORONCOLOR
#Define STRETCH_HALFTONE    		HALFTONE

#Define ALTERNATE                   1
#Define WINDING                     2
#Define POLYFILL_LAST               2

#Define TA_NOUPDATECP               0
#Define TA_UPDATECP                 1

#Define TA_LEFT                 	0
#Define TA_RIGHT                	2
#Define TA_CENTER               	6

#Define TA_TOP                  	0
#Define TA_BOTTOM               	8
#Define TA_BASELINE             	24
#Define TA_RTLREADING           	256
#Define TA_MASK       				(TA_BASELINE + TA_CENTER + TA_UPDATECP + TA_RTLREADING)

#Define VTA_BASELINE 				TA_BASELINE
#Define VTA_LEFT     				TA_BOTTOM
#Define VTA_RIGHT    				TA_TOP
#Define VTA_CENTER   				TA_CENTER
#Define VTA_BOTTOM   				TA_RIGHT
#Define VTA_TOP      				TA_LEFT

#Define ETO_OPAQUE                  00002H
#Define ETO_CLIPPED                 00004H
#Define ETO_GLYPH_INDEX             00010H
#Define ETO_RTLREADING              00080H
#Define ETO_NUMERICSLOCAL           00400H
#Define ETO_NUMERICSLATIN           00800H
#Define ETO_IGNORELANGUAGE          01000H
#Define ETO_PDY                     02000H

#Define ASPECT_FILTERING            00001H

#Define DCB_RESET       			00001H
#Define DCB_ACCUMULATE  			00002H
#Define DCB_DIRTY       			DCB_ACCUMULATE
#Define DCB_SET         			(DCB_RESET | DCB_ACCUMULATE)
#Define DCB_ENABLE      			00004H
#Define DCB_DISABLE     			00008H

#Define META_SETBKCOLOR             00201H
#Define META_SETBKMODE              00102H
#Define META_SETMAPMODE             00103H
#Define META_SETROP2                00104H
#Define META_SETRELABS              00105H
#Define META_SETPOLYFILLMODE        00106H
#Define META_SETSTRETCHBLTMODE      00107H
#Define META_SETTEXTCHAREXTRA       00108H
#Define META_SETTEXTCOLOR           00209H
#Define META_SETTEXTJUSTIFICATION   0020AH
#Define META_SETWINDOWORG           0020BH
#Define META_SETWINDOWEXT           0020CH
#Define META_SETVIEWPORTORG         0020DH
#Define META_SETVIEWPORTEXT         0020EH
#Define META_OFFSETWINDOWORG        0020FH
#Define META_SCALEWINDOWEXT         00410H
#Define META_OFFSETVIEWPORTORG      00211H
#Define META_SCALEVIEWPORTEXT       00412H
#Define META_LINETO                 00213H
#Define META_MOVETO                 00214H
#Define META_EXCLUDECLIPRECT        00415H
#Define META_INTERSECTCLIPRECT      00416H
#Define META_ARC                    00817H
#Define META_ELLIPSE                00418H
#Define META_FLOODFILL              00419H
#Define META_PIE                    0081AH
#Define META_RECTANGLE              0041BH
#Define META_ROUNDRECT              0061CH
#Define META_PATBLT                 0061DH
#Define META_SAVEDC                 0001EH
#Define META_SETPIXEL               0041FH
#Define META_OFFSETCLIPRGN          00220H
#Define META_TEXTOUT                00521H
#Define META_BITBLT                 00922H
#Define META_STRETCHBLT             00B23H
#Define META_POLYGON                00324H
#Define META_POLYLINE               00325H
#Define META_ESCAPE                 00626H
#Define META_RESTOREDC              00127H
#Define META_FILLREGION             00228H
#Define META_FRAMEREGION            00429H
#Define META_INVERTREGION           0012AH
#Define META_PAINTREGION            0012BH
#Define META_SELECTCLIPREGION       0012CH
#Define META_SELECTOBJECT           0012DH
#Define META_SETTEXTALIGN           0012EH
#Define META_CHORD                  00830H
#Define META_SETMAPPERFLAGS         00231H
#Define META_EXTTEXTOUT             00A32H
#Define META_SETDIBTODEV            00D33H
#Define META_SELECTPALETTE          00234H
#Define META_REALIZEPALETTE         00035H
#Define META_ANIMATEPALETTE         00436H
#Define META_SETPALENTRIES          00037H
#Define META_POLYPOLYGON            00538H
#Define META_RESIZEPALETTE          00139H
#Define META_DIBBITBLT              00940H
#Define META_DIBSTRETCHBLT          00B41H
#Define META_DIBCREATEPATTERNBRUSH  00142H
#Define META_STRETCHDIB             00F43H
#Define META_EXTFLOODFILL           00548H
#Define META_DELETEOBJECT           001F0H
#Define META_CREATEPALETTE          000F7H
#Define META_CREATEPATTERNBRUSH     001F9H
#Define META_CREATEPENINDIRECT      002FAH
#Define META_CREATEFONTINDIRECT     002FBH
#Define META_CREATEBRUSHINDIRECT    002FCH
#Define META_CREATEREGION           006FFH

#Define NEWFRAME                    1
#Define ABORTDOC                    2
#Define NEXTBAND                    3
#Define SETCOLORTABLE               4
#Define GETCOLORTABLE               5
#Define FLUSHOUTPUT                 6
#Define DRAFTMODE                   7
#Define QUERYESCSUPPORT             8
#Define SETABORTPROC                9
#Define STARTDOC                    10
#Define ENDDOC                      11
#Define GETPHYSPAGESIZE             12
#Define GETPRINTINGOFFSET           13
#Define GETSCALINGFACTOR            14
#Define MFCOMMENT                   15
#Define GETPENWIDTH                 16
#Define SETCOPYCOUNT                17
#Define SELECTPAPERSOURCE           18
#Define DEVICEDATA                  19
#Define PASSTHROUGH                 19
#Define GETTECHNOLGY                20
#Define GETTECHNOLOGY               20
#Define SETLINECAP                  21
#Define SETLINEJOIN                 22
#Define SETMITERLIMIT               23
#Define BANDINFO                    24
#Define DRAWPATTERNRECT             25
#Define GETVECTORPENSIZE            26
#Define GETVECTORBRUSHSIZE          27
#Define ENABLEDUPLEX                28
#Define GETSETPAPERBINS             29
#Define GETSETPRINTORIENT           30
#Define ENUMPAPERBINS               31
#Define SETDIBSCALING               32
#Define EPSPRINTING                 33
#Define ENUMPAPERMETRICS            34
#Define GETSETPAPERMETRICS          35
#Define POSTSCRIPT_DATA             37
#Define POSTSCRIPT_IGNORE           38
#Define MOUSETRAILS                 39
#Define GETDEVICEUNITS              42

#Define GETEXTENDEDTEXTMETRICS      256
#Define GETEXTENTTABLE              257
#Define GETPAIRKERNTABLE            258
#Define GETTRACKKERNTABLE           259
#Define EXTTEXTOUT                  512
#Define GETFACENAME                 513
#Define DOWNLOADFACE                514
#Define ENABLERELATIVEWIDTHS        768
#Define ENABLEPAIRKERNING           769
#Define SETKERNTRACK                770
#Define SETALLJUSTVALUES            771
#Define SETCHARSET                  772

#Define STRETCHBLT                  2048
#Define GETSETSCREENPARAMS          3072
#Define QUERYDIBSUPPORT             3073
#Define BEGIN_PATH                  4096
#Define CLIP_TO_PATH                4097
#Define END_PATH                    4098
#Define EXT_DEVICE_CAPS             4099
#Define RESTORE_CTM                 4100
#Define SAVE_CTM                    4101
#Define SET_ARC_DIRECTION           4102
#Define SET_BACKGROUND_COLOR        4103
#Define SET_POLY_MODE               4104
#Define SET_SCREEN_ANGLE            4105
#Define SET_SPREAD                  4106
#Define TRANSFORM_CTM               4107
#Define SET_CLIP_BOX                4108
#Define SET_BOUNDS                  4109
#Define SET_MIRROR_MODE             4110
#Define OPENCHANNEL                 4110
#Define DOWNLOADHEADER              4111
#Define CLOSECHANNEL                4112
#Define POSTSCRIPT_PASSTHROUGH      4115
#Define ENCAPSULATED_POSTSCRIPT     4116

#Define POSTSCRIPT_IDENTIFY         4117
#Define POSTSCRIPT_INJECTION        4118

#Define PSIDENT_GDICENTRIC    		0
#Define PSIDENT_PSCENTRIC     		1

#Define   PSINJECT_APPEND       	0
#Define   PSINJECT_REPLACE      	1

#Define PSINJECT_BEGINSTREAM     	0
#Define PSINJECT_PSADOBE         	1
#Define PSINJECT_COMMENTS        	2
#Define PSINJECT_BEGINDEFAULTS   	3
#Define PSINJECT_ENDDEFAULTS     	4
#Define PSINJECT_BEGINPROLOG     	5
#Define PSINJECT_ENDPROLOG       	6
#Define PSINJECT_BEGINSETUP      	7
#Define PSINJECT_ENDSETUP        	8
#Define PSINJECT_ENDPAGECOMMENTS 	9
#Define PSINJECT_BEGINPAGESETUP 	10
#Define PSINJECT_ENDPAGESETUP   	11
#Define PSINJECT_SHOWPAGE       	12
#Define PSINJECT_PAGETRAILER    	13
#Define PSINJECT_TRAILER        	14
#Define PSINJECT_EOF            	15
#Define PSINJECT_ENDSTREAM      	16
#Define PSINJECT_VMSAVE         	17
#Define PSINJECT_VMRESTORE      	18

#Define PSINJECT_DOCNEEDEDRES   	19
#Define PSINJECT_DOCSUPPLIEDRES 	20

#Define PSINJECT_PAGES          	21
#Define PSINJECT_PAGEORDER      	22
#Define PSINJECT_ORIENTATION    	23
#Define PSINJECT_BOUNDINGBOX    	24
#Define PSINJECT_PAGENUMBER     	25
#Define PSINJECT_PAGEBBOX       	26

#Define PSINJECT_MAX            	27

#Define QDI_SETDIBITS               1
#Define QDI_GETDIBITS               2
#Define QDI_DIBTOSCREEN             4
#Define QDI_STRETCHDIB              8

#Define SP_NOTREPORTED              04000H
#Define SP_ERROR                    (-1)
#Define SP_APPABORT                 (-2)
#Define SP_USERABORT                (-3)
#Define SP_OUTOFDISK                (-4)
#Define SP_OUTOFMEMORY              (-5)

#Define PR_JOBSTATUS                00000H

#Define OBJ_PEN             		1
#Define OBJ_BRUSH           		2
#Define OBJ_DC              		3
#Define OBJ_METADC          		4
#Define OBJ_PAL             		5
#Define OBJ_FONT            		6
#Define OBJ_BITMAP          		7
#Define OBJ_REGION          		8
#Define OBJ_METAFILE        		9
#Define OBJ_MEMDC           		10
#Define OBJ_EXTPEN          		11
#Define OBJ_ENHMETADC       		12
#Define OBJ_ENHMETAFILE     		13

#Define MWT_IDENTITY        		1
#Define MWT_LEFTMULTIPLY    		2
#Define MWT_RIGHTMULTIPLY   		3

#Define MWT_MIN             		MWT_IDENTITY
#Define MWT_MAX             		MWT_RIGHTMULTIPLY

#Define CS_ENABLE                   000000001H
#Define CS_DISABLE                  000000002H
#Define CS_DELETE_TRANSFORM         000000003H

#Define LCS_SIGNATURE           	'PSOC'

#Define LCS_sRGB                	'sRGB'
#Define LCS_WINDOWS_COLOR_SPACE		'Win '

#Define LCS_CALIBRATED_RGB          000000000H
#Define LCS_DEVICE_RGB              000000001H
#Define LCS_DEVICE_CMYK             000000002H

#Define LCS_GM_BUSINESS             000000001H
#Define LCS_GM_GRAPHICS             000000002H
#Define LCS_GM_IMAGES               000000004H
#Define LCS_GM_ABS_COLORIMETRIC     000000008H

#Define CM_OUT_OF_GAMUT             255
#Define CM_IN_GAMUT                 0

#Define ICM_ADDPROFILE              1
#Define ICM_DELETEPROFILE           2
#Define ICM_QUERYPROFILE            3
#Define ICM_SETDEFAULTPROFILE       4
#Define ICM_REGISTERICMATCHER       5
#Define ICM_UNREGISTERICMATCHER     6
#Define ICM_QUERYMATCH              7

#Define PROFILE_LINKED          	'LINK'
#Define PROFILE_EMBEDDED        	'MBED'

#Define BI_RGB        				0
#Define BI_RLE8       				1
#Define BI_RLE4       				2
#Define BI_BITFIELDS  				3

#Define TCI_SRCCHARSET  			1
#Define TCI_SRCCODEPAGE 			2
#Define TCI_SRCFONTSIG  			3

#Define TMPF_FIXED_PITCH    		001H
#Define TMPF_VECTOR             	002H
#Define TMPF_DEVICE             	008H
#Define TMPF_TRUETYPE       		004H

#Define NTM_REGULAR     			000000040H
#Define NTM_BOLD        			000000020H
#Define NTM_ITALIC      			000000001H

#Define NTM_NONNEGATIVE_AC  		000010000H
#Define NTM_OPENTYPE        		000020000H
#Define NTM_MULTIPLEMASTER  		000040000H
#Define NTM_MM_INSTANCE     		000080000H
#Define NTM_TYPE1           		000100000H
#Define NTM_DSIG            		000200000H

#Define LF_FACESIZE         		32
#Define LF_FULLFACESIZE     		64

#Define OUT_DEFAULT_PRECIS          0
#Define OUT_STRING_PRECIS           1
#Define OUT_CHARACTER_PRECIS        2
#Define OUT_STROKE_PRECIS           3
#Define OUT_TT_PRECIS               4
#Define OUT_DEVICE_PRECIS           5
#Define OUT_RASTER_PRECIS           6
#Define OUT_TT_ONLY_PRECIS          7
#Define OUT_OUTLINE_PRECIS          8
#Define OUT_SCREEN_OUTLINE_PRECIS   9

#Define CLIP_DEFAULT_PRECIS     	0
#Define CLIP_CHARACTER_PRECIS   	1
#Define CLIP_STROKE_PRECIS      	2
#Define CLIP_MASK               	0FH
#Define CLIP_LH_ANGLES          	010H ;(1<<4)
#Define CLIP_TT_ALWAYS          	020H ;(2<<4)
#Define CLIP_EMBEDDED           	080H ;(8<<4)

#Define DEFAULT_QUALITY         	0
#Define DRAFT_QUALITY           	1
#Define PROOF_QUALITY           	2
#Define NONANTIALIASED_QUALITY  	3
#Define ANTIALIASED_QUALITY     	4

#Define DEFAULT_PITCH           	0
#Define FIXED_PITCH             	1
#Define VARIABLE_PITCH          	2
#Define MONO_FONT               	8

#Define ANSI_CHARSET            	0
#Define DEFAULT_CHARSET         	1
#Define SYMBOL_CHARSET          	2
#Define SHIFTJIS_CHARSET        	128
#Define HANGEUL_CHARSET         	129
#Define HANGUL_CHARSET          	129
#Define GB2312_CHARSET          	134
#Define CHINESEBIG5_CHARSET     	136
#Define OEM_CHARSET             	255
#Define JOHAB_CHARSET           	130
#Define HEBREW_CHARSET          	177
#Define ARABIC_CHARSET          	178
#Define GREEK_CHARSET           	161
#Define TURKISH_CHARSET         	162
#Define VIETNAMESE_CHARSET      	163
#Define THAI_CHARSET            	222
#Define EASTEUROPE_CHARSET      	238
#Define RUSSIAN_CHARSET         	204

#Define MAC_CHARSET             	77
#Define BALTIC_CHARSET          	186

#Define FS_LATIN1               	000000001H
#Define FS_LATIN2               	000000002H
#Define FS_CYRILLIC             	000000004H
#Define FS_GREEK                	000000008H
#Define FS_TURKISH              	000000010H
#Define FS_HEBREW               	000000020H
#Define FS_ARABIC               	000000040H
#Define FS_BALTIC               	000000080H
#Define FS_VIETNAMESE           	000000100H
#Define FS_THAI                 	000010000H
#Define FS_JISJAPAN             	000020000H
#Define FS_CHINESESIMP          	000040000H
#Define FS_WANSUNG              	000080000H
#Define FS_CHINESETRAD          	000100000H
#Define FS_JOHAB                	000200000H
#Define FS_SYMBOL               	080000000H

#Define FF_DONTCARE         		0 ;(0<<4)
#Define FF_ROMAN            		16 ;(1<<4)
#Define FF_SWISS            		32 ;(2<<4)
#Define FF_MODERN           		48 ;(3<<4)
#Define FF_SCRIPT           		64 ;(4<<4)
#Define FF_DECORATIVE       		80 ;(5<<4)

#Define FW_DONTCARE         		0
#Define FW_THIN             		100
#Define FW_EXTRALIGHT       		200
#Define FW_LIGHT            		300
#Define FW_NORMAL           		400
#Define FW_MEDIUM           		500
#Define FW_SEMIBOLD         		600
#Define FW_BOLD             		700
#Define FW_EXTRABOLD        		800
#Define FW_HEAVY            		900

#Define FW_ULTRALIGHT       		FW_EXTRALIGHT
#Define FW_REGULAR          		FW_NORMAL
#Define FW_DEMIBOLD         		FW_SEMIBOLD
#Define FW_ULTRABOLD        		FW_EXTRABOLD
#Define FW_BLACK            		FW_HEAVY

#Define PANOSE_COUNT               10
#Define PAN_FAMILYTYPE_INDEX       0
#Define PAN_SERIFSTYLE_INDEX       1
#Define PAN_WEIGHT_INDEX           2
#Define PAN_PROPORTION_INDEX       3
#Define PAN_CONTRAST_INDEX         4
#Define PAN_STROKEVARIATION_INDEX  5
#Define PAN_ARMSTYLE_INDEX         6
#Define PAN_LETTERFORM_INDEX       7
#Define PAN_MIDLINE_INDEX          8
#Define PAN_XHEIGHT_INDEX          9

#Define PAN_CULTURE_LATIN          0

#Define PAN_ANY                         0
#Define PAN_NO_FIT                      1

#Define PAN_FAMILY_TEXT_DISPLAY         2
#Define PAN_FAMILY_SCRIPT               3
#Define PAN_FAMILY_DECORATIVE           4
#Define PAN_FAMILY_PICTORIAL            5

#Define PAN_SERIF_COVE                  2
#Define PAN_SERIF_OBTUSE_COVE           3
#Define PAN_SERIF_SQUARE_COVE           4
#Define PAN_SERIF_OBTUSE_SQUARE_COVE	5
#Define PAN_SERIF_SQUARE                6
#Define PAN_SERIF_THIN                  7
#Define PAN_SERIF_BONE                  8
#Define PAN_SERIF_EXAGGERATED           9
#Define PAN_SERIF_TRIANGLE             10
#Define PAN_SERIF_NORMAL_SANS          11
#Define PAN_SERIF_OBTUSE_SANS          12
#Define PAN_SERIF_PERP_SANS            13
#Define PAN_SERIF_FLARED               14
#Define PAN_SERIF_ROUNDED              15

#Define PAN_WEIGHT_VERY_LIGHT           2
#Define PAN_WEIGHT_LIGHT                3
#Define PAN_WEIGHT_THIN                 4
#Define PAN_WEIGHT_BOOK                 5
#Define PAN_WEIGHT_MEDIUM               6
#Define PAN_WEIGHT_DEMI                 7
#Define PAN_WEIGHT_BOLD                 8
#Define PAN_WEIGHT_HEAVY                9
#Define PAN_WEIGHT_BLACK               10
#Define PAN_WEIGHT_NORD                11

#Define PAN_PROP_OLD_STYLE              2
#Define PAN_PROP_MODERN                 3
#Define PAN_PROP_EVEN_WIDTH             4
#Define PAN_PROP_EXPANDED               5
#Define PAN_PROP_CONDENSED              6
#Define PAN_PROP_VERY_EXPANDED          7
#Define PAN_PROP_VERY_CONDENSED         8
#Define PAN_PROP_MONOSPACED             9

#Define PAN_CONTRAST_NONE               2
#Define PAN_CONTRAST_VERY_LOW           3
#Define PAN_CONTRAST_LOW                4
#Define PAN_CONTRAST_MEDIUM_LOW         5
#Define PAN_CONTRAST_MEDIUM             6
#Define PAN_CONTRAST_MEDIUM_HIGH        7
#Define PAN_CONTRAST_HIGH               8
#Define PAN_CONTRAST_VERY_HIGH          9

#Define PAN_STROKE_GRADUAL_DIAG         2
#Define PAN_STROKE_GRADUAL_TRAN         3
#Define PAN_STROKE_GRADUAL_VERT         4
#Define PAN_STROKE_GRADUAL_HORZ         5
#Define PAN_STROKE_RAPID_VERT           6
#Define PAN_STROKE_RAPID_HORZ           7
#Define PAN_STROKE_INSTANT_VERT         8

#Define PAN_STRAIGHT_ARMS_HORZ          2
#Define PAN_STRAIGHT_ARMS_WEDGE         3
#Define PAN_STRAIGHT_ARMS_VERT          4
#Define PAN_STRAIGHT_ARMS_SINGLE_SERIF  5
#Define PAN_STRAIGHT_ARMS_DOUBLE_SERIF  6
#Define PAN_BENT_ARMS_HORZ              7
#Define PAN_BENT_ARMS_WEDGE             8
#Define PAN_BENT_ARMS_VERT              9
#Define PAN_BENT_ARMS_SINGLE_SERIF     10
#Define PAN_BENT_ARMS_DOUBLE_SERIF     11

#Define PAN_LETT_NORMAL_CONTACT         2
#Define PAN_LETT_NORMAL_WEIGHTED        3
#Define PAN_LETT_NORMAL_BOXED           4
#Define PAN_LETT_NORMAL_FLATTENED       5
#Define PAN_LETT_NORMAL_ROUNDED         6
#Define PAN_LETT_NORMAL_OFF_CENTER      7
#Define PAN_LETT_NORMAL_SQUARE          8
#Define PAN_LETT_OBLIQUE_CONTACT        9
#Define PAN_LETT_OBLIQUE_WEIGHTED      10
#Define PAN_LETT_OBLIQUE_BOXED         11
#Define PAN_LETT_OBLIQUE_FLATTENED     12
#Define PAN_LETT_OBLIQUE_ROUNDED       13
#Define PAN_LETT_OBLIQUE_OFF_CENTER    14
#Define PAN_LETT_OBLIQUE_SQUARE        15

#Define PAN_MIDLINE_STANDARD_TRIMMED    2
#Define PAN_MIDLINE_STANDARD_POINTED    3
#Define PAN_MIDLINE_STANDARD_SERIFED    4
#Define PAN_MIDLINE_HIGH_TRIMMED        5
#Define PAN_MIDLINE_HIGH_POINTED        6
#Define PAN_MIDLINE_HIGH_SERIFED        7
#Define PAN_MIDLINE_CONSTANT_TRIMMED    8
#Define PAN_MIDLINE_CONSTANT_POINTED    9
#Define PAN_MIDLINE_CONSTANT_SERIFED   10
#Define PAN_MIDLINE_LOW_TRIMMED        11
#Define PAN_MIDLINE_LOW_POINTED        12
#Define PAN_MIDLINE_LOW_SERIFED        13

#Define PAN_XHEIGHT_CONSTANT_SMALL      2
#Define PAN_XHEIGHT_CONSTANT_STD        3
#Define PAN_XHEIGHT_CONSTANT_LARGE      4
#Define PAN_XHEIGHT_DUCKING_SMALL       5
#Define PAN_XHEIGHT_DUCKING_STD         6
#Define PAN_XHEIGHT_DUCKING_LARGE       7

#Define ELF_VENDOR_SIZE     			4

#Define ELF_VERSION         			0
#Define ELF_CULTURE_LATIN   			0

#Define RASTER_FONTTYPE     			00001H
#Define DEVICE_FONTTYPE     			0002H
#Define TRUETYPE_FONTTYPE   			0004H

#Define PC_RESERVED     				001H
#Define PC_EXPLICIT     				002H
#Define PC_NOCOLLAPSE   				004H

#Define TRANSPARENT         			1
#Define OPAQUE              			2
#Define BKMODE_LAST         			2

#Define GM_COMPATIBLE       			1
#Define GM_ADVANCED         			2
#Define GM_LAST             			2

#Define PT_CLOSEFIGURE      			001H
#Define PT_LINETO           			002H
#Define PT_BEZIERTO         			004H
#Define PT_MOVETO           			006H

#Define MM_TEXT             			1
#Define MM_LOMETRIC         			2
#Define MM_HIMETRIC         			3
#Define MM_LOENGLISH        			4
#Define MM_HIENGLISH        			5
#Define MM_TWIPS            			6
#Define MM_ISOTROPIC        			7
#Define MM_ANISOTROPIC      			8

#Define MM_MIN              			MM_TEXT
#Define MM_MAX              			MM_ANISOTROPIC
#Define MM_MAX_FIXEDSCALE   			MM_TWIPS

#Define ABSOLUTE            			1
#Define RELATIVE            			2

#Define WHITE_BRUSH         			0
#Define LTGRAY_BRUSH        			1
#Define GRAY_BRUSH          			2
#Define DKGRAY_BRUSH        			3
#Define BLACK_BRUSH         			4
#Define NULL_BRUSH          			5
#Define HOLLOW_BRUSH        			NULL_BRUSH
#Define WHITE_PEN           			6
#Define BLACK_PEN           			7
#Define NULL_PEN            			8
#Define OEM_FIXED_FONT      			10
#Define ANSI_FIXED_FONT     			11
#Define ANSI_VAR_FONT       			12
#Define SYSTEM_FONT         			13
#Define DEVICE_DEFAULT_FONT 			14
#Define DEFAULT_PALETTE     			15
#Define SYSTEM_FIXED_FONT   			16

#Define DEFAULT_GUI_FONT    			17

#Define DC_BRUSH            			18
#Define DC_PEN              			19

#Define STOCK_LAST          			19

#IFDEF _WINNT40
	#UNDEF STOCK_LAST
	#Define STOCK_LAST          		17
#ENDIF

#IFDEF _WIN9x
	#UNDEF STOCK_LAST
	#Define STOCK_LAST          		16
#ENDIF

#Define CLR_INVALID     				0FFFFFFFFH

#Define BS_SOLID            			0
#Define BS_NULL             			1
#Define BS_HOLLOW           			BS_NULL
#Define BS_HATCHED          			2
#Define BS_PATTERN          			3
#Define BS_INDEXED          			4
#Define BS_DIBPATTERN       			5
#Define BS_DIBPATTERNPT     			6
#Define BS_PATTERN8X8       			7
#Define BS_DIBPATTERN8X8    			8
#Define BS_MONOPATTERN      			9

#Define HS_HORIZONTAL       			0
#Define HS_VERTICAL         			1
#Define HS_FDIAGONAL        			2
#Define HS_BDIAGONAL        			3
#Define HS_CROSS            			4
#Define HS_DIAGCROSS        			5

#Define PS_SOLID            			0
#Define PS_DASH             			1
#Define PS_DOT              			2
#Define PS_DASHDOT          			3
#Define PS_DASHDOTDOT       			4
#Define PS_NULL             			5
#Define PS_INSIDEFRAME      			6
#Define PS_USERSTYLE        			7
#Define PS_ALTERNATE        			8
#Define PS_STYLE_MASK       			00000000FH

#Define PS_ENDCAP_ROUND     			000000000H
#Define PS_ENDCAP_SQUARE    			000000100H
#Define PS_ENDCAP_FLAT      			000000200H
#Define PS_ENDCAP_MASK      			000000F00H

#Define PS_JOIN_ROUND       			000000000H
#Define PS_JOIN_BEVEL       			000001000H
#Define PS_JOIN_MITER       			000002000H
#Define PS_JOIN_MASK        			00000F000H

#Define PS_COSMETIC         			000000000H
#Define PS_GEOMETRIC        			000010000H
#Define PS_TYPE_MASK        			0000F0000H

#Define AD_COUNTERCLOCKWISE 			1
#Define AD_CLOCKWISE        			2

#Define DRIVERVERSION 					0
#Define TECHNOLOGY    					2
#Define HORZSIZE      					4
#Define VERTSIZE      					6
#Define HORZRES       					8
#Define VERTRES       					10
#Define BITSPIXEL     					12
#Define PLANES        					14
#Define NUMBRUSHES    					16
#Define NUMPENS       					18
#Define NUMMARKERS    					20
#Define NUMFONTS      					22
#Define NUMCOLORS     					24
#Define PDEVICESIZE   					26
#Define CURVECAPS     					28
#Define LINECAPS      					30
#Define POLYGONALCAPS 					32
#Define TEXTCAPS      					34
#Define CLIPCAPS      					36
#Define RASTERCAPS    					38
#Define ASPECTX       					40
#Define ASPECTY       					42
#Define ASPECTXY      					44

#Define SHADEBLENDCAPS 					45

#Define LOGPIXELSX    					88
#Define LOGPIXELSY    					90

#Define SIZEPALETTE  					104
#Define NUMRESERVED  					106
#Define COLORRES     					108

#Define PHYSICALWIDTH   				110
#Define PHYSICALHEIGHT  				111
#Define PHYSICALOFFSETX 				112
#Define PHYSICALOFFSETY 				113
#Define SCALINGFACTORX  				114
#Define SCALINGFACTORY  				115

#Define VREFRESH        				116
#Define DESKTOPVERTRES  				117
#Define DESKTOPHORZRES  				118
#Define BLTALIGNMENT    				119

#Define DT_PLOTTER          			0
#Define DT_RASDISPLAY       			1
#Define DT_RASPRINTER       			2
#Define DT_RASCAMERA        			3
#Define DT_CHARSTREAM       			4
#Define DT_METAFILE         			5
#Define DT_DISPFILE         			6

#Define CC_NONE             			0
#Define CC_CIRCLES          			1
#Define CC_PIE              			2
#Define CC_CHORD            			4
#Define CC_ELLIPSES         			8
#Define CC_WIDE             			16
#Define CC_STYLED           			32
#Define CC_WIDESTYLED       			64
#Define CC_INTERIORS        			128
#Define CC_ROUNDRECT        			256

#Define LC_NONE             			0
#Define LC_POLYLINE         			2
#Define LC_MARKER           			4
#Define LC_POLYMARKER       			8
#Define LC_WIDE             			16
#Define LC_STYLED           			32
#Define LC_WIDESTYLED       			64
#Define LC_INTERIORS        			128

#Define PC_NONE             			0
#Define PC_POLYGON          			1
#Define PC_RECTANGLE        			2
#Define PC_WINDPOLYGON      			4
#Define PC_TRAPEZOID        			4
#Define PC_SCANLINE         			8
#Define PC_WIDE             			16
#Define PC_STYLED           			32
#Define PC_WIDESTYLED       			64
#Define PC_INTERIORS        			128
#Define PC_POLYPOLYGON      			256
#Define PC_PATHS            			512

#Define CP_NONE             			0
#Define CP_RECTANGLE        			1
#Define CP_REGION           			2

#Define TC_OP_CHARACTER     			000000001H
#Define TC_OP_STROKE        			000000002H
#Define TC_CP_STROKE        			000000004H
#Define TC_CR_90            			000000008H
#Define TC_CR_ANY           			000000010H
#Define TC_SF_X_YINDEP      			000000020H
#Define TC_SA_DOUBLE        			000000040H
#Define TC_SA_INTEGER       			000000080H
#Define TC_SA_CONTIN        			000000100H
#Define TC_EA_DOUBLE        			000000200H
#Define TC_IA_ABLE          			000000400H
#Define TC_UA_ABLE          			000000800H
#Define TC_SO_ABLE          			000001000H
#Define TC_RA_ABLE          			000002000H
#Define TC_VA_ABLE          			000004000H
#Define TC_RESERVED         			000008000H
#Define TC_SCROLLBLT        			000010000H

#Define RC_NONE							0
#Define RC_BITBLT           			1
#Define RC_BANDING          			2
#Define RC_SCALING          			4
#Define RC_BITMAP64         			8
#Define RC_GDI20_OUTPUT     			00010H
#Define RC_GDI20_STATE      			00020H
#Define RC_SAVEBITMAP       			00040H
#Define RC_DI_BITMAP        			00080H
#Define RC_PALETTE          			00100H
#Define RC_DIBTODEV         			00200H
#Define RC_BIGFONT          			00400H
#Define RC_STRETCHBLT       			00800H
#Define RC_FLOODFILL        			01000H
#Define RC_STRETCHDIB       			02000H
#Define RC_OP_DX_OUTPUT     			04000H
#Define RC_DEVBITS          			08000H

#Define SB_NONE             			000000000H
#Define SB_CONST_ALPHA      			000000001H
#Define SB_PIXEL_ALPHA      			000000002H
#Define SB_PREMULT_ALPHA    			000000004H

#Define SB_GRAD_RECT        			000000010H
#Define SB_GRAD_TRI         			000000020H

#Define DIB_RGB_COLORS      			0
#Define DIB_PAL_COLORS      			1

#Define SYSPAL_ERROR    				0
#Define SYSPAL_STATIC   				1
#Define SYSPAL_NOSTATIC 				2
#Define SYSPAL_NOSTATIC256 				3

#Define CBM_INIT        				004H

#Define  FLOODFILLBORDER   				0
#Define  FLOODFILLSURFACE  				1

#Define CCHDEVICENAME 					32

#Define CCHFORMNAME 					32

#Define DM_SPECVERSION					00401H

#IFDEF _WIN9x
	#UNDEF DM_SPECVERSION
	#Define DM_SPECVERSION				00400H
#ENDIF

#Define DM_ORIENTATION      			000000001H
#Define DM_PAPERSIZE        			000000002H
#Define DM_PAPERLENGTH      			000000004H
#Define DM_PAPERWIDTH       			000000008H
#Define DM_SCALE            			000000010H

#Define DM_POSITION         			000000020H
#Define DM_COPIES           			000000100H
#Define DM_DEFAULTSOURCE    			000000200H
#Define DM_PRINTQUALITY     			000000400H
#Define DM_COLOR            			000000800H
#Define DM_DUPLEX           			000001000H
#Define DM_YRESOLUTION      			000002000H
#Define DM_TTOPTION         			000004000H
#Define DM_COLLATE          			000008000H
#Define DM_FORMNAME         			000010000H
#Define DM_LOGPIXELS        			000020000H
#Define DM_BITSPERPEL       			000040000H
#Define DM_PELSWIDTH        			000080000H
#Define DM_PELSHEIGHT       			000100000H
#Define DM_DISPLAYFLAGS     			000200000H
#Define DM_DISPLAYFREQUENCY 			000400000H
#Define DM_ICMMETHOD        			000800000H
#Define DM_ICMINTENT        			001000000H
#Define DM_MEDIATYPE        			002000000H
#Define DM_DITHERTYPE       			004000000H
#Define DM_PANNINGWIDTH     			008000000H
#Define DM_PANNINGHEIGHT    			010000000H

#Define DMORIENT_PORTRAIT   			1
#Define DMORIENT_LANDSCAPE  			2

#Define DMPAPER_FIRST                	DMPAPER_LETTER
#Define DMPAPER_LETTER               	1
#Define DMPAPER_LETTERSMALL          	2
#Define DMPAPER_TABLOID              	3
#Define DMPAPER_LEDGER               	4
#Define DMPAPER_LEGAL                	5
#Define DMPAPER_STATEMENT            	6
#Define DMPAPER_EXECUTIVE            	7
#Define DMPAPER_A3                   	8
#Define DMPAPER_A4                   	9
#Define DMPAPER_A4SMALL             	10
#Define DMPAPER_A5                  	11
#Define DMPAPER_B4                  	12
#Define DMPAPER_B5                  	13
#Define DMPAPER_FOLIO               	14
#Define DMPAPER_QUARTO              	15
#Define DMPAPER_10X14               	16
#Define DMPAPER_11X17               	17
#Define DMPAPER_NOTE                	18
#Define DMPAPER_ENV_9               	19
#Define DMPAPER_ENV_10              	20
#Define DMPAPER_ENV_11              	21
#Define DMPAPER_ENV_12              	22
#Define DMPAPER_ENV_14              	23
#Define DMPAPER_CSHEET              	24
#Define DMPAPER_DSHEET              	25
#Define DMPAPER_ESHEET              	26
#Define DMPAPER_ENV_DL              	27
#Define DMPAPER_ENV_C5              	28
#Define DMPAPER_ENV_C3              	29
#Define DMPAPER_ENV_C4              	30
#Define DMPAPER_ENV_C6              	31
#Define DMPAPER_ENV_C65             	32
#Define DMPAPER_ENV_B4              	33
#Define DMPAPER_ENV_B5              	34
#Define DMPAPER_ENV_B6              	35
#Define DMPAPER_ENV_ITALY           	36
#Define DMPAPER_ENV_MONARCH         	37
#Define DMPAPER_ENV_PERSONAL        	38
#Define DMPAPER_FANFOLD_US          	39
#Define DMPAPER_FANFOLD_STD_GERMAN  	40
#Define DMPAPER_FANFOLD_LGL_GERMAN  	41
#Define DMPAPER_ISO_B4              	42
#Define DMPAPER_JAPANESE_POSTCARD   	43
#Define DMPAPER_9X11                	44
#Define DMPAPER_10X11               	45
#Define DMPAPER_15X11               	46
#Define DMPAPER_ENV_INVITE          	47
#Define DMPAPER_RESERVED_48         	48
#Define DMPAPER_RESERVED_49         	49
#Define DMPAPER_LETTER_EXTRA        	50
#Define DMPAPER_LEGAL_EXTRA         	51
#Define DMPAPER_TABLOID_EXTRA       	52
#Define DMPAPER_A4_EXTRA            	53
#Define DMPAPER_LETTER_TRANSVERSE   	54
#Define DMPAPER_A4_TRANSVERSE       	55
#Define DMPAPER_LETTER_EXTRA_TRANSVERSE 56
#Define DMPAPER_A_PLUS              	57
#Define DMPAPER_B_PLUS              	58
#Define DMPAPER_LETTER_PLUS         	59
#Define DMPAPER_A4_PLUS             	60
#Define DMPAPER_A5_TRANSVERSE       	61
#Define DMPAPER_B5_TRANSVERSE       	62
#Define DMPAPER_A3_EXTRA            	63
#Define DMPAPER_A5_EXTRA            	64
#Define DMPAPER_B5_EXTRA            	65
#Define DMPAPER_A2                  	66
#Define DMPAPER_A3_TRANSVERSE       	67
#Define DMPAPER_A3_EXTRA_TRANSVERSE 	68
#Define DMPAPER_DBL_JAPANESE_POSTCARD	69
#Define DMPAPER_A6                  	70
#Define DMPAPER_JENV_KAKU2          	71
#Define DMPAPER_JENV_KAKU3          	72
#Define DMPAPER_JENV_CHOU3          	73
#Define DMPAPER_JENV_CHOU4          	74
#Define DMPAPER_LETTER_ROTATED      	75
#Define DMPAPER_A3_ROTATED          	76
#Define DMPAPER_A4_ROTATED          	77
#Define DMPAPER_A5_ROTATED          	78
#Define DMPAPER_B4_JIS_ROTATED      	79
#Define DMPAPER_B5_JIS_ROTATED      	80
#Define DMPAPER_JAPANESE_POSTCARD_ROTATED 81
#Define DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED 82
#Define DMPAPER_A6_ROTATED          	83
#Define DMPAPER_JENV_KAKU2_ROTATED  	84
#Define DMPAPER_JENV_KAKU3_ROTATED  	85
#Define DMPAPER_JENV_CHOU3_ROTATED  	86
#Define DMPAPER_JENV_CHOU4_ROTATED  	87
#Define DMPAPER_B6_JIS              	88
#Define DMPAPER_B6_JIS_ROTATED      	89
#Define DMPAPER_12X11               	90
#Define DMPAPER_JENV_YOU4           	91
#Define DMPAPER_JENV_YOU4_ROTATED   	92
#Define DMPAPER_P16K                	93
#Define DMPAPER_P32K                	94
#Define DMPAPER_P32KBIG             	95
#Define DMPAPER_PENV_1              	96
#Define DMPAPER_PENV_2              	97
#Define DMPAPER_PENV_3              	98
#Define DMPAPER_PENV_4              	99
#Define DMPAPER_PENV_5              	100
#Define DMPAPER_PENV_6              	101
#Define DMPAPER_PENV_7              	102
#Define DMPAPER_PENV_8              	103
#Define DMPAPER_PENV_9              	104
#Define DMPAPER_PENV_10             	105
#Define DMPAPER_P16K_ROTATED        	106
#Define DMPAPER_P32K_ROTATED        	107
#Define DMPAPER_P32KBIG_ROTATED     	108
#Define DMPAPER_PENV_1_ROTATED      	109
#Define DMPAPER_PENV_2_ROTATED      	110
#Define DMPAPER_PENV_3_ROTATED      	111
#Define DMPAPER_PENV_4_ROTATED      	112
#Define DMPAPER_PENV_5_ROTATED      	113
#Define DMPAPER_PENV_6_ROTATED      	114
#Define DMPAPER_PENV_7_ROTATED      	115
#Define DMPAPER_PENV_8_ROTATED      	116
#Define DMPAPER_PENV_9_ROTATED      	117
#Define DMPAPER_PENV_10_ROTATED     	118

#IF (WINVER >= 00500H)
	#Define DMPAPER_LAST                DMPAPER_PENV_10_ROTATED
#ELIF (WINVER >= 00400H)
	#Define DMPAPER_LAST                DMPAPER_A3_EXTRA_TRANSVERSE
#ELSE
	#Define DMPAPER_LAST                DMPAPER_FANFOLD_LGL_GERMAN
#ENDIF

#Define DMPAPER_USER                	256

#Define DMBIN_FIRST         			DMBIN_UPPER
#Define DMBIN_UPPER         			1
#Define DMBIN_ONLYONE       			1
#Define DMBIN_LOWER         			2
#Define DMBIN_MIDDLE        			3
#Define DMBIN_MANUAL        			4
#Define DMBIN_ENVELOPE      			5
#Define DMBIN_ENVMANUAL     			6
#Define DMBIN_AUTO          			7
#Define DMBIN_TRACTOR       			8
#Define DMBIN_SMALLFMT      			9
#Define DMBIN_LARGEFMT      			10
#Define DMBIN_LARGECAPACITY 			11
#Define DMBIN_CASSETTE      			14
#Define DMBIN_FORMSOURCE    			15
#Define DMBIN_LAST          			DMBIN_FORMSOURCE

#Define DMBIN_USER          			256

#Define DMRES_DRAFT         			(-1)
#Define DMRES_LOW           			(-2)
#Define DMRES_MEDIUM        			(-3)
#Define DMRES_HIGH          			(-4)

#Define DMCOLOR_MONOCHROME  			1
#Define DMCOLOR_COLOR       			2

#Define DMDUP_SIMPLEX    				1
#Define DMDUP_VERTICAL   				2
#Define DMDUP_HORIZONTAL 				3

#Define DMTT_BITMAP     				1
#Define DMTT_DOWNLOAD   				2
#Define DMTT_SUBDEV     				3
#Define DMTT_DOWNLOAD_OUTLINE			4

#Define DMCOLLATE_FALSE  				0
#Define DMCOLLATE_TRUE   				1

#Define DMDISPLAYFLAGS_TEXTMODE 		000000004H

#Define DMICMMETHOD_NONE    			1
#Define DMICMMETHOD_SYSTEM  			2
#Define DMICMMETHOD_DRIVER  			3
#Define DMICMMETHOD_DEVICE  			4

#Define DMICMMETHOD_USER  				256

#Define DMICM_SATURATE          		1
#Define DMICM_CONTRAST          		2
#Define DMICM_COLORIMETRIC       		3
#Define DMICM_ABS_COLORIMETRIC   		4

#Define DMICM_USER        				256

#Define DMMEDIA_STANDARD      			1
#Define DMMEDIA_TRANSPARENCY  			2
#Define DMMEDIA_GLOSSY        			3

#Define DMMEDIA_USER        			256

#Define DMDITHER_NONE       			1
#Define DMDITHER_COARSE     			2
#Define DMDITHER_FINE       			3
#Define DMDITHER_LINEART    			4
#Define DMDITHER_ERRORDIFFUSION			5
#Define DMDITHER_RESERVED6      		6
#Define DMDITHER_RESERVED7      		7
#Define DMDITHER_RESERVED8      		8
#Define DMDITHER_RESERVED9      		9
#Define DMDITHER_GRAYSCALE  			10

#Define DMDITHER_USER     				256

#Define DISPLAY_DEVICE_ATTACHED_TO_DESKTOP 000000001H
#Define DISPLAY_DEVICE_MULTI_DRIVER        000000002H
#Define DISPLAY_DEVICE_PRIMARY_DEVICE      000000004H
#Define DISPLAY_DEVICE_MIRRORING_DRIVER    000000008H
#Define DISPLAY_DEVICE_VGA_COMPATIBLE      000000010H

#Define GGO_METRICS        					0
#Define GGO_BITMAP         					1
#Define GGO_NATIVE         					2
#Define GGO_BEZIER         					3

#Define  GGO_GRAY2_BITMAP   				4
#Define  GGO_GRAY4_BITMAP   				5
#Define  GGO_GRAY8_BITMAP   				6
#Define  GGO_GLYPH_INDEX    				00080H

#Define TT_POLYGON_TYPE   					24

#Define TT_PRIM_LINE       					1
#Define TT_PRIM_QSPLINE    					2
#Define TT_PRIM_CSPLINE    					3

#Define GCP_DBCS           					00001H
#Define GCP_REORDER        					00002H
#Define GCP_USEKERNING     					00008H
#Define GCP_GLYPHSHAPE     					00010H
#Define GCP_LIGATE         					00020H

#Define GCP_DIACRITIC      					00100H
#Define GCP_KASHIDA        					00400H
#Define GCP_ERROR          					08000H
#Define FLI_MASK           					0103BH

#Define GCP_JUSTIFY        					000010000H
#Define FLI_GLYPHS         					000040000H
#Define GCP_CLASSIN        					000080000H
#Define GCP_MAXEXTENT      					000100000H
#Define GCP_JUSTIFYIN      					000200000H
#Define GCP_DISPLAYZWG      				000400000H
#Define GCP_SYMSWAPOFF      				000800000H
#Define GCP_NUMERICOVERRIDE 				001000000H
#Define GCP_NEUTRALOVERRIDE 				002000000H
#Define GCP_NUMERICSLATIN   				004000000H
#Define GCP_NUMERICSLOCAL   				008000000H

#Define GCPCLASS_LATIN                  	1
#Define GCPCLASS_HEBREW                 	2
#Define GCPCLASS_ARABIC                 	2
#Define GCPCLASS_NEUTRAL                	3
#Define GCPCLASS_LOCALNUMBER            	4
#Define GCPCLASS_LATINNUMBER            	5
#Define GCPCLASS_LATINNUMERICTERMINATOR 	6
#Define GCPCLASS_LATINNUMERICSEPARATOR  	7
#Define GCPCLASS_NUMERICSEPARATOR       	8
#Define GCPCLASS_PREBOUNDLTR         		080H
#Define GCPCLASS_PREBOUNDRTL         		040H
#Define GCPCLASS_POSTBOUNDLTR        		020H
#Define GCPCLASS_POSTBOUNDRTL        		010H

#Define GCPGLYPH_LINKBEFORE          		08000H
#Define GCPGLYPH_LINKAFTER           		04000H

#Define PFD_TYPE_RGBA        				0
#Define PFD_TYPE_COLORINDEX  				1

#Define PFD_MAIN_PLANE       				0
#Define PFD_OVERLAY_PLANE    				1
#Define PFD_UNDERLAY_PLANE   				(-1)

#Define PFD_DOUBLEBUFFER            		000000001H
#Define PFD_STEREO                  		000000002H
#Define PFD_DRAW_TO_WINDOW          		000000004H
#Define PFD_DRAW_TO_BITMAP          		000000008H
#Define PFD_SUPPORT_GDI             		000000010H
#Define PFD_SUPPORT_OPENGL          		000000020H
#Define PFD_GENERIC_FORMAT          		000000040H
#Define PFD_NEED_PALETTE            		000000080H
#Define PFD_NEED_SYSTEM_PALETTE     		000000100H
#Define PFD_SWAP_EXCHANGE           		000000200H
#Define PFD_SWAP_COPY               		000000400H
#Define PFD_SWAP_LAYER_BUFFERS      		000000800H
#Define PFD_GENERIC_ACCELERATED     		000001000H
#Define PFD_SUPPORT_DIRECTDRAW      		000002000H

#Define PFD_DEPTH_DONTCARE          		020000000H
#Define PFD_DOUBLEBUFFER_DONTCARE   		040000000H
#Define PFD_STEREO_DONTCARE         		080000000H

#Define DM_UPDATE           				1
#Define DM_COPY             				2
#Define DM_PROMPT           				4
#Define DM_MODIFY           				8

#Define DM_IN_BUFFER        				DM_MODIFY
#Define DM_IN_PROMPT        				DM_PROMPT
#Define DM_OUT_BUFFER       				DM_COPY
#Define DM_OUT_DEFAULT      				DM_UPDATE

#Define DC_FIELDS           				1
#Define DC_PAPERS           				2
#Define DC_PAPERSIZE        				3
#Define DC_MINEXTENT        				4
#Define DC_MAXEXTENT        				5
#Define DC_BINS             				6
#Define DC_DUPLEX           				7
#Define DC_SIZE             				8
#Define DC_EXTRA            				9
#Define DC_VERSION          				10
#Define DC_DRIVER           				11
#Define DC_BINNAMES         				12
#Define DC_ENUMRESOLUTIONS  				13
#Define DC_FILEDEPENDENCIES 				14
#Define DC_TRUETYPE         				15
#Define DC_PAPERNAMES       				16
#Define DC_ORIENTATION      				17
#Define DC_COPIES           				18
#Define DC_BINADJUST            			19
#Define DC_EMF_COMPLIANT        			20
#Define DC_DATATYPE_PRODUCED    			21
#Define DC_COLLATE              			22
#Define DC_MANUFACTURER         			23
#Define DC_MODEL                			24
#Define DC_COLORDEVICE          			23
#Define DC_NUP                  			24
#Define DC_PERSONALITY          			25
#Define DC_PRINTRATE            			26
#Define DC_PRINTRATEUNIT        			27
#Define PRINTRATEUNIT_PPM     				1
#Define PRINTRATEUNIT_CPS     				2
#Define PRINTRATEUNIT_LPM     				3
#Define PRINTRATEUNIT_IPM     				4
#Define DC_PRINTERMEM           			28
#Define DC_MEDIAREADY           			29

#Define DCTT_BITMAP             			00000001H
#Define DCTT_DOWNLOAD           			00000002H
#Define DCTT_SUBDEV             			00000004H
#Define DCTT_DOWNLOAD_OUTLINE   			00000008H

#Define DCBA_FACEUPNONE       				00000H
#Define DCBA_FACEUPCENTER     				00001H
#Define DCBA_FACEUPLEFT       				00002H
#Define DCBA_FACEUPRIGHT      				00003H
#Define DCBA_FACEDOWNNONE     				00100H
#Define DCBA_FACEDOWNCENTER   				00101H
#Define DCBA_FACEDOWNLEFT     				00102H
#Define DCBA_FACEDOWNRIGHT    				00103H

#Define GS_8BIT_INDICES     				000000001H

#Define GGI_MARK_NONEXISTING_GLYPHS			00001H

#Define MM_MAX_AXES_NAMELEN 				16

#Define AC_SRC_OVER                 		000H

#Define AC_SRC_NO_PREMULT_ALPHA     		001H
#Define AC_SRC_NO_ALPHA             		002H
#Define AC_DST_NO_PREMULT_ALPHA     		010H
#Define AC_DST_NO_ALPHA             		020H

#Define GRADIENT_FILL_RECT_H    			000000000H
#Define GRADIENT_FILL_RECT_V    			000000001H
#Define GRADIENT_FILL_TRIANGLE  			000000002H
#Define GRADIENT_FILL_OP_FLAG   			0000000FFH

#Define CA_NEGATIVE                 		00001H
#Define CA_LOG_FILTER               		00002H

#Define ILLUMINANT_DEVICE_DEFAULT   		0
#Define ILLUMINANT_A                		1
#Define ILLUMINANT_B                		2
#Define ILLUMINANT_C                		3
#Define ILLUMINANT_D50              		4
#Define ILLUMINANT_D55              		5
#Define ILLUMINANT_D65              		6
#Define ILLUMINANT_D75              		7
#Define ILLUMINANT_F2               		8
#Define ILLUMINANT_MAX_INDEX        		ILLUMINANT_F2

#Define ILLUMINANT_TUNGSTEN         		ILLUMINANT_A
#Define ILLUMINANT_DAYLIGHT         		ILLUMINANT_C
#Define ILLUMINANT_FLUORESCENT      		ILLUMINANT_F2
#Define ILLUMINANT_NTSC             		ILLUMINANT_C

#Define RGB_GAMMA_MIN               		02500
#Define RGB_GAMMA_MAX               		65000

#Define REFERENCE_WHITE_MIN         		6000
#Define REFERENCE_WHITE_MAX         		10000
#Define REFERENCE_BLACK_MIN         		0
#Define REFERENCE_BLACK_MAX         		4000

#Define COLOR_ADJ_MIN               		(-100)
#Define COLOR_ADJ_MAX               		100

#Define DI_APPBANDING               		000000001H
#Define DI_ROPS_READ_DESTINATION    		000000002H

#Define FONTMAPPER_MAX 						10

#Define ICM_OFF               				1
#Define ICM_ON                				2
#Define ICM_QUERY             				3
#Define ICM_DONE_OUTSIDEDC    				4

#Define ENHMETA_SIGNATURE       			0464D4520H
#Define ENHMETA_STOCK_OBJECT    			080000000H

#Define EMR_HEADER                      	1
#Define EMR_POLYBEZIER                  	2
#Define EMR_POLYGON                     	3
#Define EMR_POLYLINE                    	4
#Define EMR_POLYBEZIERTO                	5
#Define EMR_POLYLINETO                  	6
#Define EMR_POLYPOLYLINE                	7
#Define EMR_POLYPOLYGON                 	8
#Define EMR_SETWINDOWEXTEX              	9
#Define EMR_SETWINDOWORGEX              	10
#Define EMR_SETVIEWPORTEXTEX            	11
#Define EMR_SETVIEWPORTORGEX            	12
#Define EMR_SETBRUSHORGEX               	13
#Define EMR_EOF                         	14
#Define EMR_SETPIXELV                   	15
#Define EMR_SETMAPPERFLAGS              	16
#Define EMR_SETMAPMODE                  	17
#Define EMR_SETBKMODE          				18
#Define EMR_SETPOLYFILLMODE             	19
#Define EMR_SETROP2                     	20
#Define EMR_SETSTRETCHBLTMODE           	21
#Define EMR_SETTEXTALIGN                	22
#Define EMR_SETCOLORADJUSTMENT          	23
#Define EMR_SETTEXTCOLOR                	24
#Define EMR_SETBKCOLOR                  	25
#Define EMR_OFFSETCLIPRGN               	26
#Define EMR_MOVETOEX                    	27
#Define EMR_SETMETARGN                  	28
#Define EMR_EXCLUDECLIPRECT             	29
#Define EMR_INTERSECTCLIPRECT           	30
#Define EMR_SCALEVIEWPORTEXTEX          	31
#Define EMR_SCALEWINDOWEXTEX            	32
#Define EMR_SAVEDC                      	33
#Define EMR_RESTOREDC                   	34
#Define EMR_SETWORLDTRANSFORM           	35
#Define EMR_MODIFYWORLDTRANSFORM        	36
#Define EMR_SELECTOBJECT                	37
#Define EMR_CREATEPEN                   	38
#Define EMR_CREATEBRUSHINDIRECT         	39
#Define EMR_DELETEOBJECT                	40
#Define EMR_ANGLEARC                    	41
#Define EMR_ELLIPSE                     	42
#Define EMR_RECTANGLE                   	43
#Define EMR_ROUNDRECT                   	44
#Define EMR_ARC                         	45
#Define EMR_CHORD                       	46
#Define EMR_PIE                         	47
#Define EMR_SELECTPALETTE               	48
#Define EMR_CREATEPALETTE               	49
#Define EMR_SETPALETTEENTRIES           	50
#Define EMR_RESIZEPALETTE               	51
#Define EMR_REALIZEPALETTE              	52
#Define EMR_EXTFLOODFILL                	53
#Define EMR_LINETO                      	54
#Define EMR_ARCTO                       	55
#Define EMR_POLYDRAW                    	56
#Define EMR_SETARCDIRECTION             	57
#Define EMR_SETMITERLIMIT               	58
#Define EMR_BEGINPATH                   	59
#Define EMR_ENDPATH                     	60
#Define EMR_CLOSEFIGURE                 	61
#Define EMR_FILLPATH                    	62
#Define EMR_STROKEANDFILLPATH           	63
#Define EMR_STROKEPATH                  	64
#Define EMR_FLATTENPATH                 	65
#Define EMR_WIDENPATH                   	66
#Define EMR_SELECTCLIPPATH              	67
#Define EMR_ABORTPATH                   	68

#Define EMR_GDICOMMENT                  	70
#Define EMR_FILLRGN                     	71
#Define EMR_FRAMERGN                    	72
#Define EMR_INVERTRGN                   	73
#Define EMR_PAINTRGN                    	74
#Define EMR_EXTSELECTCLIPRGN            	75
#Define EMR_BITBLT                      	76
#Define EMR_STRETCHBLT                  	77
#Define EMR_MASKBLT                     	78
#Define EMR_PLGBLT                      	79
#Define EMR_SETDIBITSTODEVICE           	80
#Define EMR_STRETCHDIBITS               	81
#Define EMR_EXTCREATEFONTINDIRECTW      	82
#Define EMR_EXTTEXTOUTA                 	83
#Define EMR_EXTTEXTOUTW                 	84
#Define EMR_POLYBEZIER16                	85
#Define EMR_POLYGON16                   	86
#Define EMR_POLYLINE16                  	87
#Define EMR_POLYBEZIERTO16              	88
#Define EMR_POLYLINETO16                	89
#Define EMR_POLYPOLYLINE16              	90
#Define EMR_POLYPOLYGON16               	91
#Define EMR_POLYDRAW16                  	92
#Define EMR_CREATEMONOBRUSH             	93
#Define EMR_CREATEDIBPATTERNBRUSHPT     	94
#Define EMR_EXTCREATEPEN                	95
#Define EMR_POLYTEXTOUTA                	96
#Define EMR_POLYTEXTOUTW                	97

#Define EMR_SETICMMODE                  	98
#Define EMR_CREATECOLORSPACE            	99
#Define EMR_SETCOLORSPACE              		100
#Define EMR_DELETECOLORSPACE           		101
#Define EMR_GLSRECORD                  		102
#Define EMR_GLSBOUNDEDRECORD           		103
#Define EMR_PIXELFORMAT                		104

#Define EMR_DRAWESCAPE                 		105
#Define EMR_EXTESCAPE                  		106
#Define EMR_STARTDOC                   		107
#Define EMR_SMALLTEXTOUT               		108
#Define EMR_FORCEUFIMAPPING            		109
#Define EMR_NAMEDESCAPE                		110
#Define EMR_COLORCORRECTPALETTE        		111
#Define EMR_SETICMPROFILEA             		112
#Define EMR_SETICMPROFILEW             		113
#Define EMR_ALPHABLEND                 		114
#Define EMR_ALPHADIBBLEND              		115
#Define EMR_TRANSPARENTBLT             		116
#Define EMR_TRANSPARENTDIB             		117
#Define EMR_GRADIENTFILL               		118
#Define EMR_SETLINKEDUFIS              		119
#Define EMR_SETTEXTJUSTIFICATION       		120

#Define EMR_MIN                          	1
#Define EMR_MAX                        		120

#Define SETICMPROFILE_EMBEDED           	000000001H


#Define GDICOMMENT_IDENTIFIER           	043494447H
#Define GDICOMMENT_WINDOWS_METAFILE     	080000001H
#Define GDICOMMENT_BEGINGROUP           	000000002H
#Define GDICOMMENT_ENDGROUP             	000000003H
#Define GDICOMMENT_MULTIFORMATS         	040000004H
#Define EPS_SIGNATURE                   	046535045H


#Define WGL_FONT_LINES      				0
#Define WGL_FONT_POLYGONS   				1

#Define LPD_DOUBLEBUFFER        			000000001H
#Define LPD_STEREO              			000000002H
#Define LPD_SUPPORT_GDI         			000000010H
#Define LPD_SUPPORT_OPENGL      			000000020H
#Define LPD_SHARE_DEPTH         			000000040H
#Define LPD_SHARE_STENCIL       			000000080H
#Define LPD_SHARE_ACCUM         			000000100H
#Define LPD_SWAP_EXCHANGE       			000000200H
#Define LPD_SWAP_COPY           			000000400H
#Define LPD_TRANSPARENT         			000001000H

#Define LPD_TYPE_RGBA        				0
#Define LPD_TYPE_COLORINDEX  				1

#Define WGL_SWAP_MAIN_PLANE     			000000001H
#Define WGL_SWAP_OVERLAY1       			000000002H
#Define WGL_SWAP_OVERLAY2       			000000004H
#Define WGL_SWAP_OVERLAY3       			000000008H
#Define WGL_SWAP_OVERLAY4       			000000010H
#Define WGL_SWAP_OVERLAY5       			000000020H
#Define WGL_SWAP_OVERLAY6       			000000040H
#Define WGL_SWAP_OVERLAY7       			000000080H
#Define WGL_SWAP_OVERLAY8       			000000100H
#Define WGL_SWAP_OVERLAY9       			000000200H
#Define WGL_SWAP_OVERLAY10      			000000400H
#Define WGL_SWAP_OVERLAY11      			000000800H
#Define WGL_SWAP_OVERLAY12      			000001000H
#Define WGL_SWAP_OVERLAY13      			000002000H
#Define WGL_SWAP_OVERLAY14      			000004000H
#Define WGL_SWAP_OVERLAY15      			000008000H
#Define WGL_SWAP_UNDERLAY1      			000010000H
#Define WGL_SWAP_UNDERLAY2      			000020000H
#Define WGL_SWAP_UNDERLAY3      			000040000H
#Define WGL_SWAP_UNDERLAY4      			000080000H
#Define WGL_SWAP_UNDERLAY5      			000100000H
#Define WGL_SWAP_UNDERLAY6      			000200000H
#Define WGL_SWAP_UNDERLAY7      			000400000H
#Define WGL_SWAP_UNDERLAY8      			000800000H
#Define WGL_SWAP_UNDERLAY9      			001000000H
#Define WGL_SWAP_UNDERLAY10     			002000000H
#Define WGL_SWAP_UNDERLAY11     			004000000H
#Define WGL_SWAP_UNDERLAY12     			008000000H
#Define WGL_SWAP_UNDERLAY13     			010000000H
#Define WGL_SWAP_UNDERLAY14     			020000000H
#Define WGL_SWAP_UNDERLAY15     			040000000H

#Define WGL_SWAPMULTIPLE_MAX				16


DRAWPATRECT Struct
	ptPosition POINT <>
	ptSize POINT <>
	wStyle DW
	wPattern DW
EndS

PSINJECTDATA Struct 
	DataBytes DD
	InjectionPoint DD
	Flags DD
	Reserved DD
EndS

XFORM Struct
	eM11 DD
	eM12 DD
	eM21 DD
	eM22 DD
	elx DD
	eDy DD
EndS

BITMAP Struct
	bmType DD
	bmWidth DD
	bmHeight DD
	bmWidthBytes DD
	bmPlanes DW
	bmBitsPixel DW
	bmBits DD
EndS

RGBTRIPLE Struct
	rgbtBlue DB
	rgbtGreen DB
	rgbtRed DB
EndS

RGBQUAD Struct
	rgbBlue DB
	rgbGreen DB
	rgbRed DB
	rgbReserved DB
EndS

CIEXYZ Struct
	ciexyzX DD
	ciexyzY DD
	ciexyzZ DD
EndS

CIEXYZTRIPLE Struct
	ciexyzRed CIEXYZ <>
	ciexyzGreen CIEXYZ <>
	ciexyzBlue CIEXYZ <>
EndS

LOGCOLORSPACEA Struct
	lcsSignature DD
	lcsVersion DD
	lcsSize DD
	lcsCSType DD
	lcsIntent DD
	lcsEndpoints CIEXYZTRIPLE <>
	lcsGammaRed DD
	lcsGammaGreen DD
	lcsGammaBlue DD
	lcsFilename DB MAX_PATH Dup ?
EndS

LOGCOLORSPACEW Struct
	lcsSignature DD
	lcsVersion DD
	lcsSize DD
	lcsCSType DD
	lcsIntent DD
	lcsEndpoints CIEXYZTRIPLE <>
	lcsGammaRed DD
	lcsGammaGreen DD
	lcsGammaBlue DD
	lcsFilename DW MAX_PATH Dup ?
EndS

BITMAPCOREHEADER Struct
	bcSize DD
	bcWidth DW
	bcHeight DW
	bcPlanes DW
	bcBitCount DW
EndS

BITMAPINFOHEADER Struct
	biSize DD
	biWidth DD
	biHeight DD
	biPlanes DW
	biBitCount DW
	biCompression DD
	biSizeImage DD
	biXPelsPerMeter DD
	biYPelsPerMeter DD
	biClrUsed DD
	biClrImportant DD
EndS

BITMAPV4HEADER Struct
	bV4Size DD
	bV4Width DD
	bV4Height DD
	bV4Planes DW
	bV4BitCount DW
	bV4V4Compression DD
	bV4SizeImage DD
	bV4XPelsPerMeter DD
	bV4YPelsPerMeter DD
	bV4ClrUsed DD
	bV4ClrImportant DD
	bV4RedMask DD
	bV4GreenMask DD
	bV4BlueMask DD
	bV4AlphaMask DD
	bV4CSType DD
	bV4Endpoints CIEXYZTRIPLE <>
	bV4GammaRed DD
	bV4GammaGreen DD
	bV4GammaBlue DD
EndS

BITMAPV5HEADER Struct
	bV5Size DD
	bV5Width DD
	bV5Height DD
	bV5Planes DW
	bV5BitCount DW
	bV5Compression DD
	bV5SizeImage DD
	bV5XPelsPerMeter DD
	bV5YPelsPerMeter DD
	bV5ClrUsed DD
	bV5ClrImportant DD
	bV5RedMask DD
	bV5GreenMask DD
	bV5BlueMask DD
	bV5AlphaMask DD
	bV5CSType DD
	bV5Endpoints CIEXYZTRIPLE <>
	bV5GammaRed DD
	bV5GammaGreen DD
	bV5GammaBlue DD
	bV5Intent DD
	bV5ProfileData DD
	bV5ProfileSize DD
	bV5Reserved DD
EndS

BITMAPINFO Struct
	bmiHeader BITMAPINFOHEADER <>
	bmiColors RGBQUAD <>
EndS

BITMAPCOREINFO Struct
	bmciHeader BITMAPCOREHEADER <>
	bmciColors RGBTRIPLE <>
EndS

BITMAPFILEHEADER Struct
	bfType DW
	bfSize DD
	bfReserved1 DW
	bfReserved2 DW
	bfOffBits DD
EndS

FONTSIGNATURE Struct
	fsUsb DD 4 Dup ?
	fsCsb DD 2 Dup ?
EndS

CHARSETINFO Struct
    UINT ciCharset;
    UINT ciACP;
    FONTSIGNATURE fs;
EndS

LOCALESIGNATURE Struct
	lsUsb DD 4 Dup ?
	lsCsbDefault DD 2 Dup ?
	lsCsbSupported DD 2 Dup ?
EndS

HANDLETABLE Struct
	objectHandle DD 1 Dup ?
EndS

METARECORD Struct
	rdSize DD
	rdFunction DW
	rdParm DW 1 Dup ?
EndS

METAFILEPICT Struct
	mm DD
	xExt DD
	yExt DD
	hMF DD
EndS

METAHEADER Struct
	mtType DW
	mtHeaderSize DW
	mtVersion DW
	mtSize DD
	mtNoObjects DW
	mtMaxRecord DD
	mtNoParameters DW
EndS

ENHMETARECORD Struct
	iType DD
	nSize DD
	dParm DD 1 Dup ?
EndS

ENHMETAHEADER Struct
	iType DD
	nSize DD
	rclBounds RECTL <>
	rclFrame RECTL <>
	dSignature DD
	nVersion DD
	nBytes DD
	nRecords DD
	nHandles DW
	sReserved DW
	nDescription DD
	offDescription DD
	nPalEntries DD
	szlDevice SIZEL <>
	szlMillimeters SIZEL <>
	cbPixelFormat DD
	offPixelFormat DD
	bOpenGL DD
EndS

TEXTMETRICA Struct
	tmHeight DD
	tmAscent DD
	tmDescent DD
	tmInternalLeading DD
	tmExternalLeading DD
	tmAveCharWidth DD
	tmMaxCharWidth DD
	tmWeight DD
	tmOverhang DD
	tmDigitizedAspectX DD
	tmDigitizedAspectY DD
	tmFirstChar DB
	tmLastChar DB
	tmDefaultChar DB
	tmBreakChar DB
	tmItalic DB
	tmUnderlined DB
	tmStruckOut DB
	tmPitchAndFamily DB
	tmCharSet DB
EndS

TEXTMETRICW Struct
	tmHeight DD
	tmAscent DD
	tmDescent DD
	tmInternalLeading DD
	tmExternalLeading DD
	tmAveCharWidth DD
	tmMaxCharWidth DD
	tmWeight DD
	tmOverhang DD
	tmDigitizedAspectX DD
	tmDigitizedAspectY DD
	tmFirstChar DW
	tmLastChar DW
	tmDefaultChar DW
	tmBreakChar DW
	tmItalic DB
	tmUnderlined DB
	tmStruckOut DB
	tmPitchAndFamily DB
	tmCharSet DB
EndS

NEWTEXTMETRICA Struct
	tmHeight DD
	tmAscent DD
	tmDescent DD
	tmInternalLeading DD
	tmExternalLeading DD
	tmAveCharWidth DD
	tmMaxCharWidth DD
	tmWeight DD
	tmOverhang DD
	tmDigitizedAspectX DD
	tmDigitizedAspectY DD
	tmFirstChar DB
	tmLastChar DB
	tmDefaultChar DB
	tmBreakChar DB
	tmItalic DB
	tmUnderlined DB
	tmStruckOut DB
	tmPitchAndFamily DB
	tmCharSet DB
	ntmFlags DD
	ntmSizeEM DD
	ntmCellHeight DD
	ntmAvgWidth DD
EndS

NEWTEXTMETRICW Struct
	tmHeight DD
	tmAscent DD
	tmDescent DD
	tmInternalLeading DD
	tmExternalLeading DD
	tmAveCharWidth DD
	tmMaxCharWidth DD
	tmWeight DD
	tmOverhang DD
	tmDigitizedAspectX DD
	tmDigitizedAspectY DD
	tmFirstChar DW
	tmLastChar DW
	tmDefaultChar DW
	tmBreakChar DW
	tmItalic DB
	tmUnderlined DB
	tmStruckOut DB
	tmPitchAndFamily DB
	tmCharSet DB
	ntmFlags DD
	ntmSizeEM DD
	ntmCellHeight DD
	ntmAvgWidth DD
EndS

NEWTEXTMETRICEXA Struct
	ntmTm NEWTEXTMETRICA <>
	ntmFontSig FONTSIGNATURE <>
EndS

NEWTEXTMETRICEXW Struct
	ntmTm NEWTEXTMETRICW <>
	ntmFontSig FONTSIGNATURE <>
EndS

PELARRAY Struct
	paXCount DD
	paYCount DD
	paXExt DD
	paYExt DD
	paRGBs DB
EndS

LOGBRUSH Struct
	lbStyle DD
	lbColor DD
	lbHatch DD
EndS

LOGPEN Struct
	lopnStyle DD
	lopnWidth POINT <>
	lopnColor DD
EndS

EXTLOGPEN Struct
	elpPenStyle DD
	elpWidth DD
	elpBrushStyle DD
	elpColor DD
	elpHatch DD
	elpNumEntries DD
	elpStyleEntry DD 1 Dup ?
EndS

PALETTEENTRY Struct
	peRed DB
	peGreen DB
	peBlue DB
	peFlags DB
EndS

LOGPALETTE Struct
	palVersion DW
	palNumEntries DW
	palPalEntry PALETTEENTRY <>
EndS

LOGFONTA Struct
	lfHeight DD
	lfWidth DD
	lfEscapement DD
	lfOrientation DD
	lfWeight DD
	lfItalic DB
	lfUnderline DB
	lfStrikeOut DB
	lfCharSet DB
	lfOutPrecision DB
	lfClipPrecision DB
	lfQuality DB
	lfPitchAndFamily DB
	lfFaceName DB LF_FACESIZE Dup ?
EndS

LOGFONTW Struct
	lfHeight DD
	lfWidth DD
	lfEscapement DD
	lfOrientation DD
	lfWeight DD
	lfItalic DB
	lfUnderline DB
	lfStrikeOut DB
	lfCharSet DB
	lfOutPrecision DB
	lfClipPrecision DB
	lfQuality DB
	lfPitchAndFamily DB
	lfFaceName DW LF_FACESIZE Dup ?
EndS

ENUMLOGFONTA Struct
	elfLogFont LOGFONTA <>
	elfFullName DB LF_FULLFACESIZE Dup ?
	elfStyle DB LF_FACESIZE Dup ?
EndS

ENUMLOGFONTW Struct
	elfLogFont LOGFONTW <>
	elfFullName DW LF_FULLFACESIZE Dup ?
	elfStyle DW LF_FACESIZE Dup ?
EndS

ENUMLOGFONTEXA Struct
	elfLogFont LOGFONTA <>
	elfFullName DB LF_FULLFACESIZE Dup ?
	elfStyle DB LF_FACESIZE Dup ?
	elfScript DB LF_FACESIZE Dup ?
EndS

ENUMLOGFONTEXW Struct
	elfLogFont LOGFONTW <>
	elfFullName DW LF_FULLFACESIZE Dup ?
	elfStyle DW LF_FACESIZE Dup ?
	elfScript DW LF_FACESIZE Dup ?
EndS

PANOSE Struct
	bFamilyType DB
	bSerifStyle DB
	bWeight DB
	bProportion DB
	bContrast DB
	bStrokeVariation DB
	bArmStyle DB
	bLetterform DB
	bMidline DB
	bXHeight DB
EndS

EXTLOGFONTA Struct
	elfLogFont LOGFONTA <>
	elfFullName DB LF_FULLFACESIZE Dup ?
	elfStyle DB LF_FACESIZE Dup ?
	elfVersion DD
	elfStyleSize DD
	elfMatch DD
	elfReserved DD
	elfVendorId DB ELF_VENDOR_SIZE Dup ?
	elfCulture DD
	elfPanose PANOSE <>
EndS

EXTLOGFONTW Struct
	elfLogFont LOGFONTW <>
	DW LF_FULLFACESIZE Dup ?
	elfStyle DW LF_FACESIZE Dup ?
	elfVersion DD
	elfStyleSize DD
	elfMatch DD
	elfReserved DD
	elfVendorId DB ELF_VENDOR_SIZE Dup ?
	elfCulture DD
	elfPanose PANOSE <>
EndS

DEVMODEA Struct
	dmDeviceName DB CCHDEVICENAME Dup ?
	dmSpecVersion DW
	dmDriverVersion DW
	dmSize DW
	dmDriverExtra DW
	dmFields DD
	Union
		Struct
	        short dmOrientation DW
	        short dmPaperSize DW
	        short dmPaperLength DW
	        short dmPaperWidth DW
		EndS
		dmPosition POINTL <>
    EndUnion
	dmScale DW
	dmCopies DW
	dmDefaultSource DW
	dmPrintQuality DW
	dmColor DW
	dmDuplex DW
	dmYResolution DW
	dmTTOption DW
	dmCollate DW
	dmFormName DB CCHFORMNAME Dup ?
	dmLogPixels DW
	dmBitsPerPel DD
	dmPelsWidth DD
	dmPelsHeight DD
	dmDisplayFlags DD
	dmDisplayFrequency DD
	dmICMMethod DD
	dmICMIntent DD
	dmMediaType DD
	dmDitherType DD
	dmReserved1 DD
	dmReserved2 DD
#IF (WINVER >= 00500H)
	dmPanningWidth DD
	dmPanningHeight DD
#ENDIF
EndS

DEVMODEW Struct
	dmDeviceName DW CCHDEVICENAME Dup ?
	dmSpecVersion DW
	dmDriverVersion DW
	dmSize DW
	dmDriverExtra DW
	dmFields DD
	Union
		Struct
			dmOrientation DW
			dmPaperSize DW
			dmPaperLength DW
			dmPaperWidth DW
		EndS
		dmPosition POINTL <>
    EndUnion
	dmScale DW
	dmCopies DW
	dmDefaultSource DW
	dmPrintQuality DW
	dmColor DW
	dmDuplex DW
	dmYResolution DW
	dmTTOption DW
	dmCollate DW
	dmFormName DW CCHFORMNAME Dup ?
	dmLogPixels DW
	dmBitsPerPel DD
	dmPelsWidth DD
	dmPelsHeight DD
	dmDisplayFlags DD
	dmDisplayFrequency DD
	dmICMMethod DD
	dmICMIntent DD
	dmMediaType DD
	dmDitherType DD
	dmReserved1 DD
	dmReserved2 DD
#IF (WINVER >= 00500H)
	dmPanningWidth DD
	dmPanningHeight DD
#ENDIF
EndS

DISPLAY_DEVICEA Struct
	cb DD
	DeviceName DB 32 Dup ?
	DeviceString DB 128 Dup ?
	StateFlags DD
EndS

DISPLAY_DEVICEW Struct
	cb DD
	DeviceName DW 32 Dup ?
	DeviceString DW 128 Dup ?
	StateFlags DD
EndS

RGNDATAHEADER Struct
	dwSize DD
	iType DD
	nCount DD
	nRgnSize DD
	rcBound RECT <>
EndS

RGNDATA Struct
	rdh RGNDATAHEADER <>
	Buffer DB 1 Dup ?
EndS

ABC Struct
	abcA DD
	abcB DD
	abcC DD
EndS

ABCFLOAT Struct
	abcfA DD
	abcfB DD
	abcfC DD
EndS

OUTLINETEXTMETRICA Struct
	otmSize DD
	otmTextMetrics TEXTMETRICA <>
	otmFiller DB
	otmPanoseNumber PANOSE <>
	otmfsSelection DD
	otmfsType DD
	otmsCharSlopeRise DD
	otmsCharSlopeRun DD
	otmItalicAngle DD
	otmEMSquare DD
	otmAscent DD
	otmDescent DD
	otmLineGap DD
	otmsCapEmHeight DD
	otmsXHeight DD
	otmrcFontBox RECT <>
	otmMacAscent DD
	otmMacDescent DD
	otmMacLineGap DD
	otmusMinimumPPEM DD
	otmptSubscriptSize POINT <>
	otmptSubscriptOffset POINT <>
	otmptSuperscriptSize POINT <>
	otmptSuperscriptOffset POINT <>
	otmsStrikeoutSize DD
	otmsStrikeoutPosition DD
	otmsUnderscoreSize DD
	otmsUnderscorePosition DD
	otmpFamilyName DD
	otmpFaceName DD
	otmpStyleName DD
	otmpFullName DD
EndS

OUTLINETEXTMETRICW Struct
	otmSize DD
    otmTextMetrics TEXTMETRICW <>
	otmFiller DB
	otmPanoseNumber PANOSE <>
	otmfsSelection DD
	otmfsType DD
	otmsCharSlopeRise DD
	otmsCharSlopeRun DD
	otmItalicAngle DD
	otmEMSquare DD
	otmAscent DD
	otmDescent DD
	otmLineGap DD
	otmsCapEmHeight DD
	otmsXHeight DD
	otmrcFontBox RECT <>
	otmMacAscent DD
	otmMacDescent DD
	otmMacLineGap DD
	otmusMinimumPPEM DD
	otmptSubscriptSize POINT <>
	otmptSubscriptOffset POINT <>
	otmptSuperscriptSize POINT <>
	otmptSuperscriptOffset POINT <>
	otmsStrikeoutSize DD
	otmsStrikeoutPosition DD
	otmsUnderscoreSize DD
	otmsUnderscorePosition DD
	otmpFamilyName DD
	otmpFaceName DD
	otmpStyleName DD
	otmpFullName DD
EndS

POLYTEXTA Struct
	x DD
	y DD
	n DD
	lpstr DD
	uiFlags DD
	rcl RECT <>
	pdx DD
EndS

POLYTEXTW Struct
	x DD
	y DD
	n DD
	lpstr DD
	uiFlags DD
	rcl RECT <>
	pdx DD
EndS

FIXED Struct
	fract DW
	value DW
EndS

MAT2 Struct
	eM11 FIXED <>
	eM12 FIXED <>
	eM21 FIXED <>
	eM22 FIXED <>
EndS

GLYPHMETRICS Struct
	gmBlackBoxX DD
	gmBlackBoxY DD
	gmptGlyphOrigin POINT <>
	gmCellIncX DW
	gmCellIncY DW
EndS

POINTFX Struct
	x FIXED <>
	y FIXED <>
EndS

TTPOLYCURVE Struct
	wType DW
	cpfx DW
	apfx POINTFX <>
EndS

TTPOLYGONHEADER Struct
	cb DD
	dwType DD
	pfxStart POINTFX <>
EndS

GCP_RESULTSA Struct
	lStructSize DD
	lpOutString DD
	lpOrder DD
	lpDx DD
	lpCaretPos DD
	lpClass DD
	lpGlyphs DD
	nGlyphs DD
	nMaxFit DD
EndS

GCP_RESULTSW Struct
	lStructSize DD
	lpOutString DD
	lpOrder DD
	lpDx DD
	lpCaretPos DD
	lpClass DD
	lpGlyphs DD
	nGlyphs DD
	nMaxFit DD
EndS

RASTERIZER_STATUS Struct
	nSize DW
	wFlags DW
	nLanguageID DW
EndS

PIXELFORMATDESCRIPTOR Struct
	nSize DW
	nVersion DW
	dwFlags DD
	iPixelType DB
	cColorBits DB
	cRedBits DB
	cRedShift DB
	cGreenBits DB
	cGreenShift DB
	cBlueBits DB
	cBlueShift DB
	cAlphaBits DB
	cAlphaShift DB
	cAccumBits DB
	cAccumRedBits DB
	cAccumGreenBits DB
	cAccumBlueBits DB
	cAccumAlphaBits DB
	cDepthBits DB
	cStencilBits DB
	cAuxBuffers DB
	iLayerType DB
	bReserved DB
	dwLayerMask DD
	dwVisibleMask DD
	dwDamageMask DD
EndS

WCRANGE Struct
	wcLow DW
	cGlyphs DW
EndS

GLYPHSET Struct
	cbThis DD
	flAccel DD
	cGlyphsSupported DD
	cRanges DD
	ranges WCRANGE <>
EndS

DESIGNVECTOR Struct
	dvReserved DD
	dvNumAxes DD
	dvValues DD MM_MAX_NUMAXES Dup ?
EndS

AXISINFOA Struct
	axMinValue DD
	axMaxValue DD
	axAxisName DB MM_MAX_AXES_NAMELEN Dup ?
EndS

AXISINFOW Struct
	axMinValue DD
	axMaxValue DD
	axAxisName DW MM_MAX_AXES_NAMELEN Dup ?
EndS

AXESLISTA Struct
	axlReserved DD
	axlNumAxes DD
	axlAxisInfo AXISINFOA MM_MAX_NUMAXES Dup <>
EndS

AXESLISTW Struct
	axlReserved DD
	axlNumAxes DD
	axlAxisInfo AXISINFOW MM_MAX_NUMAXES Dup <>
EndS

ENUMLOGFONTEXDVA Struct
	elfEnumLogfontEx ENUMLOGFONTEXA <>
	elfDesignVector DESIGNVECTOR <>
EndS

ENUMLOGFONTEXDVW Struct
	elfEnumLogfontEx ENUMLOGFONTEXW <>
	elfDesignVector DESIGNVECTOR <>
EndS

ENUMTEXTMETRICA Struct
	etmNewTextMetricEx NEWTEXTMETRICEXA <>
	etmAxesList AXESLISTA <>
EndS

ENUMTEXTMETRICW Struct
	etmNewTextMetricEx NEWTEXTMETRICEXW <>
	etmAxesList AXESLISTW <>
EndS

TRIVERTEX Struct
	x DD
	y DD
	Red DW
	Green DW
	Blue DW
	Alpha DW
EndS

GRADIENT_TRIANGLE Struct
	Vertex1 DD
	Vertex2 DD
	Vertex3 DD
EndS

GRADIENT_RECT Struct
	UpperLeft DD
	LowerRight DD
EndS

BLENDFUNCTION Struct
	BlendOp DB
	BlendFlags DB
	SourceConstantAlpha DB
	AlphaFormat DB
EndS

DIBSECTION Struct
	dsBm BITMAP <>
	dsBmih BITMAPINFOHEADER <>
	dsBitfields DD 3 Dup ?
	dshSection DD
	dsOffset DD
EndS

COLORADJUSTMENT Struct
	caSize DW
	caFlags DW
	caIlluminantIndex DW
	caRedGamma DW
	caGreenGamma DW
	caBlueGamma DW
	caReferenceBlack DW
	caReferenceWhite DW
	caContrast DW
	caBrightness DW
	caColorfulness DW
	caRedGreenTint DW
EndS

DOCINFOA Struct
	cbSize DD
	lpszDocName DD
	lpszOutput DD
	lpszDatatype DD
	fwType DD
EndS

DOCINFOW Struct
	cbSize DD
	lpszDocName DD
	lpszOutput DD
	lpszDatatype DD
	fwType DD
EndS

KERNINGPAIR Struct
	wFirst DW
	wSecond DW
	iKernAmount DD
EndS

EMR Struct
	iType DD
	nSize DD
EndS

EMRTEXT Struct
	ptlReference POINTL <>
	nChars DD
	offString DD
	fOptions DD
	rcl RECTL <>
	offDx DD
EndS

EMRABORTPATH Struct
	emr EMR <>
EndS
#Define EMRBEGINPATH		EMRABORTPATH
#Define EMRENDPATH			EMRABORTPATH
#Define EMRCLOSEFIGURE		EMRABORTPATH
#Define EMRFLATTENPATH		EMRABORTPATH
#Define EMRWIDENPATH		EMRABORTPATH
#Define EMRSETMETARGN		EMRABORTPATH
#Define EMRSAVEDC			EMRABORTPATH
#Define EMRREALIZEPALETTE	EMRABORTPATH

EMRSELECTCLIPPATH Struct
	emr EMR <>
	iMode DD
EndS

EMRSETMITERLIMIT Struct
	emr EMR <>
	eMiterLimit DD
EndS

EMRRESTOREDC Struct
	emr EMR <>
	iRelative DD
EndS

EMRSETARCDIRECTION Struct
	emr EMR <>
	iArcDirection DD
EndS

EMRSETMAPPERFLAGS Struct
	emr EMR <>
	dwFlags DD
EndS

EMRSETBKCOLOR Struct
	emr EMR <>
	crColor DD
EndS
#Define EMRSETTEXTCOLOR		EMRSETBKCOLOR

EMRSELECTOBJECT Struct
	emr EMR <>
	ihObject DD
EndS
#Define EMRDELETEOBJECT		EMRSELECTOBJECT

EMRSELECTCOLORSPACE Struct
	emr EMR <>
	ihCS DD
EndS
#Define EMRDELETECOLORSPACE	EMRSELECTCOLORSPACE

EMRSELECTPALETTE Struct
	emr EMR <>
	ihPal DD
EndS

EMRRESIZEPALETTE Struct
	emr EMR <>
	ihPal DD
	cEntries DD
EndS

EMRSETPALETTEENTRIES Struct
	emr EMR <>
	ihPal DD
	iStart DD
	cEntries DD
	aPalEntries PALETTEENTRY <>
EndS

EMRSETCOLORADJUSTMENT Struct
	emr EMR <>
	ColorAdjustment COLORADJUSTMENT <>
EndS

EMRGDICOMMENT Struct
	emr EMR <>
	cbData DD
	Data DB 1 Dup ?
EndS

EMREOF Struct
	emr EMR <>
	nPalEntries DD
	offPalEntries DD
	nSizeLast DD
EndS

EMRLINETO Struct
	emr EMR <>
	ptl POINTL <>
EndS
#Define EMRMOVETOEX			EMRLINETO

EMROFFSETCLIPRGN Struct
	emr EMR <>
	ptlOffset POINTL <>
EndS

EMRFILLPATH Struct
	emr EMR <>
	rclBounds RECTL <>
EndS
#Define EMRSTROKEANDFILLPATH	EMRFILLPATH
#Define EMRSTROKEANDFILLPATH	EMRFILLPATH
#Define EMRSTROKEPATH			EMRFILLPATH

EMREXCLUDECLIPRECT Struct
	emr EMR <>
	rclClip RECTL <>
EndS
#Define EMRINTERSECTCLIPRECT	EMREXCLUDECLIPRECT

EMRSETVIEWPORTORGEX Struct
	emr EMR <>
	ptlOrigin POINTL <>
EndS
#Define EMRSETWINDOWORGEX		EMRSETVIEWPORTORGEX
#Define EMRSETBRUSHORGEX   		EMRSETVIEWPORTORGEX

EMRSETVIEWPORTEXTEX Struct
	emr EMR <>
	szlExtent SIZEL <>
EndS
#Define EMRSETWINDOWEXTEX		EMRSETVIEWPORTEXTEX

EMRSCALEVIEWPORTEXTEX Struct
	emr EMR <>
	xNum DD
	xDenom DD
	yNum DD
	yDenom DD
EndS
#Define EMRSCALEWINDOWEXTEX		EMRSCALEVIEWPORTEXTEX

EMRSETWORLDTRANSFORM Struct
	emr EMR <>
	xform XFORM <>
EndS

EMRMODIFYWORLDTRANSFORM Struct
	emr EMR <>
	xform XFORM <>
	iMode DD
EndS

EMRSETPIXELV Struct
	emr EMR <>
	ptlPixel POINTL <>
	crColor DD
EndS

EMREXTFLOODFILL Struct
	emr EMR <>
	ptlStart POINTL <>
	crColor DD
	iMode DD
EndS

EMRELLIPSE Struct
	emr EMR <>
	rclBox RECTL <>
EndS
#Define EMRRECTANGLE			EMRELLIPSE

EMRROUNDRECT Struct
	emr EMR <>
	rclBox RECTL <>
	szlCorner SIZEL <>
EndS

EMRARC Struct
	emr EMR <>
	rclBox RECTL <>
	ptlStart POINTL <>
	ptlEnd POINTL <>
EndS
#Define EMRARCTO				EMRARC
#Define EMRCHORD				EMRARC
#Define EMRPIE					EMRARC

EMRANGLEARC Struct
	emr EMR <>
	ptlCenter POINTL <>
	nRadius DD
	eStartAngle DD
	eSweepAngle DD
EndS

EMRPOLYLINE Struct
	emr EMR <>
	rclBounds RECTL <>
	cptl DD
	aptl POINTL <>
EndS
#Define EMRPOLYBEZIER			EMRPOLYLINE
#Define EMRPOLYGON				EMRPOLYLINE
#Define EMRPOLYBEZIERTO			EMRPOLYLINE
#Define EMRPOLYLINETO			EMRPOLYLINE

EMRPOLYLINE16 Struct
	emr EMR <>
	rclBounds RECTL <>
	cpts DD
	apts POINTS <>
EndS
#Define EMRPOLYBEZIER16			EMRPOLYLINE16
#Define EMRPOLYGON16			EMRPOLYLINE16
#Define EMRPOLYBEZIERTO16		EMRPOLYLINE16
#Define EMRPOLYLINETO16			EMRPOLYLINE16

EMRPOLYDRAW Struct
	emr EMR <>
	rclBounds RECTL <>
	cptl DD
	aptl POINTL <>
	abTypes D 1 Dup ?
EndS

EMRPOLYDRAW16 Struct
	emr EMR <>
	rclBounds RECTL <>
	cpts DD
	apts POINTS <>
	abTypes DB 1 Dup ?
EndS

EMRPOLYPOLYLINE Struct
	emr EMR <>
	rclBounds RECTL <>
	nPolys DD
	cptl DD
	aPolyCounts DD 1 Dup ?
	aptl POINTL <>
EndS
#Define EMRPOLYPOLYGON			EMRPOLYPOLYLINE

EMRPOLYPOLYLINE16 Struct
	emr EMR <>
	rclBounds RECTL <>
	nPolys DD
	cpts DD
	aPolyCounts DD 1 Dup ?
	apts POINTS <>
EndS
#Define EMRPOLYPOLYGON16		EMRPOLYPOLYLINE16

EMRINVERTRGN Struct
	emr EMR <>
	rclBounds RECTL <>
	cbRgnData DD
	RgnData DB 1 Dup ?
EndS
#Define EMRPAINTRGN				EMRINVERTRGN

EMRFILLRGN Struct
	emr EMR <>
	rclBounds RECTL <>
	cbRgnData DD
	ihBrush DD
	RgnData DB 1 Dup ?
EndS

EMRFRAMERGN Struct
	emr EMR <>
	rclBounds RECTL <>
	cbRgnData DD
	ihBrush DD
	szlStroke SIZEL <>
	RgnData DB 1 Dup ?
EndS

EMRGRADIENTFILL Struct
	emr EMR <>
	rclBounds RECTL <>
	nVer DD
	nTri DD
	ulMode DD
	Ver TRIVERTEX <>
EndS

EMREXTSELECTCLIPRGN Struct
	emr EMR <>
	cbRgnData DD
	iMode DD
	RgnData DB 1 Dup ?
EndS

EMREXTTEXTOUTA Struct
	emr EMR <>
	rclBounds RECTL <>
	iGraphicsMode DD
	exScale DD
	eyScale DD
	emrtext EMRTEXT <>
EndS
#Define EMREXTTEXTOUTW			EMREXTTEXTOUTA

EMRPOLYTEXTOUTA Struct
	emr EMR <>
	rclBounds RECTL <>
	iGraphicsMode DD
	exScale DD
	eyScale DD
	cStrings DD
	aemrtext EMRTEXT <>
EndS
#Define EMRPOLYTEXTOUTW			EMRPOLYTEXTOUTA

EMRBITBLT Struct
	emr EMR <>
	rclBounds RECTL <>
	xDest DD
	yDest DD
	cxDest DD
	cyDest DD
	dwRop DD
	xSrc DD
	ySrc DD
	xformSrc XFORM <>
	crBkColorSrc DD
	iUsageSrc DD
	offBmiSrc DD
	cbBmiSrc DD
	offBitsSrc DD
	cbBitsSrc DD
EndS

EMRSTRETCHBLT Struct
	emr EMR <>
	rclBounds RECTL <>
	xDest DD
	yDest DD
	cxDest DD
	cyDest DD
	dwRop DD
	xSrc DD
	ySrc DD
	xformSrc XFORM <>
	crBkColorSrc DD
	iUsageSrc DD
	offBmiSrc DD
	cbBmiSrc DD
	offBitsSrc DD
	cbBitsSrc DD
	cxSrc DD
	cySrc DD
EndS

EMRMASKBLT Struct
	emr EMR <>
	rclBounds RECTL <>
	xDest DD
	yDest DD
	cxDest DD
	cyDest DD
	dwRop DD
	xSrc DD
	ySrc DD
	xformSrc XFORM <>
	crBkColorSrc DD
	iUsageSrc DD
	offBmiSrc DD
	cbBmiSrc DD
	offBitsSrc DD
	cbBitsSrc DD
	xMask DD
	yMask DD
	iUsageMask DD
	offBmiMask DD
	cbBmiMask DD
	offBitsMask DD
	cbBitsMask DD
EndS

EMRPLGBLT Struct
	emr EMR <>
	rclBounds RECTL <>
	aptlDest POINTL 3 Dup <>
	xSrc DD
	ySrc DD
	cxSrc DD
	cySrc DD
	xformSrc XFORM <>
	crBkColorSrc DD
	iUsageSrc DD
	offBmiSrc DD
	cbBmiSrc DD
	offBitsSrc DD
	cbBitsSrc DD
	xMask DD
	yMask DD
	iUsageMask DD
	offBmiMask DD
	cbBmiMask DD
	offBitsMask DD
	cbBitsMask DD
EndS

EMRSETDIBITSTODEVICE Struct
	emr EMR <>
	rclBounds RECTL <>
	xDest DD
	yDest DD
	xSrc DD
	ySrc DD
	cxSrc DD
	cySrc DD
	offBmiSrc DD
	cbBmiSrc DD
	offBitsSrc DD
	cbBitsSrc DD
	iUsageSrc DD
	iStartScan DD
	cScans DD
EndS

EMRSTRETCHDIBITS Struct
	emr EMR <>
	rclBounds RECTL <>
	xDest DD
	yDest DD
	xSrc DD
	ySrc DD
	cxSrc DD
	cySrc DD
	offBmiSrc DD
	cbBmiSrc DD
	offBitsSrc DD
	cbBitsSrc DD
	iUsageSrc DD
	dwRop DD
	cxDest DD
	cyDest DD
EndS

EMRALPHABLE Struct
	emr EMR <>
	rclBounds RECTL <>
	xDest DD
	yDest DD
	cxDest DD
	cyDest DD
	dwRop DD
	xSrc DD
	ySrc DD
	xformSrc XFORM <>
	crBkColorSrc DD
	iUsageSrc DD
	offBmiSrc DD
	cbBmiSrc DD
	offBitsSrc DD
	cbBitsSrc DD
	cxSrc DD
	cySrc DD
EndS

EMREMRTRANSPARENTBLT Struct
	emr EMR <>
	rclBounds RECTL <>
	xDest DD
	yDest DD
	cxDest DD
	cyDest DD
	dwRop DD
	xSrc DD
	ySrc;
	xformSrc XFORM <>
	crBkColorSrc DD
	iUsageSrc DD
	offBmiSrc DD
	cbBmiSrc DD
	offBitsSrc DD
	cbBitsSrc DD
	cxSrc DD
	cySrc DD
EndS

EMREXTCREATEFONTINDIRECTW Struct
	emr EMR <>
	ihFont DD
	elfw EXTLOGFONTW <>
EndS

EMRCREATEPALETTE Struct
	emr EMR <>
	ihPal DD
	lgpl LOGPALETTE <>
EndS

EMRCREATECOLORSPACE Struct
	emr EMR <>
	ihCS DD
	lcs LOGCOLORSPACEW <>
EndS

EMRCREATEPEN Struct
	emr EMR <>
	ihPen DD
	lopn LOGPEN <>
EndS

EMREXTCREATEPEN Struct
	emr EMR <>
	ihPen DD
	offBmi DD
	cbBmi DD
	offBits DD
	cbBits DD
	elp EXTLOGPEN <>
EndS

EMRCREATEBRUSHINDIRECT Struct
	emr EMR <>
	ihBrush DD
	lb LOGBRUSH <>
EndS

EMRCREATEMONOBRUSH Struct
	emr EMR <>
	ihBrush DD
	iUsage DD
	offBmi DD
	cbBmi DD
	offBits DD
	cbBits DD
EndS

EMRCREATEDIBPATTERNBRUSHPT Struct
	emr EMR <>
	ihBrush DD
	iUsage DD
	offBmi DD
	cbBmi DD
	offBits DD
	cbBits DD
EndS

EMRFORMAT Struct
	dSignature DD
	nVersion DD
	cbData DD
	offData DD
EndS

EMRGLSRECORD Struct
	emr EMR <>
	cbData DD
	Data DB 1 Dup ?
EndS

EMRGLSBOUNDEDRECORD Struct
	emr EMR <>
	rclBounds RECTL <>
	cbData DD
	Data DB 1 Dup ?
EndS

EMRPIXELFORMAT Struct
	emr EMR <>
	pfd PIXELFORMATDESCRIPTOR <>
EndS

EMRSETICMPROFILE Struct
	emr EMR <>
	dwFlags DD
	cbName DD
	cbData DD
	Data DB 1 Dup ?
EndS

POINTFLOAT Struct
	x DD
	y DD
EndS

GLYPHMETRICSFLOAT Struct
	gmfBlackBoxX DD
	gmfBlackBoxY DD
	gmfptGlyphOrigin POINTFLOAT <>
	gmfCellIncX DD
	gmfCellIncY DD
EndS

LAYERPLANEDESCRIPTOR Struct
	nSize DW
	nVersion DW
	dwFlags DD
	iPixelType DB
	cColorBits DB
	cRedBits DB
	cRedShift DB
	cGreenBits DB
	cGreenShift DB
	cBlueBits DB
	cBlueShift DB
	cAlphaBits DB
	cAlphaShift DB
	cAccumBits DB
	cAccumRedBits DB
	cAccumGreenBits DB
	cAccumBlueBits DB
	cAccumAlphaBits DB
	cDepthBits DB
	cStencilBits DB
	cAuxBuffers DB
	iLayerPlane DB
	bReserved DB
	crTransparent DD
EndS

WGLSWAP Struct
	hdc DD
	uiFlags DD
EndS


#IF STRINGS UNICODE
	#Define LOGCOLORSPACE LOGCOLORSPACEW
	#Define TEXTMETRIC TEXTMETRICW
	#Define NEWTEXTMETRIC NEWTEXTMETRICW
	#Define NEWTEXTMETRICEX NEWTEXTMETRICEXW
	#Define LOGFONT LOGFONTW
	#Define ENUMLOGFONT ENUMLOGFONTW
	#Define ENUMLOGFONTEX ENUMLOGFONTEXW
	#Define EXTLOGFONT EXTLOGFONTW
	#Define DEVMODE DEVMODEW
	#Define DISPLAY_DEVICE DISPLAY_DEVICEW
	#Define OUTLINETEXTMETRIC OUTLINETEXTMETRICW
	#Define POLYTEXT POLYTEXTW
	#Define GCP_RESULTS GCP_RESULTSW
	#Define AddFontResource AddFontResourceW
	#Define CopyMetaFile CopyMetaFileW
	#Define CreateDC CreateDCW
	#Define CreateFontIndirect CreateFontIndirectW
	#Define CreateFont CreateFontW
	#Define CreateIC CreateICW
	#Define CreateMetaFile CreateMetaFileW
	#Define CreateScalableFontResource CreateScalableFontResourceW
	#Define DeviceCapabilities DeviceCapabilitiesW
	#Define EnumFontFamiliesEx EnumFontFamiliesExW
	#Define EnumFontFamilies EnumFontFamiliesW
	#Define EnumFonts EnumFontsW
	#Define GetCharWidth GetCharWidthW
	#Define GetCharWidth32 GetCharWidth32W
	#Define GetCharWidthFloat GetCharWidthFloatW
	#Define GetCharABCWidths GetCharABCWidthsW
	#Define GetCharABCWidthsFloat GetCharABCWidthsFloatW
	#Define GetGlyphOutline GetGlyphOutlineW
	#Define GetMetaFile GetMetaFileW
	#Define GetOutlineTextMetrics GetOutlineTextMetricsW
	#Define GetTextExtentPoint GetTextExtentPointW
	#Define GetTextExtentPoint32 GetTextExtentPoint32W
	#Define GetTextExtentExPoint GetTextExtentExPointW
	#Define GetCharacterPlacement GetCharacterPlacementW
	#Define GetGlyphIndices GetGlyphIndicesW
	#Define AddFontResourceEx AddFontResourceExW
	#Define RemoveFontResourceEx RemoveFontResourceExW
	#Define AXISINFO AXISINFOW
	#Define AXESLIST AXESLISTW
	#Define ENUMLOGFONTEXDV ENUMLOGFONTEXDVW
	#Define CreateFontIndirectEx CreateFontIndirectExW
	#Define ENUMTEXTMETRIC ENUMTEXTMETRICW
	#Define ResetDC ResetDCW
	#Define RemoveFontResource RemoveFontResourceW
	#Define CopyEnhMetaFile CopyEnhMetaFileW
	#Define CreateEnhMetaFile CreateEnhMetaFileW
	#Define GetEnhMetaFile GetEnhMetaFileW
	#Define GetEnhMetaFileDescription GetEnhMetaFileDescriptionW
	#Define GetTextMetrics GetTextMetricsW
	#Define DOCINFO DOCINFOW
	#Define StartDoc StartDocW
	#Define GetObject GetObjectW
	#Define TextOut TextOutW
	#Define ExtTextOut ExtTextOutW
	#Define PolyTextOut PolyTextOutW
	#Define GetTextFace GetTextFaceW
	#Define GetKerningPairs GetKerningPairsW
	#Define GetLogColorSpace GetLogColorSpaceW
	#Define CreateColorSpace CreateColorSpaceW
	#Define GetICMProfile GetICMProfileW
	#Define SetICMProfile SetICMProfileW
	#Define EnumICMProfiles EnumICMProfilesW
	#Define UpdateICMRegKey UpdateICMRegKeyW
	#Define wglUseFontBitmaps wglUseFontBitmapsW
	#Define wglUseFontOutlines wglUseFontOutlinesW
#ELSE
	#Define LOGCOLORSPACE LOGCOLORSPACEA
	#Define TEXTMETRIC TEXTMETRICA
	#Define NEWTEXTMETRIC NEWTEXTMETRICA
	#Define NEWTEXTMETRICEX NEWTEXTMETRICEXA
	#Define LOGFONT LOGFONTA
	#Define ENUMLOGFONT ENUMLOGFONTA
	#Define ENUMLOGFONTEX ENUMLOGFONTEXA
	#Define EXTLOGFONT EXTLOGFONTA
	#Define DEVMODE DEVMODEA
	#Define DISPLAY_DEVICE DISPLAY_DEVICEA
	#Define OUTLINETEXTMETRIC OUTLINETEXTMETRICA
	#Define POLYTEXT POLYTEXTA
	#Define GCP_RESULTS GCP_RESULTSA
	#Define AddFontResource AddFontResourceA
	#Define CopyMetaFile CopyMetaFileA
	#Define CreateDC CreateDCA
	#Define CreateFontIndirect CreateFontIndirectA
	#Define CreateFont CreateFontA
	#Define CreateIC CreateICA
	#Define CreateMetaFile CreateMetaFileA
	#Define CreateScalableFontResource CreateScalableFontResourceA
	#Define DeviceCapabilities DeviceCapabilitiesA
	#Define EnumFontFamiliesEx EnumFontFamiliesExA
	#Define EnumFontFamilies EnumFontFamiliesA
	#Define EnumFonts EnumFontsA
	#Define GetCharWidth GetCharWidthA
	#Define GetCharWidth32 GetCharWidth32A
	#Define GetCharWidthFloat GetCharWidthFloatA
	#Define GetCharABCWidths GetCharABCWidthsA
	#Define GetCharABCWidthsFloat GetCharABCWidthsFloatA
	#Define GetGlyphOutline GetGlyphOutlineA
	#Define GetMetaFile GetMetaFileA
	#Define GetOutlineTextMetrics GetOutlineTextMetricsA
	#Define GetTextExtentPoint GetTextExtentPointA
	#Define GetTextExtentPoint32 GetTextExtentPoint32A
	#Define GetTextExtentExPoint GetTextExtentExPointA
	#Define GetCharacterPlacement GetCharacterPlacementA
	#Define GetGlyphIndices GetGlyphIndicesA
	#Define AddFontResourceEx AddFontResourceExA
	#Define RemoveFontResourceEx RemoveFontResourceExA
	#Define AXISINFO AXISINFOA
	#Define AXESLIST AXESLISTA
	#Define ENUMLOGFONTEXDV ENUMLOGFONTEXDVA
	#Define CreateFontIndirectEx CreateFontIndirectExA
	#Define ENUMTEXTMETRIC ENUMTEXTMETRICA
	#Define ResetDC ResetDCA
	#Define RemoveFontResource RemoveFontResourceA
	#Define CopyEnhMetaFile CopyEnhMetaFileA
	#Define CreateEnhMetaFile CreateEnhMetaFileA
	#Define GetEnhMetaFile GetEnhMetaFileA
	#Define GetEnhMetaFileDescription GetEnhMetaFileDescriptionA
	#Define GetTextMetrics GetTextMetricsA
	#Define DOCINFO DOCINFOA
	#Define StartDoc StartDocA
	#Define GetObject GetObjectA
	#Define TextOut TextOutA
	#Define ExtTextOut ExtTextOutA
	#Define PolyTextOut PolyTextOutA
	#Define GetTextFace GetTextFaceA
	#Define GetKerningPairs GetKerningPairsA
	#Define GetLogColorSpace GetLogColorSpaceA
	#Define CreateColorSpace CreateColorSpaceA
	#Define GetICMProfile GetICMProfileA
	#Define SetICMProfile SetICMProfileA
	#Define EnumICMProfiles EnumICMProfilesA
	#Define UpdateICMRegKey UpdateICMRegKeyA
	#Define wglUseFontBitmaps wglUseFontBitmapsA
	#Define wglUseFontOutlines wglUseFontOutlinesA
#ENDIF

#ENDIF ;WINGDI_INC
