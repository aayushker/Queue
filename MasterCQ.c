#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int front = -1, rear = -1;
int queue[MAX_SIZE];

void enqueue(int value) {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1)) {
        printf("Queue is full\n");
        return;
    }
    else if (front == -1 && rear == -1) {
        front = rear = 0;
    }
    else if (rear == MAX_SIZE - 1 && front != 0) {
        rear = 0;
    }
    else {
        rear++;
    }
    queue[rear] = value;
}

int dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue[front];
    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX_SIZE - 1) {
        front = 0;
    }
    else {
        front++;
    }
    return value;
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    else {
        for (int i = front; i < MAX_SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}

int main() {
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
            enqueue(x);
            break;
        case 2:
            x = dequeue();
            if (x != -1)
                printf("Deleted element is %d\n", x);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}