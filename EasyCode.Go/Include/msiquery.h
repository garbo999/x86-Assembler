#ifndef MSIQUERY_H
#define MSIQUERY_H

/* Installer Service custom actions and tools definitions */

#IFNDEF MSI_H
	#include "msi.h"
#ENDIF

#define MSI_NULL_INTEGER  0x80000000

#define MSIDBOPEN_READONLY  0
#define MSIDBOPEN_TRANSACT  1
#define MSIDBOPEN_DIRECT  2
#define MSIDBOPEN_CREATE  3
#define MSIDBOPEN_CREATEDIRECT 4

#define INSTALLMESSAGE_TYPEMASK = 0xFF000000

MSIDBSTATE_ERROR = -1
MSIDBSTATE_READ = 0
MSIDBSTATE_WRITE = 1

MSIMODIFY_SEEK = -1
MSIMODIFY_REFRESH = 0
MSIMODIFY_INSERT = 1
MSIMODIFY_UPDATE = 2
MSIMODIFY_ASSIGN = 3
MSIMODIFY_REPLACE = 4
MSIMODIFY_MERGE = 5
MSIMODIFY_DELETE = 6
MSIMODIFY_INSERT_TEMPORARY = 7
MSIMODIFY_VALIDATE = 8
MSIMODIFY_VALIDATE_NEW = 9
MSIMODIFY_VALIDATE_FIELD = 10
MSIMODIFY_VALIDATE_DELETE = 11

MSICOLINFO_NAMES = 0
MSICOLINFO_TYPES = 1

MSICONDITION_FALSE = 0
MSICONDITION_TRUE = 1
MSICONDITION_NONE = 2
MSICONDITION_ERROR = 3

MSICOSTTREE_SELFONLY = 0
MSICOSTTREE_CHILDREN = 1
MSICOSTTREE_PARENTS = 2
MSICOSTTREE_RESERVED = 3

MSIDBERROR_INVALIDARG = -3
MSIDBERROR_MOREDATA = -2
MSIDBERROR_FUNCTIONERROR = -1
MSIDBERROR_NOERROR = 0
MSIDBERROR_DUPLICATEKEY = 1
MSIDBERROR_REQUIRED = 2
MSIDBERROR_BADLINK = 3
MSIDBERROR_OVERFLOW = 4
MSIDBERROR_UNDERFLOW = 5
MSIDBERROR_NOTINSET = 6
MSIDBERROR_BADVERSION = 7
MSIDBERROR_BADCASE = 8
MSIDBERROR_BADGUID = 9
MSIDBERROR_BADWILDCARD = 10
MSIDBERROR_BADIDENTIFIER = 11
MSIDBERROR_BADLANGUAGE = 12
MSIDBERROR_BADFILENAME = 13
MSIDBERROR_BADPATH = 14
MSIDBERROR_BADCONDITION = 15
MSIDBERROR_BADFORMATTED = 16
MSIDBERROR_BADTEMPLATE = 17
MSIDBERROR_BADDEFAULTDIR = 18
MSIDBERROR_BADREGPATH = 19
MSIDBERROR_BADCUSTOMSOURCE = 20
MSIDBERROR_BADPROPERTY = 21
MSIDBERROR_MISSINGDATA = 22
MSIDBERROR_BADCATEGORY = 23
MSIDBERROR_BADKEYTABLE = 24
MSIDBERROR_BADMAXMINVALUES = 25
MSIDBERROR_BADCABINET = 26
MSIDBERROR_BADSHORTCUT = 27
MSIDBERROR_STRINGOVERFLOW = 28
MSIDBERROR_BADLOCALIZEATTRIB = 29

MSIRUNMODE_ADMIN = 0
MSIRUNMODE_ADVERTISE = 1
MSIRUNMODE_MAINTENANCE = 2
MSIRUNMODE_ROLLBACKENABLED = 3
MSIRUNMODE_LOGENABLED = 4
MSIRUNMODE_OPERATIONS = 5
MSIRUNMODE_REBOOTATEND = 6
MSIRUNMODE_REBOOTNOW = 7
MSIRUNMODE_CABINET = 8
MSIRUNMODE_SOURCESHORTNAMES = 9
MSIRUNMODE_TARGETSHORTNAMES = 10
MSIRUNMODE_RESERVED11 = 11
MSIRUNMODE_WINDOWS9X = 12
MSIRUNMODE_ZAWENABLED = 13
MSIRUNMODE_RESERVED14 = 14
MSIRUNMODE_RESERVED15 = 15
MSIRUNMODE_SCHEDULED = 16
MSIRUNMODE_ROLLBACK = 17
MSIRUNMODE_COMMIT = 18

MSITRANSFORM_ERROR_ADDEXISTINGROW = 0x00000001
MSITRANSFORM_ERROR_DELMISSINGROW = 0x00000002
MSITRANSFORM_ERROR_ADDEXISTINGTABLE = 0x00000004
MSITRANSFORM_ERROR_DELMISSINGTABLE = 0x00000008
MSITRANSFORM_ERROR_UPDATEMISSINGROW = 0x00000010
MSITRANSFORM_ERROR_CHANGECODEPAGE = 0x00000020
MSITRANSFORM_ERROR_VIEWTRANSFORM = 0x00000100

