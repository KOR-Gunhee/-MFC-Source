
// DCDrawing.h : DCDrawing ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CDCDrawingApp:
// �� Ŭ������ ������ ���ؼ��� DCDrawing.cpp�� �����Ͻʽÿ�.
//

class CDCDrawingApp : public CWinAppEx
{
public:
	CDCDrawingApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDCDrawingApp theApp;
