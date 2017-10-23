#IFNDEF CERTADM_H
#define CERTADM_H

#IFNDEF RPC_H
	#include "rpc.h"
#ENDIF

#IFNDEF RPCNDR_H
	#include "rpcndr.h"
#ENDIF

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

#define CA_DISP_INCOMPLETE  0
#define CA_DISP_ERROR  1
#define CA_DISP_REVOKED 2
#define CA_DISP_VALID  3
#define CA_DISP_INVALID 4
#define CA_DISP_UNDER_SUBMISSION  5

#define GUID_IID_ICertAdmin <0x34df6950,0x7fb6,0x11d0,<0x88,0x17,0x00,0xa0,0xc9,0x03,0xb8,0x3c>>
ICertAdmin STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	IsValidCertificate PTR
	GetRevocationReason PTR
	RevokeCertificate PTR
	SetRequestAttributes PTR
	SetCertificateExtension PTR
	DenyRequest PTR
	ResubmitRequest PTR
	PublishCRL PTR
	GetCRL PTR
	ImportCertificate PTR
ENDS

#ENDIF /* CERTADM_H */
