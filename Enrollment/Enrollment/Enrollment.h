
// Enrollment.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CEnrollmentApp:
// �� Ŭ������ ������ ���ؼ��� Enrollment.cpp�� �����Ͻʽÿ�.
//

class CEnrollmentApp : public CWinApp
{
public:
	CEnrollmentApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CEnrollmentApp theApp;