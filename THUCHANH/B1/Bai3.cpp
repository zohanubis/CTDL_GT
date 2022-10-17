#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct Node
{
    int info;
    Node *next;
};
struct Slist
{
    Node *head;
    Node *tail;
};
Node *createList(int x)
{
    Node *p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat !");
        return NULL;
    }
    p -> info = x;
    p -> next = NULL;
}
void menu();
void initSList(Slist &sl);
void addHeadSList(Slist &sl, Node *p);
void addTailSList(Slist &sl, Node *p);
void createAutoList(Slist &sl);
void printList(Slist sl);
void sortIncrease(Slist &sl);
void insertX(Slist &sl, int x);
void sortDecrease(Slist &sl);
void joinTwoList(Slist &sl1, Slist sl2, int x);
int main()
{
    menu();
    return 0;
}