// InContact.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "ClassAdd2.h"
#include "InContact.h"
#include "afxdialogex.h"


// CInContact ��ȭ �����Դϴ�.

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


// CInContact �޽��� ó�����Դϴ�.
