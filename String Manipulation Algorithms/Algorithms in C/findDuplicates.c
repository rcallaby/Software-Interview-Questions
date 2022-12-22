#include <stdio.h>
#include <string.h>

/* This is a possible solution to find duplicate characters in a given string. It may need work. 
*/

void find_duplicates(char *str)
{
    int i, j;
    int length = strlen(str);
    char ch;

    for (i = 0; i < length; i++) {
        for (j = i+1; j < length; j++) {
            if (str[i] == str[j]) {
                ch = str[j];
                printf("Duplicate character: %c \n", ch);
            }
        }
    }
}

int main(void)
{
    char str[20];
    printf("Enter a string: \n");
    scanf("%s", str);

    find_duplicates(str);

    return 0;
}