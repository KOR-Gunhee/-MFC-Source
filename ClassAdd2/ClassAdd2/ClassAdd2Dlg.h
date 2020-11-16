
// ClassAdd2Dlg.h : ��� ����
//

#pragma once

#include "InName.h"
#include "InContact.h"
#include "OutAll.h"


// CClassAdd2Dlg ��ȭ ����
class CClassAdd2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CClassAdd2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

	CInName m_InNameDlg;
	CInContact m_InContactDlg;
	COutAll m_OutAllDlg;

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLASSADD2_DIALOG };
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
	afx_msg void OnClickedButtonNameIn();
	afx_msg void OnClickedButtonContactIn();
	afx_msg void OnClickedButtonNameOut();
	afx_msg void OnClickedButtonAllOut();
	afx_msg void OnClickedButtonExit();
};
