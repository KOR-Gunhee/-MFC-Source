
// ListExDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CListExDlg ��ȭ ����
class CListExDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CListExDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTEX_DIALOG };
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
	CListBox m_listSub;
	CListBox m_listLang;
	CListBox m_listEnge;
	CListBox m_listSel;
	CListBox m_listSign;
	afx_msg void OnClickedButtonSub();
	afx_msg void OnClickedButtonLang();
	afx_msg void OnClickedButtonEnge();
	afx_msg void OnClickedButtonDel();
	afx_msg void OnClickedButtonSel();
};
