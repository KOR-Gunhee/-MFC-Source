
// Drawing1.h : Drawing1 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CDrawing1App:
// �� Ŭ������ ������ ���ؼ��� Drawing1.cpp�� �����Ͻʽÿ�.
//

class CDrawing1App : public CWinApp
{
public:
	CDrawing1App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawing1App theApp;
