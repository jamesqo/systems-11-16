#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int child_proc_main(){

  printf("child pid: %d\n", getpid() );
  int r = (rand() % 16) + 5;
  sleep(r);
  printf("I'm done\n");
  return r;
}
