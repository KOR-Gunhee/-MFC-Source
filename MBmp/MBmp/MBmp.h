
// MBmp.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMBmpApp:
// �� Ŭ������ ������ ���ؼ��� MBmp.cpp�� �����Ͻʽÿ�.
//

class CMBmpApp : public CWinApp
{
public:
	CMBmpApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMBmpApp theApp;