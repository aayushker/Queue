#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

typedef struct Queue {
    Stack* stack1;
    Stack* stack2;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

void enqueue(Queue* queue, int item) {
    push(queue->stack1, item);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue->stack2)) {
        while (!isEmpty(queue->stack1)) {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    return pop(queue->stack2);
}

int main() {
    Queue* queue = createQueue(1000);
    int choice, value;

    do {
        printf("\n**** MENU ****\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("Enter the value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(queue, value);
                    break;
            case 2: value = dequeue(queue);
                    if (value != -1)
                        printf("Dequeued value is %d\n", value);
                    else
                        printf("Queue is empty\n");
                    break;
            case 3: break;
            default: printf("Incorrect choice\n");
        }
    } while(choice != 3);

    return 0;
}