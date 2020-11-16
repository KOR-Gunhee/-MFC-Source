
// AB_AREADlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CAB_AREADlg ��ȭ ����
class CAB_AREADlg : public CDialogEx
{
// �����Դϴ�.
public:
	CAB_AREADlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AB_AREA_DIALOG };
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
	CTabCtrl m_tabArea;
	double m_dCirR;
	double m_dCirResult;
	double m_dTriA;
	double m_dTriB;
	double m_dTriResult;
	double m_dRectA;
	double m_dRectB;
	double m_dRectResult;
	afx_msg void OnSelchangeTabArea(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedButtonCir();
	afx_msg void OnClickedButtonRect();
	afx_msg void OnClickedButtonTri();
	afx_msg void OnClickedButtonShow();
	afx_msg void OnClickedButtonExit();
};
