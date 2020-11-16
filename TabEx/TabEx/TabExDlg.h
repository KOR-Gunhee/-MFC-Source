
// TabExDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"


// CTabExDlg 대화 상자
class CTabExDlg : public CDialogEx
{
// 생성입니다.
public:
	CTabExDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TABEX_DIALOG };
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
	CTabCtrl m_tabArea;
	double m_dEngA;
	double m_dEngB;
	double m_dEngC;
	double m_dEngD;
	double m_dEngTotal;
	double m_dKorA;
	double m_dKorB;
	double m_dKorC;
	double m_dKorTotal;
	double m_dMathA;
	double m_dMathB;
	double m_dMathC;
	double m_dMathTotal;
	double m_dTotal;
	afx_msg void OnSelchangeTabArea(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnClickedButtonEngTotal();
	afx_msg void OnClickedButtonMathTotal();
	afx_msg void OnClickedButtonKorTotal();
	afx_msg void OnClickedButtonTotal();
	afx_msg void OnClickedButtonExit();
};
