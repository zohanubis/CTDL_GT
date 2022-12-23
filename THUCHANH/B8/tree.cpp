#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<Windows.h>
#include<queue>

using namespace std;
struct MonHoc{
	char maMH[20];
	char tenMH[40];
	int soTC;
	char HocPhan[20];
};
enum EColor { RED, BLACK };
struct BTNode
{
	MonHoc Info;
	EColor Color;
	BTNode* Left, * Right, * Parent;
};
//typedef BTNode* BTree;
struct BTree
{
	BTNode* Root;
};
int compare(MonHoc x, MonHoc y)
{
	return strcmp(x.maMH, y.maMH);
}
BTNode* CreateTNode(MonHoc x)
{
	BTNode* p = new BTNode;
	if (p == NULL)
	{
		cout << "Khong the cap phat";
		return NULL;
	}
	p->Info = x;
	p->Color = RED;
	p->Left = NULL;
	p->Right = NULL;
	p->Parent = NULL;
	return p;
}
void setColor(int colorBackground, int colorText)
{
	HANDLE hColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hColor, colorBackground * 16 + colorText);
	/*	0 = Black       8 = Gray
		1 = Blue        9 = Light Blue
		2 = Green       A = Light Green
		3 = Aqua        B = Light Aqua
		4 = Red         C = Light Red
		5 = Purple      D = Light Purple
		6 = Yellow      E = Light Yellow
		7 = White       F = Bright White
		=> set_Color(X); -> X = a*16 + b, a (background) và b (character)
		*/
}
void ShowBTNode(BTNode* p)
{
	if (p->Color == RED)
		setColor(15, 12);
	else if (p->Color == BLACK)
		setColor(15, 0);
	printf("%4d", p->Info);
	setColor(0, 7);
}
int Insert(BTNode* tr,BTNode* root)
{
	if (tr->Info.maMH == root->Info.maMH) return 0;
	if (tr->Info.maMH > root->Info.maMH)
	{
		if (tr->Left == NULL)
			tr->Left = root;
		else {
			Insert(tr->Left, root);
		}
	}
	if (tr->Info.maMH < root->Info.maMH)
	{
		if (tr->Right == NULL)
			tr->Right = root;
		else {
			Insert(tr->Right, root);
		}
	}
	return 1;
}
	
