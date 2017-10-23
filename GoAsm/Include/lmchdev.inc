;=============================================================;
;          lmchdev.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMCHDEV_INC
#Define LMCHDEV_INC

CHARDEV_INFO_0 Struct
	ch0_dev DD
EndS

CHARDEV_INFO_1 Struct
	ch1_dev DD
	ch1_status DD
	ch1_username DD
	ch1_time DD
EndS

CHARDEVQ_INFO_0 Struct
	cq0_dev DD
EndS

CHARDEVQ_INFO_1 Struct
	cq1_dev DD
	cq1_priority DD
	cq1_devs DD
	cq1_numusers DD
	cq1_numahead DD
EndS

CHARDEVQ_INFO_1002 Struct
	cq1002_priority DD
EndS

CHARDEVQ_INFO_1003 Struct
	cq1003_devs DD
EndS

#Define CHARDEV_STAT_OPENED                 002H
#Define CHARDEV_STAT_ERROR                  004H

#Define CHARDEV_CLOSE                       0

#Define CHARDEVQ_DEV_PARMNUM                1
#Define CHARDEVQ_PRIORITY_PARMNUM           2
#Define CHARDEVQ_DEVS_PARMNUM               3
#Define CHARDEVQ_NUMUSERS_PARMNUM           4
#Define CHARDEVQ_NUMAHEAD_PARMNUM           5

#Define CHARDEVQ_PRIORITY_INFOLEVEL         (PARMNUM_BASE_INFOLEVEL + CHARDEVQ_PRIORITY_PARMNUM)
#Define CHARDEVQ_DEVS_INFOLEVEL             (PARMNUM_BASE_INFOLEVEL + CHARDEVQ_DEVS_PARMNUM)

#Define CHARDEVQ_MAX_PRIORITY               1
#Define CHARDEVQ_MIN_PRIORITY               9
#Define CHARDEVQ_DEF_PRIORITY               5

#Define CHARDEVQ_NO_REQUESTS                (-1)

HANDLE_INFO_1 Struct
	hdli1_chartime DD
	hdli1_charcount DD
EndS

#define HANDLE_INFO_LEVEL_1                 1

#Define HANDLE_CHARTIME_PARMNUM             1
#Define HANDLE_CHARCOUNT_PARMNUM            2

#ENDIF ;LMCHDEV_INC
