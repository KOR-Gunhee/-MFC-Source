
// WinProDlg.h : ��� ����
//

#pragma once


// CWinProDlg ��ȭ ����
class CWinProDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CWinProDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WINPRO_DIALOG };
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
	BOOL m_chShow;
	BOOL m_chEnable;
	CString m_strBasic;
	CString m_strMulti;
	void ActiveShow();
	void ActiveEnable();
	afx_msg void OnClickedCheckEnable();
	afx_msg void OnClickedCheckShow();
	afx_msg void OnClickedButtonExit();
	afx_msg void OnChangeEdiBasic();
	afx_msg void OnChangeEditMulti();
};
