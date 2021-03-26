#pragma once



// CEffectView 폼 뷰입니다.

class CEffectView : public CFormView
{
	DECLARE_DYNCREATE(CEffectView)

public:
	CEffectView();          
	virtual ~CEffectView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EFFECTVIEW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
};


