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
#include "ResourcePage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CResourcePage property page

IMPLEMENT_DYNCREATE(CResourcePage, CMFCPropertyPage)

CResourcePage::CResourcePage() : CMFCPropertyPage(CResourcePage::IDD)
{
}

CResourcePage::~CResourcePage()
{
}

void CResourcePage::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CResourcePage, CMFCPropertyPage)
	//{{AFX_MSG_MAP(CResourcePage)
	ON_BN_CLICKED(IDC_HOME, OnHome)
	ON_BN_CLICKED(IDC_CONTACT, OnContact)
	ON_BN_CLICKED(IDC_PRODUCT, OnProduct)
	ON_BN_CLICKED(IDC_SUPPORT, OnSupport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CResourcePage message handlers

void CResourcePage::OnHome()
{
	::ShellExecute(NULL, NULL, _T("http://www.microsoft.com"), NULL, NULL, NULL);
}

void CResourcePage::OnContact()
{
	::ShellExecute(NULL, NULL, _T("http://www.microsoft.com"), NULL, NULL, NULL);
}

void CResourcePage::OnProduct()
{
	::ShellExecute(NULL, NULL, _T("http://www.microsoft.com"), NULL, NULL, NULL);
}

void CResourcePage::OnSupport()
{
	::ShellExecute(NULL, NULL, _T("http://www.microsoft.com"), NULL, NULL, NULL);
}

