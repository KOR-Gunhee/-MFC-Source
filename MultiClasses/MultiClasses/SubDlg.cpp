// SubDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MultiClasses.h"
#include "SubDlg.h"
#include "afxdialogex.h"


// CSubDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CSubDlg, CDialogEx)

CSubDlg::CSubDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_IN_SUB, pParent)
	, m_strSub1(_T(""))
	, m_strSub2(_T(""))
{

}

CSubDlg::~CSubDlg()
{
}

void CSubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_IN_SUB1, m_strSub1);
	DDX_Text(pDX, IDC_EDIT_IN_SUB2, m_strSub2);
}


BEGIN_MESSAGE_MAP(CSubDlg, CDialogEx)
END_MESSAGE_MAP()


// CSubDlg 메시지 처리기입니다.
