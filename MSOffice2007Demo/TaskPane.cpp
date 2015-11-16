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
#include "TaskPane.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTaskPane

BEGIN_MESSAGE_MAP(CTaskPane, CMFCTasksPane)
	//{{AFX_MSG_MAP(CTaskPane)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTaskPane construction/destruction

CTaskPane::CTaskPane()
{
}

CTaskPane::~CTaskPane()
{
}

/////////////////////////////////////////////////////////////////////////////
// CTaskPane message handlers

int CTaskPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	SetWindowText(_T("Clipboard"));

	if (CMFCTasksPane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// Create tasks pane windows.
	// TODO: create your own tasks panes here:

	return 0;
}

