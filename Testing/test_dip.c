/******** test_dip.c ********/
/* 28 June 2012
   
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
  
  unsigned char a,c,prev,ln,un;
  /* int value; */
  
  /* if(argc > 1) printf("%s\n",argv[1]); */
  
  /* if(argc > 1 && atoi(argv[1]) == 1) */
  /*   value = 1; */
  /* else */
  /*   value = 0; */
  
  
  
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
  
  /* if(value == 1) */
  /*   c = 0x08; */
  /* else */
  
  
  a = 0x00;
  
  
  prev = inb(port_add+2)^0x0b;
  printf("Previous value on CONTROL port: %X\n",prev);
  
  c = prev | 0x01;
  
  outb(c^0x0b,port_add+2);
  outb(a,port_add);
  
  
  
  fputs("\r",stdout);
  printf("Present values are c = %X    a = %2X        Total: %4d                          ",c,a,
	 256*(int)c + (int)a);
  fflush(stdout);
  printf("\n");
  
  sleep(1);
  sleep(1);
  
  ln = inb(port_add+1);
  ln = ln >> 4;
  printf("Present value on the STATUS port: %X\n",ln);
  un = inb(port_add+1);
  printf("Present value on the STATUS port: %X\n",un);
  ln = ln & 0x0f;
  un = un & 0xf0;
  printf("Final byte = %X\n",(un|ln)^0x88);

  
  sleep(1);
  
  
  
  printf("Turning bit 0 off again.../n");
  c = c^0x01;
  outb(c^0x0b,port_add+2);
  outb(a,port_add);
   fputs("\r",stdout);
  printf("Present values are c = %X    a = %2X        Total: %4d                          ",c,a,
	 256*(int)c + (int)a);
  fflush(stdout);
  printf("\n");
 
  
  return(0);
}
