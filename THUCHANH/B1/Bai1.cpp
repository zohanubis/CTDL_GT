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
int addBeforeNode(SList &sl, Node *q, Node *p);
void deleteHeadSList(SList &sl);
void deleteTailSList(SList &sl);
void deleteAfterNode(SList &sl, Node *q);
void deleteNodeGreaterThanX(SList &sl, int x);
void deleteEvenNode(SList &sl);
void sortIncrease(SList &sl);
void sortDecrease(SList &sl);
int countPrimNumberInSList(SList sl);
int computeSumSquareNumberInSList(SList sl);
int findMaxInSList(SList sl);
int findMinInSList(SList sl);
int countNodeGreaterThanDoubleAfterNode(SList sl);
void splitSListIntoEvenListAndOddList(SList sl, SList &sl1, SList &sl2);
int demSoDuongChiaHetCho5(SList sl);
int main(){
	menu();
	return 0;
}
void menu(){
	SList sl;
	initSList(sl);
	createAutoList(sl);
	printf("\n\tSList: ");
	printList(sl);
	printf("\n\n1. Them phan tu moi vao cuoi danh sach sl.");
	printf("\n2. Chen them phan tu co gia tri x vao truoc phan tu co gia tri y.");
	printf("\n3. Viet ham xoa cac phan tu lon hon x trong dslk.");
	printf("\n4. Viet ham xoa cac phan tu chan trong dslk.");
	printf("\n5. Sap xep dslk tang dan, giam dan.");
	printf("\n6. Cho biet trong dslk co bao nhieu so nguyen to.");
	printf("\n7. Tinh tong cac so chinh phuong trong dslk.");
	printf("\n8. Tim phan tu nho nhat, phan tu lon nhat trong dslk.");
	printf("\n9. Cho biet trong dslk co bao nhieu phan tu lon hon gap doi phan tu phia sau no.");
	printf("\n10. Tu sl tao 2 danh sach moi: sl1 chua cac so chan, sl2 chua cac so le.");
	int nhap;
	do{
		printf("\n\nNhap 0 de thoat!");
		printf("\nNhap thao tac muon thuc hien: ");scanf("%d",&nhap);
		switch(nhap){
			case 1:
            {
				int x;
				printf("Nhap phan tu muon them vao cuoi danh sach sl: ");scanf("%d",&x);
				Node *p = createNode(x);
				addTailSList(sl,p);
				printf("\n\tSList sau khi them %d vao cuoi: ",p->info);
				printList(sl);
				break;
			}
			case 2:
            {
				int x,y;
				printf("Nhap phan tu x muon them truoc phan tu y: ");scanf("%d%d",&x,&y);
				Node *q = createNode(x);
				Node *p = createNode(y);
				int result = addBeforeNode(sl,q,p);
				if(result != 0){
					printf("\n\tSList sau khi them %d truoc %d: ",q->info,p->info);
					printList(sl);
				}
				break;
			}
			case 3:
            {
				int x;
				printf("Nhap phan tu x: ");scanf("%d",&x);
				deleteNodeGreaterThanX(sl,x);
				printf("\n\tSList sau khi xoa nhung phan tu lon hon %d: ",x);
				printList(sl);
				break;
			}
			case 4:
            {
				deleteEvenNode(sl);
				printf("\n\tSList sau khi xoa nhung phan tu chan: ");
				printList(sl);
				break;
			}
			case 5:{
				sortIncrease(sl);
				printf("\n\tSList sau khi sap xep tang: ");
				printList(sl);
				sortDecrease(sl);
				printf("\n\tSList sau khi sap xep giam: ");
				printList(sl);
				break;
			}
			case 6:{
				printf("\n\tSo luong so nguyen to trong danh sach la: %d",countPrimNumberInSList(sl));
				break;
			}
			case 7:{
				printf("\n\tTong so chinh phuong trong danh sach la: %d",computeSumSquareNumberInSList(sl));
				break;
			}
			case 8:{
				printf("\n\tPhan tu lon nhat trong danh sach la: %d",findMaxInSList(sl));
				printf("\n\tPhan tu nho nhat trong danh sach la: %d",findMinInSList(sl));
				break;
			}
			case 9:{
				printf("\n\tSo luong phan tu lon hon gap doi phan tu phia sau no la: %d",countNodeGreaterThanDoubleAfterNode(sl));
				break;
			}
			case 10:{
				SList sl1;
				SList sl2;
				initSList(sl1);
				initSList(sl2);
				splitSListIntoEvenListAndOddList(sl,sl1,sl2);
				printf("\n\tSList1: ");
				printList(sl1);
				printf("\n\tSList2: ");
				printList(sl2);
				break;
			}
			case 11:{
				SList sl;
				printf("So luong so co chia het cho 5 : %d", demSoDuongChiaHetCho5(sl));
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
int addBeforeNode(SList &sl, Node *q, Node *p){
	int temp = p->info;
	p = sl.head;
	while(p != NULL && p->info != temp){
		p = p->next;
	}
	if(q == NULL || p == NULL){
		printf("\n\tKhong ton tai phan tu de them!");
		return 0;
	}else{
		if(p == sl.head){
			addHeadSList(sl,q);
		}else{
			Node *temp = sl.head;
			while(temp->next != p){
				temp = temp->next;
			}
			temp->next = q;
			q->next = p;
		}
	}
}
void deleteHeadSList(SList &sl){
	if(sl.head == NULL){
		printf("\n\tKhong co phan tu de xoa!");
		return;
	}else{
		Node *temp = sl.head;
		sl.head = sl.head->next;
		temp->next = NULL;
		delete temp;
	}
}
void deleteTailSList(SList &sl){
	if(sl.head == NULL){
		printf("\n\tKhong co phan tu de xoa!");
		return;
	}else{
		Node *temp = sl.tail;
		Node *temp2 = sl.head;
		while(temp2->next != sl.tail){
			temp2 = temp2->next;
		}
		temp2->next = NULL;
		sl.tail = temp2;
		delete temp;
	}
}
void deleteAfterNode(SList &sl, Node *q){
	int temp = q->info;
	q = sl.head;
	while(q != NULL && q->info != temp){
		q = q->next;
	}
	if(q == NULL || sl.head == NULL){
		return;
	}else{
		if(q->next == sl.tail){
			deleteTailSList(sl);
		}else{
			Node *temp = q->next;
			q->next = temp->next;
			temp->next = NULL;
			delete temp;
		}
	}
}
void deleteNodeGreaterThanX(SList &sl, int x){
	if(sl.head->info > x){
		deleteHeadSList(sl);
	}
	int flag = 1;
	Node *temp = sl.head;
	while(temp->next != NULL){
		if(temp->next->info > x){
			deleteAfterNode(sl,temp);
			continue;
		}
		temp = temp->next;
	} 
}
void deleteEvenNode(SList &sl){
	if(sl.head->info % 2 == 0){
		deleteHeadSList(sl);
	}
	int flag = 1;
	Node *temp = sl.head;
	while(temp->next != NULL){
		if(temp->next->info % 2 == 0){
			deleteAfterNode(sl,temp);
			continue;
		}
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
int checkPrimNumber(int n){
	int count = 0;
	for(int i = 1; i <= n; i++){
		if(n % i == 0){
			count++;
		}
	}
	if(count == 2){
		return 1;
	}else{
		return 0;
	}
}

int countPrimNumberInSList(SList sl){
	Node *temp = sl.head;
	int count = 0;
	while(temp != NULL){
		if(checkPrimNumber(temp->info) == 1){
			count++;
		}
		temp = temp->next;
	}
	return count;
}
int checkDuongVaChia5(int n){
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if(n % 5 == 0 && n > 0)
			count++;
	}
	if(count == 0)
		return 1;
	else
		return 0;
	
}
int demSoDuongChiaHetCho5(SList sl){
	Node *temp = sl.head;
	int count = 0;
	if(!temp) return 0;
	while(temp){
		if(temp->info % 5 == 0){
			count++;
			temp = temp -> next;
		}
		return count;
	}
}
int checkSquareNumber(int n){
	for(int i = 1; i <= n/2; i++){
		if(i*i == n){
			return 1;
		}
	}
	return 0;
}
int computeSumSquareNumberInSList(SList sl){
	Node *temp = sl.head;
	int sum = 0;
	while(temp != NULL){
		if(checkSquareNumber(temp->info) == 1){
			sum += temp->info;
		}
		temp = temp->next;
	}
	return sum;
}
int findMaxInSList(SList sl){
	Node *temp = sl.head;
	int max = temp->info;
	temp = temp->next;
	while(temp != NULL){
		if(temp->info > max){
			max = temp->info;
		}
		temp = temp->next;
	}
	return max;
}
int findMinInSList(SList sl){
	Node *temp = sl.head;
	int min = temp->info;
	temp = temp->next;
	while(temp != NULL){
		if(temp->info < min){
			min = temp->info;
		}
		temp = temp->next;
	}
	return min;
}
int countNodeGreaterThanDoubleAfterNode(SList sl){
	int count = 0;
	Node *temp = sl.head;
	while(temp->next != NULL){
		if(temp->info > temp->next->info*2){
			count++;
		}
		temp = temp->next;
	}
	return count;
}
int countEvenNumberInSList(SList sl){
	Node *temp = sl.head;
	int count = 0;
	while(temp != NULL){
		if(temp->info % 2 == 0){
			count++;
		}
		temp = temp->next;
	}
	return count;
}
int countOddNumberInSList(SList sl){
	Node *temp = sl.head;
	int count = 0;
	while(temp != NULL){
		if(temp->info % 2 != 0){
			count++;
		}
		temp = temp->next;
	}
	return count;
}
void splitSListIntoEvenListAndOddList(SList sl, SList &sl1, SList &sl2){
	int evenNumberInSList = countEvenNumberInSList(sl);
	int oddNumberInSList = countOddNumberInSList(sl);
	int countEven = 0;
	int countOdd = 0;
	Node *temp = new Node;
	Node *temp2 = new Node;
	for(Node *i = sl.head; i != NULL; i = i->next){
		if(i->info % 2 == 0){
			countEven++;
			if(countEven == evenNumberInSList){
				temp = i;
			}
			addTailSList(sl1,i);
		}
		if(i->info % 2 != 0){
			countOdd++;
			if(countOdd == oddNumberInSList){
				temp2 = i;
			}
			addTailSList(sl2,i);
		}
	}
	temp->next = NULL;
	temp2->next = NULL;
}
