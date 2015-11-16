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

#include "MSOffice2007DemoDoc.h"
#include "MSOffice2007DemoView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMSOffice2007DemoCntrItem implementation

IMPLEMENT_SERIAL(CMSOffice2007DemoCntrItem, CRichEditCntrItem, 0)

CMSOffice2007DemoCntrItem::CMSOffice2007DemoCntrItem(REOBJECT* preo, CMSOffice2007DemoDoc* pContainer) :
	CRichEditCntrItem(preo, pContainer)
{
	m_uiCategoryID = 0;
}

CMSOffice2007DemoCntrItem::~CMSOffice2007DemoCntrItem()
{
	// TODO: add cleanup code here
}

BOOL CMSOffice2007DemoCntrItem::OnShowPanes(CFrameWnd* pFrameWnd, BOOL bShow)
{
	CMDIFrameWndEx* pMainFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, pFrameWnd);
	if (pMainFrame != NULL)
	{
		return pMainFrame->OnShowPanes(bShow);
	}
	else // Maybe, SDI frame...
	{
		CFrameWndEx* pFrame = DYNAMIC_DOWNCAST(CFrameWndEx, pFrameWnd);
		if (pFrame != NULL)
		{
			return pFrame->OnShowPanes(bShow);
		}
	}

	return FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CMSOffice2007DemoCntrItem diagnostics

#ifdef _DEBUG
void CMSOffice2007DemoCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CMSOffice2007DemoCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////


