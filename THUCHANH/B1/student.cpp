#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Student
{
    char sbd[6];
    char hoTen[26];
    float toan, ly, anhVan;
};
Student s;
float dtb(Student &s){
	return (s.anhVan + s.toan +s.ly) /3;
}
float sum(Student &s )
{
    return s.toan + s.ly + s.anhVan;
}
struct Node
{
    Student info;
    Node *next;
};
struct SList
{
    Node *head;
    Node *tail;
};
void menu();
void init(SList &sl);
bool isEmpty(SList sl);
Node *createNode(Student s);
void output1Student(Student s);
void read1Student(FILE *f, Student &s);
void ouputTilte();
void addHeadSList(SList &sl, Node *p);
void addTailSList(SList &sl, Node *p);
void inputSListFromFile(SList &sl, char fileName[]);
void display(SList sl);
void delelteHeadSList(SList &sl);
void delelteTailSList(SList &sl);
void deleteAfterNode(SList &l, Node *q);
void topK(SList sl, int k);
void cau4(SList sl);
void cau5(SList sl);
void swap(Student &a, Student &b);
void cau6(SList sl);
void cau7(SList sl);
void cau8(SList &sl);
int main()
{
    menu();
    return 0;
}

void menu()
{
    SList sl;
    Student s;
    init(sl);
    inputSListFromFile(sl,"sinhvien.txt");
    display(sl);

    printf("\n1. Tra cuu thong tin thi sinh dua tren ma so ");
    printf("\n2. Hien thi top k co tong diem cao nhat (thu tu tu cao xuong thap, k la gia tri nhap vao)");
    printf("\n3. Sap xep danh sach diem toan tang dan");
    printf("\n4. Sap xep diem trung binh thi sinh giam dan theo danh sach ");
    printf("\n5. Xoa tat ca cac thi sinh nho hon diem chuan");
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
            printf("\n\t\t\t\tThong tin sinh vien can tim\n");
            cau4(sl);
            break;
        }
        case 2:
        {
            int k;
            printf("Nhap top k : ");
            scanf("%d",&k);
            cau7(sl);
            display(sl);
            printf("\n\t\tTop %d\n", k);
            topK(sl,k);
            break;
        }
        case 3:
        {
            printf("\n\t\t\tDanh sach sinh vien duoc sap xep tang dan theo diem toan\n");
            cau6(sl);
            display(sl);
            break;
        }
        case 4:
        {
            float dtb = (s.toan + s.ly + s.anhVan) /3;
            printf("\n\t\t\tDanh sach sinh vien duoc sap xep giam dan theo diem trung binh\n");
            cau7(sl);
            display(sl);
            break;
        }
        case 5:
        {
            printf("\n\t\t\tDanh sach sinh vien sau khi theo diem chuan \n");
            cau8(sl);
            display(sl);
            break;
        }
        default:
            break;
        }
    } while (nhap != 0);
}
void init(SList &sl)
{
    sl.head = sl.tail = NULL;
}
bool isEmpty(SList sl)
{
    return sl.head == NULL;
}
Node *createNode(Student s)
{
    Node *p = new Node;
    if (p != NULL)
    {
        p -> info = s;
        p -> next = NULL;
    }
    return p;
}
void output1Student(Student s)
{
    printf("%-10s%-20s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n",s.sbd,s.hoTen,s.toan,s.ly,s.anhVan,dtb(s),sum(s));
}
void read1Student(FILE *f, Student &s)
{
    fscanf(f,"%s%s%f%f%f",&s.sbd,&s.hoTen,&s.toan,&s.ly,&s.anhVan);
}
void ouputTilte()
{
    printf("%-10s%-20s%5s%10s%10s%10s%10s\n","SoBaoDanh","HoTen","Toan","Ly","AnhVan","DiemTB","DiemTong");
}
void addHeadSList(SList &sl, Node *p)
{
    if (isEmpty(sl))
    {
        sl.head = sl.tail = p;
    }
    else{
        p -> next = sl.head;
        sl.head = p;
    }
}
void addTailSList(SList &sl, Node *p)
{
    if(isEmpty(sl))
    {
        sl.head = sl.tail = p;
    }
    else
    {
        sl.tail -> next = p;
        sl.tail = p;
    }
}
void inputSListFromFile(SList &sl, char fileName[])
{
    FILE *f = fopen (fileName,"rt");
    if(f != NULL)
    {
        int n;
        fscanf(f,"%d",&n);
        Student s;
        for (int i = 0; i < n; i++)
        {
            read1Student(f,s);
            addTailSList(sl,createNode(s));
        }
        fclose(f);
    }
}
void display(SList sl)
{
    ouputTilte();
    Node *p = sl.head;
    while (p != NULL)
    {
        output1Student(p -> info);
        p = p -> next;
    }
}
void delelteHeadSList(SList &sl)
{
    if (isEmpty(sl))
    {
        return;
    }
    Node *p = sl.head;
    sl.head = p -> next;
    if (sl.head == NULL)
    {
        sl.tail = NULL;
        delete p;
    }
}
void delelteTailSList(SList &sl)
{
    if (sl.head == NULL)
    {
        return ;
    }
    else
    {
        Node *temp = sl.head;
        Node *temp2 = sl.tail;
        while (temp -> next != temp2)
        {
            temp = temp -> next;
        }
        temp -> next = NULL;
        temp = sl.tail;
        delete temp2;
    }
}
void cau4(SList sl)     // Tra cứu thông tin thí sinh
{
    char x[6];
    printf("\nNhap so bao danh can tim : ");
    scanf("%s",x);
    for(Node *i = sl.head;i != NULL ; i = i -> next)
    {
        if (strcmp(i->info.sbd,x)== 0)
        {
            ouputTilte();
            output1Student(i -> info);
            // display(i -> info);
            return;
        }
        
    }
    printf("Khong ton tai thi sinh co SBD : %s",x);
}
void cau5(SList &sl)
{
    int x;
    printf("Nhap top k : ");
}
void swap(Student &a, Student &b)
{
    Student temp = a;
    a = b;
    b = temp;
}
void cau6(SList sl) // Interchage Sort 
{
    for(Node *i = sl.head ; i != sl.tail; i = i -> next)
    {
        for(Node *j = i ->next ; j != NULL ; j = j -> next)
        {
            if(i -> info.toan > j -> info.toan)
            swap(i -> info, j -> info);
        }
    }
}
void cau7(SList sl) // Sắp xếp sinh viên theo điểm tb giảm dần 
{
    for(Node *i = sl.head ; i != sl.tail; i = i -> next)
    {
        for(Node *j = i -> next ; j != NULL ; j = j -> next)
        {
            if(dtb(i->info) < dtb(j->info))
            swap(i -> info, j -> info);
        }
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
void cau8(SList &sl)
{
    int x;
    Student s;
    printf("\nNhap diem chuan : ");
    scanf("%d",&x);
    Node *q = sl.head;
    while (q -> next != sl.tail)
    {
        if (sum(q -> next -> info) < x)
        {
            deleteAfterNode(sl,q);
            continue;
        }
        q = q -> next;
    }
    if(sum(sl.head -> info) < x) {
        delelteHeadSList(sl);
    }
    if(sum(sl.tail -> info ) < x)
    {
        delelteTailSList(sl);
    }
}
void topK(SList sl, int k)
{
    ouputTilte();
    int flag = 0;
    for(Node *p = sl.head; p != NULL; p = p -> next)
    {
        output1Student(p -> info);
        flag++;
        if(flag == k)
            return;
    }
}