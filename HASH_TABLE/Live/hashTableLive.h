#ifndef hashTableLive_h
#define hashTableLive_h
struct Node
{
    Node *bucket;
    int size;
    int count;
    int key;
    Node *next;
};
// typedef Node* NodePtr;
int hash(int key, int maxsize);
void initHT(Node &ht, int maxsize);
void freeHT(Node &ht);
Node *HTGet(Node ht, int key);
void deleteHT(Node &ht , int key);
void rehashingHT(Node &ht_old, int maxsize_new);
void pushHT(Node &ht, int key);
void traverse(Node ht);
Node *listSearch(Node *head, int key);
#endif // !hashTableLive_h