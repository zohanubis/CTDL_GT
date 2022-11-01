#include"stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX 100
// struct
struct Node
{
    char info;
    Node * next;
};
struct Stack
{
    Node *top;
};
Node * createNode(char value)
{
    Node *p = new Node;
    if (p != NULL)
    {
        p -> info = value;
        p -> next = NULL;
    }
    return p;
}
void push(Stack &s, int value);
void pop(Stack *s);
void infixToPostfix(char infix[], char postfix[]);
void daoChuoi(char s[]);
void thayTheNgoac(char s[]);
void infixToPrefix(char infix[], char prefix[]);

    // Main 
int main()
{
    char infix[MAX] = "(4-2)*2+2";
    daoChuoi(infix);
    char prefix[MAX];
    char postfix[MAX];
    
    infixToPrefix(infix, prefix);
    printf("\nInfix sang Prefix : %s\n",prefix);
    infixToPostfix(infix,postfix);
    printf("Infix sang Postfix (dao chuoi): %s ", postfix);
    daoChuoi(postfix);
    system("pause");
    return 0;
}

    // Code 
void init(Stack &s){
    s.top = NULL;
}
bool isEmpty(Stack s)
{
    return s.top == NULL;
}
void push(Stack &s, int value)
{
    Node *p = createNode(value);
    if (isEmpty(s))
    {
        s.top = p;
    }
    else
    {
        p -> next = s.top;
        s.top = p;
    }
}
void pop(Stack &s)
{
    if (isEmpty(s))
    {
        return;
    }
    else
    {
        Node *p = s.top;
        s.top = p -> next;
    }
}
char getTop(Stack s)
{
    if (isEmpty(s))
        return -1;
    else
        return s.top -> info;
}
int getPriority(char c)
{
    if (c == '+' || c =='-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}
bool isToanHang(char c)
{
    if(c >= '0' && c <= '9')
        return true;
    if(c >= 'a' && c <= 'z')
        return true;
    if(c >= 'A' && c <= 'Z')
        return true;
    return false;
}
bool isToanTu(char c)
{
    if( c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    return false;
}
void infixToPostfix(char infix[], char postfix[])
{
    Stack s;
    init(s);
    char k = 0;
    for (int i = 0 ; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        if (isToanHang(c))
            postfix[k++] = c;
        else if ( c == '(')
            push(s,c);
        else if( isToanTu(c))
        {
            while (!isEmpty(s) 
                        && getPriority(getTop(s)) 
                            >= getPriority(c)){
                postfix[k++] = getTop(s);
                pop(s);
            }
        }
    }
}
void daoChuoi(char s[])
{
    int n = strlen(s);
    for (int i = 0; i < n/2; i++)
    {
        char t = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = t;
    }
}
void thayTheNgoac(char s[])
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            s[i] == ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }
}
void infixToPrefix(char infix[], char prefix[])
{
	printf("Chuoi infix ban dau %s\n", infix);
    daoChuoi(infix);
    printf("Ket qua dao chuoi infix %s\n",infix);
    thayTheNgoac(infix);
    printf("Ket qua thay the ngoac infix %s\n",infix);
    infixToPostfix(infix,prefix);
    printf("Ket qua infix sang postfix : %s\n",prefix);
    daoChuoi(prefix);
}
