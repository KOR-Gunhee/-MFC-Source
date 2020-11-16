
// DateTimeDlg.h : ��� ����
//

#pragma once


// CDateTimeDlg ��ȭ ����
class CDateTimeDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CDateTimeDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

	CRect screen;
	int vsize, hsize;

	UINT htimer;

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DATETIME_DIALOG };
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
