#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* F;
    struct Node* R;
};

void enqueue(struct Queue* q, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    if (q->F == NULL) {
        q->F = new_node;
    }
    else {
        q->R->next = new_node;
    }
    q->R = new_node;
    q->R->next = q->F;
}

int dequeue(struct Queue* q) {
    if (q->F == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->F->data;
    struct Node* temp = q->F;
    if (q->F == q->R) {
        q->F = q->R = NULL;
    }
    else {
        q->F = q->F->next;
        q->R->next = q->F;
    }
    free(temp);
    return value;
}

void display(struct Queue* q) {
    if (q->F == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    struct Node* temp = q->F;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->F);
    printf("\n");
}

int main() {
    struct Queue q = { NULL, NULL };
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
            enqueue(&q, x);
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