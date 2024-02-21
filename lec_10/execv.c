#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
  printf("Программа %s будет выполнена...\n\n",
         argv[0]);
  printf("Выполняется %s", argv[0]);
  execv("hello",argv);
  return 0;
}
