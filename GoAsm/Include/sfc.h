#ifndef SFC_H
#define SFC_H

/* Windows File Protection definitions */

#define SFC_DISABLE_NORMAL  0
#define SFC_DISABLE_ASK  1
#define SFC_DISABLE_ONCE  2
#define SFC_DISABLE_SETUP  3
#define SFC_DISABLE_NOPOPUPS  4

#define SFC_SCAN_NORMAL  0
#define SFC_SCAN_ALWAYS  1
#define SFC_SCAN_ONCE  2

#define SFC_QUOTA_DEFAULT  50
#define SFC_QUOTA_ALL_FILES  ((ULONG)-1)

PROTECTED_FILE_DATA STRUCT
	FileName DW MAX_PATH DUP (?)
	FileNumber DD
ENDS

#endif /* _SFC_H */
