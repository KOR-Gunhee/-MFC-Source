
// CalcEXDlg.h : ��� ����
//

#pragma once


// CCalcEXDlg ��ȭ ����
class CCalcEXDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CCalcEXDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCEX_DIALOG };
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
	CString Average;
	CString Language;
	CString English;
	CString Math;
	CString Total;
	afx_msg void OnClickedButtonInsert();
	CString Grade;
};
