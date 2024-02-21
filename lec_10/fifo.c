#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
int main()
{
	int fd_fifo;
	char buffer[]="Sample string\n";
	char buf[BUFSIZ];
	unlink("/tmp/fifo0.1");
	if ((mkfifo("/tmp/fifo0.1", O_RDWR)) == -1)
	{
		printf("cannot");
	}
	if ((fd_fifo = open("/tmp/fifo0.1", O_RDWR)) == -1)
	 {
		 printf("fail");
	 }
	write(fd_fifo, buffer, strlen(buffer));
	read(fd_fifo, &buf, sizeof(buf));
	printf("Read %s", buf);
	return 0;
}
