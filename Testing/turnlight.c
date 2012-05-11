/******** turnlight.c ********/
/* 11 May 2012
   
   EXECUTION POSSIBLE ONLY AS SUPERUSER!
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/io.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define port_add 0x378          // Data register

int main(int argc, char *argv[]) {
  
  unsigned char a,c;
  int value;
  
  if(argc > 1) printf("%s\n",argv[1]);
  
  if(argc > 1 && atoi(argv[1]) == 1)
    value = 1;
  else
    value = 0;
  
  
  
  // Get access to PORTBASE
  if (ioperm(port_add, 1, 1)) {
    printf("Couldn't get the port.\n");
    perror("ioperm problem:");
  }
  // Get access to PORTSTATUS
  if (ioperm(port_add+1, 1, 1)) {
    printf("Couldn't get the port.\n");
    perror("ioperm problem:");
  }
  // Get access to PORTCTRL
  if (ioperm(port_add+2, 1, 1)) {
    printf("Couldn't get the port.\n");
    perror("ioperm problem:");
  }
  
  
  printf("\n");
  
  if(value == 1)
    c = 0x08;
  else
    c = 0x00;
  
  a = 0x00;
  
  outb(c^0x0b,port_add+2);
  outb(a,port_add);
  
  
  
  fputs("\r",stdout);
  printf("Present values are c = %X    a = %2X        Total: %4d                          ",c,a,
	 256*(int)c + (int)a);
  fflush(stdout);
  usleep(100000);
  
  printf("\n");
  return(0);
}
