
// CountryTreeDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CCountryTreeDlg ��ȭ ����
class CCountryTreeDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CCountryTreeDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COUNTRYTREE_DIALOG };
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
	CTreeCtrl m_ctrAsia;
	CTreeCtrl m_ctrEuro;
	afx_msg void OnClickedButtonChina();
	afx_msg void OnClickedButtonFrance();
	afx_msg void OnClickedButtonUk();
};
