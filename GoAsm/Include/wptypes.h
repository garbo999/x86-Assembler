#ifndef WPTYPES_H
#define WPTYPES_H

/* Microsoft Web Publishing API data type definitions */

WPSITEINFOA STRUCT
	dwSize DD
	dwFlags DD
	lpszSiteName PTR
	lpszSiteURL PTR
ENDS

WPSITEINFOW STRUCT
	dwSize DD
	dwFlags DD
	lpszSiteName PTR
	lpszSiteURL PTR
ENDS

WPPROVINFOA STRUCT
	dwSize DD
	dwFlags DD
	dwPriority DD
	lpszProviderName PTR
	lpszProviderCLSID PTR
	lpszDllPath PTR
ENDS

WPPROVINFOW STRUCT
	dwSize DD
	dwFlags DD
	dwPriority DD
	lpszProviderName PTR
	lpszProviderCLSID PTR
	lpszDllPath PTR
ENDS

#IFDEF UNICODE
	#define WPSITEINFO WPSITEINFOW
	#define WPPROVINFO WPPROVINFOW
#else
	#define WPSITEINFO WPSITEINFOA
	#define WPPROVINFO WPPROVINFOA
#endif

#endif /* _WPTYPES_H */

