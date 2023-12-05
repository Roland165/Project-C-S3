//
// Created by Max on 02/12/2023.
//
#include "agenda.h"
#include <stdlib.h>
#include <stdio.h>


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