/*
    Name: Hai Dang Hoang
    Email: goldsea5191@gmail.com

    intquit.c: This program establishes the same handler for SIGINT
    and SIGQUIT (SIGQUIT is generated by the terminal driver) when we type the
    terminal quit character, usually Control -\.) The code of the handler distinguishes
    the two signals by examining the sig argument, and takes different actions for each
    signal. In the main() function, we use pause() to block the process until a signal is caught
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void sigHandler(int sig)
{
  static int count = 0;
  if (sig == SIGINT)
  {
    printf("  Caught SIGINT (%d) ! \n",count);
    count++;
    return;                             // Resume execution at point of interruption
  }
  if (sig == SIGQUIT)
  {
    printf("  Caught SIGQUIT - that's all folks \n");
    exit(EXIT_SUCCESS);
  }
}
int main(int argc, char * argv[])
{
  if (signal(SIGINT,sigHandler) == SIG_ERR)
  {
      perror("Error - SIGINT \n");
      exit(EXIT_FAILURE);
  }
  if (signal(SIGQUIT,sigHandler) == SIG_ERR)
  {
      perror("Error - SIGQUIT \n");
      exit(EXIT_FAILURE);
  }

  while(1)                          // Loop forever, waiting for signals
  {
      pause();                      // Block until a signal is Caught
  }
  exit(EXIT_SUCCESS);
}
