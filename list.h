#ifndef LISTE_H
#define LISTE_H
#include <stddef.h>

typedef enum { TYPE_STRING, TYPE_WORDARRAY } NodeType;

typedef struct Node {
    void *data;
    NodeType type;
    struct Node *next;
} Node;

typedef struct {
    Node* head;
    int size;
}List;

typedef struct {
    char **words;
    int count;
}WordArray;

void initializeList(List* list);
void addElement(List* list, char* value);
void deleteElement(List* list, char* value);
void addWordArray(List *list, char **words, int count);
void freeList(List *list);
int countElements(List *list);
WordArray* readElement(Node *node);
Node* nextElement(Node **current);
void sortByWordCount(List *list);


#endif
