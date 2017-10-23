#ifndef PROFINFO_H
#define PROFINFO_H

/* Profile info definitions */

PROFILEINFOA STRUCT
	dwSize DD
	dwFlags DD
	lpUserName PTR
	lpProfilePath PTR
	lpDefaultPath PTR
	lpServerName PTR
	lpPolicyPath PTR
	hProfile HANDLE
ENDS

PROFILEINFOW STRUCT
	dwSize DD
	dwFlags DD
	lpUserName PTR
	lpProfilePath PTR
	lpDefaultPath PTR
	lpServerName PTR
	lpPolicyPath PTR
	hProfile HANDLE
ENDS

#IFDEF UNICODE
	#define PROFILEINFO PROFILEINFOW
#else
	#define PROFILEINFO PROFILEINFOA
#endif /* UNICODE */

#endif /* _PROFINFO_H */
