#include <ansi_c.h>
#include "CMXWinSDK.h"
#include "GlobalVariables.h"
#include <windows.h>

unsigned int ChassisHandle;
unsigned int  BoardHandle;
unsigned int port=1;
unsigned int IP[4] = {192, 168, 10,30};
unsigned int IP2[4] = {192, 168, 10,30};
unsigned int Device_MAC[6] = { 01, 01, 01, 01, 01, 03 };	// MAC address
unsigned int new_MAC[6] ;
double  firmware;
unsigned int serial_no;
unsigned int GetIP[4] ;
unsigned int ip2[4];




int main (int argc, char *argv[])
{
	
	ChassisHandle = CmxOpenChassis (IPAdd, &Error);
	printf ("Open Chassis Error is %d\n",Error);

	Sleep(500);
	
	
	
	CmxSetModuleName (ChassisHandle, port, ModuleName1, &Error);
	Sleep(500);


	

/*********************************BC TEST**********************/

		
	BoardHandle=CmxMTOpenBoard(IPAdd,port, &Error);
	printf ("OpenBoard Error is %d\n",Error);
	Sleep(500);
	CmxMTGetFirmware(BoardHandle,&firmware,&Error);
	Sleep(500);



	//CmxMTSetIp(BoardHandle,IP2,&Error);
	//Sleep(500);
	//	CmxMTGetIp(BoardHandle,GetIP,&Error);
	//Sleep(500);
	//CmxMTSetMac(BoardHandle,Device_MAC,&Error);
	//	Sleep(500);
	//	CmxMTGetMac(BoardHandle,new_MAC,&Error);
	//Sleep(500);
	CmxMTSetChannel(BoardHandle,TIMER_CHANNEL_ALL,1,20,&Error);
	printf ("Set Channel Error is %d\n",Error);
	Sleep(500);
	
	CmxMTStartChannel(BoardHandle,TIMER_CHANNEL_ALL,&Error);
	printf ("Start Channel Error is %d\n",Error);
		
	getchar();
	// Komutlar Burada Biter

	CmxDiscardChassis (ChassisHandle, &Error);
	printf ("Discard Chassis Error is %d\n",Error);

	return 0;
}




