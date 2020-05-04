//
// Created by ileana on 3/8/2020.
//

#ifndef INC_2_1_HEADER_H
#define INC_2_1_HEADER_H

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int key;
    struct node * next;
}NodeT;


struct circularList
{
    int length;
    NodeT * first;
};

struct circularList * L;


void initialize();
void insertData(int givenKey);
void deleteData(int givenKey);

void addFirstNode(int givenKey);
void deleteFirstNode();
void printList();
NodeT * findNode(int givenKey);
void addLast(int givenKey);

#endif //INC_2_1_HEADER_H
