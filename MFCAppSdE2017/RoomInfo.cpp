// RoomInfo.cpp : implementation file
//

#include "stdafx.h"
#include "MFCAppSdE2017.h"
#include "RoomInfo.h"
#include "afxdialogex.h"


// CRoomInfo dialog

IMPLEMENT_DYNAMIC(CRoomInfo, CDialog)

CRoomInfo::CRoomInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CRoomInfo::IDD, pParent)
	, nameInfo(_T(""))
	, rateInfo(_T(""))
	, chairsInfo(_T(""))
	, plugInfo(_T(""))
	, typeInfo(_T(""))
	, libraryInfo(_T(""))
	, silentInfo(_T(""))
	, buildingInfo(_T(""))
	, addressInfo(_T(""))
	, latInfo(_T(""))
	, longInfo(_T(""))
	, newRating(_T(""))
	, floorInfo(_T(""))
	, openInfo(_T(""))
{

}

CRoomInfo::~CRoomInfo()
{
}

void CRoomInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NameInfo, nameInfo);
	DDX_Text(pDX, IDC_RatingInfo, rateInfo);
	DDX_Text(pDX, IDC_ChairsInfo, chairsInfo);
	DDX_Text(pDX, IDC_PlugsInfo, plugInfo);
	DDX_Text(pDX, IDC_TypeInfo, typeInfo);
	DDX_Text(pDX, IDC_LibraryInfo, libraryInfo);
	DDX_Text(pDX, IDC_SilentInfo, silentInfo);
	DDX_Text(pDX, IDC_BuildingInfo, buildingInfo);
	DDX_Text(pDX, IDC_AddressInfo, addressInfo);
	DDX_Text(pDX, IDC_LatInfo, latInfo);
	DDX_Text(pDX, IDC_LongInfo, longInfo);
	DDX_Text(pDX, IDC_rateEDIT, newRating);
	DDX_Text(pDX, IDC_floorInfo, floorInfo);
	DDX_Text(pDX, IDC_EDIT3, openInfo);
}


BEGIN_MESSAGE_MAP(CRoomInfo, CDialog)
	ON_BN_CLICKED(IDC_RateBUTTON, &CRoomInfo::OnBnClickedRatebutton)
	ON_EN_CHANGE(IDC_RatingInfo, &CRoomInfo::OnEnChangeRatinginfo)
END_MESSAGE_MAP()


// CRoomInfo message handlers


void CRoomInfo::OnBnClickedRatebutton()
{
	UpdateData(TRUE);
	UpdateData(FALSE); 
}


void CRoomInfo::OnEnChangeRatinginfo()
{
	UpdateData(TRUE);
	CString rated;
	CString message;
	if (username == _T("Guest")){
		message.Format(_T("Login before submiting the Rating"));
		AfxMessageBox(message);
	}
	else{
		myconnectorclassDB MyConnection;
		MyConnection.connect();
		rated = MyConnection.rate(newRating, username, roomID);
		if (!(rated.IsEmpty())){
			message.Format(_T("Thank you for your opinion!"));
			AfxMessageBox(message);
		}
	}
	UpdateData(FALSE);
}
