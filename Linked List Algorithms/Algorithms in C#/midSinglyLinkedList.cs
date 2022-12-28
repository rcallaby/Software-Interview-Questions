public class Program
{
    // create a Linked List node
    public class Node
    {
        public int data;
        public Node next;

        public Node(int data)
        {
            this.data = data;
            this.next = null;
        }
    }

    public static Node head;

    public static void Main(string[] args)
    {
        // create a linked list with 5 elements
        head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);
        head.next.next.next = new Node(4);
        head.next.next.next.next = new Node(5);

        int middleElement = FindMiddleElement(head);

        Console.WriteLine("Middle element of the linked list is " + middleElement);
    }

    // Function to find the middle element of a singly linked list
    private static int FindMiddleElement(Node head)
    {
        Node slow_ptr = head;
        Node fast_ptr = head;

        if (head != null)
        {
            while (fast_ptr != null && fast_ptr.next != null)
            {
                fast_ptr = fast_ptr.next.next;
                slow_ptr = slow_ptr.next;
            }
            return slow_ptr.data;
        }
        return 0;
    }
}