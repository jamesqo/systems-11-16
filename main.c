#include "child_proc.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  srand(time(NULL));

  printf("Initial message.\nPID: %ld\n", (long)getpid());

  // TODO: Check if fork() returns -1 and handle accordingly
  if (fork() == 0 || fork() == 0) {
    // We're the child.
    child_proc_main();
  }
  else {
    // We're the parent. Wait for any child to finish.
    int wstatus;
    pid_t child_pid = wait(&wstatus);
    if (child_pid == -1) {
      printf("%s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
    printf("A child just finished. Child PID: %ld\n", (long)getpid());
    int number_of_seconds_it_slept = WEXITSTATUS(wstatus);
    printf("It slept for this many seconds: %d\n", number_of_seconds_it_slept);
    printf("The parent is done.\n");
  }

  return 0;
}
