;=============================================================;
;            ntnls.h file for Easy Code visual IDE            ;
;                       (GoAsm version)                       ;
;                                                             ;
;                   Driver Development Kit                    ;
;                                                             ;
;          Version 1.0.00 (created on November, 2010)         ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF NTNLS_H
#Define NTNLS_H 1

#IFNDEF NTDEF_H
    #Include ntdef.h
#ENDIF

MAXIMUM_LEADBYTES                                           Equ         12

CPTABLEINFO Struct
    CodePage                                                DW
    MaximumCharacterSize                                    DW
    DefaultChar                                             DW
    UniDefaultChar                                          DW
    TransDefaultChar                                        DW
    TransUniDefaultChar                                     DW
    DBCSCodePage                                            DW
    LeadByte                                                DB          MAXIMUM_LEADBYTES Dup ?
    MultiByteTable                                          DD
    WideCharTable                                           DD
    DBCSRanges                                              DD
    DBCSOffsets                                             DD
EndS

NLSTABLEINFO Struct
    OemTableInfo                                            CPTABLEINFO
    AnsiTableInfo                                           CPTABLEINFO
    UpperCaseTable                                          DD
    LowerCaseTable                                          DD
EndS

#ENDIF ;NTNLS_H
