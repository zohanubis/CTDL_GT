#include "stdio.h"
#define MAXSIZE 50
#include "math.h"
struct SNode{
	int info;
	SNode *next;
};
struct Stack{
	SNode *top;
};
SNode *createNode(int s){
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
int computePostfix(char postfix[]);
int main(){
	char infix[MAXSIZE];
	char postfix[MAXSIZE];
	printf("Nhap chuoi trung to: ");gets_s(infix);
	infixToPostfix(infix,postfix);
	printf("\n\tChuoi sau khi chuyen tu trung to sang hau to: %s",postfix);
	printf("\n\tGia tri cua chuoi la: %d",computePostfix(postfix));
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
int calculate(char x, int op1, int op2){
	char sum = 0;
	if(x == '+'){
		sum = op1 + op2;
	}else if(x == '-'){
		sum = op1 - op2;
	}else if(x == '*'){
		sum = op1 * op2;
	}else if(x == '/'){
		sum = op1 / op2;
	}else{
		sum = pow(op1,op2);
	}
	return sum;
}
int change(char x){
	if(x == '0'){
		return 0;
	}else if(x == '1'){
		return 1;
	}else if(x == '2'){
		return 2;
	}else if(x == '3'){
		return 3;
	}else if(x == '4'){
		return 4;
	}else if(x == '5'){
		return 5;
	}else if(x == '6'){
		return 6;
	}else if(x == '7'){
		return 7;
	}else if(x == '8'){
		return 8;
	}else if(x == '9'){
		return 9;
	}
}
int computePostfix(char postfix[]){
	Stack s;
	initStack(s);
	for(int i = 0; postfix[i] != '\0'; i++){
		char c = postfix[i];
		if(checkToanHang(c)){
			int x = change(c);
			SNode *p = createNode(x);
			push(s,p);
		}else if(checkToanTu(c)){
			int op2 = pop(s)->info;
			int op1 = pop(s)->info;
			int result = calculate(c,op1,op2);
			SNode *p = createNode(result);
			push(s,p);
		}
	}
	return pop(s)->info;
}
