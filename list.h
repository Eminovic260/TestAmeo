#ifndef LISTE_H
#define LISTE_H


typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node* head;
    int size;
}List;


void initializeList(List* list);
void addElement(List* list, int value);
void removeElement(List* list, int value);

#endif
