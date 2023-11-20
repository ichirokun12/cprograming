#include <stdio.h>
#include <stdlib.h>

int* stack_arr;  // Dynamic array for stack
int top = -1;
int stack_size;  // User-defined stack size

void initializeStack(int size) {
    stack_arr = (int*)malloc(size * sizeof(int));  // Allocate memory for the stack
    if (stack_arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack_size = size;
}

void push(int data) {
    if (top == stack_size - 1) {
        // Stack is full, reallocate memory
        stack_size *= 2;
        stack_arr = (int*)realloc(stack_arr, stack_size * sizeof(int));
        if (stack_arr == NULL) {
            printf("Memory reallocation failed\n");
            exit(1);
        }
    }
    top = top + 1;
    stack_arr[top] = data;
}

int pop() {
    int value;
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    value = stack_arr[top];
    top = top - 1;
    return value;
}

void print() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
    }
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack_arr[i]);
    }
}

int main() {
    int data;
    int choice;

    printf("Enter the size of the stack: ");
    scanf("%d", &stack_size);
    initializeStack(stack_size);

    do {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                printf("Popped value: %d\n", data);
                break;
            case 3:
                print();
                break;
            case 4:
                free(stack_arr);  // Free dynamically allocated memory
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }

    } while (1);

    return 0;
}
