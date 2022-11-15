#include "stdio.h"
#include "stdlib.h"
#include "time.h"
struct TNode{
	int info;
	TNode *left;
	TNode *right;
};
struct BTree{
	TNode *root;
};
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
void initBTree(BTree &bt);
int insertTNodeLeft(TNode* &t, TNode *p);
int insertTNodeRight(TNode* &t, TNode *p);
int insertTNode(TNode* &root, TNode *p);
void createBTree_FromArray(BTree &bt, int a[], int na);
void showTNode(TNode *p);
void traverseNLR(TNode *root);
void traverseNRL(TNode *root);
void traverseLNR(TNode *root);
void traverseRNL(TNode *root);
void traverseLRN(TNode *root);
void traverseRLN(TNode *root);
TNode *findTNode(TNode *root, int x);
int highTree(TNode *root);
void menu()
{
    int a[50], na;
    printf("Nhap so luong phan tu muon them vao cay: ");scanf("%d",&na);
    for (int i = 0; i < na; i++)
    {
        printf("\nNhap phan tu thu %d: ",i+1);
		scanf("%d",&a[i]);
    }
    BTree bt;
    initBTree(bt);
	createBTree_FromArray(bt,a,na);
    printf("\n1. Traverse NLR ; NRL");
    printf("\n2. Traverse LNR ; RNL");
    printf("\n3. Traverse LRN ; RLN");
    printf("\n4. Tim node x cua cay ");
    printf("\n5. Chieu cao cua cay ");
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
            printf("\n\tTraverse NLR: ");
            traverseNLR(bt.root);
            printf("\n\tTraverse NRL: ");
            traverseNRL(bt.root);
            break;
        }
        case 2:
        {
            printf("\n\tTraverse LNR: ");
            traverseLNR(bt.root);
            printf("\n\tTraverse RNL: ");
            traverseRNL(bt.root);
            break;
        }
        case 3:
        {
            printf("\n\tTraverse LRN: ");
            traverseLRN(bt.root);
            printf("\n\tTraverse RLN: ");
            traverseRLN(bt.root);
            break;
        }
        case 4:
        {
            int x;
            printf("\n\nNhap gia tri node can tim: ");scanf("%d",&x);
            if(findTNode(bt.root,x) != NULL)
            {
                printf("\n\tDa tim thay va node co gia tri la: %d",findTNode(bt.root,x)->info);
            }
            else
            {
                printf("\n\tKhong tim thay!");
            }
        }
        case 5:
        {
            printf("\n\tHigh Of Tree is: %d",highTree(bt.root));
            break;
        }
        default:
            break;
        }
    } while (nhap != 0);
    
}
int main(){
	int a[50],na;
	printf("Nhap so luong phan tu muon them vao cay: ");scanf("%d",&na);
	for(int i = 0; i < na; i++){
		printf("\nNhap phan tu thu %d: ",i+1);
		scanf("%d",&a[i]);
	}
	BTree bt;
	initBTree(bt);
	createBTree_FromArray(bt,a,na);
	printf("\n\tTraverse NLR: ");
	traverseNLR(bt.root);
	int x;
	printf("\n\nNhap gia tri node can tim: ");scanf("%d",&x);
	if(findTNode(bt.root,x) != NULL){
		printf("\n\tDa tim thay va node co gia tri la: %d",findTNode(bt.root,x)->info);
	}else{
		printf("\n\tKhong tim thay!");
	}
	printf("\n\tHigh Of Tree is: %d",highTree(bt.root));
	return 0;
}
void initBTree(BTree &bt){
	bt.root = NULL;
}
int insertTNodeLeft(TNode* &t, TNode *p){
	if(t == NULL || p == NULL){
		return 0;
	}else{
		if(t->left != NULL) return 0;
		t->left = p;
		return 1;
	}
}
int insertTNodeRight(TNode* &t, TNode *p){
	if(t == NULL || p == NULL){
		return 0;
	}else{
		if(t->right != NULL) return 0;
		t->right = p;
		return 1;
	}
}
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
void createBTree_FromArray(BTree &bt, int a[], int na){
	for(int i = 0; i < na; i++){
		TNode *p = createTNode(a[i]);
		insertTNode(bt.root,p);
	}
}
void showTNode(TNode *p){
	printf("%d ",p->info);
}
void traverseNLR(TNode *root){
	if(root == NULL){
		return;
	}
	showTNode(root);
	traverseNLR(root->left);
	traverseNLR(root->right);
}
TNode *findTNode(TNode *root, int x){
	if(root == NULL){
		return NULL;
	}
	if(root->info == x){
		return root;
	}
	TNode *p = findTNode(root->left,x);
	if(p != NULL){
		return p;
	}
	return findTNode(root->right,x);
}
int highTree(TNode *root){ // Chieu cao cay
	if(root == NULL){
		return 0;
	}
	int hl = highTree(root->left);
	int hr = highTree(root->right);
	return hl > hr ? hl + 1 : hr + 1;
}
void traverseNRL(TNode *root){
	if(root == NULL){
		return;
	}
	showTNode(root);
	traverseNRL(root->right);
	traverseNRL(root->left);
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
void traverseRNL(TNode *root)
{
	if(root == NULL)
	{
		return;
	}
	traverseRNL(root -> right);
	showTNode(root);
	traverseRNL(root -> left);
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
void traverseRLN(TNode *root)
{
	if(root == NULL)
	{
		return;
	}
	traverseRLN(root -> right);
	traverseRLN(root -> left);
	showTNode(root);
}