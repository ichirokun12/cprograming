# include <stdio.h>
# include <stdlib.h>

    struct node *f = NULL;
    struct node *r = NULL;

struct node {
    int data;
    struct node *next;
};

void Linked_list_treversal(struct node *ptr) {
    printf("printing the elements of the Linked list \n");
    while(ptr != NULL) {
        printf("elements : %d \n ", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue( int val) {
    struct node *n = (struct node*) malloc(sizeof(struct node*));
    if(n == NULL) {
        printf("queue is full");

    } else {
        n->data = val;
        n->next = NULL;
        if(f == NULL) {
            f= r = n;
        } else {
            r->next = n;
            r = n;
        }
    }
}

int dequeue() {
    int val = -1;
    struct node *ptr= f;
    if(f == NULL) {
        printf("queue is empty");
    }
    else {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
}

int main() {
  
    enqueue(1);
    enqueue(23);
    enqueue(2234);
    enqueue(4);
    dequeue();


    Linked_list_treversal(f);
    return 0;
}
