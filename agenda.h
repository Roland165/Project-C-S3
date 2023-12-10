#ifndef PROJET_C_S3_MAX_AGENDA_H
#define PROJET_C_S3_MAX_AGENDA_H

// Définition de la structure Contact représentant un contact
typedef struct Contact{
    char* nom;
    char* prenom;
}Contact;

// Définition de la structure RDV représentant un rendez-vous
typedef struct RDV{
    int jour;
    int mois;
    int annee;
    int heure;
    int minute;
    char* objet;
    struct RDV* next;
}RDV;

// Définition de la structure LLCRDV représentant une liste chaînée de RDV
typedef struct LLCRDV{
    RDV* head;
}LLCRDV;

// Définition de la structure Entrees représentant un tableau de Entree
typedef struct Entrees{
    struct Entree **next;
}Entrees;

// Définition de la structure Entree représentant une cellule de ListAgenda
typedef struct Entree{
    Contact myContact;
    LLCRDV myLLCRDV;
    struct Entrees EntreeNext;
    int nbLevels;
}Entree;

// Définition de la structure ListAgenda représentant une liste de Entree
typedef struct ListAgenda{
    Entrees entreesHeads;
    int nbLevels;
}ListAgenda;

// Fonction pour afficher un contact
void displayContact(Contact* myContact);

//Fonction pour créer une ListAgenda vide
ListAgenda* createEmptyListAgenda();

//Fonction pour afficher la liste
void displayList(ListAgenda list);

//Fonction menu
void menu();

//Fonction pour afficher le menu
void displayMenu();

//Fonction pour afficher la liste sous sa forme classique
void displayAgendaInList(ListAgenda* myList);

//Fonction pour afficher les information d'une personne dans la liste
void displayInformationFromSomeone(char* name, ListAgenda list);

//Fonction pour créer un rendez-vous directement dans une Entree
void createRDVForEntree(int jour, int mois, int annee, int heure, int minute, char* objet, Entree *entree);

//Fonction pour supprimer un rendez-vous dans une Entree par l'objet
void deleteRDVFromEntreeByObject(Entree *entree, char *objet);

//Fonction pour créer un contact dans la liste avec son Entree
Entree *createContactInList(ListAgenda *listAgenda, char* nom, char* prenom );

#endif


