#include <stdio.h>
#include "list.h"

int main() {
    List list;
    initializeList(&list);

    printf("Premier element : %p\n", (void*)list.head);
    printf("Taille de la liste : %d\n", list.size);

    addElement(&list, 30);
    addElement(&list, 20);
    addElement(&list, 10);
    Node* current= list.head;
   while(current!=NULL) {
       printf("%d \n", current->data);
       current = current->next;
   }
    printf("NULL\n");
    printf("Taille de la liste : %d\n", list.size);
    return 0;
}