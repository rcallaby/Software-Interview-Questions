#include <stdio.h>

int main(void) {
    int array[50];
    int counter = 0;
    int currentNumber;
    int i, j;

    // populate array with values

    int array[50] = {1,2,3,4,5,6,7,8,9,10,11,1,
        12,13,14,15,16,17,18,19,20,21,22,
        23,24,25,26,27,28,29,30,31,32,33,
        34,35,36,37,38,39,40,42,43,44,
        45,46,47,48,49,50};

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