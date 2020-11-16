
// SEditGraphicView.h : CSEditGraphicView Ŭ������ �������̽�
//

#pragma once


class CSEditGraphicView : public CView
{
protected: // serialization������ ��������ϴ�.
	CSEditGraphicView();
	DECLARE_DYNCREATE(CSEditGraphicView)

// Ư���Դϴ�.
public:
	CSEditGraphicDoc* GetDocument() const;

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
	virtual ~CSEditGraphicView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	int m_nOption;
	afx_msg void OnFigCir();
	afx_msg void OnFigRect();
	afx_msg void OnFigLine();
	afx_msg void OnFigCross();
	afx_msg void OnFigApple();
};

#ifndef _DEBUG  // SEditGraphicView.cpp�� ����� ����
inline CSEditGraphicDoc* CSEditGraphicView::GetDocument() const
   { return reinterpret_cast<CSEditGraphicDoc*>(m_pDocument); }
#endif

