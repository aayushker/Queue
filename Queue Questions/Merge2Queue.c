#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Queue {
    unsigned front, rear, size;
    unsigned capacity;
    int* array;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0; 
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Rest of the code...

Queue* mergeQueues(Queue* q1, Queue* q2) {
    Queue* mergedQueue = createQueue(q1->capacity + q2->capacity);
    while (!isEmpty(q1)) {
        enqueue(mergedQueue, dequeue(q1));
    }
    while (!isEmpty(q2)) {
        enqueue(mergedQueue, dequeue(q2));
    }
    return mergedQueue;
}

int main() {
    Queue* q1 = createQueue(1000);
    Queue* q2 = createQueue(1000);

    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);

    enqueue(q2, 4);
    enqueue(q2, 5);
    enqueue(q2, 6);

    Queue* mergedQueue = mergeQueues(q1, q2);

    while (!isEmpty(mergedQueue)) {
        printf("%d ", dequeue(mergedQueue));
    }

    return 0;
}