
// ChildView.cpp : CChildView Ŭ������ ����
//

#include "stdafx.h"
#include "Drawing1.h"
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
	
	CRect rect;
	GetClientRect(&rect);

	dc.SetTextColor(RGB(255, 0, 0));
	dc.SetBkColor(RGB(255, 255, 0));
	dc.DrawText(CString("Dreams Come TRUE!"), &rect, 0);
	dc.DrawText(CString("���� �̷������."), &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	dc.SetTextAlign(TA_CENTER);
	dc.SetTextColor(RGB(0, 0, 255));
	dc.SetBkColor(RGB(0, 255, 0));
	dc.TextOutW(rect.right / 2, 3 * rect.bottom / 4, CString("���� �ִ� ���� ���� �ִ�."));
	// �׸��� �޽����� ���ؼ��� CWnd::OnPaint()�� ȣ������ ���ʽÿ�.
}
