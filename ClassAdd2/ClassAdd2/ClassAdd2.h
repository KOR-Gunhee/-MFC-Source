
// ClassAdd2.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CClassAdd2App:
// �� Ŭ������ ������ ���ؼ��� ClassAdd2.cpp�� �����Ͻʽÿ�.
//

class CClassAdd2App : public CWinApp
{
public:
	CClassAdd2App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CClassAdd2App theApp;