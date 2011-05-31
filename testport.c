/******** testport.c ********/
/* 31 May 2011
   
   EXECUTION POSSIBLE ONLY AS SUPERUSER!
*/

#include <stdio.h>
#include <sys/io.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define PORTBASE 0x378       // Data register
#define PORTSTATUS 0x378+1   // Status register
#define PORTCTRL 0x378+2     // Control register

void respond(void);

int main() {
  // Get access to PORTBASE
  if (ioperm(PORTBASE, 1, 1)) {
    printf("Couldn't get the port.\n");
    perror("ioperm problem:");
  }
  // Get access to PORTSTATUS
  if (ioperm(PORTSTATUS, 1, 1)) {
    printf("Couldn't get the port.\n");
    perror("ioperm problem:");
  }
  // Start Infinite loop
  for(;;){
    // Tring to avoid %100cpu usage
    sleep(1);
    //printf("I assume we're in this loop here, because PORTSTATUS = %x\n",inb(PORTSTATUS));
    unsigned int high = 0x7F;
    unsigned int low  = 0x6F;
    printf("Low = %X  High = %X\n",low,high);

    // Pin 13 of status register became low (from 0x7F to 0x6F)
    
    //if (inb(PORTSTATUS) == 78){
      // Notify about pin status change
      printf("status port register value %X\n",inb(PORTSTATUS));
      // External function respond
      respond();
    //}
  }
  return 0;
}

void respond(void){
  // Set pin 2 (pin 0 data register) high
  outb(0x1, PORTBASE);
  printf("Set pin 2 (pin 0 data register) high\n");
  sleep(1);
  // Set data register low
  outb(0x0, PORTBASE);
  printf("Set data register low\n");
  
  return;
}

