#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Ошибка: нужно больше аргументов\n");
        return 1; // Завершение программы с кодом ошибки
    }

    double result = 0; // Используем double для суммирования

    for (int i = 1; i < argc; i++) {
        result += atof(argv[i]);
    }

    printf("Результат = %.2f\n", result); // Выводим результат с двумя знаками после запятой

    return 0; // Успешное завершение программы
}
