#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

void initializeList(List *list) {
    if (!list)return;
    list->head = NULL;
    list->size = 0;
}

void addElement(List *list, char* value) {
    if (!list || !value) return;

    Node *newNode = (Node *) malloc(sizeof(Node));
    if (!newNode) {
        printf("Problème d'allocation de mémoire");
        return;
    }

    newNode->data = strdup(value);
    if (!newNode->data) {
        free(newNode);
        printf("Problème d'allocation pour la chaîne\n");
        return;
    }

    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void deleteElement(List *list, char* value) {
    if (!list || !list->head || !value) return;

    Node *currentNode = list->head;
    Node *previousNode = NULL;

    while (currentNode != NULL && strcmp(currentNode->data, value) != 0) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if (!currentNode) return;
    if (!previousNode) list->head = currentNode->next;
    else previousNode->next = currentNode->next;

    free(currentNode->data);
    free(currentNode);
    list->size--;
}

