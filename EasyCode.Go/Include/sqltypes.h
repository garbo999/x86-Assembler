#ifndef SQLTYPES_H
#define SQLTYPES_H

/* ODBC type definitions */

DATE_STRUCT STRUCT
	year DW
	month DW
	day DW
ENDS

TIME_STRUCT STRUCT
	hour DW
	minute DW
	second DW
ENDS

TIMESTAMP_STRUCT STRUCT
	year DW
	month DW
	day DW
	hour DW
	minute DW
	second DW
	fraction DD
ENDS

SQL_IS_YEAR = 1
SQL_IS_MONTH = 2
SQL_IS_DAY = 3
SQL_IS_HOUR = 4
SQL_IS_MINUTE = 5
SQL_IS_SECOND = 6
SQL_IS_YEAR_TO_MONTH = 7
SQL_IS_DAY_TO_HOUR = 8
SQL_IS_DAY_TO_MINUTE = 9
SQL_IS_DAY_TO_SECOND = 10
SQL_IS_HOUR_TO_MINUTE = 11
SQL_IS_HOUR_TO_SECOND = 12
SQL_IS_MINUTE_TO_SECOND = 13


SQL_YEAR_MONTH STRUCT
	year DD
	month DD
ENDS

SQL_DAY_SECOND STRUCT
	day DD
	hour DD
	minute DD
	second DD
	fraction DD
ENDS

SQL_INTERVAL_STRUCT STRUCT
	interval_type DD
	interval_sign DW
	UNION
		year_month SQL_YEAR_MONTH_STRUCT <>
		day_second SQL_DAY_SECOND_STRUCT <>
	ENDUNION
ENDS

#define SQL_MAX_NUMERIC_LEN  16

SQL_NUMERIC_STRUCT
	precision DB
	scale DB
	sign DB
	val DB SQL_MAX_NUMERIC_LEN DUP (?)
ENDS

#DEFINE SQLGUID GUID

#endif /* _SQLTYPES_H */
