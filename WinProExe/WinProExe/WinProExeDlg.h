
// WinProExeDlg.h : ��� ����
//

#pragma once


// CWinProExeDlg ��ȭ ����
class CWinProExeDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CWinProExeDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WINPROEXE_DIALOG };
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
	BOOL m_chActive;
	BOOL m_chShow;
	CString m_strInput;
	void ActiveShow();
	afx_msg void OnClickedCheckActive();
	afx_msg void OnClickedCheckShow();
	afx_msg void OnChangeEditInput();
	afx_msg void OnClickedButtonClear();
	afx_msg void OnClickedButtonExit();
};
