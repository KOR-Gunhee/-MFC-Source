
// Calc.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCalcApp:
// �� Ŭ������ ������ ���ؼ��� Calc.cpp�� �����Ͻʽÿ�.
//

class CCalcApp : public CWinApp
{
public:
	CCalcApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCalcApp theApp;