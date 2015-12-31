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
	afx_msg void OnEnChangebuildnameedit();
	afx_msg void OnEnChangetypebuildedit();
	afx_msg void OnEnChangeaddressedit();
	afx_msg void OnEnChangelatedit();
	afx_msg void OnEnChangelongedit();
	afx_msg void OnBnClickedButton3();
	CString buildName;
	CString buildType;
	CString buildLat;
	CString buildLong;
	CString buildAdd;
};
