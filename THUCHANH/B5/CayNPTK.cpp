#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include "VeCay.h"
using namespace std;

struct Node
{
	int info;
	Node* left;
	Node* right;
};
void init(Node*& root)
{
	root = NULL;
}
Node* createNode(int x)
{
	Node* p = new Node;
	if (p != NULL)
	{
		p->info = x;
		p->left = p->right = NULL;
	}
	return p;
}

void insert(Node*& root, int x)
{
	if (root == NULL)
		root = createNode(x);
	else
	{
		if (root->info == x) return;
		else if (x < root->info)
			insert(root->left, x);
		else
			insert(root->right, x);
	}
}

void readFile(Node*& root, char* fileName)
{
	FILE* fp = fopen(fileName, "rt");
	if (fp != NULL)
	{
		int x;
		while (fscanf(fp, "%d", &x) == 1)
		{
			insert(root, x);
		}

		fclose(fp);
	}
}

void LNR(Node* root)
{
	if (root != NULL)
	{
		LNR(root->left);
		printf("%3d ", root->info);
		LNR(root->right);
	}
}
void RNL(Node* root)
{
	if (root != NULL)
	{
		RNL(root->right);
		printf("%4d", root->info);
		RNL(root->left);
	}
}

bool isDoanA(int n, int a)
{
	return n >= a;
}

bool isDoanB(int n, int b)
{
	return n <= b;
}

bool isDoanX(int n, int x)
{
	return n > x;
}

int demNodeTrongDoanAB(Node* root,int a,int b)
{
	if (root == NULL) return 0;
	else
	{
		int d1 = demNodeTrongDoanAB(root->left,a,b);
		int d2 = demNodeTrongDoanAB(root->right,a,b);
		if (isDoanA(root->info, a) && isDoanB(root->info, b))
		{
			return 1 + d1 + d2;
		}
		else
			return d1 + d2;

	}
}


int demNodeHonXTrongDoanAB(Node* root, int x, int b)
{
	if (root == NULL) return 0;
	else
	{
		int d1 = demNodeHonXTrongDoanAB(root->left, x, b);
		int d2 = demNodeHonXTrongDoanAB(root->right, x, b);
		if (isDoanB(root->info, b)&& isDoanX(root->info, x))
		{
			return 1 + d1 + d2;
		}
		else
			return d1 + d2;
	}
}

int tongGTNodeDoanAB(Node* root,int a, int b)
{
	if (root == NULL) return 0;
	else
	{
		int d1 = tongGTNodeDoanAB(root->left,a,b);
		int d2 = tongGTNodeDoanAB(root->right,a,b);

		if (isDoanA(root->info,a)&& isDoanB(root->info, b))
			return root->info + d1 + d2; 
		else
			return d1 + d2;
	}
}

void xuatTrongDoanAB(Node* root, int a, int b)
{
	if (root != NULL)
	{
		xuatTrongDoanAB(root->left, a, b);
		xuatTrongDoanAB(root->right, a, b);
		if (isDoanA(root->info, a) && isDoanB(root->info, b))
		{

			printf("%4d", root->info);
		}
		
	}
}


void xuatTrongDoanABGiamDan(Node* root, int a, int b)
{
	if (root != NULL)
	{

		xuatTrongDoanABGiamDan(root->right, a, b);
		if (isDoanA(root->info, a) && isDoanB(root->info, b))
		{
			printf("%4d", root->info);
		}
		xuatTrongDoanABGiamDan(root->left, a, b);
	}
}

