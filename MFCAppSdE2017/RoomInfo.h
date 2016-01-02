#pragma once


// CRoomInfo dialog

class CRoomInfo : public CDialog
{
	DECLARE_DYNAMIC(CRoomInfo)

public:
	CRoomInfo(CWnd* pParent = NULL);   // standard constructor
	virtual ~CRoomInfo();

// Dialog Data
	enum { IDD = IDD_RoomINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString nameInfo;
	CString rateInfo;
	CString chairsInfo;
	afx_msg void OnBnClickedRatebutton();
	afx_msg void OnEnChangeRatinginfo();
	CString plugInfo;
	CString typeInfo;
	CString libraryInfo;
	CString silentInfo;
	CString buildingInfo;
	CString addressInfo;
	CString latInfo;
	CString longInfo;
	CString newRating;
	CString floorInfo;
};
