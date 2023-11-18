#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *AddToEmpty(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node *AddToBag(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = head;
    if (head != NULL)
        head->prev = temp;
    head = temp;
    return head;
}

struct node *AtTheEnd(struct node *head, int data)
{
    struct node *temp, *tp;
    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    tp = head;
    while (tp->next != NULL)
    {
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return head;
}

struct node *AddAfterPos(struct node *head, int data, int position)
{
    struct node *newp = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;

    if (position == 1)
    {
        return AddToBag(head, data);
    }

    newp = malloc(sizeof(struct node));
    newp->prev = NULL;
    newp->data = data;
    newp->next = NULL;

    while (position != 1)
    {
        temp = temp->next;
        position--;
    }

    if (temp == NULL)
    {
        return AddToBag(head, data);
    }
    else
    {
        temp2 = temp->next;
        temp->next = newp;
        newp->prev = temp;
        newp->next = temp2;

        if (temp2 != NULL)
            temp2->prev = newp;

        return head;
    }
}

struct node *createALinkedList(struct node *head)
{
    int n, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n == 0)
        return head;

    printf("Enter the element for node 1: ");
    scanf("%d", &data);
    head = AddToEmpty(head, data);

    for (i = 1; i < n; i++)
    {
        printf("Enter the element for node %d: ", i + 1);
        scanf("%d", &data);
        head = AtTheEnd(head, data);
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    struct node *ptr;

    head = createALinkedList(head);

    ptr = head;
    printf("\nLinked List: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}
