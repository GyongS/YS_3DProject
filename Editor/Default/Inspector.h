#pragma once
#include "afxwin.h"
#include "ButtonSkin.h"
#include "MapView.h"

// CInspector 폼 뷰입니다.

class CInspector : public CFormView
{
	DECLARE_DYNCREATE(CInspector)

protected:
	CInspector();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CInspector();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSPECTOR };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
	
#endif
#endif

private:
	CMapView* m_pMapView;


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.


	void AllocForms();
	void ShowForm(int idx);

	DECLARE_MESSAGE_MAP()
public:

public:
	CButtonSkin m_BtnSkin;


	afx_msg void OnBnClickedMapView();
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedMeshView();
	afx_msg void OnBnClickedPhysicsView();
	afx_msg void OnBnClickedEffectView();
};


