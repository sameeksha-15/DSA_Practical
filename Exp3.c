#include <stdio.h>
#include <stdlib.h>
#define MAX 50

void enqueue();
void dequeue();
void display();
int isfull();
int isempty();
int size();
int queue_front();
int queue_rear();

int queue_array[MAX];
int rear = -1;
int front = -1;

int main() {
    int choice;
    while (1) {
        printf("1.Enqueue element to queue \n");
        printf("2.Dequeue element from queue \n");
        printf("3.Display all elements of queue \n");
        printf("4.Display front element \n");
        printf("5.Display rear element \n");
        printf("6.Check if queue is empty \n");
        printf("7.Check if queue is full \n");
        printf("8.Get the size of the queue \n");
        printf("9.Quit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Front element: %d\n", queue_front());
                break;
            case 5:
                printf("Rear element: %d\n", queue_rear());
                break;
            case 6:
                printf(isempty() ? "Queue is empty\n" : "Queue is not empty\n");
                break;
            case 7:
                printf(isfull() ? "Queue is full\n" : "Queue is not full\n");
                break;
            case 8:
                printf("Queue size: %d\n", size());
                break;
            case 9:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
}

void enqueue() {
    int add_item;
    if (isfull()) {
        printf("Queue Overflow\n");
    } else {
        if (isempty()) {
            front = 0;
        }
        printf("Insert the element into the queue: ");
        scanf("%d", &add_item);
        queue_array[++rear] = add_item;
    }
}

void dequeue() {
    if (isempty()) {
        printf("Queue Underflow\n");
    } else {
        printf("Element deleted from queue is: %d\n", queue_array[front++]);
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (isempty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
}

int isfull() {
    return rear == MAX - 1;
}

int isempty() {
    return front == -1;
}

int size() {
    return (isempty() ? 0 : rear - front + 1);
}

int queue_front() {
    if (isempty()) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue_array[front];
}

int queue_rear() {
    if (isempty()) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue_array[rear];
}
