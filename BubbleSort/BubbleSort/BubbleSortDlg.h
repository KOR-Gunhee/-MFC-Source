
// BubbleSortDlg.h : ��� ����
//

#pragma once


// CBubbleSortDlg ��ȭ ����
class CBubbleSortDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CBubbleSortDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUBBLESORT_DIALOG };
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
//	CString n1;
//	CString n2;
//	CString n3;
//	CString n4;
//	CString n5;
//	CString n6;
//	CString n7;
//	CString n8;
	afx_msg void OnClickedButtonSort();
	afx_msg void OnClickedButtonExit();
//	CString m_n1;
	int m_n1;
	int m_n2;
	int m_n3;
	int m_n4;
	int m_n5;
	int m_n6;
	int m_n7;
	int m_n8;
};
