
// SEditGraphicDoc.h : CSEditGraphicDoc Ŭ������ �������̽�
//


#pragma once


class CSEditGraphicDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CSEditGraphicDoc();
	DECLARE_DYNCREATE(CSEditGraphicDoc)

// Ư���Դϴ�.
public:

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CSEditGraphicDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	CString m_strData;
	CString GetText();
	void SetText(CString strInput);
	afx_msg void OnDataInput();
	COLORREF m_curColor;
	void ColorSet(COLORREF color);
	COLORREF ColorGet();
	afx_msg void OnColorBlue();
	afx_msg void OnColorRed();
	afx_msg void OnColorYellow();
};
