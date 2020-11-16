
// CalcEXDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CalcEX.h"
#include "CalcEXDlg.h"
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


// CCalcEXDlg ��ȭ ����



CCalcEXDlg::CCalcEXDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCEX_DIALOG, pParent)
	, Average(_T("0"))
	, Language(_T("0"))
	, English(_T("0"))
	, Math(_T("0"))
	, Total(_T("0"))
	, Grade(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcEXDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_AVERAGE, Average);
	DDX_Text(pDX, IDC_EDI_LANGUAGE, Language);
	DDX_Text(pDX, IDC_EDIT_ENGLISH, English);
	DDX_Text(pDX, IDC_EDIT_MATH, Math);
	DDX_Text(pDX, IDC_EDIT_TOTAL, Total);
	DDX_Text(pDX, IDC_EDIT_GRADE, Grade);
}

BEGIN_MESSAGE_MAP(CCalcEXDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CCalcEXDlg::OnClickedButtonInsert)
END_MESSAGE_MAP()


// CCalcEXDlg �޽��� ó����

BOOL CCalcEXDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.
	//Total = _T("0");
	//Average = _T("0");
	//Grade = _T("0");

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

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CCalcEXDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalcEXDlg::OnPaint()
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
HCURSOR CCalcEXDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalcEXDlg::OnClickedButtonInsert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	char temp1[10];
	char temp2[10];
	char temp3[10];
	double tmpTotal;
	double tmpAver;
	double tmpGrade = 0;

	UpdateData(TRUE);

	tmpTotal = atof(Language) + atof(English) + atof(Math);
	tmpAver = tmpTotal / 3;
	
	sprintf_s(temp1, "%2.f", tmpTotal);
	Total = temp1;
	sprintf_s(temp2, "%2.f", tmpAver);
	Average = temp2;

	if (tmpAver >= 90)
	{
		sprintf_s(temp3, "A", tmpGrade);
		Grade = temp3;
	}
	else if ((90 > tmpAver)|(tmpAver >= 80))
	{
		sprintf_s(temp3, "B", tmpGrade);
		Grade = temp3;
	}
	else if ((80 > tmpAver) | (tmpAver >= 70))
	{
		sprintf_s(temp3, "C", tmpGrade);
		Grade = temp3;
	}
	else if ((70 > tmpAver) | (tmpAver >= 60))
	{
		sprintf_s(temp3, "D", tmpGrade);
		Grade = temp3;
	}
	else if (60 > tmpAver)
	{
		sprintf_s(temp3, "F", tmpGrade);
	}

	UpdateData(FALSE);
}
