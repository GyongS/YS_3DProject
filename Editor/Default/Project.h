#pragma once



// CProject 폼 뷰입니다.

class CProject : public CFormView
{
	DECLARE_DYNCREATE(CProject)

protected:
	CProject();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CProject();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECT };
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
};


