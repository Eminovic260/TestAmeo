#include <stdio.h>
#include "list.h"

int main() {
    List list;
    initializeList(&list);

    addElement(&list, 40);
    addElement(&list, 30);
    addElement(&list, 20);
    addElement(&list, 10);


    printf("Taille de la liste : %d\n", list.size);
    Node *current = list.head;
    while (current != NULL) {
        printf("%d \n", current->data);
        current = current->next;
    }
    printf("NULL/fin de liste\n");

    deleteElement(&list, 20);
    printf("Liste après suppression :\n");
    printf("Taille de la liste : %d\n", list.size);

    current = list.head;
    while (current != NULL) {
        printf("%d \n", current->data);
        current = current->next;
    }

    printf("NULL/fin de liste\n");

    return 0;
}
