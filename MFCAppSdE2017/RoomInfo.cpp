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
	, schedule_info(_T(""))
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
	DDX_Text(pDX, IDC_scheduleinfo, schedule_info);
	DDV_MaxChars(pDX, schedule_info, 100);
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
}

void CRoomInfo::SetRoomID(CString* room_id_ptr){
	roomID = *room_id_ptr;
}

void CRoomInfo::SetRoomInfo(std::vector<CString>* room_info_ptr){

	nameInfo = room_info_ptr->at(0);
	chairsInfo = room_info_ptr->at(1);
	plugInfo = room_info_ptr->at(2); 
	typeInfo = room_info_ptr->at(3);
	
	if (room_info_ptr->at(4) == "0") libraryInfo = _T("No");
	else libraryInfo = _T("Yes");

	if (room_info_ptr->at(5) == "0") silentInfo = _T("Yes");
	else silentInfo = _T("No");
	
	floorInfo = room_info_ptr->at(6);
	rateInfo = room_info_ptr->at(7);
	buildingInfo = room_info_ptr->at(8);
	addressInfo = room_info_ptr->at(9);
	latInfo = room_info_ptr->at(10);
	longInfo = room_info_ptr->at(11);

	std::vector<CString> Day;
	CString sHour = room_info_ptr->at(14);
	CString cHour = room_info_ptr->at(15);
	for (int i = 12; i < 14; i++){
		if (room_info_ptr->at(i).Compare(_T("0"))) Day.push_back(_T("Sunday"));
		else if (room_info_ptr->at(i).Compare(_T("1"))) Day.push_back(_T("Monday"));
		else if (room_info_ptr->at(i).Compare(_T("2"))) Day.push_back(_T("Tuesday"));
		else if (room_info_ptr->at(i).Compare(_T("3"))) Day.push_back(_T("Wednesday"));
		else if (room_info_ptr->at(i).Compare(_T("4"))) Day.push_back(_T("Thursday"));
		else if (room_info_ptr->at(i).Compare(_T("5"))) Day.push_back(_T("Friday"));
		else if (room_info_ptr->at(i).Compare(_T("6"))) Day.push_back(_T("Saturday"));
	}
	if (Day[0] == Day[1]){
		schedule_info = _T("Open on ") + Day[0]
			+ _T(", from ") + sHour + _T(":00 to ") + cHour + _T(":00");
	}
	else{
		schedule_info = _T("Open from ") + Day[0] + _T(" to ") + Day[1]
			+ _T(", from ") + sHour + _T(":00 to ") + cHour + _T(":00");
	}
}

void CRoomInfo::SetUsername(CString* user_ptr){
	username = *user_ptr;
}



