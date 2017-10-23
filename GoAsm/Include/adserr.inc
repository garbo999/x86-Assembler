;=============================================================;
;          adserr.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF ADSERR_INC
#Define ADSERR_INC

#Define FACILITY_WINDOWS                8
#Define FACILITY_STORAGE                3
#Define FACILITY_RPC                    1
#Define FACILITY_SSPI                   9
#Define FACILITY_WIN32                  7
#Define FACILITY_CONTROL                10
#Define FACILITY_NULL                   0
#Define FACILITY_ITF                    4
#Define FACILITY_DISPATCH				2

#Define E_ADS_BAD_PATHNAME              080005000H
#Define E_ADS_INVALID_DOMAIN_OBJECT     080005001H
#Define E_ADS_INVALID_USER_OBJECT       080005002H
#Define E_ADS_INVALID_COMPUTER_OBJECT   080005003H
#Define E_ADS_UNKNOWN_OBJECT            080005004H
#Define E_ADS_PROPERTY_NOT_SET          080005005H
#Define E_ADS_PROPERTY_NOT_SUPPORTED    080005006H
#Define E_ADS_PROPERTY_INVALID          080005007H
#Define E_ADS_BAD_PARAMETER             080005008H
#Define E_ADS_OBJECT_UNBOUND            080005009H
#Define E_ADS_PROPERTY_NOT_MODIFIED     08000500AH
#Define E_ADS_PROPERTY_MODIFIED         08000500BH
#Define E_ADS_CANT_CONVERT_DATATYPE     08000500CH
#Define E_ADS_PROPERTY_NOT_FOUND        08000500DH
#Define E_ADS_OBJECT_EXISTS             08000500EH
#Define E_ADS_SCHEMA_VIOLATION          08000500FH
#Define E_ADS_COLUMN_NOT_SET            080005010H
#Define S_ADS_ERRORSOCCURRED            000005011H
#Define S_ADS_NOMORE_ROWS               000005012H
#Define S_ADS_NOMORE_COLUMNS            000005013H
#Define E_ADS_INVALID_FILTER            080005014H

#ENDIF ;ADSERR_INC
