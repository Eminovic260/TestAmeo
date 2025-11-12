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
    newNode->data = strdup(value);
    newNode->type = TYPE_STRING;
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

void addWordArray(List *list, char** words, int count) {
    if (!list || !words || count<=0) return;
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (!newNode) return;

    WordArray *newWordArray = (WordArray *) malloc(sizeof(WordArray));
    if (!newWordArray) {
        free(newNode);
        return;
    }

    newWordArray->count = count;
    newWordArray->words = (char **) malloc(sizeof(char *) * count);
    if (!newWordArray->words) {
        free(newWordArray);
        free(newNode);
        return;
    }
    for (int i = 0; i < count; i++) {
        newWordArray->words[i] = strdup(words[i]);
    }
    newNode->data = newWordArray;
    newNode->next = list->head;
    list->head = newNode;
    newNode->data = newWordArray;
    newNode->type = TYPE_WORDARRAY;
    list->size++;
}

int countElements(List *list) {
    if (!list) return 0;
    return list->size;
}

WordArray* readElement(Node *node) {
    if (!node) return NULL;
    return (WordArray*) node->data;
}

void freeList(List *list) {
    if (!list) return;
    Node *current = list->head;
    while (current) {
        Node *next = current->next;

        if (current->type == TYPE_STRING) {
            free(current->data);
        }
        else if (current->type == TYPE_WORDARRAY) {
            WordArray *wa = (WordArray*) current->data;
            for (int i = 0; i < wa->count; i++) {
                free(wa->words[i]);
            }
            free(wa->words);
            free(wa);
        }

        free(current);
        current = next;
    }
    list->head = NULL;
    list->size = 0;
}
