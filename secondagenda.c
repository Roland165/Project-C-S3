#include "secondagenda.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

// Fonction pour créer un contact
Contact* createContact(char* nom, char* prenom){
    Contact* newContact = (Contact*) malloc(sizeof(Contact));
    newContact->nom = nom;
    newContact->prenom = prenom;
    return newContact;
}

// Fonction pour créer un rendez-vous
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

// Fonction pour afficher un rendez-vous
void displayRDV(RDV myRDV){
    printf("\nLa date du rendez-vous est : %d / %d / %d.\n",myRDV.jour, myRDV.mois, myRDV.annee);
    printf("Le rendez-vous est a %dh %d.\n",myRDV.heure, myRDV.minute);
    printf("l'objet du rendez-vous est : %s.\n",myRDV.objet);
}

// Fonction pour créer une Entree
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

//Fonction pour trouver une entree dans la liste
Entree* findEntreeInList(ListAgenda list, Entree entree){
    Entree *temp=list.entreesHeads.next[1];
    while (temp->EntreeNext.next[1] !=NULL){
        temp = temp->EntreeNext.next[1];
        if (temp->myContact.nom == entree.myContact.nom)
            return temp;
    }
    return NULL;
}

//Fonction pour ajouter un rendez-vous à sa liste chaînée
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

//Fonction pour créer une liste chaînée vide de rendez-vous
LLCRDV *createLLCRDV(){
    LLCRDV *llcrdv=(LLCRDV*) malloc(sizeof (LLCRDV));
    llcrdv->head=NULL;
    return llcrdv;
}

//Fonction pour afficher une liste chaînée de rendez-vous
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

//Fonction test pour afficher les niveaux dans la liste
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

//fonction pour ajouter une Entree à la liste
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

//Fonction pour récupérer les informations dans la console destiné au menu
char* scanString(){
    char* tempStr = (char*)malloc(200*sizeof(char));
    printf("Scanning: ");
    gets(tempStr);
    return tempStr;
}

/*
//Fonction pour avoir le niveau de l'Entree en fonction des premières lettres du nom de son Contact
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


