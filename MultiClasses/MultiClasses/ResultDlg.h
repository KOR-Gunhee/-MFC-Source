#pragma once


// CResultDlg 대화 상자입니다.

class CResultDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CResultDlg)

public:
	CResultDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CResultDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OUT_RESULT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strOutMajor1;
	CString m_strOutMajor2;
	CString m_strOutMajor3;
	CString m_strOutSub1;
	CString m_strOutSub2;
};
