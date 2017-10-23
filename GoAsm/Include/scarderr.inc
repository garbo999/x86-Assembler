;=============================================================;
;         scarderr.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF SCARDERR_INC
#Define SCARDERR_INC

#IFNDEF SCARD_S_SUCCESS
	#Define SCARD_S_SUCCESS                 NO_ERROR
	#Define FACILITY_SYSTEM                 00H
	#Define FACILITY_SCARD                  010H

	#Define SCARD_F_INTERNAL_ERROR          080100001H
	#Define SCARD_E_CANCELLED               080100002H
	#Define SCARD_E_INVALID_HANDLE          080100003H
	#Define SCARD_E_INVALID_PARAMETER       080100004H
	#Define SCARD_E_INVALID_TARGET          080100005H
	#Define SCARD_E_NO_MEMORY               080100006H
	#Define SCARD_F_WAITED_TOO_LONG         080100007H
	#Define SCARD_E_INSUFFICIENT_BUFFER     080100008H
	#Define SCARD_E_UNKNOWN_READER          080100009H
	#Define SCARD_E_TIMEOUT                 08010000AH
	#Define SCARD_E_SHARING_VIOLATION       08010000BH
	#Define SCARD_E_NO_SMARTCARD            08010000CH
	#Define SCARD_E_UNKNOWN_CARD            08010000DH
	#Define SCARD_E_CANT_DISPOSE            08010000EH
	#Define SCARD_E_PROTO_MISMATCH          08010000FH
	#Define SCARD_E_NOT_READY               080100010H
	#Define SCARD_E_INVALID_VALUE           080100011H
	#Define SCARD_E_SYSTEM_CANCELLED        080100012H
	#Define SCARD_F_COMM_ERROR              080100013H
	#Define SCARD_F_UNKNOWN_ERROR           080100014H
	#Define SCARD_E_INVALID_ATR             080100015H
	#Define SCARD_E_NOT_TRANSACTED          080100016H
	#Define SCARD_E_READER_UNAVAILABLE      080100017H
	#Define SCARD_P_SHUTDOWN                080100018H
	#Define SCARD_E_PCI_TOO_SMALL           080100019H
	#Define SCARD_E_READER_UNSUPPORTED      08010001AH
	#Define SCARD_E_DUPLICATE_READER        08010001BH
	#Define SCARD_E_CARD_UNSUPPORTED        08010001CH
	#Define SCARD_E_NO_SERVICE              08010001DH
	#Define SCARD_E_SERVICE_STOPPED         08010001EH
	#Define SCARD_W_UNSUPPORTED_CARD        080100065H
	#Define SCARD_W_UNRESPONSIVE_CARD       080100066H
	#Define SCARD_W_UNPOWERED_CARD          080100067H
	#Define SCARD_W_RESET_CARD              080100068H
	#Define SCARD_W_REMOVED_CARD            080100069H
#ENDIF
#ENDIF ;SCARDERR_INC
