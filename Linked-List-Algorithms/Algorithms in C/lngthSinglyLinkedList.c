
#include <stdio.h>
#include <stdlib.h>

/* This is a solution to find the length of a singly linked list
*/
 
struct node
{
    int data;
    struct node *next;
};
 
int getCount(struct node *head);
 
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    /* Use the count function to get the count of nodes in the list */
    printf("Count of nodes is %d", getCount(head));
    return 0;
}
 
/* returns the count of nodes in the linked list */
int getCount(struct node *head)
{
    int count = 0;  // Initialize count
    struct node *current = head;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}