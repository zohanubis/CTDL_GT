#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct Node
{
    int info;
    Node *next;
};
struct Slist
{
    Node *head;
    Node *tail;
};
Node *createNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat !");
        return NULL;
    }
    p -> info = x;
    p -> next = NULL;
}
void menu();
void initSlist(Slist &l);
void addHeadSlist(Slist &l, Node *p);
void addTailSlist(Slist &l, Node *p);
void createAutoList(Slist &l);
void printList(Slist &l);
int addBeforeNode(Slist &l, Node *q, Node *p);
void deleteHeadSlist(Slist &l, Node *p);
void deleteTailSlist(Slist &l, Node *p);
void deleteAfterNode(Slist &l, Node *q);
void deleteNodeGreaterThanX(Slist &l, int x);
void deleteEvenNode(Slist &l);
void sortIncrease(Slist &l);
void sortDecrease(Slist &l);
int countPrimNumberInSlist(Slist l);
int computeSumSquareNumberInSList(Slist l);
int findMaxInSlist(Slist l);
int findMinInSlist(Slist l);
int countNodeGreaterThanDoubleAfterNode(Slist &l);
void splitSlistIntoEvenListAndOddList(Slist l,Slist &l1,Slist &l2);
int main(){
    menu();
    return 0;
}
void menu(){
    Slist l;
    initSlist(l);
    createAutoList(l);
    printf("\n\tSlist : ");
    printList(l);
    printf("\n\n1. Them phan tu moi vao cuoi danh sach sl");
	printf("\n2. Chen them phan tu co gia tri x vao truoc phan tu co gia tri y");
	printf("\n3. Viet ham xoa cac phan tu lon hon x trong dslk");
	printf("\n4. Viet ham xoa cac phan tu chan trong dslk");
	printf("\n5. Sap xep dslk tang dan, giam dan");
	printf("\n6. Cho biet trong dslk co bao nhieu so nguyen to");
	printf("\n7. Tinh tong cac so chinh phuong trong dslk");
	printf("\n8. Tim phan tu nho nhat, phan tu lon nhat trong dslk");
	printf("\n9. Cho biet trong dslk co bao nhieu phan tu lon hon gap doi phan tu phia sau no");
	printf("\n10. Tu sl tao 2 danh sach moi: sl1 chua cac so chan, sl2 chua cac so le");
    int nhap;
    do
    {
        printf("\n\nNhap 0 de thoat ");
        printf("\nNhap thao tac muon thuc hien : "); scanf("%d",&nhap);
        switch (nhap)
        {
            case 1 :{
                int x;
                printf("Nhap phan tu muon them vao cuoi danh sach : "); scanf("%d",&x);
                Node *p = createNode(x);
                addTailSlist(l,p);
                printf("\n\tSlist sau khi them %d vao cuoi : ",p -> info);
                printList(l);
                break;
            }
            case 2:{
                int x,y;
                printf("Nhap phan tu x muon them vao truoc phan tu y : "); scanf("%d%d",&x,&y);
                Node *q = createNode(x);
                Node *p = createNode(y);
                int result = addBeforeNode(l,q,p);
                if (result != 0)
                {
                    printf("\n\tSlist sau khi them %d truoc %d", q-> info ,p -> info);
                    printList(l);
                }
                break;
            }
            case 3:{
                int x;
				printf("Nhap phan tu x: ");scanf("%d",&x);
				deleteNodeGreaterThanX(l,x);
				printf("\n\tSList sau khi xoa nhung phan tu lon hon %d: ",x);
				printList(l);
				break;
            }
            case 4:{
				deleteEvenNode(l);
				printf("\n\tSList sau khi xoa nhung phan tu chan: ");
				printList(l);
				break;
			}
        default:
            break;
        }
    } while (nhap != 0);
}
void initSlist(Slist &l)
{
    l.head = l.tail = NULL;
}
void addHeadSlist(Slist &l, Node *p)
{
    if (p == NULL)
    {
        return;
    }
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        p -> next = l.head;
        l.head = p;
    }
}
void addTailSlist(Slist &l, Node *p)
{
    if (p == NULL)
    {
        return;
    }
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail -> next = p;
        l.tail = p;
    }
}
void createAutoSlist(Slist &l)
{
    int n,x;
    do
    {
        printf("Nhap so luong node cua danh sach ( n > 0 ) : "); scanf ("%d",&n);
    } while (n <= 0);
    srand(time(NULL));
    for (int i = 1; i <= n; i++)
    {
        x = (rand() % 199)-99;
        Node *p = createNode(x);
        addTailSlist(l,p);
    }
    
}
void printList(Slist &l){
    Node *temp = l.head;
    while (temp != NULL)
    {
        printf("%d ",temp -> info);
        temp = temp -> next;
    }
}
int addBeforeNode(Slist &l, Node *q, Node *p)
{
    int temp = p-> info;
    p = l.head;
    while (p != NULL && p -> info != temp)
    {
        p = p -> next;
    }
    if (q == NULL || p == NULL)
    {
        printf("\n\tKhong ton tai phan tu de them ! ");
        return 0;
    }
    else
    {
        if (p == l.head)
        {
            addHeadSlist(l,q);
        }
        else
        {
            Node *temp = l.head;
            while (temp -> next != p)
            {
                temp = temp -> next;
            }
            temp -> next = q;
            q -> next = p;
        }
    }
}
void deleteHeadSlist(Slist &l, Node *p)
{
    if (l.head == NULL)
    {
        printf("\n\tKhong co phan tu de xoa !");
        return ;
    }
    else
    {
        Node *temp = l.head;
        l.head = l.head -> next;
        temp -> next = NULL;
        delete temp;
    }
}
void deleteTailSlist(Slist &l, Node *p)
{
    if (l.head == NULL)
    {
        printf("\n\tKhong co phan tu de xoa !");
        return;
    }
    else{
        Node *temp = l.tail;
        Node *temp2 = l.head;
    }
    
}
void deleteAfterNode(Slist &l, Node *q);
void deleteNodeGreaterThanX(Slist &l, int x);
void deleteEvenNode(Slist &l);
void sortIncrease(Slist &l);
void sortDecrease(Slist &l);
int countPrimNumberInSlist(Slist l);
int computeSumSquareNumberInSList(Slist l);
int findMaxInSlist(Slist l);
int findMinInSlist(Slist l);
int countNodeGreaterThanDoubleAfterNode(Slist &l);
void splitSlistIntoEvenListAndOddList(Slist l,Slist &l1,Slist &l2);