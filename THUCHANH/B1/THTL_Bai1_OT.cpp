#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct NhanVien
{
    char ma[11];
    char ten[31];
    int ngay,thang,nam;
    int gioiTinh;
    float luong;
};
struct Node
{
    NhanVien info;
    Node *next;
};
struct Slist
{
    Node *head;
    Node *tail;
};
void menu();
void init(Slist &sl);
Node *createNode(NhanVien nv);
void output1NV(NhanVien nv);
void read1NhanVien(FILE *f, NhanVien &nv);
void display(Slist sl);
void addHeadSList(Slist &sl, Node *p);
void addTailSList(Slist &sl, Node *p);
void inputSListFromFile(Slist &sl, char fileName[]);

// main
int main()
{
    menu();
    return 0;
}
void menu()
{
    Slist sl;
    init(sl);
    inputSListFromFile(sl,"nhanvien.txt");
    display(sl);

    printf("\n1. Liet ke danh sach co bao nhieu nhan vien nu co luong lon hon 10 trieu.");
    printf("\n2. Xoa 1 nhan vien co ma so bang x, x nhap tu ban phim.");
    printf("\n3. Them nhan vien moi co luong hon 7 trieu.");
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
            
        }
        
        default:
            break;
        }
    } while (nhap != 0);
    
}
void init(Slist &sl)
{
    sl.head = sl.tail = NULL;
}
bool isEmpty(Slist sl)
{
    return sl.head == NULL;
}
Node *createNode(NhanVien nv)
{
    Node *p = new Node;
    if (p != NULL)
    {
        p -> info = nv;
        p -> next = NULL;
    }
    return p;
}

void addHeadSlist( Slist &sl,Node *p)
{
    if (isEmpty(sl))
    {
        sl.head = sl.tail = p;
    }
    else
    {
        p -> next = sl.head;
        sl.head == p;
    }
}
void addTailSList(Slist &sl, Node *p)
{
    if(isEmpty(sl))
    {
        sl.head = sl.tail = p;
    }
    else{
        sl.tail -> next = p; 
        sl.tail = p;
    }
}
void inputSListFromFile(Slist &sl, char fileName[]);