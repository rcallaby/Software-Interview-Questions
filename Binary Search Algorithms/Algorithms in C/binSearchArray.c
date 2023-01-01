#include<stdio.h>

/*
    This is a solution to how to perform a binary search in a given array of 120 integers
*/


int binarySearch(int arr[], int l, int r, int x) 
{ 
    while (l <= r) 
    { 
        int m = l + (r-l)/2; 
  
        if (arr[m] == x) 
            return m; 
  
        if (arr[m] < x) 
            l = m + 1; 
  
        else
            r = m - 1; 
    } 

    return -1; 
} 

int main (void) 
{ 
    int arr[120]; 
    int n = sizeof(arr)/ sizeof(arr[0]); 
    int x; 

    // Input array elements
    printf("Input array elements: \n");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to be searched
    printf("Input element to be searched: \n");
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n-1, x); 
    (result == -1)? printf("Element is not present in array") 
                   : printf("Element is present at index %d", 
                                                   result); 
    return 0; 
}