#pragma once



// CPhysicsView ?? ???Դϴ?.

class CPhysicsView : public CFormView
{
	DECLARE_DYNCREATE(CPhysicsView)

public:
	CPhysicsView();           
	virtual ~CPhysicsView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PHYSICSVIEW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ?????Դϴ?.

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
};


