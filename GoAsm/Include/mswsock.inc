;=============================================================;
;          mswsock.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF MSWSOCK_INC
#Define MSWSOCK_INC

#Define SO_CONNDATA                 07000H
#Define SO_CONNOPT                  07001H
#Define SO_DISCDATA                 07002H
#Define SO_DISCOPT                  07003H
#Define SO_CONNDATALEN              07004H
#Define SO_CONNOPTLEN               07005H
#Define SO_DISCDATALEN              07006H
#Define SO_DISCOPTLEN               07007H

#Define SO_OPENTYPE                 07008H

#Define SO_SYNCHRONOUS_ALERT        010H
#Define SO_SYNCHRONOUS_NONALERT     020H

#Define SO_MAXDG                    07009H
#Define SO_MAXPATHDG                0700AH
#Define SO_UPDATE_ACCEPT_CONTEXT    0700BH
#Define SO_CONNECT_TIME             0700CH

#Define TCP_BSDURGENT               07000H

#Define TF_DISCONNECT       		001H
#Define TF_REUSE_SOCKET     		002H
#Define TF_WRITE_BEHIND     		004H

#Define WSAID_TRANSMITFILE			<0B5367DF0H, 0CBACH, 011CFH, <095H, 0CAH, 000H, 080H, 05FH, 048H, 0A1H, 092H>>

#ENDIF ;MSWSOCK_INC
