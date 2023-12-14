#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *q)
{
    if (q->r ==q-> f)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int dqueue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("queue is empty");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("queue is full");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int main()
{

    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));


    enqueue(&q, 12);
    enqueue(&q, 123);
    enqueue(&q, 12456);
    enqueue(&q, 1278910);

    printf("dqueueing element %d", dqueue(&q));
    
    if(isEmpty(&q)) {
        printf("queue is empty");
    }

    
    if(isFull(&q)) {
        printf("queue is full");
    }

    return 0;

}
