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
    if (q->r == q->f)
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

int dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
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
        printf("Queue is full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

void printQueue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Elements in the queue: ");
        for (int i = q->f + 1; i <= q->r; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n, m, i;

    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    printf("Enter the length of queue: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter element for the queue: ");
        scanf("%d", &m);
        enqueue(&q, m);
    }

    printQueue(&q);

    printf("Dequeueing element: %d\n", dequeue(&q));

    printQueue(&q);

    if (isEmpty(&q))
    {
        printf("Queue is empty\n");
    }

    if (isFull(&q))
    {
        printf("Queue is full\n");
    }

    return 0;
}
