#include "stdio.h"
#include "hashTableLive.h"
int hash(int key, int maxsize)
{
    return key % maxsize;
}
void initHT(Node &ht, int maxsize)
{
    ht.size = maxsize;
    ht.count = 0;
    ht.bucket = new Node[ht.size];
    for (int i = 0; i < ht.size; i++)
    {
        initHT(ht.bucket[i]);
    }
}
void freeHT(Node &ht)
{
    for (int i = 0; i < ht.size; i++)
    {
        freeHT(ht.bucket[i]);
    }
    ht.size = 0;
    ht.count = 0;
    delete[] ht.bucket;
}
Node *HTGet(Node ht, int key)
{
    int h = hash(key, ht.size);
    return listSearch(ht.bucket[h], key);
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
void deleteHT(Node &ht , int key)
{
    int h = hash(key, ht.size);
    Node *result = listSearch(ht.bucket[h], key);
    if(result == NULL)
        printf("Khoa %d khong ton tai \n", key);
    else 

}
void rehashingHT(Node &ht_old, int maxsize_new);
void pushHT(Node &ht, int key);
void traverse(Node ht);