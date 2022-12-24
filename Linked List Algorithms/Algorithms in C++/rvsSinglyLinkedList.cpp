#include <iostream> 
using namespace std; 

/*
 This is a solution to reverse a singly linked list using recursion.
*/

// A linked list node 
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

/* Function to reverse the linked list */
static void reverse(struct Node** head_ref) 
{ 
	struct Node* prev = NULL; 
	struct Node* current = *head_ref; 
	struct Node* next; 
	while (current != NULL) 
	{ 
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
	} 
	*head_ref = prev; 
} 

/* Function to push a node */
void push(struct Node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = 
			(struct Node*) malloc(sizeof(struct Node)); 

	/* put in the data */
	new_node->data = new_data;  

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Function to print linked list */
void printList(struct Node *head) 
{ 
	struct Node *temp = head; 
	while(temp != NULL) 
	{ 
		cout<<temp->data<<" "; 
		temp = temp->next; 
	} 
} 

// Driver program to test above functions 
int main() 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 

	/* Let us create a sorted linked list to test the functions 
Created linked list will be 11->12->13->14->15 */
	push(&head, 15); 
	push(&head, 14); 
	push(&head, 13); 
	push(&head, 12); 
	push(&head, 11); 

	cout<<"Given linked list\n"; 
	printList(head); 

	/* Reverse the linked list */
	reverse(&head); 

	cout<<"\nReversed Linked list \n"; 
	printList(head); 
	getchar(); 
}