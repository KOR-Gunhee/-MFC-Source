
// DTPicker.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CDTPickerApp:
// �� Ŭ������ ������ ���ؼ��� DTPicker.cpp�� �����Ͻʽÿ�.
//

class CDTPickerApp : public CWinApp
{
public:
	CDTPickerApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CDTPickerApp theApp;