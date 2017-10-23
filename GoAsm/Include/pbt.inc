;=============================================================;
;            pbt.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF PBT_INC
#Define PBT_INC

#IFNDEF WM_POWERBROADCAST
	#Define WM_POWERBROADCAST               0218H
#ENDIF

#Define PBT_APMQUERYSUSPEND                 00000H
#Define PBT_APMQUERYSTANDBY                 00001H

#Define PBT_APMQUERYSUSPENDFAILED           00002H
#Define PBT_APMQUERYSTANDBYFAILED           00003H

#Define PBT_APMSUSPEND                      00004H
#Define PBT_APMSTANDBY                      00005H

#Define PBT_APMRESUMECRITICAL               00006H
#Define PBT_APMRESUMESUSPEND                00007H
#Define PBT_APMRESUMESTANDBY                00008H

#Define PBTF_APMRESUMEFROMFAILURE           000000001H

#Define PBT_APMBATTERYLOW                   00009H
#Define PBT_APMPOWERSTATUSCHANGE            0000AH

#Define PBT_APMOEMEVENT                     0000BH

#ENDIF ;PBT_INC
