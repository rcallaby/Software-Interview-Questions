#include <iostream>
#include <array>
#include <unordered_set>
#include <vector>

//I am working on improving this solution to make it a bit more elegant. It is a work in progress.

int main()
{
    std::array<int, 50> arr = {1, 2, 3, 4, 5, 6, 7, 8, 8, 10, 10, 12, 13, 14, 10, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 39, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
    
    std::array<int, 50> duplicates;
    
    // Iterate through the first array
    for (int i = 0; i < arr.size(); i++)
    {
        // Check if any of the numbers have already been seen
        if (duplicates.find(arr[i]) != duplicates.end())
        {
            // If a number has been seen before, add it to the set
            duplicates.insert(arr[i]);
        }
    }
    
    // Return the set containing the duplicates
    return duplicates;
}