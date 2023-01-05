using System;

namespace BubbleSortDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            // create an array of unsorted integers
            int[] nums = {5, 3, 8, 2, 1, 4};

            // print out the unsorted array
            Console.WriteLine("Unsorted Array:");
            foreach (int n in nums)
            {
                Console.Write(n + " ");
            }
            Console.WriteLine();

            // sort the array using bubble sort
            BubbleSort(nums);

            // print out the sorted array
            Console.WriteLine("Sorted Array:");
            foreach (int n in nums)
            {
                Console.Write(n + " ");
            }
            Console.WriteLine();
        }

        static void BubbleSort(int[] arr)
        {
            // keep track of whether or not an element was swapped
            bool swapped;

            do
            {
                // assume no elements were swapped
                swapped = false;


                for (int i = 0; i < arr.Length - 1; i++)
                {
                    // if two adjacent elements are out of order
                    if (arr[i] > arr[i + 1])
                    {
                        // swap them
                        int temp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = temp;

                        // indicate that an element was swapped
                        swapped = true;
                    }
                }
            } while (swapped);
        }
    }
}