;=============================================================;
;            imm.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF IMM_INC
#Define IMM_INC

COMPOSITIONFORM Struct
	dwStyle DD
	ptCurrentPos POINT <>
	rcArea RECT <>
EndS

CANDIDATEFORM Struct
	dwIndex DD
	dwStyle DD
	ptCurrentPos POINT <>
	rcArea RECT <>
EndS

CANDIDATELIST Struct
	dwSize DD
	dwStyle DD
	dwCount DD
	dwSelection DD
	dwPageStart DD
	dwPageSize DD
	dwOffset DD
EndS

REGISTERWORDA Struct
	lpReading DD
	lpWord DD
EndS

REGISTERWORDW Struct
	lpReading DD
	lpWord DD
EndS

RECONVERTSTRING Struct
	dwSize DD
	dwVersion DD
	dwStrLen DD
	dwStrOffset DD
	dwCompStrLen DD
	dwCompStrOffset DD
	dwTargetStrLen DD
	dwTargetStrOffset DD
EndS

#Define STYLE_DESCRIPTION_SIZE              32

STYLEBUFA Struct
	dwStyle DD
	szDescription DB STYLE_DESCRIPTION_SIZE Dup ?
EndS

STYLEBUFW Struct
	dwStyle DD
	szDescription DW STYLE_DESCRIPTION_SIZE Dup ?
EndS

#Define IMEMENUITEM_STRING_SIZE             80

IMEMENUITEMINFOA Struct
	cbSize DD
	fType DD
	fState DD
	wID DD
	hbmpChecked DD
	hbmpUnchecked DD
	dwItemData DD
	szString DB IMEMENUITEM_STRING_SIZE Dup ?
	hbmpItem DD
EndS

IMEMENUITEMINFOW Struct
	cbSize DD
	fType DD
	fState DD
	wID DD
	hbmpChecked DD
	hbmpUnchecked DD
	dwItemData DD
	szString DW IMEMENUITEM_STRING_SIZE Dup ?
	hbmpItem DD
EndS
#Define IMC_GETCANDIDATEPOS                 00007H
#Define IMC_SETCANDIDATEPOS                 00008H
#Define IMC_GETCOMPOSITIONFONT              00009H
#Define IMC_SETCOMPOSITIONFONT              0000AH
#Define IMC_GETCOMPOSITIONWINDOW            0000BH
#Define IMC_SETCOMPOSITIONWINDOW            0000CH
#Define IMC_GETSTATUSWINDOWPOS              0000FH
#Define IMC_SETSTATUSWINDOWPOS              00010H
#Define IMC_CLOSESTATUSWINDOW               00021H
#Define IMC_OPENSTATUSWINDOW                00022H

#Define NI_OPENCANDIDATE                    00010H
#Define NI_CLOSECANDIDATE                   00011H
#Define NI_SELECTCANDIDATESTR               00012H
#Define NI_CHANGECANDIDATELIST              00013H
#Define NI_FINALIZECONVERSIONRESULT         00014H
#Define NI_COMPOSITIONSTR                   00015H
#Define NI_SETCANDIDATE_PAGESTART           00016H
#Define NI_SETCANDIDATE_PAGESIZE            00017H
#Define NI_IMEMENUSELECTED                  00018H

#Define ISC_SHOWUICANDIDATEWINDOW           000000001H
#Define ISC_SHOWUICOMPOSITIONWINDOW         080000000H
#Define ISC_SHOWUIGUIDELINE                 040000000H
#Define ISC_SHOWUIALLCANDIDATEWINDOW        00000000FH
#Define ISC_SHOWUIALL                       0C000000FH

#Define CPS_COMPLETE                        00001H
#Define CPS_CONVERT                         00002H
#Define CPS_REVERT                          00003H
#Define CPS_CANCEL                          00004H

#Define MOD_ALT                             00001H
#Define MOD_CONTROL                         00002H
#Define MOD_SHIFT                           00004H

#Define MOD_LEFT                            08000H
#Define MOD_RIGHT                           04000H

#Define MOD_ON_KEYUP                        00800H
#Define MOD_IGNORE_ALL_MODIFIER             00400H

#Define IME_CHOTKEY_IME_NONIME_TOGGLE       010H
#Define IME_CHOTKEY_SHAPE_TOGGLE            011H
#Define IME_CHOTKEY_SYMBOL_TOGGLE           012H

#Define IME_JHOTKEY_CLOSE_OPEN              030H

#Define IME_KHOTKEY_SHAPE_TOGGLE            050H
#Define IME_KHOTKEY_HANJACONVERT            051H
#Define IME_KHOTKEY_ENGLISH                 052H

#Define IME_THOTKEY_IME_NONIME_TOGGLE       070H
#Define IME_THOTKEY_SHAPE_TOGGLE            071H
#Define IME_THOTKEY_SYMBOL_TOGGLE           072H

