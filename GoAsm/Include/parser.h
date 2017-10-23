#ifndef PARSER_H
#define PARSER_H

#IFNDEF BHTYPES_H
	#include "bhtypes.h"
#ENDIF
#IFNDEF FRAME_H
	#include "frame.h"
#ENDIF
#IFNDEF BHERR_H
	#include "bherr.h"
#ENDIF

/* Microsoft Network Monitor parser DLL definitions */

#define PROTOCOL_STATUS_RECOGNIZED  0
#define PROTOCOL_STATUS_NOT_RECOGNIZED  1
#define PROTOCOL_STATUS_CLAIMED  2
#define PROTOCOL_STATUS_NEXT_PROTOCOL  3

#define HOT_SIGNATURE  A'HOT$'
#define HOE_SIGNATURE  A'HOE$'

#define MAX_PROTOCOL_NAME_LEN  16
#define MAX_PROTOCOL_COMMENT_LEN  256

MACFRAME UNION
	MacHeader PTR
	Ethernet PTR
	Tokenring PTR
	Fddi PTR
ENDS

HANDOFFENTRY STRUCT
	hoe_sig DD
	hoe_ProtIdentNumber DD
	hoe_ProtocolHandle HANDLE
	hoe_ProtocolData DD
ENDS

HANDOFFTABLE STRUCT
	hot_sig DD
	hot_NumEntries DD
	hot_Entries PTR
ENDS

HANDOFF_VALUE_FORMAT_BASE_UNKNOWN = 0
HANDOFF_VALUE_FORMAT_BASE_DECIMAL = 10
HANDOFF_VALUE_FORMAT_BASE_HEX = 16

PF_HANDOFFENTRY STRUCT
	szIniFile DB MAX_PATH DUP
	szIniSection DB MAX_PATH DUP
	szProtocol DB MAX_PROTOCOL_NAME_LEN DUP
	dwHandOffValue DD
	ValueFormatBase PTR
ENDS

PF_HANDOFFSET STRUCT
	nEntries DD
	Entry PF_HANDOFFENTRY
ENDS

PF_FOLLOWENTRY STRUCT
	szProtocol DB MAX_PROTOCOL_NAME_LEN DUP
ENDS

PF_FOLLOWSET STRUCT
	nEntries DD
	Entry PF_FOLLOWENTRY
ENDS

PF_PARSERINFO STRUCT
	szProtocolName DB MAX_PROTOCOL_NAME_LEN DUP
	szComment DB MAX_PROTOCOL_COMMENT_LEN DUP
	szHelpFile DB MAX_PATH DUP
	pWhoCanPrecedeMe PTR
	pWhoCanFollowMe PTR
	pWhoHandsOffToMe PTR
	pWhoDoIHandOffTo PTR
ENDS

PF_PARSERDLLINFO STRUCT
	nParsers DD
	ParserInfo PF_PARSERINFO
ENDS

#endif /* _PARSER_H */
