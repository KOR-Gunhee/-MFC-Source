
// Drawing2.h : Drawing2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CDrawing2App:
// �� Ŭ������ ������ ���ؼ��� Drawing2.cpp�� �����Ͻʽÿ�.
//

class CDrawing2App : public CWinAppEx
{
public:
	CDrawing2App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawing2App theApp;
