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
END_MESSAGE_MAP()

/*BOOL CADMIN::OnInitDialog()
{
	//CDialogEx::OnInitDialog();

	// user control list column initialization
	CRect rect;
	m_userListCtrl.GetClientRect(&rect);
	int nColInterval = rect.Width() / 4; // column width
	m_userListCtrl.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 50 * 2);
	m_userListCtrl.InsertColumn(1, _T("Rating"), LVCFMT_LEFT, 50 * 2);

	return 1;
}*/
// CADMIN message handlers


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
		myconnectorclassDB MyConnection;
		MyConnection.connect();
		UpdateData(TRUE);
		CString retStudy = MyConnection.addStudyroom(SRName,SRbuilding,SRChairs,SRPlugs,SRFloor,SRNoise,SRBibl);
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
	int nColInterval = rect.Width() / 7; // column width
	m_userListCtrl.InsertColumn(0, _T("ID"), LVCFMT_LEFT, nColInterval *2);
	m_userListCtrl.InsertColumn(1, _T("Name"), LVCFMT_LEFT, nColInterval * 3);
	m_userListCtrl.InsertColumn(2, _T("Email"), LVCFMT_LEFT, nColInterval * 4);

}
