
// SlideEx.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSlideExApp:
// �� Ŭ������ ������ ���ؼ��� SlideEx.cpp�� �����Ͻʽÿ�.
//

class CSlideExApp : public CWinApp
{
public:
	CSlideExApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSlideExApp theApp;