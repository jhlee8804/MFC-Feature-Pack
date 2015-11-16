// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

class CRibbonTableButton : public CMFCRibbonGallery
{
	DECLARE_DYNCREATE(CRibbonTableButton)

// Construction:
public:
	CRibbonTableButton() {}
	CRibbonTableButton(UINT nID, LPCTSTR lpszText, int nSmallImageIndex, int nLargeImageIndex);

	virtual ~CRibbonTableButton();

// Attributes:
public:
	static int GetRows() { return m_nRows; }
	static int GetColumns() { return m_nColumns; }

protected:
	static int m_nRows;
	static int m_nColumns;

// Overrides:
protected:
	virtual void OnDrawPaletteIcon(CDC* pDC, CRect rectIcon, int nIconIndex, CMFCRibbonGalleryIcon* pIcon, COLORREF clrText);
	virtual void NotifyHighlightListItem(int nIndex);
	virtual void OnShowPopupMenu();
};

