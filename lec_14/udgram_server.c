/* A simple echo UNIX Domain datagram server */
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h> /* Новый include-файл вместо 
    netinet/in.h и arpa/inet.h */
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int sockfd;
    int clilen, n;
    char line[1000];
    struct sockaddr_un servaddr, cliaddr; /* новый 
        тип данных под адреса сокетов */
    if((sockfd = socket(AF_UNIX, SOCK_DGRAM, 0)) < 0) 
    /* Изменен тип семейства протоколов */
    {
        perror(NULL);
        exit(1);
    }
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_UNIX; /* Изменен тип 
        семейства протоколов и имя поля в структуре */
    strcpy(servaddr.sun_path,"BBBB"); /* Локальный 
        адрес сокета сервера – BBBB – в текущей 
        директории */
    if(bind(sockfd, (struct sockaddr *) &servaddr, 
    SUN_LEN(&servaddr)) < 0) /* Изменено вычисление 
        фактической длины адреса */
    {
        perror(NULL);
        close(sockfd);
        exit(1);
    }
    while(1) {
        clilen = sizeof(struct sockaddr_un); /* Изменено 
            вычисление максимальной длины для адреса
            клиента */
        if((n = recvfrom(sockfd, line, 999, 0, 
        (struct sockaddr *) &cliaddr, &clilen)) < 0){
            perror(NULL);
            close(sockfd);
            exit(1);
        }
        if(sendto(sockfd, line, strlen(line), 0, 
        (struct sockaddr *) &cliaddr, clilen) < 0){
            perror(NULL);
            close(sockfd);
            exit(1);
        }
    }
    return 0;
}
