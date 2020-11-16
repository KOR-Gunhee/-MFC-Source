
// MultiExView.h : CMultiExView Ŭ������ �������̽�
//

#pragma once


class CMultiExView : public CView
{
protected: // serialization������ ��������ϴ�.
	CMultiExView();
	DECLARE_DYNCREATE(CMultiExView)

// Ư���Դϴ�.
public:
	CMultiExDoc* GetDocument() const;

	int m_ptX;
	int m_ptY;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMultiExView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // MultiExView.cpp�� ����� ����
inline CMultiExDoc* CMultiExView::GetDocument() const
   { return reinterpret_cast<CMultiExDoc*>(m_pDocument); }
#endif

