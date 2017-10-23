;=============================================================;
;          adsnms.inc file for Easy Code visual IDE           ;
;            (made for the GoAsm compiler version)            ;
;                                                             ;
;         Version 1.0.00 (created on February, 2007)          ;
;                                                             ;
;      Please report any bug you find (asm@easycode.cat)      ;
;                                                             ;
;                Do not modify this file!!                    ;
;=============================================================;

#IFNDEF ADSNMS_INC
#Define ADSNMS_INC

#IF STRINGS UNICODE
	#Define NAMESPACE_CLASS_NAME    		L"Namespace"
	#Define COUNTRY_CLASS_NAME      		L"Country"
	#Define LOCALITY_CLASS_NAME     		L"Locality"
	#Define ORGANIZATION_CLASS_NAME 		L"Organization"
	#Define ORGANIZATIONUNIT_CLASS_NAME		L"Organizational Unit"
	#Define DOMAIN_CLASS_NAME       		L"Domain"
	#Define COMPUTER_CLASS_NAME     		L"Computer"
	#Define USER_CLASS_NAME         		L"User"
	#Define GROUP_CLASS_NAME        		L"Group"
	#Define SERVICE_CLASS_NAME      		L"Service"
	#Define FILESERVICE_CLASS_NAME  		L"FileService"
	#Define SESSION_CLASS_NAME      		L"Session"
	#Define RESOURCE_CLASS_NAME     		L"Resource"
	#Define FILESHARE_CLASS_NAME    		L"FileShare"
	#Define PRINTER_CLASS_NAME      		L"PrintQueue"
	#Define PRINTJOB_CLASS_NAME     		L"PrintJob"
	#Define SCHEMA_CLASS_NAME       		L"Schema"
	#Define CLASS_CLASS_NAME        		L"Class"
	#Define PROPERTY_CLASS_NAME     		L"Property"
	#Define SYNTAX_CLASS_NAME       		L"Syntax"
	#Define ROOTDSE_CLASS_NAME      		L"RootDSE"

	#Define NO_SCHEMA               		L""
	#Define DOMAIN_SCHEMA_NAME      		L"Domain"
	#Define COMPUTER_SCHEMA_NAME    		L"Computer"
	#Define USER_SCHEMA_NAME        		L"User"
	#Define GROUP_SCHEMA_NAME       		L"Group"
	#Define SERVICE_SCHEMA_NAME     		L"Service"
	#Define PRINTER_SCHEMA_NAME     		L"PrintQueue"
	#Define PRINTJOB_SCHEMA_NAME    		L"PrintJob"
	#Define FILESERVICE_SCHEMA_NAME 		L"FileService"
	#Define SESSION_SCHEMA_NAME     		L"Session"
	#Define RESOURCE_SCHEMA_NAME    		L"Resource"
	#Define FILESHARE_SCHEMA_NAME   		L"FileShare"
	#Define FPNW_FILESERVICE_SCHEMA_NAME	L"FPNWFileService"
	#Define FPNW_SESSION_SCHEMA_NAME    	L"FPNWSession"
	#Define FPNW_RESOURCE_SCHEMA_NAME   	L"FPNWResource"
	#Define FPNW_FILESHARE_SCHEMA_NAME		L"FPNWFileShare"
#ELSE
	#Define NAMESPACE_CLASS_NAME    		"Namespace"
	#Define COUNTRY_CLASS_NAME      		"Country"
	#Define LOCALITY_CLASS_NAME     		"Locality"
	#Define ORGANIZATION_CLASS_NAME 		"Organization"
	#Define ORGANIZATIONUNIT_CLASS_NAME		"Organizational Unit"
	#Define DOMAIN_CLASS_NAME       		"Domain"
	#Define COMPUTER_CLASS_NAME     		"Computer"
	#Define USER_CLASS_NAME         		"User"
	#Define GROUP_CLASS_NAME        		"Group"
	#Define SERVICE_CLASS_NAME      		"Service"
	#Define FILESERVICE_CLASS_NAME  		"FileService"
	#Define SESSION_CLASS_NAME      		"Session"
	#Define RESOURCE_CLASS_NAME     		"Resource"
	#Define FILESHARE_CLASS_NAME    		"FileShare"
	#Define PRINTER_CLASS_NAME      		"PrintQueue"
	#Define PRINTJOB_CLASS_NAME     		"PrintJob"
	#Define SCHEMA_CLASS_NAME       		"Schema"
	#Define CLASS_CLASS_NAME        		"Class"
	#Define PROPERTY_CLASS_NAME     		"Property"
	#Define SYNTAX_CLASS_NAME       		"Syntax"
	#Define ROOTDSE_CLASS_NAME      		"RootDSE"

	#Define NO_SCHEMA               		""
	#Define DOMAIN_SCHEMA_NAME      		"Domain"
	#Define COMPUTER_SCHEMA_NAME    		"Computer"
	#Define USER_SCHEMA_NAME        		"User"
	#Define GROUP_SCHEMA_NAME       		"Group"
	#Define SERVICE_SCHEMA_NAME     		"Service"
	#Define PRINTER_SCHEMA_NAME     		"PrintQueue"
	#Define PRINTJOB_SCHEMA_NAME    		"PrintJob"
	#Define FILESERVICE_SCHEMA_NAME 		"FileService"
	#Define SESSION_SCHEMA_NAME     		"Session"
	#Define RESOURCE_SCHEMA_NAME    		"Resource"
	#Define FILESHARE_SCHEMA_NAME   		"FileShare"
	#Define FPNW_FILESERVICE_SCHEMA_NAME	"FPNWFileService"
	#Define FPNW_SESSION_SCHEMA_NAME    	"FPNWSession"
	#Define FPNW_RESOURCE_SCHEMA_NAME   	"FPNWResource"
	#Define FPNW_FILESHARE_SCHEMA_NAME		"FPNWFileShare"
#ENDIF

#ENDIF ;ADSNMS_INC
