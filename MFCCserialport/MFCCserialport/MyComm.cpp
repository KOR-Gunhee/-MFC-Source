#include "stdafx.h"
#include "MyComm.h"


CMyComm::CMyComm()
{
}


CMyComm::~CMyComm()
{
	if (m_bIsOpenned)
		Close();
	delete m_pEvent;
}

CMyComm::CMyComm(CString port, CString baudrate, CString parity, CString databit, CString stopbit)
{
	m_sComPort = port;
	m_sBaudRate = baudrate;
	m_sParity = parity;
	m_sDataBit = databit;
	m_sStopBit = stopbit;
	m_bFlowChk = 1;
	m_bIsOpenned = FALSE;
	m_nLength = 0;
	memset(m_sInBuf, 0, MAXBUF * 2);
	m_pEvent = new CEvent(FALSE, TRUE);
}

void CMyComm::ResetSerial()
{
	DCB				dcb;
	DWORD			DErr;
	COMMTIMEOUTS	CommTimeOuts;

	if (!m_bIsOpenned)
		return;

	//��� ��Ʈ�� ��� ������ ����
	ClearCommError(m_hComDev, &DErr, NULL);
	// ��� ��Ʈ�� Input/Output Buffer ����� ����
	SetupComm(m_hComDev, InBufSize, OutBufSize);
	// ��� Rx/Tx ������ �����ϰ� ���� Buffer�� ������ ����
	PurgeComm(m_hComDev, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);

	// set up for overlapped I/O
	// ��� ���λ󿡼� �ѹ���Ʈ�� ���۵ǰ� ���� ����Ʈ�� ���۵Ǳ������ �ð�
	CommTimeOuts.ReadIntervalTimeout = MAXDWORD;
	// Read doperation ���� TimeOut�� ������� ����
	CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
	CommTimeOuts.ReadTotalTimeoutConstant = 0;

	// CBR_9600 is approximatelu 1byte/ms. For our purposes, allow
	// double the expected time per character for a fudge factor.
	CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
	CommTimeOuts.WriteTotalTimeoutConstant = 1000;
	// ��� ��Ʈ�� TimeOut�� ����
	SetCommTimeouts(m_hComDev, &CommTimeOuts);



	memset(&dcb, 0, sizeof(DCB));
	dcb.DCBlength = sizeof(DCB);
	// ��� ��Ʈ�� DCB�� ����
	GetCommState(m_hComDev, &dcb);
	// DCb�� ���� (DCB: �ø��� ����� ���� �Ķ����, MSDN ����)
	dcb.fBinary = TRUE;
	dcb.fParity = TRUE;

	if (m_sBaudRate == "300")
		dcb.BaudRate = CBR_300;
	else if (m_sBaudRate == "600")
		dcb.BaudRate = CBR_600;
	else if (m_sBaudRate == "1200")
		dcb.BaudRate = CBR_1200;
	else if (m_sBaudRate == "2400")
		dcb.BaudRate = CBR_2400;
	else if (m_sBaudRate == "4800")
		dcb.BaudRate = CBR_4800;
	else if (m_sBaudRate == "9600")
		dcb.BaudRate = CBR_9600;
	else if (m_sBaudRate == "14400")
		dcb.BaudRate = CBR_14400;
	else if (m_sBaudRate == "19200")
		dcb.BaudRate = CBR_19200;
	else if (m_sBaudRate == "28800")
		dcb.BaudRate = CBR_38400;
	else if (m_sBaudRate == "33600")
		dcb.BaudRate = CBR_38400;
	else if (m_sBaudRate == "38400")
		dcb.BaudRate = CBR_38400;
	else if (m_sBaudRate == "56000")
		dcb.BaudRate = CBR_56000;
	else if (m_sBaudRate == "57600")
		dcb.BaudRate = CBR_57600;
	else if (m_sBaudRate == "115200")
		dcb.BaudRate = CBR_115200;
	else if (m_sBaudRate == "128000")
		dcb.BaudRate = CBR_128000;
	else if (m_sBaudRate == "256000")
		dcb.BaudRate = CBR_256000;
	else if (m_sBaudRate == "PCI_9600")
		dcb.BaudRate = 1075;
	else if (m_sBaudRate == "PCI_19200")
		dcb.BaudRate = 2212;
	else if (m_sBaudRate == "PCI_38400")
		dcb.BaudRate = 4300;
	else if (m_sBaudRate == "PCI_57600")
		dcb.BaudRate = 6450;
	else if (m_sBaudRate == "PCI_500K")
		dcb.BaudRate = 56000;


	if (m_sParity == "None")
		dcb.Parity = NOPARITY;
	else if (m_sParity == "Even")
		dcb.Parity = EVENPARITY;
	else if (m_sParity == "Odd")
		dcb.Parity = ODDPARITY;

	if (m_sDataBit == "7 Bit")
		dcb.ByteSize = 7;
	else if (m_sStopBit == "8 Bit")
		dcb.ByteSize = 8;

	if (m_sStopBit == "1 Bit")
		dcb.StopBits = ONESTOPBIT;
	else if (m_sStopBit == "1.5 Bit")
		dcb.StopBits = ONE5STOPBITS;
	else if (m_sStopBit == "2 Bit")
		dcb.StopBits = TWOSTOPBITS;

	dcb.fRtsControl = RTS_CONTROL_ENABLE;
	dcb.fDtrControl = DTR_CONTROL_ENABLE;
	dcb.fOutxDsrFlow = FALSE;

	if (m_bFlowChk)
	{
		dcb.fOutX = FALSE;
		dcb.fInX = FALSE;
		dcb.XonLim = 2048;
		dcb.XoffLim = 1024;
	}
	else
	{
		dcb.fOutxCtsFlow = TRUE;
		dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
	}

	// ������ DCB�� ��� ��Ʈ�� ���� �Ķ���͸� ����
	SetCommState(m_hComDev, &dcb);
	// Input Buffer�� �����Ͱ� ������ �� �̺�Ʈ�� �߻��ϵ��� ����
	SetCommMask(m_hComDev, EV_RXCHAR);

}

