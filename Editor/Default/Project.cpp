// Project.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Editor.h"
#include "Project.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CProject

IMPLEMENT_DYNCREATE(CProject, CFormView)

CProject::CProject()
	: CFormView(IDD_PROJECT)
{

}

CProject::~CProject()
{
}

void CProject::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CProject, CFormView)
END_MESSAGE_MAP()


// CProject �����Դϴ�.

#ifdef _DEBUG
void CProject::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CProject::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CProject �޽��� ó�����Դϴ�.
