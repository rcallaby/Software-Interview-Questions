
#include<stdio.h> 
#include<stdlib.h> 

/*This is a solution to the problem of finding element of a singly linked list in one pass*/

struct Node 
{ 
	int data; 
	struct Node* next; 
}; 

/* Given a reference (pointer to pointer) to the head of a list 
and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data) 
{ 
	/* 1. allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 

	/* 2. put in the data */
	new_node->data = new_data; 

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref); 

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node; 
} 

// This function finds the element in a singly linked list in one pass 
int findElement(struct Node* head, int data) 
{ 
	// start from the beginning 
	struct Node* current = head; 
	
	// traverse the list 
	while (current != NULL) 
	{ 
		// if the element is found, return true 
		if (current->data == data) 
			return 1; 

		// move to next node 
		current = current->next; 
	} 

	// element not found 
	return 0; 
} 

int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 

	push(&head, 1); 
	push(&head, 2); 
	push(&head, 3); 
	push(&head, 4); 
	push(&head, 5); 

	int data = 4; 

	if (findElement(head, data)) 
		printf("Element found"); 
	else
		printf("Element not found"); 

	return 0; 
}