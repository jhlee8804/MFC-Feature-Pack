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
// CDlgBanner window

class CDlgBanner : public CStatic
{
// Construction
public:
	CDlgBanner();

// Implementation
public:
	virtual ~CDlgBanner();

// Generated message map functions
protected:
	//{{AFX_MSG(CDlgBanner)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};
