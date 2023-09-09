using System;

// This is a example of the radixsort algorithm written in C#

// TODO: This may need refactoring

namespace RadixSort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] array = new int[] { 543, 123, 456, 477, 678, 987, 876, 765 };

            int maxDigits = GetMaxDigits(array); // get the maximum number of digits in the array

            RadixSort(array, maxDigits); // sort the array using radix sort

            Console.WriteLine("Sorted Array:");
            foreach (int n in array)
            {
                Console.Write(n + " ");
            }
            Console.ReadKey();
        }

        // radix sort method
        static void RadixSort(int[] array, int maxDigits)
        {
            // declare and initialize an array of 10 buckets
            int[][] buckets = new int[10][];
            for (int i = 0; i < 10; i++)
            {
                buckets[i] = new int[array.Length];
            }

            // declare and initialize an array to efficiently keep track of the number of elements in each bucket
            int[] numElements = new int[10];

            // loop through each digit position from right to left
            for (int digitPos = 0; digitPos < maxDigits; digitPos++)
            {
                // loop through each element in the array
                for (int i = 0; i < array.Length; i++)
                {
                    // get the digit at the current position
                    int digit = GetDigit(array[i], digitPos);

                    // add the element to the appropriate bucket
                    buckets[digit][numElements[digit]++] = array[i];
                }

                // reset the array index
                int index = 0;

                // loop through each bucket and add the elements back to the array
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < numElements[i]; j++)
                    {
                        array[index++] = buckets[i][j];
                    }

                    // reset the number of elements
                    numElements[i] = 0;
                }
            }
        }
    }
}