// InName.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ClassAdd2.h"
#include "InName.h"
#include "afxdialogex.h"


// CInName 대화 상자입니다.

IMPLEMENT_DYNAMIC(CInName, CDialogEx)

CInName::CInName(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_IN_NAME, pParent)
	, m_strInKorName(_T(""))
	, m_strInEngName(_T(""))
{

}

CInName::~CInName()
{
}

void CInName::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_IN_ENG_NAME, m_strInKorName);
	DDX_Text(pDX, IDC_EDIT_IN_ENG_NAME, m_strInEngName);
	DDX_Text(pDX, IDC_EDIT_IN_KOR_NAME, m_strInKorName);
}


BEGIN_MESSAGE_MAP(CInName, CDialogEx)
END_MESSAGE_MAP()


// CInName 메시지 처리기입니다.
