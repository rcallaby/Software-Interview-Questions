//Create a Node constructor to create a new node
function Node(data) {
    this.data = data;
    this.next = null;
}

//Create a LinkedList constructor to create a new linked list
function LinkedList() {
    this.head = null;
    this.tail = null;
}

//Add a node to the linked list
LinkedList.prototype.add = function(data) {
    var node = new Node(data);
    
    if (this.head === null) {
        this.head = node;
        this.tail = node;
    } else {
        this.tail.next = node;
        this.tail = node;
    }
};

//Function to determine the length of a singly linked list
LinkedList.prototype.length = function() {
    var current = this.head;
    var count = 0;
    //Loop through the list until the end is reached
    while (current !== null) {
        count++;
        current = current.next;
    }
    //Return the length
    return;
}

//Create a new linked list
var list = new LinkedList();

//Add nodes to the linked list
list.add(1);
list.add(2);
list.add(3);
list.add(4);

//Print the length of the linked list
console.log(list.length()); //4