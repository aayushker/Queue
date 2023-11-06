#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int F = -1, R = -1;
int queue[MAX_SIZE];

void enqueue(int value) {
    if ((F == 0 && R == MAX_SIZE - 1) || (R == F - 1)) {
        printf("Queue is full\n");
        return;
    }
    else if (F == -1 && R == -1) {
        F = R = 0;
    }
    else if (R == MAX_SIZE - 1 && F != 0) {
        R = 0;
    }
    else {
        R++;
    }
    queue[R] = value;
}

int dequeue() {
    if (F == -1 && R == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue[F];
    if (F == R) {
        F = R = -1;
    }
    else if (F == MAX_SIZE - 1) {
        F = 0;
    }
    else {
        F++;
    }
    return value;
}

void display() {
    if (F == -1 && R == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    if (R >= F) {
        for (int i = F; i <= R; i++) {
            printf("%d ", queue[i]);
        }
    }
    else {
        for (int i = F; i < MAX_SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= R; i++) {
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