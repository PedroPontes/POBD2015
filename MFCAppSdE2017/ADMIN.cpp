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
{

}

CADMIN::~CADMIN()
{
}

void CADMIN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DelUser, userIDdel);
}


BEGIN_MESSAGE_MAP(CADMIN, CDialog)
	ON_EN_CHANGE(IDC_EDIT_DelUser, &CADMIN::OnEnChangeEditDeluser)
	ON_BN_CLICKED(IDC_BUTTON_DelUser, &CADMIN::OnBnClickedButtonDeluser)
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
	if (!aux){
		message.Format(_T("User not Found!"));
		AfxMessageBox(message);
	}
	else{
		message.Format(_T("Deletion successful"));
		AfxMessageBox(message);
	}

}
