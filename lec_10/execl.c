#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
  printf("Будет выполнена программа %s...\n\n",
         argv[0]);
  printf("Выполняется %s", argv[0]);
  execl("hello"," ","Hello", "World!", NULL);
  return 0;
}
