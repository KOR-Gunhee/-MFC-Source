
// ListExDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "ListEx.h"
#include "ListExDlg.h"
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


// CListExDlg ��ȭ ����



CListExDlg::CListExDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LISTEX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SUB, m_listSub);
	DDX_Control(pDX, IDC_LIST_LANG, m_listLang);
	DDX_Control(pDX, IDC_LIST_ENGE, m_listEnge);
	DDX_Control(pDX, IDC_LIST_SEL, m_listSel);
	DDX_Control(pDX, IDC_LIST_SIGN, m_listSign);
}

BEGIN_MESSAGE_MAP(CListExDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CListExDlg::OnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_LANG, &CListExDlg::OnClickedButtonLang)
	ON_BN_CLICKED(IDC_BUTTON_ENGE, &CListExDlg::OnClickedButtonEnge)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CListExDlg::OnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_SEL, &CListExDlg::OnClickedButtonSel)
END_MESSAGE_MAP()


// CListExDlg �޽��� ó����

BOOL CListExDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	m_listSub.AddString(_T("�������"));
	m_listSub.AddString(_T("�α�������"));
	m_listSub.AddString(_T("���뽺����"));
	m_listSub.AddString(_T("�⵶���� ����"));
	m_listSub.AddString(_T("���翵��"));
	m_listSub.AddString(_T("ö�л��"));

	m_listLang.AddString(_T("�Ͼ�"));
	m_listLang.AddString(_T("�߱���"));
	m_listLang.AddString(_T("���Ͼ�"));

	m_listEnge.AddString(_T("��ǻ�����"));
	m_listEnge.AddString(_T("�ü��"));
	m_listEnge.AddString(_T("���м���"));
	m_listEnge.AddString(_T("��Ű���"));
	m_listEnge.AddString(_T("��Ʈ��ũ�̷�"));

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CListExDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListExDlg::OnPaint()
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
HCURSOR CListExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CListExDlg::OnClickedButtonSub()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	int count = m_listSub.GetCount();

	for (int i = count - 1; i >= 0; i--)
	{
		if (m_listSub.GetSel(i))
		{
			m_listSub.GetText(i, str);
			m_listSel.AddString(str);
		}
	}
}


void CListExDlg::OnClickedButtonLang()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int Index = m_listLang.GetCurSel();
	if (Index != LB_ERR)
	{
		CString str;
		m_listLang.GetText(Index, str);
		m_listLang.SetCurSel(Index);
		m_listSel.AddString(str);
	}
}


void CListExDlg::OnClickedButtonEnge()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int Index = m_listEnge.GetCurSel();
	if (Index != LB_ERR)
	{
		CString str;
		m_listEnge.GetText(Index, str);
		m_listEnge.SetCurSel(Index);
		m_listSel.AddString(str);
	}
}


void CListExDlg::OnClickedButtonSel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	int count = m_listSel.GetCount();

	for (int i = count - 1; i >= 0; i--)
	{
		if (m_listSel.GetSel(i))
		{
			m_listSel.GetText(i, str);
			m_listSign.AddString(str);
		}
	}
}


void CListExDlg::OnClickedButtonDel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int nIndex;
	nIndex = m_listSel.GetCurSel();
	if (nIndex != LB_ERR)
	{
		m_listSel.DeleteString(nIndex);
	}
	else
	{
		AfxMessageBox(_T("������ �޴��� �����ϼ���"));
	}
}