# This is a possible solution in python to reverse a singly linked list
# TODO: This needs some editing and possible refactoring

# Node class 
class Node: 
    # Function to initialize the node object 
    def __init__(self, data): 
        self.data = data  # Assign data 
        self.next = None  # Initialize next as null 

# Linked List class contains a Node object 
class LinkedList: 
  
    # Function to initialize head 
    def __init__(self): 
        self.head = None
  
    # This function prints contents of linked list 
    # starting from head 
    def printList(self): 
        temp = self.head 
        while temp: 
            print (temp.data) 
            temp = temp.next
  
    # This function reverses the linked list 
    def reverse(self): 
        prev = None
        current = self.head 
        while(current is not None): 
            next = current.next
            current.next = prev 
            prev = current 
            current = next
        self.head = prev 

if __name__ == '__main__': 
  
    # Start with the empty list 
    llist = LinkedList() 
  
    llist.head = Node(1) 
    second = Node(2) 
    third = Node(3) 
  
    llist.head.next = second; # Link first node with second 
    second.next = third; # Link second node with the third node 
  
    llist.printList() 
    llist.reverse() 
    print('Reversed Linked list')
    llist.printList()