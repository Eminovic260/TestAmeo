#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initializeList(List *list) {
    if (!list)return;
    list->head = NULL;
    list->size = 0;
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

void deleteElement (List* list, int value) {
    if (!list || !list->head) return;

    Node* current = list->head;
    Node* previous = NULL;
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }
if (!current) return;

    if (previous==NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    list->size--;
}