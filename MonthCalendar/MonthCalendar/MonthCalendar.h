
// MonthCalendar.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMonthCalendarApp:
// �� Ŭ������ ������ ���ؼ��� MonthCalendar.cpp�� �����Ͻʽÿ�.
//

class CMonthCalendarApp : public CWinApp
{
public:
	CMonthCalendarApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMonthCalendarApp theApp;