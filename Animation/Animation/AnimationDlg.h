
// AnimationDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CAnimationDlg ��ȭ ����
class CAnimationDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CAnimationDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ANIMATION_DIALOG };
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
	CAnimateCtrl m_cAnimation;
	CString m_strFileName;
	afx_msg void OnClickedButtonPlay();
	afx_msg void OnClickedButtonStop();
	afx_msg void OnClickedButtonFile();
	afx_msg void OnClickedButtonExit();
};
