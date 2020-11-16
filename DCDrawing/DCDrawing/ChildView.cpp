
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "DCDrawing.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	CBrush Brush1(RGB(0, 0, 0)); //HS_CROSS 외 다른 스타일은 f12 로 확인해보자
	CBrush* pOldBrush = dc.SelectObject(&Brush1);

	dc.Rectangle(100, 100, 200, 200);

	dc.SelectObject(pOldBrush);

	CRect Rect;
	GetClientRect(&Rect);
	dc.Rectangle(&Rect);

	dc.SelectObject(pOldBrush);
	
	

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}