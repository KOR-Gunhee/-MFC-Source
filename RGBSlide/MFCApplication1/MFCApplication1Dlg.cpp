
// MFCApplication1Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
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


// CMFCApplication1Dlg ��ȭ ����



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, m_nR(0)
	, m_nG(0)
	, m_nB(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_R, m_sldR);
	DDX_Control(pDX, IDC_SLIDER_G, m_sldG);
	DDX_Control(pDX, IDC_SLIDER_B, m_sldB);
	DDX_Text(pDX, IDC_EDIT_R, m_nR);
	DDX_Text(pDX, IDC_EDIT_G, m_nG);
	DDX_Text(pDX, IDC_EDIT_B, m_nB);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CMFCApplication1Dlg::OnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CMFCApplication1Dlg::OnClickedButtonExit)
END_MESSAGE_MAP()


// CMFCApplication1Dlg �޽��� ó����

BOOL CMFCApplication1Dlg::OnInitDialog()
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

	/* ------ ��Ʈ�� ���� ���� 256 �÷� ���� ---------*/

	m_sldR.SetRange(0, 255);
	m_sldG.SetRange(0, 255);
	m_sldB.SetRange(0, 255);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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

		CRect rect;
		CClientDC rgbdc(GetDlgItem(IDC_STATIC_RGB));
		CStatic *pSRGB = (CStatic *)GetDlgItem(IDC_STATIC_RGB);
		pSRGB->GetClientRect(rect);
		rgbdc.FillSolidRect(rect, m_cRGB);
		pSRGB->ValidateRect(rect);
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CRect rect;GetDlgItem(IDC_STATIC_RGB)->GetWindowRect(&rect);
	ScreenToClient(&rect);
	int nR = m_sldR.GetPos();
	int nG = m_sldR.GetPos();
	int nB = m_sldR.GetPos();

	if ((pScrollBar == (CScrollBar*)&m_sldR) || (pScrollBar == (CScrollBar*)&m_sldG) || (pScrollBar == (CScrollBar*)&m_sldB))
	{
		int nPosR = m_sldR.GetPos();
		int nPosG = m_sldG.GetPos();
		int nPosB = m_sldB.GetPos();

		m_nR = nPosR;
		m_nG = nPosG;
		m_nB = nPosB;

		m_cRGB = RGB(m_nR, m_nG, m_nB);
		UpdateData(FALSE);
		InvalidateRect(&rect);
	}
	else
	{
		CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	}	
}


void CMFCApplication1Dlg::Clear()
{
	UpdateData(TRUE);

	CRect rect;
	GetDlgItem(IDC_STATIC_RGB)->GetWindowRect(&rect);

	ScreenToClient(&rect);
	InvalidateRect(&rect);

	m_cRGB = RGB(0, 0, 0);

	m_sldR.SetPos(0);
	m_sldG.SetPos(0);
	m_sldB.SetPos(0);

	m_nR = 0;
	m_nG = 0;
	m_nB = 0;

	m_cRGB = RGB(0, 0, 0);
	UpdateData(FALSE);
}


void CMFCApplication1Dlg::OnClickedButtonClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Clear();
}


void CMFCApplication1Dlg::OnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}
