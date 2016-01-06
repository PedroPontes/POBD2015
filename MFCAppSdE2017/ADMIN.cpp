// ADMIN.cpp : implementation file
//

#include "stdafx.h"
#include "MFCAppSdE2017.h"
#include "ADMIN.h"
#include "afxdialogex.h"


// CADMIN dialog

IMPLEMENT_DYNAMIC(CADMIN, CDialog)

CADMIN::CADMIN(CWnd* pParent /*=NULL*/)
	: CDialog(CADMIN::IDD, pParent)
	, userIDdel(_T(""))
	, buildName(_T(""))
	, buildType(_T(""))
	, buildLat(_T(""))
	, buildLong(_T(""))
	, buildAdd(_T(""))
	, SRName(_T(""))
	, SRChairs(_T(""))
	, SRbuilding(_T(""))
	, SRFloor(_T(""))
	, SRPlugs(_T(""))
	, isSRNoise(FALSE)
	, isSRbibl(FALSE)
	, SRNoise(_T("0"))
	, SRBibl(_T("0"))
	, adminCode(_T("'1234'"))
	, SRopen(_T(""))
	, SRclose(_T(""))
	, SRfday(_T(""))
	, SRlday(_T(""))
	, check_everyday(FALSE)
{

}

CADMIN::~CADMIN()
{
}

void CADMIN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DelUser, userIDdel);
	DDX_Text(pDX, IDC_buildNameEDIT, buildName);
	DDX_Text(pDX, IDC_typeBuildEDIT, buildType);
	DDX_Text(pDX, IDC_latEDIT, buildLat);
	DDX_Text(pDX, IDC_longEDIT, buildLong);
	DDX_Text(pDX, IDC_addressEDIT, buildAdd);
	DDX_Text(pDX, IDC_NameAddStudEDIT, SRName);
	DDX_Text(pDX, IDC_ChairsAddEDIT, SRChairs);
	DDX_Text(pDX, IDC_BuildaddEDIT, SRbuilding);
	DDX_Text(pDX, IDC_FloorEDIT, SRFloor);
	DDX_Text(pDX, IDC_PlugsEDIT, SRPlugs);
	DDX_Check(pDX, IDC_NoiseCHECK, isSRNoise);
	DDX_Check(pDX, IDC_LibraryAddCHECK, isSRbibl);
	DDX_Control(pDX, IDC_userLIST, m_userListCtrl);
	DDX_Text(pDX, IDC_openEDIT, SRopen);
	DDX_Text(pDX, IDC_closeEDIT, SRclose);
	DDX_Text(pDX, IDC_fDayEDIT, SRfday);
	DDX_Text(pDX, IDC_lDayEDIT, SRlday);
	DDX_Check(pDX, IDC_CHECKeveryday, check_everyday);
}


BEGIN_MESSAGE_MAP(CADMIN, CDialog)
	ON_EN_CHANGE(IDC_EDIT_DelUser, &CADMIN::OnEnChangeEditDeluser)
	ON_BN_CLICKED(IDC_BUTTON_DelUser, &CADMIN::OnBnClickedButtonDeluser)
	ON_EN_CHANGE(IDC_buildNameEDIT, &CADMIN::OnEnChangebuildnameedit)
	ON_EN_CHANGE(IDC_typeBuildEDIT, &CADMIN::OnEnChangetypebuildedit)
	ON_EN_CHANGE(IDC_addressEDIT, &CADMIN::OnEnChangeaddressedit)
	ON_EN_CHANGE(IDC_latEDIT, &CADMIN::OnEnChangelatedit)
	ON_EN_CHANGE(IDC_longEDIT, &CADMIN::OnEnChangelongedit)
	ON_BN_CLICKED(IDC_addBuildBUTTON, &CADMIN::OnBnClickedButtonAddbuilding)
	ON_BN_CLICKED(IDC_AddStudyroom, &CADMIN::OnBnClickedAddstudyroom)
	ON_EN_CHANGE(IDC_NameAddStudEDIT, &CADMIN::OnEnChangeNameaddstudedit)
	ON_EN_CHANGE(IDC_ChairsAddEDIT, &CADMIN::OnEnChangeChairsaddedit)
	ON_EN_CHANGE(IDC_BuildaddEDIT, &CADMIN::OnEnChangeBuildaddedit)
	ON_EN_CHANGE(IDC_FloorEDIT, &CADMIN::OnEnChangeFlooredit)
	ON_EN_CHANGE(IDC_PlugsEDIT, &CADMIN::OnEnChangePlugsedit)
	ON_BN_CLICKED(IDC_NoiseCHECK, &CADMIN::OnBnClickedNoisecheck)
	ON_BN_CLICKED(IDC_LibraryAddCHECK, &CADMIN::OnBnClickedLibraryaddcheck)
	ON_BN_CLICKED(IDC_BUTTON_refresh, &CADMIN::OnBnClickedButtonrefresh)
	ON_EN_CHANGE(IDC_openEDIT, &CADMIN::OnEnChangeopenedit)
	ON_EN_CHANGE(IDC_closeEDIT, &CADMIN::OnEnChangecloseedit)
	ON_EN_CHANGE(IDC_fDayEDIT, &CADMIN::OnEnChangefdayedit)
	ON_EN_CHANGE(IDC_lDayEDIT, &CADMIN::OnEnChangeldayedit)
