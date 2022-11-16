#ifndef BRTree_h
#define BRTree_h

#include "stdio.h"
#include "conio.h"
#include "queue"
#include "stack"    
#include "Windows.h"
using namespace std;
/* Khai báo kiểu dữ liệu của Node */
typedef int ItemType;
/* Khai báo cấu trúc cây Đỏ-Đen */
enum EColor {RED , BLACK};
/* Khai báo cấu trúc cây Đỏ-Đen */
struct BRTNode
{
    int info;
    EColor Color;
    BRTNode *left, *right, *parent;
};
/* Khai báo cấu trúc cây Đỏ-Đen */
struct BRTree
{
    BRTNode *root;
};
//==================================================
BRTNode* createBRTNode(ItemType x);
void set_Color(int colorBackground, int colorText);
void showTNode(BRTNode *p);
void initBRTree(BRTree &brt);

void swapColors(EColor &color1, EColor &color2);
void swapInfos(ItemType &info1, ItemType &info2);

void showBRTree_PreOrder(BRTNode *root);
void showBRTree_InOrder(BRTNode *root);
void showBRTree_PostOrder(BRTNode *root);

void levelOrder(BRTNode *root);
void showLevelOrder(BRTNode *root);

void iterativePreOrder(BRTNode *root);
void showPreOrder(BRTNode *root);
void iterativeInOrder(BRTNode *root);
void showInOrder(BRTNode *root);
void iterativePostOrder(BRTNode *root);
void showPostOrder(BRTNode *root);

BRTNode* BRTInsert(BRTNode* root, BRTNode *pNew);
void rotateLeft(BRTNode *&root, BRTNode *&p);
void rotateRight(BRTNode *&root, BRTNode *&p);
void fixViolation(BRTNode *&root, BRTNode *&p);
void insert(BRTNode *&root, ItemType Info);

bool isOnLeft(BRTNode *p);
bool hasRedChild(BRTNode *p);
BRTNode *findUncle(BRTNode *p);
BRTNode *findSibling(BRTNode *p);
BRTNode *findSuccessor(BRTNode *p);
void fixDoubleBlack(BRTNode *&root, BRTNode *p);
BRTNode *BSTReplace(BRTNode *p);
void deleteNode(BRTNode *&root, BRTNode *pDelete);
BRTNode *search(BRTNode *root, ItemType x);
void deleteByInfo(BRTNode *&root, ItemType x);

void createBRTreeFromArray(BRTree &brt, ItemType a[], int na);
void createBSTree(BRTree &brt);

void traverseNRL(BRTNode *root);
void traverseRNL(BRTNode *root);
void traverseRLN(BRTNode *root);

int demSoNodeDo(BRTNode* root);
int demSoNodeDen(BRTNode* root);

int demSoNodeDenMucK(BRTNode* root, int k);
int demSoNodeDoMucK(BRTNode* root, int k);
#endif // !BTree_h