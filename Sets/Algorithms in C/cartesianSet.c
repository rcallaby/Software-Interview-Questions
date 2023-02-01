#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 4

int main()
{
    int setA[MAX_ELEMENTS] = {1, 2, 3, 4};
    int setB[MAX_ELEMENTS] = {3, 4, 5, 6};
    int resultSet[MAX_ELEMENTS * MAX_ELEMENTS][2]; // 2D array to store the Cartesian set

    int resultIndex = 0; // Index to keep track of the number of elements in the result set

    for (int i = 0; i < MAX_ELEMENTS; i++) {
        for (int j = 0; j < MAX_ELEMENTS; j++) {
            resultSet[resultIndex][0] = setA[i];
            resultSet[resultIndex][1] = setB[j];
            resultIndex++;
        }
    }

    // Print the result set
    printf("Result set:\n");
    for (int i = 0; i < resultIndex; i++) {
        printf("(%d, %d)\n", resultSet[i][0], resultSet[i][1]);
    }

    return 0;
}
