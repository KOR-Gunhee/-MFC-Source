#pragma once


// CInName ��ȭ �����Դϴ�.

class CInName : public CDialogEx
{
	DECLARE_DYNAMIC(CInName)

public:
	CInName(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CInName();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_IN_NAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
//	CString m_strInKorName;
	CString m_strInEngName;
	CString m_strInKorName;
};
