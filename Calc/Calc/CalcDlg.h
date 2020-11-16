
// CalcDlg.h : ��� ����
//

#pragma once


// CCalcDlg ��ȭ ����
class CCalcDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CCalcDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALC_DIALOG };
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
	int m_nOption;
//	CString m_nNum1;
//	CString m_nNum2;
//	CString m_nResult;
	afx_msg void OnClickedButtonAdd();
	afx_msg void OnClickedButtonSub();
	afx_msg void OnClickedButtonMul();
	afx_msg void OnClickedButtonDiv();
	afx_msg void OnClickedButtonEqu();
	CString m_nNum1;
	CString m_nNum2;
	CString m_nResult;
	afx_msg void OnClickedButtonClr();
	afx_msg void OnClickedButtonExit();
};
