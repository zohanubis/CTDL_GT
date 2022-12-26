//Binary search tree
#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include "stdlib.h"
#include "iostream"
#include "queue" 
using namespace std;
struct TNode
{
	int info;
	TNode* left;
	TNode* right;
};
struct BTree
{
	TNode* root;
};
void menu();
TNode* createTNode(int x);
void init(BTree& t);
int insertTNode(TNode* &root, TNode* p);
int isEmpty(BTree t);
void inputTree(TNode*& root);
void showTNode(TNode *p);
void NLR(TNode* root);  
void NRL(TNode* root);
void LRN(TNode* root);
int countNutLa(TNode* t);
int countTNodeduong(TNode* t);
int countTNodeam(TNode* t);
TNode* findTNodeReplace(TNode*& p);
int deleteTNodeX(TNode*& root, int x);
void readFile(TNode*& root,const char* filename);
int main()
{
	BTree t;
	init(t);
	int x,k,s,e;
	int chon = 1;;
	TNode* p;
	while (chon!=0)
	{
		menu();
		printf("Nhap lua chon : ");
		scanf("%d", &chon);
		switch (chon)
		{
		case 1:
			readFile(t.root, "tree.txt");
			break;
		case 2:
			printf("\nCay nhi phan xuat theo NLR:\n");
			NLR(t.root);
			printf("\nCay nhi phan xuat theo NRL:\n");
			NRL(t.root);
			printf("\nCay nhi phan xuat theo LRN:\n");
			LRN(t.root);


			break;
		case 3:
			printf("So nut la trong cay la % d \n", countNutLa(t.root));
			break;
		case 4:
			printf("So node duong la %d\n",countTNodeduong(t.root));
			printf("So node am la %d\n",countTNodeam(t.root));
			break;
		case 5:
			printf("Nhap nut can them\n");
			scanf("%d",&s);
			p = createTNode(s);
			insertTNode(t.root,p);

			break;
		case 6:
			printf("Nhap nut can xoa\n");
			scanf("%d",&e);
			deleteTNodeX(t.root,e);
			break;
		default:printf("ERROR\n");
			break;
		}
	}
	
	return 0;
}
void menu()
{
	printf("\n--------------------Binary search tree-----------------\n");
	printf("0.Thoat\n");
	printf("1.Nhap cay nhi phan\n");
	printf("2.xuat cay nhi phan\n");
	printf("3.dem nut la tree\n");
	printf("4.Dem so nut am duong cay\n");
	printf("5.chen node tren cay\n");
	printf("6.xoa node tren cay\n");
}
void readFile(TNode*& root,const char* filename)
{
	FILE* fp = fopen(filename, "rt");
	if (fp)
	{
		int x;
		while (fscanf(fp,"%d",&x)==1)
		{
			insertTNode(root, createTNode(x));
		}
		fclose(fp);
	}
}
TNode* createTNode(int x)
{
	TNode* p = new TNode;
	if (p == NULL)
		return 0;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}
void init(BTree& t)
{
	t.root = NULL;
}
int isEmpty(BTree t)
{
	if (t.root == NULL)
		return 1;
	else
		return 0;

}
int insertTNode(TNode*&root , TNode *p)
{
	if (root != NULL)
	{
		if (root->info == p->info)
			return 0;
		if (root->info > p->info)
			return insertTNode(root->left, p);
		else
			return insertTNode(root->right, p);

	}
	else
		root = p;
		
}
void inputTree(TNode*& root)
{
	int n;
	printf("Nhap so luong node : ");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		printf("Nhap du lieu cua node %d: ", i);
		scanf("%d", &x);
		TNode* p = createTNode(x);
		insertTNode(root, p);
	}
}
void showTNode(TNode *p)
{
	printf("%d ", p ->info);
}
void NLR(TNode* root)
{
	if (root == NULL)
		return;
	printf("%4d", root->info);
	NLR(root->left);
	NLR(root->right);
}
void NRL(TNode* root)
{
	if (root == NULL)
		return;
	printf("%4d", root->info);
	NRL(root->right);
	NRL(root->left);
}
void LRN(TNode* root)
{
	if (root == NULL)
		return;
	LRN(root->left);
	LRN(root->right);
	printf("%4d", root->info);

}
int countTNodeduong(TNode* t)
{
	if (t == NULL)
		return 0;
	int a = countTNodeduong(t->left);
	int b = countTNodeduong(t->right);
	if(t->info>0)
		return a + b + 1;
	return a + b;
}
int countTNodeam(TNode* t){
	if (t == NULL)
		return 0;
	int a = countTNodeam(t->left);
	int b = countTNodeam(t->right);
	if(t->info < 0)
		return a + b + 1;
	return a + b;
}
int countNutLa(TNode* t)
{
	if (t == NULL)
		return 0;
	int a = countNutLa(t->left);
	int b = countNutLa(t->right);
	if (!t->left&&!t->right)
		return a + b + 1;
	return a + b;
}

TNode* findTNodeReplace(TNode*& p)
{
	TNode* f = p;
	TNode* q = p->right;
	while (q->left!=NULL)
	{
		f = q;
		q = q->left;
	}
	p->info = q->info;
	if (p == q)
		f->right = q->right;
	else
		f->left = q->right;
	return q;
}
int deleteTNodeX(TNode* &root, int x)
{
	if (root == NULL)
		return 0;
	if (root->info > x)
		return deleteTNodeX(root->left, x);
	else
	{
		if (root->info < x)
		{
			return deleteTNodeX(root->right, x);
		}
		else
		{
			TNode* p = root;
			if (root->left == NULL)
			{
				root = root->right;
				delete p;
			}
			else
				if (root->right == NULL)
			{
				root = root->left;
				delete p;
			}
			else
			{
				TNode* q = findTNodeReplace(p);
				delete p;
			}
		}
	}
}

	
