#include "stdio.h"
#include "stdlib.h"
struct Book
{
    char ma[11];
    char tenSach[31];
    int soTrang, nsx;
    float gia;
}; 
struct Node
{
    Book info;
    Node *next;
};
struct SList
{
    Node *head;
    Node *tail;
};
Node *createNode(Book x){
	Node *p = new Node;
	if(p == NULL){
		printf("Khong du bo nho de cap phat!");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
    return p;
}
Book x;
void menu();
void initSList(SList &sl){
	sl.head = sl.tail = NULL;
}
bool isEmpty(SList sl)
{
    return sl.head == NULL;
}
void addHeadSList(SList &sl, Node *p){
	if(p == NULL){
		return;
	}
	if(sl.head == NULL){
		sl.head = sl.tail = p;
	}else{
		p->next = sl.head;
		sl.head = p;
	}
}
void addTailSList(SList &sl, Node *p){
	if(p == NULL){
		return;
	}
	if(sl.head == NULL){
		sl.head = sl.tail = p;
	}else{
		sl.tail->next = p;
		sl.tail = p;
	}
}
void inpurListFromFle(SList &sl)
{
    FILE *f = fopen("cuonsach.txt" ,"rt");
    if (f != NULL)
    {
        int n;
        fscanf(f,"%d",&n);
        Book x;
        for (int i = 0; i < n; i++)
        {
            readBook(f,x);
            addTailSList(sl,createNode(x));
        }
        fclose(f);
    }
}
void traverse(SList sl)
{
    outputTitle();
    Node *p = sl.head;

    while (p != NULL)
    {
        output1Book(p -> info);
        p = p -> next;
    }
}
void output1Book (Book x) // 1 cuon
{
    printf("%-10s%-20s%10d%10.2f%10d\n",x.ma,x.tenSach,x.soTrang,x.gia,x.nsx);
}
void readBook(FILE *f,Book &x){
    fscanf(f,"%s%s%d%f%d",&x.ma,&x.tenSach,&x.soTrang,&x.gia,&x.nsx);
}
void outputTitle()
{
    printf("%-10s%-20s%10s%10s%10s\n",x.ma,x.tenSach,x.soTrang,x.gia,x.nsx);
}
void deleleSList(SList &sl)
{
    Node *p;
    while (!isEmpty(sl))
    {
        p = sl.head;
        sl.head = p -> next;
        delete p;
    }
    sl.head = sl.tail = NULL;
}
bool isThoaDkCau4(Book x)
{
    return x.soTrang > 500 && x.nsx < 2018;
}
int countBook(SList sl)
{
    int count = 0;
    Node *p = sl.head;
    while (p != NULL)
    {
        if(isThoaDkCau4(p -> info))
        {
            count++;
            p = p -> next;
        }
        return count;
    }
}
bool isThoaDKCau5(Book x)
{
    return x.gia > 100000;
}
void deleteHeadSList(SList &sl){
	if(sl.head == NULL){
		printf("\n\tKhong co phan tu de xoa!");
		return;
	}else{
		Node *temp = sl.head;
		sl.head = sl.head->next;
		temp->next = NULL;
		delete temp;
	}
}
void deleteTailSList(SList &sl){
	if(sl.head == NULL){
		printf("\n\tKhong co phan tu de xoa!");
		return;
	}else{
		Node *temp = sl.tail;
		Node *temp2 = sl.head;
		while(temp2->next != sl.tail){
			temp2 = temp2->next;
		}
		temp2->next = NULL;
		sl.tail = temp2;
		delete temp;
	}
}
void deleteAfterNode(SList &sl, Node *q){
	int temp = q->info;
	q = sl.head;
	while(q != NULL && q->info != temp){
		q = q->next;
	}
	if(q == NULL || sl.head == NULL){
		return;
	}else{
		if(q->next == sl.tail){
			deleteTailSList(sl);
		}else{
			Node *temp = q->next;
			q->next = temp->next;
			temp->next = NULL;
			delete temp;
		}
	}
}
void xoaSachThoaDk(SList &sl)
{
    if (isEmpty(sl))
    {
        return;
    }
    else
    {
        while (isThoaDkCau5(sl.head ->info))
        {
            deleteHeadSList(sl);
        }
        Node *q = sl.head;
        while (q -> next != NULL)
        {
            if(isThoaDKCau5(q -> next -> info)){
                deleteAfterNode(sl,q);
            }
            else
            {
                q = q -> next;
            }
        }
    }
}
void main()
{
    SList sl;
    initSList(sl);
    inpurListFromFle(sl,"cuonsach.txt");
    traverse(sl);
    int count = countBook(sl);
    printf("So sach thoa dk : %d ",count);
    printf("Sau khi xoa : \n");
    xoaSachThoaDk(sl);
    traverse(sl);
    deleleSList(sl);
    system("pause");
}