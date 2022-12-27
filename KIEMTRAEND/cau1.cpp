#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include<stdlib.h>
#include "math.h"
#include "conio.h"
#include <iostream>
using namespace std;
struct TNode
{
	int Info;
	TNode* Left;
	TNode* Right;
};
struct BTree
{
	TNode* Root;
};
TNode* CreateTNode(int x)
{
	TNode* p = new TNode;
	if (p == NULL)
	{
		printf("khong du bo nho de cap phat");
		return NULL;
	}
	p->Info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}
void ShowTNode(TNode* T);
void DeleteTNode(TNode*& p);
TNode* FindTNodeTheMangLeft(TNode*& p);
void InitBTree(BTree& bt);
void InsertTNode(TNode*& root, TNode* p);
void docFile1(BTree &bt, char fileName[]);
void RNL(TNode* root);
void RNL1(TNode* root);
TNode* FindTNode(TNode* root, int x);
int DeleteTNodeX(TNode*& root, int x);
void LNR(TNode* root);
bool SoChinhPhuong(int n);
int DemCP(TNode *root);
int TongNutMuck(TNode *root, int k);
void nut2ConGiam(TNode *root);
int nut2Con(TNode *p);
void menu();
void ShowTNode(TNode* T)
{
	printf("%d", T->Info);
}
void DeleteTNode(TNode*& p)
{
	if (p == NULL)
		return;
	delete p;
}
TNode* FindTNodeTheMangLeft(TNode*& p)
{
	TNode* f = p;
	TNode* q = p->Left;
	while (q->Right != NULL)
	{
		f = q;
		q = q->Right;
	}
	p->Info = q->Info;
	if (f == p)
		f->Left = q->Left;
	else
		f->Right = q->Left;
	return q;
}
void InitBTree(BTree& bt)
{
	bt.Root = NULL;
}

void InsertTNode(TNode*& root, TNode* p)
{
	if (p == NULL)
		return;
	if (root == NULL)
	{
		root = p;
		return;
	}
	if (root->Info == p->Info)
		return;
	if (p->Info < root->Info)
		InsertTNode(root->Left, p);
	else
		InsertTNode(root->Right, p);
}

void docFile1(BTree &bt, char fileName[])
{
	FILE *f = fopen(fileName, "rt");
	if (f == NULL)
	{
		printf("\nLoi doc file!");
		return;
	}
	int x;
	TNode *p;
	while (fscanf(f, "%d", &x) == 1)
	{
		TNode* p = CreateTNode(x);
		InsertTNode(bt.Root, p);
	}
	fclose(f);
}

void RNL(TNode* root)
{
	if (root == NULL) return;
	RNL(root->Right);
	printf("%4d", root->Info);
	RNL(root->Left);
}
void RNL1(TNode* root)
{
	if (root == NULL) return;
	printf("%4d", root->Info);
	RNL(root->Left);
}

int TinhTong(TNode* c)
{
	if (c != NULL)
	{
		int a = TinhTong(c->Left);
		int b = TinhTong(c->Right);
		if (c->Left != NULL && c->Right != NULL)
			return c->Info + a + b;
		return a + b;
	}
	return 0;
}
TNode* FindTNode(TNode* root, int x)
{
	if (!root)
		return NULL;
	if (root->Info == x)
		return root;
	else if (root->Info > x)
		return FindTNode(root->Left, x);
	else
		return FindTNode(root->Right, x);
}
int DeleteTNodeX(TNode*& root, int x)
{
	if (root == NULL)
		return 0;
	if (root->Info > x)
		return DeleteTNodeX(root->Left, x);
	else if (root->Info < x)
		return DeleteTNodeX(root->Right, x);
	else
	{
		TNode* p = root;
		if (root->Left == NULL)
		{
			root = root->Right;
			delete p;
		}
		else if (root->Right == NULL)
		{
			root = root->Left;
			delete p;
		}
		else
		{
			TNode* q = FindTNodeTheMangLeft(p);
			delete q;
		}
		return 1;
	}
}

void LNR(TNode* root)
{
	if (root == NULL)
		return;
	LNR(root->Left);
	printf("%4d", root->Info);
	LNR(root->Right);
}
bool SoChinhPhuong(int n)
{
	if (n <= 0)
		return 0;
	int s = sqrt((double)n);
	if (s*s == n)
		return 1;
	return 0;
}
int DemCP(TNode *root)
{

	int count = 0;
	if (!root){
		return 0;
	}
	int a = DemCP(root->Left);
	int b = DemCP(root->Right);
	if (SoChinhPhuong(root->Info)){
		return a + b + 1;
		
	}
	return a + b;
}
	int TongNutMuck(TNode *root, int k)
	{
	if (!root)
		return 0;
	if (k == 0)
		return root->Info;
	k--;
	int nl = TongNutMuck(root->Left, k);
	int nr = TongNutMuck(root->Right, k);
	return nl + nr;
}
void nut2ConGiam(TNode *root){
	if (!root)
		return; 
	else{
		nut2ConGiam(root->Right);
		nut2ConGiam(root->Left);
		if (root->Left != NULL && root->Right != NULL){
			printf(" %d", root->Info);
		}
	}
}
int nut2Con(TNode *p)
{
	int a = nut2Con(p->Left);
	int b = nut2Con(p->Right);
	if (p) return 0;
	if (p->Left != NULL && p->Left != NULL){
		return 1 + a + b;
	}
	return a + b;
}
void Menu()
{
	printf("\nCau 1 : Doc file ");
	printf("\nCau 2 : In ra cac nut cay theo thu tu tang dan");
	printf("\nCau 3 : Tim phan tu tren cay");
	printf("\nCau 4 : In theo nut 2 con giam dan");
	printf("\nCau 5 : Dem cac node chinh phuong");
	printf("\nCau 6 : Tinh tong cac nut muc k");
	printf("\nCau 7 : Xoa nut co gia tri x ");
	printf("\n");
	
}
int main()
{
	int Chon;
	TNode root;
	BTree bt;
	TNode* p, *q, *t = NULL;

	int n, x;
	bt.Root = NULL;
	do
	{
		Menu();
		do
		{
			printf("\nBan hay chon mot chuc nang (0->10): ");
			scanf("%d", &Chon);
		} while (Chon < 0 || Chon > 14);
		switch (Chon)
		{
		case 1:{
			docFile1(bt, "data.txt");
			break;
		}
		
		case 2:
		{
				  printf("Xuat con theo chieu tang dan: ");
				  LNR(bt.Root);
				  printf("\n");
				  break;
		}
		case 3:{
				   int x;
				   printf("Nhap gia tri x can tim  :"); scanf("%d", &x);
				   q = FindTNode(bt.Root, x);
				   if (q != NULL)
					   printf("Tim thay ");
				   else
					   printf("Khong tim thay");

				   break;
		}
		case 4:{
				   nut2ConGiam(bt.Root);
				   printf("\n");
				   break;
		}
		case 5:
		{
				  int kq = DemCP(bt.Root);
				  printf("So luong nut la so chinh phuong : %d", kq);
				  break;
		}
		case 6:
		{
				  int k;
				  printf("Nhap k : "); scanf("%d", &k);
				  int kq = TongNutMuck(bt.Root, k);
				  printf("Tong nut o muc %d : %d", k,kq);
				  break;
		}
		case 7:
			int x;
			printf("Nhap nut can xoa : ");
			scanf("%d", &x);
			if (DeleteTNodeX(bt.Root, x))
				printf("Xoa thanh cong ");
			else
				printf("Xoa khong thanh cong ");
			break;
		
		}
	} while (Chon != 0);
	getch();
}

