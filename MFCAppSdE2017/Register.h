#pragma once


// CRegister dialog

class CRegister : public CDialog
{
	DECLARE_DYNAMIC(CRegister)

public:
	CRegister(CWnd* pParent = NULL);   // standard constructor
	virtual ~CRegister();

// Dialog Data
	enum { IDD = IDD_RegisterDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRegisterbutt();
	afx_msg void OnEnChangeEditusername();
	afx_msg void OnEnChangeEditfullname();
	afx_msg void OnEnChangeEditemail();
	afx_msg void OnEnChangeEditpassword();
	CString regUser;
	CString regName;
	CString regEmail;
	CString regPass;
};
