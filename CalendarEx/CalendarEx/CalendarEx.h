
// CalendarEx.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCalendarExApp:
// �� Ŭ������ ������ ���ؼ��� CalendarEx.cpp�� �����Ͻʽÿ�.
//

class CCalendarExApp : public CWinApp
{
public:
	CCalendarExApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCalendarExApp theApp;