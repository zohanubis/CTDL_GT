#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Student
{
    char ma[12];
    char hoTen[25];
    char lop[25];
    float toan,ly,hoa;
};
Student st;
float dtb(Student &st)
{
    return(st.toan + st.ly +st.ly)/3;
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
Node *createNode(Student st);
void ouputTitle();
void read1Student(FILE *f, Student &st);
void output1Student(Student st);
void display(SList sl);
void addHeadSList(SList &sl, Node *p);
void addTailSList(SList &sl, Node *p);
void deleteHeadSList(SList &l);
void deleteTailSList(SList &l);
void deleteAfterNode(SList &sl, Node *q);
void inputSListFromFile(SList &sl, char fileName[]);

int main()
{
    menu();
    return 0;
}

void menu()
{
    SList sl;
    Student st;
    init(sl);
    inputSListFromFile(sl,"sinhvien.txt");
    display(sl);

    printf("\n1. Xuat thong tin cac sinh vien ra man hinh ");
    printf("\n2. Tinh diem trung binh cua sinh vien");
    printf("\n3. Sap xep giam theo khoa");
    printf("\n4. Them sinh vien vao sau mot sinh vien");
    printf("\n5. Xoa sinh vien co ten nhap tu ban phim ");
    printf("\n6. Dem so sinh vien thuoc khoa X");
    
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

            break;
        }
        case 2:
        {
            
            break;
        }
        case 3:
        {
            
            break;
        }
        case 4:
        {
            
            break;
        }
        case 5:
        {
            
            break;
        }
        case 6:
        {
            
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
Node *createNode(Student st)
{
    Node *p = new Node;
    if (p != NULL)
    {
        p -> info = st;
        p -> next = NULL;
    }
    return p;
}

void addHeadSList( SList &sl,Node *p)
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
void addTailSList(SList &sl, Node *p)
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
void deleteHeadSList(SList &sl)
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
void deleteTailSList(SList &l)
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
void deleteAfterNode(SList &sl, Node *q)
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
void outputTitle()
{
    printf("%-10s%-20s%10s%10s%10s%10s%10s\n", "MaSinhVien", "TenSinhVien", "Lop","Toan", "Ly","Hoa","DiemTB");
}
void read1Student(FILE *f, Student &st)
{
    fscanf(f,"%s%s%s%f%f%f",&st.ma,&st.hoTen,&st.lop,&st.toan,&st.ly,&st.hoa);
}
void output1Student(Student st)
{
    printf("%-10s%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.2f\n",st.ma,st.hoTen,st.lop,st.toan,st.ly,st.hoa,dtb(st));
}
void display(SList sl)
{
    outputTitle();
    Node *p = sl.head;
    while (p != NULL)
    {
        output1Student( p -> info);
        p = p -> next;
    }
}
void inputSListFromFile(SList &sl, char fileName[])
{
    FILE *f = fopen (fileName,"rt");
    if (f != NULL)
    {
        int n;
        fscanf(f,"%d",&n);
        Student st;
        for (int i = 0; i < n; i++)
        {
            read1Student(f,st);
            addTailSList(sl,createNode(st));
        }
        fclose(f);
    }
}