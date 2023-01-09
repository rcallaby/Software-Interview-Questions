//This is a possible solution to find a middle element of a singly linked list
// TODO: This may need some refactoring. I need to think about this solution.


class Node { 
    constructor(data) 
    { 
        this.data = data; 
        this.next = null
    } 
} 

// Linked List class 
class LinkedList { 
    constructor() 
    { 
        this.head = null; 
        this.size = 0; 
    } 
    
    // Add a new node at the end 
    add(data) 
    { 
        // Create a new node 
        let node = new Node(data); 
        // Store current node 
        let current; 
        // If list is Empty, add the node and make it head 
        if (this.head == null) 
            this.head = node; 
        else { 
            current = this.head; 
            // Iterate to the end of the list 
            while (current.next) { 
                current = current.next; 
            } 
            // Add node 
            current.next = node; 
        } 
        this.size++; 
    } 
    
    // Find the middle element of the list 
    findMiddle() 
    { 
        let slowPtr = this.head; 
        let fastPtr = this.head; 
  
        if (this.head !== null) { 
            while (fastPtr !== null && fastPtr.next !== null) { 
                fastPtr = fastPtr.next.next; 
                slowPtr = slowPtr.next; 
            } 
            console.log("The middle element is: " + slowPtr.data); 
        } 
    } 
} 

//Create an instance of the Linked List 
let list = new LinkedList(); 
list.add(10); 
list.add(20); 
list.add(30); 
list.add(40); 
list.add(50); 

//Find the middle element of the list 
list.findMiddle();