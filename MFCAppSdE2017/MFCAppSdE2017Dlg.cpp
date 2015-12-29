
// MFCAppSdE2017Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCAppSdE2017.h"
#include "MFCAppSdE2017Dlg.h"
#include "afxdialogex.h"
#include "ctime"

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
	, library(FALSE)
	, isSmall(FALSE)
	, isMedium(FALSE)
	, isLarge(FALSE)
	, isOpen(FALSE)
	, silentV(FALSE)
	, silentX(FALSE)
	, distance(0)
	, latitude(0)
	, longitude(0)
	, distON(FALSE)
	, isGood(FALSE)
	, isBest(FALSE)
	, plugG(FALSE)
	, plugB(FALSE)
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
	DDX_Check(pDX, IDC_CHECKOpen, isOpen);
	DDX_Check(pDX, IDC_CHECKSilenceV, silentV);
	DDX_Check(pDX, IDC_CHECKSilenceX, silentX);
	DDX_Text(pDX, IDC_EDITDist, distance);
	DDX_Text(pDX, IDC_EDITlat, latitude);
	DDV_MinMaxFloat(pDX, latitude, -90, 90);
	DDX_Text(pDX, IDC_EDITlong, longitude);
	DDV_MinMaxFloat(pDX, longitude, -180, 180);
	DDX_Check(pDX, IDC_CHECKDist, distON);
	DDX_Check(pDX, IDC_CHECKGood, isGood);
	DDX_Check(pDX, IDC_CHECKBest, isBest);
	DDX_Check(pDX, IDC_CHECKPlugB, plugB);
	DDX_Check(pDX, IDC_CHECKPlugG, plugG);
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
	ON_BN_CLICKED(IDC_CHECKOpen, &CMFCAppSdE2017Dlg::CheckOpen)
	ON_BN_CLICKED(IDC_CHECKSilenceV, &CMFCAppSdE2017Dlg::ChecksilenceV)
	ON_BN_CLICKED(IDC_CHECKSilenceX, &CMFCAppSdE2017Dlg::Checksilencex)
	ON_EN_CHANGE(IDC_EDITlat, &CMFCAppSdE2017Dlg::OnEnChangeEditlat)
	ON_EN_CHANGE(IDC_EDITlong, &CMFCAppSdE2017Dlg::OnEnChangeEditlong)
	ON_EN_CHANGE(IDC_EDITDist, &CMFCAppSdE2017Dlg::OnEnChangeEditdist)
	ON_BN_CLICKED(IDC_CHECKDist, &CMFCAppSdE2017Dlg::OnBnClickedCheckdist)
	ON_BN_CLICKED(IDC_CHECKGood, &CMFCAppSdE2017Dlg::OnBnClickedCheckgood)
	ON_BN_CLICKED(IDC_CHECKBest, &CMFCAppSdE2017Dlg::OnBnClickedCheckbest)
	ON_BN_CLICKED(IDC_CHECKPlugG, &CMFCAppSdE2017Dlg::OnBnClickedCheckplugG)
	ON_BN_CLICKED(IDC_CHECKPlugB, &CMFCAppSdE2017Dlg::OnBnClickedCheckplugB)
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
	// TRACKING FUNCTION PIECE //////////
	float latitudeMaxF;
	float latitudeMinF;
	float longitudeMaxF;
	float longitudeMinF;
	CString longitudeMin;
	CString latitudeMax;
	CString latitudeMin;
	CString longitudeMax;
	if (distON){
		latitudeMaxF = latitude + distance / 111111;latitudeMax.Format(_T("%.5f"), latitudeMaxF);
		latitudeMinF = latitude - distance / 111111;latitudeMin.Format(_T("%.5f"), latitudeMinF);
		longitudeMaxF = longitude + distance / 111111;longitudeMax.Format(_T("%.5f"), longitudeMaxF);
		longitudeMinF = longitude - distance / 111111; longitudeMin.Format(_T("%.5f"), longitudeMinF);
	};
	// END///////////RATING///VVV////////
	CString minRate;
	if (isGood){
		minRate = _T("50");
	}
	else if (isBest && !isGood){
		minRate = _T("75");
	}
	else {
		minRate = _T("0");
	};
	/////END///////PLUGS///VVVV//////
	CString minPlugs;
	if (plugG){
		minPlugs = _T("0.5");
	}
	else if (plugB && !plugG){
		minPlugs = _T("0.75");
	}
	else {
		minPlugs = _T("0");
	};
	/////END//////
	CString sentence;
	CString isSmallQ = Bule2String(isSmall); CString isMediumQ = Bule2String(isMedium); CString isLargeQ = Bule2String(isLarge);
	CString isOpenQ = Bule2String(isOpen); CString libraryQ = Bule2String(library); CString silentVQ = Bule2String(silentV);
	CString silentXQ = Bule2String(silentX); CString distONQ = Bule2String(distON);
	sentence = isSmallQ + _T(",") + isMediumQ + _T(",") + isLargeQ + _T(",") + isOpenQ + _T(",") + hour + _T(",") + wday + _T(",") + minRate +
		_T(",") + libraryQ + _T(",") + minPlugs + _T(",") + silentVQ + _T(",") + silentXQ + _T(",") + distONQ + _T(",") + latitudeMin + _T(",") +
		latitudeMax + _T(",") + longitudeMin + _T(",") + longitudeMax;
	building = MyConnection.Search(sentence);
	UpdateData(FALSE);
}


void CMFCAppSdE2017Dlg::Librarybutton()
{
	// TODO: Add your control notification handler code here;
	UpdateData(TRUE);
}


void CMFCAppSdE2017Dlg::SizeSmall()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
}


void CMFCAppSdE2017Dlg::SizeMedium()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
}


void CMFCAppSdE2017Dlg::SizeLarge()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
}

void CMFCAppSdE2017Dlg::CheckOpen()
{
	UpdateData(TRUE);
	time_t t = time(0);   // get time now
	struct tm now;
	localtime_s(&now,&t);
	hour.Format(_T("%d"), now.tm_hour);
	wday.Format(_T("%d"), now.tm_wday);
}


void CMFCAppSdE2017Dlg::ChecksilenceV()
{
	UpdateData(TRUE);// CHECK SILENT
}


void CMFCAppSdE2017Dlg::Checksilencex()
{
	UpdateData(TRUE);// CHECK NOT SILENT
}

/////////////////////////////////////////DISTANCE BOX/////////////////////////
void CMFCAppSdE2017Dlg::OnEnChangeEditlat()
{
	UpdateData(TRUE);
}


void CMFCAppSdE2017Dlg::OnEnChangeEditlong()
{
	UpdateData(TRUE);
}


void CMFCAppSdE2017Dlg::OnEnChangeEditdist()
{
	UpdateData(TRUE);
}


void CMFCAppSdE2017Dlg::OnBnClickedCheckdist()
{
	UpdateData(TRUE);
}
/////////////////////////////////////////END/////////////////////////

void CMFCAppSdE2017Dlg::OnBnClickedCheckgood()
{
	UpdateData(TRUE);
}


void CMFCAppSdE2017Dlg::OnBnClickedCheckbest()
{
	UpdateData(TRUE);
}


void CMFCAppSdE2017Dlg::OnBnClickedCheckplugG()
{
	UpdateData(TRUE);
}


void CMFCAppSdE2017Dlg::OnBnClickedCheckplugB()
{
	UpdateData(TRUE);
}

CString Bule2String(BOOL boolean)
{
	CString newstring;
	if (boolean){
		newstring = _T("1");
	}
	else{
		newstring = _T("0");
	}
	return newstring;
}