#include <stdio.h>
#include <stdlib.h>
#define size 10

typedef struct queue
{
    int a[size];
    int F, R;
} Queue;

void init(Queue *q)
{
    q->F = q->R = -1;
}

int underflow(Queue *q)
{
    if (q->F == -1)
        return 1;
    return 0;
}

int overflow(Queue *q)
{
    if (q->R == size - 1)
        return 1;
    return 0;
}

void insert(Queue *q, int x)
{
    if (overflow(q))
    {
        printf("Queue is full\n");
        return;
    }
    if (underflow(q))
    {
        q->F = q->R = 0;
        q->a[q->R] = x;
        return;
    }
    q->R++;
    q->a[q->R] = x;
}

int delete(Queue *q)
{
    if (underflow(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int x = q->a[q->F];
    if (q->F == q->R)
    {
        q->F = q->R = -1;
        return x;
    }
    q->F++;
    return x;
}

void display(Queue *q)
{
    if (underflow(q))
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->F; i <= q->R; i++)
        printf("%d ", q->a[i]);
    printf("\n");
}

int main()
{
    Queue q;
    init(&q);
    int ch, x;
    while (1)
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &x);
            insert(&q, x);
            break;
        case 2:
            x = delete (&q);
            if (x != -1)
                printf("Deleted element is %d\n", x);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
