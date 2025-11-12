#ifndef LISTE_H
#define LISTE_H
#include <stddef.h>

typedef struct Node {
    void *data;
    struct Node *next;
} Node;

typedef struct {
    Node* head;
    int size;
}List;

void initializeList(List* list);
void addElement(List* list, char* value);
void deleteElement(List* list, char* value);


#endif
