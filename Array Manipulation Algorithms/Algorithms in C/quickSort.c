#include <stdio.h>
 
void quicksort(int *array, int low, int high)
{
    int pivot, i, j, temp;
 
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
 
        while (i < j) 
        {
            while (array[i] <= array[pivot] && i <= high)
            {
                i++;
            }
            while (array[j] > array[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
 
        temp = array[j];
        array[j] = array[pivot];
        array[pivot] = temp;
        quicksort(array, low, j-1);
        quicksort(array, j+1, high);
    }
}

int main()
{
    int array[50], i;
 
    printf("Enter 50 elements of an array: \n");
    for(i = 0; i < 50; i++)
    {
        scanf("%d", &array[i]);
    }
    quicksort(array, 0, 50-1);
    printf("Sorted array: \n");
    for (i = 0; i < 50; i++)
    {
        printf("%d ", array[i]);
    }
 
    return 0;
}