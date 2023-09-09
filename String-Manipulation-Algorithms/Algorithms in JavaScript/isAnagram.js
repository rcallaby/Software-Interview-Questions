// This is a possible solution for determing if a string is a anaagram of another string in JavaScript


function isAnagram(str1, str2) {
    // check if the lengths of strings are the same
    if (str1.length !== str2.length) {
        return false;
    }
    
    let frequencyCounter1 = {};
    let frequencyCounter2 = {};
    
    for (let char of str1) {
        frequencyCounter1[char] = (frequencyCounter1[char] || 0) + 1;
    }
    
    for (let char of str2) {
        frequencyCounter2[char] = (frequencyCounter2[char] || 0) + 1;
    }
    
    for (let key in frequencyCounter1) {
        if (!(key in frequencyCounter2)) {
            return false;
        }
        if (frequencyCounter1[key] !== frequencyCounter2[key]) {
            return false;
        }
    }
    
    return true;
  }
  
  // using multiple helper functions
  function isAnagram(str1, str2) {
    // check if the lengths of strings are the
    if (str1.length !== str2.length) {
        return false;
    }
    
    const frequencyCounter1 = buildFrequencyCounter(str1);
    const frequencyCounter2 = buildFrequencyCounter(str2);
    
    return validateFrequencyCounter(frequencyCounter1, frequencyCounter2);
  }
  
  function buildFrequencyCounter(str) {
    const frequencyCounter = {};
    
    for (let char of str) {
        frequencyCounter[char] = (frequencyCounter[char] || 0) + 1;
    }
    
    return frequencyCounter;
  }
  
  function validateFrequencyCounter(freqCounter1, freqCounter2) {
    for (let key in freqCounter1) {
        if (!(key in freqCounter2)) {
            return false;
        }
        if (freqCounter1[key] !== freqCounter2[key]) {
            return false;
        }
    }
    
    return true;
  }