#include <stdio.h>
#include "list.h"

int main() {
    List list;
    initializeList(&list);

    addElement(&list, "Test");
    addElement(&list, "Oui");
    addElement(&list, "World");
    addElement(&list, "Hello");



    printf("Taille de la liste : %d\n", list.size);
    Node *current = list.head;
    while (current != NULL) {
        printf("%s \n", current->data);
        current = current->next;
    }
    printf("NULL/fin de liste\n");

    deleteElement(&list, "Oui");
    printf("Liste après suppression :\n");
    printf("Taille de la liste : %d\n", list.size);

    current = list.head;
    while (current != NULL) {
        printf("%s \n", current->data);
        current = current->next;
    }

    printf("NULL/fin de liste\n");

    return 0;
}
