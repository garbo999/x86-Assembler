#ifndef EXCPT_H
#define EXCPT_H

/* excpt.h - private header for SEH definitions */

#define EXCEPTION_EXECUTE_HANDLER  1
#define EXCEPTION_CONTINUE_SEARCH  0
#define EXCEPTION_CONTINUE_EXECUTION  (-1)

ExceptionContinueExecution = 0
ExceptionContinueSearch = 1
ExceptionNestedException = 2
ExceptionCollidedUnwind = 3

#Define SIZE_OF_80387_REGISTERS 80
#Define MAXIMUM_SUPPORTED_EXTENSION 512
#Define EXCEPTION_MAXIMUM_PARAMETERS 15

#IFNDEF FLOATING_SAVE_AREA
FLOATING_SAVE_AREA STRUCT
  ControlWord   DD ; 0
  StatusWord    DD ; 4
  TagWord       DD ; 8
  ErrorOffset   DD ; 12
  ErrorSelector DD ; 16
  DataOffset    DD ; 20
  DataSelector  DD ; 24
  RegisterArea  DB  SIZE_OF_80387_REGISTERS dup (?) ; 28
  Cr0NpxState   DD ; 108
ENDS ; 112 Bytes
#ENDIF

/*
CONTEXT STRUCT
  ContextFlags  DD ; 0
  iDr0          DD ; 4
  iDr1          DD ; 8
  iDr2          DD ; 12
  iDr3          DD ; 16
  iDr6          DD ; 20
  iDr7          DD ; 24
  FloatSave     FLOATING_SAVE_AREA <> ; 28
  regGs         DD ; 140
  regFs         DD ; 144
  regEs         DD ; 148
  regDs         DD ; 152
  regEdi        DD ; 156
  regEsi        DD ; 160
  regEbx        DD ; 164
  regEdx        DD ; 168
  regEcx        DD ; 172
  regEax        DD ; 176
  regEbp        DD ; 180
  regEip        DD ; 184
  regCs         DD ; 188
  regFlag       DD ; 192
  regEsp        DD ; 196
  regSs         DD ; 200
  ExtendedRegisters DB MAXIMUM_SUPPORTED_EXTENSION dup (?) ; 204
ENDS ; 716 Bytes
*/

#IFNDEF CONTEXT
CONTEXT STRUCT
	ContextFlags DD
	Dr0 DD
	Dr1 DD
	Dr2 DD
	Dr3 DD
	Dr6 DD
	Dr7 DD
	FloatSave FLOATING_SAVE_AREA <>
	SegGs DD
	SegFs DD
	SegEs DD
	SegDs DD
	Edi DD
	Esi DD
	Ebx DD
	Edx DD
	Ecx DD
	Eax DD
	Ebp DD
	Eip DD
	SegCs DD
	EFlags DD
	Esp DD
	SegSs DD
	ExtendedRegisters DB MAXIMUM_SUPPORTED_EXTENSION DUP (?)
ENDS
#ENDIF

#IFNDEF EXCEPTION_RECORD
EXCEPTION_RECORD STRUCT
  ExceptionCode         DD
  ExceptionFlags        DD
  pExceptionRecord      DD
  ExceptionAddress      DD
  NumberParameters      DD
  ExceptionInformation  DD EXCEPTION_MAXIMUM_PARAMETERS dup (?)
ENDS
#ENDIF

#endif /* _EXCPT_H */
