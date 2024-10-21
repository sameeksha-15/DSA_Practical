#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
	int data;
	struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = newNode;  // Initially points to itself
	return newNode;
}

// Function to insert a node at the end of the list
void insertEnd(struct Node** head, int data) {
	struct Node* newNode = createNode(data);

	// If the list is empty, the new node becomes the head
	if (*head == NULL) {
    	*head = newNode;
	} else {
    	struct Node* temp = *head;
    	// Traverse to the last node
    	while (temp->next != *head) {
        	temp = temp->next;
    	}
    	// Update links to insert the new node at the end
    	temp->next = newNode;
    	newNode->next = *head;
	}
	printf("%d inserted at the end.\n", data);
}

// Function to insert a node at the beginning of the list
void insertBeginning(struct Node** head, int data) {
	struct Node* newNode = createNode(data);
    
	if (*head == NULL) {
    	*head = newNode;
	} else {
    	struct Node* temp = *head;
    	// Traverse to the last node
    	while (temp->next != *head) {
        	temp = temp->next;
    	}
    	// Update links to insert at the beginning
    	newNode->next = *head;
    	temp->next = newNode;
    	*head = newNode;  // Update the head to the new node
	}
	printf("%d inserted at the beginning.\n", data);
}

// Function to delete a node from the beginning
void deleteBeginning(struct Node** head) {
	if (*head == NULL) {
    	printf("List is empty. No nodes to delete.\n");
    	return;
	}

	struct Node* temp = *head;
	struct Node* last = *head;

	// If the list has only one node
	if (temp->next == *head) {
    	free(temp);
    	*head = NULL;
	} else {
    	// Traverse to the last node
    	while (last->next != *head) {
        	last = last->next;
    	}
    	// Update the head and the last node's next pointer
    	*head = temp->next;
    	last->next = *head;
    	free(temp);
	}
	printf("Node deleted from the beginning.\n");
}

// Function to delete a node from the end
void deleteEnd(struct Node** head) {
	if (*head == NULL) {
    	printf("List is empty. No nodes to delete.\n");
    	return;
	}

	struct Node* temp = *head;
	struct Node* prev = NULL;

	// If the list has only one node
	if (temp->next == *head) {
    	free(temp);
    	*head = NULL;
	} else {
    	// Traverse to the second last node
    	while (temp->next != *head) {
        	prev = temp;
        	temp = temp->next;
    	}
    	prev->next = *head;  // Update the last node's pointer
    	free(temp);
	}
	printf("Node deleted from the end.\n");
}

// Function to traverse and print the list
void traverse(struct Node* head) {
	if (head == NULL) {
    	printf("List is empty.\n");
    	return;
	}

	struct Node* temp = head;
	do {
    	printf("%d -> ", temp->data);
    	temp = temp->next;
	} while (temp != head);
	printf("HEAD\n");
}

int main() {
	struct Node* head = NULL;

	// Insert nodes at the end
	insertEnd(&head, 10);
	insertEnd(&head, 20);
	insertEnd(&head, 30);

	// Insert a node at the beginning
	insertBeginning(&head, 5);

	// Print the list
	printf("Circular Linked List after insertion:\n");
	traverse(head);

	// Delete a node from the beginning
	deleteBeginning(&head);
	printf("Circular Linked List after deleting from the beginning:\n");
	traverse(head);

	// Delete a node from the end
	deleteEnd(&head);
	printf("Circular Linked List after deleting from the end:\n");
	traverse(head);

	return 0;
}
