
// TabExDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "TabEx.h"
#include "TabExDlg.h"
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


// CTabExDlg 대화 상자



CTabExDlg::CTabExDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TABEX_DIALOG, pParent)
	, m_dEngA(0)
	, m_dEngB(0)
	, m_dEngC(0)
	, m_dEngD(0)
	, m_dEngTotal(0)
	, m_dKorA(0)
	, m_dKorB(0)
	, m_dKorC(0)
	, m_dKorTotal(0)
	, m_dMathA(0)
	, m_dMathB(0)
	, m_dMathC(0)
	, m_dMathTotal(0)
	, m_dTotal(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTabExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_AREA, m_tabArea);
	DDX_Text(pDX, IDC_EDIT_ENG_A, m_dEngA);
	DDX_Text(pDX, IDC_EDIT_ENG_B, m_dEngB);
	DDX_Text(pDX, IDC_EDIT_ENG_C, m_dEngC);
	DDX_Text(pDX, IDC_EDIT_ENG_D, m_dEngD);
	DDX_Text(pDX, IDC_EDIT_ENG_TOTAL, m_dEngTotal);
	DDX_Text(pDX, IDC_EDIT_KOR_A, m_dKorA);
	DDX_Text(pDX, IDC_EDIT_KOR_B, m_dKorB);
	DDX_Text(pDX, IDC_EDIT_KOR_C, m_dKorC);
	DDX_Text(pDX, IDC_EDIT_KOR_TOTAL, m_dKorTotal);
	DDX_Text(pDX, IDC_EDIT_MATH_A, m_dMathA);
	DDX_Text(pDX, IDC_EDIT_MATH_B, m_dMathB);
	DDX_Text(pDX, IDC_EDIT_MATH_C, m_dMathC);
	DDX_Text(pDX, IDC_EDIT_MATH_TOTAL, m_dMathTotal);
	DDX_Text(pDX, IDC_EDIT_TOTAL, m_dTotal);
}

BEGIN_MESSAGE_MAP(CTabExDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_AREA, &CTabExDlg::OnSelchangeTabArea)
	ON_BN_CLICKED(IDC_BUTTON_ENG_TOTAL, &CTabExDlg::OnClickedButtonEngTotal)
	ON_BN_CLICKED(IDC_BUTTON_MATH_TOTAL, &CTabExDlg::OnClickedButtonMathTotal)
	ON_BN_CLICKED(IDC_BUTTON_KOR_TOTAL, &CTabExDlg::OnClickedButtonKorTotal)
	ON_BN_CLICKED(IDC_BUTTON_TOTAL, &CTabExDlg::OnClickedButtonTotal)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CTabExDlg::OnClickedButtonExit)
END_MESSAGE_MAP()


// CTabExDlg 메시지 처리기

BOOL CTabExDlg::OnInitDialog()
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

	TC_ITEM tabItem;
	LPSTR tabName[3] = { _T("영어성적"), _T("수학성적"), _T("국어성적") };
	for (int nIndex = 0; nIndex < 3; nIndex++)
	{
		tabItem.mask = TCIF_TEXT;
		tabItem.pszText = tabName[nIndex];
		m_tabArea.InsertItem(nIndex, &tabItem);	
	}
	
	GetDlgItem(IDC_STATIC_ENG_A)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_ENG_B)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_ENG_C)->ShowWindow(TRUE);
	GetDlgItem(IDC_STATIC_ENG_D)->ShowWindow(TRUE);
	GetDlgItem(IDC_BUTTON_ENG_TOTAL)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_ENG_A)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_ENG_B)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_ENG_C)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_ENG_D)->ShowWindow(TRUE);
	GetDlgItem(IDC_EDIT_ENG_TOTAL)->ShowWindow(TRUE);

	GetDlgItem(IDC_STATIC_MATH_A)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_MATH_B)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_MATH_C)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON_MATH_TOTAL)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_MATH_A)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_MATH_B)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_MATH_C)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_MATH_TOTAL)->ShowWindow(FALSE);

	GetDlgItem(IDC_STATIC_KOR_A)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_KOR_B)->ShowWindow(FALSE);
	GetDlgItem(IDC_STATIC_KOR_C)->ShowWindow(FALSE);
	GetDlgItem(IDC_BUTTON_KOR_TOTAL)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_KOR_A)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_KOR_B)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_KOR_C)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_KOR_TOTAL)->ShowWindow(FALSE);
	
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTabExDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTabExDlg::OnPaint()
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
HCURSOR CTabExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTabExDlg::OnSelchangeTabArea(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	int nSelect = m_tabArea.GetCurSel();

	switch (nSelect)
	{
	case 0:
		GetDlgItem(IDC_STATIC_ENG_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_ENG_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_ENG_C)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_ENG_D)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON_ENG_TOTAL)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_ENG_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_ENG_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_ENG_C)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_ENG_D)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_ENG_TOTAL)->ShowWindow(TRUE);

		GetDlgItem(IDC_STATIC_MATH_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_MATH_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_MATH_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_MATH_TOTAL)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_TOTAL)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_KOR_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_KOR_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_KOR_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_KOR_TOTAL)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_TOTAL)->ShowWindow(FALSE);
		break;

	case 1:
		GetDlgItem(IDC_STATIC_ENG_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_ENG_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_ENG_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_ENG_D)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_ENG_TOTAL)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_D)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_TOTAL)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_MATH_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_MATH_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_MATH_C)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON_MATH_TOTAL)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_MATH_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_MATH_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_MATH_C)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_MATH_TOTAL)->ShowWindow(TRUE);

		GetDlgItem(IDC_STATIC_KOR_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_KOR_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_KOR_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_KOR_TOTAL)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_KOR_TOTAL)->ShowWindow(FALSE);
		break;

	case 2:
		GetDlgItem(IDC_STATIC_ENG_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_ENG_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_ENG_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_ENG_D)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_ENG_TOTAL)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_D)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_ENG_TOTAL)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_MATH_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_MATH_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_MATH_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_BUTTON_MATH_TOTAL)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_A)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_B)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_C)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_MATH_TOTAL)->ShowWindow(FALSE);

		GetDlgItem(IDC_STATIC_KOR_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_KOR_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_KOR_C)->ShowWindow(TRUE);
		GetDlgItem(IDC_BUTTON_KOR_TOTAL)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_KOR_A)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_KOR_B)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_KOR_C)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_KOR_TOTAL)->ShowWindow(TRUE);
		break;
	}
	*pResult = 0;
}


void CTabExDlg::OnClickedButtonEngTotal()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dEngTotal = m_dEngA + m_dEngB + m_dEngC + m_dEngD;
	UpdateData(FALSE);
}


void CTabExDlg::OnClickedButtonMathTotal()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dMathTotal = m_dMathA + m_dMathB + m_dMathC;
	UpdateData(FALSE);
}


void CTabExDlg::OnClickedButtonKorTotal()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dKorTotal = m_dKorA + m_dKorB + m_dKorC;
	UpdateData(FALSE);
}


void CTabExDlg::OnClickedButtonTotal()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_dTotal = m_dEngTotal + m_dMathTotal + m_dKorTotal;
	UpdateData(FALSE);
}


void CTabExDlg::OnClickedButtonExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}
