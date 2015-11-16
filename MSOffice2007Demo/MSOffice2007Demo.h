// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMSOffice2007DemoApp:
// See MSOffice2007Demo.cpp for the implementation of this class
//

class CMSOffice2007DemoApp : public CWinAppEx
{
public:
	CMSOffice2007DemoApp();

	BOOL m_bShowFloaty;
	UINT m_nAppLook;
	BOOL m_bShowDevTab;
	BOOL m_bShowToolTips;
	BOOL m_bShowToolTipDescr;
	BOOL m_bShowKeyTips;
	BOOL m_bIsRTL;

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	//{{AFX_MSG(CMSOffice2007DemoApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CMSOffice2007DemoApp theApp;
