# include <stdio.h>
# include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

struct node* addToEmpty(struct node* head , int data) {
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node* addAtBag(struct node* head, int data) {
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    temp->prev = temp;
    head = temp;
    return head;
}

struct node* AddAtEnd(struct node* head, int data) {
    struct node* temp, *tp;
    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    tp = head;
    while(tp->next != NULL) {
        tp = tp->next;
        tp->next = temp;
        temp->prev = tp;
        return head;
    }
}

int main() {
    struct node* head = NULL;
    struct node* ptr;
     
     head = addToEmpty(head, 20);
     head = addAtBag(head, 30);
     head = AddAtEnd(head, 40);

     ptr = head;
     while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;  
     }

     return 0;
}
