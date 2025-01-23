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

// Noisy interpolation search implementation
int noisy_interpolation_search(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Avoid division by zero
        if (arr[low] == arr[high]) {
            if (arr[low] == target) {
                return low;
            } else {
                break;
            }
        }

        // Interpolation formula to estimate the position
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (target - arr[low]));

        // Check if the position is out of bounds
        if (pos < low || pos > high) {
            break;
        }

        // Use reliable comparison to check the position
        int comparison = reliable_compare(arr[pos], target);

        if (comparison == 0) {
            return pos; // Target found
        } else if (comparison < 0) {
            low = pos + 1; // Target is in the upper part
        } else {
            high = pos - 1; // Target is in the lower part
        }
    }

    return -1; // Target not found
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Example sorted array
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Target value to search for
    int target = 70;

    // Perform noisy interpolation search
    int result = noisy_interpolation_search(arr, size, target);

    if (result != -1) {
        printf("Target %d found at index %d\n", target, result);
    } else {
        printf("Target %d not found in the array\n", target);
    }

    return 0;
}
