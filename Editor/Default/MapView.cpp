// MapView.cpp : 구현 파일입니다.
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


// CMapView 진단입니다.

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


// CMapView 메시지 처리기입니다.


BOOL CMapView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


void CMapView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	ChangeBtnColor();
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}




void CMapView::OnBnClickedReset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


