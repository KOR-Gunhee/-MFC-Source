#pragma once


// CMajorDlg ��ȭ �����Դϴ�.

class CMajorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMajorDlg)

public:
	CMajorDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMajorDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_IN_MAJOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strMajor1;
	CString m_strMajor2;
	CString m_strMajor3;
};
