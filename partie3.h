#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Contact {
    char *nom;
    char *prenom;
} Contact;


typedef struct Appointment {
    char *date;
    char *heure;
    char *duree;
    char *objet;
} Appointment;


typedef struct CellLevel0 {
    Contact *contact;  
    Appointment *appointment;
    struct CellLevel0 *next;
} CellLevel0;


typedef struct Cell {
    char letter;  
    struct Cell *next; 
    struct CellLevel0 *down; 
} Cell;


typedef struct List {
    Cell cellsHeads[4]; 
} List;


Contact *createContact(char *nom, char *prenom) {
    Contact *newContact = malloc(sizeof(Contact));
    newContact->nom = strdup(nom);
    newContact->prenom = strdup(prenom);
    return newContact;
}


Appointment *createAppointment(char *date, char *heure, char *duree, char *objet) {
    Appointment *newAppointment = malloc(sizeof(Appointment));
    newAppointment->date = strdup(date);
    newAppointment->heure = strdup(heure);
    newAppointment->duree = strdup(duree);
    newAppointment->objet = strdup(objet);
    return newAppointment;
}


CellLevel0 *createCellLevel0(Contact *contact, Appointment *appointment) {
    CellLevel0 *newCell = malloc(sizeof(CellLevel0));
    newCell->contact = contact;
    newCell->appointment = appointment;
    newCell->next = NULL;
    return newCell;
}


Cell *createCell(char letter) {
    Cell *newCell = malloc(sizeof(Cell));
    newCell->letter = letter;
    newCell->next = NULL;
    newCell->down = NULL;
    return newCell;
}
