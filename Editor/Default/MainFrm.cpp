
// MainFrm.cpp : CMainFrame 클래스의 구현
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
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 생성/소멸

CMainFrame::CMainFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
	
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
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return TRUE;
}

// CMainFrame 진단

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


// CMainFrame 메시지 처리기



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

    SetWindowPos(nullptr,//순서를 바꿔서 생성하지 않겠다. nullptr을 넣어주게 되면. 
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
