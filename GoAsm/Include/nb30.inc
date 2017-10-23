;=============================================================;
;           nb30.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF NB30_INC
#Define NB30_INC

#Define NCBNAMSZ        				16
#Define MAX_LANA       					254

#Define NAME_FLAGS_MASK 				087H

#Define GROUP_NAME      				080H
#Define UNIQUE_NAME     				000H

#Define REGISTERING     				000H
#Define REGISTERED      				004H
#Define DEREGISTERED    				005H
#Define DUPLICATE       				006H
#Define DUPLICATE_DEREG 				007H

#Define LISTEN_OUTSTANDING      		001H
#Define CALL_PENDING            		002H
#Define SESSION_ESTABLISHED     		003H
#Define HANGUP_PENDING          		004H
#Define HANGUP_COMPLETE         		005H
#Define SESSION_ABORTED         		006H

#Define ALL_TRANSPORTS  				"M\0\0\0"
#Define MS_NBF          				"MNBF"

#Define NCBCALL         				010H
#Define NCBLISTEN       				011H
#Define NCBHANGUP       				012H
#Define NCBSEND         				014H
#Define NCBRECV         				015H
#Define NCBRECVANY      				016H
#Define NCBCHAINSEND    				017H
#Define NCBDGSEND       				020H
#Define NCBDGRECV       				021H
#Define NCBDGSENDBC     				022H
#Define NCBDGRECVBC     				023H
#Define NCBADDNAME      				030H
#Define NCBDELNAME      				031H
#Define NCBRESET        				032H
#Define NCBASTAT        				033H
#Define NCBSSTAT        				034H
#Define NCBCANCEL       				035H
#Define NCBADDGRNAME    				036H
#Define NCBENUM         				037H
#Define NCBUNLINK       				070H
#Define NCBSENDNA       				071H
#Define NCBCHAINSENDNA  				072H
#Define NCBLANSTALERT   				073H
#Define NCBACTION       				077H
#Define NCBFINDNAME     				078H
#Define NCBTRACE        				079H

#Define ASYNCH          				080H

#Define NRC_GOODRET     				000H

#Define NRC_BUFLEN      				001H
#Define NRC_ILLCMD      				003H
#Define NRC_CMDTMO      				005H
#Define NRC_INCOMP      				006H
#Define NRC_BADDR       				007H
#Define NRC_SNUMOUT     				008H
#Define NRC_NORES       				009H
#Define NRC_SCLOSED     				00AH
#Define NRC_CMDCAN      				00BH
#Define NRC_DUPNAME     				00DH
#Define NRC_NAMTFUL     				00EH
#Define NRC_ACTSES      				00FH
#Define NRC_LOCTFUL     				011H
#Define NRC_REMTFUL     				012H
#Define NRC_ILLNN       				013H
#Define NRC_NOCALL      				014H
#Define NRC_NOWILD      				015H
#Define NRC_INUSE       				016H
#Define NRC_NAMERR      				017H
#Define NRC_SABORT      				018H
#Define NRC_NAMCONF     				019H
#Define NRC_IFBUSY      				021H
#Define NRC_TOOMANY     				022H
#Define NRC_BRIDGE      				023H
#Define NRC_CANOCCR     				024H
#Define NRC_CANCEL      				026H
#Define NRC_DUPENV      				030H
#Define NRC_ENVNOTDEF   				034H
#Define NRC_OSRESNOTAV  				035H
#Define NRC_MAXAPPS     				036H
#Define NRC_NOSAPS      				037H
#Define NRC_NORESOURCES 				038H
#Define NRC_INVADDRESS  				039H
#Define NRC_INVDDID     				03BH
#Define NRC_LOCKFAIL    				03CH
#Define NRC_OPENERR     				03FH
#Define NRC_SYSTEM      				040H

#Define NRC_PENDING     				0FFH


NCB Struct
	ncb_command DB
	ncb_retcode DB
	ncb_lsn DB
	ncb_num DB
    ncb_buffer DD
    ncb_length DW
	ncb_callname DB NCBNAMSZ Dup ?
	ncb_name DB NCBNAMSZ Dup ?
	ncb_rto DB
	ncb_sto DB
	ncb_post DD
	ncb_lana_num DB
	ncb_cmd_cplt DB
	ncb_reserve DB 10 Dup ?
	ncb_event DD
EndS

ADAPTER_STATUS Struct
	adapter_address DB 6 Dup ?
	rev_major DB
	reserved0 DB
	adapter_type DB
	rev_minor DB
	duration DW
	frmr_recv DW
	frmr_xmit DW
	iframe_recv_err DW
	xmit_aborts DW
	xmit_success DD
	recv_success DD
	iframe_xmit_err DW
	recv_buff_unavail DW
	t1_timeouts DW
	ti_timeouts DW
	reserved1 DD
	free_ncbs DW
	max_cfg_ncbs DW
	max_ncbs DW
	xmit_buf_unavail DW
	max_dgram_size DW
	pending_sess DW
	max_cfg_sess DW
	max_sess DW
	max_sess_pkt_size DW
	name_count DW
EndS

NAME_BUFFER Struct
	name DB NCBNAMSZ Dup ?
	name_num DB
	name_flags DB
EndS

SESSION_HEADER Struct
	sess_name DB
	num_sess DB
	rcv_dg_outstanding DB
	rcv_any_outstanding DB
EndS

SESSION_BUFFER Struct
	lsn DB
	state DB
	local_name DB NCBNAMSZ Dup ?
	remote_name DB NCBNAMSZ Dup ?
	rcvs_outstanding DB
	sends_outstanding DB
EndS

LANA_ENUM Struct
	length DB
	lana DB (MAX_LANA + 1) Dup ?
EndS

FIND_NAME_HEADER Struct
	node_count DW
	reserved DB
	unique_group DB
EndS

FIND_NAME_BUFFER Struct
	length DB
	access_control DB
	frame_control DB
	destination_addr DB 6 Dup ?
    UCHAR   source_addr DB 6 Dup ?
    UCHAR   routing_info DB 18 Dup ?
EndS

ACTION_HEADER Struct
	transport_id DD
	action_code DW
	reserved DW
EndS

#ENDIF ;NB30_INC
