#include <stdlib.h>
#include <stdio.h>

#include <Windows.h>


#include "rs232.h"

int main(){

  int i, n;
  int cport_nr=3;        
  int bdrate=115200;       
		  
  int interval = 1;

  unsigned char buf[4096];

  char mode[]={'8','N','1',0};


  if(RS232_OpenComport(cport_nr, bdrate, mode, 0))
  {
    printf("Can not open comport\n");

    return(0);
  }

  while(1)
  {
    n = RS232_PollComport(cport_nr, buf, 4095);

    if(n > 0)
    {
		buf[n] = 0;   /* always put a "null" at the end of a string! */

		for(i=0; i < n; i++)
		{
			if(buf[i] < 32)  /* replace unreadable control-codes by dots */
			{
			  buf[i] = '.';
			}
		}

		printf("received %i bytes: %s\n", n, (char *)buf);


		char key = 0x41;
		if(buf[0] == 'f'){
		  key = 0x46;
		}else if(buf[0] == 'd'){
		  key = 0x44;
		}
		  
		  
		INPUT ip;

		// Set up a generic keyboard event.
		ip.type = INPUT_KEYBOARD;
		ip.ki.wScan = 0; // hardware scan code for key
		ip.ki.time = 0;
		ip.ki.dwExtraInfo = 0;

		// Press the "A" key
		ip.ki.wVk = key; // virtual-key code for the "a" key
		ip.ki.dwFlags = 0; // 0 for key press
		SendInput(1, &ip, sizeof(INPUT));

		// Release the "A" key
		ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
		SendInput(1, &ip, sizeof(INPUT));
	
    }else{
		printf("no input\n");
	}

    Sleep(interval);
  }

  return(0);

}