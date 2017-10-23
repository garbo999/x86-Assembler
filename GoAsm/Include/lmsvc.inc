;=============================================================;
;           lmsvc.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMSVC_INC
#Define LMSVC_INC

#IFNDEF LMSNAME_INC
	#Include lmsname.inc
#ENDIF

SERVICE_INFO_0 Struct
	svci0_name DD
EndS

SERVICE_INFO_1 Struct
	svci1_name DD
	svci1_status DD
	svci1_code DD
	svci1_pid DD
EndS

SERVICE_INFO_2 Struct
	svci2_name DD
	svci2_status DD
	svci2_code DD
	svci2_pid DD
	svci2_text DD
	svci2_specific_error DD
	svci2_display_name DD
EndS

#Define SERVICE_INSTALL_STATE               003H
#Define SERVICE_UNINSTALLED                 000H
#Define SERVICE_INSTALL_PENDING             001H
#Define SERVICE_UNINSTALL_PENDING           002H
#Define SERVICE_INSTALLED                   003H

#Define SERVICE_PAUSE_STATE                 00CH
#Define LM20_SERVICE_ACTIVE                 000H
#Define LM20_SERVICE_CONTINUE_PENDING       004H
#Define LM20_SERVICE_PAUSE_PENDING          008H
#Define LM20_SERVICE_PAUSED                 00CH

#Define SERVICE_NOT_UNINSTALLABLE           000H
#Define SERVICE_UNINSTALLABLE               010H

#Define SERVICE_NOT_PAUSABLE                000H
#Define SERVICE_PAUSABLE                    020H

#Define SERVICE_REDIR_PAUSED                0700H
#Define SERVICE_REDIR_DISK_PAUSED           0100H
#Define SERVICE_REDIR_PRINT_PAUSED          0200H
#Define SERVICE_REDIR_COMM_PAUSED           0400H

#Define SERVICE_DOS_ENCRYPTION              L"ENCRYPT"

#Define SERVICE_CTRL_INTERROGATE            0
#Define SERVICE_CTRL_PAUSE                  1
#Define SERVICE_CTRL_CONTINUE               2
#Define SERVICE_CTRL_UNINSTALL              3

#Define SERVICE_CTRL_REDIR_DISK             01H
#Define SERVICE_CTRL_REDIR_PRINT            02H
#Define SERVICE_CTRL_REDIR_COMM             04H

#Define SERVICE_IP_NO_HINT                  00H
#Define SERVICE_CCP_NO_HINT                 00H

#Define SERVICE_IP_QUERY_HINT               010000H
#Define SERVICE_CCP_QUERY_HINT              010000H

#Define SERVICE_IP_CHKPT_NUM                00FFH
#Define SERVICE_CCP_CHKPT_NUM               00FFH

#Define SERVICE_IP_WAIT_TIME                00FF00H
#Define SERVICE_CCP_WAIT_TIME               00FF00H

#Define SERVICE_IP_WAITTIME_SHIFT           8
#Define SERVICE_NTIP_WAITTIME_SHIFT         12

#Define UPPER_HINT_MASK                     00000FF00H
#Define LOWER_HINT_MASK                     0000000FFH
#Define UPPER_GET_HINT_MASK                 00FF00000H
#Define LOWER_GET_HINT_MASK                 00000FF00H
#Define SERVICE_NT_MAXTIME                  00000FFFFH
#Define SERVICE_RESRV_MASK                  00001FFFFH
#Define SERVICE_MAXTIME                     0000000FFH

#Define SERVICE_BASE                        3050
#Define SERVICE_UIC_NORMAL                  0

