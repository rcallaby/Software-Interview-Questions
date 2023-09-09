// The insertionSort algorithm works by comparing values in an array, one at a time, and inserting them in the correct order 
//in a new array.

// Declare an array to be sorted
let arr = [12, 9, 3, 7, 14, 11];

// Create an empty array to store the sorted values
let sortedArr = [];

// Loop through each value in the array
for (let i = 0; i < arr.length; i++) {
  // Get the current value
  let currentValue = arr[i];

  // Create a variable to store the index of the current value
  let j = i - 1;

  // Loop through the sorted array
  while (j >= 0 && sortedArr[j] > currentValue) {
    // Shift the value one place to the right
    sortedArr[j + 1] = sortedArr[j];
    j--;
  }

  // Add the current value to its correct position in the sorted array
  sortedArr[j + 1] = currentValue;
}

// Log the sorted array
console.log(sortedArr);