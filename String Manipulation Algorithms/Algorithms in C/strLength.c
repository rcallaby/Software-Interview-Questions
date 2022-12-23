
#include <stdio.h>

/* This is just a solution for finding the length of a string without using an in built libraries.
*/
 
int strLength(char str[])
{
    int i, length = 0;
 
    for (i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}
 
int main()
{
    char str[] = "Hello World";
    int len = strLength(str);
    printf("Length of the given string %s is: %d", str, len);
    return 0;
}