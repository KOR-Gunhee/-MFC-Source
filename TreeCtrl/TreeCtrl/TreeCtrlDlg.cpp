
// TreeCtrlDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "TreeCtrl.h"
#include "TreeCtrlDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


char pszMenuJuiceInfo[2][100] = { "����� ���� �꽺", "�������� ���� �꽺" };
char pszMenuCoffeeInfo[3][100] = { "���� ���� ������ Coffee", "�ÿ��� ���̽� Ŀ��", "������ Ŀ��" };
char pszMenuDessertInfo[3][100] = { "�ż��� �ٴҶ� ���̽�ũ��", "���ݸ��� ��� �� ���� ����ũ", "�����ϰ� �ε巯�� ġ�� ����ũ" };

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


// CTreeCtrlDlg ��ȭ ����



CTreeCtrlDlg::CTreeCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TREECTRL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTreeCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_MENU, m_ctrMenu);
}

BEGIN_MESSAGE_MAP(CTreeCtrlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DESSERT, &CTreeCtrlDlg::OnClickedButtonDessert)
	ON_BN_CLICKED(IDC_BUTTON_DRINK, &CTreeCtrlDlg::OnClickedButtonDrink)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CTreeCtrlDlg::OnClickedButtonExit)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_MENU, &CTreeCtrlDlg::OnSelchangedTreeMenu)
END_MESSAGE_MAP()


// CTreeCtrlDlg �޽��� ó����

BOOL CTreeCtrlDlg::OnInitDialog()
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

	HTREEITEM hDrink;

	HTREEITEM hDrinkCoffee;

	HTREEITEM hHotCold;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("����");
	hDrink = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDrink;
	tInsert.item.pszText = _T("Ŀ��");
	hDrinkCoffee = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDrinkCoffee;
	tInsert.item.pszText = _T("�Ƹ޸�ī��");
	hHotCold = m_ctrMenu.InsertItem(&tInsert);
	
	tInsert.hParent = hHotCold;
	tInsert.item.pszText = _T("������ �Ƹ޸�ī��");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hHotCold;
	tInsert.item.pszText = _T("���̽� �Ƹ޸�ī��");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hHotCold;
	tInsert.item.pszText = _T("īǪġ��");
	m_ctrMenu.InsertItem(&tInsert);	

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CTreeCtrlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTreeCtrlDlg::OnPaint()
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
HCURSOR CTreeCtrlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTreeCtrlDlg::OnClickedButtonDessert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	TVINSERTSTRUCT tInsert;

	HTREEITEM hDessert;

	HTREEITEM hDessertSort;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("����Ʈ");
	hDessert = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDessert;
	tInsert.item.pszText = _T("����ũ");
	hDessert = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDessert;
	tInsert.item.pszText = _T("��������ũ");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDessert;
	tInsert.item.pszText = _T("ġ������ũ");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDessert;
	tInsert.item.pszText = _T("���̽�ũ��");
	hDessertSort = m_ctrMenu.InsertItem(&tInsert);
}


void CTreeCtrlDlg::OnClickedButtonDrink()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	TVINSERTSTRUCT tInsert;

	HTREEITEM hOtherDrink;

	HTREEITEM hDrinkJuice;

	tInsert.hParent = 0;
	tInsert.hInsertAfter = TVI_SORT;
	tInsert.item.mask = TVIF_TEXT;
	tInsert.item.pszText = _T("��Ÿ����");
	hOtherDrink = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hOtherDrink;
	tInsert.item.pszText = _T("�꽺");
	hDrinkJuice = m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDrinkJuice;
	tInsert.item.pszText = _T("���");
	m_ctrMenu.InsertItem(&tInsert);

	tInsert.hParent = hDrinkJuice;
	tInsert.item.pszText = _T("������");
	m_ctrMenu.InsertItem(&tInsert);
}


void CTreeCtrlDlg::OnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


void CTreeCtrlDlg::OnSelchangedTreeMenu(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	HTREEITEM hItemParent, hItemCur;
	CString strParent = _T("");
	CString strChild = _T("");

	hItemCur = pNMTreeView->itemNew.hItem;
	hItemParent = m_ctrMenu.GetParentItem(hItemCur);

	strChild = m_ctrMenu.GetItemText(hItemCur);
	strParent = m_ctrMenu.GetItemText(hItemParent);

	if (strParent == "�꽺")
	{
		if (strChild == "���")
		{
			::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuJuiceInfo[0]);
		}

		else if (strChild == "������")
		{
			::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuJuiceInfo[1]);
		}
	}

	if (strParent == "�Ƹ޸�ī��")
	{
		if (strChild == "������ �Ƹ޸�ī��")
		{
			::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuCoffeeInfo[0]);
		}

		else if (strChild == "���̽� �Ƹ޸�ī��")
		{
			::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuCoffeeInfo[1]);
		}
	}

	if (strParent == "Ŀ��")
	{
		if (strChild == "īǪġ��")
		{
			::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuCoffeeInfo[2]);
		}
	}

	if (strParent == "����Ʈ")
	{
		if (strChild == "���̽�ũ��")
		{
			::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuDessertInfo[0]);
		}
	}

	if (strParent == "����ũ")
	{
		if (strChild == "��������ũ")
		{
			::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuDessertInfo[1]);
		}

		else if (strChild == "ġ������ũ")
		{
			::SetDlgItemTextA(this->m_hWnd, IDC_EDIT_MENUINFO, pszMenuDessertInfo[2]);
		}
	}
	*pResult = 0;
}
