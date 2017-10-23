#ifndef TNEF_H
#define TNEF_H

/* MAPI Transport Neutral Encapsilation Format definitions */

#IFDEF LINKFILES
	#dynamiclinkfile mapi32.dll
#ENDIF

STnefProblem STRUCT
	ulComponent DD
	ulAttribute DD
	ulPropTag DD
	scode DD
ENDS

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

STnefProblemArray STRUCT
	cProblem DD
	aProblem STnefProblem MAPI_DIM DUP
ENDS

#define TNEF_DECODE  0
#define TNEF_ENCODE  2

#define TNEF_PURE  0x00010000
#define TNEF_COMPATIBILITY  0x00020000
#define TNEF_BEST_DATA  0x00040000
#define TNEF_COMPONENT_ENCODING  0x80000000

#define TNEF_PROP_INCLUDE  0x00000001
#define TNEF_PROP_EXCLUDE  0x00000002
#define TNEF_PROP_CONTAINED  0x00000004
#define TNEF_PROP_MESSAGE_ONLY  0x00000008
#define TNEF_PROP_ATTACHMENTS_ONLY  0x00000010
#define TNEF_PROP_CONTAINED_TNEF  0x00000040

#define TNEF_COMPONENT_MESSAGE  0x00001000
#define TNEF_COMPONENT_ATTACHMENT  0x00002000

#define OPENTNEFSTREAM  "OpenTnefStream"
#define OPENTNEFSTREAMEX  "OpenTnefStreamEx"
#define GETTNEFSTREAMCODEPAGE  "GetTnefStreamCodePage"

#define TNEF_SIGNATURE 0x223E9F78

#define MAC_BINARY  0x00000001

#define fmsNull  0x00
#define fmsModified  0x01
#define fmsLocal  0x02
#define fmsSubmitted  0x04
#define fmsRead  0x20
#define fmsHasAttach  0x80

#define trpidNull  0x0000
#define trpidUnresolved  0x0001
#define trpidResolvedNSID  0x0002
#define trpidResolvedAddress  0x0003
#define trpidOneOff  0x0004
#define trpidGroupNSID  0x0005
#define trpidOffline  0x0006
#define trpidIgnore  0x0007
#define trpidClassEntry  0x0008
#define trpidResolvedGroupAddress  0x0009

#define cbDisplayName  41
#define cbEmailName  11
#define cbSeverName  12

#define xtypeUnknown  0
#define xtypeInternet  6

#define cbALIAS sizeof ALIAS

#define cbTYPE  16
#define cbMaxIdData  200

#define cbNSID sizeof NSID

#define prioLow  3
#define prioNorm  2
#define prioHigh  1

#define atpTriples  0x0000
#define atpString  0x0001
#define atpText  0x0002
#define atpDate  0x0003
#define atpShort  0x0004
#define atpLong  0x0005
#define atpByte  0x0006
#define atpWord  0x0007
#define atpDword  0x0008
#define atpMax  0x0009

#define LVL_MESSAGE  0x01
#define LVL_ATTACHMENT  0x02

#define attNull  (0<<16)|(0x0000)
#define attFrom  (atpTriples<<16)|(0x8000)
#define attSubject  (atpString<<16)|(0x8004)
#define attDateSent  (atpDate<<16)|(0x8005)
#define attDateRecd  (atpDate<<16)|(0x8006)
#define attMessageStatus  (atpByte<<16)|(0x8007)
#define attMessageClass  (atpWord<<16)|(0x8008)
#define attMessageID  (atpString<<16)|(0x8009)
#define attParentID  (atpString<<16)|(0x800A)
#define attConversationID  (atpString<<16)|(0x800B)
#define attBody  (atpText<<16)|(0x800C)
#define attPriority  (atpShort<<16)|(0x800D)
#define attAttachData  (atpByte<<16)|(0x800F)
#define attAttachTitle  (atpString<<16)|(0x8010)
#define attAttachMetaFile  (atpByte<<16)|(0x8011)
#define attAttachCreateDate  (atpDate<<16)|(0x8012)
#define attAttachModifyDate  (atpDate<<16)|(0x8013)
#define attDateModified  (atpDate<<16)|(0x8020)
#define attAttachTransportFilename  (atpByte<<16)|(0x9001)
#define attAttachRenddata  (atpByte<<16)|(0x9002)
#define attMAPIProps  (atpByte<<16)|(0x9003)
#define attRecipTable  (atpByte<<16)|(0x9004)
#define attAttachment  (atpByte<<16)|(0x9005)
#define attTnefVersion  (atpDword<<16)|(0x9006)
#define attOemCodepage  (atpByte<<16)|(0x9007)
#define attOriginalMessageClass  (atpWord<<16)|(0x0006)

#define attOwner  (atpByte<<16)|(0x0000)
#define attSentFor  (atpByte<<16)|(0x0001)
#define attDelegate  (atpByte<<16)|(0x0002)
#define attDateStart  (atpDate<<16)|(0x0006)
#define attDateEnd  (atpDate<<16)|(0x0007)
#define attAidOwner  (atpLong<<16)|(0x0008)
#define attRequestRes  (atpShort<<16)|(0x0009)

ITnef STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	AddProps PTR
	ExtractProps PTR
	Finish PTR
	OpenTaggedBody PTR
	SetProps PTR
	EncodeRecips PTR
	FinishComponent PTR
ENDS

atypNull = 0
atypFile = 1
atypOle = 2
atypPicture = 3
atypMax = 4

RENDDATA STRUCT
	atyp DD
	ulPosition DD
	dxWidth DW
	dyHeight DW
	dwFlags DD
ENDS

DTR STRUCT
	wYear DW
	wMonth DW
	wDay DW
	wHour DW
	wMinute DW
	wSecond DW
	wDayOfWeek DW
ENDS

TRP STRUCT
	trpid DW
	cbgrtrp DW
	cch DW
	cbRgb DW
ENDS

ADDRALIAS STRUCT
	rgchName DB cbDisplayName DUP
	rgchEName DB cbEmailName DUP
	rgchSrvr DB cbSeverName DUP
	dibDetail DD
	type DW
ENDS

NSID STRUCT
	dwSize DD
	uchType DB cbTYPE DUP
	xtype DD
	lTime DD
	UNION
		alias ADDRALIAS
		char rgchInterNet DB
	ENDUNION
ENDS

#endif
