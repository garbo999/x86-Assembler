;=============================================================;
;          lmalert.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMALERT_INC
#Define LMALERT_INC

STD_ALERT Struct
	alrt_timestamp DD
	alrt_eventname DW (EVLEN + 1) Dup ?
	alrt_servicename DW (SNLEN + 1) Dup ?
EndS

ADMIN_OTHER_INFO Struct
	alrtad_errcode DD
	alrtad_numstrings DD
EndS

ERRLOG_OTHER_INFO Struct
	alrter_errcode DD
	alrter_offset DD
EndS

PRINT_OTHER_INFO Struct
	alrtpr_jobid DD
	alrtpr_status DD
	alrtpr_submitted DD
	alrtpr_size DD
EndS

USER_OTHER_INFO Struct
	alrtus_errcode DD
	alrtus_numstrings DD
EndS

#Define ALERTER_MAILSLOT                    L"\\.\MAILSLOT\Alerter"

#Define ALERT_PRINT_EVENT                   L"PRINTING"
#Define ALERT_MESSAGE_EVENT                 L"MESSAGE"
#Define ALERT_ERRORLOG_EVENT                L"ERRORLOG"
#Define ALERT_ADMIN_EVENT                   L"ADMIN"
#Define ALERT_USER_EVENT                    L"USER"

#Define PRJOB_QSTATUS                       03H
#Define PRJOB_DEVSTATUS                     01FCH
#Define PRJOB_COMPLETE                      04H
#Define PRJOB_INTERV                        08H
#Define PRJOB_ERROR                         010H
#Define PRJOB_DESTOFFLINE                   020H
#Define PRJOB_DESTPAUSED                    040H
#Define PRJOB_NOTIFY                        080H
#Define PRJOB_DESTNOPAPER                   0100H
#Define PRJOB_DELETED                       08000H

#Define PRJOB_QS_QUEUED                     0
#Define PRJOB_QS_PAUSED                     1
#Define PRJOB_QS_SPOOLING                   2
#Define PRJOB_QS_PRINTING                   3

#ENDIF ;LMALERT_INC
