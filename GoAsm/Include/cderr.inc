;=============================================================;
;           cderr.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF CDERR_INC
#Define CDERR_INC

#Define CDERR_DIALOGFAILURE   				0FFFFH

#Define CDERR_GENERALCODES					00000H
#Define CDERR_STRUCTSIZE					00001H
#Define CDERR_INITIALIZATION				00002H
#Define CDERR_NOTEMPLATE					00003H
#Define CDERR_NOHINSTANCE					00004H
#Define CDERR_LOADSTRFAILURE				00005H
#Define CDERR_FINDRESFAILURE				00006H
#Define CDERR_LOADRESFAILURE				00007H
#Define CDERR_LOCKRESFAILURE				00008H
#Define CDERR_MEMALLOCFAILURE				00009H
#Define CDERR_MEMLOCKFAILURE				0000AH
#Define CDERR_NOHOOK						0000BH
#Define CDERR_REGISTERMSGFAIL				0000CH

#Define PDERR_PRINTERCODES					01000H
#Define PDERR_SETUPFAILURE					01001H
#Define PDERR_PARSEFAILURE					01002H
#Define PDERR_RETDEFFAILURE					01003H
#Define PDERR_LOADDRVFAILURE				01004H
#Define PDERR_GETDEVMODEFAIL				01005H
#Define PDERR_INITFAILURE					01006H
#Define PDERR_NODEVICES						01007H
#Define PDERR_NODEFAULTPRN					01008H
#Define PDERR_DNDMMISMATCH					01009H
#Define PDERR_CREATEICFAILURE				0100AH
#Define PDERR_PRINTERNOTFOUND				0100BH
#Define PDERR_DEFAULTDIFFERENT				0100CH

#Define CFERR_CHOOSEFONTCODES				02000H
#Define CFERR_NOFONTS						02001H
#Define CFERR_MAXLESSTHANMIN				02002H

#Define FNERR_FILENAMECODES					03000H
#Define FNERR_SUBCLASSFAILURE				03001H
#Define FNERR_INVALIDFILENAME				03002H
#Define FNERR_BUFFERTOOSMALL				03003H

#Define FRERR_FINDREPLACECODES				04000H
#Define FRERR_BUFFERLENGTHZERO				04001H

#Define CCERR_CHOOSECOLORCODES				05000H

#ENDIF ;CDERR_INC
