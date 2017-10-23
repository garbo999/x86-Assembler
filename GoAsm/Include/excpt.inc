;=============================================================;
;           excpt.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF EXCPT_INC
#Define EXCPT_INC

;EXCEPTION_DISPOSITION enumeration
ExceptionContinueExecution				Equ 0
ExceptionContinueSearch					Equ 1
ExceptionNestedException				Equ 2
ExceptionCollidedUnwind					Equ 3

#Define EXCEPTION_EXECUTE_HANDLER       1
#define EXCEPTION_CONTINUE_SEARCH       0
#Define EXCEPTION_CONTINUE_EXECUTION    (-1)

#ENDIF ;EXCPT_INC