#Define IME_HOTKEY_DSWITCH_FIRST            0100H
#Define IME_HOTKEY_DSWITCH_LAST             011FH

#Define IME_HOTKEY_PRIVATE_FIRST            0200H
#Define IME_ITHOTKEY_RESEND_RESULTSTR       0200H
#Define IME_ITHOTKEY_PREVIOUS_COMPOSITION   0201H
#Define IME_ITHOTKEY_UISTYLE_TOGGLE         0202H
#Define IME_ITHOTKEY_RECONVERTSTRING        0203H
#Define IME_HOTKEY_PRIVATE_LAST             021FH

#Define GCS_COMPREADSTR                     00001H
#Define GCS_COMPREADATTR                    00002H
#Define GCS_COMPREADCLAUSE                  00004H
#Define GCS_COMPSTR                         00008H
#Define GCS_COMPATTR                        00010H
#Define GCS_COMPCLAUSE                      00020H
#Define GCS_CURSORPOS                       00080H
#Define GCS_DELTASTART                      00100H
#Define GCS_RESULTREADSTR                   00200H
#Define GCS_RESULTREADCLAUSE                00400H
#Define GCS_RESULTSTR                       00800H
#Define GCS_RESULTCLAUSE                    01000H

#Define CS_INSERTCHAR                       02000H
#Define CS_NOMOVECARET                      04000H

#Define IMEVER_0310                         00003000AH
#Define IMEVER_0400                         000040000H

#Define IME_PROP_AT_CARET                   000010000H
#Define IME_PROP_SPECIAL_UI                 000020000H
#Define IME_PROP_CANDLIST_START_FROM_1      000040000H
#Define IME_PROP_UNICODE                    000080000H
#Define IME_PROP_COMPLETE_ON_UNSELECT       000100000H

#Define UI_CAP_2700                         000000001H
#Define UI_CAP_ROT90                        000000002H
#Define UI_CAP_ROTANY                       000000004H

#Define SCS_CAP_COMPSTR                     000000001H
#Define SCS_CAP_MAKEREAD                    000000002H
#Define SCS_CAP_SETRECONVERTSTRING          000000004H

#Define SELECT_CAP_CONVERSION               000000001H
#Define SELECT_CAP_SENTENCE                 000000002H

#Define GGL_LEVEL                           000000001H
#Define GGL_INDEX                           000000002H
#Define GGL_STRING                          000000003H
#Define GGL_PRIVATE                         000000004H

#Define GL_LEVEL_NOGUIDELINE                000000000H
#Define GL_LEVEL_FATAL                      000000001H
#Define GL_LEVEL_ERROR                      000000002H
#Define GL_LEVEL_WARNING                    000000003H
#Define GL_LEVEL_INFORMATION                000000004H

#Define GL_ID_UNKNOWN                       000000000H
#Define GL_ID_NOMODULE                      000000001H
#Define GL_ID_NODICTIONARY                  000000010H
#Define GL_ID_CANNOTSAVE                    000000011H
#Define GL_ID_NOCONVERT                     000000020H
#Define GL_ID_TYPINGERROR                   000000021H
#Define GL_ID_TOOMANYSTROKE                 000000022H
#Define GL_ID_READINGCONFLICT               000000023H
#Define GL_ID_INPUTREADING                  000000024H
#Define GL_ID_INPUTRADICAL                  000000025H
#Define GL_ID_INPUTCODE                     000000026H
#Define GL_ID_INPUTSYMBOL                   000000027H
#Define GL_ID_CHOOSECANDIDATE               000000028H
#Define GL_ID_REVERSECONVERSION             000000029H
#Define GL_ID_PRIVATE_FIRST                 000008000H
#Define GL_ID_PRIVATE_LAST                  00000FFFFH

#Define IGP_GETIMEVERSION                   (-4)
#Define IGP_PROPERTY                        000000004H
#Define IGP_CONVERSION                      000000008H
#Define IGP_SENTENCE                        00000000CH
#Define IGP_UI                              000000010H
#Define IGP_SETCOMPSTR                      000000014H
#Define IGP_SELECT                          000000018H

#Define SCS_SETSTR                          (GCS_COMPREADSTR | GCS_COMPSTR)
#Define SCS_CHANGEATTR                      (GCS_COMPREADATTR | GCS_COMPATTR)
#Define SCS_CHANGECLAUSE                    (GCS_COMPREADCLAUSE | GCS_COMPCLAUSE)
#Define SCS_SETRECONVERTSTRING              000010000H
#Define SCS_QUERYRECONVERTSTRING            000020000H

#Define ATTR_INPUT                          000H
#Define ATTR_TARGET_CONVERTED               001H
#Define ATTR_CONVERTED                      002H
#Define ATTR_TARGET_NOTCONVERTED            003H
#Define ATTR_INPUT_ERROR                    004H
#Define ATTR_FIXEDCONVERTED                 005H

