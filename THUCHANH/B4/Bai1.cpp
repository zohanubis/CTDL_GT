#include "stdio.h"
#include "time.h"
#include "stdlib.h"
struct QNode{
	int info;
	QNode *next;
};
struct Queue{
	QNode *head;
	QNode *tail;
};
QNode *createQNode(int x){
	QNode *q = new QNode;
	if (q == NULL){
		printf("\n\tKhong du bo nho de cap phat!");
		return NULL;
	}
	q->info = x;
	q->next = NULL;
	return q;
}
void initQueue(Queue &q);
int isEmpty(Queue q);
void insert(Queue &q, QNode *p);
int remove(Queue &q);
void createQueueAutomatic(Queue &q);
void showQueue(Queue q);
int main(){
	Queue q;
	createQueueAutomatic(q);
	printf("\n\tQueue: ");
	showQueue(q);
	printf("\n\tRemove: %d", remove(q));
	return 0;
}
void initQueue(Queue &q){
	q.head = q.tail = NULL;
}
int isEmpty(Queue q){
	return (q.head == NULL);
}
void insert(Queue &q, QNode *p){
	if (p == NULL){
		return;
	}else{
		if (isEmpty(q)){
			q.head = q.tail = p;
		}else{
			q.tail->next = p;
			q.tail = p;
		}
	}
}
int remove(Queue &q){
	if (q.head == NULL){
		return NULL;
	}
	else{
		QNode *temp = q.head;
		q.head = q.head->next;
		temp->next = NULL;
		int x = temp->info;
		delete temp;
		return x;
	}
}
void createQueueAutomatic(Queue &q){
	int n;
	printf("\nNhap so luong phan tu cua hang doi: "); scanf("%d", &n);
	initQueue(q);
	srand(time(NULL));
	for (int i = 1; i <= n; i++){
		int x = (rand() % 199 - 99);
		QNode *p = createQNode(x);
		insert(q, p);
	}
}
void showQueue(Queue q){
	QNode *temp = q.head;
	while (temp != NULL){
		printf("%d ", temp->info);
		temp = temp->next;
	}
}
