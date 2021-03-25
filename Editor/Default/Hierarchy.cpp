// Hierarchy.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Editor.h"
#include "Hierarchy.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CHierarchy

IMPLEMENT_DYNCREATE(CHierarchy, CFormView)

CHierarchy::CHierarchy()
	: CFormView(IDD_HIERARCHY)
{

}

CHierarchy::~CHierarchy()
{
}

void CHierarchy::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHierarchy, CFormView)
END_MESSAGE_MAP()


// CHierarchy 진단입니다.

#ifdef _DEBUG
void CHierarchy::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CHierarchy::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CHierarchy 메시지 처리기입니다.
