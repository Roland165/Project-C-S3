#ifndef UNTITLED13_PARTIE2_H
#define UNTITLED13_PARTIE2_H
#include "list.h"

List* createListFromValue(int n);
Cell* searchInTheLowestLevel(List* myList, int target);
Cell* searchFromHighestLevel(List* myList, int target);
void displaySearchFromHighestLevel(List* myList, int target);
void displaySearchInTheLowestLevel(List *mylist, int target);
#endif //UNTITLED13_PARTIE2_H
