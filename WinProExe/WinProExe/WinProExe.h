
// WinProExe.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CWinProExeApp:
// �� Ŭ������ ������ ���ؼ��� WinProExe.cpp�� �����Ͻʽÿ�.
//

class CWinProExeApp : public CWinApp
{
public:
	CWinProExeApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CWinProExeApp theApp;