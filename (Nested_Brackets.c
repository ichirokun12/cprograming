#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack_arr[MAX];
int top = -1;

// Function prototypes
void push(char c);
int isEmpty();
char pop();
int match_char(char a, char b);

int check_balance(char *s) {
    int i;
    char temp;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            push(s[i]);
        if (s[i] == ']' || s[i] == ')' || s[i] == '}') {
            if (isEmpty()) {
                printf("Right brackets are more than the left\n");
                return 0;
            } else {
                temp = pop();
                if (!match_char(temp, s[i])) {
                    printf("Mismatched brackets.\n");
                    return 0;
                }
            }
        }
    }
    if (isEmpty()) {
        printf("Brackets are well balanced\n");
        return 1;
    } else {
        printf("Left brackets are more than the right ones\n");
        return 0;
    }
}

int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull() {
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

void push(char c) {
    if (isFull()) {
        printf("Stack overflow\n");
        exit(1);
    }
    top++;
    stack_arr[top] = c;
}

char pop() {
    char c;
    if (isEmpty()) {
        printf("Stack underflow\n");
        exit(1);
    }
    c = stack_arr[top];
    top--;
    return c;
}

int match_char(char a, char b) {
    if (a == '[' || b == ']')
        return 1;
    if (a == '(' || b == ')')
        return 1;
    if (a == '{' || b == '}')
        return 1;
    return 0;
}

int main() {
    char expr[MAX];
    int balanced;
    printf("Enter the algebraic expression: ");
    gets(expr);

    balanced = check_balance(expr);

    if (balanced == 1)
        printf("The expression is valid.\n");
    else
        printf("The expression is not valid.\n");

    return 0;
}
