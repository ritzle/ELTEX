#include <stdio.h>
#include <stdarg.h> 

#define Max_ARGS 5


typedef double(*function) (int, ...);

double sum(int n, ...)
{
    double result = 0;
    va_list factor;         //указатель va_list
    va_start(factor, n);    // устанавливаем указатель
    for(int i=0;i<n; i++)
    {
        result += va_arg(factor, double);  // получаем значение текущего параметра типа double
    }
    va_end(factor); // завершаем обработку параметров
    return result;
}

double div(int n, ...)
{
    double result;
    va_list factor;
    va_start(factor, n);
    result = va_arg(factor, double);
    for(int i=1; i<n; i++)
    {
        result /= va_arg(factor, double);
    }
    va_end(factor);
    return result;
}

double mul(int n, ...)
{
    double result = 1;
    va_list factor;
    va_start(factor, n);
    for(int i=0; i<n; i++)
    {
        result *= va_arg(factor, double);
    }
    va_end(factor);
    return result;
}

double sub(int n, ...)
{
    double result;
    va_list factor;
    va_start(factor, n);
    result = va_arg(factor, double);
    for(int i=1; i<n; i++)
    {
        result -= va_arg(factor, double);
    }
    va_end(factor);
    return result;
}

typedef struct{
    char name[20];
    function pFunction;
} myFunction;


int main(){

    myFunction operations[] = {
        {"sum", sum},
        {"sub", sub},
        {"mul", mul},
        {"div", div}
    };

    int sizeMyFunction = sizeof(operations) / sizeof(operations[0]);

    for(int index = 0; index < sizeMyFunction; index++){
        printf("%d - %s \n", index+1, operations[index].name);
    }

    int action;//индекс структуры в массиве operations

    while(1){
        printf("enter action: ");
        scanf("%d", &action);

        if(action > sizeMyFunction || action < 0){
            printf("erorr, not this action\n");
            continue;
        }else{
            break;
        }
    }

    int numArgs;
    double args[5];

    while(1){
        printf("Введите количество аргументов: ");
        scanf("%d", &numArgs);

        if(numArgs > Max_ARGS || numArgs < 2){
            printf("erorr, count args <= 5 and args >= 2\n");
            continue;
        }else{
            break;
        }
    }

    for(int i = 0; i < numArgs; i++){
        double nArgs;
        printf("Ввидите %d аргумент: ", i+1);
        scanf("%lf", &nArgs);
        args[i] = nArgs;
    }

    double result;
    switch(numArgs){
        case(2):
            result = operations[action-1].pFunction(numArgs, args[0], args[1]);
            break;
        case(3):
            result = operations[action-1].pFunction(numArgs, args[0], args[1], args[2]);
            break;
        case(4):
            result = operations[action-1].pFunction(numArgs, args[0], args[1], args[2], args[3]);
            break;
        case(5):
            result = operations[action-1].pFunction(numArgs, args[0], args[1], args[2], args[3], args[4]);
            break;
    }

    printf("result = %f\n", result);

    return 0;
}