#Define CFS_DEFAULT                         00000H
#Define CFS_RECT                            00001H
#Define CFS_POINT                           00002H
#Define CFS_FORCE_POSITION                  00020H
#Define CFS_CANDIDATEPOS                    00040H
#Define CFS_EXCLUDE                         00080H

#Define GCL_CONVERSION                      00001H
#Define GCL_REVERSECONVERSION               00002H
#Define GCL_REVERSE_LENGTH                  00003H

#Define IME_CMODE_ALPHANUMERIC              00000H
#Define IME_CMODE_NATIVE                    00001H
#Define IME_CMODE_CHINESE                   IME_CMODE_NATIVE

#Define IME_CMODE_HANGEUL                   IME_CMODE_NATIVE
#Define IME_CMODE_HANGUL                    IME_CMODE_NATIVE
#Define IME_CMODE_JAPANESE                  IME_CMODE_NATIVE
#Define IME_CMODE_KATAKANA                  00002H
#Define IME_CMODE_LANGUAGE                  00003H
#Define IME_CMODE_FULLSHAPE                 00008H
#Define IME_CMODE_ROMAN                     00010H
#Define IME_CMODE_CHARCODE                  00020H
#Define IME_CMODE_HANJACONVERT              00040H
#Define IME_CMODE_SOFTKBD                   00080H
#Define IME_CMODE_NOCONVERSION              00100H
#Define IME_CMODE_EUDC                      00200H
#Define IME_CMODE_SYMBOL                    00400H
#Define IME_CMODE_FIXED                     00800H

#Define IME_SMODE_NONE                      00000H
#Define IME_SMODE_PLAURALCLAUSE             00001H
#Define IME_SMODE_SINGLECONVERT             00002H
#Define IME_SMODE_AUTOMATIC                 00004H
#Define IME_SMODE_PHRASEPREDICT             00008H
#Define IME_SMODE_CONVERSATION              00010H

#Define IME_CAND_UNKNOWN                    00000H
#Define IME_CAND_READ                       00001H
#Define IME_CAND_CODE                       00002H
#Define IME_CAND_MEANING                    00003H
#Define IME_CAND_RADICAL                    00004H
#Define IME_CAND_STROKE                     00005H

#Define IMN_CLOSESTATUSWINDOW               00001H
#Define IMN_OPENSTATUSWINDOW                00002H
#Define IMN_CHANGECANDIDATE                 00003H
#Define IMN_CLOSECANDIDATE                  00004H
#Define IMN_OPENCANDIDATE                   00005H
#Define IMN_SETCONVERSIONMODE               00006H
#Define IMN_SETSENTENCEMODE                 00007H
#Define IMN_SETOPENSTATUS                   00008H
#Define IMN_SETCANDIDATEPOS                 00009H
#Define IMN_SETCOMPOSITIONFONT              0000AH
#Define IMN_SETCOMPOSITIONWINDOW            0000BH
#Define IMN_SETSTATUSWINDOWPOS              0000CH
#Define IMN_GUIDELINE                       0000DH
#Define IMN_PRIVATE                         0000EH

#Define IMR_COMPOSITIONWINDOW               00001H
#Define IMR_CANDIDATEWINDOW                 00002H
#Define IMR_COMPOSITIONFONT                 00003H
#Define IMR_RECONVERTSTRING                 00004H
#Define IMR_CONFIRMRECONVERTSTRING          00005H

#Define IMM_ERROR_NODATA                    (-1)
#Define IMM_ERROR_GENERAL                   (-2)

#Define IME_CONFIG_GENERAL                  1
#Define IME_CONFIG_REGISTERWORD             2
#Define IME_CONFIG_SELECTDICTIONARY         3

#Define IME_ESC_QUERY_SUPPORT               00003H
#Define IME_ESC_RESERVED_FIRST              00004H
#Define IME_ESC_RESERVED_LAST               007FFH
#Define IME_ESC_PRIVATE_FIRST               00800H
#Define IME_ESC_PRIVATE_LAST                00FFFH
#Define IME_ESC_SEQUENCE_TO_INTERNAL        01001H
#Define IME_ESC_GET_EUDC_DICTIONARY         01003H
#Define IME_ESC_SET_EUDC_DICTIONARY         01004H
#Define IME_ESC_MAX_KEY                     01005H
#Define IME_ESC_IME_NAME                    01006H
#Define IME_ESC_SYNC_HOTKEY                 01007H
#Define IME_ESC_HANJA_MODE                  01008H
#Define IME_ESC_AUTOMATA                    01009H
#Define IME_ESC_PRIVATE_HOTKEY              0100AH
#Define IME_ESC_GETHELPFILENAME             0100BH

