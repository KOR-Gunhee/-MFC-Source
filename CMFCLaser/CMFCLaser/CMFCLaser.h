
// CMFCLaser.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCMFCLaserApp:
// �� Ŭ������ ������ ���ؼ��� CMFCLaser.cpp�� �����Ͻʽÿ�.
//

class CCMFCLaserApp : public CWinApp
{
public:
	CCMFCLaserApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCMFCLaserApp theApp;