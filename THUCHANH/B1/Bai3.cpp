#include "stdio.h"
#include "stdlib.h"
#include "time.h"
struct Node {
	int info;
	Node* next;
};
struct SList {
	Node* head;
	Node* tail;
};
Node* createNode(int x) {
	Node* p = new Node;
	if (p == NULL) {
		printf("Khong du bo nho de cap phat!");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
}
void menu();
void initSList(SList& sl);
void addHeadSList(SList& sl, Node* p);
void addTailSList(SList& sl, Node* p);
void createAutoList(SList& sl);
void printList(SList sl);
void sortIncrease(SList& sl);
void insertX(SList& sl, int x);
void sortDecrease(SList& sl);
void joinTwoList(SList& sl1, SList sl2, int x);
int main() {
	menu();
	return 0;
}
void menu() {
	SList sl;
	initSList(sl);
	createAutoList(sl);
	sortIncrease(sl);
	printf("\n\tSList: ");
	printList(sl);
	printf("\n\n1. Chen phan tu x vao danh sach sao cho van giu nguyen thu tu tang.");
	printf("\n2. In danh sach tren theo thu tu giam dan.");
	printf("\n3. Noi danh sach sl2 vao sau phan tu co gia tri x trong danh sach sl1");
	printf("\n- neu khong co phan tu x thi thong bao <khong co phan tu x> voi sl2 la danh sach chua cac so nguyen.");
	int nhap;
	do {
		printf("\n\nNhap 0 de thoat!");
		printf("\nNhap thao tac muon thuc hien: "); scanf("%d", &nhap);
		switch (nhap)
		{
		case 1: {
			sortIncrease(sl);
			int x;
			printf("Nhap x muon chen: "); scanf("%d", &x);
			insertX(sl, x);
			printf("\n\tSList sau khi chen %d: ", x);
			printList(sl);
			break;
		}
		case 2: {
			sortDecrease(sl);
			printf("\n\tSList: ");
			printList(sl);
			break;
		}
		case 3: {
			SList sl1;
			initSList(sl1);
			createAutoList(sl1);
			printf("\n\tSList1: ");
			printList(sl1);
			SList sl2;
			initSList(sl2);
			printf("\n");
			createAutoList(sl2);
			printf("\n\tSList2: ");
			printList(sl2);
			int x;
			printf("\nNhap phan tu x: "); scanf("%d", &x);
			joinTwoList(sl1, sl2, x);
			break;
		}
		default: {
			if (nhap != 0) {
				printf("\n\tERROR !");
			}
			break;
		}
		}
	} while (nhap != 0);
}
void initSList(SList& sl) {
	sl.head = sl.tail = NULL;
}
void addHeadSList(SList& sl, Node* p) {
	if (p == NULL) {
		return;
	}
	if (sl.head == NULL) {
		sl.head = sl.tail = p;
	}
	else {
		p->next = sl.head;
		sl.head = p;
	}
}
void addTailSList(SList& sl, Node* p) {
	if (p == NULL) {
		return;
	}
	if (sl.head == NULL) {
		sl.head = sl.tail = p;
	}
	else {
		sl.tail->next = p;
		sl.tail = p;
	}
}
void createAutoList(SList& sl) {
	int n, x;
	do {
		printf("Nhap so luong node cua danh sach(n > 0): ");
		scanf("%d", &n);
	} while (n <= 0);
	srand(time(NULL));
	for (int i = 1; i <= n; i++) {
		x = (rand() % 199) - 99;
		Node* p = createNode(x);
		addTailSList(sl, p);
	}
}
void printList(SList sl) {

	Node* temp = sl.head;
	while (temp != NULL) {
		printf("%d ", temp->info);
		temp = temp->next;
	}
}
void sortIncrease(SList& sl)
{
	for (Node* i = sl.head; i != NULL; i = i->next) {
		for (Node* j = i->next; j != NULL; j = j->next) {
			if (i->info > j->info) {
				int temp = i->info;
				i->info = j->info;
				j->info = temp;
			}
		}
	}
}
void insertX(SList& sl, int x) {
	Node* p = createNode(x);
	if (p->info <= sl.head->info) {
		addHeadSList(sl, p);
	}
	if (p->info >= sl.tail->info) {
		addTailSList(sl, p);
	}
	for (Node* i = sl.head; i->next != NULL; i = i->next) {
		Node* j = i->next;
		if (i->info <= p->info && j->info >= p->info) 
        {
			i->next = p;
			p->next = j;
			break;
		}
	}
}
void sortDecrease(SList& sl) {
	for (Node* i = sl.head; i != NULL; i = i->next) {
		for (Node* j = i->next; j != NULL; j = j->next) {
			if (i->info < j->info) 
            {
				int temp = i->info;
				i->info = j->info;
				j->info = temp;
			}
		}
	}
}
void joinTwoList(SList& sl1, SList sl2, int x) 
{
	int flag = 0;
	for (Node* i = sl1.head; i != NULL; i = i->next) {
		if (i->info == x) {
			flag = 1;
			sl2.tail->next = i->next;
			sl2.tail = sl1.tail;
			i->next = sl2.head;
			sl2.head = sl1.head;
			break;
		}
	}
	if (flag == 0) {
		printf("\n\tKhong co phan tu %d", x);
	}
	else {
		printf("\n\tSList sau khi noi: ");
		printList(sl1);
	}
}
