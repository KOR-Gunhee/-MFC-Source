
// MonthCalendarDlg.h : ��� ����
//

#pragma once


// CMonthCalendarDlg ��ȭ ����
class CMonthCalendarDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMonthCalendarDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MONTHCALENDAR_DIALOG };
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
	afx_msg void OnSelchangeMonthcalendar1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedButtonExit();
};
