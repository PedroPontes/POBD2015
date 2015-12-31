
// MFCAppSdE2017.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include "myconnectorclassDB.h"

// CMFCAppSdE2017App:
// See MFCAppSdE2017.cpp for the implementation of this class
//

class CMFCAppSdE2017App : public CWinApp
{
public:
	CMFCAppSdE2017App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	DECLARE_MESSAGE_MAP()
};

extern CMFCAppSdE2017App theApp;