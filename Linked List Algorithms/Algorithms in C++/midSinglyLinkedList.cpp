#include <iostream>
using namespace std;

// create a node structure 
struct Node 
{ 
    int data; 
    Node* next; 
}; 
  
// function to get the middle of the linked list 
void printMiddle(Node *head) 
{ 
    Node *slow_ptr = head; 
    Node *fast_ptr = head; 
  
    if (head!=NULL) 
    { 
        while (fast_ptr != NULL && fast_ptr->next != NULL) 
        { 
            fast_ptr = fast_ptr->next->next; 
            slow_ptr = slow_ptr->next; 
        } 
        cout<<"The middle element is "<<slow_ptr->data; 
    } 
} 
  
// function to insert a new node at the beginning 
void push(Node** head_ref, int new_data) 
{ 
    Node* new_node = new Node(); 
  
    new_node->data  = new_data; 
  
    new_node->next = (*head_ref); 
  
    (*head_ref)    = new_node; 
} 
  
// function to print the linked list 
void printList(Node *head) 
{ 
    while (head != NULL) 
    { 
        cout << head->data << " "; 
        head = head->next; 
    } 
    cout<<"\n"; 
} 
  
// Driver code 
int main() 
{ 
    Node* head = NULL; 
    int i; 
  
    for (i=5; i>0; i--) 
    { 
        push(&head, i); 
        printList(head); 
        printMiddle(head); 
    } 
  
    return 0; 
}