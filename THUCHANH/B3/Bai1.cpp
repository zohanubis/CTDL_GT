#include "stdio.h"   
#include "conio.h"
struct SNode{
	int info;
	SNode *next;
};
struct Stack{
	SNode *top;
};
SNode *createNode(int x){
	SNode *p = new SNode;
	if (p == NULL){
		printf("\nKhong du bo nho de cap phat!");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}
void initStack(Stack &s);
int isEmptyStack(Stack s);
void push(Stack &s, SNode *p);
SNode *pop(Stack &s);
void createStack(Stack &s);
void printStack(Stack s);
void chuyenDoiCoSo(int n);
void main(){
	//Stack s;
	//initStack(s);
	//createStack(s);
	//printf("\n\tStack: ");
	//printStack(s);
	int n;
	printf("Nhap so nguyen (he 10): "); scanf("%d", &n);
	chuyenDoiCoSo(n);
	getch();
}
void initStack(Stack &s){
	s.top = NULL;
}
int isEmptyStack(Stack s){
	return s.top == NULL;
}
void push(Stack &s, SNode *p){
	if (isEmptyStack(s)){
		s.top = p;
	}else{
		p->next = s.top;
		s.top = p;
	}
}
SNode *pop(Stack &s){
	if (isEmptyStack(s)){
		return NULL;
	}
	else{
		SNode *temp = s.top;
		s.top = s.top->next;
		return temp;
	}
}
void createStack(Stack &s){
	int x,n;
	printf("Nhap so luong phan tu dua vao stack: "); scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		printf("Nhap phan tu thu %d: ", i);
		scanf("%d", &x);
		SNode *p = createNode(x);
		push(s, p);
	}
}
void printStack(Stack s){
	SNode *temp = s.top;
	while (temp != NULL){
		printf("%d ", temp->info);
		temp = temp->next;
	}
}
void chuyenDoiCoSo(int n){
	Stack s;
	initStack(s);
	SNode *r = new SNode;
	while (n > 0){
		r = createNode(n % 16);
		push(s, r);
		n = n / 16;
	}
	while (!isEmptyStack(s)){
		int x = pop(s)->info;
		printf("%d",x);
	}
}