//
// Created by ileana on 3/5/2020.
//


#include "sll.h"


void initialize() {
    firstR = lastR = NULL;
    firstG = lastG = NULL;
}

void addCar(int truck_id)
{
    NodeT * newElement =(NodeT*)malloc(sizeof(NodeT));
    newElement->next=NULL;
    newElement->truck_id=truck_id;
    if(lastR!=NULL)
        lastR->next=newElement;
    else
        firstR=newElement;
    lastR=newElement;
}

void addCarAtTop(int truck_id)
{
    NodeT * newElement =(NodeT*)malloc(sizeof(NodeT));
    newElement->next=NULL;
    newElement->truck_id=truck_id;
    if(firstR!=NULL)
    {
        newElement->next=firstR;
        firstR=newElement;
    }
    else
        firstR=lastR=NULL;
}

void deleteCar(int truck_id,int *ok)     //DELETE FIRST CAR
{
    NodeT * currentElement, * previousElement;
    previousElement=NULL;
    currentElement=firstR;
    while(currentElement!=NULL)
    {
        if(currentElement->truck_id==truck_id) {
            *ok = 1;
            break;
        }
        previousElement=currentElement;
        currentElement=currentElement->next;
    }
    if(currentElement!=NULL)
    {
        if(currentElement==firstR)
        {
            firstR=firstR->next;
            free(currentElement);
            if(firstR==NULL)
                lastR=NULL;
        }
        else
        {
            previousElement->next =currentElement->next;
            if(currentElement==lastR)
                lastR=previousElement;
            free(currentElement);
        }
    }
    else {
        fprintf(fout, "%d not on road\n", truck_id);
        *ok = 0;
    }

}

void enterGarage(int truck_id)
{
    NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
    newElement->next=NULL;
    newElement->truck_id=truck_id;
    if(lastG!=NULL)
    {
        lastG->next=newElement;
    }
    else
        firstG=newElement;
    lastG=newElement;
}

void exitGarage(int truck_id,int * ok)
{
    if(lastG!=NULL) {
        if (firstG->truck_id == truck_id) {
            *ok=1;
           NodeT *p=firstG;
           firstG=firstG->next;
           free(p);
           if(firstG==NULL)
               lastG=NULL;
        } else {
            fprintf(fout, "%d not at exit!\n", truck_id);
            ok = 0;
        }
    }
}

void showTrucks(NodeT * first, NodeT*last)
{
    NodeT * element= first;
    while(element!=NULL)
    {
        fprintf(fout,"%d ",element->truck_id);
        element=element->next;
    }
    if(first==NULL)
        fprintf(fout, "none");
    fprintf(fout, "\n");
}