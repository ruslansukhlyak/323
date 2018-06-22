#include "stdafx.h"

#include "DS323.h"

bool GetID(PUINT32 BaseAdr, LPWORD PortData, ASD_HANDLE hDevice)
{
	int flag = 0;
	for (unsigned int i = 0; i < 0x400; i = i + 8)
	{
		WritePort16(i + ID, '0', hDevice);
		ReadPort16(i + ID, PortData, hDevice);
		if (*PortData == 23)
		{
			WritePort16(i + ID, '2', hDevice);
			ReadPort16(i + ID, PortData, hDevice);
			printf("Заводской номер : 23 \n");
			printf("Адрес - 0x%X \n", i);

			printf("ID : %d \n\n", *PortData);
			WritePort16(i + ID, '1', hDevice);
			ReadPort16(i + ID, PortData, hDevice);
			int sec_byte = (int)*PortData;
			printf("Старшие 5 разрядов 2 байта кода идентификации : %d \n", sec_byte >> 3);
			printf("Младшие 3 разрядов 2 байта кода идентификации : %d \n", sec_byte & 7);
			flag = 1;
			*BaseAdr = i;
		}
	}
	if (flag == 0)
	{
		cout << "Нет платы с данным номером\n" << "Enter для выхода\n";
		_getch();
		return 0;
	}
	else
	{
		cout << "Enter для выхода\n";
		
		_getch();
		return 1;
	}
}