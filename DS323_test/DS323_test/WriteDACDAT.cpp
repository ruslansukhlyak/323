#include "stdafx.h"

#include "DS323.h"

void WriteDACDAT(UINT32 BaseAdr, LPWORD PortData, ASD_HANDLE hDevice, PINT *data)
{
	//Добавить запрет генерации
	WritePort16(BaseAdr + DAT, (WORD)data, hDevice);

}