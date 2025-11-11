#include <stdio.h>
#include <stdlib.h>

struct circular_queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct circular_queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct circular_queue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct circular_queue *q, int val)
{
    if (isFull(q))
    {
        printf("The Queue is full\n");
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
        printf("Enqueud element : %d\n", val);
    }
}

int dequeue(struct circular_queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("The Queue is Empty\n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct circular_queue q;
    q.size = 10;
    q.f = 0;
    q.r = 0;
    q.arr = (int *)malloc(q.size * (sizeof(int)));

    enqueue(&q, 33);
    enqueue(&q, 78);
    enqueue(&q, 5);

    printf("Dequeing element : %d\n", dequeue(&q));
    printf("Dequeing element : %d\n", dequeue(&q));
    printf("Dequeing element : %d\n", dequeue(&q));

    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 5);

    if (isFull(&q))
    {
        printf("Queue is full\n");
    }
    if (isEmpty(&q))
    {
        printf("Queue is empty\n");
    }
    return 0;
}
