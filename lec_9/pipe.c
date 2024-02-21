#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	// file descriptor
	int fd[2], result;
	size_t size;
	double a=1.1, b=2.2, c=3.3;
	double res_str[3];
	pipe(fd);
	write(fd[1], &b, sizeof(double));
	size = read(fd[0], res_str, sizeof(double));
	write(fd[1], &c, sizeof(double));
	size = read(fd[0], res_str, sizeof(double));
	printf("%lf\n", res_str[0]);

}