END_MESSAGE_MAP()



void CADMIN::OnEnChangeEditDeluser()
{
	UpdateData(TRUE);
}


void CADMIN::OnBnClickedButtonDeluser()
{
	UpdateData(TRUE);
	myconnectorclassDB MyConnection;
	MyConnection.connect();
	CString message;
	BOOL aux = MyConnection.deleteUser(userIDdel);
	if (aux==0){
		message.Format(_T("User not Found!"));
		AfxMessageBox(message);
	}
	else{
		message.Format(_T("Deletion successful"));
		AfxMessageBox(message);
	}
}

void CADMIN::OnEnChangebuildnameedit()
{
	UpdateData(TRUE);
}

void CADMIN::OnEnChangetypebuildedit()
{
	UpdateData(TRUE);
}

void CADMIN::OnEnChangeaddressedit()
{
	UpdateData(TRUE);
}

void CADMIN::OnEnChangelatedit()
{
	UpdateData(TRUE);
}

void CADMIN::OnEnChangelongedit()
{
	UpdateData(TRUE);
}


void CADMIN::OnBnClickedButtonAddbuilding()
{
	UpdateData(TRUE);
	CString message;

	if (buildName.IsEmpty() || buildType.IsEmpty() || buildLat.IsEmpty() || buildLong.IsEmpty() || buildAdd.IsEmpty()){ //check if the register is complete before
		message.Format(_T("Please fill every field before proceeding"));//////////////sending the query
		AfxMessageBox(message);
	}
	else{
		myconnectorclassDB MyConnection;
		MyConnection.connect();
		UpdateData(TRUE);
		CString retBuild = MyConnection.addBuilding(buildName,buildLat,buildLong,buildType,buildAdd);
		BOOL aux = 1;
		// The command mysql_real_connect is included in the libraries

		if (retBuild.IsEmpty()){
			message.Format(_T("Building Added"));
			AfxMessageBox(message);
		}
		else{
			message.Format(_T("Building ") + retBuild + _T(" already exists. Try Again."));///check if user is avaiable
			AfxMessageBox(message);
		}
	}
	UpdateData(FALSE);
}


