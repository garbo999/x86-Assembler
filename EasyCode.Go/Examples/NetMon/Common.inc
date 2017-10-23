MIB_TCP_STATE_CLOSED		Equ				1
MIB_TCP_STATE_LISTEN		Equ				2
MIB_TCP_STATE_SYN_SENT		Equ				3
MIB_TCP_STATE_SYN_RCVD		Equ				4
MIB_TCP_STATE_ESTAB			Equ				5
MIB_TCP_STATE_FIN_WAIT1		Equ				6
MIB_TCP_STATE_FIN_WAIT2		Equ				7
MIB_TCP_STATE_CLOSE_WAIT	Equ				8
MIB_TCP_STATE_CLOSING		Equ				9
MIB_TCP_STATE_LAST_ACK		Equ				10
MIB_TCP_STATE_TIME_WAIT		Equ				11
MIB_TCP_STATE_DELETE_TCB	Equ				12

MIB_IFROW Struct
    wszName					DW 				256 Dup ?	;MAX_INTERFACE_NAME_LEN
    dwIndex					DD	 			?
    dwType					DD	 			?
    dwMtu					DD	 			?
    dwSpeed					DD	 			?
    dwPhysAddrLen			DD	 			?
    bPhysAddr  				DB				8 Dup ?		;MAXLEN_PHYSADDR
    dwAdminStatus			DD	 			?
    dwOperStatus			DD	 			?
    dwLastChange			DD	 			?
    dwInOctets				DD	 			?
    dwInUcastPkts			DD	 			?
    dwInNUcastPkts			DD	 			?
    dwInDiscards			DD	 			?
    dwInErrors				DD	 			?
    dwInUnknownProtos		DD	 			?
    dwOutOctets				DD	 			?
    dwOutUcastPkts			DD	 			?
    dwOutNUcastPkts			DD	 			?
    dwOutDiscards			DD	 			?
    dwOutErrors				DD	 			?
    dwOutQLen				DD	 			?
    dwDescrLen				DD	 			?
    bDescr					DB				256 Dup ?	;MAXLEN_IFDESCR
EndS

MIB_IPADDRROW Struct
	dwAddr 					DD				? ;IP address
	dwIndex					DD				? ;interface index
	dwMask					DD				? ;subnet mask
	dwBCastAddr				DD				? ;broadcast address
	dwReasmSize				DD				? ;rassembly size
	unused1					DW				? ;not currently used
	unused2					DW				? ;not currently used
EndS

ADAPTER_DATA Struct
	dwAddress				DD				?
	dwIndex					DD				?
	dwMask					DD				?
	dwType					DD				?
	dwBytesIn				DD				?
	dwBytesOut				DD				?
	dwLastBytesIn			DD				?
	dwLastBytesOut			DD				?
	dwLastSpeedIn			DD				?
	dwLastSpeedOut			DD				?
EndS

MIB_TCPROW Struct
	dwState					DD				? ;state of the connection
	dwLocalAddr				DD				? ;address on local computer
	dwLocalPort				DD				? ;port number on local computer
	dwRemoteAddr			DD				? ;address on remote computer
	dwRemotePort			DD				? ;port number on remote computer
EndS

MIB_TCPROW_OWNER_PID Struct
	dwState					DD				? ;state of the connection
	dwLocalAddr				DD				? ;address on local computer
	dwLocalPort				DD				? ;port number on local computer
	dwRemoteAddr			DD				? ;address on remote computer
	dwRemotePort			DD				? ;port number on remote computer
	dwOwningPid				DD				? ;PID of process using the port
EndS

MIB_UDPROW Struct
	dwLocalAddr				DD				?
  	dwLocalPort				DD				?
EndS

MIB_UDPROW_OWNER_PID Struct
  dwLocalAddr				DD				?
  dwLocalPort				DD				?
  dwOwningPid				DD				?
EndS
