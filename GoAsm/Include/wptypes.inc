;=============================================================;
;          wptypes.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF WPTYPES_INC
#Define WPTYPES_INC

WPSITEINFOA Struct
	dwSize DD
	dwFlags DD
	lpszSiteName DD
	lpszSiteURL DD
EndS

WPSITEINFOW Struct
	dwSize DD
	dwFlags DD
	lpszSiteName DD
	lpszSiteURL DD
EndS

WPPROVINFOA Struct
	dwSize DD
	dwFlags DD
	dwPriority DD
	lpszProviderName DD
	lpszProviderCLSID DD
	lpszDllPath DD
EndS

WPPROVINFOW Struct
	dwSize DD
	dwFlags DD
	dwPriority DD
	lpszProviderName DD
	lpszProviderCLSID DD
	lpszDllPath DD
EndS


#IF STRINGS UNICODE
	#Define WPSITEINFO WPSITEINFOW
	#Define LPWPSITEINFO LPWPSITEINFOW
	#Define WPPROVINFO WPPROVINFOW
	#Define LPWPPROVINFO LPWPPROVINFOW
#ELSE
	#Define WPSITEINFO WPSITEINFOA
	#Define LPWPSITEINFO LPWPSITEINFOA
	#Define WPPROVINFO WPPROVINFOA
	#Define LPWPPROVINFO LPWPPROVINFOA
#ENDIF

#ENDIF ;WPTYPES_INC
