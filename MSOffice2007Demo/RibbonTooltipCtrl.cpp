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
#include "RibbonTooltipCtrl.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRibbonTooltipCtrl

IMPLEMENT_DYNCREATE(CRibbonTooltipCtrl, CMFCToolTipCtrl)

CRibbonTooltipCtrl::CRibbonTooltipCtrl()
{
	m_pParentMenuBar = NULL;
	m_pParentRibbon = NULL;
}

CRibbonTooltipCtrl::~CRibbonTooltipCtrl()
{
}

BEGIN_MESSAGE_MAP(CRibbonTooltipCtrl, CMFCToolTipCtrl)
	//{{AFX_MSG_MAP(CRibbonTooltipCtrl)
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(TTN_SHOW, OnShow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRibbonTooltipCtrl message handlers

void CRibbonTooltipCtrl::OnShow(NMHDR* pNMHDR, LRESULT* pResult)
{
	m_nID = 0;

	CPoint point;
	::GetCursorPos(&point);

	if (m_pParentRibbon != NULL)
	{
		ASSERT_VALID(m_pParentRibbon);

		m_pParentRibbon->ScreenToClient(&point);

		CMFCRibbonBaseElement* pHit = m_pParentRibbon->HitTest(point, TRUE);

		if (pHit != NULL)
		{
			ASSERT_VALID(pHit);
			m_nID = pHit->GetID();
		}
	}
	else if (m_pParentMenuBar != NULL)
	{
		ASSERT_VALID(m_pParentMenuBar);

		m_pParentMenuBar->ScreenToClient(&point);

		CMFCRibbonBaseElement* pHit = m_pParentMenuBar->HitTest(point);

		if (pHit != NULL)
		{
			ASSERT_VALID(pHit);
			m_nID = pHit->GetID();
		}
	}

	CMFCToolTipCtrl::OnShow(pNMHDR, pResult);
}

int CRibbonTooltipCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMFCToolTipCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_pParentRibbon = DYNAMIC_DOWNCAST(CMFCRibbonBar, CWnd::FromHandlePermanent(lpCreateStruct->hwndParent));
	m_pParentMenuBar = DYNAMIC_DOWNCAST(CMFCRibbonPanelMenuBar, CWnd::FromHandlePermanent(lpCreateStruct->hwndParent));

	return 0;
}

CSize CRibbonTooltipCtrl::GetIconSize()
{
	CMFCToolBarImages* pBmp = ((CMainFrame*) GetTopLevelFrame())->GetTooltipImage(m_nID);
	if (pBmp != NULL)
	{
		ASSERT_VALID(pBmp);
		return pBmp->GetImageSize();
	}

	return CMFCToolTipCtrl::GetIconSize();
}

BOOL CRibbonTooltipCtrl::OnDrawIcon(CDC* pDC, CRect rectImage)
{
	ASSERT_VALID(pDC);

	CMFCToolBarImages* pBmp = ((CMainFrame*) GetTopLevelFrame())->GetTooltipImage(m_nID);
	if (pBmp != NULL)
	{
		ASSERT_VALID(pBmp);

		pBmp->SetTransparentColor(globalData.clrBtnFace);
		pBmp->DrawEx(pDC, rectImage, 0);

		return TRUE;

	}

	return CMFCToolTipCtrl::OnDrawIcon(pDC, rectImage);
}

