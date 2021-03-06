/******** bob.c ********/
/* 11 June 2011
   
   EXECUTION POSSIBLE ONLY AS SUPERUSER!
*/

#include <stdio.h>
#include <sys/io.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define port_add 0x378          // Data register

int main() {

  unsigned char c;
  int a;

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
  
  // Infinite Loop
  while(1 > 0){
    
    // Outer CONTROL loop
    for(c=0x00; c <= 0x0f; c++){
      outb(c^0x0b,port_add+2);
      

      // Inner DATA loop
      for(a=0; a < 256; a++){
	
	outb((unsigned char)a,port_add);
	
	
	
	fputs("\r",stdout);
	printf("Present values are c = %X    a = %2X        Total: %4d                          ",c,a,
	       256*(int)c + (int)a);
	fflush(stdout);
	usleep(100000);
      }
    }
    
  }
  return(0);
}
