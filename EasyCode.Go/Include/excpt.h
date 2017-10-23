;=============================================================;
;            excpt.h file for Easy Code visual IDE            ;
;                       (GoAsm version)                       ;
;                                                             ;
;                   Driver Development Kit                    ;
;                                                             ;
;          Version 1.0.00 (created on November, 2010)         ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF ECXPT_H
#Define ECXPT_H 1

;EXCEPTION_DISPOSITION Enumeration
ExceptionContinueExecution                                  Equ         0
ExceptionContinueSearch                                     Equ         1
ExceptionNestedException                                    Equ         2
ExceptionCollidedUnwind                                     Equ         3

EXCEPTION_EXECUTE_HANDLER                                   Equ         1
EXCEPTION_CONTINUE_SEARCH                                   Equ         0
EXCEPTION_CONTINUE_EXECUTION                                Equ         (-1)

#ENDIF ;ECXPT_H
