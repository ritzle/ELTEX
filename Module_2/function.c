#include "function.h"

int currentID = 1;

void addPerson(struct Person* ListPerson, int* lenListPerson) {
    struct Person newPerson;
    memset(&newPerson, 0, sizeof(struct Person)); // для избежания


    newPerson.ID = currentID++;

    // Добавление ФИО
    printf("Введите имя: ");
    fgets(newPerson.name, MAX_LEN_FullName, stdin);
    if (newPerson.name[strlen(newPerson.name) - 1] == '\n') {
        newPerson.name[strlen(newPerson.name) - 1] = '\0';
    }

    printf("Введите фамилию: ");
    fgets(newPerson.surname, MAX_LEN_FullName, stdin);
    if (newPerson.surname[strlen(newPerson.surname) - 1] == '\n') {
        newPerson.surname[strlen(newPerson.surname) - 1] = '\0';
    }

    printf("Введите отчество: ");
    fgets(newPerson.patronymic, MAX_LEN_FullName, stdin);
    if (newPerson.patronymic[strlen(newPerson.patronymic) - 1] == '\n') {
        newPerson.patronymic[strlen(newPerson.patronymic) - 1] = '\0';
    }

    // Добавление телефонных номеров
    printf("Добавить номер телефона? (Y/N): ");
    char actionPhone;
    int countPhoneNumbers = 0;
    while (1) {
        if (scanf("%c", &actionPhone) != 1) {
            printf("Ошибка ввода, введите (Y/N): ");
            getchar();
            continue;
        }
        // Очистка буфера ввода
        while (getchar() != '\n');

        if (actionPhone == 'Y') {
            printf("Введите номер телефона: ");
            if (fgets(newPerson.phoneNumbers[countPhoneNumbers], MAX_LEN_Phone, stdin) == NULL) {
                printf("Ошибка ввода номера телефона\n");
                continue;
            }
            if (newPerson.phoneNumbers[countPhoneNumbers][strlen(newPerson.phoneNumbers[countPhoneNumbers]) - 1] == '\n') {
                newPerson.phoneNumbers[countPhoneNumbers][strlen(newPerson.phoneNumbers[countPhoneNumbers]) - 1] = '\0';
            }
            countPhoneNumbers++;
            if (countPhoneNumbers == MAX_LEN_Phone) {
                printf("Достигнут максимальный лимит телефонных номеров.\n");
                break;
            }
            printf("Добавить еще номер? (Y/N): ");
        } else if (actionPhone == 'N') {
            break;
        } else {
            printf("Ошибка ввода, введите (Y/N): ");
        }
    }

    // Добавление email-адресов
    printf("Добавить email? (Y/N): ");
    char emailAction;
    int countEmails = 0;
    while (1) {
        if (scanf("%c", &emailAction) != 1) {
            printf("Ошибка ввода, введите (Y/N): ");
            // Очистка буфера ввода
            while (getchar() != '\n');
            continue;
        }
        // Очистка буфера ввода
        while (getchar() != '\n');

        if (emailAction == 'Y') {
            printf("Введите email: ");
            if (fgets(newPerson.mail[countEmails], MAX_LEN_MAIL, stdin) == NULL) {
                printf("Ошибка ввода email\n");
                continue;
            }
            if (newPerson.mail[countEmails][strlen(newPerson.mail[countEmails]) - 1] == '\n') {
                newPerson.mail[countEmails][strlen(newPerson.mail[countEmails]) - 1] = '\0';
            }
            countEmails++;
            if (countEmails == MAX_LEN_MAIL) {
                printf("Достигнут максимальный лимит email адресов.\n");
                break;
            }
            printf("Добавить еще email? (Y/N): ");
        } else if (emailAction == 'N') {
            break;
        } else {
            printf("Ошибка ввода, введите (Y/N): ");
        }
    }

    // Добавление места работы и должности
    printf("Введите место работы: ");
    if (fgets(newPerson.InfoJob.placeOfWork, sizeof(newPerson.InfoJob.placeOfWork), stdin) == NULL) {
        printf("Ошибка ввода места работы\n");
    } else {
        if (newPerson.InfoJob.placeOfWork[strlen(newPerson.InfoJob.placeOfWork) - 1] == '\n') {
            newPerson.InfoJob.placeOfWork[strlen(newPerson.InfoJob.placeOfWork) - 1] = '\0';
        }
    }

    printf("Введите должность: ");
    if (fgets(newPerson.InfoJob.jobTitle, sizeof(newPerson.InfoJob.jobTitle), stdin) == NULL) {
        printf("Ошибка ввода должности\n");
    } else {
        if (newPerson.InfoJob.jobTitle[strlen(newPerson.InfoJob.jobTitle) - 1] == '\n') {
            newPerson.InfoJob.jobTitle[strlen(newPerson.InfoJob.jobTitle) - 1] = '\0';
        }
    }

    // Добавление социальных сетей
    printf("Добавить социальную сеть? (Y/N): ");
    char actionSocial;
    int countSocialNetworks = 0;
    while (1) {
        if (scanf("%c", &actionSocial) != 1) {
            printf("Ошибка ввода, введите (Y/N): ");
            getchar();
            continue;
        }
        // Очистка буфера ввода
        while (getchar() != '\n');

        if (actionSocial == 'Y') {
            if (countSocialNetworks == MAX_LEN_LIST_SOCIALNETWORK) {
                printf("Достигнут максимальный лимит социальных сетей.\n");
                break;
            }

            printf("Введите название социальной сети: ");
            if (fgets(newPerson.ListSocialNetworks[countSocialNetworks].name, MAX_LEN_SOCIAL_NETWORK_NAME, stdin) == NULL) {
                printf("Ошибка ввода названия социальной сети\n");
                continue;
            }
            // Удаление символа новой строки
            if (newPerson.ListSocialNetworks[countSocialNetworks].name[strlen(newPerson.ListSocialNetworks[countSocialNetworks].name) - 1] == '\n') {
                newPerson.ListSocialNetworks[countSocialNetworks].name[strlen(newPerson.ListSocialNetworks[countSocialNetworks].name) - 1] = '\0';
            }

            printf("Введите ссылку на социальную сеть: ");
            if (fgets(newPerson.ListSocialNetworks[countSocialNetworks].link, MAX_LEN_SOCIAL_NETWORK_LINK, stdin) == NULL) {
                printf("Ошибка ввода ссылки на социальную сеть\n");
                continue;
            }
            // Удаление символа новой строки
            if (newPerson.ListSocialNetworks[countSocialNetworks].link[strlen(newPerson.ListSocialNetworks[countSocialNetworks].link) - 1] == '\n') {
                newPerson.ListSocialNetworks[countSocialNetworks].link[strlen(newPerson.ListSocialNetworks[countSocialNetworks].link) - 1] = '\0';
            }

            countSocialNetworks++;
            printf("Добавить еще социальную сеть? (Y/N): ");
        } else if (actionSocial == 'N') {
            break;
        } else {
            printf("Ошибка ввода, введите (Y/N): ");
        }
    }

    ListPerson[*lenListPerson] = newPerson;
    (*lenListPerson)++;
}

