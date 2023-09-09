#include <stdio.h>
#include <string.h>

char firstNonRepeatingChar(char *string) {
    // Create an array to store the number of times a character appears
    int char_count[256] = {0};
  
    // Iterate through the string and count the number of times each character appears
    int i;
    for (i = 0; i < strlen(string); i++) { 
        char_count[string[i]]++;
    }
  
    // Iterate through the string again and find the first character that appears only once
    for (i = 0; i < strlen(string); i++) { 
        if (char_count[string[i]] == 1) { 
            return string[i];
        }
    }
  
    // If no characters appear only once, return '\0'
    return '\0';
}

int main() {
    // Test the function 
    char string[] = "hello world";
    printf("%c\n", firstNonRepeatingChar(string)); // w
    return 0;
}