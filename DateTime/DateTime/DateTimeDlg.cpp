
// DateTimeDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "DateTime.h"
#include "DateTimeDlg.h"
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


// CDateTimeDlg ��ȭ ����



CDateTimeDlg::CDateTimeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DATETIME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDateTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDateTimeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDateTimeDlg �޽��� ó����

BOOL CDateTimeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.
	CRect rect;
	screen.top = 0;
	screen.left = 0;
	screen.bottom = ::GetSystemMetrics(SM_CYSCREEN);
	screen.right = ::GetSystemMetrics(SM_CXSCREEN);

	htimer = SetTimer(1, 1000, NULL);

	GetWindowRect(rect);
	vsize = rect.Width();
	hsize = rect.Height();

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

void CDateTimeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDateTimeDlg::OnPaint()
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
HCURSOR CDateTimeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDateTimeDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CTime gct = CTime::GetCurrentTime();

	CString strYear;
	CString strMonth;
	CString strDay;
	CString strAp;
	CString strTime;
	CString strAweek;

	strYear.Format(_T("%d ��"), gct.GetYear());
	GetDlgItem(IDC_STATIC_YEAR)->SetWindowText((LPCTSTR)strYear);

	strMonth.Format(_T("%d ��"), gct.GetMonth());
	GetDlgItem(IDC_STATIC_MONTH)->SetWindowText((LPCTSTR)strMonth);

	strDay.Format(_T("%d ��"), gct.GetDay());
	GetDlgItem(IDC_STATIC_DAY)->SetWindowText((LPCTSTR)strDay);

	if ((gct.GetHour() - 12) >= 0)
	{
		strAp.Format(_T("����"));
		GetDlgItem(IDC_STATIC_AP)->SetWindowText((LPCTSTR)strAp);
	}
	else if ((gct.GetHour() - 12) < 0)
	{
		strAp.Format(_T("����"));
		GetDlgItem(IDC_STATIC_AP)->SetWindowText((LPCTSTR)strAp);
	}

	strTime.Format(_T("%d �� %d �� %d ��"), gct.GetHour(), gct.GetMinute(), gct.GetSecond());
	GetDlgItem(IDC_STATIC_TIME)->SetWindowText((LPCTSTR)strTime);

	if (gct.GetDayOfWeek() == 1)
	{
		strAweek.Format(_T("�Ͽ���"));
		GetDlgItem(IDC_STATIC_AWEEK)->SetWindowText((LPCTSTR)strAweek);
	}
	else if (gct.GetDayOfWeek() == 2)
	{
		strAweek.Format(_T("������"));
		GetDlgItem(IDC_STATIC_AWEEK)->SetWindowText((LPCTSTR)strAweek);
	}
	else if (gct.GetDayOfWeek() == 3)
	{
		strAweek.Format(_T("ȭ����"));
		GetDlgItem(IDC_STATIC_AWEEK)->SetWindowText((LPCTSTR)strAweek);
	}
	else if (gct.GetDayOfWeek() == 4)
	{
		strAweek.Format(_T("������"));
		GetDlgItem(IDC_STATIC_AWEEK)->SetWindowText((LPCTSTR)strAweek);
	}
	else if (gct.GetDayOfWeek() == 5)
	{
		strAweek.Format(_T("�����"));
		GetDlgItem(IDC_STATIC_AWEEK)->SetWindowText((LPCTSTR)strAweek);
	}
	else if (gct.GetDayOfWeek() == 6)
	{
		strAweek.Format(_T("�ݿ���"));
		GetDlgItem(IDC_STATIC_AWEEK)->SetWindowText((LPCTSTR)strAweek);
	}
	else if (gct.GetDayOfWeek() == 7)
	{
		strAweek.Format(_T("�����"));
		GetDlgItem(IDC_STATIC_AWEEK)->SetWindowText((LPCTSTR)strAweek);
	}

	Invalidate();

	CDialogEx::OnTimer(nIDEvent);
}
