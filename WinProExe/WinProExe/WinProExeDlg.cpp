
// WinProExeDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "WinProExe.h"
#include "WinProExeDlg.h"
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


// CWinProExeDlg ��ȭ ����



CWinProExeDlg::CWinProExeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WINPROEXE_DIALOG, pParent)
	, m_chActive(FALSE)
	, m_chShow(FALSE)
	, m_strInput(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWinProExeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_ACTIVE, m_chActive);
	DDX_Check(pDX, IDC_CHECK_SHOW, m_chShow);
	DDX_Text(pDX, IDC_EDIT_INPUT, m_strInput);
}

BEGIN_MESSAGE_MAP(CWinProExeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK_ACTIVE, &CWinProExeDlg::OnClickedCheckActive)
	ON_BN_CLICKED(IDC_CHECK_SHOW, &CWinProExeDlg::OnClickedCheckShow)
	ON_EN_CHANGE(IDC_EDIT_INPUT, &CWinProExeDlg::OnChangeEditInput)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CWinProExeDlg::OnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CWinProExeDlg::OnClickedButtonExit)
END_MESSAGE_MAP()


// CWinProExeDlg �޽��� ó����

BOOL CWinProExeDlg::OnInitDialog()
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
	m_chActive = TRUE;
	m_chShow = TRUE;
	UpdateData(FALSE);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CWinProExeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWinProExeDlg::OnPaint()
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
HCURSOR CWinProExeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWinProExeDlg::ActiveShow()
{
	UpdateData(TRUE);

	if ((m_chActive == TRUE) && (m_chShow == TRUE))
	{
		GetDlgItem(IDC_EDIT_INPUT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_INPUT)->EnableWindow(TRUE);
	}
	else if ((m_chActive == TRUE) && (m_chShow == FALSE))
	{
		GetDlgItem(IDC_EDIT_INPUT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_INPUT)->EnableWindow(FALSE);
	}
	else if ((m_chActive == FALSE) && (m_chShow == TRUE))
	{
		GetDlgItem(IDC_EDIT_INPUT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_INPUT)->EnableWindow(FALSE);
	}
	else if ((m_chActive == FALSE) && (m_chShow == FALSE))
	{
		GetDlgItem(IDC_EDIT_INPUT)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_INPUT)->EnableWindow(FALSE);
	}


}


void CWinProExeDlg::OnClickedCheckActive()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ActiveShow();
}


void CWinProExeDlg::OnClickedCheckShow()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ActiveShow();
}


void CWinProExeDlg::OnChangeEditInput()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);

	CString UpperChar;

	UpperChar = m_strInput;

	UpperChar.MakeUpper();

	if (UpperChar == "PAINT")
	{
		system("mspaint.exe");
		m_strInput = _T("");
		UpdateData(FALSE);
	}
	if (UpperChar == "NOTE")
	{
		system("notepad.exe");
		m_strInput = _T("");
		UpdateData(FALSE);	
	}
	if (UpperChar == "EXIT")
	{
		OnOK();
	}
}


void CWinProExeDlg::OnClickedButtonClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_strInput = _T("");
	UpdateData(FALSE);
}


void CWinProExeDlg::OnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}