void InitBTree(BTree& bt)
{
	bt.Root = NULL;
}
BTNode* BTInsert(BTNode* root, BTNode* pnew)
{
	if (root == NULL)
		return pnew;
	if (pnew->Info.maMH < root->Info.maMH)
	{
		root->Left = BTInsert(root->Left, pnew);
		root->Left->Parent = root;
	}
	else if (pnew->Info.maMH > root->Info.maMH)
	{
		root->Right = BTInsert(root->Right, pnew);
		root->Right->Parent = root;
	}
	return root;

}
//xoay nút trái
void RotateLeft(BTNode*& root, BTNode*& p)
{
	BTNode* pRight = p->Right;
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
//xoay phải
void RotateRight(BTNode*& root, BTNode*& p)
{
	BTNode* pLeft = p->Left;
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
//cấu trúc lại sự cân bằng khi nút bị vi phạm
void fixViolation(BTNode*& root, BTNode*& p)
{
	BTNode* pParent = NULL;
	BTNode* pGrandParent = NULL;
	while ((p != root) && (p->Color != BLACK) && (p->Parent->Color == RED))
	{
		pParent = p->Parent;
		pGrandParent = p->Parent->Parent;
		//trường hợp A: node cha của p là con trái của node cha của p
		if (pParent == pGrandParent->Left)
		{
			BTNode* pUncle = pGrandParent->Right;
			//trường hợp: 1 node chú của p là  node đỏkhi này chỉ cần đổi màu cho node đó thành đen
			if (pUncle != NULL && pUncle->Color == RED)
			{
				pGrandParent->Color = RED;
				pParent->Color = BLACK;
				pUncle->Color = BLACK;
				p = pGrandParent;
			}
			else
			{
				//trường hợp 2: p là nut con phải của nut cha nó, ta thực hiện  xoay trái
				if (p == pParent->Right)
				{
					RotateLeft(root, pParent);
					p = pParent;
					pParent = p->Parent;
				}
				//trường hợp 3: p là con trái của node cha nó, thực hiện xoay phải
				RotateRight(root, pGrandParent);
				
				p = pParent;
			}
		}
		//trường hợp B: node cha của p là con phải của node cha của node cha của p
		else
		{
			BTNode* pUncle = pGrandParent->Left;
			//trường hợp1: chú của p là node đỏ khi này chỉ cần đổi mau2cho node đó thành đen
			if (pUncle != NULL && pUncle->Color == RED)
			{
				pGrandParent->Color = RED;
				pParent->Color = BLACK;
				pUncle->Color = BLACK;
				p = pGrandParent;
			}
			else
			{
				//trường hợp 2: p là con trái của node  cha nó, thực hiện xoay phải
				if (p == pParent->Left)
				{
					RotateRight(root, pParent);
					p = pParent;
					pParent = p->Parent;
				}
				//trường hợp 3: p là node con phải cua3 nod cha nó, thực hiện xoay trái
				RotateLeft(root, pGrandParent);
				p = pParent;
			}
		}
	}
	root->Color = BLACK;
}
//thêm nút mới  với dữ liệu đã cho
void Insert(BTNode*& root, MonHoc x)
{
	BTNode* pnew = CreateTNode(x);
	//thực hiện chèn
	root = BTInsert(root, pnew);
	//sửa lỗi qui tắc cây đỏ đen
	fixViolation(root, pnew);
}

void xuat(MonHoc x)
{
	printf("%-10s%-20s%10d%10s\n", x.maMH, x.tenMH, x.soTC, x.HocPhan);
}
void doc1MH(FILE* fp, MonHoc& x)
{
	fscanf(fp, "%s%s%d%s", &x.maMH, &x.tenMH, &x.soTC, &x.HocPhan);
}

void taoDSTuFileText(BTree& bt,const char fileName[])
{
	FILE* f = fopen(fileName, "rt");
	if (f == NULL)
	{
		printf("\nLoi doc file!");
		return;
	}
	
	MonHoc x;
	//SNode *p;
	InitBTree(bt);
	fscanf(f, "%d", &x);
	while (!feof(f))
	{
		
		BTNode *p = CreateTNode(x);
		doc1MH(f, x);
		/*fscanf(f, "%s", &x.maMH);
		fscanf(f, "%s", &x.tenMH);
		fscanf(f, "%d", &x.soTC);
		fscanf(f, "%s", &x.HocPhan);*/
		Insert(bt.Root, x);
	}
	fclose(f);
}
void PreOrder(BTNode* p) {
	
	if (p == NULL) return; {

			PreOrder(p->Left);
			xuat(p->Info);
			//PreOrder(p->Right);
	}
	
}
void  BreadthNLR(BTNode* root)
{
	if (root == NULL)
		return;
	queue<BTNode*>q;
	q.push(root);
	while (!q.empty())
	{
		BTNode* p = q.front();
		q.pop();
		ShowBTNode(p);
		if (p->Left != NULL)
			q.push(p->Left);
		if (p->Right != NULL)
			q.push(p->Right);
	}

}
BTNode* Grandparent(BTNode* p)
{
	return p->Parent->Parent;
}

//kiểm tra nút con trái của cha
bool isOnLeft(BTNode* p)
{
	return p == p->Parent->Left;
}
//tìm nút chú của một nút
BTNode* findUncle(BTNode* p)
{
	if (p->Parent == NULL || p->Parent->Parent == NULL)
		return NULL;
	if (isOnLeft(p->Parent))
		//node chú phải
		return p->Parent->Parent->Right;
	else
		//node chú bên trái
		return p->Parent->Parent->Left;
}
BTNode* findSuccssor(BTNode* p) //Tìm nut thay the
{
	BTNode* tem = p;
	while (tem->Left != NULL)// == NULL dừng
		tem = tem->Left;
	return tem;
}
//kiểm tra nút hiện tại có nút con là nút đỏ không
bool hasRedChild(BTNode* p)
{
	return (p->Left != NULL && p->Left->Color == RED) || (p->Right != NULL && p->Right->Color == RED);
}
//tìm nút anh em 
BTNode* findSibling(BTNode* p)
{
	//node anh rỗng nếu không tồn tại node cha
	if (p->Parent == NULL)
		return NULL;
	if (isOnLeft(p))
		return p->Parent->Right;
	return p->Parent->Left;
}
BTNode* BTReplace(BTNode* p)
{
	//khi nut có 2 con
	if (p->Left != NULL && p->Right != NULL)
		return findSuccssor(p->Right);// trả về nút thay thế
	//khi nút lá
	if (p->Left == NULL && p->Right == NULL)
		return NULL;
	//khi nút có 1 con
	if (p->Left != NULL)
		return p->Left;
	else
		return p->Right;
}
void deleteNode(BTNode*& root, BTNode* pDelete)
{
	BTNode* pReplace = BTReplace(pDelete);//tìm nút thế mạng cho nút bị xóa
	//đúng khi pReplce(Thay thế) và pDelete(Xóa) đều đen
	bool flagDoubleBlack = ((pReplace == NULL || pReplace->Color == BLACK) && (pDelete->Color == BLACK));
	BTNode* pParent = pDelete->Parent;
	if (pReplace == NULL)
	{
		//pReplace là NULL do đó pDelete là lá
		if (pDelete == root)
		{
			//pDelete là root, làm cho root là NULL
			root = NULL;
		}
		else
		{
			if (flagDoubleBlack)
			{
				//pReplace và pDelete đều đen
				//pDelete là lá , sửa màu đen kép
			}
			else
			{
				//pReplace hoặc pDelete là đỏ
				if (findSibling(pDelete) != NULL)
					//node anh chị em không rỗng, làm cho nó màu đỏ
					findSibling(pDelete)->Color = RED;
			}
			//xóa delete khỏi cây
			if (isOnLeft(pDelete))
			{
				pParent->Left = NULL;
			}
			else
			{
				pParent->Right = NULL;
			}
		}
		delete pDelete;
		return;
	}
	if (pDelete->Left == NULL || pDelete->Right == NULL)
	{
		//pDelete có 1 con
		if (pDelete == root)
		{
			//gán giá trị cùa pReplace cho pDelete và xóa pReplace
			pDelete->Info = pReplace->Info;
			pDelete->Left = pDelete->Right = NULL;
			delete pReplace;
		}
		else
		{
			//tách node pDelete khỏi cây và di chuyển node pReplace lên
			if (isOnLeft(pDelete))
			{
				pParent->Left = pReplace;
			}
			else
			{
				pParent->Right = pReplace;
			}
			delete pDelete;
			pReplace->Parent = pParent;
			if (flagDoubleBlack)
			{
				//PReplace và pdelete đều đen sửa 2 màu đen ở Preplace
			}
			else
			{
				//pReplace hoặc pDelete đỏ, màu pReplace đen
				pReplace->Color = BLACK;
			}
		}
		return;
	}
	//pDelete có 2 con, hoán đổi giá trị với nút thế mạng và đệ qui
	deleteNode(root, pReplace);
}

bool isThoaDK(MonHoc x)
{
	return x.soTC < 2;
}
BTNode* delKey(BTNode* root)
{
	BTNode* P = root;

	if (P != NULL) {
		if (isThoaDK(root->Info)) {
			return P;	
			//deleteNode(root,P);
		}
		return delKey(root->Left);
		return delKey(root->Right);
	}
}
BTNode* timKiem(BTNode* root)
{
	char a[10] = "LT";
	BTNode* tem = root;
	while (tem != NULL)
	{
		if (strcmp(root->Info.HocPhan, a)==0 )
		{
			PreOrder(root->Left);
			
			xuat(root->Info);
			
			PreOrder(root->Right);
			return tem;
		}
		else if (strcmp(root->Info.HocPhan, a) > 0)
		{
			return timKiem(root->Left);
		}
		else
			return timKiem(root->Right);
	}
		
			
	return NULL;
}
BTNode* Search(BTNode* root,const char maMH[])
{
	BTNode* tem = root;
	while (tem != NULL)
	{
		if (strcmp(root->Info.maMH,maMH) == 0)
		{
			PreOrder(root->Left);
			
			PreOrder(root->Right);
			return tem;
		}
		else if (strcmp(root->Info.maMH,maMH) > 0)
		{
			//Search(root->Left, maMH);
			tem = tem->Left;
		}
		else
			//Search(root->Right, maMH);
			tem = tem->Right;
	}
	return NULL; 
}
void Menu()
{
	cout << "------------------MENU---------------------\n";
	cout << "1. doc du lieu tu file text.\n";
	cout << "2. In ra mon hoc ly thuyet\n";
	cout << "3. Tim Mon Hoc theo Ma\n";
	cout << "4. Xoa Mon Hoc co TC<2\n";
}

int main()
{
	BTree bt;
	BTNode* p;
	bt.Root = NULL;
	int x,n,Chon;
	MonHoc a;
	
	do
	{
		Menu();
		do
		{
			cout<<"\nBan hay chon mot chuc nang (1->4): "<<endl;
			cin >> Chon;
		} while (Chon < 0 || Chon > 20);
		switch (Chon)
		{
		case 1:
			taoDSTuFileText(bt, "Data.txt");
			PreOrder(bt.Root);
			cout << endl;
			break;
		case 2:
			timKiem(bt.Root);
			cout << endl;
			break;
		case 3:
			char maMH[50];
			//cin.ignore();
			//cout << "Nhap nut can tim: ";
			printf("Nhap nut can tim :");
			fflush(stdin);gets_s(maMH);
			p = Search(bt.Root,maMH);
			if (p != NULL)
			{
				cout << "----------Tim Thay Ma Mon Hoc " << maMH << "----------" << endl;
				cout << "Ma MH: " << p->Info.maMH << "\n";
				cout << "Ten MH: " << p->Info.tenMH << "\n";
				cout << "So TC: " << p->Info.soTC << "\n";
				cout << "Hoc Phan: " << p->Info.HocPhan << "\n";
			}
			else
			{
				cout << "Khong tim thay" << endl;


			}
			
			cout << endl;
			break;
		case 4:
			
			BTNode * node = delKey(bt.Root);
			cout << "sau khi xoa :\n";
			
			PreOrder(bt.Root);
			
			

			cout << endl;
			break;
		}
	} while (Chon != 0);
	
	
	
}
