#pragma once


// CResultDlg ��ȭ �����Դϴ�.

class CResultDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CResultDlg)

public:
	CResultDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CResultDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OUT_RESULT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strOutMajor1;
	CString m_strOutMajor2;
	CString m_strOutMajor3;
	CString m_strOutSub1;
	CString m_strOutSub2;
};
