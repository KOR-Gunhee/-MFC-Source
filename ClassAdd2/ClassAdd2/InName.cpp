// InName.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ClassAdd2.h"
#include "InName.h"
#include "afxdialogex.h"


// CInName ��ȭ �����Դϴ�.

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


// CInName �޽��� ó�����Դϴ�.
