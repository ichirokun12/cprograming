#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;

} *top = NULL;

void push(int data)
{
    struct node *newnode;
    newnode = malloc(sizeof(newnode));

    if (newnode == NULL)
    {
        printf("stack overflow");
        exit(1);
    }
    newnode->data = data;
    newnode->link = NULL;

    newnode->link = top;
    top = newnode;
}

void print()
{
    struct node *temp;
    temp = top;
    printf("stck elements are \n ");
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\t ");
}

int main()
{
    int choice, data;
    while (1)
    {
        printf(" \n 1 push \n 2 print \n 3 quite \n enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the data ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            print();
            break;

        case 3:
            exit(0);
        default:
            printf("\n wrong choice (yes, the girl you like) \n ");
            break;
        }
    }
    return 0;
}