void CMyComm::Close()
{
	if (!m_bIsOpenned)
		return;

	m_bIsOpenned = FALSE;
	SetCommMask(m_hComDev, 0);
	EscapeCommFunction(m_hComDev, CLRDTR);
	PurgeComm(m_hComDev, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
	Sleep(500);

}

UINT CommThread(LPVOID lpData)
{
	extern short g_nRemoteStatus;
	DWORD		ErrorFlags;
	COMSTAT		ComStat;
	DWORD		EvtMask;
	char		buf[MAXBUF];
	DWORD		Length;
	int			size;
	int			insize = 0;

	//��� Ŭ������ ��ü �����͸� ����
	CMyComm* Comm = (CMyComm*)lpData;

	//��� ��Ʈ�� ���� �ִٸ�
	while (Comm->m_bIsOpenned)
	{
		EvtMask = 0;
		Length = 0;
		insize = 0;
		memset(buf, '\0', MAXBUF);
		//�̺�Ʈ�� ��ٸ�
		WaitCommEvent(Comm->m_hComDev, &EvtMask, NULL);
		ClearCommError(Comm->m_hComDev, &ErrorFlags, &ComStat);
		// EV_RXCHAR���� �̺�Ʈ�� �߻��ϸ�
		if ((EvtMask & EV_RXCHAR) && ComStat.cbInQue)
		{
			if (ComStat.cbInQue > MAXBUF)
				size = MAXBUF;
			else
				size = ComStat.cbInQue;

			do
			{
				ClearCommError(Comm->m_hComDev, &ErrorFlags, &ComStat);
				//OVERLAPPED I/O�� ���� �����͸� ����
				if (!ReadFile(Comm->m_hComDev, buf + insize, size, &Length, &(Comm->m_OLR)))
				{
					//����
					TRACE("Error in ReadFile\n");
					if (GetLastError() == ERROR_IO_PENDING)
					{
						if (WaitForSingleObject(Comm->m_OLR.hEvent, 1000) != WAIT_OBJECT_0)
							Length = 0;
						else
							GetOverlappedResult(Comm->m_hComDev, &(Comm->m_OLR), &Length, FALSE);
					}
					else
						Length = 0;
				}
				insize += Length;
			} while ((Length != 0) && (insize < size));
			ClearCommError(Comm->m_hComDev, &ErrorFlags, &ComStat);

			if (Comm->m_nLength + insize > MAXBUF * 2)
				insize = (Comm->m_nLength + insize) - MAXBUF * 2;

			//�̺�Ʈ �߻��� ��� �ߴ��ϰ� Ipnput Buffer�� �����͸� ����
			Comm->m_pEvent->ResetEvent();
			memcpy(Comm->m_sInBuf + Comm->m_nLength, buf, insize);
			Comm->m_nLength += insize;
			// ���簡 ������ �ٽ� �̺�Ʈ�� Ȱ��ȭ ��Ű��
			Comm->m_pEvent->SetEvent();
			LPARAM temp = (LPARAM)Comm;
			// �����Ͱ� ���Դٴ� �޽����� �߻�
			SendMessage(Comm->m_hWnd, WM_MYRECEIVE, Comm->m_nLength, temp);
		}
	}
	PurgeComm(Comm->m_hComDev, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
	LPARAM temp = (LPARAM)Comm;
	// �����尡 ����� �� ���� �޽����� ����
	SendMessage(Comm->m_hWnd, WM_MYCLOSE, 0, temp);
	return 0;
}

void CMyComm::HandleClose()
{
	CloseHandle(m_hComDev);
	CloseHandle(m_OLR.hEvent);
	CloseHandle(m_OLW.hEvent);
}

BOOL CMyComm::Create(HWND hWnd)
{
	m_hWnd = hWnd;				//�޽����� ���� �� ���

	m_hComDev = CreateFile(m_sComPort, GENERIC_READ | GENERIC_WRITE, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);			//�ø��� ��Ʈ ����

	if (m_hComDev != INVALID_HANDLE_VALUE)				//��Ʈ�� ���������� ������
		m_bIsOpenned = TRUE;			// ����
	else					// �ƴϸ�
		return FALSE;			//����

	ResetSerial();			// �ø��� ��Ʈ�� ���� ����� �ʱ�ȭ

	m_OLW.Offset = 0;			// Write OVERALPPED structure �ʱ�ȭ
	m_OLW.OffsetHigh = 0;
	m_OLR.Offset = 0;			// Read OVERLAPPED structure �ʱ�ȭ
	m_OLR.OffsetHigh = 0;
	// Overlapped ����ü�� �̺�Ʈ ����
	m_OLR.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (m_OLR.hEvent == NULL) 
	{
		CloseHandle(m_OLR.hEvent);
		return FALSE;
	}
	m_OLW.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (m_OLW.hEvent == NULL)
	{
		CloseHandle(m_OLW.hEvent);
		return FALSE;
	}
	//�ø��� �����͸� �ޱ� ���� ������ ����
	AfxBeginThread(CommThread, (LPVOID)this);
	//DTR(Data Teminal Ready) signal �� ����
	EscapeCommFunction(m_hComDev, SETDTR);
	return TRUE;

}

BOOL CMyComm::Send(LPCTSTR outbuf, int len)
{
	BOOL		bRet = TRUE;
	DWORD		ErrorFlags;
	COMSTAT		ComStat;

	DWORD		BytesWritten;
	DWORD		BytesSent = 0;

	// ��� ��Ʈ�� ��� ������ ����
	ClearCommError(m_hComDev, &ErrorFlags, &ComStat);
	// Overlapped I/O�� ���Ͽ� Outbuf�� ������ len ���� ��ŭ ����
	if(!WriteFile(m_hComDev, outbuf, len, &BytesWritten, &m_OLW))
	{ 
		if (GetLastError() == ERROR_IO_PENDING)
		{
			if (WaitForSingleObject(m_OLW.hEvent, 1000) != WAIT_OBJECT_0)
				bRet = FALSE;
			else
				GetOverlappedResult(m_hComDev, &m_OLW, &BytesWritten, FALSE);
		}
		else
			bRet = FALSE;
	}
	// �ٽ� �� �� ��� ��Ʈ�� ��� ������ ����
	ClearCommError(m_hComDev, &ErrorFlags, &ComStat);

	return bRet;
}

int CMyComm::Receive(LPSTR inbuf, int len)
{
	CSingleLock lockObj((CSyncObject*)m_pEvent, FALSE);

	if (len == 0)
		return -1;
	else if (len > MAXBUF)
		return -1;

	if (m_nLength == 0)
	{
		inbuf[0] = '\n';
		return 0;
	}
	//�������̶�� �� ��ƾ���� ���� ���� ���� �������� ���̸�ŭ Input Buffer���� �����͸� ����
	else if (m_nLength <= len)
	{
		lockObj.Lock();
		memcpy(inbuf, m_sInBuf, m_nLength);
		memset(m_sInBuf, 0, MAXBUF * 2);
		int tmp = m_nLength;
		m_nLength = 0;
		lockObj.Unlock();
		return tmp;
	}
	else
	{
		lockObj.Lock();
		memcpy(inbuf, m_sInBuf, len);
		memmove(m_sInBuf, m_sInBuf + len, MAXBUF * 2 - len);
		m_nLength -= len;
		lockObj.Unlock();
		return len;
	}
}

void CMyComm::Clear()
{
	PurgeComm(m_hComDev, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
	memset(m_sInBuf, 0, MAXBUF * 2);
	m_nLength = 0;
}