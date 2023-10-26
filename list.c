//
// Created by Roland on 25/10/2023.
//

#include "list.h"
#include "stdlib.h"
#include "stdio.h"

List createList(){
    List list;
    list.max_level=0;
    list.heads[0]=NULL;
    return list;
}

Cell *createCell(int value, int level){
    Cell* cell=(Cell *) malloc(sizeof(Cell));
    cell->value=value;
    cell->next=NULL;
    cell->level=level;
    return cell;
}


void addCellToList(List* list, int value, int level){
    Cell *newCell= createCell(value,level);
    while(level>(list->max_level)){
        addLevel(list);
    }
    for (int i = 0; i <= level; i++) {
        if (list->heads[i] == NULL) {
            list->heads[i] = newCell;
        } else {
            Cell* temp = list->heads[i];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newCell;
        }
    }
}

void addLevel(List *list){
    list->max_level++;
    list->heads[list->max_level]=NULL;
}

void displayList(List list) {
    for (int i = 0; i <= list.max_level; i++){
        Cell* temp = list.heads[i];
        printf("[list_head%d @-]-->", i);
        while (temp != NULL) {
            printf("[ %d|@-]-->", temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}