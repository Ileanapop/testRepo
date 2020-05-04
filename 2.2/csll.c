//
// Created by ileana on 3/9/2020.
//


#include "header.h"



void initialize()
{
    pNode=NULL;
    L = (struct circularList * )malloc(sizeof(struct circularList));
    L->current = (NodeT*)malloc(sizeof(NodeT));
    L->current=NULL;
}

void insertData(int givenKey)
{
    if(findNode(givenKey)==NULL)
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->key=givenKey;
        if(pNode==NULL)
        {
            newElement->next=newElement;
            pNode=newElement;
        }
        else
        {
            newElement->next = pNode ->next;
            pNode->next=newElement;
            pNode=newElement;
        }
        L->current=newElement;
    }
}

NodeT * findNode(int givenKey){
    if(pNode!=NULL) {
        NodeT *p;
        p = pNode;
        do {
            if (p->key == givenKey) {
                L->current = p;
                return p;
            }
            p = p->next;
        } while (p != pNode);
    }
    return NULL;
}

void deleteElement(int givenKey)
{
    if(pNode!=NULL) {
        NodeT *q, *q1;
        q = pNode;
        q1 = pNode;
        do {
            if (q->key == givenKey)
                break;
            q1 = q;
            q = q->next;
        } while (q != pNode);
        if (q->key == givenKey) {
            if (q == q->next)
                pNode = NULL;
            else {
                q1->next = q->next;
                if(q==pNode)
                    pNode=q1;
            }
            free(q);
        }
    }
}

void insertAfterCurrent(int givenKey)
{
    if(L->current!=NULL)
    {
        NodeT * newElement = (NodeT*)malloc(sizeof(NodeT));
        newElement->key=givenKey;
        newElement->next=L->current->next;
        L->current->next=newElement;
        if(L->current==pNode)
            pNode=newElement;
        L->current=newElement;
    }
}

void deleteCurrentNode() {
    if(L->current!=NULL)
    {
        NodeT * q;
        q=pNode;
        do{
            if(q->next==L->current)
                break;
            q=q->next;
        }while(q!=pNode);
        if(q==q->next)
        {
            pNode=L->current=NULL;
        }
        else
        {
            q->next=L->current->next;
            if(L->current==pNode)
                pNode=q;
            L->current=NULL;
        }
    }
}

void printList() {
    if(pNode!=NULL)
    {
        NodeT *  element=pNode->next;
        do{
            printf("%d ",element->key);
            element=element->next;
        }while(element!=pNode);
        printf("%d ",pNode->key);
        printf("\n");
    }
}
