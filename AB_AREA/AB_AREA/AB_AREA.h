
// AB_AREA.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CAB_AREAApp:
// �� Ŭ������ ������ ���ؼ��� AB_AREA.cpp�� �����Ͻʽÿ�.
//

class CAB_AREAApp : public CWinApp
{
public:
	CAB_AREAApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CAB_AREAApp theApp;