using System;

public class SelectionSort
{
    public static void Main()
    {
        // Create an unsorted array of string elements
        int[] unsorted = { 9, 3, 5, 1, 8, 6, 4, 2, 7 };

        // Print the unsorted array
        Console.WriteLine("Unsorted Array:");
        foreach (int num in unsorted)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine();

        // Sort the array
        SelectionSortAlgorithm(unsorted);

        // Print the sorted array
        Console.WriteLine("Sorted Array:");
        foreach (int num in unsorted)
        {
            Console.Write(num + " ");
        }
        Console.WriteLine();
    }

    public static void SelectionSortAlgorithm(int[] arr)
    {
        int min;

        for (int i = 0; i < arr.Length; i++)
        {
            // Set min to the current iteration of i
            min = i;

            for (int j = i; j < arr.Length; j++)
            {
                if (arr[j] < arr[min])
                {
                    // Update min if a smaller value is found
                    min = j;
                }
            }

            // Swap the values
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    } 
}