
// SpinCtrl.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSpinCtrlApp:
// �� Ŭ������ ������ ���ؼ��� SpinCtrl.cpp�� �����Ͻʽÿ�.
//

class CSpinCtrlApp : public CWinApp
{
public:
	CSpinCtrlApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSpinCtrlApp theApp;