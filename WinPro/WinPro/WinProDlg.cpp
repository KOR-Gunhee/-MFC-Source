
// WinProDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "WinPro.h"
#include "WinProDlg.h"
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


// CWinProDlg ��ȭ ����



CWinProDlg::CWinProDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WINPRO_DIALOG, pParent)
	, m_chShow(FALSE)
	, m_chEnable(FALSE)
	, m_strBasic(_T(""))
	, m_strMulti(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWinProDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_SHOW, m_chShow);
	DDX_Check(pDX, IDC_CHECK_ENABLE, m_chEnable);
	DDX_Text(pDX, IDC_EDI_BASIC, m_strBasic);
	DDX_Text(pDX, IDC_EDIT_MULTI, m_strMulti);
}

BEGIN_MESSAGE_MAP(CWinProDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK_ENABLE, &CWinProDlg::OnClickedCheckEnable)
	ON_BN_CLICKED(IDC_CHECK_SHOW, &CWinProDlg::OnClickedCheckShow)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CWinProDlg::OnClickedButtonExit)
	ON_EN_CHANGE(IDC_EDI_BASIC, &CWinProDlg::OnChangeEdiBasic)
	ON_EN_CHANGE(IDC_EDIT_MULTI, &CWinProDlg::OnChangeEditMulti)
END_MESSAGE_MAP()


// CWinProDlg �޽��� ó����

BOOL CWinProDlg::OnInitDialog()
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
	m_chShow = TRUE;
	m_chEnable = TRUE;
	UpdateData(FALSE);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CWinProDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWinProDlg::OnPaint()
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
HCURSOR CWinProDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWinProDlg::ActiveShow()
{
	UpdateData(TRUE);

	if ((m_chShow == TRUE) && (m_chEnable == TRUE))
	{
		GetDlgItem(IDC_EDI_BASIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDI_BASIC)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_MULTI)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_MULTI)->EnableWindow(TRUE);
	}
	else if ((m_chShow == TRUE) && (m_chEnable == FALSE))
	{
		GetDlgItem(IDC_EDI_BASIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDI_BASIC)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_MULTI)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_MULTI)->EnableWindow(FALSE);
	}
	else if ((m_chShow == FALSE) && (m_chEnable == TRUE))
	{
		GetDlgItem(IDC_EDI_BASIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDI_BASIC)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_MULTI)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_MULTI)->EnableWindow(FALSE);
	}
	else if ((m_chShow == FALSE) && (m_chEnable == FALSE))
	{
		GetDlgItem(IDC_EDI_BASIC)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDI_BASIC)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_MULTI)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_MULTI)->EnableWindow(FALSE);
	}
}



void CWinProDlg::OnClickedCheckEnable()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ActiveShow();
}


void CWinProDlg::OnClickedCheckShow()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ActiveShow();
}


void CWinProDlg::OnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


void CWinProDlg::OnChangeEdiBasic()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CString UpperChar;

	UpperChar = m_strBasic;

	UpperChar.MakeUpper();

	if (UpperChar == "NOTE")
	{
		system("notepad.exe");
		m_strBasic = _T("");
		UpdateData(FALSE);
	}
	if (UpperChar == "CALC")
	{
		system("calc.exe");
		m_strBasic = _T("");
		UpdateData(FALSE);
	}
}


void CWinProDlg::OnChangeEditMulti()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CString UpperChar;

	UpperChar = m_strMulti;

	UpperChar.MakeUpper();

	if (UpperChar == "DVD")
	{
		system("WMP.exe");
		m_strBasic = _T("");
		UpdateData(FALSE);
	}
	if (UpperChar == "PAINT")
	{
		system("mspaint.exe");
		m_strBasic = _T("");
		UpdateData(FALSE);
	}
}