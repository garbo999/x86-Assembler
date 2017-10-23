;=============================================================;
;           dlgs.inc file for Easy Code visual IDE            ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF DLGS_INC
#Define DLGS_INC

#Define ctlFirst    					00400H
#Define ctlLast     					004FFH

#Define psh1        					00400H
#Define psh2        					00401H
#Define psh3        					00402H
#Define psh4        					00403H
#Define psh5        					00404H
#Define psh6        					00405H
#Define psh7        					00406H
#Define psh8        					00407H
#Define psh9        					00408H
#Define psh10       					00409H
#Define psh11       					0040AH
#Define psh12       					0040BH
#Define psh13       					0040CH
#Define psh14       					0040DH
#Define psh15       					0040EH
#Define pshHelp     					psh15
#Define psh16       					0040FH

#Define chx1        					00410H
#Define chx2        					00411H
#Define chx3        					00412H
#Define chx4        					00413H
#Define chx5        					00414H
#Define chx6        					00415H
#Define chx7        					00416H
#Define chx8        					00417H
#Define chx9        					00418H
#Define chx10       					00419H
#Define chx11       					0041AH
#Define chx12       					0041BH
#Define chx13       					0041CH
#Define chx14       					0041DH
#Define chx15       					0041EH
#Define chx16       					0041FH

#Define rad1        					00420H
#Define rad2        					00421H
#Define rad3        					00422H
#Define rad4        					00423H
#Define rad5        					00424H
#Define rad6        					00425H
#Define rad7        					00426H
#Define rad8        					00427H
#Define rad9        					00428H
#Define rad10       					00429H
#Define rad11       					0042AH
#Define rad12       					0042BH
#Define rad13       					0042CH
#Define rad14       					0042DH
#Define rad15       					0042EH
#Define rad16       					0042FH

#Define grp1        					00430H
#Define grp2        					00431H
#Define grp3        					00432H
#Define grp4        					00433H
#Define frm1        					00434H
#Define frm2        					00435H
#Define frm3        					00436H
#Define frm4        					00437H
#Define rct1        					00438H
#Define rct2        					00439H
#Define rct3        					0043AH
#Define rct4        					0043BH
#Define ico1        					0043CH
#Define ico2        					0043DH
#Define ico3        					0043EH
#Define ico4        					0043FH

#Define stc1        					00440H
#Define stc2        					00441H
#Define stc3        					00442H
#Define stc4        					00443H
#Define stc5        					00444H
#Define stc6        					00445H
#Define stc7        					00446H
#Define stc8        					00447H
#Define stc9        					00448H
#Define stc10       					00449H
#Define stc11       					0044AH
#Define stc12       					0044BH
#Define stc13       					0044CH
#Define stc14       					0044DH
#Define stc15       					0044EH
#Define stc16       					0044FH
#Define stc17       					00450H
#Define stc18       					00451H
#Define stc19       					00452H
#Define stc20       					00453H
#Define stc21       					00454H
#Define stc22       					00455H
#Define stc23       					00456H
#Define stc24       					00457H
#Define stc25       					00458H
#Define stc26       					00459H
#Define stc27       					0045AH
#Define stc28       					0045BH
#Define stc29       					0045CH
#Define stc30       					0045DH
#Define stc31       					0045EH
#Define stc32       					0045FH

#Define lst1        					00460H
#Define lst2        					00461H
#Define lst3        					00462H
#Define lst4        					00463H
#Define lst5        					00464H
#Define lst6        					00465H
#Define lst7        					00466H
#Define lst8        					00467H
#Define lst9        					00468H
#Define lst10       					00469H
#Define lst11       					0046AH
#Define lst12       					0046BH
#Define lst13       					0046CH
#Define lst14       					0046DH
#Define lst15       					0046EH
#Define lst16       					0046FH

#Define cmb1        					00470H
#Define cmb2        					00471H
#Define cmb3        					00472H
#Define cmb4        					00473H
#Define cmb5        					00474H
#Define cmb6        					00475H
#Define cmb7        					00476H
#Define cmb8        					00477H
#Define cmb9        					00478H
#Define cmb10       					00479H
#Define cmb11       					0047AH
#Define cmb12       					0047BH
#Define cmb13       					0047CH
#Define cmb14       					0047DH
#Define cmb15       					0047EH
#Define cmb16       					0047FH

#Define edt1        					00480H
#Define edt2        					00481H
#Define edt3        					00482H
#Define edt4        					00483H
#Define edt5        					00484H
#Define edt6        					00485H
#Define edt7        					00486H
#Define edt8        					00487H
#Define edt9        					00488H
#Define edt10       					00489H
#Define edt11       					0048AH
#Define edt12       					0048BH
#Define edt13       					0048CH
#Define edt14       					0048DH
#Define edt15       					0048EH
#Define edt16       					0048FH

#Define scr1        					00490H
#Define scr2        					00491H
#Define scr3        					00492H
#Define scr4        					00493H
#Define scr5        					00494H
#Define scr6        					00495H
#Define scr7        					00496H
#Define scr8        					00497H

#Define FILEOPENORD      				1536
#Define MULTIFILEOPENORD 				1537
#Define PRINTDLGORD      				1538
#Define PRNSETUPDLGORD   				1539
#Define FINDDLGORD       				1540
#Define REPLACEDLGORD    				1541
#Define FONTDLGORD       				1542
#Define FORMATDLGORD31   				1543
#Define FORMATDLGORD30   				1544
#Define RUNDLGORD        				1545

#Define PAGESETUPDLGORD  				1546
#Define NEWFILEOPENORD   				1547
#Define NEWOBJECTOPENORD 				1548


CRGB Struct
	bRed DB
	bGreen DB
	bBlue DB
	bExtra DB
EndS

#ENDIF ;DLGS_INC
