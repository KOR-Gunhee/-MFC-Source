
// ListExDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "ListEx.h"
#include "ListExDlg.h"
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


// CListExDlg 대화 상자



CListExDlg::CListExDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LISTEX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_SUB, m_listSub);
	DDX_Control(pDX, IDC_LIST_LANG, m_listLang);
	DDX_Control(pDX, IDC_LIST_ENGE, m_listEnge);
	DDX_Control(pDX, IDC_LIST_SEL, m_listSel);
	DDX_Control(pDX, IDC_LIST_SIGN, m_listSign);
}

BEGIN_MESSAGE_MAP(CListExDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CListExDlg::OnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_LANG, &CListExDlg::OnClickedButtonLang)
	ON_BN_CLICKED(IDC_BUTTON_ENGE, &CListExDlg::OnClickedButtonEnge)
	ON_BN_CLICKED(IDC_BUTTON_DEL, &CListExDlg::OnClickedButtonDel)
	ON_BN_CLICKED(IDC_BUTTON_SEL, &CListExDlg::OnClickedButtonSel)
END_MESSAGE_MAP()


// CListExDlg 메시지 처리기

BOOL CListExDlg::OnInitDialog()
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

	m_listSub.AddString(_T("독서토론"));
	m_listSub.AddString(_T("인권윤리학"));
	m_listSub.AddString(_T("현대스포츠"));
	m_listSub.AddString(_T("기독교와 종교"));
	m_listSub.AddString(_T("교양영어"));
	m_listSub.AddString(_T("철학사상"));

	m_listLang.AddString(_T("일어"));
	m_listLang.AddString(_T("중국어"));
	m_listLang.AddString(_T("독일어"));

	m_listEnge.AddString(_T("컴퓨터통신"));
	m_listEnge.AddString(_T("운영체제"));
	m_listEnge.AddString(_T("공학수학"));
	m_listEnge.AddString(_T("통신개론"));
	m_listEnge.AddString(_T("네트워크이론"));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CListExDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CListExDlg::OnPaint()
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
HCURSOR CListExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CListExDlg::OnClickedButtonSub()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	int count = m_listSub.GetCount();

	for (int i = count - 1; i >= 0; i--)
	{
		if (m_listSub.GetSel(i))
		{
			m_listSub.GetText(i, str);
			m_listSel.AddString(str);
		}
	}
}


void CListExDlg::OnClickedButtonLang()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int Index = m_listLang.GetCurSel();
	if (Index != LB_ERR)
	{
		CString str;
		m_listLang.GetText(Index, str);
		m_listLang.SetCurSel(Index);
		m_listSel.AddString(str);
	}
}


void CListExDlg::OnClickedButtonEnge()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int Index = m_listEnge.GetCurSel();
	if (Index != LB_ERR)
	{
		CString str;
		m_listEnge.GetText(Index, str);
		m_listEnge.SetCurSel(Index);
		m_listSel.AddString(str);
	}
}


void CListExDlg::OnClickedButtonSel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	int count = m_listSel.GetCount();

	for (int i = count - 1; i >= 0; i--)
	{
		if (m_listSel.GetSel(i))
		{
			m_listSel.GetText(i, str);
			m_listSign.AddString(str);
		}
	}
}


void CListExDlg::OnClickedButtonDel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nIndex;
	nIndex = m_listSel.GetCurSel();
	if (nIndex != LB_ERR)
	{
		m_listSel.DeleteString(nIndex);
	}
	else
	{
		AfxMessageBox(_T("삭제할 메뉴를 선택하세요"));
	}
}