
// SDrawing.h : SDrawing ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CSDrawingApp:
// �� Ŭ������ ������ ���ؼ��� SDrawing.cpp�� �����Ͻʽÿ�.
//

class CSDrawingApp : public CWinAppEx
{
public:
	CSDrawingApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSDrawingApp theApp;
