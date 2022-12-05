#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include"iostream"
struct TNode{
    int info;
    TNode *left;
    TNode *right;
};
struct BTree{
    TNode *root;
};

void menu();
TNode *createTNode(int x);
void initBTree(BTree &bt);
int insertTNodeLeft(TNode* &t, TNode *p);
int insertTNodeRight(TNode* &t, TNode *p);
int insertTNode(TNode* &root, TNode *p);
void showTNode(TNode *p);
void readFile(TNode * &root, char *fileName);
void traverseNLR(TNode *root);
void traverseLNR(TNode *root);
void traverseLRN(TNode *root);
int countNodeDuong(TNode *root);
int countNodeAm(TNode *root);
int countNutLa(TNode *root);
TNode *findTNodeReplace(TNode *&p);
int deleteTNodeX(TNode *&root, int x);
int demNodeTrongDoanAB(TNode *root , int a, int b);
void xuatNodeGiamDanTrongDoangAB(TNode *root, int a, int b);
int tongNodeTrongDoanAb(TNode *root, int a, int b);
int demNodeTrongDoanABNhoHonX(TNode *root, int a, int b, int x);
bool checkPrim(int n);
void xuatCacSoNguyenToGiamDan(TNode *root);
bool checkHoanHao(int n);
void xuatCacHoanHaoGiamDan(TNode *root);
void xuatCacNodeChanMucK(TNode *root , int k);
void xuatCacNodeChanMucKGiamDan(TNode *root , int k);
void tongCacNodeDuong(TNode *root);
TNode *deleteNodeGreaterThanX(TNode *root, int k);
TNode *leftMost(TNode *root);
TNode *deleteNode(TNode *root);
TNode *xoaNodeTrongDoanAB(TNode *root, int a, int b);
int main()
{
    menu();
    return 0;
}
void menu()
{
    BTree bt;
    
    initBTree(bt);
    int nhap;
    do
    {
        printf("\n\nNhap 0 de thoat !");
        printf("\nNhap thao tac muon thuc hien : ");
        scanf("%d",&nhap);
        switch (nhap)
        {
            case 1:
            {
                readFile(bt.root, "tree.txt");
                showTNode(bt.root);
                break;
            }
        case 2:
        {
            printf("\n\tTraverse NLR : ");
            traverseNLR(bt.root);
            printf("\n\tTraverse LNR : ");
            traverseLNR(bt.root);
            printf("\n\tTraverse LRN : ");
            traverseLRN(bt.root);
            break;
            
        }
        default:
            break;
        }
    } while (nhap != 0);
    
}
TNode *createTNode(int x){
    TNode *p = new TNode;
    if(p == NULL){
        printf("\n\tKhong du bo nho de cap phat!");
        return NULL;
    }
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void initBTree(BTree &bt){
    bt.root = NULL;
}
// int insertTNodeLeft(TNode* &t, TNode *p){
//     if(t == NULL || p == NULL){
//         return 0;
//     }else{
//         if(t->left != NULL) return 0;
//         t->left = p;
//         return 1;
//     }
// }
// int insertTNodeRight(TNode* &t, TNode *p){
//     if(t == NULL || p == NULL){
//         return 0;
//     }else{
//         if(t->right != NULL) return 0;
//         t->right = p;
//         return 1;
//     }
// }
int insertTNode(TNode* &root, TNode *p){
    if(p == NULL){
        return 0;
    }else{
        if(root == NULL){
            root = p;
            return 1;
        }else{
            if(root->left == NULL){
                insertTNode(root->left,p);
            }else if(root->right == NULL){
                insertTNode(root->right,p);
            }else{
                srand(time(NULL));
                int x = rand() % 2;
                if(x == 0){
                    insertTNode(root->left,p);
                }else{
                    insertTNode(root->right,p);
                }
            }
            return 1;
        }
    }
}
void showTNode(TNode *p){
    printf("%d ",p->info);
}
void readFile(TNode * &root, char *fileName)
{
    FILE *f = fopen(fileName, "rt");
    if(f)
    {
        int x;
        while (fscanf(f,"%d",&x) == 1)
        {
            insertTNode(root,createTNode(x));
        }
        fclose(f);
    }
}
void traverseNLR(TNode *root){
    if(root == NULL){
        return;
    }
    showTNode(root);
    traverseNLR(root->left);
    traverseNLR(root->right);
}
void traverseLNR(TNode *root)
{
    if(root == NULL)
    {
        return;
    }
    traverseLNR(root -> left);
    showTNode(root);
    traverseLNR(root ->right);
}
void traverseLRN(TNode *root)
{
    if(root == NULL)
    {
        return;
    }
    traverseLRN(root -> left);
    traverseLRN(root -> right);
    showTNode(root);
}
int countNodeDuong(TNode *root)
{
    if(root == NULL)
        return 0;
    int a = countNodeDuong(root -> left);
    int b = countNodeDuong(root -> right);
    if (root -> info > 0)
    {
        return a + b + 1;
    }
    return a +b;
}
int countNodeAm(TNode *root)
{
if(root == NULL)
        return 0;
    int a = countNodeDuong(root -> left);
    int b = countNodeDuong(root -> right);
    if (root -> info < 0)
    {
        return a + b + 1;
    }
    return a + b;
}
int countNutLa(TNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int a = countNutLa(root->left);
    int b = countNutLa(root->right);
    if(!root->left && !root->right)
    {
        return a + b + 1;
    }
    return a + b;
}
TNode *findTNodeReplace(TNode *&p)
{
    TNode *f = p;
    TNode *q = p->right;
    while (q -> left != NULL)
    {
        f = q;
        q = q->left;
    }
    q -> info = q->info;
    if (p == q)
    {
        f->right = q->right;
    }else{
        return q;
    }
}
int deleteTNodeX(TNode *&root, int x)
{
    if (root == NULL)
		return 0;
	if (root->info > x)
		return deleteTNodeX(root->left, x);
	else
		if (root->info < x)
			return deleteTNodeX(root->right, x);
		else
		{
			TNode* p = root;
			if (root->left == NULL) //cay con khong co nhanh trai
			{
				root = root->right;
				delete p;
			}
			else
				if (root->right == NULL)//cay con khong co nhanh phai
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
int demNodeTrongDoanAB(TNode *root , int a, int b)
{

}
void xuatNodeGiamDanTrongDoangAB(TNode *root, int a, int b);
int tongNodeTrongDoanAb(TNode *root, int a, int b);
int demNodeTrongDoanABNhoHonX(TNode *root, int a, int b, int x);
bool checkPrim(int n);
void xuatCacSoNguyenToGiamDan(TNode *root);
bool checkHoanHao(int n);
void xuatCacHoanHaoGiamDan(TNode *root);
void xuatCacNodeChanMucK(TNode *root , int k);
void xuatCacNodeChanMucKGiamDan(TNode *root , int k);
void tongCacNodeDuong(TNode *root);
TNode *deleteNodeGreaterThanX(TNode *root, int k);
TNode *leftMost(TNode *root);
TNode *deleteNode(TNode *root);
TNode *xoaNodeTrongDoanAB(TNode *root, int a, int b);