#pragma once


// COutAll 대화 상자입니다.

class COutAll : public CDialogEx
{
	DECLARE_DYNAMIC(COutAll)

public:
	COutAll(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~COutAll();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OUT_ALL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strOutCell;
	CString m_strOutEmail;
	CString m_strOutEngName;
	CString m_strOutKorName;
};
