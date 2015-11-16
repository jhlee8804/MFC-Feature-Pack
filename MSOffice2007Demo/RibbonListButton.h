// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

class CRibbonListButton : public CMFCRibbonGallery
{
	DECLARE_DYNCREATE(CRibbonListButton)

// Construction:
public:
	CRibbonListButton();
	CRibbonListButton(UINT nID, LPCTSTR lpszText, int nSmallImageIndex, int nLargeImageIndex, BOOL bRightAlignedText = TRUE);
	CRibbonListButton(UINT nID, LPCTSTR lpszText, int nSmallImageIndex, int nLargeImageIndex, UINT uiImagesPaletteResID,
		int cxPaletteImage, const CStringArray& arLabels, BOOL bRightAlignedText = TRUE);
	virtual ~CRibbonListButton();

public:
	void AddGroup(LPCTSTR lpszGroupName, UINT uiImagesPaletteResID, int cxPaletteImage, const CStringArray& arLabels);
	virtual void Clear();
	void SeRightAlignedText(BOOL bSet = TRUE);

protected:
	virtual CSize GetIconSize() const;
	virtual void OnDrawPaletteIcon(CDC* pDC, CRect rectIcon, int nIconIndex, CMFCRibbonGalleryIcon* pIcon, COLORREF clrText);
	virtual void CopyFrom(const CMFCRibbonBaseElement& src);
	virtual void OnShowPopupMenu();

	virtual BOOL IsItemMenuLook() const
	{
		return m_bRightAlignedText;
	}

	void RecalcTextSizes(CDC* pDC);

protected:
	CMFCToolBarImages m_listImages;
	CStringArray m_arLabels;
	CSize m_sizeMargins;
	BOOL m_bRightAlignedText;
	CSize m_sizeMaxText;
};

class CRibbonListFontButton : public CMFCRibbonGallery
{
	DECLARE_DYNCREATE(CRibbonListFontButton)

public:
	struct XItem
	{
		CString m_Caption;
		LOGFONT m_Font[2];
		int     m_Height;

		XItem()
		{
			ZeroMemory(&m_Font[0], sizeof(LOGFONT));
			ZeroMemory(&m_Font[1], sizeof(LOGFONT));

			m_Font[0].lfHeight         = -14;
			m_Font[0].lfWeight         = FW_BOLD;
			m_Font[0].lfCharSet        = DEFAULT_CHARSET;
			m_Font[0].lfOutPrecision   = OUT_DEFAULT_PRECIS;
			m_Font[0].lfClipPrecision  = CLIP_DEFAULT_PRECIS;
			m_Font[0].lfQuality        = DEFAULT_QUALITY;
			m_Font[0].lfPitchAndFamily = DEFAULT_PITCH;

			m_Font[1].lfHeight         = -12;
			m_Font[1].lfWeight         = FW_NORMAL;
			m_Font[1].lfCharSet        = DEFAULT_CHARSET;
			m_Font[1].lfOutPrecision   = OUT_DEFAULT_PRECIS;
			m_Font[1].lfClipPrecision  = CLIP_DEFAULT_PRECIS;
			m_Font[1].lfQuality        = DEFAULT_QUALITY;
			m_Font[1].lfPitchAndFamily = DEFAULT_PITCH;

			m_Height = 0;
		}

		XItem& operator = (const XItem& rItem)
		{
			m_Caption = rItem.m_Caption;
			memcpy(&m_Font[0], &rItem.m_Font[0], sizeof(LOGFONT));
			memcpy(&m_Font[1], &rItem.m_Font[1], sizeof(LOGFONT));
			m_Height = rItem.m_Height;

			return *this;
		}
	};

	typedef CArray<XItem, XItem&> XItems;

// Construction:
public:
	CRibbonListFontButton();
	CRibbonListFontButton(UINT nID, LPCTSTR lpszText, int nSmallImageIndex, int nLargeImageIndex);
	CRibbonListFontButton(UINT nID, LPCTSTR lpszText, int nSmallImageIndex, int nLargeImageIndex, UINT uiImagesPaletteResID, int cxPaletteImage, const XItems& arItems);
	virtual ~CRibbonListFontButton();

public:
	void AddGroup(LPCTSTR lpszGroupName, UINT uiImagesPaletteResID, int cxPaletteImage, const XItems& arItems);
	virtual void Clear();

protected:
	virtual CSize GetIconSize() const;
	virtual void OnDrawPaletteIcon(CDC* pDC, CRect rectIcon, int nIconIndex, CMFCRibbonGalleryIcon* pIcon, COLORREF clrText);
	virtual void CopyFrom(const CMFCRibbonBaseElement& src);
	virtual void OnShowPopupMenu();

	void RecalcTextSizes(CDC* pDC);

protected:
	CMFCToolBarImages m_listImages;
	XItems m_arItems;
	CSize m_sizeMargins;
	CSize m_sizeMaxText;
};

