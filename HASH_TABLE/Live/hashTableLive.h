#ifndef hashTableLive_h
#define hashTableLive_h
struct HashTable
{
    Node *bucket;
    int size;
    int count;
};
int hash(int key, int maxsize);
void initHT(HashTable &ht, int maxsize);
void freeHT(HashTable &ht);
Node *HTGet(HashTable ht, int key);
void deleteHT(HashTable &ht , int key);

#endif // !hashTableLive_h