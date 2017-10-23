;=============================================================;
;            mcx.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF MCX_INC
#Define MCX_INC

#Define DIALOPTION_BILLING  	000000040H
#Define DIALOPTION_QUIET    	000000080H
#Define DIALOPTION_DIALTONE 	000000100H

#Define MDMVOLFLAG_LOW      	000000001H
#Define MDMVOLFLAG_MEDIUM   	000000002H
#Define MDMVOLFLAG_HIGH     	000000004H

#Define MDMVOL_LOW          	000000000H
#Define MDMVOL_MEDIUM       	000000001H
#Define MDMVOL_HIGH         	000000002H

#Define MDMSPKRFLAG_OFF         000000001H
#Define MDMSPKRFLAG_DIAL        000000002H
#Define MDMSPKRFLAG_ON          000000004H
#Define MDMSPKRFLAG_CALLSETUP   000000008H

#Define MDMSPKR_OFF         	000000000H
#Define MDMSPKR_DIAL        	000000001H
#Define MDMSPKR_ON          	000000002H
#Define MDMSPKR_CALLSETUP   	000000003H

#Define MDM_COMPRESSION      	000000001H
#Define MDM_ERROR_CONTROL    	000000002H
#Define MDM_FORCED_EC        	000000004H
#Define MDM_CELLULAR         	000000008H
#Define MDM_FLOWCONTROL_HARD 	000000010H
#Define MDM_FLOWCONTROL_SOFT 	000000020H
#Define MDM_CCITT_OVERRIDE   	000000040H
#Define MDM_SPEED_ADJUST     	000000080H
#Define MDM_TONE_DIAL        	000000100H
#Define MDM_BLIND_DIAL       	000000200H
#Define MDM_V23_OVERRIDE     	000000400H


MODEMDEVCAPS Struct
	dwActualSize DD
	dwRequiredSize DD
	dwDevSpecificOffset DD
	dwDevSpecificSize DD
	dwModemProviderVersion DD
	dwModemManufacturerOffset DD
	dwModemManufacturerSize DD
	dwModemModelOffset DD
	dwModemModelSize DD
	dwModemVersionOffset DD
	dwModemVersionSize DD
	dwDialOptions DD
	dwCallSetupFailTimer DD
	dwInactivityTimeout DD
	dwSpeakerVolume DD
	dwSpeakerMode DD
	dwModemOptions DD
	dwMaxDTERate DD
	dwMaxDCERate DD
	abVariablePortion DB
EndS

MODEMSETTINGS Struct
	dwActualSize DD
	dwRequiredSize DD
	dwDevSpecificOffset DD
	dwDevSpecificSize DD
	dwCallSetupFailTimer DD
	dwInactivityTimeout DD
	dwSpeakerVolume DD
	dwSpeakerMode DD
	dwPreferredModemOptions DD
	dwNegotiatedModemOptions DD
	dwNegotiatedDCERate DD
	abVariablePortion DB
EndS

#ENDIF ;MCX_INC
