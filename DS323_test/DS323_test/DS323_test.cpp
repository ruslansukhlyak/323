// DS323_test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "DS323.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice = 0;
	LPDWORD usblist = NULL;
	UINT32 BaseAdr = 0x0;
	LPWORD PortData = new WORD;
	ASD_HANDLE hDevice;

	//Открытие USB
	if ASD_FAILED(OpenUSBDevice(0, &hDevice))
	{
		return -1;
	}

	if (!GetID(&BaseAdr, PortData, hDevice))
	{
		return -2;
	}
	int channel = 25;
	do
	{
		system("cls");
		cout << "1 - Проверка записи/чтения регистра DACADR\n";
		cout << "2 - Проверка записи/чтения регистра DAC (CSR)\n";
		cout << "3 - Проверка записи/чтения регистра TIM\n";
		cout << "4 - Проверка записи/чтения регистра MULT\n";
		cout << "5 - Генерация синуса на выходе выбираемого канала\n";
		cout << "Введите номер операции : ";
		cin >> choice;
		switch (choice)
		{
		case 1: WriteReadDACADR(BaseAdr, PortData, hDevice); break;
		case 2: WriteReadDACCSR(BaseAdr, PortData, hDevice); break;
		//case 3: WriteReadTIM(BaseAdr, PortData, hDevice); break;
		case 4: WriteReadMULT(BaseAdr, PortData, hDevice); break;
		case 5: GesSinSingleChannel(BaseAdr, PortData, hDevice); break;
		default: break;
		}
			

	} while (choice != 0);
	
    return 0;
}

