
// MemExDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CMemExDlg ��ȭ ����
class CMemExDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMemExDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEMEX_DIALOG };
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
	CString m_strName;
	CString m_strCell;
	CButton m_rMountain;
	CComboBox m_cbCountry;
	CListCtrl m_listView;
	int m_nSelected;
	void Init();
	afx_msg void OnClickedButtonInput();
	afx_msg void OnClickedButtonInit();
	afx_msg void OnClickedButtonDel();
	afx_msg void OnClickedButtonExit();
};
