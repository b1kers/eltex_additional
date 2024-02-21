/* A simple echo UNIX Domain datagram client */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h> /* Новый include-файл вместо 
    netinet/in.h и arpa/inet.h */
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
int main() /* Аргументы командной строки не нужны,
     так как сервис является локальным, и не нужно 
    указывать, к какой машине мы обращаемся с запросом */
{
    int sockfd;
    int n, len;
    char sendline[1000], recvline[1000];
    struct sockaddr_un servaddr, cliaddr; /* новый тип 
    данных под адреса сокетов */
    if((sockfd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0) 
    /* Изменен тип семейства протоколов */
    {
        perror(NULL);
        exit(1);
    }
    bzero(&cliaddr, sizeof(cliaddr));
    cliaddr.sun_family= AF_UNIX; /* Изменен тип 
        семейства протоколов и имя поля в структуре */
    strcpy(cliaddr.sun_path,"AAAA");/* Локальный адрес 
        сокета клиента – AAAA – в текущей директории */
    if(bind(sockfd, (struct sockaddr *) &cliaddr, 
    SUN_LEN(&cliaddr)) < 0) /* Изменено вычисление 
        фактической длины адреса */
    {
        perror(NULL);
        close(sockfd);
        exit(1);
    }
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_UNIX; /* Изменен тип 
        семейства протоколов и имя поля в структуре */
    strcpy(servaddr.sun_path,"BBBB"); /* Локальный адрес 
        сокета сервера – BBBB – в текущей директории */
    printf("String => ");
    fgets(sendline, 1000, stdin);
    if(sendto(sockfd, sendline, strlen(sendline)+1, 
    0, (struct sockaddr *) &servaddr, 
    SUN_LEN(&servaddr)) < 0) /* Изменено вычисление 
        фактической длины адреса */
    {
        perror(NULL);
        close(sockfd);
        exit(1);
    }
    if((n = recvfrom(sockfd, recvline, 1000, 0, 
    (struct sockaddr *) NULL, NULL)) < 0){
        perror(NULL);
        close(sockfd);
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);
    close(sockfd);
    return 0;
}
