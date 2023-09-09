#include <stdio.h>
#include <string.h>

/* This is a possible solution to reverse a string using recursion
*/
void reverse_string(char *str);
 
int main()
{
    char str[] = "Hello World";
 
    /* Print the string before reversing */
    printf("String before reversing: %s\n", str);
 
    /* Call the function to reverse the string */
    reverse_string(str);
 
    /* Print the string after reversing */
    printf("String after reversing: %s\n", str);
 
    return 0;
}
 
/* Function to reverse a string using recursion */
void reverse_string(char *str)
{
    /* If str is empty, no more processing is needed */
    if (str[0] == '\0')
        return;
 
    /* Move to the next character in the string */
    reverse_string(&str[1]);
 
    /* Swap the characters */
    char temp = str[0];
    str[0] = str[strlen(str) - 1];
    str[strlen(str) - 1] = temp;
}