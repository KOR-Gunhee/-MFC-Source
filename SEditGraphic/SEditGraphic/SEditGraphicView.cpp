
// SEditGraphicView.cpp : CSEditGraphicView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "SEditGraphic.h"
#endif

#include "SEditGraphicDoc.h"
#include "SEditGraphicView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSEditGraphicView

IMPLEMENT_DYNCREATE(CSEditGraphicView, CView)

BEGIN_MESSAGE_MAP(CSEditGraphicView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FIG_CIR, &CSEditGraphicView::OnFigCir)
	ON_COMMAND(ID_FIG_RECT, &CSEditGraphicView::OnFigRect)
	ON_COMMAND(ID_FIG_LINE, &CSEditGraphicView::OnFigLine)
	ON_COMMAND(ID_FIG_CROSS, &CSEditGraphicView::OnFigCross)
	ON_COMMAND(ID_FIG_APPLE, &CSEditGraphicView::OnFigApple)
END_MESSAGE_MAP()

// CSEditGraphicView ����/�Ҹ�

CSEditGraphicView::CSEditGraphicView()
	: m_nOption(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CSEditGraphicView::~CSEditGraphicView()
{
}

BOOL CSEditGraphicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CSEditGraphicView �׸���

void CSEditGraphicView::OnDraw(CDC* pDC)
{
	CSEditGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CFont font, *pOldFont;
	font.CreatePointFont(300, _T("Broadway"));

	pOldFont = (CFont*)pDC->SelectObject(&font);
	CString strInput1 = _T(" << Input Data >>");
	CString strInput2 = pDoc->GetText();
	pDC->SetTextColor(RGB(0, 0, 0));
	pDC->TextOutW(0, 20, strInput1);

	pDC->SetBkColor(RGB(255, 255, 255));
	pDC->SetTextColor(pDoc->ColorGet());

	pDC->TextOutW(50, 100, strInput2);

	switch (m_nOption)
	{
		case 1:
		{
			CBrush brush(RGB(0, 255, 0));
			CBrush *pOldBrush = pDC->SelectObject(&brush);
			pDC->Ellipse(200, 200, 400, 400);
			brush.DeleteObject();
			break;
		}

		case 2:
		{
			CBrush brush(RGB(150, 0, 150));
			CBrush *pOldBrush = pDC->SelectObject(&brush);
			pDC->Rectangle(200, 200, 400, 400);
			brush.DeleteObject();
			break;
		}

		case 3:
		{
			CDC* pDC = GetDC();
			int nPenType[] = { PS_SOLID, PS_DOT, PS_DASHDOT, PS_DASH, PS_DASHDOTDOT };

			for (int i = 0; i < sizeof(nPenType[0])/ sizeof(nPenType[0]); i++)
			{
				CPen pen(nPenType[i], 1, RGB(0, 0, 255));
				pDC->SelectObject(&pen);

				pDC->MoveTo(100, 200 + i * 50);
				pDC->LineTo(500, 200 + i * 50);

				pDC->MoveTo(100, 200 + i * 50);
				pDC->LineTo(500, 300 + i * 50);
			}
			break;
		}

		case 4:
		{
			CBrush brush(HS_DIAGCROSS,RGB(255, 90, 0));
			CBrush *pOldBrush = pDC->SelectObject(&brush);
			pDC->RoundRect(200, 200, 400, 400, 50, 50);
			pDC->SelectObject(pOldBrush);
			brush.DeleteObject();
			break;
		}

		case 5:
		{
			CBitmap bitmap;
			bitmap.LoadBitmapW(IDB_BITMAP1);
			CBrush brush(&bitmap);

			CBrush *pOldBrush = pDC->SelectObject(&brush);

			pDC->SetBkColor(TRANSPARENT);

			pDC->RoundRect(200, 200, 400, 400, 50, 50);
			pDC->SelectObject(&brush);
			brush.DeleteObject();

			break;
		}
	}
}


// CSEditGraphicView �μ�

BOOL CSEditGraphicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CSEditGraphicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CSEditGraphicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CSEditGraphicView ����

#ifdef _DEBUG
void CSEditGraphicView::AssertValid() const
{
	CView::AssertValid();
}

void CSEditGraphicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSEditGraphicDoc* CSEditGraphicView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSEditGraphicDoc)));
	return (CSEditGraphicDoc*)m_pDocument;
}
#endif //_DEBUG


// CSEditGraphicView �޽��� ó����


void CSEditGraphicView::OnFigCir()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nOption = 1;
	Invalidate();
}


void CSEditGraphicView::OnFigRect()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nOption = 2;
	Invalidate();
}


void CSEditGraphicView::OnFigLine()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nOption = 3;
	Invalidate();
}


void CSEditGraphicView::OnFigCross()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nOption = 4;
	Invalidate();
}


void CSEditGraphicView::OnFigApple()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_nOption = 5;
	Invalidate();
}
