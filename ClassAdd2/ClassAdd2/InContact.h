#pragma once


// CInContact ��ȭ �����Դϴ�.

class CInContact : public CDialogEx
{
	DECLARE_DYNAMIC(CInContact)

public:
	CInContact(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CInContact();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_IN_CONTACT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strInCell;
	CString m_strInEmail;
};
