#pragma once

#include "windows.h"
#include "conio.h"
#include "iostream"

#include "../../../../../asdbial2/include/asdbial2.h"

#define DACADR 0x0
#define DACCSR 0x2
#define DAT 0x4
#define MEMA 0x6
#define MEMD 0x8
#define TIM 0xA
#define MULT 0xC
#define DACEN0 0xE
#define DACEN1 0x10
#define EPROM 0x12
#define ID 0x14

using namespace std;

bool GetID(PUINT32 BaseAdr, LPWORD PortData, ASD_HANDLE hDevice);
void WriteReadDACADR(UINT32 BaseAdr, LPWORD PortData, ASD_HANDLE hDevice);
void WriteReadDACCSR(UINT32 BaseAdr, LPWORD PortData, ASD_HANDLE hDevice);
void WriteDACDAT(UINT32 BaseAdr, LPWORD PortData, ASD_HANDLE hDevice, PINT *data);
void WriteReadTIM(UINT32 BaseAdr, LPWORD PortData, ASD_HANDLE hDevice);
void WriteReadMULT(UINT32 BaseAdr, LPWORD PortData, ASD_HANDLE hDevice);
void WriteDACEN(UINT32 BaseAdr, LPWORD PortData, ASD_HANDLE hDevice, int channel);

void GesSinSingleChannel(UINT32 BaseAdr, LPWORD PortData, ASD_HANDLE hDevice);
