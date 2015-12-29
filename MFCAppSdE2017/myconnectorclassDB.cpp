#include "stdafx.h"
#include "myconnectorclassDB.h"


myconnectorclassDB::myconnectorclassDB()
{
}


myconnectorclassDB::~myconnectorclassDB()
{
}

void myconnectorclassDB::connect()
{
	connection = mysql_init(NULL); // Initialise the instance
	connection = mysql_real_connect(connection, SERVER, USER,
		PASSWORD, DATABASE, 0, NULL, 0);
	CString message;
	// The command mysql_real_connect is included in the libraries
	if (connection==NULL){
		// Adddebugcode here
		message.Format(_T("Unable to connect!"));
		AfxMessageBox(message);
	}
	else{
		message.Format(_T("Connection Successful"));
		AfxMessageBox(message);
	}
}

CString myconnectorclassDB::Search(CString sentence)
{
	CString value ;
	CString query = _T("CALL search(")+sentence+_T(")");

	Query(query);
	/*while ((row = mysql_fetch_row(result)) != NULL)
	{
		value = CPtoUnicode(row[0], 1251);
	}*/
	row = mysql_fetch_row(result);
	value = CPtoUnicode(row[0], 1251);
	return value;
}
void myconnectorclassDB::Query(CString query)
{
	wchar_t *p = query.GetBuffer();
	char bufUTF8[MAX_PATH];
	WideCharToMultiByte(CP_UTF8, 0, p, -1, bufUTF8, sizeof(bufUTF8), NULL, NULL);
	/* MySQL uses a different character set from MFC's in VS.
	A weird conversion has to be done. the good news is
	you only have to copy and paste this code once. */
	mysql_query(connection, bufUTF8); // Send a query
	result = mysql_store_result(connection); // Store the result
}

CString myconnectorclassDB::CPtoUnicode(const char* CPString, UINT CodePage)
{
	CString retValue;
	int len = MultiByteToWideChar(CodePage, 0, CPString, -1, NULL, 0);
	if (len == 0) { return retValue; }
	LPWSTR buffer = retValue.GetBuffer(len);
	MultiByteToWideChar(CodePage, 0, CPString, -1, buffer, len);
	retValue.ReleaseBuffer();
	return retValue;
}