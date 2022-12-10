/*
	Nhóm 3
	Thành viên
	Hà Phú Quý
	Lê Huu Ðán
	Lê Nhat Minh
	Pham Ho Ðang Huy
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<queue>
#include<stack>
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
void docFile(BTree& bt, char fileName[])
{
	FILE* fp = fopen(fileName, "rt");
	if (fp == NULL)
	{
		printf("\nLoi doc file!");
		return;
	}
	int x;
	TNode* p;
	while (fscanf(fp, "%d ", &x) == 1)
	{
		TNode* p = CreateTNode(x);
		InsertTNode(bt.Root, p);
	}
	fclose(fp);
}
void docFile1(BTree &bt, char fileName[])
{
	FILE *f = fopen(fileName, "r+");
	if (f == NULL)
	{
		printf("\nLoi doc file!");
		return;
	}
	int x;
	//SNode *p;
	while (!feof(f))
	{
		fscanf(f, "%d ", &x);
		TNode* p = CreateTNode(x);
		InsertTNode(bt.Root,p);
	}
	fclose(f);
}
int soAm(int n) {
	int flag = 0;
	if (n < 0) flag = -1;
	return flag;
}
int soDuong(int n) {
	int flag = 0;
	if (n > 0) flag = 1;
	else if (n < 0) flag = -1;
	return flag;
}
int SumAm(TNode* root)
{
	int KQ = 0;
	if (!root)
		return 0;
	else{
		if (root->Info < 0)
			KQ += root->Info;
		KQ += SumAm(root->Left);
		KQ += SumAm(root->Right);
	}
	return KQ;
}
int countA(TNode* root)
{
	int KQ = 0;
	if (!root)
		return 0;
	else
	{
		if (soAm(root->Info))
			KQ++;
		KQ += countA(root->Left);
		KQ += countA(root->Right);
	}
	return KQ;

}
int countD(TNode* root)
{
	int KQ = 0;
	if (!root)
		return 0;
	else{
		if (soDuong(root->Info))
			KQ++;
		KQ += countD(root->Left);
		KQ += countD(root->Right);
	}
	return KQ;

}
int SNT(int x)
{
	for (int i = 2; i < x / 2; i++)
		if (x % i == 0)
			return 0;
	return 1;
}

void RNL(TNode* root)
{
	if (root == NULL) return;
	RNL(root->Right);
	printf("%4d", root->Info);
	RNL(root->Left);
}
void TnodeLa(TNode* root, int x)
{
	if (root == NULL)
	{
		return;
	}

	if (root->Left == NULL && root->Right == NULL && root->Info > x)
		printf("%4d", root->Info);
	TnodeLa(root->Left, x);
	TnodeLa(root->Right, x);

}
int treeLevel(TNode* t) {
	if (t == NULL) return -1;
	return 1 + max(treeLevel(t->Left), treeLevel(t->Right));
}
bool checkAvl(TNode* t) {
	if (t == NULL) 	return true;
	if (abs(treeLevel(t->Left) - treeLevel(t->Right)) > 1) return false;
	return checkAvl(t->Left) && checkAvl(t->Right);
}
void XuatKqKiemTra(TNode* c)
{
	int Kt = checkAvl(c);
	if (Kt == 0)
		printf("\nla cay nhi phan tim kiem\n");
	else
		printf("\nko phai cay nhi phan tim kiem\n");
}
int Tinh(TNode* c)
{
	if (c != NULL)
	{
		int a = Tinh(c->Left);
		int b = Tinh(c->Right);
		if (c->Left != NULL && c->Right != NULL)
			return c->Info + a + b;
		return a + b;
	}
	return 0;
}
int Hightree(TNode* root)
{
	if (root == NULL)
		return 0;
	int hl = Hightree(root->Left);
	int hr = Hightree(root->Right);
	if (hl > hr)
		return (hl + 1);
	else
		return (hr + 1);
}
int wtree(TNode* root)
{
	if (root == NULL)
		return 0;
	int hl = wtree(root->Right);
	int hr = wtree(root->Left);
	if (hr < hl)
		return (hr + 1);
	else
		return (hl + 1);
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
void ShowTNodeOfLevelK(TNode* root, int k)
{
	if (!root)
		return;
	if (k == 0) 
		printf("%4d", root->Info);
	k--; 
	ShowTNodeOfLevelK(root->Left, k); 
	ShowTNodeOfLevelK(root->Right, k);
}
void ShowTNodeIsLeafOfLevelK(TNode* root, int k)
{
	if (!root)
		return;
	if (k == 0 && !root->Left && !root->Right) 
		printf("%4d", root->Info);
	k--; 
	ShowTNodeIsLeafOfLevelK(root->Left, k); 
	ShowTNodeIsLeafOfLevelK(root->Right, k);
}
void ShowTNodeOneChildOfLevelK(TNode* root, int k)
{
	if (!root)
		return;
	if (k == 0 && ((!root->Left && root->Right) || (root->Left && !root->Right))) 
		printf("%4d", root->Info);
	k--; 
	ShowTNodeOneChildOfLevelK(root->Left, k); 
	ShowTNodeOneChildOfLevelK(root->Right, k);
}
int GetNodeNum(TNode* root)
{ 
	if (root == NULL)
		return 0;
	return 1 + GetNodeNum(root->Left) + GetNodeNum(root->Right);
}
int countSNT(TNode* root)
{
	int KQ = 0;
	if (!root)
		return 0;
	else
	{
		if (SNT(root->Info))
			KQ++;
		KQ += countSNT(root->Left);
		KQ += countSNT(root->Right);
	}
	return KQ;

}
int countTNodeNhoX(TNode* root, int x)
{
	int n;
	if (root == NULL)
		return 0;
	if (root->Info < x)
		n = 1 + GetNodeNum(root->Left) + countTNodeNhoX(root->Right, x);
	else
		n = countTNodeNhoX(root->Left, x);
	return n;
}
int demLa(TNode* T)
{
	if (T == NULL) return 0;
	else
		if (T->Left == NULL && T->Right == NULL) return 1;
		else return demLa(T->Left) + demLa(T->Right);
}
int minDistance(TNode* root, int x)
{
	if (!root)
		return -1;
	int min = root->Info;
	int mindis = abs(x - min);
	while (root != NULL)
	{
		if (root->Info == x)
			return x;
		if (mindis > abs(x - root->Info))
		{
			min = root->Info;
			mindis = abs(x - min);
		}
		if (x > root->Info)
			root = root->Right;
		else
			root = root->Left;
	}
	return min;
}
int maxDistance(TNode* root, int x)
{
	if (!root)
		return -1;
	TNode* minleft = root;
	while (minleft->Left != NULL)
		minleft = minleft->Left;
	TNode* maxRight = root;
	while (maxRight->Right != NULL)
		maxRight = maxRight->Right;
	int dis1 = abs(x - minleft->Info);
	int dis2 = abs(x - maxRight->Info);
	if (dis1 > dis2)
		return minleft->Info;
	else
		return maxRight->Info;
}
void LNR(TNode* root)
{
	if (root == NULL)
		return;
	LNR(root->Left);
	printf("%4d", root->Info);
	LNR(root->Right);
}
void BreadthNLR(TNode *root) // chiều rộng của cây
{
	if(root==NULL)
		return;
	queue <TNode *> q;
	q.push(root);
	while(!q.empty())
	{
		TNode *p;
		p=q.front();
		q.pop();
		ShowTNode(p);
		if(p->Left!=NULL)
			q.push(p->Left);
		if(p->Right!=NULL)
			q.push(p->Right);
	}
}
void DepthLNR(TNode *root)
{
	if(root==NULL)
		return;
	stack <TNode *>s;
	s.push(root);
	/*while(!s.empty())
	{
		if(root->Right!=NULL)
			s.push(root->Right);
		
		ShowTNode(s.top());
		s.pop();
		//Ä‘áº©yco phai3va2o stack trÆ°á»›c Ä‘á»ƒbÃªn trÃ¡i Ä‘Æ°á»£c xá»­ lÃ½ trÆ°á»›c
		
		if(root->Left!=NULL)
			s.push(root->Left);
	}*/
	while(!s.empty()||root!=NULL)
	{
		if(root!=NULL)
		{
			s.push(root);
			root=root->Left;
		}
		else
		{
			TNode *p;
			p=s.top();
			s.pop();
			ShowTNode(p);
			root=root->Right;
		}
	}
}
void DepthNLR(TNode *root)	// chiều cao của cây
{
	if(root==NULL)
		return;
	stack <TNode *>s;
	s.push(root);
	while(!s.empty())
	{
		TNode *p;
		p=s.top();
		s.pop();
		ShowTNode(p);
		//Ä‘áº©yco phai3va2o stack trÆ°á»›c Ä‘á»ƒbÃªn trÃ¡i Ä‘Æ°á»£c xá»­ lÃ½ trÆ°á»›c
		if(p->Right!=NULL)
			s.push(p->Right);
		if(p->Left!=NULL)
			s.push(p->Left);
	}
}

