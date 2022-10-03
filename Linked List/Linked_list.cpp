#include "stdio.h"
#include "conio.h"

struct Node
{
    int info, count;
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
    if(q==NULL)
    {
        printf("Khong du bo nho de cap phat");
        return NULL;
    }
    q->info =x;
    q->next=NULL;
    return q;
}
void menu();
void createList(Slist &l, int n);
void printList(Slist l);
void addHeadSList(Slist &l,Node *p);
void addTailSList(Slist &l,Node *p);
void addAfterNodeSlist(Slist &l, Node *p);
void deleteHeadSlist(Slist &l);
void deleteTailSlist(Slist &l);
void interchangeSortSlistIncrease(Slist l);
void interchangeSortSlistDecrease(Slist l);
int countElementsOfSlist(Slist l);
int computeSumOfSlist(Slist l);
void printEvenElementsOfSlist(Slist l);
void printOddElementsOfSlist(Slist l);
void printElementsInEvenIndexOfSlist(Slist l);
void printElementsInOddIndexOfSlist(Slist l);
int searchXInSlist(Slist l,int x);
int countXInSlist(Slist l,int x);
Node* findMaxInSlist(Slist l);
Node* findMinInSlist(Slist l);
int findEvenMinInSlist(Slist l);
int findOddMaxInSlist(Slist l);
int findEvenMaxInSlist(Slist l);
int findOddMinInSlist(Slist l);
void deleteMaxInSlist(Slist &l);
void deleteMinInSlist(Slist &l);
void addXInSlist(Slist &l, Node *x);
int checkSlistIncrease(Slist l);
int checkSlistDecrease(Slist l);
int findLengthMaxOfSlist(Slist l);
int main()
{
    menu();
    return 0;
}
void menu()
{
    Slist l;
    int n;
    printf("Nhap so luong phan tu: "); scanf("%d", &n);
	createList(l, n);
	printf("\t1. Xuat thong tin cac phan tu trong dslk.");
	printf("\n\t2. Them node vao dslk (them o dau/giua/cuoi).");
	printf("\n\t3. Xoa node trong dslk (xoa o dau/cuoi/giua).");
	printf("\n\t4. Sap xep dslk tang/giam.");
	printf("\n\t5. Dem so phan tu cua dslk.");
	printf("\n\t6. Tinh tong cac phan tu cua dslk.");
	printf("\n\t7. Xuat cac phan tu chan/le.");
	printf("\n\t8. Xuat cac phan tu o vi tri chan/le.");
	printf("\n\t9. Tim kiem x tren dslk.");
	printf("\n\t10. Dem tren dslk l co bao nhieu x.");
	printf("\n\t11. Dem so phan tu tren dslk l.");
	printf("\n\t12. Tim phan tu max/min tren dslk.");
	printf("\n\t13. Tim so chan nho nhat tren dslk.");
	printf("\n\t14. Tim so le lon nhat tren dslk. ");
	printf("\n\t15. Tim so chan lon nhat trong dslk, neu dslk khong co so chan thi tra ve -1.");
	printf("\n\t16. Tim so le nho nhat trong dslk, neu dslk khong co so le thi tra ve 0.");
	printf("\n\t17. Xoa phan tu max/min cua dslk.");
	printf("\n\t18. Them x vao dslk sao cho x la phan tu cuc dai(lon hon cac phan tu ke no).");
	printf("\n\t19. Tim day con dai dat cua dslk.");
	printf("\n\t20. Kiem tra dslk co tang dan/ giam dan khong?");

    int thaoTac;
    do
    {
        printf("\n\nNhap 0 de thoat !");
        printf("\nNhap thao tac muon thuc hien :");
        scanf("%d", &thaoTac);
        switch (thaoTac)
        {
        case 1:
        {
            printf("\n\tDanh sach lien ket la :");
            printList(l);
            break;
        }
        case 2:
        {
            int x1, x2,x3, x4;
            printf("Nhap phan tu muon them o dau : "); scanf("%d",&x1);
            Node *q1= new Node;
            Node *q2= new Node;
            Node *q3= new Node;
            Node *p= new Node;

            q1 = createNode(x1);
            addHeadSlist(l,q1);
            printf("\n\tDanh sach sau khi them o dau : ");
            printList(l);

            q2 = createNode(x2);
            addTailSList(l,q2);
            printf("\n\tDanh sach sau khi them o cuoi : ");
            printList(l);
            printf("\nNhap phan tu q va phan tu p muon them vao sau q: "); scanf("%d%d",&x3,&x4);

            q3=createNode(x3);
            p=createNode(x4);
            addAfterNodeSlist(l,q3,p);
            printf("\n\tDanh sach sau khi them %d vao sau %d : ",p->info,q3->info);
            printList(l);
            break;
        }
        case 3:
        {
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
            break;
        }
        case 4:
        {
            interchangeSortSlistIncrease(l);
            printf("\n\tDanh sach sau khi sap xep tang : ");
            printList(l);
            interchangeSortSlistDecrease(l);
            printf("\n\tDanh sach sau khi sap xep giam : ");
            printList(l);
            break;
        }
        case 5:
        {
            printf("\n\tSo phan tu cua dslk : %d",countElementsOfSlist(l));
            break;
        }
        case 6:
        {
            printf("\n\tTong cac phan tu cua dslk : %d",computeSumOfSlist(l));
            break;
        }
        case 7:
        {
            printf("\n\tPhan tu chan trong dslk : ");
            printEvenElementsOfSlist(l);
            printf("\n\tPhan tu le trong dslk : ");
            printOddElementsOfSlist(l);
            break;
        }
        case 8:
        {
            printf("\n\tPhan tu o vi tri chan trong dslk la: ");
				printElementsInEvenIndexOfSlist(l);
				printf("\n\tPhan tu o vi tri le trong dslk la: ");
				printElementsInOddIndexOfSlist(l);
				break;
        }
        case 9 :
        {
            int x;
            printf("Nhap x muon tim trong Slist : "); scanf("%d",&x);
            
            int result = searchXInSlist (l,x);
            if (result == 1)
            {
                printf("\n\tDa tim thay !");
            }
            else
            {
                printf("\n\tKhong tim thay !");
            }
            break;
        }
        case 10 :
        {
            int x;
            printf("Nhap x muon dem trong Slist : ");scanf("%d", &x);
            printf("\n\tCo %d phan tu %d trong Slist ", countXInSlist(l,x),x);
            break;
        }
        case 11:
        {
            printf("\n\tSo luong phan tu tren dslk : %d",countElementsOfSlist(l));
            break;
        }
        case 12:
        {
            int resultMax=findEvenMaxInSlist(l);
            int resultMin=findEvenMinInSlist(l);
            printf("\n\tPhan tu max tren Slist : %d ", resultMax);
            printf("\n\tPhan tu min tren Slist : %d ", resultMin);
            break;
        }
        case 13:
        {
            printf("\n\tSo chan nho nhat tren dslk : %d", findEvenMinInSlist(l));
        }
        case 14:
        {
            printf("\n\tSo le lon nhat tren dslk : %d", findOddMaxInSlist(l));
            break;
        }
        case 15:
        {
            printf("\n\tSo chan lon nhat tren dslk : %d", findEvenMaxInSlist(l));
            break;
        }
        case 16: 
        {
            printf("\n\tSo le nho nhat tren dslk : %d",findOddMinInSlist(l));
            break;
        }
        case 17:
        {
            printf("\n\tSlist truoc khi xoa : ");
            printList(l);
            deleteMaxInSlist(l);
            printf("\n\tSlist sau khi xoa max :");
            printList(l);
            deleteMinInSlist(l);
            printf("\n\tSlist sau khi xoa min :");
            printList(l);
            break;
        }
        case 18:
        {
            int x1;
            printf("Nhap x muon them : "); scanf("%d",&x1);
            Node *x2= createNode(x1);
            printf("\n\tSlist : ");
            printList(l);
            addXInSlist(l,x2);
            printf("\n\tSlist sau khi them %d la phan tu cuc dai : ",x2->info);
            printList(l);
            break;
        }
        case 20:
        {
            int resultIncrease = checkSlistIncrease(l);
            int resultDecrease = checkSlistDecrease(l);
            if (resultIncrease == 1)
            {
                printf("\n\tDanh sach tang dan ");
            }
            else
            {
                printf("\n\tDanh sach khong tang dan");
            }
            if (resultDecrease == 1)
            {
                printf("\n\tDanh sach giam dan ");
            }
            else
            {
                printf("\n\tDanh sach khong giam dan ");
            }
            break;
        }
        default:
        {
            if (thaoTac != 0)
            {
                printf("\nThao tac khong hop le !");
            }
        }
            break;
        }
    } while (thaoTac != 0);
    
}
void createList(Slist &l, int n)
{
    int x;
    Node *q = new Node;
    l.head = l.tail = NULL;
    for (int i = 1; i <= n; i++)
    {
        printf("Nhap phan tu thu %d : ",i);
        scanf("%d",&x);
        q=createNode(x);
        if (q==NULL)
        {
            printf("Khong du bo nho de cap phat ");
            getch();
            return;
        }
        if (l.head==NULL)
        {
            l.head=l.tail=q;
        }
        else
        {
            l.tail -> next = q;
            l.tail = q;
        }
    }
}
void printList(Slist l)
{
    while (l.head != NULL)          
    {
        printf("%d ", l.head->info);
        l.head = l.head->next;
    }
}
void addHeadSlist(Slist &l, Node *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        if (l.head == NULL)
        {
            l.head= l.tail=p;
        }
        else
        {
            p->next = l.head;
            l.head=p;
        }
    }
}
void addTailSList(Slist &l, Node *p)
{
    if(p==NULL)
    {
        return;
    }
    else
    {
        if (l.head == NULL)
        {
            l.head = l.tail = p;
        }
        else
        {
            l.tail-> next =p; 
            l.tail=p;
        }  
    }
}
void addAfterNodeSlist(Slist &l, Node *q, Node *p)
{
    Node *temp = new Node;
    temp = q;
    q=l.head;
    
    while (q->info != temp -> info)
    {
        q = q -> next;
    }
    if (q== NULL || p == NULL)
    {
        return;
    }
    else
    {
        if (l.head == NULL)
        {
            l.head = l.tail =p;
        }
        else
        {
            if ((q==l.tail))
            {
                addTailSList(l,p);
            }
            else
            {
                p->next = q->next;
                q->next=p;
            }
        }
    }
}
void deleteHeadSlist(Slist &l)
{
    if (l.head  == NULL)
    {
        return;
    }
    else
    {
        Node *temp = l.head;
        l.head= l.head->next;
        temp->next = NULL;
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
void deleteMidSlist(Slist &l, Node *q)
{
    Node *temp = q;
    q = l.head;
    while (q->info != temp -> info)
    {
        q=q->next;
    }
    if (l.head == NULL || q == NULL || q == l.tail)
    {
        return ;
    }
    else
    {
        if (q-> next == l.tail)
        {   
            Node *p = q -> next;
            q -> next = p ->next;
            p -> next = NULL;
            delete p;
        }
    }
}
void interchangeSortSlistIncrease(Slist l)
{
    for (Node* p = l.head; p != l.tail; p = p -> next)
    {
        for (Node* q = p -> next; q != NULL; q = q -> next)
        {
            if (p -> info < q -> info)
            {
                int temp = p -> info;
                p -> info = q -> info;
                q -> info = temp;
            }
         }
    }
}
void interchangeSortSlistDecrease(Slist l)
{
    for(Node *p = l.head; p != l.tail; p = p -> next)
    {
        for(Node *q = p->next; q != NULL ; q = q -> next)
        {
            if (p -> info > q -> info)
            {
                int temp = p -> info;
                p -> info = q -> info; 
                q -> info = temp;
            }
        }
    }
}
int countElementsOfSlist(Slist l)
{
    int count = 0;
    Node *temp = l.head;
    while (temp )   // temp == NULL
    {
        temp = temp -> next;
        count++;
    }
    return count;
}
int computeSumOfSlist(Slist l)
{
    int sum = 0;
    Node *temp= l.head;
    while (temp)    // temp == NULL
    {
        sum += temp -> info;
        temp = temp -> next;
    }
    return sum;
}
void printEvenElementsOfSlist(Slist l)
{
    if (l.head == NULL)
    {
        return ;
    }
    else
    {
        Node *temp = l.head;
        while (temp)
        {
            if(temp -> info % 2 == 0)
            {
                printf("%d ", temp -> info );
            }
            temp = temp -> next;
        }
    }
}
void printOddElementsOfSlist(Slist l)
{
    if(l.head == NULL)
    {
        return ;
    }
    else
    {
        Node* temp = l.head;
        while (temp)
        {
            if(temp -> info  % 2 != 0)
            {
                printf("%d ", temp -> info );
            }
            temp = temp -> next;
        }
    }
}
void printElementsInEvenIndexOfSlist(Slist l)
// Tức là tìm info của giá trị không phải tìm link
{
    int count = 0;
    if (l.head == NULL)
    {
        return; 
    }
    else
    {
        Node *temp = l.head;
        while (temp)
        {
            count++;
            if (count % 2 == 0)
            {
                printf("%d ", temp -> info);
            }
            temp = temp -> next;
        }
    }
}
void printElementsInOddIndexOfSlist(Slist l)
// Tức là tìm info của giá trị không phải tìm link
{
    int count = 0;
    if (l.head = NULL)
    {
        return ;
    }
    else
    {
        Node *temp = l.head;
        while (temp)
        {
            count++;
            if(count % 2 != 0)
            {
                printf("%d ", temp -> info);
            }
            temp = temp -> next;
        }
    }
}
int searchXInSlist(Slist l, int x)
{
    Node *temp = l.head;
    while (temp)
    {
        if(temp -> info == x)
        {
            return 1;
        }
        temp = temp -> next;
    }
    return -1;
}
int countXInSlist(Slist l, int x)
{
    int count = 0;
    Node *temp= l.head;
    while (temp)
    {
        if (temp -> info == x)
        {
            count++;
        }
    }
    temp = temp -> next;
}
Node *findMaxInSlist(Slist l)
{
    Node *max= l.head;
    Node *temp =l.head;
    while (temp)
    {
        if(temp -> info > max -> info)
        {
            max = temp;
        }
        temp = temp -> next;
    }
    return max;
}
Node *findMinInSlist(Slist l)
{
    Node *min= l.head;
    Node *temp = l.head;
    while (temp)
    {
        if(temp -> info < min -> info)
        {
            min = temp;
        }
        temp = temp ->next;
    }
    return min;
}
int findFirstEvenElementsInSlist(Slist l)
{
    Node *temp = l.head;
    while (temp)
    {
        if(temp -> info % 2 == 0)
        {
            return temp -> info;
        }
        temp = temp -> next;
    }
    return -1;
}
int findEvenMinInSlist(Slist l)
{
    int evenMin= findFirstEvenElementsInSlist(l);
    Node *temp =l.head;
    while(temp)
    {
        if(temp -> info % 2 == 0)
        {
            if (temp -> info < evenMin)
            {
                evenMin = temp -> info;
            }
        }
        temp = temp -> next;
    }
    return evenMin;
}
int findFirstOddElementsInSlist(Slist l)
{
    Node *temp = l.head;
    while (temp)
    {
        if(temp -> info % 2 != 0)
        {
            return temp -> info;
        }
        temp = temp -> next;
    }
    return 0;
}
int findOddMaxInSlist(Slist l)
{
    int oddMax = findFirstOddElementsInSlist(l);
    Node *temp = l.head;
    while (temp)
    {
        if(temp -> info % 2 != 0)
        {
            if (temp -> info > oddMax)
            {
                oddMax= temp -> info;
            }
        }
        temp = temp -> next;
    }
    return oddMax;
}
int findEvenMaxInSlist(Slist l)
{
    int evenMax = findFirstEvenElementsInSlist(l);
    Node *temp = l.head;
    while (temp)
    {
        if (temp -> info % 2 == 0)
        {
            if(temp ->info < evenMax)
            {
                evenMax = temp -> info;
            }
        }
        temp = temp -> next;
    }
    return evenMax;
}
int findOddMinInSlist(Slist l)
{
    int oddMin = findFirstOddElementsInSlist(l);
    Node *temp = l.head;
    while (temp)
    {
        if(temp -> info % 2 != 0)
        {
            if(temp -> info < oddMin)
            {
                oddMin = temp -> info;
            }
        }
        temp = temp -> next;
    }
    return oddMin;
}
void deleteMaxInSlist(Slist &l)
{
    Node *max = findMaxInSlist(l);
    if (l.head == NULL || max == NULL)
    {
        return; 
    }
    else
    {
        if (max == l.head)  
        {
            deleteHeadSlist(l);
        }
        else if (max == l.tail)
        {
            deleteTailSlist(l);
        }
        else
        {
            Node *tmp = l.head;
            while (tmp -> next != max)
            {
                tmp= tmp -> next;
            }
            tmp -> next = max -> next;
            max -> next = NULL;
            delete max;
        }
    }
}
void deleteMinInSlist(Slist &l)
{
    Node *min = findMinInSlist(l);
    if (l.head == NULL || min == NULL)
    {
        return ;
    }
    else
    {
        if(min == l.head)
        {
            deleteHeadSlist(l);
        }
        else if (min == l.tail)
        {
            deleteTailSlist(l);
        }
        else
        {
            Node *temp = l.head;
            while(temp -> next != min)
            {
                temp = temp -> next;
            }
            temp -> next = min -> next;
            min -> next = NULL; 
            delete min;
        }
    }
}
void addXInSlist(Slist &l, Node *x)
{
    if (l.head == NULL)
    {
        l.head = l.tail = x;
    }
    else 
    {
        Node *temp = l.head;
        while(temp -> next != l.tail)
        {
            if ((x-> info > temp ->info)&&(x-> info > temp -> next -> info)) 
            {
                x -> next = temp -> next;
                temp -> next = x;
                break;
            }
            temp = temp -> next;
        }
    }
}
int checkSListIncrease(Slist l){

	if(l.head == NULL)
    {
		return -1;
	}
    else
    {
		Node *temp = l.head;
		while(temp->next != l.tail){
			if(temp->info > temp->next->info)
            {
				return -1;
			}
			temp = temp->next;
		}
	}
	return 1;
}
int checkSListDecrease(Slist l)
{
	if(l.head == NULL)
    {
		return -1;
	}
    else{
		Node *temp = l.head;
		while(temp->next != l.tail)
        {
			if(temp->info < temp->next->info)
            {
				return -1;
			}
			temp = temp->next;
		}
	}
	return 1;
}
int findLengthMaxOfSlist(Slist l)
{
	if (l.head == NULL)
	{
		return 0;
	}
	if (l.head -> next == NULL)
	{
		return 1;
	}
	Node *temp = l.head -> next;
	while(temp)
	{
		int max = 0;
		Node* temp1 = l.head;
		while (temp1 != temp)
		{
			if (temp -> info > temp1 -> info)
			{
				if (temp -> count > max)
				{
					max = temp1 -> count;
				}
			}
			temp1 = temp1 -> next;
		}
		temp -> count = 1 + max;
		temp = temp -> next;
	}
	int length = 0;
	temp = l.head;
	// Finding maximum length Slist
	while (temp)
	{
		if(length < temp -> count)
		{
			length = temp -> count;
		}
		temp = temp -> next;
	}
	return length;
}