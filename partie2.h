#ifndef UNTITLED13_PARTIE2_H
#define UNTITLED13_PARTIE2_H
#include "list.h"

// Crée une liste à partir d'une valeur entière donnée
List *createListFromValue(int n);

// Recherche d'une valeur dans le niveau le plus bas de la liste
Cell *searchInLowestLevel(List *myList, int target);

// Recherche d'une valeur à partir du niveau le plus élevé de la liste
Cell *searchFromHighestLevel(List *myList, int target);

// Affiche le résultat de la recherche à partir du niveau le plus élevé
void displaySearchFromHighestLevel(List *myList, int target);

// Affiche le résultat de la recherche dans le niveau le plus bas
void displaySearchInLowestLevel(List *myList, int target);

// Affiche les temps de recherche pour les deux méthodes à partir du niveau le plus bas et le plus élevé
void displayTimeBothSearches(int maxLevels, int nbrValues);

// Affiche les temps de recherche pour les deux méthodes à partir d'un niveau spécifique
void displayTimeBothSearchesForOneLevel(int level, int nbrValues);

// Recherche de plusieurs valeurs dans le niveau le plus bas de la liste
int searchValuesInLowestLevel(List *myList, int nbLevels, int nbrValues);

// Recherche de plusieurs valeurs à partir du niveau le plus élevé de la liste
int searchValuesFromHighestLevel(List *myList, int nbLevels, int nbrValues);

#endif
