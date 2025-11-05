#include <stdio.h>
#include "list.h"

int main() {
    List myList;
    initializeList(&myList);

    printf("Premier élément : %p\n", (void*)myList.head);
    printf("Taille de la liste : %d\n", myList.size);

    return 0;
}