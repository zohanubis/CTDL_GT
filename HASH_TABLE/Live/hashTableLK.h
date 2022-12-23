#ifndef hashTableLK_h
#define hashTableLk_h
using namespace std;
struct Node
{
    int key;
    Node *next;
};
typedef Node* NodePtr; 
void initList(Node *&head); 
bool listIsEmpty(Node * head);
void freeList(Node *&head); // giải phóng danh sách
void search(Node *&head, int x);
void remove(Node *&head, int key);
Node *listSearch(Node *head, int key);
void listTraverse(Node *head);
Node *createNode(int x);
void removeHead(Node *&head);
void removeAfter(Node *&head, Node *q);
#endif // !hashTableLK_h
