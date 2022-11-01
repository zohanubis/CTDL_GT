#include "stdio.h"
#include "conio.h"
#include "time.h"
#include "stdlib.h"

struct QNode
{
    int info;
    QNode *next;
};

struct Queue
{
    QNode *head;
    QNode *tail;
};

QNode *createNode(int x)
{
    QNode *q = new QNode;
    if (q == NULL)
    {
        printf("\n\tKhong du bo nho de cap phat !");
        return NULL;
    }
    q -> info = x;
    q -> next = NULL;
    return q;
}

void initQueue(Queue &q);
int isEmpty(Queue q);
void insert(Queue &q, QNode *p);
int remove(Queue &q);
void showQueue(Queue q);
void screenMessage(Queue &q, int b[50], int n, int k);
int daoNguoc(Queue q, int a[50]);
// main 
int main()
{
    int n, b[50], k;
    printf("Nhap so luong dien thoai : "); scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("\n\tNhap sdt thu %d : ", i+1); scanf("%d",&b[i]);
    }
    printf("\nNhap so luong tin nhan muon hien thi : "); scanf("%d",&k);
    printf("\n\tDanh sach sdt : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",b[i]);
    }
    printf("\n\tk : %d",k);
    Queue q;
    initQueue(q);
    screenMessage(q,b,n,k);
    int a[50];
    int m = daoNguoc(q,a);
    printf("\n\tSdt hien thi tren man hinh : ");
    for (int i = 0; i < n; i++)
    {
        printf("\n\t\t\t%d",a[i]);
    }
    getch();
}
// Ham xu li
void initQueue(Queue &q)
{
    q.head = q.tail = NULL;
}
int isEmpty(Queue q)
{
    return (q.head == NULL);
}
void insert(Queue &q, QNode *p)
{
    if (p == NULL){
        return;
    }
    else
    {
        if (isEmpty(q))
        {
            q.head = q.tail = p;
        }
        else
        {
            q.tail -> next = p;
            q.tail = p;
        }
    }
}
int remove(Queue &q)
{
    if (q.head == NULL)
    {
        return NULL;
    }
    else{
        QNode *temp = q.head;
        q.head = q.head -> next;
        temp -> next = NULL;
        int x = temp -> info;
        delete temp;
        return x;
    }
}
void showQueue(Queue q)
{
    QNode *temp = q.head;
    while (temp != NULL)
    {
        printf("%d ",temp -> info);
        temp = temp -> next;
    }
}
int checkTrung(Queue q, int x)
{
    QNode *temp = q.head;
    int flag = 0;
    while (temp != NULL)
    {
        if (x = temp -> info)
        {
            flag = 1;
        }
        temp = temp -> next;
    }
    return flag;
}
void screenMessage(Queue &q, int b[50], int n, int k)
{
    int count = 0;
    QNode *p;
    for (int i = 0; i < n; i++)
    {
        if (count == k)
        {
            if (checkTrung(q,b[i]) != 0){
                continue;
            }
            remove(q);
            p = createNode(b[i]);
            insert(q,p);
        }
        else
        {
            if(isEmpty(q)){
                p = createNode(b[i]);
                insert(q,p);
                count++;
            }
            else{
                int flag = checkTrung(q,b[i]);
                if (flag == 0){
                    p = createNode(b[i]);
                    insert(q,p);
                    count++;
                }
            }
        }
    }
}
int daoNguoc(Queue q, int a[50])
{
    QNode *temp = q.head;
    int count = 0;
    while (temp != NULL)
    {
        count ++;
        temp = temp -> next;
    }
    temp = q.head;
    int i = 0;
    while( temp != NULL)
    {
        a[count - i - 1] = temp ->info; i++;
        temp = temp -> next;
    }
    return i;
}