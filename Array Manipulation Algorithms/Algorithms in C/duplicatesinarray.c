#include <stdio.h>

int main(void) {
    int array[50];
    int counter = 0;
    int currentNumber;
    int i, j;

    // populate array with values

    for (i = 0; i < 50; i++) {
        array[i] = // some value;
    }

    // find duplicates

    for (i = 1; i < 50; i++) {
        currentNumber = array[i];
        for (j = 0; j < i; j++) {
            if (currentNumber == array[j]) {
                counter++;
            }
        }
    }
    printf("Number of duplicates found: %d\n", counter);
    return 0;
}