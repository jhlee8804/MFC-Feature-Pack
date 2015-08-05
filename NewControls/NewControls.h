// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h" // main symbols

/////////////////////////////////////////////////////////////////////////////
// CNewControlsApp:
// See NewControls.cpp for the implementation of this class
//

class CNewControlsApp : public CWinAppEx
{
public:
	CNewControlsApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	DECLARE_MESSAGE_MAP()
};

extern CNewControlsApp theApp;
