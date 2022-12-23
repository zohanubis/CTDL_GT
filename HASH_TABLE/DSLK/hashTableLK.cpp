#include "stdio.h"
#include "hashTableLK.h"

void initList(Node *&head)
{
    head = NULL;
}
bool listIsEmpty(Node * head)
{
    return head == NULL;
}
Node *createNode(int x)
{
    Node *p = new Node;
    p->key = x;
    p->next = NULL;
    return p;
}
void freeList(Node *&head); // giải phóng danh sách
void search(Node *&head, int x)
{
    Node *p = createNode(x);
    if(listIsEmpty(head)){
        head = p;
    }else{
        p->next = head;
        head = p;
    }
}
void removeHead(Node *&head)
{
    if(listIsEmpty(head))return;
    else{
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}
void removeAfter(Node *&head, Node *q)
{
    if(listIsEmpty(head) || q == NULL || q->next == NULL) return;
    else{
        Node *p = q->next;
        q->next = p->next;
        delete p;
    }
}
void remove(Node *&head, int key)
{
    if(listIsEmpty(head)) return;
    Node *p =head, *q = NULL ; // q la node truoc p
    while (p != NULL && p -> key != key)
    {
        q = p;
        p = p->next;
    }
    if(q) removeHead(head); // p is head
    else removeAfter(head,q);// delete p
}
Node *listSearch(Node *head, int key)
{
    Node *p = head;
    while (p != NULL)
    {
        if(p -> key == key){
            return p;
        }
        p = p->next;
    }
    return NULL;
}
void listTraverse(Node *head)
{
    Node *p = head;
    while(p){
        printf("%4d ", p->key);
        p = p->next;
    }
    printf("\n");
}