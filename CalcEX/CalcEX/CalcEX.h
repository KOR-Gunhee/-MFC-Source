
// CalcEX.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCalcEXApp:
// �� Ŭ������ ������ ���ؼ��� CalcEX.cpp�� �����Ͻʽÿ�.
//

class CCalcEXApp : public CWinApp
{
public:
	CCalcEXApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCalcEXApp theApp;