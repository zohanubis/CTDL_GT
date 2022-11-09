#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct Song
{
    char id[11];
    char nameSong[51];
    char nameSinger[51];
    char nameWriter[51];
    int time;
    float salary;
};
Song s;
struct Node
{
    Song info;
    Node *next;
};
struct Slist
{
    Node *head;
    Node *tail;
};
void menu();
void init(Slist &sl);
bool isEmpty(Slist sl);
Node *createNode(Song s);
void swap(Song &a, Song &b);
void inputSlistFromFile(Slist &sl, char fileName[]);
void read1Song(FILE *f, Song &s);
void output1Song(Song s);
void outputTilte();
void display(Slist sl);
// Câu 4
void cau4(Slist sl); 
void addHeadSlist(Slist &sl, Node *q);
void addTailSlist(Slist &sl,Node *p);
// Câu 5
void deleteHeadSList(Slist &sl);
void deleteTailSList(Slist &sl);
void deleteAfterNode(Slist &sl, Node *q);
void deleteSong(Slist &sl);
// Câu 6
void chenXTruocY(Slist &sl, Node *q, Node *p);
void add1Song(Song &s);
void addSong(Slist &sl);
// main
int main(){
    menu();
    return 0;
}
void menu()
{
    Slist sl; Song s;
    init(sl);
    inputSlistFromFile(sl,"song.txt");
    display(sl);

    printf("\n1. Sap xep danh sach cac bai hat theo thu tu tu dien cua bai hat \n");
    printf("\n2. Xoa tat ca cac bai hat co thoi luong nho hon 60 giay\n");
    printf("\n3. Them bai hat X truoc bai hat co gia tien lon hon 50000\n");
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
            printf("\n\t\tDanh sach sau khi sap xep ten bai hat ");
			cau4(sl);
			display(sl);
            break;
        }
        case 2:
        {
			printf("\n\t\tDanh sach sau khi xoa nhung bai hat duoi 60s");
            deleteSong(sl);
			display(sl);
            break;
        }
        case 3:
        {
            addSong(sl);
			display(sl);
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
Node *createNode(Song s)
{
    Node *p = new Node;
    if (p != NULL)
    {
        p -> info = s;
        p -> next = NULL;
    }
    return p;
}
void inputSlistFromFile(Slist &sl, char fileName[])
{
    FILE *f = fopen (fileName, "rt");
    if (f != NULL)
    {
        int n;
        fscanf(f,"%d",&n);
        Song s;
        for (int i = 0; i < n; i++)
        {
            read1Song(f,s);
            addTailSlist(sl,createNode(s));
        }
        fclose(f);
    }
    
}
void read1Song(FILE *f, Song &s)
{
    fscanf(f,"%s%s%s%s%d%f",&s.id,&s.nameSong,&s.nameSinger,&s.nameWriter,&s.time,&s.salary);
}
void output1Song(Song s)
{
    printf("%-15s%-10s%-10s%-10s%-10d%10.2f\n",s.id,s.nameSong,s.nameSinger,s.nameWriter,s.time,s.salary);
}
void outputTilte()
{
    printf("%-15s%-10s%-10s%5s%5s%10s\n","MaBaiHat","TenBaiHat","TenCaSi","TenTacGia","ThoiLuong","GiaTien");
}
void display(Slist sl)
{
    outputTilte();
    Node *p = sl.head;
    while (p != NULL)
    {
        output1Song(p -> info);
        p = p -> next;
    }
}
// Câu 4
void swap(Song &a, Song &b)
{
    Song temp = a;
    a = b;
    b = temp;
}
void cau4(Slist sl)
{
    char *x;
    for(Node *i = sl.head ; i != sl.tail ; i = i -> next){
        for(Node *j = i -> next ; j != NULL ; j = j -> next){
            if(strcmp(i -> info.nameSong, j -> info.nameSong) > 0){
                swap(i -> info , j -> info);
            }
        }
    }
}
void addHeadSlist(Slist &sl, Node *q)
{
    if (isEmpty(sl)){
        sl.head = sl.tail = q;
    }
    else{
        q -> next = sl.head;
        sl.head = q;
    }
}
void addTailSlist(Slist &sl,Node *p)
{
    if(isEmpty(sl)){
        sl.head = sl.tail = p;
    }
    else{
        sl.tail -> next = p;
        sl.tail = p;
    }
}
// Câu 5
void deleteHeadSList(Slist &sl)
{
    if(isEmpty(sl)){
        return ;
    }
    Node *p = sl.head;
    sl.head = p -> next;
    if(sl.head == NULL){
        sl.tail = NULL;
        delete p;
    }
}
void deleteTailSList(Slist &sl)
{
    if(sl.head == NULL){
        return;
    }
    else{
        Node *temp = sl.head;
        Node *temp2 = sl.tail;

        while (temp -> next != temp2){
            temp = temp -> next;
        }
        temp -> next = NULL;
        temp = sl.tail;
        delete temp2;
    }
}
void deleteAfterNode(Slist &sl, Node *q)
{
    if(isEmpty(sl) || q == NULL || q -> next == NULL)
        return;
    Node *p = q -> next;
    q -> next = p -> next;
    
    if(sl.tail == p)
        sl.tail = q;
        delete p;
}
bool DieuKienCau5(Song s)
{
    return  s.time < 60;
}
void deleteSong(Slist &sl)
{
    if(isEmpty(sl))
        return;
    else{
        while(DieuKienCau5(sl.head -> info)){
            deleteHeadSList(sl);
        }
        Node *q = sl.head;
        while(q -> next != NULL){
            if(DieuKienCau5(q -> next -> info)){
                deleteAfterNode(sl,q);
            }
            else{
                q = q -> next;
            }
        }
    }
}
// Câu 6
bool DieuKienCau6(Song s){
    return s.salary > 50000;
}
void chenXTruocY(Slist &sl, Node *q, Node *p)
{
    if(sl.head == p){
        addHeadSlist(sl,q);
    }
    else{
        Node *temp = sl.head;
        while(temp -> next != p){
            temp = temp -> next;
        }
        temp -> next = q;
        q -> next = p;
    }
}
void add1Song(Song &s)
{
    printf("\nNhap bai : \n");
    printf("\tMa bai hat : "); scanf("%s",&s.id);
	printf("\tTen bai hat : "); scanf("%s",&s.nameSong);
    printf("\tTen ca si : "); scanf("%s",&s.nameSinger);
	printf("\tTen tac gia : "); scanf("%s",&s.nameWriter);
    printf("\tThoi Luong : "); scanf("%d",&s.time);
	printf("\tGia Ban : "); scanf("%f",&s.salary);
}
void addSong(Slist &sl){
    Song s;
    add1Song(s);
    int count = 0;
    for(Node *p = sl.head ; p != NULL ; p = p -> next){
        if(DieuKienCau6(p -> info)){
            Node *z = createNode(s);
            chenXTruocY(sl,z,p);
            count++;
        }
    }
    if(count == 0){
        printf("Khong tim thay");
    }
}





