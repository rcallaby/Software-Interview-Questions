// This is a solution to count the number of duplicate characters in a given string.

function countDuplicates(str) {
    let occurances = {};
    let count = 0;
    
    // Loop through each character in the string
    for (let char of str) {
        // Add the character to the object if it doesn't already exist
        if (!occurances[char]) {
            occurances[char] = 1;
            // Otherwise, increment the count
        } else {
            occurances[char]++;
            // If the count is greater than 1, increment the overall count
            if (occurances[char] > 1) {
                count++;
            }
        }
    }
    return count;
}

console.log(countDuplicates("aabbcc")); // Expected Output: 2