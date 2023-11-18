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
    temp->next = NULL;
    temp->next = head;
    temp->prev = temp;
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
        tp->next = temp;
        temp->prev = tp;
        return head;
    }
}

struct node *AddAfterpos(struct node *head, int data, int position)
{
    struct node *newp = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newp = AddToEmpty(head, data);

    while (position != 1)
    {

        temp = temp->next;
        position--;
    }
    if (temp == NULL)
    {
        temp->next = newp;
        newp->prev = temp;
    }
    else
    {
        temp2 = temp->next;
        temp->next = newp;
        temp2->prev = newp;
        newp->next = temp2;
        newp->prev = temp;
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    struct node *ptr;

    head = AddToEmpty(head, 20);
    head = AddToBag(head, 100);
    head = AtTheEnd(head, 10000);
    head = AddAfterpos(head, 5, 2);

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}
