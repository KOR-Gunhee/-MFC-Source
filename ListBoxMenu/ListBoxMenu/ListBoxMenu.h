
// ListBoxMenu.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CListBoxMenuApp:
// �� Ŭ������ ������ ���ؼ��� ListBoxMenu.cpp�� �����Ͻʽÿ�.
//

class CListBoxMenuApp : public CWinApp
{
public:
	CListBoxMenuApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CListBoxMenuApp theApp;