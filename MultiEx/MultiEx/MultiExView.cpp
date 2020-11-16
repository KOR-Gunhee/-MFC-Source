
// MultiExView.cpp : CMultiExView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MultiEx.h"
#endif

#include "MultiExDoc.h"
#include "MultiExView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMultiExView

IMPLEMENT_DYNCREATE(CMultiExView, CView)

BEGIN_MESSAGE_MAP(CMultiExView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMultiExView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMultiExView ����/�Ҹ�

CMultiExView::CMultiExView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMultiExView::~CMultiExView()
{
}

BOOL CMultiExView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMultiExView �׸���

void CMultiExView::OnDraw(CDC* pDC)
{
	CMultiExDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

	RECT rect1;
	rect1.left = m_ptX - 10;
	rect1.top = m_ptY - 10;
	rect1.bottom = m_ptY + 200;
	rect1.right = m_ptX + 200;
	pDC->SelectStockObject(BLACK_BRUSH);
	pDC->Ellipse(&rect1);

	RECT rect2;
	rect2.left = m_ptX + 250;
	rect2.top = m_ptY - 100;
	rect2.bottom = m_ptY - 50;
	rect2.right = m_ptX + 300;	
	pDC->SelectStockObject(GRAY_BRUSH);
	pDC->Rectangle(&rect2);

	pDC->TextOutW(20, 20, _T("�簢��/Ÿ�� �׸��� ���� ���� ����"));

}


// CMultiExView �μ�


void CMultiExView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMultiExView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMultiExView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMultiExView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CMultiExView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMultiExView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMultiExView ����

#ifdef _DEBUG
void CMultiExView::AssertValid() const
{
	CView::AssertValid();
}

void CMultiExView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMultiExDoc* CMultiExView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMultiExDoc)));
	return (CMultiExDoc*)m_pDocument;
}
#endif //_DEBUG


// CMultiExView �޽��� ó����


void CMultiExView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	CMultiExDoc* pDoc = GetDocument();

	m_ptX = pDoc->m_ptX;
	m_ptY = pDoc->m_ptY;
}
