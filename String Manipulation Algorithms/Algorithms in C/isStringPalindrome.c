#include <stdio.h> 
#include <string.h> 

// Function to check if a string is a palindrome 
int isStringPalindrome(char str[]) 
{ 
	int l = 0; 
	int h = strlen(str) - 1; 

	// Keep comparing characters while they are same 
	while (h > l) 
	{ 
		if (str[l++] != str[h--]) 
		{ 
			return 0; 
		} 
	} 
	return 1; 
} 

int main() 
{ 
	char str[100];
	
	printf("Enter a string: ");
	scanf("%s", str); 
	
	if (isStringPalindrome(str)) 
		printf("The string is a palindrome"); 
	else
		printf("The string is not a palindrome"); 

	return 0; 
}