void changePerson(struct Person* ListPerson, int* lenListPerson) {
    int id;

    printf("Введите ID человека, которого нужно изменить: ");
    if (scanf("%d", &id) != 1) {
        printf("Ошибка ввода ID\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < *lenListPerson; i++) {
        if (ListPerson[i].ID == id) {
            found = 1;

            printf("\nТекущие данные:\n");
            printf("ID: %d\n", ListPerson[i].ID);
            printf("Имя: %s\n", ListPerson[i].name);
            printf("Фамилия: %s\n", ListPerson[i].surname);
            printf("Отчество: %s\n", ListPerson[i].patronymic);

            printf("Телефоны:\n");
            for (int j = 0; j < MAX_LEN_Phone; j++) {
                if (ListPerson[i].phoneNumbers[j][0] != '\0') {
                    printf("- %s\n", ListPerson[i].phoneNumbers[j]);
                }
            }

            printf("Электронные почты:\n");
            for (int j = 0; j < MAX_LEN_MAIL; j++) {
                if (ListPerson[i].mail[j][0] != '\0') {
                    printf("- %s\n", ListPerson[i].mail[j]);
                }
            }

            printf("Место работы: %s\n", ListPerson[i].InfoJob.placeOfWork);
            printf("Должность: %s\n", ListPerson[i].InfoJob.jobTitle);

            printf("Социальные сети:\n");
            for (int j = 0; j < MAX_LEN_LIST_SOCIALNETWORK; j++) {
                if (ListPerson[i].ListSocialNetworks[j].name[0] != '\0') {
                    printf("- %s (%s)\n", ListPerson[i].ListSocialNetworks[j].name, ListPerson[i].ListSocialNetworks[j].link);
                }
            }

            printf("\nИзменить данные?\n");

            // Изменение ФИО
            char actionName, actionSurname, actionPatronymic;
            printf("Изменить имя? (Y/N): ");
            scanf(" %c", &actionName);

            while (getchar() != '\n');

            if (actionName == 'Y') {
                printf("Введите новое имя: ");
                if (fgets(ListPerson[i].name, MAX_LEN_FullName, stdin) == NULL) {
                    printf("Ошибка ввода имени\n");
                    return;
                }
                if (ListPerson[i].name[strlen(ListPerson[i].name) - 1] == '\n') {
                    ListPerson[i].name[strlen(ListPerson[i].name) - 1] = '\0';
                }
            }

            printf("Изменить фамилию? (Y/N): ");
            scanf(" %c", &actionSurname);

            while (getchar() != '\n');
            if (actionSurname == 'Y') {
                printf("Введите новую фамилию: ");
                if (fgets(ListPerson[i].surname, MAX_LEN_FullName, stdin) == NULL) {
                    printf("Ошибка ввода фамилии\n");
                    return;
                }
                if (ListPerson[i].surname[strlen(ListPerson[i].surname) - 1] == '\n') {
                    ListPerson[i].surname[strlen(ListPerson[i].surname) - 1] = '\0';
                }
            }

            printf("Изменить отчество? (Y/N): ");
            scanf(" %c", &actionPatronymic);

            while (getchar() != '\n');
            if (actionPatronymic == 'Y') {
                printf("Введите новое отчество: ");
                if (fgets(ListPerson[i].patronymic, MAX_LEN_FullName, stdin) == NULL) {
                    printf("Ошибка ввода отчества\n");
                    return;
                }
                if (ListPerson[i].patronymic[strlen(ListPerson[i].patronymic) - 1] == '\n') {
                    ListPerson[i].patronymic[strlen(ListPerson[i].patronymic) - 1] = '\0';
                }
            }

            // Изменение телефонов
            char actionPhone;
            printf("Изменить телефоны? (Y/N): ");
            scanf(" %c", &actionPhone);

            while (getchar() != '\n');
            if (actionPhone == 'Y') {
                printf("Введите новые телефоны (по одному в строке, введите 'q' для завершения):\n");
                int countPhoneNumbers = 0;
                while (countPhoneNumbers < MAX_LEN_Phone) {
                    char buffer[MAX_LEN_Phone];
                    if (fgets(buffer, MAX_LEN_Phone, stdin) == NULL) {
                        printf("Ошибка ввода телефона\n");
                        return;
                    }

                    // Проверяем  'q' для завершения
                    if (buffer[0] == 'q' && buffer[1] == '\n') {
                        break;
                    }

                    if (buffer[strlen(buffer) - 1] == '\n') {
                        buffer[strlen(buffer) - 1] = '\0';
                    }

                    strcpy(ListPerson[i].phoneNumbers[countPhoneNumbers], buffer);
                    countPhoneNumbers++;
                }
            }


            // Изменение email-ов
            char actionMail;
            printf("Изменить email-ы? (Y/N): ");
            scanf(" %c", &actionMail);
            while (getchar() != '\n');

            if (actionMail == 'Y') {
            printf("Введите новые email-ы (по одному в строке, введите 'q' для завершения):\n");
            int countMails = 0;
            while (countMails < MAX_LEN_MAIL) {
                char buffer[MAX_LEN_MAIL];
                if (fgets(buffer, MAX_LEN_MAIL, stdin) == NULL) {
                    printf("Ошибка ввода email\n");
                    return;
                }

                
                if (buffer[0] == 'q' && buffer[1] == '\n') {
                    break;
                }

                
                if (buffer[strlen(buffer) - 1] == '\n') {
                    buffer[strlen(buffer) - 1] = '\0';
                }

                
                strcpy(ListPerson[i].mail[countMails], buffer);
                countMails++;
            }
        }

            // Изменение места работы и должности
            char actionJob;
            printf("Изменить место работы и должность? (Y/N): ");
            scanf(" %c", &actionJob);

            while (getchar() != '\n');
            if (actionJob == 'Y') {
                printf("Введите новое место работы: ");
                if (fgets(ListPerson[i].InfoJob.placeOfWork, sizeof(ListPerson[i].InfoJob.placeOfWork), stdin) == NULL) {
                    printf("Ошибка ввода места работы\n");
                    return;
                }
                if (ListPerson[i].InfoJob.placeOfWork[strlen(ListPerson[i].InfoJob.placeOfWork) - 1] == '\n') {
                    ListPerson[i].InfoJob.placeOfWork[strlen(ListPerson[i].InfoJob.placeOfWork) - 1] = '\0';
                }

                printf("Введите новую должность: ");
                if (fgets(ListPerson[i].InfoJob.jobTitle, sizeof(ListPerson[i].InfoJob.jobTitle), stdin) == NULL) {
                    printf("Ошибка ввода должности\n");
                    return;
                }
                if (ListPerson[i].InfoJob.jobTitle[strlen(ListPerson[i].InfoJob.jobTitle) - 1] == '\n') {
                    ListPerson[i].InfoJob.jobTitle[strlen(ListPerson[i].InfoJob.jobTitle) - 1] = '\0';
                }
            }

            // Изменение социальных сетей
            char actionSocial;
            printf("Изменить социальные сети? (Y/N): ");
            scanf(" %c", &actionSocial);
            while (getchar() != '\n');
            if (actionSocial == 'Y') {
    printf("Введите новые социальные сети (по одной в строке, введите 'q' для завершения):\n");
    int countSocialNetworks = 0;
    while (countSocialNetworks < MAX_LEN_LIST_SOCIALNETWORK) {
        printf("Название сети: ");
        char nameBuf[MAX_LEN_SOCIAL_NETWORK_NAME];
        if (fgets(nameBuf, MAX_LEN_SOCIAL_NETWORK_NAME, stdin) == NULL) {
            printf("Ошибка ввода названия сети\n");
            return;
        }

        
        if (nameBuf[0] == 'q' && nameBuf[1] == '\n') {
            break;
        }

        // Удаление символа новой строки
        if (nameBuf[strlen(nameBuf) - 1] == '\n') {
            nameBuf[strlen(nameBuf) - 1] = '\0';
        }

        printf("Ссылка на сеть: ");
        char linkBuf[MAX_LEN_SOCIAL_NETWORK_LINK];
        if (fgets(linkBuf, MAX_LEN_SOCIAL_NETWORK_LINK, stdin) == NULL) {
            printf("Ошибка ввода ссылки на сеть\n");
            return;
        }

        
        if (linkBuf[strlen(linkBuf) - 1] == '\n') {
            linkBuf[strlen(linkBuf) - 1] = '\0';
        }

        
        strcpy(ListPerson[i].ListSocialNetworks[countSocialNetworks].name, nameBuf);
        strcpy(ListPerson[i].ListSocialNetworks[countSocialNetworks].link, linkBuf);
        countSocialNetworks++;
    }
}


            printf("Данные человека с ID %d успешно изменены.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Человек с ID %d не найден.\n", id);
    }
}


void delPerson(struct Person* ListPerson, int* lenListPerson) {
    int id;

    printf("Введите ID человека, которого нужно удалить: ");
    if (scanf("%d", &id) != 1) {
        printf("Ошибка ввода ID\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < *lenListPerson; i++) {
        if (ListPerson[i].ID == id) {
            found = 1;
            // Сдвигаем все элементы массива после удаляемого
            for (int j = i; j < *lenListPerson - 1; j++) {
                ListPerson[j] = ListPerson[j + 1];
            }
            (*lenListPerson)--;
            printf("Человек с ID %d успешно удален.\n", id);
            break;
        }
    }

    if (!found) {
        printf("Человек с ID %d не найден.\n", id);
    }
}


void printAllPersons(struct Person* persons, int* numPersons) {
    printf("Список всех пользователей:\n");
    for (int i = 0; i < *numPersons; i++) {
        printf("ID: %d\n", persons[i].ID);
        printf("Имя: %s\n", persons[i].name);
        printf("Фамилия: %s\n", persons[i].surname);
        printf("Отчество: %s\n", persons[i].patronymic);
        printf("Телефоны:\n");
        for (int j = 0; j < MAX_LEN_Phone && persons[i].phoneNumbers[j][0] != '\0'; j++) {
            printf("- %s\n", persons[i].phoneNumbers[j]);
        }
        printf("Почта:\n");
        for (int j = 0; j < MAX_LEN_MAIL && persons[i].mail[j][0] != '\0'; j++) {
            printf("- %s\n", persons[i].mail[j]);
        }
        printf("Место работы: %s\n", persons[i].InfoJob.placeOfWork);
        printf("Должность: %s\n", persons[i].InfoJob.jobTitle);
        printf("Социальные сети:\n");
        for (int j = 0; j < MAX_LEN_LIST_SOCIALNETWORK && persons[i].ListSocialNetworks[j].name[0] != '\0'; j++) {
            printf("- %s (%s)\n", persons[i].ListSocialNetworks[j].name, persons[i].ListSocialNetworks[j].link);
        }
        printf("\n");
    }
}

void printCertainPerson(struct Person* ListPerson, int* lenListPerson) {
    char name[MAX_LEN_FullName];
    char surname[MAX_LEN_FullName];

    printf("Введите имя: ");
    if (fgets(name, MAX_LEN_FullName, stdin) == NULL) {
        printf("Ошибка ввода имени\n");
        return;
    }
    // Удаление символа новой строки
    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }

    printf("Введите фамилию: ");
    if (fgets(surname, MAX_LEN_FullName, stdin) == NULL) {
        printf("Ошибка ввода фамилии\n");
        return;
    }
    // Удаление символа новой строки
    if (surname[strlen(surname) - 1] == '\n') {
        surname[strlen(surname) - 1] = '\0';
    }

    printf("\n");

    int found = 0;
    for (int i = 0; i < *lenListPerson; i++) {
        if (strcmp(ListPerson[i].name, name) == 0 && strcmp(ListPerson[i].surname, surname) == 0) {
            found = 1;
            printf("ID: %d\n", ListPerson[i].ID);
            printf("Имя: %s\n", ListPerson[i].name);
            printf("Фамилия: %s\n", ListPerson[i].surname);
            printf("Отчество: %s\n", ListPerson[i].patronymic);

            printf("Телефоны:\n");
            for (int j = 0; j < MAX_LEN_Phone; j++) {
                if (ListPerson[i].phoneNumbers[j][1] != '\0') {
                    printf("- %s\n", ListPerson[i].phoneNumbers[j]);
                }
            }

            printf("Электронные почты:\n");
            for (int j = 0; j < MAX_LEN_MAIL; j++) {
                if (ListPerson[i].mail[j][0] != '\0') {
                    printf("- %s\n", ListPerson[i].mail[j]);
                }
            }

            printf("Место работы: %s\n", ListPerson[i].InfoJob.placeOfWork);
            printf("Должность: %s\n", ListPerson[i].InfoJob.jobTitle);

            printf("Социальные сети:\n");
            for (int j = 0; j < MAX_LEN_LIST_SOCIALNETWORK; j++) {
                if (ListPerson[i].ListSocialNetworks[j].name[1] != '\0') {
                    printf("- %s (%s)\n", ListPerson[i].ListSocialNetworks[j].name, ListPerson[i].ListSocialNetworks[j].link);
                }
            }
            break;
        }
    }

    if (!found) {
        printf("Человек с именем %s и фамилией %s не найден.\n", name, surname);
    }
}