#pragma once
#include"my_global.h" // The included headers we need
#include"mysql.h"
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
	CString Search(CString qlib);
	myconnectorclassDB(void);

	virtual ~myconnectorclassDB(void);
};