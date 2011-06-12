/******** clear_ports.c ********/
/* 12 June 2011
   
   EXECUTION POSSIBLE ONLY AS SUPERUSER!
*/

#include <stdio.h>
#include <sys/io.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define port_add 0x378          // Data register

int main() {

  unsigned char a,c;
  
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
