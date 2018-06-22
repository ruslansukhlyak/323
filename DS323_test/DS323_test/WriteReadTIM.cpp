#include "stdafx.h"

#include "DS323.h"

void WriteReadTIM(UINT32 BaseAdr, LPWORD PortData, ASD_HANDLE hDevice)
{
	system("cls");
	WORD data;
	int error = 0;

	for (int i = 0; i < 65536; i++)
	{
		WritePort16(BaseAdr + TIM, i, hDevice);
		ReadPort16(BaseAdr + TIM, &data, hDevice);
		if (data != i)
		{
			error++;
			cout << "Записано - " << i << endl;
			cout << "Считано  - " << data << endl;
		}
	}
	if (error != 0)
	{
		cout << "Количество ошибок - " << error << endl;
	}
	else
	{
		cout << "Тест завершился без ошибок" << endl;
	}
	_getch();
}