
// ClassAdd1Dlg.h : ��� ����
//

#pragma once

#include "InputDlg.h"

// CClassAdd1Dlg ��ȭ ����
class CClassAdd1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CClassAdd1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

	CInputDlg m_InputDlg;

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLASSADD1_DIALOG };
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
	afx_msg void OnClickedButtonInput();
	afx_msg void OnClickedButtonOutput();
	afx_msg void OnClickedButtonExit();
};