MSITRANSFORM_VALIDATE_LANGUAGE = 0x00000001
MSITRANSFORM_VALIDATE_PRODUCT = 0x00000002
MSITRANSFORM_VALIDATE_PLATFORM = 0x00000004
MSITRANSFORM_VALIDATE_MAJORVERSION = 0x00000008
MSITRANSFORM_VALIDATE_MINORVERSION = 0x00000010
MSITRANSFORM_VALIDATE_UPDATEVERSION = 0x00000020
MSITRANSFORM_VALIDATE_NEWLESSBASEVERSION = 0x00000040
MSITRANSFORM_VALIDATE_NEWLESSEQUALBASEVERSION = 0x00000080
MSITRANSFORM_VALIDATE_NEWEQUALBASEVERSION = 0x00000100
MSITRANSFORM_VALIDATE_NEWGREATEREQUALBASEVERSION = 0x00000200
MSITRANSFORM_VALIDATE_NEWGREATERBASEVERSION = 0x00000400
MSITRANSFORM_VALIDATE_UPGRADECODE = 0x00000800

#IFDEF UNICODE
	#define MsiDatabaseOpenView  MsiDatabaseOpenViewW
	#define MsiViewGetError  MsiViewGetErrorW
	#define MsiDatabaseGetPrimaryKeys  MsiDatabaseGetPrimaryKeysW
	#define MsiDatabaseIsTablePersistent  MsiDatabaseIsTablePersistentW
	#define MsiGetSummaryInformation  MsiGetSummaryInformationW
	#define MsiSummaryInfoSetProperty  MsiSummaryInfoSetPropertyW
	#define MsiSummaryInfoGetProperty  MsiSummaryInfoGetPropertyW
	#define MsiOpenDatabase  MsiOpenDatabaseW
	#define MsiDatabaseImport  MsiDatabaseImportW
	#define MsiDatabaseExport  MsiDatabaseExportW
	#define MsiDatabaseMerge  MsiDatabaseMergeW
	#define MsiDatabaseGenerateTransform  MsiDatabaseGenerateTransformW
	#define MsiDatabaseApplyTransform  MsiDatabaseApplyTransformW
	#define MsiCreateTransformSummaryInfo  MsiCreateTransformSummaryInfoW
	#define MsiRecordSetString  MsiRecordSetStringW
	#define MsiRecordGetString  MsiRecordGetStringW
	#define MsiRecordSetStream  MsiRecordSetStreamW
	#define MsiSetProperty  MsiSetPropertyW
	#define MsiGetProperty  MsiGetPropertyW
	#define MsiFormatRecord  MsiFormatRecordW
	#define MsiDoAction  MsiDoActionW
	#define MsiSequence  MsiSequenceW
	#define MsiEvaluateCondition  MsiEvaluateConditionW
	#define MsiGetFeatureState  MsiGetFeatureStateW
	#define MsiSetFeatureState  MsiSetFeatureStateW
	#define MsiSetFeatureAttributes  MsiSetFeatureAttributesW
	#define MsiGetComponentState  MsiGetComponentStateW
	#define MsiSetComponentState  MsiSetComponentStateW
	#define MsiGetFeatureCost  MsiGetFeatureCostW
	#define MsiGetFeatureValidStates  MsiGetFeatureValidStatesW
	#define MsiGetSourcePath  MsiGetSourcePathW
	#define MsiGetTargetPath  MsiGetTargetPathW
	#define MsiSetTargetPath  MsiSetTargetPathW
	#define MsiPreviewDialog  MsiPreviewDialogW
	#define MsiPreviewBillboard  MsiPreviewBillboardW
#else
	#define MsiDatabaseOpenView  MsiDatabaseOpenViewA
	#define MsiViewGetError  MsiViewGetErrorA
	#define MsiDatabaseGetPrimaryKeys  MsiDatabaseGetPrimaryKeysA
	#define MsiDatabaseIsTablePersistent  MsiDatabaseIsTablePersistentA
	#define MsiGetSummaryInformation  MsiGetSummaryInformationA
	#define MsiSummaryInfoSetProperty  MsiSummaryInfoSetPropertyA
	#define MsiSummaryInfoGetProperty  MsiSummaryInfoGetPropertyA
	#define MsiOpenDatabase  MsiOpenDatabaseA
	#define MsiDatabaseImport  MsiDatabaseImportA
	#define MsiDatabaseExport  MsiDatabaseExportA
	#define MsiDatabaseMerge  MsiDatabaseMergeA
	#define MsiDatabaseGenerateTransform  MsiDatabaseGenerateTransformA
	#define MsiDatabaseApplyTransform  MsiDatabaseApplyTransformA
	#define MsiCreateTransformSummaryInfo  MsiCreateTransformSummaryInfoA
	#define MsiRecordSetString  MsiRecordSetStringA
	#define MsiRecordGetString  MsiRecordGetStringA
	#define MsiRecordSetStream  MsiRecordSetStreamA
	#define MsiSetProperty  MsiSetPropertyA
	#define MsiGetProperty  MsiGetPropertyA
	#define MsiFormatRecord  MsiFormatRecordA
	#define MsiDoAction  MsiDoActionA
	#define MsiSequence  MsiSequenceA
	#define MsiEvaluateCondition  MsiEvaluateConditionA
	#define MsiGetFeatureState  MsiGetFeatureStateA
	#define MsiSetFeatureState  MsiSetFeatureStateA
	#define MsiSetFeatureAttributes  MsiSetFeatureAttributesA
	#define MsiGetComponentState  MsiGetComponentStateA
	#define MsiSetComponentState  MsiSetComponentStateA
	#define MsiGetFeatureCost  MsiGetFeatureCostA
	#define MsiGetFeatureValidStates  MsiGetFeatureValidStatesA
	#define MsiGetSourcePath  MsiGetSourcePathA
	#define MsiGetTargetPath  MsiGetTargetPathA
	#define MsiSetTargetPath  MsiSetTargetPathA
	#define MsiPreviewDialog  MsiPreviewDialogA
	#define MsiPreviewBillboard  MsiPreviewBillboardA
#endif /* UNICODE */

#endif /* _MSIQUERY_H */
