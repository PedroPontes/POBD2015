
// MFCAppSdE2017Dlg.h : header file
//

#pragma once


// CMFCAppSdE2017Dlg dialog
class CMFCAppSdE2017Dlg : public CDialogEx
{
// Construction
public:
	CMFCAppSdE2017Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCAPPSDE2017_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonquery();
	CString studyroom;
	CString building;
	afx_msg void Librarybutton();
	afx_msg void OnEnChangeEditstudyroom();
	BOOL library;
	CString qlib;
};
