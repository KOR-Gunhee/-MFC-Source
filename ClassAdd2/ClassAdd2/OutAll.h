#pragma once


// COutAll ��ȭ �����Դϴ�.

class COutAll : public CDialogEx
{
	DECLARE_DYNAMIC(COutAll)

public:
	COutAll(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~COutAll();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OUT_ALL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strOutCell;
	CString m_strOutEmail;
	CString m_strOutEngName;
	CString m_strOutKorName;
};
