
// MFCCserialport.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFCCserialportApp:
// �� Ŭ������ ������ ���ؼ��� MFCCserialport.cpp�� �����Ͻʽÿ�.
//

class CMFCCserialportApp : public CWinApp
{
public:
	CMFCCserialportApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFCCserialportApp theApp;