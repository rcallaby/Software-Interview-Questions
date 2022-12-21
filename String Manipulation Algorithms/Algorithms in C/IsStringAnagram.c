#include <stdio.h>
#include <string.h>

int isStringAnagram(char str1[], char str2[]) 
{ 
    // Get lengths of both strings 
    int n1 = strlen(str1); 
    int n2 = strlen(str2); 
  
    // If length of both strings is not same, then they 
    // cannot be anagram 
    if (n1 != n2) 
        return 0; 
  
    // Sort both strings 
    quickSort(str1, 0, n1 - 1); 
    quickSort(str2, 0, n2 - 1); 
  
    // Compare sorted strings 
    for (int i = 0; i < n1; i++) 
        if (str1[i] != str2[i]) 
            return 0; 
  
    return 1; 
} 

int main() 
{ 
    char str1[] = "test"; 
    char str2[] = "sett"; 
    if (isStringAnagram(str1, str2)) 
        printf("The two strings are anagram of each other"); 
    else
        printf("The two strings are not anagram of each other"); 
  
    return 0; 
}