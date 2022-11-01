#include "stdio.h"
#include "stdlib.h"

struct Book
{
    char ma[11];
    char ten[31];
    int soTrang;
    float gia;
    int namXB;
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
void menu();
void init(SList &sl);
Node *createNode(Book b);
void output1Book(Book x);
void read1Book(FILE *f, Book &x);
void outputTilte();
void addHeadSList(SList &l, Node *p);
void addTailSList(SList &l, Node *p);
void inputSListFromFile(SList &l, char fileName[]);
void display(SList);
void deleteSList(SList &l);
int countBook(SList l);
void deleteHeadSList(SList &l);
void deleteAfterNode(SList &l, Node *q);
void xoaSachThoaDk(SList &l);
void chenXTruocY(SList &l, Node *q, Node *p);
void add1Book(Book &b);
void addBook(SList &l);
// main 
int main()
{
    menu();
    return 0;
}
void menu()
{
    SList l;
    init(l);
    inputSListFromFile(l,"cuonsach.txt");
    display(l);

    printf("\n1. Co bao nhieu cuon sach co so trang > 500 va xuat ban truoc 2018. ");
    printf("\n2. Xoa tat ca sach co gia ban lon hon 100.000 trong dslk don.");
    printf("\n3. Them cuon sach x truoc cac cuon sach  co gia tri nho hon.");
    int nhap;
    do
    {
        printf("\n\nNhap 0 de thoat !");
        printf("\nNhap thao tac muon thuc hien : "); 
        scanf("%d",&nhap);
        switch (nhap)
        {
        case 1:{
            int count = countBook(l);
            printf("\n\tSo sach co so trang > 500 va xuat ban truoc 2018 : %d",count);
            break;
        }
        case 2:{
            printf("\n\tSau khi xoa sach co gia ban lon hon 100.000 : \n");
            xoaSachThoaDk(l);
            display(l);
            break;
        }
        case 3:{
            addBook(l);
            display(l);
            break;
        }
        default:
            break;
        }
    } while (nhap != 0);
    
}
// Code
void init(SList &l)
{
    l.head = l.tail = NULL;
}
bool isEmpty(SList l)
{
    return l.head == NULL;
}
Node *createNode(Book b)
{
    Node *p = new Node;
    if (p != NULL)
    {
        p -> info = b;
        p -> next = NULL;
    }
    return p;
}
void addHeadSList(SList &l, Node *p)
{
    if (isEmpty(l))
    {
        l.head = l.head = p;
    }
    else {
        p -> next = l.head;
        l.head = p;
    }
}
void addTailSList(SList &l, Node *p)
{
    if (isEmpty(l))
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail -> next = p;
        l.tail = p;
    }
}
void output1Book(Book x)
{
    printf("%-10s%-20s%10d%10.2f%10d\n", x.ma, x.ten, x.soTrang, x.gia,x.namXB);
}
void read1Book(FILE *f, Book &x)
{
    fscanf(f,"%s%s%d%f%d", &x.ma, &x.ten, &x.soTrang, &x.gia,&x.namXB);
}
void outputTilte()
{
    printf("%-10s%-20s%10s%10s%10s\n", "MaSach", "TenSach", "SoTrang","GiaBan", "NamXB");
}
void inputSListFromFile(SList &l, char fileName[])
{
    FILE *f = fopen (fileName , "rt");
    if (f != NULL)
    {
        int n;
        fscanf(f, "%d", &n);
        Book x;
        for (int i = 0; i < n; i++)
        {
            read1Book(f,x);
            addTailSList(l,createNode(x));
        }
        fclose(f);
    }
}
void display(SList l)
{
    outputTilte();
    Node *p = l.head;
    while (p != NULL)
    {
        output1Book(p -> info);
        p = p -> next;
    }
}
void deleteSList(SList &l)
{
    Node *p; 
    while (!isEmpty(l))
    {
        p = l.head;
        l.head = p -> next;
        delete p;
    }
    l.head = l.tail = NULL;
}
bool DieuKienCau4(Book x)
{
    return x.soTrang > 500 && x.namXB < 2018;
}
int countBook(SList l)
{
    int count = 0;
    Node *p = l.head;
    while ( p != NULL)
    {
        if(DieuKienCau4(p -> info)){
            count++;
        }
        p = p -> next;
    }
    return count;
}
bool DieuKienCau5(Book x)
{
    return x.gia > 100000;
}
void deleteHeadSList(SList &l)
{
    if (isEmpty(l))
    {
        return;
    }
    Node *p = l.head;
    l.head = p -> next;
    if (l.head == NULL)
    {
        l.tail = NULL;
        delete p;
    }
}
void deleteAfterNode(SList &l, Node *q)
{
    if(isEmpty(l) || q == NULL || q -> next == NULL){
        return;
    }
    Node *p = q -> next;
    q -> next = p -> next;
    if (l.tail == p)
    {
        l.tail = q;
        delete p;
    }
}
void xoaSachThoaDk(SList &l)
{
    if(isEmpty(l))
    {
        return ;
    }
    else
    {
        while (DieuKienCau5(l.head -> info))
        {
            deleteHeadSList(l);
        }
        Node *q = l.head;
        while (q -> next != NULL)
        {
            if(DieuKienCau5(q-> next -> info)){
                deleteAfterNode(l,q);
            }
            else{
                q = q -> next;
            }
        }
    }
}
void chenXTruocY(SList &l, Node *q, Node *p)
{
    if(l.head == p)
    {
        addHeadSList(l,p);
    }
    else{
        Node * temp = l.head;
        while (temp -> next != p)
        {
            temp = temp -> next;
        }
        temp -> next = q;
        q -> next = p;
    }
}
bool DieuKienCau6(Book x)
{
    return x.gia < 50000;
}
void add1Book(Book &x)
{
    printf("\nNhap sach : \n");
    printf("\tMa sach : "); scanf("%s",&x.ma);
    printf("\tTen sach : "); scanf("%s",&x.ten);
    printf("\tSo trang sach : "); scanf("%d",&x.soTrang);
    printf("\tGia ban : "); scanf("%f",&x.gia);
    printf("\tNam xuat ban : "); scanf("%d",&x.namXB);
}
void addBook(SList &l)
{
    Book x;
    add1Book(x);
    int count = 0;
    for(Node *p = l.head ; p != NULL ; p = p -> next){
        if(DieuKienCau6(p -> info))
        {
            Node *z = createNode(x);
            chenXTruocY(l,z,p);
            count++;
        }
    }
    if (count == 0)
    {
        printf("Khong tim thay ");
    }
}
