;=============================================================;
;           adsdb.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF ADSDB_INC
#Define ADSDB_INC

#Define ADSIPROP_ASYNCHRONOUS		000000000H
#Define ADSIPROP_DEREF_ALIASES      000000001H
#Define ADSIPROP_SIZE_LIMIT         000000002H
#Define ADSIPROP_TIME_LIMIT         000000003H
#Define ADSIPROP_ATTRIBTYPES_ONLY   000000004H
#Define ADSIPROP_SEARCH_SCOPE       000000005H
#Define ADSIPROP_TIMEOUT            000000006H
#Define ADSIPROP_PAGESIZE           000000007H
#Define ADSIPROP_PAGED_TIME_LIMIT   000000008H
#Define ADSIPROP_CHASE_REFERRALS    000000009H

#Define DBPROPFLAGS_ADSISEARCH      00000C000H

#Define ADSI_DIALECT_LDAP           000000000H
#Define ADSI_DIALECT_SQL            000000001H

#ENDIF ;ADSDB_INC
