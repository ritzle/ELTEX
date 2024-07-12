#include <stdio.h>
#include <string.h>
#include "function.h"




int main() {
    struct Person ListPerson[MAX_LEN_ListPerson];
    int lenListPerson = 0;
    int action;

    while (1) {
        printf("Enter action: 1-addPerson, 2-changePerson, 3-delPerson, 4-printAllPersons, 5-printСertainPerson:\n ");
        scanf("%d", &action);

        switch (action) {
            case 1:
                fflush(stdin);
                getchar();
                addPerson(ListPerson, &lenListPerson);
                break;
            case 2:
                fflush(stdin);
                getchar();
                changePerson(ListPerson, &lenListPerson);
                break;
            case 3:
                fflush(stdin);
                getchar();
                delPerson(ListPerson, &lenListPerson);
                break;
            case 4:
                fflush(stdin);
                getchar();
                printAllPersons(ListPerson, &lenListPerson);
                break;
            case 5:
                fflush(stdin);
                getchar();
                printCertainPerson(ListPerson, &lenListPerson);
                break;
            default:
                printf("Invalid action. Please try again.\n");
        }
    }

    return 0;
}
