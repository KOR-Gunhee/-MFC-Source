
// Select Sort.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSelectSortApp:
// �� Ŭ������ ������ ���ؼ��� Select Sort.cpp�� �����Ͻʽÿ�.
//

class CSelectSortApp : public CWinApp
{
public:
	CSelectSortApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSelectSortApp theApp;