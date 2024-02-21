#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/syscall.h>
#define PERMS 0777 

int get(int fd, int pos, char *buf, size_t size)
{
	if (lseek(fd, pos, 0) >= 0)
		return read(fd, buf, size);
	else
		return -1;
		
}

int main(int argc, char *argv[])
{
	// file descriptor
	int fd, fd2;
	fd = open(argv[1], O_RDONLY, 0);
	//printf("%n", &fd);
	//if (fd == -1)
	//	printf("Cannot open file");
	fd2 = creat(argv[2], PERMS);
	size_t size;
	char buf[BUFSIZ];
	double a=1.1, b=2.2, c=3.3;
	//double res_str[BUFS];
	//pipe(fd);
	//write(fd, &c, BUFSIZ);
	while (get(fd, 11, buf, size) > 0)
		if (write(fd2, &buf, size) != size)
			printf("FATAL");
	//close(fd);
	fd = open(argv[2], O_RDONLY, 0);
	return 0;
	//printf("%s\n", &buf);

}
