#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void initializeQueue(struct Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}
int isFULL(struct Queue *queue) {
    return queue->rear == MAX - 1;
}
int isEmpty(struct Queue *queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

void enqueue(struct Queue *queue,int element) {
    if (isFULL(queue)) {
        printf("Error: Queue overflow. Cannot enqueue element.\n");
        return;
    }
    queue->arr[++queue->rear]= element;
    printf("Element enqueued: %d\n",element);
}

int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
       printf("Error: Queue underflow. Cannot dequeue element.\n");
       return-1;
    }
    int element = queue->arr[queue->front++];
    
    if(queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    
    return element;
}

void displayQueue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    int choice, element;
    
    initializeQueue(&queue);
    
    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1, Enqueue\n");
        printf("2. dequeue\n");
        printf("3. Display\n");
        printf("4, Exit your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("enter element to ennqueue: ");
                scanf("%d", &element);
                enqueue(&queue, element);
                break;
            case 2:
                element = dequeue(&queue);
                if (element != -1)
                    printf("Dequeue element: %d\n", element);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}    
    
        
