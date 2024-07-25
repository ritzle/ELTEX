#include <stdio.h>
#include <stdlib.h>


int main(int argv, char * argc[]){

    if(argv < 2){
        perror("надо больше аргументов");
    }


    int result = 0;

    for (int i = 1; i < argv; i ++){
        result -= atof(argc[i]);
    }

    printf("результат = %d\n", result);

}