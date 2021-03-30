// MapView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Editor.h"
#include "MapView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CMapView

IMPLEMENT_DYNCREATE(CMapView, CFormView)

CMapView::CMapView()
	: CFormView(IDD_MAPVIEW)
{

}

CMapView::~CMapView()
{
}

void CMapView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCBUTTON1, m_btn_Reset);
}

void CMapView::ChangeBtnColor()
{
	m_btn_Reset.SetTextColor(RGB(255, 255, 255));
	m_btn_Reset.SetFaceColor(RGB(64, 64, 64));
}

BEGIN_MESSAGE_MAP(CMapView, CFormView)
	ON_BN_CLICKED(IDC_MFCBUTTON1, &CMapView::OnBnClickedReset)
END_MESSAGE_MAP()


// CMapView �����Դϴ�.

#ifdef _DEBUG
void CMapView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CMapView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMapView �޽��� ó�����Դϴ�.


BOOL CMapView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void CMapView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	ChangeBtnColor();
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}




void CMapView::OnBnClickedReset()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


