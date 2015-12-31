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
}


BEGIN_MESSAGE_MAP(CADMIN, CDialog)
	ON_EN_CHANGE(IDC_EDIT_DelUser, &CADMIN::OnEnChangeEditDeluser)
	ON_BN_CLICKED(IDC_BUTTON_DelUser, &CADMIN::OnBnClickedButtonDeluser)
	ON_EN_CHANGE(IDC_buildNameEDIT, &CADMIN::OnEnChangebuildnameedit)
	ON_EN_CHANGE(IDC_typeBuildEDIT, &CADMIN::OnEnChangetypebuildedit)
	ON_EN_CHANGE(IDC_addressEDIT, &CADMIN::OnEnChangeaddressedit)
	ON_EN_CHANGE(IDC_latEDIT, &CADMIN::OnEnChangelatedit)
	ON_EN_CHANGE(IDC_longEDIT, &CADMIN::OnEnChangelongedit)
	ON_BN_CLICKED(IDC_BUTTON3, &CADMIN::OnBnClickedButton3)
END_MESSAGE_MAP()


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


void CADMIN::OnBnClickedButton3()
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
