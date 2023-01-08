# This is a solution in Python to find a middle element of a singly linked list

# Node class 
class Node: 
    # Function to initialise the node object 
    def __init__(self, data): 
        self.data = data # Assign data 
        self.next = None # Initialize next as null

# Linked List class 
class LinkedList: 
    # Function to initialize head 
    def __init__(self): 
        self.head = None
  
    # Function to get the middle element of the linked list 
    def getMiddleElement(self): 
        if self.head is None: 
            return 
  
        # Initialize slow and fast pointers 
        slow_ptr = self.head 
        fast_ptr = self.head 
  
        # Move fast pointer by two and slow pointer by one 
        # Finally slow_ptr will point to the middle node 
        while(fast_ptr is not None and 
              fast_ptr.next is not None): 
            fast_ptr = fast_ptr.next.next
            slow_ptr = slow_ptr.next
  
        return slow_ptr.data 
  
# Code execution starts here 
if __name__=='__main__': 
  
    # Start with the empty list 
    llist = LinkedList() 
  
    llist.head = Node(1) 
    second = Node(2) 
    third = Node(3) 
  
    llist.head.next = second; # Link first node with second  
    second.next = third; # Link second node with the third node 
  
    print("The middle element is :", end="") 
    print(llist.getMiddleElement())