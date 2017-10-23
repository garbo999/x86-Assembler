;=============================================================;
;         rpcnterr.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF RPCNTERR_INC
#Define RPCNTERR_INC

#Define RPC_S_OK                            ERROR_SUCCESS
#Define RPC_S_INVALID_ARG                   ERROR_INVALID_PARAMETER
#Define RPC_S_OUT_OF_MEMORY                 ERROR_OUTOFMEMORY
#Define RPC_S_OUT_OF_THREADS                ERROR_MAX_THRDS_REACHED
#Define RPC_S_INVALID_LEVEL                 ERROR_INVALID_PARAMETER
#Define RPC_S_BUFFER_TOO_SMALL              ERROR_INSUFFICIENT_BUFFER
#Define RPC_S_INVALID_SECURITY_DESC         ERROR_INVALID_SECURITY_DESCR
#Define RPC_S_ACCESS_DENIED                 ERROR_ACCESS_DENIED
#Define RPC_S_SERVER_OUT_OF_MEMORY          ERROR_NOT_ENOUGH_SERVER_MEMORY
#Define RPC_S_ASYNC_CALL_PENDING            ERROR_IO_PENDING

#Define RPC_X_NO_MEMORY                     RPC_S_OUT_OF_MEMORY
#Define RPC_X_INVALID_BOUND                 RPC_S_INVALID_BOUND
#Define RPC_X_INVALID_TAG                   RPC_S_INVALID_TAG
#Define RPC_X_ENUM_VALUE_TOO_LARGE          RPC_X_ENUM_VALUE_OUT_OF_RANGE
#Define RPC_X_SS_CONTEXT_MISMATCH           ERROR_INVALID_HANDLE
#Define RPC_X_INVALID_BUFFER                ERROR_INVALID_USER_BUFFER
#Define RPC_X_PIPE_APP_MEMORY               ERROR_OUTOFMEMORY
#Define RPC_X_INVALID_PIPE_OPERATION        RPC_X_WRONG_PIPE_ORDER

#ENDIF ;RPCNTERR_INC
