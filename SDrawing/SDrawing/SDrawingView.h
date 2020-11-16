
// SDrawingView.h : CSDrawingView Ŭ������ �������̽�
//

#pragma once
#include "atltypes.h"


class CSDrawingView : public CView
{
protected: // serialization������ ��������ϴ�.
	CSDrawingView();
	DECLARE_DYNCREATE(CSDrawingView)

// Ư���Դϴ�.
public:
	CSDrawingDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CSDrawingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	int m_ptX;
	int m_ptY;
	int m_crColor;
	CRect m_reRect;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // SDrawingView.cpp�� ����� ����
inline CSDrawingDoc* CSDrawingView::GetDocument() const
   { return reinterpret_cast<CSDrawingDoc*>(m_pDocument); }
#endif

