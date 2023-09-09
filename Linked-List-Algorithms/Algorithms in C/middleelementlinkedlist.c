#include <stdio.h>
#include <stdlib.h>

/*This is a solution to finding a middle element of a singly linked list in one pass*/

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to find middle element in singly linked list
struct Node *findMiddle(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    if (head != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        return slow_ptr;
    }
    return NULL;
}

// Function to insert a node at the beginning of the linked list
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)  = new_node;
}

// Function to print linked list
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver program to test above function
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

    // Inserting elements in linked list
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printf("Linked list: ");
    printList(head);

    // Find middle element
    struct Node *middle = findMiddle(head);

    // Print middle element
    printf("\nMiddle element: %d\n", middle->data);

    return 0;
}