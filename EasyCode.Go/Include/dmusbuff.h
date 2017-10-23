#ifndef DMUSBUFF_H
#define DMUSBUFF_H

#DEFINE DMUSBUFF_H_REQVER 100

/* DirectMusic shared file buffer format definitions */

#define DMUS_EVENT_STRUCTURED   0x00000001

DMUS_EVENTHEADER STRUCT
	cbEvent DD
	dwChannelGroup DD
	rtDelta DD
	dwFlags DD
ENDS

#endif /* DMUSBUFF_H */

