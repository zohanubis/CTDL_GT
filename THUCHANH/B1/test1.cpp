#include "stdio.h"
#include "stdlib.h"

struct Book{
    char ma[11];
    char ten[31];
    int soTrang;
    float giaBan;
    int namXB;
};
void output1Book(Book x)
{
    printf("%-10s%-20s%10d%10.2f%10d\n", x.ma, x.ten, x.soTrang, x.giaBan,x.namXB);

}
void doc1Book(FILE* fp, Book& x)
{
    fscanf(fp,"%s%s%d%f%d", &x.ma, &x.ten, &x.soTrang, &x.giaBan,&x.namXB);
}
void xuatTieuDe()
{
printf("%-10s%-20s%10s%10s%10s\n", "MaSach", "TenSach", "SoTrang","GiaBan", "NamXB");
}

struct Node
{
    Book data;
    Node* next;
};
struct List
{
    Node* head;
    Node* tail;
};

void init(List& list)
{
    list.head = list.tail = NULL;
}

bool isEmpty(List list)
{
    return list.head == NULL;
}

Node* createNode(Book newData)
{
    Node* p = new Node;
    if (p != NULL)
    {
    p->data = newData;
    p->next = NULL;
    }
    return p;
}

void addHead(List& list, Node* pNew)
{
    if (isEmpty(list))
    {
        list.head = list.tail = pNew;
    }
    else
    {
        pNew->next = list.head;
        list.head = pNew;
    }
}

void addTail(List& list, Node* pNew)
{
    if (isEmpty(list))
    {
        list.head = list.tail = pNew;
    }
    else
    {
        list.tail->next = pNew;
        list.tail = pNew;
    }
}
void inputListFromFile(List& list,char fileName[])
{
    FILE* fp = fopen(fileName, "rt"); //r: read, t: text
    if (fp != NULL)
    {
        int n;
        fscanf(fp, "%d", &n);
        Book x;
        for (int i = 0; i < n; i++)
        {
        doc1Book(fp, x);
        addTail(list, createNode(x));
        }
    fclose(fp);
    }
}
void traverse(List list)
{
    xuatTieuDe();
    Node *p = list.head;
    while (p != NULL)
    {
        output1Book(p -> data);
        p = p -> next;
    }
}

void deleteList(List& list)
{
    Node* p;
    while (!isEmpty(list))
    {
        p = list.head;
        list.head = p->next;
        delete p;
    }
    list.head = list.tail = NULL;
}
bool isThoaDKCau4(Book x)
{
	return x.soTrang > 500 && x.namXB < 2018;
}
int demSach(List list)
{
	int dem = 0;
	Node* p = list.head;
	while (p != NULL)
	{
		if (isThoaDKCau4(p->data))
		dem++;
	p = p->next;
		}
	return dem;
}
bool isThoaDKCau5(Book x)

{
	return x.giaBan > 100000;
}
void removeHead(List& list)
	{
		if (isEmpty(list)) return;
		else
		{
		Node* p = list.head;
		list.head = p->next;
		if (list.head == NULL)
		list.tail = NULL;
		delete p;
		}	
}
void removeAfter(List& list, Node* q)
{
    if (isEmpty(list) || q == NULL || q->next == NULL) return;
    else
    {
    Node * p = q->next;
    q->next = p->next;
    if (list.tail == p)
    list.tail = q;
    delete p;
	}
}
void xoaSachThoaDK(List& list)
{
    if (isEmpty(list)) 
        return;
    else
    {
        while (isThoaDKCau5(list.head->data))
            removeHead(list);
        Node* q = list.head;
        while (q->next != NULL)
        {
            if (isThoaDKCau5(q->next->data))
                removeAfter(list, q);
            else
            q = q->next;
        }
    }
}
void chenXTruocY(List &list, Node *p , Node *q)
{
    if (list.head == q)
    {
        addHead(list,p);
    }
    for(Node *i = list.head; i -> next != NULL ; i = i -> next)
    {
        if (i -> next == q)
        {
            p -> next = i -> next;
            i -> next = p;
        }
    }
}
void them1Book(Book &x)
{
    printf("\n\tNhap sach : ");
    scanf("%s%s%d%f%d",&x.ma,&x.ten,&x.soTrang,&x.giaBan,&x.namXB);
}
bool isThoaDKCau6(Book x)
{
    return x.giaBan < 50000;
}
void addBook(List &list)
{
    Book x;
    them1Book(x);
    Node *B = createNode(x);
    int count = 0;
    for(Node *p = list.head; p -> next != NULL; p = p -> next)
    {
        if (isThoaDKCau6(p-> next -> data))
        {
            chenXTruocY(list,B,p);
            count++;
        }
        if (count == 0)
        {
            printf("Khong tim thay !");
        }
        
    }
}
int main()
{
	List list;
	init(list);
	inputListFromFile(list, "cuonsach.txt");
	traverse(list);
	int dem = demSach(list);
	printf("So sach thoa dk: %d", dem);
	printf("\n\tSau khi xoa: \n");
	xoaSachThoaDK(list);
	traverse(list);
	
	addBook(list);
    traverse(list);
    deleteList(list);
	system("pause");
}