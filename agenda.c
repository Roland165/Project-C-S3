//
// Created by Max on 02/12/2023.
//
#include "agenda.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


char* scanString(){
    char* tempStr = (char*)malloc(200*sizeof(char));
    printf("Scanning: ");
    gets(tempStr);
    return tempStr;
}


Contact* createContact(char* nom, char* prenom){
    Contact* newContact = (Contact*) malloc(sizeof(Contact));
    newContact->nom = nom;
    newContact->prenom = prenom;
    return newContact;
}

void displayContact(Contact* myContact){
    if(myContact != NULL){
        printf("Displaying contact :\n");
        printf("   nom : %s\n",myContact->nom);
        printf("   prenom : %s",myContact->prenom);
    }
}


RDV* createRDV(int jour, int mois, int annee, int heure, int minute, char* objet){
    RDV* newRDV = (RDV*) malloc(sizeof(RDV));
    newRDV->jour = jour;
    newRDV->mois = mois;
    newRDV->annee = annee;
    newRDV->heure = heure;
    newRDV->minute = minute;
    newRDV->objet = objet;
    return newRDV;
}

void displayRDV(RDV myRDV){
    printf("Displaying RDV:\n");
    printf("   Jour/Mois/Annee: %d / %d / %d\n",myRDV.jour, myRDV.mois, myRDV.annee);
    printf("   Heure h Minutes: %d h %d\n",myRDV.heure, myRDV.minute);
    printf("   Objet : %s\n",myRDV.objet);
}

//ROLAND
Entree* createEntree(Contact contact){
    Entree* newEntree = (Entree *) malloc(sizeof (Entree));
    newEntree->myContact=contact;
    newEntree->myLLCRDV.head=NULL;
    newEntree->nbLevels= getLevel(contact);
    for(int i = 0; i < newEntree->nbLevels; i++){
        newEntree->tabPtrEntree[i] = NULL;
    }
    return newEntree;
}

//ROLAND
List* createEmptyList(){
    List* newList =(List*) malloc(sizeof(List));
    newList->nbLevels=4;
    for(int i = 0; i < 4; i++){
        newList->tabPtrEntree[i] = NULL;
    }
    return newList;
}

//Mathieu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Rechercher un contact\n");
    printf("2. Afficher les rendez-vous d'un contact\n");
    printf("3. Créer un contact\n");
    printf("4. Créer un rendez-vous pour un contact\n");
    printf("5. Supprimer un rendez-vous\n");
    printf("6. Sauvegarder le fichier de tous les rendez-vous\n");
    printf("7. Charger un fichier de rendez-vous\n");
    printf("8. Fournir les temps de calcul pour une insertion de nouveau contact\n");
    printf("0. Quitter\n");
}

//Mathieu
void menu(){
    int choice;

    do {
        displayMenu();
        printf("Choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char partialName[100];
                printf("Entrez les premières lettres du nom : ");
                scanf("%s", partialName);
                //char* fullName = autoCompleteSearch(contacts, partialName);
                //if (fullName != NULL) {
                //printf("Nom complet trouvé : %s\n", fullName);
                //free(fullName);
                //} else {
                printf("Aucun nom trouvé.\n");
                //}
                break;
            }
            case 2: {
                char nom[100];
                printf("Entrez le nom du contact : ");
                scanf("%s", nom);
                //Contact* foundContact = searchContact(contacts, nom);
                //if (foundContact != NULL) {
                //    displayAppointments(foundContact);
                //} else {
                printf("Contact non trouvé.\n");
                //}
                break;
            }
            case 3: {
                char nom[100];
                printf("Entrez le nom du nouveau contact : ");
                scanf("%s", nom);
                char prenom[100];
                printf("Entrez le prenom du nouveau contact : ");
                scanf("%s", prenom);
                Contact* newContact = createContact(nom, prenom);
                //insertContact(&contacts, newContact);
                printf("Contact créé et ajouté à la liste.\n");
                break;
            }
            case 4: {
                char nom[100];
                printf("Entrez le nom du contact : ");
                scanf("%s", nom);
                //Contact* foundContact = searchContact(contacts, nom);
                //if (foundContact != NULL) {
                //RDV* newRDV = createRDV(int jour, int mois, int annee, int heure, int minute, char* objet);
                //insertRDV(foundContact, newRDV);
                printf("Rendez-vous créé et ajouté au contact.\n");
                //} else {
                printf("Contact non trouvé. Créez d'abord le contact.\n");
                //}
                break;
            }
            case 5: {
                char nom[100];
                printf("Entrez le nom du contact : ");
                scanf("%s", nom);
                //Contact* foundContact = searchContact(contacts, nom);
                //if (foundContact != NULL) {
                //displayAppointments(foundContact);
                int rdvIndex;
                printf("Entrez l'indice du rendez-vous à supprimer : ");
                scanf("%d", &rdvIndex);
                //deleteRDV(foundContact, rdvIndex);
                printf("Rendez-vous supprimé.\n");
                //} else {
                printf("Contact non trouvé.\n");
                //}
                break;
            }
            case 6:
                //saveAppointmentsToFile(contacts);
                printf("Rendez-vous sauvegardés dans le fichier.\n");
                break;
            case 7:
                //loadAppointmentsFromFile(&contacts);
                printf("Rendez-vous chargés depuis le fichier.\n");
                break;
            case 8:
                //calculateInsertionTime(&contacts);
                printf("Temps de calcul pour une insertion de nouveau contact fourni.\n");
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 0 et 8.\n");
        }
    } while (choice != 0);

    return;
}

int getLevel(Contact contact, List myList){
    //marche que pour le nom pour l'instant
    if(myList.nbLevels == 0 || myList.tabPtrEntree == NULL){
        return 4;
    }
    else{
        int levelOfContact = 4;
        for(int idxLetter = 0; idxLetter<=4; idxLetter++){
            Entree* tempEntree = myList.tabPtrEntree[0];
            //On copie le nom pour pas ecraser celui dans le contact
            char* nomTemp = strdup(tempEntree->myContact.nom);
            //On met le nomTemp en minuscule
            for(int idxLetterTemp = 0; idxLetterTemp <= strlen(nomTemp); idxLetterTemp++){
                nomTemp[idxLetterTemp] = tolower(nomTemp[idxLetterTemp]);
            }
            int resultComparaison = strcmp(nomTemp,contact.nom);
            if(resultComparaison == 0){
                levelOfContact = levelOfContact-1;
            }
            if(resultComparaison != 0){
                //A FINIR
            }
        }
    }
}