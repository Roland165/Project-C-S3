#include "agenda.h"
#include <stdlib.h>
#include <stdio.h>
#include "secondagenda.h"

void displayContact(Contact* myContact){
    if(myContact != NULL){
        printf("\nnom : %s\n",myContact->nom);
        printf("prenom : %s\n",myContact->prenom);
    }
}

ListAgenda* createEmptyListAgenda(){
    ListAgenda* newList =(ListAgenda*) malloc(sizeof(ListAgenda));
    newList->nbLevels=4;
    Entree** newEntrees = (Entree**)malloc(sizeof(Entree*) * 4);
    newList->entreesHeads.next = newEntrees;
    for(int i = 0; i < 4; i++){
        newList->entreesHeads.next[i] = NULL;
    }
    return newList;
}

void displayInformationFromSomeone(char* name, ListAgenda list){
    int i = 1;
    printf("\n%s",name);
    Entree *temp=list.entreesHeads.next[0];
    if (temp->EntreeNext.next[0] == NULL && temp != NULL && temp->myContact.nom == name){
        printf("\nLes RDV(s) de la personne : \n");
        displayLLCRDV(temp->myLLCRDV);
        i = 0;
    }
    while (temp->EntreeNext.next[0] != NULL){
        if (temp->myContact.nom == name){
            printf("\nLes RDV(s) de la personne : \n");
            displayLLCRDV(temp->myLLCRDV);
            i = 0;
        }
        temp=temp->EntreeNext.next[0];
    }
    if (temp->myContact.nom == name){
        printf("\nLes RDV(s) de la personne : \n");
        displayLLCRDV(temp->myLLCRDV);
        i = 0;
    }
    if (i){
        printf("\nCette personne n'existe pas");
    }
}

void displayList(ListAgenda list){
    if (list.entreesHeads.next[0]==NULL){
        printf("Ce contact n'a pas de rendez-vous\n");
        return;
    }
    Entree *temp=list.entreesHeads.next[0];
    while (temp->EntreeNext.next[0] !=NULL){
        printf("Informations du contact : \n");
        displayContact(&temp->myContact);
        printf("\nLes RDV(s) de la personne : \n");
        displayLLCRDV(temp->myLLCRDV);
        temp=temp->EntreeNext.next[0];
    }
    printf("Informations du contact : \n");
    displayContact(&temp->myContact);
    printf("\nLes RDV(s) de la personne : \n");
    displayLLCRDV(temp->myLLCRDV);
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

void displayAgendaInList(ListAgenda* myList){
    if(myList==NULL){
        printf("DisplayCellsInList error: List is empty (NULL).");
        return;
    }
    for(int level = 1; level <= myList->nbLevels; level++){
        Entree *temp=myList->entreesHeads.next[0];
        printf("[list head_%d @-]--", level-1);
        while (temp != NULL) {
            if(temp->nbLevels >= level){
                printf(">[ %s|@-]--", temp->myContact.nom);
            }
            else{
                printf("----------");
            }
            temp = temp->EntreeNext.next[0];
        }
        printf(">NULL\n");
    }
    printf("\n");
}

void createRDVForEntree(int jour, int mois, int annee, int heure, int minute, char* objet, Entree *entree){
    RDV* myRDV = createRDV(jour,mois,annee,heure,minute,objet);
    if (entree->myLLCRDV.head == NULL){
        LLCRDV *llcrdv =createLLCRDV();
    }
    addRDVtoLLCRDV(myRDV, &entree->myLLCRDV);
}

void deleteRDVFromEntreeByObject(Entree *entree, char *objet){
    RDV *temp;
    RDV *prev = entree->myLLCRDV.head;
    if ( prev == NULL){
        printf("Ce contact n'a pas de rendez-vous.");
    }
    if (prev->objet == objet){
        entree->myLLCRDV.head=entree->myLLCRDV.head->next;
    }
    temp=prev->next;
    while(temp != NULL){
        if(temp->objet == objet){
            prev->next=temp->next;
            return;
        }
        prev=temp;
        temp=&temp->next[0];
    }
}

Entree *createContactInList(ListAgenda *listAgenda, char* nom, char* prenom ){
    Contact *myContact =createContact(nom ,prenom);
    Entree *myEntree = createEntree(*myContact);
    addEntreetoAllList(listAgenda, myEntree);
    return myEntree;
}

