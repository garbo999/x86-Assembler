#ifndef SECURITY_H
#define SECURITY_H

/* Security aware components definitions (toplevel) */

#ifndef NTLMSP_NAME_A
	#define NTLMSP_NAME_A  A"NTLM"
	#define NTLMSP_NAME_W  L"NTLM"
	#IFDEF UNICODE
		#define NTLMSP_NAME  NTLMSP_NAME_W
	#else
		#define NTLMSP_NAME  NTLMSP_NAME_A
	#endif
#endif

#ifndef MICROSOFT_KERBEROS_NAME_A
	#define MICROSOFT_KERBEROS_NAME_A  A"Kerberos"
	#define MICROSOFT_KERBEROS_NAME_W  L"Kerberos"
	#ifdef UNICODE
		#define MICROSOFT_KERBEROS_NAME MICROSOFT_KERBEROS_NAME_W
	#else
		#define MICROSOFT_KERBEROS_NAME MICROSOFT_KERBEROS_NAME_A
	#endif
#endif /* MICROSOFT_KERBEROS_NAME_A */

#ifndef NEGOSSP_NAME
	#define NEGOSSP_NAME_W  L"Negotiate"
	#define NEGOSSP_NAME_A  A"Negotiate"
	#IFDEF UNICODE
		#define NEGOSSP_NAME  NEGOSSP_NAME_W
	#else
		#define NEGOSSP_NAME  NEGOSSP_NAME_A
	#endif
#endif /* NEGOSSP_NAME */

#IFNDEF SSPI_H
	#include sspi.h
#ENDIF

#IFNDEF SECEXT_H
	#include secext.h
#ENDIF

#endif /* _SECURITY_H */
