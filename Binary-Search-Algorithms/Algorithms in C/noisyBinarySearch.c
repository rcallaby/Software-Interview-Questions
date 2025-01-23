#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOISE_PROBABILITY 0.1 // Probability of returning the wrong comparison result
#define MAX_ATTEMPTS 5       // Maximum attempts to reduce noise impact

// Simulated noisy comparator
int noisy_compare(int a, int b) {
    double random_value = (double)rand() / RAND_MAX;
    if (random_value < NOISE_PROBABILITY) {
        // Return a noisy result
        return -((a > b) - (a < b)); // Flip the comparison result
    }
    // Return the correct result
    return (a > b) - (a < b);
}

// Reliable compare function (averages out the noise)
int reliable_compare(int a, int b) {
    int result = 0;
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        result += noisy_compare(a, b);
    }
    return (result > 0) - (result < 0); // Majority vote
}

// Noisy binary search implementation
int noisy_binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int comparison = reliable_compare(arr[mid], target);

        if (comparison == 0) {
            return mid; // Target found
        } else if (comparison < 0) {
            left = mid + 1; // Target is greater
        } else {
            right = mid - 1; // Target is smaller
        }
    }

    return -1; // Target not found
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Example sorted array
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Target value to search for
    int target = 7;

    // Perform noisy binary search
    int result = noisy_binary_search(arr, size, target);

    if (result != -1) {
        printf("Target %d found at index %d\n", target, result);
    } else {
        printf("Target %d not found in the array\n", target);
    }

    return 0;
}
