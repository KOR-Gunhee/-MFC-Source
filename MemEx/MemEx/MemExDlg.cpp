
// MemExDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MemEx.h"
#include "MemExDlg.h"
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


// CMemExDlg ��ȭ ����



CMemExDlg::CMemExDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MEMEX_DIALOG, pParent)
	, m_strName(_T(""))
	, m_strCell(_T(""))
	, m_nSelected(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMemExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_CELL, m_strCell);
	DDX_Control(pDX, IDC_RADIO_MOUNTAIN, m_rMountain);
	DDX_Control(pDX, IDC_COMBO_COUNTRY, m_cbCountry);
	DDX_Control(pDX, IDC_LIST_VIEW, m_listView);
}

BEGIN_MESSAGE_MAP(CMemExDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_INPUT, &CMemExDlg::OnClickedButtonInput)
	ON_BN_CLICKED(IDC_BUTTON_INIT, &CMemExDlg::OnClickedButtonInit)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CMemExDlg::OnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CMemExDlg::OnClickedButtonExit)
END_MESSAGE_MAP()


// CMemExDlg �޽��� ó����

BOOL CMemExDlg::OnInitDialog()
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

	for (int i= 0; i < 4; i++)
	{
		if (i == 0)
		{
			CString sIndex;
			sIndex.Format(_T("Korea"));
			m_cbCountry.AddString(sIndex);
			m_nSelected = 0;
		}
		else if (i == 1)
		{
			CString sIndex;
			sIndex.Format(_T("Japan"));
			m_cbCountry.AddString(sIndex);
			m_nSelected = 1;
		}
		else if (i == 2)
		{
			CString sIndex;
			sIndex.Format(_T("China"));
			m_cbCountry.AddString(sIndex);
			m_nSelected = 2;
		}
		else if (i == 3)
		{
			CString sIndex;
			sIndex.Format(_T("America"));
			m_cbCountry.AddString(sIndex);
			m_nSelected = 3;
		}

		char *szText[4] = { "�̸�", "����ó", "��ȣ������", "��ȣ����" };
		int nWidth[4] = { 50, 70, 50, 100, };

		LVCOLUMN iCol;
		iCol.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		iCol.fmt = LVCFMT_LEFT;
		m_listView.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

		for (int i = 0; i < 4; i++)
		{
			iCol.pszText = szText[i];
			iCol.iSubItem = i;
			iCol.cx = nWidth[i];
			m_listView.SetColumn(i, &iCol);
		}
	}

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMemExDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMemExDlg::OnPaint()
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
HCURSOR CMemExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMemExDlg::Init()
{
	UpdateData(TRUE);
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_EDIT_NAME);

	m_strName.Empty();
	m_strCell.Empty();

	m_rMountain.SetCheck(BST_UNCHECKED);

	m_cbCountry.SetCurSel(0);

	pEdit->SetFocus();
	UpdateData(FALSE);
}


void CMemExDlg::OnClickedButtonInput()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	char szText[100] = "";
	int nIndex = 0;
	UpdateData(TRUE);
	LVITEM iItem;
	iItem.mask = LVIF_TEXT;
	iItem.iItem = nIndex;

	iItem.iSubItem = 0;
	sprintf_s(szText, "%s", m_strName);
	iItem.pszText = (LPSTR)szText;
	m_listView.InsertItem(&iItem);

	iItem.iSubItem = 1;
	sprintf_s(szText, "%s", m_strCell);
	iItem.pszText = (LPSTR)szText;
	m_listView.InsertItem(&iItem);

	iItem.iSubItem = 2;

	if (m_rMountain.GetCheck() == BST_CHECKED)
	{
		sprintf_s(szText, "%s", _T("��"));
	}
	else
	{
		sprintf_s(szText, "%s", _T("�ٴ�"));
	}
	iItem.pszText = (LPSTR)szText;
	m_listView.SetItem(&iItem);

	if (m_nSelected == 0)
	{
		iItem.iSubItem = 3;
		sprintf_s(szText, "%s", _T("KOREA"));
		iItem.pszText = (LPSTR)szText;
		m_listView.SetItem(&iItem);
	}
	else if (m_nSelected == 1)
	{
		iItem.iSubItem = 3;
		sprintf_s(szText, "%s", _T("JAPAN"));
		iItem.pszText = (LPSTR)szText;
		m_listView.SetItem(&iItem);
	}
	else if (m_nSelected == 2)
	{
		iItem.iSubItem = 3;
		sprintf_s(szText, "%s", _T("CHINA"));
		iItem.pszText = (LPSTR)szText;
		m_listView.SetItem(&iItem);
	}
	else if (m_nSelected == 3)
	{
		iItem.iSubItem = 3;
		sprintf_s(szText, "%s", _T("AMERICA"));
		iItem.pszText = (LPSTR)szText;
		m_listView.SetItem(&iItem);
	}

}

void CMemExDlg::OnClickedButtonInit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Init();
}


void CMemExDlg::OnClickedButtonDel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	for (int nItem = 0; nItem < m_listView.GetItemCount();)
	{
		if (m_listView.GetItemState(nItem, LVIS_SELECTED) == LVIS_SELECTED)
			m_listView.DeleteItem(nItem);
		else
			++nItem;
	}
	UpdateData(FALSE);
}


void CMemExDlg::OnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}
