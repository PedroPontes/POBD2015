// LoginDIALOG.cpp : implementation file
//

#include "stdafx.h"
#include "MFCAppSdE2017.h"
#include "LoginDIALOG.h"
#include "afxdialogex.h"
#include "MFCAppSdE2017Dlg.h"
#include "Register.h"


// CLoginDIALOG dialog

IMPLEMENT_DYNAMIC(CLoginDIALOG, CDialog)

CLoginDIALOG::CLoginDIALOG(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDIALOG::IDD, pParent)
	, username(_T(""))
	, password(_T(""))
	, msgLogin(_T(""))
{

}

CLoginDIALOG::~CLoginDIALOG()
{
}

void CLoginDIALOG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITUsername, username);
	DDX_Text(pDX, IDC_EDITPassword, password);
	DDX_Text(pDX, IDC_LoginMessage, msgLogin);
}


BEGIN_MESSAGE_MAP(CLoginDIALOG, CDialog)
	ON_EN_CHANGE(IDC_EDITUsername, &CLoginDIALOG::OnEnChangeEditusername)
	ON_EN_CHANGE(IDC_EDITPassword, &CLoginDIALOG::OnEnChangeEditpassword)
	ON_BN_CLICKED(IDC_LoginBUTT, &CLoginDIALOG::OnBnClickedLoginbutt)
	ON_EN_CHANGE(IDC_LoginMessage, &CLoginDIALOG::OnEnChangeLoginmessage)
	ON_BN_CLICKED(IDC_RegisterBUTTON, &CLoginDIALOG::OnBnClickedRegisterbutton)
END_MESSAGE_MAP()


// CLoginDIALOG message handlers


void CLoginDIALOG::OnEnChangeEditusername()
{
	UpdateData(TRUE);
}


void CLoginDIALOG::OnEnChangeEditpassword()
{
	UpdateData(TRUE);
}


void CLoginDIALOG::OnBnClickedLoginbutt()
{
	// TODO: Add your control notification handler code here
	myconnectorclassDB MyConnection;
	MyConnection.connect();
	UpdateData(TRUE);

	aux = MyConnection.Login(username,password);

	if (aux){
		EndDialog(1);
	}
	else{
		msgLogin = _T("Invalid credentials, try again");
	}
	UpdateData(FALSE);
}

CString CLoginDIALOG::GetUser()
{
	return username;
}

BOOL CLoginDIALOG::GetLoginState()
{
	return aux;
}

void CLoginDIALOG::OnEnChangeLoginmessage()
{
	UpdateData(TRUE);
	UpdateData(FALSE);
}


void CLoginDIALOG::OnBnClickedRegisterbutton()
{
	UpdateData(TRUE);
	CRegister ldlg;
	ldlg.DoModal();
	UpdateData(FALSE);
}
