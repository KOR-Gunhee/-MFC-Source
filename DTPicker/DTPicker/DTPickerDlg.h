
// DTPickerDlg.h : ��� ����
//

#pragma once
#include "ATLComTime.h"


// CDTPickerDlg ��ȭ ����
class CDTPickerDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CDTPickerDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DTPICKER_DIALOG };
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
	COleDateTime m_dtDate;
	COleDateTime m_dtTime;
	CString m_strOut;
	afx_msg void OnClickedButtonOut();
};
