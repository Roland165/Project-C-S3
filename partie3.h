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
