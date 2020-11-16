// Employees.h : CEmployees Ŭ������ �����Դϴ�.



// CEmployees �����Դϴ�.

// �ڵ� ���� ��ġ 2018�� 12�� 18�� ȭ����, ���� 11:07

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
//#error ���� ����: ���� ���ڿ��� ��ȣ�� ���ԵǾ� ���� �� �ֽ��ϴ�.
// �Ʒ� ���� ���ڿ��� �Ϲ� �ؽ�Ʈ ��ȣ ��/�Ǵ� 
// �ٸ� �߿��� ������ ���ԵǾ� ���� �� �ֽ��ϴ�.
// ���� ���� ������ �ִ��� ���� ���ڿ��� ������ �Ŀ� #error��(��) �����Ͻʽÿ�.
// �ٸ� �������� ��ȣ�� �����ϰų� �ٸ� ����� ������ ����Ͻʽÿ�.
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
// RFX_Text() �� RFX_Int() ���� ��ũ�δ� �����ͺ��̽��� �ʵ�
// ������ �ƴ϶� ��� ������ ���Ŀ� ���� �޶����ϴ�.
// ODBC������ �ڵ����� �� ���� ��û�� �������� ��ȯ�Ϸ��� �մϴ�
	RFX_Text(pFX, _T("[EM_Id]"), m_EM_Id);
	RFX_Text(pFX, _T("[EM_Name]"), m_EM_Name);
	RFX_Text(pFX, _T("[EM_Dept]"), m_EM_Dept);
	RFX_Text(pFX, _T("[EM_Salary]"), m_EM_Salary);

}
/////////////////////////////////////////////////////////////////////////////
// CEmployees ����

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


