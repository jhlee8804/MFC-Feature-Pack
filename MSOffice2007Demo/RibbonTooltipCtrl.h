// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CRibbonTooltipCtrl window

class CRibbonTooltipCtrl : public CMFCToolTipCtrl
{
	DECLARE_DYNCREATE(CRibbonTooltipCtrl)

// Construction
public:
	CRibbonTooltipCtrl();

// Attributes
protected:
	CMFCRibbonPanelMenuBar* m_pParentMenuBar;
	CMFCRibbonBar* m_pParentRibbon;
	UINT m_nID;

// Overrides
public:
	virtual CSize GetIconSize();
	virtual BOOL OnDrawIcon(CDC* pDC, CRect rectImage);

	// Implementation
public:
	virtual ~CRibbonTooltipCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRibbonTooltipCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnShow(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

