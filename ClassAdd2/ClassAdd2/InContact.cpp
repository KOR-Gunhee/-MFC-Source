// InContact.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "ClassAdd2.h"
#include "InContact.h"
#include "afxdialogex.h"


// CInContact 대화 상자입니다.

IMPLEMENT_DYNAMIC(CInContact, CDialogEx)

CInContact::CInContact(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_IN_CONTACT, pParent)
	, m_strInCell(_T(""))
	, m_strInEmail(_T(""))
{

}

CInContact::~CInContact()
{
}

void CInContact::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_IN_CELL, m_strInCell);
	DDX_Text(pDX, IDC_EDIT_IN_EMAIL, m_strInEmail);
}


BEGIN_MESSAGE_MAP(CInContact, CDialogEx)
END_MESSAGE_MAP()


// CInContact 메시지 처리기입니다.
