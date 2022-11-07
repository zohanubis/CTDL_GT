#include "stdio.h"
#include "conio.h"
#include "string.h"
struct HangHoa{
	char maHang[10];
	char tenHang[30];
	char donViTinh[10];
	int soLuong;
};
struct QNode{
	HangHoa info;
	QNode *next;
};
struct Queue{
	QNode *head;
	QNode *tail;
};
QNode *creatQNode(HangHoa x){
	QNode *p = new QNode;
	if (p == NULL){
		printf("\n\tKhong du bo nho de cap phat!");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}
void menu();
void initQueue(Queue &q);
void insert(Queue &q, QNode *p);
void readFile(Queue &q, char *fileName);
void print1HangHoa(HangHoa hh);
void printList(Queue q);
QNode *getHead(Queue q);
QNode *remove(Queue &q);
QNode *getTail(Queue q);
void findHangHoa(Queue q, char *x);
void main(){
	menu();
	getch();
}
void menu(){
	printf("1. Nhap mot danh sach co n(n>0) mat hang vao kho.");
	printf("\n2. Xem thong tin tat ca hang hoa trong kho.");
	printf("\n3. Xem thong tin mat hang chuan bi duoc xuat kho.");
	printf("\n4. Xuat khoi kho mot mat hang va cho xem thong tin cua mat hang do.");
	printf("\n5. Xem thong tin mat hang moi vua nhap vao kho.");
	printf("\n6. Tim va xem thong tin cua mot mat hang bat ky trong kho.");
	printf("\n7. Xuat toan bo hang hoa trong kho.");
	int nhap;
	Queue q;
	initQueue(q);
	do{
		printf("\n\nNhap 0 de thoat!");
		printf("\nNhap thao tac muon thuc hien: "); scanf("%d", &nhap);
		switch (nhap){
			case 1:{
					   char *fileName = "HangHoa.txt";
					   readFile(q, fileName);
					   break;
			}
			case 2:{
					   printf("\n\tMaHang\t\tTenHang\t\tDonViTinh\tSoLuong");
					   printList(q);
					   break;
			}
			case 3:{
					   printf("\n\t\tThong tin mat hang chuan bi xuat kho: ");
					   printf("\n\tMaHang\t\tTenHang\t\tDonViTinh\tSoLuong");
					   print1HangHoa(getHead(q)->info);
					   break;
			}
			case 4:{
					   printf("\n\t\tThong tin mat hang da xuat khoi kho: ");
					   printf("\n\tMaHang\t\tTenHang\t\tDonViTinh\tSoLuong");
					   print1HangHoa(remove(q)->info);
					   break;
			}
			case 5:{
					   printf("\n\t\tThong tin mat hang vua nhap vao kho: ");
					   printf("\n\tMaHang\t\tTenHang\t\tDonViTinh\tSoLuong");
					   print1HangHoa(getTail(q)->info);
					   break;
			}
			case 6:{
					   char x[50];
					   printf("Nhap ma hang hoa muon tim: "); scanf("%s", &x);
					   printf("\n\tMaHang\t\tTenHang\t\tDonViTinh\tSoLuong");
					   findHangHoa(q, x);
					   break;
			}
			case 7:{
					   printf("\n\tMaHang\t\tTenHang\t\tDonViTinh\tSoLuong");
					   printList(q);
					   break;
			}
			default:{
						if (nhap != 0){
							printf("\n\tThao tac khong hop le!");
						}
						break;
			}
		}
	} while (nhap != 0);
}
void initQueue(Queue &q){
	q.head = q.tail = NULL;
}
void insert(Queue &q, QNode *p){
	if (p == NULL){
		return;
	}
	else{
		if (q.head == NULL){
			q.head = q.tail = p;
		}
		else{
			q.tail->next = p;
			q.tail = p;
		}
	}
}
void readFile(Queue &q, char *fileName){
	FILE *f = fopen(fileName, "rt");
	int n;
	fscanf(f, "%d", &n);
	HangHoa x;
	for (int i = 1; i <= n; i++){
		fscanf(f, "%s%s%s%d", &x.maHang, &x.tenHang, &x.donViTinh, &x.soLuong);
		QNode *p = creatQNode(x);
		insert(q, p);
	}
}
void print1HangHoa(HangHoa hh){
	printf("\n\n\t%s\t\t%s\t\t%s\t\t%d", hh.maHang, hh.tenHang, hh.donViTinh, hh.soLuong);
}
void printList(Queue q){
	QNode *temp = q.head;
	while (temp != NULL){
		print1HangHoa(temp->info);
		temp = temp->next;
	}
}
QNode *getHead(Queue q){
	if (q.head == NULL){
		return NULL;
	}
	else{
		QNode *temp = q.head;
		return temp;
	}
}
QNode *remove(Queue &q){
	if (q.head == NULL){
		return NULL;
	}
	else{
		QNode *temp = q.head;
		q.head = q.head->next;
		temp->next = NULL;
		return temp;
	}
}
QNode *getTail(Queue q){
	if (q.head == NULL){
		return NULL;
	}
	else{
		QNode *temp = q.tail;
		return temp;
	}
}
void findHangHoa(Queue q, char *x){
	if (q.head == NULL){
		return;
	}
	else{
		QNode *temp = q.head;
		while (temp != NULL){
			if (strcmp(temp->info.maHang,x) == 0){
				print1HangHoa(temp->info);
			}
			temp = temp->next;
		}
	}
}