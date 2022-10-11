#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "time.h"

struct Node
{
    int info, count;
    Node *next;
};
struct Slist   
{
    Node *head;
    Node *tail;
};
Node *createNode(int x)
{
    Node *q = new Node;
    if (q == NULL)
    {
        printf("Khong du bo nho de cap phat ");
        return NULL;
    }
    q -> info = x;
    q -> next = NULL;
    return q;
}
void menu();
void createSlist(Slist &l, int n);
void printSlist(Slist l);
// <-> Câu a <->
void addTailSlist(Slist &l, Node *p);
// <-> Câu b <->
// <-> Câu c <->
// <-> Câu d <->
void deleteEvenInSlist(Slist &l);
// <-> Câu e <->
void findMinInSlist(Slist l);
void findMaxInSlist(Slist l);


// Code 
void addTailSlist(Slist &l, Node *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        if (l.head == NULL)
        {
            l.head = l.tail = p;
        }
        else
        {
            l.tail -> next = p;
            l.tail = p;
        }
    }
}
int findFistEvenElenmetsInSlist(Slist l)
{
    Node *temp = l.head;
    while (temp)
    {
        if(temp -> info % 2 == 0)
            return temp -> info;
        temp = temp -> next;
    }
}

void deleteEvenInSList(Slist &l)
{
    Node *even = findFistEvenElenmetsInSlist(l);
   if (l.head == NULL || even == NULL)
   {
    /* code */
   }
   
    
}