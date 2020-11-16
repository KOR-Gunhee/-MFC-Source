#pragma once


// CSubDlg 대화 상자입니다.

class CSubDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSubDlg)

public:
	CSubDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CSubDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_IN_SUB };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strSub1;
	CString m_strSub2;
};
