
// CountryTree.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCountryTreeApp:
// �� Ŭ������ ������ ���ؼ��� CountryTree.cpp�� �����Ͻʽÿ�.
//

class CCountryTreeApp : public CWinApp
{
public:
	CCountryTreeApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCountryTreeApp theApp;