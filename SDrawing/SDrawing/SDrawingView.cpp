
// SDrawingView.cpp : CSDrawingView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "SDrawing.h"
#endif

#include "SDrawingDoc.h"
#include "SDrawingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDrawingView

IMPLEMENT_DYNCREATE(CSDrawingView, CView)

BEGIN_MESSAGE_MAP(CSDrawingView, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CSDrawingView ����/�Ҹ�

CSDrawingView::CSDrawingView()
	: m_ptX(0)
	, m_ptY(0)
	, m_crColor(0)
	,m_reRect(100,100,300,300)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	m_crColor = BLACK_BRUSH;
}

CSDrawingView::~CSDrawingView()
{
}

BOOL CSDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CSDrawingView �׸���

void CSDrawingView::OnDraw(CDC* pDC)
{
	CSDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	pDC->TextOutW(150, 50, _T("Hello, MFC 2017 !"));
	pDC->SelectStockObject(m_crColor);
	pDC->Rectangle(m_reRect);
}


// CSDrawingView ����

#ifdef _DEBUG
void CSDrawingView::AssertValid() const
{
	CView::AssertValid();
}

void CSDrawingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDrawingDoc* CSDrawingView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDrawingDoc)));
	return (CSDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDrawingView �޽��� ó����


void CSDrawingView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nFlags & MK_LBUTTON)
	{
		CClientDC dc(this);

		dc.MoveTo(m_ptX, m_ptY);
		dc.LineTo(point.x, point.y);

		m_ptX = point.x;
		m_ptY = point.y;
	}

	CView::OnMouseMove(nFlags, point);
}


void CSDrawingView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_ptX = point.x;
	m_ptY = point.y;

	if (m_reRect.PtInRect(point))
	{
		if (m_crColor == BLACK_BRUSH)
		{
			m_crColor = WHITE_BRUSH;
		}
		else
		{
			m_crColor = GRAY_BRUSH;
		}
		InvalidateRect(m_reRect);
	}
	
	CView::OnLButtonDown(nFlags, point);
}
