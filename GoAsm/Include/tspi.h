#ifndef TSPI_H
#define TSPI_H

/* Telephony Service Provider Interface (TSPI) definitions */

#IFDEF LINKFILES
	#dynamiclinkfile TAPISRV.dll
#ENDIF

#IFNDEF WINDOWS_H
	#include "windows.h"
#ENDIF
#IFNDEF TAPI_H
	#include "tapi.h"
#ENDIF

TUISPICREATEDIALOGINSTANCEPARAMS STRUCT
	dwRequestID DD
	hdDlgInst HANDLE
	htDlgInst HANDLE
	lpszUIDLLName PTR
	lpParams PTR
	dwSize DD
ENDS

#define LINEQOSSTRUCT_KEY  A'LQSK'

LINEQOSSERVICELEVEL STRUCT
	dwMediaMode DD
	dwQOSServiceLevel DD
ENDS

LINECALLQOSINFO STRUCT
	dwKey DD
	dwTotalSize DD
	dwQOSRequestType DD
    SetQOSServiceLevel STRUCT
    	dwNumServiceLevelEntries DD
		LineQOSServiceLevel LINEQOSSERVICELEVEL
    ENDS
ENDS

#define TSPI_MESSAGE_BASE 500

#define LINE_NEWCALL  TSPI_MESSAGE_BASE+0
#define LINE_CALLDEVSPECIFIC  TSPI_MESSAGE_BASE+1
#define LINE_CALLDEVSPECIFICFEATURE  TSPI_MESSAGE_BASE+2
#define LINE_CREATEDIALOGINSTANCE  TSPI_MESSAGE_BASE+3
#define LINE_SENDDIALOGINSTANCEDATA  TSPI_MESSAGE_BASE+4
#define LINE_SENDMSPDATA  TSPI_MESSAGE_BASE+5
#define LINE_QOSINFO  TSPI_MESSAGE_BASE+6
#define LINETSPIOPTION_NONREENTRANT  0x00000001

#define TUISPIDLL_OBJECT_LINEID  1
#define TUISPIDLL_OBJECT_PHONEID  2
#define TUISPIDLL_OBJECT_PROVIDERID  3
#define TUISPIDLL_OBJECT_DIALOGINSTANCE  4

#define PRIVATEOBJECT_NONE  0x00000001
#define PRIVATEOBJECT_CALLID  0x00000002
#define PRIVATEOBJECT_LINE  0x00000003
#define PRIVATEOBJECT_CALL  0x00000004
#define PRIVATEOBJECT_PHONE  0x00000005
#define PRIVATEOBJECT_ADDRESS  0x00000006

#define LINEQOSREQUESTTYPE_SERVICELEVEL  0x00000001

#define LINEQOSSERVICELEVEL_NEEDED  0x00000001
#define LINEQOSSERVICELEVEL_IFAVAILABLE  0x00000002
#define LINEQOSSERVICELEVEL_BESTEFFORT  0x00000003

#define LINEEQOSINFO_NOQOS  0x00000001
#define LINEEQOSINFO_ADMISSIONFAILURE  0x00000002
#define LINEEQOSINFO_POLICYFAILURE  0x00000003
#define LINEEQOSINFO_GENERICERROR  0x00000004

#define TSPI_PROC_BASE  500

