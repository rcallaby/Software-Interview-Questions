
#include<stdio.h> 
#include<string.h> 
  
/* A utility function to find the index of a substring in the string 
   and also return the index
*/
int findStringinString(char *string, char *substring) 
{ 
    int i, j, k, len1, len2; 
  
    len1 = strlen(string); 
    len2 = strlen(substring); 
  
    for (i = 0; i <= len1-len2; i++) 
    { 
        j = 0; 
        for (k = i; k < i + len2; k++) 
        { 
            // If current characters don't match 
            if (string[k] != substring[j]) 
                break; 
            j++; 
        } 
  
        // If all characters matched 
        if (j == len2) 
            return i; 
    } 
  
    return -1; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    char string[] = "Testing the test"; 
    char substring[] = "Test"; 
  
    int index = findStringinString(string, substring); 
    if (index == -1) 
        printf("Substring not found"); 
    else
        printf("Substring found at index %d", index); 
    return 0; 
}