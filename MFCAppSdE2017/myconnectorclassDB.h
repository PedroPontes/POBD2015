#pragma once
#include"my_global.h" // The included headers we need
#include"mysql.h"
#include <vector>

class myconnectorclassDB
{
private:
#define SERVER "db.ist.utl.pt"
#define USER "ist172814" // Your IST number
#define PASSWORD "izyc7668" // NOT IST password
#define DATABASE "ist172814" // Your IST number
	void Query(CString query); // Main query function
	MYSQL *connection; // Pointerallocationfor a connection.
	// This is an object creation of an existing class in
	// The mySQLlibraries we added.
public:
	MYSQL_ROW row; // Another object based on the existing
	// library, this one stores a single row from queries
	MYSQL_RES *result; // and this one the entire result
	// from a query
	void connect(); // Connection function. Notice how
	// this is public, but the connection itself is
	// private.
	CString CPtoUnicode(const char* CPString, UINT CodePage);
	// Converts data from MySQL format to MFC's CString.
	// My Queries
	std::vector<LVITEM> Search(CString sentence);
	std::vector<LVITEM> GetUsers(CString adminCode);
	BOOL Login(CString username, CString password);
	myconnectorclassDB(void);
	CString Register(CString regName, CString regEmail, CString regPass, CString regUser);
	virtual ~myconnectorclassDB(void);
	BOOL deleteUser(CString useID);
	CString addBuilding(CString build, CString lat, CString lng, CString buildtype, CString address);
	CString addStudyroom(CString Name, CString Building, CString chairs, CString plugs, CString floor, CString noise,
		CString bibl, CString open, CString close, CString oDay, CString cDay);
	CString query_disp_value[100]; // value initialization - no more than 100 results should be returned!
	CString admin_query_disp_value[100]; // value initialization - no more than 100 results should be returned!
	BOOL isAdmin(CString username);
	std::vector<CString> getRoomInfo(CString roomID);
	CString rate(CString rating, CString username, CString roomID)
};