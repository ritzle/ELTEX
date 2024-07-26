#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Использование: %s <количество чисел>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Пожалуйста, введите положительное целое число.\n");
        return 1;
    }

    int pipefd[2];

    // Создание трубы
    if (pipe(pipefd) == -1) {
        perror("Ошибка pipe");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("Ошибка fork");
        exit(1);
    }

    if (pid == 0) { // Дочерний процесс
        close(pipefd[0]); // Закрываем конец чтения

        // Генерация и отправка чисел
        for (int i = 0; i < n; i++) {
            int num = i + 1; // Генерация числа
            if (write(pipefd[1], &num, sizeof(num)) != sizeof(num)) {
                perror("Ошибка write");
                exit(1);
            }
        }

        close(pipefd[1]); // Закрываем конец записи
        exit(0);
    } else { // Родительский процесс
        close(pipefd[1]); // Закрываем конец записи

        // Чтение чисел
        for (int i = 0; i < n; i++) {
            int num;
            if (read(pipefd[0], &num, sizeof(num)) != sizeof(num)) {
                perror("Ошибка read");
                exit(1);
            }
            printf("%d ", num); // Вывод полученного числа
        }
        printf("\n");

        close(pipefd[0]); // Закрываем конец чтения
        wait(NULL); // Ожидание завершения дочернего процесса
    }

    return 0;
}
