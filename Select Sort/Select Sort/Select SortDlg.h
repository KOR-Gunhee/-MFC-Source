
// Select SortDlg.h : ��� ����
//

#pragma once


// CSelectSortDlg ��ȭ ����
class CSelectSortDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CSelectSortDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECTSORT_DIALOG };
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
	int n1;
	int n2;
	int n3;
	int n4;
	int n5;
	int n6;
	int n7;
	int n8;
	afx_msg void OnClickedButtonSort();
};
