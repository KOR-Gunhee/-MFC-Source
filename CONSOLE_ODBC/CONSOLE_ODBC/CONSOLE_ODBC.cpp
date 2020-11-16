// CONSOLE_ODBC.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "CONSOLE_ODBC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ������ ���� ���α׷� ��ü�Դϴ�.

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;
	HMODULE hModule = ::GetModuleHandle(nullptr);
	if (hModule != nullptr)
    {
        // MFC�� �ʱ�ȭ�մϴ�. �ʱ�ȭ���� ���� ��� ������ �μ��մϴ�.
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.

            wprintf(L"�ɰ��� ����: MFC�� �ʱ�ȭ���� ���߽��ϴ�.\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: ���� ���α׷��� ������ ���⿡�� �ڵ��մϴ�.
			/////////////////////////////////////////////////
			//ODBC�� ��ϵ� �����͸� ����.
			CDatabase db;
			//������ ���̽� ��ü ���� �� ����, ID/Password ����
			db.OpenEx(_T("DSN=ODBC_RE"), 0);
			//���ڵ�� ��ü ����
			CRecordset rs(&db);
			// Students ���̺��� ��� ������ ����
			rs.Open(CRecordset::dynaset, _T("SELECT * FROM Students"));

			CString str;
			_tprintf(_T(" ID   �̸�   ������\n"));
			_tprintf(_T("--------------------------\n"));
			while (!rs.IsEOF())
			{
				rs.GetFieldValue(short(0), str);
				_tprintf(_T("%s  "), str);
				rs.GetFieldValue(short(1), str);
				_tprintf(_T("%s  "), str);
				rs.GetFieldValue(short(2), str);
				_tprintf(_T("%s  \n"), str);
				rs.MoveNext();   //���ڵ�� �����͸� ���������� �̵�
			}
			_tprintf(_T("--------------------------\n"));
			rs.Close();
			db.Close();
			system("pause");
			////////////////////////////////////////
        }
    }
    else
    {
        // TODO: ���� �ڵ带 �ʿ信 ���� �����մϴ�.
        wprintf(L"�ɰ��� ����: GetModuleHandle ����\n");
        nRetCode = 1;
    }

    return nRetCode;
}
