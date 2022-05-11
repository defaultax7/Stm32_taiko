#include <stdlib.h>
#include <stdio.h>

//#define WINVER 0x0500

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"


int main(){

int i, n,
      cport_nr=2,        /* /dev/ttyS0 (COM1 on windows) */
      bdrate=115200;       /* 9600 baud */
	  
	 int interval = 1;
	 int linuxInterval = interval * 1000;

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
          buf[i] = 0x0A;
		  //buf[i] = '.';
        }
      }

      printf("%s", (char *)buf);
	  

    }

#ifdef _WIN32
    Sleep(interval);
#else
    usleep(linuxInterval);  /* sleep for 100 milliSeconds */
#endif
  }

  return(0);

}