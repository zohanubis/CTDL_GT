#include "stdio.h"
#define MAXSIZE 50
#include "string.h"
struct SNode{
	char info;
	SNode *next;
};
struct Stack{
	SNode *top;
};
SNode *createNode(char s){
	SNode *p = new SNode;
	if(p == NULL){
		printf("\n\tKhong du bo nho de cap phat!");
		return NULL;
	}
	p->info = s;
	p->next = NULL;
	return p;
}
void initStack(Stack &s);
int isEmptyStack(Stack s);
void push(Stack &s, SNode *p);
SNode *pop(Stack &s);
char getTop(Stack s);
int getDoUuTien(char c);
bool checkToanHang(char c);
bool checkToanTu(char c);
void infixToPostfix(char infix[], char postfix[]);
void daoChuoi(char c[]);
void thayTheNgoac(char c[]);
void infixToPrefix(char infix[], char prefix[]);
int main(){
	char infix[MAXSIZE];
	char prefix[MAXSIZE];
	printf("Nhap chuoi trung to: ");scanf("%s",&infix);
	infixToPrefix(infix,prefix);
	printf("\n\tChuoi sau khi chuyen tu trung to sang hau to: %s",prefix);
	return 0;
}
void initStack(Stack &s){
	s.top = NULL;
}
int isEmptyStack(Stack s){
	return (s.top == NULL);
}
void push(Stack &s, SNode *p){
	if(p == NULL){
		return;
	}else{
		if(isEmptyStack(s)){
			s.top = p;
		}else{
			p->next = s.top;
			s.top = p;
		}
	}
}
SNode *pop(Stack &s){
	if(isEmptyStack(s)){
		return NULL;
	}else{
		SNode *temp = s.top;
		s.top = s.top->next;
		return temp;
	}
}
char getTop(Stack s){
	return s.top != NULL ? s.top->info : -1;
}
int getDoUuTien(char c){
	if(c == '-' || c == '+'){
		return 1;
	}else if(c == '*' || c == '/'){
		return 2;
	}else if(c == '^'){
		return 3;
	}
	return 0;
}
bool checkToanHang(char c){
	if(c >= '0' && c <= '9'){
		return true;
	}else if(c >= 'a' && c <= 'z'){
		return true;
	}else if(c >= 'A' && c <= 'Z'){
		return true;
	}
	return false;
}
bool checkToanTu(char c){
	if(c == '-' || c == '+' || c == '*' || c == '/' || c == '^'){
		return true;
	}
	return false;
}
void infixToPostfix(char infix[], char postfix[]){
	Stack s;
	initStack(s);
	int k = 0;
	SNode *c = new SNode;
	for(int i = 0; infix[i] != '\0'; i++){
		if(checkToanHang(infix[i])){
			postfix[k++] = infix[i];
		}else if(infix[i] == '('){
			c = createNode(infix[i]);
			push(s,c);			
		}else if(checkToanTu(infix[i])){
			if(!isEmptyStack(s) && getDoUuTien(getTop(s)) >= getDoUuTien(infix[i])){
				postfix[k++] = getTop(s);
				pop(s);
			}
			c = createNode(infix[i]);
			push(s,c);
		}else{
			while(!isEmptyStack(s) && getTop(s) != '('){
				postfix[k++] = getTop(s);
				pop(s);
			}
			pop(s);
		}
	}
	while(!isEmptyStack(s)){
		postfix[k++] = getTop(s);
		pop(s);
	}
	postfix[k] = '\0';
}
void daoChuoi(char c[]){
	int n = strlen(c);
	for(int i = 0; i < n/2; i++){
		char temp = c[i];
		c[i] = c[n-i-1];
		c[n-i-1] = temp;
	}
}
void thayTheNgoac(char c[]){
	int n = strlen(c);
	for(int i = 0; i < n; i++){
		if(c[i] == '('){
			c[i] = ')';
		}else if(c[i] == ')'){
			c[i] = '(';
		}
	}
}
void infixToPrefix(char infix[], char prefix[]){
	daoChuoi(infix);
	printf("%s\n",infix);
	thayTheNgoac(infix);
	printf("%s\n",infix);
	infixToPostfix(infix,prefix);
	printf("%s\n",prefix);
	daoChuoi(prefix);
}
