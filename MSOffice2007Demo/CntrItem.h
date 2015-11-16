// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

class CMSOffice2007DemoDoc;
class CMSOffice2007DemoView;

class CMSOffice2007DemoCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(CMSOffice2007DemoCntrItem)

// Constructors
public:
	CMSOffice2007DemoCntrItem(REOBJECT* preo = NULL, CMSOffice2007DemoDoc* pContainer = NULL);
	// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
	//  IMPLEMENT_SERIALIZE requires the class have a constructor with
	//  zero arguments.  Normally, OLE items are constructed with a
	//  non-NULL document pointer.

// Attributes
public:
	CMSOffice2007DemoDoc* GetDocument() { return(CMSOffice2007DemoDoc*)CRichEditCntrItem::GetDocument(); }
	CMSOffice2007DemoView* GetActiveView() { return(CMSOffice2007DemoView*)CRichEditCntrItem::GetActiveView(); }

protected:
	virtual BOOL OnShowPanes(CFrameWnd* pFrameWnd, BOOL bShow);

// Implementation
public:
	~CMSOffice2007DemoCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	UINT m_uiCategoryID;
};

