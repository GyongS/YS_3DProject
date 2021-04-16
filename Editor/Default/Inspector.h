#pragma once
#include "afxwin.h"
#include "ButtonSkin.h"
#include "MapView.h"
#include "MeshView.h"
#include "PhysicsView.h"
#include "EffectView.h"
#include "afxbutton.h"

// CInspector �� ���Դϴ�.

class CInspector : public CFormView
{
	DECLARE_DYNCREATE(CInspector)

protected:
	CInspector();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
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
	CMeshView* m_pMeshView;
	CPhysicsView* m_pPhysicsView;
	CEffectView* m_pEffectView;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.


	void AllocForms();
	void ShowForm(int idx);
	void ChangeBtnColor();
	DECLARE_MESSAGE_MAP()
public:

public:
	CButtonSkin m_BtnSkin;
	virtual void OnInitialUpdate();

	afx_msg void OnBnClickedMapView();
	CMFCButton m_btn_MapView;
	afx_msg void OnBnClickedMeshView();
	CMFCButton m_btn_MeshView;
	afx_msg void OnBnClickedPhysicsView();
	CMFCButton m_btn_PhysicsView;
	afx_msg void OnBnClickedEffectView();
	CMFCButton m_btn_EffectView;
};


