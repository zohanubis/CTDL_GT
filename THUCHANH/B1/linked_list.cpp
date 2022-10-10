#include "stdio.h"
#include "conio.h"
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
    Node *q = new Node;
    if (q==NULL)
    {
        printf("Khong du bo nho de cap phat");
        return NULL;
    }
    q -> info = x;
    q -> next = NULL;
    return q;
}

void menu();
void createList(Slist &l, int n);
void printList(Slist l);
void createAutoSlist(Slist &l);
void addHeadSlist(Slist &l, Node *p);
void addTailSlist(Slist &l, Node *p);
void addAfterNodeSlist(Slist &l, Node *p);
void deleteHeadSlist(Slist &l);
void deleteTailSlist(Slist &l);
void deleteMidSlist(Slist &l, Node *q);
int main()
{
    menu();
    return 0;
}
void menu()
{
    Slist l; int n;
    printf("Nhap so luong phan tu : "); scanf("%d",&n);

    createList(l,n);
    printf("\n\t1. Them node vao dslk (them o dau/giua/cuoi).");
	printf("\n\t2. Xoa node trong dslk (xoa o dau/cuoi/giua).");
    
    int thaoTac;
    do
    {
        printf("\nNhap 0 de thoat ");
        printf("\nNhap thao tac muon thuc hien : ");
        scanf("%d",&n);
        switch (thaoTac)
        {
        case 1:  {
            int x1,x2,x3,x4;
            printf("Nhap phan muon them o dau : "); scanf("%d",&x1);
            Node *q1 = new Node;
            Node *q2 = new Node;
            Node *q3 = new Node;
            Node *p = new Node;

            q1 = createNode(x1);
            addHeadSlist(l,q1);
            printf("\n\tDanh sach sau khi them o dau : ");
            printList(l);

            q2 = createNode(x2);
            addHeadSlist(l,q2);
            printf("\n\tDanh sach sau khi them o cuoi : ");
            printList(l);
            printf("\nNhap phan tu q va phan tu p muon them vao sau q : ");
            scanf("%d%d",&x3,&x4);

            q3 = createNode(x3);
            p = createNode(x4);
            addAfterNodeSlist(l,q3,p);
            printf("\n\tDanh sach sua khi them %d vao sau %d : ",p->info,q3 -> info);
            printList(l);
            break;
        }
        case 2:{
            deleteHeadSlist(l);
            printf("\n\tDanh sach sau khi xoa dau : ");
            printList(l);
            deleteTailSlist(l);
            printf("\n\tDanh sach sau khi xoa cuoi : ");
            int x;
            printf("\nNhap phan tu q de xoa phan tu phia sau q : ");scanf("%d",&x);
            Node *q = new Node;
            q = createNode(x);
            deleteMidSlist(l,q);
            printf("\n\tDanh sach sau khi xoa phan tu %d : ",x);
            printList(l);
        }
        default:
            break;
        }
    } while (thaoTac!=0);
    
}

void createList(Slist &l, int n){
    int x;
    Node *q = new Node;
    l.head = l.tail = NULL;
    for (int i = 1; i <= n; i++)
    {
        printf("Nhap phan tu thu %d : ", i);
        scanf("%d",&x);
        q = createNode(x);
        
        if (q == NULL)
        {
            printf("Khong du bo nho de cap phat ");
            getch();
            return ;
        }
        if (l.head == NULL){
            l.head = l.tail = q;
        }
        else{
            l.tail -> next = q;
            l.tail = q;
        }
    }
}
void printList(Slist l)
{
    while (l.head != NULL)
    {
        printf("%d",l.head -> info);
        l.head = l.head -> next;
    }
}
/*void createAutoSlist(Slist &l)
{
    int n,x;
    initSlist(l);
    do
    {
        printf("Cho biet so phan tu cua danh sach ( n> 0) : "); scanf("%d",&n);
    } while (n <= 0);
    srand(time(NULL));
    for (int i = 1; i <= n; i++)
    {
        x =(rand() %199)-99;
        Node *p = createNode(x);
        addTailSList(l,p);
    }
}*/
void addHeadSlist(Slist &l, Node *p)
{
    if (p == NULL)
    {
        return ;
    }
    else
    {
        if (l.head == NULL)
        {
            l.head = l.tail = p;
        }
        else
        {
            p -> next = l.head;
            l.head= p;
        }
        
    }
}
void addTailSList(Slist &l, Node *p)
{
    if (p == NULL)
    {
        return ;
    }
    else
    {
        if (l.head == NULL)
        {
            l.head = l.tail = p;
        }
        else
        {
            l.tail ->next = p;
            l.tail = p;
        }
    }
}