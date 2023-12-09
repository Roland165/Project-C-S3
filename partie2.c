#include "partie2.h"
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
List *createListFromValue(int n) {
    if (n == 0) {
        return NULL;
    }

    // Calculer le nombre total de niveaux dans la liste, l'utilisation de (1 << n) permet d'éviter un include
    int totalLevels = (1 << n) - 1;

    // Allouer un tableau pour stocker les niveaux de chaque cellule
    int *cellLevels = (int *)malloc(sizeof(int) * totalLevels);

    // Initialiser tous les niveaux à 1
    for (int i = 0; i < totalLevels; i++) {
        cellLevels[i] = 1;
    }

    // Boucle pour ajuster les niveaux en fonction de la puissance de 2
    for (int currentPower = 1; currentPower < n; currentPower++) {
        int increment = (1 << currentPower);
        int currentIndex = increment - 1; // Commencer à l'indice correspondant à la puissance de 2

        // Ajuster les niveaux en sautant les cellules de même niveau
        while (currentIndex < totalLevels) {
            cellLevels[currentIndex]++;
            currentIndex += increment;
        }
    }

    // Créer une nouvelle liste vide
    List *newList = createEmptyList(n);

    // Insérer les cellules dans la liste en respectant l'ordre
    for (int i = 0; i < totalLevels; i++) {
        insertCellInOrder(newList, i + 1, cellLevels[i] - 1);
    }

    // Libérer la mémoire allouée pour le tableau des niveaux
    free(cellLevels);

    // Retourner la nouvelle liste créée
    return newList;
}

// Recherche d'une valeur dans le niveau le plus bas de la liste
Cell *searchInLowestLevel(List *myList, int target) {
    Cell *current = myList->cellsHeads.next[0];

    while (current != NULL) {
        if (current->value == target) {
            return current;
        }
        current = current->cellsNext.next[0];
    }

    return NULL;
}

// Recherche d'une valeur à partir du niveau le plus élevé
Cell *searchFromHighestLevel(List *myList, int target) {
    int highestLevel = myList->nbLevels - 1;
    Cell *current = myList->cellsHeads.next[highestLevel];

    // Si la cible est inférieure à la plus petite valeur dans le niveau le plus bas, la cible ne peut pas être dans la liste
    if (target < myList->cellsHeads.next[0]->value) {
        return NULL;
    }

    while (current->value > target) {
        highestLevel = highestLevel - 1;
        current = myList->cellsHeads.next[highestLevel];
    }

    if (current->value == target) {
        return current;
    }

    while (highestLevel >= 0) {
        if (current->cellsNext.next[highestLevel] != NULL && current->cellsNext.next[highestLevel]->value == target) {
            return current->cellsNext.next[highestLevel];
        }

        if (current->cellsNext.next[highestLevel] == NULL || current->cellsNext.next[highestLevel]->value > target) {
            highestLevel--;
        } else {
            current = current->cellsNext.next[highestLevel];
        }
    }

    return NULL;
}

// Affichage du résultat de la recherche à partir du niveau le plus élevé
void displaySearchFromHighestLevel(List *myList, int target) {
    Cell *resultHighestLevel = searchFromHighestLevel(myList, target);

    if (resultHighestLevel != NULL) {
        printf("Found %d at level %d.\n", target, resultHighestLevel->nbLevels - 1);
    } else {
        printf("%d not found starting from the highest level.\n", target);
    }
}

// Affichage du résultat de la recherche dans le niveau le plus bas
void displaySearchInLowestLevel(List *myList, int target) {
    Cell *resultLevel0 = searchInLowestLevel(myList, target);

    if (resultLevel0 != NULL) {
        printf("Found %d at level 0.\n", target);
    } else {
        printf("%d not found at level 0.\n", target);
    }

}

// Recherche de plusieurs valeurs à partir du niveau le plus bas
int searchValuesInLowestLevel(List *myList, int nbLevels, int nbrValues) {
    if ((nbrValues != 0) && (myList != NULL)) {
        srand(31);
        int maxiValueInList = (1 << nbLevels) - 1;

        for (int iterNbrValues = 1; iterNbrValues <= nbrValues; iterNbrValues++) {
            int valueToSearch = rand() % (maxiValueInList + 1);
            searchInLowestLevel(myList, valueToSearch);
        }
        return 1;
    }
    return 0;
}

// Recherche de plusieurs valeurs à partir du niveau le plus élevé
int searchValuesFromHighestLevel(List *myList, int nbLevels, int nbrValues) {
    if ((nbrValues != 0) && (myList != NULL)) {
        srand(31);
        int maxiValueInList = (1 << nbLevels) - 1;

        for (int iterNbrValues = 1; iterNbrValues <= nbrValues; iterNbrValues++) {
            int valueToSearch = rand() % (maxiValueInList + 1);
            searchFromHighestLevel(myList, valueToSearch);
        }
        return 1;
    }
    return 0;
}

// Affichage des temps de recherche à partir des niveaux les plus bas et les plus élevés
void displayTimeBothSearches(int maxLevels, int nbrValues) {
    for (int nbrLevels = 7; nbrLevels <= maxLevels; nbrLevels++) {
        displayTimeBothSearchesForOneLevel(nbrLevels, nbrValues);
    }
}

// Affichage des temps de recherche à partir d'un niveau spécifique pour un nombre donné de valeurs
void displayTimeBothSearchesForOneLevel(int level, int nbrValues) {
    List *myList = createListFromValue(level);

    startTimer();
    if ((searchValuesInLowestLevel(myList, level, nbrValues)) == 1) {
        stopTimer();
        printf("Lowest Level Search: nbrValues=%d; level=%d; ", nbrValues, level);
        printf("%s", getTimeAsString());
        printf("\n");
    }

    startTimer();
    if ((searchValuesFromHighestLevel(myList, level, nbrValues)) == 1) {
        stopTimer();
        printf("Highest Level Search: nbrValues=%d; level=%d; ", nbrValues, level);
        printf("%s", getTimeAsString());
        printf("\n");
    }
}
