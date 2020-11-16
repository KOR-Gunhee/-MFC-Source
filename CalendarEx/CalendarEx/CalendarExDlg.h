
// CalendarExDlg.h : ��� ����
//

#pragma once
#include "ATLComTime.h"


// CCalendarExDlg ��ȭ ����
class CCalendarExDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CCalendarExDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALENDAREX_DIALOG };
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
	COleDateTime m_dtSDate;
	COleDateTime m_dtLDate;
//	CString m_strResult;
	afx_msg void OnClickedButtonLdate();
	afx_msg void OnClickedButtonSdate();
	CString m_strResult;
};