void CADMIN::OnBnClickedAddstudyroom()
{
		UpdateData(TRUE);
	CString message;

	if (SRName.IsEmpty() || SRbuilding.IsEmpty() || SRChairs.IsEmpty() || SRPlugs.IsEmpty()){ //check if the register is complete before
		message.Format(_T("Please fill every field before proceeding"));//////////////sending the query
		AfxMessageBox(message);
	}
	else{
		CString _SRfday;
		CString _SRlday;
		if (check_everyday){
			_SRfday = _T("0");
			_SRlday = _T("6");
		}
		else{
			_SRfday = SRfday;
			_SRlday = SRlday;
		}
		CString _SRPlugs;
		_SRPlugs.Format(_T("%.1f"), _ttof(SRPlugs) * 10);
		myconnectorclassDB MyConnection;
		MyConnection.connect();
		UpdateData(TRUE);
		CString retStudy = MyConnection.addStudyroom(SRName,SRbuilding,SRChairs,_SRPlugs,SRFloor,SRNoise,SRBibl,SRopen,SRclose,
			_SRfday,_SRlday);
		BOOL aux = 1;
		// The command mysql_real_connect is included in the libraries
		
		if (retStudy.IsEmpty()){
			message.Format(_T("Studyroom Added"));
			AfxMessageBox(message);
		}
		else if (retStudy==_T("noBuilding")){
			message.Format(_T("Invalid Building. Add a building before creating a new room"));
			AfxMessageBox(message);
		}
		else{
			message.Format(_T("Studyroom ") + retStudy + _T(" already exists. Try Again."));///check if user is avaiable
			AfxMessageBox(message);
		}
	}
	UpdateData(FALSE);
}


void CADMIN::OnEnChangeNameaddstudedit()
{
	UpdateData(TRUE);
}


void CADMIN::OnEnChangeChairsaddedit()
{
	UpdateData(TRUE);
}


void CADMIN::OnEnChangeBuildaddedit()
{
	UpdateData(TRUE);
}


void CADMIN::OnEnChangeFlooredit()
{
	UpdateData(TRUE);
}


void CADMIN::OnEnChangePlugsedit()
{
	UpdateData(TRUE);
}


void CADMIN::OnBnClickedNoisecheck()
{
	UpdateData(TRUE);
	if (isSRNoise) {
		SRNoise = _T("1");
	}
	else{
		SRNoise = _T("0");
	}
}


void CADMIN::OnBnClickedLibraryaddcheck()
{
	UpdateData(TRUE);
	if (isSRbibl) {
		SRBibl = _T("1");
	}
	else{
		SRBibl = _T("0");
	}
}


void CADMIN::OnBnClickedButtonrefresh()
{
	// TODO: Add your control notification handler code here
	// user control list column initialization
	CRect rect;
	m_userListCtrl.GetClientRect(&rect);
	int nColInterval = rect.Width() / 9; // column width
	m_userListCtrl.InsertColumn(0, _T("ID"), LVCFMT_LEFT, nColInterval);
	m_userListCtrl.InsertColumn(1, _T("Username"), LVCFMT_LEFT, nColInterval * 3);
	m_userListCtrl.InsertColumn(2, _T("Email"), LVCFMT_LEFT, nColInterval * 4);
	// call getUsers()
	myconnectorclassDB MyAdminConnection;
	MyAdminConnection.connect();
	BOOL admin_value = MyAdminConnection.isAdmin(username);
	myconnectorclassDB MyConnection;
	MyConnection.connect();
	if (admin_value){
		adminCode = _T("'1234'"); 
		std::vector<LVITEM> search_results = MyConnection.GetUsers(adminCode); // query and result
		// list control box update
		UpdateData(TRUE);
		m_userListCtrl.DeleteAllItems();
		bool first_item = TRUE;
		for (int i = 0; i < search_results.size(); i++)
		{
			if (first_item){
				m_userListCtrl.InsertItem(&search_results[i]); // insert items in list control box
			}
			else{
				m_userListCtrl.SetItem(&search_results[i]); // set subitems in list control box
			}
			if (i < search_results.size() - 1){
				if (search_results[i + 1].iSubItem > 0){
					first_item = FALSE;
				}
				else{
					first_item = TRUE;
				}
			}

		}
		UpdateData(FALSE);
	}
}

void CADMIN::SetUsername(CString inputname){
	username = inputname;
}

void CADMIN::OnEnChangeopenedit()
{
	UpdateData(TRUE);
}


void CADMIN::OnEnChangecloseedit()
{
	UpdateData(TRUE);
}


void CADMIN::OnEnChangefdayedit()
{
	UpdateData(TRUE);
}


void CADMIN::OnEnChangeldayedit()
{
	UpdateData(TRUE);
}
