#include <conio.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <Windows.h>
using namespace std;


struct TTP
{
	char maMH[11];
	char tenMH[31];
	int soTC;
	char loaiHP[21];
};

enum EColor { RED, BLACK };


struct BRTNode
{
	TTP Info;
	EColor Color;
	BRTNode* Left, *Right, *Parent;
};

struct BRTree
{
	BRTNode* Root;
};
BRTNode* createBRTNode(TTP x);
void showBRTNode(BRTNode* p);
void initBRTree(BRTree& brt);
void swapColors(EColor& color1, EColor& color2);
void set_Color(int colorBackground, int colorText);
BRTNode* BRTInsert(BRTNode* root, BRTNode* p, int& flag);
void showLoaiHP(BRTNode* root, char x[]);
void showBRTNode_loaiHP(BRTNode* p);
void xoayTrai(BRTNode*& root, BRTNode*& p);
void xoayPhai(BRTNode*& root, BRTNode*& p);
/*----------------------------------------------------------*/
BRTNode* createBRTNode(TTP x)
{
	BRTNode* p = new BRTNode;
	if (p == NULL)
	{
		printf("\nKhong the cap phat nut moi!");
		_getch();
		return NULL;
	}
	p->Info = x;		
	p->Color = RED;	
	p->Left = NULL;		
	p->Right = NULL;	
	p->Parent = NULL;	
	return p;
}
void set_Color(int colorBackground, int colorText) {
	HANDLE hColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hColor, colorBackground * 16 + colorText);
}
void initBRTree(BRTree& brt)
{
	brt.Root = NULL;
}
BRTNode* BRTInsert(BRTNode* root, BRTNode* pNew, int& flag)
{
	if (root == NULL)
	{
		root = pNew;
		flag = 1;
		return pNew;
	}

	if (strcmp(pNew->Info.maMH, root->Info.maMH) < 0)
	{
		root->Left = BRTInsert(root->Left, pNew, flag);
		root->Left->Parent = root;
	}
	else if (strcmp(pNew->Info.maMH, root->Info.maMH) > 0)
	{
		root->Right = BRTInsert(root->Right, pNew, flag);
		root->Right->Parent = root;
	}
	else
		flag = 0;
	return root;
}
void createBSTreeStruct(BRTree& brt)
{
	int n;
	TTP x;
	FILE* f = fopen("mon.txt", "rt");
	if (f == NULL)
		printf("Khong doc duoc");
	fscanf(f, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%[^\n]\n%[^\n]\n%d\n%[^\n]\n", &x.maMH, &x.tenMH, &x.soTC, &x.loaiHP);
		/*insert(brt.Root, x);*/
		set_Color(14, 2);

		getch();
	}
}
void showBRTNode_loaiHP(BRTNode* p)
{
	if (p->Color == RED)
		set_Color(15, 12);
	else if (p->Color == BLACK)
		set_Color(15, 0);
	_cprintf("%s\t%s\t%d\t%s\n", p->Info.maMH, p->Info.tenMH, p->Info.soTC, p->Info.loaiHP);
	set_Color(14, 2);
}
void showLoaiHP(BRTNode* root, char x[])
{
	if (root == NULL) return;

	showLoaiHP(root->Left, x);
	showLoaiHP(root->Right, x);
	if (strcmp(x, root->Info.loaiHP) == 0)
	{
		printf("\n");
		showBRTNode_loaiHP(root);
	}
}
BRTNode* BRTInsert(BRTNode* root, BRTNode* p, int& flag)
{
	if (root == NULL)
	{
		root = p;
		flag = 1;
		return p;
	}
	if (strcmp(p->Info.maMH, root->Info.maMH) < 0)
	{
		root->Left = BRTInsert(root->Left, p, flag);
		root->Left->Parent = root;
	}
	else if (strcmp(p->Info.maMH, root->Info.maMH) > 0)
	{
		root->Right = BRTInsert(root->Right, p, flag);
		root->Right->Parent = root;
	}
	else
		flag = 0;
	return root;
}
void xoayTrai(BRTNode*& root, BRTNode*& p)
{
	BRTNode* pRight = p->Right;

	p->Right = pRight->Left;
	if (p->Right != NULL)
		p->Right->Parent = p;

	pRight->Parent = p->Parent;

	if (p->Parent == NULL)
		root = pRight;

	else if (p == p->Parent->Left)
		p->Parent->Left = pRight;

	else
		p->Parent->Right = pRight;

	pRight->Left = p;
	p->Parent = pRight;
}

void xoayPhai(BRTNode*& root, BRTNode*& p)
{
	BRTNode* pLeft = p->Left;

	p->Left = pLeft->Right;

	if (p->Left != NULL)
		p->Left->Parent = p;

	pLeft->Parent = p->Parent;

	if (p->Parent == NULL)
		root = pLeft;

	else if (p == p->Parent->Left)
		p->Parent->Left = pLeft;

	else
		p->Parent->Right = pLeft;

	pLeft->Right = p;
	p->Parent = pLeft;
}

BRTNode* search(BRTNode* root, char x[]) {
	BRTNode* temp = root;
	while (temp != NULL) {
		if (strcmp(x, temp->Info.maMH) == 0) {
			return temp;
		}
		else if (strcmp(x, temp->Info.maMH) < 0) {
			temp = temp->Left;
		}
		else {
			temp = temp->Right;
		}
	}

	return NULL; 
}
//void deleteByInfo_TC(BRTNode*& root, int x) {
//		 BRTree là rỗng 
//		if (root == NULL) return;
//	
//		/*BRTNode* delete_pt = search(root, x);*/
//	
//		if (delete_pt == NULL) {
//			printf("\nKhong tim thay nut nao de xoa voi gia tri: %d", x);
//			return;
//		}
//	
//		/*deleteNode(root, delete_pt);*/
//	}
void showBRTree_PostOrder_loaiHP(BRTNode* root, char x[])
{
	if (root == NULL) return;

	showBRTree_PostOrder_loaiHP(root->Left, x);
	showBRTree_PostOrder_loaiHP(root->Right, x);
	if (strcmp(x, root->Info.loaiHP) == 0)
	{
		printf("\n");
		showBRTNode_loaiHP(root);
	}
}
void traverseRNL_loaiHP(BRTNode* root, char x[])
{
	if (root == NULL) return;

	showBRTree_PostOrder_loaiHP(root->Right, x);
	if (strcmp(x, root->Info.loaiHP) == 0)
	{
		printf("\n");
		showBRTNode_loaiHP(root);
	}
	showBRTree_PostOrder_loaiHP(root->Left, x);
}
int main()
{
	int luachon;
	do
	{
		do
		{
			printf("\n");
			printf("1. Tao cay(doc tu file)\n");
			printf("3. In cac mon hoc Ly thuyet\n");
			printf("0. Ket thuc chuong trinh\n");
			printf("Nhap lua chon cua ban: ");
			scanf_s("%d", &luachon);
		} while (luachon < 0);

		switch (luachon)
		{
		case 1:
		{
				  BRTree brtree;
				  initBRTree(brtree);
				  createBSTreeStruct(brtree);
				  break;
		}

		

		case 3:
		{
				  BRTree brtree;
				  char x[31] = "Ly thuyet";
				  initBRTree(brtree);
				  createBSTreeStruct(brtree);
				  traverseRNL_loaiHP(brtree.Root, x);
				  break;
		}

		default:
			break;
		}
	} while (luachon > 0 && luachon <= 3);
}