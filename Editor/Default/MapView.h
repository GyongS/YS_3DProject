#pragma once



// CMapView �� ���Դϴ�.

class CMapView : public CFormView
{
	DECLARE_DYNCREATE(CMapView)

public:
	CMapView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CMapView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAPVIEW };
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
public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();
};


