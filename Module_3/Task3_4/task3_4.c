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

    // Создание канала
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
        close(pipefd[0]); 

        for (int i = 0; i < n; i++) {
            int num = rand() % 255; 
            if (write(pipefd[1], &num, sizeof(num)) != sizeof(num)) {
                perror("Ошибка write");
                exit(1);
            }
        }

        close(pipefd[1]);
        exit(0);
    }

    close(pipefd[1]);

    char *filename = "text.txt";
    FILE *fp = fopen(filename, "w");
    if (fp) {
        // Чтение чисел
        for (int i = 0; i < n; i++) {
            int num;

            if (read(pipefd[0], &num, sizeof(num)) != sizeof(num)) {
                perror("Ошибка read");
                exit(1);
            }

            // Запись числа в файл
            fprintf(fp, "%d\n", num);

            printf("%d ", num); 
        }

        printf("\n");
        fclose(fp);
    } else {
        perror("Ошибка открытия файла");
    }

    close(pipefd[0]); 
    wait(NULL); 

    return 0;
}
