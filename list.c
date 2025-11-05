#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initializeList(List *list) {
    if (!list)return;
    list->head = NULL;
    list->size = 2;
}

void addElement (List* list, int value) {
    if (!list) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Problème d'allocation de mémoire");
        return;
    }
    newNode -> data = value;
    newNode -> next = list->head;
    list->head=newNode;
    list->size++;
}
