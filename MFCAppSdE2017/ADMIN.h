#pragma once
#include "afxcmn.h"


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
	afx_msg void OnBnClickedButtonAddbuilding();
	CString buildName;
	CString buildType;
	CString buildLat;
	CString buildLong;
	CString buildAdd;
	afx_msg void OnBnClickedAddstudyroom();
	afx_msg void OnEnChangeNameaddstudedit();
	afx_msg void OnEnChangeChairsaddedit();
	afx_msg void OnEnChangeBuildaddedit();
	afx_msg void OnEnChangeFlooredit();
	afx_msg void OnEnChangePlugsedit();
	afx_msg void OnBnClickedNoisecheck();
	afx_msg void OnBnClickedLibraryaddcheck();
	CString SRName;
	CString SRChairs;
	CString SRbuilding;
	CString SRFloor;
	CString SRPlugs;
	BOOL isSRNoise;
	BOOL isSRbibl;
	CString SRNoise;
	CString SRBibl;
	// control variable for the user list control box in the admin control panel
	CListCtrl m_userListCtrl;
};
