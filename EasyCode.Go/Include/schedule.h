#ifndef SCHEDULE_H
#define SCHEDULE_H

/* Windows NT common schedule structure definitions */

#define SCHEDULE_INTERVAL  0
#define SCHEDULE_BANDWIDTH  1
#define SCHEDULE_PRIORITY  2

#define SCHEDULE_DATA_ENTRIES  (7*24)

SCHEDULE_HEADER STRUCT
	Type DD
	Offset DD
ENDS

SCHEDULE STRUCT
	Size DD
	Bandwidth DD
	NumberOfSchedules DD
	Schedules SCHEDULE_HEADER
ENDS

#endif /* _SCHEDULE_H */

