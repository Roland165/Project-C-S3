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
}RDV;

typedef struct LLCRDV{
    RDV* head;
}LLCRDV;

typedef struct Entree{
    Contact myContact;
    LLCRDV myLLCRDV;
    struct Entree** tabPtrEntree;
    int nbLevels
}Entree;

char* scanString();

#endif //PROJET_C_S3_MAX_AGENDA_H
