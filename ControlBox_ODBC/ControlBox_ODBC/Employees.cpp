// Employees.h : CEmployees 클래스의 구현입니다.



// CEmployees 구현입니다.

// 코드 생성 위치 2018년 12월 18일 화요일, 오전 11:07

#include "stdafx.h"
#include "Employees.h"
IMPLEMENT_DYNAMIC(CEmployees, CRecordset)

CEmployees::CEmployees(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_EM_Id = L"";
	m_EM_Name = L"";
	m_EM_Dept = L"";
	m_EM_Salary = L"";
	m_nFields = 4;
	m_nDefaultType = dynaset;
}
//#error 보안 문제: 연결 문자열에 암호가 포함되어 있을 수 있습니다.
// 아래 연결 문자열에 일반 텍스트 암호 및/또는 
// 다른 중요한 정보가 포함되어 있을 수 있습니다.
// 보안 관련 문제가 있는지 연결 문자열을 검토한 후에 #error을(를) 제거하십시오.
// 다른 형식으로 암호를 저장하거나 다른 사용자 인증을 사용하십시오.
CString CEmployees::GetDefaultConnect()
{
	return _T("DSN=ODBC_RE;DBQ=C:\\Users\\ghhan\\Documents\\Source_2016\\RegisterDB.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CEmployees::GetDefaultSQL()
{
	return _T("[Employees]");
}

void CEmployees::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 및 RFX_Int() 같은 매크로는 데이터베이스의 필드
// 형식이 아니라 멤버 변수의 형식에 따라 달라집니다.
// ODBC에서는 자동으로 열 값을 요청된 형식으로 변환하려고 합니다
	RFX_Text(pFX, _T("[EM_Id]"), m_EM_Id);
	RFX_Text(pFX, _T("[EM_Name]"), m_EM_Name);
	RFX_Text(pFX, _T("[EM_Dept]"), m_EM_Dept);
	RFX_Text(pFX, _T("[EM_Salary]"), m_EM_Salary);

}
/////////////////////////////////////////////////////////////////////////////
// CEmployees 진단

#ifdef _DEBUG
void CEmployees::AssertValid() const
{
	CRecordset::AssertValid();
}

void CEmployees::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


