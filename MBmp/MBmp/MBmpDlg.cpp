
// MBmpDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MBmp.h"
#include "MBmpDlg.h"
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


// CMBmpDlg ��ȭ ����



CMBmpDlg::CMBmpDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MBMP_DIALOG, pParent)
	, m_menuID(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMBmpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMBmpDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_EXIT, &CMBmpDlg::OnFileExit)
	ON_COMMAND(ID_HELP_ABOUT, &CMBmpDlg::OnHelpAbout)
	ON_WM_SIZE()
	ON_COMMAND(ID_ZOOM_IN, &CMBmpDlg::OnZoomIn)
	ON_COMMAND(ID_ZOOM_OUT, &CMBmpDlg::OnZoomOut)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CMBmpDlg::OnClickedButtonExit)
END_MESSAGE_MAP()


// CMBmpDlg �޽��� ó����

BOOL CMBmpDlg::OnInitDialog()
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

void CMBmpDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMBmpDlg::OnPaint()
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
		CPaintDC dc(this);
		HBITMAP hbitmap = ::LoadBitmap(m_hInstance, MAKEINTRESOURCE(IDB_BITMAP1));

		HDC hMemDC = ::CreateCompatibleDC(NULL);

		SelectObject(hMemDC, hbitmap);

		switch (m_menuID)
		{

		case ID_ZOOM_IN:
			::StretchBlt(dc.m_hDC, 0, 0, m_nWidth, m_nHeight, hMemDC, 0, 0, 300, 300, SRCCOPY);
			break;

		case ID_ZOOM_OUT:
			::StretchBlt(dc.m_hDC, 0, 0, 150, 150, hMemDC, 0, 0, 300, 300, SRCCOPY);
			break;

		default:
			::StretchBlt(dc.m_hDC, 50, 50, 300, 300, hMemDC, 0, 0, 250, 250, SRCCOPY);
		}

		::DeleteDC(hMemDC);
		::DeleteObject(hbitmap);

		//////////////////////////////
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMBmpDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMBmpDlg::OnFileExit()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


void CMBmpDlg::OnHelpAbout()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CAboutDlg dlg;
	dlg.DoModal();
}


void CMBmpDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	m_nWidth = cx;
	m_nHeight = cy;
	Invalidate();
}


void CMBmpDlg::OnZoomIn()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_menuID = ID_ZOOM_IN;
	Invalidate();
}


void CMBmpDlg::OnZoomOut()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_menuID = ID_ZOOM_OUT;
	Invalidate();
}


void CMBmpDlg::OnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}
