// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

#include "DlgBanner.h"

/////////////////////////////////////////////////////////////////////////////
// CDemoOptionsPage dialog

class CDemoOptionsPage : public CMFCPropertyPage
{
	DECLARE_DYNCREATE(CDemoOptionsPage)

// Construction
public:
	CDemoOptionsPage();
	~CDemoOptionsPage();

// Dialog Data
	//{{AFX_DATA(CDemoOptionsPage)
	enum { IDD = IDD_POPULAR_PAGE };
	CDlgBanner m_wndBanner;
	CComboBox m_wndColorScheme;
	int m_nColorScheme;
	int m_nTooltipStyle;
	BOOL m_bShowDevTab;
	BOOL m_bShowFloaty;
	BOOL m_bShowKeyTips;
	//}}AFX_DATA

// Overrides
public:
	virtual void OnOK();
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	//{{AFX_MSG(CDemoOptionsPage)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

	virtual BOOL OnInitDialog();
};

class CDemoOptionsPropSheet : public CMFCPropertySheet
{
public:
	CDemoOptionsPropSheet(CWnd* pWndParent, UINT nSelectedPage = 0);

protected:
	virtual void OnDrawPageHeader(CDC* pDC, int nPage, CRect rectHeader);

	CMFCToolBarImages m_Icons;
	CMFCControlRenderer m_Pat[4];
};

