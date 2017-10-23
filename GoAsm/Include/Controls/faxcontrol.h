// Generated .IDL file (by the OLE/COM Object Viewer)


#IFNDEF FAXCONTROL_H
#define FAXCONTROL_H

#IFDEF LINKFILES
	#dynamiclinkfile fxsocm.dll
#ENDIF

#define GUID_TLBID_FaxControl <0xE4DE3030,0x0142,0x4ACA,<0xBA,0x48,0x86,0x13,0xB5,0x6A,0x25,0x55>>
#define GUID_CLSID_FaxControl <0x98F63271,0x6C09,0x48B3,<0xA5,0x71,0x99,0x01,0x55,0x93,0x2D,0x0B>>
#define GUID_IID_IFaxControl <0x32B56515,0xD48B,0x4DD9,<0x87,0xAC,0x92,0x16,0xF6,0xBE,0xAA,0x6F>>

#define FAXCONTROL_PROGID "FaxControl.FaxControl"

#IFNDEF BASECOM_H
	#include "BaseCOM.h"
#ENDIF

IFaxControl STRUCT
	UNION
		struct
			QueryInterface		PTR
			AddRef				PTR
			Release				PTR
		ends
		IUnknown Unknown
	ENDUNION
	UNION
		struct
			GetTypeInfoCount PTR
			GetTypeInfo PTR
			GetIDsOfNames PTR
			Invoke PTR
		ends
		IDispatch Dispatch
	ENDUNION
	IsFaxServiceInstalled PTR
	FaxPrinterInstalled PTR
	FaxService PTR
	InstallLocalFaxPrinter PTR
ENDS

#ENDIF