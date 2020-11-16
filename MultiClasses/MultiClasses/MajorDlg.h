#pragma once


// CMajorDlg 대화 상자입니다.

class CMajorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMajorDlg)

public:
	CMajorDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMajorDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_IN_MAJOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strMajor1;
	CString m_strMajor2;
	CString m_strMajor3;
};
