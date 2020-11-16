
// AB_AREADlg.cpp : ���� ����
//

#include "stdafx.h"
#include "AB_AREA.h"
#include "AB_AREADlg.h"
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


// CAB_AREADlg ��ȭ ����



CAB_AREADlg::CAB_AREADlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_AB_AREA_DIALOG, pParent)
	, m_dCirR(0)
	, m_dCirResult(0)
	, m_dTriA(0)
	, m_dTriB(0)
	, m_dTriResult(0)
	, m_dRectA(0)
	, m_dRectB(0)
	, m_dRectResult(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAB_AREADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_AREA, m_tabArea);
	DDX_Text(pDX, IDC_EDIT_CIR_R, m_dCirR);
	DDX_Text(pDX, IDC_EDIT_CIR_RESULT, m_dCirResult);
	DDX_Text(pDX, IDC_EDIT_TRI_A, m_dTriA);
	DDX_Text(pDX, IDC_EDIT_TRI_B, m_dTriB);
	DDX_Text(pDX, IDC_EDIT_TRI_RESULT, m_dTriResult);
	DDX_Text(pDX, IDC_EDIT_RECT_A, m_dRectA);
	DDX_Text(pDX, IDC_EDIT_RECT_B, m_dRectB);
	DDX_Text(pDX, IDC_EDIT_RECT_RESULT, m_dRectResult);
}

BEGIN_MESSAGE_MAP(CAB_AREADlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_AREA, &CAB_AREADlg::OnSelchangeTabArea)
	ON_BN_CLICKED(IDC_BUTTON_CIR, &CAB_AREADlg::OnClickedButtonCir)
	ON_BN_CLICKED(IDC_BUTTON_RECT, &CAB_AREADlg::OnClickedButtonRect)
	ON_BN_CLICKED(IDC_BUTTON_TRI, &CAB_AREADlg::OnClickedButtonTri)
	ON_BN_CLICKED(IDC_BUTTON_SHOW, &CAB_AREADlg::OnClickedButtonShow)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CAB_AREADlg::OnClickedButtonExit)
END_MESSAGE_MAP()


// CAB_AREADlg �޽��� ó����

BOOL CAB_AREADlg::OnInitDialog()
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
	LPSTR tabName[3] = { _T("�ﰢ��"), _T("��"), _T("�簢��") };
	for (int nIndex = 0; nIndex < 3; nIndex++)
	{
		tabItem.mask = TCIF_TEXT;
		tabItem.pszText = tabName[nIndex];
		m_tabArea.InsertItem(nIndex, &tabItem);
	}
	GetDlgItem(IDC_STATIC_TRI)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_TRI_A)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_TRI_B)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_TRI_RESULT)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON_TRI)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_TRI_A)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_TRI_B)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_TRI_RESULT)->ShowWindow(TRUE);

	GetDlgItem(IDC_STATIC_CIR)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_CIR_R)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_CIR_RESULT)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON_CIR)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_CIR_R)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_CIR_RESULT)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_RECT)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_RECT_A)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_RECT_B)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_RECT_RESULT)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON_RECT)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_RECT_A)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_RECT_B)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_RECT_RESULT)->ShowWindow(FALSE);


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CAB_AREADlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAB_AREADlg::OnPaint()
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
HCURSOR CAB_AREADlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAB_AREADlg::OnSelchangeTabArea(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	int nSelect = m_tabArea.GetCurSel();

	switch (nSelect)
	{
	case 0:
		GetDlgItem(IDC_STATIC_TRI)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_TRI_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_TRI_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_TRI_RESULT)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON_TRI)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_TRI_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_TRI_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_TRI_RESULT)->ShowWindow(TRUE);
				   
		GetDlgItem(IDC_STATIC_CIR)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_CIR_R)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_CIR_RESULT)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_CIR)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_CIR_R)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_CIR_RESULT)->ShowWindow(FALSE);
						   
		GetDlgItem(IDC_STATIC_RECT)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_RECT_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_RECT_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_RECT_RESULT)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_RECT)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_RECT_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_RECT_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_RECT_RESULT)->ShowWindow(FALSE);
		break;

	case 1:
		GetDlgItem(IDC_STATIC_TRI)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TRI_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TRI_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TRI_RESULT)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_TRI)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TRI_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TRI_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TRI_RESULT)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_CIR)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_CIR_R)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_CIR_RESULT)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON_CIR)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_CIR_R)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_CIR_RESULT)->ShowWindow(TRUE);

		GetDlgItem(IDC_STATIC_RECT)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_RECT_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_RECT_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_RECT_RESULT)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_RECT)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_RECT_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_RECT_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_RECT_RESULT)->ShowWindow(FALSE);
		break;

	case 2:
		GetDlgItem(IDC_STATIC_TRI)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TRI_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TRI_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TRI_RESULT)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_TRI)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TRI_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TRI_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TRI_RESULT)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_CIR)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_CIR_R)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_CIR_RESULT)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_CIR)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_CIR_R)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_CIR_RESULT)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_RECT)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_RECT_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_RECT_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_RECT_RESULT)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON_RECT)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_RECT_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_RECT_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_RECT_RESULT)->ShowWindow(TRUE);
		break;
	}
	*pResult = 0;
}


void CAB_AREADlg::OnClickedButtonCir()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dCirResult = m_dCirR * m_dCirR * 3.14;
	UpdateData(FALSE);
}


void CAB_AREADlg::OnClickedButtonRect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dRectResult = m_dRectA * m_dRectB;
	UpdateData(FALSE);
}


void CAB_AREADlg::OnClickedButtonTri()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_dTriResult = m_dTriA * m_dTriB * 0.5;
	UpdateData(FALSE);
}


void CAB_AREADlg::OnClickedButtonShow()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	AfxMessageBox(_T("���� ���� = ������x������x3.14\n�ﰢ�� ���� = �غ�x����x0.5\n�簢�� ���� = ����x����"));
}


void CAB_AREADlg::OnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}
