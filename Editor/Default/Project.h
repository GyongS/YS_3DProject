#pragma once



// CProject �� ���Դϴ�.

class CProject : public CFormView
{
	DECLARE_DYNCREATE(CProject)

protected:
	CProject();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};


