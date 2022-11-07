#include "stdio.h"   
#include "conio.h"
#include "string.h"
struct SNode{
	char info;
	SNode *next;
};
struct Stack{
	SNode *top;
};
SNode *createNode(char x){
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
void daoNguocChuoi(char chuoi[50]);
int kiemTraChuoiDoiXung(char chuoi[50]);
void main(){
	char chuoi[50];
	printf("Nhap 1 chuoi ky tu bat ki: "); gets_s(chuoi);
	printf("\n\tChuoi la: %s", chuoi);
	daoNguocChuoi(chuoi);
	int result = kiemTraChuoiDoiXung(chuoi);
	if (result == 1){
		printf("\n\tChuoi doi xung!");
	}
	else{
		printf("\n\tChuoi khong doi xung!");
	}
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
	}
	else{
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
void daoNguocChuoi(char chuoi[50]){
	Stack s;
	initStack(s);
	for (int i = 0; i < strlen(chuoi); i++){
		SNode *temp = createNode(chuoi[i]);
		push(s, temp);
	}
	printf("\n\tChuoi sau khi dao nguoc: ");
	while (!isEmptyStack(s)){
		printf("%c", pop(s)->info);
	}
}
int kiemTraChuoiDoiXung(char chuoi[50]){
	Stack s;
	initStack(s);
	for (int i = 0; i < strlen(chuoi); i++){
		SNode *temp = createNode(chuoi[i]);
		push(s, temp);
	}
	int i = 0;
	while (!isEmptyStack(s)){
		if (pop(s)->info != chuoi[i]){
			return 0;
		}
		i++;
	}
	return 1;
}
