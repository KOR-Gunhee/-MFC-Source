// TextDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "SEditGraphic.h"
#include "TextDlg.h"
#include "afxdialogex.h"


// CTextDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTextDlg, CDialogEx)

CTextDlg::CTextDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_TEXT, pParent)
	, m_strTextInput(_T(""))
{

}

CTextDlg::~CTextDlg()
{
}

void CTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT_INPUT, m_strTextInput);
	DDV_MaxChars(pDX, m_strTextInput, 30);
}


BEGIN_MESSAGE_MAP(CTextDlg, CDialogEx)
END_MESSAGE_MAP()


// CTextDlg 메시지 처리기입니다.
