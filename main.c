#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void printList(List *list) {
    Node *cur = list->head;
    while (cur != NULL) {
        if (cur->type == TYPE_STRING)
            printf("Chaine simple : %s\n", (char *) cur->data);
        else if (cur->type == TYPE_WORDARRAY) {
            WordArray *wa = (WordArray *) cur->data;
            printf("WordArray, %d mots : ", wa->count);
            for (int i = 0; i < wa->count; i++)
                printf("%s ", wa->words[i]);
            printf("\n");
        }
        cur = cur->next;
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

    sortByWordCount(&list);
    printf("Apres tri par nombre de mots :\n");
    printList(&list);

    freeList(&list);
    printf("Liberation de la liste\n");
    printList(&list);

    return 0;
}
