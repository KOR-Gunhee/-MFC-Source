
// TreeCtrlDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CTreeCtrlDlg ��ȭ ����
class CTreeCtrlDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CTreeCtrlDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TREECTRL_DIALOG };
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
	CTreeCtrl m_ctrMenu;
	afx_msg void OnClickedButtonDessert();
	afx_msg void OnClickedButtonDrink();
	afx_msg void OnClickedButtonExit();
	afx_msg void OnSelchangedTreeMenu(NMHDR *pNMHDR, LRESULT *pResult);
};
