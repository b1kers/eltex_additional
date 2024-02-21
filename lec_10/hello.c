#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
  int i=0;
  printf("%s\n",argv[0]);
  printf("Программа запущена и получила строку : ");
  sleep(10);
  while(argv[++i] != NULL)
  printf("%s ",argv[i]);
  return 0;
}
