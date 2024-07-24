#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main (int argc, char * argv[]) {

    if(argc < 2){
        printf("ввидите стороны квадратов");
        exit(0);
    }

    int mid = argc/ 2;
    
    pid_t proc;

    proc = fork();

    if(proc == -1){
        perror("fork error");
    }

    if(proc == 0){
        //дочерний 

        //i =1 так как argv[0] будет иметь имя исполняемого фаила
        for(int i = 1; i < mid; i++){
            printf("площадь квадрата со стороной %.2f = %.2f\n", atof(argv[i]), atof(argv[i]) * atof(argv[i]));
        }
        exit(0);

    }
    //уже родитель
    //wait ждет пока дочерный процесс не завершится, проверяем что wait без ошибки 

    pid_t chaid_pid = wait(NULL);
    if (chaid_pid == -1){
        perror("error wait");
        exit(0);
    }


    for(int i = mid; i < argc; i ++){
        printf("площадь квадрата со стороной %.2f = %.2f\n", atof(argv[i]), atof(argv[i]) * atof(argv[i]));
    }


    return 0;
 }