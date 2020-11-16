
// ListBoxMenuDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CListBoxMenuDlg ��ȭ ����
class CListBoxMenuDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CListBoxMenuDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTBOXMENU_DIALOG };
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
	CListBox m_listMeal;
	CListBox m_listDessert;
	CListBox m_listResult;
	afx_msg void OnClickedButtonMeal();
	afx_msg void OnClickedButtonDessert();
	CString m_strEtc;
	afx_msg void OnClickedButtonEtc();
	afx_msg void OnClickedButtonReset();
	afx_msg void OnClickedButtonDel();
};
