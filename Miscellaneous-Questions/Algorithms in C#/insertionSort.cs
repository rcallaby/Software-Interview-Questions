using System; 

// This is a possible solution for demonstrating an insertion sort using C# 
  
class InsertionSort 
{ 
    static void sort(int[] arr) 
    { 
        int n = arr.Length; 
        for (int i = 1; i < n; ++i) 
        { 
            int key = arr[i]; 
            int j = i - 1; 
  

            while (j >= 0 && arr[j] > key) 
            { 
                arr[j + 1] = arr[j]; 
                j = j - 1; 
            } 
            arr[j + 1] = key; 
        } 
    } 
  

    public static void Main() 
    { 
        int[] arr = { 12, 11, 13, 5, 6 }; 
  
        sort(arr); 
  
        Console.WriteLine("Sorted array:"); 
        printArray(arr); 
    } 
  
    // Prints the array 
    static void printArray(int[] arr) 
    { 
        int n = arr.Length; 
        for (int i = 0; i < n; ++i) 
            Console.Write(arr[i] + " "); 
  
        Console.WriteLine(); 
    } 
}