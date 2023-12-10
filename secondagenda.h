#include "agenda.h"

// Fonction pour créer un contact
Contact* createContact(char* nom, char* prenom);

// Fonction pour créer un rendez-vous
RDV* createRDV(int jour, int mois, int annee, int heure, int minute, char* objet);

// Fonction pour afficher un rendez-vous
void displayRDV(RDV myRDV);

// Fonction pour créer une Entree
Entree* createEntree(Contact);

//Fonction pour trouver une entree dans la liste
Entree* findEntreeInList(ListAgenda list, Entree entree);

//Fonction de test pour ajouter une entree à la liste
void addEntreetoList(ListAgenda*, Entree*);

//Fonction pour ajouter un rendez-vous à sa liste chaînée
void addRDVtoLLCRDV(RDV *rdv, LLCRDV *llcrdv);

//Fonction pour créer une liste chaînée vide de rendez-vous
LLCRDV *createLLCRDV();

//Fonction pour afficher une liste chaînée de rendez-vous
void displayLLCRDV(LLCRDV llcrdv);

//Fonction test pour afficher les niveaux dans la liste
void displayListInLevel(ListAgenda);

//Fonction non-créé pour comparer les noms de familles entre 2 Entree
int compareEntries(Entree* entry1, Entree* entry2, int level);

//fonction pour ajouter une Entree à la liste
void addEntreetoAllList(ListAgenda* list, Entree* entree);

//Fonction pour récupérer les informations dans la console destiné au menu
char* scanString();

//Fonction pour avoir le niveau de l'Entree en fonction des premières lettres du nom de son Contact
int getLevel(Contact contact, ListAgenda myList);
