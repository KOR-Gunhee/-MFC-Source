
// ListBoxMenuDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ListBoxMenu.h"
#include "ListBoxMenuDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CListBoxMenuDlg ��ȭ ����



CListBoxMenuDlg::CListBoxMenuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LISTBOXMENU_DIALOG, pParent)
	, m_strEtc(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListBoxMenuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_MEAL, m_listMeal);
	DDX_Control(pDX, IDC_LIST_DESSERT, m_listDessert);
	DDX_Control(pDX, IDC_LIST_RESULT, m_listResult);
	DDX_Text(pDX, IDC_EDIT_ETC, m_strEtc);
}

BEGIN_MESSAGE_MAP(CListBoxMenuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_MEAL, &CListBoxMenuDlg::OnClickedButtonMeal)
	ON_BN_CLICKED(IDC_BUTTON_DESSERT, &CListBoxMenuDlg::OnClickedButtonDessert)
	ON_BN_CLICKED(IDC_BUTTON_ETC, &CListBoxMenuDlg::OnClickedButtonEtc)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CListBoxMenuDlg::OnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CListBoxMenuDlg::OnClickedButtonDel)
END_MESSAGE_MAP()


// CListBoxMenuDlg �޽��� ó����

BOOL CListBoxMenuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ���� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	m_listMeal.AddString(_T("�����"));
	m_listMeal.AddString(_T("��ä��"));
	m_listMeal.AddString(_T("�Ұ�����"));
	m_listMeal.AddString(_T("Į����"));
	m_listMeal.AddString(_T("���"));
	m_listMeal.AddString(_T("����"));
	m_listMeal.AddString(_T("��ġ�"));
	m_listMeal.AddString(_T("���İ�Ƽ"));

	m_listDessert.AddString(_T("Ŀ��"));
	m_listDessert.AddString(_T("���̽�ũ��"));
	m_listDessert.AddString(_T("����"));
	m_listDessert.AddString(_T("����ũ"));
		 
	m_listDessert.AddString(_T("����ֽ�"));
	m_listDessert.AddString(_T("�������ֽ�"));
		
	m_listDessert.AddString(_T("��Ű"));
	m_listDessert.AddString(_T("��Ϻ극��"));

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CListBoxMenuDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CListBoxMenuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CListBoxMenuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CListBoxMenuDlg::OnClickedButtonMeal()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int Index = m_listMeal.GetCurSel();
	if (Index != LB_ERR)
	{
		CString str;
		m_listMeal.GetText(Index, str);
		m_listMeal.SetCurSel(Index);
		m_listResult.AddString(str);
	}
}


void CListBoxMenuDlg::OnClickedButtonDessert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	int count = m_listDessert.GetCount();

	for (int i = count - 1; i >= 0; i--)
	{
		if (m_listDessert.GetSel(i))
		{
			m_listDessert.GetText(i, str);
			m_listResult.AddString(str);
		}
	}
}


void CListBoxMenuDlg::OnClickedButtonEtc()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_EDIT_ETC);
	UpdateData(TRUE);

	if (m_strEtc.IsEmpty())
	{
		MessageBox(_T("��Ÿ �޴��� �Է��ϼ���"), _T("Error"), MB_ICONSTOP | MB_OK);
		pEdit->SetFocus();
		return;
	}
	str = m_strEtc;
	m_listResult.AddString(str);
	UpdateData(FALSE);
}


void CListBoxMenuDlg::OnClickedButtonReset()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_EDIT_ETC);
	UpdateData(TRUE);

	m_strEtc = _T("");
	pEdit->SetFocus();
	UpdateData(FALSE);
}


void CListBoxMenuDlg::OnClickedButtonDel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nIndex;
	nIndex = m_listResult.GetCurSel();
	if (nIndex != LB_ERR)
	{
		m_listResult.DeleteString(nIndex);
	}
	else
	{
		AfxMessageBox(_T("������ �޴��� �����ϼ���"));
	}
}