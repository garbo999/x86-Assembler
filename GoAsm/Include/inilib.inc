;=============================================================;
;          inilib.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF INILIB_INC
#Define INILIB_INC

#Define INI_PATH_LENGTH                     256
#Define MAX_HANDOFF_ENTRY_LENGTH            80
#Define MAX_PROTOCOL_NAME                   40
#Define NUMALLOCENTRIES                     10
#Define RAW_INI_STR_LEN                     200

#Define PARSERS_SUBDIR                      "PARSERS"
#Define INI_EXTENSION                       "INI"
#Define BASE10_FORMAT_STR                   "%ld=%s %ld"
#Define BASE16_FORMAT_STR                   "%lx=%s %lx"

#ENDIF ;INILIB_INC
