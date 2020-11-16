
// MultiClassesDlg.h : ��� ����
//

#pragma once

#include "MajorDlg.h"
#include "SubDlg.h"
#include "ResultDlg.h"

// CMultiClassesDlg ��ȭ ����
class CMultiClassesDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMultiClassesDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

	CMajorDlg m_MajorDlg;
	CSubDlg m_SubDlg;
	CResultDlg m_ResultDlg;

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MULTICLASSES_DIALOG };
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
	afx_msg void OnClickedButtonInMajor();
	afx_msg void OnClickedButtonInSub();
	afx_msg void OnClickedButtonOutResult();
	afx_msg void OnClickedButtonExit();
};
