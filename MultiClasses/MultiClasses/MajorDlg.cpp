// MajorDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MultiClasses.h"
#include "MajorDlg.h"
#include "afxdialogex.h"


// CMajorDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMajorDlg, CDialogEx)

CMajorDlg::CMajorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_IN_MAJOR, pParent)
	, m_strMajor1(_T(""))
	, m_strMajor2(_T(""))
	, m_strMajor3(_T(""))
{

}

CMajorDlg::~CMajorDlg()
{
}

void CMajorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_IN_MAJOR1, m_strMajor1);
	DDX_Text(pDX, IDC_EDIT_IN_MAJOR2, m_strMajor2);
	DDX_Text(pDX, IDC_EDIT_IN_MAJOR3, m_strMajor3);
}


BEGIN_MESSAGE_MAP(CMajorDlg, CDialogEx)
END_MESSAGE_MAP()


// CMajorDlg 메시지 처리기입니다.
