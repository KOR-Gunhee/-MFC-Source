
// EnrollmentDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Enrollment.h"
#include "EnrollmentDlg.h"
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


// CEnrollmentDlg ��ȭ ����



CEnrollmentDlg::CEnrollmentDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ENROLLMENT_DIALOG, pParent)
	, m_strName(_T(""))
	, m_strNum(_T(""))
	, m_strCell(_T(""))
	, m_chA(FALSE)
	, m_chB(FALSE)
	, m_nSelected(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEnrollmentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_NUM, m_strNum);
	DDX_Text(pDX, IDC_EDIT_CELL, m_strCell);
	DDX_Check(pDX, IDC_CHECK_A, m_chA);
	DDX_Check(pDX, IDC_CHECK_B, m_chB);
	DDX_Control(pDX, IDC_RADIO_ONLINE, m_rOnline);
	DDX_Control(pDX, IDC_COMBO_POINT1, m_cbPoint1);
	DDX_Control(pDX, IDC_COMBO_POINT2, m_cbPoint2);
	DDX_Control(pDX, IDC_LIST_VIEW, m_listView);
}

BEGIN_MESSAGE_MAP(CEnrollmentDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_INPUT, &CEnrollmentDlg::OnClickedButtonInput)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CEnrollmentDlg::OnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_INIT, &CEnrollmentDlg::OnClickedButtonInit)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CEnrollmentDlg::OnClickedButtonExit)
END_MESSAGE_MAP()


// CEnrollmentDlg �޽��� ó����

BOOL CEnrollmentDlg::OnInitDialog()
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

	for (int i = 0; i < 11; i++)
	{
		CString sIndex;
		sIndex.Format(_T("%d"), i);
		m_cbPoint1.AddString(sIndex);
	}

	for (int i = 0; i < 11; i++)
	{
		CString sIndex;
		sIndex.Format(_T("%d"), i);
		m_cbPoint2.AddString(sIndex);
	}

	char *szText[6] = { "�й�", "�̸�", "����ó", "��Ϲ��", "��������", "�ѹ���" };
	int nWidth[6] = { 50, 70, 100, 70, 70, 70, };

	LV_COLUMN iCol;
	iCol.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	iCol.fmt = LVCFMT_LEFT;
	m_listView.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

	for (int i = 0; i < 6; i++)
	{
		iCol.pszText = szText[i];
		iCol.iSubItem = i;
		iCol.cx = nWidth[i];
		m_listView.InsertColumn(i, &iCol);
	}

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CEnrollmentDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEnrollmentDlg::OnPaint()
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
HCURSOR CEnrollmentDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CEnrollmentDlg::Init()
{
	UpdateData(TRUE);

	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_EDIT_NUM);

	m_strName.Empty();
	m_strNum.Empty();
	m_strCell.Empty();

	m_chA = m_chB = FALSE;

	m_rOnline.SetCheck(BST_UNCHECKED);

	m_cbPoint1.SetCurSel(0);
	m_cbPoint2.SetCurSel(0);

	pEdit->SetFocus();
	UpdateData(FALSE);
}


void CEnrollmentDlg::OnClickedButtonInput()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	char szText[100] = "";
	int nIndex = 0;
	UpdateData(TRUE);
	LVITEM iItem;
	iItem.mask = LVIF_TEXT;
	iItem.iItem = nIndex;

	iItem.iSubItem = 0;
	sprintf_s(szText, "&s", m_strNum);
	iItem.pszText = (LPSTR)szText;
	m_listView.InsertItem(&iItem);

	iItem.iSubItem = 1;
	sprintf_s(szText, "%s", m_strName);
	iItem.pszText = (LPSTR)szText;
	m_listView.InsertItem(&iItem);
	
	iItem.iSubItem = 2;
	sprintf_s(szText, "%s", m_strCell);
	iItem.pszText = (LPSTR)szText;
	m_listView.InsertItem(&iItem);

	iItem.iSubItem = 3;

	if (m_rOnline.GetCheck() == BST_CHECKED)
	{
		sprintf_s(szText, "%s", _T("�¶���"));
	}

	else
	{
		sprintf_s(szText, "%s", _T("�湮"));
	}

	iItem.pszText = (LPSTR)szText;
	m_listView.SetItem(&iItem);

	CString selCombo1, selCombo2;

	if ((m_chA == TRUE) && (m_chB == FALSE))
	{
		m_cbPoint1.GetLBText(m_cbPoint1.GetCurSel(), selCombo1);

		int cb10 = 0;
		int sum10 = 0;

		cb10 = _ttoi(selCombo1);
		sum10 = sum10 + cb10 * 20;

		iItem.iSubItem = 4;
		sprintf_s(szText, "%s", _T("�ְ���"));
		iItem.pszText = (LPSTR)szText;
		m_listView.InsertItem(&iItem);

		iItem.iSubItem = 5;
		sprintf_s(szText, "%s", sum10);
		iItem.pszText = (LPSTR)szText;
		m_listView.InsertItem(&iItem);
	}

	else if ((m_chA == FALSE) && (m_chB == TRUE))
	{
		m_cbPoint2.GetLBText(m_cbPoint2.GetCurSel(), selCombo2);

		int cb20 = 0;
		int sum20 = 0;

		cb20 = _ttoi(selCombo2);
		sum20 = sum20 + cb20 * 10;

		iItem.iSubItem = 4;
		sprintf_s(szText, "%s", _T("������"));
		iItem.pszText = (LPSTR)szText;
		m_listView.InsertItem(&iItem);

		iItem.iSubItem = 5;
		sprintf_s(szText, "%s", sum20);
		iItem.pszText = (LPSTR)szText;
		m_listView.InsertItem(&iItem);
	}

	else if ((m_chA == FALSE) && (m_chB == TRUE))
	{
		m_cbPoint1.GetLBText(m_cbPoint1.GetCurSel(), selCombo1);
		m_cbPoint2.GetLBText(m_cbPoint2.GetCurSel(), selCombo2);

		int cb30 = _ttoi(selCombo1);
		int cb31 = _ttoi(selCombo2);
		int sum30 = 0;
		sum30 - cb30 * 20 + cb31 * 10;

		iItem.iSubItem = 4;
		sprintf_s(szText, "%s", _T("ȥ����"));
		iItem.pszText = (LPSTR)szText;
		m_listView.InsertItem(&iItem);

		iItem.iSubItem = 5;
		sprintf_s(szText, "%s", sum30);
		iItem.pszText = (LPSTR)szText;
		m_listView.InsertItem(&iItem);
	}

	else if ((m_chA == FALSE) && (m_chB == FALSE))
	{
		MessageBox(_T("���� ������ �����ϼ���"), _T("�Է¿���"), MB_ICONSTOP | MB_OK);
	}

	Init();
	nIndex++;
	UpdateData(FALSE);
}


void CEnrollmentDlg::OnClickedButtonDel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	for (int nItem = 0; nItem < m_listView.GetItemCount();)
	{
		if (m_listView.GetItemState(nItem, LVIS_SELECTED) == LVIS_SELECTED) m_listView.DeleteItem(nItem);
		else
			++nItem;
	}
	UpdateData(FALSE);
}


void CEnrollmentDlg::OnClickedButtonInit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Init();
}


void CEnrollmentDlg::OnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}

