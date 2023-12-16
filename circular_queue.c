# include <stdio.h>
# include <stdlib.h>

struct circular_q {
    int size; 
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circular_q *q) {
    if(q->r == q->f) {
        return 1;
    }
    return 0;
}

int isFull(struct circular_q *q) {
    if((q->r+1)% q->size == q->f) {
        return 1;
    }
    return 0;
}

void enqueue(struct circular_q *q, int val) {
    if(isFull(q)) {
        printf("queue is full \n");
    } else {
       q->r = (q->r+1) % q->size;
        q->arr[q->r] = val;
        printf("enqueued element : %d \n", val);
    }
}

int dequeue(struct circular_q *q) {
    int a = -1;
    if(isEmpty(q)) {
        printf("queue is empty \n");
    } else {
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}



int main() {
    struct circular_q  q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    enqueue(&q, 11);
    enqueue(&q, 1);
    enqueue(&q, 111);

    printf("dequeing element %d", dequeue(&q));


    if(isEmpty(&q)) {
        printf("queue is empty \n");

    }

    if(isFull(&q)) {
        printf("queue is full");

    }
    return 0;

}
