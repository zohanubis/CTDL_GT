#include "stdio.h"
#include "stdlib.h"
#include "time.h"
struct Node{
	int info;
	Node *next;
};
struct SList{
	Node *head;
	Node *tail;
};
Node *createNode(int x){
	Node *p = new Node;
	if(p == NULL){
		printf("Khong du bo nho de cap phat!");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
}
void menu();
void initSList(SList &sl);
void addHeadSList(SList &sl, Node *p);
void addTailSList(SList &sl, Node *p);
void createAutoList(SList &sl);
void printList(SList sl); 
void sortIncrease(SList &sl);
void joinTwoSListIncrease(SList &sl, SList sl1, SList sl2);
void sortDecrease(SList &sl);
void joinTwoSListDecrease(SList &sl, SList sl1, SList sl2);
void joinTwoSListEvenIncrease(SList &sl, SList sl1, SList sl2);
void joinTwoSListOddDecrease(SList &sl, SList sl1, SList sl2);
int main(){
	menu();
	return 0;
}
void menu(){
	SList sl1;
	initSList(sl1);
	createAutoList(sl1);
	sortIncrease(sl1);
	printf("\n\tSList1: ");
	printList(sl1);
	SList sl2;
	initSList(sl2);
	printf("\n\n");
	createAutoList(sl2);
	sortIncrease(sl2);
	printf("\n\tSList2: ");
	printList(sl2);
	printf("\n\n1. Tron 2 danh sach tren thanh mot danh sach sl co thu tu tang.");
	printf("\n2. Tron 2 danh sach tren thanh mot danh sach sl co thu tu giam.");
	printf("\n3. Tron 2 danh sach tren thanh mot danh sach sl sao cho cac phan tu\n co gia tri chan tang dan, cac phan tu co gia tri le giam dan.");
	printf("\n4. Tron 2 danh sach tren thanh mot danh sach sl sao cho cac phan tu\n tai nhung vi tr chan tang dan, cac phan tu tai nhung vi tri le giam dan.");
	int nhap;
	do{
		printf("\n\nNhap 0 de thoat!");
		printf("\nNhap thao tac muon thuc hien: ");scanf("%d",&nhap);
		switch(nhap){
			case 1:{
				SList sl;
				initSList(sl);
				joinTwoSListIncrease(sl,sl1,sl2);
				printf("\n\tSList sau khi tron 2 danh sach tang: ");
				printList(sl);
				break;
			}
			case 2:{
				SList sl;
				initSList(sl);
				joinTwoSListDecrease(sl,sl1,sl2);
				printf("\n\tSList sau khi tron 2 danh sach giam: ");
				printList(sl);
				break;
			}
			case 3:{
				SList sl;
				initSList(sl);
				joinTwoSListEvenIncrease(sl,sl1,sl2);
				joinTwoSListOddDecrease(sl,sl1,sl2);
				printf("\n\tSList sau khi tron 2 danh sach chan tang, le giam: ");
				printList(sl);
				break;
			}
			default:{
				if(nhap != 0){
					printf("\n\tThao tac khong hop le!");
				}
				break;
			}
		}
	}while(nhap != 0);
}
void initSList(SList &sl){
	sl.head = sl.tail = NULL;
}
void addHeadSList(SList &sl, Node *p){
	if(p == NULL){
		return;
	}
	if(sl.head == NULL){
		sl.head = sl.tail = p;
	}else{
		p->next = sl.head;
		sl.head = p;
	}
}
void addTailSList(SList &sl, Node *p){
	if(p == NULL){
		return;
	}
	if(sl.head == NULL){
		sl.head = sl.tail = p;
	}else{
		sl.tail->next = p;
		sl.tail = p;
	}
}
void createAutoList(SList &sl){
	int n,x;
	do{
		printf("Nhap so luong node cua danh sach(n > 0): ");scanf("%d",&n);
	}while(n <= 0);
	srand(time(NULL));
	for(int i = 1; i <= n; i++){
		x = (rand() % 199) - 99;
		Node *p = createNode(x);
		addTailSList(sl,p);
	}
}
void printList(SList sl){
	Node *temp = sl.head;
	while(temp != NULL){
		printf("%d ",temp->info);
		temp = temp->next;
	}
}
void sortIncrease(SList &sl){
	for(Node *i = sl.head; i != NULL; i = i->next){
		for(Node *j = i->next; j != NULL; j = j->next){
			if(i->info > j->info){
				int temp = i->info;
				i->info = j->info;
				j->info = temp;
			}
		}
	}	
}
int findLength(SList sl){
	int count = 0;
	Node *temp = sl.head;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}
void joinTwoSListIncrease(SList &sl, SList sl1, SList sl2){
	Node *temp1 = sl1.head;
	Node *temp2 = sl2.head;
	int lengthSl1 = findLength(sl1);
	int lengthSl2 = findLength(sl2);
	int countSl1 = 0;
	int countSl2 = 0;
	while(temp1 != NULL && temp2 != NULL){
		if(temp1->info < temp2->info){
			countSl1++;
			addTailSList(sl,temp1);
			temp1 = temp1->next;
		}else{
			countSl2++;
			addTailSList(sl,temp2);
			temp2 = temp2->next;
		}
	}
	if(countSl1 < lengthSl1){
		while(temp1 != NULL){
			addTailSList(sl,temp1);
			temp1 = temp1->next;
		}
	}
	if(countSl2 < lengthSl2){
		while(temp2 != NULL){
			addTailSList(sl,temp2);
			temp2 = temp2->next;
		}
	}
}
void sortDecrease(SList &sl){
	for(Node *i = sl.head; i != NULL; i = i->next){
		for(Node *j = i->next; j != NULL; j = j->next){
			if(i->info < j->info){
				int temp = i->info;
				i->info = j->info;
				j->info = temp;
			}
		}
	}
}
void joinTwoSListDecrease(SList &sl, SList sl1, SList sl2){
	sortDecrease(sl1);
	sortDecrease(sl2);
	Node *temp1 = sl1.head;
	Node *temp2 = sl2.head;
	int lengthSl1 = findLength(sl1);
	int lengthSl2 = findLength(sl2);
	int countSl1 = 0;
	int countSl2 = 0;
	while(temp1 != NULL && temp2 != NULL){
		if(temp1->info > temp2->info){
			countSl1++;
			addTailSList(sl,temp1);
			temp1 = temp1->next;
		}else{
			countSl2++;
			addTailSList(sl,temp2);
			temp2 = temp2->next;
		}
	}
	if(countSl1 < lengthSl1){
		while(temp1 != NULL){
			addTailSList(sl,temp1);
			temp1 = temp1->next;
		}
	}
	if(countSl2 < lengthSl2){
		while(temp2 != NULL){
			addTailSList(sl,temp2);
			temp2 = temp2->next;
		}
	}
}
int countEven(SList sl){
	int count = 0;
	Node *temp = sl.head;
	while(temp != NULL){
		if(temp->info % 2 == 0){
			count++;
		}
		temp = temp->next;
	}
	return count;
}
int countOdd(SList sl){
	int count = 0;
	Node *temp = sl.head;
	while(temp != NULL){
		if(temp->info % 2 != 0){
			count++;
		}
		temp = temp->next;
	}
	return count;
}
void joinTwoSListEvenIncrease(SList &sl, SList sl1, SList sl2){
	sortIncrease(sl1);
	sortIncrease(sl2);
	Node *temp1 = sl1.head;
	Node *temp2 = sl2.head;
	int countEvenSl1 = countEven(sl1);
	int countEvenSl2 = countEven(sl2);
	int countSl1 = 0;
	int countSl2 = 0;
	while(temp1 != NULL && temp2 != NULL){
		if((temp1->info % 2 == 0) && (temp2->info % 2 == 0)){
			if(temp1->info < temp2->info){
				Node *add = createNode(temp1->info);
				countSl1++;
				addTailSList(sl,add);
				temp1 = temp1->next;
			}else{
				Node *add = createNode(temp2->info);
				countSl2++;
				addTailSList(sl,add);
				temp2 = temp2->next;
			}
		}
		if(temp1->info % 2 != 0){
			temp1 = temp1->next;
		}
		if(temp2->info %2  != 0){
			temp2 = temp2->next;
		}
	}
	if(countSl1 < countEvenSl1){
		while(temp1 != NULL){
			if(temp1->info % 2 == 0){
				Node *add = createNode(temp1->info);
				addTailSList(sl,add);
			}
			temp1 = temp1->next;
		}
	}
	if(countSl2 < countEvenSl2){
		while(temp2 != NULL){
			if(temp2->info % 2 == 0){
				Node *add = createNode(temp2->info);
				addTailSList(sl,add);
			}
			temp2 = temp2->next;
		}
	}
}
void joinTwoSListOddDecrease(SList &sl, SList sl1, SList sl2){
	sortDecrease(sl1);
	sortDecrease(sl2);
	Node *temp1 = sl1.head;
	Node *temp2 = sl2.head;
	int countOddSl1 = countOdd(sl1);
	int countOddSl2 = countOdd(sl2);
	int countSl1 = 0;
	int countSl2 = 0;
	while(temp1 != NULL && temp2 != NULL){
		if((temp1->info % 2 != 0) && (temp2->info % 2 != 0)){
			if(temp1->info > temp2->info){
				Node *add = createNode(temp1->info);
				countSl1++;
				addTailSList(sl,add);
				temp1 = temp1->next;
			}else{
				Node *add = createNode(temp2->info);
				countSl2++;
				addTailSList(sl,add);
				temp2 = temp2->next;
			}
		}
		if(temp1->info % 2 == 0){
			temp1 = temp1->next;
		}
		if(temp2->info %2  == 0){
			temp2 = temp2->next;
		}
	}
	if(countSl1 < countOddSl1){
		while(temp1 != NULL){
			if(temp1->info % 2 != 0){
				Node *add = createNode(temp1->info);
				addTailSList(sl,add);
			}
			temp1 = temp1->next;
		}
	}
	if(countSl2 < countOddSl2){
		while(temp2 != NULL){
			if(temp2->info % 2 != 0){
				Node *add = createNode(temp2->info);
				addTailSList(sl,add);
			}
			temp2 = temp2->next;
		}
	}
}
