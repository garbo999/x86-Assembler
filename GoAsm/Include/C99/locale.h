#ifndef LOCALE_H
#define LOCALE_H

/* locale.h - C99 standard header */

/* macros */
#ifndef NULL
#define NULL 0
#endif

/* locale categories */
#define LC_COLLATE   1
#define LC_CTYPE     2
#define LC_MONETARY  4
#define LC_NUMERIC   8
#define LC_TIME      16
#define LC_ALL       (LC_COLLATE|LC_CTYPE|LC_MONETARY|LC_NUMERIC|LC_TIME)

/* type definitions */
lconv struct
	/* LC_MONETARY */
	currency_symbol DD
	int_curr_symbol DD
	mon_decimal_point DD
	mon_grouping DD
	mon_thousands_sep DD
	negative_sign DD
	positive_sign DD
	frac_digits DB
	n_cs_precedes DB
	n_sep_by_space DB
	n_sign_posn DB
	p_cs_precedes DB
	p_sep_by_space DB
	p_sign_posn DB
	int_frac_digits DB
	int_n_cs_precedes DB
	int_n_sep_by_space DB
	int_n_sign_posn DB
	int_p_cs_precedes DB
	int_p_sep_by_space DB
 	int_p_sign_posn DB
    /* LC_NUMERIC */
	decimal_point DD
	grouping DD
	thousands_sep DD
ends

#endif /* LOCALE_H */

