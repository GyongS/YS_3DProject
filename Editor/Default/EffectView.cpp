// EffectView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Editor.h"
#include "EffectView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CEffectView

IMPLEMENT_DYNCREATE(CEffectView, CFormView)

CEffectView::CEffectView()
	: CFormView(IDD_EFFECTVIEW)
{

}

CEffectView::~CEffectView()
{
}

void CEffectView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CEffectView, CFormView)
END_MESSAGE_MAP()


// CEffectView �����Դϴ�.

#ifdef _DEBUG
void CEffectView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CEffectView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CEffectView �޽��� ó�����Դϴ�.


void CEffectView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}


BOOL CEffectView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return CFormView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
