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
#include "RibbonTableButton.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define CELLS_X 10
#define CELLS_Y 8

IMPLEMENT_DYNCREATE(CRibbonTableButton, CMFCRibbonGallery)

int CRibbonTableButton::m_nRows = 0;
int CRibbonTableButton::m_nColumns = 0;

LPCTSTR lpszDefaultCaption = _T("Insert Table");

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRibbonTableButton::CRibbonTableButton(UINT nID, LPCTSTR lpszText, int nSmallImageIndex, int nLargeImageIndex) :
	CMFCRibbonGallery(nID, lpszText, nSmallImageIndex, nLargeImageIndex, CSize(18, 18), 0, FALSE)
{
	AddGroup(lpszDefaultCaption, CELLS_X * CELLS_Y);
	SetIconsInRow(CELLS_X);
}

CRibbonTableButton::~CRibbonTableButton()
{
}

void CRibbonTableButton::OnDrawPaletteIcon(CDC* pDC, CRect rectIcon, int nIconIndex, CMFCRibbonGalleryIcon* /*pIcon*/, COLORREF /*clrText*/)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	rectIcon.DeflateRect(2, 2);

	COLORREF color = globalData.clrWindowText;

	if (nIconIndex / CELLS_X + 1 <= m_nRows && (nIconIndex % CELLS_X) + 1 <= m_nColumns)
	{
		COLORREF clrInner = RGB(255, 226, 148);

		pDC->Draw3dRect(rectIcon, clrInner, clrInner);

		color = RGB(239, 72, 16);
		rectIcon.InflateRect(1, 1);
	}

	pDC->Draw3dRect(rectIcon, color, color);
}

void CRibbonTableButton::NotifyHighlightListItem(int nIndex)
{
	ASSERT_VALID(this);

	if (m_pPopupMenu != NULL)
	{
		if (nIndex < 0)
		{
			m_nRows = m_nColumns = 0;
		}
		else
		{
			m_nRows = nIndex / CELLS_X + 1;
			m_nColumns = (nIndex % CELLS_X) + 1;
		}

		CString strCaption = lpszDefaultCaption;
		if (m_nColumns > 0 && m_nRows > 0)
		{
			strCaption.Format(_T("%dx%d Table"), m_nColumns, m_nRows);
		}

		SetGroupName(0, strCaption);
		RedrawIcons();
	}

	CMFCRibbonGallery::NotifyHighlightListItem(nIndex);
}

void CRibbonTableButton::OnShowPopupMenu()
{
	ASSERT_VALID(this);

	m_nRows = m_nColumns = 0;
	SetGroupName(0, lpszDefaultCaption);

	CMFCRibbonGallery::OnShowPopupMenu();
}

