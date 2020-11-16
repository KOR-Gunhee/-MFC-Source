
// MessageBoxesDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MessageBoxes.h"
#include "MessageBoxesDlg.h"
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


// CMessageBoxesDlg ��ȭ ����



CMessageBoxesDlg::CMessageBoxesDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MESSAGEBOXES_DIALOG, pParent)
	, m_strResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMessageBoxesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_strResult);
}

BEGIN_MESSAGE_MAP(CMessageBoxesDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_YN, &CMessageBoxesDlg::OnBnClickedButtonYn)
	ON_BN_CLICKED(IDC_BUTTON_OC, &CMessageBoxesDlg::OnBnClickedButtonOc)
	ON_BN_CLICKED(IDC_BUTTON_YNC, &CMessageBoxesDlg::OnBnClickedButtonYnc)
	ON_BN_CLICKED(IDC_BUTTON_RC, &CMessageBoxesDlg::OnBnClickedButtonRc)
	ON_BN_CLICKED(IDC_BUTTON_ARI, &CMessageBoxesDlg::OnBnClickedButtonAri)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CMessageBoxesDlg::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_MFC, &CMessageBoxesDlg::OnBnClickedButtonMfc)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CMessageBoxesDlg::OnBnClickedButtonExit)
END_MESSAGE_MAP()


// CMessageBoxesDlg �޽��� ó����

BOOL CMessageBoxesDlg::OnInitDialog()
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

void CMessageBoxesDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMessageBoxesDlg::OnPaint()
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
HCURSOR CMessageBoxesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMessageBoxesDlg::OnBnClickedButtonYn()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int iResults;
	iResults = AfxMessageBox(_T("YES/NO ��ư�� �����̽��ϴ�"), (MB_YESNO | MB_ICONWARNING));
	if (iResults == IDYES)
	{
		m_strResult = _T("YES ��ư�� �����̽��ϴ�!");
		UpdateData(FALSE);
	}
	if (iResults == IDNO)
	{
		m_strResult = _T("NO ��ư�� �����̽��ϴ�!");
		UpdateData(FALSE);
	}
}


void CMessageBoxesDlg::OnBnClickedButtonOc()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int iResults;
	iResults = AfxMessageBox(_T("OK/CANCEL ��ư�� �����̽��ϴ�"), (MB_OKCANCEL | MB_ICONSTOP));
	if (iResults == IDOK)
	{
		m_strResult = _T("OK ��ư�� �����̽��ϴ�!");
		UpdateData(FALSE);
	}
	if (iResults == IDCANCEL)
	{
		m_strResult = _T("CANCEL ��ư�� �����̽��ϴ�!");
		UpdateData(FALSE);
	}
}


void CMessageBoxesDlg::OnBnClickedButtonYnc()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int iResults;
	iResults = AfxMessageBox(_T("YES/NO/CANCEL ��ư�� �����̽��ϴ�"), (MB_YESNOCANCEL | MB_ICONINFORMATION));
	if (iResults == IDYES)
	{
		m_strResult = _T("YES ��ư�� �����̽��ϴ�!");
		UpdateData(FALSE);
	}
	if (iResults == IDNO)
	{
		m_strResult = _T("NO ��ư�� �����̽��ϴ�!");
		UpdateData(FALSE);
	}
	if (iResults == IDCANCEL)
	{
		m_strResult = _T("CANCEL ��ư�� �����̽��ϴ�!");
		UpdateData(FALSE);
	}
}


void CMessageBoxesDlg::OnBnClickedButtonRc()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int iResults;
	iResults = AfxMessageBox(_T("RETRY/CANCEL ��ư�� �����̽��ϴ�"), (MB_RETRYCANCEL | MB_ICONQUESTION));
	if (iResults == IDRETRY)
	{
		m_strResult = _T("RETRY ��ư�� �����̽��ϴ�!");
		UpdateData(FALSE);
	}
	if (iResults == IDCANCEL)
	{
		m_strResult = _T("CANCEL ��ư�� �����̽��ϴ�!");
		UpdateData(FALSE);
	}
}


void CMessageBoxesDlg::OnBnClickedButtonAri()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int iResults;
	iResults = AfxMessageBox(_T("ABORT/RETRY/IGNORE ��ư�� �����̽��ϴ�"), (MB_ABORTRETRYIGNORE | MB_ICONINFORMATION));
	if (iResults == IDABORT)
	{
		m_strResult = _T("ABORT ��ư�� �����̽��ϴ�!");
		UpdateData(FALSE);
	}
	if (iResults == IDRETRY)
	{
		m_strResult = _T("RETRY ��ư�� �����̽��ϴ�!");
		UpdateData(FALSE);
	}
	if (iResults == IDIGNORE)
	{
		m_strResult = _T("IGNORE ��ư�� �����̽��ϴ�!");
		UpdateData(FALSE);
	}
}


void CMessageBoxesDlg::OnBnClickedButtonOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int iResults;
	iResults = AfxMessageBox(_T("OK ��ư�� �����̽��ϴ�"), (MB_OK | MB_ICONSTOP));
	if (iResults == IDOK)
	{
		m_strResult = _T("OK ��ư�� �����̽��ϴ�!");
		UpdateData(FALSE);
	}

}


void CMessageBoxesDlg::OnBnClickedButtonMfc()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	MessageBox(_T("Microsoft Foundation Class �Դϴ�."));
}


void CMessageBoxesDlg::OnBnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}