#Define IME_REGWORD_STYLE_EUDC              000000001H
#Define IME_REGWORD_STYLE_USER_FIRST        080000000H
#Define IME_REGWORD_STYLE_USER_LAST         0FFFFFFFFH

#Define IACE_CHILDREN                       00001H
#Define IACE_DEFAULT                        00010H
#Define IACE_IGNORENOCONTEXT                00020H

#Define IGIMIF_RIGHTMENU                    00001H

#Define IGIMII_CMODE                        00001H
#Define IGIMII_SMODE                        00002H
#Define IGIMII_CONFIGURE                    00004H
#Define IGIMII_TOOLS                        00008H
#Define IGIMII_HELP                         00010H
#Define IGIMII_OTHER                        00020H
#Define IGIMII_INPUTTOOLS                   00040H

#Define IMFT_RADIOCHECK                     000001H
#Define IMFT_SEPARATOR                      000002H
#Define IMFT_SUBMENU                        000004H

#Define IMFS_GRAYED                         MFS_GRAYED
#Define IMFS_DISABLED                       MFS_DISABLED
#Define IMFS_CHECKED                        MFS_CHECKED
#Define IMFS_HILITE                         MFS_HILITE
#Define IMFS_ENABLED                        MFS_ENABLED
#Define IMFS_UNCHECKED                      MFS_UNCHECKED
#Define IMFS_UNHILITE                       MFS_UNHILITE
#Define IMFS_DEFAULT                        MFS_DEFAULT

#Define SOFTKEYBOARD_TYPE_T1                00001H
#Define SOFTKEYBOARD_TYPE_C1                00002H

#IF STRINGS UNICODE
	#Define REGISTERWORD REGISTERWORDW
	#Define STYLEBUF STYLEBUFW
	#Define IMEMENUITEMINFO IMEMENUITEMINFOW
	#Define ImmInstallIME ImmInstallIMEW
	#Define ImmGetDescription ImmGetDescriptionW
	#Define ImmGetIMEFileName ImmGetIMEFileNameW
	#Define ImmGetCompositionString ImmGetCompositionStringW
	#Define ImmSetCompositionString ImmSetCompositionStringW
	#Define ImmGetCandidateListCount ImmGetCandidateListCountW
	#Define ImmGetCandidateList ImmGetCandidateListW
	#Define ImmGetGuideLine ImmGetGuideLineW
	#Define ImmGetCompositionFont ImmGetCompositionFontW
	#Define ImmSetCompositionFont ImmSetCompositionFontW
	#Define ImmConfigureIME ImmConfigureIMEW
	#Define ImmEscape ImmEscapeW
	#Define ImmGetConversionList ImmGetConversionListW
	#Define ImmIsUIMessage ImmIsUIMessageW
	#Define REGISTERWORDENUMPROC REGISTERWORDENUMPROCW
	#Define ImmRegisterWord ImmRegisterWordW
	#Define ImmUnregisterWord ImmUnregisterWordW
	#Define ImmGetRegisterWordStyle ImmGetRegisterWordStyleW
	#Define ImmEnumRegisterWord ImmEnumRegisterWordW
	#Define ImmGetImeMenuItems ImmGetImeMenuItemsW
#ELSE
	#Define REGISTERWORD REGISTERWORDA
	#Define STYLEBUF STYLEBUFA
	#Define IMEMENUITEMINFO IMEMENUITEMINFOA
	#Define ImmInstallIME ImmInstallIMEA
	#Define ImmGetDescription ImmGetDescriptionA
	#Define ImmGetIMEFileName ImmGetIMEFileNameA
	#Define ImmGetCompositionString ImmGetCompositionStringA
	#Define ImmSetCompositionString ImmSetCompositionStringA
	#Define ImmGetCandidateListCount ImmGetCandidateListCountA
	#Define ImmGetCandidateList ImmGetCandidateListA
	#Define ImmGetGuideLine ImmGetGuideLineA
	#Define ImmGetCompositionFont ImmGetCompositionFontA
	#Define ImmSetCompositionFont ImmSetCompositionFontA
	#Define ImmConfigureIME ImmConfigureIMEA
	#Define ImmEscape ImmEscapeA
	#Define ImmGetConversionList ImmGetConversionListA
	#Define ImmIsUIMessage ImmIsUIMessageA
	#Define REGISTERWORDENUMPROC REGISTERWORDENUMPROCA
	#Define ImmRegisterWord ImmRegisterWordA
	#Define ImmUnregisterWord ImmUnregisterWordA
	#Define ImmGetRegisterWordStyle ImmGetRegisterWordStyleA
	#Define ImmEnumRegisterWord ImmEnumRegisterWordA
	#Define ImmGetImeMenuItems ImmGetImeMenuItemsA
#ENDIF

#ENDIF ;IMM_INC
