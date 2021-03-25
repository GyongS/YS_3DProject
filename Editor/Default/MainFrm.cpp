
// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "Editor.h"

#include "MainFrm.h"
#include "EditorView.h"
#include "Inspector.h"
#include "Hierarchy.h"
#include "Project.h"
#include "ShaderView.h"
#include "ObjectListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;	

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return TRUE;
}

// CMainFrame ����

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame �޽��� ó����



BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

	RECT rcMainRect = {};
	GetWindowRect(&rcMainRect);

	::SetRect(&rcMainRect, 0, 0, rcMainRect.right - rcMainRect.left, rcMainRect.bottom - rcMainRect.top);

	RECT rcView = {};
	GetClientRect(&rcView);
	int iGapX = rcMainRect.right - rcView.left;
	int iGapY = rcMainRect.bottom - rcView.top;

    SetWindowPos(nullptr,//������ �ٲ㼭 �������� �ʰڴ�. nullptr�� �־��ְ� �Ǹ�. 
		0, 0, VIEWCX + 850, VIEWCY , SWP_NOZORDER | SWP_NOMOVE);

	/*	
	0, 0 | 0, 1 | 0, 2
	1, 0 | 1, 1 | 1, 2

	*/

	m_mainSplitter.CreateStatic(this, 1, 2);
	m_mainSplitter.CreateView(0, 0, RUNTIME_CLASS(CEditorView), CSize(VIEWCX, VIEWCY), pContext);

	m_FirstSplitter.CreateStatic(&m_mainSplitter, 1, 2, WS_VISIBLE | WS_CHILD, m_mainSplitter.IdFromRowCol(0, 1));
	m_FirstSplitter.CreateView(0, 0, RUNTIME_CLASS(CHierarchy), CSize(400, 300), pContext);
	m_FirstSplitter.CreateView(0, 1, RUNTIME_CLASS(CInspector), CSize(400, 300), pContext);
	m_FirstSplitter.SetColumnInfo(1, 300, 10);





	return TRUE;
}
