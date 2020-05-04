#include <stdio.h>
#include "header.h"
int main() {

    initialize();
    deleteFirstNode();
    deleteData(20);
    for(int i=0;i<9;i++) {
        addLast(i);
        //printf("%d\n", L->first->key);
    }
    printList();
    addFirstNode(10);
    addFirstNode(10);
    printList();
    deleteData(10);
    deleteData(4);
    printList();
    deleteFirstNode();
    printList();
    return 0;
}