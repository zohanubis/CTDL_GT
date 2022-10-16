#include "stdio.h"
#include "conio.h"

struct PhanSo
{
    int tuSo;
    int mauSo;
};
struct  Node
{
    PhanSo ps;
    Node *next;
};
struct Slist
{
    Node *head;
    Node *tail;
};
Node *createNode(int x, int y)
{
    Node *p = new Node;
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat !");
        return NULL;
    }
    p -> ps.tuSo = x;
    p -> ps.mauSo = y;
    p -> next = NULL;
    return p;
}
void menu();
void initSlist(Slist &sl);
void addTailSlist(Slist &sl, Node *p);
void createList(Slist &sl);
void printList(Slist sl);
void toiGianPhanSo(Node *p);
void toiGianCacPhanSo(Slist &sl);
Node *tinhTongCacPhanSo(Slist sl);
Node *tinhTichCacPhanSo(Slist sl);
Node *timPhanSoMax(Slist sl);
Node *timPhanSoMin(Slist sl);
void tangMoiPhanSoLen1DonVi(Slist &sl);
void xuatCacPhanSoLonHon1(Slist sl);
Node *timNodeTrongSlist(Slist sl, int tuSo, int mauSo);
int main()
{
    menu();
    return 0;
}
void menu()
{
    printf("1. Nhap/xuat danh sach co n phan so");
	printf("\n2. Toi gian cac phan so");
	printf("\n3. Tinh tong/tich cac phan so.");
	printf("\n4. Cho biet cac phan so lon nhat, phan so nho nhat");
	printf("\n5. Tang moi phan so cua danh sach len 1 don vi");
	printf("\n6. Xuat cac phan so lon hon 1 trong danh sach lien ket");
	printf("\n7. Viet ham tra ve SNode chua phan so p trong danh sach lien ket.Neu khong co p trong DSLK thi tra ve NULL");
    int nhap;
    Slist sl;
    do
    {
        printf("\n\nNhap O de thoat!");
		printf("\nNhap thao tac muon thuc hien: "); scanf("%d", &nhap);
    } while (nhap != 0);
    
}
void initSlist(Slist &sl)
{
    sl.head = sl.tail = NULL;
}
void addTailSlist(Slist &sl, Node *p)
{
    if (p == NULL)
    {
        return;
    }
    else
    {
        sl.tail -> next = p;
        sl.tail = p;
    }
}
void createList(Slist &sl)
{
    int n, x,y;
    Node *p = new Node;
    printf("Nhap so luong phan so: "); scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("\tNhap phan so thu %d: ", i);
		printf("\nNhap tu so: ");
		scanf("%d", &x);
		printf("Nhap mau so: ");
		scanf("%d", &y);
        p = createNode(x,y);
        addTailSlist(sl,p);
    }
}
void printList(Slist sl)
{
    Node *temp = sl.head;
    while (temp != NULL)
    {
        if(temp -> ps.mauSo == 1)
        {
            printf("%d ", temp -> ps.tuSo);
        }
        else
        {
            printf("%d/%d ", temp -> ps.tuSo, temp -> ps.mauSo);
        }
        temp = temp -> next;
    }
}