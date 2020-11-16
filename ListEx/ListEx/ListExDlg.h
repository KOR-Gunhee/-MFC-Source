
// ListExDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CListExDlg 대화 상자
class CListExDlg : public CDialogEx
{
// 생성입니다.
public:
	CListExDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTEX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listSub;
	CListBox m_listLang;
	CListBox m_listEnge;
	CListBox m_listSel;
	CListBox m_listSign;
	afx_msg void OnClickedButtonSub();
	afx_msg void OnClickedButtonLang();
	afx_msg void OnClickedButtonEnge();
	afx_msg void OnClickedButtonDel();
	afx_msg void OnClickedButtonSel();
};
