
// MultiClasses.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMultiClassesApp:
// �� Ŭ������ ������ ���ؼ��� MultiClasses.cpp�� �����Ͻʽÿ�.
//

class CMultiClassesApp : public CWinApp
{
public:
	CMultiClassesApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMultiClassesApp theApp;