
// MemExDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MemEx.h"
#include "MemExDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMemExDlg 대화 상자



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


// CMemExDlg 메시지 처리기

BOOL CMemExDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

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

		char *szText[4] = { "이름", "연락처", "선호관광지", "선호국가" };
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMemExDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

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
		sprintf_s(szText, "%s", _T("산"));
	}
	else
	{
		sprintf_s(szText, "%s", _T("바다"));
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Init();
}


void CMemExDlg::OnClickedButtonDel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}