bool kiemtraSoNguyenTo(int x)
{
	if (x < 2)
	{
		return false;
	}
	else
	{
		if (x == 2)
		{
			return true;
		}
		else
		{
			if (x % 2 == 0)
			{
				return false;
			}
			else
			{
				for (int i = 2; i < x; i++)
				{
					if (x % i == 0)
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}

void xuatNTGiamDan(Node* root)
{
	if (root != NULL)
	{
		xuatNTGiamDan(root->left);
		if (kiemtraSoNguyenTo(root->info) == true)
		{
			printf("%4d", root->info);
		}
		xuatNTGiamDan(root->right);
	}
}

bool KTSoHoanHao(int a) 
{
	int sum = 0;
	for (int i = 1; i <= a / 2; i++) 
	{ 
		if (a % i == 0)
			sum += i; 
	}
	if (sum == a) return true; 
	return false; 
}

void xuatHoanHaoGiamDan(Node* root)
{
	if (root != NULL)
	{
		xuatHoanHaoGiamDan(root->right);
		if (KTSoHoanHao(root->info) == true)
		{
			printf("%4d", root->info);
		}
		xuatHoanHaoGiamDan(root->left);
	}
}

bool isChan(int n)
{
	return n % 2 == 0;
}

void xuatNodeChanMucK(Node* root, int k)
{
	if (!root)return;
	if (k == 0 && isChan(root->info))
	{
		printf("%4d", root->info);
	}
	k--;
	xuatNodeChanMucK(root->left, k);
	xuatNodeChanMucK(root->right, k);
}

bool isLe(int n)
{
	return n % 2 != 0;
}

void xuatNodeLeMucKGiamDan(Node* root, int k)
{
	if (!root)return;
	xuatNodeLeMucKGiamDan(root->right, k);
	if (k == 0 && isLe(root->info))
	{
		printf("%4d", root->info);
	}
	k--;
	xuatNodeLeMucKGiamDan(root->left, k);
}

bool isDuong(int n)
{
	return n > 0;
}

bool isAm(int n)
{
	return n < 0;
}

int TongDuong(Node* root)
{
	if (root == NULL) return 0;
	else
	{
		int d1 = TongDuong(root->left);
		int d2 = TongDuong(root->right);

		if (isDuong(root->info))
			return root->info + d1 + d2;
		else
			return d1 + d2;
	}
}

int TongAm(Node* root)
{
	if (root == NULL) return 0;
	else
	{
		int d1 = TongAm(root->left);
		int d2 = TongAm(root->right);

		if (isAm(root->info))
			return root->info + d1 + d2;
		else
			return d1 + d2;
	}
}

int demKhongDeQuy(Node* root)
{
	Node* p;
	int dem1 = 0, dem2 = 0;
	while (root) 
	{
		if (root->left == NULL)
		{
		    dem1++;
			root = root->right;
		}
		else
		{
			p = root->left;
			while (p->right && p->right != root)
			{
				p = p->right;
			}
			if (p->right == NULL)
			{
				p->right = root;
				root = root->left;
			}
			else
			{
				p->right = NULL;
				dem2++;
				root = root->right;
			}
		}
	}
	return dem1 + dem2 ;
}

int treeLevel(Node* root) 
{
	if (root == NULL) 
		return -1;
	return 1 + max(treeLevel(root->left), treeLevel(root->right));
}

bool ktAvl(Node* root) 
{
	if (root == NULL) 	
		return true;
	if (abs(treeLevel(root->left) - treeLevel(root->right)) > 1) 
		return false;
	return ktAvl(root->left) && ktAvl(root->right);
}

void deleteNode(Node* t) 
{
	if (t != NULL) {
		if (t->left != NULL) deleteNode(t->left);
		if (t->right != NULL) deleteNode(t->right);
		delete(t);
	}
}
Node* deleteNumber(Node* t, int x) 
{
	if (t != NULL) {
		if (t->info == x) {
			deleteNode(t->left);
			deleteNode(t->right);
			t = NULL;
		}
		else if (t->info > x) t->left = deleteNumber(t->left, x);
		else t->right = deleteNumber(t->right, x);
	}
	return t;
}


void menu()
{
	printf("\n\n\n========================MENU==========================");
	printf("\n1.Xuat cac node theo thu tu giam dan");
	printf("\n2.Dem so node trong doan ab");
	printf("\n3.Dem so node co gia tri lon hon x trong doan ab");
	printf("\nt4.tong gia tri cac node trong doan ab");
	printf("\n5.Xuat cac node trong doan ab");
	printf("\n6.Xuat cac node trong doan ab theo thu tu giam dan");
	printf("\n7.Xuat cac node la so nguyen to theo tu tu tang dan");
	printf("\n8.Xuat cac node la so hoan hao giam dan ");
	printf("\n9.Xuat cac node chan muc k");
	printf("\n10.Xuat cac node le muc k theo thu tu giam dan");
	printf("\n11.Tong nut am duong tren cay");
	printf("\n12.Dem tong cac nut khong dum de quy");
	printf("\n13.Kiem tra cay co phai la cay nhi phan khong");
	printf("\n14.Tim duong di tu goc den node co gia tri x");
	printf("\n15.Xoa cac node co gia tri lon hon x");
	printf("\n16.Xoa cac node trong doan a b");
	printf("\n======================================================");
}
void main()
{

	Node* root;
	init(root);
	int chon = 0;
	readFile(root, "CayAVL.txt");
	
	do
	{
		system("cls");
		LNR(root);
		printf("\n");
		print_ascii_tree(root);
		menu();
		printf("\nNhap lua chon: ");
		scanf("%d", &chon);
		switch (chon)
		{
			case 0:
			{
				break;
			}
			case 1:
			{
				printf("\nCac gia tri giam dan: ");
				RNL(root);
				
				break;
			}
			case 2:
			{
				int a, b;
				printf("\nNhap a: ");
				scanf("%d", &a);
				printf("\nNhap b: ");
				scanf("%d", &b);
				if (a > b)
				{
					printf("\nDoan nhap khong hop le");
				}
				else
				{
					int d = demNodeHonXTrongDoanAB(root, a, b);
					printf("\nSo node trong doan [%d,%d] la: %d", a, b, d);
				}
				
				break;
			}
			case 3:
			{
				int a, b, x;
				printf("\nNhap a: ");
				scanf("%d", &a);
				printf("\nNhap b: ");
				scanf("%d", &b);
				printf("\nNhap x: ");
				scanf("%d", &x);
				if (a > b)
				{
					printf("\nDoan nhap khong hop le");
				}
				else
				{
					if (a > x)
					{
						int d = demNodeTrongDoanAB(root, x, b);
						printf("\nSo node lon hon %d trong doan [%d,%d] la: %d",x, a, b, d);
					}
					else
					{
						int g = demNodeTrongDoanAB(root, x, b);
						printf("\nSo node lon hon %d trong doan [%d,%d] la: %d", x, a, b, g);
					}
				}
				break;
			}
			case 4:
			{
				int a, b;
				printf("\nNhap a: ");
				scanf("%d", &a);
				printf("\nNhap b: ");
				scanf("%d", &b);
				int tong = tongGTNodeDoanAB(root, a, b);
				printf("\nTong gia tri trong doan [%d,%d] la: %d", a, b, tong);
				break;
			}
			case 5:
			{
				int a, b;
				printf("\nNhap a: ");
				scanf("%d", &a);
				printf("\nNhap b: ");
				scanf("%d", &b);
				xuatTrongDoanAB(root, a, b);
				break;
			}
			case 6:
			{
				int a, b;
				printf("\nNhap a: ");
				scanf("%d", &a);
				printf("\nNhap b: ");
				scanf("%d", &b);
				printf("\nCac gia tri giam dan trong doan [%d,%d] la:",a,b);
				xuatTrongDoanABGiamDan(root, a, b);
				break;
			}
			case 7:
			{
				xuatNTGiamDan(root);
				break;
			}
			case 8:
			{
				xuatHoanHaoGiamDan(root);
				break;
			}
			case 9:
			{
				int k;
				printf("\nNhap muc K: ");
				scanf("%d", &k);
				xuatNodeChanMucK(root, k);
				break;
			}
			case 10:
			{
				int k;
				printf("\nNhap muc K: ");
				scanf("%d", &k);
				xuatNodeLeMucKGiamDan(root, k);
				break;
			}
			case 11:
			{
				int tong = TongDuong(root);
				int tong2 = TongAm(root);
				printf("\nTong duong la: %d", tong);
				printf("\nTong am la: %d", tong2);
				break;
			}
			case 12:
			{
				int d = demKhongDeQuy(root);
				printf("\n%d", d);
				break;
			}
			case 13:
			{
				if (ktAvl(root) == true)
				{
					printf("\nDay la cay AVL");
				}
				else
				{
					printf("\nDay khong phai la cay AVL");
				}
				break;
			}
			case 15:
			{
				break;
			}
			default:
			{
				printf("\nLua chon khong hop le.");
			}
		
		}
		printf("\n");
		system("pause");
	} while (chon != 0);
}

