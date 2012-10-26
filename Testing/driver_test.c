#include <parport.h>

struct parport_driver{
  const char *name;
  void (*attach) (struct parport *);
  void (*detach) (struct parport *);
  struct parport_driver *next;
};

int parport_register_driver(struct parport_driver *driver);


int main{

  return 0;
}
