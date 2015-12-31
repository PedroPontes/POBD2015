// Register.cpp : implementation file
//

#include "stdafx.h"
#include "MFCAppSdE2017.h"
#include "Register.h"
#include "MFCAppSdE2017Dlg.h"
#include "afxdialogex.h"


// CRegister dialog

IMPLEMENT_DYNAMIC(CRegister, CDialog)

CRegister::CRegister(CWnd* pParent /*=NULL*/)
	: CDialog(CRegister::IDD, pParent)
	, regUser(_T(""))
	, regName(_T(""))
	, regEmail(_T(""))
	, regPass(_T(""))
{

}

CRegister::~CRegister()
{
}

void CRegister::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITUsername, regUser);
	DDX_Text(pDX, IDC_EDITfullname, regName);
	DDX_Text(pDX, IDC_EDITemail, regEmail);
	DDX_Text(pDX, IDC_EDITPassword, regPass);
}


BEGIN_MESSAGE_MAP(CRegister, CDialog)
	ON_BN_CLICKED(IDC_RegisterButt, &CRegister::OnBnClickedRegisterbutt)
	ON_EN_CHANGE(IDC_EDITUsername, &CRegister::OnEnChangeEditusername)
	ON_EN_CHANGE(IDC_EDITfullname, &CRegister::OnEnChangeEditfullname)
	ON_EN_CHANGE(IDC_EDITemail, &CRegister::OnEnChangeEditemail)
	ON_EN_CHANGE(IDC_EDITPassword, &CRegister::OnEnChangeEditpassword)
END_MESSAGE_MAP()


// CRegister message handlers


void CRegister::OnBnClickedRegisterbutt()
{
	UpdateData(TRUE);
	CString message;
	
	if (regName.IsEmpty() || regEmail.IsEmpty() || regPass.IsEmpty() || regUser.IsEmpty()){ //check if the register is complete before
		message.Format(_T("Please fill every field before proceeding"));//////////////sending the query
		AfxMessageBox(message);
	}
	else{
		myconnectorclassDB MyConnection;
		MyConnection.connect();
		UpdateData(TRUE);
		CString retUser = MyConnection.Register(regName, regEmail, regPass, regUser);
		BOOL aux = 1;
		// The command mysql_real_connect is included in the libraries

		if (retUser.IsEmpty()){
			message.Format(_T("Account Created! Welcome."));
			AfxMessageBox(message);
			EndDialog(1);
		}
		else{
			message.Format(_T("Username ") + retUser + _T(" not avaiable, try again."));///check if user is avaiable
			AfxMessageBox(message);
		}
	}
	UpdateData(FALSE);

}


void CRegister::OnEnChangeEditusername()
{
	UpdateData(TRUE);
}


void CRegister::OnEnChangeEditfullname()
{
	UpdateData(TRUE);
}


void CRegister::OnEnChangeEditemail()
{
	UpdateData(TRUE);
}


void CRegister::OnEnChangeEditpassword()
{
	UpdateData(TRUE);
}
