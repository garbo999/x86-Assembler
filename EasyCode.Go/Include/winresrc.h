#ifndef WINRESRC_H
#define WINRESRC_H

/* Windows resource code definitions */

#ifndef WINVER
	#define WINVER NTDDI_WINXP
#endif

#ifndef WIN32_IE
	#define WIN32_IE WIN32_IE_IE500
#endif

#define WIN32_LEAN_AND_MEAN

#IFNDEF WINDEF_H
	#include windef.h ; Windows basic type definitions - WIN32/64
#ENDIF
#IFNDEF WINBASE_H
	#include winbase.h ; Windows core definitions - WIN32/64
#ENDIF
#IFNDEF WINUSER_H
	#include winuser.h
#ENDIF
#IFNDEF WINNT_H
	#include winnt.h
#ENDIF
#IFNDEF WINVER_H
	#include winver.h
#ENDIF
#IFNDEF COMMCTRL_H
	#include commctrl.h
#ENDIF
#IFNDEF DDE_H
	#include dde.h
#ENDIF
#IFNDEF DLGS_H
	#include dlgs.h
#ENDIF

#endif /* _WINRESRC_H */
