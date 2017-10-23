;=============================================================;
;           lmat.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF LMAT_INC
#Define LMAT_INC

#Define JOB_RUN_PERIODICALLY                001H
#Define JOB_EXEC_ERROR                      002H
#Define JOB_RUNS_TODAY                      004H
#Define JOB_ADD_CURRENT_DATE                008H
#Define JOB_NONINTERACTIVE                  010H

#Define JOB_INPUT_FLAGS                    (JOB_RUN_PERIODICALLY | JOB_ADD_CURRENT_DATE | JOB_NONINTERACTIVE)
#Define JOB_OUTPUT_FLAGS                   (JOB_RUN_PERIODICALLY | JOB_EXEC_ERROR | JOB_RUNS_TODAY | JOB_NONINTERACTIVE)

AT_INFO Struct
	JobTime DD
	DaysOfMonth DD
	DaysOfWeek DB
	Flags DB
	Command DD
EndS

AT_ENUM Struct
	JobId DD
	JobTime DD
	DaysOfMonth DD
	DaysOfWeek DB
	Flags DB
	Command DD
EndS

#ENDIF ;LMAT_INC
