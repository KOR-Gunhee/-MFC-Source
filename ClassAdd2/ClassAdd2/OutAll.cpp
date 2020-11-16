// OutAll.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ClassAdd2.h"
#include "OutAll.h"
#include "afxdialogex.h"


// COutAll 대화 상자입니다.

IMPLEMENT_DYNAMIC(COutAll, CDialogEx)

COutAll::COutAll(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_OUT_ALL, pParent)
	, m_strOutCell(_T(""))
	, m_strOutEmail(_T(""))
	, m_strOutEngName(_T(""))
	, m_strOutKorName(_T(""))
{

}

COutAll::~COutAll()
{
}

void COutAll::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OUT_CELL, m_strOutCell);
	DDX_Text(pDX, IDC_EDIT_OUT_EMAIL, m_strOutEmail);
	DDX_Text(pDX, IDC_EDIT_OUT_ENG_NAME, m_strOutEngName);
	DDX_Text(pDX, IDC_EDIT_OUT_KOR_NAME, m_strOutKorName);
}


BEGIN_MESSAGE_MAP(COutAll, CDialogEx)
END_MESSAGE_MAP()


// COutAll 메시지 처리기입니다.
