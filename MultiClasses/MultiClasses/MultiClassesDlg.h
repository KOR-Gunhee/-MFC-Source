
// MultiClassesDlg.h : 헤더 파일
//

#pragma once

#include "MajorDlg.h"
#include "SubDlg.h"
#include "ResultDlg.h"

// CMultiClassesDlg 대화 상자
class CMultiClassesDlg : public CDialogEx
{
// 생성입니다.
public:
	CMultiClassesDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

	CMajorDlg m_MajorDlg;
	CSubDlg m_SubDlg;
	CResultDlg m_ResultDlg;

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MULTICLASSES_DIALOG };
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
	afx_msg void OnClickedButtonInMajor();
	afx_msg void OnClickedButtonInSub();
	afx_msg void OnClickedButtonOutResult();
	afx_msg void OnClickedButtonExit();
};
