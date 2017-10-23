#ifndef RPC_H
#define RPC_H

#IFDEF LINKFILES
	#dynamiclinkfile Rpcns4.dll
#ENDIF

#ifndef COM_NO_WINDOWS_H
	#ifndef RPC_NO_WINDOWS_H
		#ifndef WINDOWS_H
			#include windows.h // WIN32/64
		#ENDIF
	#endif
#ENDIF

#IFNDEF WINERROR_H
	#include winerror.h // WIN3264
#ENDIF

#IFNDEF RPCDCE_H
	#include rpcdce.h // WIN3264
#ENDIF

#IFNDEF RPCNSI_H
	#include rpcnsi.h // WIN3264
#ENDIF

#IFNDEF RPCNTERR_H
	#include rpcnterr.h // WIN3264
#ENDIF

#IFNDEF EXCPT_H
	#include C99\excpt.h // WIN3264 through WINNT
#ENDIF

#ifndef RPC_NO_WINDOWS_H
	#include rpcasync.h // WIN3264
#endif

#endif
