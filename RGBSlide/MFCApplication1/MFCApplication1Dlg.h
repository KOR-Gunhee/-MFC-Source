
// MFCApplication1Dlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"


// CMFCApplication1Dlg ��ȭ ����
class CMFCApplication1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
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
	CSliderCtrl m_sldR;
	CSliderCtrl m_sldG;
	CSliderCtrl m_sldB;
	int m_nR;
	int m_nG;
	int m_nB;
	COLORREF m_cRGB;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	void Clear();
	afx_msg void OnClickedButtonClear();
	afx_msg void OnClickedButtonExit();
};
