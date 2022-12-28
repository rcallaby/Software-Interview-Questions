#include <stdio.h>

/* This is a solution to count the number of vowels in a string
*/

int countVowels(char* str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        // check if the current character is a vowel
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || 
            str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || 
            str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || 
            str[i] == 'U')
            count++;
    }

    return count;
}

int main()
{
    char str[] = "Hello World!";
    int count = countVowels(str);
    printf("Number of vowels in '%s' = %d\n", str, count);

    return 0;
}