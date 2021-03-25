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
}

CInspector::~CInspector()
{
}

void CInspector::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
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

	GetDlgItem(IDC_STATIC)->DestroyWindow();

	//CCreateContext context;
	//ZeroMemory(&context, sizeof(context));

	//CRect rectOfPanelArea;

	//GetDlgItem(IDC_STATIC_RECT)->GetWindowRect(&rectOfPanelArea);
	//ScreenToClient(&rectOfPanelArea);

	//m_pForm1 = new CMyForm1();
	//m_pForm1->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_FORM_FORM1, &context);
	//m_pForm1->OnInitialUpdate();
	//m_pForm1->ShowWindow(SW_SHOW);

	//m_pForm2 = new CMyForm2();
	//m_pForm2->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_FORM_FORM2, &context);
	//m_pForm2->OnInitialUpdate();
	//m_pForm2->ShowWindow(SW_HIDE);

	//m_pForm3 = new CMyForm3();
	//m_pForm3->Create(NULL, NULL, WS_CHILD | WS_VSCROLL | WS_HSCROLL, rectOfPanelArea, this, IDD_FORM_FORM3, &context);
	//m_pForm3->OnInitialUpdate();
	//m_pForm3->ShowWindow(SW_HIDE);

}

void CInspector::ShowForm(int idx)
{
	//switch (idx)
	//{
	//case 0:
	//	m_pForm1->ShowWindow(SW_SHOW);
	//	m_pForm2->ShowWindow(SW_HIDE);
	//	m_pForm3->ShowWindow(SW_HIDE);
	//	break;
	//case 1:
	//	m_pForm1->ShowWindow(SW_HIDE);
	//	m_pForm2->ShowWindow(SW_SHOW);
	//	m_pForm3->ShowWindow(SW_HIDE);
	//	break;
	//case 2:
	//	m_pForm1->ShowWindow(SW_HIDE);
	//	m_pForm2->ShowWindow(SW_HIDE);
	//	m_pForm3->ShowWindow(SW_SHOW);
	//	break;
	//}
}

BEGIN_MESSAGE_MAP(CInspector, CFormView)
	
	ON_BN_CLICKED(IDC_BUTTON1, &CInspector::OnBnClickedMapView)
	ON_BN_CLICKED(IDC_BUTTON2, &CInspector::OnBnClickedMeshView)
	ON_BN_CLICKED(IDC_BUTTON3, &CInspector::OnBnClickedPhysicsView)
	ON_BN_CLICKED(IDC_BUTTON4, &CInspector::OnBnClickedEffectView)
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
