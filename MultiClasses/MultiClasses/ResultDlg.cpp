// ResultDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MultiClasses.h"
#include "ResultDlg.h"
#include "afxdialogex.h"


// CResultDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CResultDlg, CDialogEx)

CResultDlg::CResultDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_OUT_RESULT, pParent)
	, m_strOutMajor1(_T(""))
	, m_strOutMajor2(_T(""))
	, m_strOutMajor3(_T(""))
	, m_strOutSub1(_T(""))
	, m_strOutSub2(_T(""))
{

}

CResultDlg::~CResultDlg()
{
}

void CResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OUT_MAJOR1, m_strOutMajor1);
	DDX_Text(pDX, IDC_EDIT_OUT_MAJOR2, m_strOutMajor2);
	DDX_Text(pDX, IDC_EDIT_OUT_MAJOR3, m_strOutMajor3);
	DDX_Text(pDX, IDC_EDIT_OUT_SUB1, m_strOutSub1);
	DDX_Text(pDX, IDC_EDIT_OUT_SUB2, m_strOutSub2);
}


BEGIN_MESSAGE_MAP(CResultDlg, CDialogEx)
END_MESSAGE_MAP()


// CResultDlg 메시지 처리기입니다.
