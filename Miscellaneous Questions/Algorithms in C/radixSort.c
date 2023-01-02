#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLEN 10
#define BASE 10

/*
    This is a possible solution to demonstrating the Radix sorting algorithm
*/

int max(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void radixSort(int arr[], int n)
{
    int exp, m;
    int *output = (int *)malloc(n * sizeof(int));
    m = max(arr, n);
    for (exp = 1; m/exp > 0; exp *= BASE)
    {
        int count[BASE] = {0};
        int i;
        for (i = 0; i < n; i++)
            count[ (arr[i]/exp)%BASE ]++;
        for (i = 1; i < BASE; i++)
            count[i] += count[i - 1];
        for (i = n - 1; i >= 0; i--)
        {
            output[count[ (arr[i]/exp)%BASE ] - 1] = arr[i];
            count[ (arr[i]/exp)%BASE ]--;
        }
        for (i = 0; i < n; i++)
            arr[i] = output[i];
    }
    free(output);
}

int main()
{
    int n, i;
    int arr[MAXLEN];
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter elements of array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    radixSort(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}