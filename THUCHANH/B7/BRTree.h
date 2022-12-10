#ifndef BRTree_h
#define BRTree_h

#include <conio.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <Windows.h>
using namespace std;

/* Khai báo kiểu dữ liệu của Node */
struct TTP
{
	char maMH[11];
	char tenMH[31];
	int soTC;
	char loaiHP[21];
};

/* Khai báo thuộc tính color */
enum EColor { RED, BLACK };

/* Khai báo cấu trúc node */
struct BRTNode
{
	TTP Info;
	EColor Color;
	BRTNode* Left, * Right, * Parent;
};

/* Khai báo cấu trúc cây Đỏ-Đen */
struct BRTree
{
	BRTNode* Root;
};
//==================================================
BRTNode* createBRTNode(TTP x);
void set_Color(int colorBackground, int colorText);
void showBRTNode(BRTNode* p);
void initBRTree(BRTree& brt);

void swapColors(EColor& color1, EColor& color2);
void swapInfos(TTP& info1, TTP& info2);

void showBRTree_PreOrder(BRTNode* root);
void showBRTree_InOrder(BRTNode* root);
void showBRTree_PostOrder(BRTNode* root);
void traverseNRL(BRTNode* root);
void traverseRNL(BRTNode* root);
void traverseRLN(BRTNode* root);


void levelOrder(BRTNode* root);
void showLevelOrder(BRTNode* root);

void iterativePreOrder(BRTNode* root);
void showPreOrder(BRTNode* root);
void iterativeInOrder(BRTNode* root);
void showInOrder(BRTNode* root);
void iterativePostOrder(BRTNode* root);
void showPostOrder(BRTNode* root);

BRTNode* BRTInsert(BRTNode* root, BRTNode* pNew, int& flag);
void rotateLeft(BRTNode*& root, BRTNode*& p);
void rotateRight(BRTNode*& root, BRTNode*& p);
void fixViolation(BRTNode*& root, BRTNode*& p);
void insert(BRTNode*& root, TTP Info);

bool isOnLeft(BRTNode* p);
bool hasRedChild(BRTNode* p);
BRTNode* findUncle(BRTNode* p);
BRTNode* findSibling(BRTNode* p);
BRTNode* findSuccessor(BRTNode* p);

void fixDoubleBlack(BRTNode*& root, BRTNode* p);
BRTNode* BSTReplace(BRTNode* p);
void deleteNode(BRTNode*& root, BRTNode* pDelete);

void createBSTreeStruct(BRTree& brt);

BRTNode* search(BRTNode* root, char x[]);

void showBRTNodeSearch(BRTNode* p);

void deleteByInfo(BRTNode*& root, char x[]);

//BRTNode* searchTC(BRTNode* root, int x);
void traverseRNL_loaiHP(BRTNode* root, char x[]);

void showBRTNode_loaiHP(BRTNode* p);
void showBRTree_PostOrder_loaiHP(BRTNode* root, char x[]);

//void deleteByInfo_TC(BRTNode*& root, int x);
//void createBRTreeFromArray(BRTree &brt, ItemType a[], int na);
//int DemSoNutDo(BRTNode *root);
//int DemSoNutDen(BRTNode *root);`	
#endif
