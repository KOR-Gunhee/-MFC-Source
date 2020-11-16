
// MDrawingView.cpp : CMDrawingView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MDrawing.h"
#endif

#include "MDrawingDoc.h"
#include "MDrawingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMDrawingView

IMPLEMENT_DYNCREATE(CMDrawingView, CView)

BEGIN_MESSAGE_MAP(CMDrawingView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMDrawingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMDrawingView ����/�Ҹ�

CMDrawingView::CMDrawingView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMDrawingView::~CMDrawingView()
{
}

BOOL CMDrawingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMDrawingView �׸���

void CMDrawingView::OnDraw(CDC* pDC)
{
	CMDrawingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	RECT rect;
	rect.left = m_ptX - 30;
	rect.top = m_ptY - 30;
	rect.bottom = m_ptY + 50;
	rect.right = m_ptX + 50;
	pDC->SelectStockObject(BLACK_BRUSH);
	pDC->Rectangle(&rect);

	pDC->TextOutW(20, 20, _T("���� ���� �������̽�"));
}


// CMDrawingView �μ�


void CMDrawingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMDrawingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMDrawingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMDrawingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMDrawingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMDrawingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMDrawingView ����

#ifdef _DEBUG
void CMDrawingView::AssertValid() const
{
	CView::AssertValid();
}

void CMDrawingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMDrawingDoc* CMDrawingView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMDrawingDoc)));
	return (CMDrawingDoc*)m_pDocument;
}
#endif //_DEBUG


// CMDrawingView �޽��� ó����


void CMDrawingView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	CMDrawingDoc* pDoc = GetDocument();

	m_ptX = pDoc->m_ptX;
	m_ptY = pDoc->m_ptY;
}
