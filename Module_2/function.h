#ifndef Function_H  
#define Function_H

#include <stdio.h>
#include <string.h>
 
#define MAX_LEN_FullName 30
#define MAX_LEN_Phone 13
#define MAX_LEN_MAIL 35

#define MAX_LEN_SOCIAL_NETWORK_NAME 20
#define MAX_LEN_SOCIAL_NETWORK_LINK 50
#define MAX_LEN_LIST_SOCIALNETWORK 20

#define MAX_LEN_ListPerson 50
extern int currentID;

struct InfoJob {
    char placeOfWork[100];
    char jobTitle[50];
};

struct SocialNetwork {
    char name[MAX_LEN_SOCIAL_NETWORK_NAME];
    char link[MAX_LEN_SOCIAL_NETWORK_LINK];
};

struct Person {
    int ID;
    char name[MAX_LEN_FullName];
    char surname[MAX_LEN_FullName];
    char patronymic[MAX_LEN_FullName];
    char phoneNumbers[MAX_LEN_Phone][MAX_LEN_Phone];
    char mail[MAX_LEN_MAIL][MAX_LEN_MAIL];
    struct InfoJob InfoJob;
    struct SocialNetwork ListSocialNetworks[MAX_LEN_LIST_SOCIALNETWORK];
};

void addPerson(struct Person* ListPerson, int* lenListPerson);
void changePerson(struct Person* ListPerson, int* lenListPerson);
void delPerson(struct Person* ListPerson, int* lenListPerson);
void printAllPersons(struct Person* persons, int* numPersons);
void printCertainPerson(struct Person* ListPerson, int* lenListPerson);
 
#endif         