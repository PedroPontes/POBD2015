#pragma once


// CADMIN dialog

class CADMIN : public CDialog
{
	DECLARE_DYNAMIC(CADMIN)

public:
	CADMIN(CWnd* pParent = NULL);   // standard constructor
	virtual ~CADMIN();

// Dialog Data
	enum { IDD = IDD_ADMIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString userIDdel;
	afx_msg void OnEnChangeEditDeluser();
	afx_msg void OnBnClickedButtonDeluser();
};
