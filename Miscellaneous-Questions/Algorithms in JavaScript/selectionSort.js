// SelectionSort algorithm
function selectionSort(arr) {
    // loop through the array
    for (let i = 0; i < arr.length; i++) {
      // set the minimum index to the current index
      let minIndex = i;
      // loop through the rest of the array
      for (let j = i + 1; j < arr.length; j++) {
        // if the current element is smaller than the minimum element
        if (arr[j] < arr[minIndex]) {
          // set the new minimum index
          minIndex = j;
        }
      }
      // if the minimum index is not the current index
      if (minIndex !== i) {
        // swap the minimum element with the current element
        let temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
      }
    }
    // return the sorted array
    return arr;
  }
  
  // example
  let arr = [3, 5, 1, 4, 2];
  console.log(selectionSort(arr)); // [1, 2