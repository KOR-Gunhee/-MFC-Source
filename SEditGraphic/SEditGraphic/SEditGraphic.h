
// SEditGraphic.h : SEditGraphic ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSEditGraphicApp:
// �� Ŭ������ ������ ���ؼ��� SEditGraphic.cpp�� �����Ͻʽÿ�.
//

class CSEditGraphicApp : public CWinApp
{
public:
	CSEditGraphicApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSEditGraphicApp theApp;
