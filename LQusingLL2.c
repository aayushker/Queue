#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
    int size;
    int capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

int isFull(struct Queue* queue) {
    return queue->size == queue->capacity;
}

int isEmpty(struct Queue* queue) {
    return queue->size == 0;
}

void enqueue(struct Queue* queue, int x) {
    if (isFull(queue)) {
        printf("Overflow\n");
        return;
    }
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Underflow\n");
        return;
    }
    
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    queue->size--;
    if(queue->size <= 0){
        printf("Underflow\n");
    }
    else{
        struct Node* current = queue->front;
        while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
        }
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Empty\n");
        return;
    }
    
    
    struct Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int M, Q;
    scanf("%d %d", &M, &Q);

    struct Queue* queue = createQueue(M);

    while (Q--) {
        int query, x;
        scanf("%d", &query);
        if (query == 1) {
            scanf("%d", &x);
            enqueue(queue, x);
        } else if (query == 2) {
            dequeue(queue);
        } else if (query == 3) {
            display(queue);
        }
    }

    return 0;
}