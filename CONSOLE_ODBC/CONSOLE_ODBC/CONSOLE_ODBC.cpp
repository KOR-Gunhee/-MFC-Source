// CONSOLE_ODBC.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "CONSOLE_ODBC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 유일한 응용 프로그램 개체입니다.

CWinApp theApp;

using namespace std;

int main()
{
    int nRetCode = 0;
	HMODULE hModule = ::GetModuleHandle(nullptr);
	if (hModule != nullptr)
    {
        // MFC를 초기화합니다. 초기화하지 못한 경우 오류를 인쇄합니다.
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: 오류 코드를 필요에 따라 수정합니다.

            wprintf(L"심각한 오류: MFC를 초기화하지 못했습니다.\n");
            nRetCode = 1;
        }
        else
        {
            // TODO: 응용 프로그램의 동작은 여기에서 코딩합니다.
			/////////////////////////////////////////////////
			//ODBC에 등록된 데이터를 연다.
			CDatabase db;
			//데이터 베이스 객체 선언 및 연결, ID/Password 생략
			db.OpenEx(_T("DSN=ODBC_RE"), 0);
			//레코드셋 객체 생성
			CRecordset rs(&db);
			// Students 테이블의 모든 내용을 선택
			rs.Open(CRecordset::dynaset, _T("SELECT * FROM Students"));

			CString str;
			_tprintf(_T(" ID   이름   거주지\n"));
			_tprintf(_T("--------------------------\n"));
			while (!rs.IsEOF())
			{
				rs.GetFieldValue(short(0), str);
				_tprintf(_T("%s  "), str);
				rs.GetFieldValue(short(1), str);
				_tprintf(_T("%s  "), str);
				rs.GetFieldValue(short(2), str);
				_tprintf(_T("%s  \n"), str);
				rs.MoveNext();   //레코드셋 포인터를 다음행으로 이동
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
        // TODO: 오류 코드를 필요에 따라 수정합니다.
        wprintf(L"심각한 오류: GetModuleHandle 실패\n");
        nRetCode = 1;
    }

    return nRetCode;
}
