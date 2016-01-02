
// MFCAppSdE2017Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCAppSdE2017.h"
#include "MFCAppSdE2017Dlg.h"
#include "afxdialogex.h"
#include "ctime"
#include "LoginDIALOG.h"
#include "ADMIN.h"

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
	, LoginStateMsg(_T("Logged in as Guest"))
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
	DDX_Text(pDX, IDC_LoginState, LoginStateMsg);
	//DDX_Control(pDX, IDC_STATIC_1, *m_label);
	DDX_Control(pDX, IDC_roomLIST, m_roomListCtrl);
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
	ON_BN_CLICKED(IDC_LoginBUTTON, &CMFCAppSdE2017Dlg::OnBnClickedLoginbutton)
	ON_EN_CHANGE(IDC_LoginState, &CMFCAppSdE2017Dlg::OnEnChangeLoginstate)
	ON_BN_CLICKED(IDC_LogoutBUTTON, &CMFCAppSdE2017Dlg::OnBnClickedLogoutbutton)
	ON_BN_CLICKED(IDC_AdminCP_BUTTON, &CMFCAppSdE2017Dlg::OnBnClickedAdmincpButton)
	ON_NOTIFY(HDN_ITEMDBLCLICK, 0, &CMFCAppSdE2017Dlg::OnHdnItemdblclickroomlist)
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
	CFont *m_Font1 = new CFont;
	m_Font1->CreatePointFont(120, _T("Arial Black"));
	m_label = (CStatic *)GetDlgItem(IDC_STATIC_1);
	m_label->SetFont(m_Font1);

	// room control list column initialization
	CRect rect;
	m_roomListCtrl.GetClientRect(&rect);
	int nColInterval = rect.Width() / 4; // column width
	m_roomListCtrl.InsertColumn(0, _T("Name"), LVCFMT_LEFT, nColInterval * 2);
	m_roomListCtrl.InsertColumn(1, _T("Rating"), LVCFMT_LEFT, nColInterval * 2);

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
	}
	else{
		latitudeMaxF = 0;
		latitudeMax.Format(_T("%.5f"), latitudeMaxF);
		latitudeMinF = 0;
		latitudeMin.Format(_T("%.5f"), latitudeMinF);
		longitudeMaxF = 0;
		longitudeMax.Format(_T("%.5f"), longitudeMaxF);
		longitudeMinF = 0;
		longitudeMin.Format(_T("%.5f"), longitudeMinF);
	}
	// END///////////HOUR AND DAY////
	// TODO access system date and time
	int hourInt = 0;
	hour.Format(_T("%d"), hourInt);
	int wdayInt = 0;
	wday.Format(_T("%d"), wdayInt);
	// END///////////RATING///VVV////
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
	/////END///////PLUGS///VVVV/////
	CString minPlugs;
	if (plugG){
		minPlugs = _T("7");
	}
	else if (plugB && !plugG){
		minPlugs = _T("10");
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
	std::vector<LVITEM> search_results = MyConnection.Search(sentence); // query and result

	// list control box update
	UpdateData(TRUE);
	m_roomListCtrl.DeleteAllItems();
	bool first_item = TRUE;
	for (int i = 0; i < search_results.size(); i++)
	{
		if (first_item){
			m_roomListCtrl.InsertItem(&search_results[i]); // insert items in list control box
		}
		else{
			m_roomListCtrl.SetItem(&search_results[i]); // set subitems in list control box
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

CString CMFCAppSdE2017Dlg::Bule2String(BOOL booleano)
{
	CString newstring;
	if (booleano){
		newstring = _T("1");
	}
	else{
		newstring = _T("0");
	}
	return newstring;
}

void CMFCAppSdE2017Dlg::OnBnClickedLoginbutton()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CLoginDIALOG ldlg;
	ldlg.DoModal();
	logstate= ldlg.GetLoginState();
	CString username = ldlg.GetUser();
	if (!logstate){
		username = _T("Guest");
	}
	LoginStateMsg = _T("Logged in as ") + username;
	UpdateData(FALSE);
}


void CMFCAppSdE2017Dlg::OnEnChangeLoginstate()
{
	UpdateData(TRUE);
}


void CMFCAppSdE2017Dlg::OnBnClickedLogoutbutton()
{
	UpdateData(TRUE);
	logstate = 0;
	CString username = _T("Guest");
	LoginStateMsg = _T("Logged in as ") + username;
	UpdateData(FALSE);
}


void CMFCAppSdE2017Dlg::OnBnClickedAdmincpButton()
{
	// TODO: Add your control notification handler code here
	CADMIN Admin;
	Admin.DoModal();
}


void CMFCAppSdE2017Dlg::OnHdnItemdblclickroomlist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
