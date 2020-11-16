
// TabExDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "TabEx.h"
#include "TabExDlg.h"
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


// CTabExDlg ��ȭ ����



CTabExDlg::CTabExDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TABEX_DIALOG, pParent)
	, m_dEngA(0)
	, m_dEngB(0)
	, m_dEngC(0)
	, m_dEngD(0)
	, m_dEngTotal(0)
	, m_dKorA(0)
	, m_dKorB(0)
	, m_dKorC(0)
	, m_dKorTotal(0)
	, m_dMathA(0)
	, m_dMathB(0)
	, m_dMathC(0)
	, m_dMathTotal(0)
	, m_dTotal(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTabExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_AREA, m_tabArea);
	DDX_Text(pDX, IDC_EDIT_ENG_A, m_dEngA);
	DDX_Text(pDX, IDC_EDIT_ENG_B, m_dEngB);
	DDX_Text(pDX, IDC_EDIT_ENG_C, m_dEngC);
	DDX_Text(pDX, IDC_EDIT_ENG_D, m_dEngD);
	DDX_Text(pDX, IDC_EDIT_ENG_TOTAL, m_dEngTotal);
	DDX_Text(pDX, IDC_EDIT_KOR_A, m_dKorA);
	DDX_Text(pDX, IDC_EDIT_KOR_B, m_dKorB);
	DDX_Text(pDX, IDC_EDIT_KOR_C, m_dKorC);
	DDX_Text(pDX, IDC_EDIT_KOR_TOTAL, m_dKorTotal);
	DDX_Text(pDX, IDC_EDIT_MATH_A, m_dMathA);
	DDX_Text(pDX, IDC_EDIT_MATH_B, m_dMathB);
	DDX_Text(pDX, IDC_EDIT_MATH_C, m_dMathC);
	DDX_Text(pDX, IDC_EDIT_MATH_TOTAL, m_dMathTotal);
	DDX_Text(pDX, IDC_EDIT_TOTAL, m_dTotal);
}

BEGIN_MESSAGE_MAP(CTabExDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_AREA, &CTabExDlg::OnSelchangeTabArea)
	ON_BN_CLICKED(IDC_BUTTON_ENG_TOTAL, &CTabExDlg::OnClickedButtonEngTotal)
	ON_BN_CLICKED(IDC_BUTTON_MATH_TOTAL, &CTabExDlg::OnClickedButtonMathTotal)
	ON_BN_CLICKED(IDC_BUTTON_KOR_TOTAL, &CTabExDlg::OnClickedButtonKorTotal)
	ON_BN_CLICKED(IDC_BUTTON_TOTAL, &CTabExDlg::OnClickedButtonTotal)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CTabExDlg::OnClickedButtonExit)
END_MESSAGE_MAP()


// CTabExDlg �޽��� ó����

BOOL CTabExDlg::OnInitDialog()
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

	TC_ITEM tabItem;
	LPSTR tabName[3] = { _T("�����"), _T("���м���"), _T("�����") };
	for (int nIndex = 0; nIndex < 3; nIndex++)
	{
		tabItem.mask = TCIF_TEXT;
		tabItem.pszText = tabName[nIndex];
		m_tabArea.InsertItem(nIndex, &tabItem);	
	}
	
	GetDlgItem(IDC_STATIC_ENG_A)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_ENG_B)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_ENG_C)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_ENG_D)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON_ENG_TOTAL)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_ENG_A)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_ENG_B)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_ENG_C)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_ENG_D)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_ENG_TOTAL)->ShowWindow(TRUE);

	GetDlgItem(IDC_STATIC_MATH_A)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_MATH_B)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_MATH_C)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON_MATH_TOTAL)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_MATH_A)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_MATH_B)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_MATH_C)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_MATH_TOTAL)->ShowWindow(FALSE);

	GetDlgItem(IDC_STATIC_KOR_A)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_KOR_B)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_KOR_C)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON_KOR_TOTAL)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_KOR_A)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_KOR_B)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_KOR_C)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_KOR_TOTAL)->ShowWindow(FALSE);
	
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CTabExDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTabExDlg::OnPaint()
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
HCURSOR CTabExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTabExDlg::OnSelchangeTabArea(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	int nSelect = m_tabArea.GetCurSel();

	switch (nSelect)
	{
	case 0:
		GetDlgItem(IDC_STATIC_ENG_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_ENG_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_ENG_C)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_ENG_D)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON_ENG_TOTAL)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_ENG_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_ENG_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_ENG_C)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_ENG_D)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_ENG_TOTAL)->ShowWindow(TRUE);

		GetDlgItem(IDC_STATIC_MATH_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_MATH_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_MATH_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_MATH_TOTAL)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_TOTAL)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_KOR_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_KOR_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_KOR_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_KOR_TOTAL)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_TOTAL)->ShowWindow(FALSE);
		break;

	case 1:
		GetDlgItem(IDC_STATIC_ENG_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_ENG_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_ENG_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_ENG_D)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_ENG_TOTAL)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_D)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_TOTAL)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_MATH_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_MATH_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_MATH_C)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON_MATH_TOTAL)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_MATH_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_MATH_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_MATH_C)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_MATH_TOTAL)->ShowWindow(TRUE);

		GetDlgItem(IDC_STATIC_KOR_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_KOR_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_KOR_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_KOR_TOTAL)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_TOTAL)->ShowWindow(FALSE);
		break;

	case 2:
		GetDlgItem(IDC_STATIC_ENG_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_ENG_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_ENG_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_ENG_D)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_ENG_TOTAL)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_D)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_TOTAL)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_MATH_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_MATH_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_MATH_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_MATH_TOTAL)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_TOTAL)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_KOR_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_KOR_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_KOR_C)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON_KOR_TOTAL)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_KOR_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_KOR_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_KOR_C)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_KOR_TOTAL)->ShowWindow(TRUE);
		break;
	}
	*pResult = 0;
}


void CTabExDlg::OnClickedButtonEngTotal()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dEngTotal = m_dEngA + m_dEngB + m_dEngC + m_dEngD;
	UpdateData(FALSE);
}


void CTabExDlg::OnClickedButtonMathTotal()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dMathTotal = m_dMathA + m_dMathB + m_dMathC;
	UpdateData(FALSE);
}


void CTabExDlg::OnClickedButtonKorTotal()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dKorTotal = m_dKorA + m_dKorB + m_dKorC;
	UpdateData(FALSE);
}


void CTabExDlg::OnClickedButtonTotal()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dTotal = m_dEngTotal + m_dMathTotal + m_dKorTotal;
	UpdateData(FALSE);
}


void CTabExDlg::OnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}
