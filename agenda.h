//
// Created by Max on 02/12/2023.
//

#ifndef PROJET_C_S3_MAX_AGENDA_H
#define PROJET_C_S3_MAX_AGENDA_H

typedef struct Contact{
    char* nom;
    char* prenom;
}Contact;

typedef struct RDV{
    int jour;
    int mois;
    int annee;
    int heure;
    int minute;
    char* objet;
    struct RDV* next;
}RDV;

typedef struct LLCRDV{
    RDV* head;
}LLCRDV;

typedef struct Entree{
    Contact myContact;
    LLCRDV myLLCRDV;
    struct Entree** tabPtrEntree;
    int nbLevels;
}Entree;

typedef struct List{
    Entree **tabPtrEntree;
    int nbLevels;
}List;

char* scanString();
Contact* createContact(char* nom, char* prenom);
void displayContact(Contact* myContact);
RDV* createRDV(int jour, int mois, int annee, int heure, int minute, char* objet);
void displayRDV(RDV myRDV);
int getLevel(Contact contact, List myList);
Entree* createEntree(Contact contact);
List* createEmptyList();
void menu();
void displayMenu();

#endif //PROJET_C_S3_MAX_AGENDA_H
