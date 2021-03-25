#include "stdafx.h"
#include "ButtonSkin.h"

CButtonSkin::CButtonSkin()
{
	m_clrBackGround = Gdiplus::Color(255, 64, 64, 64);
	m_clrBorder = Gdiplus::Color(255, 128, 128, 128);
	m_clrText = Gdiplus::Color(255, 255, 255, 255);
	m_strText = _T("Button");
	m_fTextSize = 15;
}


CButtonSkin::~CButtonSkin()
{
}

void CButtonSkin::SetColorBackGround(_uint a, _uint r, _uint g, _uint b)
{
	m_clrBackGround = Gdiplus::Color(a, r, g, b);
}

void CButtonSkin::SetColorBorder(_uint a, _uint r, _uint g, _uint b)
{
	m_clrBorder = Gdiplus::Color(a, r, g, b);

}

void CButtonSkin::SetColorText(_uint a, _uint r, _uint g, _uint b)
{
	m_clrText = Gdiplus::Color(a, r, g, b);
}

void CButtonSkin::SetTextSize(_float size)
{
	m_fTextSize = size;
}

void CButtonSkin::DrawingBackGround(Gdiplus::Graphics * pG)
{
	CRect rc;
	GetClientRect(&rc);

	Gdiplus::SolidBrush br(m_clrBackGround);

	pG->FillRectangle(&br, rc.left, rc.top, rc.right, rc.bottom);
}

void CButtonSkin::DrawingBorder(Gdiplus::Graphics * pG)
{
	CRect rc;
	GetClientRect(&rc);
	Gdiplus::Pen pen(m_clrBorder, 1);
	pG->DrawRectangle(&pen, rc.left, rc.top, rc.Width(), rc.Height());
}

void CButtonSkin::DrawingText(Gdiplus::Graphics * pG)
{


	CRect rc;
	GetClientRect(&rc);

	Gdiplus::FontFamily fontfam(_T("Arial"));
	Gdiplus::Font font(&fontfam, m_fTextSize, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);

	Gdiplus::StringFormat strAlign;
	strAlign.SetAlignment(Gdiplus::StringAlignmentCenter);
	strAlign.SetLineAlignment(Gdiplus::StringAlignmentCenter);

	Gdiplus::SolidBrush br(m_clrText);

	pG->DrawString(m_strText,
		m_strText.GetLength(),
		&font, 
		Gdiplus::RectF((_float)rc.left,	(_float)rc.top, (_float)rc.Width(), (_float)rc.Height()),
		&strAlign,
		&br);


}
BEGIN_MESSAGE_MAP(CButtonSkin, CButton)
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CButtonSkin::OnPaint()
{
	CPaintDC dc(this);					   

	CRect rect;
	GetClientRect(&rect);

	
	Gdiplus::Graphics mainG(dc.GetSafeHdc());

	Gdiplus::Bitmap bmp(rect.Width(), rect.Height());

	Gdiplus::Graphics memG(&bmp);

	Gdiplus::SolidBrush brush(m_clrBackGround);
	memG.FillRectangle(&brush, 0, 0, rect.Width(), rect.Height());

	DrawingBackGround(&memG);
	DrawingBorder(&memG);
	DrawingText(&memG);

	mainG.DrawImage(&bmp, 0, 0);
}
