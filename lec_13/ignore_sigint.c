#include <signal.h>
int main(void){ 
    /* Выставляем реакцию процесса на сигнал
       SIGINT на игнорирование */ 
    (void)signal(SIGINT, SIG_IGN);
    /*Начиная с этого места, процесс будет 
      игнорировать возникновение сигнала 
      SIGINT */ 
    while(1);
    return 0;
}
