#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
   char pid[255];
   fork();
   fork();
   fork();
   fork();
   fork();
   sprintf(pid, "PID : %d\n",getpid());
   write(STDOUT_FILENO, pid, strlen(pid));
   exit(0);
}
