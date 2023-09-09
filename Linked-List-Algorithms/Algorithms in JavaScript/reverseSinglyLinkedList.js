// This is a possible solution to reverse a singly linked list in JavaScript
// TODO: This needs some driver program and also this needs a bit more testing to confirm it is a
// TODO: good solution


function reverseLinkedList(head) {
    let currentNode = head;
    let previousNode = null;
    let nextNode = null;
  
    while (currentNode) {
      // Store next node
      nextNode = currentNode.next;
  
      // Reverse current node's pointer
      currentNode.next = previousNode;
  
      // Move pointers one position ahead
      previousNode = currentNode;
      currentNode = nextNode;
    }
    return previousNode;
  }