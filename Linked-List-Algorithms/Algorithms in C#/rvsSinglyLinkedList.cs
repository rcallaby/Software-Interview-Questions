
using System;

/*
    This is a solution in C# that will reverse a singly linked list.
*/

public class Program
{
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

    public static void ReverseList()
    {
        Node prev = null;
        Node current = head;
        Node next = null;
        while (current != null)
        {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    public static void PrintList()
    {
        Node temp = head;
        while (temp != null)
        {
            Console.Write(temp.data + " ");
            temp = temp.next;
        }
        Console.WriteLine();
    }

    public static void Main(string[] args)
    {
        head = new Node(1);
        head.next = new Node(2);
        head.next = new Node(3);
        head.next.next = new Node(4);
        head.next.next.next = new Node(5);

        Console.Write("Original List: ");
        PrintList();

        ReverseList();
        Console.Write("Reversed List: ");
        PrintList();
    }
}