// PhysicsView.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Editor.h"
#include "PhysicsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CPhysicsView

IMPLEMENT_DYNCREATE(CPhysicsView, CFormView)

CPhysicsView::CPhysicsView()
	: CFormView(IDD_PHYSICSVIEW)
{

}

CPhysicsView::~CPhysicsView()
{
}

void CPhysicsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPhysicsView, CFormView)
END_MESSAGE_MAP()


// CPhysicsView 진단입니다.

#ifdef _DEBUG
void CPhysicsView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CPhysicsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPhysicsView 메시지 처리기입니다.


void CPhysicsView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}


BOOL CPhysicsView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
