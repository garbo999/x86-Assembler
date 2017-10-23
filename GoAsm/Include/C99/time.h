#ifndef TIME_H
#define TIME_H

/* time.h - C99 standard header */

#define CLOCKS_PER_SEC  1000

tm struct
	tm_sec dd     /* seconds after the minute [0,60] */
	tm_min dd     /* minutes after the hour [0,59] */
	tm_hour dd    /* hours since midnight [0,23] */
	tm_mday dd    /* day of the month [1,31] */
	tm_mon dd     /* month since January [0,11] */
	tm_year dd    /* years since 1900 */
	tm_wday dd    /* days since Sunday [0,6] */
	tm_yday dd    /* days since January 1 [0,365] */
	tm_isdst dd   /* Daylight Saving Time flag */
ends

#endif /* TIME_H */

