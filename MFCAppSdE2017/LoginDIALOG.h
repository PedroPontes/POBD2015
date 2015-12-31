#pragma once
#include "myconnectorclassDB.h"

// CLoginDIALOG dialog

class CLoginDIALOG : public CDialog
{
	DECLARE_DYNAMIC(CLoginDIALOG)

public:
	CLoginDIALOG(CWnd* pParent = NULL);   // standard constructor
	virtual ~CLoginDIALOG();

// Dialog Data
	enum { IDD = IDD_LoginDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEditusername();
	afx_msg void OnEnChangeEditpassword();
	CString username;
	CString password;
	CString GetUser();
	BOOL GetLoginState();
	afx_msg void OnBnClickedLoginbutt();
	BOOL aux;
	afx_msg void OnEnChangeLoginmessage();
	CString msgLogin;
	
	afx_msg void OnBnClickedRegisterbutton();
};
