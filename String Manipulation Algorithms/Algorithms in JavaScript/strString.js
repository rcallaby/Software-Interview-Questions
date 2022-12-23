//This is a possible solution to find a string within a string using JavaScript without using any libraries


function findString(string, subString) { 
  
    let length = subString.length; 
  
    // Iterate over the length of the string 
    for (let i = 0; i < string.length; i++) { 
        if (string.substring(i, i + length) == subString) { 
            return i; 
        } 
    } 
    return -1; 
} 

let string = "This is the string to search in"; 
let subString = "search"; 
  
if (findString(string, subString) >= 0) { 
    console.log("Yes, the string is found at index " + findString(string, subString)); 
} else { 
    console.log("No, the string is not found"); 
}