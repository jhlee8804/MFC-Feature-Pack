// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

#include "TaskPane.h"
#include "RibbonListButton.h"

class CMainFrame : public CFrameWndEx
{
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	CMFCRibbonBar* GetRibbonBar()
	{
		return &m_wndRibbonBar;
	}

// Operations
public:
	CMFCToolBarImages* GetTooltipImage(UINT uiID);

	void SetRibbonContextCategory(UINT uiCategoryID);
	void ActivateRibbonContextCategory(UINT uiCategoryID);

	void OnChangeLayout(CWnd* pWnd = NULL, BOOL bNoLoopOverPopup = FALSE);

protected:
	void AddMainCategory();

	void AddTab_Home();
	void AddTab_Insert();
	void AddTab_PageLayout();
	void AddTab_References();
	void AddTab_Mailings();
	void AddTab_Review();
	void AddTab_View();
	void AddTab_Developer();

	void AddContextTab_Picture();
	void AddContextTab_Chart();
	void AddContextTab_Table();

	CMFCRibbonPanel* AddPanelArrange(CMFCRibbonCategory* pCategory, UINT imageP, UINT imageS, UINT imageL);

	void InitBulletPalette(CMFCRibbonGallery* pPalette);
	void InitNumberingPalette(CMFCRibbonGallery* pPalette);
	void InitMultilevelPalette(CMFCRibbonGallery* pPalette);
	void InitPositionPalette(CMFCRibbonGallery* pPalette);

	void SetKeys();

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	virtual void AdjustClientArea();
	virtual BOOL OnShowPopupMenu(CMFCPopupMenu* pMenuPopup);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CMFCRibbonBar m_wndRibbonBar; // Ribbon control bar
	CMFCRibbonApplicationButton m_MainButton; // Ribbon main button
	CTaskPane m_wndTaskPane;
	CMFCRibbonStatusBar m_wndStatusBar;
	CMFCCaptionBar m_wndMessageBar;

	CMFCToolBarImages m_PanelImages; // Ribbon panel images (appear when pane is collapsed)

	CMap<UINT,UINT,CMFCToolBarImages*,CMFCToolBarImages*> m_TooltipImages;

	void CreateDocumentColors();
	void CreateStyleList();
	void CreateThemeList();
	void CreateFontsList();

	void ShowProgress(BOOL bShow = TRUE);

protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnWriteClipboard();
	afx_msg void OnUpdateWriteClipboard(CCmdUI* pCmdUI);
	afx_msg void OnViewRtl();
	afx_msg void OnUpdateViewRtl(CCmdUI* pCmdUI);
	afx_msg void OnRefresh();
	afx_msg void OnSpell();
	afx_msg void OnUpdateRefresh(CCmdUI* pCmdUI);
	afx_msg void OnAppLook(UINT id);
	afx_msg void OnUpdateAppLook(CCmdUI* pCmdUI);
	afx_msg void OnToolsOptions();
	afx_msg LRESULT OnRibbonCustomize(WPARAM wp, LPARAM lp);
	afx_msg void OnLink();
	afx_msg LRESULT OnHighlightRibbonListItem(WPARAM wp, LPARAM lp);
	afx_msg void OnViewMessageBar();
	afx_msg void OnUpdateViewMessageBar(CCmdUI* pCmdUI);
	afx_msg LRESULT OnShowRibbonItemMenu(WPARAM wp, LPARAM lp);
	afx_msg void OnDummy(UINT id);
	afx_msg void OnZoomSlider();
	afx_msg void OnZoom();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

	BOOL CreateRibbonBar();
	BOOL CreateStatusBar();
	BOOL CreateMessageBar();

	void ShowOptions(int nPage);

	CMFCControlRenderer m_Pat[4];

	CRect m_rectFill;
	CBitmap m_MemBitmap;
	CRect m_rectSizing;

	int m_nProgressValue;
	BOOL m_bInfiniteProgressMode;

	// Document colors for demo:
	CList<COLORREF,COLORREF> m_lstMainColors;
	CList<COLORREF,COLORREF> m_lstAdditionalColors;
	CList<COLORREF,COLORREF> m_lstStandardColors;

	// Theme names for demo:
	CStringArray m_arStyles;
	CStringArray m_arThemes;
	CStringArray m_arColorThemes;
	CStringArray m_arStyleSets;
	CRibbonListFontButton::XItems m_arFonts;
};


