#include <stdio.h>
#include "header.h"
int main() {

    initialize();
    deleteElement(4);
    insertAfterCurrent(4);
    printList();
    for(int i=0;i<9;i++)
        insertData(i);
    printList();
    deleteElement(0);
    deleteElement(7);
    deleteElement(73);
    printList();
    printf("%d\n",L->current->key);
    insertAfterCurrent(22);
    printList();
    printf("%d\n",L->current->key);
    insertAfterCurrent(25);
    printList();
    deleteCurrentNode();
    printList();
    return 0;
}