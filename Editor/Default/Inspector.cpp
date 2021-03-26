// Inspector.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Editor.h"
#include "Inspector.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CInspector

IMPLEMENT_DYNCREATE(CInspector, CFormView)

CInspector::CInspector()
	: CFormView(IDD_INSPECTOR)
{
	m_pMapView = nullptr;
	m_pMeshView = nullptr;
	m_pPhysicsView = nullptr;
	m_pEffectView = nullptr;
}

CInspector::~CInspector()
{

}

void CInspector::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON1, m_btn_MapView);
	DDX_Control(pDX, IDC_MFCBUTTON2, m_btn_MeshView);
	DDX_Control(pDX, IDC_MFCBUTTON3, m_btn_PhysicsView);
	DDX_Control(pDX, IDC_MFCBUTTON4, m_btn_EffectView);
}

void CInspector::AllocForms()
{
	CCreateContext context;
	ZeroMemory(&context, sizeof(context));

	CRect rectOfPanelArea;

	GetDlgItem(IDC_STATIC)->GetWindowRect(&rectOfPanelArea);
	ScreenToClient(&rectOfPanelArea);

	m_pMapView = new CMapView();
	m_pMapView->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_MAPVIEW, &context);
	m_pMapView->OnInitialUpdate();
	m_pMapView->ShowWindow(SW_SHOW);

	m_pMeshView = new CMeshView();
	m_pMeshView->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_MAPVIEW, &context);
	m_pMeshView->OnInitialUpdate();
	m_pMeshView->ShowWindow(SW_HIDE);

	m_pPhysicsView = new CPhysicsView();
	m_pPhysicsView->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_MAPVIEW, &context);
	m_pPhysicsView->OnInitialUpdate();
	m_pPhysicsView->ShowWindow(SW_HIDE);

	m_pEffectView = new CEffectView();
	m_pEffectView->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_MAPVIEW, &context);
	m_pEffectView->OnInitialUpdate();
	m_pEffectView->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_STATIC)->DestroyWindow();
}

void CInspector::ShowForm(int idx)
{
	switch (idx)
	{
	case 0:
		m_pMapView->ShowWindow(SW_SHOW);
		m_pMeshView->ShowWindow(SW_HIDE);
		m_pPhysicsView->ShowWindow(SW_HIDE);
		m_pEffectView->ShowWindow(SW_HIDE);
		break;
	case 1:
		m_pMapView->ShowWindow(SW_HIDE);
		m_pMeshView->ShowWindow(SW_SHOW);
		m_pPhysicsView->ShowWindow(SW_HIDE);
		m_pEffectView->ShowWindow(SW_HIDE);
		break;
	case 2:
		m_pMapView->ShowWindow(SW_HIDE);
		m_pMeshView->ShowWindow(SW_HIDE);
		m_pPhysicsView->ShowWindow(SW_SHOW);
		m_pEffectView->ShowWindow(SW_HIDE);
		break;
	case 3:
		m_pMapView->ShowWindow(SW_HIDE);
		m_pMeshView->ShowWindow(SW_HIDE);
		m_pPhysicsView->ShowWindow(SW_HIDE);
		m_pEffectView->ShowWindow(SW_SHOW);
		break;
	}
}

void CInspector::ChangeBtnColor()
{
	m_btn_MapView.EnableWindowsTheming(FALSE);
	m_btn_MapView.SetTextColor(RGB(255, 255, 255));
	m_btn_MapView.SetFaceColor(RGB(64, 64, 64));

	m_btn_MeshView.EnableWindowsTheming(FALSE);
	m_btn_MeshView.SetTextColor(RGB(255, 255, 255));
	m_btn_MeshView.SetFaceColor(RGB(64, 64, 64));

	m_btn_PhysicsView.EnableWindowsTheming(FALSE);
	m_btn_PhysicsView.SetTextColor(RGB(255, 255, 255));
	m_btn_PhysicsView.SetFaceColor(RGB(64, 64, 64));

	m_btn_EffectView.EnableWindowsTheming(FALSE);
	m_btn_EffectView.SetTextColor(RGB(255, 255, 255));
	m_btn_EffectView.SetFaceColor(RGB(64, 64, 64));
}

BEGIN_MESSAGE_MAP(CInspector, CFormView)

	ON_BN_CLICKED(IDC_MFCBUTTON1, &CInspector::OnBnClickedMapView)
	ON_BN_CLICKED(IDC_MFCBUTTON2, &CInspector::OnBnClickedMeshView)
	ON_BN_CLICKED(IDC_MFCBUTTON3, &CInspector::OnBnClickedPhysicsView)
	ON_BN_CLICKED(IDC_MFCBUTTON4, &CInspector::OnBnClickedEffectView)
END_MESSAGE_MAP()


// CInspector 진단입니다.

#ifdef _DEBUG
void CInspector::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CInspector::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG



// CInspector 메시지 처리기입니다.
void CInspector::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();	

	ChangeBtnColor();

	AllocForms();
}



void CInspector::OnBnClickedMapView()
{
	ShowForm(0);
}


void CInspector::OnBnClickedMeshView()
{
	ShowForm(1);
}


void CInspector::OnBnClickedPhysicsView()
{
	ShowForm(2);
}


void CInspector::OnBnClickedEffectView()
{
	ShowForm(3);
}
