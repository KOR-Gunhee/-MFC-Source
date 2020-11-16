
// MFCCserialportDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "MFCCserialport.h"
#include "MFCCserialportDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCCserialportDlg ��ȭ ����



CMFCCserialportDlg::CMFCCserialportDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCCSERIALPORT_DIALOG, pParent)
	, m_str_comport(_T(""))
	, m_str_baudrate(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCserialportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_COMPORT, m_combo_comport_list);
	DDX_CBString(pDX, IDC_COMBO_COMPORT, m_str_comport);
	DDX_Control(pDX, IDC_COMBO_BAUDRATE, m_combo_baudrate_list);
	DDX_CBString(pDX, IDC_COMBO_BAUDRATE, m_str_baudrate);
	DDX_Control(pDX, IDC_EDIT_RCV_VIEW, m_edit_rcv_view);
	DDX_Control(pDX, IDC_EDIT_SEND_DATA, m_edit_send_data);
}

BEGIN_MESSAGE_MAP(CMFCCserialportDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	
	ON_MESSAGE(WM_MYCLOSE, &CMFCCserialportDlg::OnThreadClosed)
	ON_MESSAGE(WM_MYRECEIVE, &CMFCCserialportDlg::OnReceive)


	ON_BN_CLICKED(IDC_BT_CONNECT, &CMFCCserialportDlg::OnBnClickedBtConnect)
	ON_CBN_SELCHANGE(IDC_COMBO_COMPORT, &CMFCCserialportDlg::OnCbnSelchangeComboComport)
	ON_CBN_SELCHANGE(IDC_COMBO_BAUDRATE, &CMFCCserialportDlg::OnCbnSelchangeComboBaudrate)
	ON_BN_CLICKED(IDC_BT_CLEAR, &CMFCCserialportDlg::OnBnClickedBtClear)
	ON_BN_CLICKED(IDC_BT_SEND, &CMFCCserialportDlg::OnBnClickedBtSend)
END_MESSAGE_MAP()


// CMFCCserialportDlg �޽��� ó����

BOOL CMFCCserialportDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_combo_comport_list.AddString(_T("COM1"));
	m_combo_comport_list.AddString(_T("COM2"));
	m_combo_comport_list.AddString(_T("COM3"));
	m_combo_comport_list.AddString(_T("COM4"));


	m_combo_baudrate_list.AddString(_T("9600"));
	m_combo_baudrate_list.AddString(_T("19200"));
	m_combo_baudrate_list.AddString(_T("115200"));

	comport_state = false;
	GetDlgItem(IDC_BT_CONNECT)->SetWindowText(_T("OPEN"));
	m_str_comport = "COM4";
	m_str_baudrate = "115200";
	UpdateData(FALSE);
	
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMFCCserialportDlg::OnPaint()
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
HCURSOR CMFCCserialportDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CMFCCserialportDlg::OnThreadClosed(WPARAM length, LPARAM lpara)
{
	//overlapped i/o �ڵ��� �ݴ´�.
	((CMyComm*)lpara)->HandleClose();
	delete ((CMyComm*)lpara);

	return 0;
}

LRESULT CMFCCserialportDlg::OnReceive(WPARAM length, LPARAM lpara)
{
	CString str;
	char data[2000];
	if (m_comm)
	{
		m_comm->Receive(data, length);		//length ���� ��ŭ �����͸� �޴´�
		data[length] = _T('\n');
		str += _T("\r\n");
		for (int i = 0; i < (int)length; i++)
		{
			str += data[i];
		}
		m_edit_rcv_view.ReplaceSel(str);	//����Ʈ �ڽ��� ǥ���ϱ� ����
		str = _T("");
		//UpdateData(FALSE);
		m_edit_rcv_view.LineScroll(m_edit_rcv_view.GetLineCount());
	}

	return 0;
}

void CMFCCserialportDlg::OnBnClickedBtConnect()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (comport_state)
	{
		if (m_comm)
		{
			m_comm->Close();
			m_comm = NULL;
			AfxMessageBox(_T("COM PORT CLOSE"));
			comport_state = false;
			GetDlgItem(IDC_BT_CONNECT)->SetWindowTextA(_T("OPEN"));
			GetDlgItem(IDC_BT_SEND)->EnableWindow(false);
		}
	}
	else
	{
//		CString str = "COM4";
		m_comm = new CMyComm("\\\\.\\" + m_str_comport , m_str_baudrate, "None", "8 Bit", "1 Bit");		//initial Comm port
		if (m_comm->Create(GetSafeHwnd()) != 0)		//��� ��Ʈ�� ���� �������� �ڵ��� �ѱ��.
		{
			AfxMessageBox(_T("COM PORT OPEN"));
			comport_state = true;
			GetDlgItem(IDC_BT_CONNECT)->SetWindowTextA(_T("CLOSE"));
			GetDlgItem(IDC_BT_SEND)->EnableWindow(true);
		}
		else
		{
			AfxMessageBox(_T("ERROR!"));
		}
	}
}


void CMFCCserialportDlg::OnCbnSelchangeComboComport()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData();
}


void CMFCCserialportDlg::OnCbnSelchangeComboBaudrate()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData();
}


void CMFCCserialportDlg::OnBnClickedBtClear()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	GetDlgItem(IDC_EDIT_RCV_VIEW)->SetWindowTextA(_T(""));
}


void CMFCCserialportDlg::OnBnClickedBtSend()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString str;
	GetDlgItem(IDC_EDIT_SEND_DATA)->GetWindowTextA(str);
	str += "\r\n";
	m_comm->Send(str, str.GetLength());
}
