
// MFCAppSdE2017Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCAppSdE2017.h"
#include "MFCAppSdE2017Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCAppSdE2017Dlg dialog



CMFCAppSdE2017Dlg::CMFCAppSdE2017Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCAppSdE2017Dlg::IDD, pParent)
	, building(_T(""))
	, qlib(_T(""))//Library query
	, qsmall(_T(""))// Size query
	, qmedium(_T(""))//  ''
	, qlarge(_T(""))//   ''
	, library(FALSE)
	, isSmall(FALSE)
	, isMedium(FALSE)
	, isLarge(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCAppSdE2017Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITbuilding, building);
	DDX_Check(pDX, IDC_CHECKLib, library);
	DDX_Check(pDX, IDC_CHECKsmall, isSmall);
	DDX_Check(pDX, IDC_CHECKmedium, isMedium);
	DDX_Check(pDX, IDC_CHECKLarge, isLarge);
}

BEGIN_MESSAGE_MAP(CMFCAppSdE2017Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONquery, &CMFCAppSdE2017Dlg::OnBnClickedButtonquery)
	ON_BN_CLICKED(IDC_CHECKLib, &CMFCAppSdE2017Dlg::Librarybutton)
	ON_BN_CLICKED(IDC_CHECKsmall, &CMFCAppSdE2017Dlg::SizeSmall)
	ON_BN_CLICKED(IDC_CHECKmedium, &CMFCAppSdE2017Dlg::SizeMedium)
	ON_BN_CLICKED(IDC_CHECKLarge, &CMFCAppSdE2017Dlg::SizeLarge)
END_MESSAGE_MAP()


// CMFCAppSdE2017Dlg message handlers

BOOL CMFCAppSdE2017Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCAppSdE2017Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCAppSdE2017Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCAppSdE2017Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCAppSdE2017Dlg::OnBnClickedButtonquery()
{
	// TODO: Add your control notification handler code here
	myconnectorclassDB MyConnection;
	MyConnection.connect();
	UpdateData(TRUE);
	CString qsize;

	if((isSmall && isMedium && isLarge) || (!isSmall && !isMedium && !isLarge))
	{
		qsize = _T("");
	}
	else if (isSmall && (isMedium || isLarge )){
		qsize = _T(" and (") + qsmall + _T(" or") + qmedium + qlarge + _T(")");
	}
	else if (isLarge && isMedium){
		qsize = _T(" and (") + qlarge + _T(" or") + qmedium + _T(")");
	}
	else{
		qsize = _T(" and") + qsmall + qmedium + qlarge;
	}
	building = MyConnection.Search(qlib+qsize);
	UpdateData(FALSE);
}


void CMFCAppSdE2017Dlg::Librarybutton()
{
	// TODO: Add your control notification handler code here;
	UpdateData(TRUE);
	if (library == TRUE){
		qlib = _T(" and studyroom.bibl= '1'");
	}
	else{
		qlib = _T("");
	}
}


void CMFCAppSdE2017Dlg::SizeSmall()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (isSmall == TRUE){
		qsmall = _T(" studyroom.chairs< '35'");
	}
	else{
		qsmall = _T("");
	}
}


void CMFCAppSdE2017Dlg::SizeMedium()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (isMedium == TRUE){
		qmedium = _T(" (studyroom.chairs<= '55' and studyroom.chairs> '35')");
	}
	else{
		qmedium = _T("");
	}
}


void CMFCAppSdE2017Dlg::SizeLarge()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (isLarge == TRUE){
		qlarge = _T(" studyroom.chairs> '55'");
	}
	else{
		qlarge = _T("");
	}
}