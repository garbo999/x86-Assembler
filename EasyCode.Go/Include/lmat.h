#ifndef LMAT_H
#define LMAT_H

/* Schedule service API definitions */

#define JOB_RUN_PERIODICALLY  0x01
#define JOB_EXEC_ERROR  0x02
#define JOB_RUNS_TODAY  0x04
#define JOB_ADD_CURRENT_DATE  0x08
#define JOB_NONINTERACTIVE  0x10

#define JOB_INPUT_FLAGS  (JOB_RUN_PERIODICALLY|JOB_ADD_CURRENT_DATE|JOB_NONINTERACTIVE)
#define JOB_OUTPUT_FLAGS  (JOB_RUN_PERIODICALLY|JOB_EXEC_ERROR|JOB_RUNS_TODAY|JOB_NONINTERACTIVE)

AT_ENUM STRUCT
	JobId DD
	JobTime DWORD_PTR
	DaysOfMonth DD
	DaysOfWeek DB
	Flags DB
	Command PTR
ENDS

AT_INFO STRUCT
	JobTime DWORD_PTR
	DaysOfMonth DD
	DaysOfWeek DB
	Flags DB
	Command PTR
ENDS

#endif /* _LMAT_H */
