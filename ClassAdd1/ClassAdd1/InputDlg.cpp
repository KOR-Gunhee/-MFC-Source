// InputDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ClassAdd1.h"
#include "InputDlg.h"
#include "afxdialogex.h"


// CInputDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CInputDlg, CDialogEx)

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_INPUT, pParent)
	, m_strName(_T(""))
	, m_strNum(_T(""))
{

}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_NUM, m_strNum);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialogEx)
END_MESSAGE_MAP()


// CInputDlg 메시지 처리기입니다.
