#include <stdio.h>

int stack[100], i, j, choice = 0, n, top = -1;

void push();
void pop();
void show();
int peek();
int isFull();
int isEmpty();

int main() {
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);
    printf("********* Stack operations using array *********");

    printf("\n----------------------------------------------\n");
    while (choice != 5) {
        printf("Choose one from the below options...\n");
        printf("\n1.Push\n2.Pop\n3.Show\n4.Peek\n5.Exit");
        printf("\n Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
            case 4:
                printf("Top element is: %d\n", peek());
                break;
            case 5:
                printf("Exiting....\n");
                break;
            default:
                printf("Please Enter a valid choice\n");
        }
    }
}

void push() {
    int val;
    if (isFull()) {
        printf("\nOverflow\n");
    } else {
        printf("Enter the value: ");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop() {
    if (isEmpty()) {
        printf("Underflow\n");
    } else {
        printf("Popped element is: %d\n", stack[top]);
        top = top - 1;
    }
}

void show() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    } else {
        return stack[top];
    }
}

int isFull() {
    return top == n - 1;
}

int isEmpty() {
    return top == -1;
}