#define TSPI_LINEACCEPT  (TSPI_PROC_BASE+0)
#define TSPI_LINEADDTOCONFERENCE  (TSPI_PROC_BASE+1)
#define TSPI_LINEANSWER  (TSPI_PROC_BASE+2)
#define TSPI_LINEBLINDTRANSFER  (TSPI_PROC_BASE+3)
#define TSPI_LINECLOSE  (TSPI_PROC_BASE+4)
#define TSPI_LINECLOSECALL  (TSPI_PROC_BASE+5)
#define TSPI_LINECOMPLETECALL  (TSPI_PROC_BASE+6)
#define TSPI_LINECOMPLETETRANSFER  (TSPI_PROC_BASE+7)
#define TSPI_LINECONDITIONALMEDIADETECTION  (TSPI_PROC_BASE+8)
#define TSPI_LINECONFIGDIALOG  (TSPI_PROC_BASE+9)
#define TSPI_LINEDEVSPECIFIC  (TSPI_PROC_BASE+10)
#define TSPI_LINEDEVSPECIFICFEATURE  (TSPI_PROC_BASE+11)
#define TSPI_LINEDIAL  (TSPI_PROC_BASE+12)
#define TSPI_LINEDROP  (TSPI_PROC_BASE+13)
#define TSPI_LINEFORWARD  (TSPI_PROC_BASE+14)
#define TSPI_LINEGATHERDIGITS  (TSPI_PROC_BASE+15)
#define TSPI_LINEGENERATEDIGITS  (TSPI_PROC_BASE+16)
#define TSPI_LINEGENERATETONE  (TSPI_PROC_BASE+17)
#define TSPI_LINEGETADDRESSCAPS  (TSPI_PROC_BASE+18)
#define TSPI_LINEGETADDRESSID  (TSPI_PROC_BASE+19)
#define TSPI_LINEGETADDRESSSTATUS  (TSPI_PROC_BASE+20)
#define TSPI_LINEGETCALLADDRESSID  (TSPI_PROC_BASE+21)
#define TSPI_LINEGETCALLINFO  (TSPI_PROC_BASE+22)
#define TSPI_LINEGETCALLSTATUS  (TSPI_PROC_BASE+23)
#define TSPI_LINEGETDEVCAPS  (TSPI_PROC_BASE+24)
#define TSPI_LINEGETDEVCONFIG  (TSPI_PROC_BASE+25)
#define TSPI_LINEGETEXTENSIONID  (TSPI_PROC_BASE+26)
#define TSPI_LINEGETICON  (TSPI_PROC_BASE+27)
#define TSPI_LINEGETID  (TSPI_PROC_BASE+28)
#define TSPI_LINEGETLINEDEVSTATUS  (TSPI_PROC_BASE+29)
#define TSPI_LINEGETNUMADDRESSIDS  (TSPI_PROC_BASE+30)
#define TSPI_LINEHOLD  (TSPI_PROC_BASE+31)
#define TSPI_LINEMAKECALL  (TSPI_PROC_BASE+32)
#define TSPI_LINEMONITORDIGITS  (TSPI_PROC_BASE+33)
#define TSPI_LINEMONITORMEDIA  (TSPI_PROC_BASE+34)
#define TSPI_LINEMONITORTONES  (TSPI_PROC_BASE+35)
#define TSPI_LINENEGOTIATEEXTVERSION  (TSPI_PROC_BASE+36)
#define TSPI_LINENEGOTIATETSPIVERSION  (TSPI_PROC_BASE+37)
#define TSPI_LINEOPEN  (TSPI_PROC_BASE+38)
#define TSPI_LINEPARK  (TSPI_PROC_BASE+39)
#define TSPI_LINEPICKUP  (TSPI_PROC_BASE+40)
#define TSPI_LINEPREPAREADDTOCONFERENCE  (TSPI_PROC_BASE+41)
#define TSPI_LINEREDIRECT  (TSPI_PROC_BASE+42)
#define TSPI_LINEREMOVEFROMCONFERENCE  (TSPI_PROC_BASE+43)
#define TSPI_LINESECURECALL  (TSPI_PROC_BASE+44)
#define TSPI_LINESELECTEXTVERSION  (TSPI_PROC_BASE+45)
#define TSPI_LINESENDUSERUSERINFO  (TSPI_PROC_BASE+46)
#define TSPI_LINESETAPPSPECIFIC  (TSPI_PROC_BASE+47)
#define TSPI_LINESETCALLPARAMS  (TSPI_PROC_BASE+48)
#define TSPI_LINESETDEFAULTMEDIADETECTION  (TSPI_PROC_BASE+49)
#define TSPI_LINESETDEVCONFIG  (TSPI_PROC_BASE+50)
#define TSPI_LINESETMEDIACONTROL  (TSPI_PROC_BASE+51)
#define TSPI_LINESETMEDIAMODE  (TSPI_PROC_BASE+52)
#define TSPI_LINESETSTATUSMESSAGES  (TSPI_PROC_BASE+53)
#define TSPI_LINESETTERMINAL  (TSPI_PROC_BASE+54)
#define TSPI_LINESETUPCONFERENCE  (TSPI_PROC_BASE+55)
#define TSPI_LINESETUPTRANSFER  (TSPI_PROC_BASE+56)
#define TSPI_LINESWAPHOLD  (TSPI_PROC_BASE+57)
#define TSPI_LINEUNCOMPLETECALL  (TSPI_PROC_BASE+58)
#define TSPI_LINEUNHOLD  (TSPI_PROC_BASE+59)
#define TSPI_LINEUNPARK  (TSPI_PROC_BASE+60)
#define TSPI_PHONECLOSE  (TSPI_PROC_BASE+61)
#define TSPI_PHONECONFIGDIALOG  (TSPI_PROC_BASE+62)
#define TSPI_PHONEDEVSPECIFIC  (TSPI_PROC_BASE+63)
#define TSPI_PHONEGETBUTTONINFO  (TSPI_PROC_BASE+64)
#define TSPI_PHONEGETDATA  (TSPI_PROC_BASE+65)
#define TSPI_PHONEGETDEVCAPS  (TSPI_PROC_BASE+66)
#define TSPI_PHONEGETDISPLAY  (TSPI_PROC_BASE+67)
#define TSPI_PHONEGETEXTENSIONID  (TSPI_PROC_BASE+68)
#define TSPI_PHONEGETGAIN  (TSPI_PROC_BASE+69)
#define TSPI_PHONEGETHOOKSWITCH  (TSPI_PROC_BASE+70)
#define TSPI_PHONEGETICON  (TSPI_PROC_BASE+71)
#define TSPI_PHONEGETID  (TSPI_PROC_BASE+72)
#define TSPI_PHONEGETLAMP  (TSPI_PROC_BASE+73)
#define TSPI_PHONEGETRING  (TSPI_PROC_BASE+74)
#define TSPI_PHONEGETSTATUS  (TSPI_PROC_BASE+75)
#define TSPI_PHONEGETVOLUME  (TSPI_PROC_BASE+76)
#define TSPI_PHONENEGOTIATEEXTVERSION  (TSPI_PROC_BASE+77)
#define TSPI_PHONENEGOTIATETSPIVERSION  (TSPI_PROC_BASE+78)
#define TSPI_PHONEOPEN  (TSPI_PROC_BASE+79)
#define TSPI_PHONESELECTEXTVERSION  (TSPI_PROC_BASE+80)
#define TSPI_PHONESETBUTTONINFO  (TSPI_PROC_BASE+81)
#define TSPI_PHONESETDATA  (TSPI_PROC_BASE+82)
#define TSPI_PHONESETDISPLAY  (TSPI_PROC_BASE+83)
#define TSPI_PHONESETGAIN  (TSPI_PROC_BASE+84)
#define TSPI_PHONESETHOOKSWITCH  (TSPI_PROC_BASE+85)
#define TSPI_PHONESETLAMP  (TSPI_PROC_BASE+86)
#define TSPI_PHONESETRING  (TSPI_PROC_BASE+87)
#define TSPI_PHONESETSTATUSMESSAGES  (TSPI_PROC_BASE+88)
#define TSPI_PHONESETVOLUME  (TSPI_PROC_BASE+89)
#define TSPI_PROVIDERCONFIG  (TSPI_PROC_BASE+90)
#define TSPI_PROVIDERINIT  (TSPI_PROC_BASE+91)
#define TSPI_PROVIDERINSTALL  (TSPI_PROC_BASE+92)
#define TSPI_PROVIDERREMOVE  (TSPI_PROC_BASE+93)
#define TSPI_PROVIDERSHUTDOWN  (TSPI_PROC_BASE+94)
#define TSPI_PROVIDERENUMDEVICES  (TSPI_PROC_BASE+95)
#define TSPI_LINEDROPONCLOSE  (TSPI_PROC_BASE+96)
#define TSPI_LINEDROPNOOWNER  (TSPI_PROC_BASE+97)
#define TSPI_PROVIDERCREATELINEDEVICE  (TSPI_PROC_BASE+98)
#define TSPI_PROVIDERCREATEPHONEDEVICE  (TSPI_PROC_BASE+99)
#define TSPI_LINESETCURRENTLOCATION  (TSPI_PROC_BASE+100)
#define TSPI_LINECONFIGDIALOGEDIT  (TSPI_PROC_BASE+101)
#define TSPI_LINERELEASEUSERUSERINFO  (TSPI_PROC_BASE+102)
#define TSPI_LINEGETCALLID  (TSPI_PROC_BASE+103)
#define TSPI_LINEGETCALLHUBTRACKING  (TSPI_PROC_BASE+104)
#define TSPI_LINESETCALLHUBTRACKING  (TSPI_PROC_BASE+105)
#define TSPI_LINERECEIVEMSPDATA  (TSPI_PROC_BASE+106)
#define TSPI_LINEMSPIDENTIFY  (TSPI_PROC_BASE+107)
#define TSPI_LINECREATEMSPINSTANCE  (TSPI_PROC_BASE+108)
#define TSPI_LINECLOSEMSPINSTANCE  (TSPI_PROC_BASE+109)

#endif