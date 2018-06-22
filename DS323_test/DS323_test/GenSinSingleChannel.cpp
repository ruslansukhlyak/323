#include "stdafx.h"

#include "DS323.h"

void GesSinSingleChannel(UINT32 BaseAdr, LPWORD PortData, ASD_HANDLE hDevice)
{
	WritePort16(BaseAdr + DACADR, 1, hDevice);
	WritePort16(BaseAdr + DAT, 8192, hDevice);
	WritePort16(BaseAdr + MULT, (WORD)0, hDevice);
	//Разрешение генерации
	WritePort16(BaseAdr + DACADR, 129, hDevice);
	//Подключение нагрузки
	WritePort16(BaseAdr + DACCSR, 1, hDevice);
}