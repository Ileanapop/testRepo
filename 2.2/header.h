//
// Created by ileana on 3/9/2020.
//

#ifndef INC_2_2_HEADER_H
#define INC_2_2_HEADER_H

#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int key;
    struct node * next;
}NodeT;

struct circularList
{
    int length;
    NodeT * current;
};
struct circularList * L;

NodeT * pNode;

void insertData(int givenKey);
NodeT * findNode(int givenKey);
void initialize();
void printList();
void deleteElement(int givenKey);
void insertAfterCurrent(int givenKey);
void deleteCurrentNode();

#endif //INC_2_2_HEADER_H
