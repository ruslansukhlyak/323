#include "stdafx.h"

#include "DS323.h"

void WriteReadDACADR(UINT32 BaseAdr, LPWORD PortData, ASD_HANDLE hDevice)
{
	system("cls");
	WORD data;
	int error = 0;

	for (int i = 0; i < 32; i++)
	{
		WritePort16(BaseAdr + DACADR, i, hDevice);
		ReadPort16(BaseAdr + DACADR, &data, hDevice);
		if (data != i)
		{
			error++;
			cout << "�������� - " << i << endl;
			cout << "�������  - " << data << endl;
		}
	}
	if (error != 0)
	{
		cout << "���������� ������ - " << error << endl;
	}
	else
	{
		cout << "���� ���������� ��� ������" << endl;
	}
	_getch();
}
