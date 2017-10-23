#ifndef WINEFS_H
#define WINEFS_H

/* Windows File Encryption definitions */

#define MAX_SID_SIZE  256

#IFDEF LINKFILES
	#dynamiclinkfile Advapi32.dll
#ENDIF

CERTIFICATE_BLOB STRUCT
	dwCertEncodingType DD
	cbData DD
	pbData PTR
ENDS

EFS_HASH_BLOB STRUCT
	cbData DD
	pbData PTR
ENDS

ENCRYPTION_CERTIFICATE STRUCT
	cbTotalLength DD
	pUserSid PTR
	pCertBlob PTR
ENDS

ENCRYPTION_CERTIFICATE_HASH STRUCT
	cbTotalLength DD
	pUserSid PTR
	pHash PTR
	lpDisplayInformation PTR
ENDS

ENCRYPTION_CERTIFICATE_HASH_LIST STRUCT
	nCert_Hash DD
	pUsers PTR
ENDS

ENCRYPTION_CERTIFICATE_LIST STRUCT
	nUsers DD
	pUsers PTR
ENDS

#endif /* WINEFS_H */

