#ifndef PROJETS3_LIST_H
#define PROJETS3_LIST_H

typedef struct Cell{
    int value;
    int level;
    struct Cell *next;
}Cell;

typedef struct List{
    int max_level;
    struct Cell *heads[100];
}List;

List createList();
Cell *createCell(int value, int level);
void displayList(List list);
void addCellToList(List *list, int value, int level);
void addLevel(List *list);

#endif //PROJETS3_LIST_H
