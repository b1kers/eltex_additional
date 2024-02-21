#include <signal.h>
#include <stdio.h>
int i=0; /* Счетчик числа обработок сигнала */
void (*p)(int); /* Указатель, в который будет 
занесен адрес предыдущего обработчика сигнала */ 
/* Функция my_handler – пользовательский обработчик 
    сигнала */ 
void my_handler(int nsig){ 
    printf("Receive signal %d, CTRL-Z pressed\n", nsig); 
    i = i+1;
    /* После 5-й обработки возвращаем первоначальную 
    реакцию на сигнал */
    if(i == 5) (void)signal(SIGQUIT, p);
}
int main(void){ 
    /* Выставляем свою реакцию процесса на сигнал 
SIGINT, запоминая адрес предыдущего обработчика */ 
    p = signal(SIGQUIT, my_handler);
    /*Начиная с этого места, процесс будет 5 раз 
печатать сообщение о возникновении сигнала SIGINT */ 
    while(1);
    return 0;
}
