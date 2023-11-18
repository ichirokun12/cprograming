#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

struct node *AddToEmpty(struct node* head, int data) {
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node* addAtEnd(struct node* head, int data) {
    struct node* temp, *tp;
    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    tp = head;
    while (tp->next != NULL)
        tp = tp->next;
    tp->next = temp;
    temp->prev = tp;
    return head;
}

struct node* delFirst(struct node* head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    struct node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    temp = NULL;
    return head;
}


struct node* delLast(struct node* head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    struct node* temp = head;
    struct node* temp2;

    while(temp->next !=  NULL) 
    temp = temp->next;
    temp2 = temp->prev;
    temp2->next =NULL;
    free(temp);
    return head;
}

void print(struct node* head) {
    struct node* ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;

    head = AddToEmpty(head, 45);
    head = addAtEnd(head, 456);
    head = addAtEnd(head, 67);

    printf("Before deletion:\n");
    print(head);

    head = delLast(head);

    printf("After deletion:\n");
    print(head);

    return 0;
}
