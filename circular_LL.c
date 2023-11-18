# include <stdio.h>
# include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void linklist(struct Node* head) {
    struct Node *ptr = head;
      printf("elements %d\n", ptr->data);
        ptr = ptr->next;
    while(ptr != head) {
        printf("elements %d\n", ptr->data);
        ptr = ptr->next;
    } 
}

struct Node* addnode(struct Node*head,  int data) {
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr-> data = data;
    return ptr;
 
}

int main() {
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head =(struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));

    head-> data = 6565;
    head-> next = second;

    second -> data = 8465464;
    second -> next = third;

    third -> data = 6548998;
    third-> next = fourth;

    fourth ->data = 4454;
    fourth -> next = head;

    linklist(head);
 

    return 0;
}
