
// ControlBox_ODBCDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"

////////////////////////////
#include "Employees.h"
////////////////////////////

// CControlBox_ODBCDlg ��ȭ ����
class CControlBox_ODBCDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CControlBox_ODBCDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONTROLBOX_ODBC_DIALOG };
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
	CListCtrl m_listView;
};
