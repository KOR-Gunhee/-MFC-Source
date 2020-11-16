
// SEditGraphicDoc.cpp : CSEditGraphicDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "SEditGraphic.h"
#endif

#include "SEditGraphicDoc.h"

#include <propkey.h>
#include "TextDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define BLACK RGB(0, 0, 0)
#define RED RGB(255, 0, 0)
#define BLUE RGB(51, 51, 255)
#define YELLOW RGB(255, 204, 51)

// CSEditGraphicDoc

IMPLEMENT_DYNCREATE(CSEditGraphicDoc, CDocument)

BEGIN_MESSAGE_MAP(CSEditGraphicDoc, CDocument)
	ON_COMMAND(ID_DATA_INPUT, &CSEditGraphicDoc::OnDataInput)
	ON_COMMAND(ID_COLOR_BLUE, &CSEditGraphicDoc::OnColorBlue)
	ON_COMMAND(ID_COLOR_RED, &CSEditGraphicDoc::OnColorRed)
	ON_COMMAND(ID_COLOR_YELLOW, &CSEditGraphicDoc::OnColorYellow)
END_MESSAGE_MAP()


// CSEditGraphicDoc ����/�Ҹ�

CSEditGraphicDoc::CSEditGraphicDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CSEditGraphicDoc::~CSEditGraphicDoc()
{
}

BOOL CSEditGraphicDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CSEditGraphicDoc serialization

void CSEditGraphicDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CSEditGraphicDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// �˻� ó���⸦ �����մϴ�.
void CSEditGraphicDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CSEditGraphicDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CSEditGraphicDoc ����

#ifdef _DEBUG
void CSEditGraphicDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSEditGraphicDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSEditGraphicDoc ���


CString CSEditGraphicDoc::GetText()
{
	return m_strData;
}


void CSEditGraphicDoc::SetText(CString strInput)
{
	m_strData = strInput;
	UpdateAllViews(NULL);
}


void CSEditGraphicDoc::OnDataInput()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CTextDlg m_TextDlg;
	m_TextDlg.m_strTextInput = GetText();
	if (m_TextDlg.DoModal() == IDOK)
	{
		SetText(m_TextDlg.m_strTextInput);
	}
}


void CSEditGraphicDoc::ColorSet(COLORREF color)
{
	m_curColor = color;
	UpdateAllViews(NULL);
}


COLORREF CSEditGraphicDoc::ColorGet()
{
	return m_curColor;
}


void CSEditGraphicDoc::OnColorBlue()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	ColorSet(BLUE);
}


void CSEditGraphicDoc::OnColorRed()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	ColorSet(RED);
}


void CSEditGraphicDoc::OnColorYellow()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	ColorSet(YELLOW);
}
