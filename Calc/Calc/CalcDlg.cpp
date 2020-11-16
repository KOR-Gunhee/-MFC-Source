
// CalcDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Calc.h"
#include "CalcDlg.h"
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


// CCalcDlg ��ȭ ����



CCalcDlg::CCalcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALC_DIALOG, pParent)
	, m_nOption(0)
	, m_nNum1(_T(""))
	, m_nNum2(_T(""))
	, m_nResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_NUM1, m_nNum1);
	//  DDX_Text(pDX, IDC_EDIT_NUM2, m_nNum2);
	//  DDX_Text(pDX, IDC_EDIT_RESULT, m_nResult);
	DDX_Text(pDX, IDC_EDIT_NUM1, m_nNum1);
	DDX_Text(pDX, IDC_EDIT_NUM2, m_nNum2);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_nResult);
}

BEGIN_MESSAGE_MAP(CCalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CCalcDlg::OnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CCalcDlg::OnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CCalcDlg::OnClickedButtonMul)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CCalcDlg::OnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_EQU, &CCalcDlg::OnClickedButtonEqu)
	ON_BN_CLICKED(IDC_BUTTON_CLR, &CCalcDlg::OnClickedButtonClr)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CCalcDlg::OnClickedButtonExit)
END_MESSAGE_MAP()


// CCalcDlg �޽��� ó����

BOOL CCalcDlg::OnInitDialog()
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

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalcDlg::OnPaint()
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
HCURSOR CCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalcDlg::OnClickedButtonAdd()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nOption = 1;
}


void CCalcDlg::OnClickedButtonSub()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nOption = 2;
}


void CCalcDlg::OnClickedButtonMul()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nOption = 3;
}


void CCalcDlg::OnClickedButtonDiv()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nOption = 4;
}


void CCalcDlg::OnClickedButtonEqu()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	char temp[10];
	double tmpResult;

	UpdateData(TRUE);

	switch (m_nOption)
	{
		case 1:
			tmpResult = atof(m_nNum1) + atof(m_nNum2);
			break;
		case 2:
			tmpResult = atof(m_nNum1) - atof(m_nNum2);
			break;
		case 3:
			tmpResult = atof(m_nNum1) * atof(m_nNum2);
			break;
		case 4:
			tmpResult = atof(m_nNum1) / atof(m_nNum2);
			break;
		default:
			tmpResult = 0.00;
			break;
	}

	sprintf_s(temp, "%2.f", tmpResult);
	m_nResult = temp;
	UpdateData(FALSE);
}


void CCalcDlg::OnClickedButtonClr()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_nNum1 = _T("");
	m_nNum2 = _T("");
	m_nResult = _T("");
	UpdateData(FALSE);
}


void CCalcDlg::OnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	PostQuitMessage(0);
}
