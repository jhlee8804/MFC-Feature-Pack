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
// CResourcePage dialog

class CResourcePage : public CMFCPropertyPage
{
	DECLARE_DYNCREATE(CResourcePage)

// Construction
public:
	CResourcePage();
	~CResourcePage();

// Dialog Data
	//{{AFX_DATA(CResourcePage)
	enum { IDD = IDD_RES_PAGE };
	//}}AFX_DATA

// Overrides
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	//{{AFX_MSG(CResourcePage)
	afx_msg void OnHome();
	afx_msg void OnContact();
	afx_msg void OnProduct();
	afx_msg void OnSupport();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

