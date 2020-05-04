//
// Created by ileana on 3/5/2020.
//

#ifndef INC_1_2_SLL_H
#define INC_1_2_SLL_H

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int truck_id;
    struct node * next;
}NodeT;

NodeT *firstG, *lastG;
NodeT * firstR, *lastR;

void addCar(int truck_id);
void deleteCar(int truck_id, int * ok);
void enterGarage(int truck_id);
void exitGarage(int truck_id, int *ok);
void showTrucks(NodeT * first, NodeT * last);
void initialize();
void addCarAtTop(int truck_id);


FILE * fin,* fout;


#endif //INC_1_2_SLL_H
