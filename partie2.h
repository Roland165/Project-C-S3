#ifndef UNTITLED13_PARTIE2_H
#define UNTITLED13_PARTIE2_H
#include "list.h"

List* createListFromValue(int n);
Cell* searchInTheLowestLevel(List* myList, int target);
Cell* searchFromHighestLevel(List* myList, int target);
void displaySearchFromHighestLevel(List* myList, int target);
void displaySearchInTheLowestLevel(List *mylist, int target);
void displayTimeBothSearchesForNbrLevelsMaxAndNbrValues(int maxLevels, int nbrValues);
void displayTimeBothSearchesForOneLevelAndNbrValues(int level, int nbrValues);
int searchForNbrValuesFromLowestLevel(List* myList, int nbLevels, int nbrValues);
int searchForNbrValuesFromHighestLevel(List* myList, int nbLevels, int nbrValues);
#endif //UNTITLED13_PARTIE2_H
