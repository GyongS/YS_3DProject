// PhysicsView.cpp : ���� �����Դϴ�.
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


// CPhysicsView �����Դϴ�.

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


// CPhysicsView �޽��� ó�����Դϴ�.


void CPhysicsView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}


BOOL CPhysicsView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
