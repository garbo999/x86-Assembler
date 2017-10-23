;=============================================================;
;         mapiguid.inc file for Easy Code visual IDE          ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;           Version 1.0.00 (created on March, 2008)           ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF MAPIGUID_INC
#Define MAPIGUID_INC

#Define GUID_IID_IMAPISession               <000020300H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPITable                 <000020301H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIAdviseSink            <000020302H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIControl               <00002031BH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IProfAdmin                 <00002031CH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMsgServiceAdmin           <00002031DH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IProviderAdmin             <000020325H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIProgress              <00002031FH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIProp                  <000020303H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IProfSect                  <000020304H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIStatus                <000020305H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMsgStore                  <000020306H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMessage                   <000020307H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IAttachment                <000020308H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IAddrBook                  <000020309H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMailUser                  <00002030AH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIContainer             <00002030BH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIFolder                <00002030CH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IABContainer               <00002030DH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IDistList                  <00002030EH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPISup                   <00002030FH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMSProvider                <000020310H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IABProvider                <000020311H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IXPProvider                <000020312H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMSLogon                   <000020313H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IABLogon                   <000020314H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IXPLogon                   <000020315H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPITableData             <000020316H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPISpoolerInit           <000020317H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPISpoolerSession        <000020318H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_ITNEF                      <000020319H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIPropData              <00002031AH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_ISpoolerHook               <000020320H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPISpoolerService        <00002031EH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIViewContext           <000020321H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIFormMgr               <000020322H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IEnumMAPIFormProp          <000020323H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIFormInfo              <000020324H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIForm                  <000020327H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_PS_MAPI                        <000020328H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_PS_PUBLIC_STRINGS              <000020329H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IPersistMessage            <00002032AH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIViewAdviseSink        <00002032BH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IStreamDocfile             <00002032CH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIFormProp              <00002032DH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIFormContainer         <00002032EH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIFormAdviseSink        <00002032FH, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IStreamTnef                <000020330H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIFormFactory           <000020350H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_IID_IMAPIMessageSite           <000020370H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_PS_ROUTING_EMAIL_ADDRESSES     <000020380H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_PS_ROUTING_ADDRTYPE            <000020381H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_PS_ROUTING_DISPLAY_NAME        <000020382H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_PS_ROUTING_ENTRYID             <000020383H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_PS_ROUTING_SEARCH_KEY          <000020384H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>
#Define GUID_MUID_PROFILE_INSTANCE          <000020385H, 00H, 00H, 0C0H, 00H, 00H, 00H, 00H, 00H, 00H, 046H>

#ENDIF ;MAPIGUID_INC
