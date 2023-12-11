#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

void push(char);
char pop();
int isEmpty();
void InToPost();
int space(char);
void print();
int precedence(char);

void InToPost() {
    int i, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        switch (symbol) {
            case '(':
                push(symbol);
                break;

            case ')':
                while ((next = pop()) != '(')
                    postfix[j++] = next;
                break;
            case '+':
            case '-':
            case '/':
            case '*':
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                    postfix[j++] = pop();
                push(symbol);
                break;
            default:
                postfix[j++] = symbol;
        }
    }
    while (!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';
}

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '/':
        case '*':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int space(char c) {
    if (c == ' ' || c == '\t')
        return 1;
    else
        return 0;
}

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = c;
}

char pop() {
    char c;
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c;
}

int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

void print() {
    printf("The equivalent postfix expression is: ");
    puts(postfix);
}

int main() {
    printf("Enter the infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = '\0';  

    InToPost();
    print();

    return 0;
}
