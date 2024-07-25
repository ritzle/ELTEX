#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

typedef struct {
    char name[20];
} myFunction;

int main() {
    myFunction operations[] = {
        {"sum"},
        {"sub"},
        {"mul"},
        {"div"},
        {"exit"}
    };

    char *argc[100];

    while (1) {
        int sizeMyFunction = sizeof(operations) / sizeof(operations[0]);

        for (int index = 0; index < sizeMyFunction; index++) {
            printf("-%s \n", operations[index].name);
        }

        printf("Введите одну из команд с аргументами (sum 3 2) или 'exit' для выхода: \n");

        char input[100];

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Удаление символа новой строки

        //printf("%s\n", input);

    int i = 0;
    char *token = strtok(input, " ");

    while (token != NULL && i < 100) {
        argc[i] = token; 
        i++;
        token = strtok(NULL, " ");
    }
    argc[i] = NULL;

        

     

        if (argc[0] == NULL) {
            continue; // Если не введена команда, продолжаем цикл
        }

        if (strcmp(argc[0], "exit") == 0) {
            break; // Выход из цикла
        }

        pid_t proc = fork();

        if (proc == -1) {
            perror("fork error");
            exit(1);
        }

        if (proc == 0) { // Дочерний процесс
            execv(argc[0], argc); // Выполнение команды
            perror("execvp error"); // Ошибка при выполнении
            exit(1); // Завершение дочернего процесса с ошибкой
        }

        wait(NULL); // Ожидание завершения дочернего процесса
    }

    return 0;
}
