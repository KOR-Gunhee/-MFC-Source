
// Animation.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CAnimationApp:
// �� Ŭ������ ������ ���ؼ��� Animation.cpp�� �����Ͻʽÿ�.
//

class CAnimationApp : public CWinApp
{
public:
	CAnimationApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CAnimationApp theApp;