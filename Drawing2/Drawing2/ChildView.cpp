
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "Drawing2.h"
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



// CChildView �޽��� ó����

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
	CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.
	
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	CPen blackpen(PS_SOLID, 1, RGB(0, 0, 0));

	dc.SelectObject(&blackpen);
	dc.Rectangle(100, 100, 200, 200);
	CPen pen1(PS_SOLID, 20, RGB(0, 255, 0));
	dc.SelectObject(&pen1);
	dc.Ellipse(100, 100, 200, 200);

	dc.SelectObject(&blackpen);
	dc.Rectangle(300, 100, 400, 200);
	CPen pen2(PS_SOLID, 20, RGB(0, 255, 0));
	dc.SelectObject(&pen2);
	dc.Ellipse(300, 100, 00, 200);
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}

