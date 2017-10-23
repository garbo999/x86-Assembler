#ifndef SQLUCODE_H
#define SQLUCODE_H

/* ODBC Core functions Unicode definitions */

#IFNDEF SQLEXT_H
	#include "sqlext.h"
#ENDIF

#define SQL_WCHAR  -8
#define SQL_WVARCHAR  -9
#define SQL_WLONGVARCHAR  -10
#define SQL_C_WCHAR  SQL_WCHAR

#define SQL_SQLSTATE_SIZEW  10

#IFDEF UNICODE
	#define SQLColAttribute  SQLColAttributeW
	#define SQLColAttributes  SQLColAttributesW
	#define SQLConnect  SQLConnectW
	#define SQLDescribeCol  SQLDescribeColW
	#define SQLError  SQLErrorW
	#define SQLExecDirect  SQLExecDirectW
	#define SQLGetConnectAttr  SQLGetConnectAttrW
	#define SQLGetCursorName  SQLGetCursorNameW
	#define SQLGetDescField  SQLGetDescFieldW
	#define SQLGetDescRec  SQLGetDescRecW
	#define SQLGetDiagField  SQLGetDiagFieldW
	#define SQLGetDiagRec  SQLGetDiagRecW
	#define SQLPrepare  SQLPrepareW
	#define SQLSetConnectAttr  SQLSetConnectAttrW
	#define SQLSetCursorName  SQLSetCursorNameW
	#define SQLSetDescField  SQLSetDescFieldW
	#define SQLSetStmtAttr  SQLSetStmtAttrW
	#define SQLGetStmtAttr  SQLGetStmtAttrW
	#define SQLColumns  SQLColumnsW
	#define SQLGetConnectOption SQLGetConnectOptionW
	#define SQLGetInfo  SQLGetInfoW
	#define SQLGetTypeInfo  SQLGetTypeInfoW
	#define SQLSetConnectOption SQLSetConnectOptionW
	#define SQLSpecialColumns  SQLSpecialColumnsW
	#define SQLStatistics  SQLStatisticsW
	#define SQLTables  SQLTablesW
	#define SQLDataSources  SQLDataSourcesW
	#define SQLDriverConnect  SQLDriverConnectW
	#define SQLBrowseConnect  SQLBrowseConnectW
	#define SQLColumnPrivileges SQLColumnPrivilegesW
	#define SQLForeignKeys  SQLForeignKeysW
	#define SQLNativeSql  SQLNativeSqlW
	#define SQLPrimaryKeys  SQLPrimaryKeysW
	#define SQLProcedureColumns SQLProcedureColumnsW
	#define SQLProcedures  SQLProceduresW
	#define SQLTablePrivileges  SQLTablePrivilegesW
	#define SQLDrivers  SQLDriversW
#else
// These functions are available with or without the A suffix
#IFDEF SQL_USEANSI
	#define SQLColAttribute  SQLColAttributeA
	#define SQLColAttributes  SQLColAttributesA
	#define SQLConnect  SQLConnectA
	#define SQLDescribeCol  SQLDescribeColA
	#define SQLError  SQLErrorA
	#define SQLExecDirect  SQLExecDirectA
	#define SQLGetConnectAttr  SQLGetConnectAttrA
	#define SQLGetCursorName  SQLGetCursorNameA
	#define SQLGetDescField  SQLGetDescFieldA
	#define SQLGetDescRec  SQLGetDescRecA
	#define SQLGetDiagField  SQLGetDiagFieldA
	#define SQLGetDiagRec  SQLGetDiagRecA
	#define SQLPrepare  SQLPrepareA
	#define SQLSetConnectAttr  SQLSetConnectAttrA
	#define SQLSetCursorName  SQLSetCursorNameA
	#define SQLSetDescField  SQLSetDescFieldA
	#define SQLSetStmtAttr  SQLSetStmtAttrA
	#define SQLGetStmtAttr  SQLGetStmtAttrA
	#define SQLColumns  SQLColumnsA
	#define SQLGetConnectOption SQLGetConnectOptionA
	#define SQLGetInfo  SQLGetInfoA
	#define SQLGetTypeInfo  SQLGetTypeInfoA
	#define SQLSetConnectOption SQLSetConnectOptionA
	#define SQLSpecialColumns  SQLSpecialColumnsA
	#define SQLStatistics  SQLStatisticsA
	#define SQLTables  SQLTablesA
	#define SQLDataSources  SQLDataSourcesA
	#define SQLDriverConnect  SQLDriverConnectA
	#define SQLBrowseConnect  SQLBrowseConnectA
	#define SQLColumnPrivileges SQLColumnPrivilegesA
	#define SQLForeignKeys  SQLForeignKeysA
	#define SQLNativeSql  SQLNativeSqlA
	#define SQLPrimaryKeys  SQLPrimaryKeysA
	#define SQLProcedureColumns SQLProcedureColumnsA
	#define SQLProcedures  SQLProceduresA
	#define SQLTablePrivileges  SQLTablePrivilegesA
	#define SQLDrivers  SQLDriversA
#ENDIF
#endif /* UNICODE */

#endif /* SQLUCODE_H */
