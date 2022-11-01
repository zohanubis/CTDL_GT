#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct NhanVien
{
    char ma[11];
    char ten[31];
    char gioiTinh[5];
    float luong;
    int ngay,thang,nam;
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
void output1NhanVien(NhanVien nv);
void outputTiltle();
void read1NhanVien(FILE *f, NhanVien &nv);
void display(Slist sl);
void addHeadSlist(Slist &sl, Node *p);
void addTailSlist(Slist &sl, Node *p);
void addAfterNodeSlist(Slist &sl, Node *q, Node *p);
void deleteHeadSlist(Slist &l);
void deleteTailSlist(Slist &l);
void deleteAfterNode(Slist &sl, Node *q);

void inputSListFromFile(Slist &sl, char fileName[]);
void add1NhanVien(NhanVien &nv);
void addEmployee(Slist &sl);

// main
int main()
{
    menu();
    return 0;
}
void menu()
{
    Slist sl;
    NhanVien nv;
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
        case 3:
        {
            printf("Danh sach sau khi them :\n");
            add1NhanVien(nv);
            themSachXtruocSachCoGiaTriNhoHon50000_C2(sl,createNode(nv));
            display(sl);
            // addEmployee(sl);
            // display(sl);
            break;
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
void deleteHeadSlist(Slist &sl)
{
    if(sl.head == NULL)
    {
        return;
    }

    else {
        Node *temp = sl.head;
        sl.head = sl.head -> next;
        temp ->next = NULL;
        delete temp;
    }
}
void deleteTailSlist(Slist &l)
{
    if (l.head == NULL)
    {
        return ;
    }
    else
    {
        Node *temp = l.head;
        Node *temp2 = l.tail;
        while (temp -> next != temp2)
        {
            temp = temp -> next;
        }
        temp -> next = NULL;
        temp = l.tail;
        delete temp2;
    }
}
void deleteAfterNode(Slist &sl, Node *q)
{
    if(isEmpty(sl) || q == NULL || q -> next == NULL){
        return;
    }
    Node *p = q -> next;
    q -> next = p -> next;
    if (sl.tail == p)
    {
        sl.tail = q;
        delete p;
    }
}
void read1NhanVien(FILE *f, NhanVien &nv)
{
    fscanf(f,"%s%s%d%d%d%s%f",&nv.ma,&nv.ten,&nv.ngay,&nv.thang,&nv.nam,&nv.gioiTinh,&nv.luong);
}
void output1NhanVien(NhanVien nv)
{
    
    printf("%-10s%-20s%d/%d/%-15d%-5s%.2f\n",nv.ma,nv.ten,nv.ngay,nv.thang,nv.nam,nv.gioiTinh,nv.luong);
}
void outputTiltle()
{
    printf("%-10s%-20s%10s%10s%10s\n", "MaNhanVien", "TenNhanVien", "NgayThangNam","GioiTinh", "Luong");
}
void inputSListFromFile(Slist &sl, char fileName[])
{
    FILE *f = fopen (fileName,"rt");
    if (f != NULL)
    {
        int n;
        fscanf(f,"%d",&n);
        NhanVien nv;
        for (int i = 0; i < n; i++)
        {
            read1NhanVien(f,nv);
            addTailSList(sl,createNode(nv));
        }
        fclose(f);
    }
}
void display(Slist sl)
{
    outputTiltle();
    Node *p = sl.head;
    while (p != NULL)
    {
        output1NhanVien( p -> info);
        p = p -> next;
    }
}
void add1NhanVien(NhanVien &nv)
{
    printf("\nNhap nhan vien : \n");
    printf("\tMa Nhan Vien : "); scanf("%s",&nv.ma);
    printf("\tTen Nhan Vien : "); scanf("%s",&nv.ten);
    printf("\tNgay Sinh : "); scanf("%d",&nv.ngay);
    printf("\tThang Sinh : "); scanf("%d",&nv.thang);
    printf("\tNam Sinh : "); scanf("%d",&nv.nam);
    printf("\tGioi Tinh : "); scanf("%s",&nv.gioiTinh);
    printf("\tLuong : "); scanf("%f",&nv.luong);
}
void addAfterNodeSlist(Slist &sl, Node *q, Node *p)
{
    if(sl.head == p)
    {
        addHeadSlist(sl,p);
    }
    else{
        Node * temp = sl.head;
        while (temp -> next != p)
        {
            temp = temp -> next;
        }
        temp -> next = q;
        q -> next = p;
    }
}
bool DieuKienCau6(NhanVien nv)
{
    return nv.luong > 7000000;
}
void addEmployee(Slist &sl)
{
    NhanVien nv;
    add1NhanVien(nv); 
    int count = 0;
    for(Node *p = sl.head ; p != NULL ; p = p -> next){
        if(DieuKienCau6(p -> info))
        {
            Node *z = createNode(nv);
            addAfterNodeSlist(sl,z,p);
            count++;
        }
    }
    if (count == 0)
    {
        printf("Khong tim thay ");
    }
}
void themSachXtruocSachCoGiaTriNhoHon50000_C2(Slist& sl,Node* p)
{
    if (isEmpty(sl) || p == NULL) return;
    else
    {
        Node* q = NULL, *p = sl.head;
        while (p != NULL && !DieuKienCau6(p->info))
        {
            q = p;
            p = p->next;
        }
        if (q == NULL)
            addHeadSlist(sl, p);
        else
        {
            if (p != NULL)
                addAfterNodeSlist(sl, q, p);
        }}
}