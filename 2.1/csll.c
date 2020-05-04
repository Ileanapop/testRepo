//
// Created by ileana on 3/8/2020.
//

#include "header.h"

void initialize()
{
    L=(struct circularList *)malloc(sizeof(struct circularList));
    L->first=(NodeT*)malloc(sizeof(NodeT));
    L->first=NULL;
    L->length=0;
}

void addFirstNode(int givenKey)
{
    if(findNode(givenKey)==NULL)
    {
        NodeT * element = (NodeT*)malloc(sizeof(NodeT));
        element->key=givenKey;
        if(L->first==NULL)
        {
            L->first=element;
            L->first->next=element;
        }
        else
        {
            NodeT * p=L->first;
            do{
                p=p->next;
            }while(p->next!=L->first);
            p->next=element;
            element->next=L->first;
            L->first=element;
        }
        L->length++;
    }
}
void addLast(int givenKey)
{
    if(findNode(givenKey)==NULL)
    {
        NodeT * element=(NodeT*)malloc(sizeof(NodeT));
        element->key=givenKey;
        if(L->first==NULL)
        {
            element->next=element;
            L->first=element;
        } else
        {
            NodeT * p=L->first;
            do{
                p=p->next;
            }while(p->next!=L->first);
            p->next=element;
            element->next =L->first;
        }
        L->length++;
    }
}
void deleteData(int givenKey)
{
    NodeT* q;
    q=L->first;
    NodeT * p=(NodeT*)malloc(sizeof(NodeT));
    p=findNode(givenKey);
    if(p!=NULL)
    {
        do{
            q=q->next;
        }while(q->next!=p);
        if(p==q)
            L->first=NULL;
        else {
            q->next = p->next;
            if (p == L->first)
                L->first = L->first->next;
        }
        free(p);
        L->length--;
    }
}

void deleteFirstNode()
{
    if(L->first!=NULL)
    {
        NodeT * p=L->first;
        do {
            p = p->next;
        } while (p->next!=L->first);
        if(p==L->first) {
            L->first = NULL;
            free(p);
        }
        else {
            NodeT * q=L->first;
            p->next = L->first->next;
            L->first = L->first->next;
            free(q);
        }
        L->length--;
    }
}
void printList()
{
    if(L->first!=NULL)
    {
        NodeT* element=L->first;
        do{
            printf("%d ",element->key);
            element=element->next;
        }while(element!=L->first);
        printf("\n");
    }
}

NodeT * findNode(int givenKey)
{
    if(L->first!=NULL){
        NodeT *p;
        p = L->first;
        do {
            if (p->key == givenKey)
                return p;
            p = p->next;
        } while (p != L->first);
    }
    return NULL;
}