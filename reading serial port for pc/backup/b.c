#include <windows.h>
#include <stdio.h>

int main(){

HANDLE serialHandle;

//serialHandle = CreateFile("\\\\.\\COM3", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
serialHandle = CreateFile("COM3", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

if(serialHandle == INVALID_HANDLE_VALUE){
	printf("fucking shit la");
	exit(0);
}

// Do some basic settings
DCB serialParams = { 0 };
serialParams.DCBlength = sizeof(serialParams);

GetCommState(serialHandle, &serialParams);
serialParams.BaudRate = CBR_115200;
serialParams.ByteSize = 8;
serialParams.StopBits = ONESTOPBIT;
serialParams.Parity = NOPARITY;
if(!SetCommState(serialHandle, &serialParams)){
	printf("life sucks");
	exit(0);
}

// Set timeouts
COMMTIMEOUTS timeout = { 50 };
timeout.ReadIntervalTimeout = 50;
timeout.ReadTotalTimeoutConstant = 50;
timeout.ReadTotalTimeoutMultiplier = 50;
timeout.WriteTotalTimeoutConstant = 50;
timeout.WriteTotalTimeoutMultiplier = 10;

if(SetCommTimeouts(serialHandle, &timeout)){
	printf("time out ar");
	exit(0);
}
while(1){

	char szBuff[1+1] = {0};
	DWORD dwBtyesRead = 0;

	if(!ReadFile(serialHandle , szBuff , 1 , &dwBtyesRead , NULL)){
		printf("Cant read ar");
		exit(0);
	}
	
	printf("%c" , szBuff[0]);

}

CloseHandle(serialHandle);

}