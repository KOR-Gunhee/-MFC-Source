
// CountryTreeDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "CountryTree.h"
#include "CountryTreeDlg.h"
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


// CCountryTreeDlg ��ȭ ����



CCountryTreeDlg::CCountryTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_COUNTRYTREE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCountryTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_ASIA, m_ctrAsia);
	DDX_Control(pDX, IDC_TREE_EURO, m_ctrEuro);
}

BEGIN_MESSAGE_MAP(CCountryTreeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CHINA, &CCountryTreeDlg::OnClickedButtonChina)
	ON_BN_CLICKED(IDC_BUTTON_FRANCE, &CCountryTreeDlg::OnClickedButtonFrance)
	ON_BN_CLICKED(IDC_BUTTON_UK, &CCountryTreeDlg::OnClickedButtonUk)
END_MESSAGE_MAP()


// CCountryTreeDlg �޽��� ó����

BOOL CCountryTreeDlg::OnInitDialog()
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
	TVINSERTSTRUCT tInsert;

	HTREEITEM hAsia;
	HTREEITEM hKorea;
	HTREEITEM hJapan;
	HTREEITEM hKCity;
	HTREEITEM hJCity;
	HTREEITEM hKState;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("���Ͼƽþ�");
	hAsia = m_ctrAsia.InsertItem(&tInsert);

	tInsert.hParent = hAsia;
	tInsert.item.pszText = _T("�ѱ�");
	hKorea = m_ctrAsia.InsertItem(&tInsert);

	tInsert.hParent = hKorea;
	tInsert.item.pszText = _T("����");
	hKCity = m_ctrAsia.InsertItem(&tInsert);

	tInsert.hParent = hKCity;
	tInsert.item.pszText = _T("�ּ���");
	m_ctrAsia.InsertItem(&tInsert);

	tInsert.hParent = hKCity;
	tInsert.item.pszText = _T("�ѳ���");
	m_ctrAsia.InsertItem(&tInsert);

	tInsert.hParent = hKorea;
	tInsert.item.pszText = _T("�λ�");
	m_ctrAsia.InsertItem(&tInsert);

	tInsert.hParent = hAsia;
	tInsert.item.pszText = _T("�Ϻ�");
	hJapan = m_ctrAsia.InsertItem(&tInsert);

	tInsert.hParent = hJapan;
	tInsert.item.pszText = _T("����");
	m_ctrAsia.InsertItem(&tInsert);

	tInsert.hParent = hJapan;
	tInsert.item.pszText = _T("����ī");
	m_ctrAsia.InsertItem(&tInsert);

	HTREEITEM hGermany;
	HTREEITEM hItaly;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("����");
	hGermany = m_ctrEuro.InsertItem(&tInsert);

	tInsert.hParent = hGermany;
	tInsert.item.pszText = _T("����");
	m_ctrEuro.InsertItem(&tInsert);

	tInsert.hParent = hGermany;
	tInsert.item.pszText = _T("������");
	m_ctrEuro.InsertItem(&tInsert);

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("��Ż����");
	hItaly = m_ctrEuro.InsertItem(&tInsert);

	tInsert.hParent = hItaly;
	tInsert.item.pszText = _T("�θ�");
	m_ctrEuro.InsertItem(&tInsert);
	
	tInsert.hParent = hItaly;
	tInsert.item.pszText = _T("����ġ��");
	m_ctrEuro.InsertItem(&tInsert);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CCountryTreeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCountryTreeDlg::OnPaint()
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
HCURSOR CCountryTreeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCountryTreeDlg::OnClickedButtonChina()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	TVINSERTSTRUCT tInsert;

	HTREEITEM hChina;
	
	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("�߱�");
	hChina = m_ctrAsia.InsertItem(&tInsert);

	tInsert.hParent = hChina;
	tInsert.item.pszText = _T("����¡");
	m_ctrAsia.InsertItem(&tInsert);
}


void CCountryTreeDlg::OnClickedButtonFrance()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	TVINSERTSTRUCT tInsert;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("������");
	m_ctrEuro.InsertItem(&tInsert);
}


void CCountryTreeDlg::OnClickedButtonUk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	TVINSERTSTRUCT tInsert;

	HTREEITEM hUk;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("����");
	hUk = m_ctrEuro.InsertItem(&tInsert);

	tInsert.hParent = hUk;
	tInsert.item.pszText = _T("����");
	m_ctrEuro.InsertItem(&tInsert);
}
