#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct PriorityQueue {
    struct Node* front;
};

void enqueue(struct PriorityQueue* q, int value, int priority) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->priority = priority;
    if (q->front == NULL || priority < q->front->priority) {
        new_node->next = q->front;
        q->front = new_node;
    }
    else {
        struct Node* temp = q->front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

int dequeue(struct PriorityQueue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->front->data;
    struct Node* temp = q->front;
    q->front = q->front->next;
    free(temp);
    return value;
}

void display(struct PriorityQueue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    struct Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct PriorityQueue q = { NULL };
    int ch, x,y;
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
            printf("Enter the priority element to insert: ");
            scanf("%d", &y);
            enqueue(&q, x,y);
            break;
        case 2:
            x = dequeue(&q);
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