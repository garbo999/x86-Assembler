;=============================================================;
;          adssts.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF ADSSTS_INC
#Define ADSSTS_INC

#Define ADS_PRINTER_PAUSED              000000001H
#Define ADS_PRINTER_PENDING_DELETION	000000002H
#Define ADS_PRINTER_ERROR               000000003H
#Define ADS_PRINTER_PAPER_JAM           000000004H
#Define ADS_PRINTER_PAPER_OUT           000000005H
#Define ADS_PRINTER_MANUAL_FEED         000000006H
#Define ADS_PRINTER_PAPER_PROBLEM       000000007H
#Define ADS_PRINTER_OFFLINE             000000008H
#Define ADS_PRINTER_IO_ACTIVE           000000100H
#Define ADS_PRINTER_BUSY                000000200H
#Define ADS_PRINTER_PRINTING            000000400H
#Define ADS_PRINTER_OUTPUT_BIN_FULL     000000800H
#Define ADS_PRINTER_NOT_AVAILABLE       000001000H
#Define ADS_PRINTER_WAITING             000002000H
#Define ADS_PRINTER_PROCESSING          000004000H
#Define ADS_PRINTER_INITIALIZING        000008000H
#Define ADS_PRINTER_WARMING_UP          000010000H
#Define ADS_PRINTER_TONER_LOW           000020000H
#Define ADS_PRINTER_NO_TONER            000040000H
#Define ADS_PRINTER_PAGE_PUNT           000080000H
#Define ADS_PRINTER_USER_INTERVENTION   000100000H
#Define ADS_PRINTER_OUT_OF_MEMORY       000200000H
#Define ADS_PRINTER_DOOR_OPEN           000400000H
#Define ADS_PRINTER_SERVER_UNKNOWN      000800000H
#Define ADS_PRINTER_POWER_SAVE          001000000H

#Define ADS_JOB_PAUSED                  000000001H
#Define ADS_JOB_ERROR                   000000002H
#Define ADS_JOB_DELETING                000000004H
#Define ADS_JOB_SPOOLING                000000008H
#Define ADS_JOB_PRINTING                000000010H
#Define ADS_JOB_OFFLINE                 000000020H
#Define ADS_JOB_PAPEROUT                000000040H
#Define ADS_JOB_PRINTED                 000000080H
#Define ADS_JOB_DELETED                 000000100H

#Define ADS_SERVICE_STOPPED             000000001H
#Define ADS_SERVICE_START_PENDING	    000000002H
#Define ADS_SERVICE_STOP_PENDING        000000003H
#Define ADS_SERVICE_RUNNING	            000000004H
#Define ADS_SERVICE_CONTINUE_PENDING    000000005H
#Define ADS_SERVICE_PAUSE_PENDING	    000000006H
#Define ADS_SERVICE_PAUSED              000000007H
#Define ADS_SERVICE_ERROR               000000008H

#Define ADS_SERVICE_OWN_PROCESS         000000010H
#Define ADS_SERVICE_SHARE_PROCESS       000000020H
#Define ADS_SERVICE_KERNEL_DRIVER       000000001H
#Define ADS_SERVICE_FILE_SYSTEM_DRIVER  000000002H

#Define ADS_SERVICE_BOOT_START          SERVICE_BOOT_START
#define ADS_SERVICE_SYSTEM_START        SERVICE_SYSTEM_START
#define ADS_SERVICE_AUTO_START          SERVICE_AUTO_START
#define ADS_SERVICE_DEMAND_START        SERVICE_DEMAND_START
#Define ADS_SERVICE_DISABLED           	SERVICE_DISABLED

#Define ADS_SERVICE_ERROR_IGNORE        0
#Define ADS_SERVICE_ERROR_NORMAL        1
#Define ADS_SERVICE_ERROR_SEVERE        2
#Define ADS_SERVICE_ERROR_CRITICAL      3

#ENDIF ;ADSSTS_INC
