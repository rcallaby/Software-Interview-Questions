#include <iostream> 
using namespace std; 

// Function to swap two elements A[i] and A[j] 
void swap(int A[], int i, int j) 
{ 
	int temp = A[i]; 
	A[i] = A[j]; 
	A[j] = temp; 
} 

// Function to implement bubble sort 
void bubbleSort(int A[], int n) 
{ 
	int i, j; 
	for (i = 0; i < n-1; i++)	 
	
	// Last i elements are already in place 
	for (j = 0; j < n-i-1; j++) 
		if (A[j] > A[j+1]) 
			swap(A, j, j+1); 
} 

// Function to print an array 
void printArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
	cout << A[i] << " "; 
	cout << endl; 
} 

// Driver program to test above functions 
int main() 
{ 
	int A[] = {64, 34, 25, 12, 22, 11, 90}; 
	int n = sizeof(A)/sizeof(A[0]); 
	bubbleSort(A, n); 
	cout<<"Sorted array: \n"; 
	printArray(A, n); 
	return 0; 
}