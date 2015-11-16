// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "MSOffice2007Demo.h"
#include "DlgBanner.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgBanner

CDlgBanner::CDlgBanner()
{
}

CDlgBanner::~CDlgBanner()
{
}

BEGIN_MESSAGE_MAP(CDlgBanner, CStatic)
	//{{AFX_MSG_MAP(CDlgBanner)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgBanner message handlers

void CDlgBanner::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect rect;
	GetClientRect(rect);

	CFont* pOldFont = dc.SelectObject(&globalData.fontBold);
	ASSERT(pOldFont != NULL);

	dc.SetTextColor(CMFCVisualManager::GetInstance()->OnDrawMenuLabel(&dc, rect));
	dc.SetBkMode(TRANSPARENT);

	rect.DeflateRect(5, 0);

	CString strText;
	GetWindowText(strText);

	dc.DrawText(strText, rect, DT_LEFT | DT_SINGLELINE | DT_VCENTER);

	dc.SelectObject(pOldFont);
}