#Define SERVICE_UIC_BADPARMVAL              (SERVICE_BASE + 1)
#Define SERVICE_UIC_MISSPARM                (SERVICE_BASE + 2)
#Define SERVICE_UIC_UNKPARM                 (SERVICE_BASE + 3)
#Define SERVICE_UIC_RESOURCE                (SERVICE_BASE + 4)
#Define SERVICE_UIC_CONFIG                  (SERVICE_BASE + 5)
#Define SERVICE_UIC_SYSTEM                  (SERVICE_BASE + 6)
#Define SERVICE_UIC_INTERNAL                (SERVICE_BASE + 7)
#Define SERVICE_UIC_AMBIGPARM               (SERVICE_BASE + 8)
#Define SERVICE_UIC_DUPPARM                 (SERVICE_BASE + 9)
#Define SERVICE_UIC_KILL                    (SERVICE_BASE + 10)
#Define SERVICE_UIC_EXEC                    (SERVICE_BASE + 11)
#Define SERVICE_UIC_SUBSERV                 (SERVICE_BASE + 12)
#Define SERVICE_UIC_CONFLPARM               (SERVICE_BASE + 13)
#Define SERVICE_UIC_FILE                    (SERVICE_BASE + 14)

#Define SERVICE_UIC_M_NULL                  0

#Define SERVICE_UIC_M_MEMORY                (SERVICE_BASE + 20)
#Define SERVICE_UIC_M_DISK                  (SERVICE_BASE + 21)
#Define SERVICE_UIC_M_THREADS               (SERVICE_BASE + 22)
#Define SERVICE_UIC_M_PROCESSES             (SERVICE_BASE + 23)

#Define SERVICE_UIC_M_SECURITY              (SERVICE_BASE + 24)
#Define SERVICE_UIC_M_LANROOT               (SERVICE_BASE + 25)
#Define SERVICE_UIC_M_REDIR                 (SERVICE_BASE + 26)
#Define SERVICE_UIC_M_SERVER                (SERVICE_BASE + 27)
#Define SERVICE_UIC_M_SEC_FILE_ERR          (SERVICE_BASE + 28)
#Define SERVICE_UIC_M_FILES                 (SERVICE_BASE + 29)
#Define SERVICE_UIC_M_LOGS                  (SERVICE_BASE + 30)
#Define SERVICE_UIC_M_LANGROUP              (SERVICE_BASE + 31)
#Define SERVICE_UIC_M_MSGNAME               (SERVICE_BASE + 32)
#Define SERVICE_UIC_M_ANNOUNCE              (SERVICE_BASE + 33)
#Define SERVICE_UIC_M_UAS                   (SERVICE_BASE + 34)
#Define SERVICE_UIC_M_SERVER_SEC_ERR        (SERVICE_BASE + 35)
#Define SERVICE_UIC_M_WKSTA                 (SERVICE_BASE + 37)
#Define SERVICE_UIC_M_ERRLOG                (SERVICE_BASE + 38)
#Define SERVICE_UIC_M_FILE_UW               (SERVICE_BASE + 39)
#Define SERVICE_UIC_M_ADDPAK                (SERVICE_BASE + 40)
#Define SERVICE_UIC_M_LAZY                  (SERVICE_BASE + 41)
#Define SERVICE_UIC_M_UAS_MACHINE_ACCT      (SERVICE_BASE + 42)
#Define SERVICE_UIC_M_UAS_SERVERS_NMEMB     (SERVICE_BASE + 43)
#Define SERVICE_UIC_M_UAS_SERVERS_NOGRP     (SERVICE_BASE + 44)
#Define SERVICE_UIC_M_UAS_INVALID_ROLE      (SERVICE_BASE + 45)
#Define SERVICE_UIC_M_NETLOGON_NO_DC        (SERVICE_BASE + 46)
#Define SERVICE_UIC_M_NETLOGON_DC_CFLCT     (SERVICE_BASE + 47)
#Define SERVICE_UIC_M_NETLOGON_AUTH         (SERVICE_BASE + 48)
#Define SERVICE_UIC_M_UAS_PROLOG            (SERVICE_BASE + 49)

#Define SERVICE2_BASE                       5600
#Define SERVICE_UIC_M_NETLOGON_MPATH        (SERVICE2_BASE + 0)
#Define SERVICE_UIC_M_LSA_MACHINE_ACCT      (SERVICE2_BASE + 1)
#Define SERVICE_UIC_M_DATABASE_ERROR        (SERVICE2_BASE + 2)

#ENDIF ;LMSVC_INC
