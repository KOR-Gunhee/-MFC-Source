
// BubbleSort.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CBubbleSortApp:
// �� Ŭ������ ������ ���ؼ��� BubbleSort.cpp�� �����Ͻʽÿ�.
//

class CBubbleSortApp : public CWinApp
{
public:
	CBubbleSortApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CBubbleSortApp theApp;