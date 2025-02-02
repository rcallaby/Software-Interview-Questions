#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <chrono>

// Utility function to measure execution time of a function
template <typename Func, typename... Args>
double measureExecutionTime(Func func, Args&&... args) {
    auto start = std::chrono::high_resolution_clock::now();
    func(std::forward<Args>(args)...);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::micro>(end - start).count(); // Time in microseconds
}

// Function to efficiently search for a number using a hash table
bool searchNumber(const std::unordered_set<int>& hashTable, int target) {
    return hashTable.find(target) != hashTable.end();
}

// Function to sort numbers efficiently using std::sort (Introsort)
void sortNumbers(std::vector<int>& arr) {
    std::sort(arr.begin(), arr.end());
}

// Function to print a vector
void printVector(const std::vector<int>& arr) {
    for (int num : arr) std::cout << num << " ";
    std::cout << "\n";
}

// Main function
int main() {
    std::vector<int> numbers = {34, 7, 23, 32, 5, 62, 32, 7, 1, 98};
    std::unordered_set<int> hashTable(numbers.begin(), numbers.end());

    int target = 23;

    // Measure search execution time
    double searchTime = measureExecutionTime([&]() {
        bool found = searchNumber(hashTable, target);
        std::cout << "Search Result for " << target << ": " << (found ? "Found" : "Not Found") << "\n";
    });

    std::cout << "Search Time: " << searchTime << " μs\n";

    // Measure sorting execution time
    double sortTime = measureExecutionTime(sortNumbers, std::ref(numbers));

    std::cout << "Sorted Numbers: ";
    printVector(numbers);
    std::cout << "Sorting Time: " << sortTime << " μs\n";

    return 0;
}
