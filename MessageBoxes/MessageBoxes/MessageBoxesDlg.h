
// MessageBoxesDlg.h : ��� ����
//

#pragma once


// CMessageBoxesDlg ��ȭ ����
class CMessageBoxesDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMessageBoxesDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MESSAGEBOXES_DIALOG };
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
	afx_msg void OnBnClickedButtonYn();
	afx_msg void OnBnClickedButtonOc();
	afx_msg void OnBnClickedButtonYnc();
	afx_msg void OnBnClickedButtonRc();
	afx_msg void OnBnClickedButtonAri();
	afx_msg void OnBnClickedButtonOk();
	afx_msg void OnBnClickedButtonMfc();
	afx_msg void OnBnClickedButtonExit();
	CString m_strResult;
};
