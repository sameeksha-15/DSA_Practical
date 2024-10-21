#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    struct node *next;
    int data;
};

struct node *head = NULL;

void insertion_beginning();
void insertion_last();
void deletion_beginning();
void deletion_last();
void display();
void search();

int main() {
    int choice = 0;
    while(choice != 7) {
        printf("\n********* Main Menu *********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("1. Insert in Beginning\n");
        printf("2. Insert at Last\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from Last\n");
        printf("5. Search\n");
        printf("6. Show\n");
        printf("7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                insertion_beginning();
                break;
            case 2:
                insertion_last();
                break;
            case 3:
                deletion_beginning();
                break;
            case 4:
                deletion_last();
                break;
            case 5:
                search();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Please enter a valid choice.\n");
        }
    }
    return 0;
}

void insertion_beginning() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("\nEnter Item value: ");
        scanf("%d", &item);
        ptr->data = item;

        if(head == NULL) {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        } else {
            temp = head;
            while(temp->next != head) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        printf("\nNode inserted at the beginning\n");
    }
}

void insertion_last() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL) {
        printf("\nOVERFLOW\n");
    } else {
        printf("\nEnter Item value: ");
        scanf("%d", &item);
        ptr->data = item;

        if(head == NULL) {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        } else {
            temp = head;
            while(temp->next != head) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = head;
            head->prev = ptr;
        }
        printf("\nNode inserted at the end\n");
    }
}

void deletion_beginning() {
    struct node *temp;
    if(head == NULL) {
        printf("\nUNDERFLOW\n");
    } else if(head->next == head) {
        head = NULL;
        free(head);
        printf("\nNode deleted from the beginning\n");
    } else {
        temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        head->next->prev = temp;
        free(head);
        head = temp->next;
        printf("\nNode deleted from the beginning\n");
    }
}

void deletion_last() {
    struct node *ptr;
    if(head == NULL) {
        printf("\nUNDERFLOW\n");
    } else if(head->next == head) {
        head = NULL;
        free(head);
        printf("\nNode deleted from the end\n");
    } else {
        ptr = head;
        while(ptr->next != head) {
            ptr = ptr->next;
        }
        ptr->prev->next = head;
        head->prev = ptr->prev;
        free(ptr);
        printf("\nNode deleted from the end\n");
    }
}

void display() {
    struct node *ptr;
    ptr = head;
    if(head == NULL) {
        printf("\nList is empty\n");
    } else {
        printf("\nDisplaying the list:\n");
        while(ptr->next != head) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}

void search() {
    struct node *ptr;
    int item, i = 0, flag = 1;
    if(head == NULL) {
        printf("\nEmpty List\n");
    } else {
        printf("\nEnter item to search: ");
        scanf("%d", &item);
        ptr = head;
        while(ptr->next != head) {
            if(ptr->data == item) {
                printf("\nItem found at position %d\n", i + 1);
                flag = 0;
                break;
            }
            i++;
            ptr = ptr->next;
        }
        if(ptr->data == item && flag != 0) {
            printf("\nItem found at position %d\n", i + 1);
            flag = 0;
        }
        if(flag != 0) {
            printf("\nItem not found\n");
        }
    }
}