void Menu()
{
	cout << "---------------MENU--------------\n";
	cout << "1. doc FILE.\n";
	cout << "2. Tim kiem x.\n";
	cout << "3. xoa mot pt co gia tri x.\n";
	cout << "4. xuat cac pt trong cay theo thu tu tang dan.\n";
	cout << "5. tim pt co khoang cach toi x nho nhat.\n";
	cout << "6. dem xem co bao nhieu nut nho hon x va co muc k .\n";
	cout << "7. tinh tong nut 2 cay con.\n";
	cout << "8. kiem tra cay nhi phan tim kiem.\n";
	cout << "9. tinh chieu sau va chieu rong cua cay.\n";
	cout << "10. Dem cac node co gia tri la snt\n";
	cout << "11. Dem cac node Am - Duong: \n";
	cout << "---------------------------------\n";
}
void Process()
{
	int Chon;

	BTree bt;
	TNode* p, * q, * t = NULL;

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
		case 1:
			docFile1(bt, "data.txt");
			break;
		case 2:
			cout << "nhap gia tri can tim: ";
			cin >> x;
			q = FindTNode(bt.Root, x);
			if (q != NULL)
				cout << "tim thay nut: " << x << endl;
			else
				cout << "khong tim thay" << endl;

			break;
		case 3:
			cout << "Nhap nut can xoa: ";
			cin >> x;
			if (DeleteTNodeX(bt.Root, x))
				cout << "Xoa thanh cong  ";
			else
				cout << "khong thanh cong";
			cout << endl;
			break;
		case 4:
			cout << "Xuat theo chieu tang dan:";
			LNR(bt.Root);
			cout << "\n";

			break;
		case 5:
			n = minDistance(bt.Root, 50);
			cout << "phan tu gan x nhat: " << n << endl;
			n = maxDistance(bt.Root, 50);
			cout << "phan tu gan x nhat: " << n << endl;
			cout << "\n";
			break;
		case 6:
			n = countTNodeNhoX(bt.Root, 30);
			cout << "so nut nho ho x= " << n << endl;
			cout << "\nNut mot con o muc k: ";
			ShowTNodeOneChildOfLevelK(bt.Root, 2);
			cout << "\nNut o muc k: ";
			ShowTNodeOfLevelK(bt.Root, 2);
			cout << endl;
			break;
		case 7:
			cout << "so nut la cua cay: " << demLa(bt.Root) << endl;
			cout << "\n";
			break;
		case 8:
			XuatKqKiemTra(t);
			cout << "\n";
			break;
		case 9:
			cout << "Chieu cao cay: " ;
			DepthNLR(bt.Root);
			cout << "\nChieu rong cay: " ;
			BreadthNLR(bt.Root);
			cout << "\n";
			break;
		case 10:
			cout << "So nut SNT: " << countSNT(bt.Root) << endl;
			cout << "\n";
			break;
		case 11:
			cout << "So nut Am: " << countA(bt.Root) << endl;
			cout << "So nut Duong: " << countD(bt.Root) << endl;
			cout << "\n";
			break;

		}
	} while (Chon != 0);
}
int main()
{
	Process();
}
