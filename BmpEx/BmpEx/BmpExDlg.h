
// BmpExDlg.h : ��� ����
//

#pragma once


// CBmpExDlg ��ȭ ����
class CBmpExDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CBmpExDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

	/////////////////////////////

	HINSTANCE m_hInstance;

	int m_nWidth;
	int m_nHeight;

	/////////////////////////////

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BMPEX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnExit();
	int m_menuID;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnZoomIn1();
	afx_msg void OnZoomIn2();
	afx_msg void OnZoomOut1();
	afx_msg void OnZoomOut2();
	afx_msg void OnClickedButtonExit();
};
