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

typedef struct Entrees{
    struct Entree **next;
}Entrees;

typedef struct Entree{
    Contact myContact;
    LLCRDV myLLCRDV;
    struct Entrees EntreeNext;
    int nbLevels;
}Entree;

typedef struct ListAgenda{
    Entrees entreesHeads;
    int nbLevels;
}ListAgenda;



char* scanString();
Contact* createContact(char* nom, char* prenom);
void displayContact(Contact* myContact);
RDV* createRDV(int jour, int mois, int annee, int heure, int minute, char* objet);
void displayRDV(RDV myRDV);
Entree* createEntree(Contact);
int getLevel(Contact contact, ListAgenda myList);
ListAgenda* createEmptyListAgenda();
Entree* findEntreeInList(ListAgenda list, Entree entree);
void addEntreetoList(ListAgenda*, Entree*);
void displayList(ListAgenda list);
void addRDVtoLLCRDV(RDV *rdv, LLCRDV *llcrdv);
LLCRDV *createLLCRDV();
void displayLLCRDV(LLCRDV llcrdv);
void menu();
void displayMenu();

