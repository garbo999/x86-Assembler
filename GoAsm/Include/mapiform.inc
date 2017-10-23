;=============================================================;
;         mapiform.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF MAPIFORM_INC
#Define MAPIFORM_INC

#IFNDEF MAPIDEFS_INC
	#Include mapidefs.inc
#ENDIF

#IFNDEF MAPICODE_INC
	#Include mapicode.inc
#ENDIF

#IFNDEF MAPIGUID_INC
	#Include mapiguid.inc
#ENDIF

#IFNDEF MAPITAGS_INC
	#Include mapitags.inc
#ENDIF

#IFNDEF Unknown
	Unknown Struct
	   QueryInterface		DD
	   AddRef				DD
	   Release				DD
	EndS
#ENDIF

#Define HFRMREG_DEFAULT                     0
#Define HFRMREG_LOCAL                       1
#Define HFRMREG_PERSONAL                    2
#Define HFRMREG_FOLDER                      3

;SAVEOPTS enumeration
#Define SAVEOPTS_SAVEIFDIRTY                0
#Define SAVEOPTS_NOSAVE                     1
#Define SAVEOPTS_PROMPTSAVE                 2

FORMPRINTSETUP Struct
	ulFlags DD
	hDevMode DD
	hDevNames DD
	ulFirstPageNumber DD
	fPrintAttachments DD
EndS

#Define SAVE_FORMAT_TEXT                    1
#Define SAVE_FORMAT_RICHTEXT                2

#Define VCSTATUS_NEXT                       000000001H
#Define VCSTATUS_PREV                       000000002H
#Define VCSTATUS_MODAL                      000000004H
#Define VCSTATUS_INTERACTIVE                000000008H
#Define VCSTATUS_READONLY                   000000010H
#Define VCSTATUS_DELETE                     000010000H
#Define VCSTATUS_COPY                       000020000H
#Define VCSTATUS_MOVE                       000040000H
#Define VCSTATUS_SUBMIT                     000080000H
#Define VCSTATUS_DELETE_IS_MOVE             000100000H
#Define VCSTATUS_SAVE                       000200000H
#Define VCSTATUS_NEW_MESSAGE                000400000H

#Define VCDIR_NEXT                          VCSTATUS_NEXT
#Define VCDIR_PREV                          VCSTATUS_PREV
#Define VCDIR_DELETE                        VCSTATUS_DELETE
#Define VCDIR_MOVE                          VCSTATUS_MOVE

SMAPIFormPropEnumVal Struct
	pszDisplayName DD
	nVal DD
EndS

#Define FPST_VANILLA                        0
#Define FPST_ENUM_PROP                      1

_s1 Struct
	nmidIdx DD
	cfpevAvailable DD
	pfpevAvailable DD
EndS

SMAPIFormProp Struct
    ulFlags DD
    nPropType DD
    nmid DD
    pszDisplayName DD
	nSpecialType DD
	s1 _s1 <>
EndS

SMAPIFormPropArray Struct
	cProps DD
	ulPad DD
	aFormProp SMAPIFormProp MAPI_DIM DUP <>
EndS

SMAPIVerb Struct
	lVerb DD
	szVerbname DD
	fuFlags DD
	grfAttribs DD
	ulFlags DD
EndS

SMAPIVerbArray Struct
	cMAPIVerb DD
	aMAPIVerb SMAPIVerb MAPI_DIM Dup ?
EndS

#Define MAPI_MESSAGE_BEHAVIOR_IPM           0
#Define MAPI_MESSAGE_BEHAVIOR_FOLDER        1

SMessageClassArray Struct
	cValues DD
	aMessageClass DD MAPI_DIM Dup ?
EndS

SMAPIFormInfoArray Struct
	cForms DD
	aFormInfo DD MAPI_DIM Dup ?
EndS

#define MAPIFORM_SELECT_ALL_REGISTRIES           0
#define MAPIFORM_SELECT_FOLDER_REGISTRY_ONLY     1
#define MAPIFORM_SELECT_NON_FOLDER_REGISTRY_ONLY 2

#Define FORMPROPSET_UNION                   0
#Define FORMPROPSET_INTERSECTION            1

#Define MAPIFORM_EXACTMATCH                 00020H

#Define MAPIFORM_CPU_X86                    1
#Define MAPIFORM_CPU_MIP                    2
#Define MAPIFORM_CPU_AXP                    3
#Define MAPIFORM_CPU_PPC                    4
#Define MAPIFORM_CPU_M68                    5

#Define MAPIFORM_OS_WIN_31                  1
#Define MAPIFORM_OS_WINNT_35                2
#Define MAPIFORM_OS_WIN_95                  3
#Define MAPIFORM_OS_MAC_7x                  4
#Define MAPIFORM_OS_WINNT_40                5

#Define MAPIFORM_INSTALL_DIALOG              MAPI_DIALOG
#Define MAPIFORM_INSTALL_OVERWRITEONCONFLICT 00010H

#ENDIF ;MAPIFORM_INC

