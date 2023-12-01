#include <stdio.h>
#include <stdlib.h>
#include <string.h>


CellLevel0 *searchContact(List *agenda, char *partialName) {
    int level = 3;
    Cell *currentCell = &agenda->cellsHeads[level];
    while (level >= 0 && currentCell != NULL) {
        CellLevel0 *currentLevel0 = currentCell->down;
        while (currentLevel0 != NULL) {
            if (strncmp(partialName, currentLevel0->contact->nom, strlen(partialName)) == 0) {
                printf("Auto-completion suggestion: %s %s\n", currentLevel0->contact->nom, currentLevel0->contact->prenom);
                return currentLevel0;
            }
            currentLevel0 = currentLevel0->next;
        }
        currentCell = currentCell->next;
        level--;
    }
    printf("Contact not found.\n");
    return NULL;
}


void displayAppointments(Contact *contact) {
    printf("Appointments for %s %s:\n", contact->nom, contact->prenom);
}

void createContact(List *agenda, char *nom, char *prenom) {
    Contact *newContact = createContact(nom, prenom);
    CellLevel0 *newCellLevel0 = createCellLevel0(newContact, NULL);

    int level = 3;
    Cell *currentCell = &agenda->cellsHeads[level];
    while (level >= 0) {
        if (currentCell->next == NULL || nom[0] < currentCell->next->letter) {
            Cell *newCell = createCell(nom[0]);
            newCell->next = currentCell->next;
            currentCell->next = newCell;
            newCell->down = newCellLevel0;
            break;
        } else if (nom[0] == currentCell->next->letter) {
            currentCell = currentCell->next;
            level--;
        } else {
            currentCell = currentCell->next;
        }
    }

    printf("Contact created: %s %s\n", nom, prenom);
}

void createAppointment(List *agenda, char *nom, char *date, char *heure, char *duree, char *objet) {
    CellLevel0 *contactCell = searchContact(agenda, nom);
    if (contactCell != NULL) {
        Appointment *newAppointment = createAppointment(date, heure, duree, objet);
        contactCell->appointment = newAppointment;
        printf("Appointment created for %s %s\n", contactCell->contact->nom, contactCell->contact->prenom);
    } else {
        printf("Contact not found. Unable to create appointment.\n");
    }
}

void deleteAppointment(List *agenda, char *nom, char *date, char *heure) {
    CellLevel0 *contactCell = searchContact(agenda, nom);
    if (contactCell != NULL && contactCell->appointment != NULL) {
        free(contactCell->appointment);
        contactCell->appointment = NULL;
        printf("Appointment deleted for %s %s\n", contactCell->contact->nom, contactCell->contact->prenom);
    } else {
        printf("No appointment found for the specified contact.\n");
    }
}

void saveAppointments(List *agenda, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file != NULL) {
        int level = 3;
        Cell *currentCell = &agenda->cellsHeads[level];
        while (level >= 0 && currentCell != NULL) {
            CellLevel0 *currentLevel0 = currentCell->down;
            while (currentLevel0 != NULL) {
                fprintf(file, "%s %s\n", currentLevel0->contact->nom, currentLevel0->contact->prenom);
                if (currentLevel0->appointment != NULL) {
                    fprintf(file, "  Appointment: %s %s %s %s\n", currentLevel0->appointment->date,
                            currentLevel0->appointment->heure, currentLevel0->appointment->duree,
                            currentLevel0->appointment->objet);
                }
                currentLevel0 = currentLevel0->next;
            }
            currentCell = currentCell->next;
            level--;
        }
        fclose(file);
        printf("Appointments saved to %s\n", filename);
    } else {
        printf("Error opening file for saving appointments.\n");
    }
}

void loadAppointments(List *agenda, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        char line[256]; 
        while (fgets(line, sizeof(line), file) != NULL) {
            char *token = strtok(line, " ");
            char *nom = token;
            token = strtok(NULL, " ");
            char *prenom = token;
            CellLevel0 *contactCell = searchContact(agenda, nom);
            if (contactCell != NULL) {
                token = strtok(NULL, " ");
                if (token != NULL && strcmp(token, "Appointment:") == 0) {
                    char *date = strtok(NULL, " ");
                    char *heure = strtok(NULL, " ");
                    char *duree = strtok(NULL, " ");
                    char *objet = strtok(NULL, "\n");
                    Appointment *newAppointment = createAppointment(date, heure, duree, objet);
                    contactCell->appointment = newAppointment;
                }
            } else {
                printf("Contact not found: %s %s\n", nom, prenom);
            }
        }
        fclose(file);
        printf("Appointments loaded from %s\n", filename);
    } else {
        printf("Error opening file for loading appointments.\n");
    }
}

void calculateInsertionTime(List *agenda, char *nom, char *prenom) {
    int insertionTime = 0;
    int level = 3;
    Cell *currentCell = &agenda->cellsHeads[level];
    while (level >= 0) {
        if (currentCell->next == NULL || nom[0] < currentCell->next->letter) {
            insertionTime++;
            break;
        } else if (nom[0] == currentCell->next->letter) {
            currentCell = currentCell->next;
            level--;
        } else {
            currentCell = currentCell->next;
        }
        insertionTime++;
    }

    printf("Insertion time for %s %s: %d levels\n", nom, prenom, insertionTime);
}

