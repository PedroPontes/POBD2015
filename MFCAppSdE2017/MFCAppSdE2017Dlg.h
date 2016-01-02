
// MFCAppSdE2017Dlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


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
	afx_msg void Librarybutton();
	BOOL library;
	afx_msg void SizeSmall();
	BOOL isSmall;
	afx_msg void SizeMedium();
	BOOL isMedium;
	afx_msg void SizeLarge();
	BOOL isLarge;
	afx_msg void OnLvnItemchangedList4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void CheckOpen();
	BOOL isOpen;
	afx_msg void ChecksilenceV();
	afx_msg void Checksilencex();
	BOOL silentV;
	BOOL silentX;
	afx_msg void OnEnChangeEditlat();
	afx_msg void OnEnChangeEditlong();
	afx_msg void OnEnChangeEditdist();
	int distance;
	float latitude;
	float longitude;
	afx_msg void OnBnClickedCheckdist();
	BOOL distON;
	CString hour;
	CString wday;
	afx_msg void OnBnClickedCheckgood();
	afx_msg void OnBnClickedCheckbest();
	BOOL isGood;
	BOOL isBest;
	afx_msg void OnBnClickedCheckplugG();
	afx_msg void OnBnClickedCheckplugB();
	BOOL plugG;
	BOOL plugB;

	CString Bule2String(BOOL booleano);
	afx_msg void OnBnClickedLoginbutton();
	afx_msg void OnEnChangeLoginstate();
	CString LoginStateMsg;
	CStatic * m_label;
	afx_msg void OnBnClickedLogoutbutton();
	BOOL logstate;
	afx_msg void OnBnClickedAdmincpButton();
	// variable for room ctrl list
	CListCtrl m_roomListCtrl;
	afx_msg void OnHdnItemdblclickroomlist(NMHDR *pNMHDR, LRESULT *pResult);
	void showAdmin();
};
