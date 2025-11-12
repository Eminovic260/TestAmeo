#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void printList(List *list) {
    Node *current = list->head;
    printf("Liste (%d elements) :\n", list->size);

    while (current) {
        if (current->type == TYPE_STRING) {
            printf("Chaine simple : %s\n", (char*)current->data);
        } else if (current->type == TYPE_WORDARRAY) {
            WordArray *wa = (WordArray*) current->data;
            printf("WordArray, %d mots : ", wa->count);
            for (int i = 0; i < wa->count; i++) {
                printf("%s ", wa->words[i]);
            }
            printf("\n");
        }
        current = current->next;
    }

    printf("NULL / fin de liste\n\n");
}


int main() {
    List list;
    initializeList(&list);

    addElement(&list, "Test");
    addElement(&list, "Oui");
    addElement(&list, "World");
    addElement(&list, "Hello");

    printf("Ajout de chaines simples\n");
    printList(&list);

    deleteElement(&list, "Oui");
    printf("Apres suppression de 'oui'\n");
    printList(&list);



    char *words1[] = {"Hellow", "World"};
    char *words2[] = {"C", "est", "un", "test"};

    addWordArray(&list, words1, 2);
    addWordArray(&list, words2, 4);

    printf("Apres ajout de WordArrays\n");
    printList(&list);

    freeList(&list);
    printf("Liberation de la liste\n");
    printList(&list);

    return 0;
}

