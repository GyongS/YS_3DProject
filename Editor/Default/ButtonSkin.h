#pragma once
class CButtonSkin : public CButton
{
public:
	CButtonSkin();
	~CButtonSkin();

public:
	void SetColorBackGround(_uint a, _uint r, _uint g, _uint b);
	void SetColorBorder(_uint a, _uint r, _uint g, _uint b);
	void SetColorText(_uint a, _uint r, _uint g, _uint b);
	void SetTextSize(_float size);

private:
	Gdiplus::Color m_clrBackGround; // 배경 색상
	Gdiplus::Color m_clrBorder;     // 테두리 색상
	Gdiplus::Color m_clrText;       // 텍스트 색상
	_float m_fTextSize;
	CString m_strText;

	void DrawingBackGround(Gdiplus::Graphics* pG);
	void DrawingBorder(Gdiplus::Graphics* pG);
	void DrawingText(Gdiplus::Graphics* pG);

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

