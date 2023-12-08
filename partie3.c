#include "partie3.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Contact* createContact(char* nom, char* prenom){
    Contact* newContact = (Contact*) malloc(sizeof(Contact));
    newContact->nom = nom;
    newContact->prenom = prenom;
    return newContact;
}

void displayContact(Contact* myContact){
    if(myContact != NULL){
        printf("nom : %s\n",myContact->nom);
        printf("prenom : %s\n",myContact->prenom);
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
    newRDV->next=NULL;
    return newRDV;
}

void displayRDV(RDV myRDV){
    printf("\nLa date du rendez-vous est : %d / %d / %d.\n",myRDV.jour, myRDV.mois, myRDV.annee);
    printf("Le rendez-vous est a %dh %d.\n",myRDV.heure, myRDV.minute);
    printf("l'objet du rendez-vous est : %s.\n",myRDV.objet);
}

Entree* createEntree(Contact contact){
    Entree* newEntree = (Entree *) malloc(sizeof (Entree));
    newEntree->myContact=contact;
    newEntree->myLLCRDV.head=NULL;
    newEntree->nbLevels= 1;
    Entree ** newEntrees = (Entree**)malloc(sizeof(Entree*)*1);
    newEntree->EntreeNext.next = newEntrees;
    for(int i = 0; i < 1; i++){
        newEntree->EntreeNext.next[i] = NULL;
    }
    return newEntree;
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

LLCRDV *createLLCRDV(){
    LLCRDV *llcrdv=(LLCRDV*) malloc(sizeof (LLCRDV));
    llcrdv->head=NULL;
    return llcrdv;
}

void addRDVtoLLCRDV(RDV *rdv, LLCRDV *llcrdv){
    if (llcrdv->head == NULL){
        llcrdv->head=rdv;
    }
    else{
        RDV *temp=llcrdv->head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=rdv;
    }
}

void displayLLCRDV(LLCRDV llcrdv){
    RDV *temp=llcrdv.head;
    if (temp==NULL){
        printf("Ce contact n'a pas de rendez-vous.\n\n");
        return;
    }
    int i=1;
    while (temp->next!=NULL){
        printf("RDV number %d :",i);
        displayRDV(*temp);
        temp=temp->next;
        i++;
    }
    printf("RDV number %d :",i);
    displayRDV(*temp);
    printf("\n");
}

void displayInformationFromSomeone(char* name, ListAgenda list){
    int i = 1;
    printf("%s",name);
    Entree *temp=list.entreesHeads.next[0];
    while (temp->EntreeNext.next[0] != NULL){
        if (temp->myContact.nom == name){
            printf("\nLes RDV(s) de la personne : \n");
            displayLLCRDV(temp->myLLCRDV);
            i = 0;
        }
            temp=temp->EntreeNext.next[0];
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
/*
int getLevel(Contact contact, ListAgenda myList){
    //marche que pour le nom pour l'instant
    if(myList.nbLevels == 0 || myList.entreesHeads.next[0] == NULL){
        return 4;
    }
    else{
        int levelOfContact = 4;
        for(int idxLetter = 0; idxLetter<=4; idxLetter++){
            Entree* tempEntree = myList.entreesHeads.next[0];
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
}*/

void displayListInLevel(ListAgenda list){
    Entree *temp=list.entreesHeads.next[0];
    while (temp->EntreeNext.next[0] !=NULL){
        printf("Contact : \n");
        displayContact(&temp->myContact);
        temp=temp->EntreeNext.next[0];
    }
    printf("Contact : \n");
    displayContact(&temp->myContact);
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


void addEntreetoAllList(ListAgenda* list, Entree* entree) {

    if (list->entreesHeads.next[0] == NULL){
        list->entreesHeads.next[0]=entree;
        return;
    }

    Entree* current = list->entreesHeads.next[0];
    if (strcmp(current->myContact.nom, entree->myContact.nom) > 0){
        entree->EntreeNext.next[0] = current;
        list->entreesHeads.next[0]=entree;
        return;
    }
    while (current->EntreeNext.next[0] != NULL && strcmp(current->EntreeNext.next[0]->myContact.nom, entree->myContact.nom) < 0) {
        current = current->EntreeNext.next[0];
    }

    entree->EntreeNext.next[0] = current->EntreeNext.next[0];
    current->EntreeNext.next[0] = entree;
}

char* scanString(){
    char* tempStr = (char*)malloc(200*sizeof(char));
    printf("Scanning: ");
    gets(tempStr);
    return tempStr;
}

Entree* findEntreeInList(ListAgenda list, Entree entree){
    Entree *temp=list.entreesHeads.next[1];
    while (temp->EntreeNext.next[1] !=NULL){
        temp = temp->EntreeNext.next[1];
        if (temp->myContact.nom == entree.myContact.nom)
            return temp;
    }
    return NULL;
}
