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
	/*CString message;
	// The command mysql_real_connect is included in the libraries
	if (connection==NULL){
		// Adddebugcode here
		message.Format(_T("Unable to connect!"));
		AfxMessageBox(message);
	}
	else{
		message.Format(_T("Connection Successful"));
		AfxMessageBox(message);
	}*/
}
CString myconnectorclassDB::rate(CString rating, CString username, CString roomID)
{
	CString query = _T("CALL rateRoom('") + rating + _T("','") + username + _T(",") + roomID + _T("')");
	Query(query);
	row = mysql_fetch_row(result);
	CString value = CPtoUnicode(row[0], 1251);
	return value;
}

std::vector<CString> myconnectorclassDB::getRoomInfo(CString roomID)
{
	CString query = _T("CALL getRoomInfo('") + roomID + _T("')");

	Query(query);
	row = mysql_fetch_row(result);
	std::vector<CString> roomInfo;

	int line = 0;
	int ncolumns = 16;
	for (int i = 0; i < ncolumns; i++)
	{
		roomInfo.push_back(CPtoUnicode(row[i], 1251));
	}
	return roomInfo;
}

BOOL myconnectorclassDB::isAdmin(CString username)
{
	CString value;
	CString query = _T("CALL isAdmin('") + username + _T("')");
	Query(query);
	row = mysql_fetch_row(result);
	value = CPtoUnicode(row[0], 1251);
	BOOL aux = 0;
	if (value == '1'){
		aux = 1;
	}
	return aux;
}

CString myconnectorclassDB::addBuilding(CString build, CString lat, CString lng, CString buildtype, CString address)
{
	CString value;
	CString query = _T("CALL addBuilding('") + build + _T("','") + lat + _T("','") + lng + _T("','")
		+ buildtype + _T("','") + address+ _T("')");
	Query(query);
	row = mysql_fetch_row(result);
	value = CPtoUnicode(row[0], 1251);
	return value;
}

CString myconnectorclassDB::addStudyroom(CString Name, CString Building, CString chairs, CString plugs, CString floor,
	CString noise, CString bibl, CString open, CString close, CString oDay, CString cDay)
{
	CString value;
	CString query = _T("CALL addStudyroom('") + Name + _T("','") + Building + _T("','") + chairs + _T("','")
		+ plugs + _T("','") + floor + _T("','") + noise + _T("','") + bibl + _T("','") + open + _T("','") 
		+ close + _T("','") + oDay + _T("','") + cDay + _T("')");
	Query(query);
	row = mysql_fetch_row(result);
	value = CPtoUnicode(row[0], 1251);
	return value;
}


BOOL myconnectorclassDB::Login(CString username, CString password)
{
	CString value;
	CString query = _T("CALL login('") + username + _T("','") + password + _T("')");
	Query(query);
	row = mysql_fetch_row(result);
	value = CPtoUnicode(row[0], 1251);
	BOOL aux = 0;
	if (value == '1'){
		aux = 1;
	}
	return aux;
}

CString myconnectorclassDB::Register(CString regName, CString regEmail, CString regPass, CString regUser)
{
	BOOL aux = FALSE;
	CString value;
	CString query = _T("CALL register('") + regName + _T("','") + regEmail + _T("','") + regPass + _T("','")
		+ regUser + _T("')");
	Query(query);
	row = mysql_fetch_row(result);
	value = CPtoUnicode(row[0], 1251);
	return value;
}


std::vector<LVITEM> myconnectorclassDB::GetUsers(CString adminCode)
{
	CString query = _T("CALL getUsers(")+adminCode+(")");
	std::vector<LVITEM> admin_search_results;
	Query(query);

	int line = 0;
	int value_index = 0;
	while ((row = mysql_fetch_row(result)) != NULL)
	{
		int column[] = { 0, 1, 2 }; // column selection
		int ncolumns = 3;
		for (int i = 0; i < ncolumns; i++)
		{
			admin_query_disp_value[value_index] = CPtoUnicode(row[column[i]], 1251);
			// Use the LV_ITEM structure to insert the items
			LVITEM lvi;
			// Insert the first item
			lvi.mask = LVIF_TEXT;
			lvi.iItem = line; // line where this result will be displayed
			lvi.iSubItem = i; // column where this result will be displayed
			int length = 1024;
			LPWSTR pwsz = admin_query_disp_value[value_index].GetBuffer(length);
			// do something with the string that pwsz points to.
			lvi.pszText = pwsz;
			admin_query_disp_value[value_index].ReleaseBuffer();

			admin_search_results.push_back(lvi); // insert new structure in the vector
			value_index++;
		}
		line++;
	}

	return admin_search_results;
}



std::vector<LVITEM> myconnectorclassDB::Search(CString sentence)/////// MAIN SEARCH FUNCTION
{
	CString query = _T("CALL search(")+sentence+_T(")");
	std::vector<LVITEM> search_results;
	Query(query);

	int line = 0;
	int value_index = 0;
	if (result != NULL){
		while ((row = mysql_fetch_row(result)) != NULL)
		{
			int column[] = { 3, 2, 0 }; // column selection
			int ncolumns = 3; // number of columns to use
			for (int i = 0; i < ncolumns; i++)
			{
				query_disp_value[value_index] = CPtoUnicode(row[column[i]], 1251);
				// Use the LV_ITEM structure to insert the items
				LVITEM lvi;
				// Insert the first item
				lvi.mask = LVIF_TEXT;
				lvi.iItem = line; // line where this result will be displayed
				lvi.iSubItem = i; // column where this result will be displayed
				int length = 1024;
				LPWSTR pwsz = query_disp_value[value_index].GetBuffer(length);
				// do something with the string that pwsz points to.
				lvi.pszText = pwsz;
				query_disp_value[value_index].ReleaseBuffer();

				search_results.push_back(lvi); // insert new structure in the vector
				value_index++;
			}
			line++;
		}
	}
	return search_results;
}

BOOL myconnectorclassDB::deleteUser(CString useID)/////// DELETE USER FUNCTION ADMIN
{
	CString query = _T("CALL deleteUser('") + useID + _T("')");
	Query(query);
	row = mysql_fetch_row(result);
	CString value = CPtoUnicode(row[0], 1251);
	BOOL aux=0;
	if (value == '1'){
		aux = 1;
	}
	return aux;
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