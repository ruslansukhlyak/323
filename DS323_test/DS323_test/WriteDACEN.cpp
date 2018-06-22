#include "stdafx.h"
#include <cmath>

#include "DS323.h"

void WriteDACEN(UINT32 BaseAdr, LPWORD PortData, ASD_HANDLE hDevice, int channel)
{
	int temp;
	if (channel < 17)
	{
		temp = pow(2, channel - 1);
		WritePort16(BaseAdr + DACEN0, (WORD)temp, hDevice);
	}
	else
	{
		temp = pow(2, channel - 17);
		WritePort16(BaseAdr + DACEN1, (WORD)temp, hDevice);
	}
	
}